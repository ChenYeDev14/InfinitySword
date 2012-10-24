#include "loginwidget.h"
#include "ui_loginwidget.h"
#include <QPainter>
#include <QPalette>
#include <QMessageBox>

#include <QUrl>
#include <QCryptographicHash>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

LogInWidget::LogInWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogInWidget)
{
    ui->setupUi(this);
    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::white);
    ui->label->setPalette(pe);
    ui->label_2->setPalette(pe);
    connect(ui->pushButton_login,SIGNAL(clicked()),this,SLOT(LogIn()));
}

LogInWidget::~LogInWidget()
{
    delete ui;
}


void LogInWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,1024,768,QPixmap(":/image/logIn.png"));
}

Ui::LogInWidget* LogInWidget::returnUi()
{
    return ui;
}


void LogInWidget::LogIn()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("166.111.223.20");
    db.setDatabaseName("team14");
    db.setUserName("team14");
    db.setPassword("duishi14_2012");
    QString id;
    user_name = ui->lineEdit_user->text();
    if (db.open())
    {
        QUrl email;
        email.setPath(user_name);
        char *c = email.encodedPath().data();
        std::string s_email(c);

        ui->pushButton_login->setEnabled(false);

        //转换sha1
        QByteArray data=ui->lineEdit_code->text().toAscii();
        QCryptographicHash *hash=new QCryptographicHash(QCryptographicHash::Sha1);
        hash->addData(data);
        QByteArray sha1=hash->result();
        c = sha1.toHex().data();
        std::string string_sha1(c);
        //创建一个请求
        QNetworkRequest request;
        QString url = "http://duishi.eekexie.org/index.php/management/login_query?email="
                +QString::fromStdString(s_email)+"&pwd=";
        url += QString::fromStdString(string_sha1);
        request.setUrl(QUrl(url));
        //创建一个管理器
        QNetworkAccessManager *manager = new QNetworkAccessManager(this);
        //发送GET请求
        reply = manager->get(request);
        connect(reply, SIGNAL(readyRead()), this, SLOT(http_request_ready_read()));
        db.close();


    }
    else
    {
        QMessageBox box;
        box.setWindowTitle(tr("错误！"));
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("连接服务器失败！请检查网络连接"));
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
        return;
    }
}

void LogInWidget::http_request_ready_read()
{
    //emit login_success(user_name);
    //ui->pushButton_login->setEnabled(true);
    //return;

    char result;
    reply->read(&result, sizeof(char));
    if (result == '1')
    {
        emit login_success(user_name);
    }
    else
    {
        QMessageBox box;
        box.setWindowTitle(tr("错误！"));
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("密码或邮箱输入错误！"));
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
    }
    ui->pushButton_login->setEnabled(true);
}
