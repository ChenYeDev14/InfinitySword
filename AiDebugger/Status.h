#ifndef STATUS_H
#define STATUS_H

#include "Basic.h"

namespace DS14
{

    typedef struct statuspotinfo
    {
		int AI1PotNumber;
		int AI2PotNumber;
		int QingFenCD;
		int groundNumber;
		Coordinate groundPots[MAX_GOUNDPOT_NUMBER];
	}StatusPotInfo;

	typedef struct statusmissileinfo
	{
		bool isReal;
		Coordinate fromPoint;
		Coordinate targetPoint;
		double speed;
		double radius;
		double power;
        int Last;
	}StatusMissileInfo;

	typedef struct names
	{
		char team1Name[15];
		char team2Name[15];
		char team1HeroName[3][15];
		char team2HeroName[3][15];
	}Names;

	typedef struct statusmapinfo
	{
		Coordinate AIBases[2];
		Coordinate AIHeroBirthPlace[2][3];
		int roadBlockNumber;//number of roadblocks
		int slowDownAreaNumber;//number of slow down areas.
		Coordinate roadBlock[MAX_ROADBLOCK_NUMBER];
		Coordinate slowDownArea[MAX_SLOWDOWN_AREA_NUMBER];
	}StatusMapInfo;

	//The struct that our program use.
	typedef struct status
	{
		int roundNumber;
		HeroInfo AI1HeroInfo[3];
		HeroInfo AI2HeroInfo[3];
		StatusMapInfo mapInfo;
		MissileArea missleArea[6];
		StatusPotInfo potInfo;
		int AI1gold;
		int AI2gold;
		StatusMissileInfo missileInfo[6];
	}Status;



}
#endif
