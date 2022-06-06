#include "formdeckbuilder.h"

#include <QHBoxLayout>
#include <QScrollArea>
#include <QCheckBox>
#include <QLineEdit>
#include <qtimer.h>
#include <QSplitter>
#include <QFileDialog>
#include <QMenuBar>
#include <QProgressBar>

#include "../Cards/archieve.h"
#include "../Cards/io.h"
#include "resourcemanager.h"
#include "cardsingleview.h"
#include "cardslineview.h"

QScrollArea *createScrollArea(QWidget *widget)
{
    auto *_scrollArea = new QScrollArea();
    _scrollArea->setWidget(widget);
    _scrollArea->setWidgetResizable(true);
    return _scrollArea;
}

FormDeckBuilder::FormDeckBuilder(QWidget *parent) :
    QMainWindow(parent)
{
    QAction *saveDeck = new QAction("Save Deck...");
    connect(saveDeck, &QAction::triggered, this, &FormDeckBuilder::openSaveDialog);
    saveDeck->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));

    QMenuBar *menuBar = new QMenuBar(this);
    menuBar->addAction(saveDeck);
    setMenuBar(menuBar);

    int id = 0;
    std::map<int, std::vector<CardView>> views;
    for (const Card *card : allCards(PublicBeta_0_9_24_3_432)) {
        CardView view = cardView(card, id++);
        view.count = card->rarity == Bronze ? 3 : 1;
        _allCardViews.push_back(view);
    }

    _resourceManager = new ResourceManager("ru");

    auto *widget = new QWidget;
    widget->setContentsMargins(0, 0, 0, 0);

    auto *layout = new QVBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);
    widget->setLayout(layout);

    auto *layoutH = new QHBoxLayout;
    layoutH->addWidget(_checkBoxGold = new QCheckBox("Gold"));
    layoutH->addWidget(_checkBoxSilver = new QCheckBox("Silver"));
    layoutH->addWidget(_checkBoxBronze = new QCheckBox("Bronze"));
    layoutH->addWidget(_checkBoxNeutral = new QCheckBox("Neutral"));
    layoutH->addWidget(_checkBoxMonster = new QCheckBox("Monster"));
    layoutH->addWidget(_checkBoxNilfgaard = new QCheckBox("Nilfgaard"));
    layoutH->addWidget(_checkBoxNothernRealms = new QCheckBox("Nothern Realms"));
    layoutH->addWidget(_checkBoxScoiatael = new QCheckBox("Scoea'tael"));
    layoutH->addWidget(_checkBoxSkellige = new QCheckBox("Skellige"));
    layoutH->addStretch(1);
    layout->addLayout(layoutH);
    auto *layoutH3 = new QHBoxLayout;
    layoutH3->setContentsMargins(0, 0, 0, 0);
    layoutH3->addWidget(_lineEditSearch = new QLineEdit(), 1);
    layout->addLayout(layoutH3);


    auto *splitterH2 = new QSplitter(Qt::Horizontal);
    splitterH2->insertWidget(0, (createScrollArea(_cardsLineView = new CardsLineView(_resourceManager, {}, {}, Qt::Vertical, 6))));
    splitterH2->insertWidget(1, createScrollArea(_cardSingleView = new CardSingleView(_resourceManager, {}, nullptr)));
    auto *splitterV = new QSplitter(Qt::Vertical);
    splitterV->insertWidget(0, splitterH2);
    splitterV->insertWidget(1, createScrollArea(_cardsLineView2 = new CardsLineView(_resourceManager, {}, {}, Qt::Horizontal, 1)));
    layout->addWidget(splitterV, 5);

    auto *progress = new QProgressBar();
    progress->setFixedHeight(10);
    layoutH3->addWidget(progress, 1);
    progress->setFormat("%v/%m (%p%)");
    progress->setVisible(false);
    _timeStampProgressBar = QDateTime::currentDateTime();
    setCentralWidget(widget);
    auto *progressTimer = new QTimer(this);
    progressTimer->setInterval(1000);
    progressTimer->setSingleShot(false);
    progressTimer->start();

    connect(_checkBoxGold, &QCheckBox::clicked, this, &FormDeckBuilder::updateCardsList);
    connect(_checkBoxSilver, &QCheckBox::clicked, this, &FormDeckBuilder::updateCardsList);
    connect(_checkBoxBronze, &QCheckBox::clicked, this, &FormDeckBuilder::updateCardsList);
    connect(_checkBoxNeutral, &QCheckBox::clicked, this, &FormDeckBuilder::updateCardsList);
    connect(_checkBoxMonster, &QCheckBox::clicked, this, &FormDeckBuilder::updateCardsList);
    connect(_checkBoxNilfgaard, &QCheckBox::clicked, this, &FormDeckBuilder::updateCardsList);
    connect(_checkBoxNothernRealms, &QCheckBox::clicked, this, &FormDeckBuilder::updateCardsList);
    connect(_checkBoxScoiatael, &QCheckBox::clicked, this, &FormDeckBuilder::updateCardsList);
    connect(_checkBoxSkellige, &QCheckBox::clicked, this, &FormDeckBuilder::updateCardsList);
    connect(_lineEditSearch, &QLineEdit::textChanged, this, &FormDeckBuilder::updateCardsList);
    const auto hoverId = [=](const int id) {
        if (id >= 0)
            for (const CardView &view : _allCardViews)
                if (view.id == id) {
                    return _cardSingleView->setCardView(view);
                }
        _cardSingleView->setCardView({});
    };
    connect(_cardsLineView, &CardsLineView::hovered, this, hoverId);
    connect(_cardsLineView2, &CardsLineView::hovered, this, hoverId);
    connect(_cardsLineView, &CardsLineView::clicked, this, &FormDeckBuilder::putCardToDeck);
    connect(_cardsLineView2, &CardsLineView::clicked, this, &FormDeckBuilder::putCardBack);
    connect(_resourceManager, &ResourceManager::imageRequestSucceed, this, static_cast<void(QWidget::*)()>(&QWidget::repaint));
    const auto showProgress = [=]{
        progress->setRange(0, _resourceManager->nRequests());
        progress->setValue(_resourceManager->nReplies());
        progress->setVisible(true);
        _timeStampProgressBar = QDateTime::currentDateTime().addSecs(2);
    };
    connect(_resourceManager, &ResourceManager::imageRequestSucceed, this, showProgress);
    connect(_resourceManager, &ResourceManager::cardRequestSucceed, this, showProgress);
    connect(progressTimer, &QTimer::timeout, this, [=]{
        if (QDateTime::currentDateTime() > _timeStampProgressBar || progress->value() >= progress->maximum())
            progress->setVisible(false);
    });

    updateCardsList();

    resize(800, 900);
    splitterV->setSizes({800, 100});
    splitterH2->setSizes({500, 300});
}

