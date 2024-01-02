#ifndef CARDS_H
#define CARDS_H

#include "card.h"

/// open-beta Gwent v0.9.24.3.432
class Cards
{
public:
    virtual ~Cards() = default;
    virtual std::vector<Card *> createAll();

    virtual Card *createAddaStriga();
    virtual Card *createDaoLesser();
    virtual Card *createDao();
    virtual Card *createLeftFlankInfantry();
    virtual Card *createRightFlankInfantry();
    virtual Card *createPoorFingInfantry();
    virtual Card *createDeithwenArbalest();
    virtual Card *createTemerianDrummer();
    virtual Card *createTridamInfantry();
    virtual Card *createDandelionPoet();
    virtual Card *createSileDeTansarville();
    virtual Card *createRedanianKnightElect();
    virtual Card *createKaedweniKnight();
    virtual Card *createAnCraiteMarauder();
    virtual Card *createAnCraiteGreatsword();
    virtual Card *createDimunLightLongship();
    virtual Card *createBear();
    virtual Card *createWolf();
    virtual Card *createTuirseachBearmaster();
    virtual Card *createTuirseachHunter();
    virtual Card *createRedanianElite();
    virtual Card *createRedanianKnight();
    virtual Card *createKaedweniCavalry();
    virtual Card *createAlzursThunder();
    virtual Card *createSwallow();
    virtual Card *createThunderbolt();
    virtual Card *createArachasVenom();
    virtual Card *createKeiraMetz();
    virtual Card *createDolBlathannaArcher();
    virtual Card *createHalfElfHunter();
    virtual Card *createAmbassador();
    virtual Card *createAssassin();
    virtual Card *createEmissary();
    virtual Card *createCeallachDyffryn();
    virtual Card *createTuirseachArcher();
    virtual Card *createInfiltrator();
    virtual Card *createImpenetrableFog();
    virtual Card *createTorrentialRain();
    virtual Card *createBitingFrost();
    virtual Card *createGoldenFroth();
    virtual Card *createSkelligeStorm();
    virtual Card *createImperialManticore();
    virtual Card *createManticoreVenom();
    virtual Card *createGloriousHunt();
    virtual Card *createVes();
    virtual Card *createVaedermakar();
    virtual Card *createFrightener();
    virtual Card *createCleaver();
    virtual Card *createScorch();
    virtual Card *createReinforcements();
    virtual Card *createJohnNatalis();
    virtual Card *createEleyas();
    virtual Card *createReaverScout();
    virtual Card *createHeymaeySpearmaiden();
    virtual Card *createVriheddSappers();
    virtual Card *createPriestessOfFreya();
    virtual Card *createDimunCorsair();
    virtual Card *createSigrdrifa();
    virtual Card *createDrummondQueensguard();
    virtual Card *createSage();
    virtual Card *createReconnaissance();
    virtual Card *createElvenMercenary();
    virtual Card *createChampionOfHov();
    virtual Card *createPriscilla();
    virtual Card *createSeltkirkOfGulet();
    virtual Card *createAdrenalineRush();
    virtual Card *createMandrake();
    virtual Card *createBoneTalisman();
    virtual Card *createRestore();
    virtual Card *createDecoy();
    virtual Card *createShupesDayOff();
    virtual Card *createShupeKnight();
    virtual Card *createShupeHunter();
    virtual Card *createShupeMage();
    virtual Card *createFirstLight();
    virtual Card *createClearSkies();
    virtual Card *createEpidemic();
    virtual Card *createMoonlight();
    virtual Card *createCiriNova();
    virtual Card *createHaraldTheCripple();
    virtual Card *createBranTuirseach();
    virtual Card *createDrummondWarmonger();
    virtual Card *createDimunPirate();
    virtual Card *createAnCraiteRaider();
    virtual Card *createMadmanLugos();
    virtual Card *createErmion();
    virtual Card *createCerysFearless();
    virtual Card *createCerysAnCraite();
    virtual Card *createWoodlandSpirit();
    virtual Card *createTrollololo();
    virtual Card *createPrinceStennis();
    virtual Card *createVincentMeis();
    virtual Card *createMorkvarg();
    virtual Card *createJadeFigurine();
    virtual Card *createArtefactCompression();
    virtual Card *createLordOfUndvik();
    virtual Card *createHjalmarAnCraite();
    virtual Card *createRegis();
    virtual Card *createLethoOfGulet();
    virtual Card *createAuckes();
    virtual Card *createAnCraiteLongship();
    virtual Card *createGeraltIgni();
    virtual Card *createGeraltOfRivia();
    virtual Card *createTuirseachVeteran();
    virtual Card *createUdalryk();
    virtual Card *createBloodcurdlingRoar();
    virtual Card *createGremist();
    virtual Card *createZoriaRunestone();
    virtual Card *createOperator();
    virtual Card *createRenew();
    virtual Card *createEistTuirseach();
    virtual Card *createTuirseachAxeman();
    virtual Card *createDerran();
    virtual Card *createTuirseachSkirmisher();
    virtual Card *createRoach();
    virtual Card *createJanCalveit();
    virtual Card *createCahirDyffryn();
    virtual Card *createLethoKingslayer();
    virtual Card *createKingHenselt();
    virtual Card *createBloodyBaron();
    virtual Card *createDethmold();
    virtual Card *createRonvidTheIncessant();
    virtual Card *createHubertRejk();
    virtual Card *createCrachAnCraite();
    virtual Card *createBirnaBran();
    virtual Card *createCoral();
    virtual Card *createVabjorn();
    virtual Card *createSpectralWhale();
    virtual Card *createBlueboyLugos();
    virtual Card *createDjengeFrett();
    virtual Card *createDonarAnHindar();
    virtual Card *createDraigBonDhu();
    virtual Card *createHolgerBlackhand();
    virtual Card *createJuttaAnDimun();
    virtual Card *createSavageBear();
    virtual Card *createSvanrigeTuirseach();
    virtual Card *createSkjall();
    virtual Card *createWilfred();
    virtual Card *createWilhelm();
    virtual Card *createWilmar();
    virtual Card *createHaraldHoundsnout();
    virtual Card *createYoana();
    virtual Card *createAnCraiteBlacksmith();
    virtual Card *createAnCraiteWarcrier();
    virtual Card *createAnCraiteWarrior();
    virtual Card *createBerserkerMarauder();
    virtual Card *createDimunPirateCaptain();
    virtual Card *createDimunSmuggler();
    virtual Card *createDrummondShieldmaid();
    virtual Card *createHeymaeyFlaminica();
    virtual Card *createHeymaeyHerbalist();
    virtual Card *createHeymaeyProtector();
    virtual Card *createHeymaeySkald();
    virtual Card *createRagingBear();
    virtual Card *createRagingBerserker();
    virtual Card *createHym();
    virtual Card *createHemdall();
    virtual Card *createKambi();
    virtual Card *createOlaf();
    virtual Card *createUlfhedinn();
    virtual Card *createWildBoarOfTheSea();
    virtual Card *createGiantBoar();
    virtual Card *createOrnamentalSword();
    virtual Card *createDimunWarship();
    virtual Card *createVilgefortz();
    virtual Card *createTrissButterflies();
    virtual Card *createChironex();
    virtual Card *createUnicorn();
    virtual Card *createYennefer();
    virtual Card *createGermainPiquant();
    virtual Card *createCow();
    virtual Card *createCommandersHorn();
    virtual Card *createMarchingOrders();
    virtual Card *createAlzursDoubleCross();
    virtual Card *createAlbaArmoredCavalry();
    virtual Card *createSentry();
    virtual Card *createCiri();
    virtual Card *createNauzicaaSergeant();
    virtual Card *createSlaveInfantry();
    virtual Card *createRecruit();
    virtual Card *createOintment();
    virtual Card *createVreemde();
    virtual Card *createEskel();
    virtual Card *createLambert();
    virtual Card *createVesemir();
    virtual Card *createVriheddDragoon();
    virtual Card *createMalena();
    virtual Card *createUnseenElder();
    virtual Card *createDevanaRunestone();
    virtual Card *createDazhbogRunestone();
    virtual Card *createMoranaRunestone();
    virtual Card *createStribogRunestone();
    virtual Card *createMuzzle();
    virtual Card *createWhisperingHillock();
    virtual Card *createBrewess();
    virtual Card *createWeavess();
    virtual Card *createWhispess();
    virtual Card *createWeavessIncantation();
    virtual Card *createBrewessRitual();
    virtual Card *createWhispessTribute();
    virtual Card *createRockBarrage();
    virtual Card *createNivellen();
    virtual Card *createLeoBonhart();
    virtual Card *createMorvranVoorhis();
    virtual Card *createCynthia();
    virtual Card *createSerrit();
    virtual Card *createSweers();
    virtual Card *createTiborEggebracht();
    virtual Card *createVattierDeRideaux();
    virtual Card *createAlbrich();
    virtual Card *createHeftyHelge();
    virtual Card *createAlchemist();
    virtual Card *createDaerlanSoldier();
    virtual Card *createFireScorpion();
    virtual Card *createMangonel();
    virtual Card *createNilfgaardianKnight();
    virtual Card *createSpotter();
    virtual Card *createVenendalElite();
    virtual Card *createMasterOfDisguise();
    virtual Card *createHenryVarAttre();
    virtual Card *createSummoningCircle();
    virtual Card *createXavierMoran();
    virtual Card *createYenneferEnchantress();
    virtual Card *createVernonRoche();
    virtual Card *createBlueStripeScout();
    virtual Card *createBlueStripeCommando();
    virtual Card *createImperialGolem();
    virtual Card *createWildHuntHound();
    virtual Card *createWildHuntWarrior();
    virtual Card *createWildHuntNavigator();
    virtual Card *createNithral();
    virtual Card *createMiruna();
    virtual Card *createImlerith();
    virtual Card *createCaretaker();
    virtual Card *createRuehin();
    virtual Card *createOldSpeartipAsleep();
    virtual Card *createOldSpeartip();
    virtual Card *createGolyat();
    virtual Card *createBarbegazi();
    virtual Card *createGhoul();
    virtual Card *createForktail();
    virtual Card *createArachasQueen();
    virtual Card *createOzzrel();
    virtual Card *createKayran();
    virtual Card *createMourntart();
    virtual Card *createToadPrince();
    virtual Card *createFiend();
    virtual Card *createMorvudd();
    virtual Card *createEkimmara();
    virtual Card *createRotfiend();
    virtual Card *createArchespore();
    virtual Card *createCyclops();
    virtual Card *createMaerolorn();
    virtual Card *createMonsterNest();
    virtual Card *createArachasDrone();
    virtual Card *createWerewolf();
    virtual Card *createAlphaWerewolf();
    virtual Card *createEredinBreaccGlas();
    virtual Card *createCaranthirArFeiniel();
    virtual Card *createImlerithSabbath();
    virtual Card *createDagon();
    virtual Card *createIfritLesser();
    virtual Card *createIfrit();
    virtual Card *createSheTrollOfVergen();
    virtual Card *createWyvern();
    virtual Card *createAbaya();
    virtual Card *createParasite();
    virtual Card *createJotunn();
    virtual Card *createIceGiant();
    virtual Card *createIceTroll();
    virtual Card *createDrowner();
    virtual Card *createFoglet();
    virtual Card *createAncientFoglet();
    virtual Card *createDraugir();
    virtual Card *createDraug();
    virtual Card *createHarpyEgg();
    virtual Card *createHarpyHatchling();
    virtual Card *createCelaenoHarpy();
    virtual Card *createArachasBehemoth();
    virtual Card *createArachasHatchling();
    virtual Card *createArchgriffin();
    virtual Card *createGriffin();
    virtual Card *createBridgeTroll();
    virtual Card *createCockatrice();
    virtual Card *createNekurat();
    virtual Card *createSiren();
    virtual Card *createLamia();
    virtual Card *createNekker();
    virtual Card *createNekkerWarrior();
    virtual Card *createSlyzard();
    virtual Card *createWerecat();
    virtual Card *createHarpy();
    virtual Card *createWildHuntDrakkar();
    virtual Card *createGeels();
    virtual Card *createWildHuntRider();
    virtual Card *createVranWarrior();
    virtual Card *createAnCraiteArmorsmith();
    virtual Card *createAvalach();
    virtual Card *createAvalachSage();
    virtual Card *createRaghNarRoog();
    virtual Card *createGeraltProfessional();
    virtual Card *createGeraltAard();
    virtual Card *createGeraltYrden();
    virtual Card *createCiriDash();
    virtual Card *createAguara();
    virtual Card *createAguaraTrueForm();
    virtual Card *createKorathiHeatwave();
    virtual Card *createAleOfTheAncestors();
    virtual Card *createMahakamAle();
    virtual Card *createOdrin();
    virtual Card *createToruviel();
    virtual Card *createMilva();
    virtual Card *createPrincessPavetta();
    virtual Card *createLesserGuardian();
    virtual Card *createTheGuardian();
    virtual Card *createGaunterODimm();
    virtual Card *createKaedweniSergeant();
    virtual Card *createReinforcedBallista();
    virtual Card *createSigismundDijkstra();
    virtual Card *createWhiteFrost();
    virtual Card *createWolfsbane();
    virtual Card *createDunBanner();
    virtual Card *createAelirenn();
    virtual Card *createHanmarvynsDream();
    virtual Card *createBlackBlood();
    virtual Card *createBekkersRockslide();
    virtual Card *createBekkersDarkMirror();
    virtual Card *createMerigoldsHailstorm();
    virtual Card *createNecromancy();
    virtual Card *createStammelfordsTremor();
    virtual Card *createExpiredAle();
    virtual Card *createTrialOfTheGrasses();
    virtual Card *createDimeritiumBomb();
    virtual Card *createGarrison();
    virtual Card *createTheLastWish();
    virtual Card *createDimeritiumShackles();
    virtual Card *createWyvernScaleShield();
    virtual Card *createMastercraftedSpear();
    virtual Card *createPetrisPhilter();
    virtual Card *createShrike();
    virtual Card *createRoyalDecree();
    virtual Card *createUmasCurse();
    virtual Card *createLacerate();
    virtual Card *createCrowsEye();
    virtual Card *createDoppler();
    virtual Card *createSpores();
    virtual Card *createMardroeme();
    virtual Card *createSihil();
    virtual Card *createDragonsDream();
    virtual Card *createEskelPathfinder();
    virtual Card *createVesemirMentor();
    virtual Card *createLambertSwordmaster();
    virtual Card *createRegisHigherVampire();
    virtual Card *createDudaCompanion();
    virtual Card *createDudaAgitator();
    virtual Card *createZoltanScoundrel();
    virtual Card *createYenneferConjurer();
    virtual Card *createTrissMerigold();
    virtual Card *createTrissTelekinesis();
    virtual Card *createDorregarayOfVole();
    virtual Card *createDandelionVainglory();
    virtual Card *createCyprianWiley();
    virtual Card *createDudu();
    virtual Card *createIhuarraquax();
    virtual Card *createMahakamMarauder();
    virtual Card *createZoltanChivay();
    virtual Card *createYenneferNecromancer();
    virtual Card *createPhoenix();
    virtual Card *createSaesenthessisBlaze();
    virtual Card *createVillentretenmerth();
    virtual Card *createOcvist();
    virtual Card *createMyrgtabrakke();
    virtual Card *createKingOfBeggars();
    virtual Card *createOlgierdVonEverec();
    virtual Card *createIrisVonEverec();
    virtual Card *createIrisCompanions();
    virtual Card *createJohnny();
    virtual Card *createStregobor();
    virtual Card *createSarah();
    virtual Card *createPeasant();
    virtual Card *createPeasantMilitia();
    virtual Card *createChort();
    virtual Card *createPrizeWinningCow();
    virtual Card *createPrincessAdda();
    virtual Card *createKingFoltest();
    virtual Card *createKingRadovidV();
    virtual Card *createEmhyrVarEmreis();
    virtual Card *createUsurper();
    virtual Card *createBrouverHoog();
    virtual Card *createEithne();
    virtual Card *createFilavandrel();
    virtual Card *createFrancescaFindabair();
    virtual Card *createAglais();
    virtual Card *createIorveth();
    virtual Card *createIorvethMeditation();
    virtual Card *createIsengrimFaoiltiarna();
    virtual Card *createIsengrimOutlaw();
    virtual Card *createIthlinneAegli();
    virtual Card *createSchirru();
    virtual Card *createSaesenthessis();
    virtual Card *createSaskia();
    virtual Card *createBarclayEls();
    virtual Card *createDennisCranmer();
    virtual Card *createSheldonSkaggs();
    virtual Card *createYarpenZigrin();
    virtual Card *createYaevinn();
    virtual Card *createIdaEmeanAepSivney();
    virtual Card *createPavkoGale();
    virtual Card *createCiaranAepEasnillen();
    virtual Card *createEibhearHattori();
    virtual Card *createMilaen();
    virtual Card *createBraenn();
    virtual Card *createMorenn();
    virtual Card *createPaulieDahlberg();
    virtual Card *createMahakamHorn();
    virtual Card *createNaturesGift();
    virtual Card *createPitTrap();
    virtual Card *createCrushingTrap();
    virtual Card *createElvenBlade();
    virtual Card *createIncineratingTrap();
    virtual Card *createBlueMountainElite();
    virtual Card *createDolBlathannaBomber();
    virtual Card *createDolBlathannaBowman();
    virtual Card *createDolBlathannaSentry();
    virtual Card *createElvenScout();
    virtual Card *createElvenSwordmaster();
    virtual Card *createDwarvenAgitator();
    virtual Card *createDwarvenMercenary();
    virtual Card *createDwarvenSkirmisher();
    virtual Card *createHawkerHealer();
    virtual Card *createHawkerSupport();
    virtual Card *createMahakamDefender();
    virtual Card *createMahakamGuard();
    virtual Card *createMahakamVolunteers();
    virtual Card *createPyrotechnician();
    virtual Card *createWardancer();
    virtual Card *createVriheddVanguard();
    virtual Card *createVriheddOfficer();
    virtual Card *createVriheddNeophyte();
    virtual Card *createVriheddBrigade();
    virtual Card *createHawkerSmuggler();
    virtual Card *createMennoCoehoorn();
    virtual Card *createRainfarnOfAttre();
    virtual Card *createAssassination();
    virtual Card *createStefanSkellen();
    virtual Card *createShilard();
    virtual Card *createXarthisius();
    virtual Card *createCantarella();
    virtual Card *createPanther();
    virtual Card *createVicovaroMedic();
    virtual Card *createAssireVarAnahid();
    virtual Card *createFringillaVigo();
    virtual Card *createFalseCiri();
    virtual Card *createDandelion();
    virtual Card *createKiyan();
    virtual Card *createPhilippaEilhart();
    virtual Card *createRocheMerciless();
    virtual Card *createShani();
    virtual Card *createVandergrift();
    virtual Card *createBotchling();
    virtual Card *createLubberkin();
    virtual Card *createNilfgaardianGate();
    virtual Card *createPeterSaarGwynleve();
    virtual Card *createVicovaroNovice();
    virtual Card *createCadaverine();
    virtual Card *createJoachimDeWett();
    virtual Card *createTreason();
    virtual Card *createVanhemar();
    virtual Card *createVrygheff();
    virtual Card *createAlbaPikeman();
    virtual Card *createCombatEngineer();
    virtual Card *createMagneDivision();
    virtual Card *createNauzicaaBrigade();
    virtual Card *createSlaveDriver();
    virtual Card *createSlaveHunter();
    virtual Card *createViperWitcher();
    virtual Card *createRotTosser();
    virtual Card *createCowCarcass();
    virtual Card *createStandardBearer();
    virtual Card *createCursedKnight();
    virtual Card *createMargaritaOfAretuza();
    virtual Card *createNenneke();
    virtual Card *createSabrinasSpecter();
    virtual Card *createSabrinaGlevissig();
    virtual Card *createThaler();
    virtual Card *createAedirnianMauler();
    virtual Card *createAretuzaAdept();
    virtual Card *createVandergriftsBlade();
    virtual Card *createReinforcedTrebuchet();
    virtual Card *createBallista();
    virtual Card *createBloodyFlail();
    virtual Card *createSpecter();
    virtual Card *createBatteringRam();
    virtual Card *createTrebuchet();
    virtual Card *createBanArdTutor();
    virtual Card *createFieldMedic();
    virtual Card *createFoltestsPride();
    virtual Card *createDamnedSorceress();
    virtual Card *createKaedweniRevenant();
    virtual Card *createTormentedMage();
    virtual Card *createSiegeTower();
    virtual Card *createSiegeMaster();
};
#endif // CARDS_H
