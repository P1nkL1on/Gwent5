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
#include <QHBoxLayout>
#include <QPointer>
#include <QMenuBar>
#include <QScrollBar>
#include <qfiledialog.h>

#include "Cards/demos.h"
#include "Cards/io.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    _networkAccessManager = new QNetworkAccessManager(this);
    connect(_networkAccessManager, &QNetworkAccessManager::finished, this, &MainWindow::onImageRequestFinished);

    auto *w = new QWidget;
    auto *l = new QHBoxLayout;
    w->setLayout(l);
    l->addStretch(3);
    l->addWidget(_textAlly = new QTextEdit, 1);
    l->addWidget(_textEnemy = new QTextEdit, 1);
    _textAlly->setReadOnly(true);
    _textEnemy->setReadOnly(true);
    w->setAttribute(Qt::WA_TransparentForMouseEvents);
    setCentralWidget(w);

    using Demo = std::function<void(Field &, Field &)>;
    const std::vector<std::pair<std::string, Demo>> demoTitleToMethod {
        {"Nilfgaard's Soldiers Deck", demoNilfgaardSoldiersDeck},
        {"Skellige's Veteran Deck", demoSkelligeVeteransPrimeDeck},
        {"Nilfgaard's Reveal Deck VS Nothern Realms' Armor Deck", demoNilfgaardReveal},
        {"Skellige's Discard Deck VS Nothern Realms' Armor Deck", demoVsSkelligeDiscardVsNothernRealmsArmor},
        {"Transformation", demoTransforms},
        //{"Instant Log Effects", demoInstantEffects},
        {"Spawning and Summoning", demoSpawnAndSummon},
        {"Single-Use (Frightener)", demoSingleUseFrightener},
        //{"Ambushes & Invisible Timers", demoAmbushes},
        //{"Charming Happy Case", demoCharm},
        //{"Rock Barrage", demoRockBarrage},
        //{"Row Movement", demoMoving},
        //{"Runestones Generation", demoRunestones},
        //{"Reveal Leo Bonhart", demoLeoBonhart},
        //{"Locking The Deathwish", demoLockingDeathwish},
        //{"Monsters Leaders", demoMonsterLeaders},
        //{"Monsters Sisters", demoMonsterSisters},
        //{"Monsters Summoning", demoSummoning},
        //{"Last Played Card", demoLastPlayed},
        //{"Blue Stripes", demoBlueStripes},
        //{"New Big Ogrs vs some Skellige", demoBigOgrs},
        {"Wild Hunt", demoWildHunt},
        {"Archespore demo", demoArchesporeJumping},
        //{"Party against Devil Lord", demoImlerithSabbath},
        //{"Consume demo", demoConsume},
        //{"Temporary demo", demoTemporaryForTests},
        //{"Nekker Warrior", demoNekkerWarrior},
        {"Nekkers", demoNekkers},
        //{"Arachas Drones", demoArachasDrones},
        //{"Slyzards", demoSlyzards},
        //{"Avalach", demoAvalach},
        //{"Bears and Beer", demoBeer},
        {"Crew and Crewed", demoCrewAndCrewed},
        //{"She-Troll of Vergen", demoSheTrollOfVergen},
        //{"Sigismund Dijkstra", demoSigismundDijkstra},
        //{"Rows Selection", demoRowsSelection},
        //{"Wolfsbane", demoWolfsbane},
        {"Deck Summon", demoDeckSummon},
        {"Turn and Round Finishing", demoTurnFinishingAndRoundFinishing},
        {"Every Choice Types", demoAllTypedChoices},
        //{"Neutral Specials", demoNeutralSpecial},
        //{"Gold Witchers", demoGoldWitchers},
        //{"Regis", demoNeutralDudes},
        {"PowerChanged demo", demoPowerChanged},
        //{"Saskia", demoAedirnDragon},
        {"Leaders test", demoLeaders},
        //{"Dwarfs pack of dudes", demoDwarws},
        {"Pack of smoothy elves", demoSwapElves},
        {"Option 1 bug case", demoWithOpion1},
        {"Window 3/3 of 5", demoWithWindow5},
        {"Empty should resolve to Draw", demoEmpty},
        {"Trigger Order", demoTriggersOrder},
        {"Temporary Nilfgaard-ian table", demoNilfsTemporary},
        {"PANTHERAAAA", demoPanther},
        {"Nilfgaard Mages and Hefty Heldge", demoNilfgaardMages},
        {"Northen Deck Buff", demoNothern},
        {"Treason VS Ambush", demoTreason},
    };

    /// make a choosing menu for it
    QMenu *menuDemos = new QMenu("Demos");
    QList<QAction *> actions;
    for (const auto &it : demoTitleToMethod) {
        const QString title = QString::fromStdString(it.first);
        QAction *action = menuDemos->addAction(title, this, [=]{
            _textAlly->clear();
            _textEnemy->clear();
            initField({}, nullptr, _ally);
            initField({}, nullptr, _enemy);
            it.second(_ally, _enemy);
            repaintCustom();
        });
        actions.push_back(action);
    }

    QAction *loadDeck = new QAction("Load Deck...");
    connect(loadDeck, &QAction::triggered, this, &MainWindow::openLoadDialog);
    loadDeck->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));

    QMenuBar *menuBar = new QMenuBar(this);
    menuBar->addAction(loadDeck);
    menuBar->addMenu(menuDemos);
    setMenuBar(menuBar);

    resize(1400, 800);
    setMouseTracking(true);
    installEventFilter(this);

    /// trigger last exist demo
    if (!actions.isEmpty())
        actions.last()->trigger();
}