void FormDeckBuilder::updateCardsList()
{
    std::function<bool (const CardView &)> filter([=](const CardView &view){
        const bool skipRarityFilter =
                !_checkBoxGold->isChecked()
                && !_checkBoxSilver->isChecked()
                && !_checkBoxBronze->isChecked();
        if (!skipRarityFilter && !_checkBoxGold->isChecked() && view.rarity == Gold)
            return false;
        if (!skipRarityFilter && !_checkBoxSilver->isChecked() && view.rarity == Silver)
            return false;
        if (!skipRarityFilter && !_checkBoxBronze->isChecked() && view.rarity == Bronze)
            return false;
        const bool skipFactionFilter =
                !_checkBoxNeutral->isChecked()
                && !_checkBoxMonster->isChecked()
                && !_checkBoxNilfgaard->isChecked()
                && !_checkBoxNothernRealms->isChecked()
                && !_checkBoxScoiatael->isChecked()
                && !_checkBoxSkellige->isChecked();
        if (!skipFactionFilter && !_checkBoxNeutral->isChecked() && view.faction == Neutral)
            return false;
        if (!skipFactionFilter && !_checkBoxMonster->isChecked() && view.faction == Monster)
            return false;
        if (!skipFactionFilter && !_checkBoxNilfgaard->isChecked() && view.faction == Nilfgaard)
            return false;
        if (!skipFactionFilter && !_checkBoxNothernRealms->isChecked() && view.faction == NothernRealms)
            return false;
        if (!skipFactionFilter && !_checkBoxScoiatael->isChecked() && view.faction == Scoiatael)
            return false;
        if (!skipFactionFilter && !_checkBoxSkellige->isChecked() && view.faction == Skellige)
            return false;

        const CardStringsAndUrls strings = _resourceManager->cardStringsAndUrls(view.idInfo);
        if (!_lineEditSearch->text().isEmpty()
                && !QString::fromStdString(strings.name).contains(_lineEditSearch->text(), Qt::CaseInsensitive)
                && !QString::fromStdString(strings.text).contains(_lineEditSearch->text(), Qt::CaseInsensitive))
            return false;
        return true;
    });
    const auto sortCollection = [=](const CardView &lhs, const CardView &rhs) {
        if (isLeader(lhs) != isLeader(rhs))
            return isLeader(lhs);
        if (lhs.faction != rhs.faction)
            return (lhs.faction < rhs.faction);
        if (lhs.rarity != rhs.rarity)
            return (lhs.rarity > rhs.rarity);
        if (lhs.powerBase != rhs.powerBase)
            return (lhs.powerBase < rhs.powerBase);
        return _resourceManager->cardName(lhs.idInfo) < _resourceManager->cardName(rhs.idInfo);
    };
    const auto sortDeck = [=](const CardView &lhs, const CardView &rhs) {
        if (isLeader(lhs) != isLeader(rhs))
            return isLeader(lhs);
        if (lhs.rarity != rhs.rarity)
            return (lhs.rarity > rhs.rarity);
        if (lhs.powerBase != rhs.powerBase)
            return (lhs.powerBase < rhs.powerBase);
        return _resourceManager->cardName(lhs.idInfo) < _resourceManager->cardName(rhs.idInfo);
    };

    std::vector<CardView> views = _filtered({filter}, _allCardViews);
    std::sort(views.begin(), views.end(), sortCollection);
    _cardsLineView->setCardAndChoiceViews(views, {});

    std::vector<CardView> views2 = _deckCardViews;
    std::sort(views2.begin(), views2.end(), sortDeck);
    _cardsLineView2->setCardAndChoiceViews(views2, {});
}

