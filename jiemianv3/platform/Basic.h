/*
author：DarkTheCross
time：2012/6/30 21:41
This head file states several important constants and defines several important structs.
This head file will send to the competitors.
*/
#ifndef BASIC_H
#define BASIC_H


namespace DS14
{
    const int VERSION_BASIC = 104;

	//Some basic information of the game that used widely.
	const int MAX_ROADBLOCK_NUMBER = 50;
	const int MAX_SLOWDOWN_AREA_NUMBER = 50;
    //The maximum number of swords that are on the ground
    const int MAX_GOUNDSWORD_NUMBER = 5;
	const int MAX_UPDATE_NUMBER_PER_ROUND = 5;
	const int MAP_RADIUS = 1200;
	const int HERO_RADIUS = 50;
	const int GAME_ROUNDS = 2400;
	const int RADIUS_OF_ROADBLOCK = 50;
	const int RADIUS_OF_SLOWDOWNAREA = 50;
	const double TIME_PER_ROUND = 0.1;//each round will take 0.1s. So a hero can walk 600*0.1 = 60 per round.
    
    const int TIME_CentreSwordCD=30;
    const double SWORD_DIST_EPS=1.0;

	const int BASE_RADIUS = 100;

	//Hero data.
	const int HERO_ORIGIN_SPEED = 100; //hero can move 10 per round.
	const int HERO_ORIGIN_HP = 100;
	const int HERO_ORIGIN_HP_RECOVERY = 0;
	const int HERO_ORIGIN_STRENTH = 0;
	const int HERO_ORIGIN_AGILITY = 0;
	const int HERO_ORINGIN_REBIRTH_TIME = 10;
	const int HERO_REBIRTH_TIME_INCREASE = 3;//each hundred of investment on the hero will increase the rebirth time by 3 rounds.
	const int HERO_INVINCIBLE_TIME = 5;//The rounds that the hero will be invincible when reborn or harmed.

	//missile
    const int MISSILE_ORIGIN_POWER = 20;
    const int MISSILE_POWER_REDUCE = 10; //Harm = 20-5%*distance
    const int MISSILE_ORIGIN_SPEED = 600;
    const int MISSILE_ORIGIN_RADIUS = 150;
    const int MISSILE_DELAY = 5;
	const int MISSILE_LAST = 5;//The time of a missile can affect the map.
    const int MISSILE_CD = 100;

	//Something about the technology tree.
	const int MAXIUMUM_ATTRIBUTE_LEVEL = 40;
	const int MAXIUMUM_ABILITY_LEVEL = 4;


	const int SPEEDRATE_WHEN_FASTWALKING_ORIGIN = 20;//hero speed will multiple 1.2 when fastwalking.
	const int SPEEDRATE_WHEN_FASTWALKING_PER_LEVEL = 5;
	const int FAST_WALK_FORWARD_SWING = 1;
	const int FAST_WALK_BACK_SWING = 0;
	const int FAST_WALK_LAST_ROUND = 50;
    const int FAST_WALK_CD = 100;

	const int STUN_RADIUS = 300;
	const int STUN_ROUNDS_ORIGIN = 20;
	const int STUN_ROUNDS_PER_LEVEL = 10;
	const int STUN_FORWARD_SWING = 3;
	const int STUN_BACK_SWING = 2;
	const int STUN_ORIGIN_CD = 400;
	const int STUN_CD_REDUCE_PER_LEVEL = 20;
	const int STUN_ORINGIN_DAMAGE = 20;
    //data changed
    const int STUN_DAMAGE_PER_LEVEL = 10;

	const int ATTACK_ORINGIN = 30;
	const int ATTACK_PER_LEVEL = 15;
	const int ATTACK_FORWARD_SWING = 0;
	const int ATTACK_BACK_SWING = 3;
	const int ATTACK_CD = 0;
    const int ATTACK_RANGE=350;

	const int HP_PER_STRENTH = 10;
    const double HP_RECOVERY_PER_STRENTH = 0.5;
    const int MISSILE_RANGE_PER_STRENTH = 3;
    const double MISSILE_DAMAGE_PER_STRENTH = 0.5;

	const int MOVE_SPEED_PER_AGILITY = 1;
	const int MISSILE_SPEED_PER_AGILITY = 30;

