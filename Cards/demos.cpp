#include "demos.h"

void demoHjalmarAnCraite(Field &ally, Field &enemy)
{
    Cards cards;
    ally.cardsAdded = {
        cards.createHjalmarAnCraite(),
        cards.createTuirseachHunter(),
    };
    ally.hand = ally.cardsAdded;
    startDemo(ally, enemy);
}

void demoHalfElfHunter(Field &ally, Field &enemy)
{
    Cards cards;
    ally.cardsAdded = {
        cards.createHalfElfHunter(),
        cards.createDecoy(),
    };
    ally.hand = ally.cardsAdded;
    startDemo(ally, enemy);
}

void demoSlaveInfantry(Field &ally, Field &enemy)
{
    Cards cards;
    ally.cardsAdded = {
        cards.createSlaveInfantry(),
        cards.createSlaveInfantry(),
        cards.createSentry(),
        cards.createDecoy(),
    };
    ally.hand = ally.cardsAdded;
    startDemo(ally, enemy);
}


void demoHaraldHoundsnout(Field &ally, Field &enemy)
{
    Cards cards;
    auto *h = cards.createHaraldHoundsnout();
    auto *d = cards.createDjengeFrett();
    auto *s = cards.createDimunLightLongship();
    ally.cardsAdded = {h, d, s};

    auto *t = cards.createTemerianDrummer();
    enemy.cardsAdded = {t};

    ally.hand = {h, d};
    ally.rowRange = {s};
    enemy.rowRange = {t};
    startDemo(ally, enemy);
}

void demoNilfgaardSoldiersDeck(Field &ally, Field &enemy)
{
    Cards cards;
    const std::vector<Card *> deck {
        cards.createVilgefortz(),
        cards.createTrissButterflies(),
        cards.createYennefer(),
        cards.createLethoKingslayer(),

        cards.createGermainPiquant(),
        cards.createOperator(),
        cards.createVreemde(),
        cards.createDecoy(),
        cards.createCommandersHorn(),
        cards.createMarchingOrders(),

        cards.createSentry(), cards.createSentry(), cards.createSentry(),
        cards.createNauzicaaSergeant(),
        cards.createAlbaArmoredCavalry(), cards.createAlbaArmoredCavalry(), cards.createAlbaArmoredCavalry(),
        cards.createSlaveInfantry(), cards.createSlaveInfantry(), cards.createSlaveInfantry(),
        cards.createRecruit(), cards.createRecruit(), cards.createRecruit(),
        cards.createOintment(), cards.createOintment(),
    };
    initField(deck, cards.createJanCalveit(), ally);
    startNextRound(ally, enemy);
}

void demoGiantBoar(Field &ally, Field &enemy)
{
    Cards cards;
    ally.cardsAdded = {
        cards.createGiantBoar(),
        cards.createDimunPirateCaptain(),
    };
    ally.hand = ally.cardsAdded;
    startDemo(ally, enemy);
}

void demoTransforms(Field &ally, Field &enemy)
{
    Cards cards;
    ally.cardsAdded = {cards.createArtefactCompression(), cards.createCoral()};

    auto *d = cards.createDjengeFrett();
    auto *s = cards.createDimunLightLongship();
    enemy.cardsAdded = {s, d};

    ally.hand = ally.cardsAdded;
    enemy.rowRange = {s, d};
    startDemo(ally, enemy);
}

void demoSkelligeVeteransPrimeDeck(Field &ally, Field &enemy)
{
    Cards cards;
    const std::vector<Card *> deck;
    initField(deck, cards.createCrachAnCraite(), ally);
    startNextRound(ally, enemy);
}

void demoMorkvarg(Field &ally, Field &enemy)
{
    Cards cards;
    auto *m = cards.createMorkvarg();
    auto *a1 = cards.createAlzursThunder();
    auto *a2 = cards.createAlzursThunder();
    auto *a3 = cards.createAlzursThunder();
    auto *s = cards.createSvanrigeTuirseach();
    ally.cardsAdded = { m, a1, a2, a3, s };
    ally.deck = { a1 };
    ally.hand = { m, a2, a3, s };
    startDemo(ally, enemy);
}

void demoVsSkelligeDiscardVsNothernRealmsArmor(Field &ally, Field &enemy)
{
    Cards cards;
    const std::vector<Card *> deckStartingAlly = {
        cards.createAnCraiteLongship(), cards.createAnCraiteLongship(), cards.createAnCraiteLongship(),
        cards.createCerysAnCraite(), cards.createCerysFearless(), cards.createMadmanLugos(), cards.createErmion(),
        cards.createChampionOfHov(), cards.createMorkvarg(), cards.createSigrdrifa(), cards.createRestore(),
        cards.createAnCraiteRaider(), cards.createAnCraiteRaider(), cards.createAnCraiteRaider(),
        cards.createDimunPirate(), cards.createDimunPirate(), cards.createDimunPirate(),
        cards.createDimunCorsair(), cards.createDimunCorsair(), cards.createDimunCorsair(),
        cards.createDimunPirateCaptain(), cards.createDimunPirateCaptain(),
        cards.createDrummondWarmonger(), cards.createDrummondWarmonger(), cards.createDrummondWarmonger(),
        cards.createReconnaissance(), cards.createPriestessOfFreya(), cards.createPriestessOfFreya()
    };
    const std::vector<Card *> deckStartingEnemy = {
        cards.createJohnNatalis(), cards.createKeiraMetz(), cards.createPriscilla(), cards.createSeltkirkOfGulet(),
        cards.createReinforcements(), cards.createVes(), cards.createSileDeTansarville(),
        cards.createTrollololo(), cards.createPrinceStennis(), cards.createVincentMeis(),
        cards.createRedanianKnightElect(), cards.createRedanianKnightElect(), cards.createRedanianKnightElect(),
        cards.createRedanianElite(), cards.createRedanianElite(), cards.createRedanianElite(),
        cards.createReaverScout(), cards.createReaverScout(), cards.createReaverScout(),
        cards.createKaedweniCavalry(), cards.createKaedweniCavalry(), cards.createKaedweniCavalry(),
        cards.createReconnaissance(), cards.createThunderbolt(), cards.createThunderbolt(),
    };
    initField(deckStartingAlly, cards.createBranTuirseach(), ally);
    initField(deckStartingEnemy, cards.createMorvranVoorhis(), enemy);
    startNextRound(ally, enemy);
}

void demoInstantEffects(Field &ally, Field &enemy)
{
    Cards cards;
    auto *d1 = cards.createTemerianDrummer();
    auto *d2 = cards.createTemerianDrummer();
    auto *d3 = cards.createTemerianDrummer();
    auto *d4 = cards.createTridamInfantry();
    auto *a = cards.createTuirseachArcher();
    ally.cardsAdded = { a };
    ally.hand = { a };
    enemy.cardsAdded = { d1, d2, d3, d4 };
    enemy.rowSeige = { d1 };
    enemy.rowRange = { d2 };
    enemy.rowMeele = { d3, d4 };
    d4->onDeploy(enemy, ally);
    startDemo(ally, enemy);
}

void demoSpawnAndSummon(Field &ally, Field &enemy)
{
    Cards cards;
    ally.cardsAdded = {
        cards.createDao(),
        cards.createAlzursThunder(),
        cards.createPoorFingInfantry(),
        cards.createHalfElfHunter(),
        cards.createVriheddSappers(),
        cards.createVriheddSappers(),
    };
    ally.hand = ally.cardsAdded;
    startDemo(ally, enemy);
}

void demoSingleUseFrightener(Field &ally, Field &enemy)
{
    Cards cards;
    auto *d1 = cards.createDecoy();
    auto *d2 = cards.createDecoy();
    auto *d3 = cards.createDecoy();
    auto *d4 = cards.createDecoy();
    auto *s = cards.createAnCraiteGreatsword();
    auto *f = cards.createFrightener();
    ally.cardsAdded = { d1, d2, f };
    ally.hand = { f };
    ally.deck = { d1, d2 };
    enemy.cardsAdded = { d3, d4, s };
    enemy.hand = { s, d3, d4 };
    startDemo(ally, enemy, false, true);
}

