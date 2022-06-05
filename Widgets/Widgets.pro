QT       += core gui widgets opengl network

TARGET = Widgets
TEMPLATE = app

include($$PWD/../Cards/Cards.pri)

SOURCES += \
    main.cpp \
    resourcemanager.cpp \
    cardslineview.cpp \
    cardspainting.cpp \
    cardsingleview.cpp \
    cardsfieldview.cpp \
    formdeckbuilder.cpp \
    formgame.cpp

HEADERS += \
    resourcemanager.h \
    cardslineview.h \
    cardspainting.h \
    cardsingleview.h \
    cardsfieldview.h \
    formdeckbuilder.h \
    formgame.h
