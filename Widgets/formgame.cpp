#include "formgame.h"

#include "cardsfieldview.h"
#include "resourcemanager.h"

#include "Cards/demos.h" // for custom demo

FormGame::FormGame(QWidget *parent) :
    QMainWindow(parent)
{
    auto *a = new Wolf();
    auto *a2 = new Wolf();
    auto *a3 = new Wolf();
    auto *a4 = new Wolf();
    auto *a5 = new Wolf();
    auto *a6 = new Wolf();
    auto *a7 = new Wolf();
    auto *a8 = new Wolf();
    auto *a9 = new Wolf();
    auto *a10 = new Wolf();
    auto *a11 = new Wolf();
    auto *a12 = new Wolf();
    auto *a13 = new Wolf();
    auto *a14 = new Wolf();
    auto *a15 = new Wolf();
    auto *a16 = new Wolf();
    auto *a17 = new Wolf();
    auto *a18 = new Wolf();
    auto *a19 = new Wolf();

    Field ally;
    Field enemy;
    ally.cardsAdded = { a, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16 };
    ally.rowMeele = { a };
    ally.rowRange = { a2, a3 };
    ally.rowSeige = { a4, a5, a6, a7, a8, a9, a10, a11, a12 };
    enemy.cardsAdded = { a16, a17, a18, a19 };
    enemy.rowMeele = { a16, a17 };
    enemy.rowRange = { a18 };
    enemy.rowSeige = { a19 };
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));

    const FieldView view = fieldView(ally, enemy, TurnStart, nullptr, {}, {}, -1, false);


    _resourceManager = new ResourceManager();
    _cardsFieldView = new CardsFieldView(_resourceManager, view);
    connect(_cardsFieldView, &CardsFieldView::hovered, this, [=](const int id){ qDebug() << "hovered" << id; });
    connect(_cardsFieldView, &CardsFieldView::clicked, this, [=](const int id){ qDebug() << "clicked" << id; });


    setCentralWidget(_cardsFieldView);
}