void demoAmbushes(Field &ally, Field &enemy)
{
    Cards cards;
    ally.cardsAdded = {
        cards.createVriheddSappers(),
        cards.createVriheddSappers(),
        cards.createDolBlathannaArcher(),
        cards.createDolBlathannaArcher(),
        cards.createSwallow(),
        cards.createSwallow(),
        cards.createVriheddDragoon(),
        cards.createVriheddDragoon(),
        cards.createVriheddDragoon(),
    };
    ally.hand = ally.cardsAdded;
    enemy.cardsAdded = {
        cards.createVriheddSappers(),
        cards.createVriheddSappers(),
        cards.createDolBlathannaArcher(),
        cards.createDolBlathannaArcher(),
        cards.createSwallow(),
        cards.createSwallow(),
        cards.createAlzursThunder(),
        cards.createAnCraiteGreatsword(),
    };
    enemy.hand = enemy.cardsAdded;
    startDemo(ally, enemy);
}

void demoMalena(Field &ally, Field &enemy)
{
    Cards cards;
    auto *m = cards.createMalena();
    auto *d = cards.createDolBlathannaArcher();
    auto *t3 = cards.createTemerianDrummer();
    ally.cardsAdded = {m, d, t3};

    auto *t1 = cards.createTemerianDrummer();
    auto *t2 = cards.createTemerianDrummer();
    auto *t4 = cards.createTemerianDrummer();
    auto *t5 = cards.createTemerianDrummer();
    auto *mo = cards.createMorkvarg();
    auto *v = cards.createVreemde();
    enemy.cardsAdded = {t1, t2, t4, t5, mo, v};

    ally.hand = {m, d, t3};
    enemy.rowRange = {t1, t2, mo, v};
    enemy.hand = {t4, t5};
    startDemo(ally, enemy);
}

void demoCharm(Field &ally, Field &enemy)
{
    Cards cards;
    ally.cardsAdded = {
        cards.createMuzzle(),
        cards.createMuzzle(),
        cards.createGermainPiquant(),
        cards.createGermainPiquant(),
    };
    ally.hand = ally.cardsAdded;
    enemy.cardsAdded = {
        cards.createTemerianDrummer(),
        cards.createTemerianDrummer(),
    };
    enemy.rowRange = enemy.cardsAdded;
    startDemo(ally, enemy);
}

void demoRockBarrage(Field &ally, Field &enemy)
{
    Cards cards;
    ally.cardsAdded = {
        cards.createGermainPiquant(),
        cards.createGermainPiquant(),
        cards.createGermainPiquant(),
        cards.createGermainPiquant(),
        cards.createAddaStriga(),
        cards.createTemerianDrummer(),
        cards.createTridamInfantry(),
    };
    ally.hand = ally.cardsAdded;
    enemy.cardsAdded = {
        cards.createRockBarrage(),
        cards.createRockBarrage(),
        cards.createRockBarrage(),
        cards.createRockBarrage(),
        cards.createRockBarrage(),
        cards.createRockBarrage(),
    };
    enemy.hand = enemy.cardsAdded;
    startDemo(ally, enemy, false, true);
}

void demoMoving(Field &ally, Field &enemy)
{
    Cards cards;
    ally.cardsAdded = {
        cards.createGermainPiquant(),
        cards.createGermainPiquant(),
        cards.createGermainPiquant(),
    };
    ally.hand = ally.cardsAdded;
    enemy.cardsAdded = {
        cards.createRockBarrage(),
        cards.createNivellen(),
        cards.createNivellen(),
    };
    enemy.hand = enemy.cardsAdded;
    startDemo(ally, enemy, false, true);
}

void demoUnseenElder(Field &ally, Field &enemy)
{
    Cards cards;
    auto *u = cards.createUnseenElder();
    auto *t3 = cards.createTemerianDrummer();
    auto *p1 = cards.createPoorFingInfantry();
    auto *p2 = cards.createPoorFingInfantry();
    auto *p3 = cards.createPoorFingInfantry();
    ally.cardsAdded = {u, t3, p1, p2, p3};

    auto *t1 = cards.createTemerianDrummer();
    auto *t2 = cards.createTemerianDrummer();
    auto *mo = cards.createMorkvarg();
    auto *w1 = cards.createWolf();
    auto *w2 = cards.createWolf();
    enemy.cardsAdded = {t1, t2, mo, w1, w2};

    ally.hand = {u, t3};
    ally.rowMeele = {p1, p2, p3};
    enemy.rowMeele = {w1, w2};
    enemy.rowRange = {mo};
    enemy.hand = {t1, t2};
    startDemo(ally, enemy);
}

void demoRunestones(Field &ally, Field &enemy)
{
    Cards cards;
    auto *r1 = cards.createZoriaRunestone();
    auto *r2 = cards.createDevanaRunestone();
    auto *r3 = cards.createDazhbogRunestone();
    auto *r4 = cards.createMoranaRunestone();
    auto *r5 = cards.createStribogRunestone();
    ally.cardsAdded = {r1, r2, r3, r4, r5};

    auto *w1 = cards.createWolf();
    auto *w2 = cards.createWolf();
    auto *w3 = cards.createWolf();
    enemy.cardsAdded = {w1, w2, w3};

    ally.hand = {r1, r2, r3, r4, r5};
    enemy.rowMeele = {w1, w2, w3};
    startDemo(ally, enemy);
}

void demoMonsterLeaders(Field &ally, Field &enemy)
{
    Cards cards;
    auto *u = cards.createUnseenElder();
    auto *w = cards.createWhisperingHillock();
    auto *t3 = cards.createTemerianDrummer();
    auto *p1 = cards.createPoorFingInfantry();
    auto *p2 = cards.createPoorFingInfantry();
    auto *p3 = cards.createPoorFingInfantry();
    ally.cardsAdded = {u, w, t3, p1, p2, p3};

    auto *t1 = cards.createTemerianDrummer();
    auto *t2 = cards.createTemerianDrummer();
    auto *mo = cards.createMorkvarg();
    auto *w1 = cards.createWolf();
    auto *w2 = cards.createWolf();
    enemy.cardsAdded = {t1, t2, mo, w1, w2};

    ally.hand = {u, t3, w};
    ally.rowMeele = {p1, p2, p3};
    enemy.rowMeele = {w1, w2};
    enemy.rowRange = {mo};
    enemy.hand = {t1, t2};
    startDemo(ally, enemy);
}

void demoLeoBonhart(Field &ally, Field &enemy)
{
    Cards cards;
    ally.cardsAdded = {
        cards.createLeoBonhart(),
        cards.createCahirDyffryn(),
        cards.createSentry(),
        cards.createRockBarrage(),
    };
    ally.hand = ally.cardsAdded;
    enemy.cardsAdded = {
        cards.createDjengeFrett()
    };
    enemy.rowRange = enemy.cardsAdded;
    startDemo(ally, enemy);
}

