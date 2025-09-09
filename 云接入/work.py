import json
from PyQt6.QtGui import QPixmap,QImage
from PyQt6 import QtCore, QtGui, QtWidgets
from PyQt6.QtCore import QTimer,Qt
from PyQt6.QtWidgets import QVBoxLayout,QFileDialog
import numpy as np
import matplotlib.pyplot as plt 
from matplotlib.backends.backend_qtagg import FigureCanvasQTAgg as FigureCanvas
import pyttsx3
import threading
import time
import logging
import os
import time
import base64
from linkkit import linkkit
from PIL import Image
from io import BytesIO
import wave
import pyaudio
from scipy.io import wavfile
import numpy as np
from io import StringIO,BytesIO
import cv2
class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(859, 723)
        self.centralwidget = QtWidgets.QWidget(parent=MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.data_creat = QtWidgets.QGroupBox(parent=self.centralwidget)
        self.data_creat.setGeometry(QtCore.QRect(460, 390, 371, 91))
        self.data_creat.setObjectName("data_creat")
        self.creat = QtWidgets.QPushButton(parent=self.data_creat)
        self.creat.setGeometry(QtCore.QRect(260, 10, 93, 28))
        self.creat.setObjectName("creat")
        self.data_feature = QtWidgets.QComboBox(parent=self.data_creat)
        self.data_feature.setGeometry(QtCore.QRect(110, 25, 87, 22))
        self.data_feature.setObjectName("data_feature")
        self.data_feature.addItem("")
        self.data_feature.addItem("")
        self.data_feature.addItem("")
        self.data_feature.addItem("")
        self.data_feature.addItem("")
        self.label = QtWidgets.QLabel(parent=self.data_creat)
        self.label.setGeometry(QtCore.QRect(30, 30, 72, 15))
        self.label.setObjectName("label")
        self.label_2 = QtWidgets.QLabel(parent=self.data_creat)
        self.label_2.setGeometry(QtCore.QRect(10, 60, 91, 16))
        self.label_2.setObjectName("label_2")
        self.data_n = QtWidgets.QLineEdit(parent=self.data_creat)
        self.data_n.setGeometry(QtCore.QRect(110, 55, 113, 21))
        self.data_n.setObjectName("data_n")
        self.clear = QtWidgets.QPushButton(parent=self.data_creat)
        self.clear.setGeometry(QtCore.QRect(260, 50, 93, 28))
        self.clear.setObjectName("clear")
        self.groupBox_2 = QtWidgets.QGroupBox(parent=self.centralwidget)
        self.groupBox_2.setGeometry(QtCore.QRect(460, 490, 171, 171))
        self.groupBox_2.setObjectName("groupBox_2")
        self.data_p = QtWidgets.QLabel(parent=self.groupBox_2)
        self.data_p.setGeometry(QtCore.QRect(10, 20, 151, 131))
        self.data_p.setText("")
        self.data_p.setObjectName("data_p")
        self.groupBox = QtWidgets.QGroupBox(parent=self.centralwidget)
        self.groupBox.setGeometry(QtCore.QRect(440, 180, 391, 201))
        self.groupBox.setObjectName("groupBox")
        self.label_3 = QtWidgets.QLabel(parent=self.groupBox)
        self.label_3.setGeometry(QtCore.QRect(10, 30, 101, 16))
        self.label_3.setObjectName("label_3")
        self.scrollArea = QtWidgets.QScrollArea(parent=self.groupBox)
        self.scrollArea.setGeometry(QtCore.QRect(10, 60, 371, 71))
        self.scrollArea.setWidgetResizable(True)
        self.scrollArea.setObjectName("scrollArea")
        self.scrollAreaWidgetContents = QtWidgets.QWidget()
        self.scrollAreaWidgetContents.setGeometry(QtCore.QRect(0, 0, 369, 69))
        self.scrollAreaWidgetContents.setObjectName("scrollAreaWidgetContents")
        self.textinput = QtWidgets.QTextEdit(parent=self.scrollAreaWidgetContents)
        self.textinput.setGeometry(QtCore.QRect(10, 10, 351, 51))
        self.textinput.setObjectName("textinput")
        self.scrollArea.setWidget(self.scrollAreaWidgetContents)
        self.gen = QtWidgets.QPushButton(parent=self.groupBox)
        self.gen.setGeometry(QtCore.QRect(190, 150, 93, 28))
        self.gen.setObjectName("gen")
        self.pause = QtWidgets.QPushButton(parent=self.groupBox)
        self.pause.setGeometry(QtCore.QRect(290, 150, 93, 28))
        self.pause.setObjectName("pause")
        self.label_4 = QtWidgets.QLabel(parent=self.groupBox)
        self.label_4.setGeometry(QtCore.QRect(10, 140, 41, 16))
        self.label_4.setObjectName("label_4")
        self.label_5 = QtWidgets.QLabel(parent=self.groupBox)
        self.label_5.setGeometry(QtCore.QRect(100, 140, 41, 16))
        self.label_5.setObjectName("label_5")
        self.volumn = QtWidgets.QDoubleSpinBox(parent=self.groupBox)
        self.volumn.setGeometry(QtCore.QRect(10, 160, 81, 22))
        self.volumn.setObjectName("volumn")
        self.speed = QtWidgets.QDoubleSpinBox(parent=self.groupBox)
        self.speed.setGeometry(QtCore.QRect(100, 160, 81, 22))
        self.speed.setObjectName("speed")
        self.record = QtWidgets.QPushButton(parent=self.groupBox)
        self.record.setGeometry(QtCore.QRect(270, 20, 93, 28))
        self.record.setObjectName("record")
        self.groupBox_3 = QtWidgets.QGroupBox(parent=self.centralwidget)
        self.groupBox_3.setGeometry(QtCore.QRect(10, 10, 821, 161))
        self.groupBox_3.setObjectName("groupBox_3")
        self.label_6 = QtWidgets.QLabel(parent=self.groupBox_3)
        self.label_6.setGeometry(QtCore.QRect(20, 20, 61, 21))
        self.label_6.setObjectName("label_6")
        self.label_7 = QtWidgets.QLabel(parent=self.groupBox_3)
        self.label_7.setGeometry(QtCore.QRect(420, 20, 81, 21))
        self.label_7.setObjectName("label_7")
        self.label_8 = QtWidgets.QLabel(parent=self.groupBox_3)
        self.label_8.setGeometry(QtCore.QRect(20, 50, 91, 21))
        self.label_8.setObjectName("label_8")
        self.label_9 = QtWidgets.QLabel(parent=self.groupBox_3)
        self.label_9.setGeometry(QtCore.QRect(20, 90, 101, 21))
        self.label_9.setObjectName("label_9")
        self.label_10 = QtWidgets.QLabel(parent=self.groupBox_3)
        self.label_10.setGeometry(QtCore.QRect(20, 130, 121, 21))
        self.label_10.setObjectName("label_10")
        self.product_key_Edit = QtWidgets.QLineEdit(parent=self.groupBox_3)
        self.product_key_Edit.setGeometry(QtCore.QRect(120, 50, 231, 21))
        self.product_key_Edit.setObjectName("product_key_Edit")
        self.device_name_Edit = QtWidgets.QLineEdit(parent=self.groupBox_3)
        self.device_name_Edit.setGeometry(QtCore.QRect(120, 90, 231, 21))
        self.device_name_Edit.setObjectName("device_name_Edit")
        self.device_secret_Edit = QtWidgets.QLineEdit(parent=self.groupBox_3)
        self.device_secret_Edit.setGeometry(QtCore.QRect(140, 130, 271, 21))
        self.device_secret_Edit.setObjectName("device_secret_Edit")
        self.product_key_Edit_2 = QtWidgets.QLineEdit(parent=self.groupBox_3)
        self.product_key_Edit_2.setGeometry(QtCore.QRect(520, 50, 231, 21))
        self.product_key_Edit_2.setObjectName("product_key_Edit_2")
        self.device_secret_Edit_2 = QtWidgets.QLineEdit(parent=self.groupBox_3)
        self.device_secret_Edit_2.setGeometry(QtCore.QRect(540, 130, 271, 21))
        self.device_secret_Edit_2.setObjectName("device_secret_Edit_2")
        self.label_11 = QtWidgets.QLabel(parent=self.groupBox_3)
        self.label_11.setGeometry(QtCore.QRect(420, 50, 91, 21))
        self.label_11.setObjectName("label_11")
        self.label_12 = QtWidgets.QLabel(parent=self.groupBox_3)
        self.label_12.setGeometry(QtCore.QRect(420, 130, 121, 21))
        self.label_12.setObjectName("label_12")
        self.label_13 = QtWidgets.QLabel(parent=self.groupBox_3)
        self.label_13.setGeometry(QtCore.QRect(420, 90, 101, 21))
        self.label_13.setObjectName("label_13")
        self.device_name_Edit_2 = QtWidgets.QLineEdit(parent=self.groupBox_3)
        self.device_name_Edit_2.setGeometry(QtCore.QRect(520, 90, 231, 21))
        self.device_name_Edit_2.setObjectName("device_name_Edit_2")
        self.act = QtWidgets.QPushButton(parent=self.groupBox_3)
        self.act.setGeometry(QtCore.QRect(600, 10, 93, 28))
        self.act.setObjectName("act")
        self.close = QtWidgets.QPushButton(parent=self.groupBox_3)
        self.close.setGeometry(QtCore.QRect(710, 10, 93, 28))
        self.close.setObjectName("close")
        self.groupBox_4 = QtWidgets.QGroupBox(parent=self.centralwidget)
        self.groupBox_4.setGeometry(QtCore.QRect(20, 180, 411, 101))
        self.groupBox_4.setObjectName("groupBox_4")
        self.label_14 = QtWidgets.QLabel(parent=self.groupBox_4)
        self.label_14.setGeometry(QtCore.QRect(20, 30, 51, 16))
        self.label_14.setObjectName("label_14")
        self.filename = QtWidgets.QLineEdit(parent=self.groupBox_4)
        self.filename.setGeometry(QtCore.QRect(80, 20, 231, 31))
        self.filename.setObjectName("filename")
        self.upload = QtWidgets.QPushButton(parent=self.groupBox_4)
        self.upload.setGeometry(QtCore.QRect(220, 60, 93, 28))
        self.upload.setObjectName("upload")
        self.select = QtWidgets.QPushButton(parent=self.groupBox_4)
        self.select.setGeometry(QtCore.QRect(110, 60, 93, 28))
        self.select.setObjectName("select")
        self.face = QtWidgets.QLabel(parent=self.groupBox_4)
        self.face.setGeometry(QtCore.QRect(330, 20, 71, 71))
        self.face.setText("")
        self.face.setObjectName("face")
        self.groupBox_5 = QtWidgets.QGroupBox(parent=self.centralwidget)
        self.groupBox_5.setGeometry(QtCore.QRect(20, 290, 411, 381))
        self.groupBox_5.setObjectName("groupBox_5")
        self.clr_win = QtWidgets.QPushButton(parent=self.groupBox_5)
        self.clr_win.setGeometry(QtCore.QRect(280, 350, 111, 28))
        self.clr_win.setObjectName("clr_win")
        self.show_window = QtWidgets.QLabel(parent=self.groupBox_5)
        self.show_window.setGeometry(QtCore.QRect(10, 40, 381, 301))
        self.show_window.setText("")
        self.show_window.setAlignment(QtCore.Qt.AlignmentFlag.AlignLeading|QtCore.Qt.AlignmentFlag.AlignLeft|QtCore.Qt.AlignmentFlag.AlignTop)
        self.show_window.setObjectName("show_window")
        self.play = QtWidgets.QPushButton(parent=self.groupBox_5)
        self.play.setGeometry(QtCore.QRect(180, 350, 93, 28))
        self.play.setObjectName("play")
        self.groupBox_6 = QtWidgets.QGroupBox(parent=self.centralwidget)
        self.groupBox_6.setGeometry(QtCore.QRect(660, 480, 171, 181))
        self.groupBox_6.setObjectName("groupBox_6")
        self.fps = QtWidgets.QLineEdit(parent=self.groupBox_6)
        self.fps.setGeometry(QtCore.QRect(60, 40, 71, 21))
        self.fps.setObjectName("fps")
        self.label_15 = QtWidgets.QLabel(parent=self.groupBox_6)
        self.label_15.setGeometry(QtCore.QRect(10, 30, 41, 31))
        self.label_15.setObjectName("label_15")
        self.time = QtWidgets.QLineEdit(parent=self.groupBox_6)
        self.time.setGeometry(QtCore.QRect(60, 80, 71, 21))
        self.time.setText("")
        self.time.setObjectName("time")
        self.label_16 = QtWidgets.QLabel(parent=self.groupBox_6)
        self.label_16.setGeometry(QtCore.QRect(10, 70, 41, 31))
        self.label_16.setObjectName("label_16")
        self.creat_vedio = QtWidgets.QPushButton(parent=self.groupBox_6)
        self.creat_vedio.setGeometry(QtCore.QRect(70, 140, 93, 28))
        self.creat_vedio.setObjectName("creat_vedio")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(parent=MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 859, 26))
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
        self.data_creat.setTitle(_translate("MainWindow", "数据生成"))
        self.creat.setText(_translate("MainWindow", "生成并保存"))
        self.data_feature.setItemText(0, _translate("MainWindow", "正态分布"))
        self.data_feature.setItemText(1, _translate("MainWindow", "二项分布"))
        self.data_feature.setItemText(2, _translate("MainWindow", "指数分布"))
        self.data_feature.setItemText(3, _translate("MainWindow", "泊松分布"))
        self.data_feature.setItemText(4, _translate("MainWindow", "正弦函数"))
        self.label.setText(_translate("MainWindow", "数据类型:"))
        self.label_2.setText(_translate("MainWindow", "数据点个数:"))
        self.clear.setText(_translate("MainWindow", "清空"))
        self.groupBox_2.setTitle(_translate("MainWindow", "数据展示"))
        self.groupBox.setTitle(_translate("MainWindow", "音频文件生成"))
        self.label_3.setText(_translate("MainWindow", "输入音频文本:"))
        self.gen.setText(_translate("MainWindow", "朗读并保存"))
        self.pause.setText(_translate("MainWindow", "暂停"))
        self.label_4.setText(_translate("MainWindow", "音量:"))
        self.label_5.setText(_translate("MainWindow", "语速:"))
        self.record.setText(_translate("MainWindow", "录制音频"))
        self.groupBox_3.setTitle(_translate("MainWindow", "设备信息"))
        self.label_6.setText(_translate("MainWindow", "Sender:"))
        self.label_7.setText(_translate("MainWindow", "Receiver:"))
        self.label_8.setText(_translate("MainWindow", "ProductKey:"))
        self.label_9.setText(_translate("MainWindow", "device_name:"))
        self.label_10.setText(_translate("MainWindow", "device_secret:"))
        self.product_key_Edit.setText(_translate("MainWindow", "k12fzeyE9hO"))
        self.device_name_Edit.setText(_translate("MainWindow", "Sender"))
        self.device_secret_Edit.setText(_translate("MainWindow", "aa4263394478895dccc6fdb6f5deeb94"))
        self.product_key_Edit_2.setText(_translate("MainWindow", "k12fzeyE9hO"))
        self.device_secret_Edit_2.setText(_translate("MainWindow", "f7683788602750bbe74f349c4ee3afbc"))
        self.label_11.setText(_translate("MainWindow", "ProductKey:"))
        self.label_12.setText(_translate("MainWindow", "device_secret:"))
        self.label_13.setText(_translate("MainWindow", "device_name:"))
        self.device_name_Edit_2.setText(_translate("MainWindow", "Receiver"))
        self.act.setText(_translate("MainWindow", "激活"))
        self.close.setText(_translate("MainWindow", "关闭"))
        self.groupBox_4.setTitle(_translate("MainWindow", "数据上传"))
        self.label_14.setText(_translate("MainWindow", "文件名:"))
        self.upload.setText(_translate("MainWindow", "上传"))
        self.select.setText(_translate("MainWindow", "选择文件"))
        self.groupBox_5.setTitle(_translate("MainWindow", "数据接收与展示"))
        self.clr_win.setText(_translate("MainWindow", "清空/暂停播放"))
        self.play.setText(_translate("MainWindow", "展示"))
        self.groupBox_6.setTitle(_translate("MainWindow", "视频生成"))
        self.label_15.setText(_translate("MainWindow", "fps:"))
        self.label_16.setText(_translate("MainWindow", "time:"))
        self.creat_vedio.setText(_translate("MainWindow", "生成并保存"))
        self.speed.setMaximum(1000)
        self.speed.setMinimum(0)
        self.volumn.setMaximum(10)
        self.volumn.setMinimum(0)
        self.engine = pyttsx3.init()  # 初始化语音引擎
        self.data_n.textChanged.connect(self.showText)
        self.filename.textChanged.connect(self.showText)
        self.time.textChanged.connect(self.showText)
        self.fps.textChanged.connect(self.showText)
        self.creat.clicked.connect(self.get_data)
        self.clear.clicked.connect(self.clearF)
        #self.clear_vedio.clicked.connect(self.clearF)
        self.gen.clicked.connect(self.music)
        self.pause.clicked.connect(self.pauseF)
        self.upload.clicked.connect(self.uploadF)
        self.act.clicked.connect(self.actF)
        self.close.clicked.connect(self.closeF)
        self.is_running=None
        self.mode=0
        self.clr_win.clicked.connect(self.close_win)
        self.play.clicked.connect(self.playF)
        self.select.clicked.connect(self.selectFile)
        self.creat_vedio.clicked.connect(self.make_vedio)
        self.record.clicked.connect(self.recordF)
    def recordF(self):
        audio = pyaudio.PyAudio()
        FORMAT = pyaudio.paInt16  # 16位深度
        CHANNELS = 1  # 单声道
        RATE = 44100  # 采样率
        CHUNK = 1024  # 每个缓冲区的帧数
        RECORD_SECONDS = 5  # 录制时长
        BITRATE = "16k" 
        # 打开音频流
        stream = audio.open(format=pyaudio.paInt16,
                            channels=1,
                            rate=44100,
                            input=True,
                            frames_per_buffer=1024)
        print("开始录制...")
        frames = []
        for i in range(0, int(RATE / CHUNK * RECORD_SECONDS)):
            data = stream.read(CHUNK)
            frames.append(data)
        print("录制结束")
        stream.stop_stream()
        stream.close()
        audio.terminate()
        wf = wave.open('text.wav', 'wb')
        wf.setnchannels(CHANNELS)
        wf.setsampwidth(audio.get_sample_size(FORMAT))
        wf.setframerate(RATE)
        wf.writeframes(b''.join(frames))
        wf.close()
        
    def make_vedio(self):
        duration=int(self.time.text())
        fps=int(self.fps.text())
        width,height=100,100
        total_frames=fps*duration
        outpath='test.mp4'
        fourcc=cv2.VideoWriter_fourcc(*'mp4v')
        out=cv2.VideoWriter(outpath,fourcc,fps,(width,height))
        for i in range(total_frames):
            frame=np.zeros((height,width,3),dtype=np.uint8)
            # 创建颜色变化
            r = (i * 255 // total_frames) % 256
            g = ((i * 2) * 255 // total_frames) % 256
            b = ((i * 3) * 255 // total_frames) % 256
            frame[:]=[b,g,r]    
            out.write(frame)
        out.release()
    def selectFile(self):
        file_dialog = QFileDialog()
        path, _ = file_dialog.getOpenFileName(None, "选择文件", "")
        self.path=path
        self.filename.setText(path)
    def play_audio(self,wf):
            data = wf.readframes(1024)
            while data and self.is_playing and self.stream:
                self.stream.write(data)
                data = wf.readframes(1024)
            if self.stream:
                self.stream.stop_stream()
                self.stream.close()
                self.stream=None
            if self.p:
                self.p.terminate()
                self.p=None
            self.is_playing = False
    def playAudio(self):
        self.stream=None
        self.p=None
        self.is_playing=False
        file_path = "temp.mp3"
        self.p=pyaudio.PyAudio()
        wf=wave.open(file_path,'rb')
        self.stream = self.p.open(format=self.p.get_format_from_width(wf.getsampwidth()),
                        channels=wf.getnchannels(),
                        rate=wf.getframerate(),
                        output=True)
        self.is_playing=True
        threading.Thread(target=self.play_audio,args=(wf,)).start() 
           
        sample_rate, audio_data = wavfile.read(file_path)
        if len(audio_data.shape) > 1:
            audio_data=audio_data[:, 0]
        fig,ax=plt.subplots(figsize=(10,10))
        ax.plot(np.arange(len(audio_data))/sample_rate,audio_data)
        fig.savefig("wave.jpg")
        pixmap=QPixmap(r"wave.jpg")
        self.show_window.setPixmap(pixmap)
        self.show_window.setScaledContents(True)
    def update_frame(self,cap):
        ret,frame=cap.read()
        if not ret:
            self.timer.stop()
            cap.release()
            return
        rgb_image = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        h, w, ch = rgb_image.shape
        bytes_per_line = ch * w
        qt_image = QImage(rgb_image.data, w, h, bytes_per_line, QImage.Format.Format_RGB888)

        # 将 QImage 转换为 QPixmap 并显示
        pixmap = QPixmap.fromImage(qt_image)
        pixmap = pixmap.scaled(350, 300)  # 缩放图像
        self.show_window.setPixmap(pixmap)
        self.show_window.setScaledContents(True)
    def play_vedio(self):
        path="temp.mp4"
        self.cap=cv2.VideoCapture(path)
        self.timer=QTimer()
        self.timer.timeout.connect(lambda:self.update_frame(self.cap))
        self.timer.start(30)
    def playF(self):
        self.show_window.clear()
        if self.type=="image":
            pixmap=QPixmap(r"temp.jpg")
            self.show_window.setPixmap(pixmap)
            self.show_window.setScaledContents(True)
        elif self.type=="audio":
            self.playAudio()
        elif self.type=="word":
            with open('temp.txt','r',encoding='utf-8') as f:
                    text=f.read()
            self.show_window.setText(text)
        elif self.type=="mp4":
            self.play_vedio()
    def close_win(self):
        self.is_playing=False
        if self.timer.isActive():
            self.timer.stop()
        if self.cap:
            self.cap.release()
        self.show_window.clear()
    def closeF(self):
        self.is_running=False
        if os.path.exists('temp.mp4'):
            os.remove('temp.mp4')
        if os.path.exists('temp.txt'):
            os.remove('temp.txt')
        if os.path.exists('temp.mp3'):
            os.remove('temp.mp3')
        if os.path.exists('temp.wav'):
            os.remove('temp.wav')
        if os.path.exists('temp.jpg'):
            os.remove('temp.jpg')
    def uploadF(self):
        target=self.product_key_Edit_2.text()
        __log_format = "%(asctime)s-%(process)d-%(thread)d - %(name)s:%(module)s:%(funcName)s - %(levelname)s - %(message)s"
        logging.basicConfig(format=__log_format)
            # Sender 设备信息
        sender_product_key = self.product_key_Edit.text()
        sender_device_name = self.device_name_Edit.text()
        sender_device_secret = self.device_secret_Edit.text()
        #self.check()
        lk_sender = linkkit.LinkKit(
            host_name="cn-shanghai",
            product_key=sender_product_key,
            device_name=sender_device_name,
            device_secret=sender_device_secret,
        )     
        lk_sender.config_mqtt(
            port=8883,
            protocol="MQTTv311",
            transport="TCP",
            secure="TLS",
            keep_alive=60,
            clean_session=True,
            max_inflight_message=20,
            max_queued_message=0,
            auto_reconnect_min_sec=1,
            auto_reconnect_max_sec=60,
            cadata=None,
        ) 
        lk_sender.connect_async()
        file=self.filename.text()
        if os.path.exists(file):
            # pixmap=QPixmap("green.png")
            # self.label_face.setPixmap(pixmap)
            # self.label_face.setScaledContents(True)
            name,type=file.split(".")
            time.sleep(1)
            print("Sender正在运行")
            if type=="jpg" or type =="png" or type=="jpeg" or type =="gif":
                self.mode=1
                with open(file, "rb") as f:
                    image_base64 = base64.b64encode(f.read()).decode("utf-8")
                topic = f"/{sender_product_key}/{sender_device_name}/user/update"
                payload = f'{{"type":"image","data":"{image_base64}"}}'
                lk_sender.publish_topic(topic, payload)
            elif type=="mp3" or type=="wav":
                self.mode=2
                with open(file,'rb') as f:
                    audio_base64 = base64.b64encode(f.read()).decode("utf-8")
                topic = f"/{sender_product_key}/{sender_device_name}/user/update"
                payload = f'{{"type":"audio","data":"{audio_base64}"}}'
                lk_sender.publish_topic(topic, payload)
            elif type=="txt":
                self.mode=3
                with open(file,'rb') as f:
                    word_base64=base64.b64encode(f.read()).decode('utf-8')
                topic = f"/{sender_product_key}/{sender_device_name}/user/update"
                payload = f'{{"type":"word","data":"{word_base64}"}}'
                lk_sender.publish_topic(topic, payload)   
            elif type=='mp4':
                self.mode=4
                with open(file,'rb') as f:
                    video_base64=base64.b64encode(f.read()).decode('utf-8')
                topic = f"/{target}/{sender_device_name}/user/update"
                payload = f'{{"type":"mp4","data":"{video_base64}"}}'
                lk_sender.publish_topic(topic, payload)  
            print("上传成功")
            time.sleep(2)
            lk_sender.disconnect()
        else:
            self.filename.setText("文件名不正确")
    def act_Receiver(self):
        logging.basicConfig(level=logging.INFO, format="%(asctime)s - %(levelname)s - %(message)s")
        logger = logging.getLogger(__name__)
        # Receiver 设备信息
        receiver_product_key = self.product_key_Edit_2.text()
        receiver_device_name = self.device_name_Edit_2.text()
        receiver_device_secret = self.device_secret_Edit_2.text()
        lk_receiver = linkkit.LinkKit(
            host_name="cn-shanghai",
            product_key=receiver_product_key,
            device_name=receiver_device_name,
            device_secret=receiver_device_secret,
        )
        # 配置 MQTT
        lk_receiver.config_mqtt(
            endpoint=f"{receiver_product_key}.iot-as-mqtt.cn-shanghai.aliyuncs.com",
            port=8883,
            protocol="MQTTv311",
            transport="TCP",
            secure="TLS",
            keep_alive=60,
            clean_session=True,
            max_inflight_message=20,
            max_queued_message=0,
            auto_reconnect_min_sec=1,
            auto_reconnect_max_sec=60,
            cadata=None,
        )
        topic = f"/{receiver_product_key}/{receiver_device_name}/user/get"
        lk_receiver.subscribe_topic(topic, qos=1)
        logger.info(f"Receiver: Subscribed to topic: {topic}")
        # 消息回调函数
        def on_topic_message(topic, payload, qos, userdata): # 当接收到数据时，会调用此函数
            print(payload)
            pixmap=QPixmap('green.png')
            self.face.setScaledContents(True)
            self.face.setPixmap(pixmap)
            if isinstance(payload,bytes):
                data = json.loads(payload.decode("utf-8"))
            self.type=data.get("type")
            context=data.get("data")
            if self.type=="image":
                img_data=base64.b64decode(context)
                image=Image.open(BytesIO(img_data))
                if os.path.exists('temp.jpg'):
                    os.remove('temp.jpg')
                image.save('temp.jpg')
                pass
            elif self.type=="audio":
                audio_data=base64.b64decode(context)
                audio_buffer=BytesIO(audio_data)
                if os.path.exists('temp.mp3'):
                    os.remove('temp.mp3')
                with open('temp.mp3','wb',buffering=1024 * 1024) as f:
                    f.write(audio_buffer.getvalue())
                pass
            elif self.type=="word":
                
                word_data=base64.b64decode(context).decode('utf-8')

                text_buffer=StringIO(word_data)
                if os.path.exists('temp.txt'):
                    os.remove('temp.txt')
                with open('temp.txt','w',encoding='utf-8',buffering=1024 * 1024) as f:
                    f.write(text_buffer.getvalue())
                pass
            elif self.type=="mp4":
                video_data=base64.b64decode(context)
                with open('temp.mp4','wb') as f:
                    f.write(video_data)
                pass
            self.face.clear()
        # 注册消息回调函数
        lk_receiver.on_topic_message = on_topic_message
        # 异步连接设备
        lk_receiver.connect_async()
        time.sleep(3)  # 等待连接完成
        self.is_running=True
        self.act.setStyleSheet("color:red;")
        # 保持运行
        while self.is_running:
            time.sleep(5)
        lk_receiver.disconnect()
        self.act.setStyleSheet("color:black;")
        print("已关闭")
    def actF(self):
        self.receiver_thread = threading.Thread(target=self.act_Receiver)
        # 启动线程
        #sender_thread.start()
        self.receiver_thread.start()   
    def showText(self):
        self.data_n.setText(self.data_n.text())
        self.filename.setText(self.filename.text())
        self.time.setText(self.time.text())
        self.fps.setText(self.fps.text())
    def pauseF(self):
        self.engine.stop()
    def music(self):
        vol=self.volumn.value()
        speed=self.speed.value()
        text=self.textinput.toPlainText()
        self.engine.setProperty('rate', speed)  # 设置语速
        self.engine.setProperty('volume', vol)  # 设置音量
        voices = self.engine.getProperty('voices')
        id=''
        for voice in voices:
            if 'ZH-CN' in voice.id:
                id=voice.id
                break 
        self.engine.setProperty('voice',id) 
        self.engine.say(text)
        self.engine.save_to_file(text,'text.mp3')
        if os.path.exists('word.txt'):
            os.remove('word.txt')
        with open('word.txt','w',encoding='utf-8') as f:
            f.write(text)
        self.engine.runAndWait()
        self.engine.stop()   
    def clearF(self):
        def del_layout(self,layout):
            if layout is not None:
                for i in reversed(range(layout.count())):
                    widget = layout.itemAt(i).widget()
                    if widget is not None:
                        widget.deleteLater()  # 删除控件
                layout.deleteLater()
        del_layout(self,self.data_p.layout())
    def get_data(self):
        n=int(self.data_n.text())
        mode=self.data_feature.currentIndex()
        if mode==0:
            data=np.random.normal(0,1,n)
        elif mode==1:
            data=np.random.binomial(10,0.5,size=n)
        elif mode==2:
            data=np.random.exponential(2,size=n)
        elif mode==3:
            lam=10
            data=np.random.poisson(lam,n)
        elif mode==4:
            t=np.linspace(1,n,n)
            data=np.sin(t)
        fig,ax=plt.subplots(figsize=(10,10))
        plt.tight_layout()
        plt.plot(data)
        canvas=FigureCanvas(fig)
        self.fig=fig
        layout=QtWidgets.QVBoxLayout(self.data_p)
        layout.addWidget(canvas)
        self.data_p.setLayout(layout)
        canvas.draw()
        fig.savefig('fig.jpg')
if __name__=="__main__":
    import sys
    app=QtWidgets.QApplication(sys.argv)
    Server=QtWidgets.QMainWindow()
    ui=Ui_MainWindow()
    ui.setupUi(Server)
    Server.show()
    sys.exit(app.exec())