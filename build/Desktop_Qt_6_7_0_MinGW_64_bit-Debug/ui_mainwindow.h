/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QWidget *centralwidget;
    QGroupBox *groupBox_Video;
    QLabel *LogoLabel;
    QPushButton *pushButton_Seek_Backword;
    QPushButton *pushButton_Play_Pause;
    QPushButton *pushButton_Stop;
    QPushButton *pushButton_seek_forward;
    QPushButton *pushButton_Volume;
    QSlider *horizontalSlider_Volume;
    QSlider *horizontalSlider_Duration;
    QLabel *label_current_Time;
    QLabel *label_total_Time;
    QMenuBar *menubar;
    QMenu *menuSelect_Video_File_Here;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox_Video = new QGroupBox(centralwidget);
        groupBox_Video->setObjectName("groupBox_Video");
        groupBox_Video->setGeometry(QRect(5, 5, 790, 450));
        groupBox_Video->setAutoFillBackground(false);
        groupBox_Video->setStyleSheet(QString::fromUtf8("QGroupBox \n"
"{\n"
"	border: 1px solid black;\n"
"background: white;\n"
"}"));
        groupBox_Video->setCheckable(false);
        LogoLabel = new QLabel(groupBox_Video);
        LogoLabel->setObjectName("LogoLabel");
        LogoLabel->setGeometry(QRect(180, 150, 391, 141));
        pushButton_Seek_Backword = new QPushButton(centralwidget);
        pushButton_Seek_Backword->setObjectName("pushButton_Seek_Backword");
        pushButton_Seek_Backword->setGeometry(QRect(10, 490, 51, 41));
        pushButton_Play_Pause = new QPushButton(centralwidget);
        pushButton_Play_Pause->setObjectName("pushButton_Play_Pause");
        pushButton_Play_Pause->setGeometry(QRect(70, 490, 51, 41));
        pushButton_Stop = new QPushButton(centralwidget);
        pushButton_Stop->setObjectName("pushButton_Stop");
        pushButton_Stop->setGeometry(QRect(130, 490, 51, 41));
        pushButton_seek_forward = new QPushButton(centralwidget);
        pushButton_seek_forward->setObjectName("pushButton_seek_forward");
        pushButton_seek_forward->setGeometry(QRect(190, 490, 51, 41));
        pushButton_Volume = new QPushButton(centralwidget);
        pushButton_Volume->setObjectName("pushButton_Volume");
        pushButton_Volume->setGeometry(QRect(510, 490, 51, 41));
        horizontalSlider_Volume = new QSlider(centralwidget);
        horizontalSlider_Volume->setObjectName("horizontalSlider_Volume");
        horizontalSlider_Volume->setGeometry(QRect(570, 500, 221, 20));
        horizontalSlider_Volume->setOrientation(Qt::Horizontal);
        horizontalSlider_Duration = new QSlider(centralwidget);
        horizontalSlider_Duration->setObjectName("horizontalSlider_Duration");
        horizontalSlider_Duration->setGeometry(QRect(80, 460, 631, 20));
        horizontalSlider_Duration->setOrientation(Qt::Horizontal);
        label_current_Time = new QLabel(centralwidget);
        label_current_Time->setObjectName("label_current_Time");
        label_current_Time->setGeometry(QRect(10, 460, 63, 20));
        label_total_Time = new QLabel(centralwidget);
        label_total_Time->setObjectName("label_total_Time");
        label_total_Time->setGeometry(QRect(720, 460, 63, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuSelect_Video_File_Here = new QMenu(menubar);
        menuSelect_Video_File_Here->setObjectName("menuSelect_Video_File_Here");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuSelect_Video_File_Here->menuAction());
        menuSelect_Video_File_Here->addAction(actionOpen);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        groupBox_Video->setTitle(QString());
        LogoLabel->setText(QString());
        pushButton_Seek_Backword->setText(QString());
        pushButton_Play_Pause->setText(QString());
        pushButton_Stop->setText(QString());
        pushButton_seek_forward->setText(QString());
        pushButton_Volume->setText(QString());
        label_current_Time->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        label_total_Time->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        menuSelect_Video_File_Here->setTitle(QCoreApplication::translate("MainWindow", "Select Video File Here", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
