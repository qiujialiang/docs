import os
import sys
import threading
import serial
from PySide6.QtWidgets import (QApplication, QMainWindow, QVBoxLayout, QHBoxLayout,
                               QWidget, QPushButton, QLabel, QTextEdit, QLineEdit,
                               QMessageBox, QTableWidget, QTableWidgetItem, QGroupBox,
                               QHeaderView, QStatusBar,QComboBox)
from PySide6.QtCore import QFile, QIODevice, Qt, QThread, Signal, QThreadPool, QTimer
from datetime import datetime
import time
import struct
from collections import defaultdict
import requests
import json
import paho.mqtt.client as mqtt
from collections import defaultdict


def Attributes_set(OrigiSrcAddr, DestAddr, Seq, tempture, Humi, Photo, FrameType, Error, CardData):
    return {
        'OrigiSrcAddr': OrigiSrcAddr,
        'DestAddr': DestAddr,
        'Seq': Seq,
        'tempture': tempture,
        'Humi': Humi,
        'Photo': Photo,
        'FrameType': FrameType,
        'Error': Error,
        'CardData': CardData
    }


def FrameType_rename(FrameType):
    return {
        1: '读取光照数据',
        2: '读取温湿度数据',
        3: '读取标签信息'
    }.get(FrameType, '未知类型')


def CardData_to_string(CardData):
    try:
        CardData = struct.unpack('4B', CardData)
        return ' '.join(str(b) if b <= 9 else chr(b) for b in CardData)
    except:
        return 'None'


class UploadThread(QThread):
    upload_status = Signal(bool, str)
    data_received = Signal(dict)
    block_command_received = Signal(str,str)
    def __init__(self, parent=None):
        super().__init__(parent)
        self.server_url = "http://192.168.140.133:8083/api/data"
        self.mqtt_broker = "192.168.140.133"
        self._running = True
        self.blocked_addresses=set()
        self.setup_mqtt()

    def setup_mqtt(self):
        """MQTT客户端初始化"""
        self.mqtt_client = mqtt.Client()
        self.mqtt_client.on_connect = self.on_mqtt_connect
        self.mqtt_client.on_message = self.on_mqtt_message
        try:
            self.mqtt_client.connect(self.mqtt_broker, 1883, 60)
            self.mqtt_client.subscribe('sensor/control', qos=1)
            self.mqtt_client.subscribe('sensor/block/+', qos=1)
            self.mqtt_client.loop_start()
        except Exception as e:
            self.upload_status.emit(False, f"MQTT连接失败: {str(e)}")

    def on_mqtt_connect(self, client, userdata, flags, rc):
        """MQTT连接回调"""
        if rc == 0:
            self.upload_status.emit(True, "MQTT连接成功")
        else:
            self.upload_status.emit(False, f"MQTT连接错误码: {rc}")

    def on_mqtt_message(self, client, userdata, message):
        """MQTT消息接收回调"""
        try:
            topic = message.topic
            payload = message.payload.decode()

            if topic == 'sensor/control':
                self.data_received.emit({
                    'type': 'command',
                    'data': payload,
                    'timestamp': datetime.now().isoformat()
                })
            elif topic.startswith('sensor/block/'):
                # 处理屏蔽命令
                source_addr = topic.split('/')[-1]
                action = payload  # 'block' 或 'unblock'
                self.block_command_received.emit(action, source_addr)

                if action == 'block':
                    self.blocked_addresses.add(source_addr)  # 使用复数形式
                    self.upload_status.emit(True, f"已屏蔽节点 {source_addr}")
                elif action == 'unblock':
                    if source_addr in self.blocked_addresses:
                        self.blocked_addresses.remove(source_addr)
                    self.upload_status.emit(True, f"已取消屏蔽节点 {source_addr}")

        except Exception as e:
            self.upload_status.emit(False, f"MQTT消息处理失败: {str(e)}")

    def is_blocked(self, source_addr):
        """检查地址是否被屏蔽"""
        return str(source_addr) in self.blocked_addresses

    def upload_data(self, data):
        """上传数据到服务器"""
        print(f"[DEBUG] 准备上传数据: {data}")

        # 检查源地址是否被屏蔽
        source_addr = data.get('source_addr', '')
        if self.is_blocked(source_addr):
            print(f"[INFO] 数据来自被屏蔽的节点 {source_addr}，不上传")
            return False

        try:
            response = requests.post(
                self.server_url,
                json=data,
                headers={'Content-Type': 'application/json'},
                timeout=5
            )
            print(f"服务器响应: {response.status_code}, {response.text}")
            return response.status_code == 201
        except Exception as e:
            print(f"上传异常: {str(e)}")
            return False


