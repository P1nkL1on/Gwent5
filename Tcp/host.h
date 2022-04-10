#ifndef HOST_H
#define HOST_H

#include <QTcpServer>

class Host : public QObject
{
    Q_OBJECT
public:
    explicit Host(QObject *parent = nullptr);
    bool addressResAndPort(QHostAddress &hostAddress, int &port) const;

signals:
    void connected();

private slots:
    void onNewConnection();
    void onReadyRead();

private:
    QTcpServer *_tcpServer = nullptr;
};

#endif // HOST_H
