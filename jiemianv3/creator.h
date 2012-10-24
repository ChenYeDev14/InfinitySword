#ifndef CREATOR_H
#define CREATOR_H

#include <QGraphicsView>
#include <QGraphicsProxyWidget>
#include <QWidget>
#include <QGraphicsScene>
#include <QWindowsXPStyle>
#include <QApplication>
#include <QObject>
#include <QPushButton>
#include <phonon/MediaObject>
#include <phonon/AudioOutput>
#include <QCloseEvent>
#include <QResizeEvent>
#include <QState>
#include <QStateMachine>

#include "rounditem.h"
#include "backwidget.h"
#include "beginbottum.h"
#include "clickbottum.h"
#include "aivsai.h"
#include "widgetssingle.h"
#include "replaywindow.h"
#include "teammenu.h"
#include "productionteam.h"
#include "Animation.h"
#include "mapeditor.h"
#include "humanai.h"
#include "loginwidget.h"
#include "testwidget.h"

class Creator : public QGraphicsView
{
    Q_OBJECT

public:
    Creator(QApplication &);
    ~Creator();
    void sleep(unsigned int msec);

private:
    RoundRectItem* pad;

    QGraphicsProxyWidget* backWindow;
    QGraphicsProxyWidget* beginWindow;
    QGraphicsProxyWidget* musicWindow;
    QGraphicsProxyWidget* aiWindow;
    QGraphicsProxyWidget* singleWindow;
    QGraphicsProxyWidget* replayerWindow;
    QGraphicsProxyWidget* teamWindow;
    QGraphicsProxyWidget* teamMeneWindow;
    QGraphicsProxyWidget* mapEditWindow;
    QGraphicsProxyWidget* humanaiWindow;
    QGraphicsProxyWidget* LogInWindow;
    QGraphicsProxyWidget* TestWindow;

    BackWidget* backWidget;
    BeginBottum* beginWidget;
    ClickBottum* musicWidget;
    AIvsAI* aiWidget;
    widgetssingle* singleWidget;
    ReplayWindow* replayerWidget;
    TeamMenu* teamMeneWideget;
    ProductionTeam* teamWideget;
    MapEditor* mapWideget;
    humanai* humanaiWidget;
    LogInWidget* logInwidget;
    TestWidget* testwidget;


 //≤•∑≈“Ù¿÷
    Phonon::MediaObject *media;
    Phonon::AudioOutput *audioOutput;
    QList<Phonon::MediaSource> sourceList;

    QStateMachine* stateMachine;
    QState* MainState;
    QState* TeamState;
    QState* BeginState;
    QState* TestState;
    QState* BeginMenuState;
    QState* SingleState;
    QState* OldMenuState;
    QState* CheckMenuState;
    QState* TeamMenuState;
    QState* ReplayerState;
    QState* WebState;
    QState* MapState;
    QState* HumanaiState;
    QState* ChatState;
    QState* WidState;
    QState* LogState;


private slots:
    void BeginToSingle();
    void SingleToBegin();
    void SingleToAi();
    void AiToSingle();
    void SingleToReplayer();
    void ReplayerToSingle();
    void TeamToBegin();
    void BeginToTeam();
    void MapToSingle();
    void SingLeToMap();
    void Music();
    void SingleToHumanai();
    void HumanaiToSingle();
    void continueMusic();
    void SingleToLogIn();
    void LogInToSingle();
    void LogInToTest(QString user_name);
    void TestToLogIn();


protected:
    void closeEvent(QCloseEvent *);
    void resizeEvent(QResizeEvent *event);

};

#endif // CREATOR_H
