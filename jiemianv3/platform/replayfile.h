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
    //д��
    bool NewFile(QString playerName1, QString playerName2, QString mapName);//������Ϣ�½��ط��ļ�
    void WriteInitialInfo(int basic_version, int logic_version, const PlayerInfo &playerInfo1, const PlayerInfo &playerInfo2);
            //д���ʼ��Ϣ����ң���ͼ��
    //void WriteRoundInfo(const Status &roundStatus); //д��غ���Ϣ
    void WriteStatus0(const Status &s);
    void WriteCommand(int round, const PlayerCommand* cmd1, const PlayerCommand* cmd2);
    void WriteWinner(int round, int winSide);
    //����
    bool OpenFile(QString path); //�򿪻ط��ļ��������Ƿ�ɹ�
    //���º���Ĭ���ļ��򿪳ɹ�
    bool ReadInitialInfo(PlayerInfo &playerInfo1, PlayerInfo &playerInfo2); //������ʼ��Ϣ
    bool ReadAllRoundInfo(int &roundNum, Status *statusList[]); //�������лغ���Ϣ,statusList[]Ϊָ�����飬���ö�̬�����ڴ�
    void ReadWinner(int &winSide);
    void WriteErrorEnd();
private:
    QFile file;
    bool newfile;
};
}

#endif // REPLAYFILE_H
