#ifndef REPLAYDEVICE_H
#define REPLAYDEVICE_H
#include "Status.h"
#include <QWidget>

class replayDevice : public QWidget
{
    Q_OBJECT
private:
    DS14::Status gameStatus;
    DS14::Coordinate toGameCo(QPoint programCo);
    QPoint toProCo(DS14::Coordinate gameCo);
public:

    explicit replayDevice(QWidget *parent = 0);

    void paintEvent(QPaintEvent *e);
    void setStatus(DS14::Status GS);

signals:
    
public slots:
    
};

#endif // REPLAYDEVICE_H
