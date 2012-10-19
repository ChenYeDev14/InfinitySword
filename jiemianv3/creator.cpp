#include "creator.h"
#include <QtGui>
#include <QDebug>

Creator::Creator(QApplication &app)
{
    //播放音乐文件
    media = new Phonon::MediaObject();
    audioOutput = new Phonon::AudioOutput(Phonon::VideoCategory);//声音
    Phonon::createPath(media, audioOutput);
    sourceList.append(QString("music/infinity.wma"));


    //建立pad
    pad = new RoundRectItem(QRectF(QPointF(0,0),QPointF(0,0)),QColor(0,0,255,0));
    pad->setZValue(0);

    //设置backwindow
    backWindow = new QGraphicsProxyWidget(pad);
    backWidget = new BackWidget();
    backWindow->setX(0);
    backWindow->setY(0);
 //   backWindow->widget()->setWindowOpacity(1);
    backWindow->setWidget(backWidget);
    backWindow->setZValue(0);


    //设置开始窗口按钮
    beginWindow = new QGraphicsProxyWidget(pad);
    beginWidget = new BeginBottum;
    beginWindow->setWidget(beginWidget);
    beginWindow->setX(backWindow->x()+400);
    beginWindow->setY(backWindow->y()+200);
    beginWindow->widget()->setWindowOpacity(1);
    beginWindow->setZValue(0.5);

    //设置音乐按键
    musicWindow = new QGraphicsProxyWidget(pad);
    musicWidget = new ClickBottum;
    musicWindow->setWidget(musicWidget);
    musicWindow->setX(backWindow->widget()->width()-120);
    musicWindow->setY(backWindow->y()+20);
    musicWindow->widget()->setWindowOpacity(1);
    musicWindow->setZValue(0.9);


    //设置AI对战窗口
    aiWindow = new QGraphicsProxyWidget(pad);
    aiWidget = new AIvsAI();
    aiWindow->setWidget(aiWidget);
    aiWindow->setX(backWindow->x());
    aiWindow->setY(backWindow->y());
    aiWindow->widget()->setWindowOpacity(0);
    aiWindow->setZValue(0.5);

    //按钮控件
    singleWindow = new QGraphicsProxyWidget(pad);
    singleWidget = new widgetssingle;
    singleWindow->setWidget(singleWidget);
    singleWindow->setX(backWindow->x()+400);
    singleWindow->setY(backWindow->y()+200);
    singleWindow->widget()->setWindowOpacity(0);
    singleWindow->setZValue(0.5);

    //回放器
    replayerWindow = new QGraphicsProxyWidget(pad);
    replayerWidget = new ReplayWindow();
    replayerWindow->setWidget(replayerWidget);
    replayerWindow->setX(backWindow->x());
    replayerWindow->setY(backWindow->y());
    replayerWindow->widget()->setWindowOpacity(0);
    replayerWindow->setZValue(0.5);

    //地图编辑器
    mapEditWindow = new QGraphicsProxyWidget(pad);
    mapWideget = new MapEditor();
    mapEditWindow->setWidget(mapWideget);
    mapEditWindow->setX(backWindow->x());
    mapEditWindow->setY(backWindow->y());
    mapEditWindow->widget()->setWindowOpacity(0);
    mapEditWindow->setZValue(0.5);

    //人机对战
    humanaiWindow = new QGraphicsProxyWidget(pad);
    humanaiWidget = new humanai();
    humanaiWindow->setWidget(humanaiWidget);
    humanaiWindow->setX(backWindow->x());
    humanaiWindow->setY(backWindow->y());
    humanaiWindow->widget()->setWindowOpacity(0);
    humanaiWindow->setZValue(0.5);

    //制作团队
    teamMeneWindow = new QGraphicsProxyWidget(pad);
    teamMeneWideget = new TeamMenu();
    teamMeneWindow->setWidget(teamMeneWideget);
    teamMeneWindow->setX(backWindow->x());
    teamMeneWindow->setY(backWindow->y());
    teamMeneWindow->widget()->setWindowOpacity(1);
    teamMeneWindow->setZValue(0.5);

    teamWindow = new QGraphicsProxyWidget(pad);
    teamWideget = new ProductionTeam();
    teamWindow->setWidget(teamWideget);
    teamWindow->widget()->setWindowOpacity(1);
    teamWindow->setZValue(0.5);
    teamWideget->setAutoFillBackground(true);
    QPalette Tpalette = teamWindow->palette();
    Tpalette.setBrush(QPalette::Window,
                      QBrush(Qt::black));
    teamWindow->setPalette(Tpalette);


//  beginWindow->close();
    aiWindow->close();
    singleWindow->close();
    replayerWindow->close();
    teamMeneWindow->close();
    teamWindow->close();
    mapEditWindow->close();
    humanaiWindow->close();

    QObject::connect(beginWidget->returnUi()->exitmain,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(beginWidget->returnUi()->startsingle,SIGNAL(clicked()),this,SLOT(BeginToSingle()));
    connect(this->singleWidget->ui->returnpre,SIGNAL(clicked()),this,SLOT(SingleToBegin()));
    connect(this->singleWidget->ui->aivsai,SIGNAL(clicked()),this,SLOT(SingleToAi()));
    connect(this->aiWidget->ui->ReturnPre,SIGNAL(clicked()),this,SLOT(AiToSingle()));
    connect(this->singleWidget->ui->replay,SIGNAL(clicked()),this,SLOT(SingleToReplayer()));
    connect(this->replayerWidget->returnUi()->pushButton,SIGNAL(clicked()),this,SLOT(ReplayerToSingle()));
    connect(this->beginWidget->returnUi()->team,SIGNAL(clicked()),this,SLOT(BeginToTeam()));
    connect(this->teamMeneWideget->returnUi()->pushButton,SIGNAL(clicked()),this,SLOT(TeamToBegin()));
    connect(this->musicWidget->ui->checkBox,SIGNAL(clicked()),this,SLOT(Music()));
    connect(this->replayerWidget->returnUi()->pushButton,SIGNAL(clicked()),this->replayerWidget,SLOT(GoInto()));
    connect(this->mapWideget->returnUi()->pushButton_5,SIGNAL(clicked()),this,SLOT(MapToSingle()));
    connect(this->singleWidget->ui->mapedit,SIGNAL(clicked()), this, SLOT(SingLeToMap()));
    connect(this->singleWidget->ui->playervsai,SIGNAL(clicked()),this,SLOT(SingleToHumanai()));
    connect(this->humanaiWidget->returnUi()->Button_back, SIGNAL(clicked()), this, SLOT(HumanaiToSingle()));
    connect(this->media,SIGNAL(aboutToFinish()),this,SLOT(continueMusic()));

//    connect(this->singleWidget->ui->replay,SIGNAL(clicked()),this->replayerWidget,SLOT(GoInto()));

    //设置界面背景
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->addItem(pad);
    scene->setBackgroundBrush(QBrush(QColor(0,0,0,255)));
    scene->setSceneRect(scene->itemsBoundingRect());

    setScene(scene);
    showFullScreen();

    //建立状态
    stateMachine = new QStateMachine(this);
    MainState = new QState(stateMachine);
    TeamState = new QState(stateMachine);
    BeginState = new QState(stateMachine);
    CheckState = new QState(stateMachine);
    ReplayerState = new QState(stateMachine);
    WebState = new QState(stateMachine);
    MapState = new QState(stateMachine);
    HumanaiState = new QState(stateMachine);
    ChatState = new QState(stateMachine);
    WidState = new QState(stateMachine);

    BeginMenuState= new QState(stateMachine);
    SingleState= new QState(stateMachine);
    OldMenuState = new QState(stateMachine);
    CheckMenuState = new QState(stateMachine);
    TeamMenuState = new QState(stateMachine);

    MainState->assignProperty(MainState, "z", 0);
    MainState->assignProperty(beginWindow->widget(), "windowOpacity", 1);

    stateMachine->setInitialState(MainState);
    stateMachine->start();
}

Creator::~Creator()
{
    delete aiWidget;
}

void Creator::resizeEvent(QResizeEvent *event)
 {
     QGraphicsView::resizeEvent(event);
     fitInView(scene()->sceneRect(), Qt::KeepAspectRatio);
 }


void Creator::BeginToSingle()
{
    singleWindow->show();

    QParallelAnimationGroup* sequintial = MenuAnimation(beginWindow, singleWindow, BeginMenuState, SingleState);
    sequintial->start();
    sleep(1000);

    beginWindow->close();
 //   qDebug() << "lalala";
}


void Creator::SingleToBegin()
{
    beginWindow->show();

    QParallelAnimationGroup* sequintial = MenuAnimation(singleWindow, beginWindow, SingleState, BeginMenuState);
    sequintial->start();
    sleep(1000);

    singleWindow->close();
}

void Creator::SingleToAi()
{
    aiWindow->show();

    QParallelAnimationGroup* parallelMenu = MenuToWindowAnimation(singleWindow, aiWindow, SingleState , OldMenuState);
    parallelMenu->start();
    sleep(1000);

    singleWindow->close();
}

void Creator::AiToSingle()
{
    singleWindow->show();

    QParallelAnimationGroup* parallelMenu = WindowToMenuAnimation(aiWindow, singleWindow ,OldMenuState , SingleState );
    parallelMenu->start();
    sleep(1000);

    aiWindow->close();
}

void Creator::SingleToReplayer()
{
    replayerWindow->show();

    QParallelAnimationGroup* parallelWindow = MenuToWindowAnimation( singleWindow , replayerWindow, SingleState , ReplayerState);
    parallelWindow->start();
    sleep(1000);

    singleWindow->close();
}

void Creator::ReplayerToSingle()
{
//    replayerWidget->returnUi()->label->hide();
    singleWindow->show();

    QParallelAnimationGroup* parallelWindow = WindowToMenuAnimation( replayerWindow ,singleWindow , ReplayerState , SingleState);
    parallelWindow->start();
    sleep(1000);

    replayerWindow->close();
}

void Creator::BeginToTeam()
{
    beginWindow->close();
    backWindow->close();
    teamWindow->show();
    teamMeneWindow->show();
}

void Creator::TeamToBegin()
{
    teamWindow->close();
    teamMeneWindow->close();
    beginWindow->show();
    backWindow->show();
}

void Creator::Music()
{
    if(sourceList.isEmpty()){
        QMessageBox::information(this, tr("no music files"), tr("no files to play"));
        return;
    }
     media->setQueue(sourceList);//列表循环
     if(media->state() == Phonon::PlayingState)
         media->pause();
     else{
          media->play();
     }
}

void Creator::closeEvent(QCloseEvent *)
{
    if(media->state() == Phonon::PlayingState){
        this->musicWidget->ui->checkBox->setTristate(false);
        media->pause();
    }
    media->stop();
}


void Creator::sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void Creator::MapToSingle()
{
    singleWindow->show();

    QParallelAnimationGroup* parallelWindow = WindowToMenuAnimation( mapEditWindow ,singleWindow , MapState , SingleState);
    parallelWindow->start();
    sleep(1000);

    mapEditWindow->close();
}

void Creator::SingLeToMap()
{
    mapEditWindow->show();

    QParallelAnimationGroup* parallelWindow = MenuToWindowAnimation( singleWindow , mapEditWindow, SingleState , MapState);
    parallelWindow->start();
    sleep(1000);

    singleWindow->close();
}

void Creator::HumanaiToSingle()
{
    singleWindow->show();

    QParallelAnimationGroup* parallelWindow = WindowToMenuAnimation( humanaiWindow ,singleWindow , HumanaiState , SingleState);
    parallelWindow->start();
    sleep(1000);

    humanaiWindow->close();
}

void Creator::SingleToHumanai()
{
    humanaiWindow->show();

    QParallelAnimationGroup* parallelWindow = MenuToWindowAnimation( singleWindow , humanaiWindow, SingleState , HumanaiState);
    parallelWindow->start();
    sleep(1000);

    singleWindow->close();
}


void Creator::continueMusic()
{
    media->enqueue(sourceList);
    media->play();
}
