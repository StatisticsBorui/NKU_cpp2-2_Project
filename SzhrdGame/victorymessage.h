#ifndef VICTORYMESSAGE_H
#define VICTORYMESSAGE_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class victoryMessage;
}

class victoryMessage : public QDialog
{
    Q_OBJECT

public:
    explicit victoryMessage(QWidget *parent = nullptr);
    ~victoryMessage();
    void changeType(int);

private slots:
    void on_buttonBox_accepted();


    void on_buttonBox_rejected();

private:
    Ui::victoryMessage *ui;
    int type = 1;


};

#endif // VICTORYMESSAGE_H
