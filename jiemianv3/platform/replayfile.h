#ifndef REPLAYFILE_H
#define REPLAYFILE_H
#include "Basic.h"
#include "Logic.h"
#include "Status.h"
#include <string>
#include <fstream>

namespace DS14
{
class ReplayFile
{
public:
    ReplayFile();
    //д��
    bool NewFile(std::string playerName1, std::string playerName2, std::string mapName);//������Ϣ�½��ط��ļ�
    void WriteInitialInfo(int basic_version, int logic_version, const PlayerInfo &playerInfo1, const PlayerInfo &playerInfo2);
            //д���ʼ��Ϣ����ң���ͼ��
    //void WriteRoundInfo(const Status &roundStatus); //д��غ���Ϣ
    void WriteStatus0(const Status &s);
    void WriteCommand(int round, const PlayerCommand* cmd1, const PlayerCommand* cmd2);
    void WriteWinner(int round, int winSide);
    //����
	bool OpenFile(std::string path); //�򿪻ط��ļ��������Ƿ�ɹ�
    //���º���Ĭ���ļ��򿪳ɹ�
    bool ReadInitialInfo(PlayerInfo &playerInfo1, PlayerInfo &playerInfo2); //������ʼ��Ϣ
    void ReadAllRoundInfo(int &roundNum, Status *statusList[]); //�������лغ���Ϣ,statusList[]Ϊָ�����飬���ö�̬�����ڴ�
    void ReadWinner(int &winSide);
private:
	std::fstream file;
};
}

#endif // REPLAYFILE_H
