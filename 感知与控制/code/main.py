from PyQt6 import QtWidgets
import sys
from send import *
from receive import *
from Dialog_open import Ui_Dialog_open
from Dialog_pic import Ui_Dialog_pic
from Dialog_mach import Ui_Dialog_mach
from Dialog_temp import Ui_Dialog_temp
from mian_ui import Ui_MainWindow
import threading
from api_server import run_flask_app
from com_init import com
import global_var

class MainWindow(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        with open(r"style.qss", "r",encoding='utf-8') as f:
            self.setStyleSheet(f.read())
        self.setWindowTitle("智能保鲜柜控制系统") 
        # 手动连接按钮事件
        self.pushButton.clicked.connect(lambda: self.op(Ui_Dialog_open))
        self.pushButton_2.clicked.connect(lambda: self.op(Ui_Dialog_mach))
        self.pushButton_3.clicked.connect(lambda: self.op(Ui_Dialog_temp))
        self.pushButton_4.clicked.connect(lambda: self.op(Ui_Dialog_pic))
    def op(self,window):
        dialog =QtWidgets.QDialog()
        self.open_form = window(main_window=self)
        self.open_form.setupUi(dialog)
        if isinstance(self.open_form,Ui_Dialog_open):
            self.open_form.pushButton.clicked.disconnect()
            self.open_form.pushButton.clicked.connect(lambda: (
                self.open_form.update_statu(),
                dialog.accept(),  # 关闭对话框
            ))
        
        if isinstance(self.open_form,Ui_Dialog_mach):
            self.open_form.pushButton.clicked.disconnect()
            self.open_form.pushButton.clicked.connect(lambda: (
                self.open_form.set_mach(),
                dialog.accept(),  # 关闭对话框
            ))
        
        if isinstance(self.open_form,Ui_Dialog_temp):
            self.open_form.pushButton.clicked.disconnect()
            self.open_form.pushButton.clicked.connect(lambda: (
                self.open_form.set_temp(),
                dialog.accept(),  # 关闭对话框
            ))
        dialog.exec()
    def update_state(self,status):
        drawer_to_row = {
            0: 0, 1: 0, 2: 0, 3: 0, 4: 0,
            5: 2, 6: 2, 7: 2, 8: 2, 9: 2
        }
        for i in range(10): 
            row = drawer_to_row.get(i,0)
            col = i % 5
            state = "开启" if status[i] else "关闭"
            item = self.tableWidget_2.item(row, col)
            if item is not None:
                item.setText(state)
                
    def handle_received_frame(self, frame):
        if len(frame) == 44:  # 状态帧
            current_temp_byte = frame[33]
            set_temp_byte = frame[32]
            temp_p = frame[18]
            temp_now = get_temp(current_temp_byte)
            temp_set = get_temp(set_temp_byte)
             
            self.label_5.setText(f"{temp_set:.1f}")
            self.label_4.setText(f"{temp_now:.1f}")  # 更新当前温度显示
            self.label_8.setText(str(temp_p))
            global_var.temp_list.append(temp_now)
            print("温度已更新:", temp_now)
            
            # 更新压缩机状态
            compressor_status = frame[31]
            delay=frame[14]
            if compressor_status==0:
                self.label_7.setText("关闭")
            elif compressor_status==1:
                self.label_7.setText("预启动")
            elif compressor_status==2:
                self.label_7.setText("启动")
            else:
                self.label_7.setText("故障")
            global_var.mach_statu = compressor_status
            
            self.label_10.setText(str(delay))
                
            device=frame[23:28]
            self.label_13.setText(" ".join(f"{b:02X}" for b in device))
            
            addr = frame[11]
            self.label_14.setText(str(addr))
            
            status_byte= frame[36:38]
            status=[]
            for byte in status_byte:
                for i in range(8):
                    status.append((byte >> i) & 1)
            self.update_state(status[:10])
            global_var.statu=status

        elif len(frame) == 28:  # 参数帧
            temp_set_byte = frame[17]
            temp_set = get_temp(temp_set_byte)
            set = temp_set
            self.label_5.setText(str(set))  # 更新设定温度
        
        elif len(frame) == 14:
            status_byte= frame[8:10]
            status=[]
            for byte in status_byte:
                for i in range(8):
                    status.append((byte >> i) & 1)
            s = status[:10]
            self.update_state(status[:10])
            
    
    def start_monitor(self,com):
        self.receiver=SerialReceiver(com)
        self.receiver.frame_received.connect(self.handle_received_frame)
        self.receiver.start()
    
    
    def log(self,frame_info):
        row_pos=self.tableWidget.rowCount()
        self.tableWidget.insertRow(row_pos)
        headers = ["length", "frame_number", "dev_addr", "func_code", "data", "checksum"]
        for col, key in enumerate(headers):
            self.tableWidget.setItem(row_pos, col, QtWidgets.QTableWidgetItem(str(frame_info[key])))
    

if __name__ == "__main__":
    # 启动 Flask 在单独线程中运行
    flask_thread = threading.Thread(target=run_flask_app)
    flask_thread.daemon = True
    flask_thread.start()
    
    app = QtWidgets.QApplication(sys.argv)
    window = MainWindow()
    window.show()
    try:
        window.start_monitor(com)
        sys.exit(app.exec())
    finally:
        if hasattr(window, 'receiver'):
            window.receiver.stop()
        com.close()
    