#ifndef FINDPATH_H
#define FINDPATH_H

namespace FindPath
{

using namespace DS14;

double Dis(Coordinate &p1, Coordinate &p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
double DisSquare(Coordinate &p1, Coordinate &p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool Cutting(Coordinate *que, int &r)
{
    Coordinate centre;
    centre.x = 0; centre.y = 0;
    if (Dis(que[r], centre) > MAP_RADIUS) { r--; return true;}
    for (int i=0; i<r; i++)
        if (Dis(que[i], que[r]) < 10) {r--; return true;}
    return false;
}

bool CanGo(GameInfo & gInfo, Coordinate &p1, Coordinate &p2, int heroID)
{
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double A = -dy, B = dx, C = A*p1.x + B*p1.y;
    for (int i=0; i<gInfo.mapInfo.roadBlockNumber; i++)
    {
        Coordinate block = gInfo.mapInfo.roadBlock[i];
        double dis = abs(A*block.x + B*block.y - C) / sqrt(A*A+B*B);
        if (dis < RADIUS_OF_ROADBLOCK + HERO_RADIUS)
        {
            double AA = B, BB = -A;
            double CC = AA*block.x + BB*block.y;
            if ((AA*p1.x+BB*p1.y-CC)*(AA*p2.x+BB*p2.y-CC) < 0) return false;
        }
    }
    for (int i=0; i<3; i++)
    {
        Coordinate block = gInfo.mapInfo.enemyHeroBirthPlace[i];
        double dis = abs(A*block.x + B*block.y - C) / sqrt(A*A+B*B);
        if (dis < HERO_RADIUS * 2)
        {
            double AA = B, BB = -A;
            double CC = AA*block.x + BB*block.y;
            if ((AA*p1.x+BB*p1.y-CC)*(AA*p2.x+BB*p2.y-CC) < 0) return false;
        }
    }
    for (int i=0; i<3; i++)
    {
        if (i==heroID) continue;
        Coordinate block = gInfo.mapInfo.selfHeroBirthPlace[i];
        double dis = abs(A*block.x + B*block.y - C) / sqrt(A*A+B*B);
        if (dis < 2*HERO_RADIUS)
        {
            double AA = B, BB = -A;
            double CC = AA*block.x + BB*block.y;
            if ((AA*p1.x+BB*p1.y-CC)*(AA*p2.x+BB*p2.y-CC) < 0) return false;
        }
    }
    for (int i=0; i<3; i++)
    {
        if (i==heroID) continue;
        Coordinate block = gInfo.selfHeroInfo[i].heroPosition;
        double dis = abs(A*block.x + B*block.y - C) / sqrt(A*A+B*B);
        if (dis < 2*HERO_RADIUS)
        {
            double AA = B, BB = -A;
            double CC = AA*block.x + BB*block.y;
            if ((AA*p1.x+BB*p1.y-CC)*(AA*p2.x+BB*p2.y-CC) < 0) return false;
        }
    }
    Coordinate block = gInfo.mapInfo.selfBase;
    double dis = abs(A*block.x + B*block.y - C) / sqrt(A*A+B*B);
    if (dis < HERO_RADIUS + BASE_RADIUS)
    {
        double AA = B, BB = -A;
        double CC = AA*block.x + BB*block.y;
        if ((AA*p1.x+BB*p1.y-CC)*(AA*p2.x+BB*p2.y-CC) < 0) return false;
    }

    block = gInfo.mapInfo.enemyBase;
    dis = abs(A*block.x + B*block.y - C) / sqrt(A*A+B*B);
    if (dis < HERO_RADIUS + BASE_RADIUS)
    {
        double AA = B, BB = -A;
        double CC = AA*block.x + BB*block.y;
        if ((AA*p1.x+BB*p1.y-CC)*(AA*p2.x+BB*p2.y-CC) < 0) return false;
    }

    return true;
}

const int A[4] = {0, 1,1,1}; //搜路八个方向的直线方程 Ax + By = C
const int B[4] = {1,-1,0,1};
const int longest = 10000;
const int max_step = 200;
const double dx_rate[4] = {1, 0.7071, 0, 0.7071},
             dy_rate[4] = {0, 0.7071, 1, -0.7071};
Coordinate & Goto(GameInfo & gInfo, int heroID, Coordinate & target)
{
    bool Cutting(Coordinate *que, int &r);
    Coordinate current = gInfo.selfHeroInfo[heroID].heroPosition;
    Coordinate que[longest];
    int dir[longest];
    int f = 0, r = 0;
    que[f] = target;
    dir[f] = -1;
    if (CanGo(gInfo, current, que[r], heroID)) return que[r];
    while (f<=r && r<longest-8)
    {
        for (int i=0; i<4; i++)
        {
            double step = max_step, opp_step = max_step;
            double C = A[i]*que[f].x + B[i]*que[f].y;
            for (int j=0; j<gInfo.mapInfo.roadBlockNumber; j++) //障碍
            {
                Coordinate block = gInfo.mapInfo.roadBlock[j];
                double dis_to_line = abs(A[i] * block.x + B[i] * block.y - C) / sqrt(double(A[i] * A[i] + B[i] * B[i]));
                if (dis_to_line >= RADIUS_OF_ROADBLOCK + HERO_RADIUS) continue;
                double radius = RADIUS_OF_ROADBLOCK + HERO_RADIUS;
                double restrict_dis = sqrt(DisSquare(que[f], block) - dis_to_line * dis_to_line) -
                                      sqrt(radius * radius - dis_to_line * dis_to_line);
                int k = (i + 2) % 4; //perpendicular
                double CC = A[k]*que[f].x + B[k]*que[f].y;
                if (A[k]*block.x + B[k]*block.y - CC > 0)
                { if (restrict_dis < step) step = restrict_dis;}
                else if (restrict_dis < opp_step) opp_step = restrict_dis;
            }
            for (int j=0; j<3; j++)	//敌方英雄出生点
            {
                Coordinate block = gInfo.mapInfo.enemyHeroBirthPlace[j];
                double dis_to_line = abs(A[i] * block.x + B[i] * block.y - C) / sqrt(double(A[i] * A[i] + B[i] * B[i]));
                if (dis_to_line >= HERO_RADIUS*2) continue;
                double radius = HERO_RADIUS*2;
                double restrict_dis = sqrt(DisSquare(que[f], block) - dis_to_line * dis_to_line) -
                                      sqrt(radius * radius - dis_to_line * dis_to_line);
                int k = (i + 2) % 4; //perpendicular
                double CC = A[k]*que[f].x + B[k]*que[f].y;
                if (A[k]*block.x + B[k]*block.y - CC > 0)
                { if (restrict_dis < step) step = restrict_dis;}
                else if (restrict_dis < opp_step) opp_step = restrict_dis;
            }
            for (int j=0; j<3; j++)
            {
                if (j == heroID) continue;
                Coordinate block = gInfo.mapInfo.selfHeroBirthPlace[j];//己方英雄出生点
                double dis_to_line = abs(A[i] * block.x + B[i] * block.y - C) / sqrt(double(A[i] * A[i] + B[i] * B[i]));
                if (dis_to_line >= HERO_RADIUS*2) continue;
                double radius = HERO_RADIUS*2;
                double restrict_dis = sqrt(DisSquare(que[f], block) - dis_to_line * dis_to_line) -
                                      sqrt(radius * radius - dis_to_line * dis_to_line);
                int k = (i + 2) % 4; //perpendicular
                double CC = A[k]*que[f].x + B[k]*que[f].y;
                if (A[k]*block.x + B[k]*block.y - CC > 0)
                { if (restrict_dis < step) step = restrict_dis;}
                else if (restrict_dis < opp_step) opp_step = restrict_dis;
            }

            for (int j=0; j<3; j++)
            {
                if (j == heroID) continue;
                Coordinate block = gInfo.selfHeroInfo[j].heroPosition; //己方英雄
                double dis_to_line = abs(A[i] * block.x + B[i] * block.y - C) / sqrt(double(A[i] * A[i] + B[i] * B[i]));
                if (dis_to_line >= HERO_RADIUS*2) continue;
                double radius = HERO_RADIUS*2;
                double restrict_dis = sqrt(DisSquare(que[f], block) - dis_to_line * dis_to_line) -
                                      sqrt(radius * radius - dis_to_line * dis_to_line);
                int k = (i + 2) % 4; //perpendicular
                double CC = A[k]*que[f].x + B[k]*que[f].y;
                if (A[k]*block.x + B[k]*block.y - CC > 0)
                { if (restrict_dis < step) step = restrict_dis;}
                else if (restrict_dis < opp_step) opp_step = restrict_dis;
            }
            if (step > 0 && dir[f] != i+4)
            {
                r++;
                que[r].x = que[f].x + step * dx_rate[i];
                que[r].y = que[f].y + step * dy_rate[i];
                dir[r] = i;
                if (!Cutting(que, r)) if (CanGo(gInfo, current, que[r], heroID))
                    return que[r];
            }
            if (opp_step > 0 && dir[f] != i)
            {
                r++;
                que[r].x = que[f].x - opp_step * dx_rate[i];
                que[r].y = que[f].y - opp_step * dy_rate[i];
                dir[r] = i+4;
                if (!Cutting(que, r))  if (CanGo(gInfo, current, que[r], heroID))
                    return que[r];
            }
        }
        f++;
    }
    return target;
}

}

#endif // FINDPATH_H
