#include "cardinfo.h"

#include <QApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>


bool requestCardInfo(const std::string &id, const std::string &lang)
{
    const QString url = QString::fromStdString("https://gwent.one/" + lang + "/beta/card/" + id);
    const QUrl qUrl(url);
    const QNetworkRequest request(qUrl);
    QNetworkAccessManager manager;
    QNetworkReply *reply = manager.get(request);

    // TODO: change loading waiter
    QEventLoop l;
    QObject::connect(&manager, &QNetworkAccessManager::finished, [&](QNetworkReply *r){
        l.quit();
        reply = r;
    });
    l.exec(QEventLoop::AllEvents);

    if (reply->error() != QNetworkReply::NoError)
        return false;

    const QString res = reply->url().toString();
    qDebug().nospace().noquote() << QString(reply->readAll());
    return true;
}
