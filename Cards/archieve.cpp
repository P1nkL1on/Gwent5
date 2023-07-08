#include "archieve.h"

#include <cassert>
#include <random>

#include "filters.h"

std::vector<Card *> Cards::createAll()
{
    const std::vector<Card *> cards {
        createAddaStriga(),
        createDao(),
//        createPoorFingInfantry(),
//        createDeithwenArbalest(),
//        createTemerianDrummer(),
//        createDandelionPoet(),
//        createSileDeTansarville(),
//        createRedanianKnightElect(),
//        createKaedweniKnight(),
//        createAnCraiteMarauder(),
//        createAnCraiteGreatsword(),
//        createDimunLightLongship(),
//        createTuirseachBearmaster(),
//        createTuirseachHunter(),
//        createRedanianElite(),
//        createRedanianKnight(),
//        createKaedweniCavalry(),
//        createAlzursThunder(),
//        createSwallow(),
//        createThunderbolt(),
//        createArachasVenom(),
//        createKeiraMetz(),
        createDolBlathannaArcher(),
        createHalfElfHunter(),
//        createAmbassador(),
//        createAssassin(),
//        createEmissary(),
//        createCeallachDyffryn(),
//        createTuirseachArcher(),
//        createInfiltrator(),
//        createImpenetrableFog(),
//        createTorrentialRain(),
//        createBitingFrost(),
//        createGoldenFroth(),
//        createSkelligeStorm(),
//        createImperialManticore(),
//        createManticoreVenom(),
//        createGloriousHunt(),
//        createVes(),
//        createVaedermakar(),
//        createFrightener(),
//        createCleaver(),
        createScorch(),
//        createReinforcements(),
//        createJohnNatalis(),
//        createEleyas(),
//        createReaverScout(),
//        createHeymaeySpearmaiden(),
//        createVriheddSappers(),
//        createPriestessOfFreya(),
//        createDimunCorsair(),
//        createSigrdrifa(),
//        createDrummondQueensguard(),
//        createSage(),
//        createReconnaissance(),
//        createElvenMercenary(),
//        createChampionOfHov(),
//        createPriscilla(),
//        createSeltkirkOfGulet(),
//        createAdrenalineRush(),
        createMandrake(),
        createBoneTalisman(),
//        createRestore(),
//        createDecoy(),
        createShupesDayOff(),
//        createFirstLight(),
//        createEpidemic(),
//        createMoonlight(),
//        createCiriNova(),
//        createHaraldTheCripple(),
//        createBranTuirseach(),
//        createDrummondWarmonger(),
//        createDimunPirate(),
//        createAnCraiteRaider(),
//        createMadmanLugos(),
//        createErmion(),
//        createCerysFearless(),
//        createCerysAnCraite(),
//        createWoodlandSpirit(),
//        createTrollololo(),
//        createPrinceStennis(),
//        createVincentMeis(),
//        createMorkvarg(),
//        createArtefactCompression(),
//        createHjalmarAnCraite(),
//        createRegis(),
//        createLethoOfGulet(),
//        createAnCraiteLongship(),
//        createGeraltIgni(),
//        createGeraltOfRivia(),
//        createTuirseachVeteran(),
//        createUdalryk(),
//        createBloodcurdlingRoar(),
//        createGremist(),
//        createZoriaRunestone(),
//        createOperator(),
//        createRenew(),
//        createEistTuirseach(),
//        createTuirseachAxeman(),
//        createDerran(),
//        createTuirseachSkirmisher(),
//        createRoach(),
//        createJanCalveit(),
//        createCahirDyffryn(),
//        createLethoKingslayer(),
//        createKingHenselt(),
//        createBloodyBaron(),
//        createHubertRejk(),
//        createDethmold(),
//        createRonvidTheIncessant(),
//        createCrachAnCraite(),
//        createBirnaBran(),
//        createCoral(),
//        createVabjorn(),
//        createBlueboyLugos(),
//        createDjengeFrett(),
//        createDonarAnHindar(),
//        createDraigBonDhu(),
//        createHolgerBlackhand(),
//        createJuttaAnDimun(),
//        createSavageBear(),
//        createSvanrigeTuirseach(),
//        createSkjall(),
//        createHaraldHoundsnout(),
//        createYoana(),
//        createAnCraiteBlacksmith(),
//        createAnCraiteWarcrier(),
//        createAnCraiteWarrior(),
//        createBerserkerMarauder(),
//        createDimunPirateCaptain(),
//        createDimunSmuggler(),
//        createDrummondShieldmaid(),
//        createHeymaeyFlaminica(),
//        createHeymaeyHerbalist(),
//        createHeymaeyProtector(),
//        createHeymaeySkald(),
//        createRagingBerserker(),
//        createHym(),
//        createKambi(),
//        createOlaf(),
//        createUlfhedinn(),
//        createWildBoarOfTheSea(),
//        createGiantBoar(),
//        createOrnamentalSword(),
//        createDimunWarship(),
//        createVilgefortz(),
//        createTrissButterflies(),
//        createYennefer(),
//        createGermainPiquant(),
//        createCommandersHorn(),
//        createMarchingOrders(),
//        createAlzursDoubleCross(),
//        createAlbaArmoredCavalry(),
//        createSentry(),
//        createNauzicaaSergeant(),
//        createSlaveInfantry(),
//        createRecruit(),
//        createOintment(),
//        createVreemde(),
//        createLambert(),
//        createEskel(),
//        createVesemir(),
//        createTridamInfantry(),
//        createVriheddDragoon(),
//        createMalena(),
//        createUnseenElder(),
//        createDevanaRunestone(),
//        createDazhbogRunestone(),
//        createMoranaRunestone(),
//        createStribogRunestone(),
//        createMuzzle(),
//        createWhisperingHillock(),
//        createBrewess(),
//        createWeavess(),
//        createWhispess(),
//        createWeavessIncantation(),
//        createBrewessRitual(),
//        createWhispessTribute(),
//        createNivellen(),
//        createLeoBonhart(),
//        createMorvranVoorhis(),
//        createCynthia(),
//        createSerrit(),
//        createSweers(),
//        createTiborEggebracht(),
//        createVattierDeRideaux(),
//        createAlbrich(),
//        createHeftyHelge(),
//        createAlchemist(),
//        createDaerlanSoldier(),
//        createFireScorpion(),
//        createMangonel(),
//        createNilfgaardianKnight(),
//        createSpotter(),
//        createVenendalElite(),
//        createMasterOfDisguise(),
//        createHenryVarAttre(),
//        createWildHuntHound(),
//        createWildHuntWarrior(),
//        createWildHuntNavigator(),
//        createNithral(),
//        createMiruna(),
//        createImlerith(),
//        createCaretaker(),
//        createRuehin(),
//        createOldSpeartipAsleep(),
//        createOldSpeartip(),
//        createGolyat(),
//        createBarbegazi(),
//        createGhoul(),
//        createForktail(),
//        createArachasQueen(),
//        createOzzrel(),
//        createKayran(),
//        createMourntart(),
//        createToadPrince(),
//        createFiend(),
//        createMorvudd(),
//        createEkimmara(),
//        createRotfiend(),
//        createArchespore(),
//        createCyclops(),
//        createMaerolorn(),
//        createMonsterNest(),
//        createArachasDrone(),
//        createEredinBreaccGlas(),
//        createCaranthirArFeiniel(),
//        createImlerithSabbath(),
//        createDagon(),
//        createIfrit(),
//        createSheTrollOfVergen(),
//        createWyvern(),
//        createAbaya(),
//        createParasite(),
//        createJotunn(),
//        createIceGiant(),
//        createIceTroll(),
//        createDrowner(),
//        createFoglet(),
//        createAncientFoglet(),
//        createDraug(),
//        createCelaenoHarpy(),
//        createArachasBehemoth(),
//        createArchgriffin(),
//        createGriffin(),
//        createBridgeTroll(),
//        createCockatrice(),
//        createSiren(),
//        createLamia(),
//        createNekker(),
//        createNekkerWarrior(),
//        createSlyzard(),
//        createWerecat(),
//        createHarpy(),
//        createWildHuntDrakkar(),
//        createGeels(),
//        createWildHuntRider(),
//        createVranWarrior(),
//        createAnCraiteArmorsmith(),
//        createAvalach(),
//        createAvalachSage(),
//        createNekurat(),
//        createRaghNarRoog(),
//        createGeraltProfessional(),
//        createGeraltAard(),
//        createGeraltYrden(),
//        createCiriDash(),
//        createAguara(),
//        createAguaraTrueForm(),
//        createKorathiHeatwave(),
//        createAleOfTheAncestors(),
//        createMahakamAle(),
//        createOdrin(),
//        createToruviel(),
//        createCiri(),
//        createMilva(),
//        createPrincessPavetta(),
//        createTheGuardian(),
//        createGaunterODimm(),
//        createKaedweniSergeant(),
//        createReinforcedBallista(),
//        createSigismundDijkstra(),
//        createWhiteFrost(),
//        createWolfsbane(),
//        createDunBanner(),
//        createAelirenn(),
//        createHanmarvynsDream(),
//        createBlackBlood(),
//        createBekkersRockslide(),
//        createBekkersDarkMirror(),
//        createMerigoldsHailstorm(),
//        createNecromancy(),
//        createStammelfordsTremor(),
//        createExpiredAle(),
//        createTrialOfTheGrasses(),
//        createDimeritiumBomb(),
//        createGarrison(),
//        createTheLastWish(),
//        createDimeritiumShackles(),
//        createWyvernScaleShield(),
//        createMastercraftedSpear(),
//        createPetrisPhilter(),
//        createShrike(),
//        createRoyalDecree(),
//        createUmasCurse(),
//        createLacerate(),
//        createCrowsEye(),
//        createDoppler(),
//        createSpores(),
//        createMardroeme(),
//        createSihil(),
//        createEskelPathfinder(),
//        createVesemirMentor(),
//        createLambertSwordmaster(),
//        createRegisHigherVampire(),
//        createZoltanScoundrel(),
//        createYenneferConjurer(),
//        createTrissMerigold(),
//        createTrissTelekinesis(),
//        createDorregarayOfVole(),
//        createDandelionVainglory(),
//        createCyprianWiley(),
//        createDudu(),
//        createIhuarraquax(),
//        createMahakamMarauder(),
//        createZoltanChivay(),
//        createYenneferNecromancer(),
//        createPhoenix(),
//        createSaesenthessisBlaze(),
//        createVillentretenmerth(),
//        createOcvist(),
//        createMyrgtabrakke(),
//        createKingOfBeggars(),
//        createOlgierdVonEverec(),
//        createIrisVonEverec(),
//        createIrisCompanions(),
//        createJohnny(),
//        createStregobor(),
//        createSarah(),
//        createPeasantMilitia(),
//        createPrizeWinningCow(),
//        createPrincessAdda(),
//        createKingFoltest(),
//        createKingRadovidV(),
//        createEmhyrVarEmreis(),
//        createUsurper(),
//        createBrouverHoog(),
//        createEithne(),
//        createFilavandrel(),
//        createFrancescaFindabair(),
//        createAglais(),
//        createIorveth(),
//        createIorvethMeditation(),
//        createIsengrimFaoiltiarna(),
//        createIsengrimOutlaw(),
//        createSchirru(),
//        createSaesenthessis(),
//        createSaskia(),
//        createBarclayEls(),
//        createDennisCranmer(),
//        createSheldonSkaggs(),
//        createYarpenZigrin(),
//        createYaevinn(),
//        createIdaEmeanAepSivney(),
//        createPavkoGale(),
//        createCiaranAepEasnillen(),
//        createEibhearHattori(),
//        createMilaen(),
//        createBraenn(),
//        createMorenn(),
//        createPaulieDahlberg(),
//        createMahakamHorn(),
//        createNaturesGift(),
//        createPitTrap(),
//        createCrushingTrap(),
//        createElvenBlade(),
//        createIncineratingTrap(),
//        createBlueMountainElite(),
//        createDolBlathannaBomber(),
//        createDolBlathannaBowman(),
//        createDolBlathannaSentry(),
//        createElvenScout(),
//        createElvenSwordmaster(),
//        createDwarvenAgitator(),
//        createDwarvenMercenary(),
//        createDwarvenSkirmisher(),
//        createHawkerHealer(),
//        createHawkerSupport(),
//        createMahakamDefender(),
//        createMahakamGuard(),
//        createMahakamVolunteers(),
//        createPyrotechnician(),
//        createWardancer(),
//        createVriheddVanguard(),
//        createVriheddOfficer(),
//        createVriheddNeophyte(),
//        createVriheddBrigade(),
//        createHawkerSmuggler(),
//        createMennoCoehoorn(),
//        createRainfarnOfAttre(),
//        createAssassination(),
//        createStefanSkellen(),
//        createShilard(),
//        createCantarella(),
//        createPanther(),
//        createVicovaroMedic(),
//        createAssireVarAnahid(),
//        createFringillaVigo(),
//        createFalseCiri(),
//        createDandelion(),
//        createKiyan(),
//        createPlay(),
//        createCreate(),
//        createPhilippaEilhart(),
//        createRocheMerciless(),
//        createShani(),
//        createVandergrift(),
//        createBotchling(),
//        createLubberkin(),
//        createNilfgaardianGate(),
//        createPeterSaarGwynleve(),
//        createVicovaroNovice(),
//        createCadaverine(),
//        createDealDamage(),
//        createDestroy(),
//        createJoachimDeWett(),
//        createTreason(),
//        createVanhemar(),
//        createVrygheff(),
//        createAlbaPikeman(),
//        createCombatEngineer(),
//        createMagneDivision(),
//        createNauzicaaBrigade(),
//        createSlaveDriver(),
//        createSlaveHunter(),
//        createViperWitcher(),
//        createRotTosser(),
//        createCowCarcass(),
//        createStandardBearer(),
    };
    return cards;
}

Card *Cards::createAddaStriga()
{
    auto *card = new Card();
    card->_constructor = std::bind(&Cards::createAddaStriga, this);

    card->id = "200073";
    card->power = card->powerBase = 6;
    card->rarity = Silver;
    card->faction = Monster;
    card->tags = { Relict, Cursed };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isNonMonsterFaction});
    };

    card->_onTargetChoosen = [=](Card *card, Field &ally, Field &enemy) {
        damage(card, 8, ally, enemy, card);
    };

    return card;
}

Card *Cards::createDaoLesser()
{
    auto *card = new Card();
    card->_constructor = std::bind(&Cards::createDaoLesser, this);

    card->id = "132405";
    card->power = card->powerBase = 4;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Construct };
    card->isDoomed = true;
    return card;
}

Card *Cards::createDao()
{
    auto *card = new Card();
    card->_constructor = std::bind(&Cards::createDao, this);

    card->id = "132213";
    card->power = card->powerBase = 6;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Construct };

    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &rowAndPos) {
        spawnNewUnitToPos(createDaoLesser(), rowAndPos, ally, enemy, card);
        spawnNewUnitToPos(createDaoLesser(), rowAndPos, ally, enemy, card);
    };

    return card;
}

//Card *Cards::createPoorFingInfantry()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200234";
//    card->power = card->powerBase = 6;
//    card->rarity = Bronze;
//    card->faction = NothernRealms;
//    card->tags = { Temeria, Soldier };


//    const auto createLeftFlankInfantry = []{
//        auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//        card->id = "200302";
//        card->power = card->powerBase = 2;
//        card->rarity = Bronze;
//        card->faction = NothernRealms;
//        card->tags = { Temeria, Soldier };
//        card->isDoomed = true;
//        return card;
//    };


//    const auto createRightFlankInfantry = []{
//        auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//        card->id = "200303";
//        card->power = card->powerBase = 2;
//        card->rarity = Bronze;
//        card->faction = NothernRealms;
//        card->tags = { Temeria, Soldier };
//        card->isDoomed = true;
//        return card;
//    };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        spawnNewUnitToPos(createLeftFlankInfantry(), rowAndPosToTheLeft(card, ally, 1), ally, enemy, card);
//        spawnNewUnitToPos(createRightFlankInfantry(), rowAndPosToTheRight(card, ally, 1), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createDeithwenArbalest()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162305";
//    card->power = card->powerBase = 7;
//    card->rarity = Bronze;
//    card->faction = Nilfgaard;
//    card->tags = { Soldier };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        damage(target, target->isSpy ? 6 : 3, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createTemerianDrummer()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200299";
//    card->power = card->powerBase = 5;
//    card->rarity = Bronze;
//    card->faction = NothernRealms;
//    card->tags = { Temeria, Support };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AllyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        boost(target, 6, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createDandelionPoet()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201776";
//    card->power = card->powerBase = 5;
//    card->rarity = Gold;
//    card->faction = Neutral;
//    card->tags = { Support };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (drawACard(ally, enemy,  card))
//            startChoiceToTargetCard(ally, enemy, card, {}, AllyHand);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createSileDeTansarville()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "122205";
//    card->power = card->powerBase = 4;
//    card->rarity = Silver;
//    card->faction = NothernRealms;
//    card->tags = { Mage };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, ::isSpecial}, AllyHand);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//        drawACard(ally, enemy,  card);
//    };
//    return card;
//}


//Card *Cards::createRedanianKnightElect()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "123301";
//    card->power = card->powerBase = 7;
//    card->rarity = Bronze;
//    card->faction = NothernRealms;
//    card->tags = { Redania, Soldier };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        gainArmor(card, 2, ally, enemy, card);
//    };

//    card->_onTurnEnd = [=](Field &ally, Field &enemy) {
//        if (card->armor == 0)
//            return;

//        Card *left = cardNextTo(card, ally, enemy, -1);
//        Card *right = cardNextTo(card, ally, enemy, 1);

//        if (left != nullptr)
//            boost(left, 1, ally, enemy, card);
//        if (right != nullptr)
//            boost(right, 1, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createAnCraiteMarauder()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201578";
//    card->power = card->powerBase = 7;
//    card->rarity = Bronze;
//    card->faction = Skellige;
//    card->tags = { ClanAnCraite, Soldier };

//    // FIXME: no ability
//    return card;
//}


//Card *Cards::createAnCraiteGreatsword()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200040";
//    card->power = card->powerBase = 8;
//    card->rarity = Bronze;
//    card->faction = Skellige;
//    card->tags = { ClanAnCraite, Soldier };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        setTimer(card, ally, enemy, 2);
//    };

//    card->_onTurnStart = [=](Field &ally, Field &enemy) {
//        if (!isOnBoard(card, ally) || !tick(card, ally, enemy, 2))
//            return;

//        if (card->power >= card->powerBase)
//            return;

//        heal(card, ally, enemy, card);
//        strengthen(card, 2, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createDimunLightLongship()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152309";
//    card->power = card->powerBase = 7;
//    card->rarity = Bronze;
//    card->faction = Skellige;
//    card->tags = { ClanDimun, Machine };

//    card->_onTurnEnd = [=](Field &ally, Field &enemy) {
//        if (Card *right = cardNextTo(card, ally, enemy, 1)) {
//            damage(right, 1, ally, enemy, card);
//            boost(card, 2, ally, enemy, card);
//        }
//    };
//    return card;
//}


//Card *Cards::createBear()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152406";
//    card->power = card->powerBase = 11;
//    card->rarity = Bronze;
//    card->faction = Neutral;
//    card->tags = { Beast, Cursed };
//    return card;
//}


//Card *Cards::createWolf()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132403";
//    card->power = card->powerBase = 1;
//    card->isDoomed = true;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Beast };
//    return card;
//}


//Card *Cards::createTuirseachBearmaster()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200144";
//    card->power = card->powerBase = 1;
//    card->rarity = Bronze;
//    card->faction = Skellige;
//    card->tags = { ClanTuirseach, Soldier };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        spawnNewCard(createBear(), ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createRedanianElite()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "122317";
//    card->power = card->powerBase = 8;
//    card->rarity = Bronze;
//    card->faction = NothernRealms;
//    card->tags = { Redania, Soldier };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        gainArmor(card, 4, ally, enemy, card);
//    };

//    card->_onArmorLost = [=](Field &ally, Field &enemy) {
//        boost(card, 5, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createRedanianKnight()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "122308";
//    card->power = card->powerBase = 7;
//    card->rarity = Bronze;
//    card->faction = NothernRealms;
//    card->tags = { Redania, Soldier };

//    card->_onTurnEnd = [=](Field &ally, Field &enemy) {
//        if (card->armor != 0)
//            return;
//        boost(card, 2, ally, enemy, card);
//        gainArmor(card, 2, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createKaedweniCavalry()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "122314";
//    card->power = card->powerBase = 8;
//    card->rarity = Bronze;
//    card->faction = NothernRealms;
//    card->tags = { Kaedwen, Soldier };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {hasArmor});
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        const int armorTarget = target->armor;
//        damage(target, armorTarget, ally, enemy, card);
//        boost(card, armorTarget, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createAlzursThunder()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "113301";
//    card->rarity = Bronze;
//    card->faction = Neutral;
//    card->tags = { Spell };
//    card->isSpecial = true;

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        saveFieldsSnapshot(ally, enemy, DealDamage, card, {target}, "", 9);
//        damage(target, 9, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createSwallow()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "113310";
//    card->rarity = Bronze;
//    card->faction = Neutral;
//    card->tags = { Alchemy, Item };
//    card->isSpecial = true;

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        boost(target, 10, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createThunderbolt()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "113311";
//    card->rarity = Bronze;
//    card->faction = Neutral;
//    card->tags = { Alchemy, Item };
//    card->isSpecial = true;

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        boost(target, 3, ally, enemy, card);
//        gainArmor(target, 2, ally, enemy, card);

//        Card *left = cardNextTo(target, ally, enemy, -1);
//        Card *right = cardNextTo(target, ally, enemy, 1);

//        if (left != nullptr) {
//            boost(left, 3, ally, enemy, card);
//            gainArmor(left, 2, ally, enemy, card);
//        }
//        if (right != nullptr) {
//            boost(right, 3, ally, enemy, card);
//            gainArmor(right, 2, ally, enemy, card);
//        }
//    };
//    return card;
//}


//Card *Cards::createArachasVenom()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200023";
//    card->rarity = Bronze ;
//    card->faction = Neutral;
//    card->tags = { Organic };
//    card->isSpecial = true;

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        Card *left = cardNextTo(target, ally, enemy, -1);
//        Card *right = cardNextTo(target, ally, enemy, 1);
//        for (Card *card : std::vector<Card *>{left, target, right})
//            if (card != nullptr)
//                damage(card, 4, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createKeiraMetz()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "122108";
//    card->power = card->powerBase = 6;
//    card->rarity = Gold;
//    card->faction = NothernRealms;
//    card->tags = { Temeria, Mage };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectOption(ally, enemy, card, {createAlzursThunder(), createThunderbolt(), createArachasVenom()});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        spawnNewCard(target, ally, enemy, card);
//    };
//    return card;
//}


Card *Cards::createDolBlathannaArcher()
{
    auto *card = new Card();
    card->_constructor = std::bind(&Cards::createDolBlathannaArcher, this);

    card->id = "142310";
    card->power = card->powerBase = 7;
    card->rarity = Bronze;
    card->faction = Scoiatael;
    card->tags = { Elf, Soldier };

    struct State : StateCopy<State> { int _nShots = 0; };
    card->state = new State();

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        card->stateAs<State>()->_nShots = 0;
        startChoiceToTargetCard(ally, enemy, card);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        int &nShots = card->stateAs<State>()->_nShots;
        ++nShots;
        if (nShots == 1) {
            damage(target, 3, ally, enemy, card);
            startChoiceToTargetCard(ally, enemy, card);
            return;
        }
        if (nShots == 2) {
            damage(target, 1, ally, enemy, card);
            return;
        }
        assert(false);
    };
    return card;
}


Card *Cards::createHalfElfHunter()
{
    auto *card = new Card();
    card->_constructor = std::bind(&Cards::createHalfElfHunter, this);

    card->id = "201636";
    card->power = card->powerBase = 6;
    card->rarity = Bronze;
    card->faction = Scoiatael;
    card->tags = { Elf, Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        Card *copy = card->defaultCopy();
        copy->isDoomed = true;
        summonNewUnitToPos(copy, rowAndPosToTheRight(card, ally, 1), ally, enemy, card);
    };
    return card;
}


