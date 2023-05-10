#include "lesson2.h"
#include "ui_lesson2.h"
#include "szhrd.h"
#include "victorymessage.h"

Szhrd Game2(4,4);

lesson2::lesson2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::lesson2)
{
    ui->setupUi(this);

    Game2.playmusic();

    connect(ui->start_2,SIGNAL(clicked(bool)),this,SLOT(on_manual_clicked()));
    connect(ui->out_2,SIGNAL(clicked(bool)),this,SLOT(on_manual_clicked()));
}

lesson2::~lesson2()
{
    delete ui;
}

void lesson2::on_start_2_clicked()
{
    Game2.makeBoard();
    Game2.resetSteps();
    update();
}

void lesson2::paintEvent(QPaintEvent *){
    QPainter p(this);
    p.setPen(Qt::black);
    p.setFont(QFont("宋体",15,700,false));
    QString strtime;
    p.drawText(QPoint(50,60),"步数：" + QString::number(Game2.getStep()));
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(Game2.getBoard(j,i) == 0){
                p.setBrush(Qt::lightGray);
                p.drawRect(i*110 + 65,j*110 +190,100,100);
            }
            else{
                p.setBrush(QBrush(QColor("lemonchiffon")));
                p.drawRect(i*110 + 65,j*110 +190,100,100);
                p.setFont(QFont("微软雅黑",10,700,false));
                p.drawText(QPoint(i*110 + 120,j*110 +245),QString::number(Game2.getBoard(j,i)));
            }
        }
    }
}


void lesson2::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
    case Qt::Key_W:
        Game2.PressUp();
        break;
    case Qt::Key_S:
        Game2.PressDown();
        break;
    case Qt::Key_A:
        Game2.PressLeft();
        break;
    case Qt::Key_D:
        Game2.PressRight();
        break;
    default:
        break;
    }
    update();
    if(Game2.isSolved()){
        Game2.clear();
        Game2.closemusic();
        lesson2Victory();
        close();
    }
}

void lesson2::lesson2Victory(){
    victoryMessage *e = new victoryMessage;
    e -> changeType(2);
    e -> show();
    close();
}

void lesson2::on_out_2_clicked()
{
    Game2.closemusic();
    Game2.clear();
    Game2.resetSteps();
    MainWindow *w = new MainWindow;
    w -> show();
    close();
}
