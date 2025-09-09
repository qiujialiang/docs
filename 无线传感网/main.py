from PyQt6 import QtCore, QtGui, QtWidgets
import serial
import threading
import receive
import pymysql
Attributes = {
    'OrigiSrcAddr': 0x00,   # 源地址（读卡器地址）
    'DestAddr': 0x00,   # 目的地址（sink地址）
    'Seq': 0x00,    # 数据包的序列号
    'tempture': 0xFF,   # 温度数据
    'Humi': 0xFF,   # 湿度数据
    'Photo': b'\xFF\xFF',   # 光照数据
    'Error': 0x00,  # 读取标签是否成功 （0:成功， 2:失败）
    'CardData': b'\xFF\xFF\xFF\xFF',    # 标签信息
    'FrameType': 0x00,  # 数据帧类型（1：光照，2：温湿度，3：标签信息）
}

port='COM5'
bps=57600
ser = serial.Serial(port, bps,timeout=None)



class Ui_MainWindow(object):
    def __init__(self):
        self.Attributes = Attributes
    def open(self):
        self.pushButton.setEnabled(False)
        self.pushButton_2.setEnabled(True)
        self.receive_thread = threading.Thread(target=receive.receive, args=(self, ser))
        self.receive_thread.daemon = True
        self.receive_thread.start()
        
    def close(self):
        ser.close()
        self.pushButton.setEnabled(True)
        self.pushButton_2.setEnabled(False)
        self.lineEdit.clear()
        self.lineEdit_4.clear()
        self.lineEdit_2.clear()
        self.lineEdit_3.clear()
        self.tableWidget
    
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(681, 659)
        self.centralwidget = QtWidgets.QWidget(parent=MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.tableWidget = QtWidgets.QTableWidget(parent=self.centralwidget)
        self.tableWidget.setGeometry(QtCore.QRect(20, 160, 631, 431))
        self.tableWidget.setObjectName("tableWidget")
        self.tableWidget.setColumnCount(5)
        self.tableWidget.setRowCount(0)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget.setHorizontalHeaderItem(0, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget.setHorizontalHeaderItem(1, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget.setHorizontalHeaderItem(2, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget.setHorizontalHeaderItem(3, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget.setHorizontalHeaderItem(4, item)
        self.groupBox = QtWidgets.QGroupBox(parent=self.centralwidget)
        self.groupBox.setGeometry(QtCore.QRect(20, 30, 631, 111))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.groupBox.setFont(font)
        self.groupBox.setObjectName("groupBox")
        self.label = QtWidgets.QLabel(parent=self.groupBox)
        self.label.setGeometry(QtCore.QRect(20, 30, 72, 31))
        self.label.setObjectName("label")
        self.label_2 = QtWidgets.QLabel(parent=self.groupBox)
        self.label_2.setGeometry(QtCore.QRect(220, 30, 72, 31))
        self.label_2.setObjectName("label_2")
        self.label_3 = QtWidgets.QLabel(parent=self.groupBox)
        self.label_3.setGeometry(QtCore.QRect(420, 30, 72, 31))
        self.label_3.setObjectName("label_3")
        self.lineEdit = QtWidgets.QLineEdit(parent=self.groupBox)
        self.lineEdit.setGeometry(QtCore.QRect(80, 30, 113, 31))
        self.lineEdit.setObjectName("lineEdit")
        self.lineEdit_2 = QtWidgets.QLineEdit(parent=self.groupBox)
        self.lineEdit_2.setGeometry(QtCore.QRect(290, 30, 113, 31))
        self.lineEdit_2.setObjectName("lineEdit_2")
        self.lineEdit_3 = QtWidgets.QLineEdit(parent=self.groupBox)
        self.lineEdit_3.setGeometry(QtCore.QRect(480, 30, 113, 31))
        self.lineEdit_3.setObjectName("lineEdit_3")
        self.label_4 = QtWidgets.QLabel(parent=self.groupBox)
        self.label_4.setGeometry(QtCore.QRect(20, 70, 91, 31))
        self.label_4.setObjectName("label_4")
        self.lineEdit_4 = QtWidgets.QLineEdit(parent=self.groupBox)
        self.lineEdit_4.setGeometry(QtCore.QRect(120, 70, 113, 31))
        self.lineEdit_4.setObjectName("lineEdit_4")
        self.pushButton = QtWidgets.QPushButton(parent=self.groupBox)
        self.pushButton.setGeometry(QtCore.QRect(400, 70, 93, 28))
        self.pushButton.setObjectName("pushButton")
        self.pushButton_2 = QtWidgets.QPushButton(parent=self.groupBox)
        self.pushButton_2.setGeometry(QtCore.QRect(510, 70, 93, 28))
        self.pushButton_2.setObjectName("pushButton_2")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(parent=MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 681, 26))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(parent=MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        with open(r"style.qss", "r",encoding='utf-8') as f:
            MainWindow.setStyleSheet(f.read())
        MainWindow.setWindowTitle("无线传感网络数据收集系统") 
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        header = self.tableWidget.horizontalHeader()
        if header is not None:
            header.setSectionResizeMode(QtWidgets.QHeaderView.ResizeMode.Stretch)
        item = self.tableWidget.horizontalHeaderItem(0)
        if item is not None:
            item.setText(_translate("MainWindow", "源地址"))
        item = self.tableWidget.horizontalHeaderItem(1)
        if item is not None:
            item.setText(_translate("MainWindow", "目的地址"))
        item = self.tableWidget.horizontalHeaderItem(2)
        if item is not None:
            item.setText(_translate("MainWindow", "Seq"))
        item = self.tableWidget.horizontalHeaderItem(3)
        if item is not None:
            item.setText(_translate("MainWindow", "CardData"))
        item = self.tableWidget.horizontalHeaderItem(4)
        if item is not None:
            item.setText(_translate("MainWindow", "Type"))
        self.groupBox.setTitle(_translate("MainWindow", "数据采集模块"))
        self.label.setText(_translate("MainWindow", "温度："))
        self.label_2.setText(_translate("MainWindow", "湿度："))
        self.label_3.setText(_translate("MainWindow", "照度："))
        self.label_4.setText(_translate("MainWindow", "标签数据："))
        self.pushButton.setText(_translate("MainWindow", "开启"))
        self.pushButton_2.setText(_translate("MainWindow", "关闭"))
        
        self.pushButton.clicked.connect(self.open)
        self.pushButton_2.clicked.connect(self.close)
        

if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec())