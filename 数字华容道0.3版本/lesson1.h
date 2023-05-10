#ifndef LESSON1_H
#define LESSON1_H

#include <QMainWindow>

namespace Ui {
class lesson1;
}

class lesson1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit lesson1(QWidget *parent = nullptr);
    ~lesson1();

private:
    Ui::lesson1 *ui;
};

#endif // LESSON1_H
