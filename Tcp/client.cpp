#include "client.h"

#include <QTcpSocket>
#include <QTcpServer>
#include <QEventLoop>

Client::Client(QObject *parent) :
    QObject(parent)
{
}

Client::~Client()
{
    if (_tcpSocket != nullptr)
        delete _tcpSocket;
}

bool Client::connectTo(const QHostAddress &hostAddress, const quint16 port)
{
    Q_ASSERT(_tcpSocket == nullptr);

    _tcpSocket = new QTcpSocket(this);
    _tcpSocket->abort();
    _tcpSocket->connectToHost(hostAddress.toString(), port);
    if (!_tcpSocket->waitForConnected(_msTimeout)) {
        delete _tcpSocket;
        _tcpSocket = nullptr;
        qCritical() << "Can't connect tcp client" << _tcpSocket->errorString();
        return false;
    }

    connect(_tcpSocket, &QAbstractSocket::readyRead, this, &Client::onReadyRead, Qt::UniqueConnection);
    return true;
}

bool Client::disconnectFromHost()
{
    Q_ASSERT(_tcpSocket != nullptr);

    _tcpSocket->disconnectFromHost();
    if (_tcpSocket->state() != QTcpSocket::UnconnectedState && !_tcpSocket->waitForDisconnected(_msTimeout)) {
        return false;
    }

    delete _tcpSocket;
    _tcpSocket = nullptr;
    return true;
}

void Client::sendMessage(const QString &string)
{
    Q_ASSERT(_tcpSocket != nullptr);

    _tcpSocket->write(string.toLatin1());
}

void Client::onReadyRead()
{
    Q_ASSERT(_tcpSocket != nullptr);

    const QString socketMessage = QString::fromLatin1(_tcpSocket->readAll());
    qInfo() << "Client::onReadyRead()" << socketMessage;
    emit message(socketMessage);
}

