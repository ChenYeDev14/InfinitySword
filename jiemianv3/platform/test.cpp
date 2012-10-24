#include "test.h"
#include <cmath>
#include <QDebug>
using namespace DS14;

void test::test_init(int i)
{
	Status gstate;
	gstate.AI1gold = 0;
	gstate.AI2gold = 0;
	for(int i = 0;i<=2;i++)
	{
		gstate.AI1HeroInfo[i].AttackBackWait = 0;
		gstate.AI1HeroInfo[i].AttackForwardWait = 0;
		gstate.AI1HeroInfo[i].currentHP = 100;
		gstate.AI1HeroInfo[i].FastwalkBackWait = 0;
		gstate.AI1HeroInfo[i].fastWalkCD = -1;
		gstate.AI1HeroInfo[i].FastwalkForwardWait = 0;
		gstate.AI1HeroInfo[i].FastwalkLast = 0;
		gstate.AI1HeroInfo[i].hasSword = false;
		gstate.AI1HeroInfo[i].heroTechTree.agility = 0;
		gstate.AI1HeroInfo[i].heroTechTree.attackLevel = 0;
		gstate.AI1HeroInfo[i].heroTechTree.fastWalkLevel = 0;
		gstate.AI1HeroInfo[i].heroTechTree.strenth = 0;
		gstate.AI1HeroInfo[i].heroTechTree.stunLevel = 0;
		gstate.AI1HeroInfo[i].InvincibleLast = 0;
		gstate.AI1HeroInfo[i].missileCD = -1;
		gstate.AI1HeroInfo[i].RebornWait = 0;
		gstate.AI1HeroInfo[i].StunBackWait = 0;
		gstate.AI1HeroInfo[i].stunCD = -1;
		gstate.AI1HeroInfo[i].StunForwardWait = 0;
		gstate.AI1HeroInfo[i].StunLast = 0;

		gstate.AI2HeroInfo[i].AttackBackWait = 0;
		gstate.AI2HeroInfo[i].AttackForwardWait = 0;
		gstate.AI2HeroInfo[i].currentHP = 100;
		gstate.AI2HeroInfo[i].FastwalkBackWait = 0;
		gstate.AI2HeroInfo[i].fastWalkCD = -1;
		gstate.AI2HeroInfo[i].FastwalkForwardWait = 0;
		gstate.AI2HeroInfo[i].FastwalkLast = 0;
		gstate.AI2HeroInfo[i].hasSword = false;
		gstate.AI2HeroInfo[i].heroTechTree.agility = 0;
		gstate.AI2HeroInfo[i].heroTechTree.attackLevel = 0;
		gstate.AI2HeroInfo[i].heroTechTree.fastWalkLevel = 0;
		gstate.AI2HeroInfo[i].heroTechTree.strenth = 0;
		gstate.AI2HeroInfo[i].heroTechTree.stunLevel = 0;
		gstate.AI2HeroInfo[i].InvincibleLast = 0;
		gstate.AI2HeroInfo[i].missileCD = -1;
		gstate.AI2HeroInfo[i].RebornWait = 0;
		gstate.AI2HeroInfo[i].StunBackWait = 0;
		gstate.AI2HeroInfo[i].stunCD = -1;
		gstate.AI2HeroInfo[i].StunForwardWait = 0;
		gstate.AI2HeroInfo[i].StunLast = 0;
	}
	for(int i = 0;i<=5;i++)
	{
		gstate.missileInfo[i].isReal = false;
	}
	gstate.swordInfo.AI1SwordNumber = 0;
	gstate.swordInfo.AI2SwordNumber = 0;
	gstate.swordInfo.groundNumber = 0;
	gstate.swordInfo.CentreSwordCD = -1;
	gstate.roundNumber = 0;
	for(int i = 0;i<=5;i++)
	{
		gstate.missileInfo[i].isReal = false;
	}
	for(int i = 0;i<=5;i++)
	{
		gstate.missileArea[i].real = false;
	}

	switch(i)
	{
	case(1):
		{
			gstate.mapInfo.roadBlockNumber = 0;
			gstate.mapInfo.slowDownAreaNumber = 0;
			gstate.mapInfo.AIBases[0].x = -900;
			gstate.mapInfo.AIBases[0].y = -900;
			gstate.mapInfo.AIBases[1].x = 900;
			gstate.mapInfo.AIBases[1].y = 900;
			for(int i = 0;i<3;i++)
			{
				gstate.mapInfo.AIHeroBirthPlace[0][i].x = -500;
				gstate.mapInfo.AIHeroBirthPlace[0][i].y = -500+500*i;
				gstate.mapInfo.AIHeroBirthPlace[1][i].x = 500;
				gstate.mapInfo.AIHeroBirthPlace[1][i].y = 500-500*i;
			}
			break;
		}
	case(2):
		{
			gstate.mapInfo.roadBlockNumber = 0;
			gstate.mapInfo.slowDownAreaNumber = 0;
			gstate.mapInfo.AIBases[0].x = -900;
			gstate.mapInfo.AIBases[0].y = -900;
			gstate.mapInfo.AIBases[1].x = 900;
			gstate.mapInfo.AIBases[1].y = 900;
			for(int i = 0;i<3;i++)
			{
				gstate.mapInfo.AIHeroBirthPlace[0][i].x = -500;
				gstate.mapInfo.AIHeroBirthPlace[0][i].y = -500+500*i;
				gstate.mapInfo.AIHeroBirthPlace[1][i].x = 500;
				gstate.mapInfo.AIHeroBirthPlace[1][i].y = 500-500*i;
			}
			break;
		}
	case(3):
		{
			gstate.mapInfo.roadBlockNumber = 0;
			gstate.mapInfo.slowDownAreaNumber = 0;
			gstate.mapInfo.AIBases[0].x = -900;
			gstate.mapInfo.AIBases[0].y = -900;
			gstate.mapInfo.AIBases[1].x = 900;
			gstate.mapInfo.AIBases[1].y = 900;
			for(int i = 0;i<3;i++)
			{
				gstate.mapInfo.AIHeroBirthPlace[0][i].x = -500;
				gstate.mapInfo.AIHeroBirthPlace[0][i].y = -500+500*i;
				gstate.mapInfo.AIHeroBirthPlace[1][i].x = 500;
				gstate.mapInfo.AIHeroBirthPlace[1][i].y = 500-500*i;
			}
			break;
		}
	case(4):
		{
			gstate.mapInfo.slowDownAreaNumber = 0;
			gstate.mapInfo.AIBases[0].x = -900;
			gstate.mapInfo.AIBases[0].y = -900;
			gstate.mapInfo.AIBases[1].x = 900;
			gstate.mapInfo.AIBases[1].y = 900;
			for(int i = 0;i<3;i++)
			{
				gstate.mapInfo.AIHeroBirthPlace[0][i].x = -500;
				gstate.mapInfo.AIHeroBirthPlace[0][i].y = -500+500*i;
				gstate.mapInfo.AIHeroBirthPlace[1][i].x = 500;
				gstate.mapInfo.AIHeroBirthPlace[1][i].y = 500-500*i;
			}
            gstate.mapInfo.roadBlockNumber = 9;
			for(int k = 0;k<9;k++)
			{
                gstate.mapInfo.roadBlock[k].x = -500+200*sin(double(30*k * 3.1415 / 180));
                gstate.mapInfo.roadBlock[k].y = -500-200*cos(double(30*k * 3.1415 / 180));
			}
			break;
		}
	case(5):
		{
			break;
		}
	case(6):
		{
			break;
		}
	case(7):
		{
			break;
		}
	case(8):
		{
			break;
		}
	case(9):
		{
			break;
		}
	case(10):
		{
			break;
		}
	default:
		{

		}
	}
    for (int i=0; i<3; i++)
    {
        gstate.AI1HeroInfo[i].heroPosition = gstate.mapInfo.AIHeroBirthPlace[0][i];
        gstate.AI2HeroInfo[i].heroPosition = gstate.mapInfo.AIHeroBirthPlace[1][i];
    }
	this->init(gstate);
}

