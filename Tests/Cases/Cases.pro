QT -= gui

CONFIG += c++11
CONFIG -= app_bundle console
QMAKE_CXXFLAGS += -Wno-padded

include($$PWD/../../Cards/Cards.pri)

SOURCES += \
    main.cpp \
    tests.cpp

HEADERS += \
    tests.h
