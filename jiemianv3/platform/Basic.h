/*
本头文件定义游戏中的各种常量
建议选手在写AI的时候使用这些常量的名称，以适应常量可能的更改。
*/
#ifndef BASIC_H
#define BASIC_H


namespace DS14
{
//版本号
    const int VERSION_BASIC = 106;

//游戏基本常量：路障最大数量、减速区域最大数量
	const int MAX_ROADBLOCK_NUMBER = 50;
	const int MAX_SLOWDOWN_AREA_NUMBER = 50;
//地上最多有多少剑
    const int MAX_GOUNDSWORD_NUMBER = 5;
//每回合每个英雄升级科技不超过5次
	const int MAX_UPDATE_NUMBER_PER_ROUND = 5;
//地图半径、英雄半径、游戏回合数、路障半径、减速区半径、每回合的真实世界时间	
const int MAP_RADIUS = 1200;
	const int HERO_RADIUS = 50;
	const int GAME_ROUNDS = 2400;
	const int RADIUS_OF_ROADBLOCK = 50;
	const int RADIUS_OF_SLOWDOWNAREA = 50;
	const double TIME_PER_ROUND = 0.1;
//注记：这个时间只是为了计算每回合的移动。比如飞弹每回合飞600*0.1的距离，英雄每回合走100*0.1的距离……
    
//中间区域神剑刷新时间
    const int TIME_CentreSwordCD = 60;
//判定捡起神剑的距离，当英雄与神剑间距小于这个值的时候视为捡起。
    const double SWORD_DIST_EPS=1.0;
//基地半径
	const int BASE_RADIUS = 100;

	//英雄移速、初始血量、初始生命恢复、初始力量敏捷数值、初始复活时间、
	const int HERO_ORIGIN_SPEED = 100; //英雄初始每回合移动100*0.1 = 10单位距离
	const int HERO_ORIGIN_HP = 100;
	const int HERO_ORIGIN_HP_RECOVERY = 0;
	const int HERO_ORIGIN_STRENTH = 0;
	const int HERO_ORIGIN_AGILITY = 0;
	const int HERO_ORINGIN_REBIRTH_TIME = 10;
	const int HERO_REBIRTH_TIME_INCREASE = 3;//每百金钱投入将增加三回合复活时间
	const int HERO_INVINCIBLE_TIME = 5;//英雄复活之后会有短暂时间的无敌

	//飞弹初始威力、威力随英雄与中心距离减小比例、初始速度、初始半径、飞弹延迟、飞弹伤害持续时间、飞弹冷却时间
    const int MISSILE_ORIGIN_POWER = 20;
    const int MISSILE_POWER_REDUCE = 10; //飞弹伤害随英雄与飞弹作用区域中心距离而衰减
    const int MISSILE_ORIGIN_SPEED = 600;
    const int MISSILE_ORIGIN_RADIUS = 150;
    const int MISSILE_DELAY = 5;
	const int MISSILE_LAST = 5;//The time of a missile can affect the map.
    const int MISSILE_CD = 100;

	//属性最高等级、技能最高等级
	const int MAXIUMUM_ATTRIBUTE_LEVEL = 40;
	const int MAXIUMUM_ABILITY_LEVEL = 4;

	//疾风步：加速效果、抬手、施法后摇、持续时间、冷却时间
	const int SPEEDRATE_WHEN_FASTWALKING_ORIGIN = 20;//英雄移速在疾风步状态加成
	const int SPEEDRATE_WHEN_FASTWALKING_PER_LEVEL = 5;//升级疾风步将会获得更多的加成。疾风步技能为一级时：125%
	const int FAST_WALK_FORWARD_SWING = 1;
	const int FAST_WALK_BACK_SWING = 0;
	const int FAST_WALK_LAST_ROUND = 50;
    const int FAST_WALK_CD = 100;

//战争践踏：眩晕半径、眩晕时间、抬手后摇、冷却时间、伤害
	const int STUN_RADIUS = 300;
	const int STUN_ROUNDS_ORIGIN = 20;
	const int STUN_ROUNDS_PER_LEVEL = 10;
	const int STUN_FORWARD_SWING = 3;
	const int STUN_BACK_SWING = 2;
	const int STUN_ORIGIN_CD = 400;
	const int STUN_CD_REDUCE_PER_LEVEL = 20;
	const int STUN_ORINGIN_DAMAGE = 20;
    const int STUN_DAMAGE_PER_LEVEL = 10;

//制裁之刃：伤害、施法后摇、冷却时间、攻击半径
	const int ATTACK_ORINGIN = 30;
	const int ATTACK_PER_LEVEL = 15;
	const int ATTACK_FORWARD_SWING = 0;
	const int ATTACK_BACK_SWING = 3;
	const int ATTACK_CD = 0;
    const int ATTACK_RANGE=350;

//力量对HP、生命恢复、飞弹半径、飞弹伤害的加成
	const int HP_PER_STRENTH = 10;
    const double HP_RECOVERY_PER_STRENTH = 0.5;
    const int MISSILE_RANGE_PER_STRENTH = 3;
    const double MISSILE_DAMAGE_PER_STRENTH = 0.5;
//敏捷对移动速度、飞弹速度的加成
	const int MOVE_SPEED_PER_AGILITY = 1;
	const int MISSILE_SPEED_PER_AGILITY = 30;

