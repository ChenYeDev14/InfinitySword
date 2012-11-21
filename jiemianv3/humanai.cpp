#include "humanai.h"
#include "ui_humanai.h"
#include <iostream>
#include <QFile>
#include <QMessageBox>
#include "FindPath.h"


humanai::humanai(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::humanai)
{
    ui->setupUi(this);
    ui->progressBar->setRange(0,2400);
    ui->lcdNumber_round->setNumDigits(4);
    connect(ui->Button_loadAI, SIGNAL(clicked()), this, SLOT(LoadAI()));
    connect(ui->Button_loadMap, SIGNAL(clicked()), this, SLOT(LoadMap()));
    connect(ui->Button_start, SIGNAL(clicked()), this, SLOT(StartGame()));
    connect(ui->Button_back, SIGNAL(clicked()), this, SLOT(end()));

    humanSide = 2;

    map_path = "";
    ai = new AiThread;
    connect(ai, SIGNAL(connect_error()), this, SLOT(connectError()));
    connect(ai, SIGNAL(init_error()), this, SLOT(initError()));
    connect(ai, SIGNAL(path_error()), this, SLOT(pathError()));
    connect(ai, SIGNAL(version_error()), this, SLOT(versionError()));
    connect(ai, SIGNAL(init_ready(QString)), this, SLOT(ai_init_ready(QString)));

    gameDisplay = NULL;
    for (int i=0; i<3; i++)
    {
        AI1Hero[i] = NULL;
        AI2Hero[i] = NULL;
    }

    initEmpty();
    connect(&(GameTimer),SIGNAL(timeout()),this,SLOT(GameUpdate()));
}

void humanai::initEmpty()
{
    ui->lcdNumber_round->display(0);
    ui->progressBar->setValue(0);
    if (humanSide == 1)
    {
        ui->flag1->setText("Human");
        ui->flag2->setText("AI");
    }
    else
    {
        ui->flag1->setText("AI");
        ui->flag2->setText("Human");
    }
    ui->AI1Info->setText(QString("Gold: 0\n\nSword: 0"));
    ui->AI2Info->setText(QString("Gold: 0\n\nSword: 0"));
    TheGame.init();
    setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/image/human_back.png")));
    setPalette(palette);
    for(int i = 0;i<3;i++)
    {
        if (AI1Hero[i] == NULL)
        {
            AI1Hero[i]= new heroDisplay;
            ui->Layout_AI1->addWidget(AI1Hero[i]);
        }
        AI1Hero[i]->setHeroIndex(i);
        AI1Hero[i]->setHeroInfo(TheGame.getStatus().AI1HeroInfo[i]);
        if (AI2Hero[i] == NULL)
        {
            AI2Hero[i] = new heroDisplay;
            ui->Layout_AI2->addWidget(AI2Hero[i]);
        }
        AI2Hero[i]->setHeroIndex(i+3);
        AI2Hero[i]->setHeroInfo(TheGame.getStatus().AI2HeroInfo[i]);

    }
    if (gameDisplay == NULL)
    {
        gameDisplay = new replayDevice(this);
        ui->Layout_display->addWidget(gameDisplay);
    }
    gameDisplay->setStatus(TheGame.getStatus());
    gameDisplay->setHumanSide(humanSide);
    int selectID = gameDisplay->getHeroChosen();
    for (int i=0; i<3; i++)
        if (humanSide == 1)
        {
            if (selectID == i) AI1Hero[i]->setSelected(true); else AI1Hero[i]->setSelected(false);
            AI2Hero[i]->setSelected(false);
        }
        else
        {
            if (selectID == i) AI2Hero[i]->setSelected(true); else AI2Hero[i]->setSelected(false);
            AI1Hero[i]->setSelected(false);
        }
}

humanai::~humanai()
{
    delete ui;
    ai->EndGame();
    delete ai;
    ai = NULL;
    delete gameDisplay;
    for (int i=0; i<3; i++)
    {
        delete AI1Hero[i];
        delete AI2Hero[i];
    }
}

void humanai::end()
{
    rFile.WriteErrorEnd();
    ai->EndGame();
    GameTimer.stop();
}

