#include "mainwindow.h"

#include <QPaintEvent>
#include <QPainter>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QMediaPlayer>
#include <QPropertyAnimation>
#include <QFrame>
#include <QEventLoop>
#include <QThread>
#include <QTimer>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    _networkAccessManager = new QNetworkAccessManager(this);
    connect(_networkAccessManager, &QNetworkAccessManager::finished, this, &MainWindow::onImageRequestFinished);


    const std::vector<Card *> deckStarting = {
        new PriestessOfFreya, new Dao, new Dao,
//        new Vaedermakar, new CiriNova, new CiriNova, new HaraldTheCripple, new DolBlathannaArcher, new DolBlathannaArcher,
//        new HaraldTheCripple, new HaraldTheCripple, new FirstLight, new FirstLight,
//        new GeraltIgni, new DolBlathannaArcher, new DolBlathannaArcher, new DolBlathannaArcher,
//        new Reconnaissance, new Reconnaissance, new Reconnaissance,
//        new HeymaeySpearmaiden, new HeymaeySpearmaiden, new HeymaeySpearmaiden,
//        new PriestessOfFreya, new PriestessOfFreya, new PriestessOfFreya,
//        new AnCraiteGreatsword, new AnCraiteGreatsword, new AnCraiteGreatsword,
//        new ChampionOfHov, new DandelionPoet, new Frightener, new Vaedermakar,
//        new TuirseachBearmaster, new TuirseachBearmaster,
//        new DimunDracar, new DimunDracar,
    };

    const std::vector<Card *> deckStarting2 = {
        new CeallachDyffryn, new CeallachDyffryn,
        new Reconnaissance, new Reconnaissance,
        new Ambassador, new Ambassador,
        new Assassin, new Assassin,
        new Emissary, new Emissary,
        new ShupesDayOff, new ArachasVenom, new AlzursThunder,
//        new ReaverScout, new ReaverScout, new ReaverScout,
//        new KaedweniKnight, new KaedweniKnight, new KaedweniKnight,
//        new JohnNatalis, new Vaedermakar, new KeiraMetz,
//        new TemerianDrummer, new TemerianDrummer, new TemerianDrummer,
//        new SileDeTansarville,
//        new GeraltIgni, new GeraltIgni, new GeraltIgni, new GeraltIgni,
//        new Reconnaissance, new Reconnaissance, new Reconnaissance,
//        new PoorFingInfantry, new PoorFingInfantry, new PoorFingInfantry,
    };

    initField(deckStarting, _ally);
    initField(deckStarting2, _enemy);
    startNextRound(_ally, _enemy);

    // TODO: remove test units
    for (int i = 1; i <= 7; ++i) {
        auto *c = new Card;
        c->name = "Dummy";
        c->url = "https://gwent.one/image/card/low/cid/png/113201.png";
        c->isDoomed = true;
        c->power = c->powerBase = i;
        _ally.rowMeele.push_back(c);
        _ally.cardsAdded.push_back(c);
    }
    for (int i = 1; i <= 5; ++i) {
        auto *c = new Card;
        c->name = "Egg";
        c->url = "https://gwent.one/image/card/low/cid/png/132316.png";
        c->isDoomed = true;
        c->power = c->powerBase = i;
        _enemy.rowMeele.push_back(c);
        _enemy.cardsAdded.push_back(c);
    }

    resize(600, 550);
    setMouseTracking(true);
    installEventFilter(this);
    _snapshot = fieldView(_ally, _enemy);
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

void MainWindow::requestSoundByUrl(const std::string &url)
{
    if (url.size() == 0)
        return;

    const QString qString = QString::fromStdString(url);
    if (!_sounds.contains(qString)) {
        auto *mediaPlayer = new QMediaPlayer(this);
        mediaPlayer->setMedia(QUrl(qString));
        mediaPlayer->setVolume(_sound);
        _sounds.insert(qString, mediaPlayer);
    }

    _sounds.value(qString)->play();
}