	//Data about the gold.
	const int ORIGIN_GOLD = 0;
	const int GOLD_PER_ROUND = 5;
	const int HERO_GOLD = 200;//The reward when killed an enemy hero.
    const int FIRST_BLOOD_GOLD = 200;//The first kill will win extra gold.
    const int GOLD_PER_SWORD = 1;
	const int LEARN_FASTWALK_GOLD = 600;
	const int LEARN_STUN_GOLD = 600;
	const int LEARN_ATTACK_GOLD = 600;
	const int UPDATE_FASTWALK_GOLD = 1000;
	const int UPDATE_STUN_GOLD = 1000;
	const int UPDATE_ATTACK_GOLD = 1000;
	const int UPDATE_STRENTH_GOLD = 60;
	const int UPDATE_AGILITY_GOLD = 60;

	const int SLOWDOWN_REDUCE = 20; //Slow-down area will reduce the speed
    const int SWORD_REDUCE = 20;      //Having sword will reduce the speed

    //darkthecross修改
    const int SWORD_RADIUS = 50;

	typedef struct coordinate
	{
		double x;
		double y;
	}Coordinate;

	//The area of missiles which are affecting the map
	typedef struct missilearea
	{
		bool real;//Because we have 6 missile areas, and only a few is useful while the others are useless.
		Coordinate centerPosition;//center
		int roundLast;//how long it will last
		double power;//the harm at the center point.
		double radius;//the radius
	}MissileArea;

	//technology tree
	typedef struct techtree
	{
		int strenth;
		int agility;
		int fastWalkLevel;
		int attackLevel;
		int stunLevel;
	}TechTree;

	//Hero info that will send to ai.Used both for self and enemy.
	typedef struct heroinfo
	{
		Coordinate heroPosition;
        bool hasSword;//If the hero has a sword.
		int currentHP;
        int missileCD;//Cold down time of missile. Not available for enemy.
		int fastWalkCD;
		int stunCD;
		int InvincibleLast;//Stop being invincible ** rounds later
		int FastwalkForwardWait;
		int FastwalkBackWait;
		int FastwalkLast;//Stop fastwalking ** rounds later
		int StunForwardWait;
		int StunBackWait;
		int StunLast;//Under stun in ** rounds...
		int AttackForwardWait;
		int AttackBackWait;
		int RebornWait; //Reborn ** rounds later
		TechTree heroTechTree;//visible for enemy
	}HeroInfo;

    //swords on the map
    typedef struct swordinfo
	{
        int selfSwordNumber;
        int enemySwordNumber;
        //modified:10.07
        int groundSwordNumber;

        int CentreSwordCD;//CD of qingfen
        Coordinate groundSwords[MAX_GOUNDSWORD_NUMBER];
    }SwordInfo;

	//map info
	typedef struct mapinfo
	{
		Coordinate selfBase;
		Coordinate enemyBase;
		Coordinate selfHeroBirthPlace[3];
		Coordinate enemyHeroBirthPlace[3];
		int roadBlockNumber;//number of roadblocks
		int slowDownAreaNumber;//number of slow down areas.
		Coordinate roadBlock[MAX_ROADBLOCK_NUMBER];
		Coordinate slowDownArea[MAX_SLOWDOWN_AREA_NUMBER];
	}MapInfo;

	//the gameinfo that will send to AI.
	typedef struct gameinfo
	{
		int roundNumber;
		HeroInfo selfHeroInfo[3];
		HeroInfo enemyHeroInfo[3];
		MapInfo mapInfo;
        SwordInfo swordInfo;
		int gold;
		MissileArea missileArea[6];//The missiles that are affecting the map.
        Coordinate Missile[6];//The missiles that are being sent.
	}GameInfo;

	//commands to hero
	typedef enum heroorder
	{
        launchMissile,
		walk,
		fastWalk,
		attack,
		stun
	}HeroOrder;

	//commands of updating technology
	typedef enum updatescience
	{
		updateStrenth,
        updateAgility,
		updateFastWalk,
		updateStun,
		updateAttack,
		none
	}UpdateScience;

	//commands from AI
	typedef struct playercommand
	{
		HeroOrder heroOrder[3];
		Coordinate target[3];//Target, if heroorder is to walk, attack, or to send missile;Otherwise useless.
		UpdateScience updateScience[3][MAX_UPDATE_NUMBER_PER_ROUND];
	}PlayerCommand;

	//info of ai   平台组添 2012.7.22
	typedef struct playerinfo
    {        
		wchar_t teamName[20];        
		wchar_t heroName[3][20]; 
		wchar_t userName[20]; //测试赛用 用户名，密码
		wchar_t code[20];   
	}PlayerInfo;

}
#endif
