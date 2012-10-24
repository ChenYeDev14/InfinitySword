/*
��ͷ�ļ�������Ϸ�еĸ��ֳ���
����ѡ����дAI��ʱ��ʹ����Щ���������ƣ�����Ӧ�������ܵĸ��ġ�
*/
#ifndef BASIC_H
#define BASIC_H


namespace DS14
{
//�汾��
    const int VERSION_BASIC = 106;

//��Ϸ����������·��������������������������
	const int MAX_ROADBLOCK_NUMBER = 50;
	const int MAX_SLOWDOWN_AREA_NUMBER = 50;
//��������ж��ٽ�
    const int MAX_GOUNDSWORD_NUMBER = 5;
//ÿ�غ�ÿ��Ӣ�������Ƽ�������5��
	const int MAX_UPDATE_NUMBER_PER_ROUND = 5;
//��ͼ�뾶��Ӣ�۰뾶����Ϸ�غ�����·�ϰ뾶���������뾶��ÿ�غϵ���ʵ����ʱ��	
const int MAP_RADIUS = 1200;
	const int HERO_RADIUS = 50;
	const int GAME_ROUNDS = 2400;
	const int RADIUS_OF_ROADBLOCK = 50;
	const int RADIUS_OF_SLOWDOWNAREA = 50;
	const double TIME_PER_ROUND = 0.1;
//ע�ǣ����ʱ��ֻ��Ϊ�˼���ÿ�غϵ��ƶ�������ɵ�ÿ�غϷ�600*0.1�ľ��룬Ӣ��ÿ�غ���100*0.1�ľ��롭��
    
//�м�������ˢ��ʱ��
    const int TIME_CentreSwordCD = 60;
//�ж������񽣵ľ��룬��Ӣ�����񽣼��С�����ֵ��ʱ����Ϊ����
    const double SWORD_DIST_EPS=1.0;
//���ذ뾶
	const int BASE_RADIUS = 100;

	//Ӣ�����١���ʼѪ������ʼ�����ָ�����ʼ����������ֵ����ʼ����ʱ�䡢
	const int HERO_ORIGIN_SPEED = 100; //Ӣ�۳�ʼÿ�غ��ƶ�100*0.1 = 10��λ����
	const int HERO_ORIGIN_HP = 100;
	const int HERO_ORIGIN_HP_RECOVERY = 0;
	const int HERO_ORIGIN_STRENTH = 0;
	const int HERO_ORIGIN_AGILITY = 0;
	const int HERO_ORINGIN_REBIRTH_TIME = 10;
	const int HERO_REBIRTH_TIME_INCREASE = 3;//ÿ�ٽ�ǮͶ�뽫�������غϸ���ʱ��
	const int HERO_INVINCIBLE_TIME = 5;//Ӣ�۸���֮����ж���ʱ����޵�

	//�ɵ���ʼ������������Ӣ�������ľ����С��������ʼ�ٶȡ���ʼ�뾶���ɵ��ӳ١��ɵ��˺�����ʱ�䡢�ɵ���ȴʱ��
    const int MISSILE_ORIGIN_POWER = 20;
    const int MISSILE_POWER_REDUCE = 10; //�ɵ��˺���Ӣ����ɵ������������ľ����˥��
    const int MISSILE_ORIGIN_SPEED = 600;
    const int MISSILE_ORIGIN_RADIUS = 150;
    const int MISSILE_DELAY = 5;
	const int MISSILE_LAST = 5;//The time of a missile can affect the map.
    const int MISSILE_CD = 100;

	//������ߵȼ���������ߵȼ�
	const int MAXIUMUM_ATTRIBUTE_LEVEL = 40;
	const int MAXIUMUM_ABILITY_LEVEL = 4;