void FormDeckBuilder::openSaveDialog()
{
    QFileDialog d(this);
    d.setWindowTitle("Save Deck");
    d.setAcceptMode(QFileDialog::AcceptSave);
    d.setNameFilter("TXT (*.txt);; All Files (*.*)");
    if (!d.exec())
        return;
    const QStringList files = d.selectedFiles();
    if (files.isEmpty())
        return;
    const std::string filename = files.first().toStdString();

    Deck2 deck;
    for (auto it = _deckCardViews.begin(); it != _deckCardViews.end(); ++it) {
        deck.nameToCount.insert({_resourceManager->cardName(it->idInfo), it->count});
    }

    const bool isOk = write(filename, deck);
    qDebug() << "save deck to" << files.first() << isOk;
}

bool FormDeckBuilder::putCardToDeck(const int id)
{
    if (id < 0)
        return false;
    for (CardView &view : _allCardViews) {
        if (view.id == id && view.count > 0) {
            view.count--;
            bool alreadyInDeck = false;
            for (CardView &_view : _deckCardViews) {
                if (_view.id == id) {
                    _view.count++;
                    alreadyInDeck = true;
                    break;
                }
            }
            if (!alreadyInDeck) {
                CardView view2 = view;
                view2.count = 1;
                _deckCardViews.push_back(view2);
            }
            break;
        }
    }
    updateCardsList();
    return true;
}

bool FormDeckBuilder::putCardBack(const int id)
{
    if (id < 0)
        return false;
    for (size_t i = 0; i < _deckCardViews.size(); ++i) {
        if (_deckCardViews[i].id != id)
            continue;
        _deckCardViews[i].count--;
        if (_deckCardViews[i].count >= 1)
            break;
        _deckCardViews.erase(_deckCardViews.begin() + int(i));
        break;
    }
    for (CardView &view : _allCardViews) {
        if (view.id == id) {
            view.count++;
            break;
        }
    }
    updateCardsList();
    return true;
}

bool FormDeckBuilder::isDeckOk(int &nBronze, int &nSilver, int &nGold, QString &err)
{
    nBronze = 0;
    nSilver = 0;
    nGold = 0;
    err.clear();
    for (const CardView &view : _deckCardViews) {
        if (view.rarity == Bronze) {
            Q_ASSERT(view.count <= 0 || view.count >= 3);
            nBronze += view.count;
        } else if (view.rarity == Silver) {
            Q_ASSERT(view.count == 1);
            nSilver++;
        } else if (view.rarity == Gold) {
            Q_ASSERT(view.count == 1);
            nGold++;
        } else
            Q_UNREACHABLE();
    }
    const QString errCountTemplate = "Deck contains %1 cards (25 to 40 allowed)!";
    const QString errSilverTemplate = "Deck contains %1 Silver cards (6 max allowed)!";
    const QString errGoldTemplate = "Deck contains %1 Gold cards (4 max allowed)!";

    if (_deckCardViews.size() < 25 || _deckCardViews.size() > 40) {
        err = errCountTemplate.arg(_deckCardViews.size());
        return false;
    }
    if (nSilver > 6) {
        err = errSilverTemplate.arg(nSilver);
        return false;
    }
    if (nGold > 4) {
        err = errGoldTemplate.arg(nGold);
        return false;
    }
    return true;
}
