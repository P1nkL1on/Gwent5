#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <string>
#include <vector>

#include <QImage>
#include <QObject>
#include <QtNetwork/qnetworkreply.h>
#include <QString>

#include "Cards/enums.h"


struct CardStringsAndUrls
{
    std::string lang;

    std::string name;
    std::string text;
    std::string flavor;
    std::vector<std::string> textSounds;

    std::string urlImageLow;
    std::string urlImageMedium;
    std::string urlVideo;
    std::vector<std::string> urlSounds;
};


struct IdAndLang
{
    std::string id;
    std::string lang;
    static QString toUrl(const std::string &id, const std::string &lang);
    static IdAndLang fromUrl(const QString &toUrl);
};


QString urlCardRequest(const IdAndLang &idAndLang);
CardStringsAndUrls parseCardReply(const QString &stringReply, const std::string &id, const std::string &lang);



class ResourceManager : public QObject
{
    Q_OBJECT
public:
    /// lang works w/ [en, ru, pl, de, fr, es, mx, it, jp, pt, cn, kr]
    ResourceManager(const std::string &lang = "en", QObject *parent = nullptr);
    void requestImageByUrl(const QString &url);
    void requestCardStringsAndUrls(const std::string &id);
    bool hasUrl(const QString &url) const;
    QImage imageByUrl(const QString &url) const;
    CardStringsAndUrls cardStringsAndUrls(const std::string &id) const;
    std::string cardName(const std::string &id) const;
    int nRequests() const;
    int nReplies() const;

signals:
    void imageRequestSucceed();
    void cardRequestSucceed();

private slots:
    void onRequestFinished(QNetworkReply *reply);

private:
    std::string _lang;
    QNetworkAccessManager *_networkAccessManager = nullptr;
    QSet<QString> _urlRequests;
    QMap<QString, QImage> _pixMapsLoaded;
    QMap<std::string, CardStringsAndUrls> _cardStringsAndUrlsLoaded;
};


#endif // RESOURCEMANAGER_H