void demoMonsterSisters(Field &ally, Field &enemy)
{
    Cards cards;
    auto *w1 = cards.createBrewess();
    auto *w2 = cards.createWeavess();
    auto *w3 = cards.createWhispess();
    auto *gw1 = cards.createWeavessIncantation();
    auto *gw2 = cards.createWeavessIncantation();
    auto *gb1 = cards.createBrewessRitual();
    auto *gb2 = cards.createBrewessRitual();
    auto *gb3 = cards.createBrewessRitual();
    auto *gwh = cards.createWhispessTribute();
    auto *o1 = cards.createArachasVenom();
    auto *o2 = cards.createManticoreVenom();
    auto *o3 = cards.createAdrenalineRush();
    auto *o4 = cards.createMandrake();
    auto *o5 = cards.createBloodcurdlingRoar();
    auto *t = cards.createTuirseachArcher();
    auto *d1 = cards.createDao();
    auto *d2 = cards.createDao();
    auto *k = cards.createKambi();
    auto *n = cards.createNekker();
    ally.cardsAdded = {w1, w2, w3, gw1, gw2, gb1, gb2, gb3, gwh, d1, d2, k, t, o1, o2, o3, o4, o5, n};


    ally.hand = {w1, gw1, gb1, gb2, gwh, t};
    ally.deck = {w2, w3, gw2, o1, o2, o3, o4, o5};
    ally.discard = {gb3, d1, d2, k, n};
    startDemo(ally, enemy);
}

void demoLockingDeathwish(Field &ally, Field &enemy)
{
    Cards cards;
    ally.cardsAdded = {
        cards.createAuckes(),
        cards.createDimunLightLongship(),
        cards.createRagingBerserker(),
        cards.createAlzursThunder(),
        cards.createAlzursThunder(),
    };
    ally.hand = ally.cardsAdded;
    enemy.cardsAdded = {
        cards.createDimunLightLongship(),
        cards.createDao(),
        cards.createDao(),
    };
    enemy.rowRange = enemy.cardsAdded;
    startDemo(ally, enemy);
}

void demoNilfgaardReveal(Field &ally, Field &enemy)
{
    Cards cards;
    const std::vector<Card *> deckStartingAlly = {
        cards.createLeoBonhart(), cards.createVilgefortz(), cards.createTiborEggebracht(), cards.createVattierDeRideaux(),
        cards.createCynthia(), cards.createSerrit(), cards.createHeftyHelge(), cards.createHenryVarAttre(), cards.createSweers(), cards.createAlbrich(),
        cards.createDaerlanSoldier(), cards.createDaerlanSoldier(), cards.createDaerlanSoldier(),
        cards.createFireScorpion(), cards.createFireScorpion(), cards.createImperialGolem(),
        cards.createSpotter(), cards.createAlchemist(), cards.createMasterOfDisguise(),
        cards.createMangonel(), cards.createMangonel(), cards.createMangonel(),
        cards.createNauzicaaSergeant(), cards.createImperialGolem(), cards.createImperialGolem()
    };
    const std::vector<Card *> deckStartingEnemy = {
        cards.createJohnNatalis(), cards.createKeiraMetz(), cards.createPriscilla(), cards.createSeltkirkOfGulet(),
        cards.createReinforcements(), cards.createVes(), cards.createSileDeTansarville(),
        cards.createTrollololo(), cards.createPrinceStennis(), cards.createVincentMeis(),
        cards.createRedanianKnightElect(), cards.createRedanianKnightElect(), cards.createRedanianKnightElect(),
        cards.createRedanianElite(), cards.createRedanianElite(), cards.createRedanianElite(),
        cards.createReaverScout(), cards.createReaverScout(), cards.createReaverScout(),
        cards.createKaedweniCavalry(), cards.createKaedweniCavalry(), cards.createKaedweniCavalry(),
        cards.createReconnaissance(), cards.createThunderbolt(), cards.createThunderbolt(),
    };
    initField(deckStartingAlly, cards.createMorvranVoorhis(), ally);
    initField(deckStartingEnemy, cards.createJanCalveit(), enemy);
    startNextRound(ally, enemy);
}

void demoLastPlayed(Field &ally, Field &enemy)
{
    Cards cards;
    ally.cardsAdded = {
        cards.createSummoningCircle(),
        cards.createSummoningCircle(),
        cards.createYenneferEnchantress(),
        cards.createYenneferEnchantress(),
        cards.createXavierMoran(),
        cards.createCleaver(),
        cards.createCleaver(),
        cards.createFrightener(),
    };
    ally.hand = ally.cardsAdded;
    startDemo(ally, enemy);
}

void demoBlueStripes(Field &ally, Field &enemy)
{
    Cards cards;
    ally.cardsAdded = {
        cards.createVernonRoche(),
        cards.createBlueStripeScout(),
        cards.createBlueStripeScout(),
        cards.createBlueStripeScout(),
        cards.createRoach(),
        cards.createBlueStripeCommando(),
        cards.createBlueStripeCommando(),
        cards.createBlueStripeCommando(),
    };
    ally.deck = ally.cardsAdded;
    enemy.passed = true;
    ally.canPass = false;
    for (int i = 0; i < 4; ++i)
        drawACard(ally, enemy, nullptr);
    startDemo(ally, enemy);
}

void demoWildHunt(Field &ally, Field &enemy)
{
    Cards cards;
    auto *whh1 = cards.createWildHuntHound();
    auto *whh2 = cards.createWildHuntHound();
    auto *bf1 = cards.createBitingFrost();
    auto *bf2 = cards.createBitingFrost();
    auto *whw1 = cards.createWildHuntWarrior();
    auto *whw2 = cards.createWildHuntWarrior();
    auto *whw3 = cards.createWildHuntWarrior();
    auto *whn1 = cards.createWildHuntNavigator();
    auto *whn2 = cards.createWildHuntNavigator();
    auto *whn3 = cards.createWildHuntNavigator();
    auto *n = cards.createNithral();
    auto *i = cards.createImlerith();
    auto *m = cards.createMiruna();
    auto *e = cards.createEredinBreaccGlas();
    auto *c = cards.createCaranthirArFeiniel();
    auto *d = cards.createWildHuntDrakkar();
    auto *whr1 = cards.createWildHuntRider();
    auto *whr2 = cards.createWildHuntRider();
    ally.cardsAdded = {m, whh1, whh2, bf1, bf2, whw1, whw2, whw3, whn1, whn2, whn3, n, i, e, c, d, whr1, whr2};

    auto *b1 = cards.createBrewessRitual();
    auto *m2 = cards.createImperialManticore();
    auto *m3 = cards.createImperialManticore();
    auto *m4 = cards.createImperialManticore();
    auto *m5 = cards.createImperialManticore();
    auto *m6 = cards.createImperialManticore();
    enemy.cardsAdded = {b1, m2, m3, m4, m5, m6};

    ally.hand = {m, whh1,  whh2, whw1, whn1, n, i, e, c, d};
    ally.deck = {bf1, bf2, whw2, whw3};
    ally.rowSeige = {whn3, whr1};
    ally.rowMeele = {whr2};

    enemy.rowSeige = {b1};
    enemy.rowRange = {m2, m3};
    enemy.rowMeele = {m4, m5, m6};

    startDemo(ally, enemy);
}

void demoSummoning(Field &ally, Field &enemy)
{
    Cards cards;
    auto *a1 = cards.createArachasDrone();
    auto *a2 = cards.createArachasDrone();
    auto *a3 = cards.createArachasDrone();
    auto *a4 = cards.createArachasDrone();
    auto *s1 = cards.createDrummondShieldmaid();
    auto *s2 = cards.createDrummondShieldmaid();
    auto *s3 = cards.createDrummondShieldmaid();
    auto *s4 = cards.createDrummondShieldmaid();
    auto *as = cards.createAnCraiteArmorsmith();
    auto *t = cards.createTuirseachArcher();
    auto *m = cards.createMaerolorn();
    auto *mn = cards.createMonsterNest();
    auto *r = cards.createRotfiend();
    auto *d = cards.createDao();
    ally.cardsAdded = {a1, a2, a3, a4, s1, s2, s3, s4, as, t, m, mn, r, d};

    ally.hand = {a1, a2, s1, s2, m, mn, as, t};
    ally.discard = {a3, s3};
    ally.deck = {a4, s4, r, d};

    startDemo(ally, enemy);
}

