#-------------------------------------------------
#
# Project created by QtCreator 2016-03-15T21:33:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HCalc
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    calculator.cpp

HEADERS  += mainwindow.h \
    calculator.h \
    isnumeric.h \
    chartostring.h

FORMS    += mainwindow.ui