QMargins MainWindow::margins() const
{
    return QMargins(10, 10, int(width() * 0.4) + 20, 10);
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
    // NOTE: tmp disabled sound requests
    return;

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

        if (!ally.cardStack2.isEmpty()) {
            for (size_t i = 0; i < ally.cardStack2.peek().options.size(); ++i) {
                const QRectF cardRect = QRectF(i * posWidth, 2 * _layout.spacingPx + 7 * posHeight, posWidth, posHeight).translated(rect.topLeft());
                if (cardRect.contains(point))
                    return ally.cardStack2.peek().options[i];
            }
        }
        return nullptr;
    };

    const auto rowAndPostAt = [=](const bool ally, const QPoint &point) -> RowAndPos {
        const int jFrom = ally ? 3 : 0;
        const int jTo = ally ? 6 : 3;
        for (int j = jFrom; j < jTo; ++j) {
            const Row _row = Row(j < 3 ? (2 - j) : (j - 3));
            for (size_t i = 0; i < 9; ++i) {
                const QRectF cardRect = QRectF(i * posWidth, _layout.spacingPx + (j + 1) * posHeight, posWidth, posHeight).translated(rect.topLeft());
                if (cardRect.contains(point))
                    return RowAndPos(_row, Pos(i));
            }
        }
        return RowAndPos();
    };

    const auto screenRowAt = [=](const QPoint &point, int &screenRow) -> bool {
        for (int rowInd = 0; rowInd < 6; ++rowInd) {
            const QRectF rowRect = QRectF(0, _layout.spacingPx + (rowInd + 1) * posHeight, posWidth * 9, posHeight).translated(rect.topLeft());
            if (rowRect.contains(point)) {
                screenRow = 5 - rowInd;
                return true;
            }
        }
        return false;
    };

    const auto isFinishChoiceButton = [=](const QPoint &point) {
        const QFontMetricsF metrics(QFont{});
        const QPointF topLeft(_layout.borderTextPx, 2 * _layout.spacingPx + 7 * posHeight - metrics.height());
        const QRectF rectRes = QRectF(topLeft, QSizeF(metrics.width("Finish Choice"), metrics.height())).translated(rect.topLeft());
        return rectRes.contains(point);
    };

    const auto topLeftOf = [=](const Card *card) -> QPointF {
        Row row;
        Pos pos;
        if (_findRowAndPos(card, ally, row, pos))
            return rect.topLeft() + QPointF(pos * posWidth, _layout.spacingPx + (row + 4) * posHeight);
        if (_findRowAndPos(card, enemy, row, pos))
            return rect.topLeft() + QPointF(pos * posWidth, _layout.spacingPx + (3 - row) * posHeight);
        return rect.topLeft() + QPointF(_layout.spacingPx + 9 * posWidth, _layout.spacingPx + 4 * posHeight);
    };

    if (ally.cardStack2.isEmpty())
        return;

    if (ally.cardStack2.peek().type == CardRoundStartPlay) {
        if (ally.cardStack2.peek().isOptional && isFinishChoiceButton(point)) {
            onChoiceDoneCard(nullptr, ally, enemy);
            goto finish_turn;
        }
        Card *card = cardAt(point);
        if (card == nullptr || !isIn(card, ally.cardStack2.peek().options))
            return;
        onChoiceDoneCard(card, ally, enemy);
        goto finish_turn;
    }

    if (ally.cardStack2.peek().type == CardTarget || ally.cardStack2.peek().type == CardOption) {
        if (ally.cardStack2.peek().isOptional && isFinishChoiceButton(point)) {
            onChoiceDoneCard(nullptr, ally, enemy);
            goto finish_turn;
        }
        Card *card = cardAt(point);
        if (card == nullptr || !isIn(card, ally.cardStack2.peek().options))
            return;
        onChoiceDoneCard(card, ally, enemy);
        goto finish_turn;
    }

    if (ally.cardStack2.peek().type == RowAndPosAlly) {
        const RowAndPos rowAndPos = rowAndPostAt(true, point);
        if (!isOkRowAndPos(rowAndPos, ally))
            return;
        onChoiceDoneRowAndPlace(rowAndPos, ally, enemy);
        goto finish_turn;
    }

    if (ally.cardStack2.peek().type == RowAndPosEnemy) {
        const RowAndPos rowAndPos = rowAndPostAt(false, point);
        if (!isOkRowAndPos(rowAndPos, ally))
            return;
        onChoiceDoneRowAndPlace(rowAndPos, ally, enemy);
        goto finish_turn;
    }

    if (ally.cardStack2.peek().type == RowSelect) {
        int screenRow;
        if (screenRowAt(point, screenRow) && std::find(ally.cardStack2.peek().screenRows.begin(), ally.cardStack2.peek().screenRows.end(), screenRow) != ally.cardStack2.peek().screenRows.end())
            onChoiceDoneRow(screenRow, ally, enemy);
        goto finish_turn;
    }

    if (ally.cardStack2.peek().type == CardRoundStartSwap) {
        if (isFinishChoiceButton(point)) {
            onChoiceDoneRoundStartSwap(nullptr, ally, enemy);
            repaintCustom();
            return;
        }
        Card *card = cardAt(point);
        if (card == nullptr || !isIn(card, ally.cardStack2.peek().options))
            return;
        onChoiceDoneRoundStartSwap(card, ally, enemy);
        repaintCustom();
        return;
    }

    Q_ASSERT(false);

