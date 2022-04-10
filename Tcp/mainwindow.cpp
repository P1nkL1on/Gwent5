#include "mainwindow.h"

#include <QEventLoop>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    _host = new Host();

    QHostAddress hostAddress;
    quint16 port;

    if (!_host->addressResAndPort(hostAddress, port))
        return;

    qInfo() << "TCP Server started" << hostAddress << port;

    _client = new Client();
    if (!_client->connectTo(hostAddress, port))
        return;

    qInfo() << "TCP Client connected";

    QEventLoop loop;
    connect(_host, &Host::connected, &loop, &QEventLoop::quit);
    loop.exec(QEventLoop::ExcludeUserInputEvents);

    _client->sendMessage("Hello, its a client!");
    _host->sendMessage("Hello, its a host!");
}
