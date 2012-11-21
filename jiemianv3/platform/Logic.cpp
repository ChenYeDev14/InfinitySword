#include "logic.h"
#include <cmath>
#include <algorithm>
#include <QString>
#include <QFile>
#include <QDebug>

using namespace std;
using namespace DS14;

DS14::logic::logic()
{
    FIRSTBLOOD = false;
}

bool DS14::logic::init(QString path)
{
    gameState.AI1gold = 0;
    gameState.AI2gold = 0;
    for(int i = 0;i<=2;i++)
    {
        gameState.AI1HeroInfo[i].AttackBackWait = 0;
        gameState.AI1HeroInfo[i].AttackForwardWait = 0;
        gameState.AI1HeroInfo[i].currentHP = 100;
        gameState.AI1HeroInfo[i].FastwalkBackWait = 0;
        gameState.AI1HeroInfo[i].fastWalkCD = -1;
        gameState.AI1HeroInfo[i].FastwalkForwardWait = 0;
        gameState.AI1HeroInfo[i].FastwalkLast = 0;
        gameState.AI1HeroInfo[i].hasSword = false;
        gameState.AI1HeroInfo[i].heroTechTree.agility = 0;
        gameState.AI1HeroInfo[i].heroTechTree.attackLevel = 0;
        gameState.AI1HeroInfo[i].heroTechTree.fastWalkLevel = 0;
        gameState.AI1HeroInfo[i].heroTechTree.strenth = 0;
        gameState.AI1HeroInfo[i].heroTechTree.stunLevel = 0;
        gameState.AI1HeroInfo[i].InvincibleLast = 0;
        gameState.AI1HeroInfo[i].missileCD = -1;
        gameState.AI1HeroInfo[i].RebornWait = 0;
        gameState.AI1HeroInfo[i].StunBackWait = 0;
        gameState.AI1HeroInfo[i].stunCD = -1;
        gameState.AI1HeroInfo[i].StunForwardWait = 0;
        gameState.AI1HeroInfo[i].StunLast = 0;

        gameState.AI2HeroInfo[i].AttackBackWait = 0;
        gameState.AI2HeroInfo[i].AttackForwardWait = 0;
        gameState.AI2HeroInfo[i].currentHP = 100;
        gameState.AI2HeroInfo[i].FastwalkBackWait = 0;
        gameState.AI2HeroInfo[i].fastWalkCD = -1;
        gameState.AI2HeroInfo[i].FastwalkForwardWait = 0;
        gameState.AI2HeroInfo[i].FastwalkLast = 0;
        gameState.AI2HeroInfo[i].hasSword = false;
        gameState.AI2HeroInfo[i].heroTechTree.agility = 0;
        gameState.AI2HeroInfo[i].heroTechTree.attackLevel = 0;
        gameState.AI2HeroInfo[i].heroTechTree.fastWalkLevel = 0;
        gameState.AI2HeroInfo[i].heroTechTree.strenth = 0;
        gameState.AI2HeroInfo[i].heroTechTree.stunLevel = 0;
        gameState.AI2HeroInfo[i].InvincibleLast = 0;
        gameState.AI2HeroInfo[i].missileCD = -1;
        gameState.AI2HeroInfo[i].RebornWait = 0;
        gameState.AI2HeroInfo[i].StunBackWait = 0;
        gameState.AI2HeroInfo[i].stunCD = -1;
        gameState.AI2HeroInfo[i].StunForwardWait = 0;
        gameState.AI2HeroInfo[i].StunLast = 0;
    }
    for(int i = 0;i<=5;i++)
    {
        gameState.missileInfo[i].isReal = false;
    }
    gameState.swordInfo.AI1SwordNumber = 0;
    gameState.swordInfo.AI2SwordNumber = 0;
    gameState.swordInfo.groundNumber = 0;
    gameState.swordInfo.first_index = 0;
    gameState.swordInfo.CentreSwordCD = -1;
    gameState.roundNumber = 0;
    for(int i = 0;i<=5;i++)
    {
        gameState.missileInfo[i].isReal = false;
    }
    for(int i = 0;i<=5;i++)
    {
        gameState.missileArea[i].real = false;
    }
    QFile infile;
    infile.setFileName(path);
    if (!infile.open(QIODevice::ReadOnly)) return false;
    int version_basic;
    infile.read((char*)&version_basic, sizeof(int));
    if (version_basic != VERSION_BASIC)
    {
        infile.close();
        return false;
    }
    infile.read((char*)(&(gameState.mapInfo)),sizeof(DS14::StatusMapInfo));
    for (int i=0; i<3; i++)
    {
        gameState.AI1HeroInfo[i].heroPosition = gameState.mapInfo.AIHeroBirthPlace[0][i];
        gameState.AI2HeroInfo[i].heroPosition = gameState.mapInfo.AIHeroBirthPlace[1][i];
    }
    infile.close();
    return true;
}

void logic::init()
{
    gameState.AI1gold = 0;
    gameState.AI2gold = 0;
    for(int i = 0;i<=2;i++)
    {
        gameState.AI1HeroInfo[i].AttackBackWait = 0;
        gameState.AI1HeroInfo[i].AttackForwardWait = 0;
        gameState.AI1HeroInfo[i].currentHP = 100;
        gameState.AI1HeroInfo[i].FastwalkBackWait = 0;
        gameState.AI1HeroInfo[i].fastWalkCD = 0;
        gameState.AI1HeroInfo[i].FastwalkForwardWait = 0;
        gameState.AI1HeroInfo[i].FastwalkLast = 0;
        gameState.AI1HeroInfo[i].hasSword = false;
        gameState.AI1HeroInfo[i].heroTechTree.agility = 0;
        gameState.AI1HeroInfo[i].heroTechTree.attackLevel = 0;
        gameState.AI1HeroInfo[i].heroTechTree.fastWalkLevel = 0;
        gameState.AI1HeroInfo[i].heroTechTree.strenth = 0;
        gameState.AI1HeroInfo[i].heroTechTree.stunLevel = 0;
        gameState.AI1HeroInfo[i].InvincibleLast = 0;
        gameState.AI1HeroInfo[i].missileCD = 0;
        gameState.AI1HeroInfo[i].RebornWait = 0;
        gameState.AI1HeroInfo[i].StunBackWait = 0;
        gameState.AI1HeroInfo[i].stunCD = 0;
        gameState.AI1HeroInfo[i].StunForwardWait = 0;
        gameState.AI1HeroInfo[i].StunLast = 0;

        gameState.AI2HeroInfo[i].AttackBackWait = 0;
        gameState.AI2HeroInfo[i].AttackForwardWait = 0;
        gameState.AI2HeroInfo[i].currentHP = 100;
        gameState.AI2HeroInfo[i].FastwalkBackWait = 0;
        gameState.AI2HeroInfo[i].fastWalkCD = 0;
        gameState.AI2HeroInfo[i].FastwalkForwardWait = 0;
        gameState.AI2HeroInfo[i].FastwalkLast = 0;
        gameState.AI2HeroInfo[i].hasSword = false;
        gameState.AI2HeroInfo[i].heroTechTree.agility = 0;
        gameState.AI2HeroInfo[i].heroTechTree.attackLevel = 0;
        gameState.AI2HeroInfo[i].heroTechTree.fastWalkLevel = 0;
        gameState.AI2HeroInfo[i].heroTechTree.strenth = 0;
        gameState.AI2HeroInfo[i].heroTechTree.stunLevel = 0;
        gameState.AI2HeroInfo[i].InvincibleLast = 0;
        gameState.AI2HeroInfo[i].missileCD = 0;
        gameState.AI2HeroInfo[i].RebornWait = 0;
        gameState.AI2HeroInfo[i].StunBackWait = 0;
        gameState.AI2HeroInfo[i].stunCD = 0;
        gameState.AI2HeroInfo[i].StunForwardWait = 0;
        gameState.AI2HeroInfo[i].StunLast = 0;
    }
    for(int i = 0;i<=5;i++)
    {
        gameState.missileInfo[i].isReal = false;
    }
    gameState.swordInfo.AI1SwordNumber = 0;
    gameState.swordInfo.AI2SwordNumber = 0;
    gameState.swordInfo.groundNumber = 1;
    gameState.swordInfo.groundSwords[0].x = 0;
    gameState.swordInfo.groundSwords[0].y = 0;
    gameState.swordInfo.CentreSwordCD = 0;
    gameState.roundNumber = 0;


    gameState.mapInfo.AIHeroBirthPlace[0][0].x = 0;
    gameState.mapInfo.AIHeroBirthPlace[0][0].y = 0;
    gameState.mapInfo.AIHeroBirthPlace[0][1].x = 0;
    gameState.mapInfo.AIHeroBirthPlace[0][1].y = 0;
    gameState.mapInfo.AIHeroBirthPlace[0][2].x = 0;
    gameState.mapInfo.AIHeroBirthPlace[0][2].y = 0;
    gameState.mapInfo.AIHeroBirthPlace[1][0].x = 0;
    gameState.mapInfo.AIHeroBirthPlace[1][0].y = 0;
    gameState.mapInfo.AIHeroBirthPlace[1][1].x = 0;
    gameState.mapInfo.AIHeroBirthPlace[1][1].y = 0;
    gameState.mapInfo.AIHeroBirthPlace[1][2].x = 0;
    gameState.mapInfo.AIHeroBirthPlace[1][2].y = 0;

    for(int i=0;i<3;i++)
    {
        gameState.AI1HeroInfo[i].heroPosition = gameState.mapInfo.AIHeroBirthPlace[0][i];
    }
    for(int i=0;i<3;i++)
    {
        gameState.AI2HeroInfo[i].heroPosition = gameState.mapInfo.AIHeroBirthPlace[1][i];
    }
    gameState.mapInfo.roadBlockNumber = 0;


    for(int i = 0;i<6;i++)
    {
        gameState.missileArea[i].centerPosition.x = 0;
        gameState.missileArea[i].centerPosition.y = 0;
        gameState.missileArea[i].real = false;
    }


    gameState.mapInfo.AIBases[0].x = 0;
    gameState.mapInfo.AIBases[0].y = 0;
    gameState.mapInfo.AIBases[1].x = 0;
    gameState.mapInfo.AIBases[1].y = 0;


}

