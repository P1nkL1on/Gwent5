!GWENT_CARDS {

CONFIG += GWENT_CARDS

INCLUDEPATH *= $$clean_path($$PWD/../)

HEADERS += \
    $$PWD/card.h \
    $$PWD/iterator.h \
    $$PWD/archieve.h \
    $$PWD/view.h \
    $$PWD/enums.h \
    $$PWD/filters.h \
    $$PWD/demos.h \
    $$PWD/io.h

SOURCES += \
    $$PWD/card.cpp \
    $$PWD/archieve.cpp \
    $$PWD/view.cpp \
    $$PWD/demos.cpp \
    $$PWD/io.cpp

DISTFILES += \
    $$PWD/archieve.md

}
