#-------------------------------------------------
#
# Project created by QtCreator 2019-04-12T16:52:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HCalc
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    math/infixtopostfix.cpp \
    math/operator.cpp \
    math/operators.cpp \
    math/test.cpp \
    math/testharness.cpp \
    math/token.cpp \
    math/tokens.cpp \
    math/calculator.cpp \
    math/stringtypehelper.cpp \
    math/popstfixevaluator.cpp

HEADERS += \
        mainwindow.h \
    math/infixtopostfix.h \
    math/operator.h \
    math/operators.h \
    math/test.h \
    math/testharness.h \
    math/token.h \
    math/tokens.h \
    math/calculator.h \
    math/instruction.h \
    math/stringtypehelper.h \
    math/exceptions.h \
    math/postfixevaluator.h

FORMS += \
        mainwindow.ui

DISTFILES += \
    .gitignore \
    README
