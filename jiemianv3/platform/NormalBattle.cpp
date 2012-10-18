#include "NormalBattle.h"
#include <QTime>
#include <QLocalServer>
#include <QLocalSocket>
#include <QProcess>
#include <QFile>
#include <QFileInfo>
#include <wchar.h>
#include <string>
#include <windows.h>


using namespace DS14;
NormalBattle::NormalBattle()
{
    pcMap = NULL;
    debug_mode = false;
    roundTime = 100;
    for (int i=0; i<2; i++)
    {
        server[i] = NULL;
        process[i] = NULL;
        aiThread[i] = NULL;
    }
    _logic = NULL;
    rFile = NULL;
    ended = false;
    completed = true;
}

NormalBattle::~NormalBattle()
{
    end();
}

/**********************************************************************************************************
 共用函数
 **********************************************************************************************************/
void NormalBattle::StartNormalBattle(QString side1, QString side2, QString map)
{
    ended = false;
    human = -1;
    debug = -1;
    ai[0] = side1;
    ai[1] = side2;
    map_location = map;
    //检查三个文件地址是否指向一个正确的文件
    QFile file(ai[0]);
    if (!file.exists())
    {
        if (ai[0] == "\\\human")
            human = 0;
        else if (ai[0] == "\\\debug")
            debug = 0;
        else
        {
            emit path_error(1);
            return;
        }
    }
    file.setFileName(ai[1]);
    if (!file.exists())
    {
        if (ai[1] == "\\\human")
            human = 1;
        else if (ai[1] == "\\\debug")
            debug = 1;
        else
        {
            emit path_error(2);
            return;
        }
    }
    file.setFileName(map_location);
    if (!file.exists())
    {
        emit path_error(0);
        return ;
    }
    debugAiStarted = false;
    terminate();
    wait();
    start();
}

int NormalBattle::WhetherWin(const Status &state)
{
    if (state.roundNumber == GAME_ROUNDS)
    {
        if (state.swordInfo.AI1SwordNumber > state.swordInfo.AI2SwordNumber) return 1;
        else if (state.swordInfo.AI1SwordNumber < state.swordInfo.AI2SwordNumber) return 2;
        else if (state.AI1gold > state.AI2gold) return 1;
        else if (state.AI1gold < state.AI2gold) return 2;
        else return 3;
    }
    else
    {
        if (state.swordInfo.AI1SwordNumber == 0 && state.swordInfo.AI2SwordNumber >= 5)
            return 2;
        else if (state.swordInfo.AI1SwordNumber >= 5 && state.swordInfo.AI2SwordNumber == 0)
            return 1;
    }
    return 0;
}

void NormalBattle::run()
{
    if (human == -1 && debug == -1) StartTwoAiBattle();
    else if (debug == -1) StartHumanAiBattle();
    else StartDebugBattle();
}

bool NormalBattle::InitAiInfo()
{
    for (int i=0; i<2; i++)
    {
        if (!client[i]->waitForReadyRead())
        {
            emit version_error(i+1);
            return false;
        }
        int ai_basic_version;
        client[i]->read((char*)&ai_basic_version, sizeof(int));
        if (ai_basic_version != VERSION_BASIC)
        {
            emit version_error(i+1);
            return false;
        }
    }
    PlayerInfo pInfo[2];
    QString playerName[2];
    for (int i=0; i<2; i++)
    {
        if (!client[i]->waitForReadyRead())
        {
            emit init_error(i+1);
            return false;
        }
        client[i]->read((char*)&pInfo[i], sizeof(PlayerInfo));
        playerName[i] = playerName[i].fromWCharArray(pInfo[i].teamName);

    }
    _logic = new logic;
    if (!_logic->init(map_location.toStdString()))
    {
        emit version_error(3);
        return false;
    }
    QFileInfo mapFile(map_location);
    rFile = new ReplayFile;
    rFile->NewFile(playerName[0].toStdString(), playerName[1].toStdString(), mapFile.baseName().toStdString());
    //StatusMapInfo mInfo; //  wait for logic add a function
    rFile->WriteInitialInfo(VERSION_BASIC, VERSION_LOGIC, pInfo[0], pInfo[1]);
    return true;
}
/**********************************************************************************************************
 调试对战函数
 **********************************************************************************************************/

