

#include "humanai_maindevice.h"
#include <iostream>
#include <QFile>
#include <QMessageBox>


maindevice::maindevice(QWidget *parent) :
    QWidget(parent)
{
    humanSide = 2;

    map_path = "";
    ai = new AiThread;
    connect(ai, SIGNAL(connect_error()), this, SLOT(connectError()));
    connect(ai, SIGNAL(init_error()), this, SLOT(initError()));
    connect(ai, SIGNAL(path_error()), this, SLOT(pathError()));
    connect(ai, SIGNAL(version_error()), this, SLOT(versionError()));

    setFixedSize(1024,768);
    for(int i = 0;i<3;i++)
    {

        //setAutoFillBackground(true);
        //QPalette palette;
        //palette.setBrush(QPalette::Background, QBrush(QPixmap(":/image/bg2.png")));
        //setPalette(palette);

        AI1Hero[i].setParent(this);
        AI2Hero[i].setParent(this);
        AI1Hero[i].setHeroIndex(i);
        AI1Hero[i].setHeroInfo(TheGame.getStatus().AI1HeroInfo[i]);
        AI1Hero[i].setGeometry(72,100*i,128,100);
        AI2Hero[i].setHeroIndex(i+3);
        AI2Hero[i].setHeroInfo(TheGame.getStatus().AI2HeroInfo[i]);
        AI2Hero[i].setGeometry(928,100*i,128,100);
        AI1Hero[i].repaint();
        AI2Hero[i].repaint();
    }
    gameDisplay = new replayDevice(this);
    gameDisplay->setParent(this);
    gameDisplay->setStatus(TheGame.getStatus());
    gameDisplay->setGeometry(200,80,600,600);
    gameDisplay->setHumanSide(humanSide);
    QPalette pa1;
    AI1Info.setParent(this);
    AI2Info.setParent(this);
    AI1Info.setGeometry(72,300,100,50);
    AI1Info.setText(QString("Gold:"+QString::number(TheGame.getStatus().AI1gold)+"\nPot:"+QString::number(TheGame.getStatus().swordInfo.AI1SwordNumber)) + QString("\n AI1"));
    AI2Info.setGeometry(728, 300, 100,50);
    AI2Info.setText(QString("Human \n Gold:"+QString::number(TheGame.getStatus().AI2gold)+"\nPot:"+QString::number(TheGame.getStatus().swordInfo.AI1SwordNumber)));


    connect(&(GameTimer),SIGNAL(timeout()),this,SLOT(GameUpdate()));


}


maindevice::~maindevice()
{
    ai->EndGame();
    delete ai;
    ai = NULL;
}

void maindevice::end()
{
    ai->EndGame();
}

void maindevice::GameUpdate()
{

    DS14::PlayerCommand command1 = gameDisplay->getHumanCommand();

    PlayerCommand * cmd2 = ai->AskCommand();
    if (cmd2 != NULL)
    {
        command2 = *cmd2;
        delete cmd2;
    }

    if (humanSide == 1)
    {
        TheGame.update(&command1,&command2);
        ai->SetGameInfo(TheGame.toPlayer(2));
    }
    else
    {
        TheGame.update(&command2,&command1);
        ai->SetGameInfo(TheGame.toPlayer(1));
    }

    for(int i = 0;i<=2;i++)
    {
        if (command2.heroOrder[i] != DS14::walk)
        {
            command2.heroOrder[i] = DS14::walk;
            if (humanSide == 1)
                command2.target[i] = TheGame.getStatus().AI2HeroInfo[i].heroPosition;
            else
                command2.target[i] = TheGame.getStatus().AI1HeroInfo[i].heroPosition;
        }
        for(int j = 0;j<DS14::MAX_UPDATE_NUMBER_PER_ROUND;j++)
        {
            command2.updateScience[i][j] = DS14::none;
        }

    }
    for(int i = 0;i<=2;i++)
    {
        AI1Hero[i].setHeroInfo(TheGame.getStatus().AI1HeroInfo[i]);
        AI2Hero[i].setHeroInfo(TheGame.getStatus().AI2HeroInfo[i]);
        AI1Hero[i].repaint();
        AI2Hero[i].repaint();
    }
    AI1Info.setText(QString("Gold:"+QString::number(TheGame.getStatus().AI1gold)+"\nPot:"+QString::number(TheGame.getStatus().swordInfo.AI1SwordNumber)));
    AI2Info.setText(QString("Gold:"+QString::number(TheGame.getStatus().AI2gold)+"\nPot:"+QString::number(TheGame.getStatus().swordInfo.AI2SwordNumber)));

    gameDisplay->setStatus(TheGame.getStatus());
    gameDisplay->repaint();
    this->gameDisplay->setFocus();

    if(TheGame.getStatus().roundNumber>=2399)
    {
        if(TheGame.getStatus().swordInfo.AI1SwordNumber>TheGame.getStatus().swordInfo.AI2SwordNumber)
        {
            emit(gameEnd(1));
        }
        else if(TheGame.getStatus().swordInfo.AI1SwordNumber<TheGame.getStatus().swordInfo.AI2SwordNumber)
        {
            emit(gameEnd(2));
        }
        else
        {
            emit(gameEnd(3));
        }
    }
    else if(TheGame.getStatus().swordInfo.AI1SwordNumber>=5&&TheGame.getStatus().swordInfo.AI2SwordNumber==0)
    {
        emit(gameEnd(1));
    }
    else if(TheGame.getStatus().swordInfo.AI2SwordNumber>=5&&TheGame.getStatus().swordInfo.AI1SwordNumber==0)
    {
        emit(gameEnd(2));
    }
}

void maindevice::LoadMap()
{
    QString fileName = QFileDialog::getOpenFileName(
                        this,
                        tr("打开文件"),
                        "MapFiles/",
                        tr("地图文件(*.map)"));
    map_path = fileName;
}

void maindevice::LoadAI()
{
    QString fileName = QFileDialog::getOpenFileName(
                        this,
                        tr("打开文件"),
                        "AIFiles/",
                        tr("AI文件(*.exe)"));
    ai->SetAIPath(fileName);
}

void maindevice::StartGame()
{
    QFile map(map_path);
    if (!map.exists())
    {
        QMessageBox::warning(this, QString(tr("路径错误")), QString(tr("地图路径错误！")));
        return;
    }
    TheGame.init(map_path);
    ai->StartGame(TheGame.toPlayer(2));
    GameTimer.start(200);
}

void maindevice::pathError()
{
    GameTimer.stop();
    QMessageBox::warning(this, QString(tr("路径错误")), QString(tr("AI路径出错，请正确载入AI")));
    emit gameEnd(0);
}

void maindevice::initError()
{
    GameTimer.stop();
    QMessageBox::warning(this, QString(tr("初始化错误")), QString(tr("AI初始化出错")));
    emit gameEnd(0);
}

void maindevice::connectError()
{
    GameTimer.stop();
    QMessageBox::warning(this, QString(tr("连接错误")), QString(tr("AI连接出错")));
    emit gameEnd(0);
}

void maindevice::versionError()
{
    GameTimer.stop();
    QMessageBox::warning(this, QString(tr("版本错误")), QString(tr("AI版本错误")));
    emit gameEnd(0);
}