DS14::GameInfo DS14::logic::toPlayer(int side)//��side=1����AI1����side=2����AI2,��ֵΪ-1�����ɼ�
{
    Status status1;
    GameInfo gameinfo;
    status1=gameState;
    //���öԵз��ɵ�CD���ɼ�
    if(side == 1)
    {
        status1.AI2HeroInfo[0].missileCD=-1;
        status1.AI2HeroInfo[1].missileCD=-1;
        status1.AI2HeroInfo[2].missileCD=-1;
    }
    if(side == 2)
    {
        status1.AI1HeroInfo[0].missileCD=-1;
        status1.AI1HeroInfo[1].missileCD=-1;
        status1.AI1HeroInfo[2].missileCD=-1;
    }

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

    //��Ǯ��Ϣ����
    if(side == 1) gameinfo.gold=status1.AI1gold;
    if(side == 2) gameinfo.gold=status1.AI2gold;
    //�ɵ���Ϣ����
    for(int i=0;i<6;i++)
    {
        gameinfo.missileArea[i]=status1.missileArea[i];
        if(!(status1.missileInfo[i].isReal))
        {
            gameinfo.Missile[i].x=gameinfo.Missile[i].y=9999;
        }
        else
        {
            gameinfo.Missile[i] = status1.missileInfo[i].fromPoint;
        }
    }
    //�����Ϣ
    gameinfo.swordInfo.CentreSwordCD = status1.swordInfo.CentreSwordCD;
    gameinfo.swordInfo.groundSwordNumber = status1.swordInfo.groundNumber;
    for (int i=0; i<gameinfo.swordInfo.groundSwordNumber; i++) gameinfo.swordInfo.groundSwords[i] = status1.swordInfo.groundSwords[i];
    if (side==1)
    {
        gameinfo.swordInfo.enemySwordNumber = status1.swordInfo.AI2SwordNumber;
        gameinfo.swordInfo.selfSwordNumber = status1.swordInfo.AI1SwordNumber;
    }
    else
    {
        gameinfo.swordInfo.enemySwordNumber = status1.swordInfo.AI1SwordNumber;
        gameinfo.swordInfo.selfSwordNumber = status1.swordInfo.AI2SwordNumber;
    }
    return gameinfo;
}
namespace DS14
{
    //���뺯��
    double Distance(Coordinate p1,Coordinate p2)
    {
        return sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
    }

    //����p1��p2ʱ·���Ƿ����Բ��Ϊcenter,�뾶Ϊradius��Բ�ཻ(��֪p1����Բ��)
    //�����ֱཻ�ӷ��ؿɵ���p2,���򷵻���Զ�Ŀɵ���c
    Coordinate check_intersection(Coordinate center,Coordinate p1,Coordinate p2,double radius)
    {
        if(!(p1.x==p2.x&&p1.y==p2.y))
        {
            double a = Distance(p1,p2),b = Distance(p1,center), c = Distance(p2,center);//���߳�
            double area3;
            //darkthecross�޸ģ���������BΪ��ǲ���C��Ϊ���
            //Han�޸ģ�B��Ϊ���
            if(a*a+c*c<=b*b)
            {
                if(c>=radius) return p2;
                else
                {
                    double area2 = fabs(p1.x*p2.y+p1.y*center.x+p2.x*center.y-p1.x*center.y-p1.y*p2.x-p2.y*center.x); //���������������
                    double d = area2/a;   //��a�ϵĸ�d
                    double distance = sqrt(b*b-d*d)-sqrt(radius*radius-d*d);  //������Զ�ĵ㵽p1�ľ���
                    Coordinate target;
                    target.x = (distance/a) * (p2.x-p1.x) + p1.x;
                    target.y = (distance/a) * (p2.y-p1.y) + p1.y;
                    return target; //ȷ����Զ���е�
                }
            }
            else if(a*a+b*b<=c*c)//��C��Ϊ���
            {
                return p2;
            }
            else
            {
                area3 = abs(double(p1.x*p2.y+p1.y*center.x+p2.x*center.y-p1.x*center.y-p1.y*p2.x-p2.y*center.x)); //���������������
                if(area3>=0.01)
                {
                    double d = area3/a;   //��a�ϵĸ�d
                    if(d>=radius)
                    {
                        return p2;
                    }
                    else
                    {
                        double distance = sqrt(b*b-d*d)-sqrt(radius*radius-d*d);  //������Զ�ĵ㵽p1�ľ���
                        Coordinate target;
                        target.x = (distance/a) * (p2.x-p1.x) + p1.x;
                        target.y = (distance/a) * (p2.y-p1.y) + p1.y;
                        return target; //ȷ����Զ���е�
                    }
                }
                else
                {
                    return p2;
                }
            }
        }
        else
        {
            return p2;
        }
    }

    bool isOperable(const HeroInfo &hero)
    {
        return (!hero.hasSword &&
            !hero.FastwalkForwardWait &&
            !hero.FastwalkBackWait &&
            !hero.StunForwardWait &&
            !hero.StunBackWait &&
            !hero.AttackForwardWait &&
            !hero.AttackBackWait &&
            !hero.StunLast &&
            !hero.RebornWait);
    }

    //darkthecross�޸�
    bool isOperablew(const HeroInfo &hero)
    {
        return (!hero.FastwalkForwardWait &&
            !hero.FastwalkBackWait &&
            !hero.StunForwardWait &&
            !hero.StunBackWait &&
            !hero.AttackForwardWait &&
            !hero.AttackBackWait &&
            !hero.StunLast &&
            !hero.RebornWait);
    }

    //Ӣ�۷����ƶ�����
    void HeroMoveBack(Status & gameState,Coordinate position[][3])
    {

            bool a[6] = {false, false, false, false, false, false};

            for(int i=0;i<3;i++)
            {
                if (gameState.AI1HeroInfo[i].RebornWait == 0)
                for(int j=0;j<5;j++)

                {
                    if(j<i)
                    {
                        if (gameState.AI1HeroInfo[j].RebornWait == 0)
                        if(Distance(gameState.AI1HeroInfo[i].heroPosition,gameState.AI1HeroInfo[j].heroPosition)<2*HERO_RADIUS)
                        {
                            a[i] = true;

                        }
                    }
                    else if(j>=i&&j<2)
                    {
                        if (gameState.AI1HeroInfo[j+1].RebornWait == 0)
                        if(Distance(gameState.AI1HeroInfo[i].heroPosition,gameState.AI1HeroInfo[j+1].heroPosition)<2*HERO_RADIUS)
                        {
                            a[i] = true;

                        }
                    }
                    else
                    {
                        if (gameState.AI2HeroInfo[j-2].RebornWait == 0)
                        if(Distance(gameState.AI1HeroInfo[i].heroPosition,gameState.AI2HeroInfo[j-2].heroPosition)<2*HERO_RADIUS)
                        {
                            a[i] = true;

                        }
                    }
                }
            }

            for(int i=0;i<3;i++)
            {
                if (gameState.AI2HeroInfo[i].RebornWait == 0)
                for(int j=0;j<5;j++)
                {
                    if(j<i)
                    {
                        if (gameState.AI2HeroInfo[j].RebornWait == 0)
                        if(Distance(gameState.AI2HeroInfo[i].heroPosition,gameState.AI2HeroInfo[j].heroPosition)<2*HERO_RADIUS)
                        {
                            a[i+3] = true;
                        }
                    }
                    else if(j>=i&&j<2)
                    {
                        if (gameState.AI2HeroInfo[j+1].RebornWait == 0)
                        if(Distance(gameState.AI2HeroInfo[i].heroPosition,gameState.AI2HeroInfo[j+1].heroPosition)<2*HERO_RADIUS)
                        {
                            a[i+3] = true;
                        }
                    }
                    else
                    {
                        if (gameState.AI1HeroInfo[j-2].RebornWait == 0)
                        if(Distance(gameState.AI2HeroInfo[i].heroPosition,gameState.AI1HeroInfo[j-2].heroPosition)<2*HERO_RADIUS)
                        {
                            a[i+3] = true;
                        }
                    }
                }
            }

            for (int i=0; i<6; i++)
            {
                if (a[i])
                {
                    if(i>2)
                    {
                        gameState.AI2HeroInfo[i-3].heroPosition=position[1][i-3];
                    }
                    else
                    {
                        gameState.AI1HeroInfo[i].heroPosition=position[0][i];
                    }
                }
            }

    }

