#include "browser.h"
#include <QDebug>

Browser::Browser()
{
     setWindowIcon(QIcon(":/image/icon.png"));
     setWindowTitle(QString(tr("duishi14_browser")));

     //QAxWidget 的构建
     myAxWidget = new QAxWidget(this);
     myAxWidget->setControl(QString::fromUtf8("{8856F961-340A-11D0-A96B-00C04FD705A2}"));

     pageView = new QWebView(this);
     pageView->load(QUrl("http://duishi.eekexie.org/"));
     //pageView->load(QUrl("http://duishi.eekexie.org/"));
     pageView->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
     setCentralWidget(pageView);

     pageLine = new QLineEdit(this);
     pageLine->setText("http://duishi.eekexie.org/");
     createActions();
     createToolBars();
     createStatusBar();

     connect(pageView, SIGNAL(loadProgress(int)), this, SLOT(loading(int)));
     connect(pageLine, SIGNAL(returnPressed()), this, SLOT(loadPage()));
     connect(pageView, SIGNAL(linkClicked(const QUrl)), SLOT(loadLinkPage(const QUrl)));

 }

void Browser::createActions()
{
    backAct = new QAction(QIcon(":/image/back.png"), tr("&Back"), this);
    backAct->setShortcut(tr("Ctrl+B"));
    connect(backAct, SIGNAL(triggered()), this, SLOT(backPage()));

    forwardAct = new QAction(QIcon(":/image/forward.png"), tr("&Forward"), this);
    forwardAct->setShortcut(tr("Ctrl+F"));
    connect(forwardAct, SIGNAL(triggered()), this, SLOT(forwardPage()));

    reloadAct = new QAction(QIcon(":/image/reload.png"), tr("&Refresh"), this);
    reloadAct->setShortcut(tr("Ctrl+R"));
    connect(reloadAct, SIGNAL(triggered()), this, SLOT(reloadPage()));

    homeAct = new QAction(QIcon(":/image/icon.png"), tr("&Home"), this);
    homeAct->setShortcut(tr("Ctrl+H"));
    connect(homeAct, SIGNAL(triggered()), this, SLOT(homePage()));

}

 void Browser::createToolBars()
 {
     navigationToolBar = addToolBar(tr("Navigation"));
     navigationToolBar->addAction(backAct);
     navigationToolBar->addAction(forwardAct);
     navigationToolBar->addAction(reloadAct);
     navigationToolBar->addAction(homeAct);
     navigationToolBar->addWidget(pageLine);

 }

 void Browser::createStatusBar()
 {
     statusBar()->showMessage(tr("Ready"));
 }

 void Browser::loadPage()
 { 
     QString str = pageLine->text();
     pageView->load(QUrl(str));
 }

 void Browser::backPage()
 {
	 pageView->back();
 }

 void Browser::forwardPage()
 {
	 pageView->forward();
 }

 void Browser::reloadPage()
 {
	 pageView->reload();
 }

 void Browser::homePage()
 {
     pageView->load(QUrl("http://duishi.eekexie.org/"));
 }

 void Browser::loading(int progress)
 {
     if (progress == 100)
     {
         pageLine->setText(pageView->url().toString());
         statusBar()->showMessage(tr("Ready"));
     }
     else
     {
         QString str_pro;
         str_pro.setNum(progress);
         statusBar()->showMessage(QString("Loading... ").append(str_pro).append("% Done"));
     }
 }

 void Browser::loadLinkPage(const QUrl & url)
 {
     statusBar()->showMessage(tr("Waiting..."));
     pageView->load(url);
     QString tmp = url.toString();

     //特殊字串，使用这个
     if (tmp.contains("download/"))
        myAxWidget->dynamicCall("Navigate(const QString&)",tmp);
     statusBar()->showMessage(tr("Ready"));
 }

