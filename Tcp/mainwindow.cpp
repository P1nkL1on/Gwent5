#include "mainwindow.h"

#include <QEventLoop>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto *formLayout = new QFormLayout;

    auto *buttonStartHost = new QPushButton("Start");
    auto *buttonCloseHost = new QPushButton("Close");
    auto *buttonMessageHost = new QPushButton("Send Message");
    auto *buttonConnectClient = new QPushButton("Connect");
    auto *buttonCloseClient = new QPushButton("Close");
    auto *buttonMessageClient = new QPushButton("Send Message");
    auto *labelAddress = new QLabel;
    auto *labelPort = new QLabel;

    formLayout->addRow("Host", buttonStartHost);
    formLayout->addRow("", buttonCloseHost);
    formLayout->addRow("", buttonMessageHost);
    formLayout->addRow("Address", labelAddress);
    formLayout->addRow("Port", labelPort);
    formLayout->addRow("Client", buttonConnectClient);
    formLayout->addRow("", buttonCloseClient);
    formLayout->addRow("", buttonMessageClient);

    auto *centralWidget = new QWidget;
    centralWidget->setLayout(formLayout);

    setCentralWidget(centralWidget);

    buttonCloseHost->setEnabled(false);
    buttonMessageHost->setEnabled(false);
    buttonCloseClient->setEnabled(false);
    buttonMessageClient->setEnabled(false);

    _client = new Client();

    connect(buttonStartHost, &QPushButton::clicked, this, [=]{
        Q_ASSERT(_host == nullptr);
        _host = new Host;
        buttonStartHost->setEnabled(false);
        QHostAddress address;
        quint16 port;
        if (!_host->addressResAndPort(address, port)) {
            buttonStartHost->setEnabled(true);
            delete _host;
            _host = nullptr;
            return;
        }

        labelAddress->setText(address.toString());
        labelPort->setText(QString::number(port));
        buttonCloseHost->setEnabled(true);
        buttonConnectClient->setEnabled(true);
        connect(_host, &Host::clientConnected, this, [=]{
            buttonMessageHost->setEnabled(true);
        });
    });

    connect(buttonConnectClient, &QPushButton::clicked, this, [=]{
        if (_host == nullptr) {
            qWarning() << "No server";
            return;
        }
        buttonConnectClient->setEnabled(false);
        QHostAddress address;
        quint16 port;
        const bool isOk = _host->addressResAndPort(address, port);
        Q_ASSERT(isOk);
        if (!_client->connectTo(address, port)) {
            buttonConnectClient->setEnabled(true);
            return;
        }

        buttonCloseClient->setEnabled(true);
        buttonMessageClient->setEnabled(true);
    });

    connect(buttonMessageHost, &QPushButton::clicked, this, [=]{
        _host->sendMessage("Host sends a message!");
    });

    connect(buttonMessageClient, &QPushButton::clicked, this, [=]{
        _client->sendMessage("Client sends a message!");
    });
}
