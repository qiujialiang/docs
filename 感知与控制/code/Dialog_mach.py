from PyQt6 import QtCore, QtGui, QtWidgets
from send import *
import global_var 
from com_init import com
import time
class Ui_Dialog_mach(object):
    def __init__(self,main_window=None):
        self.main_window = main_window
    def init_mach(self):
        if global_var.mach_statu==2 or global_var.mach_statu==1:
            self.radioButton_2.setChecked(False)
            self.radioButton.setChecked(True)
        else:
            self.radioButton.setChecked(False)
            self.radioButton_2.setChecked(True)
    def set_mach(self):
        v=self.lineEdit_2.text()
        mach_statu = self.radioButton.isChecked()
        if v != '':
            global_var.data["compressor_delay"]=int(v)
            data_p=set_parameter_frame(addr=0x01, set_parameter_data=global_var.data)
            send_frame(data_p, com,ui=self.main_window)
            time.sleep(1)
        compressor_control_frame_data = compressor_control_frame(addr=0x01, compressor_control_data=mach_statu)
        send_frame(compressor_control_frame_data, com,ui=self.main_window)
        time.sleep(1)
    
    def cancel(self):
        self.Dialog.close()
        
    def setupUi(self, Dialog):
        self.Dialog = Dialog
        Dialog.setObjectName("Dialog")
        Dialog.resize(299, 171)
        self.radioButton_2 = QtWidgets.QRadioButton(parent=Dialog)
        self.radioButton_2.setGeometry(QtCore.QRect(10, 20, 115, 19))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.radioButton_2.setFont(font)
        self.radioButton_2.setObjectName("radioButton_2")
        self.radioButton = QtWidgets.QRadioButton(parent=Dialog)
        self.radioButton.setGeometry(QtCore.QRect(140, 20, 115, 19))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.radioButton.setFont(font)
        self.radioButton.setObjectName("radioButton")
        self.pushButton_2 = QtWidgets.QPushButton(parent=Dialog)
        self.pushButton_2.setGeometry(QtCore.QRect(170, 110, 121, 51))
        self.pushButton_2.setObjectName("pushButton_2")
        self.lineEdit_2 = QtWidgets.QLineEdit(parent=Dialog)
        self.lineEdit_2.setGeometry(QtCore.QRect(200, 60, 91, 31))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.lineEdit_2.setFont(font)
        self.lineEdit_2.setObjectName("lineEdit_2")
        self.pushButton = QtWidgets.QPushButton(parent=Dialog)
        self.pushButton.setGeometry(QtCore.QRect(10, 110, 121, 51))
        self.pushButton.setObjectName("pushButton")
        self.label_2 = QtWidgets.QLabel(parent=Dialog)
        self.label_2.setGeometry(QtCore.QRect(10, 50, 191, 51))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_2.setFont(font)
        self.label_2.setObjectName("label_2")

        self.retranslateUi(Dialog)
        QtCore.QMetaObject.connectSlotsByName(Dialog)
        
        with open(r"style.qss", "r",encoding='utf-8') as f:
            Dialog.setStyleSheet(f.read())
        Dialog.setWindowTitle("压缩机控制")
        self.init_mach()

    def retranslateUi(self, Dialog):
        _translate = QtCore.QCoreApplication.translate
        Dialog.setWindowTitle(_translate("Dialog", "Dialog"))
        self.radioButton_2.setText(_translate("Dialog", "关机"))
        self.radioButton.setText(_translate("Dialog", "开机"))
        self.pushButton_2.setText(_translate("Dialog", "取消"))
        self.pushButton.setText(_translate("Dialog", "确认"))
        self.label_2.setText(_translate("Dialog", "设定压缩机启动延时:"))
        
        self.pushButton.clicked.connect(self.set_mach)
        self.pushButton_2.clicked.connect(self.cancel)