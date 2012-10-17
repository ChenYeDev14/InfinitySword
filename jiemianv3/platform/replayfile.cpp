#include "replayfile.h"
#include <ctime>

using namespace DS14;
using namespace std;


ReplayFile::ReplayFile() { }

bool ReplayFile::NewFile(std::string playerName1, std::string playerName2, std::string mapName)
{
	time_t nowtime=time(0);
	char tmp[64];
    strftime(tmp,sizeof(tmp),"%Y-%m-%d_%a_%H-%M-%S",localtime(&nowtime));
	string time(tmp);
    string fullname="RepFiles/"+playerName1+"_vs_"+playerName2+"_inMap_"+mapName+"_atTime_"+time+".rep";
	const char* filename=fullname.c_str();
    file.open(filename, ios::binary | ios::out);
    return file.is_open();
}

void ReplayFile::WriteInitialInfo(int basic_version, int logic_version, const DS14::PlayerInfo &playerInfo1, const DS14::PlayerInfo &playerInfo2)
{
    /*int heronum;
    int side1length,side2length,lengthhero1[3],lengthhero2[3];

    side1length=wcslen(playerInfo1.teamName)+1;
    side2length=wcslen(playerInfo2.teamName)+1;

    for(heronum=0;heronum<3;heronum++)
	{
		lengthhero1[heronum]=wcslen(playerInfo1.heroName[heronum])+1;
		lengthhero2[heronum]=wcslen(playerInfo1.heroName[heronum])+1;
    }

    file.write((char*)(&side1length),  sizeof(int));
    file.write((char*)(playerInfo1.teamName), sizeof(wchar_t) * side1length);
	for(heronum=0;heronum<3;heronum++)
	{
        file.write((char*)(&lengthhero1[heronum]), sizeof(int));
        file.write((char*)playerInfo1.heroName[heronum], sizeof(wchar_t) * lengthhero1[heronum]);
	}

    file.write((char*)(&side2length), sizeof(int));
    file.write((char*)(playerInfo2.teamName),sizeof(wchar_t) * side2length);
	for(heronum=0;heronum<3;heronum++)
	{
        file.write((char*)(&lengthhero2[heronum]), sizeof(int));
        file.write((char*)playerInfo2.heroName[heronum], sizeof(wchar_t) * lengthhero2[heronum]);
    }*/
    file.write((char*)(&basic_version), sizeof(int));
    file.write((char*)(&logic_version), sizeof(int));
    file.write((char*)(&playerInfo1), sizeof(PlayerInfo));
    file.write((char*)(&playerInfo2), sizeof(PlayerInfo));

    //file.write((char*)(&mapInfo), sizeof(mapInfo));
}

/*void ReplayFile::WriteRoundInfo(const DS14::Status &roundStatus)
{
    file.put('r');
    file.write((char*)(&roundStatus), sizeof(roundStatus));
}*/

void ReplayFile::WriteStatus0(const Status &s)
{
    file.write((char*)&s, sizeof(Status));
}

void ReplayFile::WriteCommand(int round, const PlayerCommand *cmd1, const PlayerCommand *cmd2)
{
    file.write((char*)&round, sizeof(int));
    file.put('c');
    if (cmd1 == NULL) file.put('n');
    else
    {
        file.put('y');
        file.write((char*)cmd1, sizeof(PlayerCommand));
    }
    if (cmd2 == NULL) file.put('n');
    else
    {
        file.put('y');
        file.write((char*)cmd2, sizeof(PlayerCommand));
    }
}

void ReplayFile::WriteWinner(int round, int winSide)
{
    file.write((char*)&round, sizeof(int));
    file.put('e');
    file.write((char*)(&winSide), sizeof(int));
    file.close();
}

bool ReplayFile::OpenFile(std::string path)
{
	const char* pathname=path.c_str();
	file.open(pathname,ios::binary|ios::in);
	if(file) return true;
	else return false;
}

bool ReplayFile::ReadInitialInfo(DS14::PlayerInfo &playerInfo1, DS14::PlayerInfo &playerInfo2)
{
    /*int heronum;
	int lengthside1,lengthside2,lengthhero1[3],lengthhero2[3];

	file.read((char*)lengthside1,sizeof(int));
	wchar_t tempchar1[20],temphero1[20];
	file.read((char*)tempchar1,lengthside1*sizeof(wchar_t));
	wcscpy(playerInfo1.teamName,tempchar1);
	for(heronum=0;heronum<3;heronum++)
	{
		file.read((char*)&lengthhero1[heronum],sizeof(int));
		file.read((char*)temphero1,lengthhero1[heronum]*sizeof(wchar_t));
		wcscpy(playerInfo1.heroName[heronum],temphero1);
	}

	file.read((char*)lengthside2,sizeof(int));
	wchar_t tempchar2[20],temphero2[20];
	file.read((char*)tempchar2,lengthside2*sizeof(wchar_t));
	wcscpy(playerInfo2.teamName,tempchar2);
	for(heronum=0;heronum<3;heronum++)
	{
		file.read((char*)&lengthhero2[heronum],sizeof(int));
		file.read((char*)temphero2,lengthhero2[heronum]*sizeof(wchar_t));
		wcscpy(playerInfo2.heroName[heronum],temphero2);
    }*/
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
    //file.read((char*)(&mapInfo),sizeof(mapInfo));
}

void ReplayFile::ReadAllRoundInfo(int &roundNum, DS14::Status *statusList[])
{
/*	int round=0;
//    int fp;
    char f;
    while(!file.eof())
	{
//        fp = file.tellg();
        file.get(f);
        if (f == 'e') break;
        statusList[round]=new Status;
        file.read((char*)statusList[round],sizeof(Status));
		round++;
	}
//    round--;
//    delete statusList[round];
//    statusList[round]=NULL;

//    file.seekg(fp, ios::beg);
//    fp = file.tellg();

	roundNum=round;
    */
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
    while(!file.eof())
    {
        file.read((char*)&next, sizeof(int));
        file.get(f);
        if (f == 'c')
        {
            file.get(f);
            if (f != 'n')
            {
                cmd1 = new PlayerCommand;
                file.read((char*)cmd1, sizeof(PlayerCommand));
            }
            file.get(f);
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
		
