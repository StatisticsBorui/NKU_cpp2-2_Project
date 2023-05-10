#ifndef HELPMESSAGE_H
#define HELPMESSAGE_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class helpMessage;
}

class helpMessage : public QDialog
{
    Q_OBJECT

public:
    explicit helpMessage(QWidget *parent = nullptr);
    ~helpMessage();

    QTimer* timeClose;

public slots:
    void timeClose_func();

private:
    Ui::helpMessage *ui;
};

#endif // HELPMESSAGE_H
