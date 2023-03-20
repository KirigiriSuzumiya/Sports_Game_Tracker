#include    "QWVideoWidget.h"
#include    <QKeyEvent>
#include    <QMouseEvent>

void QWVideoWidget::keyPressEvent(QKeyEvent *event)
{//按键事件，ESC退出全屏状态
    if ((event->key() == Qt::Key_Escape)&&(isFullScreen()))
    {
        setFullScreen(false);
        event->accept();
    }
    QVideoWidget::keyPressEvent(event);
}

void QWVideoWidget::mousePressEvent(QMouseEvent *event)
{//鼠标事件，单击控制暂停和继续播放
    if (event->button()==Qt::LeftButton)
    {
        if (m_player->state()==QMediaPlayer::PlayingState)
          m_player->pause();
        else
          m_player->play();
    }
    QVideoWidget::mousePressEvent(event);

}

QWVideoWidget::QWVideoWidget(QWidget *parent):QVideoWidget(parent)
{

}

void QWVideoWidget::setMediaPlayer(QMediaPlayer *player)
{//设置播放器
    m_player=player;
}
