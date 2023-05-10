#ifndef EASTEREGG_H
#define EASTEREGG_H

#include <QMainWindow>


namespace Ui {
class EasterEgg;
}

class EasterEgg : public QMainWindow
{
    Q_OBJECT

public:
    explicit EasterEgg(QWidget *parent = nullptr);
    ~EasterEgg();

    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);

private:
    Ui::EasterEgg *ui;
};

#endif // EASTEREGG_H
