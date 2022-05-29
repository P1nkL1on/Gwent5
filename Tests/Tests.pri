!GWENT_TESTS {

CONFIG += GWENT_TESTS

INCLUDEPATH *= $$clean_path($$PWD/../)

include($$PWD/../Cards/Cards.pri)

HEADERS += $$PWD/tests.h
SOURCES += $$PWD/tests.cpp

}