void MainWindow::mouseClick(const QRect &rect, const QPoint &point, Field &ally, Field &enemy)
{
    const double posWidth = (rect.width() - 2 * _layout.spacingPx) / 11.0;
    const double posHeight = (rect.height() - 2 * _layout.spacingPx) / 8.0;

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

                const QRectF cardRect = QRectF(i * posWidth, _layout.spacingPx + (j + 1) * posHeight, posWidth, posHeight).translated(rect.topLeft());
                if (cardRect.contains(point))
                    return cards[i];
            }
        }

        if (ally.cardStack.size() > 0) {
            for (size_t i = 0; i < ally.choice().cardOptions.size(); ++i) {
                const QRectF cardRect = QRectF(i * posWidth, 2 * _layout.spacingPx + 7 * posHeight, posWidth, posHeight).translated(rect.topLeft());
                if (cardRect.contains(point))
                    return ally.choice().cardOptions[i];
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
                const QRectF cardRect = QRectF(i * posWidth, _layout.spacingPx + (j + 1) * posHeight, posWidth, posHeight).translated(rect.topLeft());
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
            const QRectF rowRect = QRectF(0, _layout.spacingPx + (i + 1) * posHeight, posWidth * 9, posHeight).translated(rect.topLeft());
            if (rowRect.contains(point)) {
                row = _row;
                return true;
            }
        }
        return false;
    };

    const auto isFinishChoiceButton = [=](const QPoint &point) {
        const QFontMetricsF metrics(QFont{});
        const QString string = QString("Turn %1: %2").arg(1 + ally.nTurns).arg(QString::fromStdString(stringChoices(ally.cardStack)));
        const QPointF topLeft(metrics.width(string) + _layout.borderTextPx, 2 * _layout.spacingPx + 7 * posHeight - metrics.height());
        const QRectF rectRes = QRectF(topLeft, QSizeF(metrics.width("Finish Choice"), metrics.height())).translated(rect.topLeft());
        return rectRes.contains(point);
    };

    const auto topLeftOf = [=](const Card *card) -> QPointF {
        Row row;
        Pos pos;
        if (rowAndPos(card, ally, row, pos))
            return rect.topLeft() + QPointF(pos * posWidth, _layout.spacingPx + (row + 4) * posHeight);
        if (rowAndPos(card, enemy, row, pos))
            return rect.topLeft() + QPointF(pos * posWidth, _layout.spacingPx + (3 - row) * posHeight);
        return rect.topLeft() + QPointF(_layout.spacingPx + 9 * posWidth, _layout.spacingPx + 4 * posHeight);
    };

    if (ally.cardStack.size() == 0)
        return;

    if (ally.choice().choiceType == RoundStartPlay) {
        if (ally.choice().isOptional && isFinishChoiceButton(point)) {
            onChoiceDoneCard(nullptr, ally, enemy);
            goto finish_turn;
        }
        Card *card = cardAt(point);
        if (card == nullptr || !isIn(card, ally.choice().cardOptions))
            return;
        onChoiceDoneCard(card, ally, enemy);
        goto finish_turn;
    }

    if (ally.choice().choiceType == Target) {
        if (ally.choice().isOptional && isFinishChoiceButton(point)) {
            onChoiceDoneCard(nullptr, ally, enemy);
            goto finish_turn;
        }
        Card *card = cardAt(point);
        if (card == nullptr || !isIn(card, ally.choice().cardOptions))
            return;
        onChoiceDoneCard(card, ally, enemy);
        goto finish_turn;
    }

    if (ally.choice().choiceType == SelectAllyRowAndPos) {
        Row row;
        Pos pos;
        if (!rowAndPostAt(true, point, row, pos))
            return;
        if (!isOkRowAndPos(row, pos, ally))
            return;
        onChoiceDoneRowAndPlace(row, pos, ally, enemy);
        goto finish_turn;
    }

    if (ally.choice().choiceType == SelectEnemyRowAndPos) {
        Row row;
        Pos pos;
        if (!rowAndPostAt(false, point, row, pos))
            return;
        if (!isOkRowAndPos(row, pos, enemy))
            return;
        onChoiceDoneRowAndPlace(row, pos, ally, enemy);
        goto finish_turn;
    }

    if (ally.choice().choiceType == SelectAllyRow) {
        Row row;
        if (!rowAt(true, point, row))
            return;
        onChoiceDoneRow(row, ally, enemy);
        goto finish_turn;
    }

    if (ally.choice().choiceType == SelectEnemyRow) {
        Row row;
        if (!rowAt(false, point, row))
            return;
        onChoiceDoneRow(row, ally, enemy);
        goto finish_turn;
    }

    if (ally.choice().choiceType == RoundStartSwap) {
        if (isFinishChoiceButton(point)) {
            onChoiceDoneRoundStartSwap(nullptr, ally, enemy);
            repaint();
            return;
        }
        Card *card = cardAt(point);
        if (card == nullptr || !isIn(card, ally.choice().cardOptions))
            return;
        onChoiceDoneRoundStartSwap(card, ally, enemy);
        repaint();
        return;
    }

    Q_ASSERT(false);

