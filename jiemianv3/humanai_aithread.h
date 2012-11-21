#ifndef AITHREAD_FOR_HUMANAIBATTLE_H
#define AITHREAD_FOR_HUMANAIBATTLE_H

#include <QThread>
#include <QTime>
#include "platform/Basic.h"
#include "platform/logic.h"

class QLocalServer;
class QLocalSocket;
class QProcess;

using namespace DS14;
class AiThread : public QThread
{
    Q_OBJECT
public:
    AiThread();
    void SetAIPath(const QString & path);
    void StartGame(const GameInfo &gameInfo);
    PlayerCommand * AskCommand();
    void SetGameInfo(const GameInfo &gameInfo);
    void EndGame();
    ~AiThread();
protected:
    void run();
private:
    QString ai_path;
    QLocalServer *server;
    QLocalSocket *client;
    QProcess *process;
    PlayerCommand *command;
    GameInfo gInfo;
    QTime time;
    bool reading, setting;
    bool ended;
signals:
    void path_error();      //当文件地址错误时被发送，0代表地图地址错误，1、2分别代表ai地址错误
    void connect_error();   //当ai管道连接出错时被发送，1,2分别代表两个ai
    void init_error();      //当读取ai初始信息出错时被发送，1,2分别代表两个ai
    void mem_error();
    void version_error();
    void init_ready(QString);
};

#endif // AITHREAD_FOR_HUMANAIBATTLE_H
