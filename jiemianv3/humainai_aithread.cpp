#include "humanai_aithread.h"
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
AiThread::AiThread()
{
    process = NULL;
    ai_path = "";
    command = NULL;

}

AiThread::~AiThread()
{
    EndGame();
    if (!wait(1000)) process->kill();
    if (command != NULL) delete command;
}

void AiThread::SetAIPath(const QString &path)
{
    ai_path = path;
}

void AiThread::StartGame(const GameInfo &gameInfo)
{
    QFile file(ai_path);
    if (!file.exists())
    {
        emit path_error();
        return;
    }
    gInfo = gameInfo;
    ended = false;
    reading = false;
    setting = false;
    /*if (cmd == NULL) cmd = new PlayerCommand;
    for (int i=0; i<3; i++)
    {
        cmd->heroOrder[i] = walk;
        cmd->target[i] = gInfo.selfHeroInfo[i].heroPosition;
        for (int j=0; j<MAX_UPDATE_NUMBER_PER_ROUND; j++) cmd->updateScience[i][j] = none;
    }*/
    command = NULL;
    terminate();
    start();
}

PlayerCommand * AiThread::AskCommand()
{
    setting = true;
    while(reading) msleep(1);
    if (command == NULL) return NULL;
    PlayerCommand *returncmd = new PlayerCommand;
    *returncmd = *command;
    delete command;
    command = NULL;
    setting = false;
    return returncmd;
}

void AiThread::SetGameInfo(const GameInfo &gameInfo)
{
    setting = true;
    while(reading) msleep(1);
    gInfo = gameInfo;
    setting = false;
    //time.restart();
}

void AiThread::EndGame()
{
    ended = true;
    if (!wait())
        process->kill();
}

void AiThread::run()
{
    QTime time = QTime::currentTime();
    QString listen_name = QString(time.toString("ss"));
    server = new QLocalServer;
    server->listen("DS14"+listen_name);

    HANDLE hFileMap = CreateFileMappingA((HANDLE)0xffffffff, NULL, PAGE_READWRITE, 0, 1, listen_name.toStdString().c_str());
    if(hFileMap == NULL)
    {
        emit mem_error();
    }
    LPBYTE pcMap = (LPBYTE)MapViewOfFile(hFileMap, FILE_MAP_READ|FILE_MAP_WRITE, 0, 0, 0);
    if(pcMap == NULL)
    {
        emit mem_error();
        CloseHandle(hFileMap);
        return;
    }
    *pcMap = 'R';

    process = new QProcess;
    process->start(ai_path, QStringList()<<listen_name);
    process->waitForStarted(-1);

    if (!server->waitForNewConnection(3000))
    {//等待三秒，若未能连接则返回错误并终止程序
        *pcMap = 'E';
        UnmapViewOfFile(pcMap);
        CloseHandle(hFileMap);
        process->terminate();
        emit connect_error();
        return;
    }
    client = server->nextPendingConnection();
    client->waitForConnected(-1);

    //AI信息初始化
    if (!client->waitForReadyRead())
    {
        *pcMap = 'E';
        UnmapViewOfFile(pcMap);
        CloseHandle(hFileMap);
        process->terminate();
        emit init_error();
        return;
    }
    int version_basic;
    client->read((char*)&version_basic, sizeof(int));
    if (version_basic != VERSION_BASIC)
    {
        emit version_error();
        return;
    }
    PlayerInfo pInfo;
    client->read((char*)&pInfo, sizeof(PlayerInfo));
    //time.start();
    int last_round = 0;
    while(!ended)
    {
        //int t = time.elapsed();
        if (setting)
        {
            //*pcMap = 'S';
            msleep(1);
            continue;
        }
        /*if (time.elapsed() >= 100)
            if (gInfo.roundNumber == last_round)
            {
                *pcMap = 'S';
                msleep(1);
                continue;
            }
            else
            {
                last_round = gInfo.roundNumber;
                time.restart();
            }*/

        *pcMap = 'R';
        if (!client->waitForReadyRead(1)) continue;
        char f;
        reading = true;
        client->read(&f, sizeof(char));
        if (f == 'r')
        {
            client->write((char*)&gInfo, sizeof(gInfo));
        }
        else if (f == 'w')
        {
            if (command == NULL) command = new PlayerCommand;
            client->waitForReadyRead(-1);
            client->read((char*)command, sizeof(PlayerCommand));
        }
        reading = false;
    }
    *pcMap = 'E';
    process->terminate();
    int i=0;
    while (!process->atEnd() && i<100) {msleep(1); i++;}
    process->kill();
    UnmapViewOfFile(pcMap);
    CloseHandle(hFileMap);
}
