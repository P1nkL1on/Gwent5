!GWENT_CARDS {

CONFIG += GWENT_CARDS

INCLUDEPATH *= $$clean_path($$PWD/../)

HEADERS += \
    $$PWD/card.h \
    $$PWD/iterator.h \
    $$PWD/archieve.h

SOURCES += \
    $$PWD/card.cpp \
    $$PWD/archieve.cpp
}
