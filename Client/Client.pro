QT       += core gui widgets opengl multimedia network

TARGET = Client
TEMPLATE = app

include($$PWD/../Cards/Cards.pri)

SOURCES += \
     $$PWD/main.cpp \
     $$PWD/mainwindow.cpp

HEADERS += \
     $$PWD/mainwindow.h