void NormalBattle::StartDebugBattle()
{
    //初始化管道
   //处理初始化服务端。
    for (int i=0; i<2; i++)
    {
        server[i] = new QLocalServer;
        if (process[i] != NULL) delete process[i];
        process[i] = new QProcess;

    }
    QTime time = QTime::currentTime();
    QString listen_name[2] = {QString(time.toString("ss-mm")),
                              QString(time.toString("ss"))};
    server[0]->listen("DS14"+listen_name[0]);
    server[1]->listen("DS14"+listen_name[1]);

    HANDLE hFileMap = CreateFileMappingA((HANDLE)0xffffffff, NULL, PAGE_READWRITE, 0, 1, listen_name[1].toStdString().c_str());
    if(hFileMap == NULL)
    {
        emit mem_error();
    }
    pcMap = (LPBYTE)MapViewOfFile(hFileMap, FILE_MAP_READ|FILE_MAP_WRITE, 0, 0, 0);
    if(pcMap == NULL)
    {
        emit mem_error();
        CloseHandle(hFileMap);
        return;
    }
    *pcMap = 'R';

   //连接ai及界面
    process[!debug]->start(ai[!debug], QStringList()<<listen_name[!debug]);
    process[!debug]->waitForStarted(-1);


    emit ready_for_connect(listen_name[debug]); //发送管道名，显示给选手，选手手动输入Ai.exe后，通过调试器调用NormalBattle::connect进行连接
    while (!debugAiStarted) msleep(1);


    for (int i=0; i<2; i++)
    {
        if (!server[i]->waitForNewConnection(3000))
        {//等待三秒，若未能连接则返回错误并终止程序
            emit connect_error(i+1);
            *pcMap = 'E';
            process[!debug]->kill();
            msleep(100);
            UnmapViewOfFile(pcMap);
            CloseHandle(hFileMap);

            return;
        }
        client[i] = server[i]->nextPendingConnection();
        client[i]->waitForConnected(-1);
    }

    //开始对战
    if (!InitAiInfo())
    {
        *pcMap = 'E';
        process[!debug]->kill();
        msleep(100);
        UnmapViewOfFile(pcMap);
        CloseHandle(hFileMap);
        return;
    };

    emit(debug_battle_logic_prepared());
    char f;
    PlayerCommand *command[2];
    command[0] = NULL;
    command[1] = NULL;

    time.start();

    PlayerCommand cmd[2];
    Status state = _logic->getStatus();
    rFile->WriteStatus0(state);
    for (int i=0; i<2; i++)
    {
        for (int j=0; j<3; j++)
        {
            cmd[i].heroOrder[j] = walk;
            if (i == 0) cmd[i].target[j] = state.AI1HeroInfo[j].heroPosition;
            else cmd[i].target[j] = state.AI2HeroInfo[j].heroPosition;
            for (int k=0; k<MAX_UPDATE_NUMBER_PER_ROUND; k++) cmd[i].updateScience[j][k] = none;
        }
    }
    is_stoped = false;
    completed = false;
    while (!ended)
    {
        if (is_stoped)
        {
            msleep(1);
            continue;
        }
        if (debug_mode)     //单步调试模式
        {
            client[debug]->waitForReadyRead(-1);
            client[debug]->read(&f, sizeof(f));
            if (f == 'r')
            {
                GameInfo gInfo = _logic->toPlayer(debug+1);
                client[debug]->write((char*)&gInfo, sizeof(gInfo));
            }
            else if (f == 'w')
            {
                command[debug] = new PlayerCommand;
                client[debug]->waitForReadyRead(-1);
                client[debug]->read((char*)command[debug], sizeof(PlayerCommand));
            }

            client[!debug]->waitForReadyRead(-1);
            client[!debug]->read(&f, sizeof(f));
            if (f == 'r')
            {
                GameInfo gInfo = _logic->toPlayer(!debug+1);
                client[!debug]->write((char*)&gInfo, sizeof(gInfo));
            }
            else if (f == 'w')
            {
                command[!debug] = new PlayerCommand;
                client[!debug]->waitForReadyRead(-1);
                client[!debug]->read((char*)command[!debug], sizeof(PlayerCommand));
            }

            if (command[0] != NULL && command[1] != NULL)
            {
                bool end = UpDateCommand(command[0], command[1], true);
                delete command[0]; command[0] = NULL;
                delete command[1]; command[1] = NULL;
                if (end) break;
                time.restart();
            }
        }
        else    //非单步调试，正常运行
        {
            for (int i=0; i<2; i++)
                if (client[i]->waitForReadyRead(0))
                {
                    client[i]->read((char*)&f, sizeof(char));
                    if (f == 'r')
                    {
                        GameInfo gInfo = _logic->toPlayer(i+1);
                        client[i]->write((char*)&gInfo, sizeof(gInfo));
                    }
                    else if (f == 'w')
                    {
                        if (command[i] == NULL) command[i] = new PlayerCommand;
                        client[i]->waitForReadyRead(-1);
                        client[i]->read((char*)command[i], sizeof(PlayerCommand));
                    }
                }
            if (time.elapsed() >= roundTime)
            {
                for (int i=0; i<2; i++)
                    if (command[i] != NULL) cmd[i] = *command[i];
                bool end = UpDateCommand(&cmd[0], &cmd[1], command[0] != NULL || command[1] != NULL);
                state = _logic->getStatus();
                delete command[0]; command[0] = NULL;
                delete command[1]; command[1] = NULL;
                if (end) break;
                for (int i=0; i<2; i++)
                {
                    for (int j=0; j<3; j++)
                    {
                        cmd[i].heroOrder[j] = walk;
                        if (i==0) cmd[i].target[j] = state.AI1HeroInfo[j].heroPosition;
                        else cmd[i].target[j] = state.AI2HeroInfo[j].heroPosition;
                        for (int k=0; k<MAX_UPDATE_NUMBER_PER_ROUND; k++) cmd[i].updateScience[j][k] = none;
                    }
                }

                *pcMap = 'S';
                msleep(sleep_time);
                *pcMap = 'R';

                time.restart();
            }
        }
    }
    *pcMap = 'E';
    msleep(100);
    UnmapViewOfFile(pcMap);
    CloseHandle(hFileMap);
    process[!debug]->terminate();
    delete _logic;
    _logic = NULL;
    for (int i=0; i<2; i++)
    {
        client[i]->close();
        server[i]->close();
        delete server[i];
        server[i] = NULL;
    }
    completed = true;
}