finish_turn:
    tryFinishTurn(ally, enemy);

    repaintCustom();
}

void MainWindow::paintInRect(const QRect rect, const FieldView &view)
{
    if (rect.width() < _layout.spacingPx * 2)
        return;

    if (rect.height() < _layout.spacingPx * 2)
        return;

    const ChoiceView *currentChoiceView = view.choices.size() ? &view.choices.front() : nullptr;

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

    const QMap<int, QString> rarityToBorderUrl {
        {Bronze, "https://gwent.one/image/card/medium/assets/open-beta/border-bronze.png"},
        {Silver, "https://gwent.one/image/card/medium/assets/open-beta/border-silver.png"},
        {Gold, "https://gwent.one/image/card/medium/assets/open-beta/border-gold.png"},
    };
    const QMap<int, QString> factionToSilverCornerUrl {
        {Neutral, "https://gwent.one/image/card/medium/assets/open-beta/banner-sb-nt.png"},
        {NothernRealms, "https://gwent.one/image/card/medium/assets/open-beta/banner-sb-nr.png"},
        {Monster, "https://gwent.one/image/card/medium/assets/open-beta/banner-sb-mo.png"},
        {Nilfgaard, "https://gwent.one/image/card/medium/assets/open-beta/banner-sb-ng.png"},
        {Scoiatael, "https://gwent.one/image/card/medium/assets/open-beta/banner-sb-st.png"},
        {Skellige, "https://gwent.one/image/card/medium/assets/open-beta/banner-sb-sk.png"},
    };
    const QMap<int, QString> factionToGoldCornerUrl {
        {Neutral, "https://gwent.one/image/card/medium/assets/open-beta/banner-g-nt.png"},
        {NothernRealms, "https://gwent.one/image/card/medium/assets/open-beta/banner-g-nr.png"},
        {Monster, "https://gwent.one/image/card/medium/assets/open-beta/banner-g-mo.png"},
        {Nilfgaard, "https://gwent.one/image/card/medium/assets/open-beta/banner-g-ng.png"},
        {Scoiatael, "https://gwent.one/image/card/medium/assets/open-beta/banner-g-st.png"},
        {Skellige, "https://gwent.one/image/card/medium/assets/open-beta/banner-g-sk.png"},
    };
    const auto paintCardLarge = [=, &painter](const CardView &cardView, const QRectF &rect)
    {
        const double wa = 97 / 130.0;
        const double wb = 30 / 130.0;
        const double ha = 138 / 163.0;
        const double hb = 22 / 163.0;
        const QPointF topLeft(rect.left() + rect.width() * wb, rect.top() + rect.height() * hb);
        const QSizeF size(rect.width() * wa, rect.height() * ha);
        const QRectF rectImage(topLeft, size);

        if (cardView.url.size() > 0) {
            requestImageByUrl(cardView.url);
            const QImage image = _pixMapsLoaded.value(QString::fromStdString(cardView.url));
            painter.drawImage(rectImage, image);
        }
        {
            const QString borderUrl = rarityToBorderUrl.value(cardView.rarity);
            requestImageByUrl(borderUrl.toStdString());
            const QImage image = _pixMapsLoaded.value(borderUrl);
            painter.drawImage(rect, image);
        }
        {
            const QString cornerUrl = cardView.rarity == Gold ? factionToGoldCornerUrl.value(cardView.faction) : factionToSilverCornerUrl.value(cardView.faction);
            requestImageByUrl(cornerUrl.toStdString());
            const QImage image = _pixMapsLoaded.value(cornerUrl);
            painter.drawImage(rect, image);
        }
    };
    const auto paintCard = [=, &painter](const CardView &cardView, const QPointF &topLeft)
    {
        const QSizeF size(posWidth, posHeight);
        const QRectF rect(topLeft, size);
        painter.setPen(Qt::black);
        painter.drawRect(rect);

        const QRectF rectBorder = QRectF(rect).marginsRemoved(QMarginsF(_layout.borderCardPx, _layout.borderCardPx, _layout.borderCardPx, _layout.borderCardPx));

        /// draw url image
        if (cardView.isVisible && (cardView.url.size() > 0)) {
            requestImageByUrl(cardView.url);
            const QImage image = _pixMapsLoaded.value(QString::fromStdString(cardView.url));
            painter.drawImage(rectBorder, image);
        }

        /// draw rarity
        if (cardView.isVisible) {
            painter.setPen(cardView.rarity == Bronze ? Qt::darkRed : cardView.rarity == Silver ? Qt::gray : Qt::yellow);
            painter.drawRect(rectBorder);
        }

        /// draw selection border
        if (view.choices.size() && isIn(cardView.id, view.choices.front().cardOptionIds)) {
            painter.setPen(Qt::green);
            painter.drawLine(rect.topLeft(), rect.bottomRight());
            painter.drawLine(rect.topRight(), rect.bottomLeft());
        }

        /// draw selected border
        if (view.choices.size() && isIn(cardView.id, view.choices.front().cardOptionIdsSelected)) {
            painter.setPen(Qt::red);
            painter.drawLine(rect.topLeft(), rect.bottomRight());
            painter.drawLine(rect.topRight(), rect.bottomLeft());
        }

        /// draw source border
        if (view.choices.size() && (cardView.id == view.choices.front().cardSourceId)) {
            painter.setPen(Qt::cyan);
            painter.drawLine(rect.topLeft(), rect.bottomRight());
            painter.drawLine(rect.topRight(), rect.bottomLeft());
        }

        if (!cardView.isVisible)
            /// TODO: draw a card back
            return;

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
            width += paintTextInPoint("X", QPointF(topLeft.x() + width, topLeft.y()), Qt::black, Qt::white);
            width += _layout.borderTextPx;
        }

        if (cardView.timer > 0) {
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
            width += paintTextInPoint("*", QPointF(topLeft.x() + width, topLeft.y()), Qt::black, Qt::cyan);
            width += _layout.borderTextPx;
        }

        if (cardView.isRevealed) {
            width += paintTextInPoint("REVEALED", QPointF(topLeft.x() + width, topLeft.y()), Qt::black, Qt::yellow);
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
        paintCardLarge(cardView, QRectF(QPointF(posWidth * 9 + _layout.spacingPx, posHeight * 1 + _layout.spacingPx) + rect.topLeft(), QSizeF(posWidth * 2 + _layout.spacingPx, posHeight * 2)));

        QString tags;
        for (const Tag tag : cardView.tags)
            tags += (tags.isEmpty() ? "" : ", ") + QString::fromStdString(stringTag(tag));

        QStringList infos {
            QString("Name: %1").arg(QString::fromStdString(cardView.name)),
            QString("Faction: %1").arg(QString::fromStdString(stringTag(Tag(cardView.faction)))),
            QString("Tags: %1").arg(tags),
            QString("Text: %1").arg(QString::fromStdString(cardView.text)),
            QString("Power = %1").arg(cardView.power),
            QString("Power Base = %1").arg(cardView.powerBase),
            QString("Armor = %1").arg(cardView.armor),
            QString("Locked? %1").arg(cardView.isLocked ? "True" : "False"),
            QString("Resilient? %1").arg(cardView.isResilient ? "True" : "False"),
            QString("Spying? %1").arg(cardView.isSpy ? "True" : "False"),
            QString("Immune? %1").arg(cardView.isImmune ? "True" : "False"),
            QString("Doomed? %1").arg(cardView.isDoomed ? "True" : "False"),
            QString("Revealed? %1").arg(cardView.isRevealed? "True" : "False"),
        };
        for (const auto &it : keywordDescriptions())
            if (cardView.text.find(it.first) != std::string::npos)
                infos.append(QString("%1: %2").arg(QString::fromStdString(it.first), QString::fromStdString(it.second)));

        for (int i = 0; i < infos.size(); ++i)
            paintTextInPoint(infos[i], topLeft + QPointF(0, 2 * posHeight + i * metrics.height()), Qt::white, Qt::black);
    }
    // TODO: tmp remove all above
    // __________________________



    for (int rowInd = 0; rowInd < 6; ++rowInd) {
        for (size_t posInd = 0; posInd < 9; ++posInd) {
            const QPointF topLeft = rect.topLeft() + QPointF(posInd * posWidth, _layout.spacingPx + (rowInd + 1) * posHeight);
            int id;
            int n;
            if (!view.idAtRowAndPos(Row(rowInd), Pos(posInd), &id, &n)) {
                const QRectF rect = QRectF(topLeft, QSizeF(posWidth, posHeight)).marginsRemoved(QMarginsF(_layout.borderCardPx, _layout.borderCardPx, _layout.borderCardPx, _layout.borderCardPx));
                const bool canBePlaced = currentChoiceView && ((currentChoiceView->choiceType == RowAndPosAlly && rowInd >= 3) || (currentChoiceView->choiceType == RowAndPosEnemy && rowInd < 3)) && (posInd <= n);
                painter.setPen(Qt::gray);
                painter.drawRect(rect);
                if (canBePlaced) {
                    painter.setPen(Qt::green);
                    painter.drawLine(rect.topLeft(), rect.bottomRight());
                    painter.drawLine(rect.topRight(), rect.bottomLeft());
                }
            } else {
                const CardView &cardView = view.cardView(id);
                paintCard(cardView, topLeft);
            }
        }

        // TODO: return showing a power
        paintTextInPoint(QString::number(view.rowPower(Row(rowInd))), rect.topLeft() + QPointF(9 * posWidth, _layout.spacingPx + (rowInd + 1) * posHeight));

        /// draw a row back
        const QRectF rowRect = QRectF(0, _layout.spacingPx + (rowInd + 1) * posHeight + metrics.height(), posWidth * 9, posHeight - 2 *  metrics.height()).translated(rect.topLeft());
        switch (view.rowEffect(Row(rowInd))) {
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
            painter.fillRect(rowRect, QBrush(Qt::darkBlue, Qt::HorPattern));
            break;
        case DragonsDreamEffect:
            painter.fillRect(rowRect, QBrush(Qt::darkCyan, Qt::HorPattern));
            break;
        case KorathiHeatwaveEffect:
            painter.fillRect(rowRect, QBrush(Qt::red, Qt::Dense5Pattern));
            break;
        case RaghNarRoogEffect:
            painter.fillRect(rowRect, QBrush(Qt::darkMagenta, Qt::Dense4Pattern));
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

        const bool canBePlaced = currentChoiceView
                && (currentChoiceView->choiceType == RowSelect)
                && (std::find(currentChoiceView->valuesOptions.begin(), currentChoiceView->valuesOptions.end(), 5 - rowInd) != currentChoiceView->valuesOptions.end());
        if (canBePlaced) {
            painter.setPen(Qt::green);
            painter.drawLine(rowRect.topLeft(), rowRect.bottomRight());
            painter.drawLine(rowRect.topRight(), rowRect.bottomLeft());
        }
    }

    static_assert(View_count == 9, "");
    if (_view == ViewStack) {
        double statusWidth = 0;
        if (currentChoiceView && currentChoiceView->isOptional) {
            statusWidth += paintTextInPoint("Finish Choice", rect.topLeft() + QPointF(statusWidth, 2 * _layout.spacingPx + 7 * posHeight - metrics.height()), Qt::black, Qt::white) + _layout.borderTextPx;
        }
        if (currentChoiceView){
            const QString stringStatus = QString::fromStdString(currentChoiceView->toString());
            const QString stringTurn = QString::number(1 + view.nTurns);
            statusWidth += paintTextInPoint("Turn " + stringTurn + ": " + stringStatus, rect.topLeft() + QPointF(statusWidth, 2 * _layout.spacingPx + 7 * posHeight - metrics.height()), Qt::gray) + _layout.borderTextPx;
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
    } else {
        QString title;
        const std::vector<int> *ids = nullptr;
        if (_view == ViewHand) {
            title = "Hand";
            ids = &view.allyHandIds;

        } else if (_view == ViewDiscard) {
            title = "Discard";
            ids = &view.allyDiscardIds;

        } else if (_view == ViewDeck) {
            title = "Deck";
            ids = &view.allyDeckIds;

        } else if (_view == ViewHandOpponent) {
            title = "Opponent's Hand";
            ids = &view.enemyHandIds;

        } else if (_view == ViewDiscardOpponent) {
            title = "Opponent's Discard";
            ids = &view.enemyDiscardIds;

        } else if (_view == ViewDeckOpponent) {
            title = "Opponent's Deck";
            ids = &view.enemyDeckIds;

        } else if (_view == ViewCardsAppeared) {
            title = "Cards Appeared (Both Players)";
            ids = &view.cardsAppearedIds;

        } else if (_view == ViewCardsPlayed) {
            title = "Cards Played";
            ids = &view.cardsPlayedIds;
        } else {
            Q_ASSERT(false);
        }
        const QString stringStatus = QString("%1 (%2):").arg(title).arg(ids->size());
        paintTextInPoint(stringStatus, rect.topLeft() + QPointF(0, 2 * _layout.spacingPx + 7 * posHeight - metrics.height()), Qt::gray);
        for (size_t i = 0, pos = 0; i < ids->size(); ++i, ++pos) {
            const QPointF topLeft = rect.topLeft() + QPointF(pos * posWidth, 2 * _layout.spacingPx + 7 * posHeight);
            const CardView &cardView = view.cardView(ids->at(i));
            paintCard(cardView, topLeft);
            // if (!cardView.isVisible)
            //     --pos;
        }
    }
    const QString stringStatusAlly = QString("ALLY: Power = %1, Pass = %2, Wins = %3")
            .arg(view.nPowerRowAllyMeele + view.nPowerRowAllyRange + view.nPowerRowAllySeige)
            .arg(view.allyPassed)
            .arg(view.nAllyWins);
    const QString stringStatusEnemy = QString("ENEMY: Power = %1, Pass = %2, Wins = %3")
            .arg(view.nPowerRowEnemyMeele + view.nPowerRowEnemyRange + view.nPowerRowEnemySeige)
            .arg(view.enemyPassed)
            .arg(view.nEnemyWins);
    const QString statusRound = QString("Round #%1 Turn #%2")
            .arg(view.nRounds)
            .arg(view.nTurns);
    paintTextInPoint(stringStatusAlly, QPointF(0, 20), Qt::black, Qt::cyan);
    paintTextInPoint(stringStatusEnemy, QPointF(0, 35), Qt::black, Qt::red);
    paintTextInPoint(statusRound, QPointF(0, 50), Qt::black, Qt::white);
}

void MainWindow::onImageRequestFinished(QNetworkReply *reply)
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
        repaint();

    } else {
        Q_ASSERT(false);
    }
}

