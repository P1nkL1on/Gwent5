#include "demos.h"

void demoHjalmarAnCraite(Field &ally, Field &enemy)
{
    ally.cardsAdded = {
        new HjalmarAnCraite(),
        new TuirseachHunter(),
    };
    ally.hand = ally.cardsAdded;
    enemy.passed = true;
    ally.canPass = false;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
}

void demoHalfElfHunter(Field &ally, Field &enemy)
{
    ally.cardsAdded = {
        new HalfElfHunter(),
        new Decoy(),
    };
    ally.hand = ally.cardsAdded;
    enemy.passed = true;
    ally.canPass = false;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
}

void demoSlaveInfantry(Field &ally, Field &enemy)
{
    ally.cardsAdded = {
        new SlaveInfantry(),
        new SlaveInfantry(),
        new Sentry(),
        new Decoy(),
    };
    ally.hand = ally.cardsAdded;
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

void demoNilfgaardSoldiersDeck(Field &ally, Field &enemy)
{
    const std::vector<Card *> deck {
        new Vilgefortz(),
        new TrissButterflies(),
        new Yennefer(),
        new LethoKingslayer(),
        new GermainPiquant(),
        new Operator(),
        new Vreemde(),
        new Decoy(),
        new CommandersHorn(),
        new MarchingOrders(),
        new Sentry(), new Sentry(), new Sentry(),
        new NauzicaaSergeant(),
        new AlbaArmoredCavalry(), new AlbaArmoredCavalry(), new AlbaArmoredCavalry(),
        new SlaveInfantry(), new SlaveInfantry(), new SlaveInfantry(),
        new Recruit(), new Recruit(), new Recruit(),
        new Ointment(), new Ointment(),
    };
    initField(deck, new JanCalveit, ally);
    startNextRound(ally, enemy);
}

void demoGiantBoar(Field &ally, Field &enemy)
{
    ally.cardsAdded = {
        new GiantBoar(),
        new DimunPirateCaptain(),
    };
    ally.hand = ally.cardsAdded;
    enemy.passed = true;
    ally.canPass = false;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
}

void demoTransforms(Field &ally, Field &enemy)
{
    ally.cardsAdded = {new ArtefactCompression(), new Coral()};

    auto *d = new DjengeFrett();
    auto *s = new DimunLightLongship();
    enemy.cardsAdded = {s, d};

    ally.hand = ally.cardsAdded;
    enemy.rowRange = {s, d};
    enemy.passed = true;
    ally.canPass = false;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
}
