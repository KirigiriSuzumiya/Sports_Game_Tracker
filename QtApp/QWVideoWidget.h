#ifndef QWVIDEOWIDGET_H
#define QWVIDEOWIDGET_H

#include    <QObject>
#include    <QWidget>
#include    <QVideoWidget>
#include    <QMediaPlayer>

class QWVideoWidget : public QVideoWidget
{
private:
    QMediaPlayer    *m_player;//

protected:
    void keyPressEvent(QKeyEvent *event);

    void mousePressEvent(QMouseEvent *event);

public:
    QWVideoWidget(QWidget *parent = Q_NULLPTR);

    void    setMediaPlayer(QMediaPlayer *player);
};

#endif // QWVIDEOWIDGET_H
