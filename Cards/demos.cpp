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
    initField(deck, new JanCalveit(), ally);
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

void demoSkelligeVeteransPrimeDeck(Field &ally, Field &enemy)
{
    const std::vector<Card *> deck {
        new Coral(),
        new Ermion(),
        // new Muzzle(),

        new Gremist,
        new Operator,
        new Sigrdrifa(),
        new Udalryk(),
        new Restore(),
        new Decoy(),

        new TuirseachVeteran, new TuirseachVeteran, new TuirseachVeteran,
        new TuirseachBearmaster, new TuirseachBearmaster, new TuirseachBearmaster,
        new TuirseachHunter, new TuirseachHunter, new TuirseachHunter,
        new HeymaeySpearmaiden, new HeymaeySpearmaiden,
        new PriestessOfFreya, new PriestessOfFreya,
        new Reconnaissance, new Reconnaissance,
    };
    initField(deck, new CrachAnCraite(), ally);
    startNextRound(ally, enemy);
}

void demoMorkvarg(Field &ally, Field &enemy)
{
    auto *m = new Morkvarg();
    auto *a1 = new AlzursThunder();
    auto *a2 = new AlzursThunder();
    auto *a3 = new AlzursThunder();
    auto *s = new SvanrigeTuirseach();
    ally.cardsAdded = { m, a1, a2, a3, s };
    ally.deck = { a1 };
    ally.hand = { m, a2, a3, s };
    enemy.passed = true;
    ally.canPass = false;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
}

void demoVsSkelligeDiscardVsNothernRealmsArmor(Field &ally, Field &enemy)
{
    const std::vector<Card *> deckStartingAlly = {
        new AnCraiteLongship, new AnCraiteLongship, new AnCraiteLongship,
        new CerysAnCraite, new CerysFearless, new MadmanLugos, new Ermion,
        new ChampionOfHov, new Morkvarg, new Sigrdrifa, new Restore,
        new AnCraiteRaider, new AnCraiteRaider, new AnCraiteRaider,
        new DimunPirate, new DimunPirate, new DimunPirate,
        new DimunCorsair, new DimunCorsair, new DimunCorsair,
        new DimunPirateCaptain, new DimunPirateCaptain,
        new DrummondWarmonger, new DrummondWarmonger, new DrummondWarmonger,
        new Reconnaissance, new PriestessOfFreya, new PriestessOfFreya
    };
    const std::vector<Card *> deckStartingEnemy = {
        new JohnNatalis, new KeiraMetz, new Priscilla, new SeltkirkOfGulet,
        new Reinforcements, new Ves, new SileDeTansarville,
        new Trollololo, new PrinceStennis, new VincentMeis,
        new RedanianKnightElect, new RedanianKnightElect, new RedanianKnightElect,
        new RedanianElite, new RedanianElite, new RedanianElite,
        new ReaverScout, new ReaverScout, new ReaverScout,
        new KaedweniCavalry, new KaedweniCavalry, new KaedweniCavalry,
        new Reconnaissance, new Thunderbolt, new Thunderbolt,
    };
    initField(deckStartingAlly, new BranTuirseach, ally);
    initField(deckStartingEnemy, new JanCalveit, enemy);
    startNextRound(ally, enemy);
}