//Card *Cards::createAmbassador()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162315";
//    card->power = card->powerBase = 2;
//    card->isLoyal = false;
//    card->rarity = Bronze;
//    card->faction = Nilfgaard;
//    card->tags = {};

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AllyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        boost(target, 12, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createAssassin()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200115";
//    card->power = card->powerBase = 1;
//    card->isLoyal = false;
//    card->rarity = Bronze;
//    card->faction = Nilfgaard;
//    card->tags = {};

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (Card *left = cardNextTo(card, ally, enemy, -1)) {
//            damage(left, 10, ally, enemy, card);
//        }
//    };
//    return card;
//}


//Card *Cards::createTuirseachArcher()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152315";
//    card->power = card->powerBase = 8;
//    card->rarity = Bronze;
//    card->faction = Skellige;
//    card->tags = { ClanTuirseach, Soldier };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard, 3);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        saveFieldsSnapshot(ally, enemy, DealDamage, card, {target}, "", 1);
//        damage(target, 1, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createInfiltrator()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200118";
//    card->power = card->powerBase = 10;
//    card->rarity = Bronze;
//    card->faction = Nilfgaard;
//    card->tags = {};

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        toggleSpy(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createImpenetrableFog()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "113305";
//    card->isSpecial = true;
//    card->rarity = Bronze;
//    card->faction = Neutral;
//    card->tags = { Hazard };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectRow(ally, enemy, card, {3, 4, 5});
//    };

//    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
//        applyRowEffect(ally, enemy, screenRow, ImpenetrableFogEffect);
//    };
//    return card;
//}


//Card *Cards::createTorrentialRain()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "113312";
//    card->isSpecial = true;
//    card->rarity = Bronze;
//    card->faction = Neutral;
//    card->tags = { Hazard };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectRow(ally, enemy, card, {3, 4, 5});
//    };

//    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
//        applyRowEffect(ally, enemy, screenRow, TorrentialRainEffect);
//    };
//    return card;
//}


//Card *Cards::createBitingFrost()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "113302";
//    card->isSpecial = true;
//    card->rarity = Bronze;
//    card->faction = Neutral;
//    card->tags = { Hazard };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectRow(ally, enemy, card, {3, 4, 5});
//    };

//    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
//        applyRowEffect(ally, enemy, screenRow, BitingFrostEffect);
//    };
//    return card;
//}


//Card *Cards::createGoldenFroth()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201749";
//    card->isSpecial = true;
//    card->rarity = Bronze;
//    card->faction = Neutral;
//    card->tags = { Boon };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectRow(ally, enemy, card, {0, 1, 2});
//    };

//    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
//        applyRowEffect(ally, enemy, screenRow, GoldenFrothEffect);
//    };
//    return card;
//}


//Card *Cards::createSkelligeStorm()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "113203";
//    card->isSpecial = true;
//    card->rarity = Silver;
//    card->faction = Neutral;
//    card->tags = { Hazard };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectRow(ally, enemy, card, {3, 4, 5});
//    };

//    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
//        applyRowEffect(ally, enemy, screenRow, SkelligeStormEffect);
//    };
//    return card;
//}


//Card *Cards::createImperialManticore()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132209";
//    card->power = card->powerBase = 13;
//    card->rarity = Silver;
//    card->faction = Monster;
//    card->tags = { Beast };
//    return card;
//}


//Card *Cards::createManticoreVenom()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "113306";
//    card->isSpecial = true;
//    card->rarity = Silver;
//    card->faction = Neutral;
//    card->tags = { Organic };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        damage(target, 13, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createGloriousHunt()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201635";
//    card->isSpecial = true;
//    card->rarity = Silver;
//    card->faction = Neutral;
//    card->tags = { Tactics };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        if (powerField(ally) < powerField(enemy))
//            return spawnNewCard(createImperialManticore(), ally, enemy, card);

//        return spawnNewCard(createManticoreVenom(), ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createVes()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "122204";
//    card->power = card->powerBase = 12;
//    card->rarity = Silver;
//    card->faction = NothernRealms;
//    card->tags = { Temeria, Soldier };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AllyHand, 2, true);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        swapACard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createVaedermakar()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "113208";
//    card->power = card->powerBase = 4;
//    card->rarity = Silver;
//    card->faction = Neutral;
//    card->tags = { Mage };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectOption(ally, enemy, card, {createBitingFrost(), createImpenetrableFog(), createAlzursThunder()});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        spawnNewCard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createFrightener()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132204";
//    card->power = card->powerBase = 13;
//    card->isLoyal = false;
//    card->timer = 1;
//    card->rarity = Silver;
//    card->faction = Monster;
//    card->tags = { Construct, Agent };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (tick(card, ally, enemy))
//            drawACard(ally, enemy,  card);

//        /// can't move another to this row, if its already full
//        startChoiceToTargetCard(ally, enemy, card, {isOnAnotherRow(&enemy, card)}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        moveExistedUnitToPos(target, rowAndPosLastInTheSameRow(card, enemy), enemy, ally, card);
//    };
//    return card;
//}


//Card *Cards::createCleaver()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "122216";
//    card->power = card->powerBase = 7;
//    card->rarity = Silver;
//    card->faction = Neutral;
//    card->tags = { Dwarf };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (ally.hand.size() != 0)
//            startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        damage(target, int(ally.hand.size()), ally, enemy, card);
//    };
//    return card;
//}


Card *Cards::createScorch()
{
    auto *card = new Card();
    card->_constructor = std::bind(&Cards::createScorch, this);

    card->id = "113309";
    card->isSpecial = true;
    card->rarity = Silver;
    card->faction = Neutral;
    card->tags = { Spell };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        for (Card *card : highests(cardsFiltered(ally, enemy, {}, AnyBoard)))
            putToDiscard(card, ally, enemy, card);
    };
    return card;
}


//Card *Cards::createReinforcements()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "123201";
//    card->isSpecial = true;
//    card->rarity = Silver;
//    card->faction = NothernRealms;
//    card->tags = { Tactics };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, hasAnyOfTags({Soldier, Support, Machine, Officer})}, AllyDeckShuffled);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createJohnNatalis()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "122103";
//    card->power = card->powerBase = 6;
//    card->rarity = Gold;
//    card->faction = NothernRealms;
//    card->tags = { Temeria, Officer };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, hasTag(Tactics)}, AllyDeckShuffled);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createEleyas()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142214";
//    card->power = card->powerBase = 10;
//    card->rarity = Silver;
//    card->faction = Scoiatael;
//    card->tags = { Elf, Soldier };

//    // NOTE: when Eleyas goes to deck, it loses all the boosts - so it doesn't work properly
//    card->_onDraw = [=](Field &ally, Field &enemy) {
//        boost(card, 2, ally, enemy, card);
//    };

//    card->_onSwap = [=](Field &ally, Field &enemy) {
//        boost(card, 2, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createReaverScout()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "122307";
//    card->power = card->powerBase = 1;
//    card->rarity = Bronze;
//    card->faction = NothernRealms;
//    card->tags = { Redania, Support };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronze, otherThan(name), hasCopyInADeck(&ally)}, AllyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (Card *copy = findCopy(target, ally.deck))
//            playExistedCard(copy, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createHeymaeySpearmaiden()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200528";
//    card->power = card->powerBase = 2;
//    card->rarity = Bronze;
//    card->faction = Skellige;
//    card->tags = { ClanAnCraite, Support };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronze, hasAnyOfTags({Soldier, Machine}), hasCopyInADeck(&ally)}, AllyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        damage(target, 1, ally, enemy, card);
//        if (Card *copy = findCopy(target, ally.deck))
//            playExistedCard(copy, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createKaedweniKnight()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201622";
//    card->power = card->powerBase = 8;
//    card->rarity = Bronze;
//    card->faction = NothernRealms;
//    card->tags = { Kaedwen, Soldier };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        gainArmor(card, 2, ally, enemy, card);
//    };

//    card->_onDeployFromDeck = [=](Field &ally, Field &enemy) {
//        gainArmor(card, 2, ally, enemy, card);
//        boost(card, 5, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createVriheddSappers()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142307";
//    card->power = card->powerBase = 11;
//    card->isAmbush = true;
//    card->rarity = Bronze;
//    card->faction = Scoiatael;
//    card->tags = { Elf, Soldier };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        card->isAmbush = true;
//        setTimer(card, ally, enemy, 2);
//    };

//    card->_onTurnStart = [=](Field &ally, Field &enemy) {
//        if (!isOnBoard(card, ally) || tick(card, ally, enemy))
//            flipOver(card, ally, enemy);
//    };
//    return card;
//}


//Card *Cards::createPriestessOfFreya()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152310";
//    card->power = card->powerBase = 1;
//    card->rarity = Bronze;
//    card->faction = Skellige;
//    card->tags = { ClanHeymaey, Support };
//    card->isDoomed = true;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronze, hasTag(Soldier)}, AllyDiscard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createDimunCorsair()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200145";
//    card->power = card->powerBase = 3;
//    card->rarity = Bronze;
//    card->faction = Skellige;
//    card->tags = { ClanDimun, Support };
//    card->isDoomed = true;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronze, hasTag(Machine)}, AllyDiscard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createSigrdrifa()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152211";
//    card->power = card->powerBase = 3;
//    card->rarity = Silver;
//    card->faction = Skellige;
//    card->tags = { Support };
//    card->isDoomed = true;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, hasAnyOfTags({ClanAnCraite, ClanDimun, ClanDrummond, ClanHeymaey, ClanTuirseach, ClanBrokvar, ClanTordarroch})}, AllyDiscard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createSage()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200138";
//    card->power = card->powerBase = 2;
//    card->rarity = Bronze;
//    card->faction = Scoiatael;
//    card->tags = { Elf, Mage };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronze, hasAnyOfTags({Alchemy, Spell})}, AllyDiscard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        target->isDoomed = true;
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createReconnaissance()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201704";
//    card->isSpecial = true;
//    card->rarity = Bronze;
//    card->faction = Neutral;
//    card->tags = { Tactics };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, randoms(cardsFiltered(ally, enemy, {isBronze, isUnit}, AllyDeck), 2, ally.rng));
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createElvenMercenary()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142308";
//    card->power = card->powerBase = 1;
//    card->rarity = Bronze;
//    card->faction = Scoiatael;
//    card->tags = { Elf, Soldier };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, randoms(cardsFiltered(ally, enemy, {isBronze, ::isSpecial}, AllyDeck), 2, ally.rng));
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createChampionOfHov()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152202";
//    card->power = card->powerBase = 7;
//    card->rarity = Silver;
//    card->faction = Skellige;
//    card->tags = { Ogroid };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        duel(card, target, ally, enemy);
//    };
//    return card;
//}


//Card *Cards::createGeraltIgni()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112102";
//    card->power = card->powerBase = 5;
//    card->rarity = Gold;
//    card->faction = Neutral;
//    card->tags = { Witcher };

//    const auto isOkRow = [](const std::vector<Card *> &cards) {
//        return powerRow(cards) >= 25;
//    };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectRow(ally, enemy, card, {3, 4, 5}, {isOkRow});
//    };

//    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
//        for (Card *card : highests(cardsInRow(ally, enemy, screenRow)))
//            putToDiscard(card, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createGeraltOfRivia()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112103";
//    card->power = card->powerBase = 15;
//    card->rarity = Gold;
//    card->faction = Neutral;
//    card->tags = { Witcher };
//    return card;
//}


//Card *Cards::createPriscilla()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "122202";
//    card->power = card->powerBase = 3;
//    card->rarity = Gold;
//    card->faction = NothernRealms;
//    card->tags = { Support };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        for (Card *card : randoms(cardsFiltered(ally, enemy, {[=](Card *card){ return card != card; }}, AllyBoard), 5, ally.rng))
//            boost(card, 3, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createSeltkirkOfGulet()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201618";
//    card->power = card->powerBase = 8;
//    card->rarity = Gold;
//    card->faction = NothernRealms;
//    card->tags = { Aedirn, Officer, Cursed };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        gainArmor(card, 3, ally, enemy, card);
//        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        duel(card, target, ally, enemy);
//    };
//    return card;
//}


//Card *Cards::createAdrenalineRush()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "113307";
//    card->isSpecial = true;
//    card->rarity = Bronze;
//    card->faction = Neutral;
//    card->tags = { Organic };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &, Field &) {
//        target->isResilient = !target->isResilient;
//    };
//    return card;
//}


struct StateChoosen : StateCopy<StateChoosen> { Card *_choosen = nullptr; };


Card *Cards::createMandrake()
{
    auto *card = new Card();
    card->_constructor = std::bind(&Cards::createMandrake, this);

    card->id = "200223";
    card->isSpecial = true;
    card->rarity = Silver;
    card->faction = Neutral;
    card->tags = { Alchemy, Organic };
    card->state = new StateChoosen();

    enum { Buff, Debuff };
    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        Card *option1 = createOption(card, Buff);
        option1->text = "Heal a unit and and Strengthen it by 6.";

        Card *option2 = createOption(card, Debuff);
        option2->text = "Reset a unit and Weaken it by 6.";

        card->stateAs<StateChoosen>()->_choosen = nullptr;
        startChoiceToSelectOption(ally, enemy, card, {option1, option2});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        card->stateAs<StateChoosen>()->_choosen = target;
        startChoiceToTargetCard(ally, enemy, card);
        return;
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        Card *choosen = card->stateAs<StateChoosen>()->_choosen;
        assert(choosen);

        if (isOption(choosen, Buff)) {
            heal(target, ally, enemy, card);
            strengthen(target, 6, ally, enemy, card);

            delete choosen;
            choosen = nullptr;
            return;
        }

        if (isOption(choosen, Debuff)) {
            reset(target, ally, enemy, card);
            weaken(target, 6, ally, enemy, card);

            delete choosen;
            choosen = nullptr;
            return;
        }

        assert(false);
    };
    return card;
}


Card *Cards::createBoneTalisman()
{
    auto *card = new Card();
    card->_constructor = std::bind(&Cards::createBoneTalisman, this);

    card->id = "201598";
    card->isSpecial = true;
    card->rarity = Bronze;
    card->faction = Skellige;
    card->tags = { Item };
    card->state = new StateChoosen();

    enum { Resurrect, Buff };
    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        auto *option1 = createOption(card, Resurrect);
        option1->text = "Resurrect a Bronze Beast or Cultist.";

        auto *option2 = createOption(card, Buff);
        option2->text = "Heal an ally and Strengthen it by 3.";

        card->stateAs<StateChoosen>()->_choosen = nullptr;
        startChoiceToSelectOption(ally, enemy, card, {option1, option2});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        card->stateAs<StateChoosen>()->_choosen = target;

        if (isOption(target, Resurrect))
            return startChoiceToTargetCard(ally, enemy, card, {isBronze, hasAnyOfTags({Beast, Cultist})}, AllyDiscard);

        if (isOption(target, Buff))
            return startChoiceToTargetCard(ally, enemy, card, {}, AllyBoard);

        assert(false);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        Card *choosen = card->stateAs<StateChoosen>()->_choosen;
        assert(choosen);

        if (isOption(choosen, Resurrect)) {
            playExistedCard(target, ally, enemy, card);

            delete choosen;
            choosen = nullptr;
            return;
        }

        if (isOption(choosen, Buff)) {
            heal(target, ally, enemy, card);
            strengthen(target, 3, ally, enemy, card);

            delete choosen;
            choosen = nullptr;
            return;
        }

        assert(false);
    };
    return card;
}


Card *Cards::createShupesDayOff()
{
    auto *card = new Card();
    card->_constructor = std::bind(&Cards::createShupesDayOff, this);

    card->id = "201627";
    card->isSpecial = true;
    card->rarity = Gold;
    card->faction = Neutral;
    card->tags = { Organic };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        if (!hasNoDuplicates(ally.deckStarting))
            return;

        startChoiceToSelectOption(ally, enemy, card, {createShupeKnight(), createShupeHunter(), createShupeMage()});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}


Card *Cards::createShupeHunter()
{
    auto *card = new Card();
    card->_constructor = std::bind(&Cards::createShupeHunter, this);

    card->id = "201731";
    card->power = card->powerBase = 8;
    card->isDoomed = true;
    card->rarity = Gold;
    card->faction = Neutral;
    card->tags = { Ogroid };
    card->state = new StateChoosen();

    enum { Play, Shot, Replay, Clear, Barrage };
    card->_onDeploy = [=](Field &ally, Field &enemy) {
        auto *option1 = createOption(card, Play);
        option1->text = "Play a Bronze or Silver unit from Deck.";

        auto *option2 = createOption(card, Shot);
        option2->text = "Deal 15 damage.";

        auto *option3 = createOption(card, Replay);
        option3->text = "Replay a Bronze or Silver unit and Boost it by 5.";

        auto *option4 = createOption(card, Clear);
        option4->text = "Clear all Hazards from your side and Boost allies by 1.";

        auto *option5 = createOption(card, Barrage);
        option5->text = "Deal 2 damage to a random enemy. Repeat 8 times.";

        card->stateAs<StateChoosen>()->_choosen = nullptr;
        startChoiceToSelectOption(ally, enemy, card, {option1, option2, option3, option4, option5}, 1, 3);
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (isOption(target, Play)) {
            card->stateAs<StateChoosen>()->_choosen = target;
            startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, isUnit}, AllyDeck);
            return;
        }

        if (isOption(target, Shot)) {
            card->stateAs<StateChoosen>()->_choosen = target;
            startChoiceToTargetCard(ally, enemy, card);
            return;
        }

        if (isOption(target, Replay)) {
            card->stateAs<StateChoosen>()->_choosen = target;
            startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, isUnit}, AllyBoard);
            return;
        }

        if (isOption(target, Clear)) {
            for (Card *card : cardsFiltered(ally, enemy, {}, AllyBoard))
                boost(card, 1, ally, enemy, card);
            clearAllHazards(ally);
            return;
        }

        if (isOption(target, Barrage)) {
            for (int n = 0; n < 8; ++n)
                if (Card *card = random(cardsFiltered(ally, enemy, {}, EnemyBoard), ally.rng)) {
                    damage(card, 2, ally, enemy, card);
                }
            return;
        }

        assert(false);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        Card *choosen = card->stateAs<StateChoosen>()->_choosen;
        assert(choosen);

        if (isOption(choosen, Play)) {
            playExistedCard(target, ally, enemy, card);
            delete choosen;
            choosen = nullptr;
            return;
        }

        if (isOption(choosen, Shot)) {
            damage(target, 15, ally, enemy, card);
            delete choosen;
            choosen = nullptr;
            return;
        }

        if (isOption(choosen, Replay)) {
            putToHand(target, ally, enemy,  card);
            boost(target, 5, ally, enemy, card);
            playExistedCard(target, ally, enemy, card);
            delete choosen;
            choosen = nullptr;
            return;
        }

        assert(false);
    };
    return card;
}


Card *Cards::createShupeMage()
{
    auto *card = new Card();
    card->_constructor = std::bind(&Cards::createShupeMage, this);

    card->id = "201725";
    card->power = card->powerBase = 4;
    card->isDoomed = true;
    card->rarity = Gold;
    card->faction = Neutral;
    card->tags = { Ogroid };
    card->state = new StateChoosen();

    enum { Draw, Charm, Hazards, Meteor, Play };
    card->_onDeploy = [=](Field &ally, Field &enemy) {
        auto *option1 = createOption(card, Draw);
        option1->text = "Draw a card.";

        auto *option2 = createOption(card, Charm);
        option2->text = "Charm a random enemy.";

        auto *option3 = createOption(card, Hazards);
        option3->text = "Spawn a random Hazard on each enemy row.";

        auto *option4 = createOption(card, Meteor);
        option4->text = "Deal 10 damage to an enemy and 5 damage to each adjacent enemy.";

        auto *option5 = createOption(card, Play);
        option5->text = "Play a Bronze or Silver special card from your deck.";

        card->stateAs<StateChoosen>()->_choosen = nullptr;
        startChoiceToSelectOption(ally, enemy, card, {option1, option2, option3, option4, option5}, 1, 3);
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (isOption(target, Draw)) {
            drawACard(ally, enemy,  card);
            return;
        }

        if (isOption(target, Charm)) {
            if (Card *card = random(cardsFiltered(ally, enemy, {}, EnemyBoard), ally.rng))
                charm(card, ally, enemy, card);
            return;
        }

        if (isOption(target, Hazards)) {
            for (int screenRow = 3; screenRow < 6; ++screenRow)
                applyRowEffect(ally, enemy, screenRow, randomHazardEffect(ally.rng));
            return;
        }

        if (isOption(target, Meteor)) {
            card->stateAs<StateChoosen>()->_choosen = target;
            startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
            return;
        }

        if (isOption(target, Play)) {
            card->stateAs<StateChoosen>()->_choosen = target;
            startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, ::isSpecial}, AllyDeckShuffled);
            return;
        }

        assert(false);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        Card *choosen = card->stateAs<StateChoosen>()->_choosen;
        assert(choosen);

        if (isOption(choosen, Meteor)) {
            Card *left = cardNextTo(target, ally, enemy, -1);
            Card *right = cardNextTo(target, ally, enemy, 1);

            damage(target, 10, ally, enemy, card);
            if (left != nullptr) {
                damage(left, 5, ally, enemy, card);
            }
            if (right != nullptr) {
                damage(right, 5, ally, enemy, card);
            }

            delete choosen;
            choosen = nullptr;
            return;
        }

        if (isOption(choosen, Play)) {
            playExistedCard(target, ally, enemy, card);

            delete choosen;
            choosen = nullptr;
            return;
        }

        assert(false);
    };
    return card;
}


Card *Cards::createShupeKnight()
{
    auto *card = new Card();
    card->_constructor = std::bind(&Cards::createShupeKnight, this);

    card->id = "201737";
    card->power = card->powerBase = 12;
    card->isDoomed = true;
    card->rarity = Gold;
    card->faction = Neutral;
    card->tags = { Ogroid };
    card->state = new StateChoosen();

    enum { Destroy, Reset, Duel, Strengthen, Resilient };
    card->_onDeploy = [=](Field &ally, Field &enemy) {
        auto *option1 = createOption(card, Destroy);
        option1->text = "Destroy enemies with 4 or less power.";

        auto *option2 = createOption(card, Reset);
        option2->text = "Reset a unit.";

        auto *option3 = createOption(card, Duel);
        option3->text = "Duel an enemy.";

        auto *option4 = createOption(card, Strengthen);
        option4->text = "Strengthen self to 25.";

        auto *option5 = createOption(card, Resilient);
        option5->text = "Resilent.";

        card->stateAs<StateChoosen>()->_choosen = nullptr;
        startChoiceToSelectOption(ally, enemy, card, {option1, option2, option3, option4, option5}, 1, 3);
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (isOption(target, Destroy)) {
            for (Card *card : cardsFiltered(ally, enemy, {hasPowerXorLess(4)}, EnemyBoard))
                putToDiscard(card, ally, enemy, card);
            return;
        }

        if (isOption(target, Reset)) {
            card->stateAs<StateChoosen>()->_choosen = target;
            startChoiceToTargetCard(ally, enemy, card);
            return;
        }

        if (isOption(target, Duel)) {
            card->stateAs<StateChoosen>()->_choosen = target;
            startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
            return;
        }

        if (isOption(target, Strengthen)) {
            strengthen(card, 25 - card->powerBase, ally, enemy, card);
            return;
        }

        if (isOption(target, Resilient)) {
            card->isResilient = true;
            return;
        }

        assert(false);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        Card *choosen = card->stateAs<StateChoosen>()->_choosen;
        assert(choosen);

        if (isOption(choosen, Reset)) {
            //target->power = target->powerBase;
            reset(target, ally, enemy, card);
            delete choosen;
            choosen = nullptr;
            return;
        }

        if (isOption(choosen, Duel)) {
            duel(card, target, ally, enemy);
            delete choosen;
            choosen = nullptr;
            return;
        }

        assert(false);
    };
    return card;
}


//Card *Cards::createDecoy()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "113201";
//    card->isSpecial = true;
//    card->rarity = Silver;
//    card->faction = Neutral;
//    card->tags = { Tactics };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, { isBronzeOrSilver }, AllyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        putToHand(target, ally, enemy,  card);
//        boost(target, 3, ally, enemy, card);
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createFirstLight()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "113303";
//    card->isSpecial = true;
//    card->rarity = Bronze;
//    card->faction = Neutral;
//    card->tags = { Tactics };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        auto *option1 = createOption(card, Clear);
//        option1->text = "Boost all damaged allies under Hazards by 2 and clear all Hazards from your side.";

//        auto *option2 = createOption(card, Play);
//        option2->text = "Play a random Bronze unit from your deck.";

//        startChoiceToSelectOption(ally, enemy, card, {option1, option2});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (isOption(target, Clear)) {
//            std::vector<Card *> damagedUnitsUnderHazards;
//            clearAllHazards(ally, &damagedUnitsUnderHazards);
//            for (Card *card : damagedUnitsUnderHazards)
//                boost(card, 2, ally, enemy, card);
//            delete target;
//            return;
//        }

//        if (isOption(target, Play)) {
//            if (Card *card = random(cardsFiltered(ally, enemy, { isBronze, isUnit }, AllyDeck), ally.rng))
//                playExistedCard(card, ally, enemy, card);
//            delete target;
//            return;
//        }

//        assert(false);
//    };
//    return card;
//}


//Card *Cards::createClearSkies()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "113303";
//    card->isSpecial = true;
//    card->rarity = Bronze;
//    card->faction = Neutral;
//    card->tags = { Tactics };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        std::vector<Card *> damagedUnitsUnderHazards;
//        clearAllHazards(ally, &damagedUnitsUnderHazards);
//        for (Card *card : damagedUnitsUnderHazards)
//            boost(card, 2, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createEpidemic()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "113308";
//    card->isSpecial = true;
//    card->rarity = Bronze;
//    card->faction = Neutral;
//    card->tags = { Organic, Spell };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        for (Card *card : lowests(cardsFiltered(ally, enemy, {}, AnyBoard)))
//            putToDiscard(card, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createMoonlight()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200067";
//    card->isSpecial = true;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Hazard, Boon };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        auto *option1 = createOption(card, FullMoon);
//        option1->name = "Full Moon";
//        option1->text = "Apply a Boon to an allied row that boosts a random Beast or Vampire by 2 on turn start.";

//        auto *option2 = createOption(card, BloodMoon);
//        option2->name = "Blood Moon";
//        option2->text = "Apply a Hazard to an enemy row that deals 2 damage to all units on contact.";

//        startChoiceToSelectOption(ally, enemy, card, {option1, option2});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (isOption(target, FullMoon)) {
//            startChoiceToSelectRow(ally, enemy, card, {0, 1, 2});
//            delete target;
//            return;
//        }

//        if (isOption(target, BloodMoon)) {
//            startChoiceToSelectRow(ally, enemy, card, {3, 4, 5});
//            delete target;
//            return;
//        }

//        assert(false);
//    };

//    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
//        applyRowEffect(ally, enemy, screenRow, screenRow < 3 ? FullMoonEffect : BloodMoonEffect);
//    };
//    return card;
//}


//Card *Cards::createCiriNova()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201626";
//    card->power = card->powerBase = 1;
//    card->isDoomed = true;
//    card->rarity = Gold;
//    card->faction = Neutral;
//    card->tags = { Cintra, Witcher };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (!hasExactTwoDuplicatesOfBronze(ally.deckStarting))
//            return;

//        strengthen(card, 22 - powerBase, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createHaraldTheCripple()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200161";
//    card->power = card->powerBase = 6;
//    card->rarity = Gold;
//    card->faction = Skellige;
//    card->tags = { ClanAnCraite, Leader };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        Row row;
//        Pos pos;
//        if (!_findRowAndPos(card, ally, row, pos))
//            return;
//        for (int n = 0; n < 9; ++n)
//            if (Card *card = random(enemy.row(row), ally.rng))
//                damage(card, 1, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createEmissary()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162314";
//    card->isLoyal = false;
//    card->power = card->powerBase = 2;
//    card->rarity = Bronze;
//    card->faction = Nilfgaard;
//    card->tags = { };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, randoms(cardsFiltered(ally, enemy, {isBronze, isUnit}, AllyDeckShuffled), 2, ally.rng));
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createCeallachDyffryn()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162213";
//    card->power = card->powerBase = 2;
//    card->rarity = Silver;
//    card->faction = Nilfgaard;
//    card->tags = { Officer };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectOption(ally, enemy, card, {new Ambassador(), new Assassin(), new Emissary()});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        spawnNewCard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createRestore()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "153201";
//    card->isSpecial = true;
//    card->rarity = Silver;
//    card->faction = Skellige;
//    card->tags = { Spell };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, isUnit, isSkelligeFaction}, AllyDiscard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        putToHand(target, ally, enemy,  card);
//        target->isDoomed = true;
//        target->powerBase = target->power = 8;
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createDrummondQueensguard()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152307";
//    card->power = card->powerBase = 4;
//    card->rarity = Bronze;
//    card->faction = Skellige;
//    card->tags = { ClanDrummond, Soldier };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        for (Card *card : cardsFiltered(ally, enemy, {isCopy<DrummondQueensguard>}, AllyDiscard))
//            moveExistedUnitToPos(card, rowAndPosToTheRight(card, ally, 1), ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createBranTuirseach()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200159";
//    card->power = card->powerBase = 2;
//    card->rarity = Gold;
//    card->faction = Skellige;
//    card->tags = { ClanTuirseach, Leader };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AllyDeckShuffled, 3, true);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        putToDiscard(target, ally, enemy, card);
//        if (!target->isSpecial)
//            strengthen(target, 1, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createDrummondWarmonger()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200036";
//    card->power = card->powerBase = 8;
//    card->rarity = Bronze;
//    card->faction = Skellige;
//    card->tags = { ClanDrummond, Soldier };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronze}, AllyDeckShuffled);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        putToDiscard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createDimunPirate()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152305";
//    card->power = card->powerBase = 11;
//    card->rarity = Bronze;
//    card->faction = Skellige;
//    card->tags = { ClanDimun, Soldier };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        for (Card *card : cardsFiltered(ally, enemy, {isCopy<DimunPirate>}, AllyDeck))
//            putToDiscard(card, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createAnCraiteRaider()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152316";
//    card->power = card->powerBase = 4;
//    card->rarity = Bronze;
//    card->faction = Skellige;
//    card->tags = { ClanAnCraite, Soldier };

//    card->_onDiscard = [=](Field &ally, Field &enemy) {
//        moveExistedUnitToPos(card, rowAndPosRandom(ally), ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createMadmanLugos()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152106";
//    card->power = card->powerBase = 6;
//    card->rarity = Gold;
//    card->faction = Skellige;
//    card->tags = { ClanDrummond, Officer };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronze, isUnit}, AllyDeckShuffled);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (_discarded == nullptr) {
//            _discarded = target;
//            putToDiscard(target, ally, enemy, card);
//            startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//            return;
//        }
//        damage(target, _discarded->powerBase, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createErmion()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152103";
//    card->power = card->powerBase = 10;
//    card->rarity = Gold;
//    card->faction = Skellige;
//    card->tags = { ClanAnCraite, Support };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        drawACard(ally, enemy,  card);
//        drawACard(ally, enemy,  card);
//        startChoiceToTargetCard(ally, enemy, card, {}, AllyHand, 2);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        putToDiscard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createCerysFearless()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201778";
//    card->power = card->powerBase = 6;
//    card->rarity = Gold;
//    card->faction = Skellige;
//    card->tags = { ClanAnCraite, Officer };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        setTimer(card, ally, enemy, 1);
//    };

//    card->_onOtherAllyDiscarded = [=](Card *other, Field &ally, Field &enemy) {
//        if (other->isSpecial || !isOnBoard(card, ally))
//            return;

//        if (tick(card, ally, enemy))
//            playExistedCard(other, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createCerysAnCraite()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200177";
//    card->power = card->powerBase = 6;
//    card->rarity = Gold;
//    card->faction = Skellige;
//    card->tags = { ClanAnCraite, Officer };

//    card->_onDiscard = [=](Field &ally, Field &enemy) {
//        setTimer(card, ally, enemy, 4);
//    };

//    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
//        setTimer(card, ally, enemy, 4);
//    };

//    card->_onOtherAllyResurrecteded = [=](Card *, Field &ally, Field &enemy) {
//        if (!isIn(card, ally.discard))
//            return;

//        if (tick(card, ally, enemy))
//            moveExistedUnitToPos(card, rowAndPosRandom(ally), ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createWoodlandSpirit()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132103";
//    card->power = card->powerBase = 5;
//    card->rarity = Gold;
//    card->faction = Monster;
//    card->tags = { Relict };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        Row row;
//        Pos pos;
//        if (!_findRowAndPos(card, ally, row, pos))
//            return;
//        applyRowEffect(ally, enemy, 3 + row, ImpenetrableFogEffect);
//        for (int n = 0; n < 3; ++n)
//            spawnNewUnitToPos(createWolf(), rowAndPosLastInExactRow(ally, Meele), ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createTrollololo()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "122209";
//    card->power = card->powerBase = 11;
//    card->rarity = Silver;
//    card->faction = NothernRealms;
//    card->tags = { Redania, Ogroid };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        gainArmor(card, 9, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createPrinceStennis()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "122208";
//    card->power = card->powerBase = 3;
//    card->rarity = Silver;
//    card->faction = NothernRealms;
//    card->tags = { Aedirn, Officer };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        gainArmor(card, 3, ally, enemy, card);
//        const std::vector<Card *> cards = cardsFiltered(ally, enemy, {isNonSpying, isBronzeOrSilver, isUnit}, AllyDeck);
//        if (cards.size() == 0)
//            return;

//        Card *target = cards.front();
//        playExistedCard(target, ally, enemy, card);
//        gainArmor(target, 5, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createVincentMeis()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200098";
//    card->power = card->powerBase = 9;
//    card->rarity = Silver;
//    card->faction = NothernRealms;
//    card->tags = { Beast, Cursed };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        int _armor = 0;
//        for (Card *target: cardsFiltered(ally, enemy, {hasArmor}, AnyBoard)) {
//            const int armorTarget = target->armor;
//            damage(target, armorTarget, ally, enemy, card);
//            _armor += armorTarget;
//        }
//        if (_armor)
//            boost(card, _armor / 2, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createMorkvarg()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    // BUG: isn't carry over...
//    // Add a onPutOnDiscard for Morkvarg and golden spell which strikes after 3 turns
//    card->id = "152209";
//    card->power = card->powerBase = 9;
//    card->rarity = Silver;
//    card->faction = Skellige;
//    card->tags = { Beast, Cursed };

//    card->_onDiscard = [=](Field &ally, Field &enemy) {
//        if (!weaken(card, half(card->powerBase), ally, enemy, card))
//            moveExistedUnitToPos(card, rowAndPosRandom(ally), ally, enemy, card);
//    };

//    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &rowAndPos) {
//        if (!weaken(card, half(card->powerBase), ally, enemy, card))
//            moveExistedUnitToPos(card, rowAndPos, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createArtefactCompression()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200053";
//    card->isSpecial = true;
//    card->rarity = Silver;
//    card->faction = Neutral;
//    card->tags = { Spell };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver});
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        transform(target, JadeFigurine(), ally, enemy, card);
//    };
//    return card;
//}


//ArtefactCompression::JadeFigurine::JadeFigurine()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200053";
//    card->isDoomed = true;
//    card->power = card->powerBase = 2;
//    card->rarity = Bronze;
//    card->faction = Neutral;
//    card->tags = {};
//    return card;
//}

//HjalmarAnCraite::LordOfUndvik::LordOfUndvik()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->isLoyal = false;
//    card->isDoomed = true;
//    card->power = card->powerBase = 5;
//    card->rarity = Silver;
//    card->faction = Skellige;
//    card->tags = { Ogroid };

//    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
//        for (Card *card : cardsFiltered(ally, enemy, {isCopy<HjalmarAnCraite>}, EnemyBoard))
//            boost(card, 10, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createHjalmarAnCraite()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152101";
//    card->power = card->powerBase = 16;
//    card->rarity = Gold;
//    card->faction = Skellige;
//    card->tags = { ClanAnCraite, Officer };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        spawnNewUnitToPos(new LordOfUndvik(), rowAndPosLastInExactRow(enemy, _findRowAndPos(card, ally).row()), enemy, ally, card);
//    };
//    return card;
//}