void NormalBattle::ready_connect()
{
    debugAiStarted = true;
}

void NormalBattle::setSleepTime(int t)
{
    sleep_time = t;
}

bool NormalBattle::UpDateCommand(PlayerCommand *c1, PlayerCommand *c2, bool toRFile)
{
    _logic->update(c1, c2);
    Status state = _logic->getStatus();
    emit round(state.roundNumber);
    if (toRFile) rFile->WriteCommand(state.roundNumber-1, c1, c2);
    int winner = WhetherWin(state);
    if (winner)
    {
        rFile->WriteWinner(state.roundNumber, winner);
        emit send_winner(winner);
        delete rFile;
        rFile = NULL;
        return true;
    }
    return false;
}

void NormalBattle::change_to_debug_mode()
{
    //if (debug == -1) return;
    debug_mode = true;
}

void NormalBattle::change_to_run_mode()
{
    //if (debug == -1) return;
    debug_mode = false;
}

void NormalBattle::stopBattle()
{
    is_stoped = true;
}

void NormalBattle::continueBattle()
{
    is_stoped = false;
}

/**********************************************************************************************************
 人机对战函数
 **********************************************************************************************************/
void NormalBattle::StartHumanAiBattle()
{
}



/**********************************************************************************************************
 Ai对战函数
 **********************************************************************************************************/

