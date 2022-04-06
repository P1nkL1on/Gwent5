#include "mainwindow.h"

#include <QPaintEvent>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto *dp = new DandelionPoet;
    auto *td = new TemerianDrummer;
    auto *td2 = new TemerianDrummer;
    auto *sd = new SileDeTansarville;
    _cards = {new AddaStriga, new DeithwenArbalest, dp, td, td2, new TemerianDrummer, sd};

    _ally.hand = _cards;

    startChoiceToPlayCard(_ally);
    onChoiceDoneCard(td2, _ally, _enemy);
    onChoiceDoneRowAndPlace(Meele, 0, _ally, _enemy);

    startChoiceToPlayCard(_ally);
//    onChoiceDoneCard(dp, _ally, _enemy);
//    onChoiceDoneRowAndPlace(Meele, 0, _ally, _enemy);
//    onChoiceDoneCard(td, _ally, _enemy);
//    onChoiceDoneRowAndPlace(Meele, 0, _ally, _enemy);
//    onChoiceDoneCard(dp, _ally, _enemy);

//    startChoiceToPlayCard(_ally);
//    onChoiceDoneCard(sd, _ally, _enemy);
//    onChoiceDoneRowAndPlace(Meele, 2, _ally, _enemy);

    resize(600, 450);

    installEventFilter(this);
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

        if ((_ally.choice == Play) || (_ally.choice == Target)) {
            Card *card = cardAt(em->pos());
            if (card == nullptr || !isIn(card, _ally.choiceBetween))
                goto event;
            onChoiceDoneCard(card, _ally, _enemy);
            repaint();
            goto event;
        }

        if (_ally.choice == SelectAllyRowAndPos) {
            Row row;
            Pos pos;
            if (!rowAndPostAt(em->pos(), row, pos))
                goto event;
            onChoiceDoneRowAndPlace(row, pos, _ally, _enemy);
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

    const auto paintCard = [=, &painter](const Card *card, const QPointF &topLeft) {

        const QSizeF size(posWidth, posHeight);
        const QRectF rect(topLeft, size);
        painter.setPen(Qt::black);
        painter.drawRect(rect);

        if (isIn(card, _ally.choiceBetween)) {
            painter.setPen(Qt::green);
            painter.drawLine(rect.topLeft(), rect.bottomRight());
            painter.drawLine(rect.topRight(), rect.bottomLeft());
        }

        const QRectF rectBorder = QRectF(rect).marginsRemoved(QMarginsF(_view.borderCardPx, _view.borderCardPx, _view.borderCardPx, _view.borderCardPx));
        painter.setPen(card->rarity == Bronze ? Qt::darkRed : card->rarity == Silver ? Qt::gray : Qt::yellow);
        painter.drawRect(rectBorder);

        const QFontMetricsF metrics(QFont{});
        const double textHeight = metrics.height();
        const double textWidth = metrics.width(QString::number(card->power));
        const QRectF rectText(topLeft, QSizeF(textWidth, textHeight));
        const QRectF rectTextBorder(topLeft, QSizeF(textWidth + 2 * _view.borderTextPx, textHeight + 2 * _view.borderTextPx));

        painter.fillRect(rectTextBorder, Qt::white);
        painter.fillRect(rectText.translated(_view.borderTextPx, _view.borderTextPx), card->power > card->powerBase ? Qt::green : card->power < card->powerBase ? Qt::red : Qt::gray);

        painter.setPen(Qt::black);
        painter.drawRect(rectTextBorder);

        painter.setPen(card->power > card->powerBase ? Qt::darkGreen : card->power < card->powerBase ? Qt::darkRed : Qt::black);
        painter.drawText(rectText.translated(_view.borderTextPx, _view.borderTextPx), QString::number(card->power));
    };

    for (int j = 0; j < 6; ++j) {
        // determine a row

        const Field *field = j < 3 ? &_enemy : &_ally;
        const Row row = Row(j < 3 ? (2 - j) : (j - 3));
        const std::vector<Card *> &cards = field->row(row);
        const size_t count = cards.size();

        for (size_t i = 0; i < 9; ++i) {
            const QPointF topLeft(i * posWidth, _view.spacingPx + (j + 1) * posHeight);

            if (i >= count) {
                const QRectF rect = QRectF(topLeft, QSizeF(posWidth, posHeight)).marginsRemoved(QMarginsF(_view.borderCardPx, _view.borderCardPx, _view.borderCardPx, _view.borderCardPx));
                const bool canBePlaced = ((_ally.choice == SelectAllyRowAndPos && j >= 3) || (_ally.choice == SelectEnemyRowAndPos && j < 3)) && (i < count + 1);
                painter.setPen(canBePlaced ? Qt::green : Qt::gray);
                painter.drawRect(rect);
                continue;
            }

            const Card *card = cards.at(i);
            paintCard(card, topLeft);
        }
    }

    for (size_t i = 0; i < _ally.hand.size(); ++i) {
        const QPointF topLeft(i * posWidth, 2 * _view.spacingPx + 7 * posHeight);
        paintCard(_ally.hand[i], topLeft);
    }
}
