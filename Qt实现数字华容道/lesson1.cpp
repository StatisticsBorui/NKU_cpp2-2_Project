#include "lesson1.h"
#include "ui_lesson1.h"

lesson1::lesson1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::lesson1)
{
    ui->setupUi(this);
}

lesson1::~lesson1()
{
    delete ui;
}