finish_turn:
    ally.snapshots.clear();
    repaint();
    tryFinishTurn(ally, enemy);
    repaintAllSnapshots();
}

void MainWindow::paintInRect(const QRect rect, const FieldView &view)
{
    if (rect.width() < _layout.spacingPx * 2)
        return;

    if (rect.height() < _layout.spacingPx * 2)
        return;

    const ChoiceView *currentChoiceView = view.choices.size() ? &view.choices.back() : nullptr;

    const QFontMetricsF metrics(QFont{});
    const double posWidth = (rect.width() - 2 * _layout.spacingPx) / 11.0;
    const double posHeight = (rect.height() - 2 * _layout.spacingPx) / 8.0;

    QPainter painter(this);
    painter.fillRect(rect, Qt::white);

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
        const QRectF rect(topLeft, QSizeF(textWidth + 2 * _layout.borderTextPx, textHeight));
        painter.fillRect(rect, colorBack);
        painter.setPen(Qt::black);
        painter.drawRect(rect);
        painter.setPen(colorFore);
        const QRectF rectText(QPointF(topLeft.x() + _layout.borderTextPx, topLeft.y()), QSizeF(textWidth, textHeight));
        painter.drawText(rectText, text);
        if (rectRes != nullptr)
            *rectRes = rect;
        return textWidth + 2 * _layout.borderTextPx;
    };

    const auto paintTextInRect = [=, &painter](const QString &text, const QRectF &rect)
    {
        painter.fillRect(rect, Qt::white);
        painter.setPen(Qt::black);
        painter.drawRect(rect);

        const QString textElided = metrics.elidedText(text, Qt::ElideRight, rect.width() - 2 * _layout.borderNamePx);
        painter.drawText(rect.marginsRemoved(QMarginsF(_layout.borderNamePx, 0, _layout.borderNamePx, 0)), textElided);
    };

    const auto paintCardHidden = [=, &painter](const QPointF &topLeft)
    {
        const QSizeF size(posWidth, posHeight);
        const QRectF rect(topLeft, size);
        painter.setPen(Qt::black);
        painter.drawRect(rect);
    };

    const auto paintCardGrayscale = [=, &painter](const CardView &cardView, const QPointF &topLeft)
    {
        Q_ASSERT(!cardView.isAmbush);
        const QSizeF size(posWidth, posHeight);
        const QRectF rect(topLeft, size);
        painter.setPen(Qt::black);
        painter.drawRect(rect);

        const QRectF rectBorder = QRectF(rect).marginsRemoved(QMarginsF(_layout.borderCardPx, _layout.borderCardPx, _layout.borderCardPx, _layout.borderCardPx));

        /// draw url image
        if (cardView.url.size() > 0) {
            requestImageByUrl(cardView.url);
            const QImage image = _pixMapsLoaded.value(QString::fromStdString(cardView.url)).convertToFormat(QImage::Format_Grayscale8);
            painter.drawImage(rectBorder, image);
        }

        /// draw name
        const QRectF rectNameText(topLeft.x(), topLeft.y() + posHeight - metrics.height(), posWidth, metrics.height());
        paintTextInRect(QString::fromStdString(cardView.name), rectNameText);
    };

    const auto paintCard = [=, &painter](const CardView &cardView, const QPointF &topLeft)
    {
        Q_ASSERT(!cardView.isAmbush);
        const QSizeF size(posWidth, posHeight);
        const QRectF rect(topLeft, size);
        painter.setPen(Qt::black);
        painter.drawRect(rect);

        const QRectF rectBorder = QRectF(rect).marginsRemoved(QMarginsF(_layout.borderCardPx, _layout.borderCardPx, _layout.borderCardPx, _layout.borderCardPx));

        /// draw url image
        if (cardView.url.size() > 0) {
            requestImageByUrl(cardView.url);
            const QImage image = _pixMapsLoaded.value(QString::fromStdString(cardView.url));
            painter.drawImage(rectBorder, image);
        }

        /// draw rarity
        painter.setPen(cardView.rarity == Bronze ? Qt::darkRed : cardView.rarity == Silver ? Qt::gray : Qt::yellow);
        painter.drawRect(rectBorder);


        /// draw selection border
        if (view.choices.size() && isIn(cardView.id, view.choices.back().cardOptionIds)) {
            painter.setPen(Qt::green);
            painter.drawLine(rect.topLeft(), rect.bottomRight());
            painter.drawLine(rect.topRight(), rect.bottomLeft());
        }

        /// draw selected border
        if (view.choices.size() && isIn(cardView.id, view.choices.back().cardOptionIdsSelected)) {
            painter.setPen(Qt::red);
            painter.drawLine(rect.topLeft(), rect.bottomRight());
            painter.drawLine(rect.topRight(), rect.bottomLeft());
        }

        /// draw source border
        if (view.choices.size() && (cardView.id == view.choices.back().cardSourceId)) {
            painter.setPen(Qt::cyan);
            painter.drawLine(rect.topLeft(), rect.bottomRight());
            painter.drawLine(rect.topRight(), rect.bottomLeft());
        }

        /// draw power
        double width = 0;
        if (cardView.power) {
            const Qt::GlobalColor back = cardView.power > cardView.powerBase ? Qt::green : cardView.power < cardView.powerBase ? Qt::red : Qt::gray;
            const Qt::GlobalColor fore = cardView.power > cardView.powerBase ? Qt::darkGreen : cardView.power < cardView.powerBase ? Qt::darkRed : Qt::black;
            width += paintTextInPoint(QString::number(cardView.power), topLeft, back, fore);
            width += _layout.borderTextPx;
        }

        /// draw armor
        if (cardView.armor) {
            width += paintTextInPoint("ARMOR " + QString::number(cardView.armor), QPointF(topLeft.x() + width, topLeft.y()), Qt::yellow, Qt::black);
            width += _layout.borderTextPx;
        }

        if (cardView.isLocked) {
            width += paintTextInPoint("LOCKED", QPointF(topLeft.x() + width, topLeft.y()), Qt::black, Qt::white);
            width += _layout.borderTextPx;
        }

        if (cardView.timer) {
            width += paintTextInPoint("TIMER " + QString::number(cardView.timer), QPointF(topLeft.x() + width, topLeft.y()), Qt::cyan, Qt::black);
            width += _layout.borderTextPx;
        }

        if (cardView.isSpy) {
            width += paintTextInPoint("SPY", QPointF(topLeft.x() + width, topLeft.y()), Qt::white, Qt::red);
            width += _layout.borderTextPx;
        }

        if (cardView.isResilient) {
            width += paintTextInPoint("RESILIENCE", QPointF(topLeft.x() + width, topLeft.y()), Qt::white, Qt::darkGreen);
            width += _layout.borderTextPx;
        }

        if (cardView.isImmune) {
            width += paintTextInPoint("IMMUNE", QPointF(topLeft.x() + width, topLeft.y()), Qt::black, Qt::green);
            width += _layout.borderTextPx;
        }

        if (cardView.isDoomed) {
            width += paintTextInPoint("DOOMED", QPointF(topLeft.x() + width, topLeft.y()), Qt::black, Qt::cyan);
            width += _layout.borderTextPx;
        }

        /// draw name
        const QRectF rectNameText(topLeft.x(), topLeft.y() + posHeight - metrics.height(), posWidth, metrics.height());
        paintTextInRect(QString::fromStdString(cardView.name), rectNameText);
    };

    // ___________________
    // TODO: tmp copypaste
    const auto cardIdAt = [=](const QPoint &point) -> int {
        for (int j = 0; j < 6; ++j) {
            for (size_t i = 0; i < 9; ++i) {
                int id;
                if (!view.idAtRowAndPos(Row(j), Pos(i), &id))
                    continue;
                const QRectF cardRect = QRectF(i * posWidth, _layout.spacingPx + (j + 1) * posHeight, posWidth, posHeight).translated(rect.topLeft());
                if (cardRect.contains(point))
                    return id;
            }
        }
        if (currentChoiceView)
            for (size_t i = 0; i < currentChoiceView->cardOptionIds.size(); ++i) {
                const QRectF cardRect = QRectF(i * posWidth, 2 * _layout.spacingPx + 7 * posHeight, posWidth, posHeight).translated(rect.topLeft());
                if (cardRect.contains(point))
                    return currentChoiceView->cardOptionIds[i];
            }
        return -1;
    };
    const int cardIdSelected = cardIdAt(_pos);
    if (cardIdSelected >= 0) {
        const CardView &cardView = view.cardView(cardIdSelected);
        const QPointF topLeft = QPointF(posWidth * 9 + _layout.spacingPx, posHeight * 1 + _layout.spacingPx) + rect.topLeft();
        paintCard(cardView, topLeft);
        paintTextInPoint(QString("Power = %1").arg(cardView.power), topLeft + QPointF(0, posHeight + 0 * metrics.height()), Qt::white, Qt::black);
        paintTextInPoint(QString("Power Base = %1").arg(cardView.powerBase), topLeft + QPointF(0, posHeight + 1 * metrics.height()), Qt::white, Qt::black);
        paintTextInPoint(QString("Armor = %1").arg(cardView.armor), topLeft + QPointF(0, posHeight + 2 * metrics.height()), Qt::white, Qt::black);
        paintTextInPoint(QString("Locked? %1").arg(cardView.isLocked), topLeft + QPointF(0, posHeight + 3 * metrics.height()), Qt::white, Qt::black);
        paintTextInPoint(QString("Resilient? %1").arg(cardView.isResilient), topLeft + QPointF(0, posHeight + 4 * metrics.height()), Qt::white, Qt::black);
        paintTextInPoint(QString("Spying? %1").arg(cardView.isSpy), topLeft + QPointF(0, posHeight + 5 * metrics.height()), Qt::white, Qt::black);
        paintTextInPoint(QString("Immune? %1").arg(cardView.isImmune), topLeft + QPointF(0, posHeight + 6 * metrics.height()), Qt::white, Qt::black);
        paintTextInPoint(QString("Doomed? %1").arg(cardView.isDoomed), topLeft + QPointF(0, posHeight + 7 * metrics.height()), Qt::white, Qt::black);
        paintTextInPoint(QString("Name: %1").arg(QString::fromStdString(cardView.name)), topLeft + QPointF(0, posHeight + 8 * metrics.height()), Qt::white, Qt::black);
        paintTextInPoint(QString("Text: %1").arg(QString::fromStdString(cardView.text)), topLeft + QPointF(0, posHeight + 9 * metrics.height()), Qt::white, Qt::black);
    }
    // TODO: tmp remove all above
    // __________________________



    for (int j = 0; j < 6; ++j) {        
        for (size_t i = 0; i < 9; ++i) {
            const QPointF topLeft = rect.topLeft() + QPointF(i * posWidth, _layout.spacingPx + (j + 1) * posHeight);
            int id;
            int n;
            if (!view.idAtRowAndPos(Row(j), Pos(i), &id, &n)) {
                const QRectF rect = QRectF(topLeft, QSizeF(posWidth, posHeight)).marginsRemoved(QMarginsF(_layout.borderCardPx, _layout.borderCardPx, _layout.borderCardPx, _layout.borderCardPx));
                const bool canBePlaced = currentChoiceView && ((currentChoiceView->choiceType == SelectAllyRowAndPos && j >= 3) || (currentChoiceView->choiceType == SelectEnemyRowAndPos && j < 3)) && (i <= n);
                painter.setPen(canBePlaced ? Qt::green : Qt::gray);
                painter.drawRect(rect);
            } else {
                const CardView &cardView = view.cardView(id);
                paintCard(cardView, topLeft);
            }
        }

        // TODO: return showing a power
        paintTextInPoint(QString::number(view.rowPower(Row(j))), rect.topLeft() + QPointF(9 * posWidth, _layout.spacingPx + (j + 1) * posHeight));

        /// draw a row back
        const QRectF rowRect = QRectF(0, _layout.spacingPx + (j + 1) * posHeight + metrics.height(), posWidth * 9, posHeight - 2 *  metrics.height()).translated(rect.topLeft());
        switch (view.rowEffect(Row(j))) {
        case NoRowEffect:
            break;
        case TorrentialRainEffect:
            painter.fillRect(rowRect, QBrush(Qt::gray, Qt::BDiagPattern));
            break;
        case BitingFrostEffect:
            painter.fillRect(rowRect, QBrush(Qt::cyan, Qt::Dense7Pattern));
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
            painter.fillRect(rowRect, QBrush(Qt::darkCyan, Qt::HorPattern));
            break;
        case KorathiHeatwaveEffect:
            painter.fillRect(rowRect, QBrush(Qt::red, Qt::Dense5Pattern));
            break;
        case RaghNarRoogEffect:
            painter.fillRect(rowRect, QBrush(Qt::red, Qt::Dense4Pattern));
            break;
        case FullMoonEffect:
            painter.fillRect(rowRect, QBrush(Qt::blue, Qt::VerPattern));
            break;
        case BloodMoonEffect:
            painter.fillRect(rowRect, QBrush(Qt::red, Qt::VerPattern));
            break;
        case PitTrapEffect:
            painter.fillRect(rowRect, QBrush(Qt::darkYellow, Qt::VerPattern));
            break;
        }
        painter.setBrush(QBrush(Qt::NoBrush));
    }

    if (_view == ViewStack) {
        double statusWidth = 0;
        if (currentChoiceView){
            const QString stringStatus = QString::fromStdString(currentChoiceView->toString());
            const QString stringTurn = QString::number(1 + view.nTurns);
            statusWidth += paintTextInPoint("Turn " + stringTurn + ": " + stringStatus, rect.topLeft() + QPointF(0, 2 * _layout.spacingPx + 7 * posHeight - metrics.height()), Qt::gray) + _layout.borderTextPx;
        }
        if (currentChoiceView && currentChoiceView->isOptional) {
            statusWidth += paintTextInPoint("Finish Choice", rect.topLeft() + QPointF(statusWidth, 2 * _layout.spacingPx + 7 * posHeight - metrics.height()), Qt::black, Qt::white) + _layout.borderTextPx;
        }
        if (currentChoiceView) {
            for (size_t i = 0; i < currentChoiceView->cardOptionIds.size(); ++i) {
                const QPointF topLeft = rect.topLeft() + QPointF(i * posWidth, 2 * _layout.spacingPx + 7 * posHeight);
                paintCard(view.cardView(currentChoiceView->cardOptionIds[i]), topLeft);
            }
            if (currentChoiceView->cardSourceId >= 0) {
                Row row;
                Pos pos;
                bool isAlly;
                QPointF topLeft;
                if (!view.rowAndPos(currentChoiceView->cardSourceId, &row, &pos, &isAlly)) {
                    topLeft = rect.topLeft() + QPointF(_layout.spacingPx + 9 * posWidth, _layout.spacingPx + 4 * posHeight);
                    paintCard(view.cardView(currentChoiceView->cardSourceId), topLeft);
                } else if (isAlly) {
                    topLeft = rect.topLeft() + QPointF(pos * posWidth, _layout.spacingPx + (4 + row) * posHeight);
                } else {
                    topLeft = rect.topLeft() + QPointF(pos * posWidth, _layout.spacingPx + (3 - row) * posHeight);
                }
                if (!_pos.isNull()) {
                    painter.setPen(Qt::cyan);
                    const QPointF center = topLeft + QPointF(posWidth * 0.5, posHeight * 0.5);
                    painter.drawLine(_pos, center);
                }
            }
        }
    } else if (_view == ViewHand) {
        const QString stringStatus = QString("Hand (%1):").arg(view.allyHandIds.size());
        paintTextInPoint(stringStatus, rect.topLeft() + QPointF(0, 2 * _layout.spacingPx + 7 * posHeight - metrics.height()), Qt::gray);
        for (size_t i = 0; i < view.allyHandIds.size(); ++i) {
            const QPointF topLeft = rect.topLeft() + QPointF(i * posWidth, 2 * _layout.spacingPx + 7 * posHeight);
            paintCardGrayscale(view.cardView(view.allyHandIds[i]), topLeft);
        }
    } else if (_view == ViewDiscard) {
        const QString stringStatus = QString("Discard (%1):").arg(view.allyDiscardIds.size());
        paintTextInPoint(stringStatus, rect.topLeft() + QPointF(0, 2 * _layout.spacingPx + 7 * posHeight - metrics.height()), Qt::gray);
        for (size_t i = 0; i < view.allyDiscardIds.size(); ++i) {
            const QPointF topLeft = rect.topLeft() + QPointF(i * posWidth, 2 * _layout.spacingPx + 7 * posHeight);
            paintCardGrayscale(view.cardView(view.allyDiscardIds[i]), topLeft);
        }
    } else if (_view == ViewDeck) {
        const QString stringStatus = QString("Deck (%1):").arg(view.allyDeckIds.size());
        paintTextInPoint(stringStatus, rect.topLeft() + QPointF(0, 2 * _layout.spacingPx + 7 * posHeight - metrics.height()), Qt::gray);
        for (size_t i = 0; i < view.allyDeckIds.size(); ++i) {
            const QPointF topLeft = rect.topLeft() + QPointF(i * posWidth, 2 * _layout.spacingPx + 7 * posHeight);
            paintCardHidden(topLeft);
        }
    } else {
        Q_ASSERT(false);
    }
    const QString stringStatusAlly = QString("ALLY: Power = %1, Pass = %2, Wins = %3")
            .arg(view.nPowerRowAllyMeele + view.nPowerRowAllyRange + view.nPowerRowAllySeige)
            .arg(view.allyPassed)
            .arg(view.nAllyWins);
    const QString stringStatusEnemy = QString("ENEMY: Power = %1, Pass = %2, Wins = %3")
            .arg(view.nPowerRowEnemyMeele + view.nPowerRowEnemyRange + view.nPowerRowEnemySeige)
            .arg(view.enemyPassed)
            .arg(view.nEnemyWins);
    paintTextInPoint(stringStatusAlly, QPointF(0, 0), Qt::black, Qt::cyan);
    paintTextInPoint(stringStatusEnemy, QPointF(0, 15), Qt::black, Qt::red);
}

