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


    const std::vector<Card *> deckStarting = {
        new VriheddSappers, new VriheddSappers, new VriheddSappers, new VriheddSappers,
        new ReaverScout, new Vaedermakar, new Vaedermakar, new Vaedermakar,
        new DolBlathannaArcher, new DolBlathannaArcher, new DolBlathannaArcher,
        new TuirseachBearmaster, new TuirseachBearmaster, new TuirseachBearmaster,
        new ReaverScout, new ReaverScout, new ReaverScout, new ReaverScout,
        new DolBlathannaArcher, new DolBlathannaArcher, new DolBlathannaArcher,
        new TuirseachBearmaster, new TuirseachBearmaster, new TuirseachBearmaster,
    };

    initField(deckStarting, _ally);
    startNextRound(_ally, _enemy);


    const std::vector<Card *> deckStarting2 = {
        new KeiraMetz, new KeiraMetz, new KeiraMetz, new KeiraMetz, new KeiraMetz,
    };

    initField(deckStarting2, _enemy);
    startNextRound(_enemy, _ally);

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

void MainWindow::mouseClick(const QRect &rect, const QPoint &point, Field &ally, Field &enemy)
{
    const double posWidth = (rect.width() - 2 * _view.spacingPx) / 11.0;
    const double posHeight = (rect.height() - 2 * _view.spacingPx) / 8.0;

    const auto cardAt = [=](const QPoint &point) -> Card * {
        for (int j = 0; j < 6; ++j) {

            const Field *field = j < 3 ? &enemy : &ally;
            const Row row = Row(j < 3 ? (2 - j) : (j - 3));
            const std::vector<Card *> &cards = field->row(row);
            const size_t count = cards.size();
            if (count == 0)
                continue;

            for (size_t i = 0; i < 9; ++i) {

                if (i >= count)
                    continue;

                const QRectF cardRect = QRectF(i * posWidth, _view.spacingPx + (j + 1) * posHeight, posWidth, posHeight).translated(rect.topLeft());
                if (cardRect.contains(point))
                    return cards[i];
            }
        }

        if (ally.cardStack.size() > 0) {
            for (size_t i = 0; i < ally.snapshot().cardOptions.size(); ++i) {
                const QRectF cardRect = QRectF(i * posWidth, 2 * _view.spacingPx + 7 * posHeight, posWidth, posHeight).translated(rect.topLeft());
                if (cardRect.contains(point))
                    return ally.snapshot().cardOptions[i];
            }
        }
        return nullptr;
    };

    const auto rowAndPostAt = [=](const bool ally, const QPoint &point, Row &row, Pos &pos) -> bool {
        const int jFrom = ally ? 3 : 0;
        const int jTo = ally ? 6 : 3;
        for (int j = jFrom; j < jTo; ++j) {
            const Row _row = Row(j < 3 ? (2 - j) : (j - 3));
            for (size_t i = 0; i < 9; ++i) {
                const QRectF cardRect = QRectF(i * posWidth, _view.spacingPx + (j + 1) * posHeight, posWidth, posHeight).translated(rect.topLeft());
                if (cardRect.contains(point)) {
                    row = _row;
                    pos = Pos(i);
                    return true;
                }
            }
        }
        return false;
    };

    const auto rowAt = [=](const bool ally, const QPoint &point, Row &row) -> bool {
        const int iFrom = ally ? 3 : 0;
        const int iTo = ally ? 6 : 3;
        for (int i = iFrom; i < iTo; ++i) {
            const Row _row = Row(i < 3 ? (2 - i) : (i - 3));
            const QRectF rowRect = QRectF(0, _view.spacingPx + (i + 1) * posHeight, posWidth * 9, posHeight).translated(rect.topLeft());
            if (rowRect.contains(point)) {
                row = _row;
                return true;
            }
        }
        return false;
    };

    const auto isFinishChoiceButton = [=](const QPoint &point) {
        const QFontMetricsF metrics(QFont{});
        const QString string = QString("Turn %1: %2").arg(1 + ally.nTurns).arg(QString::fromStdString(stringSnapShots(ally.cardStack)));
        const QPointF topLeft(metrics.width(string) + _view.borderTextPx, 2 * _view.spacingPx + 7 * posHeight - metrics.height());
        const QRectF rectRes = QRectF(topLeft, QSizeF(metrics.width("Finish Choice"), metrics.height())).translated(rect.topLeft());
        return rectRes.contains(point);
    };

    if (ally.cardStack.size() == 0)
        return;

    if (ally.snapshot().choice == RoundStartPlay) {
        Card *card = cardAt(point);
        if (card == nullptr || !isIn(card, ally.snapshot().cardOptions))
            return;
        onChoiceDoneCard(card, ally, enemy);
        tryFinishTurn(ally, enemy);
        repaint();
        return;
    }

    if (ally.snapshot().choice == Target) {
        if (ally.snapshot().isOptional && isFinishChoiceButton(point)) {
            onChoiceDoneCard(nullptr, ally, enemy);
            tryFinishTurn(ally, enemy);
            repaint();
            return;
        }
        Card *card = cardAt(point);
        if (card == nullptr || !isIn(card, ally.snapshot().cardOptions))
            return;
        onChoiceDoneCard(card, ally, enemy);
        tryFinishTurn(ally, enemy);
        repaint();
        return;
    }

    if (ally.snapshot().choice == SelectAllyRowAndPos) {
        Row row;
        Pos pos;
        if (!rowAndPostAt(true, point, row, pos))
            return;
        if (!isOkRowAndPos(row, pos, ally))
            return;
        onChoiceDoneRowAndPlace(row, pos, ally, enemy);
        tryFinishTurn(ally, enemy);
        repaint();
        return;
    }

    if (ally.snapshot().choice == SelectEnemyRowAndPos) {
        Row row;
        Pos pos;
        if (!rowAndPostAt(false, point, row, pos))
            return;
        if (!isOkRowAndPos(row, pos, enemy))
            return;
        onChoiceDoneRowAndPlace(row, pos, ally, enemy);
        tryFinishTurn(ally, enemy);
        repaint();
        return;
    }

    if (ally.snapshot().choice == SelectAllyRow) {
        Row row;
        if (!rowAt(true, point, row))
            return;
        onChoiceDoneRow(row, ally, enemy);
        tryFinishTurn(ally, enemy);
        repaint();
        return;
    }

    if (ally.snapshot().choice == SelectEnemyRow) {
        Row row;
        if (!rowAt(false, point, row))
            return;
        onChoiceDoneRow(row, ally, enemy);
        tryFinishTurn(ally, enemy);
        repaint();
        return;
    }

    if (ally.snapshot().choice == RoundStartSwap) {
        if (isFinishChoiceButton(point)) {
            onChoiceDoneRoundStartSwap(nullptr, ally, enemy);
            repaint();
            return;
        }
        Card *card = cardAt(point);
        if (card == nullptr || !isIn(card, ally.snapshot().cardOptions))
            return;
        onChoiceDoneRoundStartSwap(card, ally, enemy);
        repaint();
        return;
    }

    Q_ASSERT(false);
}

