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
    void path_error();      //���ļ���ַ����ʱ�����ͣ�0�����ͼ��ַ����1��2�ֱ����ai��ַ����
    void connect_error();   //��ai�ܵ����ӳ���ʱ�����ͣ�1,2�ֱ��������ai
    void init_error();      //����ȡai��ʼ��Ϣ����ʱ�����ͣ�1,2�ֱ��������ai
    void mem_error();
    void version_error();
    void init_ready(QString);
};

#endif // AITHREAD_FOR_HUMANAIBATTLE_H