void MainWindow::openLoadDialog()
{
    QFileDialog d(this);
    d.setWindowTitle("Load Deck");
    d.setAcceptMode(QFileDialog::AcceptOpen);
    d.setNameFilter("TXT (*.txt);; All Files (*.*)");
    if (!d.exec())
        return;
    const QStringList files = d.selectedFiles();
    if (files.isEmpty())
        return;
    const std::string filename = files.first().toStdString();

    Deck2 deck;
    const bool isOkRead = read(filename, deck);
    if (!isOkRead) {
        qDebug() << "Can't read a deck" << files.first();
        return;
    }

    // TODO: not reading leader correctly...
    const std::vector<Card *> cards = allCards(PublicBeta_0_9_24_3_432);
    const auto addNewCard = [cards](const std::string &name) -> const Card *
    {
        for (const Card *card : cards)
            if (card->name == name)
                return card;
        return nullptr;
    };
    bool isOkSpawn = true;
    std::vector<Card *> cardsDeck;
    for (const auto &it : deck.nameToCount) {
        if (const Card *card = addNewCard(it.first)) {
            for (int n = 0; n < it.second; ++n)
                cardsDeck.push_back(card->defaultCopy());
            continue;
        }
        isOkSpawn = false;
        qDebug() << "Unknown card with name" << QString::fromStdString(it.first);
    }
    if (!isOkSpawn)
        return;

    _textAlly->clear();
    _textEnemy->clear();
    initField(cardsDeck, nullptr, _ally);
    initField({}, nullptr, _enemy);
    _enemy.passed = true;
    _ally.canPass = false;

    for (int i = 0; i < 10; ++i)
        drawACard(_ally, _enemy, nullptr);
    // FIXME: check because changed choices
    Q_ASSERT(false);
    // _ally.cardStack.push_back(Choice(CardRoundStartPlay, nullptr, _ally.hand, 1, false));
    // repaintCustom();
}