int test::test_update(DS14::PlayerCommand * AIcommand, int test_number)
{
    PlayerCommand cmd2;
	for(int i = 0;i<=2;i++)
	{
        cmd2.heroOrder[i] = walk;
        cmd2.target[i] = getStatus().AI2HeroInfo[i].heroPosition;
		for(int j = 0;j<5;j++)
		{
            cmd2.updateScience[i][j] = DS14::none;
		}
	}
	switch(test_number)
	{
	case(1):
		{
			break;
		}
	case(2):
		{
			break;
		}
	case(3):
		{
			break;
		}
	case(4):
		{
			break;
		}
	case(5):
		{
			break;
		}
	case(6):
		{
			break;
		}
	case(7):
		{
			break;
		}
	case(8):
		{
			break;
		}
	case(9):
		{
			break;
		}
	case(10):
		{
			break;
		}
	default:
			{

			}
	}
    qDebug()<<"5";
    update(AIcommand, &cmd2);
    qDebug()<<"6";
	switch(test_number)
	{
	case(1):
		{
			if(getStatus().AI1HeroInfo[0].hasSword)
			{
                int result = (1000-double(getStatus().roundNumber)*1000/75) * 3;
				return (result>0)?result:0;
			}
            else if (1000-double(getStatus().roundNumber)*1000/75 <= 0) return 0;
            else return -1;
			break;
		}
	case(2):
		{
			if(getStatus().AI2HeroInfo[0].RebornWait >0)
			{
                int result = 1000-double(getStatus().roundNumber)*1000/15;
				return (result>0)?result:0;
			}
            else if (1000-double(getStatus().roundNumber)*1000/15 <= 0) return 0;
            else return -1;
			break;
		}
	case(3):
		{
            if(getStatus().AI1HeroInfo[0].FastwalkLast >0)
			{
                int result = 1000-double(getStatus().roundNumber)*1000/45;
				return (result>0)?result:0;
			}
            else if (1000-double(getStatus().roundNumber)*1000/45 <= 0) return 0;
            else return -1;
			break;
		}
	case(4):
		{
			if(getStatus().AI1HeroInfo[0].hasSword)
			{
                int result = (1000-double(getStatus().roundNumber)*1000/180) * 5;
				return (result>0)?result:0;
			}
            else if (1000-double(getStatus().roundNumber)*1000/180 <= 0) return 0;
            else return -1;
			break;
		}
	case(5):
		{
			break;
		}
	case(6):
		{
			break;
		}
	case(7):
		{
			break;
		}
	case(8):
		{
			break;
		}
	case(9):
		{
			break;
		}
	case(10):
		{
			break;
		}
	default:
		{

		}
	}
	return -1;
}
