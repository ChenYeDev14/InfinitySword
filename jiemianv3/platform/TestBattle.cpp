#include "TestBattle.h"
#include <QTime>
#include <QLocalServer>
#include <QLocalSocket>
#include <QProcess>
#include <QFile>
#include <QFileInfo>
#include <wchar.h>
#include <string>
#include <windows.h>

#include <QDebug>


using namespace DS14;
TestBattle::TestBattle()
{
    process = NULL;
    command = NULL;
    test_logic = NULL;
    round_time = 100;
}

TestBattle::~TestBattle()
{
    EndGame();
    if (process != NULL) process->kill();
    if (command != NULL) delete command;
    if (test_logic != NULL) delete test_logic;
}


void TestBattle::StartBattle(QString aiPath, int level)
{
    /*if (!db.open())
    {
        emit database_fail();
        return;
    }*/
    QFile file;
    file.setFileName(aiPath);
    if (!file.exists())
    {
        emit path_error();
        return;
    }

    ai_path = aiPath;
    test_level = level;

    ended = false;
    reading = false;
    setting = false;
    command = NULL;

    terminate();
    start();
}



void TestBattle::EndGame()
{
    ended = true;
    if (!wait())
        process->kill();
}

/**/


void TestBattle::run()
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
        process->kill();
        emit init_error();
        return;
    }
    int version_basic;
    client->read((char*)&version_basic, sizeof(int));
    if (version_basic != VERSION_BASIC)
    {
        emit version_error();
        *pcMap = 'E';
        UnmapViewOfFile(pcMap);
        CloseHandle(hFileMap);
        process->kill();
        return;
    }
    if (!client->waitForReadyRead())
    {
        *pcMap = 'E';
        UnmapViewOfFile(pcMap);
        CloseHandle(hFileMap);
        process->kill();
        emit init_error();
        return;
    }
    PlayerInfo pInfo;
    client->read((char*)&pInfo, sizeof(PlayerInfo));
    //验证用户名
    QString ai_user = QString::fromWCharArray(pInfo.userName);
    if (user.toUpper() != ai_user.toUpper())
    {
        emit check_fail();
        *pcMap = 'E';
        process->kill();
        UnmapViewOfFile(pcMap);
        CloseHandle(hFileMap);
        return;
    }


    //初始化逻辑
    test_logic = new test;
    test_logic->test_init(test_level);
    PlayerCommand cmd;
    for (int i=0; i<3; i++)
    {
        cmd.heroOrder[i] = walk;
        cmd.target[i] = test_logic->getStatus().AI1HeroInfo[i].heroPosition;
        for (int j=0; j<MAX_UPDATE_NUMBER_PER_ROUND; j++) cmd.updateScience[i][j] = none;
    }
    time.start();
    QTime time_read;
    time_read.start();
    //qDebug()<<"1";
    while(!ended)
    {
        if (time.elapsed() >= round_time)
        {
            *pcMap = 'S';
            if (command != NULL) cmd = *command;

            int result = test_logic->test_update(&cmd, test_level);

            emit round_up(test_logic->getStatus().roundNumber);
            if (result != -1)
            {
                //显示和记录score = result
                *pcMap = 'E';
                emit game_end(result);
                break;//退出
            }
            for (int i=0; i<3; i++)
            {
                if (cmd.heroOrder[i] != walk)
                {
                    cmd.heroOrder[i] = walk;
                    cmd.target[i] = test_logic->getStatus().AI1HeroInfo[i].heroPosition;
                }
                for (int j=0; j<MAX_UPDATE_NUMBER_PER_ROUND; j++) cmd.updateScience[i][j] = none;
            }
            *pcMap = 'R';
            time.restart();
        }
        if (!client->waitForReadyRead(1)) continue;
        char f;
        reading = true;
        client->read(&f, sizeof(char));
        if (f == 'r')
        {
            int t = time_read.elapsed();
            if (t < 10) msleep(10-t);
            GameInfo gInfo = test_logic->toPlayer(1);
            client->write((char*)&gInfo, sizeof(gInfo));
            time_read.restart();
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
    process->kill();
    UnmapViewOfFile(pcMap);
    CloseHandle(hFileMap);
}