void NormalBattle::StartTwoAiBattle()
{
    //初始化管道
    //处理初始化服务端。
   QTime time = QTime::currentTime();
   QString listen_name[2] = {QString(time.toString("ss-mm")),
                             QString(time.toString("ss"))};
   PlayerInfo pInfo[2];

   for (int i=0; i<2; i++)
   {
       if (aiThread[i] != NULL) delete aiThread[i];
       aiThread[i] = new AiReadWriteThread(listen_name[i], ai[i]);
   }
   connect(aiThread[0], SIGNAL(connectError()), this, SLOT(send_connect_error1()));
   connect(aiThread[1], SIGNAL(connectError()), this, SLOT(send_connect_error2()));

   HANDLE hFileMap = CreateFileMappingA((HANDLE)0xffffffff, NULL, PAGE_READWRITE, 0, 1, listen_name[1].toStdString().c_str());
   if(hFileMap == NULL)
   {
       emit mem_error();
   }
   pcMap = (LPBYTE)MapViewOfFile(hFileMap, FILE_MAP_READ|FILE_MAP_WRITE, 0, 0, 0);
   if(pcMap == NULL)
   {
       emit mem_error();
       CloseHandle(hFileMap);
       return;
   }
   *pcMap = 'R';

   aiThread[0]->start();
   aiThread[1]->start();
   for (int i=0; i<2; i++)
   {
       int init_state = aiThread[i]->readPlayerInfo(pInfo[i]);
       if (init_state <= 2)
       {
           if (init_state == 1) emit version_error(i+1);
           else emit init_error(i+1);
           *pcMap = 'E';
           for(int j=0; j<2; j++) aiThread[j]->Ter();
           return;
       }

   }

   QString playerName[2];
   for (int i=0; i<2; i++)
   {
       playerName[i] = playerName[i].fromWCharArray(pInfo[i].teamName);
   }

   _logic = new logic;
   if (!_logic->init(map_location.toStdString()))
   {
       emit version_error(3);
       *pcMap = 'E';
       for(int j=0; j<2; j++) aiThread[j]->Ter();
       return;
   }
   QFileInfo mapFile(map_location);
   rFile = new ReplayFile;
   rFile->NewFile(playerName[0].toStdString(), playerName[1].toStdString(), mapFile.baseName().toStdString());
   rFile->WriteInitialInfo(VERSION_BASIC, VERSION_LOGIC, pInfo[0], pInfo[1]);
   rFile->WriteStatus0(_logic->getStatus());

   //开始对战
   for (int i=0; i<2; i++)
   {
        aiThread[i]->reset(_logic->toPlayer(i+1));

   }
   bool game_over = false;
   Status state = _logic->getStatus();
   for (int i=0; i<3; i++)
   {
       pcmd1.heroOrder[i] = walk;
       pcmd1.target[i] = state.AI1HeroInfo[i].heroPosition;

       pcmd2.heroOrder[i] = walk;
       pcmd2.target[i] = state.AI2HeroInfo[i].heroPosition;
       for (int j=0; j<MAX_UPDATE_NUMBER_PER_ROUND; j++)
       {
           pcmd1.updateScience[i][j] = none;
           pcmd2.updateScience[i][j] = none;
       }
   }
   time.start();
   completed = false;
   while(!ended && !game_over)
   {
       if (time.elapsed() >= roundTime)
       {
           game_over = RoundTimer();
           time.restart();
       }
   }
   *pcMap = 'E';
   UnmapViewOfFile(pcMap);
   CloseHandle(hFileMap);
   completed = true;
}


bool NormalBattle::RoundTimer()
{
    Status old_state = _logic->getStatus();
    if (old_state.roundNumber % 2)
    {
        aiThread[0]->waitForReadingCompeleted();
        aiThread[1]->waitForReadingCompeleted();
    }
    else
    {
        aiThread[1]->waitForReadingCompeleted();
        aiThread[0]->waitForReadingCompeleted();
    }
    *pcMap = 'S';
    PlayerCommand *cmd1 = aiThread[0]->getCommand(),
                  *cmd2 = aiThread[1]->getCommand();

    if (cmd1 != NULL) pcmd1 = *cmd1;
    else //如果AI未更新Command
        for(int i=0; i<3; i++)
        {
            if (pcmd1.heroOrder[i] != walk) {pcmd1.heroOrder[i] = walk; pcmd1.target[i] = old_state.AI1HeroInfo[i].heroPosition;}
            for (int j=0; j<MAX_UPDATE_NUMBER_PER_ROUND; j++) pcmd1.updateScience[i][j] = none;

        }
    if (cmd2 != NULL) pcmd2 = *cmd2;
    else
        for(int i=0; i<3; i++)
        {
            if (pcmd2.heroOrder[i] != walk) {pcmd2.heroOrder[i] = walk; pcmd2.target[i] = old_state.AI2HeroInfo[i].heroPosition;}
            for (int j=0; j<MAX_UPDATE_NUMBER_PER_ROUND; j++) pcmd2.updateScience[i][j] = none;
        }

    _logic->update(&pcmd1, &pcmd2);
    Status state = _logic->getStatus();
    if (state.roundNumber % 10 == 0) emit round(state.roundNumber);
    //rFile->WriteRoundInfo(state);
    if (cmd1 != NULL || cmd2 != NULL) rFile->WriteCommand(state.roundNumber-1, cmd1, cmd2);
    int winner = WhetherWin(state);
    if (aiThread[0]->hasCrashed() && !aiThread[1]->hasCrashed()) winner = 2;
    else if (!aiThread[0]->hasCrashed() && aiThread[1]->hasCrashed()) winner = 1;
    else if (aiThread[0]->hasCrashed() && aiThread[1]->hasCrashed()) winner = 3;
    if (winner)
    {
        rFile->WriteWinner(state.roundNumber, winner);
        emit send_winner(winner);
        for (int i=0; i<2; i++)
        {
            aiThread[i]->Ter();
         }
        //killTimer(timerID);
        delete _logic;
        _logic = NULL;
        delete rFile;
        rFile = NULL;
        return true;
    }
    for (int i=0; i<2; i++)
    {
        aiThread[i]->reset(_logic->toPlayer(i+1));
    }
    *pcMap = 'R';
    return false;
}

