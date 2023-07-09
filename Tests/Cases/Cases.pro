QT -= gui

CONFIG += c++11
CONFIG -= app_bundle console
QMAKE_CXXFLAGS += -Wno-padded

include($$PWD/../../Cards/Cards.pri)

DEFINES += QT_TESTS
SOURCES += $$PWD/test_*.cpp $$PWD/main.cpp
HEADERS += $$PWD/test_*.h
