from PyQt6 import QtCore, QtGui, QtWidgets
from send import *
from global_var import *
from com_init import com
import time
class Ui_Dialog_temp(object):
    def __init__(self, main_window=None):
        self.main_window = main_window  # 用于与主窗口交互

    def set_temp(self):
        # 获取用户输入的设定温度和温度控制偏差
        set_temp_str = self.lineEdit.text()
        set_temp = float(set_temp_str) if set_temp_str else None
        temp_control_str = self.lineEdit_2.text()
        temp_control = int(temp_control_str) if temp_control_str else None

        # 更新全局数据字典中的温度设置
        data["set_temp"] = set_temp if set_temp is not None else data["set_temp"]
        data["temp_control"] = temp_control if temp_control is not None else data["temp_control"]

        # 如果输入有效，生成并发送设置参数帧
        if set_temp is not None and temp_control is not None:
            data_p = set_parameter_frame(addr=0x01, set_parameter_data=data)
            send_frame(data_p, com, ui=self.main_window)
            time.sleep(0.5)

        # 如果输入有效，生成并发送设置温度帧
        if set_temp is not None:
            set_temperature_frame_data = set_temperature_frame(addr=0x01, set_temperature_data=set_temp)
            send_frame(set_temperature_frame_data, com, ui=self.main_window)
            time.sleep(0.5)

        # 如果输入有效，生成并发送设置温度控制偏差帧
        if temp_control is not None:
            set_temperature_control_deviation_frame_data = set_temperature_control_deviation_frame(addr=0x01, set_temperature_control_deviation_data=temp_control)
            send_frame(set_temperature_control_deviation_frame_data, com, ui=self.main_window)
            time.sleep(0.5)

    def cancel(self):
        # 关闭对话框
        self.Dialog.close()

    def setupUi(self, Dialog):
        self.Dialog = Dialog
        Dialog.setObjectName("Dialog")
        Dialog.resize(303, 173)
        self.lineEdit = QtWidgets.QLineEdit(parent=Dialog)
        self.lineEdit.setGeometry(QtCore.QRect(120, 20, 151, 31))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.lineEdit.setFont(font)
        self.lineEdit.setObjectName("lineEdit")
        self.label = QtWidgets.QLabel(parent=Dialog)
        self.label.setGeometry(QtCore.QRect(20, 10, 91, 51))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label.setFont(font)
        self.label.setObjectName("label")
        self.pushButton = QtWidgets.QPushButton(parent=Dialog)
        self.pushButton.setGeometry(QtCore.QRect(20, 110, 121, 51))
        self.pushButton.setObjectName("pushButton")
        self.pushButton_2 = QtWidgets.QPushButton(parent=Dialog)
        self.pushButton_2.setGeometry(QtCore.QRect(150, 110, 121, 51))
        self.pushButton_2.setObjectName("pushButton_2")
        self.label_4 = QtWidgets.QLabel(parent=Dialog)
        self.label_4.setGeometry(QtCore.QRect(20, 50, 141, 51))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_4.setFont(font)
        self.label_4.setObjectName("label_4")
        self.lineEdit_2 = QtWidgets.QLineEdit(parent=Dialog)
        self.lineEdit_2.setGeometry(QtCore.QRect(160, 60, 131, 31))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.lineEdit_2.setFont(font)
        self.lineEdit_2.setObjectName("lineEdit_2")

        self.retranslateUi(Dialog)
        QtCore.QMetaObject.connectSlotsByName(Dialog)

        with open(r"style.qss", "r", encoding='utf-8') as f:
            Dialog.setStyleSheet(f.read())
        Dialog.setWindowTitle("温度设定")

    def retranslateUi(self, Dialog):
        _translate = QtCore.QCoreApplication.translate
        Dialog.setWindowTitle(_translate("Dialog", "Dialog"))
        self.label.setText(_translate("Dialog", "设定温度:"))
        self.pushButton.setText(_translate("Dialog", "确认"))
        self.pushButton_2.setText(_translate("Dialog", "取消"))
        self.label_4.setText(_translate("Dialog", "温度控制偏差:"))

        # 连接确认按钮的点击事件到设置温度函数
        self.pushButton.clicked.connect(self.set_temp)
        # 连接取消按钮的点击事件到关闭对话框函数
        self.pushButton_2.clicked.connect(self.cancel)