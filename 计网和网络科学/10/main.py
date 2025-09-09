import socket
from PyQt6 import QtCore, QtGui, QtWidgets
from PyQt6.QtCore import *
class Thread(QtCore.QThread):
    message=QtCore.pyqtSignal(int,str,str,tuple,str)
    ID=[]
    server_socket=None
    def __init__(self):
        super().__init__()
        print("启动")
        self.server_socket=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
        self.server_socket.bind(('',8080))
        print("启动成功")
    def run(self):
        while True:
            rece_tep,addr=self.server_socket.recvfrom(1024)
            rece_light,addr=self.server_socket.recvfrom(1024)
            rece_wet,addr=self.server_socket.recvfrom(1024)
            id,addr=self.server_socket.recvfrom(1024)
            data_tep=rece_tep.decode('utf-8')
            data_light=rece_light.decode('utf-8')
            data_wet=rece_wet.decode('utf-8')
            data_id=id.decode('utf-8')
            print(f"ip地址为{addr}:温度{data_tep}/光照{data_light}/湿度{data_wet}/ID{data_id}")
            if data_light=='#' or data_tep=='#' or data_wet=='#':
                break
            if data_light<="400":
                self.server_socket.sendto(b"1",addr)
                self.server_socket.sendto(data_id.encode('utf-8'),addr)
                self.bind(data_id,addr,(data_tep,data_wet,data_light),'open')
            else:
                self.server_socket.sendto(b"0",addr)
                self.server_socket.sendto(data_id.encode('utf-8'),addr)
                self.bind(data_id,addr,(data_tep,data_wet,data_light),'close')
    def bind(self,id,addr,data,status):
        if id in self.ID:
            self.message.emit(self.ID.index(id),addr[0],id,data,status)
        else:
            if len(self.ID)<3:
                self.ID.append(id)
                self.message.emit(self.ID.index(id),addr[0],id,data,status)
            else:
                self.message.emit(-1,(),"")
