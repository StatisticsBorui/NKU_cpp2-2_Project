#include "video.h"
#include "ui_video.h"
#include "mainwindow.h"

video::video(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::video)
{
    ui->setupUi(this);
    QVideoWidget* happy = new QVideoWidget(this);
    happy -> resize(800,600);

    QMediaPlayer* player = new QMediaPlayer(this);
    player -> setVideoOutput(happy);
    player -> setMedia(QMediaContent(QUrl::fromLocalFile("C://Users//54016//Desktop//QtSzhrdGame//SzhrdGame//happycat.mp4")));
    player ->play();
    Timer_= new QTimer();
    Timer_->setInterval(16000);
    connect(Timer_, SIGNAL(timeout()), this, SLOT(Timer_func()));
    Timer_->start();




}

video::~video()
{
    delete ui;
}

void video::Timer_func(){
    close();
    MainWindow *w = new MainWindow;
    w -> show();
    Timer_->stop();
}
