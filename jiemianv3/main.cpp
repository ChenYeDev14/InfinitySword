#include <QApplication>
#include <QtGui>
#include <QCursor>
#include <QSplashScreen>
#include "windowsstyle.h"
#include "creator.h"
#include <QFont>

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

    QApplication::setStyle(new Style);
    //设置字体
    QFont font = app.font();
    font.setBold(true);
    font.setLetterSpacing(QFont::PercentageSpacing, 115);
    app.setFont(font);
    //设置颜色
    QPalette palette = app.palette();
    palette.setBrush(QPalette::Active,QPalette::ButtonText, QColor(255, 255, 255));
    palette.setBrush(QPalette::Disabled,QPalette::ButtonText,QColor(0,0,0));
    palette.setBrush(QPalette::Inactive,QPalette::ButtonText,QColor(255,255,255));
    app.setPalette(palette);

    QApplication::addLibraryPath("./plugins");
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());



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
