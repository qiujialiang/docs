from PyQt6 import QtCore, QtGui, QtWidgets
from send import *
import global_var
from com_init import com
import time
class Ui_Dialog_open(object):
    def __init__(self, main_window=None):
        self.main_window = main_window  # 用于与主窗口交互

    def init_state(self):
        # 初始化界面元素状态，根据全局变量中的抽屉状态设置复选框的勾选状态
        self.checkBox.setChecked(bool(global_var.statu[0]))
        self.checkBox_2.setChecked(bool(global_var.statu[1]))
        self.checkBox_3.setChecked(bool(global_var.statu[2]))
        self.checkBox_4.setChecked(bool(global_var.statu[3]))
        self.checkBox_5.setChecked(bool(global_var.statu[4]))
        self.checkBox_10.setChecked(bool(global_var.statu[5]))
        self.checkBox_6.setChecked(bool(global_var.statu[6]))
        self.checkBox_7.setChecked(bool(global_var.statu[7]))
        self.checkBox_8.setChecked(bool(global_var.statu[8]))
        self.checkBox_9.setChecked(bool(global_var.statu[9]))

    def update_statu(self):
        # 收集各个复选框的当前状态，构造控制数据
        statu = [
            int(self.checkBox.isChecked()),     # 抽屉1
            int(self.checkBox_2.isChecked()),   # 抽屉2
            int(self.checkBox_3.isChecked()),   # 抽屉3
            int(self.checkBox_4.isChecked()),   # 抽屉4
            int(self.checkBox_5.isChecked()),   # 抽屉5
            int(self.checkBox_10.isChecked()),  # 抽屉6
            int(self.checkBox_6.isChecked()),   # 抽屉7
            int(self.checkBox_7.isChecked()),   # 抽屉8
            int(self.checkBox_8.isChecked()),   # 抽屉9
            int(self.checkBox_9.isChecked()),   # 抽屉10
            0, 0  # 保留两位，未使用的抽屉状态
        ]
        box_control_data = statu
        unlock_frame_data = box_control_frame(addr=0x01, box_control_data=box_control_data)
        send_frame(unlock_frame_data, com, ui=self.main_window)
        time.sleep(1)

    def setupUi(self, Dialog):
        Dialog.setObjectName("Dialog")
        Dialog.resize(208, 282)
        self.pushButton = QtWidgets.QPushButton(parent=Dialog)
        self.pushButton.setGeometry(QtCore.QRect(50, 220, 121, 51))
        self.pushButton.setObjectName("pushButton")
        self.checkBox = QtWidgets.QCheckBox(parent=Dialog)
        self.checkBox.setGeometry(QtCore.QRect(20, 30, 91, 19))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.checkBox.setFont(font)
        self.checkBox.setObjectName("checkBox")
        self.checkBox_2 = QtWidgets.QCheckBox(parent=Dialog)
        self.checkBox_2.setGeometry(QtCore.QRect(20, 70, 91, 19))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.checkBox_2.setFont(font)
        self.checkBox_2.setObjectName("checkBox_2")
        self.checkBox_3 = QtWidgets.QCheckBox(parent=Dialog)
        self.checkBox_3.setGeometry(QtCore.QRect(20, 110, 91, 19))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.checkBox_3.setFont(font)
        self.checkBox_3.setObjectName("checkBox_3")
        self.checkBox_4 = QtWidgets.QCheckBox(parent=Dialog)
        self.checkBox_4.setGeometry(QtCore.QRect(20, 150, 91, 19))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.checkBox_4.setFont(font)
        self.checkBox_4.setObjectName("checkBox_4")
        self.checkBox_5 = QtWidgets.QCheckBox(parent=Dialog)
        self.checkBox_5.setGeometry(QtCore.QRect(20, 190, 91, 19))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.checkBox_5.setFont(font)
        self.checkBox_5.setObjectName("checkBox_5")
        self.checkBox_6 = QtWidgets.QCheckBox(parent=Dialog)
        self.checkBox_6.setGeometry(QtCore.QRect(110, 70, 91, 19))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.checkBox_6.setFont(font)
        self.checkBox_6.setObjectName("checkBox_6")
        self.checkBox_7 = QtWidgets.QCheckBox(parent=Dialog)
        self.checkBox_7.setGeometry(QtCore.QRect(110, 110, 91, 19))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.checkBox_7.setFont(font)
        self.checkBox_7.setObjectName("checkBox_7")
        self.checkBox_8 = QtWidgets.QCheckBox(parent=Dialog)
        self.checkBox_8.setGeometry(QtCore.QRect(110, 150, 91, 19))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.checkBox_8.setFont(font)
        self.checkBox_8.setObjectName("checkBox_8")
        self.checkBox_9 = QtWidgets.QCheckBox(parent=Dialog)
        self.checkBox_9.setGeometry(QtCore.QRect(110, 190, 91, 19))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.checkBox_9.setFont(font)
        self.checkBox_9.setObjectName("checkBox_9")
        self.checkBox_10 = QtWidgets.QCheckBox(parent=Dialog)
        self.checkBox_10.setGeometry(QtCore.QRect(110, 30, 91, 19))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.checkBox_10.setFont(font)
        self.checkBox_10.setObjectName("checkBox_10")

        self.retranslateUi(Dialog)
        QtCore.QMetaObject.connectSlotsByName(Dialog)
        with open(r"style.qss", "r", encoding='utf-8') as f:
            Dialog.setStyleSheet(f.read())
        Dialog.setWindowTitle("抽屉控制")
        self.init_state()  # 初始化界面状态

    def retranslateUi(self, Dialog):
        _translate = QtCore.QCoreApplication.translate
        Dialog.setWindowTitle(_translate("Dialog", "Dialog"))
        self.pushButton.setText(_translate("Dialog", "确认"))
        self.checkBox.setText(_translate("Dialog", "抽屉1"))
        self.checkBox_2.setText(_translate("Dialog", "抽屉2"))
        self.checkBox_3.setText(_translate("Dialog", "抽屉3"))
        self.checkBox_4.setText(_translate("Dialog", "抽屉4"))
        self.checkBox_5.setText(_translate("Dialog", "抽屉5"))
        self.checkBox_6.setText(_translate("Dialog", "抽屉7"))
        self.checkBox_7.setText(_translate("Dialog", "抽屉8"))
        self.checkBox_8.setText(_translate("Dialog", "抽屉9"))
        self.checkBox_9.setText(_translate("Dialog", "抽屉10"))
        self.checkBox_10.setText(_translate("Dialog", "抽屉6"))

        # 连接确认按钮的点击事件到更新状态函数
        self.pushButton.clicked.connect(self.update_statu)