#ifndef LESSON3_H
#define LESSON3_H

#include <QMainWindow>

namespace Ui {
class lesson3;
}

class lesson3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit lesson3(QWidget *parent = nullptr);
    ~lesson3();

    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
    void lesson3Victory();
private slots:
    void on_start_3_clicked();

private:
    Ui::lesson3 *ui;
};

#endif // LESSON3_H