//Card *Cards::createRegis()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112104";
//    card->power = card->powerBase = 1;
//    card->rarity = Gold;
//    card->faction = Neutral;
//    card->tags = { Vampire };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBoosted}, AnyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        const int x = target->power - target->powerBase;
//        drain(target, x, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createLethoOfGulet()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162101";
//    card->isLoyal = false;
//    card->power = card->powerBase = 1;
//    card->rarity = Gold;
//    card->faction = Nilfgaard;
//    card->tags = { Witcher };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isOnSameRow(&enemy, card)}, EnemyBoard, 2);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        lock(target, ally, enemy, card);
//        drain(target, target->power, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createAnCraiteLongship()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152314";
//    card->power = card->powerBase = 7;
//    card->rarity = Bronze;
//    card->faction = Skellige;
//    card->tags = { ClanAnCraite, Machine };

//    const auto onDeploy = [=](Field &ally, Field &enemy) {
//        if (Card *card = random(cardsFiltered(ally, enemy, {}, EnemyBoard), ally.rng))
//            damage(card, 2, ally, enemy, card);
//    };

//    card->_onDeploy = onDeploy;

//    card->_onOtherAllyDiscarded = [=](Card *, Field &ally, Field &enemy) {
//        if (isOnBoard(card, ally))
//            onDeploy(ally, enemy);
//    };
//    return card;
//}


//Card *Cards::createTuirseachVeteran()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200046";
//    card->power = card->powerBase = 7;
//    card->rarity = Bronze;
//    card->faction = Skellige;
//    card->tags = { ClanTuirseach, Support };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        for (Card *card : cardsFiltered(ally, enemy, {hasTag(ClanTuirseach), otherThan(card)}, AllyBoardHandDeck))
//            strengthen(card, 1, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createTuirseachHunter()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152304";
//    card->power = card->powerBase = 6;
//    card->rarity = Bronze;
//    card->faction = Skellige;
//    card->tags = { ClanTuirseach, Soldier };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        damage(target, 5, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createUdalryk()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152214";
//    card->power = card->powerBase = 13;
//    card->isLoyal = false;
//    card->timer = 1;
//    card->rarity = Silver;
//    card->faction = Skellige;
//    card->tags = { ClanBrokvar, Cursed, Agent };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (tick(card, ally, enemy))
//            startChoiceToTargetCard(ally, enemy, card, _drawn = randoms(cardsFiltered(ally, enemy, {}, AllyDeck), 2, ally.rng));
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        putToHand(target, ally, enemy,  card);
//        for (Card *card : _drawn)
//            if (card != target)
//                putToDiscard(card, ally, enemy, card);

//        _drawn.clear();
//    };
//    return card;
//}


//Card *Cards::createBloodcurdlingRoar()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152406";
//    card->isSpecial = true;
//    card->rarity = Bronze;
//    card->faction = Neutral;
//    card->tags = { Organic };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AllyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        putToDiscard(target, ally, enemy, card);
//        spawnNewCard(createBear(), ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createGremist()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152206";
//    card->power = card->powerBase = 4;
//    card->rarity = Silver;
//    card->faction = Skellige;
//    card->tags = { Support };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectOption(ally, enemy, card, {createTorrentialRain(), createClearSkies(), createBloodcurdlingRoar()});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        spawnNewCard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createOperator()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112208";
//    card->power = card->powerBase = 5;
//    card->timer = 1;
//    card->rarity = Silver;
//    card->faction = Neutral;
//    card->tags = { Mage };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (ally.passed || enemy.passed)
//            return;
//        if (tick(card, ally, enemy))
//            startChoiceToTargetCard(ally, enemy, card, {isBronze, isUnit}, AllyHand);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        Card *copyAlly = target->defaultCopy();
//        ally.cardsAdded.push_back(copyAlly);
//        putToHand(copyAlly, ally, enemy,  card);

//        Card *copyEnemy = target->defaultCopy();
//        enemy.cardsAdded.push_back(copyEnemy);
//        putToHand(copyEnemy, enemy, ally,  card);
//    };
//    return card;
//}


//Card *Cards::createZoriaRunestone()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201582";
//    card->isSpecial = true;
//    card->rarity = Silver;
//    card->faction = NothernRealms;
//    card->tags = { Alchemy, Item };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceCreateOptions(ally, enemy, card, {isBronzeOrSilver, isNothernRealmsFaction});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        spawnNewCard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createRenew()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "113316";
//    card->isSpecial = true;
//    card->rarity = Gold;
//    card->faction = Neutral;
//    card->tags = { Spell };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceCreateOptions(ally, enemy, card, {isGold, isNonLeader}, AllyDiscard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createEistTuirseach()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201597";
//    card->power = card->powerBase = 5;
//    card->rarity = Gold;
//    card->faction = Skellige;
//    card->tags = { ClanTuirseach, Leader };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectOption(ally, enemy, card, {new TuirseachArcher, new TuirseachAxeman, new TuirseachBearmaster, new TuirseachHunter, new TuirseachSkirmisher});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        spawnNewCard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createTuirseachAxeman()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152312";
//    card->power = card->powerBase = 6;
//    card->rarity = Bronze;
//    card->faction = Skellige;
//    card->tags = { ClanTuirseach, Soldier };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        gainArmor(card, 2, ally, enemy, card);
//    };

//    card->_onOtherEnemyDamaged = [=](Card *other, Field &ally, Field &enemy) {
//        Pos _;
//        Row row;
//        if (!_findRowAndPos(other, enemy, row, _))
//            return;
//        if (isIn(card, ally.row(row)))
//            boost(card, 1, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createTuirseachSkirmisher()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152313";
//    card->power = card->powerBase = 8;
//    card->rarity = Bronze;
//    card->faction = Skellige;
//    card->tags = { ClanTuirseach, Soldier };

//    card->_onDeployFromDiscard = [=](Field &ally, Field &enemy) {
//        strengthen(card, 3, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createDerran()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201646";
//    card->power = card->powerBase = 6;
//    card->rarity = Silver;
//    card->faction = Skellige;
//    card->tags = { ClanTuirseach, Cursed };

//    card->_onOtherEnemyDamaged = [=](Card *, Field &ally, Field &enemy) {
//        if (isOnBoard(card, ally))
//            boost(card, 1, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createRoach()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112210";
//    card->power = card->powerBase = 4;
//    card->rarity = Silver;
//    card->faction = Neutral;
//    card->tags = { Beast };

//    card->_onOtherAllyPlayedFromHand = [=](Card *other, Field &ally, Field &enemy) {
//        if (other->rarity != Gold)
//            return;

//        if (!isIn(card, ally.deck))
//            return;

//        moveExistedUnitToPos(card, rowAndPosRandom(ally), ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createJanCalveit()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200164";
//    card->power = card->powerBase = 5;
//    card->rarity = Gold;
//    card->faction = Nilfgaard;
//    card->tags = { Officer, Leader };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        const std::vector<Card *> topThreeCards(ally.deck.begin(), ally.deck.begin() + std::min(int(ally.deck.size()), 3));
//        startChoiceToTargetCard(ally, enemy, card, topThreeCards);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createCahirDyffryn()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162104";
//    card->power = card->powerBase = 1;
//    card->isDoomed = true;
//    card->rarity = Gold;
//    card->faction = Nilfgaard;
//    card->tags = { Officer };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {hasTag(Leader)}, AllyDiscard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createLethoKingslayer()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201603";
//    card->power = card->powerBase = 5;
//    card->rarity = Gold;
//    card->faction = Nilfgaard;
//    card->tags = { Witcher };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        auto *option1 = createOption(card, Destroy);
//        option1->text = "Destroy an enemy Leader, then boost self by 5.";

//        auto *option2 = createOption(card, Play);
//        option2->text = "Play a Bronze or Silver Tactic from your deck.";

//        _choosen = nullptr;
//        startChoiceToSelectOption(ally, enemy, card, {option1, option2});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        _choosen = target;

//        if (isOption(_choosen, Destroy))
//            return startChoiceToTargetCard(ally, enemy, card, {hasTag(Leader)}, EnemyBoard);

//        if (isOption(_choosen, Play))
//            return startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, hasTag(Tactics)}, AllyDeckShuffled);

//        assert(false);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        assert(_choosen);

//        if (isOption(_choosen, Destroy)) {
//            putToDiscard(target, ally, enemy, card);
//            boost(card, 5, ally, enemy, card);

//            delete _choosen;
//            _choosen = nullptr;
//            return;
//        }

//        if (isOption(_choosen, Play)) {
//            playExistedCard(target, ally, enemy, card);

//            delete _choosen;
//            _choosen = nullptr;
//            return;
//        }

//        assert(false);
//    };
//    return card;
//}


//Card *Cards::createKingHenselt()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200170";
//    card->power = card->powerBase = 3;
//    card->rarity = Gold;
//    card->isCrew = true;
//    card->faction = NothernRealms;
//    card->tags = { Kaedwen, Leader };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronze, hasAnyOfTags({Machine, Kaedwen})}, AllyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        for (Card *copy : findCopies(target, ally.deck))
//            playExistedCard(copy, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createBloodyBaron()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "122101";
//    card->power = card->powerBase = 9;
//    card->rarity = Gold;
//    card->faction = NothernRealms;
//    card->tags = { Temeria, Officer };

//    card->_onOtherEnemyDestroyed = [=](Card *, Field &ally, Field &enemy) {
//        if (isOnBoard(card, ally) || isIn(card, ally.deck) || isIn(card, ally.hand))
//            boost(card, 1, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createDethmold()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "122207";
//    card->power = card->powerBase = 4;
//    card->rarity = Silver;
//    card->faction = NothernRealms;
//    card->tags = { Kaedwen, Mage };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectOption(ally, enemy, card, {new TorrentialRain(), new ClearSkies(), new AlzursThunder()});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        spawnNewCard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createRonvidTheIncessant()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200529";
//    card->power = card->powerBase = 11;
//    card->rarity = Silver;
//    card->faction = NothernRealms;
//    card->tags = { Kaedwen, Soldier };
//    card->isCrew = true;

//    card->_onTurnEnd = [=](Field &ally, Field &enemy) {
//        if (!isIn(card, ally.discard))
//            return;
//        moveExistedUnitToPos(card, rowAndPosRandom(ally), ally, enemy, card);
//        if (powerBase > 1)
//            weaken(card, powerBase - 1, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createHubertRejk()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200088";
//    card->power = card->powerBase = 7;
//    card->rarity = Silver;
//    card->faction = NothernRealms;
//    card->tags = { Vampire };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        for (Card *card : cardsFiltered(ally, enemy, {isBoosted}, AllyDeck))
//            drain(card, card->power - card->powerBase, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createCrachAnCraite()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200160";
//    card->power = card->powerBase = 5;
//    card->faction = Skellige;
//    card->rarity = Gold;
//    card->tags = { ClanAnCraite, Leader };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (Card *card = highest(cardsFiltered(ally, enemy, {isUnit, isBronzeOrSilver, isNonSpying}, AllyDeck), ally.rng)) {
//            strengthen(card, 2, ally, enemy, card);
//            playExistedCard(card, ally, enemy, card);
//        }
//    };
//    return card;
//}


//Card *Cards::createBirnaBran()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152105";
//    card->power = card->powerBase = 6;
//    card->faction = Skellige;
//    card->rarity = Gold;
//    card->tags = { ClanTuirseach, Officer };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectRow(ally, enemy, card, {3, 4, 5});
//    };

//    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
//        applyRowEffect(ally, enemy, screenRow, SkelligeStormEffect);
//    };
//    return card;
//}


//Card *Cards::createCoral()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152107";
//    card->power = card->powerBase = 5;
//    card->faction = Skellige;
//    card->rarity = Gold;
//    card->tags = { Mage };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, isUnit}, AnyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        transform(target, ArtefactCompression::JadeFigurine(), ally, enemy, card);
//    };
//    return card;
//}


//Kambi::Hemdall::Hemdall()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152402";
//    card->isDoomed = true;
//    card->power = card->powerBase = 20;
//    card->faction = Skellige;
//    card->rarity = Gold;
//    card->tags = {};

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        for (int screenRow = 0; screenRow < 6; ++screenRow)
//            applyRowEffect(ally, enemy, screenRow, NoRowEffect);
//        for (Card *card : cardsFiltered(ally, enemy, {}, AnyBoard))
//            putToDiscard(card, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createVabjorn()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200028";
//    card->power = card->powerBase = 11;
//    card->faction = Skellige;
//    card->rarity = Gold;
//    card->tags = { Cursed, Cultist };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (isDamaged(target))
//            putToDiscard(target, ally, enemy, card);
//        else
//            damage(target, 2, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createBlueboyLugos()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152201";
//    card->power = card->powerBase = 9;
//    card->faction = Skellige;
//    card->rarity = Silver;
//    card->tags = { ClanDrummond, Soldier };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        spawnNewCard(new SpectralWhale(), ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createDjengeFrett()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152203";
//    card->power = card->powerBase = 10;
//    card->faction = Skellige;
//    card->rarity = Silver;
//    card->tags = { Soldier, ClanDimun };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AllyBoard, 2);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        damage(target, 1, ally, enemy, card);
//        strengthen(card, 2, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createDonarAnHindar()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152204";
//    card->power = card->powerBase = 8;
//    card->faction = Skellige;
//    card->rarity = Silver;
//    card->tags = { ClanHeymaey, Officer };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronze, isUnit}, EnemyDiscard);
//        startChoiceToTargetCard(ally, enemy, card);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (!isIn(target, enemy.discard)) {
//            toggleLock(target, ally, enemy, card);
//            return;
//        }
//        // FIXME: discard moving will crash
//        putToDiscard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createDraigBonDhu()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152205";
//    card->power = card->powerBase = 6;
//    card->faction = Skellige;
//    card->rarity = Silver;
//    card->tags = { Support };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isNonLeader, isUnit}, AllyDiscard, 2);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        strengthen(target, 3, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createHolgerBlackhand()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152207";
//    card->power = card->powerBase = 6;
//    card->faction = Skellige;
//    card->rarity = Silver;
//    card->tags = { ClanDimun, Officer };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (damage(target, 6, ally, enemy, card))
//            if (Card *card = highest(ally.discard, ally.rng))
//                strengthen(card, 3, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createJuttaAnDimun()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152208";
//    card->power = card->powerBase = 13;
//    card->faction = Skellige;
//    card->rarity = Silver;
//    card->tags = { ClanDimun, Soldier };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        damage(card, 1, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createSavageBear()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152210";
//    card->power = card->powerBase = 9;
//    card->faction = Skellige;
//    card->rarity = Bronze;
//    card->tags = { Beast, Cursed };

//    card->_onOtherEnemyPlayedFromHand = [=](Card *other, Field &ally, Field &enemy) {
//        if (isOnBoard(card, ally))
//            damage(other, 1, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createSvanrigeTuirseach()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152213";
//    card->power = card->powerBase = 9;
//    card->faction = Skellige;
//    card->rarity = Silver;
//    card->tags = { ClanTuirseach, Officer };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (drawACard(ally, enemy,  card))
//            startChoiceToTargetCard(ally, enemy, card, {}, AllyHand);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        putToDiscard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createSkjall()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200212";
//    card->power = card->powerBase = 5;
//    card->faction = Skellige;
//    card->rarity = Silver;
//    card->tags = { ClanHeymaey, Cursed };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (Card *card = random(cardsFiltered(ally, enemy, {isUnit, isBronzeOrSilver, hasTag(Cursed)}, AllyDeck), ally.rng))
//            playExistedCard(card, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createHaraldHoundsnout()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200043";
//    card->power = card->powerBase = 6;
//    card->faction = Skellige;
//    card->rarity = Silver;
//    card->tags = { ClanTordarroch, Cursed };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        spawnNewUnitToPos(new Wilfred(), rowAndPosToTheLeft(card, ally, 1), ally, enemy, card);
//        spawnNewUnitToPos(new Wilhelm(), rowAndPosToTheRight(card, ally, 1), ally, enemy, card);
//        spawnNewUnitToPos(new Wilmar(), rowAndPosLastInExactRow(enemy, _findRowAndPos(card, ally).row()), enemy, ally, card);
//    };
//    return card;
//}


//HaraldHoundsnout::Wilfred::Wilfred()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->power = card->powerBase = 1;
//    card->faction = Skellige;
//    card->rarity = Bronze;
//    card->isDoomed = true;

//    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &rowAndPos) {
//        for (Card *card : enemy.row(rowAndPos.row()))
//            damage(card, 1, ally, enemy, card);
//    };
//    return card;
//}


//HaraldHoundsnout::Wilhelm::Wilhelm()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->power = card->powerBase = 1;
//    card->faction = Skellige;
//    card->rarity = Bronze;
//    card->isDoomed = true;

//    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
//        if (Card *card = random(cardsFiltered(ally, enemy, {}, AllyBoard), ally.rng))
//            strengthen(card, 3, ally, enemy, card);
//    };
//    return card;
//}


//HaraldHoundsnout::Wilmar::Wilmar()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->power = card->powerBase = 1;
//    card->faction = Skellige;
//    card->rarity = Bronze;
//    card->isDoomed = true;