void NormalBattle::end()
{
    ended = true;
    while (!completed) msleep(1);
    terminate();
    wait();
    for (int i=0; i<2; i++)
    {
        //delete server[i];
        if (process[i] != NULL)
        {
            process[i]->kill();
            //delete process[i];
        }
        if (aiThread[i] != NULL)
        {
            delete aiThread[i];
            aiThread[i] = NULL;
        }
    }   
    if (_logic != NULL) delete _logic;
    if (rFile != NULL) delete rFile;
    _logic = NULL;
    rFile = NULL;
}

void AiReadWriteThread::run()
{
    QLocalServer server;
    server.listen("DS14"+listen_name);
    //运行AI
    process = new QProcess;
    process->start(ai, QStringList() << listen_name);
    process->waitForStarted(-1);
    //连接
    if (!server.waitForNewConnection(3000))
    {
        emit connectError();
        return;
    }
    QLocalSocket *client = server.nextPendingConnection();
    client->waitForConnected(-1);
    //读入初始信息
    init_state = 0;
    if (!client->waitForReadyRead())
    {
        init_state = 1;
        return;
    }
    int ai_basic_version;
    client->read((char*)&ai_basic_version, sizeof(int));
    if (ai_basic_version != VERSION_BASIC)
    {
        init_state = 1;
        return;
    }
    if (!client->waitForReadyRead())
    {
        init_state = 2;
        return;
    }
    client->read((char*)&playerInfo, sizeof(playerInfo));
    init_state = 3;
    while (!ter)
    {
        //if (process.state() != QProcess::Running)
        //if (process.error() != QProcess::UnknownError)
        //if (process.exitStatus() == QProcess::CrashExit)
        if (process->waitForFinished(0))
        {
            crashed = true;
            break;
        }

        reading = false;
        while (!ter && !client->waitForReadyRead(1)) msleep(1);
        if (ter) break;
        char f = ' ';
        if (!stoped)
        {
            reading = true;
            client->read(&f, sizeof(f));
            if (f == 'r')
            {
                client->write((char*)&gInfo, sizeof(gInfo));
            }
            else if (f == 'w')
            {
                if (aiCommand == NULL) aiCommand = new PlayerCommand;
                client->waitForReadyRead(-1);
                client->read((char*)aiCommand, sizeof(PlayerCommand));
            }
        }
        else msleep(1);
    }

    client->close();
    server.close();
    process->terminate();
}

void AiReadWriteThread::waitForReadingCompeleted()
{
    stoped = true;
    while (reading) msleep(1);
}

void AiReadWriteThread::reset(const GameInfo &ngInfo)
{
    gInfo = ngInfo;
    if (aiCommand != NULL) delete aiCommand;
    aiCommand = NULL;
    stoped = false;
}

int AiReadWriteThread::readPlayerInfo(PlayerInfo &pInfo)
{
    while (!init_state) msleep(1);
    pInfo = playerInfo;
    return init_state;
}

bool AiReadWriteThread::hasCrashed()
{
    return crashed;
}

AiReadWriteThread::~AiReadWriteThread()
{
    Ter();
    wait();
    process->kill();
    if (aiCommand != NULL) delete aiCommand;
    aiCommand = NULL;
}


