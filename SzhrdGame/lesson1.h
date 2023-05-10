#ifndef LESSON1_H
#define LESSON1_H

#include <QMainWindow>
#include <QPainter>
#include <QTime>
#include <QDebug>
#include <QMessageBox>
#include <QKeyEvent>
#include "szhrd.h"


namespace Ui {
class lesson1;
}

class lesson1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit lesson1(QWidget *parent = nullptr);
    ~lesson1();

    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
    void lesson1Victory();




private slots:
    void on_start_clicked();

private:
    Ui::lesson1 *ui;
};

#endif // LESSON1_H
