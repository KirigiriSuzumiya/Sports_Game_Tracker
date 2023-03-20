# -*- coding: gb18030 -*-

import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QFileDialog, QMessageBox
from PyQt5.QtCore import pyqtSlot, QUrl, QDir, QFileInfo, Qt, QEvent
from PyQt5.QtGui import QIcon  # ,QKeyEvent,QMouseEvent
from PyQt5.QtMultimedia import QMediaContent, QMediaPlayer
from ui_MainWindow import Ui_MainWindow
from qt_material import apply_stylesheet
import cv2
import threading as thread
from queue import Queue
import time


class QmyMainWindow(QMainWindow):
    path = ''
    start = 0
    end = 0

    cv_buffer = Queue(50)
    time = 0
    start_time = 0
    end_time = 0
    cap = 0
    width = 0
    height = 0
    fps = 0
    frame_count = 0

    div = 1  # div������ÿ����֡ȡһ֡

    def __init__(self, parent=None):
        super().__init__(parent)  # ���ø��๹�캯������������
        self.ui = Ui_MainWindow()  # ����UI����
        self.ui.setupUi(self)  # ����UI����

        self.player = QMediaPlayer(self)  # ������Ƶ������
        self.player.setNotifyInterval(1000)  # ��Ϣ��������, ms
        self.player.setVideoOutput(self.ui.videoWidget)  # ��Ƶ��ʾ���

        self.ui.videoWidget.installEventFilter(self)  # �¼�������

        self.__duration = ""
        self.__curPos = ""

        self.player.stateChanged.connect(self.do_stateChanged)
        self.player.positionChanged.connect(self.do_positionChanged)
        self.player.durationChanged.connect(self.do_durationChanged)

    ##  ==============�Զ��幦�ܺ���========================

    ##  ==============event������==========================
    def closeEvent(self, event):  # ����ر�ʱ
        # ���ڹر�ʱ�����Զ�ֹͣ���ţ����ֶ�ֹͣ
        if (self.player.state() == QMediaPlayer.PlayingState):
            self.player.stop()

    def eventFilter(self, watched, event):  ##�¼�������
        if (watched != self.ui.videoWidget):
            return super().eventFilter(watched, event)

        # ����������ʱ����ͣ���������
        if event.type() == QEvent.MouseButtonPress:
            if event.button() == Qt.LeftButton:
                if self.player.state() == QMediaPlayer.PlayingState:
                    self.player.pause()
                else:
                    self.player.play()

        # ȫ��״̬ʱ����ESC���˳�ȫ��
        if event.type() == QEvent.KeyPress:
            if event.key() == Qt.Key_Escape:
                if self.ui.videoWidget.isFullScreen():
                    self.ui.videoWidget.setFullScreen(False)

        return super().eventFilter(watched, event)

    ##  ==========��connectSlotsByName()�Զ����ӵĲۺ���============
    @pyqtSlot()  ##���ļ�
    def on_btnOpen_clicked(self):
        ##      curPath=os.getcwd()  #��ȡϵͳ��ǰĿ¼
        curPath = QDir.currentPath()  # ��ȡϵͳ��ǰĿ¼

        title = "ѡ����Ƶ�ļ�"
        filt = "��Ƶ�ļ�(*.wmv *.avi );;�����ļ�(*.*)"
        fileName, flt = QFileDialog.getOpenFileName(self, title, curPath, filt)
        self.path = fileName
        if (fileName == ""):
            return

        fileInfo = QFileInfo(fileName)
        baseName = fileInfo.fileName()
        ##      baseName=os.path.basename(fileName)
        self.ui.LabCurMedia.setText(baseName)

        curPath = fileInfo.absolutePath()
        QDir.setCurrent(curPath)  # ���赱ǰĿ¼

        media = QMediaContent(QUrl.fromLocalFile(fileName))
        self.player.setMedia(media)  # ���ò����ļ�
        self.player.play()

    @pyqtSlot()  ##����
    def on_btnPlay_clicked(self):
        self.player.play()

    @pyqtSlot()  ##��ͣ
    def on_btnPause_clicked(self):
        self.player.pause()

    @pyqtSlot()  ##ֹͣ
    def on_btnStop_clicked(self):
        self.player.stop()

    @pyqtSlot()  ##ȫ��
    def on_btnFullScreen_clicked(self):
        self.ui.videoWidget.setFullScreen(True)

    @pyqtSlot()  ##������ť
    def on_btnSound_clicked(self):
        mute = self.player.isMuted()
        self.player.setMuted(not mute)
        if mute:
            self.ui.btnSound.setIcon(QIcon(":/icons/images/volumn.bmp"))
        else:
            self.ui.btnSound.setIcon(QIcon(":/icons/images/mute.bmp"))

    @pyqtSlot(int)  ##��������
    def on_sliderVolumn_valueChanged(self, value):
        self.player.setVolume(value)

    @pyqtSlot(int)  ##���Ž��ȵ���
    def on_sliderPosition_valueChanged(self, value):
        self.player.setPosition(value)

    ##  =============�Զ���ۺ���===============================

    def do_stateChanged(self, state):  ##״̬�仯
        isPlaying = (state == QMediaPlayer.PlayingState)

        self.ui.btnPlay.setEnabled(not isPlaying)
        self.ui.btnPause.setEnabled(isPlaying)
        self.ui.btnStop.setEnabled(isPlaying)

    def do_durationChanged(self, duration):  ##�ļ����ȱ仯
        self.ui.sliderPosition.setMaximum(duration)

        secs = duration / 1000  # ��
        mins = secs / 60  # ����
        secs = secs % 60  # ������
        self.__duration = "%d:%d" % (mins, secs)
        self.ui.LabRatio.setText(self.__curPos + "/" + self.__duration)

    def do_positionChanged(self, position):  ##��ǰ����λ�ñ仯
        if (self.ui.sliderPosition.isSliderDown()):
            return  # ��������϶��������˳�

        self.ui.sliderPosition.setSliderPosition(position)
        secs = position / 1000  # ��
        mins = secs / 60  # ����
        secs = secs % 60  # ������
        self.__curPos = "%d:%d" % (mins, secs)
        self.ui.LabRatio.setText(self.__curPos + "/" + self.__duration)

    ## ============��Ƶ����ۺ���================================
    @pyqtSlot(int)
    def on_start_point_value_valueChanged(self):
        _value = self.ui.start_point_value.value()
        duration = self.player.duration()
        duration_s = duration * _value / 1000
        secs = duration_s / 1000  # ��
        self.start = round(secs, 2)
        mins = secs / 60  # ����
        secs = secs % 60  # ������
        self.ui.start_time_display.setText("%d:%d" % (mins, secs))

    @pyqtSlot(int)
    def on_end_point_value_valueChanged(self):
        _value = self.ui.end_point_value.value()
        duration = self.player.duration()
        duration_s = duration * _value / 1000
        secs = duration_s / 1000  # ��
        self.end = round(secs, 2)
        mins = secs / 60  # ����
        secs = secs % 60  # ������
        self.ui.end_time_display.setText("%d:%d" % (mins, secs))

    def _input(self):
        print('input:processing')
        while self.time <= self.end_time:
            if self.cv_buffer.full():
                import time
                time.sleep(0.5)
                continue
            success, img = self.cap.read()
            print('input:doing')
            if not success:
                QMessageBox.critical(self, '��Ƶ��Ϣ���ִ���', '��Ƶ��Ϣ����δ֪���������Ҳ��֪����ô��',
                                     QMessageBox.Yes | QMessageBox.No, QMessageBox.Yes)
            self.time += self.div  # div������ÿ����֡ȡһ֡
            if self.time > self.start_time:
                self.cv_buffer.put(img)
                print('input:', self.cv_buffer.qsize(), self.time, self.start_time, self.end_time)
        self.cv_buffer.put(1)
    # def _output(self):
    #     print('output:processing')
    #     if not self.cv_buffer.empty():
    #         print('output:doing')
    #         img = self.cv_buffer.get()  # img
    #         print(img)

    # =======================================�˴�����PPHUMAN����ӿ�======================================
    @pyqtSlot()
    def video_infer(self):
        from pipeline import pipeline
        import os
        import pickle
        import time
        FLAGS = pickle.load(open("FLAGS", "rb"))
        FLAGS.config = os.path.abspath(os.path.join(os.path.dirname(__file__),
                                                    "pipeline", "config",
                                                    "infer_cfg_pphuman_player.yml"))
        print(FLAGS)
        cfg = pipeline.merge_cfg(FLAGS)
        pipeline.print_arguments(cfg)
        pipeline_obj = pipeline.PipePredictor(FLAGS, cfg)
        while True:
            if self.fps == 0:
                time.sleep(0.5)
                continue
            res = pipeline_obj.predict_video(self.cv_buffer, {"fps": self.fps,
                                                              "width": self.width,
                                                              "height": self.height,
                                                              "frame_count": self.end - self.start})
            while True:
                if self.cv_buffer.empty():
                    time.sleep(0.5)
                    print("�ȴ�����")
                    pass
                else:
                    data = next(res)
                    if type(data) == str:
                        break
                    info = "�����У�"+str(data["frame_id"]) + "/" + str(self.end - self.start)
                    self.ui.start_processing.setText(info)
            self.ui.start_processing.setText("������ɣ������ڣ�" + data)
            self.ui.start_processing.setEnabled(True)
            self.fps = 0
    # =======================================�˴�����PPHUMAN����ӿ�======================================

    @pyqtSlot()
    def on_start_processing_clicked(self):
        self.cap = cv2.VideoCapture(self.path)
        self.width = int(self.cap.get(cv2.CAP_PROP_FRAME_WIDTH))
        self.height = int(self.cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
        self.fps = int(self.cap.get(cv2.CAP_PROP_FPS))
        self.start_time = int(self.start * self.fps)
        self.end_time = int(self.end * self.fps)
        while self.time < self.start_time:
            success, img = self.cap.read()
            # print('pre:doing')
            self.time += self.div  # div������ÿ����֡ȡһ֡
            if not success:
                QMessageBox.critical(self, '��Ƶ��Ϣ���ִ���', '��Ƶ��Ϣ����δ֪���������Ҳ��֪����ô��',
                                     QMessageBox.Yes | QMessageBox.No, QMessageBox.Yes)
        # print(self.time, self.end_time)
        loops = self.end_time - self.start_time
        t_video_load = thread.Thread(target=self._input)
        t_video_infer = thread.Thread(target=self.video_infer)
        t_video_load.start()
        t_video_infer.start()
        self.ui.start_processing.setText('Infering!')
        self.ui.start_processing.setEnabled(False)


## ============��Ƶ�༭�ۺ���================================


##  ============������Գ��� ================================
if __name__ == "__main__":  # ���ڵ�ǰ�������

    app = QApplication(sys.argv)  # ����GUIӦ�ó���
    apply_stylesheet(app, theme='dark_teal.xml')
    form = QmyMainWindow()  # ��������
    form.show()
    sys.exit(app.exec_())