void demoBigOgrs(Field &ally, Field &enemy)
{
    Cards cards;
    auto *osa = cards.createOldSpeartipAsleep();
    auto *os = cards.createOldSpeartip();
    auto *g = cards.createGolyat();
    auto *m = cards.createMorvudd();
    auto *d = cards.createDagon();
    ally.cardsAdded = {osa, os, g, m, d};
    ally.hand = {osa, os, g, m, d};

    auto *h1 = cards.createHeymaeyHerbalist();
    auto *h2 = cards.createHeymaeyHerbalist();
    auto *h3 = cards.createHeymaeyHerbalist();
    auto *b1 = cards.createBear();
    auto *b2 = cards.createBear();
    auto *a1 = cards.createTuirseachArcher();
    auto *a2 = cards.createTuirseachArcher();
    auto *th1 = cards.createTuirseachHunter();
    auto *th2 = cards.createTuirseachHunter();
    auto *th3 = cards.createTuirseachHunter();
    enemy.cardsAdded = {h1, h2, h3, b1, b2, a1, a2, th1, th2, th3};
    enemy.hand = {a1, a2, th1};
    enemy.rowRange = {b1, h1, h2, h3, b2};
    enemy.rowMeele = {th2, th3};

    startDemo(ally, enemy);
}

void demoConsume(Field &ally, Field &enemy)
{
    Cards cards;
    auto *g1 = cards.createGhoul();
    auto *m1 = cards.createImperialManticore();
    auto *m2 = cards.createImperialManticore();
    auto *m3 = cards.createImperialManticore();
    auto *b1 = cards.createBarbegazi();
    auto *b2 = cards.createBarbegazi();
    auto *d1 = cards.createDevanaRunestone();
    auto *d2 = cards.createDevanaRunestone();
    auto *d3 = cards.createDevanaRunestone();
    auto *o = cards.createOzzrel();
    auto *k = cards.createKayran();
    auto *m0 = cards.createMaerolorn();
    auto *s = cards.createSheTrollOfVergen();
    auto *r1 = cards.createRotfiend();
    auto *a = cards.createArchespore();
    auto *n1 = cards.createNekker();
    auto *n2 = cards.createNekker();
    auto *n3 = cards.createNekker();
    auto *nw = cards.createNekkerWarrior();
    auto *h1 = cards.createHarpy();
    auto *h2 = cards.createHarpy();
    auto *h3 = cards.createHarpy();
    ally.cardsAdded = {g1, m1, m2, m3, b1, b2, d1, d2, d3, o, k, m0, s, r1, a, n1, n2, n3, nw, h1, h2, h3};
    ally.hand = {g1, b1, b2, d1, o, k, m0, s, nw};
    ally.discard = {m1, d2};
    ally.rowMeele = {m2, n1};
    ally.rowSeige = {};
    ally.deck = {d3, m3, r1, a, n2, n3, h1, h2, h3};

    auto *t1 = cards.createTuirseachAxeman();
    auto *t2 = cards.createTuirseachAxeman();
    auto *t3 = cards.createTuirseachAxeman();
    auto *am = cards.createAnCraiteMarauder();
    auto *m = cards.createMorkvarg();
    enemy.cardsAdded = {t1, t2, t3, m, am};
    enemy.rowRange = {t3, m, am};
    enemy.discard = {t1, t2};

    startDemo(ally, enemy);
}

void demoArchesporeJumping(Field &ally, Field &enemy)
{
    Cards cards;
    auto *a1 = cards.createArchespore();
    auto *a2 = cards.createArchespore();
    auto *a3 = cards.createArchespore();
    auto *f1 = cards.createFiend();
    auto *f2 = cards.createFiend();
    auto *f3 = cards.createFiend();
    auto *f4 = cards.createFiend();
    auto *f5 = cards.createFiend();
    auto *f6 = cards.createFiend();
    auto *f7 = cards.createFiend();
    auto *f8 = cards.createFiend();
    auto *f9 = cards.createFiend();
    auto *i = cards.createIfrit();
    ally.cardsAdded = {a1, a2, a3, f1, f2, f3, f4, f5, f6, f7, f8, f9, i};
    ally.hand = {a1, a2, f6, f7, f8, f9, i};
    ally.rowMeele = {f1, f2, f3, f4, f5};
    ally.rowRange = {a3};

    auto *m1 = cards.createImperialManticore();
    auto *m2 = cards.createImperialManticore();
    auto *m3 = cards.createImperialManticore();
    auto *c1 = cards.createCyclops();
    auto *t1 = cards.createTuirseachHunter();
    auto *t2 = cards.createTuirseachHunter();
    auto *t3 = cards.createTuirseachHunter();
    enemy.cardsAdded = {m1, m2, m3, c1, t1, t2, t3};
    enemy.rowMeele = {m1, m2};
    enemy.rowRange = {m3};
    enemy.hand = {c1, t1, t2, t3};

    startDemo(ally, enemy);
}

void demoImlerithSabbath(Field &ally, Field &enemy)
{
    Cards cards;
    auto *i = cards.createImlerithSabbath();
    auto *m1 = cards.createMandrake();
    auto *m2 = cards.createMandrake();
    auto *f = cards.createFrightener();
    ally.cardsAdded = {i, m1, m2, f};
    ally.hand = {i, m1, m2, f};

    auto *d = cards.createDerran();
    auto *h = cards.createHaraldHoundsnout();
    auto *j = cards.createJuttaAnDimun();
    auto *s = cards.createSvanrigeTuirseach();
    enemy.cardsAdded = {d, h, j, s};
    enemy.hand = {h, j};
    enemy.rowRange = {d, s};

    startDemo(ally, enemy);
}

void demoTemporaryForTests(Field &ally, Field &enemy)
{
    Cards cards;
    auto *r = cards.createRaghNarRoog();
    auto *g1 = cards.createGeraltProfessional();
    auto *g2 = cards.createGeraltAard();
    auto *g3 = cards.createGeraltYrden();
    auto *c = cards.createCiriDash();
    auto *b = cards.createBarbegazi();
    auto *t1 = cards.createToadPrince();
    auto *t2 = cards.createToadPrince();
    auto *a = cards.createAguara();
    auto *g = cards.createGaunterODimm();
    auto *t = cards.createTrialOfTheGrasses();

    ally.cardsAdded = {r, g1, g2, g3, c, b, t1, t2, a, g, t};
    ally.hand = {r, g1, g2, g3, c, b, t1, t2, a, g, t};
    ally.canPass = false;

    auto *m1 = cards.createImperialManticore();
    auto *m2 = cards.createImperialManticore();
    auto *m3 = cards.createImperialManticore();
    auto *d = cards.createDandelionPoet();
    enemy.cardsAdded = {m1, m2, m3, d};
    enemy.rowMeele = {m1, m2};
    enemy.rowRange = {m3};
    enemy.rowSeige = {d};

    startDemo(ally, enemy, false, false);
}

void demoNekkerWarrior(Field &ally, Field &enemy)
{
    Cards cards;
    auto *c0 = cards.createNekkerWarrior();
    auto *c1 = cards.createNekkerWarrior();
    auto *c2 = cards.createToadPrince();
    auto *c3 = cards.createToadPrince();
    auto *c4 = cards.createSiren();

    ally.cardsAdded = { c0, c1, c2, c3, c4 };
    ally.hand = { c0, c1, c2, c3 };
    ally.deck = { c4 };
    startDemo(ally, enemy);
}

void demoNekkers(Field &ally, Field &enemy)
{
    Cards cards;
    ally.cardsAdded = {
        cards.createNekker(),
        cards.createNekker(),
        cards.createNekkerWarrior(),
        cards.createBarbegazi(),
        cards.createGhoul(),
        cards.createMaerolorn(),
    };
    ally.hand = ally.cardsAdded;
    startDemo(ally, enemy);
}

