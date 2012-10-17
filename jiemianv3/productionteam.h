#ifndef PRODUCTIONTEAM_H
#define PRODUCTIONTEAM_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "productionteamtitle.h"

class ProductionTeam:public QWidget
{
     Q_OBJECT
public:
   ProductionTeam(QWidget *parent = 0);
   QPushButton* getBotton();
private:
   QLabel *label;
   QLabel *space;
   ProductionTeamTiltle* productionteamtiltle;
};

#endif // PRODUCTIONTEAM_H

