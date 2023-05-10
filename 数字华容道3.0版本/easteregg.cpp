#include "easteregg.h"
#include "ui_easteregg.h"
#include "szhrd.h"
#include "video.h"



Szhrd Game(10,10);
EasterEgg::EasterEgg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EasterEgg)
{
    ui->setupUi(this);
    Game.makeBoard();
    Game.playmusic();
    connect(ui->vip,SIGNAL(clicked(bool)),this,SLOT(on_manual_clicked()));
}

EasterEgg::~EasterEgg()
{
    delete ui;
}





void EasterEgg::paintEvent(QPaintEvent *){
    QPainter p(this);
    p.setPen(Qt::black);
    p.setFont(QFont("宋体",15,700,false));
    QString strtime;
    p.drawText(QPoint(50,100),"这里有一个10阶数字华容道，完成它可能会有惊喜哦。");
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(Game.getBoard(j,i) == 0){
                p.setBrush(Qt::lightGray);
                p.drawRect(i*70 + 50,j*70 +160,60,60);
            }
            else{
                p.setBrush(QBrush(QColor("lemonchiffon")));
                p.drawRect(i*70 + 50,j*70 +160,60,60);
                p.setFont(QFont("微软雅黑",10,700,false));
                p.drawText(QPoint(i*70 + 70,j*70 +200),QString::number(Game.getBoard(j,i)));
            }
        }
    }
}


void EasterEgg::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
    case Qt::Key_W:
        Game.PressUp();
        break;
    case Qt::Key_S:
        Game.PressDown();
        break;
    case Qt::Key_A:
        Game.PressLeft();
        break;
    case Qt::Key_D:
        Game.PressRight();
        break;
    default:
        break;
    }
    update();
    if(Game.isSolved()){
        video *bb = new video;
        bb ->show();
        close();
        Game.closemusic();
    }
}

void EasterEgg::on_vip_clicked()
{
    Game.vipmakeBoard();
    update();
}
