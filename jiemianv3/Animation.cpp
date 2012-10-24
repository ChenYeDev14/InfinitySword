#include "Animation.h"
#include <QtGui>

const double pi = 3.1415926;

QParallelAnimationGroup* MenuAnimation(QGraphicsProxyWidget *formerWidget, QGraphicsProxyWidget *aimWidget, QState *formerState, QState *aimState)
{
    if(formerWidget != NULL)
    {
        formerState->assignProperty(formerWidget->widget(), "windowOpacity", 1);
        formerState->assignProperty(aimWidget->widget(), "windowOpacity", 0);
    }

    aimState->assignProperty(aimWidget->widget(), "windowOpacity", 1);
    if(formerWidget != NULL)
        aimState->assignProperty(formerWidget->widget(), "windowOpacity", 0);
    int y;
    if(formerWidget != NULL)
         y = formerWidget->widget()->y();
    else
         y = aimWidget->widget()->y();

    QPropertyAnimation *DisWidget;
    if(formerWidget != NULL)
    {
        DisWidget = new QPropertyAnimation(formerWidget->widget(), "windowOpacity");
        DisWidget->setDuration(500);
        DisWidget->setKeyValueAt(1,0);
        DisWidget->setEasingCurve(QEasingCurve::InOutQuad);
    }

    QPropertyAnimation *AppWidget;
    if(aimWidget != NULL)
    {
        AppWidget = new QPropertyAnimation(aimWidget->widget(), "windowOpacity");
        AppWidget->setDuration(1000);
        AppWidget->setKeyValueAt(1,1);
        AppWidget->setEasingCurve(QEasingCurve::InOutQuad);
    }

    QPropertyAnimation *fPingWidget;
    if(formerWidget != NULL)
    {
        fPingWidget = new QPropertyAnimation(formerWidget, "y");
        fPingWidget->setDuration(500);
        fPingWidget->setKeyValueAt(0,y);
        fPingWidget->setKeyValueAt(0.9999,y-900);
        fPingWidget->setEasingCurve(QEasingCurve::InOutQuad);
    }

    QPropertyAnimation *aPingWidget;
    if(aimWidget != NULL)
    {
        aPingWidget = new QPropertyAnimation(aimWidget, "y");
        aPingWidget->setDuration(1000);
        aPingWidget->setKeyValueAt(0.00001,y-900);
        aPingWidget->setKeyValueAt(0.5,y);
        for ( int i = 0 ; i < 5 ; i++ ){
            aPingWidget->setKeyValueAt(0.5 + 0.05 * (2 * i + 1 )  , y - 200 / (i + 1 ));
            aPingWidget->setKeyValueAt(0.5 + 0.1 * ( i + 1 ) , y);
        }
        aPingWidget->setKeyValueAt(1,y);
        aPingWidget->setEasingCurve(QEasingCurve::InOutQuad);
    }

    QParallelAnimationGroup* parallelWid = new QParallelAnimationGroup();
    if(formerWidget != NULL)
        parallelWid->addAnimation(DisWidget);
    if(aimWidget != NULL)
        parallelWid->addAnimation(AppWidget);
    if(formerWidget != NULL)
        parallelWid->addAnimation(fPingWidget);
    if(aimWidget != NULL)
        parallelWid->addAnimation(aPingWidget);

    return parallelWid;
}

QParallelAnimationGroup* WindowAnimation(QGraphicsProxyWidget *formerWidget, QGraphicsProxyWidget *aimWidget, QState *formerState, QState *aimState)
{
    formerState->assignProperty(formerWidget->widget(), "windowOpacity", 1);
    formerState->assignProperty(aimWidget->widget(), "windowOpacity", 0);

    aimState->assignProperty(aimWidget->widget(), "windowOpacity", 1);
    aimState->assignProperty(formerWidget->widget(), "windowOpacity", 0);

    QPropertyAnimation *DisWidget = new QPropertyAnimation(formerWidget->widget(), "windowOpacity");
    DisWidget->setDuration(500);
    DisWidget->setKeyValueAt(1,0);
    DisWidget->setEasingCurve(QEasingCurve::InOutQuad);

    QPropertyAnimation *AppWidget = new QPropertyAnimation(aimWidget->widget(), "windowOpacity");
    AppWidget->setDuration(500);
    AppWidget->setKeyValueAt(1,1);
    AppWidget->setEasingCurve(QEasingCurve::InOutQuad);

    QParallelAnimationGroup* parallelWid = new QParallelAnimationGroup();
    parallelWid->addAnimation(DisWidget);
    parallelWid->addAnimation(AppWidget);

    return parallelWid;
}

QParallelAnimationGroup* ButtonAnimation(QPushButton* but[], int n)
{
    QParallelAnimationGroup *group = new QParallelAnimationGroup;
    for (int i = 0; i < 10 ; ++i) {
         QPropertyAnimation *anim = new QPropertyAnimation(but[i], "pos");
         anim->setDuration(750 + 9*25 - i * 25);
         if ( i == 9 )
             anim->setKeyValueAt(1,QPointF(but[9]->x(),but[9]->y()));
         for ( int j = 1 ; j <= ( 9 - i ) ; j++ ){
             anim->setKeyValueAt( 1.0 / ( 9.0 - (double)i ) * (double)j ,QPointF(but[9]->x() - ( 1 - cos ( pi / 2 * j ) ) * 80 , but[9]->y() - j * 60 ));
         }
         anim->setEasingCurve(QEasingCurve::InOutBack);
         group->addAnimation(anim);
     }

    return group;
}