//    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
//        spawnNewUnitToPos(new Bear(), rowAndPosRandom(enemy), ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createYoana()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201644";
//    card->power = card->powerBase = 6;
//    card->faction = Skellige;
//    card->rarity = Silver;
//    card->tags = { ClanTordarroch, Support };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isUnit, isDamaged}, AllyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        const int x = target->powerBase - target->power;
//        heal(target, ally, enemy, card);
//        boost(target, x, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createAnCraiteBlacksmith()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152311";
//    card->power = card->powerBase = 9;
//    card->faction = Skellige;
//    card->rarity = Bronze;
//    card->tags = { ClanAnCraite, Support };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AllyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        strengthen(target, 2, ally, enemy, card);
//        gainArmor(target, 2, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createAnCraiteWarcrier()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "113313";
//    card->power = card->powerBase = 5;
//    card->faction = Skellige;
//    card->rarity = Bronze;
//    card->tags = { ClanAnCraite, Support};

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AllyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        boost(target, int(std::floor(target->power / 2.0)), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createAnCraiteWarrior()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152303";
//    card->power = card->powerBase = 12;
//    card->faction = Skellige;
//    card->rarity = Bronze;
//    card->tags = { ClanAnCraite, Soldier };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        damage(card, 1, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createBerserkerMarauder()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152302";
//    card->power = card->powerBase = 9;
//    card->faction = Skellige;
//    card->rarity = Bronze;
//    card->tags = { Cursed, Soldier, Cultist };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        const auto isDamagedOrCursed = [=](Card *card) {
//            return (card != card) && (isDamaged(card) || hasTag(card, Cursed));
//        };
//        const int nUnits = int(cardsFiltered(ally, enemy, {isDamagedOrCursed}, AllyBoard).size());
//        if (nUnits)
//            boost(card, nUnits, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createDimunPirateCaptain()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152306";
//    card->power = card->powerBase = 1;
//    card->faction = Skellige;
//    card->rarity = Bronze;
//    card->tags = { ClanDimun, Officer };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronze, otherThan(name), hasTag(ClanDimun)}, AllyDeckShuffled);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createDimunSmuggler()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200146";
//    card->power = card->powerBase = 10;
//    card->faction = Skellige;
//    card->rarity = Bronze;
//    card->tags = { ClanDimun, Soldier };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronze, isUnit}, AllyDiscard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        putToDeck(target, ally, enemy, DeckPosRandom, card);
//    };
//    return card;
//}

//Card *Cards::createDrummondShieldmaid()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152318";
//    card->power = card->powerBase = 3;
//    card->faction = Skellige;
//    card->rarity = Bronze;
//    card->tags = { ClanDrummond, Soldier };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        for (Card *copy : cardsFiltered(ally, enemy, {isCopy(card->name)}, AllyDeck))
//            moveExistedUnitToPos(copy, _findRowAndPos(card, ally), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createHeymaeyFlaminica()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200147";
//    card->power = card->powerBase = 10;
//    card->faction = Skellige;
//    card->rarity = Bronze;
//    card->tags = { ClanHeymaey, Support };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        clearHazardsFromItsRow(card, ally);
//        startChoiceToTargetCard(ally, enemy, card, {isOnAnotherRow(&ally, card)}, AllyBoard, 2);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        moveExistedUnitToPos(target, rowAndPosLastInTheSameRow(card, ally), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createHeymaeyHerbalist()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200081";
//    card->power = card->powerBase = 3;
//    card->faction = Skellige;
//    card->rarity = Bronze;
//    card->tags = { ClanHeymaey, Support };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (Card *target = random(cardsFiltered(ally, enemy, {isBronze, hasAnyOfTags({Organic, Hazard})}, AllyDeck), ally.rng))
//            playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createHeymaeyProtector()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200149";
//    card->power = card->powerBase = 2;
//    card->faction = Skellige;
//    card->rarity = Bronze;
//    card->tags = { ClanHeymaey, Soldier };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronze, hasTag(Item)}, AllyDeck);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createHeymaeySkald()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152308";
//    card->power = card->powerBase = 9;
//    card->faction = Skellige;
//    card->rarity = Bronze;
//    card->tags = { ClanHeymaey, Support };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {hasAnyOfTags({ClanAnCraite, ClanDimun, ClanDrummond, ClanHeymaey, ClanTuirseach, ClanBrokvar, ClanTordarroch})}, AllyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        for (const Tag tag : std::vector<Tag>{ClanAnCraite, ClanDimun, ClanDrummond, ClanHeymaey, ClanTuirseach, ClanBrokvar, ClanTordarroch}) {
//            if (!hasTag(target, tag))
//                continue;
//            for (Card *card : cardsFiltered(ally, enemy, {hasTag(tag), otherThan(card)}, AllyBoard))
//                boost(card, 1, ally, enemy, card);
//            break;
//        }
//    };
//    return card;
//}

//Card *Cards::createRagingBerserker()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152301";
//    card->power = card->powerBase = 8;
//    card->faction = Skellige;
//    card->rarity = Bronze;
//    card->tags = { Cursed, Soldier, Cultist };

//    card->_onDamaged = [=](const int, Field &ally, Field &enemy, const Card *) {
//        transform(card, RagingBear(), ally, enemy, card);
//    };

//    card->_onWeakened = [=](const int x, Field &ally, Field &enemy, const Card *src) {
//        onDamaged(x, ally, enemy, src);
//    };
//    return card;
//}

//RagingBerserker::RagingBear::RagingBear()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152405";
//    card->power = card->powerBase = 12;
//    card->faction = Skellige;
//    card->rarity = Bronze;
//    card->tags = { Cursed, Beast, Cultist };
//    return card;
//}

//Card *Cards::createHym()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200102";
//    card->power = card->powerBase = 3;
//    card->faction = Skellige;
//    card->rarity = Gold;
//    card->tags = { Cursed };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        auto *option1 = createOption(card, Play);
//        option1->text = "Play a Bronze or Silver Cursed unit from your deck.";

//        auto *option2 = createOption(card, Create);
//        option2->text = "Create a Silver unit from your opponent's starting deck.";

//        _choosen = nullptr;
//        startChoiceToSelectOption(ally, enemy, card, {option1, option2});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {

//        if (!_choosen && isOption(target, Play)) {
//            _choosen = target;
//            return startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, hasTag(Cursed)}, AllyDeckShuffled);
//        }

//        if (!_choosen && isOption(target, Create)) {
//            _choosen = target;
//            return startChoiceCreateOptions(ally, enemy, card, {isSilver, isUnit, isNonAgent}, EnemyDeckStarting);
//        }

//        if (isOption(_choosen, Create)) {
//            spawnNewCard(target, ally, enemy, card);
//            delete _choosen;
//            _choosen = nullptr;
//            return;
//        }

//        assert(false);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        assert(isOption(_choosen, Play));

//        playExistedCard(target, ally, enemy, card);
//        delete _choosen;
//        _choosen = nullptr;
//    };
//    return card;
//}

//Card *Cards::createKambi()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152104";
//    card->isLoyal = false;
//    card->power = card->powerBase = 1;
//    card->faction = Skellige;
//    card->rarity = Gold;
//    card->tags = { };

//    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
//        spawnNewUnitToPos(new Hemdall(), rowAndPosRandom(ally), ally, enemy, card);
//        // TODO: Check if Hemdall doesn't wipe a board!
//    };
//    return card;
//}

//Card *Cards::createOlaf()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200103";
//    card->power = card->powerBase = 20;
//    card->faction = Skellige;
//    card->rarity = Gold;
//    card->tags = { Beast, Cursed };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        const int n = cardsFiltered(ally, enemy, {hasTag(Beast)}, AllyAppeared).size();
//        const int x = std::max(0, 10 - 2 * n);
//        damage(card, x, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createUlfhedinn()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200104";
//    card->power = card->powerBase = 6;
//    card->faction = Skellige;
//    card->rarity = Gold;
//    card->tags = { Beast, Cursed };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        const std::vector<Card *> damaged = cardsFiltered(ally, enemy, {isDamaged}, EnemyBoard);
//        const std::vector<Card *> other   = cardsFiltered(ally, enemy, {isUndamaged}, EnemyBoard);
//        for (Card *card : other)
//            damage(card, 1, ally, enemy, card);
//        for (Card *card : damaged)
//            damage(card, 2, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createWildBoarOfTheSea()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152109";
//    card->power = card->powerBase = 8;
//    card->faction = Skellige;
//    card->rarity = Gold;
//    card->tags = { ClanAnCraite, Machine };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        gainArmor(card, 5, ally, enemy, card);
//    };

//    card->_onTurnEnd = [=](Field &ally, Field &enemy) {
//        if (Card *left = cardNextTo(card, ally, enemy, -1)) {
//            strengthen(left, 1, ally, enemy, card);
//            if (Card *right = cardNextTo(card, ally, enemy, 1))
//                damage(right, 1, ally, enemy, card);
//        }
//    };
//    return card;
//}

//Card *Cards::createGiantBoar()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201623";
//    card->power = card->powerBase = 8;
//    card->faction = Skellige;
//    card->rarity = Silver;
//    card->tags = { Beast };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (Card *card = random(cardsFiltered(ally, enemy, {otherThan(card)}, AllyBoard), ally.rng)) {
//            putToDiscard(card, ally, enemy, card);
//            boost(card, 10, ally, enemy, card);
//        }
//    };
//    return card;
//}

//Card *Cards::createOrnamentalSword()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201642";
//    card->isSpecial = true;
//    card->faction = Skellige;
//    card->rarity = Silver;
//    card->tags = { Item };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceCreateOptions(ally, enemy, card, {isBronzeOrSilver, isSkelligeFaction, hasTag(Soldier)});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        strengthen(target, 3, ally, enemy, card);
//        spawnNewCard(target, ally, enemy, card);
//    };
//    return card;
//}

//BlueboyLugos::SpectralWhale::SpectralWhale()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152403";
//    card->isDoomed = true;
//    card->power = card->powerBase = 3;
//    card->faction = Skellige;
//    card->rarity = Silver;
//    card->tags = { Cursed };

//    card->_onTurnEnd = [=](Field &ally, Field &enemy) {
//        if (!isOnBoard(card, ally) || !moveToRandomRow(card, ally, enemy, card))
//            return;
//        for (Card *card : cardsFiltered(ally, enemy, {isOnSameRow(&ally, card)}, AllyBoard))
//            damage(card, 1, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createDimunWarship()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200105";
//    card->power = card->powerBase = 7;
//    card->faction = Skellige;
//    card->rarity = Bronze;
//    card->tags = { ClanDimun, Machine };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        /// break if killed already
//        for (int n = 0; n < 4; ++n)
//            if (damage(target, 1, ally, enemy, card))
//                break;
//    };
//    return card;
//}

//Card *Cards::createTrissButterflies()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "122107";
//    card->tags = { Mage, Temeria };
//    card->power = card->powerBase = 8;
//    card->faction = Neutral;
//    card->rarity = Gold;

//    card->_onTurnEnd = [=](Field &ally, Field &enemy) {
//        if (!isOnBoard(card, ally))
//            return;
//        for (Card *card : lowests(cardsFiltered(ally, enemy, {}, AllyBoard)))
//            boost(card, 1, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createYennefer()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112108";
//    card->tags = { Mage, Aedirn };
//    card->power = card->powerBase = 6;
//    card->faction = Neutral;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectOption(ally, enemy, card, {new Unicorn(), new Chironex()});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        spawnNewCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Yennefer::Chironex::Chironex()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112402";
//    card->tags = { Cursed };
//    card->isDoomed = true;
//    card->power = card->powerBase = 4;
//    card->faction = Neutral;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        for (Card *card : cardsFiltered(ally, enemy, {}, AnyBoard))
//            damage(card, 2, ally, enemy, card);
//    };
//    return card;
//}


//Yennefer::Unicorn::Unicorn()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112401";
//    card->tags = { Beast };
//    card->isDoomed = true;
//    card->power = card->powerBase = 1;
//    card->faction = Neutral;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        for (Card *card : cardsFiltered(ally, enemy, {}, AnyBoard))
//            boost(card, 2, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createGermainPiquant()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200523";
//    card->tags = { Officer };
//    card->power = card->powerBase = 10;
//    card->faction = Neutral;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        spawnNewUnitToPos(new Cow(), rowAndPosToTheLeft(card, ally, 1), ally, enemy, card);
//        spawnNewUnitToPos(new Cow(), rowAndPosToTheLeft(card, ally, 1), ally, enemy, card);
//        spawnNewUnitToPos(new Cow(), rowAndPosToTheRight(card, ally, 1), ally, enemy, card);
//        spawnNewUnitToPos(new Cow(), rowAndPosToTheRight(card, ally, 1), ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createCommandersHorn()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "113207";
//    card->tags = { Tactics };
//    card->isSpecial = true;
//    card->faction = Neutral;
//    card->rarity = Silver;

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        const std::vector<Card *> cardsToBoost {
//            cardNextTo(target, ally, enemy, -2),
//                    cardNextTo(target, ally, enemy, -1),
//                    target,
//                    cardNextTo(target, ally, enemy, 1),
//                    cardNextTo(target, ally, enemy, 2),
//        };
//        for (Card *card : cardsToBoost)
//            if (card != nullptr)
//                boost(card, 3, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createMarchingOrders()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200019";
//    card->tags = { Tactics };
//    card->isSpecial = true;
//    card->faction = Neutral;
//    card->rarity = Silver;

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        Card *card = lowest(cardsFiltered(ally, enemy, {isBronzeOrSilver, isUnit}, AllyDeck), ally.rng);
//        if (card != nullptr) {
//            boost(card, 2, ally, enemy, card);
//            playExistedCard(card, ally, enemy, card);
//        }
//    };
//    return card;
//}


//Card *Cards::createAlzursDoubleCross()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "113209";
//    card->tags = { Spell };
//    card->isSpecial = true;
//    card->faction = Neutral;
//    card->rarity = Silver;

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        Card *card = highest(cardsFiltered(ally, enemy, {isBronzeOrSilver, isUnit}, AllyDeck), ally.rng);
//        if (card != nullptr) {
//            boost(card, 2, ally, enemy, card);
//            playExistedCard(card, ally, enemy, card);
//        }
//    };
//    return card;
//}


//Card *Cards::createAlbaArmoredCavalry()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200296";
//    card->tags = { Soldier };
//    card->power = card->powerBase = 7;
//    card->faction = Nilfgaard;
//    card->rarity = Bronze;
//    return card;
//}


//Card *Cards::createSentry()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201661";
//    card->tags = { Soldier };
//    card->power = card->powerBase = 8;
//    card->faction = Nilfgaard;
//    card->rarity = Bronze;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {hasTag(Soldier), hasCopyOnABoard(&ally)}, AllyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        for (Card *card : cardsFiltered(ally, enemy, {isCopy(target->name), otherThan(card)}, AllyBoard))
//            boost(card, 2, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createNauzicaaSergeant()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162309";
//    card->tags = { Officer };
//    card->power = card->powerBase = 7;
//    card->faction = Nilfgaard;
//    card->rarity = Bronze;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        clearHazardsFromItsRow(card, ally);
//        startChoiceToTargetCard(ally, enemy, card, {isUnit}, AllyBoardAndHandRevealed);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        boost(target, 3, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createSlaveInfantry()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201610";
//    card->tags = { Soldier };
//    card->power = card->powerBase = 3;
//    card->faction = Nilfgaard;
//    card->rarity = Bronze;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        Row row;
//        Pos pos;
//        if (!_findRowAndPos(card, ally, row, pos))
//            return;

//        for (int _row = Meele; _row <= Seige; ++_row)
//            if (_row != row) {
//                Card *copy = defaultCopy();
//                copy->isDoomed = true;
//                summonNewUnitToPos(copy, rowAndPosLastInExactRow(ally, Row(_row)), ally, enemy, card);
//            }
//    };
//    return card;
//}


//Card *Cards::createRecruit()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201617";
//    card->tags = { Soldier };
//    card->power = card->powerBase = 1;
//    card->faction = Nilfgaard;
//    card->rarity = Bronze;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (Card *card = random(cardsFiltered(ally, enemy, {isBronze, hasTag(Soldier), otherThan(card->name)}, AllyDeckShuffled), ally.rng))
//            playExistedCard(card, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createOintment()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201619";
//    card->tags = { Alchemy, Item };
//    card->isSpecial = true;
//    card->faction = Nilfgaard;
//    card->rarity = Bronze;

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronze, isUnit, hasPowerXorLess(5)}, AllyDiscard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createVilgefortz()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162105";
//    card->tags = { Mage };
//    card->power = card->powerBase = 9;
//    card->faction = Nilfgaard;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        const bool isTruce = !ally.passed && !enemy.passed;
//        const ChoiceGroup choiceGroup = isTruce ? AnyBoard : AllyBoard;
//        startChoiceToTargetCard(ally, enemy, card, {}, choiceGroup);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        const bool isAlly = isOnBoard(target, ally);
//        putToDiscard(target, ally, enemy, card);
//        if (isAlly) {
//            if (Card *copy = first(ally.deck))
//                playExistedCard(copy, ally, enemy, card);
//        } else {
//            if (Card *card = random(cardsFiltered(ally, enemy, {isBronze}, EnemyDeck), ally.rng)) {
//                putToHand(card, enemy, ally,  card);
//                reveal(card, ally, enemy, card);
//            }
//        }
//    };
//    return card;
//}


//Card *Cards::createVreemde()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200050";
//    card->tags = { Officer };
//    card->power = card->powerBase = 4;
//    card->faction = Nilfgaard;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceCreateOptions(ally, enemy, card, {isBronze, isNilfgaardFaction, hasTag(Soldier)});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        spawnNewCard(target, ally, enemy, card);
//    };
//    return card;
//}

//GermainPiquant::Cow::Cow()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201576";
//    card->tags = { Beast };
//    card->isDoomed = true;
//    card->power = card->powerBase = 1;
//    card->faction = Neutral;
//    card->rarity = Bronze;
//    return card;
//}


//Card *Cards::createAuckes()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162208";
//    card->tags = { Witcher };
//    card->power = card->powerBase = 7;
//    card->faction = Nilfgaard;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard, 2);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        toggleLock(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createEskel()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112202";
//    card->tags = { Witcher };
//    card->power = card->powerBase = 6;
//    card->faction = Neutral;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        for (Card *lambert : cardsFiltered(ally, enemy, {isCopy<Lambert>}, AllyDeck))
//            moveExistedUnitToPos(lambert, rowAndPosToTheLeft(card, ally, 1), ally, enemy, card);

//        for (Card *vesemir : cardsFiltered(ally, enemy, {isCopy<Vesemir>}, AllyDeck))
//            moveExistedUnitToPos(vesemir, rowAndPosToTheLeft(card, ally, 1), ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createLambert()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112204";
//    card->tags = { Witcher };
//    card->power = card->powerBase = 6;
//    card->faction = Neutral;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        for (Card *eskel : cardsFiltered(ally, enemy, {isCopy<Eskel>}, AllyDeck))
//            moveExistedUnitToPos(eskel, rowAndPosToTheRight(card, ally, 1), ally, enemy, card);

//        for (Card *vesemir : cardsFiltered(ally, enemy, {isCopy<Vesemir>}, AllyDeck))
//            moveExistedUnitToPos(vesemir, rowAndPosToTheRight(card, ally, 1), ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createVesemir()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112203";
//    card->tags = { Witcher };
//    card->power = card->powerBase = 7;
//    card->faction = Neutral;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        for (Card *lambert : cardsFiltered(ally, enemy, {isCopy<Lambert>}, AllyDeck))
//            moveExistedUnitToPos(lambert, rowAndPosToTheLeft(card, ally, 1), ally, enemy, card);

//        for (Card *eskel : cardsFiltered(ally, enemy, {isCopy<Eskel>}, AllyDeck))
//            moveExistedUnitToPos(eskel, rowAndPosToTheRight(card, ally, 1), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createTridamInfantry()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200171";
//    card->tags = { Soldier };
//    card->power = card->powerBase = 10;
//    card->faction = NothernRealms;
//    card->rarity = Bronze;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        gainArmor(card, 4, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createVriheddDragoon()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142205";
//    card->tags = { Elf, Soldier };
//    card->power = card->powerBase = 8;
//    card->faction = Scoiatael;
//    card->rarity = Bronze;

//    card->_onTurnEnd = [=](Field &ally, Field &enemy) {
//        if (!isOnBoard(card, ally))
//            return;
//        if (Card *card = random(cardsFiltered(ally, enemy, {isUnit, isNonSpying}, AllyHand), ally.rng))
//            boost(card, 1, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createMalena()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142210";
//    card->power = card->powerBase = 7;
//    card->isAmbush = true;
//    card->rarity = Silver;
//    card->faction = Scoiatael;
//    card->tags = { Elf };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        isAmbush = true;
//        setTimer(card, ally, enemy, 2);
//    };

//    card->_onTurnStart = [=](Field &ally, Field &enemy) {
//        if (!isOnBoard(card, ally) || !tick(card, ally, enemy))
//            return;
//        flipOver(card, ally, enemy);
//        if (Card *card = highest(cardsFiltered(ally, enemy, {isBronzeOrSilver, hasPowerXorLess(5)}, EnemyBoard), ally.rng))
//            charm(card, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createUnseenElder()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200055";
//    card->power = card->powerBase = 5;
//    card->rarity = Gold;
//    card->faction = Monster;
//    card->tags = { Vampire, Leader };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        drain(target, half(target->power), ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createDevanaRunestone()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201584";
//    card->isSpecial = true;
//    card->rarity = Silver;
//    card->faction = Monster;
//    card->tags = { Alchemy, Item };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceCreateOptions(ally, enemy, card, {isBronzeOrSilver, isMonsterFaction});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        spawnNewCard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createDazhbogRunestone()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201583";
//    card->isSpecial = true;
//    card->rarity = Silver;
//    card->faction = Nilfgaard;
//    card->tags = { Alchemy, Item };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceCreateOptions(ally, enemy, card, {isBronzeOrSilver, isNilfgaardFaction});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        spawnNewCard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createMoranaRunestone()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201585";
//    card->isSpecial = true;
//    card->rarity = Silver;
//    card->faction = Scoiatael;
//    card->tags = { Alchemy, Item };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceCreateOptions(ally, enemy, card, {isBronzeOrSilver, isScoiataelFaction});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        spawnNewCard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createStribogRunestone()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201581";
//    card->isSpecial = true;
//    card->rarity = Silver;
//    card->faction = Skellige;
//    card->tags = { Alchemy, Item };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceCreateOptions(ally, enemy, card, {isBronzeOrSilver, isSkelligeFaction});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        spawnNewCard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createMuzzle()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200225";
//    card->isSpecial = true;
//    card->rarity = Gold;
//    card->faction = Neutral;
//    card->tags = { Item };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, hasPowerXorLess(8)}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        charm(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createRockBarrage()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201647";
//    card->isSpecial = true;
//    card->rarity = Bronze;
//    card->faction = Neutral;
//    card->tags = {};

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        const RowAndPos rowAndPos = _findRowAndPos(target, enemy);
//        const Row rowAbove = std::min(Row(rowAndPos.row() + 1), Seige);

//        const bool shouldDestroy = isRowFull(enemy.row(rowAbove));
//        if (shouldDestroy) {
//            putToDiscard(target, ally, enemy, card);
//            return;
//        }

//        if (!damage(target, 7, ally, enemy, card) && (rowAndPos.row() != Seige))
//            moveExistedUnitToPos(target, rowAndPosLastInExactRow(enemy, rowAbove), enemy, ally, card);
//    };
//    return card;
//}


//Card *Cards::createWhisperingHillock()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201587";
//    card->power = card->powerBase = 6;
//    card->rarity = Gold;
//    card->faction = Monster;
//    card->tags = { Leader, Relict };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceCreateOptions(ally, enemy, card, {isBronzeOrSilver, hasTag(Organic)});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        spawnNewCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createBrewess()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132207";
//    card->tags = { Mage, Relict };
//    card->power = card->powerBase = 8;
//    card->faction = Monster;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        for (Card *weavess: cardsFiltered(ally, enemy, {isCopy<Weavess>}, AllyDeck))
//            moveExistedUnitToPos(weavess, rowAndPosToTheRight(card, ally, 1), ally, enemy, card);

//        for (Card *whispess : cardsFiltered(ally, enemy, {isCopy<Whispess>}, AllyDeck))
//            moveExistedUnitToPos(whispess, rowAndPosToTheLeft(card, ally, 1), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createWeavess()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132208";
//    card->tags = { Mage, Relict };
//    card->power = card->powerBase = 6;
//    card->faction = Monster;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        for (Card *whispess : cardsFiltered(ally, enemy, {isCopy<Whispess>}, AllyDeck))
//            moveExistedUnitToPos(whispess, rowAndPosToTheLeft(card, ally, 1), ally, enemy, card);

//        for (Card *brewess: cardsFiltered(ally, enemy, {isCopy<Brewess>}, AllyDeck))
//            moveExistedUnitToPos(brewess, rowAndPosToTheLeft(card, ally, 1), ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createWhispess()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132206";
//    card->tags = { Mage, Relict };
//    card->power = card->powerBase = 6;
//    card->faction = Monster;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        for (Card *weavess: cardsFiltered(ally, enemy, {isCopy<Weavess>}, AllyDeck))
//            moveExistedUnitToPos(weavess, rowAndPosToTheRight(card, ally, 1), ally, enemy, card);

//        for (Card *brewess: cardsFiltered(ally, enemy, {isCopy<Brewess>}, AllyDeck))
//            moveExistedUnitToPos(brewess, rowAndPosToTheRight(card, ally, 1), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createWeavessIncantation()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200222";
//    card->tags = { Mage, Relict };
//    card->power = card->powerBase = 4;
//    card->faction = Monster;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        auto *option1 = createOption(card, StrengthenAll);
//        option1->text = "Strengthen all your other Relicts in hand, deck, and on board by 2.";

//        auto *option2 = createOption(card, PlayAndStrengthen);
//        option2->text = "Play a Bronze or Silver Relict from your deck and Strengthen it by 2.";

//        startChoiceToSelectOption(ally, enemy, card, {option1, option2});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (isOption(target, StrengthenAll)) {
//            for (Card *card : cardsFiltered(ally, enemy, {hasTag(Relict), otherThan(card)}, AllyBoardHandDeck))
//                strengthen(card, 2, ally, enemy, card);
//            return;
//        }

//        if (isOption(target, PlayAndStrengthen)) {
//            startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, hasTag(Relict)}, AllyDeckShuffled);
//            return;
//        }

//        assert(false);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        strengthen(target, 2, ally, enemy, card);
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createBrewessRitual()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200221";
//    card->tags = { Mage, Relict };
//    card->power = card->powerBase = 1;
//    card->faction = Monster;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isDeathwish, isBronze, isUnit}, AllyDiscard, 2);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createWhispessTribute()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200220";
//    card->tags = { Mage, Relict };
//    card->power = card->powerBase = 6;
//    card->faction = Monster;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, hasTag(Organic)}, AllyDeckShuffled);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createNivellen()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200089";
//    card->power = card->powerBase = 10;
//    card->rarity = Silver;
//    card->faction = Neutral;
//    card->tags = { Cursed };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectRow(ally, enemy, card);
//    };

//    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
//        for (Card *card : cardsInRow(ally, enemy, screenRow)) {
//            if (isOnBoard(card, ally)) {
//                moveToRandomRow(card, ally, enemy, card);
//            } else {
//                moveToRandomRow(card, enemy, ally, card);
//            }
//        }
//    };
//    return card;
//}



//Card *Cards::createLeoBonhart()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200031";
//    card->power = card->powerBase = 7;
//    card->rarity = Gold;
//    card->faction = Nilfgaard;
//    card->tags = { Soldier };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isNonRevealed, isUnit}, AllyHand);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (_revealed == nullptr) {
//            _revealed = target;
//            reveal(target, ally, enemy, card);
//            startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//            return;
//        }
//        damage(target, _revealed->powerBase, ally, enemy, card);
//    };
//    return card;
//}



//Card *Cards::createMorvranVoorhis()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200163";
//    card->power = card->powerBase = 7;
//    card->rarity = Gold;
//    card->faction = Nilfgaard;
//    card->tags = { Officer, Leader };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isNonRevealed}, AnyHandShuffled, 4, true);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        reveal(target, ally, enemy, card);
//    };
//    return card;
//}



//Card *Cards::createCynthia()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162203";
//    card->power = card->powerBase = 5;
//    card->rarity = Silver;
//    card->faction = Nilfgaard;
//    card->tags = { Mage };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (Card *card = highest(cardsFiltered(ally, enemy, {isUnit, isNonRevealed}, EnemyHand), ally.rng)) {
//            reveal(card, ally, enemy, card);
//            boost(card, card->power, ally, enemy, card);
//        }
//    };
//    return card;
//}


//Card *Cards::createSerrit()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162209";
//    card->power = card->powerBase = 6;
//    card->rarity = Silver;
//    card->faction = Nilfgaard;
//    card->tags = { Witcher };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isUnit}, EnemyBoardAndHandRevealed);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        const int x = isOnBoard(target, enemy) ? 7 : (target->power - 1);
//        damage(target, x, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createSweers()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162206";
//    card->power = card->powerBase = 9;
//    card->rarity = Silver;
//    card->faction = Nilfgaard;
//    card->tags = { Officer };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isUnit, hasCopyInADeck(&enemy)}, EnemyBoardAndHandRevealed);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        for (Card *copy : findCopies(target, enemy.deck))
//            putToDiscard(copy, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createTiborEggebracht()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162107";
//    card->power = card->powerBase = 10;
//    card->rarity = Gold;
//    card->faction = Nilfgaard;
//    card->tags = { Officer };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (ally.passed || enemy.passed)
//            return;
//        if (Card *card = random(cardsFiltered(ally, enemy, {isBronze}, EnemyDeck), ally.rng)) {
//            putToHand(card, enemy, ally,  card);
//            reveal(card, ally, enemy, card);
//        }
//    };
//    return card;
//}

//Card *Cards::createVattierDeRideaux()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162103";
//    card->power = card->powerBase = 10;
//    card->rarity = Gold;
//    card->faction = Nilfgaard;
//    card->tags = { Officer };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isNonRevealed}, AllyHand, 2, true);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        reveal(target, ally, enemy, card);
//        if (Card *card = random(cardsFiltered(ally, enemy, {isNonRevealed}, EnemyHand), ally.rng))
//            reveal(card, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createAlbrich()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162201";
//    card->power = card->powerBase = 10;
//    card->rarity = Silver;
//    card->faction = Nilfgaard;
//    card->tags = { Mage };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (ally.passed || enemy.passed)
//            return;
//        drawACard(ally, enemy,  card);
//        if (Card *card = first(enemy.deck)) {
//            putToHand(card, ally, enemy,  card);
//            reveal(card, ally, enemy, card);
//        }
//    };
//    return card;
//}

//Card *Cards::createHeftyHelge()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200041";
//    card->power = card->powerBase = 8;
//    card->rarity = Silver;
//    card->faction = Nilfgaard;
//    card->tags = { Machine };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        const Filters filters = isRevealed ? Filters{} : Filters{isOnAnotherRow(&ally, &enemy, card)};
//        for (Card *card : cardsFiltered(ally, enemy, filters, EnemyBoard))
//            damage(card, 1, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createAlchemist()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162316";
//    card->power = card->powerBase = 9;
//    card->rarity = Bronze;
//    card->faction = Nilfgaard;
//    card->tags = { Mage };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isNonRevealed}, AnyHandShuffled, 2, true);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        reveal(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createDaerlanSoldier()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162301";
//    card->power = card->powerBase = 4;
//    card->rarity = Bronze;
//    card->faction = Nilfgaard;
//    card->tags = { Soldier };

//    card->_onRevealed = [=](Field &ally, Field &enemy, const Card *src) {
//        /// reveal is possible only by units on a board
//        /// check if revealed by an you
//        if (!isOnBoard(src, ally))
//            return;
//        /// don't jump and draw a card, if no place on a field
//        if (moveExistedUnitToPos(card, rowAndPosRandom(ally), ally, enemy, card))
//            drawACard(ally, enemy,  card);
//    };
//    return card;
//}

//Card *Cards::createFireScorpion()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162306";
//    card->power = card->powerBase = 5;
//    card->rarity = Bronze;
//    card->faction = Nilfgaard;
//    card->tags = { Machine };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        damage(target, 5, ally, enemy, card);
//    };
//    card->_onRevealed = [=](Field &ally, Field &enemy, const Card *src) {
//        if (isOnBoard(src, ally))
//            onDeploy(ally, enemy);
//    };
//    return card;
//}

//Card *Cards::createWildHuntHound()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132402";
//    card->power = card->powerBase = 4;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { WildHunt, Construct };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (Card *card = random(cardsFiltered(ally, enemy, {isCopy("Biting Frost")}, AllyDeck), ally.rng))
//            playExistedCard(card, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createWildHuntWarrior()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132309";
//    card->power = card->powerBase = 7;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { WildHunt, Soldier };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        const bool isUnderFrost = rowEffectUnderUnit(target, enemy) == BitingFrostEffect;
//        if (damage(target, 3, ally, enemy, card) || isUnderFrost)
//            boost(card, 2, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createMangonel()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162317";
//    card->power = card->powerBase = 7;
//    card->rarity = Bronze;
//    card->faction = Nilfgaard;
//    card->tags = { Machine };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (Card *card = random(cardsFiltered(ally, enemy, {}, EnemyBoard), ally.rng))
//            damage(card, 2, ally, enemy, card);
//    };

//    card->_onOtherRevealed = [=](Field &ally, Field &enemy, Card *, const Card *) {
//        if (isOnBoard(card, ally))
//            onDeploy(ally, enemy);
//    };
//    return card;
//}

//Card *Cards::createNilfgaardianKnight()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162318";
//    card->power = card->powerBase = 12;
//    card->rarity = Bronze;
//    card->faction = Nilfgaard;
//    card->tags = { Soldier };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        gainArmor(card, 2, ally, enemy, card);

//        for (const Filter &filter : Filters{isBronze, isSilver, isGold})
//            if (Card *card = random(cardsFiltered(ally, enemy, {filter, isNonRevealed}, AllyHand), ally.rng)) {
//                reveal(card, ally, enemy, card);
//                break;
//            }
//    };
//    return card;
//}

//Card *Cards::createSpotter()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162303";
//    card->power = card->powerBase = 5;
//    card->rarity = Bronze;
//    card->faction = Nilfgaard;
//    card->tags = { Soldier };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isUnit, isBronzeOrSilver, ::isRevealed}, AnyHandShuffled);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        boost(card, target->powerBase, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createVenendalElite()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200518";
//    card->power = card->powerBase = 1;
//    card->rarity = Bronze;
//    card->faction = Nilfgaard;
//    card->tags = { Soldier };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isUnit, ::isRevealed}, AnyHandShuffled);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        const int powerTarget = target->power;
//        // TODO: check if triggered onDamaged and onDamaged of other units,
//        // because it shouldn't
//        setPower(target, power, ally, enemy, card);
//        setPower(card, powerTarget, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createMasterOfDisguise()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201616";
//    card->power = card->powerBase = 11;
//    card->rarity = Bronze;
//    card->faction = Nilfgaard;
//    card->tags = { Soldier };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {::isRevealed}, AnyHandShuffled, 2);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        conceal(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createHenryVarAttre()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200227";
//    card->power = card->powerBase = 9;
//    card->rarity = Silver;
//    card->faction = Nilfgaard;
//    card->tags = { Support };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        const Filters filters {::isRevealed, isUnit};
//        const int nRevealed = int(cardsFiltered(ally, enemy, filters, AnyHandShuffled).size());
//        if (nRevealed)
//            startChoiceToTargetCard(ally, enemy, card, filters, AnyHandShuffled, nRevealed);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (isIn(target, ally.hand)) {
//            boost(target, 2, ally, enemy, card);
//            conceal(target, ally, enemy, card);
//            return;
//        }
//        damage(target, 2, ally, enemy, card);
//        conceal(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createSummoningCircle()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200022";
//    card->isSpecial = true;
//    card->rarity = Silver;
//    card->faction = Neutral;
//    card->tags = { Spell };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        if (Card *card = last(cardsFiltered(ally, enemy, {isUnit, isBronzeOrSilver, isNonAgent, otherThan(card)}, BothAppeared)))
//            spawnNewCard(card->defaultCopy(), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createXavierMoran()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200080";
//    card->power = card->powerBase = 10;
//    card->rarity = Gold;
//    card->faction = Scoiatael;
//    card->tags = { Dwarf };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (Card *card = last(cardsFiltered(ally, enemy, {hasTag(Dwarf), otherThan(card)}, AllyAppeared)))
//            boost(card, card->powerBase, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createYenneferEnchantress()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201601";
//    card->tags = { Mage, Aedirn };
//    card->power = card->powerBase = 5;
//    card->faction = Nilfgaard;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (Card *card = last(cardsFiltered(ally, enemy, {hasTag(Spell), isBronzeOrSilver}, AllyAppeared)))
//            spawnNewCard(card->defaultCopy(), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createVernonRoche()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "122102";
//    card->tags = { Temeria, Officer };
//    card->power = card->powerBase = 3;
//    card->faction = NothernRealms;
//    card->rarity = Gold;

//    card->_onGameStart = [=](Field &ally, Field &enemy) {
//        Card *card = new BlueStripeCommando();
//        addAsNew(ally, card);
//        putToDeck(card, ally, enemy, DeckPosRandom, card);
//    };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *card, Field &ally, Field &enemy) {
//        damage(card, 7, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createBlueStripeScout()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "122310";
//    card->tags = { Temeria, Soldier };
//    card->power = card->powerBase = 3;
//    card->isCrew = true;
//    card->faction = NothernRealms;
//    card->rarity = Bronze;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        for (Card *card : cardsFiltered(ally, enemy, {hasTag(Temeria), isNonSpying, hasPowerX(power)}, AllyBoardHandDeck))
//            boost(card, 1, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createBlueStripeCommando()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "122311";
//    card->tags = { Temeria, Soldier };
//    card->power = card->powerBase = 3;
//    card->faction = NothernRealms;
//    card->rarity = Bronze;

//    card->_onOtherAllyPlayedFromHand = [=](Card *target, Field &ally, Field &enemy) {
//        if (!hasTag(Temeria) || !hasPowerX(power) || !isIn(card, ally.deck))
//            return;

//        for (Card *card : cardsFiltered(ally, enemy, {isCopy<BlueStripeCommando>, otherThan(card)}, AllyDeckShuffled)) {
//            BlueStripeCommando *commando = static_cast<BlueStripeCommando *>(card);
//            commando->_allyPlayedToCopy.insert({target, card});
//        }

//        if (_allyPlayedToCopy.find(target) == _allyPlayedToCopy.end())
//            moveExistedUnitToPos(card, rowAndPosRandom(ally), ally, enemy, card);

//        _allyPlayedToCopy.clear();
//    };
//    return card;
//}

//Card *Cards::createImperialGolem()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132407";
//    card->tags = { Construct };
//    card->power = card->powerBase = 3;
//    card->faction = Nilfgaard;
//    card->rarity = Bronze;

//    card->_onOtherRevealed = [=](Field &ally, Field &enemy, Card *target, const Card *) {
//        if (!isIn(card, ally.deck) || !isIn(target, enemy.hand))
//            return;

//        for (Card *card : cardsFiltered(ally, enemy, {isCopy<ImperialGolem>, otherThan(card)}, AllyDeckShuffled)) {
//            ImperialGolem *golem = static_cast<ImperialGolem *>(card);
//            golem->_cardRevealedToCopy.insert({target, card});
//        }

//        if (_cardRevealedToCopy.find(target) == _cardRevealedToCopy.end())
//            moveExistedUnitToPos(card, rowAndPosRandom(ally), ally, enemy, card);

//        _cardRevealedToCopy.clear();
//    };
//    return card;
//}

//Card *Cards::createWildHuntNavigator()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200026";
//    card->power = card->powerBase = 3;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { WildHunt, Mage };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronze, hasTag(WildHunt), hasNoTag(Mage), hasCopyInADeck(&ally)}, AllyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (Card *copy = findCopy(target, ally.deck))
//            playExistedCard(copy, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createNithral()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132214";
//    card->power = card->powerBase = 6;
//    card->rarity = Silver;
//    card->faction = Monster;
//    card->tags = { WildHunt, Officer };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        const int nWildHuntUnits = cardsFiltered(ally, enemy, {hasTag(WildHunt), isUnit}, AllyHand).size();
//        damage(target, 6 + nWildHuntUnits, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createMiruna()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132108";
//    card->power = card->powerBase = 4;
//    card->rarity = Gold;
//    card->faction = Monster;
//    card->tags = { Beast };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        setTimer(card, ally, enemy, 2);
//    };

//    card->_onTurnStart = [=](Field &ally, Field &enemy) {
//        if (!isOnBoard(card, ally) || !tick(card, ally, enemy))
//            return;
//        if (Card *card = highest(cardsFiltered(ally, enemy, {isOnOppositeRow(&ally, &enemy, card)}, EnemyBoard), ally.rng))
//            charm(card, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createImlerith()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132102";
//    card->power = card->powerBase = 9;
//    card->rarity = Gold;
//    card->faction = Monster;
//    card->tags = { WildHunt, Officer };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        const bool isUnderFrost = rowEffectUnderUnit(target, enemy) == BitingFrostEffect;
//        damage(target, isUnderFrost ? 8 : 4, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createCaretaker()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132106";
//    card->power = card->powerBase = 4;
//    card->rarity = Gold;
//    card->faction = Monster;
//    card->isDoomed = true;
//    card->tags = { Relict };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isUnit, isBronzeOrSilver}, EnemyDiscard);
//    };
//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createRuehin()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201660";
//    card->power = card->powerBase = 8;
//    card->rarity = Silver;
//    card->faction = Monster;
//    card->tags = { Insectoid, Cursed };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        for (Card *card : cardsFiltered(ally, enemy, {hasAnyOfTags({Insectoid, Cursed}), otherThan(card), isUnit}, AllyBoardHandDeck))
//            strengthen(card, 1, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createOldSpeartipAsleep()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132218";
//    card->power = card->powerBase = 12;
//    card->rarity = Gold;
//    card->faction = Monster;
//    card->tags = { Ogroid };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        for (Card *card : cardsFiltered(ally, enemy, {hasTag(Ogroid), otherThan(card), isUnit}, AllyBoardHandDeck))
//            strengthen(card, 1, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createOldSpeartip()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132408";
//    card->power = card->powerBase = 10;
//    card->rarity = Gold;
//    card->faction = Monster;
//    card->tags = { Ogroid };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        for(Card *card : randoms(cardsFiltered(ally, enemy, {isOnOppositeRow(&ally, &enemy, card)}, EnemyBoard), 5, ally.rng))
//            damage(card, 2, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createGolyat()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200052";
//    card->power = card->powerBase = 10;
//    card->rarity = Silver;
//    card->faction = Monster;
//    card->tags = { Ogroid };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        boost(card, 7, ally, enemy, card);
//    };

//    card->_onDamaged = [=](const int, Field &ally, Field &enemy, const Card *src) {
//        if (src != card)
//            damage(card, 2, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createBarbegazi()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201701";
//    card->power = card->powerBase = 6;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Insectoid };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        isResilient = true;
//        startChoiceToTargetCard(ally, enemy, card, {}, AllyBoard);
//    };

//    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
//        boost(card, consume(target, ally, enemy, card), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createGhoul()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132306";
//    card->power = card->powerBase = 4;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Necrophage };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, isUnit}, AllyDiscard);
//    };

//    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
//        boost(card, consume(target, ally, enemy, card), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createForktail()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201606";
//    card->power = card->powerBase = 8;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Draconid };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AllyBoard, 2);
//    };

//    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
//        boost(card, consume(target, ally, enemy, card), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createArachasQueen()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201743";
//    card->power = card->powerBase = 7;
//    card->rarity = Gold;
//    card->faction = Monster;
//    card->tags = { Leader, Insectoid };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        isImmune = true;
//        startChoiceToTargetCard(ally, enemy, card, {}, AllyBoard, 3);
//    };

//    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
//        boost(card, consume(target, ally, enemy, card), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createOzzrel()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201698";
//    card->power = card->powerBase = 5;
//    card->rarity = Silver;
//    card->faction = Monster;
//    card->tags = { Necrophage };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, isUnit}, BothDiscard);
//    };

//    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
//        boost(card, consume(target, ally, enemy, card), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createKayran()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132107";
//    card->power = card->powerBase = 5;
//    card->rarity = Gold;
//    card->faction = Monster;
//    card->tags = { Insectoid };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {hasPowerXorLess(7)}, AnyBoard);
//    };

//    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
//        boost(card, consume(target, ally, enemy, card), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createMourntart()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132202";
//    card->power = card->powerBase = 4;
//    card->rarity = Silver;
//    card->faction = Monster;
//    card->tags = { Necrophage };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        const std::vector<Card *> cards = cardsFiltered(ally, enemy, {isBronzeOrSilver, isUnit}, AllyDiscard);

//        for (Card *card : cards)
//            consume(card, ally, enemy, card);

//        boost(card, cards.size(), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createToadPrince()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132216";
//    card->power = card->powerBase = 6;
//    card->rarity = Silver;
//    card->faction = Monster;
//    card->tags = { Cursed };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (Card *unit = first(cardsFiltered(ally, enemy, {isUnit}, AllyDeck))) {
//            putToHand(unit, ally, enemy,  card);
//            startChoiceToTargetCard(ally, enemy, card, {isUnit}, AllyHand);
//        }
//    };

//    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
//        boost(card, consume(target, ally, enemy, card), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createFiend()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112405";
//    card->power = card->powerBase = 11;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Relict };
//    return card;
//}

//Card *Cards::createMorvudd()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112405";
//    card->power = card->powerBase = 6;
//    card->rarity = Silver;
//    card->faction = Monster;
//    card->tags = { Relict };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
//    };

//    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
//        toggleLock(target, ally, enemy, card);
//        if (isOnBoard(target, enemy))
//            setPower(target, target->power - half(target->power), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createEkimmara()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132313";
//    card->power = card->powerBase = 5;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Vampire };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        drain(target, 3, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createRotfiend()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200295";
//    card->power = card->powerBase = 8;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Necrophage };

//    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
//        for(Card *target : cardsFiltered(ally, enemy, {isOnOppositeRow(&ally, &enemy, card)}, EnemyBoard))
//            damage(target, 2, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createArchespore()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200038";
//    card->power = card->powerBase = 7;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Cursed };

//    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
//        damage(random(cardsFiltered(ally, enemy, {}, EnemyBoard), ally.rng),
//               4, ally, enemy, card);
//    };

//    card->_onTurnStart = [=](Field &ally, Field &enemy) {
//        if (isOnBoard(card, ally) && moveToRandomRow(card, ally, enemy, card))
//            damage(random(cardsFiltered(ally, enemy, {}, EnemyBoard), ally.rng),
//                   1, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createCyclops()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200037";
//    card->power = card->powerBase = 11;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Ogroid };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AllyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if(!_powerOfDestroyed) {
//            _powerOfDestroyed = target->power;
//            putToDiscard(target, ally, enemy, card);
//            startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//            return;
//        }
//        damage(target, _powerOfDestroyed, ally, enemy, card);
//        _powerOfDestroyed = 0;
//    };
//    return card;
//}

//Card *Cards::createMaerolorn()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132406";
//    card->power = card->powerBase = 4;
//    card->rarity = Silver;
//    card->faction = Monster;
//    card->tags = { Relict };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronze, isDeathwish}, AllyDeckShuffled);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createMonsterNest()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "133302";
//    card->isSpecial = true;
//    card->rarity = Silver;
//    card->faction = Monster;
//    card->tags = { Organic };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceCreateOptions(ally, enemy, card, {isBronze, hasAnyOfTags({Necrophage, Insectoid})}, AnyCard, -1);
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        boost(target, 1, ally, enemy, card);
//        spawnNewCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createArachasDrone()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132304";
//    card->power = card->powerBase = 3;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Insectoid };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        for (Card *copy : cardsFiltered(ally, enemy, {isCopy(card->name)}, AllyDeck))
//            moveExistedUnitToPos(copy, rowAndPosToTheRight(card, ally, 1), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createAlphaWerewolf()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200114";
//    card->power = card->powerBase = 10;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Beast, Cursed };

//    card->_onContactWithFullMoon = [=](Field &ally, Field &enemy) {
//        spawnNewUnitToPos(new Wolf(), rowAndPosToTheLeft(card, ally, 1), ally, enemy, card);
//        spawnNewUnitToPos(new Wolf(), rowAndPosToTheRight(card, ally, 1), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createWerewolf()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201600";
//    card->power = card->powerBase = 7;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Beast, Cursed };
//    card->isImmune = true;

//    card->_onContactWithFullMoon = [=](Field &ally, Field &enemy) {
//        boost(card, 7, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createEredinBreaccGlas()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "131101";
//    card->power = card->powerBase = 5;
//    card->rarity = Gold;
//    card->faction = Monster;
//    card->tags = { WildHunt, Leader };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceCreateOptions(ally, enemy, card, {isBronze, hasTag(WildHunt)}, AnyCard, -1);
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        spawnNewCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createCaranthirArFeiniel()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132104";
//    card->power = card->powerBase = 9;
//    card->rarity = Gold;
//    card->faction = Monster;
//    card->tags = { WildHunt, Mage, Officer };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        const Row row = _findRowAndPos(card, ally).row();
//        if (moveExistedUnitToPos(target, rowAndPosLastInExactRow(enemy, row), enemy, ally, card))
//            applyRowEffect(ally, enemy, 3 + row, BitingFrostEffect);
//    };
//    return card;
//}

//Card *Cards::createImlerithSabbath()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201781";
//    card->power = card->powerBase = 5;
//    card->rarity = Gold;
//    card->faction = Monster;
//    card->tags = { WildHunt, Officer };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        gainArmor(card, 2, ally, enemy, card);
//    };

//    card->_onTurnEnd = [=](Field &ally, Field &enemy) {
//        if (!isOnBoard(card, ally))
//            return;
//        if (duel(card, highest(cardsFiltered(ally, enemy, {}, EnemyBoard), ally.rng), ally, enemy)) {
//            heal(card, 2, ally, enemy, card);
//            gainArmor(card, 2, ally, enemy, card);
//        }
//    };
//    return card;
//}

//Card *Cards::createDagon()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200158";
//    card->power = card->powerBase = 8;
//    card->rarity = Gold;
//    card->faction = Monster;
//    card->tags = { Leader, Vodyanoi };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectOption(ally, enemy, card, {new ImpenetrableFog(), new TorrentialRain()});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        spawnNewCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createIfrit()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132210";
//    card->power = card->powerBase = 8;
//    card->rarity = Silver;
//    card->faction = Monster;
//    card->tags = { Construct };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        const Row row = _findRowAndPos(card, ally).row();
//        const RowAndPos rowAndPos(row, Pos(ally.row(row).size()));
//        spawnNewUnitToPos(new IfritLesser(), rowAndPos, ally, enemy, card);
//        spawnNewUnitToPos(new IfritLesser(), rowAndPos, ally, enemy, card);
//        spawnNewUnitToPos(new IfritLesser(), rowAndPos, ally, enemy, card);
//    };
//    return card;
//}

//Ifrit::IfritLesser::IfritLesser()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132404";
//    card->power = card->powerBase = 1;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Construct };
//    card->isDoomed = true;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        damage(random(cardsFiltered(ally, enemy, {}, EnemyBoard), ally.rng), 1, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createSheTrollOfVergen()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200534";
//    card->power = card->powerBase = 1;
//    card->rarity = Silver;
//    card->faction = Monster;
//    card->tags = { Ogroid };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        _played = false;
//        startChoiceToTargetCard(ally, enemy, card, {isBronze, isDeathwish}, AllyDeckShuffled);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (!_played) {
//            _played = true;
//            startChoiceToTargetCard(ally, enemy, card, {target});
//            playExistedCard(target, ally, enemy, card);
//            return;
//        }

//        boost(card, consume(target, ally, enemy, card), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createWyvern()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132303";
//    card->power = card->powerBase = 6;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Draconid };

//    card->_onDeploy = [=] (Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
//        damage(target, 5, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createAbaya()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132203";
//    card->power = card->powerBase = 4;
//    card->rarity = Silver;
//    card->faction = Monster;
//    card->tags = { Necrophage };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectOption(ally, enemy, card, {new TorrentialRain(), new ClearSkies(), new ArachasVenom()});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        spawnNewCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createParasite()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201657";
//    card->isSpecial = true;
//    card->rarity = Silver;
//    card->faction = Monster;
//    card->tags = { Organic };

//    card->_onPlaySpecial = [=] (Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card);
//    };

//    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
//        if (isOnBoard(target, ally))
//            boost(target, 12, ally, enemy, card);
//        else if (isOnBoard(target, enemy))
//            damage(target, 12, ally, enemy, card);
//        else
//            assert(false);
//    };

//    return card;
//}

//Card *Cards::createJotunn()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200218";
//    card->power = card->powerBase = 6;
//    card->rarity = Silver;
//    card->faction = Monster;
//    card->tags = { Ogroid };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        Row rowSelf = _findRowAndPos(card, ally).row();
//        startChoiceToTargetCard(ally, enemy, card, {isNotOnRow(&enemy, rowSelf)}, EnemyBoard, 3);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        Row rowSelf = _findRowAndPos(card, ally).row();
//        if (moveExistedUnitToPos(target, rowAndPosLastInExactRow(enemy, rowSelf), enemy, ally, card))
//            damage(target, rowEffectUnderUnit(target, enemy) == BitingFrostEffect ? 3 : 2, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createIceGiant()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132212";
//    card->power = card->powerBase = 6;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Ogroid };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (enemy.rowEffect(Meele) == BitingFrostEffect
//                || enemy.rowEffect(Range) == BitingFrostEffect
//                || enemy.rowEffect(Seige) == BitingFrostEffect
//                || ally.rowEffect(Meele) == BitingFrostEffect
//                || ally.rowEffect(Range) == BitingFrostEffect
//                || ally.rowEffect(Seige) == BitingFrostEffect)
//            boost(card, 6, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createIceTroll()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200502";
//    card->power = card->powerBase = 4;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Ogroid };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        const int mult = rowEffectUnderUnit(target, enemy) == BitingFrostEffect ? 2 : 1;
//        while (true) {
//            if (damage(target, power * mult, ally, enemy, card))
//                return true;
//            if (damage(card, target->power, ally, enemy, target))
//                return false;
//        }
//    };
//    return card;
//}

//Card *Cards::createDrowner()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132314";
//    card->power = card->powerBase = 7;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Necrophage };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        Row rowSelf = _findRowAndPos(card, ally).row();
//        startChoiceToTargetCard(ally, enemy, card, {isNotOnRow(&enemy, rowSelf)}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        Row rowSelf = _findRowAndPos(card, ally).row();
//        if (moveExistedUnitToPos(target, rowAndPosLastInExactRow(enemy, rowSelf), enemy, ally, card))
//            damage(target, (rowEffectUnderUnit(target, enemy) > 0 && rowEffectUnderUnit(target, enemy) <= 9) ? 4 : 2, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createFoglet()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132301";
//    card->power = card->powerBase = 4;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Necrophage };

//    card->_onAllyAppliedRowEffect = [=](const RowEffect rowEffect, Field &ally, Field &enemy, const Row row) {
//        if (rowEffect != ImpenetrableFogEffect || !isIn(card, ally.deck))
//            return;

//        for (Card *card : cardsFiltered(ally, enemy, {isCopy<Foglet>, otherThan(card)}, AllyDeckShuffled)) {
//            Foglet *foglet = static_cast<Foglet *>(card);
//            foglet->_rowToCopy.insert({row, card});
//        }

//        if (_rowToCopy.find(row) == _rowToCopy.end())
//            moveExistedUnitToPos(card, rowAndPosLastInExactRow(ally, row), ally, enemy, card);

//        _rowToCopy.clear();
//    };
//    return card;
//}

//Card *Cards::createAncientFoglet()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132302";
//    card->power = card->powerBase = 10;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Necrophage };

//    card->_onTurnEnd = [=](Field &ally, Field &enemy) {
//        if (!isOnBoard(card, ally))
//            return;
//        if (enemy.rowEffect(Meele) == ImpenetrableFogEffect
//                || enemy.rowEffect(Range) == ImpenetrableFogEffect
//                || enemy.rowEffect(Seige) == ImpenetrableFogEffect
//                || ally.rowEffect(Meele) == ImpenetrableFogEffect
//                || ally.rowEffect(Range) == ImpenetrableFogEffect
//                || ally.rowEffect(Seige) == ImpenetrableFogEffect)
//            boost(card, 1, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createDraug()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132101";
//    card->power = card->powerBase = 10;
//    card->rarity = Gold;
//    card->faction = Monster;
//    card->tags = { Cursed, Officer };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        // TODO: check interaction w/ Cyris
//        assert(isOnBoard(card, ally));
//        const Row row = _findRowAndPos(card, ally).row();
//        for (Card *card : cardsFiltered(ally, enemy, {isUnit}, AllyDiscard)) {
//            if (isRowFull(ally.row(row)))
//                return;
//            banish(card, ally, enemy, card);
//            if (!spawnNewUnitToPos(new Draugir(), rowAndPosToTheRight(card, ally, 1), ally, enemy, card))
//                break;
//        }
//    };
//    return card;
//}

//Draug::Draugir::Draugir()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    // TODO: find picture
//    card->id = "132101";
//    card->power = card->powerBase = 1;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Cursed };
//    card->isDoomed = true;
//    return card;
//}

//Card *Cards::createCelaenoHarpy()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132217";
//    card->power = card->powerBase = 6;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Beast };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        spawnNewUnitToPos(new HarpyEgg(), rowAndPosToTheLeft(card, ally, 1), ally, enemy, card);
//        spawnNewUnitToPos(new HarpyEgg(), rowAndPosToTheLeft(card, ally, 1), ally, enemy, card);
//    };
//    return card;
//}

//CelaenoHarpy::HarpyEgg::HarpyEgg()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132316";
//    card->power = card->powerBase = 1;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->isDoomed = true;

//    card->_onConsumed = [=](Field &ally, Field &enemy, Card *src) {
//        boost(src, 4, ally, enemy, card);
//    };

//    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
//        spawnNewUnitToPos(new HarpyHatchling(), rowAndPosRandom(ally), ally, enemy, card);
//    };
//    return card;
//}

//CelaenoHarpy::HarpyHatchling::HarpyHatchling()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132315";
//    card->power = card->powerBase = 4;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Beast };
//    return card;
//}

//Card *Cards::createArachasBehemoth()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132201";
//    card->power = card->powerBase = 8;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Insectoid };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        setTimer(card, ally, enemy, 4);
//    };

//    card->_onAllyConsume = [=](Field &ally, Field &enemy, Card *) {
//        if (!isOnBoard(card, ally))
//            return;
//        if (!tick(card, ally, enemy))
//            spawnNewUnitToPos(new ArachasHatchling(), rowAndPosRandom(ally), ally, enemy, card);
//    };
//    return card;
//}

//ArachasBehemoth::ArachasHatchling::ArachasHatchling()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132304";
//    card->power = card->powerBase = 3;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Insectoid };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        for (Card *copy : cardsFiltered(ally, enemy, {isCopy<ArachasDrone>}, AllyDeck))
//            moveExistedUnitToPos(copy, rowAndPosToTheRight(card, ally, 1), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createArchgriffin()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132307";
//    card->power = card->powerBase = 10;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Beast };

//    card->_onDeploy = [=](Field &ally, Field &) {
//        clearHazardsFromItsRow(card, ally);
//    };
//    return card;
//}

//Card *Cards::createGriffin()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132312";
//    card->power = card->powerBase = 9;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Beast };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronze, isDeathwish}, AllyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        target->onDestroy(ally, enemy, _findRowAndPos(target, ally));
//    };
//    return card;
//}

//Card *Cards::createBridgeTroll()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201700";
//    card->power = card->powerBase = 10;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Ogroid };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        std::vector<int> rowsWithHazzards;
//        for (int rowInd = 0; rowInd < 3; ++rowInd) {
//            const RowEffect rowEffect = enemy.rowEffect(Row(rowInd));
//            const bool isHazzard = (0 < rowEffect) && (rowEffect <= 9);
//            if (!isHazzard)
//                continue;
//            rowsWithHazzards.push_back(rowInd + 3);
//        }
//        _rowSelected = -1;
//        startChoiceToSelectRow(ally, enemy, card, rowsWithHazzards);
//    };

//    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
//        if (_rowSelected == -1) {
//            _rowSelected = screenRow;
//            std::vector<int> otherRows = {3, 4, 5};
//            otherRows.erase(otherRows.begin() + screenRow - 3);
//            startChoiceToSelectRow(ally, enemy, card, otherRows);
//            return;
//        }
//        applyRowEffect(ally, enemy, screenRow, enemy.rowEffect(Row(_rowSelected - 3)));
//        applyRowEffect(ally, enemy, _rowSelected, NoRowEffect);
//    };
//    return card;
//}

//Card *Cards::createCockatrice()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200233";
//    card->power = card->powerBase = 6;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Draconid };


//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        reset(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createNekurat()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132220";
//    card->power = card->powerBase = 5;
//    card->rarity = Silver;
//    card->faction = Monster;
//    card->tags = { Vampire };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        spawnNewCard(new Moonlight(), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createSiren()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200112";
//    card->power = card->powerBase = 4;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Beast };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (Card *moonlight = random(cardsFiltered(ally, enemy, {isCopy<Moonlight>}, AllyDeck), ally.rng))
//            playExistedCard(moonlight, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createLamia()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132409";
//    card->power = card->powerBase = 6;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Beast };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        damage(target, rowEffectUnderUnit(target, enemy) == BloodMoonEffect ? 7 : 4 , ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createNekker()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132305";
//    card->power = card->powerBase = 4;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Ogroid };

//    card->_onAllyConsume = [=](Field &ally, Field &enemy, Card *) {
//        if (!isIn(card, ally.discard))
//            boost(card, 1, ally, enemy, card);
//    };

//    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &rowAndPos) {
//        if (Card *copy = random(cardsFiltered(ally, enemy, {isCopy<Nekker>}, AllyDeck), ally.rng))
//            moveExistedUnitToPos(copy, rowAndPos, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createNekkerWarrior()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132211";
//    card->power = card->powerBase = 9;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Ogroid };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronze}, AllyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        int n = 2;
//        while (n--) {
//            Card *card = target->defaultCopy();
//            addAsNew(ally, card);
//            putToDeck(card, ally, enemy, DeckPosBottom, card);
//        }
//    };
//    return card;
//}

//Card *Cards::createSlyzard()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200539";
//    card->power = card->powerBase = 2;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Draconid };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronze, isUnit}, AllyDiscard);
//    };

//    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
//        consume(target, ally, enemy, card);
//        if (Card *copy = random(cardsFiltered(ally, enemy, {isCopy(target->name)}, AllyDeck), ally.rng))
//            playExistedCard(copy, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createWerecat()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201599";
//    card->power = card->powerBase = 5;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Beast, Cursed };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
//        damage(target, 5, ally, enemy, card);
//        for (Card *card : cardsFiltered(ally, enemy, {}, EnemyBoard))
//            if (rowEffectUnderUnit(card, enemy) == BloodMoonEffect)
//                damage(card, 1, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createHarpy()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132315";
//    card->power = card->powerBase = 4;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Beast };

//    card->_onOtherAllyDestroyed = [=](Card *other, Field &ally, Field &enemy, const RowAndPos rowAndPos) {
//        if (!isIn(card, ally.deck) || !hasTag(other, Beast))
//            return;

//        for (Card *card : cardsFiltered(ally, enemy, {isCopy<Harpy>, otherThan(card)}, AllyDeckShuffled)) {
//            Harpy *harpy = static_cast<Harpy *>(card);
//            harpy->_allyDestroyedToCopy.insert({other, card});
//        }

//        if (_allyDestroyedToCopy.find(other) == _allyDestroyedToCopy.end())
//            moveExistedUnitToPos(card, rowAndPos, ally, enemy, card);

//        _allyDestroyedToCopy.clear();
//    };
//    return card;
//}

//Card *Cards::createWildHuntDrakkar()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200301";
//    card->power = card->powerBase = 7;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { WildHunt, Machine };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        for (Card *card : cardsFiltered(ally, enemy, {hasTag(WildHunt)}, AllyBoard))
//            boost(card, 1, ally, enemy, card);
//    };

//    card->_onOtherAllyAppears = [=](Card *card, Field &ally, Field &enemy) {
//        if (!isOnBoard(card, ally) || !hasTag(card, WildHunt))
//            return;
//        boost(card, 1, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createGeels()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "131102";
//    card->power = card->powerBase = 1;
//    card->rarity = Gold;
//    card->faction = Monster;
//    card->tags = { WildHunt, Officer };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        std::vector<Card *> variants;
//        if ((_gold = random(cardsFiltered(ally, enemy, {isGold}, AllyDeck), ally.rng)))
//            variants.push_back(_gold);
//        if ((_silver = random(cardsFiltered(ally, enemy, {isSilver}, AllyDeck), ally.rng)))
//            variants.push_back(_silver);
//        startChoiceToTargetCard(ally, enemy, card, variants);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//        if (target == _gold && _silver)
//            putToDeck(_silver, ally, enemy, DeckPosTop, card);
//        else if (target == _silver && _gold)
//            putToDeck(_gold, ally, enemy, DeckPosTop, card);
//    };

//    return card;
//}

//Card *Cards::createWildHuntRider()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132310";
//    card->power = card->powerBase = 10;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { WildHunt, Soldier };

//    // NOTE: ability is implemented inside the weather trigger
//    return card;
//}

//Card *Cards::createVranWarrior()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132308";
//    card->power = card->powerBase = 6;
//    card->rarity = Bronze;
//    card->faction = Monster;
//    card->tags = { Draconid, Soldier };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        setTimer(card, ally, enemy, 2);
//        if (Card *card = cardNextTo(card, ally, enemy, 1))
//            boost(card, consume(card, ally, enemy, card), ally, enemy, card);
//    };

//    card->_onTurnStart = [=](Field &ally, Field &enemy) {
//        if (isOnBoard(card, ally) && tick(card, ally, enemy))
//            onDeploy(ally, enemy);
//    };
//    return card;
//}

//Card *Cards::createAnCraiteArmorsmith()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "152317";
//    card->power = card->powerBase = 7;
//    card->rarity = Bronze;
//    card->faction = Skellige;
//    card->tags = { ClanAnCraite, Support };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AllyBoard, 2);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        heal(target, ally, enemy, card);
//        gainArmor(target, 3, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createAvalach()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132105";
//    card->power = card->powerBase = 8;
//    card->rarity = Gold;
//    card->faction = Neutral;
//    card->tags = { Elf, Mage };
//    card->isDoomed = true;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (ally.passed || enemy.passed)
//            return;

//        drawACard(ally, enemy,  card);
//        drawACard(enemy, ally,  card);

//        drawACard(ally, enemy,  card);
//        drawACard(enemy, ally,  card);
//    };
//    return card;
//}

//Card *Cards::createAvalachSage()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112112";
//    card->power = card->powerBase = 3;
//    card->rarity = Gold;
//    card->faction = Neutral;
//    card->tags = { Elf, Mage };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (Card *card = random(cardsFiltered(ally, enemy, {isSilverOrGold, isUnit}, EnemyDeckStarting), ally.rng))
//            spawnNewCard(card->defaultCopy(), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createRaghNarRoog()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "113101";
//    card->isSpecial = true;
//    card->rarity = Gold;
//    card->faction = Neutral;
//    card->tags = { Hazard, Spell };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        for (int screenRow = 3; screenRow < 6; ++screenRow)
//            applyRowEffect(ally, enemy, screenRow, RaghNarRoogEffect);
//    };
//    return card;
//}

//Card *Cards::createGeraltProfessional()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201772";
//    card->power = card->powerBase = 7;
//    card->rarity = Gold;
//    card->faction = Neutral;
//    card->tags = { Witcher };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (target->faction == Monster)
//            return putToDiscard(target, ally, enemy, card);

//        damage(target, 4, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createGeraltAard()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112111";
//    card->power = card->powerBase = 6;
//    card->rarity = Gold;
//    card->faction = Neutral;
//    card->tags = { Witcher };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard, 3);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (!damage(target, 3, ally, enemy, card)) {
//            const RowAndPos rowAndPos = _findRowAndPos(target, enemy);
//            const Row rowAbove = std::min(Row(rowAndPos.row() + 1), Seige);
//            if (rowAbove != rowAndPos.row())
//                moveExistedUnitToPos(target, rowAndPosLastInExactRow(enemy, rowAbove), enemy, ally, card);
//        }
//    };
//    return card;
//}

//Card *Cards::createGeraltYrden()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201523";
//    card->power = card->powerBase = 6;
//    card->rarity = Gold;
//    card->faction = Neutral;
//    card->tags = { Witcher };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectRow(ally, enemy, card);
//    };

//    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
//        for (Card *card : cardsInRow(ally, enemy, screenRow)) {
//            reset(card, ally, enemy, card);
//            removeAllStatuses(card, ally, enemy, card);
//        }
//    };
//    return card;
//}

//Card *Cards::createCiriDash()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112110";
//    card->power = card->powerBase = 11;
//    card->rarity = Gold;
//    card->faction = Neutral;
//    card->tags = { Cintra, Witcher };

//    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
//        onDiscard(ally, enemy);
//    };

//    card->_onDiscard = [=](Field &ally, Field &enemy) {
//        putToDeck(card, ally, enemy, DeckPosRandom, card);
//        strengthen(card, 3, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createAguara()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200062";
//    card->power = card->powerBase = 5;
//    card->rarity = Gold;
//    card->faction = Neutral;
//    card->tags = { Relict, Cursed };

//    card->_onDeploy = [=](Field & ally, Field &enemy) {
//        auto *option1 = createOption(card, BoostLowest);
//        option1->text = "Boost the Lowest ally by 5.";

//        auto *option2 = createOption(card, BoostInHand);
//        option2->text = "Boost a random unit in your hand by 5.";

//        auto *option3 = createOption(card, DamageHighest);
//        option3->text = "Deal 5 damage to the Highest enemy.";

//        auto *option4 = createOption(card, CharmElf);
//        option4->text = "Charm a random enemy Elf with 5 power or less.";

//        _optionsSelected.clear();
//        startChoiceToSelectOption(ally, enemy, card, {option1, option2, option3, option4}, 2);
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (isOption(target, BoostLowest))
//            if (Card *card = lowest(cardsFiltered(ally, enemy, {}, AllyBoard), ally.rng))
//                boost(card, 5, ally, enemy, card);

//        if (isOption(target, BoostInHand))
//            if (Card *card = random(cardsFiltered(ally, enemy, {isUnit}, AllyHand), ally.rng))
//                boost(card, 5, ally, enemy, card);

//        if (isOption(target, DamageHighest))
//            if (Card *card = highest(cardsFiltered(ally, enemy, {}, EnemyBoard), ally.rng))
//                damage(card, 5, ally, enemy, card);

//        if (isOption(target, CharmElf))
//            if (Card *card = random(cardsFiltered(ally, enemy, {hasTag(Elf), hasPowerXorLess(5)}, EnemyBoard), ally.rng))
//                charm(card, ally, enemy, card);

//        _optionsSelected.push_back(target);

//        /// after 2 choices done, delete selected options
//        if (_optionsSelected.size() == 2) {
//            delete _optionsSelected[0];
//            delete _optionsSelected[1];
//            _optionsSelected.clear();
//        }
//    };
//    return card;
//}

//Card *Cards::createAguaraTrueForm()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200056";
//    card->power = card->powerBase = 2;
//    card->rarity = Gold;
//    card->faction = Neutral;
//    card->tags = { Relict, Cursed };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceCreateOptions(ally, enemy, card, {isBronzeOrSilver, hasTag(Spell)});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        spawnNewCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createKorathiHeatwave()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200018";
//    card->isSpecial = true;
//    card->rarity = Gold;
//    card->faction = Neutral;
//    card->tags = { Hazard };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        for (int screenRow = 3; screenRow < 6; ++screenRow)
//            applyRowEffect(ally, enemy, screenRow, KorathiHeatwaveEffect);
//    };

//    return card;
//}

//Card *Cards::createAleOfTheAncestors()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200532";
//    card->power = card->powerBase = 10;
//    card->rarity = Gold;
//    card->faction = Neutral;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        applyRowEffect(ally, enemy, 2 - int(_findRowAndPos(card, ally).row()), GoldenFrothEffect);
//    };
//    return card;
//}

//Card *Cards::createMahakamAle()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200519";
//    card->isSpecial = true;
//    card->rarity = Bronze;
//    card->faction = Neutral;
//    card->tags = { Alchemy };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        for (const Row row : std::vector<Row>{Meele, Range, Seige})
//            if (Card *card = random(ally.row(row), ally.rng))
//                boost(card, 4, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createOdrin()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "122213";
//    card->power = card->powerBase = 8;
//    card->rarity = Silver;
//    card->faction = NothernRealms;
//    card->tags = { Kaedwen, Soldier };

//    card->_onTurnStart = [=](Field &ally, Field &enemy) {
//        if (!isOnBoard(card, ally))
//            return;
//        if (!moveToRandomRow(card, ally, enemy, card))
//            return;
//        for (Card *card : cardsFiltered(ally, enemy, {isOnSameRow(&ally, card), otherThan(card)}, AllyBoard))
//            boost(card, 1, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createToruviel()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142204";
//    card->power = card->powerBase = 6;
//    card->isAmbush = true;
//    card->rarity = Silver;
//    card->faction = Scoiatael;
//    card->tags = { Elf, Officer };

//    card->_onDeploy = [=](Field &, Field &) {
//        isAmbush = true;
//    };

//    card->_onOpponentPass = [=](Field &ally, Field &enemy) {
//        flipOver(card, ally, enemy);

//        const std::vector<Card *> cardsToBoost {
//            cardNextTo(card, ally, enemy, -2),
//                    cardNextTo(card, ally, enemy, -1),
//                    cardNextTo(card, ally, enemy, 1),
//                    cardNextTo(card, ally, enemy, 2),
//        };
//        for (Card *card : cardsToBoost)
//            if (card != nullptr)
//                boost(card, 2, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createCiri()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112101";
//    card->power = card->powerBase = 6;
//    card->rarity = Gold;
//    card->faction = Neutral;
//    card->tags = { Cintra, Witcher };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        gainArmor(card, 2, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createMilva()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142104";
//    card->power = card->powerBase = 6;
//    card->rarity = Gold;
//    card->faction = Scoiatael;
//    card->tags = { Soldier };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (Card *card = highest(cardsFiltered(ally, enemy, {isBronzeOrSilver}, AllyBoard), ally.rng))
//            putToDeck(card, ally, enemy, DeckPosRandom, card);
//        if (Card *card = highest(cardsFiltered(ally, enemy, {isBronzeOrSilver}, EnemyBoard), ally.rng))
//            putToDeck(card, enemy, ally, DeckPosRandom, card);
//    };
//    return card;
//}


//Card *Cards::createPrincessPavetta()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "122210";
//    card->power = card->powerBase = 3;
//    card->rarity = Silver;
//    card->faction = NothernRealms;
//    card->tags = { Cintra, Mage };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (Card *card = lowest(cardsFiltered(ally, enemy, {isBronzeOrSilver}, AllyBoard), ally.rng))
//            putToDeck(card, ally, enemy, DeckPosRandom, card);
//        if (Card *card = lowest(cardsFiltered(ally, enemy, {isBronzeOrSilver}, EnemyBoard), ally.rng))
//            putToDeck(card, enemy, ally, DeckPosRandom, card);
//    };
//    return card;
//}

//Card *Cards::createTheGuardian()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162401";
//    card->power = card->powerBase = 11;
//    card->rarity = Silver;
//    card->faction = Nilfgaard;
//    card->tags = { Construct };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        auto *guardian = new LesserGuardian();
//        addAsNew(enemy, guardian);
//        putToDeck(guardian, enemy, ally, DeckPosTop, card);
//    };
//    return card;
//}

//TheGuardian::LesserGuardian::LesserGuardian()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162401";
//    card->power = card->powerBase = 6;
//    card->rarity = Bronze;
//    card->faction = Nilfgaard;
//    card->tags = { Construct };
//    return card;
//}

//Card *Cards::createGaunterODimm()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "132215";
//    card->power = card->powerBase = 6;
//    card->rarity = Gold;
//    card->faction = Neutral;
//    card->tags = { Relict };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        _picked = random(createAll(patch), ally.rng);

//        auto *option1 = createOption(card, Less6);
//        option1->text = "Picked card power is less than 6.";

//        auto *option2 = createOption(card, Equal6);
//        option2->text = "Picked card power is 6.";

//        auto *option3 = createOption(card, More6);
//        option3->text = "Picked card power is more than 6.";

//        startChoiceToSelectOption(ally, enemy, card, {option1, option2, option3});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        const bool guessed =
//                (isOption(target, Less6) && (_picked->power < 6))
//                || (isOption(target, Equal6) && (_picked->power == 6))
//                || (isOption(target, More6) && (_picked->power > 6));
//        delete target;
//        if (!guessed) {
//            _picked = nullptr;
//            return;
//        }
//        spawnNewCard(_picked, ally, enemy, card);
//        _picked = nullptr;
//    };
//    return card;
//}

//Card *Cards::createKaedweniSergeant()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "122214";
//    card->power = card->powerBase = 9;
//    card->rarity = Bronze;
//    card->faction = NothernRealms;
//    card->tags = { Kaedwen };
//    card->isCrew = true;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        gainArmor(card, 3, ally, enemy, card);
//        clearHazardsFromItsRow(card, ally);
//    };
//    return card;
//}

//Card *Cards::createReinforcedBallista()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "122302";
//    card->power = card->powerBase = 7;
//    card->rarity = Bronze;
//    card->faction = NothernRealms;
//    card->tags = { Machine };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        int n = nCrewed(card, ally);
//        while (n--)
//            startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        damage(target, 2, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createSigismundDijkstra()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "122105";
//    card->isLoyal = false;
//    card->power = card->powerBase = 4;
//    card->rarity = Gold;
//    card->faction = NothernRealms;
//    card->tags = { Redania };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        for (Card *card : firsts(ally.deck, 2))
//            playExistedCard(card, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createWhiteFrost()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "113206";
//    card->isSpecial = true;
//    card->rarity = Silver;
//    card->faction = Neutral;
//    card->tags = { Hazard };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectRow(ally, enemy, card, {3, 4, 5});
//    };

//    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
//        for (int _screenRow = std::max(3, screenRow - 1); _screenRow <= screenRow; ++_screenRow)
//            applyRowEffect(ally, enemy, _screenRow, BitingFrostEffect);
//    };
//    return card;
//}


//Card *Cards::createWolfsbane()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200226";
//    card->rarity = Gold;
//    card->faction = Neutral;
//    card->isSpecial = true;
//    card->tags = { Organic, Alchemy };

//    card->_onDiscard = [=](Field &ally, Field &enemy) {
//        setTimer(card, ally, enemy, 3);
//    };

//    card->_onTurnEnd = [=](Field &ally, Field &enemy) {
//        if (!isIn(card, ally.discard))
//            return;
//        if (!tick(card, ally, enemy))
//            return;
//        if (Card *card = highest(cardsFiltered(ally, enemy, {}, EnemyBoard), ally.rng))
//            damage(card, 6, ally, enemy, card);
//        if (Card *card = lowest(cardsFiltered(ally, enemy, {}, AllyBoard), ally.rng))
//            boost(card, 6, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createDunBanner()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "122313";
//    card->power = card->powerBase = 4;
//    card->rarity = Bronze;
//    card->faction = NothernRealms;
//    card->tags = { Kaedwen, Soldier };

//    card->_onTurnStart = [=](Field &ally, Field &enemy) {
//        if (!isIn(card, ally.deck))
//            return;
//        const int scoreDiff = powerField(enemy) - powerField(ally);
//        if (scoreDiff <= 25)
//            return;
//        for (Card *card : cardsFiltered(ally, enemy, {isCopy<DunBanner>}, AllyDeck))
//            moveExistedUnitToPos(card, rowAndPosRandom(ally), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createAelirenn()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142211";
//    card->power = card->powerBase = 6;
//    card->rarity = Silver;
//    card->faction = Scoiatael;
//    card->tags = { Elf, Officer };

//    card->_onTurnEnd = [=](Field &ally, Field &enemy) {
//        if (!isIn(card, ally.deck))
//            return;
//        const int nElfs = int(cardsFiltered(ally, enemy, {hasTag(Elf)}, AllyBoard).size());
//        if (nElfs < 5)
//            return;
//        moveExistedUnitToPos(card, rowAndPosRandom(ally), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createHanmarvynsDream()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200079";
//    card->rarity = Gold;
//    card->faction = Neutral;
//    card->isSpecial = true;
//    card->tags = { Alchemy };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isGold, isUnit, hasNoTag(Leader)}, EnemyDiscard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        Card *copy = target->defaultCopy();
//        spawnNewCard(copy, ally, enemy, card);
//        boost(copy, 2, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createBlackBlood()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201697";
//    card->rarity = Silver;
//    card->faction = Neutral;
//    card->isSpecial = true;
//    card->tags = { Alchemy, Item };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        auto *option1 = createOption(card, Create);
//        option1->text = "Create a Bronze Necrophage or Vampire and boost it by 2";

//        auto *option2 = createOption(card, Destroy);
//        option2->text = "Destroy a Bronze or Silver Necrophage or Vampire.";

//        _choosen = nullptr;
//        startChoiceToSelectOption(ally, enemy, card, {option1, option2});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (!_choosen && isOption(target, Create)) {
//            _choosen = target;
//            startChoiceCreateOptions(ally, enemy, card, {isBronze, hasAnyOfTags({Necrophage, Vampire})});
//            return;
//        }

//        if (!_choosen && isOption(target, Destroy)) {
//            _choosen = target;
//            startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, hasAnyOfTags({Necrophage, Vampire})}, AnyBoard);
//            return;
//        }

//        if (isOption(_choosen, Create)) {
//            boost(target, 2, ally, enemy, card);
//            spawnNewCard(target, ally, enemy, card);

//            delete _choosen;
//            _choosen = nullptr;
//            return;
//        }

//        assert(false);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        assert(isOption(_choosen, Destroy));

//        putToDiscard(target, ally, enemy, card);

//        delete _choosen;
//        _choosen = nullptr;
//    };
//    return card;
//}

//Card *Cards::createBekkersRockslide()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201634";
//    card->rarity = Silver;
//    card->faction = Neutral;
//    card->isSpecial = true;
//    card->tags = { Spell };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        for (Card * card : randoms(cardsFiltered(ally, enemy, {}, EnemyBoard), 10, ally.rng))
//            damage(card, 2, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createBekkersDarkMirror()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "113315";
//    card->rarity = Silver;
//    card->faction = Neutral;
//    card->isSpecial = true;
//    card->tags = { Spell };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        Card *high = highest(cardsFiltered(ally, enemy, {}, AnyBoard), ally.rng);
//        Card *low = lowest(cardsFiltered(ally, enemy, {}, AnyBoard), ally.rng);
//        if (/*highest == nullptr ||*/ high == low)
//            return;
//        int transPower = std::min(10, high->power - low->power);
//        setPower(high, high->power - transPower, ally, enemy, card);
//        setPower(low, low->power + transPower, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createMerigoldsHailstorm()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "113202";
//    card->rarity = Silver;
//    card->faction = Neutral;
//    card->isSpecial = true;
//    card->tags = { Spell };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectRow(ally, enemy, card);
//    };

//    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
//        for (Card *card : cardsInRow(ally, enemy, screenRow)) {
//            if (isBronzeOrSilver(card))
//                setPower(card, card->power - half(card->power), ally, enemy, card);
//        }
//    };
//    return card;
//}

//Card *Cards::createNecromancy()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200020";
//    card->rarity = Silver;
//    card->faction = Neutral;
//    card->isSpecial = true;
//    card->tags = { Spell };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, isUnit}, BothDiscard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if(isOnBoard(target, ally)) {
//            boost(target, transPower, ally, enemy, card);
//            return;
//        }
//        transPower = target->power;
//        banish(target, ally, enemy, card);
//        startChoiceToTargetCard(ally, enemy, card, {}, AllyBoard);
//    };
//    return card;
//}

//Card *Cards::createStammelfordsTremor()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "113204";
//    card->rarity = Bronze;
//    card->faction = Neutral;
//    card->isSpecial = true;
//    card->tags = { Spell };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        for (Card *card : cardsFiltered(ally, enemy, {}, EnemyBoard))
//            damage(card, 1, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createExpiredAle()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200530";
//    card->rarity = Silver;
//    card->faction = Neutral;
//    card->isSpecial = true;
//    card->tags = { Spell };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        for (const Row row : std::vector<Row>{Meele, Range, Seige})
//            if (Card *card = highest(enemy.row(row), enemy.rng))
//                damage(card, 6, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createTrialOfTheGrasses()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200078";
//    card->rarity = Gold;
//    card->faction = Neutral;
//    card->isSpecial = true;
//    card->tags = { Alchemy };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if ((hasTag(target, Witcher) || !damage(target, 10, ally, enemy, card)) && target->power < 25)
//            setPower(target, 25, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createDimeritiumBomb()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "113205";
//    card->rarity = Silver;
//    card->faction = Neutral;
//    card->isSpecial = true;
//    card->tags = { Alchemy };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectRow(ally, enemy, card);
//    };

//    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
//        for (Card *card : cardsInRow(ally, enemy, screenRow)) {
//            if (isBoosted(card))
//                reset(card, ally, enemy, card);
//        }
//    };
//    return card;
//}

//Card *Cards::createGarrison()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201639";
//    card->rarity = Silver;
//    card->faction = Neutral;
//    card->isSpecial = true;
//    card->tags = { Tactics };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        // TODO: implenemt an ability
//        // NOTE: the same ability in TrissTelekinesis
//        //startChoiceCreateOptions(ally, card);
//    };
//    return card;
//}

//Card *Cards::createTheLastWish()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "113102";
//    card->rarity = Silver;
//    card->faction = Neutral;
//    card->isSpecial = true;
//    card->tags = { Spell };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, randoms(cardsFiltered(ally, enemy, {}, AllyDeck), 2, ally.rng));
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createDimeritiumShackles()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "113319";
//    card->rarity = Bronze;
//    card->faction = Neutral;
//    card->isSpecial = true;
//    card->tags = { Alchemy, Item };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
//    };

//    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
//        toggleLock(target, ally, enemy, card);
//        if (isOnBoard(target, enemy))
//            damage(target, 4, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createWyvernScaleShield()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "133301";
//    card->rarity = Bronze;
//    card->faction = Neutral;
//    card->isSpecial = true;
//    card->tags = { Item };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        if (cardsFiltered(ally, enemy, {}, AnyBoard).size() == 0)
//            return;
//        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, isUnit}, AllyHand);
//        _boostAmount = 0;
//    };

//    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
//        if (_boostAmount <= 0) {
//            _boostAmount = target->powerBase;
//            startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
//            return;
//        }
//        boost(target, _boostAmount, ally, enemy, card);
//        _boostAmount = 0;
//    };
//    return card;
//}

//Card *Cards::createMastercraftedSpear()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201656";
//    card->rarity = Bronze;
//    card->faction = Neutral;
//    card->isSpecial = true;
//    card->tags = { Item };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        if (cardsFiltered(ally, enemy, {}, AnyBoard).size() == 0)
//            return;
//        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, isUnit}, AllyHand);
//        _damageAmount = 0;
//    };

//    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
//        if (_damageAmount <= 0) {
//            _damageAmount = target->powerBase;
//            startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
//            return;
//        }
//        damage(target, _damageAmount, ally, enemy, card);
//        _damageAmount = 0;
//    };
//    return card;
//}

//Card *Cards::createPetrisPhilter()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200008";
//    card->rarity = Bronze;
//    card->faction = Neutral;
//    card->isSpecial = true;
//    card->tags = { Alchemy, Item };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        for (Card *card : randoms(cardsFiltered(ally, enemy, {}, AllyBoard), 6, ally.rng))
//            boost(card, 2, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createShrike()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200009";
//    card->rarity = Bronze;
//    card->faction = Neutral;
//    card->isSpecial = true;
//    card->tags = { Alchemy, Item };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        for (Card *card : randoms(cardsFiltered(ally, enemy, {}, EnemyBoard), 6, ally.rng))
//            damage(card, 2, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createRoyalDecree()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200154";
//    card->rarity = Gold;
//    card->faction = Neutral;
//    card->isSpecial = true;
//    card->tags = { Tactics };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isGold, isUnit}, AllyDeck);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        boost(target, 2, ally, enemy, card);
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createUmasCurse()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200058";
//    card->rarity = Gold;
//    card->faction = Neutral;
//    card->isSpecial = true;
//    card->tags = { Spell };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceCreateOptions(ally, enemy, card, {isGold, isUnit, hasNoTag(Leader)});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        spawnNewCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createLacerate()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "153301";
//    card->rarity = Bronze;
//    card->faction = Neutral;
//    card->isSpecial = true;
//    card->tags = { Organic };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectRow(ally, enemy, card);
//    };

//    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
//        for (Card *card : cardsInRow(ally, enemy, screenRow))
//            damage(card, 3, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createCrowsEye()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200224";
//    card->rarity = Bronze;
//    card->faction = Neutral;
//    card->isSpecial = true;
//    card->tags = { Alchemy, Organic };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        const int extraDamage = int(cardsFiltered(ally, enemy, {isCopy<CrowsEye>}, AllyDiscard).size());
//        for (const Row row : std::vector<Row>{Meele, Range, Seige})
//            if (Card *card = highest(enemy.row(row), enemy.rng))
//                damage(card, 4 + extraDamage, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createDoppler()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201631";
//    card->rarity = Bronze;
//    card->faction = Neutral;
//    card->isSpecial = true;
//    card->tags = { };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        const int currentFaction = ally.leader ? ally.leader->faction : Neutral;
//        Card *card = random(_filtered({isFaction(currentFaction), isBronze, isUnit}, createAll(card->patch)), ally.rng)->defaultCopy();
//        spawnNewCard(card, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createSpores()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201744";
//    card->rarity = Bronze;
//    card->faction = Neutral;
//    card->isSpecial = true;
//    card->tags = { Organic };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectRow(ally, enemy, card);
//    };

//    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
//        for (Card *card : cardsInRow(ally, enemy, screenRow))
//            damage(card, 2, ally, enemy, card);
//        if (rowEffectInSreenRow(ally, enemy, screenRow) > 9)
//            applyRowEffect(ally, enemy, screenRow, NoRowEffect);
//    };
//    return card;
//}

//Card *Cards::createMardroeme()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "113320";
//    card->rarity = Bronze;
//    card->faction = Neutral;
//    card->isSpecial = true;
//    card->tags = { Alchemy, Organic };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        auto *option1 = createOption(card, Strengthen);
//        option1->text = "Reset a unit and Strengthen it by 3.";

//        auto *option2 = createOption(card, Weaken);
//        option2->text = "Reset a unit and Weaken it by 3.";

//        _choosen = nullptr;
//        startChoiceToSelectOption(ally, enemy, card, {option1, option2});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        _choosen = target;
//        startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        assert(_choosen);

//        reset(target, ally, enemy, card);
//        if (isOption(_choosen, Strengthen))
//            strengthen(target, 3, ally, enemy, card);

//        if (isOption(_choosen, Weaken))
//            weaken(target, 3, ally, enemy, card);

//        delete _choosen;
//        _choosen = nullptr;
//    };
//    return card;
//}

//Card *Cards::createSihil()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201632";
//    card->rarity = Gold;
//    card->faction = Neutral;
//    card->isSpecial = true;
//    card->tags = { Item };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        auto *option1 = createOption(card, DamageOdd);
//        option1->text = "Deal 3 damage to all enemies with odd power.";

//        auto *option2 = createOption(card, DamageEven);
//        option2->text = "Deal 3 damage to all enemies with even power.";

//        auto *option3 = createOption(card, PlayFromDeck);
//        option3->text = "Play a random Bronze or Silver unit from your deck.";

//        startChoiceToSelectOption(ally, enemy, card, {option1, option2, option3});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (isOption(target, DamageOdd)) {
//            for (Card *card : cardsFiltered(ally, enemy, {hasOddPower}, EnemyBoard))
//                damage(card, 3, ally, enemy, card);
//            return;
//        }

//        if (isOption(target, DamageEven)) {
//            for (Card *card : cardsFiltered(ally, enemy, {hasEvenPower}, EnemyBoard))
//                damage(card, 3, ally, enemy, card);
//            return;
//        }

//        if (isOption(target, PlayFromDeck)) {
//            if (Card *card = random(cardsFiltered(ally, enemy, {isBronzeOrSilver, isUnit}, AllyDeck), ally.rng))
//                playExistedCard(card, ally, enemy, card);
//            return;
//        }

//        assert(false);
//    };
//    return card;
//}

//Card *Cards::createDragonsDream()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201637";
//    card->rarity = Silver;
//    card->faction = Neutral;
//    card->isSpecial = true;
//    card->tags = { Alchemy, Item };

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectRow(ally, enemy, card, {3, 4, 5});
//    };

//    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
//        applyRowEffect(ally, enemy, screenRow, DragonsDreamEffect);
//    };
//    return card;
//}

//Card *Cards::createEskelPathfinder()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200236";
//    card->power = card->powerBase = 7;
//    card->rarity = Gold;
//    card->faction = Neutral;
//    card->tags = { Witcher };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, isNotBoosted}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        putToDiscard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createVesemirMentor()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200237";
//    card->tags = { Witcher };
//    card->power = card->powerBase = 6;
//    card->faction = Neutral;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, hasTag(Alchemy)}, AllyDeckShuffled);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createLambertSwordmaster()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200235";
//    card->tags = { Witcher };
//    card->power = card->powerBase = 8;
//    card->faction = Neutral;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        for (Card *card : findCopies(target, cardsFiltered(ally, enemy, {}, EnemyBoard)))
//            damage(card, 4, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createRegisHigherVampire()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112105";
//    card->tags = { Witcher };
//    card->power = card->powerBase = 6;
//    card->faction = Neutral;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, randoms(cardsFiltered(ally, enemy, {isBronze, isUnit}, EnemyDeck), 3, ally.rng));
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        boost(card, consume(target, ally, enemy, card), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createZoltanScoundrel()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112109";
//    card->tags = { Dwarf };
//    card->power = card->powerBase = 8;
//    card->faction = Neutral;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectOption(ally, enemy, card, {new DudaCompanion(), new DudaAgitator()});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        spawnNewCard(target, ally, enemy, card);
//    };
//    return card;
//}

//ZoltanScoundrel::DudaCompanion::DudaCompanion()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112403";
//    card->tags = { Beast };
//    card->isDoomed = true;
//    card->power = card->powerBase = 1;
//    card->faction = Neutral;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        const std::vector<Card *> cardsToBoost {
//            cardNextTo(card, ally, enemy, -2),
//                    cardNextTo(card, ally, enemy, -1),
//                    cardNextTo(card, ally, enemy, 1),
//                    cardNextTo(card, ally, enemy, 2),
//        };
//        for (Card *card : cardsToBoost)
//            if (card != nullptr)
//                boost(card, 2, ally, enemy, card);
//    };
//    return card;
//}

//ZoltanScoundrel::DudaAgitator::DudaAgitator()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112404";
//    card->tags = { Beast };
//    card->isDoomed = true;
//    card->isLoyal = false;
//    card->power = card->powerBase = 1;
//    card->faction = Neutral;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        const std::vector<Card *> cardsToDamage {
//            cardNextTo(card, ally, enemy, -2),
//                    cardNextTo(card, ally, enemy, -1),
//                    cardNextTo(card, ally, enemy, 1),
//                    cardNextTo(card, ally, enemy, 2),
//        };
//        for (Card *card : cardsToDamage)
//            if (card != nullptr)
//                damage(card, 2, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createYenneferConjurer()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112113";
//    card->tags = { Mage, Aedirn };
//    card->power = card->powerBase = 10;
//    card->faction = Neutral;
//    card->rarity = Gold;

//    card->_onTurnEnd = [=](Field &ally, Field &enemy) {
//        if (!isOnBoard(card, ally))
//            return;
//        for (Card *card : highests(cardsFiltered(ally, enemy, {}, EnemyBoard)))
//            damage(card, 1, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createTrissMerigold()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112106";
//    card->tags = { Mage, Temeria };
//    card->power = card->powerBase = 10;
//    card->faction = Neutral;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        damage(target, 5, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createTrissTelekinesis()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201773";
//    card->tags = { Mage, Temeria };
//    card->power = card->powerBase = 6;
//    card->faction = Neutral;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        // TODO: implenemt an ability
//        // NOTE: the same ability in Garrison
//        //startChoiceCreateOptions(ally, card);
//    };
//    return card;
//}

//Card *Cards::createDorregarayOfVole()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200087";
//    card->tags = { Mage };
//    card->power = card->powerBase = 1;
//    card->faction = Neutral;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceCreateOptions(ally, enemy, card, {isBronzeOrSilver, hasAnyOfTags({Beast, Draconid})});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        spawnNewCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createDandelionVainglory()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201774";
//    card->power = card->powerBase = 9;
//    card->rarity = Gold;
//    card->faction = Neutral;
//    card->tags = { Support };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        const auto isFellow = [](Card *card) {
//            return isCopy<GeraltAard>(card)
//                    || isCopy<GeraltIgni>(card)
//                    || isCopy<GeraltYrden>(card)
//                    || isCopy<GeraltOfRivia>(card)
//                    || isCopy<GeraltProfessional>(card)
//                    || isCopy<Yennefer>(card)
//                    || isCopy<YenneferConjurer>(card)
//                    || isCopy<YenneferEnchantress>(card)
//                    || isCopy<YenneferNecromancer>(card)
//                    || isCopy<TrissMerigold>(card)
//                    || isCopy<TrissButterflies>(card)
//                    || isCopy<TrissTelekinesis>(card)
//                    || isCopy<ZoltanChivay>(card)
//                    || isCopy<ZoltanScoundrel>(card);
//        };

//        int boostNumber = cardsFiltered(ally, enemy, {isFellow}, AllyDeckStarting).size();
//        if (boostNumber <= 0)
//            return;
//        boost(card, boostNumber * 3, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createCyprianWiley()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112214";
//    card->power = card->powerBase = 8;
//    card->rarity = Silver;
//    card->faction = Neutral;
//    card->tags = { Redania };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        weaken(target, 4, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createDudu()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112201";
//    card->power = card->powerBase = 1;
//    card->rarity = Silver;
//    card->faction = Neutral;
//    card->tags = { Relict };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        setPower(card, target->power, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createIhuarraquax()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201817";
//    card->tags = { Beast };
//    card->power = card->powerBase = 7;
//    card->faction = Neutral;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        damageDone = false;
//        setTimer(card, ally, enemy, 1);
//        damage(card, 5, ally, enemy, card);
//    };

//    card->_onPowerChanged = [=](Field &ally, Field &enemy, const Card *, const PowerChangeType) {
//        if ((timer > 0) && (power == powerBase))
//            tick(card, ally, enemy);
//    };

//    card->_onTurnEnd = [=](Field &ally, Field &enemy) {
//        if((timer != -1) || (damageDone) || (!isOnBoard(card, ally)))
//            return;
//        for (Card *card : randoms(cardsFiltered(ally, enemy, {}, EnemyBoard), 3, ally.rng))
//            damage(card, 7, ally, enemy, card);
//        damageDone = true;
//    };
//    return card;
//}

//Card *Cards::createMahakamMarauder()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200042";
//    card->power = card->powerBase = 7;
//    card->rarity = Bronze;
//    card->faction = Scoiatael;
//    card->tags = { Dwarf, Soldier };

//    card->_onPowerChanged = [=](Field &ally, Field &enemy, const Card *src, const PowerChangeType type) {
//        if((!isOnBoard(card, ally)) || (type == Reset) || (src == card))
//            return;
//        boost(card, 2, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createZoltanChivay()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142105";
//    card->tags = { Dwarf };
//    card->power = card->powerBase = 8;
//    card->faction = Scoiatael;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard, 3);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        const Row row = _findRowAndPos(card, ally).row();
//        if (isOnBoard(target, ally)) {
//            strengthen(target, 2, ally, enemy, card);
//            moveExistedUnitToPos(target, rowAndPosLastInExactRow(ally, row), ally, enemy, card);
//            return;
//        }
//        if (isOnBoard(target, enemy)) {
//            damage(target, 2, ally, enemy, card);
//            moveExistedUnitToPos(target, rowAndPosLastInExactRow(enemy, row), enemy, ally, card);
//            return;
//        }
//        assert(false);
//    };
//    return card;
//}

//Card *Cards::createYenneferNecromancer()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201780";
//    card->tags = { Mage, Aedirn };
//    card->power = card->powerBase = 5;
//    card->faction = Nilfgaard;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, hasTag(Soldier)}, EnemyDiscard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createPhoenix()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201579";
//    card->tags = { Draconid };
//    card->isDoomed = true;
//    card->power = card->powerBase = 5;
//    card->faction = Neutral;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, hasTag(Draconid)}, AllyDiscard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createSaesenthessisBlaze()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201613";
//    card->tags = { Aedirn, Draconid };
//    card->power = card->powerBase = 11;
//    card->faction = Neutral;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        const std::vector<Card *> hand = ally.hand;
//        const int64_t nCards = hand.size();
//        for (Card *card : hand)
//            banish(card, ally, enemy, card);
//        for (int cardInd = 0; cardInd < nCards; ++cardInd)
//            drawACard(ally, enemy,  card);
//    };
//    return card;
//}

//Card *Cards::createVillentretenmerth()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112107";
//    card->tags = { Draconid };
//    card->power = card->powerBase = 10;
//    card->faction = Neutral;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        setTimer(card, ally, enemy, 3);
//    };

//    card->_onTurnStart = [=](Field &ally, Field &enemy) {
//        if (!tick(card, ally, enemy))
//            return;
//        for (Card *card : highests(cardsFiltered(ally, enemy, {otherThan(card)}, AnyBoard)))
//            putToDiscard(card, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createOcvist()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112206";
//    card->tags = { Draconid };
//    card->power = card->powerBase = 8;
//    card->faction = Neutral;
//    card->rarity = Silver;
//    card->timer = 4;

//    card->_onTurnStart = [=](Field &ally, Field &enemy) {
//        if (!isOnBoard(card, ally) || !tick(card, ally, enemy))
//            return;
//        for (Card *card : cardsFiltered(ally, enemy, {}, EnemyBoard))
//            damage(card, 1, ally, enemy, card);
//        putToHand(card, ally, enemy,  card);
//    };
//    return card;
//}

//Card *Cards::createMyrgtabrakke()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112205";
//    card->tags = { Draconid };
//    card->power = card->powerBase = 7;
//    card->faction = Neutral;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        for (int n = 0; n < 3; ++n)
//            startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        damage(target, 2, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createKingOfBeggars()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112213";
//    card->tags = { Support };
//    card->power = card->powerBase = 5;
//    card->faction = Neutral;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        const int boost = std::min(powerField(enemy) - powerField(ally), 10);
//        if (boost > 0)
//            strengthen(card, boost, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createOlgierdVonEverec()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112207";
//    card->tags = { Redania, Cursed };
//    card->power = card->powerBase = 5;
//    card->faction = Neutral;
//    card->rarity = Silver;

//    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
//        moveExistedUnitToPos(card, rowAndPosRandom(ally), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createIrisVonEverec()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112215";
//    card->tags = { Redania, Cursed };
//    card->isLoyal = false;
//    card->power = card->powerBase = 3;
//    card->faction = Neutral;
//    card->rarity = Silver;

//    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
//        for (Card *card : randoms(cardsFiltered(ally, enemy, {}, EnemyBoard), 5, ally.rng))
//            boost(card, 5, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createIrisCompanions()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200083";
//    card->tags = { Relict };
//    card->power = card->powerBase = 11;
//    card->faction = Neutral;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AllyDeck);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        putToHand(target, ally, enemy,  card);
//        putToDiscard(random(ally.hand, ally.rng), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createJohnny()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112211";
//    card->tags = { Relict };
//    card->power = card->powerBase = 9;
//    card->faction = Neutral;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AllyHand);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        putToDiscard(target, ally, enemy, card);
//        if(Card *card = random(cardsFiltered(ally, enemy, {isColor(target->rarity)}, EnemyDeckStarting), ally.rng)) {
//            Card *cardCopy = card->defaultCopy();
//            addAsNew(ally, cardCopy);
//            putToHand(cardCopy, ally, enemy,  card);
//        }
//    };
//    return card;
//}

//Card *Cards::createStregobor()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200091";
//    card->tags = { Mage };
//    card->power = card->powerBase = 10;
//    card->faction = Neutral;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (ally.passed || enemy.passed)
//            return;
//        if (Card *unit = first(cardsFiltered(ally, enemy, {isUnit}, AllyDeck))) {
//            putToHand(unit, ally, enemy,  card);
//            setPower(unit, 1, ally, enemy, card);
//        }
//        if (Card *unit = first(cardsFiltered(ally, enemy, {isUnit}, EnemyDeck))) {
//            putToHand(unit, enemy, ally,  card);
//            setPower(unit, 1, ally, enemy, card);
//        }
//    };

//    return card;
//}

//Card *Cards::createSarah()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "112212";
//    card->tags = { Relict };
//    card->power = card->powerBase = 11;
//    card->faction = Neutral;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AllyHand);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (Card *card = first(cardsFiltered(ally, enemy, {isColor(target->rarity)}, AllyDeck))) {
//            putToDeck(target, ally, enemy, DeckPosRandomButNotFirst, card);
//            putToHand(card, ally, enemy,  card);
//            // TODO: check if here we need to trigger onSwap or etc.
//        }
//    };
//    return card;
//}

//Card *Cards::createPeasantMilitia()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201753";
//    card->tags = { Tactics };
//    card->isSpecial = true;
//    card->faction = Neutral;
//    card->rarity = Bronze;

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectRow(ally, enemy, card, {0, 1, 2});
//    };

//    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
//        for(int i = 0; i < 3; i++) {
//            if (isRowFull(cardsInRow(ally, enemy, screenRow)))
//                return;
//            Card *card = new Peasant();
//            addAsNew(ally, card);
//            moveExistedUnitToPos(card, rowAndPosLastInExactRow(screenRow, ally, enemy), ally, enemy, card);
//        }
//    };
//    return card;
//}

//PeasantMilitia::Peasant::Peasant()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201753";
//    card->power = card->powerBase = 3;
//    card->tags = { };
//    card->isDoomed = true;
//    card->faction = Neutral;
//    card->rarity = Bronze;
//    //    sounds = {
//    //        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.86.mp3",
//    //        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.87.mp3",
//    //        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.84.mp3",
//    //        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.85.mp3",
//    //        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.83.mp3",
//    //    };
//    return card;
//}

//Card *Cards::createPrizeWinningCow()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    //https://gwent.one/image/gwent/assets/card/art/medium/1498.jpg
//    card->id = "112209";
//    card->power = card->powerBase = 1;
//    card->tags = { Beast };
//    card->faction = Neutral;
//    card->rarity = Silver;

//    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
//        Card *card = new Chort();
//        addAsNew(ally, card);
//        moveExistedUnitToPos(card, rowAndPosRandom(ally), ally, enemy, card);
//    };
//    return card;
//}

//PrizeWinningCow::Chort::Chort()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    // FIXME: check all the details
//    card->id = "112209";
//    // TODO: place this picture somehow
//    //https://gwent.one/image/gwent/assets/card/art/medium/1498.jpg
//    card->power = card->powerBase = 15;
//    card->tags = { Relict };
//    card->faction = Neutral;
//    card->rarity = Bronze;
//    return card;
//}

//Card *Cards::createPrincessAdda()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201595";
//    card->power = card->powerBase = 6;
//    card->tags = { Leader, Cursed };
//    card->faction = NothernRealms;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceCreateOptions(ally, enemy, card, {isBronzeOrSilver, isUnit, hasTag(Cursed)});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        spawnNewCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createKingFoltest()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200168";
//    card->power = card->powerBase = 5;
//    card->tags = { Leader, Temeria };
//    card->isCrew = true;
//    card->faction = NothernRealms;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        std::vector<Card *> cards = cardsFiltered(ally, enemy, {otherThan(card)}, AllyBoard);
//        std::vector<Card *> cardsDeck = cardsFiltered(ally, enemy, {isUnit, otherThan(card), isNonSpying}, AllyDeck);
//        std::vector<Card *> cardsHand = cardsFiltered(ally, enemy, {isUnit, otherThan(card), isNonSpying}, AllyHand);
//        cards.insert(cards.end(), cardsDeck.begin(), cardsDeck.end());
//        cards.insert(cards.end(), cardsHand.begin(), cardsHand.end());
//        for (Card *card : cards)
//            boost(card, 1, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createKingRadovidV()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200169";
//    card->power = card->powerBase = 6;
//    card->rarity = Gold;
//    card->faction = NothernRealms;
//    card->tags = { Leader, Redania };
//    card->isCrew = true;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard, 2);
//    };

//    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
//        toggleLock(target, ally, enemy, card);
//        if (isOnBoard(target, enemy))
//            damage(target, 4, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createEmhyrVarEmreis()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200162";
//    card->power = card->powerBase = 7;
//    card->rarity = Gold;
//    card->faction = Nilfgaard;
//    card->tags = { Leader, Officer };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AllyHand);
//    };

//    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
//        if (isIn(target, ally.hand)) {
//            // reverse due to choice stack: play a card, then return something to hand
//            startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver}, AllyBoard);
//            playExistedCard(target, ally, enemy, card);
//            return;
//        }
//        putToHand(target, ally, enemy,  card);
//    };
//    return card;
//}

//Card *Cards::createUsurper()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201580";
//    card->power = card->powerBase = 1;
//    card->rarity = Gold;
//    card->faction = Nilfgaard;
//    card->tags = { Leader, Officer };
//    card->isLoyal = false;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceCreateOptions(ally, enemy, card, {hasTag(Leader)});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        boost(target, 2, ally, enemy, card);
//        spawnNewCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createBrouverHoog()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200167";
//    card->power = card->powerBase = 4;
//    card->tags = { Leader, Dwarf };
//    card->faction = Scoiatael;
//    card->rarity = Gold;

//    card->const auto isOk = [=](Card *card) {
//        return isUnit(card) && ((isNonSpying(card) && isSilver(card)) || (hasTag(card, Dwarf) && isBronze(card)));
//    };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isOk}, AllyDeckShuffled);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createEithne()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200166";
//    card->power = card->powerBase = 5;
//    card->tags = { Leader, Dryad };
//    card->faction = Scoiatael;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, ::isSpecial}, AllyDiscard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}

Card *Cards::createFilavandrel()
{
    auto *card = new Card();
    card->_constructor = std::bind(&Cards::createFilavandrel, this);

    card->id = "201589";
    card->power = card->powerBase = 4;
    card->tags = { Leader, Elf };
    card->faction = Scoiatael;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceCreateOptions(ally, enemy, card, {isSilver, ::isSpecial});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}

//Card *Cards::createFrancescaFindabair()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200165";
//    card->power = card->powerBase = 7;
//    card->tags = { Leader, Mage, Elf };
//    card->faction = Scoiatael;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        _cardToSwap = nullptr;
//        startChoiceToTargetCard(ally, enemy, card, {}, AllyHand);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (_cardToSwap == nullptr) {
//            _cardToSwap = target;
//            startChoiceToTargetCard(ally, enemy, card, {}, AllyDeckShuffled);
//            return;
//        }
//        putToDeck(_cardToSwap, ally, enemy, DeckPosRandom, card);
//        putToHand(target, ally, enemy,  card);
//        boost(target, 3, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createAglais()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142106";
//    card->power = card->powerBase = 8;
//    card->tags = { Dryad };
//    card->faction = Scoiatael;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, ::isSpecial}, EnemyDiscard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//        banish(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createIorveth()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142103";
//    card->power = card->powerBase = 6;
//    card->tags = { Elf, Officer };
//    card->faction = Scoiatael;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (damage(target, 8, ally, enemy, card))
//            for (Card *card : cardsFiltered(ally, enemy, {isUnit, hasTag(Elf)}, AllyHand))
//                boost(card, 1, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createIorvethMeditation()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201611";
//    card->power = card->powerBase = 2;
//    card->tags = { Elf, Officer };
//    card->faction = Scoiatael;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        // TODO: check for new choices system and overall tests required
//        std::vector<Card *>cards;
//        for (const int _screenRow : std::vector<int>{3, 4, 5}) {
//            std::vector<Card *> rowCards = cardsInRow(ally, enemy, _screenRow);
//            if (rowCards.size() >= 2)
//                cards.insert(cards.end(), rowCards.begin(), rowCards.end());
//        }
//        if (cards.size() <= 0)
//            return;
//        startChoiceToTargetCard(ally, enemy, card, cards);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (_choosen == nullptr) {
//            _choosen = target;
//            const int screenRow = _findScreenRow(target, ally, enemy);
//            std::vector<Card *>cards = cardsInRow(ally, enemy, screenRow);
//            for (int i = 0; i < int(cards.size()); i++)
//                if (cards[i] == _choosen)
//                    cards.erase(cards.begin() + i);
//            startChoiceToTargetCard(ally, enemy, card, cards);
//            return;
//        }
//        duel(_choosen, target, ally, enemy);
//    };
//    return card;
//}

//Card *Cards::createIsengrimFaoiltiarna()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142102";
//    card->power = card->powerBase = 7;
//    card->tags = { Elf, Officer };
//    card->faction = Scoiatael;
//    card->rarity = Gold;

//    card->const auto isCardAmbush = [=](Card *card) {
//        return card->defaultCopy()->isAmbush;
//    };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, isCardAmbush}, AllyDeckShuffled);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createIsengrimOutlaw()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201615";
//    card->power = card->powerBase = 2;
//    card->tags = { Elf, Officer };
//    card->faction = Scoiatael;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        auto *option1 = createOption(card, Create);
//        option1->text = "Create a Silver Elf.";

//        auto *option2 = createOption(card, Play);
//        option2->text = "Play a Bronze or Silver special card from your deck.";

//        _choosen = nullptr;
//        startChoiceToSelectOption(ally, enemy, card, {option1, option2});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (!_choosen && isOption(target, Create)) {
//            _choosen = target;
//            startChoiceCreateOptions(ally, enemy, card, {isSilver, hasTag(Elf)});
//            return;
//        }
//        if (!_choosen && isOption(target, Play)) {
//            _choosen = target;
//            startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, ::isSpecial}, AllyDeckShuffled);
//            return;
//        }

//        if (isOption(_choosen, Create)) {
//            delete _choosen;
//            _choosen = nullptr;
//            spawnNewCard(target, ally, enemy, card);
//        }
//        return;
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        assert(isOption(_choosen, Create));
//        delete _choosen;
//        _choosen = nullptr;
//        spawnNewCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createIthlinneAegli()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142107";
//    card->power = card->powerBase = 2;
//    card->tags = { Elf, Mage };
//    card->faction = Scoiatael;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronze, hasAnyOfTags({Boon, Hazard, Spell})}, AllyDeckShuffled);
//    };
//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createSchirru()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142108";
//    card->power = card->powerBase = 4;
//    card->tags = { Elf, Soldier };
//    card->faction = Scoiatael;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectOption(ally, enemy, card, {new Scorch(), new Epidemic()});
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        spawnNewCard(target, ally, enemy, card);
//    };

//    return card;
//}

//Card *Cards::createSaesenthessis()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142108";
//    card->power = card->powerBase = 10;
//    card->tags = { Aedirn, Draconid };
//    card->faction = Scoiatael;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (const int dwarfsCount = cardsFiltered(ally, enemy, {hasTag(Dwarf)}, AllyBoard).size() > 0)
//            boost(card, dwarfsCount, ally, enemy, card);
//        if (const int elfsCount = cardsFiltered(ally, enemy, {hasTag(Elf)}, AllyBoard).size() > 0)
//            startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (const int elfsCount = cardsFiltered(ally, enemy, {hasTag(Elf)}, AllyBoard).size() > 0)
//            damage(target, elfsCount, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createSaskia()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200209";
//    card->power = card->powerBase = 11;
//    card->tags = { Aedirn, Draconid };
//    card->faction = Scoiatael;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronze}, AllyHand, 2, true);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        Card *newBronze;
//        if (!(newBronze = first(cardsFiltered(ally, enemy, {isBronze}, AllyDeck))))
//            return;
//        putToHand(newBronze, ally, enemy,  card);
//        putToDeck(target, ally, enemy, DeckPosRandomButNotFirst, card);
//    };
//    return card;
//}

//Card *Cards::createBarclayEls()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142207";
//    card->power = card->powerBase = 2;
//    card->tags = { Dwarf, Officer };
//    card->faction = Scoiatael;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (Card *card = random(cardsFiltered(ally, enemy, {isBronzeOrSilver, isUnit, hasTag(Dwarf)}, AllyDeck), ally.rng)) {
//            strengthen(card, 3, ally, enemy, card);
//            playExistedCard(card, ally, enemy, card);
//        }
//    };
//    return card;
//}

//Card *Cards::createDennisCranmer()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142211";
//    card->power = card->powerBase = 8;
//    card->tags = { Dwarf, Officer };
//    card->faction = Scoiatael;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        for (Card *card : cardsFiltered(ally, enemy, {hasTag(Dwarf), otherThan(card), isUnit}, AllyBoardHandDeck))
//            strengthen(card, 1, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createSheldonSkaggs()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142212";
//    card->power = card->powerBase = 9;
//    card->tags = { Dwarf, Officer };
//    card->faction = Scoiatael;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        int boostAmount = 0;
//        const int screenRow = _findScreenRow(card, ally, enemy);
//        std::vector<Card *>cards = cardsInRow(ally, enemy, screenRow);
//        for (Card *card : cards)
//            if (card != card)
//                if (moveToRandomRow(card, ally, enemy, card))
//                    boostAmount++;
//        if (boostAmount > 0)
//            boost(card, boostAmount, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createYarpenZigrin()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142213";
//    card->power = card->powerBase = 8;
//    card->tags = { Dwarf, Soldier };
//    card->faction = Scoiatael;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &, Field &) {
//        isResilient = true;
//    };

//    card->_onOtherAllyAppears = [=](Card *card, Field &ally, Field &enemy) {
//        if (!isOnBoard(card, ally) || !hasTag(card, Dwarf))
//            return;
//        boost(card, 1, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createYaevinn()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142203";
//    card->power = card->powerBase = 13;
//    card->tags = { Elf };
//    card->isLoyal = false;
//    card->faction = Scoiatael;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (tick(card, ally, enemy)) {
//            Card *unit = first(cardsFiltered(ally, enemy, {isUnit}, AllyDeck));
//            Card *special = first(cardsFiltered(ally, enemy, {::isSpecial}, AllyDeck));
//            if (unit) {
//                putToHand(unit, ally, enemy,  card);
//            }
//            if (special) {
//                putToHand(special, ally, enemy,  card);
//            }
//            if (!unit || !special)
//                return;
//            _drawn.push_back(unit);
//            _drawn.push_back(special);
//            startChoiceToTargetCard(ally, enemy, card, _drawn);
//        }
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        for (Card *card : _drawn)
//            if (card != target)
//                putToDeck(card, ally, enemy, DeckPosRandom, card);
//        _drawn.clear();
//    };
//    return card;
//}

//Card *Cards::createIdaEmeanAepSivney()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142202";
//    card->power = card->powerBase = 4;
//    card->tags = { Elf, Mage };
//    card->faction = Scoiatael;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectOption(ally, enemy, card, {new ImpenetrableFog(), new ClearSkies(), new AlzursThunder()});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        spawnNewCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createPavkoGale()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201676";
//    card->power = card->powerBase = 5;
//    card->tags = { Soldier };
//    card->faction = Scoiatael;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, hasTag(Item)}, AllyDeckShuffled);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createCiaranAepEasnillen()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142206";
//    card->power = card->powerBase = 9;
//    card->tags = { Elf, Soldier };
//    card->faction = Scoiatael;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {otherThan(card)}, AnyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        // TODO: fix the in-same-line moving issue (DwarvenMercenary has the same)
//        toggleLock(target, ally, enemy, card);
//        const Row row = _findRowAndPos(card, ally).row();
//        if (isOnBoard(target, ally) && _findRowAndPos(target, ally).row() != row) {
//            moveExistedUnitToPos(target, rowAndPosLastInExactRow(ally, row), ally, enemy, card);
//            return;
//        }
//        if (isOnBoard(target, enemy) && _findRowAndPos(target, ally).row() != row) {
//            moveExistedUnitToPos(target, rowAndPosLastInExactRow(enemy, row), enemy, ally, card);
//            return;
//        }
//    };
//    return card;
//}

//Card *Cards::createEibhearHattori()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200520";
//    card->power = card->powerBase = 3;
//    card->tags = { Elf, Support };
//    card->isDoomed = true;
//    card->faction = Scoiatael;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, isUnit, isFaction(Scoiatael), hasPowerXorLess(power)}, AllyDiscard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}


//Card *Cards::createMilaen()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200030";
//    card->power = card->powerBase = 4;
//    card->tags = { Elf };
//    card->faction = Scoiatael;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectRow(ally, enemy, card);
//    };

//    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
//        std::vector<Card *> cards = cardsInRow(ally, enemy, screenRow);
//        if (cards.size() <= 0)
//            return;
//        Card *first;
//        damage(first = cards[0], 6, ally, enemy, card);
//        if (cards[cards.size()] != first)
//            damage(cards[cards.size()], 6, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createBraenn()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142209";
//    card->power = card->powerBase = 6;
//    card->tags = { Dryad };
//    card->faction = Scoiatael;
//    card->rarity = Silver;

//    card->const auto isCardOk = [=](Card *card) {
//        return hasTag(card, Dryad) || card->defaultCopy()->isAmbush;
//        // || (card->defaultCopy()->isAmbush && !isOnBoard(card, ally)); // don't know how to get '&ally' here
//        // TODO: check how does the Braenn buff allies in Ambush on board
//    };

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (damage(target, power, ally, enemy, card))
//            for (Card *card : cardsFiltered(ally, enemy, {isCardOk}, AllyBoardHandDeck))
//                boost(card, 1, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createMorenn()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142208";
//    card->power = card->powerBase = 8;
//    card->tags = { Dryad };
//    card->isAmbush = true;
//    card->faction = Scoiatael;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &, Field &) {
//        isAmbush = true;
//    };

//    card->_onOtherEnemyAppears = [=](Card *target, Field &ally, Field &enemy) {
//        // TODO: check how should it works with cases like resurrect, spawn, summon
//        // maybe have to replace onOtherEnemyAppears call
//        if (!isOnBoard(card, ally) || !isAmbush)
//            return;
//        flipOver(card, ally, enemy);
//        damage (target, 7, ally, enemy, card);
//    };

//    card->_onOtherSpyAppears = [=](Card *target, Field &ally, Field &enemy) {
//        if (!isOnBoard(target, enemy))
//            return;
//        onOtherEnemyAppears(target, ally, enemy);
//    };
//    return card;
//}

//Card *Cards::createPaulieDahlberg()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201696";
//    card->power = card->powerBase = 3;
//    card->tags = { Dwarf, Support };
//    card->isDoomed = true;
//    card->faction = Scoiatael;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronze, isUnit, hasTag(Dwarf), hasNoTag(Support)}, AllyDiscard);
//    };

//    card->_onTargetChoosen = [=](Card * target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createMahakamHorn()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201653";
//    card->isSpecial = true;
//    card->tags = { Item };
//    card->faction = Scoiatael;
//    card->rarity = Silver;

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        auto *option1 = createOption(card, Create);
//        option1->text = "Create a Bronze or Silver Dwarf.";

//        auto *option2 = createOption(card, Strengthen);
//        option2->text = "Strengthen a unit by 7.";

//        _choosen = nullptr;
//        startChoiceToSelectOption(ally, enemy, card, {option1, option2});
//    };

//    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (!_choosen && isOption(target, Create)) {
//            _choosen = target;
//            startChoiceCreateOptions(ally, enemy, card, {isBronzeOrSilver, hasTag(Dwarf)});
//            return;
//        }

//        if (!_choosen && isOption(target, Strengthen)) {
//            _choosen = target;
//            startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
//            return;
//        }

//        if (isOption(_choosen, Create)) {
//            spawnNewCard(target, ally, enemy, card);
//            delete _choosen;
//            _choosen = nullptr;
//            return;
//        }

//        assert(false);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        assert(isOption(_choosen, Strengthen));

//        strengthen(target, 7, ally, enemy, card);

//        delete _choosen;
//        _choosen = nullptr;
//    };
//    return card;
//}

//Card *Cards::createNaturesGift()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "143201";
//    card->isSpecial = true;
//    card->tags = { Spell };
//    card->faction = Scoiatael;
//    card->rarity = Silver;

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, ::isSpecial}, AllyDeckShuffled);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createPitTrap()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200228";
//    card->isSpecial = true;
//    card->tags = { Item };
//    card->faction = Scoiatael;
//    card->rarity = Silver;

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectRow(ally, enemy, card, { 3, 4, 5 });
//    };

