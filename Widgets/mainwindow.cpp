#include "mainwindow.h"

#include <QScrollArea>

#include "../Cards/archieve.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    const std::vector<Card *> cards = {
        new Restore, new Udalryk, new Sigrdrifa, new Gremist, new Operator,
        new TuirseachVeteran, new TuirseachVeteran, new TuirseachVeteran,
        new TuirseachBearmaster, new TuirseachBearmaster, new TuirseachBearmaster,
        new TuirseachHunter, new TuirseachHunter, new TuirseachHunter,
        new HeymaeySpearmaiden, new HeymaeySpearmaiden,
        new PriestessOfFreya, new PriestessOfFreya,
        new Reconnaissance, new Reconnaissance,
    };
    std::vector<CardView> cardViews;
    int id = 0;
    for (const Card *card : cards)
        cardViews.push_back(cardView(card, id++));


    auto *_resourceManager = new ResourceManager();
    _cardsLineView = new CardsLineView(_resourceManager, cardViews, {});


    auto *_scrollArea = new QScrollArea();
    _scrollArea->setWidget(_cardsLineView);
    _scrollArea->setWidgetResizable(false);
    _scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setCentralWidget(_scrollArea);
}
