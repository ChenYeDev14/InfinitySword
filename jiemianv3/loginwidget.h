#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include "ui_loginwidget.h"

#include<QtSql/qsqldatabase.h>
#include<QtSql/qsqlerror.h>
#include<QtSql/qsqlquery.h>

namespace Ui {
class LogInWidget;
}

class QNetworkReply;
class LogInWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit LogInWidget(QWidget *parent = 0);
    ~LogInWidget();
    Ui::LogInWidget *returnUi();
    
private:
    Ui::LogInWidget *ui;
    void paintEvent(QPaintEvent *);
    QSqlDatabase db;
    QNetworkReply * reply;
    QString user_name;

private slots:
    void LogIn();
    void http_request_ready_read();

signals:
    void login_success(QString);
};

#endif // LOGINWIDGET_H