//    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
//        applyRowEffect(ally, enemy, screenRow, PitTrapEffect);
//    };
//    return card;
//}

//Card *Cards::createCrushingTrap()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201645";
//    card->isSpecial = true;
//    card->tags = { Item };
//    card->faction = Scoiatael;
//    card->rarity = Bronze;

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectRow(ally, enemy, card);
//    };

//    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
//        std::vector<Card *> cards = cardsInRow(ally, enemy, screenRow);
//        if (cards.size() <= 0)
//            return;
//        Card *first;
//        damage(first = cards[0], 6, ally, enemy, card);
//        if (cards[cards.size()] != first)
//            damage(cards[cards.size()], 6, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createElvenBlade()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201643";
//    card->isSpecial = true;
//    card->tags = { Item };
//    card->faction = Scoiatael;
//    card->rarity = Bronze;

//    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {hasNoTag(Elf)}, AnyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        damage(target, 10, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createIncineratingTrap()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "143301";
//    card->power = card->powerBase = 1;
//    card->tags = { Machine };
//    card->isDoomed = true;
//    card->isLoyal = false;
//    card->faction = Scoiatael;
//    card->rarity = Bronze;

//    card->_onTurnEnd = [=](Field &ally, Field &enemy) {
//        if (!isOnBoard(card, enemy))
//            return;
//        for (Card *card : cardsInRow(ally, enemy, _findScreenRow(card, ally, enemy)))
//            if (card != card)
//                damage(card, 2, ally, enemy, card);
//        banish(card, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createBlueMountainElite()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142316";
//    card->power = card->powerBase = 3;
//    card->tags = { Elf, Soldier };
//    card->faction = Scoiatael;
//    card->rarity = Bronze;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        for (Card *copy : cardsFiltered(ally, enemy, {isCopy(card->name)}, AllyDeck))
//            moveExistedUnitToPos(copy, _findRowAndPos(card, ally), ally, enemy, card);
//    };

