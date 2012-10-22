#ifndef MAINDEVICE_H
#define MAINDEVICE_H

#include <QWidget>
#include"humanai_aithread.h"
#include "humanai_herodisplay.h"
#include "humanai_replaydevice.h"
#include "platform/Status.h"
#include "platform/logic.h"
#include <QTimer>
#include <QLabel>
#include <QtGui>

class maindevice : public QWidget
{
    Q_OBJECT
private:
    heroDisplay AI1Hero[3];
    heroDisplay AI2Hero[3];
    QLabel AI1Info;
    QLabel AI2Info;
    replayDevice *gameDisplay;
    DS14::logic TheGame;
    QTimer GameTimer;
    DS14::PlayerCommand command2;
    DS14::Coordinate EnemyPosition[3];

    QString map_path;
    AiThread * ai;
    int humanSide;



public:
    explicit maindevice(QWidget *parent = 0);
    ~maindevice();
    
signals:
    void gameEnd(int);

private slots:
    void GameUpdate();
    //void INNERAI();
    void LoadMap();
    void LoadAI();
    void StartGame();
    void connectError();
    void initError();
    void pathError();
    void versionError();
    void end();

};

#endif // MAINDEVICE_H
