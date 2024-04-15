#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Player = new QMediaPlayer();
    Audio = new QAudioOutput();

    QPixmap logoPixmap("F:/QT STUDIO/video_player/images/logo.png"); // Load logo image
    ui->LogoLabel->setPixmap(logoPixmap);
    ui->LogoLabel->setScaledContents(true); // Scale logo image to fit label size
    ui->LogoLabel->setVisible(false);

    ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->pushButton_Stop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    ui->pushButton_Seek_Backword->setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));
    ui->pushButton_seek_forward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));
    ui->pushButton_Volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));

    ui->horizontalSlider_Volume->setMinimum(0);
    ui->horizontalSlider_Volume->setMaximum(100);
    ui->horizontalSlider_Volume->setValue(30);
    Audio->setVolume(ui->horizontalSlider_Volume->value());

    connect(Player, &QMediaPlayer::durationChanged,this,&MainWindow::durationChanged);
    connect(Player, &QMediaPlayer::positionChanged,this,&MainWindow::positionChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::durationChanged(qint64 duration)
{
    mDuration= duration/1000;
    ui->horizontalSlider_Duration->setMaximum(mDuration);
}

void MainWindow::positionChanged(qint64 duration)
{
    if(!ui->horizontalSlider_Duration->isSliderDown()){
        ui->horizontalSlider_Duration->setValue(duration/1000);
    }
    updateDuration(duration/1000);
}

void MainWindow::updateDuration(qint64 Duration)
{
if (Duration || mDuration)
{
    QTime CurrentTime((Duration / 3600) % 60, (Duration / 60 ) % 60, Duration % 60, (Duration *1000)%1000);
    QTime TotalTime ((mDuration / 3600) % 60, (mDuration / 60 ) % 60, mDuration % 60, (mDuration * 1000)%1000);
    QString Format = "";
    if (mDuration > 3600) Format = "hh:mm:ss";
    else Format = "mm:ss";
    ui->label_current_Time->setText(CurrentTime.toString(Format));
    ui->label_total_Time->setText(TotalTime.toString(Format));
}
}

void MainWindow::on_actionOpen_triggered()
{
    // QString FileName= QFileDialog:: getOpenFileName(this, tr("Select Video File"),"",tr("MP4 Files (.mp4)"));
    QString FileName = QFileDialog::getOpenFileName(this, tr("Select Video File"), "", tr("MP4 Files (*.mp4);;All Files (*)"));
    Video = new QVideoWidget();
    Video -> setGeometry(5,5, ui->groupBox_Video->width()-10, ui->groupBox_Video->height()-10);
    Video->setParent(ui->groupBox_Video);
    Player->setVideoOutput(Video);
    // Audio->setSource(newVol); // seting audio from video file failed
    Player->setSource(QUrl(FileName));
    Video -> setVisible(true);
    Video -> show();
}




void MainWindow::on_pushButton_Play_Pause_clicked()
{
    if ( IS_PAUSE== true){
        IS_PAUSE= false;
        Player -> play();
        ui->LogoLabel->setVisible(false);
        Video -> setVisible(true);
        ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    } else {
        IS_PAUSE= true;
        Player -> pause();

        // ui->LogoLabel->setParent(Video);
        ui->LogoLabel->setVisible(true);
        Video -> setVisible(false);

        ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));

    }
}


void MainWindow::on_pushButton_Stop_clicked()
{
    Player-> stop();
}


void MainWindow::on_pushButton_Volume_clicked()
{
    if (IS_PAUSE) {
        IS_PAUSE = false;
        Player->play();
        ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    } else {
        IS_PAUSE = true;
        Player->pause();
        ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay)); // Setting the background image when paused
    }
}


void MainWindow::on_horizontalSlider_Volume_valueChanged(int value)
{
    Audio -> setVolume(value);
}


void MainWindow::on_pushButton_seek_forward_clicked()
{
ui->horizontalSlider_Duration->setValue(ui->horizontalSlider_Duration->value()+20);
    Player->setPosition(ui->horizontalSlider_Duration->value() *1000);
}


void MainWindow::on_pushButton_Seek_Backword_clicked()
{
ui->horizontalSlider_Duration->setValue(ui->horizontalSlider_Duration->value()-20);
    Player->setPosition(ui->horizontalSlider_Duration->value() *1000);
}


void MainWindow::on_horizontalSlider_Duration_valueChanged(int value)
{
    Player->setPosition(value *1000);
}


