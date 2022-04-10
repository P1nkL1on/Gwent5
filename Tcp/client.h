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
    bool connectTo(const QHostAddress &hostAddress, const quint16 port);
    void sendMessage(const QString &string);

signals:
    void message(const QString &string);

private slots:
    void onReadyRead();

private:
    QTcpSocket *_tcpSocket = nullptr;
};

#endif // CLIENT_H