//    card->_onMoveFromRowToRow = [=](Field &ally, Field &enemy) {
//        boost(card, 2, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createDolBlathannaBomber()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142316";
//    card->power = card->powerBase = 6;
//    card->tags = { Elf, Soldier };
//    card->faction = Scoiatael;
//    card->rarity = Bronze;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        spawnNewCard(new IncineratingTrap(), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createDolBlathannaBowman()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142314";
//    card->power = card->powerBase = 7;
//    card->tags = { Elf, Soldier };
//    card->faction = Scoiatael;
//    card->rarity = Bronze;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        damage(target, 2, ally, enemy, card);
//    };

//    card->_onMoveFromRowToRow = [=](Field &ally, Field &enemy) {
//        damage(random(cardsFiltered(ally, enemy, {}, EnemyBoard), ally.rng), 2, ally, enemy, card);
//    };

//    card->_onEnemyMoved = [=](Card *target, Field &ally, Field &enemy) {
//        if (!isOnBoard(card, ally))
//            return;
//        damage(target, 2, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createDolBlathannaSentry()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200039";
//    card->power = card->powerBase = 2;
//    card->tags = { Elf, Soldier };
//    card->faction = Scoiatael;
//    card->rarity = Bronze;

//    card->_onSpecialPlayed = [=](Card *target, Field &ally, Field &enemy) {
//        if(!isOnBoard(card, ally) && !isIn(card, ally.deck) && !isIn(card, ally.hand))
//            return;
//        if (!target->isSpecial || !(isIn(target, ally.discard) || isIn(target, ally.hand)))
//            //(target != ally.cardsAppeared.end()) ??
//            return;
//        boost(card, 1, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createElvenScout()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201638";
//    card->power = card->powerBase = 10;
//    card->tags = { Elf, Soldier };
//    card->faction = Scoiatael;
//    card->rarity = Bronze;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AllyHand);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        swapACard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createElvenSwordmaster()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200535";
//    card->power = card->powerBase = 5;
//    card->tags = { Elf, Soldier };
//    card->faction = Scoiatael;
//    card->rarity = Bronze;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        damage(target, power, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createDwarvenAgitator()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200293";
//    card->power = card->powerBase = 1;
//    card->tags = { Dwarf, Support };
//    card->faction = Scoiatael;
//    card->rarity = Bronze;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (Card *card = random(cardsFiltered(ally, enemy, {isBronze, hasTag(Dwarf), isNotCopy<DwarvenAgitator>}, AllyDeck), ally.rng))
//            spawnNewCard(card->defaultCopy(), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createDwarvenMercenary()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142311";
//    card->power = card->powerBase = 8;
//    card->tags = { Dwarf, Soldier };
//    card->faction = Scoiatael;
//    card->rarity = Bronze;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        // NOTE: check if otherThan(card) required
//        // TODO: fix ability, wrong filters
//        startChoiceToTargetCard(ally, enemy, card, {otherThan(card)}, AnyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        // TODO: fix the in-same-line moving issue (CiaranAepEasnillen has the same)
//        const Row row = _findRowAndPos(card, ally).row();
//        if (isOnBoard(target, ally)) {
//            boost(target, 3, ally, enemy, card);
//            // TODO: check if it's check really needed, and can `moveExistedUnitToPos` work with both fields?
//            if (_findRowAndPos(target, ally).row() != row)
//                moveExistedUnitToPos(target, rowAndPosLastInExactRow(ally, row), ally, enemy, card);
//            return;
//        }
//        if (isOnBoard(target, enemy) && _findRowAndPos(target, ally).row() != row) {
//            moveExistedUnitToPos(target, rowAndPosLastInExactRow(enemy, row), enemy, ally, card);
//            return;
//        }
//    };
//    return card;
//}

