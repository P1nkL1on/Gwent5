#include "mainwindow.h"

#include <QHBoxLayout>
#include <QScrollArea>
#include <QCheckBox>
#include <QLineEdit>
#include <qtimer.h>

#include "../Cards/archieve.h"
#include "cardsingleview.h"
#include "cardslineview.h"

QScrollArea *createScrollArea(QWidget *widget)
{
    auto *_scrollArea = new QScrollArea();
    _scrollArea->setWidget(widget);
    _scrollArea->setWidgetResizable(true);
    return _scrollArea;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    int id = 0;
    for (const Card *card : allCards(PublicBeta_0_9_24_3_432))
        _allCardViews.push_back(cardView(card, id++));

    auto *_resourceManager = new ResourceManager();

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
    layout->addWidget(_lineEditSearch = new QLineEdit());


    auto *layoutH2 = new QHBoxLayout;
    layoutH2->addWidget(createScrollArea(_cardsLineView = new CardsLineView(_resourceManager, {}, {}, Qt::Vertical, 6)), 2);
    layoutH2->addWidget(_cardSingleView = new CardSingleView(_resourceManager, {}, nullptr), 1);
    layout->addLayout(layoutH2, 1);
    setCentralWidget(widget);

    connect(_checkBoxGold, &QCheckBox::clicked, this, &MainWindow::updateCardsList);
    connect(_checkBoxSilver, &QCheckBox::clicked, this, &MainWindow::updateCardsList);
    connect(_checkBoxBronze, &QCheckBox::clicked, this, &MainWindow::updateCardsList);
    connect(_checkBoxNeutral, &QCheckBox::clicked, this, &MainWindow::updateCardsList);
    connect(_checkBoxMonster, &QCheckBox::clicked, this, &MainWindow::updateCardsList);
    connect(_checkBoxNilfgaard, &QCheckBox::clicked, this, &MainWindow::updateCardsList);
    connect(_checkBoxNothernRealms, &QCheckBox::clicked, this, &MainWindow::updateCardsList);
    connect(_checkBoxScoiatael, &QCheckBox::clicked, this, &MainWindow::updateCardsList);
    connect(_checkBoxSkellige, &QCheckBox::clicked, this, &MainWindow::updateCardsList);
    connect(_lineEditSearch, &QLineEdit::textChanged, this, &MainWindow::updateCardsList);
    connect(_cardsLineView, &CardsLineView::hovered, this, [=](const int id) {
        if (id > 0)
            for (const CardView &view : _allCardViews)
                if (view.id == id)
                    return _cardSingleView->setCardView(view);
        _cardSingleView->setCardView({});
    });

    updateCardsList();
}

void MainWindow::updateCardsList()
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
        if (!_lineEditSearch->text().isEmpty()
                && !QString::fromStdString(view.name).contains(_lineEditSearch->text(), Qt::CaseInsensitive)
                && !QString::fromStdString(view.text).contains(_lineEditSearch->text(), Qt::CaseInsensitive))
            return false;
        return true;
    });
    std::vector<CardView> views = _filtered({filter}, _allCardViews);
    std::sort(views.begin(), views.end(), [](const CardView &lhs, const CardView &rhs) {
        if (lhs.rarity != rhs.rarity)
            return (lhs.rarity > rhs.rarity);
        if (lhs.powerBase != rhs.powerBase)
            return (lhs.powerBase < rhs.powerBase);
        return lhs.name < rhs.name;
    });
    _cardsLineView->setCardAndChoiceViews(views, {});
}