bool MainWindow::eventFilter(QObject *o, QEvent *e)
{
    const QRect rect = this->rect().marginsRemoved(margins());

    if (e->type() == QEvent::MouseButtonPress) {
        auto *em = static_cast<QMouseEvent *>(e);
        if (!_ally.cardStack2.isEmpty())
            mouseClick(rect, em->pos(), _ally, _enemy);
        else if (!_enemy.cardStack2.isEmpty())
            mouseClick(rect, em->pos(), _enemy, _ally);
    }

    if (e->type() == QEvent::MouseMove) {
        auto *em = static_cast<QMouseEvent *>(e);
        if (!_ally.cardStack2.isEmpty() && _ally.cardStack2.peek().src != nullptr) {
            _pos = em->pos();
            repaint();
        } else if (!_enemy.cardStack2.isEmpty() && _enemy.cardStack2.peek().src != nullptr) {
            _pos = em->pos();
            repaint();
        } else {
            // _pos = QPoint();
            // TODO: tmp show card description
            _pos = em->pos();
            repaint();
        }
    }

    if (e->type() == QEvent::Wheel) {
        const int n = int(View_count);
        auto *ew = static_cast<QWheelEvent *>(e);
        if (rect.contains(ew->pos())) {
            int view = _view;
            if (ew->delta() > 0) {
                view = (view + 1) % n;
            } else {
                view--;
                if (view < 0)
                    view += n;
            }
            _view = View(view);
            repaint();
        }
    }
    return QMainWindow::eventFilter(o, e);
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    const QRect rect = e->rect().marginsRemoved(margins());
    paintInRect(rect, _snapshot);
}

