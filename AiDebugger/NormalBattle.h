#ifndef NORMALBATTLE_H
#define NORMALBATTLE_H
#include <QString>
#include <QThread>
#include <QTimer>
#include "Logic.h"
#include "replayfile.h"
#include <windows.h>

class QLocalServer;
class QLocalSocket;
class QProcess;

namespace DS14
{

class AiReadWriteThread : public QThread
{
    Q_OBJECT
private:
    //QProcess *process;
    //QLocalSocket *client;
    //QLocalServer *server;
    PlayerCommand *aiCommand;
    QString listen_name, ai;
    int init_state;
    PlayerInfo playerInfo;
    bool ter;
    bool stoped;         //暂停读写保证平台安全提交选手指令
    bool reading;        //是否正与Ai交互
    bool crashed;       //Ai是否崩溃
    GameInfo gInfo;


public:
    AiReadWriteThread(QString listenName, QString aiPath) :
         listen_name(listenName), ai(aiPath), init_state(0), ter(false),
         aiCommand(NULL), stoped(true), crashed(false) {}
    ~AiReadWriteThread();
    void Ter() {ter = true;}
    PlayerCommand *getCommand() {return aiCommand;}

    bool readPlayerInfo(PlayerInfo &pInfo);
    void reset(const GameInfo &ngInfo);
    void waitForReadingCompeleted();
    bool hasCrashed();
protected:
    void run();
signals:
    void connectError();

};



class NormalBattle : public QThread
{
    Q_OBJECT
private:
    QLocalServer *server[2];
    QLocalSocket *client[2];
    QProcess *process[2];
    logic *_logic;
    ReplayFile *rFile;
    AiReadWriteThread *aiThread[2];

    QString ai[2];//ai地址
    QString map_location;//地图地址
    bool is_stoped;
    int human; //人机对战时值代表人的一方，若是双Ai对战，值为-1
    int debug; //调试模式时代表需调试Ai一方，否则为-1
    bool debug_mode;
    int sleep_time; //调试时回合间间隔时间，用于减慢回放
   // int timerID;
    int roundTime;
    bool debugAiStarted;
    PlayerCommand pcmd1, pcmd2;
    LPBYTE pcMap; //共享内存映射


    void StartTwoAiBattle();
    void StartHumanAiBattle();
    void StartDebugBattle();
    void InitAiInfo();
    int WhetherWin(const Status &state); //判断是否有一方赢，若ai1赢，返回1，ai2赢，返回2，若游戏继续，返回0，若游戏已结束但是为平局,返回3
    bool UpDateCommand(PlayerCommand *c1, PlayerCommand *c2, bool toRFile);
    bool RoundTimer(); //回合节点，返回游戏是否结束

protected:
    void run();
 //   void timerEvent(QTimerEvent *e);
  //public接口：

public:

    NormalBattle();
    QString GetReplayPath();
    void StartNormalBattle(QString side1, QString side2, QString map);//开始对战，side1,side2为Ai路径，map为地图路径
    ~NormalBattle();

public slots:

    void ready_connect();
    void end();                    //提供终止线程的接口
    void change_to_debug_mode();    //debugger中转换至调试模式（对exe方的数据请求不予满足，等到调试方请求数据时一起发放），
                                    //且回合停止计数（除非某一方有指令待执行）
                                    //这是为了满足选手暂停下来进行单步调试的需求
    void change_to_run_mode();      //切换回运行模式
    void stopBattle();                    //调试模式下暂停对战
    void continueBattle();
    void setSleepTime(int t);



private slots:
    void send_connect_error1()  {emit connect_error(1);}
    void send_connect_error2()  {emit connect_error(2);}
    void send_init_error1() {emit init_error(1);}
    void send_init_error2() {emit init_error(2);}

signals:
    void path_error(int );      //当文件地址错误时被发送，0代表地图地址错误，1、2分别代表ai地址错误
    void connect_error(int ); //当ai管道连接出错时被发送，1,2分别代表两个ai
    void init_error(int );   //当读取ai初始信息出错时被发送，1,2分别代表两个ai
    void send_winner(int);   //判断胜利方, winner = 1 代表1号选手获胜，winner =2 代表2号选手获胜, winner = 3代表战斗平局
    void round(int);        //返回当前运行到第几回合
    void ready_for_connect(QString name); //人机对战时返回服务名以便与平台连接
    void mem_error();
    void debugsignal(int);
};



}
#endif //NORMALBATTLE_H

