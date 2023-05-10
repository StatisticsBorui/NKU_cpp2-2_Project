#include "helpmessage.h"
#include "ui_helpmessage.h"

helpMessage::helpMessage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::helpMessage)
{
    ui->setupUi(this);
    timeClose= new QTimer();
    timeClose->setInterval(60000);
    connect(timeClose, SIGNAL(timeout()), this, SLOT(timeClose_func()));
    timeClose->start();
}

helpMessage::~helpMessage()
{
    delete ui;
}

void helpMessage::timeClose_func(){
    close();
    timeClose -> stop();
}
