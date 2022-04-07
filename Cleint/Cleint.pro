QT       += core gui widgets opengl

TARGET = Cleint
TEMPLATE = app

include($$PWD/../Cards/Cards.pri)

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

RESOURCES += \
    covers.qrc
