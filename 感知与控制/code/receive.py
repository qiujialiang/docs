from send import *
from com_init import com
from PyQt6.QtCore import QThread, pyqtSignal

# 定义状态帧字典
control_table_attributes = {}
control_table_status = {}
ack_status = {}

class SerialReceiver(QThread):
    frame_received = pyqtSignal(object)  # 定义一个信号，用于发送接收到的帧

    def __init__(self, com, parent=None):
        super().__init__(parent)
        self.com = com
        self.running = True

    def run(self):
        while self.running:
            if self.com.in_waiting >= 1:  # 判断是否有数据可读
                com_data = self.com.read(self.com.in_waiting)
                frames = receive_frame(com_data)
                for frame in frames:
                    self.frame_received.emit(frame)  # 发射信号，将接收到的帧传递给其他模块
            self.msleep(100)  # 避免 CPU 占满

    def stop(self):
        self.running = False
        self.quit()
        self.wait()

# 数据接收
def receive_data(com, callback=None):
    while True:
        com_data = com.read(80)  # 读取数据
        if com_data:
            frames = receive_frame(com_data)  # 解析帧
            for frame in frames:
                process_frame(frame)  # 处理每个帧
                if callback:
                    callback(frame)

def process_frame(frame):
    if len(frame) == 44:  # 状态帧
        control_table_status['dev_code'] = frame[6:11]
        control_table_status['sys_status'] = frame[29]
        control_table_status['compressor_status'] = frame[31]
        control_table_status['temp_set'] = frame[32]
        control_table_status['current_temp'] = frame[33]
        control_table_status['box_status'] = frame[36:38]
        print(f"控制表状态: {control_table_status}")
        temp_now = get_temp(control_table_status['current_temp'])
        print(f"当前温度: {temp_now}")
        compressor_control(temp_now)  # 根据当前温度控制压缩机
    elif len(frame) == 28:  # 参数帧
        control_table_attributes['dev_code'] = frame[6:11]
        control_table_attributes['addr'] = frame[11]
        control_table_attributes['time_gap'] = frame[13]
        control_table_attributes['compressor_delay'] = frame[14]
        control_table_attributes['temp_set'] = frame[17]
        control_table_attributes['temp_control'] = frame[18]
        print(f"控制表属性: {control_table_attributes}")
    elif len(frame) == 14:
        ack_status['status'] = frame[8:10]
        print(f"{ack_status}")

def get_temp(temp_byte):
    # 第7位是符号位
    sign = -1 if (temp_byte >> 7) & 1 else 1
    # 第6~1位是整数部分（取 bit6 到 bit1）
    integer_part = (temp_byte >> 1) & 0b111111
    # 第0位是小数部分
    decimal_part = 0.5 if temp_byte & 1 else 0.0
    return sign * (integer_part + decimal_part)

def compressor_control(temp_now):
    temp_set = get_temp(control_table_status['temp_set'])
    temp_control = control_table_attributes['temp_control']
    if temp_now <= temp_set - temp_control:
        compressor_control_frame_data = compressor_control_frame(addr=0x01, compressor_control_data=False)
        send_frame(compressor_control_frame_data,com)  # 关闭压缩机
        print("关闭压缩机")
    elif temp_now >= temp_set + temp_control:
        compressor_control_frame_data = compressor_control_frame(addr=0x01, compressor_control_data=True)
        send_frame(compressor_control_frame_data,com)  # 打开压缩机
        print("打开压缩机")

def receive_frame(hex_datas):
    res_frames = []
    i = 0
    while i < len(hex_datas) - 1:
        if hex_datas[i] == 0xFF and hex_datas[i + 1] == 0xFF:
            for j in range(i + 2, len(hex_datas) - 1):
                if hex_datas[j] == 0xFF and hex_datas[j + 1] == 0xF7:
                    frame = hex_datas[i:j + 2]
                    if len(frame) in [14, 44]:
                        res_frames.append(frame)
                    i = j + 2  # 跳过已处理的帧
                    break
        i += 1
    return res_frames