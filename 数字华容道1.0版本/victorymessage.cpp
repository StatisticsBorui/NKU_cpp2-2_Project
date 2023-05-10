#include "victorymessage.h"
#include "ui_victorymessage.h"
#include "lesson1.h"
#include "lesson2.h"
#include "lesson3.h"
#include "mainwindow.h"

victoryMessage::victoryMessage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::victoryMessage)
{
    ui->setupUi(this);

    connect(ui->buttonBox,SIGNAL(clicked(bool)),this,SLOT(on_manual_clicked()));
}

victoryMessage::~victoryMessage()
{
    delete ui;
}

void victoryMessage::changeType(int t){
    if(t == 1 || t == 2 || t == 3){
        type = t;
    }
}
void victoryMessage::on_buttonBox_accepted(){
    close();
    if(type == 1){
        lesson1 *d = new lesson1;
        d -> show();
    }
    else if(type == 2){
        lesson2 *d = new lesson2;
        d -> show();
    }
    else if(type == 3){
        lesson3 *d = new lesson3;
        d -> show();
    }
    else{
        qDebug("WRONG!");
    }

}

void victoryMessage::on_buttonBox_rejected()
{
    close();
    MainWindow *w = new MainWindow;
    w -> show();
}
