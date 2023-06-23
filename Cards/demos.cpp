#include "demos.h"

void demoHjalmarAnCraite(Field &ally, Field &enemy)
{
    ally.cardsAdded = {
        new HjalmarAnCraite(),
        new TuirseachHunter(),
    };
    ally.hand = ally.cardsAdded;
    startDemo(ally, enemy);
}

void demoHalfElfHunter(Field &ally, Field &enemy)
{
    ally.cardsAdded = {
        new HalfElfHunter(),
        new Decoy(),
    };
    ally.hand = ally.cardsAdded;
    startDemo(ally, enemy);
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
    startDemo(ally, enemy);
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
    startDemo(ally, enemy);
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
    startDemo(ally, enemy);
}

void demoTransforms(Field &ally, Field &enemy)
{
    ally.cardsAdded = {new ArtefactCompression(), new Coral()};

    auto *d = new DjengeFrett();
    auto *s = new DimunLightLongship();
    enemy.cardsAdded = {s, d};

    ally.hand = ally.cardsAdded;
    enemy.rowRange = {s, d};
    startDemo(ally, enemy);
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
    startDemo(ally, enemy);
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
    initField(deckStartingEnemy, new MorvranVoorhis, enemy);
    startNextRound(ally, enemy);
}

void demoInstantEffects(Field &ally, Field &enemy)
{
    auto *d1 = new TemerianDrummer();
    auto *d2 = new TemerianDrummer();
    auto *d3 = new TemerianDrummer();
    auto *d4 = new TridamInfantry();
    auto *a = new TuirseachArcher();
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
    ally.cardsAdded = {
        new Dao(),
        new AlzursThunder(),
        new PoorFingInfantry(),
        new HalfElfHunter(),
        new VriheddSappers(),
        new VriheddSappers(),
    };
    ally.hand = ally.cardsAdded;
    startDemo(ally, enemy);
}

void demoSingleUseFrightener(Field &ally, Field &enemy)
{
    auto *d1 = new Decoy();
    auto *d2 = new Decoy();
    auto *d3 = new Decoy();
    auto *d4 = new Decoy();
    auto *s = new AnCraiteGreatsword();
    auto *f = new Frightener();
    ally.cardsAdded = { d1, d2, f };
    ally.hand = { f };
    ally.deck = { d1, d2 };
    enemy.cardsAdded = { d3, d4, s };
    enemy.hand = { s, d3, d4 };
    startDemo(ally, enemy, false, true);
}

void demoAmbushes(Field &ally, Field &enemy)
{
    ally.cardsAdded = {
        new VriheddSappers(),
        new VriheddSappers(),
        new DolBlathannaArcher(),
        new DolBlathannaArcher(),
        new Swallow(),
        new Swallow(),
        new VriheddDragoon(),
        new VriheddDragoon(),
        new VriheddDragoon(),
    };
    ally.hand = ally.cardsAdded;
    enemy.cardsAdded = {
        new VriheddSappers(),
        new VriheddSappers(),
        new DolBlathannaArcher(),
        new DolBlathannaArcher(),
        new Swallow(),
        new Swallow(),
        new AlzursThunder(),
        new AnCraiteGreatsword(),
    };
    enemy.hand = enemy.cardsAdded;
    startDemo(ally, enemy);
}

void demoMalena(Field &ally, Field &enemy)
{
    auto *m = new Malena();
    auto *d = new DolBlathannaArcher();
    auto *t3 = new TemerianDrummer();
    ally.cardsAdded = {m, d, t3};

    auto *t1 = new TemerianDrummer();
    auto *t2 = new TemerianDrummer();
    auto *t4 = new TemerianDrummer();
    auto *t5 = new TemerianDrummer();
    auto *mo = new Morkvarg();
    auto *v = new Vreemde();
    enemy.cardsAdded = {t1, t2, t4, t5, mo, v};

    ally.hand = {m, d, t3};
    enemy.rowRange = {t1, t2, mo, v};
    enemy.hand = {t4, t5};
    startDemo(ally, enemy);
}

void demoCharm(Field &ally, Field &enemy)
{
    ally.cardsAdded = {
        new Muzzle(),
        new Muzzle(),
        new GermainPiquant(),
        new GermainPiquant(),
    };
    ally.hand = ally.cardsAdded;
    enemy.cardsAdded = {
        new TemerianDrummer(),
        new TemerianDrummer(),
    };
    enemy.rowRange = enemy.cardsAdded;
    startDemo(ally, enemy);
}

void demoRockBarrage(Field &ally, Field &enemy)
{
    ally.cardsAdded = {
        new GermainPiquant(),
        new GermainPiquant(),
        new GermainPiquant(),
        new GermainPiquant(),
        new AddaStriga(),
        new TemerianDrummer(),
        new TridamInfantry(),
    };
    ally.hand = ally.cardsAdded;
    enemy.cardsAdded = {
        new RockBarrage(),
        new RockBarrage(),
        new RockBarrage(),
        new RockBarrage(),
        new RockBarrage(),
        new RockBarrage(),
    };
    enemy.hand = enemy.cardsAdded;
    startDemo(ally, enemy, false, true);
}

void demoMoving(Field &ally, Field &enemy)
{
    ally.cardsAdded = {
        new GermainPiquant(),
        new GermainPiquant(),
        new GermainPiquant(),
    };
    ally.hand = ally.cardsAdded;
    enemy.cardsAdded = {
        new RockBarrage(),
        new Nivellen(),
        new Nivellen(),
    };
    enemy.hand = enemy.cardsAdded;
    startDemo(ally, enemy, false, true);
}

