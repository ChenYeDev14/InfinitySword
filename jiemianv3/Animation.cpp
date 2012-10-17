#include "Animation.h"
#include <QtGui>

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
    DisWidget->setDuration(1000);
    DisWidget->setKeyValueAt(1,0);
    DisWidget->setEasingCurve(QEasingCurve::InOutQuad);

    QPropertyAnimation *AppWidget = new QPropertyAnimation(aimWidget->widget(), "windowOpacity");
    AppWidget->setDuration(1000);
    AppWidget->setKeyValueAt(1,1);
    AppWidget->setEasingCurve(QEasingCurve::InOutQuad);

    QParallelAnimationGroup* parallelWid = new QParallelAnimationGroup();
    parallelWid->addAnimation(DisWidget);
    parallelWid->addAnimation(AppWidget);

    return parallelWid;
}

QParallelAnimationGroup* ButtonAnimation(QPushButton* button[], int n)
{
    QPropertyAnimation *but[n];
    QParallelAnimationGroup *group = new QParallelAnimationGroup;
    for (int i=0; i<n; i++)
    {
        but[i]=new QPropertyAnimation(button[i], "pos");
        but[i]->setDuration(750 + i * 50);
        but[i]->setKeyValueAt(1,QPointF(-cos(((i-4.5) / 25.0) * 6.28) * 240+700,
                                        sin(((i-4.5) / 25.0) * 6.28) * 240+240));
        but[i]->setEasingCurve(QEasingCurve::InOutBack);

        group->addAnimation(but[i]);
    }

    return group;
}

QParallelAnimationGroup* reviewAnimation(QPushButton *pushButton, QGraphicsProxyWidget *formerWidget, QState *formerState)
{
    formerState->assignProperty(formerWidget->widget(), "windowOpacity", 1);

    int y = formerWidget->widget()->y();

    QPropertyAnimation *DisWidget = new QPropertyAnimation(formerWidget->widget(), "windowOpacity");
    DisWidget->setDuration(500);
    DisWidget->setKeyValueAt(1,0);
    DisWidget->setEasingCurve(QEasingCurve::InOutQuad);

    QPropertyAnimation *fPingWidget = new QPropertyAnimation(formerWidget, "y");
    fPingWidget->setDuration(500);
    fPingWidget->setKeyValueAt(0.9999,y-300);
    fPingWidget->setKeyValueAt(1,y);
    fPingWidget->setEasingCurve(QEasingCurve::InOutQuad);

    QParallelAnimationGroup* parallelWid = new QParallelAnimationGroup();
    parallelWid->addAnimation(DisWidget);
    parallelWid->addAnimation(fPingWidget);

    return parallelWid;
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
