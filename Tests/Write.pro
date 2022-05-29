QT += core testlib
TARGET = Tests
CONFIG += testcase

include($$PWD/../Tests/Tests.pri)

SOURCES += $$PWD/write.cpp
