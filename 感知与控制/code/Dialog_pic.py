from PyQt6 import QtCore, QtWidgets
from global_var import temp_list
from matplotlib.backends.backend_qtagg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.figure import Figure
import matplotlib.pyplot as plt
plt.rcParams['font.sans-serif'] = ['SimHei'] # 正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False # 正常显示负号
class MplCanvas(FigureCanvas):
    def __init__(self, parent=None, width=5, height=4, dpi=100):
        fig = Figure(figsize=(width, height), dpi=dpi)
        self.axes = fig.add_subplot(111)
        super(MplCanvas, self).__init__(fig)
        
class Ui_Dialog_pic(object):
    
    def __init__(self,main_window=None):
        self.main_window = main_window
    def setupUi(self, Dialog):
        Dialog.setObjectName("Dialog")
        Dialog.resize(600, 400)

        self.canvas = MplCanvas(Dialog, width=5, height=4, dpi=100)
        layout = QtWidgets.QVBoxLayout()
        layout.addWidget(self.canvas)
        Dialog.setLayout(layout)

        # 初始化定时器，每秒更新一次曲线图
        self.timer = QtCore.QTimer()
        self.timer.timeout.connect(self.update_plot)
        self.timer.start(500)

        # 监听对话框关闭事件，用于清理资源
        Dialog.finished.connect(self.on_close)

        with open(r"style.qss", "r", encoding='utf-8') as f:
            Dialog.setStyleSheet(f.read())
        Dialog.setWindowTitle("温度曲线显示")
    
    def on_close(self):
        # 停止定时器并清理绘图组件
        if self.timer and self.timer.isActive():
            self.timer.stop()
        if self.canvas:
            self.canvas.deleteLater() 

    def update_plot(self):
        self.canvas.axes.clear()

        # 应用 matplotlib 内置样式
        plt.style.use('ggplot')  

        line_color = '#1f77b4'  # 更优雅的蓝色
        
        # 绘制折线图
        self.canvas.axes.plot(temp_list, label='当前温度', color=line_color, linewidth=2)

        # 添加阴影填充区域
        self.canvas.axes.fill_between(range(len(temp_list)), temp_list, color=line_color, alpha=0.1)

        # 设置标题和标签
        self.canvas.axes.set_title('温度变化曲线', fontsize=14, pad=20)
        self.canvas.axes.set_xlabel('时间步', fontsize=12)
        self.canvas.axes.set_ylabel('温度 (°C)', fontsize=12)

        # 设置图例
        self.canvas.axes.legend(loc='upper left', fontsize=10)

        # 设置网格和背景
        self.canvas.axes.grid(True, linestyle='--', alpha=0.6)
        self.canvas.axes.set_facecolor('#f9f9f9')

        self.canvas.draw()