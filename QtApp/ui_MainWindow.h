/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QVideoWidget.h>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QVideoWidget *videoWidget;
    QFrame *frameButtons;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnOpen;
    QPushButton *btnPlay;
    QPushButton *btnPause;
    QPushButton *btnStop;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSound;
    QSlider *sliderVolumn;
    QPushButton *btnFullScreen;
    QPushButton *btnClose;
    QFrame *frameProgress;
    QHBoxLayout *horizontalLayout_2;
    QLabel *LabCurMedia;
    QSlider *sliderPosition;
    QLabel *LabRatio;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(425, 286);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        videoWidget = new QVideoWidget(centralWidget);
        videoWidget->setObjectName(QStringLiteral("videoWidget"));

        verticalLayout->addWidget(videoWidget);

        frameButtons = new QFrame(centralWidget);
        frameButtons->setObjectName(QStringLiteral("frameButtons"));
        frameButtons->setMaximumSize(QSize(16777215, 35));
        frameButtons->setFrameShape(QFrame::Panel);
        frameButtons->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frameButtons);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, 0);
        btnOpen = new QPushButton(frameButtons);
        btnOpen->setObjectName(QStringLiteral("btnOpen"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/images/001.GIF"), QSize(), QIcon::Normal, QIcon::Off);
        btnOpen->setIcon(icon);

        horizontalLayout->addWidget(btnOpen);

        btnPlay = new QPushButton(frameButtons);
        btnPlay->setObjectName(QStringLiteral("btnPlay"));
        btnPlay->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/images/620.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnPlay->setIcon(icon1);

        horizontalLayout->addWidget(btnPlay);

        btnPause = new QPushButton(frameButtons);
        btnPause->setObjectName(QStringLiteral("btnPause"));
        btnPause->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/images/622.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnPause->setIcon(icon2);

        horizontalLayout->addWidget(btnPause);

        btnStop = new QPushButton(frameButtons);
        btnStop->setObjectName(QStringLiteral("btnStop"));
        btnStop->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/images/624.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnStop->setIcon(icon3);

        horizontalLayout->addWidget(btnStop);

        horizontalSpacer = new QSpacerItem(87, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSound = new QPushButton(frameButtons);
        btnSound->setObjectName(QStringLiteral("btnSound"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/images/volumn.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnSound->setIcon(icon4);
        btnSound->setFlat(true);

        horizontalLayout->addWidget(btnSound);

        sliderVolumn = new QSlider(frameButtons);
        sliderVolumn->setObjectName(QStringLiteral("sliderVolumn"));
        sliderVolumn->setMaximum(100);
        sliderVolumn->setValue(100);
        sliderVolumn->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(sliderVolumn);

        btnFullScreen = new QPushButton(frameButtons);
        btnFullScreen->setObjectName(QStringLiteral("btnFullScreen"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/images/237.GIF"), QSize(), QIcon::Normal, QIcon::Off);
        btnFullScreen->setIcon(icon5);

        horizontalLayout->addWidget(btnFullScreen);

        btnClose = new QPushButton(frameButtons);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnClose->setIcon(icon6);

        horizontalLayout->addWidget(btnClose);


        verticalLayout->addWidget(frameButtons);

        frameProgress = new QFrame(centralWidget);
        frameProgress->setObjectName(QStringLiteral("frameProgress"));
        frameProgress->setMaximumSize(QSize(16777215, 35));
        frameProgress->setFrameShape(QFrame::NoFrame);
        frameProgress->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frameProgress);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, 0);
        LabCurMedia = new QLabel(frameProgress);
        LabCurMedia->setObjectName(QStringLiteral("LabCurMedia"));
        LabCurMedia->setMinimumSize(QSize(100, 0));

        horizontalLayout_2->addWidget(LabCurMedia);

        sliderPosition = new QSlider(frameProgress);
        sliderPosition->setObjectName(QStringLiteral("sliderPosition"));
        sliderPosition->setTracking(false);
        sliderPosition->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(sliderPosition);

        LabRatio = new QLabel(frameProgress);
        LabRatio->setObjectName(QStringLiteral("LabRatio"));
        LabRatio->setMinimumSize(QSize(80, 0));

        horizontalLayout_2->addWidget(LabRatio);


        verticalLayout->addWidget(frameProgress);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(btnClose, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Demo10_5\357\274\214\350\247\206\351\242\221\346\222\255\346\224\276\345\231\250", nullptr));
#ifndef QT_NO_TOOLTIP
        btnOpen->setToolTip(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
#endif // QT_NO_TOOLTIP
        btnOpen->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnPlay->setToolTip(QApplication::translate("MainWindow", "\346\222\255\346\224\276", nullptr));
#endif // QT_NO_TOOLTIP
        btnPlay->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnPause->setToolTip(QApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
#endif // QT_NO_TOOLTIP
        btnPause->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnStop->setToolTip(QApplication::translate("MainWindow", "\345\201\234\346\255\242", nullptr));
#endif // QT_NO_TOOLTIP
        btnStop->setText(QString());
        btnSound->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnFullScreen->setToolTip(QApplication::translate("MainWindow", "\345\205\250\345\261\217\346\222\255\346\224\276", nullptr));
#endif // QT_NO_TOOLTIP
        btnFullScreen->setText(QApplication::translate("MainWindow", "\345\205\250\345\261\217", nullptr));
#ifndef QT_NO_TOOLTIP
        btnClose->setToolTip(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#endif // QT_NO_TOOLTIP
        btnClose->setText(QString());
        LabCurMedia->setText(QApplication::translate("MainWindow", "\346\227\240\346\233\262\347\233\256", nullptr));
        LabRatio->setText(QApplication::translate("MainWindow", "\350\277\233\345\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
