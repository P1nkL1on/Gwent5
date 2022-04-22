#include "resourcemanager.h"

#include <qpixmap.h>

ResourceManager::ResourceManager(QObject *parent) :
    QObject(parent)
{
    _networkAccessManager = new QNetworkAccessManager(this);
    connect(_networkAccessManager, &QNetworkAccessManager::finished, this, &ResourceManager::onImageRequestFinished);
}

void ResourceManager::requestImageByUrl(const QString &url)
{
    if (url.size() == 0)
        return;

    if (_pixMapsLoaded.contains(url))
        return;

    if (_pixMapsRequested.contains(url))
        return;

    QUrl qUrl(url);
    QNetworkRequest request(qUrl);
    _pixMapsRequested.insert(url);
    _networkAccessManager->get(request);
}

QImage ResourceManager::imageByUrl(const QString &url)
{
    return _pixMapsLoaded.value(url, QImage());
}

void ResourceManager::onImageRequestFinished(QNetworkReply *reply)
{
    const QString urlString = reply->url().toString();
    if (reply->error() != QNetworkReply::NoError) {
        _pixMapsLoaded.insert(urlString, QImage());
        return;
    }

    if (urlString.endsWith(".png") || urlString.endsWith(".jpg") || urlString.endsWith(".jpeg")) {
        QByteArray pngData = reply->readAll();
        QPixmap pixmap;
        pixmap.loadFromData(pngData);
        _pixMapsLoaded.insert(urlString, pixmap.toImage());
        emit imageRequestSucceed();

    } else {
        Q_ASSERT(false);
    }
}
