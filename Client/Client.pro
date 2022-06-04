QT       += core gui widgets opengl multimedia network

TARGET = Client
TEMPLATE = app

include($$PWD/../Cards/Cards.pri)

SOURCES += \
     main.cpp \
     mainwindow.cpp \
    cardinfo.cpp

HEADERS += \
     mainwindow.h \
    cardinfo.h
