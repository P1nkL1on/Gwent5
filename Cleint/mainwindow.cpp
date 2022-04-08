#include "mainwindow.h"

#include <QPaintEvent>
#include <QPainter>
#include <QNetworkAccessManager>
#include <QNetworkReply>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    _networkAccessManager = new QNetworkAccessManager(this);
    connect(_networkAccessManager, &QNetworkAccessManager::finished, this, &MainWindow::onImageRequestFinished);


    auto *dp = new DandelionPoet;
    auto *sd = new SileDeTansarville;
    _cards = {new TuirseachBearmaster, new TuirseachBearmaster, new AnCraiteGreatsword, new DimunDracar, new Swallow, new RedanianKnightElect, new RedanianKnightElect, dp, sd, new PoorFingInfantry, new PoorFingInfantry, new PoorFingInfantry};
    _ally.deckStarting = _ally.hand = _cards;


    startChoiceToPlayCard(_ally, nullptr);


    resize(600, 450);
    installEventFilter(this);
}

void MainWindow::requestImageByUrl(const std::string &url)
{
    if (url.size() == 0)
        return;

    const QString qString = QString::fromStdString(url);
    if (_pixMapsLoaded.contains(qString))
        return;

    if (_pixMapsRequested.contains(qString))
        return;

    QUrl qUrl(qString);
    QNetworkRequest request(qUrl);
    _pixMapsRequested.insert(qString);
    _networkAccessManager->get(request);
}


void MainWindow::onImageRequestFinished(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << reply->url() << "err";
        _pixMapsLoaded.insert(reply->url().toString(), QImage());
        return;
    }
    qDebug() << reply->url() << "ok";
    QByteArray jpegData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(jpegData);
    _pixMapsLoaded.insert(reply->url().toString(), pixmap.toImage());
    repaint();
}

