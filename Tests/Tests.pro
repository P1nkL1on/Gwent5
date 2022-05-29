QT       += core testlib

TARGET = Tests
CONFIG += testcase

include($$PWD/../Cards/Cards.pri)

SOURCES += \
     main.cpp \
     tests.cpp

HEADERS += \
     tests.h
