#include "formdeckbuilder.h"
#include "formgame.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // FormDeckBuilder w;
    FormGame w;
    w.resize(800, 600);
    w.show();

    return a.exec();
}
