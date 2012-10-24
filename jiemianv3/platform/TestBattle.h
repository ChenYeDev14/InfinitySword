#ifndef AITHREAD_FOR_HUMANAIBATTLE_H
#define AITHREAD_FOR_HUMANAIBATTLE_H

#include <QThread>
#include <QTime>


#include "Basic.h"
#include "test.h"


class QLocalServer;
class QLocalSocket;
class QProcess;

using namespace DS14;

class TestBattle : public QThread
{
    Q_OBJECT
public:
    TestBattle();
    void StartBattle(QString aiPath, int level);
    void EndGame();
    void setUser(QString user_name) {user = user_name;}
    ~TestBattle();
protected:
    void run();
private:
    QLocalServer *server;
    QLocalSocket *client;
    QProcess *process;
    PlayerCommand *command;
    QTime time;
    bool reading, setting;
    bool ended;

    int round_time;
    QString ai_path;
    int test_level; //�������ؿ�
    test *test_logic;
    QString user;


signals:
    void path_error();      //���ļ���ַ����ʱ�����ͣ�0�����ͼ��ַ����1����AI��ַ����
    void connect_error();   //��ai�ܵ����ӳ���ʱ�����ͣ�1,2�ֱ��������ai
    void init_error();      //����ȡai��ʼ��Ϣ����ʱ�����ͣ�1,2�ֱ��������ai
    void mem_error();
    void version_error();
    void game_end(int);     //���ط���
    void check_fail();      //�û�������
    void round_up(int);

};

#endif // AITHREAD_FOR_HUMANAIBATTLE_H
