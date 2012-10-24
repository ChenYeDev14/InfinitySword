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
    int test_level; //测试赛关卡
    test *test_logic;
    QString user;


signals:
    void path_error();      //当文件地址错误时被发送，0代表地图地址错误，1代表AI地址错误
    void connect_error();   //当ai管道连接出错时被发送，1,2分别代表两个ai
    void init_error();      //当读取ai初始信息出错时被发送，1,2分别代表两个ai
    void mem_error();
    void version_error();
    void game_end(int);     //返回分数
    void check_fail();      //用户名错误
    void round_up(int);

};

#endif // AITHREAD_FOR_HUMANAIBATTLE_H
