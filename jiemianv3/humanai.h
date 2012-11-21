#ifndef HUMANAI_H
#define HUMANAI_H
#include "humanai_maindevice.h"
#include "ui_humanai.h"

#include <QWidget>
#include"humanai_aithread.h"
#include "humanai_herodisplay.h"
#include "humanai_replaydevice.h"
#include "platform/Status.h"
#include "platform/logic.h"
#include "platform/replayfile.h"
#include <QTimer>
#include <QLabel>
#include <QtGui>

namespace Ui {
class humanai;
}

class humanai : public QWidget
{
    Q_OBJECT
    
public:
    explicit humanai(QWidget *parent = 0);
    Ui::humanai * returnUi(){return ui;}
    ~humanai();
    
private:
    Ui::humanai *ui;

    heroDisplay *AI1Hero[3];
    heroDisplay *AI2Hero[3];
    replayDevice *gameDisplay;
    DS14::logic TheGame;
    DS14::ReplayFile rFile;
    QTimer GameTimer;
    DS14::PlayerCommand command2;
    DS14::Coordinate EnemyPosition[3];

    QString map_path;
    AiThread * ai;
    int humanSide;

    void gameEnd(int);

public slots:
    void initEmpty();

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

    void ai_init_ready(QString);

    void on_Button_help_clicked();
};



#endif // HUMANAI_H
