#-------------------------------------------------
#
# Project created by QtCreator 2014-09-03T16:57:57
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chat
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    ConnectDialog.cpp \
    Connection.cpp \
    Server.cpp

HEADERS  += MainWindow.h \
    ConnectDialog.h \
    Connection.h \
    Server.h

FORMS    += MainWindow.ui \
    ConnectDialog.ui
