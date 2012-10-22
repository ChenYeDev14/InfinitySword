#ifndef REPLAYDEVICE_H
#define REPLAYDEVICE_H
#include "platform/Status.h"
#include <QWidget>

class replayDevice : public QWidget
{
    Q_OBJECT
private:
    DS14::Status gameStatus;

    DS14::PlayerCommand userCommand;
    int heroChoosen;

    bool missiling;
    bool attacking;
    double dist(double x1, double y1, double x2, double y2);

    int humanSide;


public:

    explicit replayDevice(QWidget *parent = 0);
    DS14::Coordinate toGameCo(QPoint programCo);
    QPoint toProCo(DS14::Coordinate gameCo);
    void paintEvent(QPaintEvent *e);
    void setStatus(DS14::Status GS);
    void mousePressEvent(QMouseEvent * e);
    void keyPressEvent(QKeyEvent *e);
    DS14::PlayerCommand getHumanCommand();
    void setHumanSide(int side) {humanSide = side;}
    int getHeroChosen() {return heroChoosen;}


signals:
    
public slots:
    
};

#endif // REPLAYDEVICE_H