void humanai::GameUpdate()
{

    PlayerCommand command1 = gameDisplay->getHumanCommand();
    //搜路
    GameInfo humanSideInfo = TheGame.toPlayer(humanSide);
    for (int i=0; i<3; i++)
    {
        if (command1.heroOrder[i] == walk)
            command1.target[i] = FindPath::Goto(humanSideInfo, i, command1.target[i]);
    }
    PlayerCommand * cmd2 = ai->AskCommand();
    if (cmd2 != NULL)
    {
        command2 = *cmd2;
        delete cmd2;
    }

    if (humanSide == 1)
    {
        rFile.WriteCommand(TheGame.getStatus().roundNumber, &command1, &command2);
        TheGame.update(&command1,&command2);
        ai->SetGameInfo(TheGame.toPlayer(2));
    }
    else
    {
        rFile.WriteCommand(TheGame.getStatus().roundNumber, &command2, &command1);
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
    int selectID = gameDisplay->getHeroChosen();
    for (int i=0; i<3; i++) {AI1Hero[i]->setSelected(false); AI2Hero[i]->setSelected(false);}
    if (humanSide == 1)
        AI1Hero[selectID]->setSelected(true);
    else AI2Hero[selectID]->setSelected(true);
    for(int i = 0;i<=2;i++)
    {
        AI1Hero[i]->setHeroInfo(TheGame.getStatus().AI1HeroInfo[i]);
        AI2Hero[i]->setHeroInfo(TheGame.getStatus().AI2HeroInfo[i]);
        AI1Hero[i]->repaint();
        AI2Hero[i]->repaint();
    }
    ui->AI1Info->setText(QString("Gold: "+QString::number(TheGame.getStatus().AI1gold)+"\n\nSword: "+QString::number(TheGame.getStatus().swordInfo.AI1SwordNumber)));
    ui->AI2Info->setText(QString("Gold: "+QString::number(TheGame.getStatus().AI2gold)+"\n\nSword: "+QString::number(TheGame.getStatus().swordInfo.AI2SwordNumber)));

    gameDisplay->setStatus(TheGame.getStatus());
    gameDisplay->repaint();
    this->gameDisplay->setFocus();

    Status gameStatus = TheGame.getStatus();
    ui->lcdNumber_round->display(gameStatus.roundNumber);
    ui->progressBar->setValue(gameStatus.roundNumber);
    if(gameStatus.roundNumber>=2400)
    {
        if(gameStatus.swordInfo.AI1SwordNumber > gameStatus.swordInfo.AI2SwordNumber)
        {
            gameEnd(1);
        }
        else if(gameStatus.swordInfo.AI1SwordNumber < gameStatus.swordInfo.AI2SwordNumber)
        {
            gameEnd(2);
        }
        else
        {
            if (gameStatus.AI1gold > gameStatus.AI2gold) gameEnd(1);
            else if (gameStatus.AI1gold < gameStatus.AI2gold) gameEnd(2);
            else gameEnd(3);
        }
    }
    else if(gameStatus.swordInfo.AI1SwordNumber>=5 && gameStatus.swordInfo.AI2SwordNumber==0)
    {
        emit(gameEnd(1));
    }
    else if(gameStatus.swordInfo.AI2SwordNumber>=5 && gameStatus.swordInfo.AI1SwordNumber==0)
    {
        emit(gameEnd(2));
    }
}

void humanai::LoadMap()
{
    QString fileName = QFileDialog::getOpenFileName(
                        this,
                        tr("打开文件"),
                        "MapFiles/",
                        tr("地图文件(*.map)"));
    map_path = fileName;
}

void humanai::LoadAI()
{
    QString fileName = QFileDialog::getOpenFileName(
                        this,
                        tr("打开文件"),
                        "AIFiles/",
                        tr("AI文件(*.exe)"));
    ai->SetAIPath(fileName);
}

void humanai::StartGame()
{
    QFile map(map_path);
    if (!map.exists())
    {
        QMessageBox::warning(this, QString(tr("路径错误")), QString(tr("地图路径错误！")));
        return;
    }
    if (!TheGame.init(map_path))
    {
        QMessageBox::warning(this, QString(tr("版本错误")), QString(tr("地图版本出错")));
        return;
    }

    ai->StartGame(TheGame.toPlayer(2));

}

void humanai::ai_init_ready(QString tName)
{
    PlayerInfo pInfo;
    int n = tName.toWCharArray(pInfo.teamName);
    pInfo.teamName[n] = '\0';
    n = QString("hero1").toWCharArray(pInfo.heroName[0]);
    pInfo.heroName[0][n] = '\0';
    n = QString("hero2").toWCharArray(pInfo.heroName[1]);
    pInfo.heroName[1][n] = '\0';
    n = QString("hero3").toWCharArray(pInfo.heroName[2]);
    pInfo.heroName[1][n] = '\0';
    QFileInfo map(map_path);
    if (humanSide == 1)
    {
        PlayerInfo info_human = pInfo;
        QString("human").toWCharArray(info_human.teamName);

        rFile.NewFile("human", tName, map.baseName());
        rFile.WriteInitialInfo(VERSION_BASIC, VERSION_LOGIC, info_human, pInfo);
    }
    else
    {
        PlayerInfo info_human = pInfo;
        QString("human").toWCharArray(info_human.teamName);
        qDebug() <<"xx:"<<QString::fromWCharArray(info_human.teamName);
        rFile.NewFile("human", tName, map.baseName());
        rFile.WriteInitialInfo(VERSION_BASIC, VERSION_LOGIC, pInfo, info_human);
    }
    rFile.WriteStatus0(TheGame.getStatus());
    GameTimer.start(200);
}

void humanai::pathError()
{
    gameEnd(0);
    QMessageBox::warning(this, QString(tr("路径错误")), QString(tr("AI路径出错，请正确载入AI")));
}

void humanai::initError()
{
    gameEnd(0);
    QMessageBox::warning(this, QString(tr("初始化错误")), QString(tr("AI初始化出错")));
}

void humanai::connectError()
{
    gameEnd(0);
    QMessageBox::warning(this, QString(tr("连接错误")), QString(tr("AI连接出错")));
}

void humanai::versionError()
{
    gameEnd(0);
    QMessageBox::warning(this, QString(tr("版本错误")), QString(tr("AI版本错误")));

}

void humanai::gameEnd(int x)
{
    GameTimer.stop();
    ai->EndGame();
    if (x==0) return;
    rFile.WriteWinner(TheGame.getStatus().roundNumber, x);
    if (x == humanSide)
    {
        QMessageBox box;
        box.setWindowTitle(tr("游戏结束"));
        box.setIcon(QMessageBox::Information);
        box.setText(tr("恭喜，你获胜了！"));
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
    }
    else if (x < 3)
    {
        QMessageBox box;
        box.setWindowTitle(tr("游戏结束"));
        box.setIcon(QMessageBox::Information);
        box.setText(tr("恨遗憾，你输了！"));
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
    }
    else
    {
        QMessageBox box;
        box.setWindowTitle(tr("游戏结束"));
        box.setIcon(QMessageBox::Information);
        box.setText(tr("平局！"));
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
    }
}


void humanai::on_Button_help_clicked()
{
    QMessageBox box;
    box.setWindowTitle(tr("帮助"));
    box.setIcon(QMessageBox::Information);
    box.setText(tr("载入一个AI，载入张地图，就可以开始对战啦~~\n"
                   "【操作说明】\n"
                   "    【基本操作】\n"
                   "     选择英雄：按1、2、3\n"
                   "     移动英雄：鼠标右键\n"
                   "     对指定点使用技能：鼠标左键（先按技能操作键）\n"
                   "    【英雄技能】\n"
                   "     法术攻击（飞弹）：按C，鼠标左键点目标点\n"
                   "     疾风步：按W\n"
                   "     制裁之刃：按A，鼠标左键点目标\n"
                   "     战争践踏：按T\n"
                   "    【科技树升级】\n"
                   "     力量：Y\n"
                   "     敏捷：U\n"
                   "     疾风步：I\n"
                   "     战争践踏：O\n"
                   "     制裁之刃：P"));
    box.setStandardButtons(QMessageBox::Ok);
    box.exec();
}