void MainWindow::onImageRequestFinished(QNetworkReply *reply)
{
    const QString urlString = reply->url().toString();
    if (reply->error() != QNetworkReply::NoError) {
        _pixMapsLoaded.insert(urlString, QImage());
        return;
    }

    if (urlString.endsWith(".png")) {
        QByteArray pngData = reply->readAll();
        QPixmap pixmap;
        pixmap.loadFromData(pngData);
        _pixMapsLoaded.insert(urlString, pixmap.toImage());
        repaint();

    } else {
        Q_ASSERT(false);
    }
}

bool MainWindow::eventFilter(QObject *o, QEvent *e)
{
    const QRect rect = this->rect().marginsRemoved(QMargins(10, 10, 200, 150));

    if (e->type() == QEvent::MouseButtonPress) {
        auto *em = static_cast<QMouseEvent *>(e);
        if (_ally.cardStack.size())
            mouseClick(rect, em->pos(), _ally, _enemy);
        else if (_enemy.cardStack.size())
            mouseClick(rect, em->pos(), _enemy, _ally);
    }

    if (e->type() == QEvent::MouseMove) {
        auto *em = static_cast<QMouseEvent *>(e);
        if (_ally.cardStack.size() && _ally.choice().cardSource != nullptr) {
            _pos = em->pos();
            repaintAllSnapshots();
        } else if (_enemy.cardStack.size() && _enemy.choice().cardSource != nullptr) {
            _pos = em->pos();
            repaintAllSnapshots();
        } else {
            // _pos = QPoint();
            // TODO: tmp show card description
            _pos = em->pos();
            repaintAllSnapshots();
        }
    }

    if (e->type() == QEvent::Wheel) {
        auto *ew = static_cast<QWheelEvent *>(e);
        if (rect.contains(ew->pos())) {
            int view = _view;
            if (ew->delta() > 0) {
                view = (view + 1) % 4;
            } else {
                view--;
                if (view < 0)
                    view += 4;
            }
            _view = View(view);
            repaintAllSnapshots();
        }
    }
    return QMainWindow::eventFilter(o, e);
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    const QRect rect = e->rect().marginsRemoved(QMargins(10, 10, 200, 150));
    paintInRect(rect, _snapshot);
}


