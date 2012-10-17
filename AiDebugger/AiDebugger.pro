#-------------------------------------------------
#
# Project created by QtCreator 2012-09-16T07:26:58
#
#-------------------------------------------------

QT       += core gui
QT       += thread
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AiDebugger
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    ../jiemianv3/platform/NormalBattle.cpp \
    ../jiemianv3/platform/replayfile.cpp \
    ../jiemianv3/platform/Logic.cpp \
    replaydevice.cpp \
    herodisplay.cpp \
    maindevice.cpp


HEADERS  += widget.h \
    ../jiemianv3/platform/NormalBattle.h \
    ../jiemianv3/platform/Status.h \
    ../jiemianv3/platform/replayfile.h \
    replaydevice.h \
    herodisplay.h \
    maindevice.h \
    ../jiemianv3/platform/Logic.h \
    ../jiemianv3/platform/Basic.h

FORMS    += widget.ui

RESOURCES += \
    image.qrc

OTHER_FILES += \
    infinity_d.rc

RC_FILE = infinity_d.rc
