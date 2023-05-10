#include "lesson3.h"
#include "ui_lesson3.h"
#include "szhrd.h"
#include "victorymessage.h"

Szhrd Game3(5,5);
lesson3::lesson3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::lesson3)
{
    ui->setupUi(this);

    Game3.playmusic();

    connect(ui->start_3,SIGNAL(clicked(bool)),this,SLOT(on_manual_clicked()));
    connect(ui->out_3,SIGNAL(clicked(bool)),this,SLOT(on_manual_clicked()));
}
lesson3::~lesson3()
{
    delete ui;
}


void lesson3::on_start_3_clicked()
{
    Game3.makeBoard();
    Game3.resetSteps();
    update();
}

void lesson3::paintEvent(QPaintEvent *){
    QPainter p(this);
    p.setPen(Qt::black);
    p.setFont(QFont("宋体",15,700,false));
    QString strtime;
    p.drawText(QPoint(50,60),"步数：" + QString::number(Game3.getStep()));
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(Game3.getBoard(j,i) == 0){
                p.setBrush(Qt::lightGray);
                p.drawRect(i*110 + 65,j*110 +190,100,100);
            }
            else{
                p.setBrush(QBrush(QColor("lemonchiffon")));
                p.drawRect(i*110 + 65,j*110 +190,100,100);
                p.setFont(QFont("微软雅黑",10,700,false));
                p.drawText(QPoint(i*110 + 120,j*110 +245),QString::number(Game3.getBoard(j,i)));
            }
        }
    }
}


void lesson3::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
    case Qt::Key_W:
        Game3.PressUp();
        break;
    case Qt::Key_S:
        Game3.PressDown();
        break;
    case Qt::Key_A:
        Game3.PressLeft();
        break;
    case Qt::Key_D:
        Game3.PressRight();
        break;
    default:
        break;
    }
    update();
    if(Game3.isSolved()){
        Game3.clear();
        Game3.closemusic();
        lesson3Victory();
        close();
    }
}

void lesson3::lesson3Victory(){
    victoryMessage *e = new victoryMessage;
    e -> changeType(3);
    e -> show();
    close();
}

void lesson3::on_out_3_clicked()
{
    Game3.closemusic();
    Game3.clear();
    Game3.resetSteps();
    MainWindow *w = new MainWindow;
    w -> show();
    close();
}