void MainWindow::paintInRect(const QRect rect, Field &ally, Field &enemy)
{
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
            const Qt::GlobalColor colorFore = Qt::black,
            QRectF *rectRes = nullptr)
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
        if (rectRes != nullptr)
            *rectRes = rect;
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
        if (!card->isAmbush && (card->url.size() > 0)) {
            requestImageByUrl(card->url);
            const QImage image = _pixMapsLoaded.value(QString::fromStdString(card->url));
            painter.drawImage(rectBorder, image);
        }

        /// draw rarity
        if (!card->isAmbush) {
            painter.setPen(card->rarity == Bronze ? Qt::darkRed : card->rarity == Silver ? Qt::gray : Qt::yellow);
            painter.drawRect(rectBorder);
        }

        /// draw selection border
        if (ally.cardStack.size() && isIn(card, ally.snapshot().cardOptions)) {
            painter.setPen(Qt::green);
            painter.drawLine(rect.topLeft(), rect.bottomRight());
            painter.drawLine(rect.topRight(), rect.bottomLeft());
        }

        /// draw selected border
        if (ally.cardStack.size() && isIn(card, ally.snapshot().cardOptionsSelected)) {
            painter.setPen(Qt::red);
            painter.drawLine(rect.topLeft(), rect.bottomRight());
            painter.drawLine(rect.topRight(), rect.bottomLeft());
        }

        /// draw source border
        if (ally.cardStack.size() && (card == ally.snapshot().cardSource)) {
            painter.setPen(Qt::cyan);
            painter.drawLine(rect.topLeft(), rect.bottomRight());
            painter.drawLine(rect.topRight(), rect.bottomLeft());
        }

        if (card->isAmbush)
            return;

        /// draw power
        double width = 0;
        if (card->power) {
            const Qt::GlobalColor back = card->power > card->powerBase ? Qt::green : card->power < card->powerBase ? Qt::red : Qt::gray;
            const Qt::GlobalColor fore = card->power > card->powerBase ? Qt::darkGreen : card->power < card->powerBase ? Qt::darkRed : Qt::black;
            width += paintTextInPoint(QString::number(card->power), topLeft, back, fore);
            width += _view.borderTextPx;
        }

        /// draw armor
        if (card->armor) {
            width += paintTextInPoint("A" + QString::number(card->armor), QPointF(topLeft.x() + width, topLeft.y()), Qt::yellow, Qt::black);
            width += _view.borderTextPx;
        }

        /// draw timer
        if (card->timer) {
            width += paintTextInPoint("T" + QString::number(card->timer), QPointF(topLeft.x() + width, topLeft.y()), Qt::cyan, Qt::black);
            width += _view.borderTextPx;
        }

        if (card->isSpy) {
            width += paintTextInPoint("SPY", QPointF(topLeft.x() + width, topLeft.y()), Qt::white, Qt::red);
            width += _view.borderTextPx;
        }

        /// draw name
        const QRectF rectNameText(topLeft.x(), topLeft.y() + posHeight - metrics.height(), posWidth, metrics.height());
        paintTextInRect(QString::fromStdString(card->name), rectNameText);
    };

    for (int j = 0; j < 6; ++j) {

        /// determine a row
        const Field *field = j < 3 ? &enemy : &ally;
        const Row row = Row(j < 3 ? (2 - j) : (j - 3));
        const std::vector<Card *> &cards = field->row(row);
        const size_t count = cards.size();

        for (size_t i = 0; i < 9; ++i) {
            const QPointF topLeft = rect.topLeft() + QPointF(i * posWidth, _view.spacingPx + (j + 1) * posHeight);

            if (i >= count) {
                const QRectF rect = QRectF(topLeft, QSizeF(posWidth, posHeight)).marginsRemoved(QMarginsF(_view.borderCardPx, _view.borderCardPx, _view.borderCardPx, _view.borderCardPx));
                const bool canBePlaced = (ally.cardStack.size()) && ((ally.snapshot().choice == SelectAllyRowAndPos && j >= 3) || (ally.snapshot().choice == SelectEnemyRowAndPos && j < 3)) && (i < count + 1);
                painter.setPen(canBePlaced ? Qt::green : Qt::gray);
                painter.drawRect(rect);
                continue;
            }

            const Card *card = cards.at(i);
            paintCard(card, topLeft);
        }

        const int power = powerRow(cards);
        paintTextInPoint(QString::number(power), rect.topLeft() + QPointF(9 * posWidth, _view.spacingPx + (j + 1) * posHeight));

        /// draw a row back
        const QRectF rowRect = QRectF(0, _view.spacingPx + (j + 1) * posHeight + metrics.height(), posWidth * 9, posHeight - 2 *  metrics.height()).translated(rect.topLeft());
        const RowEffect rowEffect = (j == 0 || j == 5) ? field->rowEffectSeige : (j == 1 || j == 4) ? field->rowEffectRange : field->rowEffectMeele;
        switch (rowEffect) {
        case NoRowEffect:
            break;
        case TorrentialRainEffect:
            painter.fillRect(rowRect, QBrush(Qt::gray, Qt::BDiagPattern));
            break;
        case BitingFrostEffect:
            painter.fillRect(rowRect, QBrush(Qt::blue, Qt::Dense7Pattern));
            break;
        case ImpenetrableFogEffect:
            painter.fillRect(rowRect, QBrush(Qt::gray, Qt::Dense6Pattern));
            break;
        case GoldenFrothEffect:
            painter.fillRect(rowRect, QBrush(Qt::yellow, Qt::FDiagPattern));
            break;
        case SkelligeStormEffect:
            painter.fillRect(rowRect, QBrush(Qt::blue, Qt::HorPattern));
            break;
        case DragonsDreamEffect:
//            painter.fillRect(rowRect, QBrush(Qt::darkCyan, Qt::Dense7Pattern));
            break;
        case KorathiHeatwaveEffect:
//            painter.fillRect(rowRect, QBrush(Qt::red, Qt::Dense5Pattern));
            break;
        case RaghNarRoogEffect:
//            painter.fillRect(rowRect, QBrush(Qt::red, Qt::Dense6Pattern));
            break;
        case FullMoonEffect:
//            painter.fillRect(rowRect, QBrush(Qt::blue, Qt::Dense1Pattern));
            break;
        case BloodMoonEffect:
//            painter.fillRect(rowRect, QBrush(Qt::red, Qt::Dense1Pattern));
            break;
        }
        painter.setBrush(QBrush(Qt::NoBrush));
    }

    paintTextInPoint(QString::number(enemy.discard.size()), rect.topLeft() + QPointF(_view.spacingPx + 10 * posWidth, _view.spacingPx + 1 * posHeight));
    for (size_t i = 0; i < enemy.discard.size(); ++i) {
        const QPointF topLeft = rect.topLeft() + QPointF(_view.spacingPx + 9 * posWidth, _view.spacingPx + 1 * posHeight);
        paintCard(enemy.discard[i], topLeft);
    }

    paintTextInPoint(QString::number(ally.discard.size()), rect.topLeft() + QPointF(_view.spacingPx + 10 * posWidth, _view.spacingPx + 6 * posHeight));
    for (size_t i = 0; i < ally.discard.size(); ++i) {
        const QPointF topLeft = rect.topLeft() + QPointF(_view.spacingPx + 9 * posWidth, _view.spacingPx + 6 * posHeight);
        paintCard(ally.discard[i], topLeft);
    }

    paintTextInPoint(QString::number(enemy.deck.size()), rect.topLeft() + QPointF(2 * _view.spacingPx + 11 * posWidth, _view.spacingPx + 1 * posHeight));

    paintTextInPoint(QString::number(ally.deck.size()), rect.topLeft() + QPointF(2 * _view.spacingPx + 11 * posWidth, _view.spacingPx + 6 * posHeight));

    if (ally.cardStack.size() > 0) {
        for (size_t i = 0; i < ally.snapshot().cardOptions.size(); ++i) {
            const QPointF topLeft = rect.topLeft() + QPointF(i * posWidth, 2 * _view.spacingPx + 7 * posHeight);
            paintCard(ally.snapshot().cardOptions[i], topLeft);
        }
    }

    const QString stringStatus = QString::fromStdString(stringSnapShots(ally.cardStack));
    const QString stringTurn = QString::number(1 + ally.nTurns);
    double statusWidth = 0;
    if ((ally.cardStack.size() > 0)){
        statusWidth += paintTextInPoint("Turn " + stringTurn + ": " + stringStatus, rect.topLeft() + QPointF(0, 2 * _view.spacingPx + 7 * posHeight - metrics.height()), Qt::gray) + _view.borderTextPx;
    }
    if ((ally.cardStack.size() > 0) && ally.snapshot().isOptional) {
        statusWidth += paintTextInPoint("Finish Choice", rect.topLeft() + QPointF(statusWidth, 2 * _view.spacingPx + 7 * posHeight - metrics.height()), Qt::black, Qt::white) + _view.borderTextPx;
    }
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
    const QRect rect = this->rect().marginsRemoved(QMargins(10, 10, 100, 10));

    if (e->type() == QEvent::MouseButtonPress) {
        auto *em = static_cast<QMouseEvent *>(e);
        if (_ally.cardStack.size())
            mouseClick(rect, em->pos(), _ally, _enemy);
        else
            mouseClick(rect, em->pos(), _enemy, _ally);
    }
    return QMainWindow::eventFilter(o, e);
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    const QRect rect = e->rect().marginsRemoved(QMargins(10, 10, 100, 10));

    if (_ally.cardStack.size())
        paintInRect(rect, _ally, _enemy);
    else
        paintInRect(rect, _enemy, _ally);
}