class Ui_Server(object):
    ID=[]
    STATUS=[]
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(800, 600)
        self.centralwidget = QtWidgets.QWidget(parent=MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.label_f1 = QtWidgets.QLabel(parent=self.centralwidget)
        self.label_f1.setGeometry(QtCore.QRect(50, 30, 201, 51))
        font = QtGui.QFont()
        font.setPointSize(15)
        self.label_f1.setFont(font)
        self.label_f1.setObjectName("label_f1")
        self.label_f3 = QtWidgets.QLabel(parent=self.centralwidget)
        self.label_f3.setGeometry(QtCore.QRect(50, 230, 201, 51))
        font = QtGui.QFont()
        font.setPointSize(15)
        self.label_f3.setFont(font)
        self.label_f3.setObjectName("label_f3")
        self.label_f2 = QtWidgets.QLabel(parent=self.centralwidget)
        self.label_f2.setGeometry(QtCore.QRect(450, 30, 201, 51))
        font = QtGui.QFont()
        font.setPointSize(15)
        self.label_f2.setFont(font)
        self.label_f2.setObjectName("label_f2")
        self.label_total = QtWidgets.QLabel(parent=self.centralwidget)
        self.label_total.setGeometry(QtCore.QRect(450, 230, 201, 51))
        font = QtGui.QFont()
        font.setPointSize(15)
        self.label_total.setFont(font)
        self.label_total.setObjectName("label_total")
        self.label_statu = QtWidgets.QLabel(parent=self.centralwidget)
        self.label_statu.setGeometry(QtCore.QRect(10, 500, 250, 40))
        font = QtGui.QFont()
        font.setPointSize(20)
        self.label_statu.setFont(font)
        self.label_statu.setObjectName("label_statu")
        self.label_isON = QtWidgets.QLabel(parent=self.centralwidget)
        self.label_isON.setGeometry(QtCore.QRect(280, 500, 50, 40))
        font = QtGui.QFont()
        font.setPointSize(15)
        self.label_isON.setFont(font)
        self.label_isON.setObjectName("label_isON")
        self.pushButton_ON = QtWidgets.QPushButton(parent=self.centralwidget)
        self.pushButton_ON.setGeometry(QtCore.QRect(600, 430, 150, 50))
        font = QtGui.QFont()
        font.setPointSize(15)
        self.pushButton_ON.setFont(font)
        self.pushButton_ON.setObjectName("pushButton_ON")
        self.pushButton_OUT = QtWidgets.QPushButton(parent=self.centralwidget)
        self.pushButton_OUT.setGeometry(QtCore.QRect(600, 500, 150, 50))
        font = QtGui.QFont()
        font.setPointSize(15)
        self.pushButton_OUT.setFont(font)
        self.pushButton_OUT.setObjectName("pushButton_OUT")
        self.textBrowser_f1 = QtWidgets.QTextBrowser(parent=self.centralwidget)
        self.textBrowser_f1.setGeometry(QtCore.QRect(50, 70, 200, 150))
        font = QtGui.QFont()
        font.setPointSize(15)
        self.textBrowser_f1.setFont(font)
        self.textBrowser_f1.setObjectName("textBrowser_f1")
        self.textBrowser_f3 = QtWidgets.QTextBrowser(parent=self.centralwidget)
        self.textBrowser_f3.setGeometry(QtCore.QRect(50, 270, 200, 150))
        font = QtGui.QFont()
        font.setPointSize(15)
        self.textBrowser_f3.setFont(font)
        self.textBrowser_f3.setObjectName("textBrowser_f3")
        self.textBrowser_f2 = QtWidgets.QTextBrowser(parent=self.centralwidget)
        self.textBrowser_f2.setGeometry(QtCore.QRect(450, 70, 200, 150))
        font = QtGui.QFont()
        font.setPointSize(15)
        self.textBrowser_f2.setFont(font)
        self.textBrowser_f2.setObjectName("textBrowser_f2")
        self.label_res1 = QtWidgets.QLabel(parent=self.centralwidget)
        self.label_res1.setGeometry(QtCore.QRect(450, 280, 200, 30))
        font = QtGui.QFont()
        font.setPointSize(15)
        self.label_res1.setFont(font)
        self.label_res1.setObjectName("label_res1")
        self.label_res2 = QtWidgets.QLabel(parent=self.centralwidget)
        self.label_res2.setGeometry(QtCore.QRect(450, 320, 200, 30))
        font = QtGui.QFont()
        font.setPointSize(15)
        self.label_res2.setFont(font)
        self.label_res2.setObjectName("label_res2")
        self.label_res3 = QtWidgets.QLabel(parent=self.centralwidget)
        self.label_res3.setGeometry(QtCore.QRect(450, 360, 200, 30))
        font = QtGui.QFont()
        font.setPointSize(15)
        self.label_res3.setFont(font)
        self.label_res3.setObjectName("label_res3")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(parent=MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 800, 26))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(parent=MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.label_f1.setText(_translate("MainWindow", "设备ID"))
        self.label_f3.setText(_translate("MainWindow", "设备ID"))
        self.label_f2.setText(_translate("MainWindow", "设备ID"))
        self.label_total.setText(_translate("MainWindow", "设备信息"))
        self.label_statu.setText(_translate("MainWindow", "当前服务器状态:"))
        self.label_isON.setText(_translate("MainWindow", "关机"))
        self.pushButton_ON.setText(_translate("MainWindow", "开机"))
        self.pushButton_OUT.setText(_translate("MainWindow", "关机"))
        self.label_res1.setText(_translate("MainWindow", "设备不存在"))
        self.label_res2.setText(_translate("MainWindow", "设备不存在"))
        self.label_res3.setText(_translate("MainWindow", "设备不存在"))
        self.pushButton_ON.clicked.connect(self.start)
        self.pushButton_OUT.clicked.connect(self.end)
    def start(self):
        if self.label_isON.text()=="关机":
            self.label_isON.setText("开机")
            self.thread=Thread()
            self.thread.start()
            self.thread.message.connect(self.display)
        elif self.label_isON.text()=="开机":
            return
    def end(self):
        if self.label_isON.text()=="开机":
            if self.socketThread is not None:
                self.thread=None
                self.label_isON.setText("关机")
                self.textBrowser_f1.setText("")
                self.textBrowser_f2.setText("")
                self.textBrowser_f3.setText("")
                self.textBrowser_f4.setText("")
                self.label_f1.setText("设备ID:")
                self.label_f2.setText("设备ID:")
                self.label_f3.setText("设备ID:")
                self.ID=[]
        elif self.label_isON.text()=="关机":
            return
    def display(self,event,ip,id,data,status):
        if id and id not in self.ID and status=='open':
            self.ID.append(id)
        if event==0:
                self.label_f1.setText("设备1  "+str(id))
                self.label_res1.setText("id:"+str(id)+"  "+"状态:"+status)
                self.textBrowser_f1.setText("温度:"+str(data[0])+"摄氏度"+'\n'
                                            +"湿度:"+str(data[1])+"%"+'\n'
                                            +"亮度:"+str(data[2]+"勒克斯"))
        elif event==1:
                self.label_f2.setText("设备2  "+str(id))
                self.label_res2.setText("id:"+str(id)+"  "+"状态:"+status)
                self.textBrowser_f2.setText("温度:"+str(data[0])+"摄氏度"+'\n'
                                            +"湿度:"+str(data[1])+"%"+'\n'
                                            +"亮度:"+str(data[2]+"勒克斯"))
        elif event==2:
                self.label_f3.setText("设备3  "+str(id))
                self.label_res3.setText("id:"+str(id)+"  "+"状态:"+status)
                self.textBrowser_f3.setText("温度:"+str(data[0])+"摄氏度"+'\n'
                                            +"湿度:"+str(data[1])+"%"+'\n'
                                            +"亮度:"+str(data[2]+"勒克斯"))
if __name__=="__main__":
    import sys
    app=QtWidgets.QApplication(sys.argv)
    Server=QtWidgets.QMainWindow()
    ui=Ui_Server()
    ui.setupUi(Server)
    Server.show()
    sys.exit(app.exec())