void MainWindow::repaintAllSnapshots()
{
    // fast version
    if (_ally.cardStack.size()) {
        _snapshot = fieldView(_ally, _enemy);
    } else if (_enemy.cardStack.size()) {
        _snapshot = fieldView(_enemy, _ally);
    }
    repaint();
//    return;

//    if (_ally.cardStack.size()) {
//        for (const FieldView &snapshot : _ally.snapshots) {
//            requestSoundByUrl(snapshot.sound);
//            _snapshot = snapshot;
//            repaint();
//            QEventLoop loop;
//            QTimer::singleShot(300, &loop, &QEventLoop::quit);
//            loop.exec(QEventLoop::ExcludeUserInputEvents);
//        }
//        _ally.snapshots.clear();
//        _snapshot = fieldView(_ally, _enemy);
//        repaint();
//    } else if (_enemy.cardStack.size()) {
//        for (const FieldView &snapshot : _enemy.snapshots) {
//            requestSoundByUrl(snapshot.sound);
//            _snapshot = snapshot;
//            repaint();
//            QEventLoop loop;
//            QTimer::singleShot(300, &loop, &QEventLoop::quit);
//            loop.exec(QEventLoop::ExcludeUserInputEvents);
//        }
//        _enemy.snapshots.clear();
//        _snapshot = fieldView(_enemy, _ally);
//        repaint();
//    }
}
