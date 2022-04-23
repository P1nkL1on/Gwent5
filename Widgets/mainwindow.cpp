#include "mainwindow.h"

#include <QScrollArea>
#include <qtimer.h>

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

    connect(_cardsLineView, &CardsLineView::hovered, this, [](const int id) {
        qDebug() << "hovered" << id;
    });

    QTimer *t = new QTimer;
    t->setInterval(100);

    auto *_scrollArea = new QScrollArea();
    _scrollArea->setWidget(_cardsLineView);
    _scrollArea->setWidgetResizable(true);
    _scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setCentralWidget(_scrollArea);

    show();
//    connect(t, &QTimer::timeout, this, [=]{
//        qDebug() << _scrollArea->rect() << _scrollArea->widget()->size() << _scrollArea->widget();
//    });

    t->start();
}
