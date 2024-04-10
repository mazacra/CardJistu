SOURCES = main.cpp menuWindow.cpp winWidget.cpp
HEADERS = menuWindow.h winWidget.h
INCLUDEPATH += src
DESTDIR = ./build
QT += widgets
LANGUAGE = C++

TEMPLATE = vcapp
TARGET = cardJistuGUI
CONFIG += warn_on qt debug windows console