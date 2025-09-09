import jieba
import matplotlib.pyplot as plt
from collections import Counter
from wordcloud import WordCloud
import pandas as pd
import requests
import re
from selenium import webdriver
from selenium.webdriver.edge.service import Service
from selenium.webdriver.edge.options import Options
from bs4 import BeautifulSoup as bs
import time
from PyQt6 import QtCore, QtGui, QtWidgets
from PyQt6.QtGui import QPixmap
from matplotlib.backends.backend_qtagg import FigureCanvasQTAgg as FigureCanvas
from snownlp import SnowNLP
import numpy as np
import sqlite3
from sklearn.decomposition import LatentDirichletAllocation
from sklearn.feature_extraction.text import CountVectorizer
from ollama import chat,ChatResponse
import socket
import urllib3.util.connection as urllib3_cn
def allowed_gai_family():
    return socket.AF_INET
urllib3_cn.allowed_gai_family = allowed_gai_family

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(1366, 803)
        self.centralwidget = QtWidgets.QWidget(parent=MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.groupBox = QtWidgets.QGroupBox(parent=self.centralwidget)
        self.groupBox.setGeometry(QtCore.QRect(20, 20, 1321, 751))
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(20)
        font.setBold(True)
        font.setItalic(False)
        font.setUnderline(False)
        font.setWeight(75)
        self.groupBox.setFont(font)
        self.groupBox.setCheckable(False)
        self.groupBox.setObjectName("groupBox")
        self.label_7 = QtWidgets.QLabel(parent=self.groupBox)
        self.label_7.setGeometry(QtCore.QRect(20, 40, 71, 21))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_7.setFont(font)
        self.label_7.setObjectName("label_7")
        self.label_2 = QtWidgets.QLabel(parent=self.groupBox)
        self.label_2.setGeometry(QtCore.QRect(10, 350, 91, 31))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_2.setFont(font)
        self.label_2.setObjectName("label_2")
        self.pinshu = QtWidgets.QWidget(parent=self.groupBox)
        self.pinshu.setGeometry(QtCore.QRect(90, 340, 300, 300))
        self.pinshu.setObjectName("pinshu")
        self.wordcloud = QtWidgets.QWidget(parent=self.groupBox)
        self.wordcloud.setGeometry(QtCore.QRect(90, 20, 300, 300))
        self.wordcloud.setObjectName("wordcloud")
        self.label_6 = QtWidgets.QLabel(parent=self.groupBox)
        self.label_6.setGeometry(QtCore.QRect(400, 40, 121, 31))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_6.setFont(font)
        self.label_6.setObjectName("label_6")
        self.label_8 = QtWidgets.QLabel(parent=self.groupBox)
        self.label_8.setGeometry(QtCore.QRect(410, 380, 91, 31))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_8.setFont(font)
        self.label_8.setObjectName("label_8")
        self.LDA = QtWidgets.QWidget(parent=self.groupBox)
        self.LDA.setGeometry(QtCore.QRect(400, 420, 521, 300))
        self.LDA.setObjectName("LDA")
        self.label_s = QtWidgets.QLabel(parent=self.groupBox)
        self.label_s.setGeometry(QtCore.QRect(1060, 400, 151, 31))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_s.setFont(font)
        self.label_s.setText("")
        self.label_s.setObjectName("label_s")
        self.label_5 = QtWidgets.QLabel(parent=self.groupBox)
        self.label_5.setGeometry(QtCore.QRect(960, 400, 91, 31))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_5.setFont(font)
        self.label_5.setObjectName("label_5")
        self.groupBox_2 = QtWidgets.QGroupBox(parent=self.groupBox)
        self.groupBox_2.setGeometry(QtCore.QRect(950, 450, 341, 261))
        font = QtGui.QFont()
        font.setPointSize(20)
        self.groupBox_2.setFont(font)
        self.groupBox_2.setObjectName("groupBox_2")
        self.label_3 = QtWidgets.QLabel(parent=self.groupBox_2)
        self.label_3.setGeometry(QtCore.QRect(10, 40, 61, 31))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_3.setFont(font)
        self.label_3.setObjectName("label_3")
        self.netname = QtWidgets.QLineEdit(parent=self.groupBox_2)
        self.netname.setGeometry(QtCore.QRect(90, 40, 241, 41))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.netname.setFont(font)
        self.netname.setText("")
        self.netname.setObjectName("netname")
        self.key = QtWidgets.QLineEdit(parent=self.groupBox_2)
        self.key.setGeometry(QtCore.QRect(90, 90, 241, 41))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.key.setFont(font)
        self.key.setObjectName("key")
        self.label_4 = QtWidgets.QLabel(parent=self.groupBox_2)
        self.label_4.setGeometry(QtCore.QRect(0, 90, 71, 31))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_4.setFont(font)
        self.label_4.setObjectName("label_4")
        self.start = QtWidgets.QPushButton(parent=self.groupBox_2)
        self.start.setGeometry(QtCore.QRect(0, 210, 93, 28))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.start.setFont(font)
        self.start.setObjectName("start")
        self.save = QtWidgets.QPushButton(parent=self.groupBox_2)
        self.save.setGeometry(QtCore.QRect(110, 210, 93, 28))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.save.setFont(font)
        self.save.setObjectName("save")
        self.close = QtWidgets.QPushButton(parent=self.groupBox_2)
        self.close.setGeometry(QtCore.QRect(220, 210, 93, 28))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.close.setFont(font)
        self.close.setObjectName("close")
        self.label_9 = QtWidgets.QLabel(parent=self.groupBox_2)
        self.label_9.setGeometry(QtCore.QRect(10, 140, 71, 31))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_9.setFont(font)
        self.label_9.setObjectName("label_9")
        self.page = QtWidgets.QLineEdit(parent=self.groupBox_2)
        self.page.setGeometry(QtCore.QRect(90, 140, 241, 41))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.page.setFont(font)
        self.page.setObjectName("page")
        self.scrollArea = QtWidgets.QScrollArea(parent=self.groupBox)
        self.scrollArea.setGeometry(QtCore.QRect(420, 80, 851, 291))
        self.scrollArea.setWidgetResizable(True)
        self.scrollArea.setObjectName("scrollArea")
        self.scrollAreaWidgetContents = QtWidgets.QWidget()
        self.scrollAreaWidgetContents.setGeometry(QtCore.QRect(0, 0, 849, 289))
        self.scrollAreaWidgetContents.setObjectName("scrollAreaWidgetContents")
        self.title = QtWidgets.QLabel(parent=self.scrollAreaWidgetContents)
        self.title.setGeometry(QtCore.QRect(0, 0, 821, 281))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.title.setFont(font)
        self.title.setText("")
        self.title.setAlignment(QtCore.Qt.AlignmentFlag.AlignLeading|QtCore.Qt.AlignmentFlag.AlignLeft|QtCore.Qt.AlignmentFlag.AlignTop)
        self.title.setWordWrap(True)
        self.title.setObjectName("title")
        self.scrollArea.setWidget(self.title)
        self.res = QtWidgets.QLabel(parent=self.groupBox)
        self.res.setGeometry(QtCore.QRect(1080, 40, 191, 31))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.res.setFont(font)
        self.res.setText("")
        self.res.setObjectName("res")
        self.label = QtWidgets.QLabel(parent=self.groupBox)
        self.label.setGeometry(QtCore.QRect(1240, 390, 60, 60))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label.setFont(font)
        self.label.setText("")
        self.label.setObjectName("label")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(parent=MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 1366, 26))
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
        self.groupBox.setTitle(_translate("MainWindow", "分析"))
        self.label_7.setText(_translate("MainWindow", "词云图"))
        self.label_2.setText(_translate("MainWindow", "词频图"))
        self.label_6.setText(_translate("MainWindow", "题目及摘要:"))
        self.label_8.setText(_translate("MainWindow", "LDA"))
        self.label_5.setText(_translate("MainWindow", "情感分析:"))
        self.groupBox_2.setTitle(_translate("MainWindow", "输入信息"))
        self.label_3.setText(_translate("MainWindow", "网址:"))
        self.label_4.setText(_translate("MainWindow", "关键词:"))
        self.start.setText(_translate("MainWindow", "开始"))
        self.save.setText(_translate("MainWindow", "保存"))
        self.close.setText(_translate("MainWindow", "关闭"))
        self.label_9.setText(_translate("MainWindow", "页数:"))
        self.netname.setText("https://so.news.cn/")
        self.netname.textChanged.connect(self.showText)
        self.key.textChanged.connect(self.showText)
        self.start.clicked.connect(self.startFun)
        self.close.clicked.connect(self.endFun)
        self.save.clicked.connect(self.saveFun)
    def showText(self):
        self.netname.setText(self.netname.text())
        self.key.setText(self.key.text())
        #print(self.netname.text())
        
    def getWord(self):
        key=self.key.text()
        page=self.page.text()
        if page=="":
            page=2
        if key=="":
            key='人工智能'
        print(key)
        print(page)
        edge_options=Options()
        edge_options.add_argument("--headless")
        edge_options.add_argument("--blink-settings=imagesEnabled=false")
        edge_options.add_argument('--ignore-certificate-errors') 
        service=Service(executable_path=r"C:\Program Files (x86)\Microsoft\Edge\Application\msedgedriver.exe")
        driver=webdriver.Edge(service=service,options=edge_options)
        seen_links = set()
        seen_titles=set()
        items = []
        link_text_dict = {}
        for index in range(1,int(page)+1):
            url=f'https://so.news.cn/#search/1/{key}/{index}/0'
            driver.get(url)
            driver.refresh()
            time.sleep(0.5)
            html=driver.page_source
            soup=bs(html,'lxml')
            item_divs = soup.select('#root > div > div.search-box > div.list > div > div > div > div.content > div.items')
            for item in item_divs:
                a_tag = item.select_one('div.title > a')
                if a_tag:
                    href = a_tag['href'] 
                    text = a_tag.get_text(strip=True)
                    if href :
                        seen_links.add(href)
                        seen_titles.add(text)
                        items.append(item)
                        link_text_dict[href] = text
        driver.quit()
        Word=[]
        raw=[]
        titles=[]
        links=[]
        i=1
        headers={
            'user-agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36 Edg/131.0.0.0'
        }
        with requests.Session() as session:
            for href, text in link_text_dict.items(): 
                url=href
                print(url)
                response=session.get(url,allow_redirects=False,headers=headers,timeout=5)
                html=response.text
                soup=bs(html,'lxml')
                word=soup.select_one('#detailContent').get_text(strip=True)
                if word=="":
                   continue    
                raw.append(word)
                word=re.sub(r'（.*?）|\(.*?\)', '', word)
                word=re.sub(r'[^\w\s]', '', word)
                Word.append(word)
                titles.append(text)
                links.append(href)
                response: ChatResponse = chat(model="qwen2.5:3b", messages=[
                    {
                        'role': 'system',
                        'content': '''请提供一个简洁的摘要,概括这篇新闻的核心内容和主要观点.
                                        必须基于原文,尽量简洁,不多于50字.不可分段.直接输出结果即可.''',
                    },
                      {
                          'role': 'user',
                          'content': word,
                     },
                ])
                response_EN: ChatResponse = chat(model="qwen2.5:3b", messages=[
                    {
                        'role': 'system',
                        'content': '''将给出的摘要翻译为英文.''',
                    },
                      {
                          'role': 'user',
                          'content': response['message']['content'],
                     },
                ])
                #print(response.message.content)
                self.title.setText(self.title.text()+'\n'+f"{i}.{text}:{href}"+'\n'+f"摘要:{response['message']['content']}"+'\n'+f"英文摘要:{response_EN['message']['content']}")
                i+=1
        self.res.setStyleSheet("QLabel { color: red; }")
        self.res.setText(f"获取新闻{i-1}篇")
        #print(Word)
        return Word,raw,titles,links
    def plot_pinsu_word(self):
        Word=self.Word
        raw=self.raw
        text=""
        for word in Word:
            text=text+word
        words=jieba.cut(text)
        word_list=list(words)
        stopwords = {
            '的', '是', '在', '和', '了', '有', '与', '对', '为', '也', '说', '根据', '报道', 
            '专家', '称', '表示', '发言人', '记者', '提出', '指出', '现', '时', '将', '当', 
            '来', '到', '关于', '同', '这些', '今年', '月', '日', '去年', '本', '后', '那', 
            '此', '以后', '以后', '前', '之后', '方面', '开始', '结束', '有', '看到', '通过',
            '认为', '此', '情况', '必须', '进行', '实施', '消息', '表示', '听到', '现已', '已经'
            ,'新华社记者'
        }
        filtered_words = [word for word in word_list if word not in stopwords and len(word.strip()) > 1]
        word_list=list(filtered_words)
        self.res.setText(self.res.text()+f"总词数{len(word_list)}个")
        for stopword in stopwords:
            for word in raw:
                word = word.replace(stopword, '')
                word_freq=Counter(filtered_words)
        df=pd.DataFrame(word_freq.items(),columns=["Word","Freq"]).sort_values(by="Freq",ascending=False)
        fig2,ax2=plt.subplots(figsize=(10,10))
        plt.rcParams['font.sans-serif'] = ['SimHei']
        df.head(10).plot(kind='bar',x='Word',y='Freq',legend=False,color='skyblue',ax=ax2)
        ax2.set_xlabel('词语', fontsize=10, fontproperties='SimHei')
        ax2.set_ylabel('频率', fontsize=10)
        ax2.set_xticklabels(df.head(10)['Word'], rotation=45, ha='right', fontsize=8)
        ax2.tick_params(axis='x', labelsize=8)
        layout = QtWidgets.QVBoxLayout(self.pinshu)
        canvas = FigureCanvas(fig2)
        self.fig_pinshu=fig2
        layout.addWidget(canvas)
        self.pinshu.setLayout(layout)
        canvas.draw()
        
        wordcloud=WordCloud(font_path='C:/Windows/Fonts/simfang.ttf',background_color='white',width=800,height=600).generate_from_frequencies(word_freq)
        fig=plt.figure(figsize=(10,10))
        plt.imshow(wordcloud,interpolation='bilinear')
        plt.axis('off')
        plt.tight_layout()
        canvas = FigureCanvas(fig)
        self.fig_wordcloud=fig
        layout = QtWidgets.QVBoxLayout(self.wordcloud) 
        layout.addWidget(canvas) 
        self.wordcloud.setLayout(layout)
        canvas.draw()
    
        vectorizer = CountVectorizer(stop_words=list(stopwords))
        X = vectorizer.fit_transform(word_list)
        lda=LatentDirichletAllocation(n_components=3,random_state=42)
        lda.fit(X)
        colormaps = ['Blues', 'Reds', 'Greens']
        def plot_wordcloud_for_topic(topic_idx, feature_names, topic_weights,ax, colormap):
            top_n = 5 
            top_indices = topic_weights.argsort()[-top_n:][::-1]  
            word_freq = {feature_names[i]: topic_weights[i] for i in top_indices}
            
            wordcloud = WordCloud(font_path='C:/Windows/Fonts/simfang.ttf',width=800, height=400
                                , background_color="white",colormap=colormap).generate_from_frequencies(word_freq)
            ax.imshow(wordcloud, interpolation="bilinear")
            ax.axis("off")
        fig3, axes = plt.subplots(1, 3, figsize=(15, 5))
        for idx,(topic, ax, cmap) in enumerate(zip(lda.components_, axes, colormaps)):
            print(idx)
            print([vectorizer.get_feature_names_out()[i] for i in topic.argsort()[-5:]])
            plot_wordcloud_for_topic(idx, vectorizer.get_feature_names_out(), topic, ax, cmap)
        plt.tight_layout()
        canvas=FigureCanvas(fig3)
        self.fig_LDA=fig3
        layout = QtWidgets.QVBoxLayout(self.LDA)  
        layout.addWidget(canvas)  
        self.LDA.setLayout(layout)
        canvas.draw()  
        
    def get_s(self):
        raws=self.raw
        res=[]
        for raw in raws:
            s=SnowNLP(raw)
            res.append(s.sentiments)
        ave=np.mean(res)
        print(ave)
        if ave>0.5:
            self.label_s.setStyleSheet("QLabel { color: green; }")
            self.label_s.setText(f"{ave:.5f} 正面")
            pixmap=QPixmap(r"green.png")
            self.label.setPixmap(pixmap)
            self.label.setScaledContents(True)
        else:
            self.label_s.setStyleSheet("QLabel { color: red; }")
            self.label_s.setText(f"{ave:.5f} 负面")
            pixmap=QPixmap(r"red.png")
            self.label.setPixmap(pixmap)
            self.label.setScaledContents(True) 
    def saveFun(self):
        Word=self.Word
        raws=self.raw
        titles=self.titles
        links=self.links
        with open(r"save_Word.txt",'w',encoding='utf-8') as f:
            for word in Word:
                f.write(word+'\n')
            print("分词写入完毕")
        with open(r"save_raw.txt",'w',encoding='utf-8') as f:
            for raw in raws:
                f.write(raw+'\n')
            print("原文本写入完毕")
        self.fig_pinshu.savefig(r'pinshu.jpg')
        self.fig_wordcloud.savefig(r'wordcloud.jpg')
        self.fig_LDA.savefig(r'LDA.jpg')
        print("图像写入完毕")
        conn=sqlite3.connect(r'word.db')
        cursor=conn.cursor()
        cursor.execute(
            '''
            CREATE TABLE IF NOT EXISTS texts (
            id INTEGER PRIMARY KEY,
            text_content TEXT,
            type TEXT
            )
            '''
        )
        cursor.execute(f'DELETE FROM texts')
        conn.commit()
        for word in Word:
            cursor.execute('INSERT INTO texts (text_content, type) VALUES (?, ?)',(word,'Word'))
        for raw in raws:
            cursor.execute('INSERT INTO texts (text_content, type) VALUES (?, ?)',(raw,'Raws'))
        for title in titles:
            cursor.execute('INSERT INTO texts (text_content, type) VALUES (?, ?)',(title,'titles'))
        for link in links:
            cursor.execute('INSERT INTO texts (text_content, type) VALUES (?, ?)',(link,'links'))
        conn.commit()
        cursor.close()
        conn.close()
    def startFun(self):
        #key=input()
        def del_layout(self,layout):
            if layout is not None:
                for i in reversed(range(layout.count())):
                    widget = layout.itemAt(i).widget()
                    if widget is not None:
                        widget.deleteLater()  # 删除控件
                layout.deleteLater()
        del_layout(self,self.LDA.layout())
        del_layout(self,self.wordcloud.layout())
        del_layout(self,self.pinshu.layout())
        self.title.clear()
        self.label_s.clear()
        self.res.clear()
        
        Word,raw,titles,links=self.getWord()
        self.Word=Word
        self.raw=raw
        self.titles=titles
        self.links=links
        self.plot_pinsu_word()
        self.get_s()
        #self.get_title()
    def endFun(self):
        def del_layout(self,layout):
            if layout is not None:
                for i in reversed(range(layout.count())):
                    widget = layout.itemAt(i).widget()
                    if widget is not None:
                        widget.deleteLater()  # 删除控件
                layout.deleteLater()
        del_layout(self,self.LDA.layout())
        del_layout(self,self.wordcloud.layout())
        del_layout(self,self.pinshu.layout())
        self.label.clear()
        self.title.clear()
        self.label_s.clear()
        self.res.clear()
    
if __name__=="__main__":
    import sys
    app=QtWidgets.QApplication(sys.argv)
    Server=QtWidgets.QMainWindow()
    ui=Ui_MainWindow()
    ui.setupUi(Server)
    Server.show()
    sys.exit(app.exec())