//Card *Cards::createDwarvenSkirmisher()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142305";
//    card->power = card->powerBase = 6;
//    card->tags = { Dwarf, Soldier };
//    card->faction = Scoiatael;
//    card->rarity = Bronze;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (!damage(target, 3, ally, enemy, card))
//            boost(card, 3, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createHawkerHealer()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142301";
//    card->power = card->powerBase = 5;
//    card->tags = { Elf, Support };
//    card->faction = Scoiatael;
//    card->rarity = Bronze;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AllyBoard, 2);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        boost(target, 3, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createHawkerSupport()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142312";
//    card->power = card->powerBase = 7;
//    card->tags = { Elf, Support };
//    card->faction = Scoiatael;
//    card->rarity = Bronze;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AllyHand);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        boost(target, 3, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createMahakamDefender()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142306";
//    card->power = card->powerBase = 6;
//    card->tags = { Dwarf, Soldier };
//    card->faction = Scoiatael;
//    card->rarity = Bronze;

//    card->_onDeploy = [=](Field &, Field &) {
//        isResilient = true;
//    };
//    return card;
//}

//Card *Cards::createMahakamGuard()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142317";
//    card->power = card->powerBase = 4;
//    card->tags = { Dwarf, Soldier };
//    card->faction = Scoiatael;
//    card->rarity = Bronze;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AllyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        boost(target, 7, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createMahakamVolunteers()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "201559";
//    card->power = card->powerBase = 3;
//    card->tags = { Dwarf, Soldier };
//    card->faction = Scoiatael;
//    card->rarity = Bronze;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        for (Card *copy : cardsFiltered(ally, enemy, {isCopy(card->name)}, AllyDeck))
//            moveExistedUnitToPos(copy, _findRowAndPos(card, ally), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createPyrotechnician()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200135";
//    card->power = card->powerBase = 5;
//    card->tags = { Dwarf, Soldier };
//    card->faction = Scoiatael;
//    card->rarity = Bronze;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        for (const Row row : std::vector<Row>{Meele, Range, Seige})
//            if (Card *card = random(enemy.row(row), enemy.rng))
//                damage(card, 3, ally, enemy, card);
//    };

//    return card;
//}

//Card *Cards::createWardancer()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142313";
//    card->power = card->powerBase = 3;
//    card->tags = { Elf, Soldier };
//    card->faction = Scoiatael;
//    card->rarity = Bronze;

//    card->_onSwap = [=](Field &ally, Field &enemy) {
//        moveExistedUnitToPos(card, rowAndPosRandom(ally), ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createVriheddVanguard()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142309";
//    card->power = card->powerBase = 6;
//    card->tags = { Elf, Soldier };
//    card->faction = Scoiatael;
//    card->rarity = Bronze;

//    card->_onDeploy = [=](Field &ally, Field & enemy) {
//        for (Card *card : cardsFiltered(ally, enemy, {hasTag(Elf)}, AllyBoard))
//            boost(card, 1, ally, enemy, card);
//    };

//    card->_onSwap = [=](Field &ally, Field &enemy) {
//        onDeploy(ally, enemy);
//    };
//    return card;
//}

//Card *Cards::createVriheddOfficer()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142303";
//    card->power = card->powerBase = 5;
//    card->tags = { Elf, Officer };
//    card->faction = Scoiatael;
//    card->rarity = Bronze;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AllyHand);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        boost(card, target->powerBase, ally, enemy, card);
//        swapACard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createVriheddNeophyte()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142301";
//    card->power = card->powerBase = 10;
//    card->tags = { Elf, Soldier };
//    card->faction = Scoiatael;
//    card->rarity = Bronze;

//    card->_onDeploy = [=](Field &ally, Field & enemy) {
//        for (Card *card : randoms(cardsFiltered(ally, enemy, {}, AllyHand), 2, ally.rng))
//            boost(card, 1, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createVriheddBrigade()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142302";
//    card->power = card->powerBase = 9;
//    card->tags = { Elf, Soldier };
//    card->faction = Scoiatael;
//    card->rarity = Bronze;

