TEMPLATE = app
CONFIG += console
QMAKE_CXXFLAGS += -std=c++11
QT += core gui widgets

SOURCES += main.cpp \
    maze.cpp \
    mazemapper.cpp \
    window.cpp \
    box.cpp \
    gobject.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    maze.h \
    mazemapper.h \
    window.h \
    box.h \
    gobject.h

