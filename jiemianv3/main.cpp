#include <QApplication>
#include <QtGui>
#include <QCursor>
#include <QSplashScreen>
#include "windowsstyle.h"
#include "creator.h"

void sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}


int main(int argc, char*argv[])
{
    QApplication app(argc, argv);
    //QApplication::setLibraryPaths(QStringList << QCoreApplication::applicationDirPath()+"/plugins/");

    QApplication::addLibraryPath("./plugins");
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QApplication::setStyle(new Style);

    QCursor my(QPixmap(":/image/cursor3.png"),52,52);
    app.setOverrideCursor(my);

    QSplashScreen* splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/image/kexie.png"));
    splash->show();
    Creator create(app);
    create.show();

    splash->finish(&create);
    delete splash;


    return app.exec();
}
