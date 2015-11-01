#-------------------------------------------------
#
# Project created by QtCreator 2015-08-06T18:27:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CaptureImageFrame
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    Mat2QImage.h \
    OpenCVFilter.h

FORMS    += mainwindow.ui
PKGCONFIG += opencv
CONFIG += link_pkgconfig
