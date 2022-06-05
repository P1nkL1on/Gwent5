#include "resourcemanager.h"

#include <qpixmap.h>

#include <QRegularExpression>

ResourceManager::ResourceManager(const std::string &lang, QObject *parent) :
    QObject(parent),
    _lang(lang)
{
    _networkAccessManager = new QNetworkAccessManager(this);
    connect(_networkAccessManager, &QNetworkAccessManager::finished, this, &ResourceManager::onRequestFinished);
}

void ResourceManager::requestImageByUrl(const QString &url)
{
    if (url.size() == 0)
        return;

    if (_pixMapsLoaded.contains(url))
        return;

    if (_urlRequests.contains(url))
        return;

    const QUrl qUrl(url);
    const QNetworkRequest request(qUrl);
    _urlRequests.insert(url);
    _networkAccessManager->get(request);
}

void ResourceManager::requestCardStringsAndUrls(const std::string &id)
{
    if (id.size() == 0)
        return;

    const QString url = IdAndLang::toUrl(id, _lang);

    if (_pixMapsLoaded.contains(url))
        return;

    if (_urlRequests.contains(url))
        return;

    const QUrl qUrl(url);
    const QNetworkRequest request(qUrl);
    _urlRequests.insert(url);
    _networkAccessManager->get(request);
}

bool ResourceManager::hasUrl(const QString &url) const
{
    return _pixMapsLoaded.contains(url);
}

QImage ResourceManager::imageByUrl(const QString &url) const
{
    return _pixMapsLoaded.value(url, QImage());
}

CardStringsAndUrls ResourceManager::cardStringsAndUrls(const std::string &id) const
{
    return _cardStringsAndUrlsLoaded.value(id, CardStringsAndUrls());
}

std::string ResourceManager::cardName(const std::string &id) const
{
    return _cardStringsAndUrlsLoaded.value(id, CardStringsAndUrls()).name;
}

int ResourceManager::nRequests() const
{
    return _urlRequests.size();
}

int ResourceManager::nReplies() const
{
    return _pixMapsLoaded.size() + _cardStringsAndUrlsLoaded.size();
}

void ResourceManager::onRequestFinished(QNetworkReply *reply)
{
    const QString urlString = reply->url().toString();
    if (reply->error() != QNetworkReply::NoError) {
        _pixMapsLoaded.insert(urlString, QImage());
        return;
    }

    if (urlString.contains("/beta/")) {
        /// card strings and urls loaded
        const IdAndLang idAndLang = IdAndLang::fromUrl(urlString);
        const CardStringsAndUrls cardStringsAndUrls = parseCardReply(reply->readAll(), idAndLang.id, idAndLang.lang);
        _cardStringsAndUrlsLoaded.insert(idAndLang.id, cardStringsAndUrls);
        emit cardRequestSucceed();

    } else if (urlString.endsWith(".png") || urlString.endsWith(".jpg") || urlString.endsWith(".jpeg")) {
        /// card image loaded
        QByteArray pngData = reply->readAll();
        QPixmap pixmap;
        pixmap.loadFromData(pngData);
        _pixMapsLoaded.insert(urlString, pixmap.toImage());
        emit imageRequestSucceed();

    } else {
        Q_ASSERT(false);
    }
}

CardStringsAndUrls parseCardReply(const QString &stringReply, const std::string &id, const std::string &lang)
{
    CardStringsAndUrls res;

    QRegularExpression regex;
    const auto matchAll = [&] {
        std::vector<std::string> matchs;
        QRegularExpressionMatchIterator i = regex.globalMatch(stringReply);
        while (i.hasNext()) {
            const QRegularExpressionMatch match = i.next();
            if (match.hasMatch()) {
                const QString str = match.captured(0).trimmed();
                matchs.push_back(str.toStdString());
            }
        }
        return matchs;
    };

    // TODO: check if exit w/ no captures
    regex.setPatternOptions(QRegularExpression::InvertedGreedinessOption | QRegularExpression::DotMatchesEverythingOption);
    regex.setPattern("(?<=<div class=\"gscard__title\">)(?<name>.*)(</div>\\r)");
    res.name = regex.match(stringReply).captured("name").toStdString();

    regex.setPattern("(?<=<div class=\"gscard__ability\">)(?<text>.*)(</div> \\r)");
    res.text = regex.match(stringReply).captured("text").remove(QRegExp("<[^>]*>")).toStdString();

    regex.setPattern("(?<=<div class=\"gscard__flavor\">)(?<flavor>.*)(</div>\\r)");
    res.flavor = regex.match(stringReply).captured("flavor").toStdString();

    regex.setPattern("(?<=play_circle_outline<\\/i>).*(?=<)");
    res.textSounds = matchAll();

    regex.setPattern("(?<=src=\").*\\.mp3(?=\"><\\/audio>)");
    res.urlSounds = matchAll();

    res.urlImageLow =    "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    res.urlImageMedium = "https://gwent.one/image/card/medium/cid/png/" + id + ".png";
    res.urlVideo =       "https://gwent.one/video/card/loop/ob/" + id + ".mp4";
    res.lang = lang;

    return res;
}

QString IdAndLang::toUrl(const std::string &id, const std::string &lang)
{
    return QString::fromStdString("https://gwent.one/" + lang + "/beta/card/" + id);
}

IdAndLang IdAndLang::fromUrl(const QString &url)
{
    const QStringList parts = url.split("/", QString::SkipEmptyParts);

    IdAndLang res;
    res.lang = parts[2].toStdString();
    res.id = parts[5].toStdString();
    return res;
}
