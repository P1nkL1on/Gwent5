#include "demos.h"

void demoHjalmarAnCraite(Field &ally, Field &enemy)
{
    auto *a = new HjalmarAnCraite();
    auto *h = new TuirseachHunter();
    ally.cardsAdded = {a, h};

    ally.hand = {a, h};
    enemy.passed = true;
    ally.canPass = false;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
}

void demoHaraldHoundsnout(Field &ally, Field &enemy)
{
    auto *h = new HaraldHoundsnout();
    auto *d = new DjengeFrett();
    auto *s = new DimunLightLongship();
    ally.cardsAdded = {h, d, s};

    auto *t = new TemerianDrummer();
    enemy.cardsAdded = {t};

    ally.hand = {h, d};
    ally.rowRange = {s};
    enemy.rowRange = {t};
    enemy.passed = true;
    ally.canPass = false;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
}