void demoArachasDrones(Field &ally, Field &enemy)
{
    Cards cards;
    auto *c0 = cards.createArachasDrone();
    auto *c1 = cards.createArachasDrone();
    auto *c2 = cards.createArachasDrone();
    auto *c3 = cards.createArachasBehemoth();
    auto *c4 = cards.createArachasBehemoth();
    auto *c5 = cards.createCelaenoHarpy();
    auto *c6 = cards.createArachasDrone();
    auto *c7 = cards.createArachasQueen();
    auto *c8 = cards.createBarbegazi();
    auto *c9 = cards.createVranWarrior();

    ally.cardsAdded = { c0, c1, c2, c3, c4, c5, c6, c7, c8, c9};
    ally.hand = { c3, c4, c5, c6, c7, c8, c9};
    ally.deck = { c0, c1, c2 };
    startDemo(ally, enemy);

}

void demoSlyzards(Field &ally, Field &enemy)
{
    Cards cards;
    auto *c0 = cards.createNekkerWarrior();
    auto *c1 = cards.createNekker();
    auto *c2 = cards.createNekker();
    auto *c3 = cards.createNekker();
    auto *c4 = cards.createSiren();
    auto *c5 = cards.createSiren();
    auto *c6 = cards.createSlyzard();
    auto *c7 = cards.createSlyzard();
    auto *c8 = cards.createSlyzard();

    ally.cardsAdded = { c0, c1, c2, c3, c4, c5, c6, c7, c8};
    ally.hand = { c0, c1, c6, c7, c8};
    ally.deck = { c2, c5 };
    ally.discard = { c3, c4 };
    startDemo(ally, enemy);
}

void demoAvalach(Field &ally, Field &enemy)
{
    Cards cards;
    const std::vector<Card *> deckStartingAlly {
        cards.createAvalach(),
        cards.createAvalachSage(),
        cards.createYenneferConjurer(),
        cards.createJohnny(),
        cards.createStregobor(),
        cards.createWyvernScaleShield(),
        cards.createMastercraftedSpear(),
        cards.createMandrake(),
        cards.createMahakamMarauder(),
        cards.createTuirseachArcher(),
        cards.createTuirseachArcher(),
        cards.createTemerianDrummer(),
        cards.createAlbaArmoredCavalry(),
        cards.createIhuarraquax(),
        cards.createSarah(),
};

    const std::vector<Card *> deckStartingEnemy {
        cards.createGeraltOfRivia(),
        cards.createCiriNova(),
        cards.createSiren(),
        cards.createSiren(),
        cards.createSiren(),
        cards.createNekurat(),
        cards.createMonsterNest(),
        cards.createLamia(),
        cards.createLamia(),
        cards.createLamia(),
        cards.createLamia(),
        cards.createLamia(),
        cards.createLamia(),
        cards.createLamia(),
    };
    initField(deckStartingAlly, cards.createBranTuirseach(), ally);
    initField(deckStartingEnemy, cards.createUnseenElder(), enemy);
    startNextRound(ally, enemy);
}

void demoBeer(Field &ally, Field &enemy)
{
    Cards cards;
    auto *h1 = cards.createHeymaeyHerbalist();
    auto *h2 = cards.createHeymaeyHerbalist();
    auto *h3 = cards.createHeymaeyHerbalist();
    auto *b1 = cards.createBear();
    auto *b2 = cards.createBear();
    auto *th1 = cards.createTuirseachHunter();
    auto *th2 = cards.createTuirseachHunter();
    auto *th3 = cards.createTuirseachHunter();
    auto *o = cards.createOdrin();
    auto *a = cards.createAleOfTheAncestors();
    auto *m1 = cards.createMahakamAle();
    auto *m2 = cards.createMahakamAle();
    auto *m3 = cards.createMahakamAle();
    ally.cardsAdded = {h1, h2, h3, b1, b2, th1, th2, th3, o, a, m1, m2, m3};
    ally.hand = {th1, o, a, m1, m2, m3};
    ally.rowRange = {b1, h1, h2, h3, b2};
    ally.rowMeele = {th2, th3};

    startDemo(ally, enemy);
}

void demoCrewAndCrewed(Field &ally, Field &enemy)
{
    Cards cards;
    auto *s1 = cards.createKaedweniSergeant();
    auto *s2 = cards.createKaedweniSergeant();
    auto *b1 = cards.createReinforcedBallista();
    auto *s3 = cards.createRonvidTheIncessant();
    auto *s = cards.createScorch();
    auto *st = cards.createSiegeTower();
    auto *sm1 = cards.createSiegeMaster();
    auto *sm2 = cards.createSiegeMaster();
    auto *dmg1 = cards.createTuirseachArcher();
    auto *dmg2 = cards.createTuirseachArcher();
    auto *dmg3 = cards.createTuirseachHunter();
    auto *dmg4 = cards.createTuirseachHunter();
    auto *ss = cards.createSiegeSupport();

    ally.cardsAdded = {s1, s2, b1, s3, s, st, sm1, sm2, dmg1, dmg2, dmg3, dmg4, ss};
    ally.hand = ally.cardsAdded;

    auto *m1 = cards.createImperialManticore();

    enemy.cardsAdded = {m1};
    enemy.rowMeele = {m1};

    startDemo(ally, enemy);
}

void demoSheTrollOfVergen(Field &ally, Field &enemy)
{
    Cards cards;
    auto *s1 = cards.createSheTrollOfVergen();
    auto *s2 = cards.createSheTrollOfVergen();
    auto *b1 = cards.createDao();
    auto *b2 = cards.createDao();
    auto *b3 = cards.createDao();

    ally.cardsAdded = {s1, s2, b1, b2, b3};
    ally.hand = {s1, s2, b3};
    ally.deck = {b1, b2};

    startDemo(ally, enemy);
}

void demoSigismundDijkstra(Field &ally, Field &enemy)
{
    Cards cards;
    auto *s = cards.createSigismundDijkstra();
    auto *b1 = cards.createKaedweniKnight();
    auto *r = cards.createReaverScout();
    auto *b2 = cards.createKaedweniKnight();
    auto *a = cards.createAbaya();

    ally.cardsAdded = {s, b1, b2, r, a};
    ally.hand = {s};
    ally.deck = {b1, r, b2, a};

    startDemo(ally, enemy);
}

void demoRowsSelection(Field &ally, Field &enemy)
{
    Cards cards;
    auto *c1 = cards.createBitingFrost();
    auto *c2 = cards.createGoldenFroth();
    auto *c3 = cards.createNekurat();
    auto *c4 = cards.createAleOfTheAncestors();
    auto *c5 = cards.createWoodlandSpirit();
    auto *c6 = cards.createBirnaBran();
    auto *c7 = cards.createCaranthirArFeiniel();
    auto *c8 = cards.createKorathiHeatwave();
    auto *c9 = cards.createGeraltIgni();
    auto *c10 = cards.createBridgeTroll();
    auto *c11 = cards.createWhiteFrost();

    ally.cardsAdded = {c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11};
    ally.hand = ally.cardsAdded;

    auto *m1 = cards.createImperialManticore();
    auto *m2 = cards.createImperialManticore();
    auto *m3 = cards.createImperialManticore();
    auto *m4 = cards.createImperialManticore();

    enemy.cardsAdded = {m1, m2, m3, m4};
    enemy.rowMeele = {m1, m2};
    enemy.rowRange = {m3, m4};

    startDemo(ally, enemy);
}

void demoWolfsbane(Field &ally, Field &enemy)
{
    Cards patch;
    std::vector<Card *> cards;
    cards.push_back(patch.createWolfsbane());
    for (int i = 0; i < 9; ++i)
        cards.push_back(patch.createWolf());

    ally.cardsAdded = cards;
    ally.hand = cards;

    auto *c1 = patch.createImperialManticore();
    auto *c2 = patch.createImperialManticore();

    enemy.cardsAdded = {c1, c2};
    enemy.rowMeele = {c1, c2};

    startDemo(ally, enemy);
}

