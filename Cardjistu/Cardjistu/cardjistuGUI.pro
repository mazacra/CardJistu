SOURCES = main.cpp menuWindow.cpp gameWindow.cpp
HEADERS = menuWindow.h gameWindow.h
INCLUDEPATH += src
DESTDIR = ./build
QT += widgets
LANGUAGE = C++

TEMPLATE = vcapp
TARGET = cardJistuGUI
CONFIG += warn_on qt debug windows console