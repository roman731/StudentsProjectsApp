#-------------------------------------------------
#
# Project created by QtCreator 2015-10-27T17:30:33
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = app
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    adminmenu.cpp \
    studentmenu.cpp \
    viewprojectsmenu.cpp \
    databaseclass.cpp

HEADERS  += mainwindow.h \
    adminmenu.h \
    studentmenu.h \
    viewprojectsmenu.h \
    databaseclass.h

FORMS    += mainwindow.ui \
    adminmenu.ui \
    studentmenu.ui \
    viewprojectsmenu.ui
