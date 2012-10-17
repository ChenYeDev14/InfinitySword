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

    BackWidget* backWidget;
    BeginBottum* beginWidget;
    ClickBottum* musicWidget;
    AIvsAI* aiWidget;
    widgetssingle* singleWidget;
    ReplayWindow* replayerWidget;
    TeamMenu* teamMeneWideget;
    ProductionTeam* teamWideget;
    MapEditor* mapWideget;

 //≤•∑≈“Ù¿÷
    Phonon::MediaObject *media;
    Phonon::AudioOutput *audioOutput;
    QList<Phonon::MediaSource> sourceList;

    QStateMachine* stateMachine;
    QState* MainState;
    QState* TeamState;
    QState* BeginState;
    QState* CheckState;
    QState* BeginMenuState;
    QState* SingleState;
    QState* OldMenuState;
    QState* CheckMenuState;
    QState* TeamMenuState;
    QState* ReplayerState;
    QState* WebState;
    QState* MapState;
    QState* ChatState;
    QState* WidState;


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

protected:
    void closeEvent(QCloseEvent *);
    void resizeEvent(QResizeEvent *event);

};

#endif // CREATOR_H
