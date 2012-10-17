#include"Basic.h"
#include"Logic.h"
#include"Status.h"
#include<iostream>
using namespace std;

DS14::GameInfo DS14::logic::toPlayer(int side)//将side=1看作AI1，将side=2看作AI2,数值为-1代表不可见
{
	DS14::Status status1;
	DS14::GameInfo gameinfo;
	status1=gameState;
	//设置对敌方飞弹CD不可见
    if(side == 1)
	{
		status1.AI2HeroInfo[0].missleCD=-1;
        status1.AI2HeroInfo[1].missleCD=-1;
	    status1.AI2HeroInfo[2].missleCD=-1;
	}
    if(side == 2)
	{
		status1.AI1HeroInfo[0].missleCD=-1;
	    status1.AI1HeroInfo[1].missleCD=-1;
	    status1.AI1HeroInfo[2].missleCD=-1;
	}
	status1.missleArea[0].centerPosition.x=status1.missleArea[0].centerPosition.y=9999;//x=y=999表示不可见
	status1.missleArea[0].power=status1.missleArea[0].radius=-1;//设置飞弹威力与半径不可见
    status1.missleArea[1].centerPosition.x=status1.missleArea[1].centerPosition.y=9999;//x=y=999表示不可见
	status1.missleArea[1].power=status1.missleArea[1].radius=-1;//设置飞弹威力与半径不可见
    status1.missleArea[2].centerPosition.x=status1.missleArea[2].centerPosition.y=9999;//x=y=999表示不可见
	status1.missleArea[2].power=status1.missleArea[2].radius=-1;//设置飞弹威力与半径不可见
    status1.missleArea[3].centerPosition.x=status1.missleArea[3].centerPosition.y=9999;//x=y=999表示不可见
	status1.missleArea[3].power=status1.missleArea[3].radius=-1;//设置飞弹威力与半径不可见
    status1.missleArea[4].centerPosition.x=status1.missleArea[4].centerPosition.y=9999;//x=y=999表示不可见
	status1.missleArea[4].power=status1.missleArea[4].radius=-1;//设置飞弹威力与半径不可见
    status1.missleArea[5].centerPosition.x=status1.missleArea[5].centerPosition.y=9999;//x=y=999表示不可见
	status1.missleArea[5].power=status1.missleArea[5].radius=-1;//设置飞弹威力与半径不可见
	//将stataus中的有用信息赋值给roundnumber
	gameinfo.roundNumber=status1.roundNumber;//回合数复制
    if (side == 1)
    {
        gameinfo.selfHeroInfo[0]=status1.AI1HeroInfo[0];//己方英雄对应side=1
        gameinfo.selfHeroInfo[1]=status1.AI1HeroInfo[1];
        gameinfo.selfHeroInfo[2]=status1.AI1HeroInfo[2];
        gameinfo.enemyHeroInfo[0]=status1.AI2HeroInfo[0];//敌方英雄对应side=2
        gameinfo.enemyHeroInfo[1]=status1.AI2HeroInfo[1];
        gameinfo.enemyHeroInfo[2]=status1.AI2HeroInfo[2];

    }
    else
    {
        gameinfo.selfHeroInfo[0]=status1.AI2HeroInfo[0];//己方英雄对应side=2
        gameinfo.selfHeroInfo[1]=status1.AI2HeroInfo[1];
        gameinfo.selfHeroInfo[2]=status1.AI2HeroInfo[2];
        gameinfo.enemyHeroInfo[0]=status1.AI1HeroInfo[0];//敌方英雄对应side=1
        gameinfo.enemyHeroInfo[1]=status1.AI1HeroInfo[1];
        gameinfo.enemyHeroInfo[2]=status1.AI1HeroInfo[2];

    }

    //地图信息复制
    int side_1 = side - 1;
    gameinfo.mapInfo.selfBase=status1.mapInfo.AIBases[side_1];
    gameinfo.mapInfo.enemyBase=status1.mapInfo.AIBases[!side_1];
    gameinfo.mapInfo.selfHeroBirthPlace[0]=status1.mapInfo.AIHeroBirthPlace[side_1][0];
    gameinfo.mapInfo.selfHeroBirthPlace[1]=status1.mapInfo.AIHeroBirthPlace[side_1][1];
    gameinfo.mapInfo.selfHeroBirthPlace[2]=status1.mapInfo.AIHeroBirthPlace[side_1][2];
    gameinfo.mapInfo.enemyHeroBirthPlace[0]=status1.mapInfo.AIHeroBirthPlace[!side_1][0];
    gameinfo.mapInfo.enemyHeroBirthPlace[1]=status1.mapInfo.AIHeroBirthPlace[!side_1][1];
    gameinfo.mapInfo.enemyHeroBirthPlace[2]=status1.mapInfo.AIHeroBirthPlace[!side_1][2];
	gameinfo.mapInfo.roadBlockNumber=status1.mapInfo.roadBlockNumber;
    gameinfo.mapInfo.slowDownAreaNumber=status1.mapInfo.slowDownAreaNumber;
	for(int i=0;i<MAX_ROADBLOCK_NUMBER;i++)
	{
		gameinfo.mapInfo.roadBlock[i]=status1.mapInfo.roadBlock[i];
	}
	for(int i=0;i<MAX_SLOWDOWN_AREA_NUMBER;i++)
	{
		gameinfo.mapInfo.slowDownArea[i]=status1.mapInfo.slowDownArea[i];
	}
	//香锅信息复制
    if (side == 1)
    {
        gameinfo.potInfo.selfPotNumber=status1.potInfo.AI1PotNumber;
        gameinfo.potInfo.enemyPotNumber=status1.potInfo.AI2PotNumber;
    }
    else
    {
        gameinfo.potInfo.selfPotNumber=status1.potInfo.AI2PotNumber;
        gameinfo.potInfo.enemyPotNumber=status1.potInfo.AI1PotNumber;
    }
    gameinfo.potInfo.QingFenCD=status1.potInfo.QingFenCD;
	for(int i=0;i<MAX_GOUNDPOT_NUMBER;i++)
	{
		gameinfo.potInfo.groundPots[i]=status1.potInfo.groundPots[i];
	}
	//金钱信息复制
    if(side == 1) gameinfo.gold=status1.AI1gold;
    if(side == 2) gameinfo.gold=status1.AI2gold;
	//飞弹信息复制
	for(int i=0;i<6;i++)
	{
		gameinfo.missileArea[i]=status1.missleArea[i];
		gameinfo.Missle[i].x=gameinfo.Missle[i].y=9999;//设置坐标不可见
	}
	return gameinfo;
}
