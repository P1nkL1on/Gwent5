QT       += core gui widgets opengl network

TARGET = Widgets
TEMPLATE = app

include($$PWD/../Cards/Cards.pri)

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    resourcemanager.cpp \
    cardslineview.cpp \
    cardspainting.cpp

HEADERS += \
    mainwindow.h \
    resourcemanager.h \
    cardslineview.h \
    cardspainting.h