	//���粽������Ч����̧�֡�ʩ����ҡ������ʱ�䡢��ȴʱ��
	const int SPEEDRATE_WHEN_FASTWALKING_ORIGIN = 20;//Ӣ�������ڼ��粽״̬�ӳ�
	const int SPEEDRATE_WHEN_FASTWALKING_PER_LEVEL = 5;//�������粽�����ø���ļӳɡ����粽����Ϊһ��ʱ��125%
	const int FAST_WALK_FORWARD_SWING = 1;
	const int FAST_WALK_BACK_SWING = 0;
	const int FAST_WALK_LAST_ROUND = 50;
    const int FAST_WALK_CD = 100;

//ս����̤��ѣ�ΰ뾶��ѣ��ʱ�䡢̧�ֺ�ҡ����ȴʱ�䡢�˺�
	const int STUN_RADIUS = 300;
	const int STUN_ROUNDS_ORIGIN = 20;
	const int STUN_ROUNDS_PER_LEVEL = 10;
	const int STUN_FORWARD_SWING = 3;
	const int STUN_BACK_SWING = 2;
	const int STUN_ORIGIN_CD = 400;
	const int STUN_CD_REDUCE_PER_LEVEL = 20;
	const int STUN_ORINGIN_DAMAGE = 20;
    const int STUN_DAMAGE_PER_LEVEL = 10;

//�Ʋ�֮�У��˺���ʩ����ҡ����ȴʱ�䡢�����뾶
	const int ATTACK_ORINGIN = 30;
	const int ATTACK_PER_LEVEL = 15;
	const int ATTACK_FORWARD_SWING = 0;
	const int ATTACK_BACK_SWING = 3;
	const int ATTACK_CD = 0;
    const int ATTACK_RANGE=350;

//������HP�������ָ����ɵ��뾶���ɵ��˺��ļӳ�
	const int HP_PER_STRENTH = 10;
    const double HP_RECOVERY_PER_STRENTH = 0.5;
    const int MISSILE_RANGE_PER_STRENTH = 3;
    const double MISSILE_DAMAGE_PER_STRENTH = 0.5;
//���ݶ��ƶ��ٶȡ��ɵ��ٶȵļӳ�
	const int MOVE_SPEED_PER_AGILITY = 1;
	const int MISSILE_SPEED_PER_AGILITY = 30;

	//��ʼ��Ǯ��ÿ�غϵĹ��ʡ���ɱӢ�۵Ľ���һѪ�Ķ��⽱��
	const int ORIGIN_GOLD = 0;
	const int GOLD_PER_ROUND = 5;
	const int HERO_GOLD = 200;//��ɱӢ�۽���
    const int FIRST_BLOOD_GOLD = 200;//һѪ����
//ÿ�غϻ���ݼ������ص��������ӹ���
    const int GOLD_PER_SWORD = 1;
//ѧϰ���������ܵĽ�Ǯ
	const int LEARN_FASTWALK_GOLD = 600;
	const int LEARN_STUN_GOLD = 600;
	const int LEARN_ATTACK_GOLD = 600;
	const int UPDATE_FASTWALK_GOLD = 1000;
	const int UPDATE_STUN_GOLD = 1000;
	const int UPDATE_ATTACK_GOLD = 1000;
	const int UPDATE_STRENTH_GOLD = 60;
	const int UPDATE_AGILITY_GOLD = 60;

//��������ļ���Ч����Я���񽣵ļ���Ч��
	const int SLOWDOWN_REDUCE = 20; //��������80%����
    const int SWORD_REDUCE = 20;      //��80%����

    //���ڵ�ͼ�ϵ�ʱ��İ뾶
    const int SWORD_RADIUS = 50;

//����ṹ��
	typedef struct coordinate
	{
		double x;
		double y;
	}Coordinate;

	//�ɵ���������ṹ��
	typedef struct missilearea
	{
		bool real;//��real == false��ʱ���ù���
		Coordinate centerPosition;//��������
		int roundLast;//ʣ��ʱ��
		double power;//���ĵ��˺�
		double radius;//���ð뾶
	}MissileArea;

