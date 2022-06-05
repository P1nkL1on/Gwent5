#include "cardinfo.h"

#include <QApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QRegularExpression>


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

    const QString res = reply->readAll();
    qDebug().noquote().nospace() << res;

    CardStringsAndUrls c;

    QRegularExpression regex;
    const auto matchAll = [&] {
        std::vector<std::string> matchs;
        QRegularExpressionMatchIterator i = regex.globalMatch(res);
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
    regex.setPatternOptions(QRegularExpression::MultilineOption | QRegularExpression::InvertedGreedinessOption);
    regex.setPattern("(?<=<div class=\"gscard__title\">)(?<name>.*)(</div>\\r$)");
    c.name = regex.match(res).captured("name").toStdString();

    regex.setPattern("(?<=<div class=\"gscard__ability\">)(?<text>.*)(</div> \\r$)");
    c.text = regex.match(res).captured("text").toStdString();

    regex.setPattern("(?<=<div class=\"gscard__flavor\">)(?<flavor>.*)(</div>\\r$)");
    c.flavor = regex.match(res).captured("flavor").toStdString();

    regex.setPattern("(?<=play_circle_outline<\\/i>).*(?=<)");
    c.textSounds = matchAll();

    regex.setPattern("(?<=src=\").*\\.mp3(?=\"><\\/audio>)");
    c.urlSounds = matchAll();

    c.urlImageLow =    "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    c.urlImageMedium = "https://gwent.one/image/card/medium/cid/png/" + id + ".png";
    c.urlVideo =       "https://gwent.one/video/card/loop/ob/" + id + ".mp4";
    c.lang = lang;

    return true;
}