void demoUnseenElder(Field &ally, Field &enemy)
{
    auto *u = new UnseenElder();
    auto *t3 = new TemerianDrummer();
    auto *p1 = new PoorFingInfantry();
    auto *p2 = new PoorFingInfantry();
    auto *p3 = new PoorFingInfantry();
    ally.cardsAdded = {u, t3, p1, p2, p3};

    auto *t1 = new TemerianDrummer();
    auto *t2 = new TemerianDrummer();
    auto *mo = new Morkvarg();
    auto *w1 = new Wolf();
    auto *w2 = new Wolf();
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
    auto *r1 = new ZoriaRunestone();
    auto *r2 = new DevanaRunestone();
    auto *r3 = new DazhbogRunestone();
    auto *r4 = new MoranaRunestone();
    auto *r5 = new StribogRunestone();
    ally.cardsAdded = {r1, r2, r3, r4, r5};

    auto *w1 = new Wolf();
    auto *w2 = new Wolf();
    auto *w3 = new Wolf();
    enemy.cardsAdded = {w1, w2, w3};

    ally.hand = {r1, r2, r3, r4, r5};
    enemy.rowMeele = {w1, w2, w3};
    startDemo(ally, enemy);
}

void demoMonsterLeaders(Field &ally, Field &enemy)
{
    auto *u = new UnseenElder();
    auto *w = new WhisperingHillock();
    auto *t3 = new TemerianDrummer();
    auto *p1 = new PoorFingInfantry();
    auto *p2 = new PoorFingInfantry();
    auto *p3 = new PoorFingInfantry();
    ally.cardsAdded = {u, w, t3, p1, p2, p3};

    auto *t1 = new TemerianDrummer();
    auto *t2 = new TemerianDrummer();
    auto *mo = new Morkvarg();
    auto *w1 = new Wolf();
    auto *w2 = new Wolf();
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
    ally.cardsAdded = {
        new LeoBonhart(),
        new CahirDyffryn(),
        new Sentry(),
        new RockBarrage(),
    };
    ally.hand = ally.cardsAdded;
    enemy.cardsAdded = {
        new DjengeFrett()
    };
    enemy.rowRange = enemy.cardsAdded;
    startDemo(ally, enemy);
}

void demoMonsterSisters(Field &ally, Field &enemy)
{
    auto *w1 = new Brewess();
    auto *w2 = new Weavess();
    auto *w3 = new Whispess();
    auto *gw1 = new WeavessIncantation();
    auto *gw2 = new WeavessIncantation();
    auto *gb1 = new BrewessRitual();
    auto *gb2 = new BrewessRitual();
    auto *gb3 = new BrewessRitual();
    auto *gwh = new WhispessTribute();
    auto *o1 = new ArachasVenom();
    auto *o2 = new ManticoreVenom();
    auto *o3 = new AdrenalineRush();
    auto *o4 = new Mandrake();
    auto *o5 = new BloodcurdlingRoar();
    auto *t = new TuirseachArcher();
    auto *d1 = new Dao();
    auto *d2 = new Dao();
    auto *k = new Kambi();
    auto *n = new Nekker();
    ally.cardsAdded = {w1, w2, w3, gw1, gw2, gb1, gb2, gb3, gwh, d1, d2, k, t, o1, o2, o3, o4, o5, n};


    ally.hand = {w1, gw1, gb1, gb2, gwh, t};
    ally.deck = {w2, w3, gw2, o1, o2, o3, o4, o5};
    ally.discard = {gb3, d1, d2, k, n};
    startDemo(ally, enemy);
}

void demoLockingDeathwish(Field &ally, Field &enemy)
{
    ally.cardsAdded = {
        new Auckes(),
        new DimunLightLongship(),
        new RagingBerserker(),
        new AlzursThunder(),
        new AlzursThunder(),
    };
    ally.hand = ally.cardsAdded;
    enemy.cardsAdded = {
        new DimunLightLongship(),
        new Dao(),
        new Dao(),
    };
    enemy.rowRange = enemy.cardsAdded;
    startDemo(ally, enemy);
}

