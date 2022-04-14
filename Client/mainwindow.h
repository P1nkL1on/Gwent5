#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QSet>
#include <QMediaPlayer>
#include <QVariantAnimation>

#include "../Cards/archieve.h"

struct Layout
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
    void requestImageByUrl(const std::string &url);
    void requestSoundByUrl(const std::string &url);
    bool eventFilter(QObject*, QEvent* e) override;
    void paintEvent(QPaintEvent *e) override;
    void mouseClick(const QRect &rect, const QPoint &point, Field &ally, Field &enemy);
    void paintInRect(const QRect rect, Field &ally, Field &enemy);

    Layout _layout;
    int _sound = 20;

    enum View { ViewStack, ViewHand, ViewDiscard, ViewDeck, View_count };
    View _view = ViewStack;
    QPoint _pos;
    Field _ally ;
    Field _enemy;

    QNetworkAccessManager *_networkAccessManager = nullptr;
    QSet<QString> _pixMapsRequested;
    QMap<QString, QImage> _pixMapsLoaded;
    QMap<QString, QMediaPlayer *> _sounds;
//    QVariantAnimation *_variantAnimation = nullptr;
};

#endif // MAINWINDOW_H
