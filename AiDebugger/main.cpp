#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    //QApplication::setLibraryPaths(QStringList(QCoreApplication::applicationDirPath()+"/plugins/"));
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf8"));
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
