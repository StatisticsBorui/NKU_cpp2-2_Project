#include "lesson1.h"
#include "ui_lesson1.h"
#include "victorymessage.h"
#include <QSound>

Szhrd Game1(3,3);

lesson1::lesson1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::lesson1)
{
    ui->setupUi(this);

    Game1.playmusic();

    connect(ui->start,SIGNAL(clicked(bool)),this,SLOT(on_manual_clicked()));
    connect(ui->out,SIGNAL(clicked(bool)),this,SLOT(on_manual_clicked()));

}


lesson1::~lesson1()
{
    delete ui;
}


void lesson1::on_start_clicked()
{
    Game1.makeBoard();
    Game1.resetSteps();
    update();
}

void lesson1::paintEvent(QPaintEvent *){
    QPainter p(this);
    p.setPen(Qt::black);
    p.setFont(QFont("宋体",15,700,false));
    QString strtime;
    p.drawText(QPoint(50,60),"步数：" + QString::number(Game1.getStep()));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(Game1.getBoard(j,i) == 0){
                p.setBrush(Qt::lightGray);
                p.drawRect(i*110 + 65,j*110 +190,100,100);
            }
            else{
                p.setBrush(QBrush(QColor("lemonchiffon")));
                p.drawRect(i*110 + 65,j*110 +190,100,100);
                p.setFont(QFont("微软雅黑",10,700,false));
                p.drawText(QPoint(i*110 + 120,j*110 +245),QString::number(Game1.getBoard(j,i)));
            }
        }
    }
}


void lesson1::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
    case Qt::Key_W:
        Game1.PressUp();
        break;
    case Qt::Key_S:
        Game1.PressDown();
        break;
    case Qt::Key_A:
        Game1.PressLeft();
        break;
    case Qt::Key_D:
        Game1.PressRight();
        break;
    default:
        break;
    }
    update();
    if(Game1.isSolved()){
        Game1.clear();
        Game1.closemusic();
        lesson1Victory();
    }
}
void lesson1::lesson1Victory(){
    victoryMessage *e = new victoryMessage;
    e -> show();
    close();
}


void lesson1::on_out_clicked()
{
    Game1.closemusic();
    Game1.clear();
    Game1.resetSteps();
    MainWindow *w = new MainWindow;
    w -> show();
    close();
}
