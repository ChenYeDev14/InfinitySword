#include <QtGui>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "ProductionTeam.h"

ProductionTeam::ProductionTeam(QWidget *parent) :
    QWidget(parent)
{
    resize(1000,564);

    const char* pcszStr ="ÖÆ×÷ÍÅ¶Ó";
    QString s = QString::fromLocal8Bit(pcszStr);
    this->setWindowTitle(s);
    const char* pcszStr0="\n\n\n\n\n\n\n\n\n\n";
    QString s0 = QString::fromLocal8Bit(pcszStr0);
    label=new QLabel(s0);
    productionteamtiltle=new ProductionTeamTiltle;
    QPalette palette = label->palette();
    palette.setColor(QPalette::Foreground,QColor(255,0,0));
    label->setPalette(palette);
    const char* pcszStr1 = "                                                                                       \n"
                           "                                    ÖÆ       ¹Ü  Ã«  ÎÂ       ¼¼  Ëï  Ä²  ÌÆ  Íõ  ËÕ  Àè  Íõ  ×¿  ³Â  ÂÀ  ÕÔ  Ðì       Âß  ·®  Áõ  ÖÜ  º«  ÎÂ  Àî       Æ½  ³Â  ×¯  ÕÅ  ÖÜ  Áú       Íø  »Æ  ºî  ÕÅ  Àî       Íø  ¹ù  Îâ  ºú  ·½  Âí  ³£       3  Àî  Ñî  ÕÔ  Ê·  ÃÏ  Âí       ÃÀ  Îä  Íõ  Íõ  ÕÅ       ½ç  Óà  Éò  Àî  Ç®  Çñ  °×  Íõ                     \n"
                           "                                                                                       \n"
                           "                                    ×÷       Àí  Éý  ×Ó       Êõ  Ôó  Í«  Ê«  º×  Éº  ÈÙ  ÃË  ¾¸  Óê  Èô  ÖÂ  Ïé       ¼­  Ã÷  Ð¥  ¶ø  ÑÜ  Óí  Óî       Ì¨  êÊ  ³Ì  ·«  Ô¶  ˜±       Âç  ²©  Ææ  ÃÎ  Çï       Õ¾  ±Ì  Åó  ²´  Ìì  Èï  Ïò       D  ¹È  ×Ó  †´  Î°  ³¿  Çï       ¹¤  Ù»  ×Ó  ÖÇ  ÇÕ       Ãæ  Ïè  Ñå  ÁÁ  Â¡  ½£  Çì  ¹á                     \n"
                           "                                                                                       \n"
                           "                                    ÍÅ           •D  ìÏ       Ö¸  À×      ÁÁ          Îõ      ì¿  ´Ï  ³½  ³½  Ïé           Ïé  Óî  ½ø  öÁ  ºÀ  ¶¼               Ðñ                               Ôó  ³Ø           ´¨          »ª      Ã÷          äø  ÃÉ  ÐÀ  çù  «h  ÔÃ           í²  ÞÈ  »Û               Óî  Ò¢          ÌÎ  Áä  ÖÐ                     \n"
                           "                                                                                       \n"
                           "                                    ¶Ó                        µ¼                                                                                                                                                                                                                                                                                          \n"
                           "                                                                                        \n" ;
    QString s1 = QString::fromLocal8Bit(pcszStr1);
    productionteamtiltle->setText(s1);
    QFont font = label->font();
    font.setFamily("»ªÎÄÁ¥Êé");
    //font.setPointSize(20);
    label->setFont(font);
    const char* pcszStr2="\n\n\n\n\n\n\n\n\n\n";
    QString s2=QString::fromLocal8Bit(pcszStr2);
    space=new QLabel(s2);
    const char* pcszStr3="·µ»ØÖ÷½çÃæ";
    QString s3 = QString::fromLocal8Bit(pcszStr3);
    QVBoxLayout* mainlayout=new QVBoxLayout;
    QHBoxLayout* hlayout=new QHBoxLayout;
    QHBoxLayout* tlayout=new QHBoxLayout;
    hlayout->addSpacing(this->width()-100);
    tlayout->addSpacing(100);
    tlayout->addWidget(productionteamtiltle);
    tlayout->addSpacing(100);
    mainlayout->addWidget(label);
    mainlayout->addLayout(tlayout);
    mainlayout->addWidget(space);
    mainlayout->addLayout(hlayout);
    setLayout(mainlayout);
}
