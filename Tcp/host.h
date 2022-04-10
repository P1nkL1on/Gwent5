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
    explicit Host(QObject *parent = nullptr);
    ~Host() override;
    bool addressResAndPort(QHostAddress &hostAddress, quint16 &port) const;
    void sendMessage(const QString &string);

signals:
    void connected();
    void message(const QString &string);

private slots:
    void onNewConnection();
    void onReadyRead();

private:
    QTcpServer *_tcpServer = nullptr;
    QTcpSocket *_tcpSocket = nullptr;
};

#endif // HOST_H
