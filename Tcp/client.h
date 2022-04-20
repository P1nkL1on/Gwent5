#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QHostAddress>

class QTcpServer;
class QTcpSocket;

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);
    ~Client() override;
    /// try connect, wait in main thread, return if success
    bool connectTo(const QHostAddress &hostAddress, const quint16 port);
    /// if connected try disconnect, wait in main thread, return if success
    bool disconnectFromHost();
    void sendMessage(const QString &string);

signals:
    void message(const QString &string);

private slots:
    void onReadyRead();

private:
    QTcpSocket *_tcpSocket = nullptr;
    int _msTimeout = 5000;
};

#endif // CLIENT_H
