#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include <QtCore>
#include <QtWidgets>
#include <QtGui>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void durationChanged(qint64 duration);
    void positionChanged(qint64 duration);
    void on_actionOpen_triggered();

    // void on_actionOpen_visibleChanged();

    void on_pushButton_Play_Pause_clicked();

    void on_pushButton_Stop_clicked();

    void on_pushButton_Volume_clicked();

    void on_horizontalSlider_Volume_valueChanged(int value);

    void on_pushButton_seek_forward_clicked();

    void on_pushButton_Seek_Backword_clicked();

    void on_horizontalSlider_Duration_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QMediaPlayer *Player;
    QVideoWidget *Video;
    QAudioOutput *Audio;
    qint64 mDuration;
    bool IS_PAUSE= true;
    bool IS_MUTED= false;

    void updateDuration(qint64 Duration);
};
#endif // MAINWINDOW_H
