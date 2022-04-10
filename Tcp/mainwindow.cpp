#include "mainwindow.h"

#include "host.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto *host = new Host();

    QHostAddress hostAddress;
    int port;

    if (host->addressResAndPort(hostAddress, port)) {
        qInfo() << hostAddress << port;
    } else {
        qCritical() << "Failed to start";
    }
}

MainWindow::~MainWindow()
{

}
