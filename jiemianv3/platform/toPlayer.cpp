#include"Basic.h"
#include"Logic.h"
#include"Status.h"
#include<iostream>
using namespace std;

DS14::GameInfo DS14::logic::toPlayer(int side)//��side=1����AI1����side=2����AI2,��ֵΪ-1�����ɼ�
{
	DS14::Status status1;
	DS14::GameInfo gameinfo;
	status1=gameState;
	//���öԵз��ɵ�CD���ɼ�
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
	status1.missleArea[0].centerPosition.x=status1.missleArea[0].centerPosition.y=9999;//x=y=999��ʾ���ɼ�
	status1.missleArea[0].power=status1.missleArea[0].radius=-1;//���÷ɵ�������뾶���ɼ�
    status1.missleArea[1].centerPosition.x=status1.missleArea[1].centerPosition.y=9999;//x=y=999��ʾ���ɼ�
	status1.missleArea[1].power=status1.missleArea[1].radius=-1;//���÷ɵ�������뾶���ɼ�
    status1.missleArea[2].centerPosition.x=status1.missleArea[2].centerPosition.y=9999;//x=y=999��ʾ���ɼ�
	status1.missleArea[2].power=status1.missleArea[2].radius=-1;//���÷ɵ�������뾶���ɼ�
    status1.missleArea[3].centerPosition.x=status1.missleArea[3].centerPosition.y=9999;//x=y=999��ʾ���ɼ�
	status1.missleArea[3].power=status1.missleArea[3].radius=-1;//���÷ɵ�������뾶���ɼ�
    status1.missleArea[4].centerPosition.x=status1.missleArea[4].centerPosition.y=9999;//x=y=999��ʾ���ɼ�
	status1.missleArea[4].power=status1.missleArea[4].radius=-1;//���÷ɵ�������뾶���ɼ�
    status1.missleArea[5].centerPosition.x=status1.missleArea[5].centerPosition.y=9999;//x=y=999��ʾ���ɼ�
	status1.missleArea[5].power=status1.missleArea[5].radius=-1;//���÷ɵ�������뾶���ɼ�
	//��stataus�е�������Ϣ��ֵ��roundnumber
	gameinfo.roundNumber=status1.roundNumber;//�غ�������
    if (side == 1)
    {
        gameinfo.selfHeroInfo[0]=status1.AI1HeroInfo[0];//����Ӣ�۶�Ӧside=1
        gameinfo.selfHeroInfo[1]=status1.AI1HeroInfo[1];
        gameinfo.selfHeroInfo[2]=status1.AI1HeroInfo[2];
        gameinfo.enemyHeroInfo[0]=status1.AI2HeroInfo[0];//�з�Ӣ�۶�Ӧside=2
        gameinfo.enemyHeroInfo[1]=status1.AI2HeroInfo[1];
        gameinfo.enemyHeroInfo[2]=status1.AI2HeroInfo[2];

    }
    else
    {
        gameinfo.selfHeroInfo[0]=status1.AI2HeroInfo[0];//����Ӣ�۶�Ӧside=2
        gameinfo.selfHeroInfo[1]=status1.AI2HeroInfo[1];
        gameinfo.selfHeroInfo[2]=status1.AI2HeroInfo[2];
        gameinfo.enemyHeroInfo[0]=status1.AI1HeroInfo[0];//�з�Ӣ�۶�Ӧside=1
        gameinfo.enemyHeroInfo[1]=status1.AI1HeroInfo[1];
        gameinfo.enemyHeroInfo[2]=status1.AI1HeroInfo[2];

    }

    //��ͼ��Ϣ����
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
	//�����Ϣ����
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
	//��Ǯ��Ϣ����
    if(side == 1) gameinfo.gold=status1.AI1gold;
    if(side == 2) gameinfo.gold=status1.AI2gold;
	//�ɵ���Ϣ����
	for(int i=0;i<6;i++)
	{
		gameinfo.missileArea[i]=status1.missleArea[i];
		gameinfo.Missle[i].x=gameinfo.Missle[i].y=9999;//�������겻�ɼ�
	}
	return gameinfo;
}
