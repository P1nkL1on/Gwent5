#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QSet>

#include "../Cards/cards.h"

struct View
{
    int spacingPx = 30;
    int borderCardPx = 1;
    int borderTextPx = 2;
    int borderNamePx = 5;
};

class QNetworkAccessManager;
class QNetworkReply;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void onImageRequestFinished(QNetworkReply *reply);

private:
    bool eventFilter(QObject*, QEvent* e) override;
    void paintEvent(QPaintEvent *e) override;
    void requestImageByUrl(const std::string &url);

    View _view;

    Field _ally ;
    Field _enemy;

    QNetworkAccessManager *_networkAccessManager = nullptr;
    QSet<QString> _pixMapsRequested;
    QMap<QString, QImage> _pixMapsLoaded;
};

#endif // MAINWINDOW_H