bool MainWindow::eventFilter(QObject *o, QEvent *e)
{
    const double posWidth = (rect().width() - _view.spacingPx) / 11.0;
    const double posHeight = (rect().height() - _view.spacingPx) / 8.0;

    const auto cardAt = [=](const QPoint &point) -> Card * {
        for (int j = 0; j < 6; ++j) {

            const Field *field = j < 3 ? &_enemy : &_ally;
            const Row row = Row(j < 3 ? (2 - j) : (j - 3));
            const std::vector<Card *> &cards = field->row(row);
            const size_t count = cards.size();
            if (count == 0)
                continue;

            for (size_t i = 0; i < 9; ++i) {

                if (i >= count)
                    continue;

                const QRectF cardRect(i * posWidth, _view.spacingPx + (j + 1) * posHeight, posWidth, posHeight);
                if (cardRect.contains(point))
                    return cards[i];
            }
        }

        for (size_t i = 0; i < _ally.hand.size(); ++i) {
            const QRectF cardRect(i * posWidth, 2 * _view.spacingPx + 7 * posHeight, posWidth, posHeight);
            if (cardRect.contains(point))
                return _ally.hand[i];
        }

        return nullptr;
    };

    const auto rowAndPostAt = [=](const QPoint &point, Row &row, Pos &pos) -> bool {
        for (int j = 0; j < 6; ++j) {
            const Row _row = Row(j < 3 ? (2 - j) : (j - 3));
            for (size_t i = 0; i < 9; ++i) {
                const QRectF cardRect(i * posWidth, _view.spacingPx + (j + 1) * posHeight, posWidth, posHeight);
                if (cardRect.contains(point)) {
                    row = _row;
                    pos = Pos(i);
                    return true;
                }
            }
        }
        return false;
    };

    if (e->type() == QEvent::MouseButtonPress) {
        auto *em = static_cast<QMouseEvent *>(e);

        if (_ally.cardStack.size() == 0)
            goto event;

        if ((_ally.snapshot().choice == Play) || (_ally.snapshot().choice == Target)) {
            Card *card = cardAt(em->pos());
            if (card == nullptr || !isIn(card, _ally.snapshot().cardOptions))
                goto event;
            onChoiceDoneCard(card, _ally, _enemy);
            tryFinishTurn(_ally, _enemy);
            repaint();
            goto event;
        }

        if (_ally.snapshot().choice == SelectAllyRowAndPos) {
            Row row;
            Pos pos;
            if (!rowAndPostAt(em->pos(), row, pos))
                goto event;
            if (!isOkRowAndPos(row, pos, _ally))
                goto event;
            onChoiceDoneRowAndPlace(row, pos, _ally, _enemy);
            tryFinishTurn(_ally, _enemy);
            repaint();
            goto event;
        }
    }
    event:
    return QMainWindow::eventFilter(o, e);
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    const QRect rect = e->rect();

    if (rect.width() < _view.spacingPx * 2)
        return;

    if (rect.height() < _view.spacingPx * 2)
        return;

    const double posWidth = (rect.width() - 2 * _view.spacingPx) / 11.0;
    const double posHeight = (rect.height() - 2 * _view.spacingPx) / 8.0;

    QPainter painter(this);
    painter.fillRect(rect, Qt::white);

    const QFontMetricsF metrics(QFont{});

    const auto paintTextInPoint = [=, &painter](
            const QString &text,
            const QPointF &topLeft,
            const Qt::GlobalColor colorBack = Qt::white,
            const Qt::GlobalColor colorFore = Qt::black)
            -> double
    {
        const double textHeight = metrics.height();
        const double textWidth = metrics.width(text);
        const QRectF rect(topLeft, QSizeF(textWidth + 2 * _view.borderTextPx, textHeight));
        painter.fillRect(rect, colorBack);
        painter.setPen(Qt::black);
        painter.drawRect(rect);
        painter.setPen(colorFore);
        const QRectF rectText(QPointF(topLeft.x() + _view.borderTextPx, topLeft.y()), QSizeF(textWidth, textHeight));
        painter.drawText(rectText, text);
        return textWidth + 2 * _view.borderTextPx;
    };

    const auto paintTextInRect = [=, &painter](const QString &text, const QRectF &rect)
    {
        painter.fillRect(rect, Qt::white);
        painter.setPen(Qt::black);
        painter.drawRect(rect);

        const QString textElided = metrics.elidedText(text, Qt::ElideRight, rect.width() - 2 * _view.borderNamePx);
        painter.drawText(rect.marginsRemoved(QMarginsF(_view.borderNamePx, 0, _view.borderNamePx, 0)), textElided);
    };

    const auto paintCard = [=, &painter](const Card *card, const QPointF &topLeft)
    {
        const QSizeF size(posWidth, posHeight);
        const QRectF rect(topLeft, size);
        painter.setPen(Qt::black);
        painter.drawRect(rect);

        const QRectF rectBorder = QRectF(rect).marginsRemoved(QMarginsF(_view.borderCardPx, _view.borderCardPx, _view.borderCardPx, _view.borderCardPx));

        /// draw url image
        if (card->url.size() > 0) {
            requestImageByUrl(card->url);
            const QImage image = _pixMapsLoaded.value(QString::fromStdString(card->url));
            painter.drawImage(rectBorder, image);
        }

        /// draw rarity
        painter.setPen(card->rarity == Bronze ? Qt::darkRed : card->rarity == Silver ? Qt::gray : Qt::yellow);
        painter.drawRect(rectBorder);

        /// draw selection border
        if (_ally.cardStack.size() && isIn(card, _ally.snapshot().cardOptions)) {
            painter.setPen(Qt::green);
            painter.drawLine(rect.topLeft(), rect.bottomRight());
            painter.drawLine(rect.topRight(), rect.bottomLeft());
        }

        /// draw source border
        if (_ally.cardStack.size() && (card == _ally.snapshot().cardSource)) {
            painter.setPen(Qt::cyan);
            painter.drawLine(rect.topLeft(), rect.bottomRight());
            painter.drawLine(rect.topRight(), rect.bottomLeft());
        }
        /// draw power
        double width = 0;
        if (card->power) {
            const Qt::GlobalColor back = card->power > card->powerBase ? Qt::green : card->power < card->powerBase ? Qt::red : Qt::gray;
            const Qt::GlobalColor fore = card->power > card->powerBase ? Qt::darkGreen : card->power < card->powerBase ? Qt::darkRed : Qt::black;
            width += paintTextInPoint(QString::number(card->power), topLeft, back, fore) + _view.borderTextPx;
        }

        /// draw armor
        if (card->armor) {
            width += paintTextInPoint("@" + QString::number(card->armor), QPointF(topLeft.x() + width, topLeft.y()), Qt::yellow, Qt::black) + _view.borderTextPx;
        }

        /// draw timer
        if (card->timer) {
            width += paintTextInPoint("»" + QString::number(card->timer), QPointF(topLeft.x() + width, topLeft.y()), Qt::cyan, Qt::black) + _view.borderTextPx;
        }

        /// draw name
        const QRectF rectNameText(topLeft.x(), topLeft.y() + posHeight - metrics.height(), posWidth, metrics.height());
        paintTextInRect(QString::fromStdString(card->name), rectNameText);
    };

    for (int j = 0; j < 6; ++j) {

        /// determine a row
        const Field *field = j < 3 ? &_enemy : &_ally;
        const Row row = Row(j < 3 ? (2 - j) : (j - 3));
        const std::vector<Card *> &cards = field->row(row);
        const size_t count = cards.size();

        for (size_t i = 0; i < 9; ++i) {
            const QPointF topLeft(i * posWidth, _view.spacingPx + (j + 1) * posHeight);

            if (i >= count) {
                const QRectF rect = QRectF(topLeft, QSizeF(posWidth, posHeight)).marginsRemoved(QMarginsF(_view.borderCardPx, _view.borderCardPx, _view.borderCardPx, _view.borderCardPx));
                const bool canBePlaced = (_ally.cardStack.size()) && ((_ally.snapshot().choice == SelectAllyRowAndPos && j >= 3) || (_ally.snapshot().choice == SelectEnemyRowAndPos && j < 3)) && (i < count + 1);
                painter.setPen(canBePlaced ? Qt::green : Qt::gray);
                painter.drawRect(rect);
                continue;
            }

            const Card *card = cards.at(i);
            paintCard(card, topLeft);
        }

        const int power = powerRow(cards);
        paintTextInPoint(QString::number(power), QPointF(9 * posWidth, _view.spacingPx + (j + 1) * posHeight));
    }

    for (size_t i = 0; i < _ally.hand.size(); ++i) {
        const QPointF topLeft(i * posWidth, 2 * _view.spacingPx + 7 * posHeight);
        paintCard(_ally.hand[i], topLeft);
    }
}
