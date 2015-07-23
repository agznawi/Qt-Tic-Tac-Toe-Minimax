#-------------------------------------------------
#
# Project created by QtCreator 2015-07-15T13:53:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TicTacToe
TEMPLATE = app


SOURCES += main.cpp\
        game.cpp \
    ai.cpp \
    board.cpp

HEADERS  += game.h \
    ai.h \
    board.h \
    globals.h

RESOURCES += \
    resource.qrc
