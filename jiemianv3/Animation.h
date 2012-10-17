#ifndef ANIMATION_H
#define ANIMATION_H

#include <QSequentialAnimationGroup>
#include <QParallelAnimationGroup>
#include <QStateMachine>
#include <QPushButton>

QParallelAnimationGroup* MenuAnimation( QGraphicsProxyWidget *formerWidget, QGraphicsProxyWidget *aimWidget, QState *formerState, QState *aimState);
QParallelAnimationGroup* WindowAnimation(QGraphicsProxyWidget *formerWidget, QGraphicsProxyWidget *aimWidget, QState *formerState, QState *aimState);
QParallelAnimationGroup* MenuToWindowAnimation(QGraphicsProxyWidget *formerWidget, QGraphicsProxyWidget *aimWidget, QState *formerState, QState *aimState);
QParallelAnimationGroup* WindowToMenuAnimation(QGraphicsProxyWidget *formerWidget, QGraphicsProxyWidget *aimWidget, QState *formerState, QState *aimState);
QParallelAnimationGroup* ButtonAnimation(QPushButton* button[], int n);

QParallelAnimationGroup* reviewAnimation(QPushButton *pushButton, QGraphicsProxyWidget *formerWidget, QState *formerState);
#endif // ANIMATION_H