void demoDeckSummon(Field &ally, Field &enemy)
{
    Cards cards;
    auto *c1 = cards.createAelirenn();
    auto *c2 = cards.createDunBanner();
    auto *c3 = cards.createDunBanner();
    auto *c4 = cards.createDunBanner();
    auto *c5 = cards.createSwallow();
    auto *c6 = cards.createHalfElfHunter();
    auto *c7 = cards.createHalfElfHunter();
    auto *c8 = cards.createHalfElfHunter();
    auto *c9 = cards.createGeraltIgni();
    auto *c10 = cards.createRoach();

    ally.cardsAdded = {c1, c2, c3, c4, c5, c6, c7, c8, c9, c10};
    ally.hand = {c5, c6, c7, c8, c9};
    ally.deck = {c1, c2, c3, c4, c10};

    auto *m1 = cards.createImperialManticore();
    auto *m2 = cards.createImperialManticore();
    m2->power -= 2;

    enemy.cardsAdded = {m1, m2};
    enemy.rowMeele = {m1, m2};

    startDemo(ally, enemy);
}

void demoTriggersOrder(Field &ally, Field &enemy)
{
    Cards cards;
    auto *c1 = cards.createDolBlathannaArcher();
    auto *c2 = cards.createDolBlathannaArcher();
    auto *c3 = cards.createTuirseachArcher();
    auto *em = cards.createEmhyrVarEmreis();
    auto *bb = cards.createSheTrollOfVergen();
    auto *zr = cards.createZoriaRunestone();
    auto *mm = cards.createDao();
    auto *mm2 = cards.createDao();

    ally.cardsAdded = {c1, c2, c3, em, bb, mm, mm2, zr};
    ally.hand = {c1, c2, c3, em, bb, zr};
    ally.deck = {mm, mm2};

    auto *m1 = cards.createImperialManticore();
    auto *m2 = cards.createImperialManticore();
    m1->power = 3;
    m2->power = 3;

    enemy.cardsAdded = {m1, m2};
    enemy.rowMeele = {m1, m2};
    startDemo(ally, enemy);
}

void demoTurnFinishingAndRoundFinishing(Field &ally, Field &enemy)
{
    Cards cards;
    const std::vector<Card *> deck1 {
        cards.createCow(),
        cards.createCow(),
        cards.createCow(),
        cards.createCow(),
        cards.createCow(),
        cards.createCow(),
        cards.createCow(),
        cards.createCow(),
        cards.createCow(),
        cards.createCow(),
        cards.createCow(),
        cards.createCow(),
        cards.createCow(),
        cards.createCow(),
        cards.createCow(),
        cards.createCow(),
    };

    const std::vector<Card *> deck2 {
        cards.createWolf(),
        cards.createWolf(),
        cards.createWolf(),
        cards.createWolf(),
        cards.createWolf(),
        cards.createWolf(),
        cards.createWolf(),
        cards.createWolf(),
        cards.createWolf(),
        cards.createWolf(),
        cards.createWolf(),
        cards.createWolf(),
        cards.createWolf(),
        cards.createWolf(),
        cards.createWolf(),
        cards.createWolf(),
    };

    initField(deck1, nullptr, ally);
    initField(deck2, nullptr, enemy);
    // startDemo(ally, enemy, false, true);
    startNextRound(ally, enemy);
}

void demoAllTypedChoices(Field &ally, Field &enemy)
{
    Cards cards;
    ally.cardsAdded = {
        cards.createAdrenalineRush(),   // target exist
        cards.createMonsterNest(),      // spawn from all
        cards.createZoriaRunestone(),   // cards.create from all
        cards.createKeiraMetz(),        // outer option
        cards.createMandrake(),         // inner option
        cards.createImpenetrableFog(),  // row
        cards.createAguara(),           // complex one

        cards.createOrnamentalSword(),
        cards.createVreemde(),
        cards.createShupesDayOff(),
        cards.createEredinBreaccGlas(),
        cards.createVaedermakar(),
        cards.createGaunterODimm(),
        cards.createWeavessIncantation(),
        cards.createHym(),
        cards.createLethoKingslayer(),
        cards.createEistTuirseach(),
        cards.createMoonlight(),

    };
    ally.hand = ally.cardsAdded;

    auto *m1 = cards.createImperialManticore();
    auto *m2 = cards.createImperialManticore();

    enemy.cardsAdded = {m1, m2};
    enemy.rowMeele = {m1, m2};
    startDemo(ally, enemy);
}

void demoNeutralSpecial(Field &ally, Field &enemy)
{
    Cards cards;
    auto *h = cards.createHanmarvynsDream();
    auto *b = cards.createBlackBlood();
    auto *br = cards.createBekkersRockslide();
    auto *bm = cards.createBekkersDarkMirror();
    auto *bf = cards.createBitingFrost();
    auto *g = cards.createGoldenFroth();
    auto *mh = cards.createMerigoldsHailstorm();
    auto *nm = cards.createNecromancy();
    auto *st = cards.createStammelfordsTremor();
    auto *d = cards.createDimeritiumBomb();
    auto *lw = cards.createTheLastWish();
    auto *ds = cards.createDimeritiumShackles();
    auto *ws = cards.createWyvernScaleShield();
    auto *ms = cards.createMastercraftedSpear();
    auto *ud = cards.createJuttaAnDimun();
    auto *rd = cards.createRoyalDecree();
    auto *uc = cards.createUmasCurse();
    auto *tb = cards.createTrissButterflies();
    auto *ye = cards.createYenneferEnchantress();
    auto *dop = cards.createDoppler();
    auto *md = cards.createMardroeme();
    auto *s = cards.createSihil();
    auto *dd = cards.createDragonsDream();

    auto *lead = cards.createBranTuirseach();

    ally.cardsAdded = {h, b, br, bm, bf, g, mh, nm, st, d, lw, ds, ws, ms, ud, tb, ye, dop, lead, md, s, dd};
    ally.leader = lead;
    ally.hand = {bf, g, lw, ds, ud, rd, uc, dop, s, dd};
    ally.deck = {h, b, br, bm, mh, nm, st, d, ws, ms, tb, ye, md};

    auto *a2 = cards.createAbaya();
    auto *e = cards.createEkimmara();
    auto *n = cards.createNekker();
    auto *u = cards.createUnseenElder();
    auto *w = cards.createWoodlandSpirit();
    auto *h1 = cards.createHanmarvynsDream();

    enemy.cardsAdded = {a2, e, n, u, w, h1};
    enemy.rowRange = {a2, e, n};
    enemy.discard = {u, w, h1};
    enemy.passed = true;

    startDemo(ally, enemy);
}

void demoGoldWitchers(Field &ally, Field &enemy)
{
    Cards cards;
    auto *e = cards.createEskelPathfinder();
    auto *l = cards.createLambertSwordmaster();
    auto *v = cards.createVesemirMentor();
    auto *dd = cards.createDragonsDream();
    auto *g = cards.createGoldenFroth();
    auto *c = cards.createCrowsEye();


    ally.cardsAdded = {e, l, v, dd, g, c};
    ally.hand = {e, l, v, dd};
    ally.deck = {g, c};


    auto *a1 = cards.createAbaya();
    auto *a2 = cards.createAbaya();
    auto *a3 = cards.createAbaya();
    auto *a4 = cards.createAbaya();
    auto *n = cards.createNekker();
    auto *u = cards.createUnseenElder();
    auto *w = cards.createWoodlandSpirit();
    auto *h1 = cards.createHanmarvynsDream();

    enemy.cardsAdded = {a1, a2, a3, a4, n, u, w, h1};
    enemy.rowRange = {a1, a2, a3, a4, n};
    enemy.discard = {u, w, h1};
    enemy.passed = true;

    startDemo(ally, enemy);
}