	//初始金钱、每回合的工资、击杀英雄的奖金、一血的额外奖金
	const int ORIGIN_GOLD = 0;
	const int GOLD_PER_ROUND = 5;
	const int HERO_GOLD = 200;//击杀英雄奖金
    const int FIRST_BLOOD_GOLD = 200;//一血奖金
//每回合会根据己方基地的神剑数增加工资
    const int GOLD_PER_SWORD = 1;
//学习、升级技能的金钱
	const int LEARN_FASTWALK_GOLD = 600;
	const int LEARN_STUN_GOLD = 600;
	const int LEARN_ATTACK_GOLD = 600;
	const int UPDATE_FASTWALK_GOLD = 1000;
	const int UPDATE_STUN_GOLD = 1000;
	const int UPDATE_ATTACK_GOLD = 1000;
	const int UPDATE_STRENTH_GOLD = 60;
	const int UPDATE_AGILITY_GOLD = 60;

//减速区域的减速效果和携带神剑的减速效果
	const int SLOWDOWN_REDUCE = 20; //减速区域80%移速
    const int SWORD_REDUCE = 20;      //神剑80%移速

    //神剑在地图上的时候的半径
    const int SWORD_RADIUS = 50;

//坐标结构体
	typedef struct coordinate
	{
		double x;
		double y;
	}Coordinate;

	//飞弹作用区域结构体
	typedef struct missilearea
	{
		bool real;//当real == false的时候不用管它
		Coordinate centerPosition;//作用中心
		int roundLast;//剩余时间
		double power;//中心点伤害
		double radius;//作用半径
	}MissileArea;

	//英雄的科技树
	typedef struct techtree
	{
		int strenth;
		int agility;
		int fastWalkLevel;
		int attackLevel;
		int stunLevel;
	}TechTree;

	//英雄信息结构体
	typedef struct heroinfo
	{
		Coordinate heroPosition;
        bool hasSword;//英雄是否携带神剑
		int currentHP;
        int missileCD;//飞弹cd，敌方cd不可见为-1
		int fastWalkCD;
		int stunCD;
		int InvincibleLast;//**回合后不再无敌
		int FastwalkForwardWait;
		int FastwalkBackWait;
		int FastwalkLast;//**回合后不再疾风步
		int StunForwardWait;
		int StunBackWait;
		int StunLast;//**回合后不再眩晕
		int AttackForwardWait;
		int AttackBackWait;
		int RebornWait; //**回合后复活
		TechTree heroTechTree;//科技树，敌方可见
	}HeroInfo;

    //神剑信息
    typedef struct swordinfo
	{
//己方基地数目
        int selfSwordNumber;
//敌方基地
        int enemySwordNumber;
//地上的神剑数目，不包含地图中央
        int groundSwordNumber;

        int CentreSwordCD;//**回合后中央神剑刷新
        Coordinate groundSwords[MAX_GOUNDSWORD_NUMBER];//地上的神剑信息，用数组来存放
    }SwordInfo;

	//map info
	typedef struct mapinfo
	{
//基地坐标
		Coordinate selfBase;
		Coordinate enemyBase;
//英雄出生点，一个只允许对应英雄通过的路障。
		Coordinate selfHeroBirthPlace[3];
		Coordinate enemyHeroBirthPlace[3];
//路障和减速区域信息
		int roadBlockNumber;//number of roadblocks
		int slowDownAreaNumber;//number of slow down areas.
		Coordinate roadBlock[MAX_ROADBLOCK_NUMBER];
		Coordinate slowDownArea[MAX_SLOWDOWN_AREA_NUMBER];
	}MapInfo;

	//the gameinfo that will send to AI.
//大个儿的结构体，传给AI的
	typedef struct gameinfo
	{
		int roundNumber;
		HeroInfo selfHeroInfo[3];
		HeroInfo enemyHeroInfo[3];
		MapInfo mapInfo;
        SwordInfo swordInfo;
		int gold;
		MissileArea missileArea[6];//飞弹区域
        Coordinate Missile[6];//发射飞弹的信息，标记该回合新发射飞弹的发射坐标。9999为没有发射的。
	}GameInfo;

	//英雄指令
	typedef enum heroorder
	{
        launchMissile,
		walk,
		fastWalk,
		attack,
		stun
	}HeroOrder;

	//升级科技树指令
	typedef enum updatescience
	{
		updateStrenth,
        updateAgility,
		updateFastWalk,
		updateStun,
		updateAttack,
		none
	}UpdateScience;

	//AI的动作
	typedef struct playercommand
	{
		HeroOrder heroOrder[3];
		Coordinate target[3];//目标，对行走、发射飞弹和普通攻击起作用
//三个英雄的科技树
		UpdateScience updateScience[3][MAX_UPDATE_NUMBER_PER_ROUND];
	}PlayerCommand;

	//AI的信息
	typedef struct playerinfo
    {        
//队伍名称和英雄名称
		wchar_t teamName[20];        
		wchar_t heroName[3][20]; 
		wchar_t userName[40]; //测试赛用 用户名
		
	}PlayerInfo;

}
#endif
