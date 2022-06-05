#include "mainwindow.h"
#include <QApplication>

#include "cardinfo.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    const bool isOk = requestCardInfo("200164", "ru");
    qDebug() << isOk;
    return 0;

    MainWindow w;
    w.show();

    return a.exec();
}
