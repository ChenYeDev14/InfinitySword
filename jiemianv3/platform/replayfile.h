#ifndef REPLAYFILE_H
#define REPLAYFILE_H
#include "Basic.h"
#include "Logic.h"
#include "Status.h"
#include <QFile>

namespace DS14
{
class ReplayFile
{
public:
    ReplayFile();
    //写入
    bool NewFile(QString playerName1, QString playerName2, QString mapName);//根据信息新建回放文件
    void WriteInitialInfo(int basic_version, int logic_version, const PlayerInfo &playerInfo1, const PlayerInfo &playerInfo2);
            //写入初始信息（玩家，地图）
    //void WriteRoundInfo(const Status &roundStatus); //写入回合信息
    void WriteStatus0(const Status &s);
    void WriteCommand(int round, const PlayerCommand* cmd1, const PlayerCommand* cmd2);
    void WriteWinner(int round, int winSide);
    //读出
    bool OpenFile(QString path); //打开回放文件，返回是否成功
    //以下函数默认文件打开成功
    bool ReadInitialInfo(PlayerInfo &playerInfo1, PlayerInfo &playerInfo2); //读出初始信息
    bool ReadAllRoundInfo(int &roundNum, Status *statusList[]); //读出所有回合信息,statusList[]为指针数组，采用动态分配内存
    void ReadWinner(int &winSide);
    void WriteErrorEnd();
private:
    QFile file;
    bool newfile;
};
}

#endif // REPLAYFILE_H
