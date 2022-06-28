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
    enemy.passed = true;

    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
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
    enemy.passed = true;
    ally.canPass = false;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
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
    enemy.passed = true;
    ally.canPass = false;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
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
    enemy.passed = true;
    ally.canPass = false;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));

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
    enemy.passed = true;
    ally.canPass = false;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
}

void demoAvalach(Field &ally, Field &enemy)
{
    const std::vector<Card *> deckStartingAlly {
        new CiriNova(),
        new Avalach(),
        new AvalachSage(),
        new DandelionVainglory(),
        new TrissButterflies(),
        new Yennefer(),
        new YenneferConjurer(),
    };

    const std::vector<Card *> deckStartingEnemy {
        new GeraltOfRivia(),
        new CiriNova(),
        new Siren(),
        new Siren(),
        new Nekurat(),
        new MonsterNest(),
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

    ally.canPass = false;

    ally.hand = {th1, o, a, m1, m2, m3};
    ally.rowRange = {b1, h1, h2, h3, b2};
    ally.rowMeele = {th2, th3};

    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));

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

    enemy.passed = true;
    ally.canPass = false;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
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

    enemy.passed = true;
    ally.canPass = false;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
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

    enemy.passed = true;
    ally.canPass = false;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
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
    enemy.passed = true;
    ally.canPass = false;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
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

    enemy.passed = true;
    ally.canPass = false;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
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
    enemy.passed = true;
    ally.canPass = false;
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
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

    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
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

    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
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

    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
}

void demoPowerChanged(Field &ally, Field &enemy)
{
    auto *i = new Ihuarraquax();
    auto *mm1 = new MahakamMarauder();
    auto *mm2 = new MahakamMarauder();
    auto *m1 = new Mandrake();
    auto *m2 = new Mandrake();
    auto *m3 = new Mandrake();
    auto *t = new TuirseachArcher();
    auto *g = new GeraltYrden();
    auto *z = new ZoltanChivay();

    ally.cardsAdded = {i, mm1, mm2, m1, m2, m3, t, g, z};
    ally.hand = {i, mm1, mm2, m1, m2, m3, t, g, z};

    auto *e1 = new Olaf();
    auto *e2 = new Olaf();
    auto *e3 = new Olaf();
    auto *e4 = new Olaf();

    enemy.cardsAdded = {e1, e2, e3, e4};
    enemy.rowMeele = {e1, e2, e3, e4};
    enemy.passed = true;

    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, false));
}
