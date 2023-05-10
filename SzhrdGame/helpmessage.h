#ifndef HELPMESSAGE_H
#define HELPMESSAGE_H

#include <QDialog>

namespace Ui {
class helpMessage;
}

class helpMessage : public QDialog
{
    Q_OBJECT

public:
    explicit helpMessage(QWidget *parent = nullptr);
    ~helpMessage();

private:
    Ui::helpMessage *ui;
};

#endif // HELPMESSAGE_H
