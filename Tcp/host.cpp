#include "host.h"

#include <QTcpSocket>
#include <QNetworkInterface>


Host::Host(QObject *parent) :
    QObject(parent)
{
    const QList<QHostAddress> hostAddresses = QNetworkInterface::allAddresses();
    if (hostAddresses.isEmpty()) {
        qCritical() << "No host addresses found";
        return;
    }

    QHostAddress hostAddressRes = QHostAddress::LocalHost;
    for (const QHostAddress &hostAddress : hostAddresses)
        if (hostAddress.toIPv4Address() && (hostAddress != QHostAddress::LocalHost))
            hostAddressRes = hostAddress;

    _tcpServer = new QTcpServer(this);

    if (!_tcpServer->listen(hostAddressRes, 0)) {
        qCritical() << "Can't start tcp server" << _tcpServer->errorString();
        delete _tcpServer;
        _tcpServer = nullptr;
        return;
    }

    connect(_tcpServer, &QTcpServer::newConnection, this, &Host::onNewConnection,
            Qt::UniqueConnection);
}

bool Host::addressResAndPort(QHostAddress &hostAddress, int &port) const
{
    if (_tcpServer == nullptr)
        return false;

    hostAddress = _tcpServer->serverAddress();
    port = _tcpServer->serverPort();
    return true;
}

void Host::onNewConnection()
{
    Q_ASSERT(_tcpServer != nullptr);

    auto *socket = _tcpServer->nextPendingConnection();

    connect(socket, &QTcpSocket::readyRead, this, &Host::onReadyRead,
            Qt::UniqueConnection);
}

void Host::onReadyRead()
{
    QObject *tcpSocket = sender();
    Q_ASSERT(tcpSocket != nullptr);
    QTcpSocket *_tcpSocket = dynamic_cast<QTcpSocket *>(tcpSocket);
    Q_ASSERT(_tcpSocket != nullptr);

    const QString socketMessage = QString::fromLatin1(_tcpSocket->readAll());

    qInfo() << "Host::onReadyRead()" << socketMessage;
}
