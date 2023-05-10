#ifndef VIDEO_H
#define VIDEO_H

#include <QWidget>
#include <QtMultimedia/QtMultimedia>
#include <QtMultimediaWidgets/QVideoWidget>

namespace Ui {
class video;
}

class video : public QWidget
{
    Q_OBJECT

public:
    explicit video(QWidget *parent = nullptr);
    ~video();

    QTimer* Timer_;
public slots:
    void Timer_func();


private:
    Ui::video *ui;
};

#endif // VIDEO_H
