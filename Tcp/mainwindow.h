#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "host.h"
#include "client.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    Host *_host = nullptr;
    Client *_client = nullptr;
};

#endif // MAINWINDOW_H
