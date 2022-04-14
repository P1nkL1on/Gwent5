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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    _networkAccessManager = new QNetworkAccessManager(this);
    connect(_networkAccessManager, &QNetworkAccessManager::finished, this, &MainWindow::onImageRequestFinished);


    const std::vector<Card *> deckStarting = {
        new Vaedermakar, new Vaedermakar, new Vaedermakar,
        new Decoy, new Decoy, new Decoy,
        new ShupesDayOff, new ShupesDayOff, new ShupesDayOff,
        new Frightener, new Ambassador, new Assassin, new AdrenalineRush, new AdrenalineRush,
        new PoorFingInfantry, new KeiraMetz, new KeiraMetz, new KeiraMetz, new Mandrake, new Mandrake
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
    for (int i = 10; i <= 15; ++i) {
        auto *c = new Card;
        c->name = "Dummy";
        c->url = "https://gwent.one/image/card/low/cid/png/113201.png";
        c->power = c->powerBase = i;
        _ally.rowMeele.push_back(c);
    }
    for (int i = 10; i <= 15; ++i) {
        auto *c = new Card;
        c->name = "Dummy";
        c->url = "https://gwent.one/image/card/low/cid/png/113201.png";
        c->power = c->powerBase = i;
        _enemy.rowMeele.push_back(c);
    }


    resize(600, 450);
    setMouseTracking(true);
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
            for (size_t i = 0; i < ally.snapshot().cardOptions.size(); ++i) {
                const QRectF cardRect = QRectF(i * posWidth, 2 * _layout.spacingPx + 7 * posHeight, posWidth, posHeight).translated(rect.topLeft());
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
        const QString string = QString("Turn %1: %2").arg(1 + ally.nTurns).arg(QString::fromStdString(stringSnapShots(ally.cardStack)));
        const QPointF topLeft(metrics.width(string) + _layout.borderTextPx, 2 * _layout.spacingPx + 7 * posHeight - metrics.height());
        const QRectF rectRes = QRectF(topLeft, QSizeF(metrics.width("Finish Choice"), metrics.height())).translated(rect.topLeft());
        return rectRes.contains(point);
    };

    const auto topLeftOf = [=](const Card *card) -> QPointF {
        Row row;
        Pos pos;
        if (rowAndPos(card, ally, row, pos))
            return QPointF(pos * posWidth, _layout.spacingPx + (row + 4) * posHeight);
        if (rowAndPos(card, enemy, row, pos))
            return QPointF(pos * posWidth, _layout.spacingPx + (3 - row) * posHeight);
        return QPointF(0, 0);
    };

    const auto popAnimations = [=, &ally] {
        while (ally.animations.size() > 0) {
            const Animation *animation = ally.animations.front();
            const std::string sound = animation->sound;
            requestSoundByUrl(sound);

            switch (animation->type) {
            default:
                Q_ASSERT(false);
                break;
            case Animation::Spawn:
                qDebug().noquote() << QString::fromStdString(animation->src->name) << "spawned";
                break;
            case Animation::Draw:
                qDebug().noquote() << QString::fromStdString(animation->src->name) << "drawned";
                break;
            case Animation::PlaySpecial:
                qDebug().noquote() << QString::fromStdString(animation->src->name) << "played special";
                break;
            case Animation::PutOnField:
                qDebug().noquote() << QString::fromStdString(animation->src->name) << "puted on field";
                break;
            case Animation::ArmorLost:
                qDebug().noquote() << QString::fromStdString(animation->src->name) << "armor lost";
                break;
            case Animation::ArmorGain:
                qDebug().noquote() << QString::fromStdString(animation->src->name) << "armor gained";
                break;
            case Animation::Damage: {
//                auto *_variantAnimation = new QVariantAnimation(this);
//                _variantAnimation->setStartValue(QSize(0, 0));
//                _variantAnimation->setStartValue(QSize(30, 30));
//                _variantAnimation->setDuration(2000);
//                _variantAnimation->setEasingCurve(QEasingCurve::Linear);
//                QEventLoop loop;
//                connect(_variantAnimation, &QVariantAnimation::valueChanged, this, [=](const QVariant &variant) {
//                    qDebug() << "variant" << variant;
//                    repaint();
//                });
//                connect(_variantAnimation, &QVariantAnimation::finished, &loop, &QEventLoop::quit);
//                _variantAnimation->start();
//                loop.exec(QEventLoop::AllEvents);
                qDebug().noquote() << QString::fromStdString(animation->src->name) << "damaged";
                break;
            }
            case Animation::Boost:
                qDebug().noquote() << QString::fromStdString(animation->src->name) << "boosted";
                break;
            case Animation::Strengthen:
                qDebug().noquote() << QString::fromStdString(animation->src->name) << "strenthened";
                break;
            case Animation::Weaken:
                qDebug().noquote() << QString::fromStdString(animation->src->name) << "weakened";
                break;
            }

            ally.animations.erase(ally.animations.begin());
        }
    };

    if (ally.cardStack.size() == 0)
        return;

    if (ally.snapshot().choice == RoundStartPlay) {
        if (ally.snapshot().isOptional && isFinishChoiceButton(point)) {
            onChoiceDoneCard(nullptr, ally, enemy);
            tryFinishTurn(ally, enemy);
            repaint();
            popAnimations();
            return;
        }
        Card *card = cardAt(point);
        if (card == nullptr || !isIn(card, ally.snapshot().cardOptions))
            return;
        onChoiceDoneCard(card, ally, enemy);
        tryFinishTurn(ally, enemy);
        repaint();
        popAnimations();
        return;
    }

    if (ally.snapshot().choice == Target) {
        if (ally.snapshot().isOptional && isFinishChoiceButton(point)) {
            onChoiceDoneCard(nullptr, ally, enemy);
            tryFinishTurn(ally, enemy);
            repaint();
            popAnimations();
            return;
        }
        Card *card = cardAt(point);
        if (card == nullptr || !isIn(card, ally.snapshot().cardOptions))
            return;
        onChoiceDoneCard(card, ally, enemy);
        tryFinishTurn(ally, enemy);
        repaint();
        popAnimations();
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
        popAnimations();
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
        popAnimations();
        return;
    }

    if (ally.snapshot().choice == SelectAllyRow) {
        Row row;
        if (!rowAt(true, point, row))
            return;
        onChoiceDoneRow(row, ally, enemy);
        tryFinishTurn(ally, enemy);
        repaint();
        popAnimations();
        return;
    }

    if (ally.snapshot().choice == SelectEnemyRow) {
        Row row;
        if (!rowAt(false, point, row))
            return;
        onChoiceDoneRow(row, ally, enemy);
        tryFinishTurn(ally, enemy);
        repaint();
        popAnimations();
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
        popAnimations();
        return;
    }

    Q_ASSERT(false);
}

