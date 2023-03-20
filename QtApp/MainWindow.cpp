#include "MainWindow.h"
#include "ui_MainWindow.h"

#include    <QFileDialog>
#include    <QKeyEvent>
#include    <QMouseEvent>

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
   return QMainWindow::eventFilter(watched,event);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::do_stateChanged(QMediaPlayer::State state)
{//播放器状态变化
}

void MainWindow::do_durationChanged(qint64 duration)
{//文件时长变化
}

void MainWindow::do_positionChanged(qint64 position)
{//文件播放位置变化
}

void MainWindow::on_btnOpen_clicked()
{//打开文件
}

void MainWindow::on_btnPlay_clicked()
{//播放
}

void MainWindow::on_btnPause_clicked()
{//暂停
}

void MainWindow::on_btnStop_clicked()
{//停止
}

void MainWindow::on_sliderVolumn_valueChanged(int value)
{//调节音量
}

void MainWindow::on_btnSound_clicked()
{//静音按钮
}

void MainWindow::on_sliderPosition_valueChanged(int value)
{//播放位置
}

void MainWindow::on_btnFullScreen_clicked()
{//全屏按钮
}


