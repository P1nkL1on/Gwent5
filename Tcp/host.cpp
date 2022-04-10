#include "host.h"

#include <QTcpSocket>
#include <QTcpServer>
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

Host::~Host()
{
    if (_tcpServer != nullptr)
        delete _tcpServer;

    if (_tcpSocket != nullptr)
        delete _tcpSocket;
}

bool Host::addressResAndPort(QHostAddress &hostAddress, quint16 &port) const
{
    if (_tcpServer == nullptr)
        return false;

    hostAddress = _tcpServer->serverAddress();
    port = _tcpServer->serverPort();
    return true;
}

void Host::sendMessage(const QString &string)
{
    Q_ASSERT(_tcpSocket != nullptr);

    _tcpSocket->write(string.toLatin1());
}

void Host::onNewConnection()
{
    Q_ASSERT(_tcpServer != nullptr);
    Q_ASSERT(_tcpSocket == nullptr);

    _tcpSocket = _tcpServer->nextPendingConnection();

    connect(_tcpSocket, &QTcpSocket::readyRead, this, &Host::onReadyRead,
            Qt::UniqueConnection);
    emit connected();
}

void Host::onReadyRead()
{
    Q_ASSERT(_tcpSocket != nullptr);

    const QString socketMessage = QString::fromLatin1(_tcpSocket->readAll());
    qInfo() << "Host::onReadyRead()" << socketMessage;
    emit message(socketMessage);
}
