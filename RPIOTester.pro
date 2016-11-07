#-------------------------------------------------
#
# Project created by QtCreator 2016-11-05T15:14:05
#
#-------------------------------------------------

QT       += core gui serialport
CONFIG += cxx11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RPIOTester
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
