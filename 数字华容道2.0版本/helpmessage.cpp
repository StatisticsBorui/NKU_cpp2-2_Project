#include "helpmessage.h"
#include "ui_helpmessage.h"

helpMessage::helpMessage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::helpMessage)
{
    ui->setupUi(this);
}

helpMessage::~helpMessage()
{
    delete ui;
}