	//Ӣ�۵ĿƼ���
	typedef struct techtree
	{
		int strenth;
		int agility;
		int fastWalkLevel;
		int attackLevel;
		int stunLevel;
	}TechTree;

	//Ӣ����Ϣ�ṹ��
	typedef struct heroinfo
	{
		Coordinate heroPosition;
        bool hasSword;//Ӣ���Ƿ�Я����
		int currentHP;
        int missileCD;//�ɵ�cd���з�cd���ɼ�Ϊ-1
		int fastWalkCD;
		int stunCD;
		int InvincibleLast;//**�غϺ����޵�
		int FastwalkForwardWait;
		int FastwalkBackWait;
		int FastwalkLast;//**�غϺ��ټ��粽
		int StunForwardWait;
		int StunBackWait;
		int StunLast;//**�غϺ���ѣ��
		int AttackForwardWait;
		int AttackBackWait;
		int RebornWait; //**�غϺ󸴻�
		TechTree heroTechTree;//�Ƽ������з��ɼ�
	}HeroInfo;

    //����Ϣ
    typedef struct swordinfo
	{
//����������Ŀ
        int selfSwordNumber;
//�з�����
        int enemySwordNumber;
//���ϵ�����Ŀ����������ͼ����
        int groundSwordNumber;

        int CentreSwordCD;//**�غϺ�������ˢ��
        Coordinate groundSwords[MAX_GOUNDSWORD_NUMBER];//���ϵ�����Ϣ�������������
    }SwordInfo;

	//map info
	typedef struct mapinfo
	{
//��������
		Coordinate selfBase;
		Coordinate enemyBase;
//Ӣ�۳����㣬һ��ֻ�����ӦӢ��ͨ����·�ϡ�
		Coordinate selfHeroBirthPlace[3];
		Coordinate enemyHeroBirthPlace[3];
//·�Ϻͼ���������Ϣ
		int roadBlockNumber;//number of roadblocks
		int slowDownAreaNumber;//number of slow down areas.
		Coordinate roadBlock[MAX_ROADBLOCK_NUMBER];
		Coordinate slowDownArea[MAX_SLOWDOWN_AREA_NUMBER];
	}MapInfo;

	//the gameinfo that will send to AI.
//������Ľṹ�壬����AI��
	typedef struct gameinfo
	{
		int roundNumber;
		HeroInfo selfHeroInfo[3];
		HeroInfo enemyHeroInfo[3];
		MapInfo mapInfo;
        SwordInfo swordInfo;
		int gold;
		MissileArea missileArea[6];//�ɵ�����
        Coordinate Missile[6];//����ɵ�����Ϣ����Ǹûغ��·���ɵ��ķ������ꡣ9999Ϊû�з���ġ�
	}GameInfo;

	//Ӣ��ָ��
	typedef enum heroorder
	{
        launchMissile,
		walk,
		fastWalk,
		attack,
		stun
	}HeroOrder;

	//�����Ƽ���ָ��
	typedef enum updatescience
	{
		updateStrenth,
        updateAgility,
		updateFastWalk,
		updateStun,
		updateAttack,
		none
	}UpdateScience;

	//AI�Ķ���
	typedef struct playercommand
	{
		HeroOrder heroOrder[3];
		Coordinate target[3];//Ŀ�꣬�����ߡ�����ɵ�����ͨ����������
//����Ӣ�۵ĿƼ���
		UpdateScience updateScience[3][MAX_UPDATE_NUMBER_PER_ROUND];
	}PlayerCommand;

	//AI����Ϣ
	typedef struct playerinfo
    {        
//�������ƺ�Ӣ������
		wchar_t teamName[20];        
		wchar_t heroName[3][20]; 
		wchar_t userName[40]; //�������� �û���
		
	}PlayerInfo;

}
#endif
