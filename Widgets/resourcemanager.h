#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <QImage>
#include <QObject>
#include <QtNetwork/qnetworkreply.h>

class ResourceManager : public QObject
{
    Q_OBJECT
public:
    ResourceManager(QObject *parent = nullptr);
    void requestImageByUrl(const QString &url);
    QImage imageByUrl(const QString &url);

signals:
    void imageRequestSucceed();

private slots:
    void onImageRequestFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager *_networkAccessManager = nullptr;
    QSet<QString> _pixMapsRequested;
    QMap<QString, QImage> _pixMapsLoaded;
};

#endif // RESOURCEMANAGER_H