void MainWindow::repaintCustom()
{
    const auto processAction = [=](const FieldView &snapshot, QTextStream &stream, const QString &prefix = "", const int msWait = 0)
    {
        const auto idToName = [=](const int id) -> QString
        {
            if (id < 0)
                return "NONE";
            return QString("%1 {%2}").arg(QString::fromStdString(snapshot.cardView(id).name), QString::number(id));
        };
        const QString dst = [=]() -> QString {
            QStringList res;
            for (const int id : snapshot.actionIdsDst)
                res.push_back(idToName(id));
            return res.isEmpty() ? "NONE" : res.join(", ");
        }();
        const QString src = [=]() -> QString {
            const QString res = idToName(snapshot.actionIdSrc);
            return res == dst ? "ITSELF" : res;
        }();
        const int x = snapshot.actionValue;
        stream << "\n";
        switch (snapshot.actionType) {
        case Invalid:
            stream << prefix << "Invalid Src = " << src << ", Dst = " << dst;
            break;
        case TurnStart:
            stream << prefix << "\n#" << x << " turn started";
            break;
        case PassedAlly:
            stream << prefix << "YOU PASSED!";
            break;
        case PassedEnemy:
            stream << prefix << "OPPONENT PASSED!";
            break;
        case WonRoundAlly:
            stream << prefix << "YOU WON IN ROUND #" << x << "!";
            break;
        case WonRoundEnemy:
            stream << prefix << "YOU LOST IN ROUND #" << x << "!";
            break;
        case WonRoundBoth:
            stream << prefix << "DRAW IN ROUND #" << x << "!";
            break;
        case WonGameAlly:
            stream << prefix << "YOU WON!";
            break;
        case WonGameEnemy:
            stream << prefix << "YOU LOST!";
            break;
        case WonGameBoth:
            stream << prefix << "DRAW!";
            break;
        case RoundStart:
            stream << prefix << "\n#" << x << " round started";
            break;
        case MulliganSkipAlly:
            stream << prefix << "You skipped a mulligan (" << x << ")";
            break;
        case MulliganSkipEnemy:
            stream << prefix << "Opponent skipped a mulligan (" << x << ")";
            break;
        case PlaySpecial:
            stream << prefix << dst << " special played by " << src;
            break;
        case PutOnField:
            stream << prefix << dst << " entered the board by " << src;
            break;
        case MoveFromRowToRow:
            stream << prefix << dst << " moved from row to row by " << src;
            break;
        case TimerSet:
            stream << prefix << src << " timer seted to " << x;
            break;
        case FlipOver:
            stream << prefix << src << " fliped over";
            break;
        case PutToHand:
            stream << prefix << dst << " moved to hand by " << src;
            break;
        case PutToDiscard:
            stream << prefix << dst << " moved to discard by " << src;
            break;
        case PutToTopDeck:
            stream << prefix << dst << " moved to the top of the deck by " << src;
            break;
        case PutToBottomDeck:
            stream << prefix << dst << " moved to the bottom of the deck by " << src;
            break;
        case ShuffleToDeck:
            stream << prefix << dst << " shuffled to deck by " << src;
            break;
        case Destroyed:
            stream << prefix << dst << " destroyed by " << src;
            break;
        case Banished:
            stream << prefix << dst << " removed from the game by " << src;
            break;
        case DealDamage:
            stream << prefix << src << " dealed " << x << " damage to " << dst;
            break;
        case Weakened:
            stream << prefix << src << " weakened " << dst << " by " << x << " power";
            break;
        case Boosted:
            stream << prefix << dst << " gained " << x << " power by " << src;
            break;
        case Strengthened:
            stream << prefix << src << " strengthened " << dst << " by " << x << " power";
            break;
        case Healed:
            stream << prefix << src << " fully healed " << dst;
            break;
        case HealedBy:
            stream << prefix << src << " healed " << dst << " by " << x << " power";
            break;
        case Damaged:
            stream << prefix << dst << " recieved " << x << " damage by " << src;
            break;
        case DamagedInArmor:
            stream << prefix << dst << " absorbed " << x << " damage by " << src;
            break;
        case ResetAsInDeckBuilder:
            stream << prefix << src << " fully reset " << dst;
            break;
        case ResetInPower:
            stream << prefix << dst << " gained power equal base power by " << src;
            break;
        case StrippedOfAllStatuses:
            stream << prefix << dst << " lost all of statuses by " << src;
            break;
        case GainArmor:
            stream << prefix << dst << " gained " << x << " armor by " << src;
            break;
        case GainLock:
            stream << prefix << dst << " gained LOCK by " << src;
            break;
        case Transform:
            stream << prefix << dst << " transformed by " << src;
            break;
        case GainSpy:
            stream << prefix << dst << " gained SPY by " << src;
            break;
        case LostLock:
            stream << prefix << dst << " lost LOCK by " << src;
            break;
        case LostSpy:
            stream << prefix << dst << " lost SPY by " << src;
            break;
        case Reveal:
            stream << prefix << dst << " revealed by " << src;
            break;
        case Conceal:
            stream << prefix << dst << " concealed by " << src;
            break;
        default:
            Q_ASSERT(false);
        }

        requestSoundByUrl(snapshot.actionSound);

        if (!msWait)
            return;

        _snapshot = snapshot;
        repaint();

        QEventLoop loop(this);
        QTimer::singleShot(msWait, &loop, &QEventLoop::quit);
        loop.exec(QEventLoop::ExcludeUserInputEvents);
        QApplication::processEvents();
    };
    class TextEditIoDevice : public QIODevice
    {
    public:
        TextEditIoDevice(QTextEdit *const textEdit, QObject *const parent)
            : QIODevice(parent), textEdit(textEdit)
        {
            open(QIODevice::WriteOnly | QIODevice::Text);
        }
    protected:
        qint64 readData(char *, qint64 ) override { return 0; }
        qint64 writeData(const char *data, qint64 maxSize) override
        {
            if(textEdit) {
                textEdit->setPlainText(textEdit->toPlainText() + data);
                textEdit->verticalScrollBar()->setValue(textEdit->verticalScrollBar()->maximum());
            }
            return maxSize;
        }

    private:
        QPointer<QTextEdit> textEdit;
    };
    {
        QTextStream ss(new TextEditIoDevice(_textAlly, this));
        for (const FieldView &snapshot : _ally.snapshots) {
            // BUG: doesn't work after a pass..
            // Maybe add a function determined, which turn is it
            // if (snapshot.actionType == TurnStart)
            //    _turn = (_turn + 1) % 2;
            // processAction(snapshot, ss, "", _turn ? 500 : 0);
            processAction(snapshot, ss);
        }
        _ally.snapshots.clear();
    }
    {
        QTextStream ss(new TextEditIoDevice(_textEnemy, this));
        for (const FieldView &snapshot : _enemy.snapshots)
            processAction(snapshot, ss);
        _enemy.snapshots.clear();
    }
    if (!_ally.cardStack2.isEmpty()) {
        _snapshot = fieldView(_ally, _enemy);
        _isLastSnapshotShownAlly = true;
        _ally.cardStack2.trace();

    } else if (!_enemy.cardStack2.isEmpty()) {
        _snapshot = fieldView(_enemy, _ally);
        _isLastSnapshotShownAlly = false;

    } else if (_isLastSnapshotShownAlly) {
        _snapshot = fieldView(_ally, _enemy);

    } else {
        _snapshot = fieldView(_enemy, _ally);

    }
    repaint();
}
