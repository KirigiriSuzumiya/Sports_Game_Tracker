#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include    <QMainWindow>

#include    <QMediaPlayer>
#include    <QMediaPlaylist>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
   bool eventFilter(QObject *watched, QEvent *event);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
//自定义槽函数
    void do_stateChanged(QMediaPlayer::State state);

    void do_durationChanged(qint64 duration);

    void do_positionChanged(qint64 position);

//
    void on_btnOpen_clicked();

    void on_btnPlay_clicked();

    void on_btnPause_clicked();

    void on_btnStop_clicked();

    void on_sliderVolumn_valueChanged(int value);

    void on_btnSound_clicked();

    void on_sliderPosition_valueChanged(int value);

    void on_btnFullScreen_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