void demoNeutralDudes(Field &ally, Field &enemy)
{
    Cards cards;
    auto *o1 = cards.createOlaf();
    auto *o2 = cards.createOlaf();
    auto *o3 = cards.createOlaf();
    auto *o4 = cards.createOlaf();
    auto *o5 = cards.createOlaf();
    auto *r = cards.createRegisHigherVampire();
    auto *z = cards.createZoltanScoundrel();
    auto *y = cards.createYenneferConjurer();

    ally.cardsAdded = {o1, o2, o3, o4, o5, r, z, y};
    ally.hand = {r, z, y};
    ally.rowMeele = {o1, o2, o3, o4, o5};

    auto *e1 = cards.createAncientFoglet();
    auto *e2 = cards.createAbaya();
    auto *e3 = cards.createCockatrice();
    auto *e4 = cards.createCaranthirArFeiniel();
    auto *e5 = cards.createNithral();
    auto *e6 = cards.createGeels();
    auto *e7 = cards.createWoodlandSpirit();
    auto *e8 = cards.createWildHuntDrakkar();

    enemy.cardsAdded = {e1, e2, e3, e4, e5, e6, e7, e8};
    enemy.deck = {e1, e2, e3};
    enemy.rowMeele = {e4, e5, e6, e7, e8};
    enemy.passed = true;

    startDemo(ally, enemy);
}

void demoPowerChanged(Field &ally, Field &enemy)
{
    Cards cards;
    auto *i = cards.createIhuarraquax();
    auto *mm = cards.createMahakamMarauder();
    auto *m1 = cards.createMandrake();
    auto *m2 = cards.createMandrake();
    auto *g = cards.createGeraltYrden();
    auto *z = cards.createZoltanChivay();
    auto *v = cards.createVillentretenmerth();
    auto *k = cards.createKingOfBeggars();
    auto *iris = cards.createIrisVonEverec();
    auto *i2 = cards.createInfiltrator();

    ally.cardsAdded = {i, mm, m1, m2, g, z, v, k, iris, i2};
    ally.hand = {i, mm, m1, m2, g, z, v, k, iris, i2};

    auto *e1 = cards.createOlaf();
    auto *e2 = cards.createOlaf();
    auto *e3 = cards.createOlaf();
    auto *e4 = cards.createOlaf();

    enemy.cardsAdded = {e1, e2, e3, e4};
    enemy.rowMeele = {e1, e2, e3, e4};
    enemy.passed = true;

    startDemo(ally, enemy);
}

void demoAedirnDragon(Field &ally, Field &enemy)
{
    Cards cards;
    auto *m1 = cards.createPeasantMilitia();
    auto *m2 = cards.createPrizeWinningCow();
    auto *m3 = cards.createMandrake();
    auto *b1 = cards.createBoneTalisman();
    auto *b2 = cards.createBoneTalisman();
    auto *b3 = cards.createBoneTalisman();
    auto *s = cards.createSaesenthessisBlaze();
    auto *m = cards.createMyrgtabrakke();

    ally.cardsAdded = {m1, m2, m3, b1, b2, s, m};
    ally.hand = {b1, b2, b3, s};
    ally.deck = {m, m1, m2, m3};

    auto *o = cards.createOlaf();
    enemy.cardsAdded = {o};
    enemy.rowMeele = {o};
    enemy.passed = true;

    startDemo(ally, enemy);
}

void demoLeaders(Field &ally, Field &enemy)
{
    Cards cards;
    auto *sc1 = cards.createCrowsEye();
    auto *sc2 = cards.createMardroeme();
    auto *sc3 = cards.createMardroeme();
    auto *mv = cards.createManticoreVenom();
    auto *u = cards.createUsurper();
    auto *y = cards.createYaevinn();
    auto *b = cards.createBraenn();
    auto *m1 = cards.createMalena();
    auto *m2 = cards.createMorenn();
    auto *f = cards.createFilavandrel();
    auto *r = cards.createMoranaRunestone();
    auto *s1 = cards.createTorrentialRain();
    auto *s2 = cards.createGoldenFroth();
    auto *s = cards.createSheldonSkaggs();
    auto *e = cards.createEithne();

    ally.cardsAdded = {sc1, sc2, sc3, mv, u, y, b, m1, m2, f, r, s1, s2, s, e};
    ally.hand = {sc1, u, y, b, f, s, e, m1, m2};
    ally.deck = {sc3, s1, s2};
    ally.discard = {sc2, mv, r};

    auto *o = cards.createOlaf();
    auto *em1 = cards.createMandrake();
    auto *emv = cards.createManticoreVenom();
    enemy.cardsAdded = {o, em1, emv};
    enemy.rowMeele = {o};
    enemy.discard = {em1, emv};
    enemy.passed = true;

    startDemo(ally, enemy);
}

void demoDwarws(Field &ally, Field &enemy)
{
    Cards cards;
    auto *da1 = cards.createDwarvenAgitator();
    auto *da2 = cards.createDwarvenAgitator();
    auto *da3 = cards.createDwarvenAgitator();
    auto *ds1 = cards.createDwarvenSkirmisher();
    auto *dm1 = cards.createDwarvenMercenary();
    auto *h1 = cards.createHawkerSupport();
    auto *mg1 = cards.createMahakamGuard();
    auto *e = cards.createElvenScout();

    ally.cardsAdded = {da1, da2, da3, ds1, dm1, h1, mg1, e};
    ally.hand = {da1, da2, ds1, h1, mg1};
    ally.deck = {da3, dm1, e};

    enemy.cardsAdded = {cards.createOlaf(), cards.createDwarvenAgitator()};
    enemy.rowMeele = enemy.cardsAdded;

    startDemo(ally, enemy, true, false);
}

void demoSwapElves(Field &ally, Field &enemy)
{
    Cards cards;
    auto *es1 = cards.createElvenScout();
    auto *es2 = cards.createElvenScout();
    auto *es3 = cards.createElvenScout();
    auto *w1 = cards.createWardancer();
    auto *w2 = cards.createWardancer();
    auto *v1 = cards.createVriheddVanguard();

    ally.cardsAdded = {es1, es2, es3, w1, w2, v1};
    ally.hand = {es1, w1, w2, v1};
    ally.deck = {es2, es3};

    startDemo(ally, enemy, true, false);
}

void demoWithOpion1(Field &ally, Field &enemy)
{
    Cards cards;
    auto *h = cards.createHym();
    auto *p = cards.createPrinceStennis();

    initField({h}, nullptr, ally);
    initField({p}, nullptr, enemy);
    drawACard(ally, enemy, nullptr);
    startDemo(ally, enemy);
}

void demoWithWindow5(Field &ally, Field &enemy)
{
    Cards cards;
    auto *h = cards.createShupesDayOff();
    initField({h}, nullptr, ally);
    drawACard(ally, enemy, nullptr);
    startDemo(ally, enemy, false, true);
}

void demoEmpty(Field &ally, Field &enemy)
{
    Cards cards;
    startNextRound(ally, enemy);
}

void demoNilfsTemporary(Field &ally, Field &enemy)
{
    Cards cards;
    auto *a1 = cards.createStefanSkellen();
    auto *a2 = cards.createShilard();
    auto *a3 = cards.createXarthisius();
    auto *a4 = cards.createElvenScout();
    auto *a5 = cards.createElvenScout();
    auto *a6 = cards.createAssassination();

    ally.cardsAdded = {a1, a2, a3, a4, a5, a6};
    ally.hand = {a1, a2, a3};
    ally.deck = {a4, a5, a6};

    auto *e1 = cards.createImperialManticore();
    auto *e2 = cards.createImperialManticore();
    auto *e3 = cards.createImperialManticore();
    auto *e4 = cards.createMardroeme();
    auto *e5 = cards.createMardroeme();
    auto *e6 = cards.createMardroeme();

    enemy.cardsAdded = {e1, e2, e3, e4, e5, e6};
    enemy.rowMeele = {e1, e2};
    enemy.deck = {e3, e4, e5, e6};

    startDemo(ally, enemy, true, false);
    // TODO: fix in card.cpp - here in the test Shilard loses Skellen's buff of a unit
}

