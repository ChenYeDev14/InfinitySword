 #ifndef BROWSER_H
 #define BROWSER_H

#include <QApplication>
#include <QtGui>
#include <QtCore>
#include <QtWebKit/QWebView>
#include <QAxWidget>

class Browser :
             public QMainWindow
 {
     Q_OBJECT
 public:
     Browser();

 private slots:
     void loadLinkPage(const QUrl & url);
     void loadPage();
	 void backPage();
	 void forwardPage();
	 void reloadPage();
     void homePage();
     void loading(int progress);

 private:
     void createActions();
   
     void createToolBars();
     void createStatusBar();
    
     QToolBar *navigationToolBar;
	 QAction *backAct;
	 QAction *forwardAct;
	 QAction *reloadAct;
     QAction *homeAct;
	 QWebView *pageView;
	 QLineEdit *pageLine;
     QAxWidget *myAxWidget;

     
 };

 #endif
