#ifndef HOST_H
#define HOST_H

#include <QObject>
#include <QHostAddress>

class QTcpServer;
class QTcpSocket;

class Host : public QObject
{
    Q_OBJECT
public:
    /// try start, wait in main thread
    explicit Host(QObject *parent = nullptr);
    ~Host() override;
    bool addressResAndPort(QHostAddress &hostAddress, quint16 &port) const;
    void sendMessage(const QString &string);

signals:
    void clientConnected();
    void message(const QString &string);

private slots:
    void onNewConnection();
    void onReadyRead();

private:
    QTcpServer *_tcpServer = nullptr;
    QTcpSocket *_tcpSocket = nullptr;
};

#endif // HOST_H
