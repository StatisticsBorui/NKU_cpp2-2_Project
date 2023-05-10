#ifndef LESSON2_H
#define LESSON2_H

#include <QMainWindow>

namespace Ui {
class lesson2;
}

class lesson2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit lesson2(QWidget *parent = nullptr);
    ~lesson2();

    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
    void lesson2Victory();

private slots:
    void on_start_2_clicked();

private:
    Ui::lesson2 *ui;
    int times = 0;
};

#endif // LESSON2_H
