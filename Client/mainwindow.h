#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QSet>
#include <QMediaPlayer>
#include <QVariantAnimation>
#include <QMetaEnum>
#include <QTextEdit>

#include "../Cards/archieve.h"
#include "../Cards/view.h"
#include "../Client/cardinfo.h"

struct Layout
{
    int spacingPx = 30;
    int borderCardPx = 1;
    int borderTextPx = 2;
    int borderNamePx = 5;
};

class QNetworkAccessManager;
class QNetworkReply;

class FormDeckBuilder : public QMainWindow
{
    Q_OBJECT

public:
    FormDeckBuilder(QWidget *parent = nullptr);

private slots:
    void onImageRequestFinished(QNetworkReply *reply);
    void openLoadDialog();

private:
    const CardStringsAndUrls &requestInfo(const std::string &id);
    void requestImageByUrl(const std::string &url);
    void requestSoundByUrl(const std::string &url);
    bool eventFilter(QObject*, QEvent* e) override;
    void paintEvent(QPaintEvent *e) override;
    void mouseClick(const QRect &rect, const QPoint &point, Field &ally, Field &enemy);
    void paintInRect(const QRect rect, const FieldView &view);
    void repaintCustom();
    QMargins margins() const;

    Layout _layout;
    int _sound = 20;
    int _turn = 0;

    enum View
    {
        ViewStack,
        ViewHand,
        ViewDiscard,
        ViewDeck,
        ViewHandOpponent,
        ViewDeckOpponent,
        ViewDiscardOpponent,
        ViewCardsAppeared,
        ViewCardsPlayed,
        View_count
    };
    View _view = ViewStack;
    QPoint _pos;
    Field _ally;
    Field _enemy;
    FieldView _snapshot;
    std::string _lang = "en";

    QNetworkAccessManager *_networkAccessManager = nullptr;
    QSet<QString> _pixMapsRequested;
    QMap<QString, QImage> _pixMapsLoaded;
    QMap<QString, QMediaPlayer *> _sounds;
    QMap<QString, CardStringsAndUrls> _infos;
    QTextEdit *_textAlly = nullptr;
    QTextEdit *_textEnemy = nullptr;
};

#endif // MAINWINDOW_H