    int OnlyOne(const Status &gameState,Coordinate pos)
    {
        int res=0;
        for (int i=0;i<3;i++)
        {
            if (!gameState.AI1HeroInfo[i].hasSword &&
                Distance(gameState.AI1HeroInfo[i].heroPosition,pos)<=HERO_RADIUS+SWORD_DIST_EPS+SWORD_RADIUS &&
                isOperable(gameState.AI1HeroInfo[i]))
            {
                if (res) return 0;
                res=i+1;
            }
            if (!gameState.AI2HeroInfo[i].hasSword &&
                Distance(gameState.AI2HeroInfo[i].heroPosition,pos)<=HERO_RADIUS+SWORD_DIST_EPS+SWORD_RADIUS &&
                isOperable(gameState.AI2HeroInfo[i]))
            {
                if (res) return 0;
                res=-i-1;
            }
        }
        return res;
    }

    //�غϳ���Ǯ����
    void AddGold(Status & gameState)
    {
        gameState.AI1gold+=GOLD_PER_ROUND;
        gameState.AI2gold+=GOLD_PER_ROUND;  //�غϿ�ʼ��˫�������Ǯ
    }

    //Ӣ�۸����
    void Preparation(Status & gameState)
    {
        for(int i=0;i<3;i++)
        {
            if(gameState.AI1HeroInfo[i].RebornWait==1)
            {
                gameState.AI1HeroInfo[i].heroPosition=gameState.mapInfo.AIHeroBirthPlace[0][i];//����Ӧ���������
                gameState.AI1HeroInfo[i].InvincibleLast=HERO_INVINCIBLE_TIME;//�޵�״̬ʣ��غ���
            }
            if(gameState.AI1HeroInfo[i].RebornWait!=0)gameState.AI1HeroInfo[i].RebornWait--;//������Ӣ����δ����,�򽫵ȴ�ʱ���1
        }
        for(int i=0;i<3;i++)//�Է����
        {
            if(gameState.AI2HeroInfo[i].RebornWait==1)
            {
                gameState.AI2HeroInfo[i].heroPosition=gameState.mapInfo.AIHeroBirthPlace[1][i];
                gameState.AI2HeroInfo[i].InvincibleLast=HERO_INVINCIBLE_TIME;
            }
            if(gameState.AI2HeroInfo[i].RebornWait!=0)gameState.AI2HeroInfo[i].RebornWait--;
        }
    }