//    card->_onDeploy = [=](Field &ally, Field & enemy) {
//        clearHazardsFromItsRow(card, ally);
//        startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        // TODO: fix the in-same-line moving issue (CiaranAepEasnillen and DwarvenMecenary has the same)
//        const Row row = _findRowAndPos(card, ally).row();
//        if (isOnBoard(target, ally) && _findRowAndPos(target, ally).row() != row) {
//            moveExistedUnitToPos(target, rowAndPosLastInExactRow(ally, row), ally, enemy, card);
//            return;
//        }
//        if (isOnBoard(target, enemy) && _findRowAndPos(target, ally).row() != row) {
//            moveExistedUnitToPos(target, rowAndPosLastInExactRow(enemy, row), enemy, ally, card);
//            return;
//        }
//    };
//    return card;
//}

//Card *Cards::createHawkerSmuggler()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "142315";
//    card->power = card->powerBase = 7;
//    card->tags = { Elf, Support };
//    card->faction = Scoiatael;
//    card->rarity = Bronze;

//    card->_onOtherEnemyAppears = [=](Card *, Field &ally, Field &enemy) {
//        // TODO: check how should it works with cases like resurrect, spawn, summon
//        // maybe have to replace onOtherEnemyAppears call
//        if (!isOnBoard(card, ally))
//            return;
//        boost(card, 1, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createMennoCoehoorn()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162102";
//    card->power = card->powerBase = 8;
//    card->tags = { Officer };
//    card->faction = Nilfgaard;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field & enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (target->isSpy == false)
//            return putToDiscard(target, ally, enemy, card);
//        damage(target, 4, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createRainfarnOfAttre()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200032";
//    card->power = card->powerBase = 5;
//    card->tags = { Officer };
//    card->faction = Nilfgaard;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field & enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isSpying, isBronzeOrSilver}, AllyDeckShuffled);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createAssassination()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "163101";
//    card->isSpecial = true;
//    card->tags = { Tactics };
//    card->faction = Nilfgaard;
//    card->rarity = Gold;

//    card->_onPlaySpecial = [=](Field &ally, Field & enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        damage(target, 8, ally, enemy, card);
//    };

//    return card;
//}

//Card *Cards::createStefanSkellen()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162106";
//    card->power = card->powerBase = 10;
//    card->tags = { Officer };
//    card->faction = Nilfgaard;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, AllyDeckShuffled);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        putToDeck(target, ally, enemy, DeckPosTop, card);
//        if (!target->isSpecial && !target->isSpy)
//            boost(target, 5, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createShilard()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200071";
//    card->power = card->powerBase = 9;
//    card->tags = { Officer };
//    card->faction = Nilfgaard;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (ally.passed || enemy.passed)
//            return;
//        std::vector<Card *> variants;
//        if ((_allyCard = first(cardsFiltered(ally, enemy, {}, AllyDeck))))
//            variants.push_back(_allyCard);
//        if ((_enemyCard = random(cardsFiltered(ally, enemy, {}, EnemyDeck), ally.rng)))
//            variants.push_back(_enemyCard);
//        startChoiceToTargetCard(ally, enemy, card, variants);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        putToHand(target, ally, enemy, card);
//        if (target == _allyCard && _enemyCard)
//            putToHand(_enemyCard, enemy, ally, card);
//        else if (target == _enemyCard && _allyCard)
//            putToHand(_allyCard, enemy, ally, card);
//    };
//    return card;
//}

//Card *Cards::createXarthisius()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162108";
//    card->power = card->powerBase = 13;
//    card->tags = { Mage };
//    card->faction = Nilfgaard;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {}, EnemyDeck);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        putToDeck(target, enemy, ally, DeckPosBottom, card);
//    };
//    return card;
//}

//Card *Cards::createCantarella()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162108";
//    card->power = card->powerBase = 13;
//    card->tags = {};
//    card->isLoyal = false;
//    card->faction = Nilfgaard;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        if (tick(card, ally, enemy)) {
//            Card *firstCard = first(cardsFiltered(ally, enemy, {}, AllyDeck));
//            Card *secondCard = first(cardsFiltered(ally, enemy, {}, AllyDeck));
//            if (firstCard) {
//                putToHand(firstCard, ally, enemy,  card);
//            }
//            if (secondCard) {
//                putToHand(secondCard, ally, enemy,  card);
//            }
//            if (!firstCard || !secondCard)
//                return;
//            _drawn.push_back(firstCard);
//            _drawn.push_back(secondCard);
//            startChoiceToTargetCard(ally, enemy, card, _drawn);
//        }
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        for (Card *card : _drawn)
//            if (card != target)
//                putToDeck(card, ally, enemy, DeckPosBottom, card);
//        _drawn.clear();
//    };
//    return card;
//}

//Card *Cards::createPanther()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "200139";
//    card->power = card->powerBase = 4;
//    card->tags = { Beast };
//    card->faction = Scoiatael;
//    card->rarity = Bronze;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        const Field *enemyPtr = &enemy;
//        const auto isOk = [enemyPtr](Card *card) {
//            const Row row = _findRowAndPos(card, *enemyPtr).row();
//            return enemyPtr->row(row).size() < 4;
//        };
//        startChoiceToTargetCard(ally, enemy, card, {isOk}, EnemyBoard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        damage(target, 7, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createVicovaroMedic()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162304";
//    card->power = card->powerBase = 1;
//    card->tags = { Support };
//    card->isDoomed = true;
//    card->faction = Nilfgaard;
//    card->rarity = Bronze;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronze, isUnit}, EnemyDiscard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createAssireVarAnahid()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162202";
//    card->power = card->powerBase = 11;
//    card->tags = { Mage };
//    card->faction = Nilfgaard;
//    card->rarity = Gold;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver}, AllyDiscard);
//        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver}, EnemyDiscard);
//    };

//    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (isIn(target, ally.discard)){
//            putToDeck(target, ally, enemy, DeckPosRandom, card);
//            return;
//        }
//        else if (isIn(target, enemy.discard)){
//            putToDeck(target, enemy, ally, DeckPosRandom, card);
//            return;
//        }
//        assert(false);
//    };
//    return card;
//}

//Card *Cards::createFringillaVigo()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162205";
//    card->power = card->powerBase = 1;
//    card->isLoyal = false;
//    card->tags = { Mage };
//    card->faction = Nilfgaard;
//    card->rarity = Silver;

//    card->_onDeploy = [=](Field &ally, Field &enemy) {
//        Card *left = cardNextTo(card, ally, enemy, -1);
//        Card *right = cardNextTo(card, ally, enemy, 1);
//        if (left != nullptr && right != nullptr)
//            setPower(right, left->power, ally, enemy, card);
//    };
//    return card;
//}

//Card *Cards::createFalseCiri()
//{
//    auto *card = new Card();
//    card->_constructor = std::bind(&Cards::, this);
// 
//    card->id = "162212";
//    card->power = card->powerBase = 8;
//    card->isLoyal = false;
//    card->tags = { };
//    card->faction = Nilfgaard;
//    card->rarity = Silver;

//    card->_onTurnStart = [=](Field &ally, Field &enemy) {
//        if (!this->isLoyal)
//            boost(card, 1, ally, enemy, card);
//    };

//    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &rowAndPos) {
//        if (Card *card = lowest(cardsInRow(ally, enemy, rowAndPos.row()), ally.rng))
//            putToDiscard(card, ally, enemy, card);
//    };

//    card->_onAllyPass = [=](Field &ally, Field &enemy) {
//        // NOTE: for spying creatures logic of this event is inverted
//        // so an ally is an original enemy for FalseCiri
//        if (!this->isLoyal) {
//            const Row row = _findRowAndPos(card, ally).row();
//            moveExistedUnitToPos(card, rowAndPosLastInExactRow(enemy, row), enemy, ally, card);
//        }
//    };
//    return card;
//}

//Dandelion::Dandelion()
//{
//    id = "122201";
//    name = "Dandelion";
//    text = "Boost 3 units in your deck by 2.";
//    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
//    power = powerBase = 11;
//    tags = { Support };
//    faction = NothernRealms;
//    rarity = Gold;
//    sounds = {
//        "https://gwent.one/audio/card/ob/en/DAND_Q302_00490269.mp3",
//        "https://gwent.one/audio/card/ob/en/DAND_DANDELION_00429307.mp3",
//        "https://gwent.one/audio/card/ob/en/DAND_Q302_00489393.mp3",
//        "https://gwent.one/audio/card/ob/en/VO_JSKR_100926_0188.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.5.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.6.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.7.mp3",
//    };

//    _onDeploy = [this](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, this, {isUnit}, AllyDeckShuffled, 3, false);
//    };

//    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        boost(target, 2, ally, enemy, this);
//    };
//}

//Kiyan::Kiyan()
//{
//    id = "201621";
//    name = "Kiyan";
//    text = "Choose One: Create a Bronze or Silver Alchemy card; or Play a Bronze or Silver Item from your deck.";
//    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
//    power = powerBase = 4;
//    tags = { Cursed, Witcher };
//    faction = NothernRealms;
//    rarity = Gold;
//    sounds = {
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.14.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.15.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.16.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.17.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.18.mp3",
//    };

//    _onDeploy = [=](Field &ally, Field &enemy) {
//        auto *option1 = new Kiyan::Create;
//        copyCardText(this, option1);
//        option1->text = "Create a Bronze or Silver Alchemy card.";

//        auto *option2 = new Kiyan::Play;
//        copyCardText(this, option2);
//        option2->text = "Play a Bronze or Silver Item from your deck.";

//        _choosen = nullptr;
//        startChoiceToSelectOption(ally, enemy, this, {option1, option2});
//    };

//    _onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {

//        if (!_choosen && dynamic_cast<Kiyan::Play *>(target)) {
//            _choosen = target;
//            return startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilver, hasTag(Item)}, AllyDeckShuffled);
//        }

//        if (!_choosen && dynamic_cast<Kiyan::Create *>(target)) {
//            _choosen = target;
//            return startChoiceCreateOptions(ally, enemy, this, {isBronzeOrSilver, hasTag(Alchemy)}, AnyCard);
//        }

//        if (dynamic_cast<Kiyan::Create *>(_choosen)) {
//            spawnNewCard(target, ally, enemy, this);
//            delete _choosen;
//            _choosen = nullptr;
//            return;
//        }

//        assert(false);
//    };

//    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, this);
//    };
//}

//PhilippaEilhart::PhilippaEilhart()
//{
//    id = "122104";
//    name = "Philippa Eilhart";
//    text = "Deal 5 damage to an enemy, then deal 4, 3, 2 and 1 damage to random enemies. Cannot damage the same enemy twice in a row.";
//    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
//    power = powerBase = 1;
//    tags = { Mage, Redania };
//    faction = NothernRealms;
//    rarity = Gold;
//    sounds = {
//        "https://gwent.one/audio/card/ob/en/PHIL_Q502_00555967.mp3",
//        "https://gwent.one/audio/card/ob/en/PHIL_Q310_00533376.mp3",
//        "https://gwent.one/audio/card/ob/en/PHIL_PHILIPPA_01041426.mp3",
//        "https://gwent.one/audio/card/ob/en/VO_FLPA_200102_0065.mp3",
//        "https://gwent.one/audio/card/ob/en/PHIL_PHILIPPA_01041424.mp3",
//        "https://gwent.one/audio/card/ob/en/VO_FLPA_300358_0012.mp3",
//    };

//    _onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, this, {}, EnemyBoard);
//    };

//    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        damage(target, 5, ally, enemy, this);

//        for (int dmg = 4; dmg > 0; --dmg) {
//            target = random(cardsFiltered(ally, enemy, {otherThan(target)}, EnemyBoard), ally.rng);
//            if (!target)
//                return;
//            damage(target, dmg, ally, enemy, this);
//        }
//    };
//}

//RocheMerciless::RocheMerciless()
//{
//    id = "201777";
//    name = "Roche: Merciless";
//    text = "Destroy a face-down Ambush enemy.";
//    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
//    tags = { Temeria, Officer };
//    power = powerBase = 6;
//    faction = NothernRealms;
//    rarity = Gold;
//    sounds = {
//        "https://gwent.one/audio/card/ob/en/ROCH_ROCHE_00541126.mp3",
//        "https://gwent.one/audio/card/ob/en/ROCH_MQ3035_01064844.mp3",
//    };

//    _onDeploy = [=](Field &ally, Field &enemy) {
//        // FIXME: test, because it won't work
//        startChoiceToTargetCard(ally, enemy, this, {isAmbushing}, EnemyBoard);
//    };

//    _onTargetChoosen = [=](Card *card, Field &ally, Field &enemy) {
//        putToDiscard(card, ally, enemy, this);
//    };
//}

//Shani::Shani()
//{
//    id = "122106";
//    name = "Shani";
//    text = "Resurrect a non-Cursed Bronze or Silver unit and give it 2 Armor.";
//    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
//    tags = { Redania, Support };
//    power = powerBase = 4;
//    faction = NothernRealms;
//    rarity = Gold;
//    isDoomed = true;

//    sounds = {
//        "https://gwent.one/audio/card/ob/en/SHNI_SHANI_01130725.mp3",
//        "https://gwent.one/audio/card/ob/en/SHNI_Q601_01101942.mp3",
//        "https://gwent.one/audio/card/ob/en/SHNI_Q602_01119358.mp3",
//    };

//    _onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, this, {isUnit, isBronzeOrSilver, hasNoTag(Cursed),}, AllyDiscard);
//    };

//    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, this);
//        gainArmor(target, 2, ally, enemy, this);
//    };
//}

//Vandergrift::Vandergrift()
//{
//    id = "201620";
//    name = "Vandergrift";
//    text = "Deal 1 damage to all enemies. If a unit is destroyed, apply Ragh Nar Roog to its row.";
//    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
//    tags = { Cursed, Kaedwen, Officer };
//    power = powerBase = 7;
//    faction = NothernRealms;
//    rarity = Gold;

//    sounds = {
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.11.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.10.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.9.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.8.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.7.mp3",
//    };

//    _onDeploy = [=](Field &ally, Field &enemy) {
//        for (Card *card : cardsFiltered(ally, enemy, {}, EnemyBoard)) {
//            if (damage(card, 1, ally, enemy, this)) {
//                const Row row = _findRowAndPos(this, enemy).row();
//                applyRowEffect(ally, enemy, toScreenRow(row, false), RaghNarRoogEffect);
//            }
//        }
//    };
//}

//Botchling::Botchling()
//{
//    id = "122401";
//    name = "Botchling";
//    text = "Summon a Lubberkin to this row.";
//    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
//    tags = { Cursed };
//    power = powerBase = 10;
//    faction = NothernRealms;
//    rarity = Silver;

//    _onDeploy = [=](Field &ally, Field &enemy) {
//        for (Card *lubberkin : cardsFiltered(ally, enemy, {isCopy<Lubberkin>}, AllyDeck))
//            moveExistedUnitToPos(lubberkin, rowAndPosToTheRight(this, ally, 1), ally, enemy, this);
//    };
//}

//Lubberkin::Lubberkin()
//{
//    id = "122402";
//    name = "Lubberkin";
//    text = "Summon a Botchling to this row.";
//    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
//    tags = { Cursed };
//    power = powerBase = 5;
//    faction = NothernRealms;
//    rarity = Silver;

//    _onDeploy = [=](Field &ally, Field &enemy) {
//        for (Card *botchling : cardsFiltered(ally, enemy, {isCopy<Botchling>}, AllyDeck))
//            moveExistedUnitToPos(botchling, rowAndPosToTheLeft(this, ally, 1), ally, enemy, this);
//    };
//}

//NilfgaardianGate::NilfgaardianGate()
//{
//    id = "201699";
//    name = "Nilfgaardian Gate";
//    text = "Play a Bronze or Silver Officer from your deck and boost it by 1.";
//    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
//    tags = { Tactics };
//    isSpecial = true;
//    faction = Nilfgaard;
//    rarity = Silver;

//    _onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, this, {hasTag(Officer), isBronzeOrSilver}, AllyDeckShuffled);
//    };

//    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        boost(target, 1, ally, enemy, this);
//        playExistedCard(target, ally, enemy, this);
//    };
//}

//PeterSaarGwynleve::PeterSaarGwynleve()
//{
//    id = "162204";
//    name = "Peter Saar Gwynleve";
//    text = "Reset an ally and Strengthen it by 3; or Reset an enemy and Weaken it by 3.";
//    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
//    tags = { Officer };
//    power = powerBase = 6;
//    faction = Nilfgaard;
//    rarity = Silver;
//    sounds = {
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.426.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.427.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.428.mp3",
//    };

//    _onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, this);
//    };

//    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        reset(target, ally, enemy, this);
//        if (isOnBoard(target, ally))
//            strengthen(target, 3, ally, enemy, this);
//        else if (isOnBoard(target, enemy))
//            weaken(target, 3, ally, enemy, this);
//        else
//            assert(false);
//    };
//}

//VicovaroNovice::VicovaroNovice()
//{
//    id = "122403";
//    name = "Vicovaro Novice";
//    text = "Look at 2 random Bronze Alchemy cards from your deck, then play 1.";
//    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
//    tags = { Mage };
//    power = powerBase = 2;
//    faction = Nilfgaard;
//    rarity = Bronze;
//    sounds = {
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.820.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.821.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.819.mp3",
//    };

//    _onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, this, randoms(cardsFiltered(ally, enemy, {isBronze, hasTag(Alchemy)}, AllyDeck), 2, ally.rng));
//    };

//    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, this);
//    };
//}

//Cadaverine::Cadaverine()
//{
//    id = "201662";
//    name = "Cadaverine";
//    text = "Choose One: Deal 2 damage to an enemy and all units that share its categories; or Destroy a Bronze or Silver Neutral unit.";
//    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
//    tags = { Alchemy, Item };
//    isSpecial = true;
//    faction = Nilfgaard;
//    rarity = Silver;

//    _onPlaySpecial = [=](Field &ally, Field &enemy) {
//        auto *option1 = new Cadaverine::DealDamage;
//        copyCardText(this, option1);
//        option1->text = "Deal 2 damage to an enemy and all units that share its categories.";

//        auto *option2 = new Cadaverine::Destroy;
//        copyCardText(this, option2);
//        option2->text = "Destroy a Bronze or Silver Neutral unit.";

//        _choosen = nullptr;
//        startChoiceToSelectOption(ally, enemy, this, {option1, option2});
//    };

//    _onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (!_choosen && dynamic_cast<Cadaverine::DealDamage *>(target)) {
//            _choosen = target;
//            startChoiceToTargetCard(ally, enemy, this, {}, EnemyBoard);
//            return;
//        }

//        if (!_choosen && dynamic_cast<Cadaverine::Destroy *>(target)) {
//            _choosen = target;
//            startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilver, isFaction(Neutral)}, AnyBoard);
//            return;
//        }

//        assert(false);
//    };

//    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        assert(_choosen);

//        if (dynamic_cast<Cadaverine::DealDamage *>(_choosen))
//            for (Card *card : cardsFiltered(ally, enemy, {hasAnyOfTags(target->tags)}, EnemyBoard))
//                damage(card, 2, ally, enemy, this);

//        if (dynamic_cast<Cadaverine::Destroy *>(_choosen))
//            putToDiscard(target, ally, enemy, this);

//        delete _choosen;
//        _choosen = nullptr;
//    };
//}

//JoachimDeWett::JoachimDeWett()
//{
//    id = "162211";
//    name = "Joachim de Wett";
//    text = "Spying. Play the top non-Spying Bronze or Silver unit from your deck and boost it by 10.";
//    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
//    tags = { Officer };
//    power = powerBase = 5;
//    faction = Nilfgaard;
//    rarity = Silver;
//    sounds = {
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.19.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.18.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.17.mp3",
//    };

//    _onDeploy = [=](Field &ally, Field &enemy) {
//        if (Card* card = first(cardsFiltered(ally, enemy, {isBronzeOrSilver, isNonSpying, isUnit}, AllyDeck))) {
//            boost(card, 10, ally, enemy, this);
//            playExistedCard(card, ally, enemy, this);
//        }
//    };
//}

//Treason::Treason()
//{
//    id = "163201";
//    name = "Treason";
//    text = "Force 2 adjacent enemies to Duel each other.";
//    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
//    tags = { Tactics };
//    isSpecial = true;
//    faction = Nilfgaard;
//    rarity = Silver;

//    _onPlaySpecial = [=](Field &ally, Field &enemy) {
//        std::vector<Card *> cardsToChoice;
//        for(Card *card : cardsFiltered(ally, enemy, {}, EnemyBoard)) {
//            if (!card->isAmbush) {
//                Card *left = cardNextTo(card, ally, enemy, -1);
//                Card *right = cardNextTo(card, ally, enemy, 1);
//                if ((left != nullptr && !left->isAmbush) || (right != nullptr && !right->isAmbush))
//                   cardsToChoice.push_back(card);
//            }
//        }
//        startChoiceToTargetCard(ally, enemy, this, cardsToChoice);
//    };

//    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (_choosen == nullptr) {
//            _choosen = target;
//            std::vector<Card *> cards;
//            if (Card *left = cardNextTo(target, ally, enemy, -1))
//                if(!left->isAmbush)
//                    cards.push_back(left);
//            if (Card *right = cardNextTo(target, ally, enemy, 1))
//                if(!right->isAmbush)
//                    cards.push_back(right);
//            assert(cards.size() != 0);
//            startChoiceToTargetCard(ally, enemy, this, cards);
//            return;
//        }
//        duel(_choosen, target, ally, enemy);
//    };
//}

//Vanhemar::Vanhemar()
//{
//    id = "162207";
//    name = "Vanhemar";
//    text = "Spawn Biting Frost, Clear Skies or Shrike.";
//    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
//    tags = { Mage };
//    power = powerBase = 4;
//    faction = Nilfgaard;
//    rarity = Silver;
//    sounds = {
//        "https://gwent.one/audio/card/ob/en/VO_NM01_200057_0187.mp3",
//        "https://gwent.one/audio/card/ob/en/VO_NM01_200996_0005.mp3",
//        "https://gwent.one/audio/card/ob/en/VO_NM01_200049_0007.mp3",
//    };

//    _onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToSelectOption(ally, enemy, this, {new BitingFrost(), new ClearSkies(), new Shrike()});
//    };

//    _onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        spawnNewCard(target, ally, enemy, this);
//    };
//}

//Vrygheff::Vrygheff()
//{
//    id = "201664";
//    name = "Vrygheff";
//    text = "Play a Bronze Machine from your deck.";
//    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
//    tags = { Officer };
//    power = powerBase = 5;
//    faction = Nilfgaard;
//    rarity = Silver;
//    sounds = {
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.256.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.255.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.253.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.254.mp3",
//    };

//    _onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, this, {isBronze, hasTag({Machine})}, AllyDeckShuffled);
//    };

//    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        playExistedCard(target, ally, enemy, this);
//    };
//}

//AlbaPikeman::AlbaPikeman()
//{
//    id = "162311";
//    name = "Alba Pikeman";
//    text = "Summon all copies of this unit to this row.";
//    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
//    tags = { Soldier };
//    power = powerBase = 3;
//    faction = Nilfgaard;
//    rarity = Bronze;
//    sounds = {
//        "https://gwent.one/audio/card/ob/en/NILF3_VSET_00514121.mp3",
//        "https://gwent.one/audio/card/ob/en/NILF3_VSET_00514091.mp3",
//        "https://gwent.one/audio/card/ob/en/NILF3_VSET_00514113.mp3",
//    };

//    _onDeploy = [=](Field &ally, Field &enemy) {
//        for (Card *copy : cardsFiltered(ally, enemy, {isCopy(this->name)}, AllyDeck))
//            moveExistedUnitToPos(copy, _findRowAndPos(this, ally), ally, enemy, this);
//    };
//}

//CombatEngineer::CombatEngineer()
//{
//    id = "162313";
//    name = "Combat Engineer";
//    text = "Boost an ally by 5. Crew.";
//    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
//    tags = { Support };
//    isCrew = true;
//    power = powerBase = 6;
//    faction = Nilfgaard;
//    rarity = Bronze;
//    sounds = {
//        "https://gwent.one/audio/card/ob/en/NILF2_Q502_00556520.mp3",
//        "https://gwent.one/audio/card/ob/en/NILF2_VSET_00513907.mp3",
//        "https://gwent.one/audio/card/ob/en/NILF2_VSET_01072393.mp3",
//    };

//    _onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, this, {}, AllyBoard);
//    };

//    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        boost(target, 5, ally, enemy, this);
//    };
//}

//MagneDivision::MagneDivision()
//{
//    id = "200044";
//    name = "Magne Division";
//    text = "Play a random Bronze Item from your deck.";
//    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
//    tags = { Soldier };
//    power = powerBase = 3;
//    faction = Nilfgaard;
//    rarity = Bronze;
//    sounds = {
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.35.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.37.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.36.mp3",
//    };

//    _onDeploy = [=](Field &ally, Field &enemy) {
//        if (Card *card = random(cardsFiltered(ally, enemy, {isBronze, hasTag(Item)}, AllyDeck), ally.rng))
//            playExistedCard(card, ally, enemy, this);
//    };
//}

//NauzicaaBrigade::NauzicaaBrigade()
//{
//    id = "162310";
//    name = "Nauzicaa Brigade";
//    text = "Deal 7 damage to a Spying unit. If it was destroyed, Strengthen self by 4.";
//    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
//    tags = { Soldier };
//    power = powerBase = 5;
//    faction = Nilfgaard;
//    rarity = Bronze;
//    sounds = {
//        "https://gwent.one/audio/card/ob/en/NILF2_VSET_00513916.mp3",
//        "https://gwent.one/audio/card/ob/en/NILF2_VSET_00513914.mp3",
//        "https://gwent.one/audio/card/ob/en/NILF2_VSET_00513922.mp3",
//    };

//    _onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, this, {isSpying}, AnyBoard);
//    };

//    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (damage(target, 7, ally, enemy, this))
//            strengthen(this, 4, ally, enemy, this);
//    };
//}

//SlaveDriver::SlaveDriver()
//{
//    id = "201612";
//    name = "Slave Driver";
//    text = "Set an ally's power to 1 and deal damage to an enemy by the amount of power lost.";
//    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
//    tags = { Officer };
//    power = powerBase = 10;
//    faction = Nilfgaard;
//    rarity = Bronze;
//    sounds = {
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.113.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.114.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.115.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.116.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.117.mp3",
//    };

//    _onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, this, {}, AllyBoard);
//    };

//    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        if (_lostPower == -1) {
//            _lostPower = target->power - 1;
//            setPower(target, 1, ally, enemy, this);
//            if (_lostPower == 0)
//                return;
//            startChoiceToTargetCard(ally, enemy, this, {}, EnemyBoard);
//            return;
//        }
//        damage(target, _lostPower, ally, enemy, this);
//    };
//}

//SlaveHunter::SlaveHunter()
//{
//    id = "201609";
//    name = "Slave Hunter";
//    text = "Charm a Bronze enemy with 3 power or less.";
//    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
//    tags = { Soldier };
//    power = powerBase = 8;
//    faction = Nilfgaard;
//    rarity = Bronze;
//    sounds = {
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.105.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.104.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.103.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.106.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.107.mp3",
//    };

//    _onDeploy = [=](Field &ally, Field &enemy) {
//        startChoiceToTargetCard(ally, enemy, this, {isBronze, hasPowerXorLess(3)}, EnemyBoard);
//    };

//    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        charm(target, ally, enemy, this);
//    };
//}

//ViperWitcher::ViperWitcher()
//{
//    id = "200124";
//    name = "Viper Witcher";
//    text = "Deal 1 damage for each Alchemy card in your starting deck.";
//    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
//    tags = { Witcher };
//    power = powerBase = 5;
//    faction = Nilfgaard;
//    rarity = Bronze;
//    sounds = {
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.339.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.338.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.337.mp3",
//    };

//    _onDeploy = [=](Field &ally, Field &enemy) {
//        if (cardsFiltered(ally, enemy, {hasTag(Alchemy)}, AllyDeckStarting).size() > 0)
//            startChoiceToTargetCard(ally, enemy, this, {}, EnemyBoard);
//    };

//    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
//        const int dmg = cardsFiltered(ally, enemy, {hasTag(Alchemy)}, AllyDeckStarting).size();
//        damage(target, dmg, ally, enemy, this);
//    };
//}

//RotTosser::RotTosser()
//{
//    id = "162302";
//    name = "Rot Tosser";
//    text = "Spawn a Cow Carcass on an enemy row.";
//    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
//    tags = { Machine };
//    power = powerBase = 8;
//    faction = Nilfgaard;
//    rarity = Bronze;

//    _onDeploy = [=](Field &ally, Field &enemy) {
//        spawnNewCard(new CowCarcass(), ally, enemy, this);
//    };
//}

//RotTosser::CowCarcass::CowCarcass()
//{
//    id = "162402";
//    name = "Cow Carcass";
//    text = "Spying. After 2 turns, destroy all the other Lowest units on the row and Banish self on turn end.";
//    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
//    isDoomed = true;
//    isLoyal = false;
//    power = powerBase = 1;
//    faction = Nilfgaard;
//    rarity = Bronze;

//    _onDeploy = [=](Field &ally, Field &enemy) {
//        setTimer(this, ally, enemy, 2);
//    };

//    _onTurnEnd = [=](Field &ally, Field &enemy) {
//        if (!tick(this, ally, enemy))
//            return;
//        for (Card *card : lowests(cardsFiltered(ally, enemy,  {otherThan(this), isOnSameRow(&ally, this)}, AllyBoard)))
//            putToDiscard(card, ally, enemy, this);
//        banish(this, ally, enemy, this);
//    };
//}

//StandardBearer::StandardBearer()
//{
//    id = "200294";
//    name = "Standard Bearer";
//    text = "Boost an ally by 2 whenever you play a Soldier.";
//    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
//    tags = { Soldier };
//    power = powerBase = 8;
//    faction = Nilfgaard;
//    rarity = Bronze;
//    sounds = {
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.338.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.339.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.340.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.341.mp3",
//        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.342.mp3",
//    };

//    _onOtherAllyPlayedFromHand = [=](Card *other, Field &ally, Field &enemy) {
//        if (!isOnBoard(this, ally))
//            return;
//        if (hasTag(other, Soldier))
//            boost(this, 2, ally, enemy, this);
//    };
//}