class SerialControlApp(QMainWindow):
    update_ui_signal = Signal(dict)
    log_message_signal = Signal(str)

    def __init__(self):
        super().__init__()
        self.serial_port = None
        self.upload_thread = UploadThread(self)
        self.upload_thread.data_received.connect(self.handle_remote_command)
        self.upload_thread.block_command_received.connect(self.handle_block_command)  # 新增: 连接屏蔽命令信号
        self._running = True
        self.init_ui()
        self.init_serial()

        # 连接信号
        self.update_ui_signal.connect(self.update_ui)
        self.log_message_signal.connect(self.log_message)

        # 初始化数据属性
        self.Attributes = {
            'OrigiSrcAddr': 0x00,
            'DestAddr': 0x00,
            'Seq': 0x00,
            'tempture': 0xFF,
            'Humi': 0xFF,
            'Photo': b'\xFF\xFF',
            'Error': 0x00,
            'CardData': b'\xFF\xFF\xFF\xFF',
            'FrameType': 0x00
        }

        # 添加上传重试定时器
        self.upload_retry_timer = QTimer(self)
        self.upload_retry_timer.timeout.connect(self.retry_upload_cached)
        self.upload_retry_timer.start(60000)  # 每60秒尝试重传

        # 连接上传状态信号
        self.upload_thread.upload_status.connect(self.handle_upload_status)

        # 初始化数据表
        self.init_data_table()

    def init_ui(self):
        """初始化UI界面"""
        self.setWindowTitle("无线传感网络数据收集系统")
        self.resize(800, 700)

        # 主窗口中心部件
        self.central_widget = QWidget()
        self.setCentralWidget(self.central_widget)

        # 主布局
        main_layout = QVBoxLayout(self.central_widget)

        # 数据采集模块
        self.data_group = QGroupBox("数据采集模块")
        self.data_group.setFont(self.get_font(12))
        main_layout.addWidget(self.data_group)

        # 数据采集模块布局
        data_layout = QHBoxLayout(self.data_group)

        # 温度显示
        temp_layout = QVBoxLayout()
        self.temp_label = QLabel("温度(℃):")
        self.temp_display = QLineEdit()
        self.temp_display.setReadOnly(True)
        temp_layout.addWidget(self.temp_label)
        temp_layout.addWidget(self.temp_display)

        # 湿度显示
        humi_layout = QVBoxLayout()
        self.humi_label = QLabel("湿度(%):")
        self.humi_display = QLineEdit()
        self.humi_display.setReadOnly(True)
        humi_layout.addWidget(self.humi_label)
        humi_layout.addWidget(self.humi_display)

        # 光照显示
        photo_layout = QVBoxLayout()
        self.photo_label = QLabel("光照(lx):")
        self.photo_display = QLineEdit()
        self.photo_display.setReadOnly(True)
        photo_layout.addWidget(self.photo_label)
        photo_layout.addWidget(self.photo_display)

        # 标签数据显示
        card_layout = QVBoxLayout()
        self.card_label = QLabel("标签数据:")
        self.card_display = QLineEdit()
        self.card_display.setReadOnly(True)
        card_layout.addWidget(self.card_label)
        card_layout.addWidget(self.card_display)

        # 按钮布局 (垂直布局)
        btn_layout = QVBoxLayout()
        self.btn_open = QPushButton("开启")
        self.btn_close = QPushButton("关闭")
        self.btn_clear = QPushButton("清空")
        self.btn_close.setEnabled(False)
        # 将按钮添加到垂直布局
        btn_layout.addWidget(self.btn_open)
        btn_layout.addWidget(self.btn_close)
        btn_layout.addWidget(self.btn_clear)
        # 修改过滤控件标签
        filter_group = QGroupBox("黑名单过滤")  # 修改标题
        filter_layout = QHBoxLayout(filter_group)

        filter_label = QLabel("黑名单地址:")  # 修改标签
        filter_layout.addWidget(filter_label)

        self.addr_filter = QComboBox()
        self.addr_filter.addItem("不启用黑名单", 0xFF)  # 修改选项文本
        self.addr_filter.addItem("0x00", 0x00)
        self.addr_filter.addItem("0x01", 0x01)
        self.addr_filter.addItem("0x02", 0x02)
        filter_layout.addWidget(self.addr_filter)
        self.filter_btn = QPushButton("应用黑名单")  # 修改按钮文本
        self.filter_btn.clicked.connect(self.apply_filter)
        filter_layout.addWidget(self.filter_btn)

        # 将过滤布局添加到主布局
        btn_layout.addLayout(filter_layout)
        # 将按钮布局和过滤组添加到主数据布局
        data_layout.addLayout(temp_layout)
        data_layout.addLayout(humi_layout)
        data_layout.addLayout(photo_layout)
        data_layout.addLayout(card_layout)
        data_layout.addLayout(btn_layout)  # 添加按钮布局
        data_layout.addWidget(filter_group)  # 添加过滤组

        # 数据表格
        self.data_table = QTableWidget()
        self.data_table.setColumnCount(5)
        self.data_table.setHorizontalHeaderLabels(["源地址", "目的地址", "Seq", "CardData", "Type"])
        self.data_table.horizontalHeader().setSectionResizeMode(QHeaderView.Stretch)
        main_layout.addWidget(self.data_table)

        # 状态栏
        self.status_bar = QStatusBar()
        self.setStatusBar(self.status_bar)
        self.status_bar.showMessage("系统准备就绪")

        # 连接信号
        self.btn_open.clicked.connect(self.start_system)
        self.btn_close.clicked.connect(self.stop_system)
        self.btn_clear.clicked.connect(self.clear_data)

        # 应用样式
        self.apply_styles()
    def handle_block_command(self, action, source_addr):
        """处理屏蔽/取消屏蔽命令"""
        if action == 'block':
            self.log_message(f"收到屏蔽命令，将忽略来自 {source_addr} 的数据")
        elif action == 'unblock':
            self.log_message(f"收到取消屏蔽命令，将恢复接收来自 {source_addr} 的数据")
    def apply_filter(self):
        """应用黑名单过滤（隐藏指定源地址的数据）"""
        if not hasattr(self, 'addr_filter'):
            return

        # 获取选中的黑名单地址
        blacklist_addr = self.addr_filter.currentData()

        # 如果是"全部地址"选项，则显示所有数据
        if blacklist_addr == 0xFF:
            for row in range(self.data_table.rowCount()):
                self.data_table.setRowHidden(row, False)
            self.status_bar.showMessage("已显示全部数据", 3000)
            return

        # 黑名单过滤逻辑
        for row in range(self.data_table.rowCount()):
            item = self.data_table.item(row, 0)  # 源地址在第0列
            if item:
                try:
                    addr = int(item.text(), 16)
                    # 隐藏匹配黑名单地址的行（黑名单模式）
                    self.data_table.setRowHidden(row, addr == blacklist_addr)
                except ValueError:
                    pass

        self.status_bar.showMessage(f"已隐藏源地址 {hex(blacklist_addr)} 的数据", 3000)

    # 在接收新数据时自动应用当前过滤
    def init_data_table(self):
        """初始化数据表格"""
        self.data_table.setColumnCount(5)
        self.data_table.setHorizontalHeaderLabels(["源地址", "目的地址", "Seq", "CardData", "Type"])
        self.data_table.horizontalHeader().setSectionResizeMode(QHeaderView.Stretch)
        self.data_table.setEditTriggers(QTableWidget.NoEditTriggers)
        self.data_table.setSelectionBehavior(QTableWidget.SelectRows)
        self.data_table.setSelectionMode(QTableWidget.SingleSelection)

    def apply_styles(self):
        """应用样式表"""
        self.setStyleSheet("""
            QMainWindow {
                background-color: #f5f5f5;
            }
            QGroupBox {
                border: 1px solid #ccc;
                border-radius: 5px;
                margin-top: 10px;
                padding-top: 15px;
            }
            QGroupBox::title {
                subcontrol-origin: margin;
                left: 10px;
                padding: 0 3px;
            }
            QPushButton {
                min-width: 80px;
                padding: 5px;
                background-color: #4CAF50;
                color: white;
                border: none;
                border-radius: 4px;
            }
            QPushButton:disabled {
                background-color: #cccccc;
            }
            QPushButton:hover {
                background-color: #45a049;
            }
            QPushButton:pressed {
                background-color: #3d8b40;
            }
            QLineEdit {
                padding: 5px;
                border: 1px solid #ddd;
                border-radius: 4px;
            }
            QTableWidget {
                border: 1px solid #ddd;
                gridline-color: #eee;
            }
            QHeaderView::section {
                background-color: #4CAF50;
                color: white;
                padding: 5px;
                border: none;
            }
        """)

    def get_font(self, size=10, bold=False):
        """获取字体对象"""
        font = self.font()
        font.setPointSize(size)
        font.setBold(bold)
        return font

    def init_serial(self):
        """初始化串口连接"""
        try:
            self.serial_port = serial.Serial(
                port="COM8",
                baudrate=57600,
                timeout=None
            )
            self.log_message("串口COM8初始化成功")
        except Exception as e:
            self.show_error(f"串口初始化失败: {str(e)}")
            self.serial_port = None

    def start_system(self):
        """启动系统"""
        if self.serial_port and self.serial_port.is_open:
            self.btn_open.setEnabled(False)
            self.btn_close.setEnabled(True)
            self._running = True

            # 启动数据接收线程
            self.receive_thread = threading.Thread(
                target=self.receive_data,
                daemon=True
            )
            self.receive_thread.start()
            self.log_message("系统启动 - 开始接收数据")
        else:
            self.show_error("串口未正确初始化，无法启动")

    def receive_data(self):
        """接收串口数据"""
        while self._running and self.serial_port and self.serial_port.is_open:
            try:
                Frame = self.serial_port.read(24)
                print(f"[DEBUG] 收到原始串口数据({len(Frame)}字节): {Frame.hex()}")

                if len(Frame) != 24:
                    print(f"[WARNING] 数据长度不正确，期望24字节，实际收到{len(Frame)}字节")
                    continue

                # 解析数据
                attrs = Attributes_set(
                    OrigiSrcAddr=Frame[0],
                    DestAddr=Frame[2],
                    Seq=Frame[8],
                    tempture=Frame[12],
                    Humi=Frame[14],
                    Photo=Frame[16:18],
                    FrameType=Frame[18],
                    Error=Frame[19],
                    CardData=Frame[20:]
                )

                print(f"[DEBUG] 解析后的属性: {attrs}")

                # 转换数据格式
                try:
                    attrs['Photo'] = struct.unpack('H', attrs['Photo'])[0]
                    attrs['FrameType'] = FrameType_rename(attrs['FrameType'])
                    # 如果是标签信息类型，使用实际卡数据
                    if attrs['FrameType'] == '读取标签信息':
                        attrs['CardData'] = CardData_to_string(attrs['CardData'])
                    else:
                        # 非标签信息类型，卡数据显示为"0000"
                        attrs['CardData'] = "0 0 0 0"
                except Exception as e:
                    print(f"[ERROR] 数据转换失败: {str(e)}")
                    continue

                # 准备上传数据
                upload_data = {
                    'temperature': attrs['tempture'],
                    'humidity': attrs['Humi'],
                    'light': attrs['Photo'],
                    'card_data': attrs['CardData'],
                    'source_addr': hex(attrs['OrigiSrcAddr']),
                    'frame_type': attrs['FrameType'],
                    'timestamp': datetime.now().strftime('%Y-%m-%d %H:%M:%S')  # 添加时间戳
                }
                print(f"[DEBUG] 准备上传的数据包: {upload_data}")

                # 上传数据
                success = self.upload_thread.upload_data(upload_data)
                print(f"[DEBUG] 上传结果: {'成功' if success else '失败'}")

                # 更新UI
                self.update_ui_signal.emit(attrs)

            except Exception as e:
                print(f"[ERROR] 数据接收处理异常: {str(e)}")
                continue

    def update_ui(self, attributes):
        """更新UI界面"""
        # 更新数据显示
        self.temp_display.setText(str(attributes['tempture']))
        self.humi_display.setText(str(attributes['Humi']))
        self.photo_display.setText(str(attributes['Photo']))
        self.card_display.setText(str(attributes['CardData']))

        # 更新数据表格
        row = self.data_table.rowCount()
        self.data_table.insertRow(row)

        self.data_table.setItem(row, 0, QTableWidgetItem(hex(attributes['OrigiSrcAddr'])))
        self.data_table.setItem(row, 1, QTableWidgetItem(hex(attributes['DestAddr'])))
        self.data_table.setItem(row, 2, QTableWidgetItem(str(attributes['Seq'])))
        self.data_table.setItem(row, 3, QTableWidgetItem(attributes['CardData']))
        self.data_table.setItem(row, 4, QTableWidgetItem(attributes['FrameType']))

        # 自动应用当前过滤
        filter_addr = self.addr_filter.currentData()
        if filter_addr != 0xFF:  # 如果不是"全部地址"模式
            item = self.data_table.item(row, 0)
            if item:
                try:
                    addr = int(item.text(), 16)
                    self.data_table.setRowHidden(row, addr != filter_addr)
                except ValueError:
                    self.data_table.setRowHidden(row, True)

        # 自动滚动到最后一行
        self.data_table.scrollToBottom()

        # 记录日志
        self.log_message(f"收到数据: 温度{attributes['tempture']}℃, 湿度{attributes['Humi']}%")

    def stop_system(self):
        """关闭系统"""
        self._running = False
        self.btn_open.setEnabled(True)
        self.btn_close.setEnabled(False)
        self.log_message("系统已停止")

    def clear_data(self):
        """清空数据"""
        self.temp_display.clear()
        self.humi_display.clear()
        self.photo_display.clear()
        self.card_display.clear()
        self.data_table.setRowCount(0)
        self.log_message("已清空所有数据")

    def handle_remote_command(self, data):
        """处理从MQTT接收到的远程控制命令"""
        if data['type'] == 'command':
            if data['data'] == 'start' and self.btn_open.isEnabled():
                self.start_system()
                self.log_message("收到远程启动命令")
            elif data['data'] == 'stop' and self.btn_close.isEnabled():
                self.stop_system()
                self.log_message("收到远程停止命令")

    def handle_upload_status(self, success, message):
        """处理上传状态反馈"""
        if success:
            self.log_message(f"[上传成功] {message}")
        else:
            self.log_message(f"[上传失败] {message}")
            self.status_bar.showMessage(f"上传失败: {message}", 5000)

    def upload_in_thread(self, data):
        """线程池中执行的上传任务"""
        success = self.upload_thread.upload_data(data)
        if not success:
            self.log_message("数据上传失败，将尝试缓存数据")
            self.cache_data(data)

    def cache_data(self, data):
        """本地缓存失败的上传数据"""
        cache_file = "upload_cache.json"
        try:
            cached = []
            # 读取现有缓存
            if os.path.exists(cache_file):
                with open(cache_file, 'r') as f:
                    cached = json.load(f)

            # 添加新数据
            cached.append(data)

            # 保存缓存（限制最大100条）
            with open(cache_file, 'w') as f:
                json.dump(cached[-100:], f)

        except Exception as e:
            print(f"缓存数据失败: {str(e)}")

    def retry_upload_cached(self):
        """重试上传缓存的数据"""
        cache_file = "upload_cache.json"
        if not os.path.exists(cache_file):
            return

        try:
            with open(cache_file, 'r') as f:
                cached = json.load(f)

            success_count = 0
            for data in cached[:]:  # 使用副本遍历
                if self.upload_thread.upload_data(data):
                    success_count += 1
                    cached.remove(data)

            # 更新缓存文件
            with open(cache_file, 'w') as f:
                json.dump(cached, f)

            self.log_message(f"重传完成: 成功{success_count}条")
        except Exception as e:
            self.log_message(f"重传缓存失败: {str(e)}")

    def log_message(self, message):
        """记录日志消息"""
        timestamp = datetime.now().strftime("%H:%M:%S")
        self.status_bar.showMessage(f"[{timestamp}] {message}", 5000)

    def show_error(self, message):
        """显示错误消息"""
        QMessageBox.critical(self, "错误", message)

    def closeEvent(self, event):
        """关闭窗口时确保资源释放"""
        self._running = False

        if hasattr(self, 'receive_thread') and self.receive_thread.is_alive():
            self.receive_thread.join(timeout=1)

        if hasattr(self, 'upload_thread'):
            self.upload_thread.mqtt_client.disconnect()
            self.upload_thread.quit()

        if self.serial_port and self.serial_port.is_open:
            self.serial_port.close()

        super().closeEvent(event)


if __name__ == "__main__":
    app = QApplication(sys.argv)

    # 设置全局样式
    app.setStyle("Fusion")

    # 创建并显示主窗口
    window = SerialControlApp()
    window.show()

    sys.exit(app.exec())