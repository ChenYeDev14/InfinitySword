QT      += core network
QT      += thread
QT      += phonon
QT       += webkit
CONFIG += qaxcontainer

OTHER_FILES += \
    jiemianv3.pro.user \
    jiemianv3.pro \
    infinity.rc

HEADERS += \
    widgetssingle.h \
    rounditem.h \
    creator.h \
    clickbottum.h \
    beginbottum.h \
    backwidget.h \
    aivsai.h \
    replaywindow.h \
    teammenu.h \
    productionteam.h \
    productionteamtitle.h \
    windowsstyle.h \
    Animation.h \
    platform/Status.h \
    platform/replayfile.h \
    platform/NormalBattle.h \
    platform/Logic.h \
    browser.h \
    mapeditor.h \
    platform/Basic.h

SOURCES += \
    widgetssingle.cpp \
    rounditem.cpp \
    main.cpp \
    creator.cpp \
    clickbottum.cpp \
    beginbottum.cpp \
    backwidget.cpp \
    aivsai.cpp \
    replaywindow.cpp \
    teammenu.cpp \
    productionteam.cpp \
    productionteamtitle.cpp \
    windowsstyle.cpp \
    Animation.cpp \
    platform/replayfile.cpp \
    platform/NormalBattle.cpp \
    platform/Logic.cpp \
    browser.cpp \
    mapeditor.cpp

FORMS += \
    widgetssingle.ui \
    clickbottum.ui \
    beginbottum.ui \
    backwidget.ui \
    aivsai.ui \
    replaywindow.ui \
    teammenu.ui \
    mapeditor.ui

RESOURCES += \
    image.qrc

RC_FILE = infinity.rc
