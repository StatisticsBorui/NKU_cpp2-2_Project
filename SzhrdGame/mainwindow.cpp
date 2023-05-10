#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lesson1.h"
#include "lesson2.h"
#include "lesson3.h"
#include "easteregg.h"
#include "helpmessage.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(on_manual_clicked()));
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(on_manual_clicked()));
    connect(ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(on_manual_clicked()));
    connect(ui->help,SIGNAL(clicked(bool)),this,SLOT(on_manual_clicked()));
    connect(ui->exitButton,SIGNAL(clicked(bool)),this,SLOT(on_manual_clicked()));


}





MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    lesson1 *d1 = new lesson1;
    d1->show();
    close();
}

void MainWindow::on_pushButton_2_clicked()
{
    lesson2 *d2 = new lesson2;
    d2->show();
    close();
}

void MainWindow::on_pushButton_3_clicked()
{
    lesson3 *d3 = new lesson3;
    d3->show();
    close();
}

void MainWindow::on_help_clicked()
{
    EasterEgg_count++;
    if(EasterEgg_count > 10){
        EasterEgg *d = new EasterEgg;
        d ->show();
        close();
    }
    if(EasterEgg_count == 1){
        helpMessage *h = new helpMessage;
        h -> show();
    }
}

void MainWindow::on_exitButton_clicked()
{
    exit(0);
}