void MainWindow::paintInRect(const QRect rect, Field &ally, Field &enemy)
{
    if (rect.width() < _layout.spacingPx * 2)
        return;

    if (rect.height() < _layout.spacingPx * 2)
        return;

    const double posWidth = (rect.width() - 2 * _layout.spacingPx) / 11.0;
    const double posHeight = (rect.height() - 2 * _layout.spacingPx) / 8.0;

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

    const auto paintCard = [=, &painter](const Card *card, const QPointF &topLeft)
    {
        Q_ASSERT(!card->isAmbush);
        const QSizeF size(posWidth, posHeight);
        const QRectF rect(topLeft, size);
        painter.setPen(Qt::black);
        painter.drawRect(rect);

        const QRectF rectBorder = QRectF(rect).marginsRemoved(QMarginsF(_layout.borderCardPx, _layout.borderCardPx, _layout.borderCardPx, _layout.borderCardPx));

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

        /// draw power
        double width = 0;
        if (card->power) {
            const Qt::GlobalColor back = card->power > card->powerBase ? Qt::green : card->power < card->powerBase ? Qt::red : Qt::gray;
            const Qt::GlobalColor fore = card->power > card->powerBase ? Qt::darkGreen : card->power < card->powerBase ? Qt::darkRed : Qt::black;
            width += paintTextInPoint(QString::number(card->power), topLeft, back, fore);
            width += _layout.borderTextPx;
        }

        /// draw armor
        if (card->armor) {
            width += paintTextInPoint("A" + QString::number(card->armor), QPointF(topLeft.x() + width, topLeft.y()), Qt::yellow, Qt::black);
            width += _layout.borderTextPx;
        }

        if (card->isLocked) {
            width += paintTextInPoint("LOCKED", QPointF(topLeft.x() + width, topLeft.y()), Qt::black, Qt::white);
            width += _layout.borderTextPx;
        }

        if (card->timer) {
            width += paintTextInPoint("T" + QString::number(card->timer), QPointF(topLeft.x() + width, topLeft.y()), Qt::cyan, Qt::black);
            width += _layout.borderTextPx;
        }

        if (card->isSpy) {
            width += paintTextInPoint("SPY", QPointF(topLeft.x() + width, topLeft.y()), Qt::white, Qt::red);
            width += _layout.borderTextPx;
        }

        if (card->isResilient) {
            width += paintTextInPoint("RESILIENCE", QPointF(topLeft.x() + width, topLeft.y()), Qt::white, Qt::darkGreen);
            width += _layout.borderTextPx;
        }

        if (card->isImmune) {
            width += paintTextInPoint("IMMUNE", QPointF(topLeft.x() + width, topLeft.y()), Qt::black, Qt::green);
            width += _layout.borderTextPx;
        }

        if (card->isDoomed) {
            width += paintTextInPoint("DOOMED", QPointF(topLeft.x() + width, topLeft.y()), Qt::black, Qt::cyan);
            width += _layout.borderTextPx;
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
            const QPointF topLeft = rect.topLeft() + QPointF(i * posWidth, _layout.spacingPx + (j + 1) * posHeight);

            if (i >= count) {
                const QRectF rect = QRectF(topLeft, QSizeF(posWidth, posHeight)).marginsRemoved(QMarginsF(_layout.borderCardPx, _layout.borderCardPx, _layout.borderCardPx, _layout.borderCardPx));
                const bool canBePlaced = (ally.cardStack.size()) && ((ally.snapshot().choice == SelectAllyRowAndPos && j >= 3) || (ally.snapshot().choice == SelectEnemyRowAndPos && j < 3)) && (i < count + 1);
                painter.setPen(canBePlaced ? Qt::green : Qt::gray);
                painter.drawRect(rect);
                continue;
            }

            const Card *card = cards.at(i);
            if (card->isAmbush) {
                paintCardHidden(topLeft);
                continue;
            }

            paintCard(card, topLeft);
        }

        const int power = powerRow(cards);
        paintTextInPoint(QString::number(power), rect.topLeft() + QPointF(9 * posWidth, _layout.spacingPx + (j + 1) * posHeight));

        /// draw a row back
        const QRectF rowRect = QRectF(0, _layout.spacingPx + (j + 1) * posHeight + metrics.height(), posWidth * 9, posHeight - 2 *  metrics.height()).translated(rect.topLeft());
        const RowEffect rowEffect = (j == 0 || j == 5) ? field->rowEffectSeige : (j == 1 || j == 4) ? field->rowEffectRange : field->rowEffectMeele;
        switch (rowEffect) {
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
        const QString stringStatus = QString::fromStdString(stringSnapShots(ally.cardStack));
        const QString stringTurn = QString::number(1 + ally.nTurns);
        double statusWidth = 0;
        if ((ally.cardStack.size() > 0)){
            statusWidth += paintTextInPoint("Turn " + stringTurn + ": " + stringStatus, rect.topLeft() + QPointF(0, 2 * _layout.spacingPx + 7 * posHeight - metrics.height()), Qt::gray) + _layout.borderTextPx;
        }
        if ((ally.cardStack.size() > 0) && ally.snapshot().isOptional) {
            statusWidth += paintTextInPoint("Finish Choice", rect.topLeft() + QPointF(statusWidth, 2 * _layout.spacingPx + 7 * posHeight - metrics.height()), Qt::black, Qt::white) + _layout.borderTextPx;
        }
        if (ally.cardStack.size() > 0) {
            for (size_t i = 0; i < ally.snapshot().cardOptions.size(); ++i) {
                const QPointF topLeft = rect.topLeft() + QPointF(i * posWidth, 2 * _layout.spacingPx + 7 * posHeight);
                paintCard(ally.snapshot().cardOptions[i], topLeft);
            }
            if ((ally.snapshot().cardSource != nullptr)) {
                Row row;
                Pos pos;
                QPointF topLeft;
                if (rowAndPos(ally.snapshot().cardSource, ally, row, pos)) {
                    topLeft = rect.topLeft() + QPointF(pos * posWidth, _layout.spacingPx + (4 + row) * posHeight);
                } else if (rowAndPos(ally.snapshot().cardSource, enemy, row, pos)) {
                    topLeft = rect.topLeft() + QPointF(pos * posWidth, _layout.spacingPx + (3 - row) * posHeight);
                } else {
                    topLeft = rect.topLeft() + QPointF(_layout.spacingPx + 9 * posWidth, _layout.spacingPx + 4 * posHeight);
                    paintCard(ally.snapshot().cardSource, topLeft);
                }
                if (!_pos.isNull()) {
                    painter.setPen(Qt::cyan);
                    const QPointF center = topLeft + QPointF(posWidth * 0.5, posHeight * 0.5);
                    painter.drawLine(_pos, center);
                }
            }
        }
    } else if (_view == ViewHand) {
        const QString stringStatus = QString("Hand (%1):").arg(ally.hand.size());
        paintTextInPoint(stringStatus, rect.topLeft() + QPointF(0, 2 * _layout.spacingPx + 7 * posHeight - metrics.height()), Qt::gray);
        for (size_t i = 0; i < ally.hand.size(); ++i) {
            const QPointF topLeft = rect.topLeft() + QPointF(i * posWidth, 2 * _layout.spacingPx + 7 * posHeight);
            paintCard(ally.hand[i], topLeft);
        }
    } else if (_view == ViewDiscard) {
        const QString stringStatus = QString("Discard (%1):").arg(ally.discard.size());
        paintTextInPoint(stringStatus, rect.topLeft() + QPointF(0, 2 * _layout.spacingPx + 7 * posHeight - metrics.height()), Qt::gray);
        for (size_t i = 0; i < ally.discard.size(); ++i) {
            const QPointF topLeft = rect.topLeft() + QPointF(i * posWidth, 2 * _layout.spacingPx + 7 * posHeight);
            paintCard(ally.discard[i], topLeft);
        }
    } else if (_view == ViewDeck) {
        const QString stringStatus = QString("Deck (%1):").arg(ally.deck.size());
        paintTextInPoint(stringStatus, rect.topLeft() + QPointF(0, 2 * _layout.spacingPx + 7 * posHeight - metrics.height()), Qt::gray);
        for (size_t i = 0; i < ally.deck.size(); ++i) {
            const QPointF topLeft = rect.topLeft() + QPointF(i * posWidth, 2 * _layout.spacingPx + 7 * posHeight);
            paintCardHidden(topLeft);
        }
    } else {
        Q_ASSERT(false);
    }

    paintTextInPoint(QString("Ally: %1%2").arg(powerField(ally)).arg(ally.passed ? " PASS" : ""), QPointF(0, 0), Qt::black, Qt::cyan);
    paintTextInPoint(QString("Enemy: %1%2").arg(powerField(enemy)).arg(enemy.passed ? " PASS" : ""), QPointF(0, 15), Qt::black, Qt::red);
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
    const QRect rect = this->rect().marginsRemoved(QMargins(10, 10, 100, 10));

    if (e->type() == QEvent::MouseButtonPress) {
        auto *em = static_cast<QMouseEvent *>(e);
        if (_ally.cardStack.size())
            mouseClick(rect, em->pos(), _ally, _enemy);
        else if (_enemy.cardStack.size())
            mouseClick(rect, em->pos(), _enemy, _ally);
    }

    if (e->type() == QEvent::MouseMove) {
        auto *em = static_cast<QMouseEvent *>(e);
        if (_ally.cardStack.size() && _ally.snapshot().cardSource != nullptr) {
            _pos = em->pos();
            repaint();
        } else if (_enemy.cardStack.size() && _enemy.snapshot().cardSource != nullptr) {
            _pos = em->pos();
            repaint();
        } else {
            _pos = QPoint();
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
            repaint();
        }
    }

    return QMainWindow::eventFilter(o, e);
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    const QRect rect = e->rect().marginsRemoved(QMargins(10, 10, 100, 10));

    if (_ally.cardStack.size())
        paintInRect(rect, _ally, _enemy);
    else if (_enemy.cardStack.size())
        paintInRect(rect, _enemy, _ally);
}