void demoPanther(Field &ally, Field &enemy)
{
    Cards cards;
    auto *a1 = cards.createPanther();
    auto *a2 = cards.createVicovaroMedic();

    ally.cardsAdded = {a1, a2};
    ally.hand = {a1, a2};

    auto *e1 = cards.createTemerianDrummer();
    auto *e2 = cards.createTemerianDrummer();
    auto *e3 = cards.createImperialManticore();
    auto *e4 = cards.createImperialManticore();
    auto *e5 = cards.createImperialManticore();
    auto *e6 = cards.createImperialManticore();

    enemy.cardsAdded = {e1, e2, e3, e4, e5, e6};
    enemy.rowMeele = {e1, e2};
    enemy.rowRange = {e3, e4, e5, e6};

    startDemo(ally, enemy, true, false);
}

void demoNilfgaardMages(Field &ally, Field &enemy)
{
    Cards cards;
    auto *a1 = cards.createAssireVarAnahid();
    auto *a2 = cards.createFringillaVigo();
    auto *a3 = cards.createHeftyHelge();
    auto *a4 = cards.createFalseCiri();
    auto *a5 = cards.createAddaStriga();
    auto *a6 = cards.createHeftyHelge();
    auto *a7 = cards.createHeftyHelge();

    ally.cardsAdded = {a1, a2, a3, a4, a5, a6, a7};
    ally.hand = {a1, a2, a3, a4, a5};
    ally.discard = {a6, a7};

    auto *e1 = cards.createTemerianDrummer();
    auto *e2 = cards.createTemerianDrummer();
    auto *e3 = cards.createImperialManticore();
    auto *e4 = cards.createImperialManticore();
    auto *e5 = cards.createImperialManticore();
    auto *e6 = cards.createImperialManticore();

    enemy.cardsAdded = {e1, e2, e3, e4, e5, e6};
    enemy.rowMeele = {e1, e3, e2};
    enemy.hand = {e4, e5};
    enemy.discard = {e6};
    enemy.passed = false;

    startDemo(ally, enemy, false, false);
}

void demoClassToFuncRefactoring(Field &ally, Field &enemy)
{
    Cards cards;
    auto *adda = cards.createAddaStriga();
    auto *adda1 = cards.createAddaStriga();

    ally.cardsAdded = {adda, adda1};
    ally.hand = {adda, adda1};

    startDemo(ally, enemy, false, false);
}

void demoNothern(Field &ally, Field &enemy)
{
    Cards cards;
    auto *m = cards.createImperialManticore();
    auto *m1 = cards.createCantarella();
    auto *m2 = cards.createFrightener();
    auto *d = cards.createDandelion();
    auto *d1 = cards.createDandelionPoet();
    auto *k = cards.createKiyan();
    auto *v = cards.createVandergrift();
    auto *pe = cards.createPhilippaEilhart();
    auto *f = cards.createKingFoltest();
    auto *b = cards.createBotchling();
    auto *b1 = cards.createBotchling();
    auto *b2 = cards.createLubberkin();
    auto *w = cards.createLubberkin();
    auto *s = cards.createSwallow();

    ally.cardsAdded = {v, pe, f, d, d1, k, b, b1, b2, w, s};
    ally.leader = f;
    ally.hand = {d, d1, k, pe, v};
    ally.deck = {b, b1, b2, w, s};

    enemy.cardsAdded = {m, m1, m2};
    enemy.rowMeele = {m, m1};
    enemy.rowRange = {m2};

    startDemo(ally, enemy, true, true);
}

void demoTreason(Field &ally, Field &enemy)
{
    Cards cards;
    auto *a1 = cards.createImperialManticore();
    auto *a2 = cards.createImperialManticore();
    auto *a3 = cards.createTreason();
    auto *a4 = cards.createRotTosser();
    auto *a5 = cards.createSwallow();
    auto *a6 = cards.createSwallow();

    ally.cardsAdded = {a1, a2, a3, a4, a5, a6};
    ally.rowMeele = {a1, a2};
    ally.hand = {a3, a4, a5, a6};

    auto *m = cards.createImperialManticore();
    auto *m1 = cards.createCantarella();
    auto *m2 = cards.createMilva();
    auto *m3 = cards.createTemerianDrummer();
    auto *m4 = cards.createMorenn();
    auto *m5 = cards.createTemerianDrummer();
    auto *m6 = cards.createTemerianDrummer();

    auto *r = cards.createImperialManticore();
    auto *r1 = cards.createMorenn();
    auto *r2 = cards.createTemerianDrummer();

    auto *s = cards.createTemerianDrummer();

    enemy.cardsAdded = {m, m1, m2, m3, m4, m5, m6, r, r1, r2, s};
    enemy.rowMeele = {m, m1, m2, m3, m4, m5, m6};
    enemy.rowRange = {r, r1, r2};
    enemy.rowSeige = {s};

    startDemo(ally, enemy, true, true);
}

void demoNennekeAndMages(Field &ally, Field &enemy)
{
    Cards cards;
    auto *n = cards.createNenneke();
    auto *m1 = cards.createReinforcedBallista();
    auto *m2 = cards.createReinforcedBallista();
    auto *m3 = cards.createReinforcedBallista();
    auto *m4 = cards.createReinforcedBallista();
    auto *m5 = cards.createReinforcedBallista();
    auto *ch1 = cards.createMargaritaOfAretuza();
    auto *ch2 = cards.createSabrinaGlevissig();
    auto *ch3 = cards.createSabrinasSpecter();
    auto *th = cards.createTuirseachHunter();
    auto *c = cards.createBear();

    auto *fp = cards.createFoltestsPride();

    ally.cardsAdded = {n, m1, m2, m3, m4, m5, ch1, ch2, ch3, th, c, fp};
    ally.rowMeele = {m1};
    ally.hand = {n, ch1, ch2, ch3, th, fp};
    ally.discard = {m2, m3, m4, m5, c};

    auto *m6 = cards.createReinforcedBallista();
    auto *m7 = cards.createReinforcedBallista();
    auto *m8 = cards.createReinforcedBallista();

    enemy.cardsAdded = {m6, m7, m8};
    enemy.rowMeele = {m6, m7};
    enemy.discard = {m8};

    boost(m7, 5, ally, enemy, m7);

    startDemo(ally, enemy, true, true);
}

void demoCursed(Field &ally, Field &enemy)
{
    Cards cards;
    auto *s1 = cards.createDamnedSorceress();
    auto *s2 = cards.createDamnedSorceress();
    auto *s3 = cards.createDamnedSorceress();
    auto *s4 = cards.createDamnedSorceress();
    auto *kr1 = cards.createKaedweniRevenant();
    auto *kr2 = cards.createKaedweniRevenant();
    auto *kr3 = cards.createKaedweniRevenant();
    auto *s = cards.createSwallow();
    auto *vb = cards.createVandergriftsBlade();

    ally.cardsAdded = {s1, s2, s3, s4, kr1, kr2, kr3, s, vb};
    ally.hand = {s1, s2, s3, s4, kr1, kr2, kr3, s, vb};

    auto *m1 = cards.createImperialManticore();
    auto *m2 = cards.createImperialManticore();
    auto *m3 = cards.createImperialManticore();

    enemy.cardsAdded = {m1, m2, m3};
    enemy.rowMeele = {m1, m2};
    enemy.discard = {m3};

    boost(m1, 5, ally, enemy, m1);

    startDemo(ally, enemy, true, true);
}
