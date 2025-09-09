import struct
from PyQt6 import QtWidgets
def Attributes_set(self, OrigiSrcAddr, DestAddr, Seq, tempture, Humi, Photo, FrameType, Error, CardData):
        self.Attributes.update({
            'OrigiSrcAddr': OrigiSrcAddr,
            'DestAddr': DestAddr,
            'Seq': Seq,
            'tempture': tempture,
            'Humi': Humi,
            'Photo': Photo,
            'FrameType': FrameType,
            'Error': Error,
            'CardData': CardData
        })
        
def FrameType_rename(FrameType):  # 数据帧种类
    if FrameType == 1:
        return '读取光照数据'
    elif FrameType == 2:
        return '读取温湿度数据'
    elif FrameType == 3:
        return '读取标签信息'


def CardData_to_string(self,CardData):  # 将标签数据转换为字符串（字节流转化为整数）
    CardData = struct.unpack('4B', CardData)
    if (self.Attributes['Error'] == 0):  # 如果读取标签成功
        string = ""
        for i in range(0, len(CardData)):
            if CardData[i] > 9:
                string += str(chr(CardData[i])) + ' '
            else:
                string += str(CardData[i]) + ' '
        return string
    else:   # 读取标签数据失败
        return 'None'

def receive(self, ser):  # 接收线程
    while(True):
        if self.pushButton_2.isEnabled():  # 如果已经开机
            Frame = ser.read(24)    # 接收24B数据
            if len(Frame)!=24:
                print("error")
                continue
            # 保留接收到的数据帧有效字段
            Attributes_set(self, Frame[0], Frame[2], Frame[8], Frame[12], Frame[14],
                    Frame[16:18], Frame[18], Frame[19], Frame[20:])
            # 处理接收到的数据帧数据
            self.Attributes['Photo'] = struct.unpack('H', self.Attributes['Photo'])[0]
            self.Attributes['FrameType'] = FrameType_rename(self.Attributes['FrameType'])
            self.Attributes['CardData'] = CardData_to_string(self,self.Attributes['CardData'])
            # 更新UI界面
            updateUI(self, self.Attributes)

def updateUI(self, attributes):
    # 更新 QLineEdit 显示当前数据
    self.lineEdit.setText(str(attributes['tempture']))     # 温度
    self.lineEdit_2.setText(str(attributes['Humi']))       # 湿度
    self.lineEdit_3.setText(str(attributes['Photo']))      # 光照
    self.lineEdit_4.setText(str(attributes['CardData']))   # 标签数据

    # 表格添加一行
    row_position = self.tableWidget.rowCount()
    self.tableWidget.insertRow(row_position)

    # 设置表格列内容
    data = [
        str(attributes['OrigiSrcAddr']),
        str(attributes['DestAddr']),
        str(attributes['Seq']),
        str(attributes['CardData']),
        str(attributes['FrameType'])
    ]

    for col, value in enumerate(data):
        self.tableWidget.setItem(row_position, col, QtWidgets.QTableWidgetItem(value))