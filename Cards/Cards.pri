!GWENT_CARDS {

CONFIG += GWENT_CARDS

INCLUDEPATH *= $$clean_path($$PWD/../)

HEADERS += \
    $$PWD/card.h \
    $$PWD/cards.h \
    $$PWD/iterator.h

SOURCES += \
    $$PWD/card.cpp
}