void demoNilfgaardReveal(Field &ally, Field &enemy)
{
    const std::vector<Card *> deckStartingAlly = {
        new LeoBonhart(), new Vilgefortz(), new TiborEggebracht(), new VattierDeRideaux(),
        new Cynthia(), new Serrit(), new HeftyHelge(), new HenryVarAttre(), new Sweers(), new Albrich(),
        new DaerlanSoldier(), new DaerlanSoldier(), new DaerlanSoldier(),
        new FireScorpion(), new FireScorpion(), new ImperialGolem(),
        new Spotter(), new Alchemist(), new MasterOfDisguise(),
        new Mangonel(), new Mangonel(), new Mangonel(),
        new NauzicaaSergeant(), new ImperialGolem(), new ImperialGolem()
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
    initField(deckStartingAlly, new MorvranVoorhis, ally);
    initField(deckStartingEnemy, new JanCalveit, enemy);
    startNextRound(ally, enemy);
}

void demoLastPlayed(Field &ally, Field &enemy)
{
    ally.cardsAdded = {
        new SummoningCircle(),
        new SummoningCircle(),
        new YenneferEnchantress(),
        new YenneferEnchantress(),
        new XavierMoran(),
        new Cleaver(),
        new Cleaver(),
        new Frightener(),
    };
    ally.hand = ally.cardsAdded;
    startDemo(ally, enemy);
}

void demoBlueStripes(Field &ally, Field &enemy)
{
    ally.cardsAdded = {
        new VernonRoche(),
        new BlueStripeScout(),
        new BlueStripeScout(),
        new BlueStripeScout(),
        new Roach(),
        new BlueStripeCommando(),
        new BlueStripeCommando(),
        new BlueStripeCommando(),
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
    auto *whh1 = new WildHuntHound();
    auto *whh2 = new WildHuntHound();
    auto *bf1 = new BitingFrost();
    auto *bf2 = new BitingFrost();
    auto *whw1 = new WildHuntWarrior();
    auto *whw2 = new WildHuntWarrior();
    auto *whw3 = new WildHuntWarrior();
    auto *whn1 = new WildHuntNavigator();
    auto *whn2 = new WildHuntNavigator();
    auto *whn3 = new WildHuntNavigator();
    auto *n = new Nithral();
    auto *i = new Imlerith();
    auto *m = new Miruna();
    auto *e = new EredinBreaccGlas();
    auto *c = new CaranthirArFeiniel();
    auto *d = new WildHuntDrakkar();
    auto *whr1 = new WildHuntRider();
    auto *whr2 = new WildHuntRider();
    ally.cardsAdded = {m, whh1, whh2, bf1, bf2, whw1, whw2, whw3, whn1, whn2, whn3, n, i, e, c, d, whr1, whr2};

    auto *b1 = new BrewessRitual();
    auto *m2 = new ImperialManticore();
    auto *m3 = new ImperialManticore();
    auto *m4 = new ImperialManticore();
    auto *m5 = new ImperialManticore();
    auto *m6 = new ImperialManticore();
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
    auto *a1 = new ArachasDrone();
    auto *a2 = new ArachasDrone();
    auto *a3 = new ArachasDrone();
    auto *a4 = new ArachasDrone();
    auto *s1 = new DrummondShieldmaid();
    auto *s2 = new DrummondShieldmaid();
    auto *s3 = new DrummondShieldmaid();
    auto *s4 = new DrummondShieldmaid();
    auto *as = new AnCraiteArmorsmith();
    auto *t = new TuirseachArcher();
    auto *m = new Maerolorn();
    auto *mn = new MonsterNest();
    auto *r = new Rotfiend();
    auto *d = new Dao();
    ally.cardsAdded = {a1, a2, a3, a4, s1, s2, s3, s4, as, t, m, mn, r, d};

    ally.hand = {a1, a2, s1, s2, m, mn, as, t};
    ally.discard = {a3, s3};
    ally.deck = {a4, s4, r, d};

    startDemo(ally, enemy);
}

void demoBigOgrs(Field &ally, Field &enemy)
{
    auto *osa = new OldSpeartipAsleep();
    auto *os = new OldSpeartip();
    auto *g = new Golyat();
    auto *m = new Morvudd();
    auto *d = new Dagon();
    ally.cardsAdded = {osa, os, g, m, d};
    ally.hand = {osa, os, g, m, d};

    auto *h1 = new HeymaeyHerbalist();
    auto *h2 = new HeymaeyHerbalist();
    auto *h3 = new HeymaeyHerbalist();
    auto *b1 = new Bear();
    auto *b2 = new Bear();
    auto *a1 = new TuirseachArcher();
    auto *a2 = new TuirseachArcher();
    auto *th1 = new TuirseachHunter();
    auto *th2 = new TuirseachHunter();
    auto *th3 = new TuirseachHunter();
    enemy.cardsAdded = {h1, h2, h3, b1, b2, a1, a2, th1, th2, th3};
    enemy.hand = {a1, a2, th1};
    enemy.rowRange = {b1, h1, h2, h3, b2};
    enemy.rowMeele = {th2, th3};

    startDemo(ally, enemy);
}

void demoConsume(Field &ally, Field &enemy)
{
    auto *g1 = new Ghoul();
    auto *m1 = new ImperialManticore();
    auto *m2 = new ImperialManticore();
    auto *m3 = new ImperialManticore();
    auto *b1 = new Barbegazi();
    auto *b2 = new Barbegazi();
    auto *d1 = new DevanaRunestone();
    auto *d2 = new DevanaRunestone();
    auto *d3 = new DevanaRunestone();
    auto *o = new Ozzrel();
    auto *k = new Kayran();
    auto *m0 = new Maerolorn();
    auto *s = new SheTrollOfVergen();
    auto *r1 = new Rotfiend();
    auto *a = new Archespore();
    auto *n1 = new Nekker();
    auto *n2 = new Nekker();
    auto *n3 = new Nekker();
    auto *nw = new NekkerWarrior();
    auto *h1 = new Harpy();
    auto *h2 = new Harpy();
    auto *h3 = new Harpy();
    ally.cardsAdded = {g1, m1, m2, m3, b1, b2, d1, d2, d3, o, k, m0, s, r1, a, n1, n2, n3, nw, h1, h2, h3};
    ally.hand = {g1, b1, b2, d1, o, k, m0, s, nw};
    ally.discard = {m1, d2};
    ally.rowMeele = {m2, n1};
    ally.rowSeige = {};
    ally.deck = {d3, m3, r1, a, n2, n3, h1, h2, h3};

    auto *t1 = new TuirseachAxeman();
    auto *t2 = new TuirseachAxeman();
    auto *t3 = new TuirseachAxeman();
    auto *am = new AnCraiteMarauder();
    auto *m = new Morkvarg();
    enemy.cardsAdded = {t1, t2, t3, m, am};
    enemy.rowRange = {t3, m, am};
    enemy.discard = {t1, t2};

    startDemo(ally, enemy);
}

void demoArchesporeJumping(Field &ally, Field &enemy)
{
    auto *a1 = new Archespore();
    auto *a2 = new Archespore();
    auto *a3 = new Archespore();
    auto *f1 = new Fiend();
    auto *f2 = new Fiend();
    auto *f3 = new Fiend();
    auto *f4 = new Fiend();
    auto *f5 = new Fiend();
    auto *f6 = new Fiend();
    auto *f7 = new Fiend();
    auto *f8 = new Fiend();
    auto *f9 = new Fiend();
    auto *i = new Ifrit();
    ally.cardsAdded = {a1, a2, a3, f1, f2, f3, f4, f5, f6, f7, f8, f9, i};
    ally.hand = {a1, a2, f6, f7, f8, f9, i};
    ally.rowMeele = {f1, f2, f3, f4, f5};
    ally.rowRange = {a3};

    auto *m1 = new ImperialManticore();
    auto *m2 = new ImperialManticore();
    auto *m3 = new ImperialManticore();
    auto *c1 = new Cyclops();
    auto *t1 = new TuirseachHunter();
    auto *t2 = new TuirseachHunter();
    auto *t3 = new TuirseachHunter();
    enemy.cardsAdded = {m1, m2, m3, c1, t1, t2, t3};
    enemy.rowMeele = {m1, m2};
    enemy.rowRange = {m3};
    enemy.hand = {c1, t1, t2, t3};

    startDemo(ally, enemy);
}

void demoImlerithSabbath(Field &ally, Field &enemy)
{
    auto *i = new ImlerithSabbath();
    auto *m1 = new Mandrake();
    auto *m2 = new Mandrake();
    auto *f = new Frightener();
    ally.cardsAdded = {i, m1, m2, f};
    ally.hand = {i, m1, m2, f};

    auto *d = new Derran();
    auto *h = new HaraldHoundsnout();
    auto *j = new JuttaAnDimun();
    auto *s = new SvanrigeTuirseach();
    enemy.cardsAdded = {d, h, j, s};
    enemy.hand = {h, j};
    enemy.rowRange = {d, s};

    startDemo(ally, enemy);
}

void demoTemporaryForTests(Field &ally, Field &enemy)
{
    auto *r = new RaghNarRoog();
    auto *g1 = new GeraltProfessional();
    auto *g2 = new GeraltAard();
    auto *g3 = new GeraltYrden();
    auto *c = new CiriDash();
    auto *b = new Barbegazi();
    auto *t1 = new ToadPrince();
    auto *t2 = new ToadPrince();
    auto *a = new Aguara();
    auto *g = new GaunterODimm;
    auto *t = new TrialOfTheGrasses();

    ally.cardsAdded = {r, g1, g2, g3, c, b, t1, t2, a, g, t};
    ally.hand = {r, g1, g2, g3, c, b, t1, t2, a, g, t};
    ally.canPass = false;

    auto *m1 = new ImperialManticore();
    auto *m2 = new ImperialManticore();
    auto *m3 = new ImperialManticore();
    auto *d = new DandelionPoet();
    enemy.cardsAdded = {m1, m2, m3, d};
    enemy.rowMeele = {m1, m2};
    enemy.rowRange = {m3};
    enemy.rowSeige = {d};

    startDemo(ally, enemy, false, false);
}

void demoNekkerWarrior(Field &ally, Field &enemy)
{
    auto *c0 = new NekkerWarrior();
    auto *c1 = new NekkerWarrior();
    auto *c2 = new ToadPrince();
    auto *c3 = new ToadPrince();
    auto *c4 = new Siren();

    ally.cardsAdded = { c0, c1, c2, c3, c4 };
    ally.hand = { c0, c1, c2, c3 };
    ally.deck = { c4 };
    startDemo(ally, enemy);
}

void demoNekkers(Field &ally, Field &enemy)
{
    ally.cardsAdded = {
        new Nekker(),
        new Nekker(),
        new NekkerWarrior(),
        new Barbegazi(),
        new Ghoul(),
        new Maerolorn(),
    };
    ally.hand = ally.cardsAdded;
    startDemo(ally, enemy);
}

void demoArachasDrones(Field &ally, Field &enemy)
{
    auto *c0 = new ArachasDrone();
    auto *c1 = new ArachasDrone();
    auto *c2 = new ArachasDrone();
    auto *c3 = new ArachasBehemoth();
    auto *c4 = new ArachasBehemoth();
    auto *c5 = new CelaenoHarpy();
    auto *c6 = new ArachasDrone();
    auto *c7 = new ArachasQueen();
    auto *c8 = new Barbegazi();
    auto *c9 = new VranWarrior();

    ally.cardsAdded = { c0, c1, c2, c3, c4, c5, c6, c7, c8, c9};
    ally.hand = { c3, c4, c5, c6, c7, c8, c9};
    ally.deck = { c0, c1, c2 };
    startDemo(ally, enemy);

}

void demoSlyzards(Field &ally, Field &enemy)
{
    auto *c0 = new NekkerWarrior();
    auto *c1 = new Nekker();
    auto *c2 = new Nekker();
    auto *c3 = new Nekker();
    auto *c4 = new Siren();
    auto *c5 = new Siren();
    auto *c6 = new Slyzard();
    auto *c7 = new Slyzard();
    auto *c8 = new Slyzard();

    ally.cardsAdded = { c0, c1, c2, c3, c4, c5, c6, c7, c8};
    ally.hand = { c0, c1, c6, c7, c8};
    ally.deck = { c2, c5 };
    ally.discard = { c3, c4 };
    startDemo(ally, enemy);
}

void demoAvalach(Field &ally, Field &enemy)
{
    const std::vector<Card *> deckStartingAlly {
        new Avalach(),
        new AvalachSage(),
        new YenneferConjurer(),
        new Johnny(),
        new Stregobor(),
        new WyvernScaleShield(),
        new MastercraftedSpear(),
        new Mandrake(),
        new MahakamMarauder(),
        new TuirseachArcher(),
        new TuirseachArcher(),
        new TemerianDrummer(),
        new AlbaArmoredCavalry(),
        new Ihuarraquax(),
        new Sarah(),
};

    const std::vector<Card *> deckStartingEnemy {
        new GeraltOfRivia(),
        new CiriNova(),
        new Siren(),
        new Siren(),
        new Siren(),
        new Nekurat(),
        new MonsterNest(),
        new Lamia(),
        new Lamia(),
        new Lamia(),
        new Lamia(),
        new Lamia(),
        new Lamia(),
        new Lamia(),
    };
    initField(deckStartingAlly, new BranTuirseach, ally);
    initField(deckStartingEnemy, new UnseenElder, enemy);
    startNextRound(ally, enemy);
}

void demoBeer(Field &ally, Field &enemy)
{
    auto *h1 = new HeymaeyHerbalist();
    auto *h2 = new HeymaeyHerbalist();
    auto *h3 = new HeymaeyHerbalist();
    auto *b1 = new Bear();
    auto *b2 = new Bear();
    auto *th1 = new TuirseachHunter();
    auto *th2 = new TuirseachHunter();
    auto *th3 = new TuirseachHunter();
    auto *o = new Odrin();
    auto *a = new AleOfTheAncestors();
    auto *m1 = new MahakamAle();
    auto *m2 = new MahakamAle();
    auto *m3 = new MahakamAle();
    ally.cardsAdded = {h1, h2, h3, b1, b2, th1, th2, th3, o, a, m1, m2, m3};
    ally.hand = {th1, o, a, m1, m2, m3};
    ally.rowRange = {b1, h1, h2, h3, b2};
    ally.rowMeele = {th2, th3};

    startDemo(ally, enemy);
}

void demoCrewAndCrewed(Field &ally, Field &enemy)
{
    auto *s1 = new KaedweniSergeant();
    auto *s2 = new KaedweniSergeant();
    auto *b1 = new ReinforcedBallista();
    auto *b2 = new ReinforcedBallista();
    auto *b3 = new ReinforcedBallista();
    auto *s3 = new RonvidTheIncessant();
    auto *s = new Scorch();

    ally.cardsAdded = {s1, s2, b1, b2, b3, s3, s};
    ally.hand = ally.cardsAdded;

    auto *m1 = new ImperialManticore();

    enemy.cardsAdded = {m1};
    enemy.rowMeele = {m1};

    startDemo(ally, enemy);
}

void demoSheTrollOfVergen(Field &ally, Field &enemy)
{
    auto *s1 = new SheTrollOfVergen();
    auto *s2 = new SheTrollOfVergen();
    auto *b1 = new Dao();
    auto *b2 = new Dao();
    auto *b3 = new Dao();

    ally.cardsAdded = {s1, s2, b1, b2, b3};
    ally.hand = {s1, s2, b3};
    ally.deck = {b1, b2};

    startDemo(ally, enemy);
}

void demoSigismundDijkstra(Field &ally, Field &enemy)
{
    auto *s = new SigismundDijkstra();
    auto *b1 = new KaedweniKnight();
    auto *r = new ReaverScout();
    auto *b2 = new KaedweniKnight();
    auto *a = new Abaya();

    ally.cardsAdded = {s, b1, b2, r, a};
    ally.hand = {s};
    ally.deck = {b1, r, b2, a};

    startDemo(ally, enemy);
}

void demoRowsSelection(Field &ally, Field &enemy)
{
    auto *c1 = new BitingFrost();
    auto *c2 = new GoldenFroth();
    auto *c3 = new Nekurat();
    auto *c4 = new AleOfTheAncestors();
    auto *c5 = new WoodlandSpirit();
    auto *c6 = new BirnaBran();
    auto *c7 = new CaranthirArFeiniel();
    auto *c8 = new KorathiHeatwave();
    auto *c9 = new GeraltIgni();
    auto *c10 = new BridgeTroll();
    auto *c11 = new WhiteFrost();

    ally.cardsAdded = {c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11};
    ally.hand = ally.cardsAdded;

    auto *m1 = new ImperialManticore();
    auto *m2 = new ImperialManticore();
    auto *m3 = new ImperialManticore();
    auto *m4 = new ImperialManticore();

    enemy.cardsAdded = {m1, m2, m3, m4};
    enemy.rowMeele = {m1, m2};
    enemy.rowRange = {m3, m4};

    startDemo(ally, enemy);
}

void demoWolfsbane(Field &ally, Field &enemy)
{
    std::vector<Card *> cards;
    cards.push_back(new Wolfsbane());
    for (int i = 0; i < 9; ++i)
        cards.push_back(new Wolf());

    ally.cardsAdded = cards;
    ally.hand = cards;

    auto *c1 = new ImperialManticore();
    auto *c2 = new ImperialManticore();

    enemy.cardsAdded = {c1, c2};
    enemy.rowMeele = {c1, c2};

    startDemo(ally, enemy);
}

void demoDeckSummon(Field &ally, Field &enemy)
{
    auto *c1 = new Aelirenn();
    auto *c2 = new DunBanner();
    auto *c3 = new DunBanner();
    auto *c4 = new DunBanner();
    auto *c5 = new Swallow();
    auto *c6 = new HalfElfHunter();
    auto *c7 = new HalfElfHunter();
    auto *c8 = new HalfElfHunter();
    auto *c9 = new GeraltIgni();
    auto *c10 = new Roach();

    ally.cardsAdded = {c1, c2, c3, c4, c5, c6, c7, c8, c9, c10};
    ally.hand = {c5, c6, c7, c8, c9};
    ally.deck = {c1, c2, c3, c4, c10};

    auto *m1 = new ImperialManticore();
    auto *m2 = new ImperialManticore();
    m2->power -= 2;

    enemy.cardsAdded = {m1, m2};
    enemy.rowMeele = {m1, m2};

    startDemo(ally, enemy);
}

void demoTriggersOrder(Field &ally, Field &enemy)
{
    auto *c1 = new DolBlathannaArcher();
    auto *c2 = new DolBlathannaArcher();
    auto *c3 = new TuirseachArcher();
    auto *em = new EmhyrVarEmreis();
    auto *bb = new SheTrollOfVergen();
    auto *zr = new ZoriaRunestone();
    auto *mm = new Dao();
    auto *mm2 = new Dao();

    ally.cardsAdded = {c1, c2, c3, em, bb, mm, mm2, zr};
    ally.hand = {c1, c2, c3, em, bb, zr};
    ally.deck = {mm, mm2};

    auto *m1 = new ImperialManticore();
    auto *m2 = new ImperialManticore();
    m1->power = 3;
    m2->power = 3;

    enemy.cardsAdded = {m1, m2};
    enemy.rowMeele = {m1, m2};
    startDemo(ally, enemy);
}

void demoTurnFinishingAndRoundFinishing(Field &ally, Field &enemy)
{
    const std::vector<Card *> deck1 {
        new GermainPiquant::Cow(),
        new GermainPiquant::Cow(),
        new GermainPiquant::Cow(),
        new GermainPiquant::Cow(),
        new GermainPiquant::Cow(),
        new GermainPiquant::Cow(),
        new GermainPiquant::Cow(),
        new GermainPiquant::Cow(),
        new GermainPiquant::Cow(),
        new GermainPiquant::Cow(),
        new GermainPiquant::Cow(),
        new GermainPiquant::Cow(),
        new GermainPiquant::Cow(),
        new GermainPiquant::Cow(),
        new GermainPiquant::Cow(),
        new GermainPiquant::Cow(),
    };

    const std::vector<Card *> deck2 {
        new Wolf(),
        new Wolf(),
        new Wolf(),
        new Wolf(),
        new Wolf(),
        new Wolf(),
        new Wolf(),
        new Wolf(),
        new Wolf(),
        new Wolf(),
        new Wolf(),
        new Wolf(),
        new Wolf(),
        new Wolf(),
        new Wolf(),
        new Wolf(),
    };

    initField(deck1, nullptr, ally);
    initField(deck2, nullptr, enemy);
    // startDemo(ally, enemy, false, true);
    startNextRound(ally, enemy);
}

void demoAllTypedChoices(Field &ally, Field &enemy)
{
    ally.cardsAdded = {
        new AdrenalineRush(),   // target exist
        new MonsterNest(),      // spawn from all
        new ZoriaRunestone(),   // create from all
        new KeiraMetz(),        // outer option
        new Mandrake(),         // inner option
        new ImpenetrableFog(),  // row
        new Aguara(),           // complex one

        new OrnamentalSword(),
        new Vreemde(),
        new ShupesDayOff(),
        new EredinBreaccGlas(),
        new Vaedermakar(),
        new GaunterODimm(),
        new WeavessIncantation(),
        new Hym(),
        new LethoKingslayer(),
        new EistTuirseach(),
        new Moonlight(),

    };
    ally.hand = ally.cardsAdded;

    auto *m1 = new ImperialManticore();
    auto *m2 = new ImperialManticore();

    enemy.cardsAdded = {m1, m2};
    enemy.rowMeele = {m1, m2};
    startDemo(ally, enemy);
}

void demoNeutralSpecial(Field &ally, Field &enemy)
{
    auto *h = new HanmarvynsDream();
    auto *b = new BlackBlood();
    auto *br = new BekkersRockslide();
    auto *bm = new BekkersDarkMirror();
    auto *bf = new BitingFrost();
    auto *g = new GoldenFroth();
    auto *mh = new MerigoldsHailstorm();
    auto *nm = new Necromancy();
    auto *st = new StammelfordsTremor();
    auto *d = new DimeritiumBomb();
    auto *lw = new TheLastWish();
    auto *ds = new DimeritiumShackles();
    auto *ws = new WyvernScaleShield();
    auto *ms = new MastercraftedSpear();
    auto *ud = new JuttaAnDimun();
    auto *rd = new RoyalDecree();
    auto *uc = new UmasCurse();
    auto *tb = new TrissButterflies();
    auto *ye = new YenneferEnchantress();
    auto *dop = new Doppler();
    auto *md = new Mardroeme();
    auto *s = new Sihil();
    auto *dd = new DragonsDream();

    auto *lead = new BranTuirseach();

    ally.cardsAdded = {h, b, br, bm, bf, g, mh, nm, st, d, lw, ds, ws, ms, ud, tb, ye, dop, lead, md, s, dd};
    ally.leader = lead;
    ally.hand = {bf, g, lw, ds, ud, rd, uc, dop, s, dd};
    ally.deck = {h, b, br, bm, mh, nm, st, d, ws, ms, tb, ye, md};

    auto *a2 = new Abaya();
    auto *e = new Ekimmara();
    auto *n = new Nekker();
    auto *u = new UnseenElder();
    auto *w = new WoodlandSpirit();
    auto *h1 = new HanmarvynsDream();

    enemy.cardsAdded = {a2, e, n, u, w, h1};
    enemy.rowRange = {a2, e, n};
    enemy.discard = {u, w, h1};
    enemy.passed = true;

    startDemo(ally, enemy);
}

void demoGoldWitchers(Field &ally, Field &enemy)
{
    auto *e = new EskelPathfinder();
    auto *l = new LambertSwordmaster();
    auto *v = new VesemirMentor();
    auto *dd = new DragonsDream();
    auto *g = new GoldenFroth();
    auto *c = new CrowsEye();


    ally.cardsAdded = {e, l, v, dd, g, c};
    ally.hand = {e, l, v, dd};
    ally.deck = {g, c};


    auto *a1 = new Abaya();
    auto *a2 = new Abaya();
    auto *a3 = new Abaya();
    auto *a4 = new Abaya();
    auto *n = new Nekker();
    auto *u = new UnseenElder();
    auto *w = new WoodlandSpirit();
    auto *h1 = new HanmarvynsDream();

    enemy.cardsAdded = {a1, a2, a3, a4, n, u, w, h1};
    enemy.rowRange = {a1, a2, a3, a4, n};
    enemy.discard = {u, w, h1};
    enemy.passed = true;

    startDemo(ally, enemy);
}

void demoNeutralDudes(Field &ally, Field &enemy)
{
    auto *o1 = new Olaf();
    auto *o2 = new Olaf();
    auto *o3 = new Olaf();
    auto *o4 = new Olaf();
    auto *o5 = new Olaf();
    auto *r = new RegisHigherVampire();
    auto *z = new ZoltanScoundrel();
    auto *y = new YenneferConjurer();

    ally.cardsAdded = {o1, o2, o3, o4, o5, r, z, y};
    ally.hand = {r, z, y};
    ally.rowMeele = {o1, o2, o3, o4, o5};

    auto *e1 = new AncientFoglet();
    auto *e2 = new Abaya();
    auto *e3 = new Cockatrice();
    auto *e4 = new CaranthirArFeiniel();
    auto *e5 = new Nithral();
    auto *e6 = new Geels();
    auto *e7 = new WoodlandSpirit();
    auto *e8 = new WildHuntDrakkar();

    enemy.cardsAdded = {e1, e2, e3, e4, e5, e6, e7, e8};
    enemy.deck = {e1, e2, e3};
    enemy.rowMeele = {e4, e5, e6, e7, e8};
    enemy.passed = true;

    startDemo(ally, enemy);
}

void demoPowerChanged(Field &ally, Field &enemy)
{
    auto *i = new Ihuarraquax();
    auto *mm = new MahakamMarauder();
    auto *m1 = new Mandrake();
    auto *m2 = new Mandrake();
    auto *g = new GeraltYrden();
    auto *z = new ZoltanChivay();
    auto *v = new Villentretenmerth();
    auto *k = new KingOfBeggars();
    auto *iris = new IrisVonEverec();
    auto *i2 = new Infiltrator();

    ally.cardsAdded = {i, mm, m1, m2, g, z, v, k, iris, i2};
    ally.hand = {i, mm, m1, m2, g, z, v, k, iris, i2};

    auto *e1 = new Olaf();
    auto *e2 = new Olaf();
    auto *e3 = new Olaf();
    auto *e4 = new Olaf();

    enemy.cardsAdded = {e1, e2, e3, e4};
    enemy.rowMeele = {e1, e2, e3, e4};
    enemy.passed = true;

    startDemo(ally, enemy);
}

void demoAedirnDragon(Field &ally, Field &enemy)
{
    auto *m1 = new PeasantMilitia();
    auto *m2 = new PrizeWinningCow();
    auto *m3 = new Mandrake();
    auto *b1 = new BoneTalisman();
    auto *b2 = new BoneTalisman();
    auto *b3 = new BoneTalisman();
    auto *s = new SaesenthessisBlaze();
    auto *m = new Myrgtabrakke();

    ally.cardsAdded = {m1, m2, m3, b1, b2, s, m};
    ally.hand = {b1, b2, b3, s};
    ally.deck = {m, m1, m2, m3};

    auto *o = new Olaf();
    enemy.cardsAdded = {o};
    enemy.rowMeele = {o};
    enemy.passed = true;

    startDemo(ally, enemy);
}

void demoLeaders(Field &ally, Field &enemy)
{
    auto *sc1 = new CrowsEye();
    auto *sc2 = new Mardroeme();
    auto *sc3 = new Mardroeme();
    auto *mv = new ManticoreVenom();
    auto *u = new Usurper();
    auto *y = new Yaevinn();
    auto *b = new Braenn();
    auto *m1 = new Malena();
    auto *m2 = new Morenn();
    auto *f = new Filavandrel();
    auto *r = new MoranaRunestone();
    auto *s1 = new TorrentialRain();
    auto *s2 = new GoldenFroth();
    auto *s = new SheldonSkaggs();
    auto *e = new Eithne();

    ally.cardsAdded = {sc1, sc2, sc3, mv, u, y, b, m1, m2, f, r, s1, s2, s, e};
    ally.hand = {sc1, u, y, b, f, s, e, m1, m2};
    ally.deck = {sc3, s1, s2};
    ally.discard = {sc2, mv, r};

    auto *o = new Olaf();
    auto *em1 = new Mandrake();
    auto *emv = new ManticoreVenom();
    enemy.cardsAdded = {o, em1, emv};
    enemy.rowMeele = {o};
    enemy.discard = {em1, emv};
    enemy.passed = true;

    startDemo(ally, enemy);
}

void demoDwarws(Field &ally, Field &enemy)
{
    auto *da1 = new DwarvenAgitator();
    auto *da2 = new DwarvenAgitator();
    auto *da3 = new DwarvenAgitator();
    auto *ds1 = new DwarvenSkirmisher();
    auto *dm1 = new DwarvenMercenary();
    auto *h1 = new HawkerSupport();
    auto *mg1 = new MahakamGuard();
    auto *e = new ElvenScout();

    ally.cardsAdded = {da1, da2, da3, ds1, dm1, h1, mg1, e};
    ally.hand = {da1, da2, ds1, h1, mg1};
    ally.deck = {da3, dm1, e};

    enemy.cardsAdded = {new Olaf(), new DwarvenAgitator()};
    enemy.rowMeele = enemy.cardsAdded;

    startDemo(ally, enemy, true, false);
}

void demoSwapElves(Field &ally, Field &enemy)
{
    auto *es1 = new ElvenScout();
    auto *es2 = new ElvenScout();
    auto *es3 = new ElvenScout();
    auto *w1 = new Wardancer();
    auto *w2 = new Wardancer();
    auto *v1 = new VriheddVanguard();

    ally.cardsAdded = {es1, es2, es3, w1, w2, v1};
    ally.hand = {es1, w1, w2, v1};
    ally.deck = {es2, es3};

    startDemo(ally, enemy, true, false);
}

void demoWithOpion1(Field &ally, Field &enemy)
{
    auto *h = new Hym();
    auto *p = new PrinceStennis();

    initField({h}, nullptr, ally);
    initField({p}, nullptr, enemy);
    drawACard(ally, enemy, nullptr);
    startDemo(ally, enemy);
}

void demoWithWindow5(Field &ally, Field &enemy)
{
    auto *h = new ShupesDayOff();
    initField({h}, nullptr, ally);
    drawACard(ally, enemy, nullptr);
    startDemo(ally, enemy, false, true);
}

void demoEmpty(Field &ally, Field &enemy)
{
    startNextRound(ally, enemy);
}

void demoNilfsTemporary(Field &ally, Field &enemy)
{
    auto *a1 = new StefanSkellen();
    auto *a2 = new Shilard();
    auto *a3 = new Xarthisius();
    auto *a4 = new ElvenScout();
    auto *a5 = new ElvenScout();
    auto *a6 = new Assassination();

    ally.cardsAdded = {a1, a2, a3, a4, a5, a6};
    ally.hand = {a1, a2, a3};
    ally.deck = {a4, a5, a6};

    auto *e1 = new ImperialManticore();
    auto *e2 = new ImperialManticore();
    auto *e3 = new ImperialManticore();
    auto *e4 = new Mardroeme();
    auto *e5 = new Mardroeme();
    auto *e6 = new Mardroeme();

    enemy.cardsAdded = {e1, e2, e3, e4, e5, e6};
    enemy.rowMeele = {e1, e2};
    enemy.deck = {e3, e4, e5, e6};

    startDemo(ally, enemy, true, false);
    // TODO: fix in card.cpp - here in the test Shilard loses Skellen's buff of a unit
}

void demoPanther(Field &ally, Field &enemy)
{
    auto *a1 = new Panther();
    auto *a2 = new VicovaroMedic();

    ally.cardsAdded = {a1, a2};
    ally.hand = {a1, a2};

    auto *e1 = new TemerianDrummer();
    auto *e2 = new TemerianDrummer();
    auto *e3 = new ImperialManticore();
    auto *e4 = new ImperialManticore();
    auto *e5 = new ImperialManticore();
    auto *e6 = new ImperialManticore();

    enemy.cardsAdded = {e1, e2, e3, e4, e5, e6};
    enemy.rowMeele = {e1, e2};
    enemy.rowRange = {e3, e4, e5, e6};

    startDemo(ally, enemy, true, false);
}

void demoNilfgaardMages(Field &ally, Field &enemy)
{
    auto *a1 = new AssireVarAnahid();
    auto *a2 = new FringillaVigo();
    auto *a3 = new HeftyHelge();
    auto *a4 = new FalseCiri();
    auto *a5 = new AddaStriga();
    auto *a6 = new HeftyHelge();
    auto *a7 = new HeftyHelge();

    ally.cardsAdded = {a1, a2, a3, a4, a5, a6, a7};
    ally.hand = {a1, a2, a3, a4, a5};
    ally.discard = {a6, a7};

    auto *e1 = new TemerianDrummer();
    auto *e2 = new TemerianDrummer();
    auto *e3 = new ImperialManticore();
    auto *e4 = new ImperialManticore();
    auto *e5 = new ImperialManticore();
    auto *e6 = new ImperialManticore();

    enemy.cardsAdded = {e1, e2, e3, e4, e5, e6};
    enemy.rowMeele = {e1, e3, e2};
    enemy.hand = {e4, e5};
    enemy.discard = {e6};
    enemy.passed = false;

    startDemo(ally, enemy, false, false);
}

void demoNothern(Field &ally, Field &enemy)
{
    auto *d = new Dandelion();
    auto *d1 = new DandelionPoet();
    auto *f = new KingFoltest();
    auto *b = new Bear();
    auto *b1 = new Bear();
    auto *b2 = new Bear();
    auto *w = new Wolf();

    ally.cardsAdded = {f, d, d1, b, b1, b2, w};
    ally.leader = f;
    ally.hand = {d, d1};
    ally.deck = {b, b1, b2, w};

    startDemo(ally, enemy, true, true);
}