    //�Ƽ������º���
    void UpdateTree(Status & gameState,PlayerCommand * command1,PlayerCommand * command2)
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<MAX_UPDATE_NUMBER_PER_ROUND;j++)
            {
                switch(command1->updateScience[i][j])
                {
                case(updateStrenth): //����strenth
                    {
                        if(gameState.AI1gold>=UPDATE_STRENTH_GOLD&&gameState.AI1HeroInfo[i].heroTechTree.strenth<MAXIUMUM_ATTRIBUTE_LEVEL)
                        {
                            gameState.AI1gold-=UPDATE_STRENTH_GOLD;
                            gameState.AI1HeroInfo[i].heroTechTree.strenth++;

                        }
                        break;
                    }
                case(updateAgility): //����agility
                    {
                        if(gameState.AI1gold>=UPDATE_AGILITY_GOLD&&gameState.AI1HeroInfo[i].heroTechTree.agility<MAXIUMUM_ATTRIBUTE_LEVEL)
                        {
                            gameState.AI1gold-=UPDATE_AGILITY_GOLD;
                            gameState.AI1HeroInfo[i].heroTechTree.agility++;
                        }
                        break;
                    }
                case(updateFastWalk): //����fastwalk
                    {
                        if(gameState.AI1HeroInfo[i].heroTechTree.fastWalkLevel<MAXIUMUM_ABILITY_LEVEL)
                        {
                            if(gameState.AI1HeroInfo[i].heroTechTree.fastWalkLevel==0)
                            {
                                if(gameState.AI1gold>=LEARN_FASTWALK_GOLD)
                                {
                                    gameState.AI1HeroInfo[i].fastWalkCD = 0; //����add 10/17
                                    gameState.AI1gold-=LEARN_FASTWALK_GOLD;
                                    gameState.AI1HeroInfo[i].heroTechTree.fastWalkLevel++;
                                }
                            }
                            else
                            {
                                if(gameState.AI1gold>=UPDATE_FASTWALK_GOLD)
                                {
                                    gameState.AI1gold-=UPDATE_FASTWALK_GOLD;
                                    gameState.AI1HeroInfo[i].heroTechTree.fastWalkLevel++;
                                }
                            }
                        }
                        break;
                    }
                case(updateStun)://����stun
                    {
                        if(gameState.AI1HeroInfo[i].heroTechTree.stunLevel<MAXIUMUM_ABILITY_LEVEL)
                        {
                            if(gameState.AI1HeroInfo[i].heroTechTree.stunLevel==0)
                            {
                                if(gameState.AI1gold>=LEARN_STUN_GOLD)
                                {
                                    gameState.AI1HeroInfo[i].stunCD = 0; //����add 10/17
                                    gameState.AI1gold-=LEARN_STUN_GOLD;
                                    gameState.AI1HeroInfo[i].heroTechTree.stunLevel++;
                                }
                            }
                            else
                            {
                                if(gameState.AI1gold>=UPDATE_STUN_GOLD)
                                {
                                    gameState.AI1gold-=UPDATE_STUN_GOLD;
                                    gameState.AI1HeroInfo[i].heroTechTree.stunLevel++;
                                }
                            }
                        }
                        break;
                    }
                case(updateAttack)://����attack
                    {
                        if(gameState.AI1HeroInfo[i].heroTechTree.attackLevel<MAXIUMUM_ABILITY_LEVEL)
                        {
                            if(gameState.AI1HeroInfo[i].heroTechTree.attackLevel==0)
                            {
                                if(gameState.AI1gold>=LEARN_ATTACK_GOLD)
                                {
                                    gameState.AI1gold-=LEARN_ATTACK_GOLD;
                                    gameState.AI1HeroInfo[i].heroTechTree.attackLevel++;
                                }
                            }
                            else
                            {
                                if(gameState.AI1gold>=UPDATE_ATTACK_GOLD)
                                {
                                    gameState.AI1gold-=UPDATE_ATTACK_GOLD;
                                    gameState.AI1HeroInfo[i].heroTechTree.attackLevel++;
                                }
                            }
                        }
                        break;
                    }
                default:;
                }
            }
        }
        for(int i=0;i<3;i++)//��һ��
        {
            for(int j=0;j<MAX_UPDATE_NUMBER_PER_ROUND;j++)
            {
                switch(command2->updateScience[i][j])
                {
                case(updateStrenth): //����strenth
                    {
                        if(gameState.AI2gold>=UPDATE_STRENTH_GOLD&&gameState.AI2HeroInfo[i].heroTechTree.strenth<MAXIUMUM_ATTRIBUTE_LEVEL)
                        {
                            gameState.AI2gold-=UPDATE_STRENTH_GOLD;
                            gameState.AI2HeroInfo[i].heroTechTree.strenth++;
                        }
                        break;
                    }
                case(updateAgility): //����agility
                    {
                        if(gameState.AI2gold>=UPDATE_AGILITY_GOLD&&gameState.AI2HeroInfo[i].heroTechTree.agility<MAXIUMUM_ATTRIBUTE_LEVEL)
                        {
                            gameState.AI2gold-=UPDATE_AGILITY_GOLD;
                            gameState.AI2HeroInfo[i].heroTechTree.agility++;
                        }
                        break;
                    }
                case(updateFastWalk): //����fastwalk
                    {
                        if(gameState.AI2HeroInfo[i].heroTechTree.fastWalkLevel<MAXIUMUM_ABILITY_LEVEL)
                        {
                            if(gameState.AI2HeroInfo[i].heroTechTree.fastWalkLevel==0)
                            {
                                if(gameState.AI2gold>=LEARN_FASTWALK_GOLD)
                                {
                                    gameState.AI2HeroInfo[i].fastWalkCD = 0; //����add 10/17
                                    gameState.AI2gold-=LEARN_FASTWALK_GOLD;
                                    gameState.AI2HeroInfo[i].heroTechTree.fastWalkLevel++;
                                }
                            }
                            else
                            {
                                if(gameState.AI2gold>=UPDATE_FASTWALK_GOLD)
                                {
                                    gameState.AI2gold-=UPDATE_FASTWALK_GOLD;
                                    gameState.AI2HeroInfo[i].heroTechTree.fastWalkLevel++;
                                }
                            }
                        }
                        break;
                    }
                case(updateStun)://����stun
                    {
                        if(gameState.AI2HeroInfo[i].heroTechTree.stunLevel<MAXIUMUM_ABILITY_LEVEL)
                        {
                            if(gameState.AI2HeroInfo[i].heroTechTree.stunLevel==0)
                            {
                                if(gameState.AI2gold>=LEARN_STUN_GOLD)
                                {
                                    gameState.AI2HeroInfo[i].stunCD = 0; //����add 10/17
                                    gameState.AI2gold-=LEARN_STUN_GOLD;
                                    gameState.AI2HeroInfo[i].heroTechTree.stunLevel++;
                                }
                            }
                            else
                            {
                                if(gameState.AI2gold>=UPDATE_STUN_GOLD)
                                {
                                    gameState.AI2gold-=UPDATE_STUN_GOLD;
                                    gameState.AI2HeroInfo[i].heroTechTree.stunLevel++;
                                }
                            }
                        }
                        break;
                    }
                case(updateAttack)://����attack
                    {
                        if(gameState.AI2HeroInfo[i].heroTechTree.attackLevel<MAXIUMUM_ABILITY_LEVEL)
                        {
                            if(gameState.AI2HeroInfo[i].heroTechTree.attackLevel==0)
                            {
                                if(gameState.AI2gold>=LEARN_ATTACK_GOLD)
                                {
                                    gameState.AI2gold-=LEARN_ATTACK_GOLD;
                                    gameState.AI2HeroInfo[i].heroTechTree.attackLevel++;
                                }
                            }
                            else
                            {
                                if(gameState.AI2gold>=UPDATE_ATTACK_GOLD)
                                {
                                    gameState.AI2gold-=UPDATE_ATTACK_GOLD;
                                    gameState.AI2HeroInfo[i].heroTechTree.attackLevel++;
                                }
                            }
                        }
                        break;
                    }
                default:;
                }
            }
        }
    }


    //Ӣ���ƶ�����
    void HeroMove(Status & gameState,PlayerCommand * command1,PlayerCommand * command2)
    {
        Coordinate position[2][3];
        //qDebug << "b1";
        for(int i=0;i<3;i++)
        {
            position[0][i]=gameState.AI1HeroInfo[i].heroPosition;
            if(command1->heroOrder[i]==walk&&      //ָ��Ϊwalk
                isOperablew(gameState.AI1HeroInfo[i])
                    && command1->target[i].x <= MAP_RADIUS
                    && command1->target[i].x >= -MAP_RADIUS
                    && command1->target[i].y <= MAP_RADIUS
                    && command1->target[i].y >= -MAP_RADIUS)
            {
                Coordinate centre;
                centre.x = 0; centre.y = 0;
                if (Distance(command1->target[i], centre) > MAP_RADIUS) continue;
                double movespeed = HERO_ORIGIN_SPEED + MOVE_SPEED_PER_AGILITY*gameState.AI1HeroInfo[i].heroTechTree.agility; //movespeed��ʾ����
                if(movespeed<=0)movespeed=0;
                for(int j=0;j<gameState.mapInfo.slowDownAreaNumber;j++)
                {
                    if(Distance(gameState.AI1HeroInfo[i].heroPosition,gameState.mapInfo.slowDownArea[j])<=RADIUS_OF_SLOWDOWNAREA)
                    {
                        movespeed-=SLOWDOWN_REDUCE;
                        if(movespeed<=0)movespeed=0;
                    }
                } //���ݼ����������ȥһ���ٶ�
                if(gameState.AI1HeroInfo[i].FastwalkLast!=0)
                    movespeed *= 1+(SPEEDRATE_WHEN_FASTWALKING_ORIGIN+SPEEDRATE_WHEN_FASTWALKING_PER_LEVEL*gameState.AI1HeroInfo[i].heroTechTree.fastWalkLevel)/100.00;//���粽����
                if(gameState.AI1HeroInfo[i].hasSword) movespeed = movespeed*(1-double(SWORD_REDUCE)/100); //���ݴ���������ȥһ���ٶ�
                //darkthecross �޸ģ�swordreduce���ٵ��ǰٷֱ�
                //Han�ٴ��޸ģ����ٰٷֱȷ������еļӡ��������
                Coordinate target; //Ŀ���
                double distance1=Distance(command1->target[i],gameState.AI1HeroInfo[i].heroPosition); //Ŀ�����Ӣ�۾���
                double distance2=TIME_PER_ROUND*movespeed; //���غ�����ƶ�����
                if(distance1<=distance2)
                {
                    target=command1->target[i]; //��Ŀ�����Ӣ�۾���С��������,��Ŀ��target��Ϊָ���
                }
                else //���򰴸÷���ﵽ��󳤶�Ϊֹ
                {
                    target.x=distance2*(command1->target[i].x-gameState.AI1HeroInfo[i].heroPosition.x)/distance1+gameState.AI1HeroInfo[i].heroPosition.x;
                    target.y=distance2*(command1->target[i].y-gameState.AI1HeroInfo[i].heroPosition.y)/distance1+gameState.AI1HeroInfo[i].heroPosition.y;
                }
                //darkthecross�޸ģ�������ʲô������
                //Han˵����Ӧ��û���˰�...
                //darkthecross�²ۣ��������ˡ���
                for(int j=0;j<gameState.mapInfo.roadBlockNumber;j++)
                {
                    target = check_intersection(gameState.mapInfo.roadBlock[j],gameState.AI1HeroInfo[i].heroPosition,target,RADIUS_OF_ROADBLOCK+HERO_RADIUS);//����·��ˢ��target
                }
                for(int j=0;j<2;j++)
                {
                    target = check_intersection(gameState.mapInfo.AIBases[j],gameState.AI1HeroInfo[i].heroPosition,target,2*HERO_RADIUS);//���ݻ���ˢ��target
                }
                for(int j=0;j<3;j++)
                {
                    if(i!=j)
                        target = check_intersection(gameState.mapInfo.AIHeroBirthPlace[0][j],gameState.AI1HeroInfo[i].heroPosition,target,2*HERO_RADIUS);//���ݳ�����ˢ��target
                        target = check_intersection(gameState.mapInfo.AIHeroBirthPlace[1][j],gameState.AI1HeroInfo[i].heroPosition,target,2*HERO_RADIUS);//���ݳ�����ˢ��target
                }


                Coordinate o_center;
                o_center.x=o_center.y=0;//o_center��ʾԭ��
                if(Distance(target,o_center)>MAP_RADIUS-HERO_RADIUS)
                {
                    target = check_intersection(o_center,target,gameState.AI1HeroInfo[i].heroPosition,MAP_RADIUS-HERO_RADIUS);
                    //����˼����Ϊʹ��check_intersection��������target��Ϊ����ʼ�㣨��Ϊ����Բ�⣩
                }

                gameState.AI1HeroInfo[i].heroPosition=target;//��λ�ø���Ŀ���target
            }
        }
        //qDebug << "b2";
        for(int i=0;i<3;i++) //��һ��
        {
            position[1][i]=gameState.AI2HeroInfo[i].heroPosition;
            if(command2->heroOrder[i]==walk&&
                isOperablew(gameState.AI2HeroInfo[i])
                    && command2->target[i].x <= MAP_RADIUS
                    && command2->target[i].x >= -MAP_RADIUS
                    && command2->target[i].y <= MAP_RADIUS
                    && command2->target[i].y >= -MAP_RADIUS)
            {
                Coordinate centre;
                centre.x = 0; centre.y = 0;
                if (Distance(command2->target[i], centre) > MAP_RADIUS) continue;
                double movespeed = HERO_ORIGIN_SPEED + MOVE_SPEED_PER_AGILITY*gameState.AI2HeroInfo[i].heroTechTree.agility;
                if(movespeed<=0)movespeed=0;
                for(int j=0;j<gameState.mapInfo.slowDownAreaNumber;j++)
                {
                    if(Distance(gameState.AI2HeroInfo[i].heroPosition,gameState.mapInfo.slowDownArea[j])<=RADIUS_OF_SLOWDOWNAREA)
                    {
                        movespeed-=SLOWDOWN_REDUCE;
                        if(movespeed<=0)movespeed=0;
                    }
                }
                if(gameState.AI2HeroInfo[i].FastwalkLast!=0)
                    movespeed *= 1+(SPEEDRATE_WHEN_FASTWALKING_ORIGIN+SPEEDRATE_WHEN_FASTWALKING_PER_LEVEL*gameState.AI2HeroInfo[i].heroTechTree.fastWalkLevel)/100.00;//���粽״̬
                if(gameState.AI2HeroInfo[i].hasSword) movespeed = movespeed*(1-double(SWORD_REDUCE)/100); //���ݴ���������ȥһ���ٶ�
                //darkthecross �޸ģ�swordreduce���ٵ��ǰٷֱ�
                //Han�ٴ��޸ģ����ٰٷֱȷ������еļӡ��������
                Coordinate target;
                double distance1=Distance(command2->target[i],gameState.AI2HeroInfo[i].heroPosition);
                double distance2=TIME_PER_ROUND*movespeed;
                if(distance1<=distance2)
                {
                    target=command2->target[i];
                }
                else
                {
                    target.x=distance2*(command2->target[i].x-gameState.AI2HeroInfo[i].heroPosition.x)/distance1+gameState.AI2HeroInfo[i].heroPosition.x;
                    target.y=distance2*(command2->target[i].y-gameState.AI2HeroInfo[i].heroPosition.y)/distance1+gameState.AI2HeroInfo[i].heroPosition.y;
                }
                for(int j=0;j<gameState.mapInfo.roadBlockNumber;j++)
                {
                    target = check_intersection(gameState.mapInfo.roadBlock[j],gameState.AI2HeroInfo[i].heroPosition,target,RADIUS_OF_ROADBLOCK+HERO_RADIUS);
                }
                for(int j=0;j<2;j++)
                {
                    target = check_intersection(gameState.mapInfo.AIBases[j],gameState.AI2HeroInfo[i].heroPosition,target,2*HERO_RADIUS);//���ݻ���ˢ��target
                }
                for(int j=0;j<3;j++)
                {
                    target = check_intersection(gameState.mapInfo.AIHeroBirthPlace[0][j],gameState.AI2HeroInfo[i].heroPosition,target,2*HERO_RADIUS);//���ݳ�����ˢ��target
                    if(i!=j)
                        target = check_intersection(gameState.mapInfo.AIHeroBirthPlace[1][j],gameState.AI2HeroInfo[i].heroPosition,target,2*HERO_RADIUS);//���ݳ�����ˢ��target
                }

                Coordinate o_center;
                o_center.x=o_center.y=0;//o_center��ʾԭ��
                if(Distance(target,o_center)>MAP_RADIUS-HERO_RADIUS)
                {
                    target = check_intersection(o_center,target,gameState.AI2HeroInfo[i].heroPosition,MAP_RADIUS-HERO_RADIUS);
                    //����˼����Ϊʹ��check_intersection��������target��Ϊ����ʼ�㣨��Ϊ����Բ�⣩
                }
                gameState.AI2HeroInfo[i].heroPosition=target;
            }
        }
        //qDebug << "b3";
        HeroMoveBack(gameState,position); //�����ظ����䷵��
        //qDebug << "b4";
    }

    //Ӣ�ۼ��粽
    void HeroFastWalk(Status & gameState,PlayerCommand * command1,PlayerCommand * command2)
    {
        for(int i=0;i<3;i++)
        {
            bool NEW = false; //�ûغ��Ƿ�ɹ������˼��粽�ķ���
            //��ָ��Ϊ���粽
            if(command1->heroOrder[i]==fastWalk)
            {
                if(gameState.AI1HeroInfo[i].StunLast==0&&           //Ӣ��δѣ��
                    gameState.AI1HeroInfo[i].RebornWait==0&&        //Ӣ��δ����
                    !gameState.AI1HeroInfo[i].hasSword&&				//Ӣ��û�����
                    gameState.AI1HeroInfo[i].fastWalkCD==0&&		//Ӣ�ۼ��粽CDΪ��
                    gameState.AI1HeroInfo[i].FastwalkLast==0&&       //Ӣ�ۼ��粽δ����
                    gameState.AI1HeroInfo[i].heroTechTree.fastWalkLevel!=0)//���粽�ȼ�����
                {
                    gameState.AI1HeroInfo[i].fastWalkCD=FAST_WALK_CD;                         //ȷ��CD
                    gameState.AI1HeroInfo[i].FastwalkForwardWait=FAST_WALK_FORWARD_SWING;
                    gameState.AI1HeroInfo[i].FastwalkBackWait=FAST_WALK_BACK_SWING;            //��ʼ��ǰҡ���ҡ
                    NEW = true;             //��ʾ�ûغϷ����˼��粽
                }
            }

            if(gameState.AI1HeroInfo[i].FastwalkForwardWait==0&&
                gameState.AI1HeroInfo[i].fastWalkCD<=FAST_WALK_CD-1&&
                gameState.AI1HeroInfo[i].fastWalkCD>=FAST_WALK_CD-FAST_WALK_FORWARD_SWING-1)
                gameState.AI1HeroInfo[i].FastwalkLast=FAST_WALK_LAST_ROUND; //��ǰҡΪ0��CD������ȷ��Χ,�򼲷粽��������

            if(gameState.AI1HeroInfo[i].fastWalkCD>0)gameState.AI1HeroInfo[i].fastWalkCD--; //��CD
            if(gameState.AI1HeroInfo[i].FastwalkLast!=0)gameState.AI1HeroInfo[i].FastwalkLast--; //�����粽���ڽ���,��ʣ��غ�����һ
            if(!NEW) //���ûغ�δ�ɹ��������粽,��ǰҡ���ҡ���е���
            {
                if(gameState.AI1HeroInfo[i].FastwalkForwardWait==0&&gameState.AI1HeroInfo[i].FastwalkBackWait!=0)
                    gameState.AI1HeroInfo[i].FastwalkBackWait--;
                if(gameState.AI1HeroInfo[i].FastwalkForwardWait!=0)gameState.AI1HeroInfo[i].FastwalkForwardWait--;
            }
        }
        for(int i=0;i<3;i++) //��һ���
        {
            bool NEW = false;
            //��ָ��Ϊ���粽
            if(command2->heroOrder[i]==fastWalk)
            {
                if(gameState.AI2HeroInfo[i].StunLast==0&&           //Ӣ��δѣ��
                    gameState.AI2HeroInfo[i].RebornWait==0&&        //Ӣ��δ����
                    !gameState.AI2HeroInfo[i].hasSword&&				//Ӣ��û�����
                    gameState.AI2HeroInfo[i].fastWalkCD==0&&		//Ӣ�ۼ��粽CDΪ��
                    gameState.AI2HeroInfo[i].FastwalkLast==0&&       //Ӣ�ۼ��粽δ����
                    gameState.AI2HeroInfo[i].heroTechTree.fastWalkLevel!=0)//���粽�ȼ�����
                {
                    gameState.AI2HeroInfo[i].fastWalkCD=FAST_WALK_CD;                         //ȷ��CD
                    gameState.AI2HeroInfo[i].FastwalkForwardWait=FAST_WALK_FORWARD_SWING;
                    gameState.AI2HeroInfo[i].FastwalkBackWait=FAST_WALK_BACK_SWING;            //��ʼ��ǰҡ���ҡ
                    NEW = true;             //��ʾ�ûغϷ����˼��粽
                }
            }

            if(gameState.AI2HeroInfo[i].FastwalkForwardWait==0&&
                gameState.AI2HeroInfo[i].fastWalkCD<=FAST_WALK_CD&&
                gameState.AI2HeroInfo[i].fastWalkCD>=FAST_WALK_CD-FAST_WALK_FORWARD_SWING)
                gameState.AI2HeroInfo[i].FastwalkLast=FAST_WALK_LAST_ROUND; //��ǰҡΪ0��CD������ȷ��Χ,�򼲷粽��������

            if(gameState.AI2HeroInfo[i].fastWalkCD>0)gameState.AI2HeroInfo[i].fastWalkCD--;
            if(gameState.AI2HeroInfo[i].FastwalkLast!=0)gameState.AI2HeroInfo[i].FastwalkLast--;
            if(!NEW)
            {
                if(gameState.AI2HeroInfo[i].FastwalkForwardWait==0&&gameState.AI2HeroInfo[i].FastwalkBackWait!=0)
                    gameState.AI2HeroInfo[i].FastwalkBackWait--;
                if(gameState.AI2HeroInfo[i].FastwalkForwardWait!=0)gameState.AI2HeroInfo[i].FastwalkForwardWait--;
            }
        }

    }

    //Ӣ��ս����̤
    void HeroStun(Status & gameState,PlayerCommand * command1,PlayerCommand * command2)
    {
        for(int i=0;i<3;i++)
        {
            bool NEW = false; //NEW��ʾ�Ƿ�ɹ�������̤
            if(gameState.AI1HeroInfo[i].StunLast==0&&              //Ӣ��δѣ��
                gameState.AI1HeroInfo[i].RebornWait==0&&           //Ӣ��δ����
                !gameState.AI1HeroInfo[i].hasSword&&                 //Ӣ��δ�����
                gameState.AI1HeroInfo[i].stunCD==0&&               //��̤CDΪ0
                command1->heroOrder[i]==stun)					   //ָ��Ϊ������̤
            {
                gameState.AI1HeroInfo[i].stunCD=STUN_ORIGIN_CD-STUN_CD_REDUCE_PER_LEVEL*gameState.AI1HeroInfo[i].heroTechTree.stunLevel; //ȷ��CD
                gameState.AI1HeroInfo[i].StunForwardWait=STUN_FORWARD_SWING;
                gameState.AI1HeroInfo[i].StunBackWait=STUN_BACK_SWING;   //ȷ��ǰ,��ҡ
                NEW = true;   //��ʾ��̤�����ɹ�
            }

            //��̤Ч������
            if(gameState.AI1HeroInfo[i].StunForwardWait==0&&gameState.AI1HeroInfo[i].StunBackWait==STUN_BACK_SWING) //��ǰҡ�ȴ�ʱ��Ϊ0,��ҡ�ȴ�ʱ��Ϊ��ʼֵ,��������
            {
                for(int j=0;j<2;j++)
                {
                    int add = ((j>=i)?1:0);
                    if(Distance(gameState.AI1HeroInfo[j+add].heroPosition,gameState.AI1HeroInfo[i].heroPosition)<=STUN_RADIUS) //����ѣ�η�Χ��
                    {
                        gameState.AI1HeroInfo[j+add].AttackBackWait=0;
                        gameState.AI1HeroInfo[j+add].AttackForwardWait=0;
                        //gameState.AI1HeroInfo[j+add].FastwalkBackWait=0;
                        //gameState.AI1HeroInfo[j+add].FastwalkForwardWait=0;
                        //gameState.AI1HeroInfo[j+add].FastwalkLast=0;           //����������м���������
                        gameState.AI1HeroInfo[j+add].StunLast=STUN_ROUNDS_ORIGIN+STUN_ROUNDS_PER_LEVEL*gameState.AI1HeroInfo[i].heroTechTree.stunLevel;    //ѣ��ʣ��غ���
                        gameState.AI1HeroInfo[j+add].currentHP-=STUN_ORINGIN_DAMAGE+STUN_DAMAGE_PER_LEVEL*gameState.AI1HeroInfo[i].heroTechTree.stunLevel;//������ֵ
                        if(gameState.AI1HeroInfo[j+add].StunForwardWait==0&&
                            gameState.AI1HeroInfo[j+add].StunBackWait==STUN_BACK_SWING) //��������ȼ�Ϊ:��Ӣ�۵ļ�̤����ͬ���ڱ��غ�����(ǰ��:��̤���ܵĺ�ҡ��ʼֵSTUN_BACK_SWING����Ϊ0)
                        {
                            ;                                           //�����κ���������(������ָ�Ժ�ҡ�Ĳ���),�Ա㵽��Ӣ��ʱ���̤�����ܹ���������
                        }
                        else      //���򽫼�̤���������
                        {
                            //gameState.AI1HeroInfo[j+add].StunBackWait=0;
                            gameState.AI1HeroInfo[j+add].StunForwardWait=0;
                        }
                    }
                }
                for(int j=0;j<3;j++) //��̤�ԶԷ�Ӣ�۵�Ӱ��(��������)
                {
                    if(Distance(gameState.AI2HeroInfo[j].heroPosition,gameState.AI1HeroInfo[i].heroPosition)<=STUN_RADIUS)
                    {
                        gameState.AI2HeroInfo[j].AttackBackWait=0;
                        gameState.AI2HeroInfo[j].AttackForwardWait=0;
                        /*gameState.AI2HeroInfo[j].FastwalkBackWait=0;
                        gameState.AI2HeroInfo[j].FastwalkForwardWait=0;
                        gameState.AI2HeroInfo[j].FastwalkLast=0;*/
                        gameState.AI2HeroInfo[j].StunLast=STUN_ROUNDS_ORIGIN+STUN_ROUNDS_PER_LEVEL*gameState.AI1HeroInfo[i].heroTechTree.stunLevel;
                        gameState.AI2HeroInfo[j].currentHP-=STUN_ORINGIN_DAMAGE+STUN_DAMAGE_PER_LEVEL*gameState.AI1HeroInfo[i].heroTechTree.stunLevel;
                        if(gameState.AI2HeroInfo[j].StunForwardWait==0&&
                            gameState.AI2HeroInfo[j].StunBackWait==STUN_BACK_SWING)
                        {
                            ;
                        }
                        else
                        {
                            //gameState.AI2HeroInfo[j].StunBackWait=0;
                            gameState.AI2HeroInfo[j].StunForwardWait=0;
                        }
                    }
                }
            }
            else if(gameState.AI1HeroInfo[i].StunLast!=0)gameState.AI1HeroInfo[i].StunLast--; //��Ӣ�����ܼ�̤Ӱ����ʣ��غϼ�һ
            if(gameState.AI1HeroInfo[i].stunCD>0)gameState.AI1HeroInfo[i].stunCD--;   //CD���ٵĲ���
            if(!NEW)  //���˻غ�δ�ɹ�������̤,�����ǰ��ҡ���ٲ���
            {
                if(gameState.AI1HeroInfo[i].StunForwardWait==0&&gameState.AI1HeroInfo[i].StunBackWait!=0)
                    gameState.AI1HeroInfo[i].StunBackWait--;
                if(gameState.AI1HeroInfo[i].StunForwardWait!=0)gameState.AI1HeroInfo[i].StunForwardWait--;
            }
        }
        for(int i=0;i<3;i++) //��һ��
        {
            bool NEW = false;
            if(gameState.AI2HeroInfo[i].StunLast==0&&              //Ӣ��δѣ��
                gameState.AI2HeroInfo[i].RebornWait==0&&           //Ӣ��δ����
                !gameState.AI2HeroInfo[i].hasSword&&                 //Ӣ��δ�����
                gameState.AI2HeroInfo[i].stunCD==0&&               //��̤CDΪ0
                command2->heroOrder[i]==stun)					   //ָ��Ϊ������̤
            {
                gameState.AI2HeroInfo[i].stunCD=STUN_ORIGIN_CD-STUN_CD_REDUCE_PER_LEVEL*gameState.AI2HeroInfo[i].heroTechTree.stunLevel; //ȷ��CD
                gameState.AI2HeroInfo[i].StunForwardWait=STUN_FORWARD_SWING;
                gameState.AI2HeroInfo[i].StunBackWait=STUN_BACK_SWING;   //ȷ��ǰ,��ҡ
                NEW = true;   //��ʾ��̤�����ɹ�
            }
            if(gameState.AI2HeroInfo[i].StunForwardWait==0&&gameState.AI2HeroInfo[i].StunBackWait==STUN_BACK_SWING)
            {
                for(int j=0;j<2;j++)
                {
                    int add = ((j>=i)?1:0);
                    if(Distance(gameState.AI2HeroInfo[j+add].heroPosition,gameState.AI2HeroInfo[i].heroPosition)<=STUN_RADIUS)
                    {
                        gameState.AI2HeroInfo[j+add].AttackBackWait=0;
                        gameState.AI2HeroInfo[j+add].AttackForwardWait=0;
                        /*gameState.AI2HeroInfo[j+add].FastwalkBackWait=0;
                        gameState.AI2HeroInfo[j+add].FastwalkForwardWait=0;
                        gameState.AI2HeroInfo[j+add].FastwalkLast=0;*/
                        gameState.AI2HeroInfo[j+add].StunLast=STUN_ROUNDS_ORIGIN+STUN_ROUNDS_PER_LEVEL*gameState.AI2HeroInfo[i].heroTechTree.stunLevel;
                        gameState.AI2HeroInfo[j+add].currentHP-=STUN_ORINGIN_DAMAGE+STUN_DAMAGE_PER_LEVEL*gameState.AI2HeroInfo[i].heroTechTree.stunLevel;
                        if(gameState.AI2HeroInfo[j+add].StunForwardWait==0&&
                            gameState.AI2HeroInfo[j+add].StunBackWait==STUN_BACK_SWING)
                        {
                            ;
                        }
                        else
                        {
                            //gameState.AI2HeroInfo[j+add].StunBackWait=0;
                            gameState.AI2HeroInfo[j+add].StunForwardWait=0;
                        }
                    }
                }
                for(int j=0;j<3;j++)
                {
                    if(Distance(gameState.AI1HeroInfo[j].heroPosition,gameState.AI2HeroInfo[i].heroPosition)<=STUN_RADIUS)
                    {
                        gameState.AI1HeroInfo[j].AttackBackWait=0;
                        gameState.AI1HeroInfo[j].AttackForwardWait=0;
                        /*gameState.AI1HeroInfo[j].FastwalkBackWait=0;
                        gameState.AI1HeroInfo[j].FastwalkForwardWait=0;
                        gameState.AI1HeroInfo[j].FastwalkLast=0;*/
                        gameState.AI1HeroInfo[j].StunLast=STUN_ROUNDS_ORIGIN+STUN_ROUNDS_PER_LEVEL*gameState.AI2HeroInfo[i].heroTechTree.stunLevel;
                        gameState.AI1HeroInfo[j].currentHP-=STUN_ORINGIN_DAMAGE+STUN_DAMAGE_PER_LEVEL*gameState.AI2HeroInfo[i].heroTechTree.stunLevel;
                        if(gameState.AI1HeroInfo[j].StunForwardWait==0&&
                            gameState.AI1HeroInfo[j].StunBackWait==STUN_BACK_SWING)
                        {
                            ;
                        }
                        else
                        {
                            //gameState.AI1HeroInfo[j].StunBackWait=0;
                            gameState.AI1HeroInfo[j].StunForwardWait=0;
                        }
                    }
                }
            }
            else if(gameState.AI2HeroInfo[i].StunLast!=0)gameState.AI2HeroInfo[i].StunLast--;
            if(gameState.AI2HeroInfo[i].stunCD>0)gameState.AI2HeroInfo[i].stunCD--;
            if(!NEW)
            {
                if(gameState.AI2HeroInfo[i].StunForwardWait==0&&gameState.AI2HeroInfo[i].StunBackWait!=0)
                    gameState.AI2HeroInfo[i].StunBackWait--;
                if(gameState.AI2HeroInfo[i].StunForwardWait!=0)gameState.AI2HeroInfo[i].StunForwardWait--;
            }
        }
    }

    void HeroHPRecovery(Status &gameState)
    {
        for (int i=0;i<3;i++)
            if (!gameState.AI1HeroInfo[i].RebornWait)
            {
                //Han�޸ģ������㽫minд��max�ˡ������ѹֲ���Ѫ������
                gameState.AI1HeroInfo[i].currentHP=std::min(
                    (int)(gameState.AI1HeroInfo[i].currentHP+gameState.AI1HeroInfo[i].heroTechTree.strenth*HP_RECOVERY_PER_STRENTH),
                    HERO_ORIGIN_HP+gameState.AI1HeroInfo[i].heroTechTree.strenth*HP_PER_STRENTH);
                gameState.AI2HeroInfo[i].currentHP=std::min(
                    (int)(gameState.AI2HeroInfo[i].currentHP+gameState.AI2HeroInfo[i].heroTechTree.strenth*HP_RECOVERY_PER_STRENTH),
                    HERO_ORIGIN_HP+gameState.AI2HeroInfo[i].heroTechTree.strenth*HP_PER_STRENTH);

            }
    }

    void HeroAttack(Status & gameState,const PlayerCommand &cmd1,const PlayerCommand &cmd2)
    {
        //AI1
        for (int i=0;i<3;i++)
        {
            if (gameState.AI1HeroInfo[i].AttackBackWait)
                gameState.AI1HeroInfo[i].AttackBackWait--;
            if (gameState.AI1HeroInfo[i].AttackBackWait) continue;
            HeroInfo hero=gameState.AI1HeroInfo[i];
            if (!isOperable(hero)) continue;
            if (cmd1.heroOrder[i]!=attack) continue;
            if (Distance(hero.heroPosition,cmd1.target[i])>ATTACK_RANGE) continue;

            int Damge=ATTACK_ORINGIN+ATTACK_PER_LEVEL*hero.heroTechTree.attackLevel;
            for (int j=0;j<3;j++)
            {
                HeroInfo enemy=gameState.AI2HeroInfo[j];
                if (Distance(enemy.heroPosition,cmd1.target[i])>HERO_RADIUS)
                    continue;
                gameState.AI2HeroInfo[j].currentHP-=Damge;
            }
        }

        //AI2
        for (int i=0;i<3;i++)
        {
            if (gameState.AI2HeroInfo[i].AttackBackWait)
                gameState.AI2HeroInfo[i].AttackBackWait--;
            if (gameState.AI2HeroInfo[i].AttackBackWait) continue;
            HeroInfo hero=gameState.AI2HeroInfo[i];
            if (!isOperable(hero)) continue;
            if (cmd2.heroOrder[i]!=attack) continue;
            if (Distance(hero.heroPosition,cmd2.target[i])>ATTACK_RANGE) continue;

            int Damge=ATTACK_ORINGIN+ATTACK_PER_LEVEL*hero.heroTechTree.attackLevel;
            for (int j=0;j<3;j++)
            {
                HeroInfo enemy=gameState.AI1HeroInfo[j];
                if (Distance(enemy.heroPosition,cmd2.target[i])>HERO_RADIUS)
                    continue;
                gameState.AI1HeroInfo[j].currentHP-=Damge;
            }
        }


    }


    void HeroMissile(Status &gameState,const PlayerCommand &cmd1,const PlayerCommand &cmd2)
    {

        //����CD
        for (int i=0;i<3;i++)
        {
            gameState.AI1HeroInfo[i].missileCD=std::max(0,gameState.AI1HeroInfo[i].missileCD-1);
            gameState.AI2HeroInfo[i].missileCD=std::max(0,gameState.AI2HeroInfo[i].missileCD-1);
        }

        //AI1
        for (int i=0;i<3;i++)
        {
            HeroInfo hero=gameState.AI1HeroInfo[i];
            if (!isOperable(hero)) continue;
            if (hero.missileCD) continue;
            if (cmd1.heroOrder[i]!=launchMissile) continue;
            gameState.AI1HeroInfo[i].missileCD=MISSILE_CD;        //��CD

            Coordinate centre; centre.x =0; centre.y = 0;
            if (Distance(cmd1.target[i], centre) > MAP_RADIUS) continue; //add by ���� 10/20

            for (int k=0;k<6;k++)
            if (!gameState.missileInfo[k].isReal)
            {
                double Dist=Distance(hero.heroPosition,cmd1.target[i]);

                gameState.missileInfo[k].isReal=1;
                gameState.missileInfo[k].fromPoint=hero.heroPosition;
                gameState.missileInfo[k].targetPoint=cmd1.target[i];
                gameState.missileInfo[k].speed=MISSILE_ORIGIN_SPEED+MISSILE_SPEED_PER_AGILITY*hero.heroTechTree.agility;
                gameState.missileInfo[k].radius=MISSILE_ORIGIN_RADIUS+MISSILE_RANGE_PER_STRENTH*hero.heroTechTree.strenth;
                gameState.missileInfo[k].power=std::max(0.0,(double)MISSILE_ORIGIN_POWER+MISSILE_DAMAGE_PER_STRENTH*hero.heroTechTree.strenth);//�����˺�
                gameState.missileInfo[k].Last=(int)(Dist/gameState.missileInfo[k].speed)+MISSILE_DELAY;     //���㼸�غϺ�ը

                break;
            }
        }

        //AI2
        for (int i=0;i<3;i++)
        {
            HeroInfo hero=gameState.AI2HeroInfo[i];
            if (!isOperable(hero)) continue;
            if (hero.missileCD) continue;
            if (cmd2.heroOrder[i]!=launchMissile) continue;
            gameState.AI2HeroInfo[i].missileCD=MISSILE_CD;        //��CD

            Coordinate centre; centre.x =0; centre.y = 0;
            if (Distance(cmd1.target[i], centre) > MAP_RADIUS) continue;  //add by ���� 10/20

            for (int k=0;k<6;k++)
            if (!gameState.missileInfo[k].isReal)
            {
                double Dist=Distance(hero.heroPosition,cmd2.target[i]);

                gameState.missileInfo[k].isReal=1;
                gameState.missileInfo[k].fromPoint=hero.heroPosition;
                gameState.missileInfo[k].targetPoint=cmd2.target[i];
                gameState.missileInfo[k].speed=MISSILE_ORIGIN_SPEED+MISSILE_SPEED_PER_AGILITY*hero.heroTechTree.agility;
                gameState.missileInfo[k].radius=MISSILE_ORIGIN_RADIUS+MISSILE_RANGE_PER_STRENTH*hero.heroTechTree.strenth;
                gameState.missileInfo[k].power=std::max(0.0,(double)MISSILE_ORIGIN_POWER+MISSILE_DAMAGE_PER_STRENTH*hero.heroTechTree.strenth);//�����˺�
                gameState.missileInfo[k].Last=(int)(Dist/gameState.missileInfo[k].speed)+MISSILE_DELAY;     //���㼸�غϺ�ը

                break;
            }
        }

        //ˢ��missileInfo
        for (int i=0;i<6;i++)
        {
            StatusMissileInfo missile=gameState.missileInfo[i];
            if (!missile.isReal) continue;
            gameState.missileInfo[i].Last--;
            if (gameState.missileInfo[i].Last) continue;
            gameState.missileInfo[i].isReal=0;

            for (int j=0;j<6;j++)
            {
                if (gameState.missileArea[j].real) continue;
                gameState.missileArea[j].centerPosition=missile.targetPoint;
                gameState.missileArea[j].roundLast=MISSILE_LAST;
                gameState.missileArea[j].power=missile.power;
                gameState.missileArea[j].radius=missile.radius;
                gameState.missileArea[j].real = true;

                break;
            }
        }

        //�����˺�

        //AI1
        for (int i=0;i<3;i++)
        {
            HeroInfo hero=gameState.AI1HeroInfo[i];
            int Damge=0;

            for (int j=0;j<6;j++)
            {
                if (!gameState.missileArea[j].real) continue;
                double Dist=Distance(gameState.missileArea[j].centerPosition,hero.heroPosition);
                if (Dist>gameState.missileArea[j].radius)
                    continue;
                Damge+=std::max(0.0,gameState.missileArea[j].power-MISSILE_POWER_REDUCE*Dist/100);
            }
            gameState.AI1HeroInfo[i].currentHP-=Damge;
        }

        //AI2
        for (int i=0;i<3;i++)
        {
            HeroInfo hero=gameState.AI2HeroInfo[i];
            int Damge=0;

            for (int j=0;j<6;j++)
            {
                if (!gameState.missileArea[j].real) continue;
                double Dist=Distance(gameState.missileArea[j].centerPosition,hero.heroPosition);
                if (Dist>gameState.missileArea[j].radius)
                    continue;
                Damge+=std::max(0.0,gameState.missileArea[j].power-MISSILE_POWER_REDUCE*Dist/100);
            }
            gameState.AI2HeroInfo[i].currentHP-=Damge;
        }

        //ˢ�±�ը�������ʱ��
        for (int i=0;i<6;i++)
        if (gameState.missileArea[i].real)
        {
            gameState.missileArea[i].roundLast--;
            if (!gameState.missileArea[i].roundLast)
                gameState.missileArea[i].real=0;
        }
    }

    void HeroSword(Status &gameState)
    {
        //������е��ҵ����
        //AI1
        for (int i=0;i<3;i++)
        {
            HeroInfo hero=gameState.AI1HeroInfo[i];
            if (hero.hasSword && Distance(hero.heroPosition,gameState.mapInfo.AIBases[0])<=HERO_RADIUS+SWORD_DIST_EPS+SWORD_RADIUS)
            {
                gameState.swordInfo.AI1SwordNumber++;
                gameState.AI1HeroInfo[i].hasSword=0;
            }
        }
        //AI2
        for (int i=0;i<3;i++)
        {
            HeroInfo hero=gameState.AI2HeroInfo[i];
            if (hero.hasSword && Distance(hero.heroPosition,gameState.mapInfo.AIBases[1])<=HERO_RADIUS+SWORD_DIST_EPS+SWORD_RADIUS)
            {
                gameState.swordInfo.AI2SwordNumber++;
                gameState.AI2HeroInfo[i].hasSword=0;
            }
        }

        //���
        gameState.swordInfo.CentreSwordCD=std::max(0,gameState.swordInfo.CentreSwordCD-1);
        if (!gameState.swordInfo.CentreSwordCD)
        {
            Coordinate pos;
            pos.x=pos.y=0;
            int w=OnlyOne(gameState,pos);
            if (w>0)
            {
                gameState.AI1HeroInfo[w-1].hasSword=1;
                gameState.swordInfo.CentreSwordCD=TIME_CentreSwordCD;
            } else
            if (w<0)
            {
                gameState.AI2HeroInfo[-w-1].hasSword=1;
                gameState.swordInfo.CentreSwordCD=TIME_CentreSwordCD;
            }
        }

        //��з����е����
        //AI1
        for (int i=0;i<3;i++)
        {
            HeroInfo hero=gameState.AI1HeroInfo[i];

            if (!isOperable(hero)) continue;
            if (!gameState.swordInfo.AI2SwordNumber) continue;

            if (Distance(hero.heroPosition,gameState.mapInfo.AIBases[1])<=HERO_RADIUS+SWORD_DIST_EPS+SWORD_RADIUS)
            {
                gameState.AI1HeroInfo[i].hasSword=1;
                gameState.swordInfo.AI2SwordNumber--;
            }
        }

        //AI2
        for (int i=0;i<3;i++)
        {
            HeroInfo hero=gameState.AI2HeroInfo[i];

            if (!isOperable(hero)) continue;
            if (!gameState.swordInfo.AI1SwordNumber) continue;

            if (Distance(hero.heroPosition,gameState.mapInfo.AIBases[0])<=HERO_RADIUS+SWORD_DIST_EPS+SWORD_RADIUS)
            {
                gameState.AI2HeroInfo[i].hasSword=1;
                gameState.swordInfo.AI1SwordNumber--;
            }
        }

        //����ϵ����
        for (int i=0;i<gameState.swordInfo.groundNumber;i++)
        {
            int w=OnlyOne(gameState,gameState.swordInfo.groundSwords[i]);
            if (!w) continue;
            if (w>0) gameState.AI1HeroInfo[w-1].hasSword=1;
            else if (w<0) gameState.AI2HeroInfo[-w-1].hasSword=1;

            gameState.swordInfo.groundSwords[i].x=-100000000;
        }
        int now=0;
        for (int i=0;i<gameState.swordInfo.groundNumber;i++)
        if (gameState.swordInfo.groundSwords[i].x>-1000000)
        {
            gameState.swordInfo.groundSwords[now++]=
                gameState.swordInfo.groundSwords[i];
        }
        gameState.swordInfo.groundNumber=now;
    }

    //Ӣ������
    void logic::HeroDeath(Status & gameState)
    {
        for(int i=0;i<3;i++)
        {
            if(gameState.AI1HeroInfo[i].currentHP<=0) //��Ӣ��HPΪ������δ����(������������Ҫ,�Է�ֹ�ȴ������Ӣ��ÿ�ζ���"����")
            {
                gameState.AI1HeroInfo[i].AttackBackWait=0;
                gameState.AI1HeroInfo[i].AttackForwardWait=0;
                gameState.AI1HeroInfo[i].FastwalkBackWait=0;
                gameState.AI1HeroInfo[i].FastwalkForwardWait=0;
                gameState.AI1HeroInfo[i].FastwalkLast=0;
                gameState.AI1HeroInfo[i].StunBackWait=0;
                gameState.AI1HeroInfo[i].StunForwardWait=0;
                gameState.AI1HeroInfo[i].StunLast=0;            //������CD������м�����������ȡ��
                gameState.AI1HeroInfo[i].currentHP=HERO_ORIGIN_HP+gameState.AI1HeroInfo[i].heroTechTree.strenth*HP_PER_STRENTH;//�����ʼ��HP
                if(gameState.AI1HeroInfo[i].hasSword)             //�������
                {
                    gameState.AI1HeroInfo[i].hasSword=false;         //�õ����û��
                    if(gameState.swordInfo.groundNumber < MAX_GOUNDSWORD_NUMBER)
                    {
                                gameState.swordInfo.groundSwords[gameState.swordInfo.groundNumber]=gameState.AI1HeroInfo[i].heroPosition;//�õ������������
                                gameState.swordInfo.groundNumber++;
                    }
                    else
                    {
                        for(int i = 0; i<MAX_GOUNDSWORD_NUMBER-1; i++)
                        {
                            gameState.swordInfo.groundSwords[i] = gameState.swordInfo.groundSwords[i+1];
                        }
                        gameState.swordInfo.groundSwords[MAX_GOUNDSWORD_NUMBER-1] = gameState.AI1HeroInfo[i].heroPosition;
                    }
                }
                gameState.AI1HeroInfo[i].heroPosition.x=(i+1)*100000;
                gameState.AI1HeroInfo[i].heroPosition.y=100000;
                int investment = 0;
                investment += gameState.AI1HeroInfo[i].heroTechTree.agility * UPDATE_AGILITY_GOLD;
                investment += gameState.AI1HeroInfo[i].heroTechTree.strenth * UPDATE_STRENTH_GOLD;
                if(gameState.AI1HeroInfo[i].heroTechTree.attackLevel!=0)
                    investment += (gameState.AI1HeroInfo[i].heroTechTree.attackLevel - 1) * UPDATE_ATTACK_GOLD + LEARN_ATTACK_GOLD;
                if(gameState.AI1HeroInfo[i].heroTechTree.fastWalkLevel!=0)
                    investment += (gameState.AI1HeroInfo[i].heroTechTree.fastWalkLevel - 1) * UPDATE_FASTWALK_GOLD + LEARN_FASTWALK_GOLD;
                if(gameState.AI1HeroInfo[i].heroTechTree.stunLevel!=0)
                    investment += (gameState.AI1HeroInfo[i].heroTechTree.stunLevel - 1) * UPDATE_STUN_GOLD + LEARN_STUN_GOLD;
                gameState.AI1HeroInfo[i].RebornWait=HERO_ORINGIN_REBIRTH_TIME+HERO_REBIRTH_TIME_INCREASE*(investment/100)+1;//���㸴��ȴ��غ���
                gameState.AI2gold+=HERO_GOLD;
                if(!FIRSTBLOOD)
                {
                    FIRSTBLOOD=true;
                    gameState.AI2gold+=FIRST_BLOOD_GOLD;
                }  //�Է����ɱӢ���Լ����ܵ�FIRSTBLOOD��ʹ��Ǯ����
            }
        }
        for(int i=0;i<3;i++)//�Է�
        {
            if(gameState.AI2HeroInfo[i].currentHP<=0)
            {
                gameState.AI2HeroInfo[i].AttackBackWait=0;
                gameState.AI2HeroInfo[i].AttackForwardWait=0;
                gameState.AI2HeroInfo[i].FastwalkBackWait=0;
                gameState.AI2HeroInfo[i].FastwalkForwardWait=0;
                gameState.AI2HeroInfo[i].FastwalkLast=0;
                gameState.AI2HeroInfo[i].StunBackWait=0;
                gameState.AI2HeroInfo[i].StunForwardWait=0;
                gameState.AI2HeroInfo[i].StunLast=0;
                gameState.AI2HeroInfo[i].currentHP=HERO_ORIGIN_HP+gameState.AI2HeroInfo[i].heroTechTree.strenth*HP_PER_STRENTH;//�����ʼ��HP
                if(gameState.AI2HeroInfo[i].hasSword)             //�������
                {
                    gameState.AI2HeroInfo[i].hasSword=false;         //�õ����û��
                    if(gameState.swordInfo.groundNumber < MAX_GOUNDSWORD_NUMBER)
                    {
                                gameState.swordInfo.groundSwords[gameState.swordInfo.groundNumber]=gameState.AI2HeroInfo[i].heroPosition;//�õ������������
                                gameState.swordInfo.groundNumber++;
                    }
                    else
                    {
                        for(int i = 0; i<MAX_GOUNDSWORD_NUMBER-1; i++)
                        {
                            gameState.swordInfo.groundSwords[i] = gameState.swordInfo.groundSwords[i+1];
                        }
                        gameState.swordInfo.groundSwords[MAX_GOUNDSWORD_NUMBER-1] = gameState.AI2HeroInfo[i].heroPosition;
                    }
                }
                gameState.AI2HeroInfo[i].heroPosition.x=100000;
                gameState.AI2HeroInfo[i].heroPosition.y=(i+1)*100000;
                int investment = 0;
                investment += gameState.AI2HeroInfo[i].heroTechTree.agility * UPDATE_AGILITY_GOLD;
                investment += gameState.AI2HeroInfo[i].heroTechTree.strenth * UPDATE_STRENTH_GOLD;
                if(gameState.AI2HeroInfo[i].heroTechTree.attackLevel!=0)
                    investment += (gameState.AI2HeroInfo[i].heroTechTree.attackLevel - 1) * UPDATE_ATTACK_GOLD + LEARN_ATTACK_GOLD;
                if(gameState.AI2HeroInfo[i].heroTechTree.fastWalkLevel!=0)
                    investment += (gameState.AI2HeroInfo[i].heroTechTree.fastWalkLevel - 1) * UPDATE_FASTWALK_GOLD + LEARN_FASTWALK_GOLD;
                if(gameState.AI2HeroInfo[i].heroTechTree.stunLevel!=0)
                    investment += (gameState.AI2HeroInfo[i].heroTechTree.stunLevel - 1) * UPDATE_STUN_GOLD + LEARN_STUN_GOLD;
                gameState.AI2HeroInfo[i].RebornWait=HERO_ORINGIN_REBIRTH_TIME+HERO_REBIRTH_TIME_INCREASE*(investment/100)+1;
                gameState.AI1gold+=HERO_GOLD;
                if(!FIRSTBLOOD)
                {
                    FIRSTBLOOD=true;
                    gameState.AI1gold+=FIRST_BLOOD_GOLD;
                }
            }
        }
    }

    void logic::update(PlayerCommand * cmd1,PlayerCommand * cmd2)
    {
        //qDebug() << 'a';
        gameState.roundNumber++;//�غ�����1
        AddGold(gameState);
        Preparation(gameState);
        UpdateTree(gameState, cmd1, cmd2);
        //////qDebug()<<"3";
        //qDebug() << 'b';
        HeroMove(gameState,cmd1,cmd2);
        //qDebug() << 'c';
       // ////qDebug()<<"4";
        HeroFastWalk(gameState,cmd1,cmd2);
        //qDebug() << 'd';
        HeroStun(gameState,cmd1,cmd2);
        //qDebug() << 'e';
        HeroHPRecovery(gameState);
        //qDebug() << 'f';
        HeroAttack(gameState,* cmd1,* cmd2);
        //qDebug() << 'g';
        HeroMissile(gameState,* cmd1,* cmd2);
        //qDebug() << 'h';
        HeroSword(gameState);
        //qDebug() << 'i';
        HeroDeath(gameState);
        //qDebug() << 'j';
    }

    Status logic::getStatus()
    {
        return gameState;
    }

}
