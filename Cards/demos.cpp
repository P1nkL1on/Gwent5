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

    enemy.passed = true;
    ally.canPass = false;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
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
    enemy.passed = true;
    ally.canPass = false;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
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
    ally.canPass = false;
    enemy.canPass = false;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
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
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
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
    enemy.passed = false;
    ally.canPass = false;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
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
    enemy.passed = true;
    ally.canPass = false;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
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
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
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
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
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
    enemy.passed = false;
    ally.canPass = false;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
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
    enemy.passed = true;
    ally.canPass = false;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
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
    enemy.passed = false;
    ally.canPass = false;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
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
    enemy.passed = true;
    ally.canPass = false;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
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
    ally.cardsAdded = {w1, w2, w3, gw1, gw2, gb1, gb2, gb3, gwh, d1, d2, k, t, o1, o2, o3, o4, o5};


    ally.hand = {w1, gw1, gb1, gb2, gwh, t};
    ally.deck = {w2, w3, gw2, o1, o2, o3, o4, o5};
    ally.discard = {gb3, d1, d2, k};
    enemy.passed = true;
    ally.canPass = false;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
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
    enemy.passed = true;
    ally.canPass = false;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
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
    enemy.passed = true;
    ally.canPass = false;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
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
        drawACard(ally, enemy);
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
}

void demoWildHunt(Field &ally, Field &enemy)
{
    auto *whh1 = new WildHuntHound();
    auto *whh2 = new WildHuntHound();
    auto *bf = new BitingFrost();
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
    ally.cardsAdded = {m, whh1, whh2, bf, whw1, whw2, whw3, whn1, whn2, whn3, n, i, e, c};

    auto *b1 = new BrewessRitual();
    auto *m2 = new ImperialManticore();
    auto *m3 = new ImperialManticore();
    auto *m4 = new ImperialManticore();
    auto *m5 = new ImperialManticore();
    auto *m6 = new ImperialManticore();
    enemy.cardsAdded = {b1, m2, m3, m4, m5, m6};

    ally.hand = {m, whh1, whw1, whn1, n, i, e, c};
    ally.deck = {bf, whh2, whn2, whw2, whw3};
    ally.rowSeige = {whn3};
    ally.canPass = false;

    enemy.rowSeige = {b1};
    enemy.rowRange = {m2, m3};
    enemy.rowMeele = {m4, m5, m6};
    enemy.passed = true;

    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
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
    auto *m = new Maerolorn();
    auto *mn = new MonsterNest();
    auto *r = new Rotfiend();
    auto *d = new Dao();
    ally.cardsAdded = {a1, a2, a3, a4, s1, s2, s3, s4, m, mn, r, d};

    ally.hand = {a1, a2, s1, s2, m, mn};
    ally.discard = {a3, s3};
    ally.deck = {a4, s4, r, d};
    ally.canPass = false;

    enemy.passed = true;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
}

void demoBigOgrs(Field &ally, Field &enemy)
{
    auto *osa = new OldSpeartipAsleep();
    auto *os = new OldSpeartip();
    auto *g = new Golyat();
    auto *m = new Morvudd();
    auto *d = new Dagon();
    ally.cardsAdded = {osa, os, g, m, d};

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

    ally.hand = {osa, os, g, m, d};
    ally.canPass = false;

    enemy.hand = {a1, a2, th1};
    enemy.rowRange = {b1, h1, h2, h3, b2};
    enemy.rowMeele = {th2, th3};
    enemy.passed = false;

    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
}

void demoConsume(Field &ally, Field &enemy)
{
    auto *g1 = new Ghoul();
    auto *m1 = new ImperialManticore();
    auto *m2 = new ImperialManticore();
    auto *m3 = new ImperialManticore();
    auto *r = new Ruehin();
    auto *b1 = new Barbegazi();
    auto *b2 = new Barbegazi();
    auto *d1 = new DevanaRunestone();
    auto *d2 = new DevanaRunestone();
    auto *d3 = new DevanaRunestone();
    auto *f = new Forktail();
    auto *o = new Ozzrel();
    auto *aq = new ArachasQueen();
    auto *k = new Kayran();
    auto *m0 = new Mourntart();
    auto *tp = new ToadPrince();
    auto *s = new SheTrollOfVergen();
    auto *r1 = new Rotfiend();
    auto *a = new Archespore();
    auto *ab = new ArachasBehemoth();
    ally.cardsAdded = {g1, m1, m2, m3, r, b1, b2, d1, d2, d3, f, o, aq, k, m0, tp, s, r1, a, ab};

    ally.hand = {g1, b1, b2, d1, f, o, aq, k, m0, tp, s, ab};
    ally.discard = {m1, d2};
    ally.rowMeele = {m2};
    ally.deck = {d3, m3, r1, r, a};
    ally.canPass = false;

    auto *t1 = new TuirseachAxeman();
    auto *t2 = new TuirseachAxeman();
    auto *t3 = new TuirseachAxeman();
    auto *am = new AnCraiteMarauder();
    auto *m = new Morkvarg();

    enemy.cardsAdded = {t1, t2, t3, m, am};
    enemy.rowRange = {t3, m, am};
    enemy.discard = {t1, t2};

    enemy.passed = true;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
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
    ally.canPass = false;

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
    enemy.passed = false;

    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
}

void demoImlerithSabbath(Field &ally, Field &enemy)
{
    auto *i = new ImlerithSabbath();
    auto *m1 = new Mandrake();
    auto *m2 = new Mandrake();
    auto *f = new Frightener();
    ally.cardsAdded = {i, m1, m2, f};
    ally.hand = {i, m1, m2, f};
    ally.canPass = false;

    auto *d = new Derran();
    auto *h = new HaraldHoundsnout();
    auto *j = new JuttaAnDimun();
    auto *s = new SvanrigeTuirseach();
    enemy.cardsAdded = {d, h, j, s};
    enemy.hand = {h, j};
    enemy.rowRange = {d, s};
    enemy.passed = false;

    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
}

void demoTemporaryForTests(Field &ally, Field &enemy)
{
    auto *w = new Wyvern();
    auto *a = new Abaya();
    auto *p = new Parasite();
    auto *j = new Jotunn();
    auto *b1 = new BitingFrost();
    auto *b2 = new BitingFrost();
    auto *ig = new IceGiant();
    auto *it = new IceTroll();
    auto *d = new Drowner();
    auto *f1 = new Foglet();
    auto *f2= new Foglet();
    auto *f3 = new Foglet();
    auto *ws = new WoodlandSpirit();
    auto *i = new ImpenetrableFog();
    auto *ai = new AncientFoglet();
    auto *d1 = new Draug();
    auto *h = new CelaenoHarpy();
    auto *ba = new Barbegazi();

    ally.cardsAdded = {w, a, p, j, b1, b2, ig, it, d, f1, f2, f3, i, ws, ai, d1, h, ba};
    ally.hand = {a, p, j, b1, ws, i, d1, h, ba};
    ally.deck = {f1, f2, f3};
    ally.discard = {b2, ig, it, d};
    ally.rowSeige = {ai, w};
    ally.canPass = false;

    auto *m1 = new ImperialManticore();
    auto *m2 = new ImperialManticore();
    auto *m3 = new ImperialManticore();

    enemy.cardsAdded = {m1, m2, m3};
    enemy.rowMeele = {m1, m2};
    enemy.rowRange = {m3};
    enemy.passed = true;

    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
}
