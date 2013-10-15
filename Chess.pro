#-------------------------------------------------
#
# Project created by QtCreator 2012-05-19T21:32:15
#
#-------------------------------------------------

QT       += core gui

TARGET = Chess
TEMPLATE = app


SOURCES += main.cpp\
        gamewindow.cpp \
    dialog.cpp \
    Board.cpp \
    Bishop.cpp \
    Knight.cpp \
    Rook.cpp \
    Queen.cpp \
    King.cpp \
    Pawn.cpp \
    Figure.cpp \
    Chess.cpp



HEADERS  += gamewindow.h \
    Rook.h \
    Queen.h \
    Pawn.h \
    Knight.h \
    King.h \
    Figure.h \
    Chess.h \
    Board.h \
    Bishop.h \
    dialog.h

FORMS    += gamewindow.ui

RESOURCES +=