QParallelAnimationGroup* MenuToWindowAnimation(QGraphicsProxyWidget *formerWidget, QGraphicsProxyWidget *aimWidget, QState *formerState, QState *aimState)
{
    if(formerWidget != NULL)
    {
        formerState->assignProperty(formerWidget->widget(), "windowOpacity", 1);
        formerState->assignProperty(aimWidget->widget(), "windowOpacity", 0);
    }

    aimState->assignProperty(aimWidget->widget(), "windowOpacity", 1);
    if(formerWidget != NULL)
        aimState->assignProperty(formerWidget->widget(), "windowOpacity", 0);
    int y;
    if(formerWidget != NULL)
         y = formerWidget->widget()->y();
    else
         y = aimWidget->widget()->y();

    QPropertyAnimation *DisWidget;
    if(formerWidget != NULL)
    {
        DisWidget = new QPropertyAnimation(formerWidget->widget(), "windowOpacity");
        DisWidget->setDuration(500);
        DisWidget->setKeyValueAt(0.00001,1);
        DisWidget->setKeyValueAt(1,0);
        DisWidget->setEasingCurve(QEasingCurve::InOutQuad);
    }

    QPropertyAnimation *AppWidget;
    if(aimWidget != NULL)
    {
        AppWidget = new QPropertyAnimation(aimWidget->widget(), "windowOpacity");
        AppWidget->setDuration(1000);
        AppWidget->setKeyValueAt(0.00001,0);
        AppWidget->setKeyValueAt(0.4,0);
        AppWidget->setKeyValueAt(1,1);
        AppWidget->setEasingCurve(QEasingCurve::InOutQuad);
    }

    QPropertyAnimation *fPingWidget;
    if(formerWidget != NULL)
    {
        fPingWidget = new QPropertyAnimation(formerWidget, "y");
        fPingWidget->setDuration(500);
        fPingWidget->setKeyValueAt(0,y);
        fPingWidget->setKeyValueAt(0.9999,y-900);
        fPingWidget->setEasingCurve(QEasingCurve::InOutQuad);
    }


    QParallelAnimationGroup* parallelWid = new QParallelAnimationGroup();
    if(formerWidget != NULL)
        parallelWid->addAnimation(DisWidget);
    if(aimWidget != NULL)
        parallelWid->addAnimation(AppWidget);
    if(formerWidget != NULL)
        parallelWid->addAnimation(fPingWidget);

    return parallelWid;
}

QParallelAnimationGroup* WindowToMenuAnimation(QGraphicsProxyWidget *formerWidget, QGraphicsProxyWidget *aimWidget, QState *formerState, QState *aimState)
{
    if(formerWidget != NULL)
    {
        formerState->assignProperty(formerWidget->widget(), "windowOpacity", 1);
        formerState->assignProperty(aimWidget->widget(), "windowOpacity", 0);
    }

    aimState->assignProperty(aimWidget->widget(), "windowOpacity", 1);
    if(formerWidget != NULL)
        aimState->assignProperty(formerWidget->widget(), "windowOpacity", 0);
    int y;
    if(aimWidget != NULL)
         y = aimWidget->widget()->y();
    else
         y = formerWidget->widget()->y();
    QPropertyAnimation *DisWidget;
    if(formerWidget != NULL)
    {
        DisWidget = new QPropertyAnimation(formerWidget->widget(), "windowOpacity");
        DisWidget->setDuration(500);
        DisWidget->setKeyValueAt(0.00001,1);
        DisWidget->setKeyValueAt(1,0);
        DisWidget->setEasingCurve(QEasingCurve::InOutQuad);
    }

    QPropertyAnimation *AppWidget;
    if(aimWidget != NULL)
    {
        AppWidget = new QPropertyAnimation(aimWidget->widget(), "windowOpacity");
        AppWidget->setDuration(1000);
        AppWidget->setKeyValueAt(0.00001,0);
        AppWidget->setKeyValueAt(0.4,0);
        AppWidget->setKeyValueAt(1,1);
        AppWidget->setEasingCurve(QEasingCurve::InOutQuad);
    }

    QPropertyAnimation *aPingWidget;
    if(aimWidget != NULL)
    {
        aPingWidget = new QPropertyAnimation(aimWidget, "y");
        aPingWidget->setDuration(1000);
        aPingWidget->setKeyValueAt(0.00001,y-900);
        aPingWidget->setKeyValueAt(0.5,y);
        for ( int i = 0 ; i < 5 ; i++ ){
            aPingWidget->setKeyValueAt(0.5 + 0.05 * (2 * i + 1 )  , y - 200 / (i + 1 ));
            aPingWidget->setKeyValueAt(0.5 + 0.1 * ( i + 1 ) , y);
        }
        aPingWidget->setKeyValueAt(1,y);
        aPingWidget->setEasingCurve(QEasingCurve::InOutQuad);
    }

    QParallelAnimationGroup* parallelWid = new QParallelAnimationGroup();
    if(formerWidget != NULL)
        parallelWid->addAnimation(DisWidget);
    if(aimWidget != NULL)
        parallelWid->addAnimation(AppWidget);
    if(aimWidget != NULL)
        parallelWid->addAnimation(aPingWidget);

    return parallelWid;
}
