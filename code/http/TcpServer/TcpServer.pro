#-------------------------------------------------
#
# Project created by QtCreator 2019-01-10T15:39:49
#
#-------------------------------------------------

QT       += core gui network
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TcpServer
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui
