#include "replayfile.h"
#include <QDate>
#include <QTime>

using namespace DS14;
using namespace std;


ReplayFile::ReplayFile() { }

bool ReplayFile::NewFile(QString playerName1, QString playerName2, QString mapName)
{
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();
    QString fileName = "RepFiles/" + playerName1 + "_vs_" + playerName2 + "_inMap_" + mapName + "_atTime_";
    fileName.append(date.toString("yyyy-MM-dd_")).append(time.toString("hh-mm-ss")).append(".rep");
    file.setFileName(fileName);
    return file.open(QIODevice::WriteOnly);
}

void ReplayFile::WriteInitialInfo(int basic_version, int logic_version, const DS14::PlayerInfo &playerInfo1, const DS14::PlayerInfo &playerInfo2)
{

    file.write((char*)(&basic_version), sizeof(int));
    file.write((char*)(&logic_version), sizeof(int));
    file.write((char*)(&playerInfo1), sizeof(PlayerInfo));
    file.write((char*)(&playerInfo2), sizeof(PlayerInfo));

}


void ReplayFile::WriteStatus0(const Status &s)
{
    file.write((char*)&s, sizeof(Status));
}

void ReplayFile::WriteCommand(int round, const PlayerCommand *cmd1, const PlayerCommand *cmd2)
{
    file.write((char*)&round, sizeof(int));
    file.putChar('c');
    if (cmd1 == NULL) file.putChar('n');
    else
    {
        file.putChar('y');
        file.write((char*)cmd1, sizeof(PlayerCommand));
    }
    if (cmd2 == NULL) file.putChar('n');
    else
    {
        file.putChar('y');
        file.write((char*)cmd2, sizeof(PlayerCommand));
    }
}

void ReplayFile::WriteWinner(int round, int winSide)
{
    file.write((char*)&round, sizeof(int));
    file.putChar('e');
    file.write((char*)(&winSide), sizeof(int));
    file.close();
}

bool ReplayFile::OpenFile(QString path)
{
    file.setFileName(path);
    return file.open(QIODevice::ReadOnly);
}

bool ReplayFile::ReadInitialInfo(DS14::PlayerInfo &playerInfo1, DS14::PlayerInfo &playerInfo2)
{

    int basic_version, logic_version;
    file.read((char*)&basic_version, sizeof(int));
    file.read((char*)&logic_version, sizeof(int));
    if (basic_version != VERSION_BASIC || logic_version != VERSION_LOGIC)
    {
        file.close();
        return false;
    }
    file.read((char*)(&playerInfo1), sizeof(PlayerInfo));
    file.read((char*)(&playerInfo2), sizeof(PlayerInfo));
    return true;

}

void ReplayFile::ReadAllRoundInfo(int &roundNum, DS14::Status *statusList[])
{

    Status s0;
    file.read((char*)&s0, sizeof(Status));
    logic _logic;
    _logic.init(s0);
    char f;
    int cur = 0, next;

    PlayerCommand *cmd1, *cmd2;
    PlayerCommand pcmd1, pcmd2;
    for (int i=0; i<3; i++)
    {
        pcmd1.heroOrder[i] = walk;
        pcmd1.target[i] = s0.AI1HeroInfo[i].heroPosition;
        pcmd2.heroOrder[i] = walk;
        pcmd2.target[i] = s0.AI2HeroInfo[i].heroPosition;
        for (int j=0; j<MAX_UPDATE_NUMBER_PER_ROUND; j++)
        {
            pcmd1.updateScience[i][j] = none;
            pcmd2.updateScience[i][j] = none;
        }
    }
    cmd1 = NULL;
    cmd2 = NULL;
    while(!file.atEnd())
    {
        file.read((char*)&next, sizeof(int));
        file.getChar(&f);
        if (f == 'c')
        {
            file.getChar(&f);
            if (f != 'n')
            {
                cmd1 = new PlayerCommand;
                file.read((char*)cmd1, sizeof(PlayerCommand));
            }
            file.getChar(&f);
            if (f != 'n')
            {
                cmd2 = new PlayerCommand;
                file.read((char*)cmd2, sizeof(PlayerCommand));
            }
        }
        for (; cur < next; cur++)
        {            
            _logic.update(&pcmd1, &pcmd2);
            statusList[cur] = new Status;
            *statusList[cur] = _logic.getStatus();
        }
        if (f == 'e')
        {
            roundNum = cur;
            break;
        }
        if (cmd1 != NULL) pcmd1 = *cmd1;
        if (cmd2 != NULL) pcmd2 = *cmd2;
        _logic.update(&pcmd1, &pcmd2);
        Status state = _logic.getStatus();
        for(int i=0; i<3; i++)
        {
            if (pcmd1.heroOrder[i] != walk) {pcmd1.heroOrder[i] = walk; pcmd1.target[i] = state.AI1HeroInfo[i].heroPosition;}
            if (pcmd2.heroOrder[i] != walk) {pcmd2.heroOrder[i] = walk; pcmd2.target[i] = state.AI2HeroInfo[i].heroPosition;}
            for (int j=0; j<MAX_UPDATE_NUMBER_PER_ROUND; j++)
            {
                pcmd1.updateScience[i][j] = none;
                pcmd2.updateScience[i][j] = none;
            }
        }
        statusList[cur] = new Status;
        *statusList[cur] = _logic.getStatus();
        cur++;
        if (cmd1 != NULL) {delete cmd1; cmd1 = NULL;}
        if (cmd2 != NULL) {delete cmd2; cmd2 = NULL;}
    }
}

void ReplayFile::ReadWinner(int &winSide)
{
	file.read((char*)(&winSide),sizeof(int));
    file.close();
}
		
