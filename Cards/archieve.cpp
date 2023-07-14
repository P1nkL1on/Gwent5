#include "archieve.h"

#include <cassert>
#include <random>

#include "filters.h"

std::vector<Card *> Cards::createAll()
{
    const std::vector<Card *> cards {
        createAddaStriga(),
        createDao(),
        createPoorFingInfantry(),
        createDeithwenArbalest(),
        createTemerianDrummer(),
        createDandelionPoet(),
        createSileDeTansarville(),
        createRedanianKnightElect(),
        createKaedweniKnight(),
        createAnCraiteMarauder(),
        createAnCraiteGreatsword(),
        createDimunLightLongship(),
        createTuirseachBearmaster(),
        createTuirseachHunter(),
        createRedanianElite(),
        createRedanianKnight(),
        createKaedweniCavalry(),
        createAlzursThunder(),
        createSwallow(),
        createThunderbolt(),
        createArachasVenom(),
        createKeiraMetz(),
        createDolBlathannaArcher(),
        createHalfElfHunter(),
        createAmbassador(),
        createAssassin(),
        createEmissary(),
        createCeallachDyffryn(),
        createTuirseachArcher(),
        createInfiltrator(),
        createImpenetrableFog(),
        createTorrentialRain(),
        createBitingFrost(),
        createGoldenFroth(),
        createSkelligeStorm(),
        createImperialManticore(),
        createManticoreVenom(),
        createGloriousHunt(),
        createVes(),
        createVaedermakar(),
        createFrightener(),
        createCleaver(),
        createScorch(),
        createReinforcements(),
        createJohnNatalis(),
        createEleyas(),
        createReaverScout(),
        createHeymaeySpearmaiden(),
        createVriheddSappers(),
        createPriestessOfFreya(),
        createDimunCorsair(),
        createSigrdrifa(),
        createDrummondQueensguard(),
        createSage(),
        createReconnaissance(),
        createElvenMercenary(),
        createChampionOfHov(),
        createPriscilla(),
        createSeltkirkOfGulet(),
        createAdrenalineRush(),
        createMandrake(),
        createBoneTalisman(),
        createRestore(),
        createDecoy(),
        createShupesDayOff(),
        createFirstLight(),
        createEpidemic(),
        createMoonlight(),
        createCiriNova(),
        createHaraldTheCripple(),
        createBranTuirseach(),
        createDrummondWarmonger(),
        createDimunPirate(),
        createAnCraiteRaider(),
        createMadmanLugos(),
        createErmion(),
        createCerysFearless(),
        createCerysAnCraite(),
        createWoodlandSpirit(),
        createTrollololo(),
        createPrinceStennis(),
        createVincentMeis(),
        createMorkvarg(),
        createArtefactCompression(),
        createHjalmarAnCraite(),
        createRegis(),
        createLethoOfGulet(),
        createAnCraiteLongship(),
        createGeraltIgni(),
        createGeraltOfRivia(),
        createTuirseachVeteran(),
        createUdalryk(),
        createBloodcurdlingRoar(),
        createGremist(),
        createZoriaRunestone(),
        createOperator(),
        createRenew(),
        createEistTuirseach(),
        createTuirseachAxeman(),
        createDerran(),
        createTuirseachSkirmisher(),
        createRoach(),
        createJanCalveit(),
        createCahirDyffryn(),
        createLethoKingslayer(),
        createKingHenselt(),
        createBloodyBaron(),
        createHubertRejk(),
        createDethmold(),
        createRonvidTheIncessant(),
        createCrachAnCraite(),
        createBirnaBran(),
        createCoral(),
        createVabjorn(),
        createBlueboyLugos(),
        createDjengeFrett(),
        createDonarAnHindar(),
        createDraigBonDhu(),
        createHolgerBlackhand(),
        createJuttaAnDimun(),
        createSavageBear(),
        createSvanrigeTuirseach(),
        createSkjall(),
        createHaraldHoundsnout(),
        createYoana(),
        createAnCraiteBlacksmith(),
        createAnCraiteWarcrier(),
        createAnCraiteWarrior(),
        createBerserkerMarauder(),
        createDimunPirateCaptain(),
        createDimunSmuggler(),
        createDrummondShieldmaid(),
        createHeymaeyFlaminica(),
        createHeymaeyHerbalist(),
        createHeymaeyProtector(),
        createHeymaeySkald(),
        createRagingBerserker(),
        createHym(),
        createKambi(),
        createOlaf(),
        createUlfhedinn(),
        createWildBoarOfTheSea(),
        createGiantBoar(),
        createOrnamentalSword(),
        createDimunWarship(),
        createVilgefortz(),
        createTrissButterflies(),
        createYennefer(),
        createGermainPiquant(),
        createCommandersHorn(),
        createMarchingOrders(),
        createAlzursDoubleCross(),
        createAlbaArmoredCavalry(),
        createSentry(),
        createNauzicaaSergeant(),
        createSlaveInfantry(),
        createRecruit(),
        createOintment(),
        createVreemde(),
        createLambert(),
        createEskel(),
        createVesemir(),
        createTridamInfantry(),
        createVriheddDragoon(),
        createMalena(),
        createUnseenElder(),
        createDevanaRunestone(),
        createDazhbogRunestone(),
        createMoranaRunestone(),
        createStribogRunestone(),
        createMuzzle(),
        createWhisperingHillock(),
        createBrewess(),
        createWeavess(),
        createWhispess(),
        createWeavessIncantation(),
        createBrewessRitual(),
        createWhispessTribute(),
        createNivellen(),
        createLeoBonhart(),
        createMorvranVoorhis(),
        createCynthia(),
        createSerrit(),
        createSweers(),
        createTiborEggebracht(),
        createVattierDeRideaux(),
        createAlbrich(),
        createHeftyHelge(),
        createAlchemist(),
        createDaerlanSoldier(),
        createFireScorpion(),
        createMangonel(),
        createNilfgaardianKnight(),
        createSpotter(),
        createVenendalElite(),
        createMasterOfDisguise(),
        createHenryVarAttre(),
        createWildHuntHound(),
        createWildHuntWarrior(),
        createWildHuntNavigator(),
        createNithral(),
        createMiruna(),
        createImlerith(),
        createCaretaker(),
        createRuehin(),
        createOldSpeartipAsleep(),
        createOldSpeartip(),
        createGolyat(),
        createBarbegazi(),
        createGhoul(),
        createForktail(),
        createArachasQueen(),
        createOzzrel(),
        createKayran(),
        createMourntart(),
        createToadPrince(),
        createFiend(),
        createMorvudd(),
        createEkimmara(),
        createRotfiend(),
        createArchespore(),
        createCyclops(),
        createMaerolorn(),
        createMonsterNest(),
        createArachasDrone(),
        createEredinBreaccGlas(),
        createCaranthirArFeiniel(),
        createImlerithSabbath(),
        createDagon(),
        createIfrit(),
        createSheTrollOfVergen(),
        createWyvern(),
        createAbaya(),
        createParasite(),
        createJotunn(),
        createIceGiant(),
        createIceTroll(),
        createDrowner(),
        createFoglet(),
        createAncientFoglet(),
        createDraug(),
        createCelaenoHarpy(),
        createArachasBehemoth(),
        createArchgriffin(),
        createGriffin(),
        createBridgeTroll(),
        createCockatrice(),
        createSiren(),
        createLamia(),
        createNekker(),
        createNekkerWarrior(),
        createSlyzard(),
        createWerecat(),
        createHarpy(),
        createWildHuntDrakkar(),
        createGeels(),
        createWildHuntRider(),
        createVranWarrior(),
        createAnCraiteArmorsmith(),
        createAvalach(),
        createAvalachSage(),
        createNekurat(),
        createRaghNarRoog(),
        createGeraltProfessional(),
        createGeraltAard(),
        createGeraltYrden(),
        createCiriDash(),
        createAguara(),
        createAguaraTrueForm(),
        createKorathiHeatwave(),
        createAleOfTheAncestors(),
        createMahakamAle(),
        createOdrin(),
        createToruviel(),
        createCiri(),
        createMilva(),
        createPrincessPavetta(),
        createTheGuardian(),
        createGaunterODimm(),
        createKaedweniSergeant(),
        createReinforcedBallista(),
        createSigismundDijkstra(),
        createWhiteFrost(),
        createWolfsbane(),
        createDunBanner(),
        createAelirenn(),
        createHanmarvynsDream(),
        createBlackBlood(),
        createBekkersRockslide(),
        createBekkersDarkMirror(),
        createMerigoldsHailstorm(),
        createNecromancy(),
        createStammelfordsTremor(),
        createExpiredAle(),
        createTrialOfTheGrasses(),
        createDimeritiumBomb(),
        createGarrison(),
        createTheLastWish(),
        createDimeritiumShackles(),
        createWyvernScaleShield(),
        createMastercraftedSpear(),
        createPetrisPhilter(),
        createShrike(),
        createRoyalDecree(),
        createUmasCurse(),
        createLacerate(),
        createCrowsEye(),
        createDoppler(),
        createSpores(),
        createMardroeme(),
        createSihil(),
        createEskelPathfinder(),
        createVesemirMentor(),
        createLambertSwordmaster(),
        createRegisHigherVampire(),
        createZoltanScoundrel(),
        createYenneferConjurer(),
        createTrissMerigold(),
        createTrissTelekinesis(),
        createDorregarayOfVole(),
        createDandelionVainglory(),
        createCyprianWiley(),
        createDudu(),
        createIhuarraquax(),
        createMahakamMarauder(),
        createZoltanChivay(),
        createYenneferNecromancer(),
        createPhoenix(),
        createSaesenthessisBlaze(),
        createVillentretenmerth(),
        createOcvist(),
        createMyrgtabrakke(),
        createKingOfBeggars(),
        createOlgierdVonEverec(),
        createIrisVonEverec(),
        createIrisCompanions(),
        createJohnny(),
        createStregobor(),
        createSarah(),
        createPeasantMilitia(),
        createPrizeWinningCow(),
        createPrincessAdda(),
        createKingFoltest(),
        createKingRadovidV(),
        createEmhyrVarEmreis(),
        createUsurper(),
        createBrouverHoog(),
        createEithne(),
        createFilavandrel(),
        createFrancescaFindabair(),
        createAglais(),
        createIorveth(),
        createIorvethMeditation(),
        createIsengrimFaoiltiarna(),
        createIsengrimOutlaw(),
        createSchirru(),
        createSaesenthessis(),
        createSaskia(),
        createBarclayEls(),
        createDennisCranmer(),
        createSheldonSkaggs(),
        createYarpenZigrin(),
        createYaevinn(),
        createIdaEmeanAepSivney(),
        createPavkoGale(),
        createCiaranAepEasnillen(),
        createEibhearHattori(),
        createMilaen(),
        createBraenn(),
        createMorenn(),
        createPaulieDahlberg(),
        createMahakamHorn(),
        createNaturesGift(),
        createPitTrap(),
        createCrushingTrap(),
        createElvenBlade(),
        createIncineratingTrap(),
        createBlueMountainElite(),
        createDolBlathannaBomber(),
        createDolBlathannaBowman(),
        createDolBlathannaSentry(),
        createElvenScout(),
        createElvenSwordmaster(),
        createDwarvenAgitator(),
        createDwarvenMercenary(),
        createDwarvenSkirmisher(),
        createHawkerHealer(),
        createHawkerSupport(),
        createMahakamDefender(),
        createMahakamGuard(),
        createMahakamVolunteers(),
        createPyrotechnician(),
        createWardancer(),
        createVriheddVanguard(),
        createVriheddOfficer(),
        createVriheddNeophyte(),
        createVriheddBrigade(),
        createHawkerSmuggler(),
        createMennoCoehoorn(),
        createRainfarnOfAttre(),
        createAssassination(),
        createStefanSkellen(),
        createShilard(),
        createCantarella(),
        createPanther(),
        createVicovaroMedic(),
        createAssireVarAnahid(),
        createFringillaVigo(),
        createFalseCiri(),
        createDandelion(),
        createKiyan(),
        createPhilippaEilhart(),
        createRocheMerciless(),
        createShani(),
        createVandergrift(),
        createBotchling(),
        createLubberkin(),
        createNilfgaardianGate(),
        createPeterSaarGwynleve(),
        createVicovaroNovice(),
        createCadaverine(),
        createJoachimDeWett(),
        createTreason(),
        createVanhemar(),
        createVrygheff(),
        createAlbaPikeman(),
        createCombatEngineer(),
        createMagneDivision(),
        createNauzicaaBrigade(),
        createSlaveDriver(),
        createSlaveHunter(),
        createViperWitcher(),
        createRotTosser(),
        createCowCarcass(),
        createStandardBearer(),
        createCursedKnight(),
        createWerewolf(),
        createMargaritaOfAretuza(),
        createNenneke(),
        createSabrinasSpecter(),
        createSabrinaGlevissig(),
        createThaler(),
        createAedirnianMauler(),
        createAretuzaAdept(),
        createVandergriftsBlade(),
        createReinforcedTrebuchet(),
        createBallista(),
        createBloodyFlail(),
        createBatteringRam(),
        createTrebuchet(),
        createBanArdTutor(),
        createFieldMedic(),
    };
    return cards;
}

Card *Cards::createAddaStriga()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAddaStriga, this);

    res->id = "200073";
    res->power = res->powerBase = 6;
    res->rarity = Silver;
    res->faction = Monster;
    res->tags = { Relict, Cursed };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isNonMonsterFaction});
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.damage(target, 8, self);
    };

    return res;
}

Card *Cards::createDaoLesser()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDaoLesser, this);

    res->id = "132405";
    res->power = res->powerBase = 4;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Construct };
    res->isDoomed = true;
    return res;
}

Card *Cards::createDao()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDao, this);

    res->id = "132213";
    res->power = res->powerBase = 6;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Construct };

    res->_onDestroy = [this](Card *self, IGame &game, const RowAndPos &rowAndPos) {
        game.spawnNewUnitToPos(createDaoLesser(), rowAndPos, self);
        game.spawnNewUnitToPos(createDaoLesser(), rowAndPos, self);
    };

    return res;
}


Card *Cards::createLeftFlankInfantry()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createLeftFlankInfantry, this);

    res->id = "200302";
    res->power = res->powerBase = 2;
    res->rarity = Bronze;
    res->faction = NothernRealms;
    res->tags = { Temeria, Soldier };
    res->isDoomed = true;
    return res;
};



Card *Cards::createRightFlankInfantry()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createRightFlankInfantry, this);

    res->id = "200303";
    res->power = res->powerBase = 2;
    res->rarity = Bronze;
    res->faction = NothernRealms;
    res->tags = { Temeria, Soldier };
    res->isDoomed = true;
    return res;
};

Card *Cards::createPoorFingInfantry()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createPoorFingInfantry, this);

    res->id = "200234";
    res->power = res->powerBase = 6;
    res->rarity = Bronze;
    res->faction = NothernRealms;
    res->tags = { Temeria, Soldier };


    res->_onDeploy = [this](Card *self, IGame &game) {
        game.spawnNewUnitToPos(createLeftFlankInfantry(), rowAndPosToTheLeft(self, 1), self);
        game.spawnNewUnitToPos(createRightFlankInfantry(), rowAndPosToTheRight(self, 1), self);
    };
    return res;
}

Card *Cards::createDeithwenArbalest()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDeithwenArbalest, this);

    res->id = "162305";
    res->power = res->powerBase = 7;
    res->rarity = Bronze;
    res->faction = Nilfgaard;
    res->tags = { Soldier };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.damage(target, target->isSpy ? 6 : 3, self);
    };
    return res;
}


Card *Cards::createTemerianDrummer()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createTemerianDrummer, this);

    res->id = "200299";
    res->power = res->powerBase = 5;
    res->rarity = Bronze;
    res->faction = NothernRealms;
    res->tags = { Temeria, Support };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AllyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.boost(target, 6, self);
    };
    return res;
}


Card *Cards::createDandelionPoet()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDandelionPoet, this);

    res->id = "201776";
    res->power = res->powerBase = 5;
    res->rarity = Gold;
    res->faction = Neutral;
    res->tags = { Support };

    res->_onDeploy = [](Card *self, IGame &game) {
        if (game.drawACard(self))
            game.startChoiceToTargetCard(self, {}, AllyHand);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}


Card *Cards::createSileDeTansarville()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSileDeTansarville, this);

    res->id = "122205";
    res->power = res->powerBase = 4;
    res->rarity = Silver;
    res->faction = NothernRealms;
    res->tags = { Mage };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronzeOrSilver, ::isSpecial}, AllyHand);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
        game.drawACard(self);
    };
    return res;
}


Card *Cards::createRedanianKnightElect()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createRedanianKnightElect, this);

    res->id = "123301";
    res->power = res->powerBase = 7;
    res->rarity = Bronze;
    res->faction = NothernRealms;
    res->tags = { Redania, Soldier };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.gainArmor(self, 2, self);
    };

    res->_onTurnEnd = [](Card *self, IGame &game) {
        if (self->armor == 0)
            return;

        Card *left = cardNextTo(self, -1);
        if (left != nullptr)
            game.boost(left, 1, self);

        Card *right = cardNextTo(self, 1);
        if (right != nullptr)
            game.boost(right, 1, self);
    };
    return res;
}


Card *Cards::createAnCraiteMarauder()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAnCraiteMarauder, this);

    res->id = "201578";
    res->power = res->powerBase = 7;
    res->rarity = Bronze;
    res->faction = Skellige;
    res->tags = { ClanAnCraite, Soldier };

    // FIXME: no ability
    return res;
}


Card *Cards::createAnCraiteGreatsword()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAnCraiteGreatsword, this);

    res->id = "200040";
    res->power = res->powerBase = 8;
    res->rarity = Bronze;
    res->faction = Skellige;
    res->tags = { ClanAnCraite, Soldier };

    res->_onDeploy = [](Card *self, IGame &game) {
        setTimer(self, 2);
    };

    res->_onTurnStart = [](Card *self, IGame &game) {
        if (!isOnBoard(self, ally) || !tick(self, 2))
            return;

        if (self->power >= self->powerBase)
            return;

        heal(self, self);
        strengthen(self, 2, self);
    };
    return res;
}


Card *Cards::createDimunLightLongship()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDimunLightLongship, this);

    res->id = "152309";
    res->power = res->powerBase = 7;
    res->rarity = Bronze;
    res->faction = Skellige;
    res->tags = { ClanDimun, Machine };

    res->_onTurnEnd = [](Card *self, IGame &game) {
        if (Card *right = cardNextTo(self, 1)) {
            game.damage(right, 1, self);
            game.boost(self, 2, self);
        }
    };
    return res;
}


Card *Cards::createBear()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createBear, this);

    res->id = "152406";
    res->power = res->powerBase = 11;
    res->rarity = Bronze;
    res->faction = Neutral;
    res->tags = { Beast, Cursed };
    return res;
}


Card *Cards::createWolf()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createWolf, this);

    res->id = "132403";
    res->power = res->powerBase = 1;
    res->isDoomed = true;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Beast };
    return res;
}


Card *Cards::createTuirseachBearmaster()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createTuirseachBearmaster, this);

    res->id = "200144";
    res->power = res->powerBase = 1;
    res->rarity = Bronze;
    res->faction = Skellige;
    res->tags = { ClanTuirseach, Soldier };

    res->_onDeploy = [this](Card *self, IGame &game) {
        game.spawnNewCard(createBear(), self);
    };
    return res;
}


Card *Cards::createRedanianElite()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createRedanianElite, this);

    res->id = "122317";
    res->power = res->powerBase = 8;
    res->rarity = Bronze;
    res->faction = NothernRealms;
    res->tags = { Redania, Soldier };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.gainArmor(self, 4, self);
    };

    res->_onArmorLost = [](Card *self, IGame &game) {
        game.boost(self, 5, self);
    };
    return res;
}


Card *Cards::createRedanianKnight()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createRedanianKnight, this);

    res->id = "122308";
    res->power = res->powerBase = 7;
    res->rarity = Bronze;
    res->faction = NothernRealms;
    res->tags = { Redania, Soldier };

    res->_onTurnEnd = [](Card *self, IGame &game) {
        if (self->armor != 0)
            return;
        game.boost(self, 2, self);
        game.gainArmor(self, 2, self);
    };
    return res;
}


Card *Cards::createKaedweniCavalry()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createKaedweniCavalry, this);

    res->id = "122314";
    res->power = res->powerBase = 8;
    res->rarity = Bronze;
    res->faction = NothernRealms;
    res->tags = { Kaedwen, Soldier };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {hasArmor});
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        const int armorTarget = target->armor;
        game.damage(target, armorTarget, self);
        game.boost(self, armorTarget, self);
    };
    return res;
}


Card *Cards::createAlzursThunder()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAlzursThunder, this);

    res->id = "113301";
    res->rarity = Bronze;
    res->faction = Neutral;
    res->tags = { Spell };
    res->isSpecial = true;

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.damage(target, 9, self);
    };
    return res;
}


Card *Cards::createSwallow()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSwallow, this);

    res->id = "113310";
    res->rarity = Bronze;
    res->faction = Neutral;
    res->tags = { Alchemy, Item };
    res->isSpecial = true;

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.boost(target, 10, self);
    };
    return res;
}


Card *Cards::createThunderbolt()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createThunderbolt, this);

    res->id = "113311";
    res->rarity = Bronze;
    res->faction = Neutral;
    res->tags = { Alchemy, Item };
    res->isSpecial = true;

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.boost(target, 3, self);
        game.gainArmor(target, 2, self);

        Card *left = cardNextTo(target, -1);
        if (left != nullptr) {
            game.boost(left, 3, self);
            game.gainArmor(left, 2, self);
        }

        Card *right = cardNextTo(target, 1);
        if (right != nullptr) {
            game.boost(right, 3, self);
            game.gainArmor(right, 2, self);
        }
    };
    return res;
}


Card *Cards::createArachasVenom()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createArachasVenom, this);

    res->id = "200023";
    res->rarity = Bronze ;
    res->faction = Neutral;
    res->tags = { Organic };
    res->isSpecial = true;

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        Card *left = cardNextTo(target, -1);
        Card *right = cardNextTo(target, 1);
        for (Card *card: std::vector<Card *>{left, target, right})
            if (card != nullptr)
                game.damage(card, 4, card);
    };
    return res;
}


Card *Cards::createKeiraMetz()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createKeiraMetz, this);

    res->id = "122108";
    res->power = res->powerBase = 6;
    res->rarity = Gold;
    res->faction = NothernRealms;
    res->tags = { Temeria, Mage };

    res->_onDeploy = [this](Card *self, IGame &game) {
        game.startChoiceToSelectOption(self, {createAlzursThunder(), createThunderbolt(), createArachasVenom()});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        game.spawnNewCard(target, self);
    };
    return res;
}


Card *Cards::createDolBlathannaArcher()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDolBlathannaArcher, this);

    res->id = "142310";
    res->power = res->powerBase = 7;
    res->rarity = Bronze;
    res->faction = Scoiatael;
    res->tags = { Elf, Soldier };

    struct State : StateCopy<State> { int _nShots = 0; };
    res->state = new State();

    res->_onDeploy = [](Card *self, IGame &game) {
        self->stateAs<State>()->_nShots = 0;
        game.startChoiceToTargetCard(self);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        int &nShots = self->stateAs<State>()->_nShots;
        ++nShots;
        if (nShots == 1) {
            game.damage(target, 3, self);
            game.startChoiceToTargetCard(self);
            return;
        }
        if (nShots == 2) {
            game.damage(target, 1, self);
            return;
        }
        throw Error(Error::Unreachable, self);
    };
    return res;
}


Card *Cards::createHalfElfHunter()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createHalfElfHunter, this);

    res->id = "201636";
    res->power = res->powerBase = 6;
    res->rarity = Bronze;
    res->faction = Scoiatael;
    res->tags = { Elf, Soldier };

    res->_onDeploy = [](Card *self, IGame &game) {
        Card *copy = self->defaultCopy();
        copy->isDoomed = true;
        summonNewUnitToPos(copy, rowAndPosToTheRight(self, ally, 1), self);
    };
    return res;
}


Card *Cards::createAmbassador()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAmbassador, this);

    res->id = "162315";
    res->power = res->powerBase = 2;
    res->isLoyal = false;
    res->rarity = Bronze;
    res->faction = Nilfgaard;
    res->tags = {};

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AllyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.boost(target, 12, self);
    };
    return res;
}


Card *Cards::createAssassin()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAssassin, this);

    res->id = "200115";
    res->power = res->powerBase = 1;
    res->isLoyal = false;
    res->rarity = Bronze;
    res->faction = Nilfgaard;
    res->tags = {};

    res->_onDeploy = [](Card *self, IGame &game) {
        if (Card *left = cardNextTo(self, -1)) {
            game.damage(left, 10, self);
        }
    };
    return res;
}


Card *Cards::createTuirseachArcher()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createTuirseachArcher, this);

    res->id = "152315";
    res->power = res->powerBase = 8;
    res->rarity = Bronze;
    res->faction = Skellige;
    res->tags = { ClanTuirseach, Soldier };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AnyBoard, 3);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.damage(target, 1, self);
    };
    return res;
}


Card *Cards::createInfiltrator()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createInfiltrator, this);

    res->id = "200118";
    res->power = res->powerBase = 10;
    res->rarity = Bronze;
    res->faction = Nilfgaard;
    res->tags = {};

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        toggleSpy(target, self);
    };
    return res;
}


Card *Cards::createImpenetrableFog()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createImpenetrableFog, this);

    res->id = "113305";
    res->isSpecial = true;
    res->rarity = Bronze;
    res->faction = Neutral;
    res->tags = { Hazard };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        startChoiceToSelectRow(self, {3, 4, 5});
    };

    res->_onTargetRowChoosen = [](Card *self, IGame &game, const int screenRow) {
        applyRowEffect(screenRow, ImpenetrableFogEffect);
    };
    return res;
}


Card *Cards::createTorrentialRain()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createTorrentialRain, this);

    res->id = "113312";
    res->isSpecial = true;
    res->rarity = Bronze;
    res->faction = Neutral;
    res->tags = { Hazard };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        startChoiceToSelectRow(self, {3, 4, 5});
    };

    res->_onTargetRowChoosen = [](Card *self, IGame &game, const int screenRow) {
        applyRowEffect(screenRow, TorrentialRainEffect);
    };
    return res;
}


Card *Cards::createBitingFrost()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createBitingFrost, this);

    res->id = "113302";
    res->isSpecial = true;
    res->rarity = Bronze;
    res->faction = Neutral;
    res->tags = { Hazard };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        startChoiceToSelectRow(self, {3, 4, 5});
    };

    res->_onTargetRowChoosen = [](Card *self, IGame &game, const int screenRow) {
        applyRowEffect(screenRow, BitingFrostEffect);
    };
    return res;
}


Card *Cards::createGoldenFroth()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createGoldenFroth, this);

    res->id = "201749";
    res->isSpecial = true;
    res->rarity = Bronze;
    res->faction = Neutral;
    res->tags = { Boon };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        startChoiceToSelectRow(self, {0, 1, 2});
    };

    res->_onTargetRowChoosen = [](Card *self, IGame &game, const int screenRow) {
        applyRowEffect(screenRow, GoldenFrothEffect);
    };
    return res;
}


Card *Cards::createSkelligeStorm()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSkelligeStorm, this);

    res->id = "113203";
    res->isSpecial = true;
    res->rarity = Silver;
    res->faction = Neutral;
    res->tags = { Hazard };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        startChoiceToSelectRow(self, {3, 4, 5});
    };

    res->_onTargetRowChoosen = [](Card *self, IGame &game, const int screenRow) {
        applyRowEffect(screenRow, SkelligeStormEffect);
    };
    return res;
}


Card *Cards::createImperialManticore()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createImperialManticore, this);

    res->id = "132209";
    res->power = res->powerBase = 13;
    res->rarity = Silver;
    res->faction = Monster;
    res->tags = { Beast };
    return res;
}


Card *Cards::createManticoreVenom()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createManticoreVenom, this);

    res->id = "113306";
    res->isSpecial = true;
    res->rarity = Silver;
    res->faction = Neutral;
    res->tags = { Organic };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.damage(target, 13, self);
    };
    return res;
}


Card *Cards::createGloriousHunt()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createGloriousHunt, this);

    res->id = "201635";
    res->isSpecial = true;
    res->rarity = Silver;
    res->faction = Neutral;
    res->tags = { Tactics };

    res->_onPlaySpecial = [this](Card *self, IGame &game) {
        const bool isLoosing = powerField(ally) < powerField(enemy);
        Card *card = isLoosing ? createImperialManticore() : createManticoreVenom();
        return game.spawnNewCard(card, self);
    };
    return res;
}


Card *Cards::createVes()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createVes, this);

    res->id = "122204";
    res->power = res->powerBase = 12;
    res->rarity = Silver;
    res->faction = NothernRealms;
    res->tags = { Temeria, Soldier };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AllyHand, 2, true);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.swapACard(target, self);
    };
    return res;
}


Card *Cards::createVaedermakar()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createVaedermakar, this);

    res->id = "113208";
    res->power = res->powerBase = 4;
    res->rarity = Silver;
    res->faction = Neutral;
    res->tags = { Mage };

    res->_onDeploy = [this](Card *self, IGame &game) {
        game.startChoiceToSelectOption(self, {createBitingFrost(), createImpenetrableFog(), createAlzursThunder()});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        game.spawnNewCard(target, self);
    };
    return res;
}


Card *Cards::createFrightener()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createFrightener, this);

    res->id = "132204";
    res->power = res->powerBase = 13;
    res->isLoyal = false;
    res->timer = 1;
    res->rarity = Silver;
    res->faction = Monster;
    res->tags = { Construct, Agent };

    res->_onDeploy = [](Card *self, IGame &game) {
        if (tick(self, ally, enemy))
            game.drawACard(self);

        /// can't move another to this row, if its already full
        game.startChoiceToTargetCard(self, {isOnAnotherRow(&enemy, self)}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        moveExistedUnitToPos(target, rowAndPosLastInTheSameRow(self, enemy), enemy, ally, self);
    };
    return res;
}


Card *Cards::createCleaver()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createCleaver, this);

    res->id = "122216";
    res->power = res->powerBase = 7;
    res->rarity = Silver;
    res->faction = Neutral;
    res->tags = { Dwarf };

    res->_onDeploy = [](Card *self, IGame &game) {
        if (ally.hand.size() != 0)
            game.startChoiceToTargetCard(self, {}, AnyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.damage(target, int(ally.hand.size()), self);
    };
    return res;
}


Card *Cards::createScorch()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createScorch, this);

    res->id = "113309";
    res->isSpecial = true;
    res->rarity = Silver;
    res->faction = Neutral;
    res->tags = { Spell };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        for (Card *card : highests(cardsFiltered({}, AnyBoard)))
            putToDiscard(card, self);
    };
    return res;
}


Card *Cards::createReinforcements()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createReinforcements, this);

    res->id = "123201";
    res->isSpecial = true;
    res->rarity = Silver;
    res->faction = NothernRealms;
    res->tags = { Tactics };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronzeOrSilver, hasAnyOfTags({Soldier, Support, Machine, Officer})}, AllyDeckShuffled);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}


Card *Cards::createJohnNatalis()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createJohnNatalis, this);

    res->id = "122103";
    res->power = res->powerBase = 6;
    res->rarity = Gold;
    res->faction = NothernRealms;
    res->tags = { Temeria, Officer };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronzeOrSilver, hasTag(Tactics)}, AllyDeckShuffled);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}


Card *Cards::createEleyas()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createEleyas, this);

    res->id = "142214";
    res->power = res->powerBase = 10;
    res->rarity = Silver;
    res->faction = Scoiatael;
    res->tags = { Elf, Soldier };

    // FIXME: when Eleyas goes to deck, it loses all the boosts - so it doesn't work properly
    res->_onDraw = [](Card *self, IGame &game) {
        game.boost(self, 2, self);
    };

    res->_onSwap = [](Card *self, IGame &game) {
        game.boost(self, 2, self);
    };
    return res;
}


Card *Cards::createReaverScout()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createReaverScout, this);

    res->id = "122307";
    res->power = res->powerBase = 1;
    res->rarity = Bronze;
    res->faction = NothernRealms;
    res->tags = { Redania, Support };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronze, otherThan(self->id), hasCopyInADeck(&ally)}, AllyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        if (Card *copy = findCopy(target, ally.deck))
            game.playExistedCard(copy, self);
    };
    return res;
}


Card *Cards::createHeymaeySpearmaiden()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createHeymaeySpearmaiden, this);

    res->id = "200528";
    res->power = res->powerBase = 2;
    res->rarity = Bronze;
    res->faction = Skellige;
    res->tags = { ClanAnCraite, Support };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronze, hasAnyOfTags({Soldier, Machine}), hasCopyInADeck(&ally)}, AllyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.damage(target, 1, self);
        if (Card *copy = findCopy(target, ally.deck))
            game.playExistedCard(copy, self);
    };
    return res;
}


Card *Cards::createKaedweniKnight()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createKaedweniKnight, this);

    res->id = "201622";
    res->power = res->powerBase = 8;
    res->rarity = Bronze;
    res->faction = NothernRealms;
    res->tags = { Kaedwen, Soldier };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.gainArmor(self, 2, self);
    };

    res->_onDeployFromDeck = [](Card *self, IGame &game) {
        game.gainArmor(self, 2, self);
        game.boost(self, 5, self);
    };
    return res;
}


Card *Cards::createVriheddSappers()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createVriheddSappers, this);

    res->id = "142307";
    res->power = res->powerBase = 11;
    res->isAmbush = true;
    res->rarity = Bronze;
    res->faction = Scoiatael;
    res->tags = { Elf, Soldier };

    res->_onDeploy = [](Card *self, IGame &game) {
        self->isAmbush = true;
        setTimer(self, 2);
    };

    res->_onTurnStart = [](Card *self, IGame &game) {
        if (!isOnBoard(self, ally) || tick(self, ally, enemy))
            flipOver(self, ally, enemy);
    };
    return res;
}


Card *Cards::createPriestessOfFreya()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createPriestessOfFreya, this);

    res->id = "152310";
    res->power = res->powerBase = 1;
    res->rarity = Bronze;
    res->faction = Skellige;
    res->tags = { ClanHeymaey, Support };
    res->isDoomed = true;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronze, hasTag(Soldier)}, AllyDiscard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}


Card *Cards::createDimunCorsair()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDimunCorsair, this);

    res->id = "200145";
    res->power = res->powerBase = 3;
    res->rarity = Bronze;
    res->faction = Skellige;
    res->tags = { ClanDimun, Support };
    res->isDoomed = true;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronze, hasTag(Machine)}, AllyDiscard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}


Card *Cards::createSigrdrifa()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSigrdrifa, this);

    res->id = "152211";
    res->power = res->powerBase = 3;
    res->rarity = Silver;
    res->faction = Skellige;
    res->tags = { Support };
    res->isDoomed = true;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronzeOrSilver, hasAnyOfTags({ClanAnCraite, ClanDimun, ClanDrummond, ClanHeymaey, ClanTuirseach, ClanBrokvar, ClanTordarroch})}, AllyDiscard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}


Card *Cards::createSage()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSage, this);

    res->id = "200138";
    res->power = res->powerBase = 2;
    res->rarity = Bronze;
    res->faction = Scoiatael;
    res->tags = { Elf, Mage };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronze, hasAnyOfTags({Alchemy, Spell})}, AllyDiscard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        target->isDoomed = true;
        game.playExistedCard(target, self);
    };
    return res;
}


Card *Cards::createReconnaissance()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createReconnaissance, this);

    res->id = "201704";
    res->isSpecial = true;
    res->rarity = Bronze;
    res->faction = Neutral;
    res->tags = { Tactics };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, randoms(cardsFiltered({isBronze, isUnit}, AllyDeck), 2, ally.rng));
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}


Card *Cards::createElvenMercenary()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createElvenMercenary, this);

    res->id = "142308";
    res->power = res->powerBase = 1;
    res->rarity = Bronze;
    res->faction = Scoiatael;
    res->tags = { Elf, Soldier };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, randoms(cardsFiltered({isBronze, ::isSpecial}, AllyDeck), 2, ally.rng));
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}


Card *Cards::createChampionOfHov()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createChampionOfHov, this);

    res->id = "152202";
    res->power = res->powerBase = 7;
    res->rarity = Silver;
    res->faction = Skellige;
    res->tags = { Ogroid };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        duel(self, target, ally, enemy);
    };
    return res;
}


Card *Cards::createGeraltIgni()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createGeraltIgni, this);

    res->id = "112102";
    res->power = res->powerBase = 5;
    res->rarity = Gold;
    res->faction = Neutral;
    res->tags = { Witcher };

    const auto isOkRow = [](const std::vector<Card *> &cards) {
        return powerRow(cards) >= 25;
    };

    res->_onDeploy = [isOkRow](Card *self, IGame &game) {
        startChoiceToSelectRow(self, {3, 4, 5}, {isOkRow});
    };

    res->_onTargetRowChoosen = [](Card *self, IGame &game, const int screenRow) {
        for (Card *card : highests(cardsInRow(screenRow)))
            putToDiscard(card, self);
    };
    return res;
}


Card *Cards::createGeraltOfRivia()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createGeraltOfRivia, this);

    res->id = "112103";
    res->power = res->powerBase = 15;
    res->rarity = Gold;
    res->faction = Neutral;
    res->tags = { Witcher };
    return res;
}


Card *Cards::createPriscilla()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createPriscilla, this);

    res->id = "122202";
    res->power = res->powerBase = 3;
    res->rarity = Gold;
    res->faction = NothernRealms;
    res->tags = { Support };

    res->_onDeploy = [](Card *self, IGame &game) {
        for (Card *card : randoms(cardsFiltered({otherThan(self)}, AllyBoard), 5, ally.rng))
            game.boost(card, 3, self);
    };
    return res;
}


Card *Cards::createSeltkirkOfGulet()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSeltkirkOfGulet, this);

    res->id = "201618";
    res->power = res->powerBase = 8;
    res->rarity = Gold;
    res->faction = NothernRealms;
    res->tags = { Aedirn, Officer, Cursed };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.gainArmor(self, 3, self);
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        duel(self, target, ally, enemy);
    };
    return res;
}


Card *Cards::createAdrenalineRush()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAdrenalineRush, this);

    res->id = "113307";
    res->isSpecial = true;
    res->rarity = Bronze;
    res->faction = Neutral;
    res->tags = { Organic };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, Field &, Field &) {
        target->isResilient = !target->isResilient;
    };
    return res;
}


struct StateChoosen : StateCopy<StateChoosen> { Card *_choosen = nullptr; };


Card *Cards::createMandrake()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMandrake, this);

    res->id = "200223";
    res->isSpecial = true;
    res->rarity = Silver;
    res->faction = Neutral;
    res->tags = { Alchemy, Organic };
    res->state = new StateChoosen();

    enum { Buff, Debuff };
    res->_onPlaySpecial = [](Card *self, IGame &game) {
        Card *option1 = createOption(self, Buff);
        option1->text = "Heal a unit and and Strengthen it by 6.";

        Card *option2 = createOption(self, Debuff);
        option2->text = "Reset a unit and Weaken it by 6.";

        self->stateAs<StateChoosen>()->_choosen = nullptr;
        game.startChoiceToSelectOption(self, {option1, option2});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        self->stateAs<StateChoosen>()->_choosen = target;
        game.startChoiceToTargetCard(self);
        return;
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        Card *choosen = self->stateAs<StateChoosen>()->_choosen;
        if (!choosen)
            throw Error(Error::ChoosenIsNullptr, self);

        if (isOption(choosen, Buff)) {
            heal(target, self);
            strengthen(target, 6, self);

            delete choosen;
            choosen = nullptr;
            return;
        }

        if (isOption(choosen, Debuff)) {
            reset(target, self);
            weaken(target, 6, self);

            delete choosen;
            choosen = nullptr;
            return;
        }

        throw Error(Error::Unreachable, self);
    };
    return res;
}


Card *Cards::createBoneTalisman()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createBoneTalisman, this);

    res->id = "201598";
    res->isSpecial = true;
    res->rarity = Bronze;
    res->faction = Skellige;
    res->tags = { Item };
    res->state = new StateChoosen();

    enum { Resurrect, Buff };
    res->_onPlaySpecial = [](Card *self, IGame &game) {
        auto *option1 = createOption(self, Resurrect);
        option1->text = "Resurrect a Bronze Beast or Cultist.";

        auto *option2 = createOption(self, Buff);
        option2->text = "Heal an ally and Strengthen it by 3.";

        self->stateAs<StateChoosen>()->_choosen = nullptr;
        game.startChoiceToSelectOption(self, {option1, option2});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        self->stateAs<StateChoosen>()->_choosen = target;

        if (isOption(target, Resurrect))
            return game.startChoiceToTargetCard(self, {isBronze, hasAnyOfTags({Beast, Cultist})}, AllyDiscard);

        if (isOption(target, Buff))
            return game.startChoiceToTargetCard(self, {}, AllyBoard);

        throw Error(Error::Unreachable, self);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        Card *choosen = self->stateAs<StateChoosen>()->_choosen;
        if (!choosen)
            throw Error(Error::ChoosenIsNullptr, self);

        if (isOption(choosen, Resurrect)) {
            game.playExistedCard(target, self);

            delete choosen;
            choosen = nullptr;
            return;
        }

        if (isOption(choosen, Buff)) {
            heal(target, self);
            strengthen(target, 3, self);

            delete choosen;
            choosen = nullptr;
            return;
        }

        throw Error(Error::Unreachable, self);
    };
    return res;
}


Card *Cards::createShupesDayOff()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createShupesDayOff, this);

    res->id = "201627";
    res->isSpecial = true;
    res->rarity = Gold;
    res->faction = Neutral;
    res->tags = { Organic };

    res->_onPlaySpecial = [this](Card *self, IGame &game) {
        if (!hasNoDuplicates(ally.deckStarting))
            return;

        game.startChoiceToSelectOption(self, {createShupeKnight(), createShupeHunter(), createShupeMage()});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        game.spawnNewCard(target, self);
    };
    return res;
}


Card *Cards::createShupeHunter()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createShupeHunter, this);

    res->id = "201731";
    res->power = res->powerBase = 8;
    res->isDoomed = true;
    res->rarity = Gold;
    res->faction = Neutral;
    res->tags = { Ogroid };
    res->state = new StateChoosen();

    enum { Play, Shot, Replay, Clear, Barrage };
    res->_onDeploy = [](Card *self, IGame &game) {
        auto *option1 = createOption(self, Play);
        option1->text = "Play a Bronze or Silver unit from Deck.";

        auto *option2 = createOption(self, Shot);
        option2->text = "Deal 15 damage.";

        auto *option3 = createOption(self, Replay);
        option3->text = "Replay a Bronze or Silver unit and Boost it by 5.";

        auto *option4 = createOption(self, Clear);
        option4->text = "Clear all Hazards from your side and Boost allies by 1.";

        auto *option5 = createOption(self, Barrage);
        option5->text = "Deal 2 damage to a random enemy. Repeat 8 times.";

        self->stateAs<StateChoosen>()->_choosen = nullptr;
        game.startChoiceToSelectOption(self, {option1, option2, option3, option4, option5}, 1, 3);
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        if (isOption(target, Play)) {
            self->stateAs<StateChoosen>()->_choosen = target;
            game.startChoiceToTargetCard(self, {isBronzeOrSilver, isUnit}, AllyDeck);
            return;
        }

        if (isOption(target, Shot)) {
            self->stateAs<StateChoosen>()->_choosen = target;
            game.startChoiceToTargetCard(self);
            return;
        }

        if (isOption(target, Replay)) {
            self->stateAs<StateChoosen>()->_choosen = target;
            game.startChoiceToTargetCard(self, {isBronzeOrSilver, isUnit}, AllyBoard);
            return;
        }

        if (isOption(target, Clear)) {
            for (Card *card : cardsFiltered({}, AllyBoard))
                game.boost(card, 1, self);
            clearAllHazards(ally);
            return;
        }

        if (isOption(target, Barrage)) {
            for (int n = 0; n < 8; ++n)
                if (Card *card = random(cardsFiltered({}, EnemyBoard), ally.rng))
                    game.damage(card, 2, self);
            return;
        }

        throw Error(Error::Unreachable, self);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        Card *choosen = self->stateAs<StateChoosen>()->_choosen;
        if (!choosen)
            throw Error(Error::ChoosenIsNullptr, self);

        if (isOption(choosen, Play)) {
            game.playExistedCard(target, self);
            delete choosen;
            choosen = nullptr;
            return;
        }

        if (isOption(choosen, Shot)) {
            game.damage(target, 15, self);
            delete choosen;
            choosen = nullptr;
            return;
        }

        if (isOption(choosen, Replay)) {
            putToHand(target,  self);
            game.boost(target, 5, self);
            game.playExistedCard(target, self);
            delete choosen;
            choosen = nullptr;
            return;
        }

        throw Error(Error::Unreachable, self);
    };
    return res;
}


Card *Cards::createShupeMage()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createShupeMage, this);

    res->id = "201725";
    res->power = res->powerBase = 4;
    res->isDoomed = true;
    res->rarity = Gold;
    res->faction = Neutral;
    res->tags = { Ogroid };
    res->state = new StateChoosen();

    enum { Draw, Charm, Hazards, Meteor, Play };
    res->_onDeploy = [](Card *self, IGame &game) {
        auto *option1 = createOption(self, Draw);
        option1->text = "Draw a self.";

        auto *option2 = createOption(self, Charm);
        option2->text = "Charm a random enemy.";

        auto *option3 = createOption(self, Hazards);
        option3->text = "Spawn a random Hazard on each enemy row.";

        auto *option4 = createOption(self, Meteor);
        option4->text = "Deal 10 damage to an enemy and 5 damage to each adjacent enemy.";

        auto *option5 = createOption(self, Play);
        option5->text = "Play a Bronze or Silver special self from your deck.";

        self->stateAs<StateChoosen>()->_choosen = nullptr;
        game.startChoiceToSelectOption(self, {option1, option2, option3, option4, option5}, 1, 3);
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        if (isOption(target, Draw)) {
            game.drawACard(self);
            return;
        }

        if (isOption(target, Charm)) {
            if (Card *self = random(cardsFiltered({}, EnemyBoard), ally.rng))
                charm(self, self);
            return;
        }

        if (isOption(target, Hazards)) {
            for (int screenRow = 3; screenRow < 6; ++screenRow)
                applyRowEffect(screenRow, randomHazardEffect(ally.rng));
            return;
        }

        if (isOption(target, Meteor)) {
            self->stateAs<StateChoosen>()->_choosen = target;
            game.startChoiceToTargetCard(self, {}, EnemyBoard);
            return;
        }

        if (isOption(target, Play)) {
            self->stateAs<StateChoosen>()->_choosen = target;
            game.startChoiceToTargetCard(self, {isBronzeOrSilver, ::isSpecial}, AllyDeckShuffled);
            return;
        }

        throw Error(Error::Unreachable, self);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        Card *choosen = self->stateAs<StateChoosen>()->_choosen;
        if (!choosen)
            throw Error(Error::ChoosenIsNullptr, self);

        if (isOption(choosen, Meteor)) {
            Card *left = cardNextTo(target, -1);
            Card *right = cardNextTo(target, 1);

            game.damage(target, 10, self);
            if (left != nullptr) {
                game.damage(left, 5, self);
            }
            if (right != nullptr) {
                game.damage(right, 5, self);
            }

            delete choosen;
            choosen = nullptr;
            return;
        }

        if (isOption(choosen, Play)) {
            game.playExistedCard(target, self);

            delete choosen;
            choosen = nullptr;
            return;
        }

        throw Error(Error::Unreachable, self);
    };
    return res;
}


Card *Cards::createShupeKnight()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createShupeKnight, this);

    res->id = "201737";
    res->power = res->powerBase = 12;
    res->isDoomed = true;
    res->rarity = Gold;
    res->faction = Neutral;
    res->tags = { Ogroid };
    res->state = new StateChoosen();

    enum { Destroy, Reset, Duel, Strengthen, Resilient };
    res->_onDeploy = [](Card *self, IGame &game) {
        auto *option1 = createOption(self, Destroy);
        option1->text = "Destroy enemies with 4 or less power.";

        auto *option2 = createOption(self, Reset);
        option2->text = "Reset a unit.";

        auto *option3 = createOption(self, Duel);
        option3->text = "Duel an enemy.";

        auto *option4 = createOption(self, Strengthen);
        option4->text = "Strengthen self to 25.";

        auto *option5 = createOption(self, Resilient);
        option5->text = "Resilent.";

        self->stateAs<StateChoosen>()->_choosen = nullptr;
        game.startChoiceToSelectOption(self, {option1, option2, option3, option4, option5}, 1, 3);
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        if (isOption(target, Destroy)) {
            for (Card *card : cardsFiltered({hasPowerXorLess(4)}, EnemyBoard))
                putToDiscard(card, self);
            return;
        }

        if (isOption(target, Reset)) {
            self->stateAs<StateChoosen>()->_choosen = target;
            game.startChoiceToTargetCard(self);
            return;
        }

        if (isOption(target, Duel)) {
            self->stateAs<StateChoosen>()->_choosen = target;
            game.startChoiceToTargetCard(self, {}, EnemyBoard);
            return;
        }

        if (isOption(target, Strengthen)) {
            strengthen(self, 25 - self->powerBase, self);
            return;
        }

        if (isOption(target, Resilient)) {
            self->isResilient = true;
            return;
        }

        throw Error(Error::Unreachable, self);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        Card *choosen = self->stateAs<StateChoosen>()->_choosen;
        if (!choosen)
            throw Error(Error::ChoosenIsNullptr, self);

        if (isOption(choosen, Reset)) {
            //target->power = target->powerBase;
            reset(target, self);
            delete choosen;
            choosen = nullptr;
            return;
        }

        if (isOption(choosen, Duel)) {
            duel(self, target, ally, enemy);
            delete choosen;
            choosen = nullptr;
            return;
        }

        throw Error(Error::Unreachable, self);
    };
    return res;
}


Card *Cards::createDecoy()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDecoy, this);

    res->id = "113201";
    res->isSpecial = true;
    res->rarity = Silver;
    res->faction = Neutral;
    res->tags = { Tactics };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, { isBronzeOrSilver }, AllyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        putToHand(target,  self);
        game.boost(target, 3, self);
        game.playExistedCard(target, self);
    };
    return res;
}


Card *Cards::createFirstLight()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createFirstLight, this);

    res->id = "113303";
    res->isSpecial = true;
    res->rarity = Bronze;
    res->faction = Neutral;
    res->tags = { Tactics };

    enum { Clear, Play };
    res->_onPlaySpecial = [](Card *self, IGame &game) {
        auto *option1 = createOption(self, Clear);
        option1->text = "Boost all damaged allies under Hazards by 2 and clear all Hazards from your side.";

        auto *option2 = createOption(self, Play);
        option2->text = "Play a random Bronze unit from your deck.";

        game.startChoiceToSelectOption(self, {option1, option2});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        if (isOption(target, Clear)) {
            std::vector<Card *> damagedUnitsUnderHazards;
            clearAllHazards(ally, &damagedUnitsUnderHazards);
            for (Card *card : damagedUnitsUnderHazards)
                game.boost(card, 2, self);
            delete target;
            return;
        }

        if (isOption(target, Play)) {
            if (Card *card = random(cardsFiltered({ isBronze, isUnit }, AllyDeck), ally.rng))
                game.playExistedCard(card, self);
            delete target;
            return;
        }

        throw Error(Error::Unreachable, self);
    };
    return res;
}


Card *Cards::createClearSkies()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createClearSkies, this);

    res->id = "113303";
    res->isSpecial = true;
    res->rarity = Bronze;
    res->faction = Neutral;
    res->tags = { Tactics };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        std::vector<Card *> damagedUnitsUnderHazards;
        clearAllHazards(ally, &damagedUnitsUnderHazards);
        for (Card *card : damagedUnitsUnderHazards)
            game.boost(card, 2, self);
    };
    return res;
}


Card *Cards::createEpidemic()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createEpidemic, this);

    res->id = "113308";
    res->isSpecial = true;
    res->rarity = Bronze;
    res->faction = Neutral;
    res->tags = { Organic, Spell };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        for (Card *card : lowests(cardsFiltered({}, AnyBoard)))
            putToDiscard(card, self);
    };
    return res;
}


Card *Cards::createMoonlight()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMoonlight, this);

    res->id = "200067";
    res->isSpecial = true;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Hazard, Boon };

    enum { FullMoon, BloodMoon };
    res->_onPlaySpecial = [](Card *self, IGame &game) {
        auto *option1 = createOption(self, FullMoon);
        option1->name = "Full Moon";
        option1->text = "Apply a Boon to an allied row that boosts a random Beast or Vampire by 2 on turn start.";

        auto *option2 = createOption(self, BloodMoon);
        option2->name = "Blood Moon";
        option2->text = "Apply a Hazard to an enemy row that deals 2 damage to all units on contact.";

        game.startChoiceToSelectOption(self, {option1, option2});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        if (isOption(target, FullMoon)) {
            startChoiceToSelectRow(self, {0, 1, 2});
            delete target;
            return;
        }

        if (isOption(target, BloodMoon)) {
            startChoiceToSelectRow(self, {3, 4, 5});
            delete target;
            return;
        }

        throw Error(Error::Unreachable, self);
    };

    res->_onTargetRowChoosen = [](Card *self, IGame &game, const int screenRow) {
        applyRowEffect(screenRow, screenRow < 3 ? FullMoonEffect : BloodMoonEffect);
    };
    return res;
}


Card *Cards::createCiriNova()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createCiriNova, this);

    res->id = "201626";
    res->power = res->powerBase = 1;
    res->isDoomed = true;
    res->rarity = Gold;
    res->faction = Neutral;
    res->tags = { Cintra, Witcher };

    res->_onDeploy = [](Card *self, IGame &game) {
        if (!hasExactTwoDuplicatesOfBronze(ally.deckStarting))
            return;

        strengthen(self, 22 - self->powerBase, self);
    };
    return res;
}


Card *Cards::createHaraldTheCripple()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createHaraldTheCripple, this);

    res->id = "200161";
    res->power = res->powerBase = 6;
    res->rarity = Gold;
    res->faction = Skellige;
    res->tags = { ClanAnCraite, Leader };

    res->_onDeploy = [](Card *self, IGame &game) {
        Row row;
        Pos pos;
        if (!_findRowAndPos(self, ally, row, pos))
            return;
        for (int n = 0; n < 9; ++n)
            if (Card *card = random(enemy.row(row), ally.rng))
                game.damage(card, 1, self);
    };
    return res;
}


Card *Cards::createEmissary()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createEmissary, this);

    res->id = "162314";
    res->isLoyal = false;
    res->power = res->powerBase = 2;
    res->rarity = Bronze;
    res->faction = Nilfgaard;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, randoms(cardsFiltered({isBronze, isUnit}, AllyDeckShuffled), 2, ally.rng));
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}


Card *Cards::createCeallachDyffryn()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createCeallachDyffryn, this);

    res->id = "162213";
    res->power = res->powerBase = 2;
    res->rarity = Silver;
    res->faction = Nilfgaard;
    res->tags = { Officer };

    res->_onDeploy = [this](Card *self, IGame &game) {
        game.startChoiceToSelectOption(self, {createAmbassador(), createAssassin(), createEmissary()});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        game.spawnNewCard(target, self);
    };
    return res;
}


Card *Cards::createRestore()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createRestore, this);

    res->id = "153201";
    res->isSpecial = true;
    res->rarity = Silver;
    res->faction = Skellige;
    res->tags = { Spell };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronzeOrSilver, isUnit, isSkelligeFaction}, AllyDiscard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        putToHand(target,  self);
        target->isDoomed = true;
        target->powerBase = target->power = 8;
        game.playExistedCard(target, self);
    };
    return res;
}


Card *Cards::createDrummondQueensguard()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDrummondQueensguard, this);

    res->id = "152307";
    res->power = res->powerBase = 4;
    res->rarity = Bronze;
    res->faction = Skellige;
    res->tags = { ClanDrummond, Soldier };

    res->_onDeploy = [](Card *self, IGame &game) {
        for (Card *card : cardsFiltered({isCopy(self->id)}, AllyDiscard))
            moveExistedUnitToPos(card, rowAndPosToTheRight(card, ally, 1), self);
    };
    return res;
}


Card *Cards::createBranTuirseach()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createBranTuirseach, this);

    res->id = "200159";
    res->power = res->powerBase = 2;
    res->rarity = Gold;
    res->faction = Skellige;
    res->tags = { ClanTuirseach, Leader };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AllyDeckShuffled, 3, true);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        putToDiscard(target, self);
        if (!target->isSpecial)
            strengthen(target, 1, self);
    };
    return res;
}


Card *Cards::createDrummondWarmonger()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDrummondWarmonger, this);

    res->id = "200036";
    res->power = res->powerBase = 8;
    res->rarity = Bronze;
    res->faction = Skellige;
    res->tags = { ClanDrummond, Soldier };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronze}, AllyDeckShuffled);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        putToDiscard(target, self);
    };
    return res;
}


Card *Cards::createDimunPirate()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDimunPirate, this);

    res->id = "152305";
    res->power = res->powerBase = 11;
    res->rarity = Bronze;
    res->faction = Skellige;
    res->tags = { ClanDimun, Soldier };

    res->_onDeploy = [](Card *self, IGame &game) {
        for (Card *card : cardsFiltered({isCopy(self->id)}, AllyDeck))
            putToDiscard(card, self);
    };
    return res;
}


Card *Cards::createAnCraiteRaider()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAnCraiteRaider, this);

    res->id = "152316";
    res->power = res->powerBase = 4;
    res->rarity = Bronze;
    res->faction = Skellige;
    res->tags = { ClanAnCraite, Soldier };

    res->_onDiscard = [](Card *self, IGame &game) {
        moveExistedUnitToPos(self, rowAndPosRandom(ally), self);
    };
    return res;
}


Card *Cards::createMadmanLugos()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMadmanLugos, this);

    res->id = "152106";
    res->power = res->powerBase = 6;
    res->rarity = Gold;
    res->faction = Skellige;
    res->tags = { ClanDrummond, Officer };

    struct State : StateCopy<State> { Card *_discarded = nullptr; };
    res->state = new State();

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronze, isUnit}, AllyDeckShuffled);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        Card *&discarded = self->stateAs<State>()->_discarded;
        if (discarded == nullptr) {
            discarded = target;
            putToDiscard(target, self);
            game.startChoiceToTargetCard(self, {}, EnemyBoard);
            return;
        }
        game.damage(target, discarded->powerBase, self);
    };
    return res;
}


Card *Cards::createErmion()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createErmion, this);

    res->id = "152103";
    res->power = res->powerBase = 10;
    res->rarity = Gold;
    res->faction = Skellige;
    res->tags = { ClanAnCraite, Support };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.drawACard(self);
        game.drawACard(self);
        game.startChoiceToTargetCard(self, {}, AllyHand, 2);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        putToDiscard(target, self);
    };
    return res;
}


Card *Cards::createCerysFearless()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createCerysFearless, this);

    res->id = "201778";
    res->power = res->powerBase = 6;
    res->rarity = Gold;
    res->faction = Skellige;
    res->tags = { ClanAnCraite, Officer };

    res->_onDeploy = [](Card *self, IGame &game) {
        setTimer(self, 1);
    };

    res->_onOtherAllyDiscarded = [](Card *self, Card *other, IGame &game) {
        if (other->isSpecial || !isOnBoard(self, ally))
            return;

        if (tick(self, ally, enemy))
            game.playExistedCard(other, self);
    };
    return res;
}


Card *Cards::createCerysAnCraite()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createCerysAnCraite, this);

    res->id = "200177";
    res->power = res->powerBase = 6;
    res->rarity = Gold;
    res->faction = Skellige;
    res->tags = { ClanAnCraite, Officer };

    res->_onDiscard = [](Card *self, IGame &game) {
        setTimer(self, 4);
    };

    res->_onDestroy = [](Card *self, IGame &game, const RowAndPos &) {
        setTimer(self, 4);
    };

    res->_onOtherAllyResurrecteded = [](Card *self, Card *, IGame &game) {
        if (!isIn(self, ally.discard))
            return;

        if (tick(self, ally, enemy))
            moveExistedUnitToPos(self, rowAndPosRandom(ally), self);
    };
    return res;
}


Card *Cards::createWoodlandSpirit()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createWoodlandSpirit, this);

    res->id = "132103";
    res->power = res->powerBase = 5;
    res->rarity = Gold;
    res->faction = Monster;
    res->tags = { Relict };

    res->_onDeploy = [=](Card *self, IGame &game) {
        Row row;
        Pos pos;
        if (!_findRowAndPos(self, ally, row, pos))
            return;
        applyRowEffect(3 + row, ImpenetrableFogEffect);
        for (int n = 0; n < 3; ++n)
            game.spawnNewUnitToPos(createWolf(), rowAndPosLastInExactRow(ally, Meele), self);
    };
    return res;
}


Card *Cards::createTrollololo()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createTrollololo, this);

    res->id = "122209";
    res->power = res->powerBase = 11;
    res->rarity = Silver;
    res->faction = NothernRealms;
    res->tags = { Redania, Ogroid };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.gainArmor(self, 9, self);
    };
    return res;
}


Card *Cards::createPrinceStennis()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createPrinceStennis, this);

    res->id = "122208";
    res->power = res->powerBase = 3;
    res->rarity = Silver;
    res->faction = NothernRealms;
    res->tags = { Aedirn, Officer };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.gainArmor(self, 3, self);
        const std::vector<Card *> cards = cardsFiltered({isNonSpying, isBronzeOrSilver, isUnit}, AllyDeck);
        if (cards.size() == 0)
            return;

        Card *target = cards.front();
        game.playExistedCard(target, self);
        game.gainArmor(target, 5, self);
    };
    return res;
}


Card *Cards::createVincentMeis()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createVincentMeis, this);

    res->id = "200098";
    res->power = res->powerBase = 9;
    res->rarity = Silver;
    res->faction = NothernRealms;
    res->tags = { Beast, Cursed };

    res->_onDeploy = [](Card *self, IGame &game) {
        int _armor = 0;
        for (Card *target: cardsFiltered({hasArmor}, AnyBoard)) {
            const int armorTarget = target->armor;
            game.damage(target, armorTarget, self);
            _armor += armorTarget;
        }
        if (_armor)
            game.boost(self, _armor / 2, self);
    };
    return res;
}


Card *Cards::createMorkvarg()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMorkvarg, this);

    // BUG: isn't carry over...
    // Add a onPutOnDiscard for Morkvarg and golden spell which strikes after 3 turns
    res->id = "152209";
    res->power = res->powerBase = 9;
    res->rarity = Silver;
    res->faction = Skellige;
    res->tags = { Beast, Cursed };

    res->_onDiscard = [](Card *self, IGame &game) {
        if (!weaken(self, half(self->powerBase), self))
            moveExistedUnitToPos(self, rowAndPosRandom(ally), self);
    };

    res->_onDestroy = [](Card *self, IGame &game, const RowAndPos &rowAndPos) {
        if (!weaken(self, half(self->powerBase), self))
            moveExistedUnitToPos(self, rowAndPos, self);
    };
    return res;
}


Card *Cards::createArtefactCompression()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createArtefactCompression, this);

    res->id = "200053";
    res->isSpecial = true;
    res->rarity = Silver;
    res->faction = Neutral;
    res->tags = { Spell };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronzeOrSilver});
    };

    res->_onTargetChoosen = [this](Card *self, Card *target, IGame &game) {
        transform(target, createJadeFigurine(), self);
    };
    return res;
}


Card *Cards::createJadeFigurine()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createJadeFigurine, this);

    res->id = "200053";
    res->isDoomed = true;
    res->power = res->powerBase = 2;
    res->rarity = Bronze;
    res->faction = Neutral;
    res->tags = {};
    return res;
}


Card *Cards::createLordOfUndvik()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createLordOfUndvik, this);

    res->isLoyal = false;
    res->isDoomed = true;
    res->power = res->powerBase = 5;
    res->rarity = Silver;
    res->faction = Skellige;
    res->tags = { Ogroid };

    res->_onDestroy = [](Card *self, IGame &game, const RowAndPos &) {
        // NOTE: 152101 is Hjalmar An Craite
        for (Card *card : cardsFiltered({isCopy("152101")}, EnemyBoard))
            game.boost(card, 10, self);
    };
    return res;
}


Card *Cards::createHjalmarAnCraite()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createHjalmarAnCraite, this);

    res->id = "152101";
    res->power = res->powerBase = 16;
    res->rarity = Gold;
    res->faction = Skellige;
    res->tags = { ClanAnCraite, Officer };

    res->_onDeploy = [=](Card *self, IGame &game) {
        game.spawnNewUnitToPos(createLordOfUndvik(), rowAndPosLastInExactRow(enemy, _findRowAndPos(self, ally).row()), enemy, ally, self);
    };
    return res;
}


Card *Cards::createRegis()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createRegis, this);

    res->id = "112104";
    res->power = res->powerBase = 1;
    res->rarity = Gold;
    res->faction = Neutral;
    res->tags = { Vampire };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBoosted}, AnyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        const int x = target->power - target->powerBase;
        drain(target, x, self);
    };
    return res;
}


Card *Cards::createLethoOfGulet()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createLethoOfGulet, this);

    res->id = "162101";
    res->isLoyal = false;
    res->power = res->powerBase = 1;
    res->rarity = Gold;
    res->faction = Nilfgaard;
    res->tags = { Witcher };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isOnSameRow(&enemy, self)}, EnemyBoard, 2);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        lock(target, self);
        drain(target, target->power, self);
    };
    return res;
}


Card *Cards::createAnCraiteLongship()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAnCraiteLongship, this);

    res->id = "152314";
    res->power = res->powerBase = 7;
    res->rarity = Bronze;
    res->faction = Skellige;
    res->tags = { ClanAnCraite, Machine };

    const auto onDeploy = [=](IGame &game) {
        if (Card *self = random(cardsFiltered({}, EnemyBoard), ally.rng))
            game.damage(self, 2, self);
    };

    res->_onOtherAllyDiscarded = [](Card *self, Card *, IGame &game) {
        if (isOnBoard(self, ally))
            self->onDeploy(ally, enemy);
    };
    return res;
}


Card *Cards::createTuirseachVeteran()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createTuirseachVeteran, this);

    res->id = "200046";
    res->power = res->powerBase = 7;
    res->rarity = Bronze;
    res->faction = Skellige;
    res->tags = { ClanTuirseach, Support };

    res->_onDeploy = [](Card *self, IGame &game) {
        for (Card *card : cardsFiltered({hasTag(ClanTuirseach), otherThan(self)}, AllyBoardHandDeck))
            strengthen(card, 1, self);
    };
    return res;
}


Card *Cards::createTuirseachHunter()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createTuirseachHunter, this);

    res->id = "152304";
    res->power = res->powerBase = 6;
    res->rarity = Bronze;
    res->faction = Skellige;
    res->tags = { ClanTuirseach, Soldier };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.damage(target, 5, self);
    };
    return res;
}


Card *Cards::createUdalryk()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createUdalryk, this);

    res->id = "152214";
    res->power = res->powerBase = 13;
    res->isLoyal = false;
    res->timer = 1;
    res->rarity = Silver;
    res->faction = Skellige;
    res->tags = { ClanBrokvar, Cursed, Agent };

    struct State : StateCopy<State> { std::vector<Card *> _drawn; };
    res->state = new State();

    res->_onDeploy = [](Card *self, IGame &game) {
        if (!tick(self, ally, enemy))
            return;
        const std::vector<Card *> cards = randoms(cardsFiltered({}, AllyDeck), 2, ally.rng);
        self->stateAs<State>()->_drawn = cards;
        game.startChoiceToTargetCard(self, cards);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        putToHand(target,  self);
        for (Card *self : self->stateAs<State>()->_drawn)
            if (self != target)
                putToDiscard(self, self);

        self->stateAs<State>()->_drawn.clear();
    };
    return res;
}


Card *Cards::createBloodcurdlingRoar()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createBloodcurdlingRoar, this);

    res->id = "152406";
    res->isSpecial = true;
    res->rarity = Bronze;
    res->faction = Neutral;
    res->tags = { Organic };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AllyBoard);
    };

    res->_onTargetChoosen = [=](Card *self, Card *target, IGame &game) {
        putToDiscard(target, self);
        game.spawnNewCard(createBear(), self);
    };
    return res;
}


Card *Cards::createGremist()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createGremist, this);

    res->id = "152206";
    res->power = res->powerBase = 4;
    res->rarity = Silver;
    res->faction = Skellige;
    res->tags = { Support };

    res->_onDeploy = [=](Card *self, IGame &game) {
        game.startChoiceToSelectOption(self, {createTorrentialRain(), createClearSkies(), createBloodcurdlingRoar()});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        game.spawnNewCard(target, self);
    };
    return res;
}


Card *Cards::createOperator()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createOperator, this);

    res->id = "112208";
    res->power = res->powerBase = 5;
    res->timer = 1;
    res->rarity = Silver;
    res->faction = Neutral;
    res->tags = { Mage };

    res->_onDeploy = [](Card *self, IGame &game) {
        if (ally.passed || enemy.passed)
            return;
        if (tick(self, ally, enemy))
            game.startChoiceToTargetCard(self, {isBronze, isUnit}, AllyHand);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        Card *copyAlly = target->defaultCopy();
        ally.cardsAdded.push_back(copyAlly);
        putToHand(copyAlly,  self);

        Card *copyEnemy = target->defaultCopy();
        enemy.cardsAdded.push_back(copyEnemy);
        putToHand(copyEnemy, enemy, ally,  self);
    };
    return res;
}


Card *Cards::createZoriaRunestone()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createZoriaRunestone, this);

    res->id = "201582";
    res->isSpecial = true;
    res->rarity = Silver;
    res->faction = NothernRealms;
    res->tags = { Alchemy, Item };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        startChoiceCreateOptions(self, {isBronzeOrSilver, isNothernRealmsFaction});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        game.spawnNewCard(target, self);
    };
    return res;
}


Card *Cards::createRenew()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createRenew, this);

    res->id = "113316";
    res->isSpecial = true;
    res->rarity = Gold;
    res->faction = Neutral;
    res->tags = { Spell };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        startChoiceCreateOptions(self, {isGold, isNonLeader}, AllyDiscard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}


Card *Cards::createEistTuirseach()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createEistTuirseach, this);

    res->id = "201597";
    res->power = res->powerBase = 5;
    res->rarity = Gold;
    res->faction = Skellige;
    res->tags = { ClanTuirseach, Leader };

    res->_onDeploy = [=](Card *self, IGame &game) {
        game.startChoiceToSelectOption(self, {createTuirseachArcher(), createTuirseachAxeman(), createTuirseachBearmaster(), createTuirseachHunter(), createTuirseachSkirmisher()});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        game.spawnNewCard(target, self);
    };
    return res;
}


Card *Cards::createTuirseachAxeman()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createTuirseachAxeman, this);

    res->id = "152312";
    res->power = res->powerBase = 6;
    res->rarity = Bronze;
    res->faction = Skellige;
    res->tags = { ClanTuirseach, Soldier };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.gainArmor(self, 2, self);
    };

    res->_onOtherEnemyDamaged = [](Card *self, Card *other, IGame &game) {
        Pos _;
        Row row;
        if (!_findRowAndPos(other, enemy, row, _))
            return;
        if (isIn(self, ally.row(row)))
            game.boost(self, 1, self);
    };
    return res;
}


Card *Cards::createTuirseachSkirmisher()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createTuirseachSkirmisher, this);

    res->id = "152313";
    res->power = res->powerBase = 8;
    res->rarity = Bronze;
    res->faction = Skellige;
    res->tags = { ClanTuirseach, Soldier };

    res->_onDeployFromDiscard = [](Card *self, IGame &game) {
        strengthen(self, 3, self);
    };
    return res;
}


Card *Cards::createDerran()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDerran, this);

    res->id = "201646";
    res->power = res->powerBase = 6;
    res->rarity = Silver;
    res->faction = Skellige;
    res->tags = { ClanTuirseach, Cursed };

    res->_onOtherEnemyDamaged = [](Card *self, Card *, IGame &game) {
        if (isOnBoard(self, ally))
            game.boost(self, 1, self);
    };
    return res;
}


Card *Cards::createRoach()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createRoach, this);

    res->id = "112210";
    res->power = res->powerBase = 4;
    res->rarity = Silver;
    res->faction = Neutral;
    res->tags = { Beast };

    res->_onOtherAllyPlayedFromHand = [](Card *self, Card *other, IGame &game) {
        if (other->rarity != Gold)
            return;

        if (!isIn(self, ally.deck))
            return;

        moveExistedUnitToPos(self, rowAndPosRandom(ally), self);
    };
    return res;
}


Card *Cards::createJanCalveit()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createJanCalveit, this);

    res->id = "200164";
    res->power = res->powerBase = 5;
    res->rarity = Gold;
    res->faction = Nilfgaard;
    res->tags = { Officer, Leader };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, firsts(ally.deck, 3));
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}


Card *Cards::createCahirDyffryn()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createCahirDyffryn, this);

    res->id = "162104";
    res->power = res->powerBase = 1;
    res->isDoomed = true;
    res->rarity = Gold;
    res->faction = Nilfgaard;
    res->tags = { Officer };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {hasTag(Leader)}, AllyDiscard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}


Card *Cards::createLethoKingslayer()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createLethoKingslayer, this);

    res->id = "201603";
    res->power = res->powerBase = 5;
    res->rarity = Gold;
    res->faction = Nilfgaard;
    res->tags = { Witcher };
    res->state = new StateChoosen();

    enum { Destroy, Play };
    res->_onDeploy = [](Card *self, IGame &game) {
        auto *option1 = createOption(self, Destroy);
        option1->text = "Destroy an enemy Leader, then boost self by 5.";

        auto *option2 = createOption(self, Play);
        option2->text = "Play a Bronze or Silver Tactic from your deck.";

        self->stateAs<StateChoosen>()->_choosen = nullptr;
        game.startChoiceToSelectOption(self, {option1, option2});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        self->stateAs<StateChoosen>()->_choosen = target;

        if (isOption(target, Destroy))
            return game.startChoiceToTargetCard(self, {hasTag(Leader)}, EnemyBoard);

        if (isOption(target, Play))
            return game.startChoiceToTargetCard(self, {isBronzeOrSilver, hasTag(Tactics)}, AllyDeckShuffled);

        throw Error(Error::Unreachable, self);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        Card *choosen = self->stateAs<StateChoosen>()->_choosen;
        if (!choosen)
            throw Error(Error::ChoosenIsNullptr, self);

        if (isOption(choosen, Destroy)) {
            putToDiscard(target, self);
            game.boost(self, 5, self);

            delete choosen;
            choosen = nullptr;
            return;
        }

        if (isOption(choosen, Play)) {
            game.playExistedCard(target, self);

            delete choosen;
            choosen = nullptr;
            return;
        }

        throw Error(Error::Unreachable, self);
    };
    return res;
}


Card *Cards::createKingHenselt()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createKingHenselt, this);

    res->id = "200170";
    res->power = res->powerBase = 3;
    res->rarity = Gold;
    res->isCrew = true;
    res->faction = NothernRealms;
    res->tags = { Kaedwen, Leader };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronze, hasAnyOfTags({Machine, Kaedwen})}, AllyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        for (Card *copy : findCopies(target, ally.deck))
            game.playExistedCard(copy, self);
    };
    return res;
}


Card *Cards::createBloodyBaron()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createBloodyBaron, this);

    res->id = "122101";
    res->power = res->powerBase = 9;
    res->rarity = Gold;
    res->faction = NothernRealms;
    res->tags = { Temeria, Officer };

    res->_onOtherEnemyDestroyed = [](Card *self, Card *, IGame &game) {
        if (isOnBoard(self, ally) || isIn(self, ally.deck) || isIn(self, ally.hand))
            game.boost(self, 1, self);
    };
    return res;
}


Card *Cards::createDethmold()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDethmold, this);

    res->id = "122207";
    res->power = res->powerBase = 4;
    res->rarity = Silver;
    res->faction = NothernRealms;
    res->tags = { Kaedwen, Mage };

    res->_onDeploy = [=](Card *self, IGame &game) {
        game.startChoiceToSelectOption(self, {createTorrentialRain(), createClearSkies(), createAlzursThunder()});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        game.spawnNewCard(target, self);
    };
    return res;
}


Card *Cards::createRonvidTheIncessant()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createRonvidTheIncessant, this);

    res->id = "200529";
    res->power = res->powerBase = 11;
    res->rarity = Silver;
    res->faction = NothernRealms;
    res->tags = { Kaedwen, Soldier };
    res->isCrew = true;

    res->_onTurnEnd = [](Card *self, IGame &game) {
        if (!isIn(self, ally.discard))
            return;
        moveExistedUnitToPos(self, rowAndPosRandom(ally), self);
        if (self->powerBase > 1)
            weaken(self, self->powerBase - 1, self);
    };
    return res;
}


Card *Cards::createHubertRejk()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createHubertRejk, this);

    res->id = "200088";
    res->power = res->powerBase = 7;
    res->rarity = Silver;
    res->faction = NothernRealms;
    res->tags = { Vampire };

    res->_onDeploy = [](Card *self, IGame &game) {
        for (Card *self : cardsFiltered({isBoosted}, AllyDeck))
            drain(self, self->power - self->powerBase, self);
    };
    return res;
}


Card *Cards::createCrachAnCraite()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createCrachAnCraite, this);

    res->id = "200160";
    res->power = res->powerBase = 5;
    res->faction = Skellige;
    res->rarity = Gold;
    res->tags = { ClanAnCraite, Leader };

    res->_onDeploy = [](Card *self, IGame &game) {
        if (Card *self = highest(cardsFiltered({isUnit, isBronzeOrSilver, isNonSpying}, AllyDeck), ally.rng)) {
            strengthen(self, 2, self);
            game.playExistedCard(self, self);
        }
    };
    return res;
}


Card *Cards::createBirnaBran()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createBirnaBran, this);

    res->id = "152105";
    res->power = res->powerBase = 6;
    res->faction = Skellige;
    res->rarity = Gold;
    res->tags = { ClanTuirseach, Officer };

    res->_onDeploy = [](Card *self, IGame &game) {
        startChoiceToSelectRow(self, {3, 4, 5});
    };

    res->_onTargetRowChoosen = [](Card *self, IGame &game, const int screenRow) {
        applyRowEffect(screenRow, SkelligeStormEffect);
    };
    return res;
}


Card *Cards::createCoral()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createCoral, this);

    res->id = "152107";
    res->power = res->powerBase = 5;
    res->faction = Skellige;
    res->rarity = Gold;
    res->tags = { Mage };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronzeOrSilver, isUnit}, AnyBoard);
    };

    res->_onTargetChoosen = [this](Card *self, Card *target, IGame &game) {
        transform(target, createJadeFigurine(), self);
    };
    return res;
}


Card *Cards::createVabjorn()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createVabjorn, this);

    res->id = "200028";
    res->power = res->powerBase = 11;
    res->faction = Skellige;
    res->rarity = Gold;
    res->tags = { Cursed, Cultist };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        if (isDamaged(target))
            putToDiscard(target, self);
        else
            game.damage(target, 2, self);
    };
    return res;
}


Card *Cards::createSpectralWhale()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSpectralWhale, this);

    res->id = "152403";
    res->isDoomed = true;
    res->power = res->powerBase = 3;
    res->faction = Skellige;
    res->rarity = Silver;
    res->tags = { Cursed };

    res->_onTurnEnd = [](Card *self, IGame &game) {
        if (!isOnBoard(self, ally) || !moveToRandomRow(self, self))
            return;
        for (Card *self : cardsFiltered({isOnSameRow(&ally, self)}, AllyBoard))
            game.damage(self, 1, self);
    };
    return res;
}


Card *Cards::createBlueboyLugos()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createBlueboyLugos, this);

    res->id = "152201";
    res->power = res->powerBase = 9;
    res->faction = Skellige;
    res->rarity = Silver;
    res->tags = { ClanDrummond, Soldier };

    res->_onDeploy = [=](Card *self, IGame &game) {
        game.spawnNewCard(createSpectralWhale(), self);
    };
    return res;
}


Card *Cards::createDjengeFrett()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDjengeFrett, this);

    res->id = "152203";
    res->power = res->powerBase = 10;
    res->faction = Skellige;
    res->rarity = Silver;
    res->tags = { Soldier, ClanDimun };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AllyBoard, 2);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.damage(target, 1, self);
        strengthen(self, 2, self);
    };
    return res;
}


Card *Cards::createDonarAnHindar()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDonarAnHindar, this);

    res->id = "152204";
    res->power = res->powerBase = 8;
    res->faction = Skellige;
    res->rarity = Silver;
    res->tags = { ClanHeymaey, Officer };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronze, isUnit}, EnemyDiscard);
        game.startChoiceToTargetCard(self);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        if (!isIn(target, enemy.discard)) {
            toggleLock(target, self);
            return;
        }
        // FIXME: discard moving will crash
        putToDiscard(target, self);
    };
    return res;
}


Card *Cards::createDraigBonDhu()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDraigBonDhu, this);

    res->id = "152205";
    res->power = res->powerBase = 6;
    res->faction = Skellige;
    res->rarity = Silver;
    res->tags = { Support };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isNonLeader, isUnit}, AllyDiscard, 2);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        strengthen(target, 3, self);
    };
    return res;
}


Card *Cards::createHolgerBlackhand()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createHolgerBlackhand, this);

    res->id = "152207";
    res->power = res->powerBase = 6;
    res->faction = Skellige;
    res->rarity = Silver;
    res->tags = { ClanDimun, Officer };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AnyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        if (game.damage(target, 6, self))
            if (Card *card = highest(ally.discard, ally.rng))
                strengthen(card, 3, self);
    };
    return res;
}


Card *Cards::createJuttaAnDimun()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createJuttaAnDimun, this);

    res->id = "152208";
    res->power = res->powerBase = 13;
    res->faction = Skellige;
    res->rarity = Silver;
    res->tags = { ClanDimun, Soldier };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.damage(self, 1, self);
    };
    return res;
}


Card *Cards::createSavageBear()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSavageBear, this);

    res->id = "152210";
    res->power = res->powerBase = 9;
    res->faction = Skellige;
    res->rarity = Bronze;
    res->tags = { Beast, Cursed };

    res->_onOtherEnemyPlayedFromHand = [](Card *self, Card *other, IGame &game) {
        if (isOnBoard(self, ally))
            game.damage(other, 1, self);
    };
    return res;
}


Card *Cards::createSvanrigeTuirseach()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSvanrigeTuirseach, this);

    res->id = "152213";
    res->power = res->powerBase = 9;
    res->faction = Skellige;
    res->rarity = Silver;
    res->tags = { ClanTuirseach, Officer };

    res->_onDeploy = [](Card *self, IGame &game) {
        if (game.drawACard(self))
            game.startChoiceToTargetCard(self, {}, AllyHand);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        putToDiscard(target, self);
    };
    return res;
}


Card *Cards::createSkjall()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSkjall, this);

    res->id = "200212";
    res->power = res->powerBase = 5;
    res->faction = Skellige;
    res->rarity = Silver;
    res->tags = { ClanHeymaey, Cursed };

    res->_onDeploy = [](Card *self, IGame &game) {
        if (Card *card = random(cardsFiltered({isUnit, isBronzeOrSilver, hasTag(Cursed)}, AllyDeck), ally.rng))
            game.playExistedCard(card, self);
    };
    return res;
}


Card *Cards::createHaraldHoundsnout()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createHaraldHoundsnout, this);

    res->id = "200043";
    res->power = res->powerBase = 6;
    res->faction = Skellige;
    res->rarity = Silver;
    res->tags = { ClanTordarroch, Cursed };

    res->_onDeploy = [=](Card *self, IGame &game) {
        game.spawnNewUnitToPos(createWilfred(), rowAndPosToTheLeft(self, ally, 1), self);
        game.spawnNewUnitToPos(createWilhelm(), rowAndPosToTheRight(self, ally, 1), self);
        game.spawnNewUnitToPos(createWilmar(), rowAndPosLastInExactRow(enemy, _findRowAndPos(self, ally).row()), enemy, ally, self);
    };
    return res;
}


Card *Cards::createWilfred()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createWilfred, this);

    res->power = res->powerBase = 1;
    res->faction = Skellige;
    res->rarity = Bronze;
    res->isDoomed = true;

    res->_onDestroy = [](Card *self, IGame &game, const RowAndPos &rowAndPos) {
        for (Card *card : enemy.row(rowAndPos.row()))
            game.damage(card, 1, self);
    };
    return res;
}


Card *Cards::createWilhelm()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createWilhelm, this);

    res->power = res->powerBase = 1;
    res->faction = Skellige;
    res->rarity = Bronze;
    res->isDoomed = true;

    res->_onDestroy = [](Card *self, IGame &game, const RowAndPos &) {
        if (Card *card = random(cardsFiltered({}, AllyBoard), ally.rng))
            strengthen(card, 3, self);
    };
    return res;
}


Card *Cards::createWilmar()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createWilmar, this);

    res->power = res->powerBase = 1;
    res->faction = Skellige;
    res->rarity = Bronze;
    res->isDoomed = true;

    res->_onDestroy = [=](Card *self, IGame &game, const RowAndPos &) {
        game.spawnNewUnitToPos(createBear(), rowAndPosRandom(enemy), self);
    };
    return res;
}


Card *Cards::createYoana()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createYoana, this);

    res->id = "201644";
    res->power = res->powerBase = 6;
    res->faction = Skellige;
    res->rarity = Silver;
    res->tags = { ClanTordarroch, Support };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isUnit, isDamaged}, AllyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        const int x = target->powerBase - target->power;
        heal(target, self);
        game.boost(target, x, self);
    };
    return res;
}


Card *Cards::createAnCraiteBlacksmith()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAnCraiteBlacksmith, this);

    res->id = "152311";
    res->power = res->powerBase = 9;
    res->faction = Skellige;
    res->rarity = Bronze;
    res->tags = { ClanAnCraite, Support };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AllyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        strengthen(target, 2, self);
        game.gainArmor(target, 2, self);
    };
    return res;
}

Card *Cards::createAnCraiteWarcrier()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAnCraiteWarcrier, this);

    res->id = "113313";
    res->power = res->powerBase = 5;
    res->faction = Skellige;
    res->rarity = Bronze;
    res->tags = { ClanAnCraite, Support};

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AllyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.boost(target, int(std::floor(target->power / 2.0)), self);
    };
    return res;
}


Card *Cards::createAnCraiteWarrior()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAnCraiteWarrior, this);

    res->id = "152303";
    res->power = res->powerBase = 12;
    res->faction = Skellige;
    res->rarity = Bronze;
    res->tags = { ClanAnCraite, Soldier };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.damage(self, 1, self);
    };
    return res;
}


Card *Cards::createBerserkerMarauder()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createBerserkerMarauder, this);

    res->id = "152302";
    res->power = res->powerBase = 9;
    res->faction = Skellige;
    res->rarity = Bronze;
    res->tags = { Cursed, Soldier, Cultist };

    res->_onDeploy = [](Card *self, IGame &game) {
        const auto isDamagedOrCursed = [](Card *self) {
            return (self != self) && (isDamaged(self) || hasTag(self, Cursed));
        };
        const int nUnits = int(cardsFiltered({isDamagedOrCursed}, AllyBoard).size());
        if (nUnits)
            game.boost(self, nUnits, self);
    };
    return res;
}


Card *Cards::createDimunPirateCaptain()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDimunPirateCaptain, this);

    res->id = "152306";
    res->power = res->powerBase = 1;
    res->faction = Skellige;
    res->rarity = Bronze;
    res->tags = { ClanDimun, Officer };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronze, otherThan(self->id), hasTag(ClanDimun)}, AllyDeckShuffled);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}


Card *Cards::createDimunSmuggler()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDimunSmuggler, this);

    res->id = "200146";
    res->power = res->powerBase = 10;
    res->faction = Skellige;
    res->rarity = Bronze;
    res->tags = { ClanDimun, Soldier };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronze, isUnit}, AllyDiscard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        putToDeck(target, DeckPosRandom, self);
    };
    return res;
}

Card *Cards::createDrummondShieldmaid()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDrummondShieldmaid, this);

    res->id = "152318";
    res->power = res->powerBase = 3;
    res->faction = Skellige;
    res->rarity = Bronze;
    res->tags = { ClanDrummond, Soldier };

    res->_onDeploy = [](Card *self, IGame &game) {
        for (Card *copy : cardsFiltered({isCopy(self->name)}, AllyDeck))
            moveExistedUnitToPos(copy, _findRowAndPos(self, ally), self);
    };
    return res;
}

Card *Cards::createHeymaeyFlaminica()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createHeymaeyFlaminica, this);

    res->id = "200147";
    res->power = res->powerBase = 10;
    res->faction = Skellige;
    res->rarity = Bronze;
    res->tags = { ClanHeymaey, Support };

    res->_onDeploy = [](Card *self, IGame &game) {
        clearHazardsFromItsRow(self, ally);
        game.startChoiceToTargetCard(self, {isOnAnotherRow(&ally, self)}, AllyBoard, 2);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        moveExistedUnitToPos(target, rowAndPosLastInTheSameRow(self, ally), self);
    };
    return res;
}

Card *Cards::createHeymaeyHerbalist()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createHeymaeyHerbalist, this);

    res->id = "200081";
    res->power = res->powerBase = 3;
    res->faction = Skellige;
    res->rarity = Bronze;
    res->tags = { ClanHeymaey, Support };

    res->_onDeploy = [](Card *self, IGame &game) {
        if (Card *card = random(cardsFiltered({isBronze, hasAnyOfTags({Organic, Hazard})}, AllyDeck), ally.rng))
            game.playExistedCard(card, self);
    };
    return res;
}

Card *Cards::createHeymaeyProtector()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createHeymaeyProtector, this);

    res->id = "200149";
    res->power = res->powerBase = 2;
    res->faction = Skellige;
    res->rarity = Bronze;
    res->tags = { ClanHeymaey, Soldier };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronze, hasTag(Item)}, AllyDeck);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}

Card *Cards::createHeymaeySkald()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createHeymaeySkald, this);

    res->id = "152308";
    res->power = res->powerBase = 9;
    res->faction = Skellige;
    res->rarity = Bronze;
    res->tags = { ClanHeymaey, Support };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {hasAnyOfTags({ClanAnCraite, ClanDimun, ClanDrummond, ClanHeymaey, ClanTuirseach, ClanBrokvar, ClanTordarroch})}, AllyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        for (const Tag tag : std::vector<Tag>{ClanAnCraite, ClanDimun, ClanDrummond, ClanHeymaey, ClanTuirseach, ClanBrokvar, ClanTordarroch}) {
            if (!hasTag(target, tag))
                continue;
            for (Card *card : cardsFiltered({hasTag(tag), otherThan(self)}, AllyBoard))
                game.boost(card, 1, self);
            break;
        }
    };
    return res;
}

Card *Cards::createRagingBerserker()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createRagingBerserker, this);

    res->id = "152301";
    res->power = res->powerBase = 8;
    res->faction = Skellige;
    res->rarity = Bronze;
    res->tags = { Cursed, Soldier, Cultist };

    res->_onDamaged = [this](Card *self, const int, IGame &game, const Card *) {
        transform(self, createRagingBear(), self);
    };

    res->_onWeakened = [](Card *self, const int x, IGame &game, const Card *src) {
        self->onDamaged(x, src);
    };
    return res;
}

Card *Cards::createRagingBear()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createRagingBear, this);

    res->id = "152405";
    res->power = res->powerBase = 12;
    res->faction = Skellige;
    res->rarity = Bronze;
    res->tags = { Cursed, Beast, Cultist };
    return res;
}

Card *Cards::createHym()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createHym, this);

    res->id = "200102";
    res->power = res->powerBase = 3;
    res->faction = Skellige;
    res->rarity = Gold;
    res->tags = { Cursed };
    res->state = new StateChoosen();

    enum { Play, Create };
    res->_onDeploy = [](Card *self, IGame &game) {
        auto *option1 = createOption(self, Play);
        option1->text = "Play a Bronze or Silver Cursed unit from your deck.";

        auto *option2 = createOption(self, Create);
        option2->text = "Create a Silver unit from your opponent's starting deck.";

        self->stateAs<StateChoosen>()->_choosen = nullptr;
        game.startChoiceToSelectOption(self, {option1, option2});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        Card *&choosen = self->stateAs<StateChoosen>()->_choosen;
        if (!choosen && isOption(target, Play)) {
            choosen = target;
            return game.startChoiceToTargetCard(self, {isBronzeOrSilver, hasTag(Cursed)}, AllyDeckShuffled);
        }

        if (!choosen && isOption(target, Create)) {
            choosen = target;
            return startChoiceCreateOptions(self, {isSilver, isUnit, isNonAgent}, EnemyDeckStarting);
        }

        if (isOption(choosen, Create)) {
            game.spawnNewCard(target, self);
            delete choosen;
            choosen = nullptr;
            return;
        }

        throw Error(Error::Unreachable, self);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        Card *&choosen = self->stateAs<StateChoosen>()->_choosen;
        if (!isOption(choosen, Play))
            throw Error(Error::Assert, self);

        game.playExistedCard(target, self);
        delete choosen;
        choosen = nullptr;
    };
    return res;
}


Card *Cards::createHemdall()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createHemdall, this);

    res->id = "152402";
    res->isDoomed = true;
    res->power = res->powerBase = 20;
    res->faction = Skellige;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        for (int screenRow = 0; screenRow < 6; ++screenRow)
            applyRowEffect(screenRow, NoRowEffect);
        for (Card *self : cardsFiltered({}, AnyBoard))
            putToDiscard(self, self);
    };
    return res;
}

Card *Cards::createKambi()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createKambi, this);

    res->id = "152104";
    res->isLoyal = false;
    res->power = res->powerBase = 1;
    res->faction = Skellige;
    res->rarity = Gold;

    res->_onDestroy = [=](Card *self, IGame &game, const RowAndPos &) {
        game.spawnNewUnitToPos(createHemdall(), rowAndPosRandom(ally), self);
        // TODO: Check if Hemdall doesn't wipe a board!
    };
    return res;
}

Card *Cards::createOlaf()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createOlaf, this);

    res->id = "200103";
    res->power = res->powerBase = 20;
    res->faction = Skellige;
    res->rarity = Gold;
    res->tags = { Beast, Cursed };

    res->_onDeploy = [](Card *self, IGame &game) {
        const int n = cardsFiltered({hasTag(Beast)}, AllyAppeared).size();
        const int x = std::max(0, 10 - 2 * n);
        game.damage(self, x, self);
    };
    return res;
}

Card *Cards::createUlfhedinn()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createUlfhedinn, this);

    res->id = "200104";
    res->power = res->powerBase = 6;
    res->faction = Skellige;
    res->rarity = Gold;
    res->tags = { Beast, Cursed };

    res->_onDeploy = [](Card *self, IGame &game) {
        const std::vector<Card *> damaged = cardsFiltered({isDamaged}, EnemyBoard);
        const std::vector<Card *> other   = cardsFiltered({isUndamaged}, EnemyBoard);
        for (Card *card : other)
            game.damage(card, 1, self);
        for (Card *card : damaged)
            game.damage(card, 2, self);
    };
    return res;
}

Card *Cards::createWildBoarOfTheSea()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createWildBoarOfTheSea, this);

    res->id = "152109";
    res->power = res->powerBase = 8;
    res->faction = Skellige;
    res->rarity = Gold;
    res->tags = { ClanAnCraite, Machine };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.gainArmor(self, 5, self);
    };

    res->_onTurnEnd = [](Card *self, IGame &game) {
        if (Card *left = cardNextTo(self, -1)) {
            strengthen(left, 1, self);
            if (Card *right = cardNextTo(self, 1))
                game.damage(right, 1, self);
        }
    };
    return res;
}

Card *Cards::createGiantBoar()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createGiantBoar, this);

    res->id = "201623";
    res->power = res->powerBase = 8;
    res->faction = Skellige;
    res->rarity = Silver;
    res->tags = { Beast };

    res->_onDeploy = [](Card *self, IGame &game) {
        if (Card *card = random(cardsFiltered({otherThan(self)}, AllyBoard), ally.rng)) {
            putToDiscard(card, self);
            game.boost(card, 10, self);
        }
    };
    return res;
}

Card *Cards::createOrnamentalSword()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createOrnamentalSword, this);

    res->id = "201642";
    res->isSpecial = true;
    res->faction = Skellige;
    res->rarity = Silver;
    res->tags = { Item };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        startChoiceCreateOptions(self, {isBronzeOrSilver, isSkelligeFaction, hasTag(Soldier)});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        strengthen(target, 3, self);
        game.spawnNewCard(target, self);
    };
    return res;
}

Card *Cards::createDimunWarship()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDimunWarship, this);

    res->id = "200105";
    res->power = res->powerBase = 7;
    res->faction = Skellige;
    res->rarity = Bronze;
    res->tags = { ClanDimun, Machine };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AnyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        // NOTE: break if kille
        for (int n = 0; n < 4; ++n)
            if (game.damage(target, 1, self))
                break;
    };
    return res;
}

Card *Cards::createTrissButterflies()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createTrissButterflies, this);

    res->id = "122107";
    res->tags = { Mage, Temeria };
    res->power = res->powerBase = 8;
    res->faction = Neutral;
    res->rarity = Gold;

    res->_onTurnEnd = [](Card *self, IGame &game) {
        if (!isOnBoard(self, ally))
            return;
        for (Card *card : lowests(cardsFiltered({}, AllyBoard)))
            game.boost(card, 1, self);
    };
    return res;
}

Card *Cards::createYennefer()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createYennefer, this);

    res->id = "112108";
    res->tags = { Mage, Aedirn };
    res->power = res->powerBase = 6;
    res->faction = Neutral;
    res->rarity = Gold;

    res->_onDeploy = [=](Card *self, IGame &game) {
        game.startChoiceToSelectOption(self, {createUnicorn(), createChironex()});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        game.spawnNewCard(target, self);
    };
    return res;
}

Card *Cards::createChironex()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createChironex, this);

    res->id = "112402";
    res->tags = { Cursed };
    res->isDoomed = true;
    res->power = res->powerBase = 4;
    res->faction = Neutral;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        for (Card *card : cardsFiltered({}, AnyBoard))
            game.damage(card, 2, self);
    };
    return res;
}


Card *Cards::createUnicorn()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createUnicorn, this);

    res->id = "112401";
    res->tags = { Beast };
    res->isDoomed = true;
    res->power = res->powerBase = 1;
    res->faction = Neutral;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        for (Card *card : cardsFiltered({}, AnyBoard))
            game.boost(card, 2, self);
    };
    return res;
}

Card *Cards::createGermainPiquant()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createGermainPiquant, this);

    res->id = "200523";
    res->tags = { Officer };
    res->power = res->powerBase = 10;
    res->faction = Neutral;
    res->rarity = Silver;

    res->_onDeploy = [=](Card *self, IGame &game) {
        game.spawnNewUnitToPos(createCow(), rowAndPosToTheLeft(self, ally, 1), self);
        game.spawnNewUnitToPos(createCow(), rowAndPosToTheLeft(self, ally, 1), self);
        game.spawnNewUnitToPos(createCow(), rowAndPosToTheRight(self, ally, 1), self);
        game.spawnNewUnitToPos(createCow(), rowAndPosToTheRight(self, ally, 1), self);
    };
    return res;
}


Card *Cards::createCommandersHorn()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createCommandersHorn, this);

    res->id = "113207";
    res->tags = { Tactics };
    res->isSpecial = true;
    res->faction = Neutral;
    res->rarity = Silver;

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        const std::vector<Card *> cardsToBoost {
            cardNextTo(target, -2),
                    cardNextTo(target, -1),
                    target,
                    cardNextTo(target, 1),
                    cardNextTo(target, 2),
        };
        for (Card *card : cardsToBoost)
            if (card != nullptr)
                game.boost(card, 3, self);
    };
    return res;
}


Card *Cards::createMarchingOrders()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMarchingOrders, this);

    res->id = "200019";
    res->tags = { Tactics };
    res->isSpecial = true;
    res->faction = Neutral;
    res->rarity = Silver;

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        Card *card = lowest(cardsFiltered({isBronzeOrSilver, isUnit}, AllyDeck), ally.rng);
        if (card != nullptr) {
            game.boost(card, 2, self);
            game.playExistedCard(card, self);
        }
    };
    return res;
}


Card *Cards::createAlzursDoubleCross()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAlzursDoubleCross, this);

    res->id = "113209";
    res->tags = { Spell };
    res->isSpecial = true;
    res->faction = Neutral;
    res->rarity = Silver;

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        Card *card = highest(cardsFiltered({isBronzeOrSilver, isUnit}, AllyDeck), ally.rng);
        if (card != nullptr) {
            game.boost(card, 2, self);
            game.playExistedCard(card, self);
        }
    };
    return res;
}


Card *Cards::createAlbaArmoredCavalry()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAlbaArmoredCavalry, this);

    res->id = "200296";
    res->tags = { Soldier };
    res->power = res->powerBase = 7;
    res->faction = Nilfgaard;
    res->rarity = Bronze;

    // FIXME: missing ability
    return res;
}


Card *Cards::createSentry()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSentry, this);

    res->id = "201661";
    res->tags = { Soldier };
    res->power = res->powerBase = 8;
    res->faction = Nilfgaard;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {hasTag(Soldier), hasCopyOnABoard(&ally)}, AllyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        for (Card *card : cardsFiltered({isCopy(target->name), otherThan(self)}, AllyBoard))
            game.boost(card, 2, self);
    };
    return res;
}


Card *Cards::createNauzicaaSergeant()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createNauzicaaSergeant, this);

    res->id = "162309";
    res->tags = { Officer };
    res->power = res->powerBase = 7;
    res->faction = Nilfgaard;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        clearHazardsFromItsRow(self, ally);
        game.startChoiceToTargetCard(self, {isUnit}, AllyBoardAndHandRevealed);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.boost(target, 3, self);
    };
    return res;
}


Card *Cards::createSlaveInfantry()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSlaveInfantry, this);

    res->id = "201610";
    res->tags = { Soldier };
    res->power = res->powerBase = 3;
    res->faction = Nilfgaard;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        Row row;
        Pos pos;
        if (!_findRowAndPos(self, ally, row, pos))
            return;

        for (int _row = Meele; _row <= Seige; ++_row)
            if (_row != row) {
                Card *copy = self->defaultCopy();
                copy->isDoomed = true;
                summonNewUnitToPos(copy, rowAndPosLastInExactRow(ally, Row(_row)), self);
            }
    };
    return res;
}


Card *Cards::createRecruit()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createRecruit, this);

    res->id = "201617";
    res->tags = { Soldier };
    res->power = res->powerBase = 1;
    res->faction = Nilfgaard;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        if (Card *card = random(cardsFiltered({isBronze, hasTag(Soldier), otherThan(self->name)}, AllyDeckShuffled), ally.rng))
            game.playExistedCard(card, self);
    };
    return res;
}


Card *Cards::createOintment()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createOintment, this);

    res->id = "201619";
    res->tags = { Alchemy, Item };
    res->isSpecial = true;
    res->faction = Nilfgaard;
    res->rarity = Bronze;

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronze, isUnit, hasPowerXorLess(5)}, AllyDiscard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}


Card *Cards::createVilgefortz()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createVilgefortz, this);

    res->id = "162105";
    res->tags = { Mage };
    res->power = res->powerBase = 9;
    res->faction = Nilfgaard;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        const bool isTruce = !ally.passed && !enemy.passed;
        const ChoiceGroup choiceGroup = isTruce ? AnyBoard : AllyBoard;
        game.startChoiceToTargetCard(self, {}, choiceGroup);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        const bool isAlly = isOnBoard(target, ally);
        putToDiscard(target, self);
        if (isAlly) {
            if (Card *copy = first(ally.deck))
                game.playExistedCard(copy, self);
        } else {
            if (Card *card = random(cardsFiltered({isBronze}, EnemyDeck), ally.rng)) {
                putToHand(card, enemy, ally,  self);
                reveal(card, self);
            }
        }
    };
    return res;
}


Card *Cards::createVreemde()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createVreemde, this);

    res->id = "200050";
    res->tags = { Officer };
    res->power = res->powerBase = 4;
    res->faction = Nilfgaard;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        startChoiceCreateOptions(self, {isBronze, isNilfgaardFaction, hasTag(Soldier)});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        game.spawnNewCard(target, self);
    };
    return res;
}


Card *Cards::createCow()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createCow, this);

    res->id = "201576";
    res->tags = { Beast };
    res->isDoomed = true;
    res->power = res->powerBase = 1;
    res->faction = Neutral;
    res->rarity = Bronze;
    return res;
}


Card *Cards::createAuckes()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAuckes, this);

    res->id = "162208";
    res->tags = { Witcher };
    res->power = res->powerBase = 7;
    res->faction = Nilfgaard;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AnyBoard, 2);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        toggleLock(target, self);
    };
    return res;
}


Card *Cards::createEskel()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createEskel, this);

    res->id = "112202";
    res->tags = { Witcher };
    res->power = res->powerBase = 6;
    res->faction = Neutral;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        for (Card *lambert : cardsFiltered({isCopy("112204")}, AllyDeck))
            moveExistedUnitToPos(lambert, rowAndPosToTheLeft(self, ally, 1), self);

        for (Card *vesemir : cardsFiltered({isCopy("112203")}, AllyDeck))
            moveExistedUnitToPos(vesemir, rowAndPosToTheLeft(self, ally, 1), self);
    };
    return res;
}


Card *Cards::createLambert()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createLambert, this);

    res->id = "112204";
    res->tags = { Witcher };
    res->power = res->powerBase = 6;
    res->faction = Neutral;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        for (Card *eskel : cardsFiltered({isCopy("112202")}, AllyDeck))
            moveExistedUnitToPos(eskel, rowAndPosToTheRight(self, ally, 1), self);

        for (Card *vesemir : cardsFiltered({isCopy("112203")}, AllyDeck))
            moveExistedUnitToPos(vesemir, rowAndPosToTheRight(self, ally, 1), self);
    };
    return res;
}


Card *Cards::createVesemir()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createVesemir, this);

    res->id = "112203";
    res->tags = { Witcher };
    res->power = res->powerBase = 7;
    res->faction = Neutral;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        for (Card *lambert : cardsFiltered({isCopy("112204")}, AllyDeck))
            moveExistedUnitToPos(lambert, rowAndPosToTheLeft(self, ally, 1), self);

        for (Card *eskel : cardsFiltered({isCopy("112202")}, AllyDeck))
            moveExistedUnitToPos(eskel, rowAndPosToTheRight(self, ally, 1), self);
    };
    return res;
}


Card *Cards::createTridamInfantry()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createTridamInfantry, this);

    res->id = "200171";
    res->tags = { Soldier };
    res->power = res->powerBase = 10;
    res->faction = NothernRealms;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.gainArmor(self, 4, self);
    };
    return res;
}


Card *Cards::createVriheddDragoon()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createVriheddDragoon, this);

    res->id = "142205";
    res->tags = { Elf, Soldier };
    res->power = res->powerBase = 8;
    res->faction = Scoiatael;
    res->rarity = Bronze;

    res->_onTurnEnd = [](Card *self, IGame &game) {
        if (!isOnBoard(self, ally))
            return;
        if (Card *card = random(cardsFiltered({isUnit, isNonSpying}, AllyHand), ally.rng))
            game.boost(card, 1, self);
    };
    return res;
}


Card *Cards::createMalena()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMalena, this);

    res->id = "142210";
    res->power = res->powerBase = 7;
    res->isAmbush = true;
    res->rarity = Silver;
    res->faction = Scoiatael;
    res->tags = { Elf };

    res->_onDeploy = [](Card *self, IGame &game) {
        self->isAmbush = true;
        setTimer(self, 2);
    };

    res->_onTurnStart = [](Card *self, IGame &game) {
        if (!isOnBoard(self, ally) || !tick(self, ally, enemy))
            return;
        flipOver(self, ally, enemy);
        if (Card *card = highest(cardsFiltered({isBronzeOrSilver, hasPowerXorLess(5)}, EnemyBoard), ally.rng))
            charm(card, self);
    };
    return res;
}


Card *Cards::createUnseenElder()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createUnseenElder, this);

    res->id = "200055";
    res->power = res->powerBase = 5;
    res->rarity = Gold;
    res->faction = Monster;
    res->tags = { Vampire, Leader };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AnyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        drain(target, half(target->power), self);
    };
    return res;
}


Card *Cards::createDevanaRunestone()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDevanaRunestone, this);

    res->id = "201584";
    res->isSpecial = true;
    res->rarity = Silver;
    res->faction = Monster;
    res->tags = { Alchemy, Item };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        startChoiceCreateOptions(self, {isBronzeOrSilver, isMonsterFaction});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        game.spawnNewCard(target, self);
    };
    return res;
}


Card *Cards::createDazhbogRunestone()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDazhbogRunestone, this);

    res->id = "201583";
    res->isSpecial = true;
    res->rarity = Silver;
    res->faction = Nilfgaard;
    res->tags = { Alchemy, Item };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        startChoiceCreateOptions(self, {isBronzeOrSilver, isNilfgaardFaction});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        game.spawnNewCard(target, self);
    };
    return res;
}


Card *Cards::createMoranaRunestone()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMoranaRunestone, this);

    res->id = "201585";
    res->isSpecial = true;
    res->rarity = Silver;
    res->faction = Scoiatael;
    res->tags = { Alchemy, Item };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        startChoiceCreateOptions(self, {isBronzeOrSilver, isScoiataelFaction});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        game.spawnNewCard(target, self);
    };
    return res;
}


Card *Cards::createStribogRunestone()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createStribogRunestone, this);

    res->id = "201581";
    res->isSpecial = true;
    res->rarity = Silver;
    res->faction = Skellige;
    res->tags = { Alchemy, Item };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        startChoiceCreateOptions(self, {isBronzeOrSilver, isSkelligeFaction});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        game.spawnNewCard(target, self);
    };
    return res;
}


Card *Cards::createMuzzle()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMuzzle, this);

    res->id = "200225";
    res->isSpecial = true;
    res->rarity = Gold;
    res->faction = Neutral;
    res->tags = { Item };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronzeOrSilver, hasPowerXorLess(8)}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        charm(target, self);
    };
    return res;
}


Card *Cards::createRockBarrage()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createRockBarrage, this);

    res->id = "201647";
    res->isSpecial = true;
    res->rarity = Bronze;
    res->faction = Neutral;
    res->tags = {};

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        const RowAndPos rowAndPos = _findRowAndPos(target, enemy);
        const Row rowAbove = std::min(Row(rowAndPos.row() + 1), Seige);

        const bool shouldDestroy = isRowFull(enemy.row(rowAbove));
        if (shouldDestroy) {
            putToDiscard(target, self);
            return;
        }

        if (!game.damage(target, 7, self) && (rowAndPos.row() != Seige))
            moveExistedUnitToPos(target, rowAndPosLastInExactRow(enemy, rowAbove), enemy, ally, self);
    };
    return res;
}


Card *Cards::createWhisperingHillock()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createWhisperingHillock, this);

    res->id = "201587";
    res->power = res->powerBase = 6;
    res->rarity = Gold;
    res->faction = Monster;
    res->tags = { Leader, Relict };

    res->_onDeploy = [](Card *self, IGame &game) {
        startChoiceCreateOptions(self, {isBronzeOrSilver, hasTag(Organic)});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        game.spawnNewCard(target, self);
    };
    return res;
}

Card *Cards::createBrewess()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createBrewess, this);

    res->id = "132207";
    res->tags = { Mage, Relict };
    res->power = res->powerBase = 8;
    res->faction = Monster;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        for (Card *weavess: cardsFiltered({isCopy("132208")}, AllyDeck))
            moveExistedUnitToPos(weavess, rowAndPosToTheRight(self, ally, 1), self);

        for (Card *whispess : cardsFiltered({isCopy("132206")}, AllyDeck))
            moveExistedUnitToPos(whispess, rowAndPosToTheLeft(self, ally, 1), self);
    };
    return res;
}

Card *Cards::createWeavess()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createWeavess, this);

    res->id = "132208";
    res->tags = { Mage, Relict };
    res->power = res->powerBase = 6;
    res->faction = Monster;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        for (Card *whispess : cardsFiltered({isCopy("132206")}, AllyDeck))
            moveExistedUnitToPos(whispess, rowAndPosToTheLeft(self, ally, 1), self);

        for (Card *brewess: cardsFiltered({isCopy("132207")}, AllyDeck))
            moveExistedUnitToPos(brewess, rowAndPosToTheLeft(self, ally, 1), self);
    };
    return res;
}


Card *Cards::createWhispess()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createWhispess, this);

    res->id = "132206";
    res->tags = { Mage, Relict };
    res->power = res->powerBase = 6;
    res->faction = Monster;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        for (Card *weavess: cardsFiltered({isCopy("132208")}, AllyDeck))
            moveExistedUnitToPos(weavess, rowAndPosToTheRight(self, ally, 1), self);

        for (Card *brewess: cardsFiltered({isCopy("132207")}, AllyDeck))
            moveExistedUnitToPos(brewess, rowAndPosToTheRight(self, ally, 1), self);
    };
    return res;
}


Card *Cards::createWeavessIncantation()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createWeavessIncantation, this);

    res->id = "200222";
    res->tags = { Mage, Relict };
    res->power = res->powerBase = 4;
    res->faction = Monster;
    res->rarity = Gold;

    enum { Strengthen, Play };
    res->_onDeploy = [](Card *self, IGame &game) {
        auto *option1 = createOption(self, Strengthen);
        option1->text = "Strengthen all your other Relicts in hand, deck, and on board by 2.";

        auto *option2 = createOption(self, Play);
        option2->text = "Play a Bronze or Silver Relict from your deck and Strengthen it by 2.";

        game.startChoiceToSelectOption(self, {option1, option2});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        if (isOption(target, Strengthen)) {
            for (Card *self : cardsFiltered({hasTag(Relict), otherThan(self)}, AllyBoardHandDeck))
                strengthen(self, 2, self);
            return;
        }

        if (isOption(target, Play)) {
            game.startChoiceToTargetCard(self, {isBronzeOrSilver, hasTag(Relict)}, AllyDeckShuffled);
            return;
        }

        throw Error(Error::Unreachable, self);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        strengthen(target, 2, self);
        game.playExistedCard(target, self);
    };
    return res;
}

Card *Cards::createBrewessRitual()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createBrewessRitual, this);

    res->id = "200221";
    res->tags = { Mage, Relict };
    res->power = res->powerBase = 1;
    res->faction = Monster;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isDeathwish, isBronze, isUnit}, AllyDiscard, 2);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}

Card *Cards::createWhispessTribute()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createWhispessTribute, this);

    res->id = "200220";
    res->tags = { Mage, Relict };
    res->power = res->powerBase = 6;
    res->faction = Monster;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronzeOrSilver, hasTag(Organic)}, AllyDeckShuffled);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}


Card *Cards::createNivellen()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createNivellen, this);

    res->id = "200089";
    res->power = res->powerBase = 10;
    res->rarity = Silver;
    res->faction = Neutral;
    res->tags = { Cursed };

    res->_onDeploy = [](Card *self, IGame &game) {
        startChoiceToSelectRow(self);
    };

    res->_onTargetRowChoosen = [](Card *self, IGame &game, const int screenRow) {
        for (Card *card : cardsInRow(screenRow)) {
            if (isOnBoard(card, ally)) {
                moveToRandomRow(card, self);
            } else {
                moveToRandomRow(card, enemy, ally, self);
            }
        }
    };
    return res;
}


Card *Cards::createLeoBonhart()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createLeoBonhart, this);

    res->id = "200031";
    res->power = res->powerBase = 7;
    res->rarity = Gold;
    res->faction = Nilfgaard;
    res->tags = { Soldier };

    struct State : StateCopy<State> { Card *_revealed = nullptr; };
    res->state = new State();

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isNonRevealed, isUnit}, AllyHand);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        Card *&revealed = self->stateAs<State>()->_revealed;
        if (revealed == nullptr) {
            revealed = target;
            reveal(target, self);
            game.startChoiceToTargetCard(self, {}, EnemyBoard);
            return;
        }
        game.damage(target, revealed->powerBase, self);
    };
    return res;
}



Card *Cards::createMorvranVoorhis()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMorvranVoorhis, this);

    res->id = "200163";
    res->power = res->powerBase = 7;
    res->rarity = Gold;
    res->faction = Nilfgaard;
    res->tags = { Officer, Leader };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isNonRevealed}, AnyHandShuffled, 4, true);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        reveal(target, self);
    };
    return res;
}


Card *Cards::createCynthia()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createCynthia, this);

    res->id = "162203";
    res->power = res->powerBase = 5;
    res->rarity = Silver;
    res->faction = Nilfgaard;
    res->tags = { Mage };

    res->_onDeploy = [](Card *self, IGame &game) {
        if (Card *card = highest(cardsFiltered({isUnit, isNonRevealed}, EnemyHand), ally.rng)) {
            reveal(card, self);
            game.boost(self, card->power, self);
        }
    };
    return res;
}


Card *Cards::createSerrit()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSerrit, this);

    res->id = "162209";
    res->power = res->powerBase = 6;
    res->rarity = Silver;
    res->faction = Nilfgaard;
    res->tags = { Witcher };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isUnit}, EnemyBoardAndHandRevealed);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        const int x = isOnBoard(target, enemy) ? 7 : (target->power - 1);
        game.damage(target, x, self);
    };
    return res;
}


Card *Cards::createSweers()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSweers, this);

    res->id = "162206";
    res->power = res->powerBase = 9;
    res->rarity = Silver;
    res->faction = Nilfgaard;
    res->tags = { Officer };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isUnit, hasCopyInADeck(&enemy)}, EnemyBoardAndHandRevealed);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        for (Card *copy : findCopies(target, enemy.deck))
            putToDiscard(copy, self);
    };
    return res;
}


Card *Cards::createTiborEggebracht()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createTiborEggebracht, this);

    res->id = "162107";
    res->power = res->powerBase = 10;
    res->rarity = Gold;
    res->faction = Nilfgaard;
    res->tags = { Officer };

    res->_onDeploy = [](Card *self, IGame &game) {
        if (ally.passed || enemy.passed)
            return;
        if (Card *card = random(cardsFiltered({isBronze}, EnemyDeck), ally.rng)) {
            putToHand(card, enemy, ally,  self);
            reveal(card, self);
        }
    };
    return res;
}

Card *Cards::createVattierDeRideaux()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createVattierDeRideaux, this);

    res->id = "162103";
    res->power = res->powerBase = 10;
    res->rarity = Gold;
    res->faction = Nilfgaard;
    res->tags = { Officer };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isNonRevealed}, AllyHand, 2, true);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        reveal(target, self);
        if (Card *card = random(cardsFiltered({isNonRevealed}, EnemyHand), ally.rng))
            reveal(card, self);
    };
    return res;
}

Card *Cards::createAlbrich()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAlbrich, this);

    res->id = "162201";
    res->power = res->powerBase = 10;
    res->rarity = Silver;
    res->faction = Nilfgaard;
    res->tags = { Mage };

    res->_onDeploy = [](Card *self, IGame &game) {
        if (ally.passed || enemy.passed)
            return;
        game.drawACard(self);
        if (Card *card = first(enemy.deck)) {
            putToHand(card,  self);
            reveal(card, self);
        }
    };
    return res;
}

Card *Cards::createHeftyHelge()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createHeftyHelge, this);

    res->id = "200041";
    res->power = res->powerBase = 8;
    res->rarity = Silver;
    res->faction = Nilfgaard;
    res->tags = { Machine };

    res->_onDeploy = [](Card *self, IGame &game) {
        const Filters filters = isRevealed ? Filters{} : Filters{isOnAnotherRow(&ally, &enemy, self)};
        for (Card *card : cardsFiltered(filters, EnemyBoard))
            game.damage(card, 1, self);
    };
    return res;
}

Card *Cards::createAlchemist()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAlchemist, this);

    res->id = "162316";
    res->power = res->powerBase = 9;
    res->rarity = Bronze;
    res->faction = Nilfgaard;
    res->tags = { Mage };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isNonRevealed}, AnyHandShuffled, 2, true);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        reveal(target, self);
    };
    return res;
}

Card *Cards::createDaerlanSoldier()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDaerlanSoldier, this);

    res->id = "162301";
    res->power = res->powerBase = 4;
    res->rarity = Bronze;
    res->faction = Nilfgaard;
    res->tags = { Soldier };

    res->_onRevealed = [](Card *self, IGame &game, const Card *src) {
        /// reveal is possible only by units on a board
        /// check if revealed by an you
        if (!isOnBoard(src, ally))
            return;
        /// don't jump and draw a self, if no place on a field
        if (moveExistedUnitToPos(self, rowAndPosRandom(ally), self))
            game.drawACard(self);
    };
    return res;
}

Card *Cards::createFireScorpion()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createFireScorpion, this);

    res->id = "162306";
    res->power = res->powerBase = 5;
    res->rarity = Bronze;
    res->faction = Nilfgaard;
    res->tags = { Machine };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.damage(target, 5, self);
    };
    res->_onRevealed = [](Card *self, IGame &game, const Card *src) {
        if (isOnBoard(src, ally))
            self->onDeploy(ally, enemy);
    };
    return res;
}

Card *Cards::createWildHuntHound()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createWildHuntHound, this);

    res->id = "132402";
    res->power = res->powerBase = 4;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { WildHunt, Construct };

    res->_onDeploy = [](Card *self, IGame &game) {
        if (Card *card = random(cardsFiltered({isCopy("Biting Frost")}, AllyDeck), ally.rng))
            game.playExistedCard(card, self);
    };
    return res;
}

Card *Cards::createWildHuntWarrior()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createWildHuntWarrior, this);

    res->id = "132309";
    res->power = res->powerBase = 7;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { WildHunt, Soldier };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        const bool isUnderFrost = rowEffectUnderUnit(target, enemy) == BitingFrostEffect;
        if (game.damage(target, 3, self) || isUnderFrost)
            game.boost(self, 2, self);
    };
    return res;
}


Card *Cards::createMangonel()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMangonel, this);

    res->id = "162317";
    res->power = res->powerBase = 7;
    res->rarity = Bronze;
    res->faction = Nilfgaard;
    res->tags = { Machine };

    res->_onDeploy = [](Card *self, IGame &game) {
        if (Card *card = random(cardsFiltered({}, EnemyBoard), ally.rng))
            game.damage(card, 2, self);
    };

    res->_onOtherRevealed = [](Card *self, IGame &game, Card *, const Card *) {
        if (isOnBoard(self, ally))
            self->onDeploy(ally, enemy);
    };
    return res;
}

Card *Cards::createNilfgaardianKnight()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createNilfgaardianKnight, this);

    res->id = "162318";
    res->power = res->powerBase = 12;
    res->rarity = Bronze;
    res->faction = Nilfgaard;
    res->tags = { Soldier };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.gainArmor(self, 2, self);

        for (const Filter &filter : Filters{isBronze, isSilver, isGold}) {
            if (Card *card = random(cardsFiltered({filter, isNonRevealed}, AllyHand), ally.rng)) {
                reveal(card, self);
                break;
            }
        }
    };
    return res;
}

Card *Cards::createSpotter()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSpotter, this);

    res->id = "162303";
    res->power = res->powerBase = 5;
    res->rarity = Bronze;
    res->faction = Nilfgaard;
    res->tags = { Soldier };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isUnit, isBronzeOrSilver, ::isRevealed}, AnyHandShuffled);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.boost(self, target->powerBase, self);
    };
    return res;
}

Card *Cards::createVenendalElite()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createVenendalElite, this);

    res->id = "200518";
    res->power = res->powerBase = 1;
    res->rarity = Bronze;
    res->faction = Nilfgaard;
    res->tags = { Soldier };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isUnit, ::isRevealed}, AnyHandShuffled);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        const int powerTarget = target->power;
        // TODO: check if triggered onDamaged and onDamaged of other units,
        // because it shouldn't
        setPower(target, self->power, self);
        setPower(self, powerTarget, self);
    };
    return res;
}


Card *Cards::createMasterOfDisguise()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMasterOfDisguise, this);

    res->id = "201616";
    res->power = res->powerBase = 11;
    res->rarity = Bronze;
    res->faction = Nilfgaard;
    res->tags = { Soldier };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {::isRevealed}, AnyHandShuffled, 2);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        conceal(target, self);
    };
    return res;
}


Card *Cards::createHenryVarAttre()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createHenryVarAttre, this);

    res->id = "200227";
    res->power = res->powerBase = 9;
    res->rarity = Silver;
    res->faction = Nilfgaard;
    res->tags = { Support };

    res->_onDeploy = [](Card *self, IGame &game) {
        const Filters filters {::isRevealed, isUnit};
        const int nRevealed = int(cardsFiltered(filters, AnyHandShuffled).size());
        if (nRevealed)
            game.startChoiceToTargetCard(self, filters, AnyHandShuffled, nRevealed);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        if (isIn(target, ally.hand)) {
            game.boost(target, 2, self);
            conceal(target, self);
            return;
        }
        game.damage(target, 2, self);
        conceal(target, self);
    };
    return res;
}


Card *Cards::createSummoningCircle()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSummoningCircle, this);

    res->id = "200022";
    res->isSpecial = true;
    res->rarity = Silver;
    res->faction = Neutral;
    res->tags = { Spell };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        if (Card *card = last(cardsFiltered({isUnit, isBronzeOrSilver, isNonAgent, otherThan(self)}, BothAppeared)))
            game.spawnNewCard(card->defaultCopy(), self);
    };
    return res;
}


Card *Cards::createXavierMoran()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createXavierMoran, this);

    res->id = "200080";
    res->power = res->powerBase = 10;
    res->rarity = Gold;
    res->faction = Scoiatael;
    res->tags = { Dwarf };

    res->_onDeploy = [](Card *self, IGame &game) {
        if (Card *card = last(cardsFiltered({hasTag(Dwarf), otherThan(self)}, AllyAppeared)))
            game.boost(self, card->powerBase, self);
    };
    return res;
}

Card *Cards::createYenneferEnchantress()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createYenneferEnchantress, this);

    res->id = "201601";
    res->tags = { Mage, Aedirn };
    res->power = res->powerBase = 5;
    res->faction = Nilfgaard;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        if (Card *card = last(cardsFiltered({hasTag(Spell), isBronzeOrSilver}, AllyAppeared)))
            game.spawnNewCard(card->defaultCopy(), self);
    };
    return res;
}

Card *Cards::createVernonRoche()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createVernonRoche, this);

    res->id = "122102";
    res->tags = { Temeria, Officer };
    res->power = res->powerBase = 3;
    res->faction = NothernRealms;
    res->rarity = Gold;

    res->_onGameStart = [=](Card *self, IGame &game) {
        Card *card = createBlueStripeCommando();
        addAsNew(ally, card);
        putToDeck(card, DeckPosRandom, self);
    };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.damage(target, 7, self);
    };
    return res;
}

Card *Cards::createBlueStripeScout()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createBlueStripeScout, this);

    res->id = "122310";
    res->tags = { Temeria, Soldier };
    res->power = res->powerBase = 3;
    res->isCrew = true;
    res->faction = NothernRealms;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        for (Card *self : cardsFiltered({hasTag(Temeria), isNonSpying, hasPowerX(self->power)}, AllyBoardHandDeck))
            game.boost(self, 1, self);
    };
    return res;
}

Card *Cards::createBlueStripeCommando()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createBlueStripeCommando, this);

    res->id = "122311";
    res->tags = { Temeria, Soldier };
    res->power = res->powerBase = 3;
    res->faction = NothernRealms;
    res->rarity = Bronze;

    struct State : StateCopy<State> { std::map<Card *, Card *> _allyPlayedToCopy; };
    res->state = new State();

    res->_onOtherAllyPlayedFromHand = [](Card *self, Card *target, IGame &game) {
        std::map<Card *, Card *> &allyPlayedToCopy = self->stateAs<State>()->_allyPlayedToCopy;
        if (!hasTag(Temeria) || !hasPowerX(self->power) || !isIn(self, ally.deck))
            return;

        for (Card *copy : cardsFiltered({isCopy(self->id), otherThan(self)}, AllyDeckShuffled))
            copy->stateAs<State>()->_allyPlayedToCopy.insert({target, self});

        if (allyPlayedToCopy.find(target) == allyPlayedToCopy.end())
            moveExistedUnitToPos(self, rowAndPosRandom(ally), self);

        allyPlayedToCopy.clear();
    };
    return res;
}

Card *Cards::createImperialGolem()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createImperialGolem, this);

    res->id = "132407";
    res->tags = { Construct };
    res->power = res->powerBase = 3;
    res->faction = Nilfgaard;
    res->rarity = Bronze;

    struct State : StateCopy<State> { std::map<Card *, Card *> _cardRevealedToCopy; };
    res->state = new State();

    res->_onOtherRevealed = [](Card *self, IGame &game, Card *target, const Card *) {
        std::map<Card *, Card *> &cardRevealedToCopy = self->stateAs<State>()->_cardRevealedToCopy;
        if (!isIn(self, ally.deck) || !isIn(target, enemy.hand))
            return;

        for (Card *copy : cardsFiltered({isCopy(self->id), otherThan(self)}, AllyDeckShuffled))
            copy->stateAs<State>()->_cardRevealedToCopy.insert({target, self});

        if (cardRevealedToCopy.find(target) == cardRevealedToCopy.end())
            moveExistedUnitToPos(self, rowAndPosRandom(ally), self);

        cardRevealedToCopy.clear();
    };
    return res;
}

Card *Cards::createWildHuntNavigator()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createWildHuntNavigator, this);

    res->id = "200026";
    res->power = res->powerBase = 3;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { WildHunt, Mage };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronze, hasTag(WildHunt), hasNoTag(Mage), hasCopyInADeck(&ally)}, AllyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        if (Card *copy = findCopy(target, ally.deck))
            game.playExistedCard(copy, self);
    };
    return res;
}

Card *Cards::createNithral()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createNithral, this);

    res->id = "132214";
    res->power = res->powerBase = 6;
    res->rarity = Silver;
    res->faction = Monster;
    res->tags = { WildHunt, Officer };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        const int nWildHuntUnits = cardsFiltered({hasTag(WildHunt), isUnit}, AllyHand).size();
        game.damage(target, 6 + nWildHuntUnits, self);
    };
    return res;
}

Card *Cards::createMiruna()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMiruna, this);

    res->id = "132108";
    res->power = res->powerBase = 4;
    res->rarity = Gold;
    res->faction = Monster;
    res->tags = { Beast };

    res->_onDeploy = [](Card *self, IGame &game) {
        setTimer(self, 2);
    };

    res->_onTurnStart = [](Card *self, IGame &game) {
        if (!isOnBoard(self, ally) || !tick(self, ally, enemy))
            return;
        if (Card *card = highest(cardsFiltered({isOnOppositeRow(&ally, &enemy, self)}, EnemyBoard), ally.rng))
            charm(card, self);
    };
    return res;
}

Card *Cards::createImlerith()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createImlerith, this);

    res->id = "132102";
    res->power = res->powerBase = 9;
    res->rarity = Gold;
    res->faction = Monster;
    res->tags = { WildHunt, Officer };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        const bool isUnderFrost = rowEffectUnderUnit(target, enemy) == BitingFrostEffect;
        game.damage(target, isUnderFrost ? 8 : 4, self);
    };
    return res;
}

Card *Cards::createCaretaker()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createCaretaker, this);

    res->id = "132106";
    res->power = res->powerBase = 4;
    res->rarity = Gold;
    res->faction = Monster;
    res->isDoomed = true;
    res->tags = { Relict };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isUnit, isBronzeOrSilver}, EnemyDiscard);
    };
    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}

Card *Cards::createRuehin()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createRuehin, this);

    res->id = "201660";
    res->power = res->powerBase = 8;
    res->rarity = Silver;
    res->faction = Monster;
    res->tags = { Insectoid, Cursed };

    res->_onDeploy = [](Card *self, IGame &game) {
        for (Card *card : cardsFiltered({hasAnyOfTags({Insectoid, Cursed}), otherThan(self), isUnit}, AllyBoardHandDeck))
            strengthen(card, 1, self);
    };
    return res;
}

Card *Cards::createOldSpeartipAsleep()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createOldSpeartipAsleep, this);

    res->id = "132218";
    res->power = res->powerBase = 12;
    res->rarity = Gold;
    res->faction = Monster;
    res->tags = { Ogroid };

    res->_onDeploy = [](Card *self, IGame &game) {
        for (Card *card : cardsFiltered({hasTag(Ogroid), otherThan(self), isUnit}, AllyBoardHandDeck))
            strengthen(card, 1, self);
    };
    return res;
}

Card *Cards::createOldSpeartip()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createOldSpeartip, this);

    res->id = "132408";
    res->power = res->powerBase = 10;
    res->rarity = Gold;
    res->faction = Monster;
    res->tags = { Ogroid };

    res->_onDeploy = [](Card *self, IGame &game) {
        for(Card *card : randoms(cardsFiltered({isOnOppositeRow(&ally, &enemy, self)}, EnemyBoard), 5, ally.rng))
            game.damage(card, 2, self);
    };
    return res;
}

Card *Cards::createGolyat()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createGolyat, this);

    res->id = "200052";
    res->power = res->powerBase = 10;
    res->rarity = Silver;
    res->faction = Monster;
    res->tags = { Ogroid };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.boost(self, 7, self);
    };

    res->_onDamaged = [](Card *self, const int, IGame &game, const Card *src) {
        if (src != self)
            game.damage(self, 2, self);
    };
    return res;
}

Card *Cards::createBarbegazi()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createBarbegazi, this);

    res->id = "201701";
    res->power = res->powerBase = 6;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Insectoid };

    res->_onDeploy = [](Card *self, IGame &game) {
        self->isResilient = true;
        game.startChoiceToTargetCard(self, {}, AllyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.boost(self, consume(target, self), self);
    };
    return res;
}

Card *Cards::createGhoul()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createGhoul, this);

    res->id = "132306";
    res->power = res->powerBase = 4;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Necrophage };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronzeOrSilver, isUnit}, AllyDiscard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.boost(self, consume(target, self), self);
    };
    return res;
}

Card *Cards::createForktail()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createForktail, this);

    res->id = "201606";
    res->power = res->powerBase = 8;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Draconid };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AllyBoard, 2);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.boost(self, consume(target, self), self);
    };
    return res;
}

Card *Cards::createArachasQueen()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createArachasQueen, this);

    res->id = "201743";
    res->power = res->powerBase = 7;
    res->rarity = Gold;
    res->faction = Monster;
    res->tags = { Leader, Insectoid };

    res->_onDeploy = [](Card *self, IGame &game) {
        self->isImmune = true;
        game.startChoiceToTargetCard(self, {}, AllyBoard, 3);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.boost(self, consume(target, self), self);
    };
    return res;
}

Card *Cards::createOzzrel()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createOzzrel, this);

    res->id = "201698";
    res->power = res->powerBase = 5;
    res->rarity = Silver;
    res->faction = Monster;
    res->tags = { Necrophage };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronzeOrSilver, isUnit}, BothDiscard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.boost(self, consume(target, self), self);
    };
    return res;
}

Card *Cards::createKayran()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createKayran, this);

    res->id = "132107";
    res->power = res->powerBase = 5;
    res->rarity = Gold;
    res->faction = Monster;
    res->tags = { Insectoid };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {hasPowerXorLess(7)}, AnyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.boost(self, consume(target, self), self);
    };
    return res;
}

Card *Cards::createMourntart()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMourntart, this);

    res->id = "132202";
    res->power = res->powerBase = 4;
    res->rarity = Silver;
    res->faction = Monster;
    res->tags = { Necrophage };

    res->_onDeploy = [](Card *self, IGame &game) {
        const std::vector<Card *> cards = cardsFiltered({isBronzeOrSilver, isUnit}, AllyDiscard);

        for (Card *card : cards)
            consume(card, self);

        game.boost(self, cards.size(), self);
    };
    return res;
}

Card *Cards::createToadPrince()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createToadPrince, this);

    res->id = "132216";
    res->power = res->powerBase = 6;
    res->rarity = Silver;
    res->faction = Monster;
    res->tags = { Cursed };

    res->_onDeploy = [](Card *self, IGame &game) {
        if (Card *unit = first(cardsFiltered({isUnit}, AllyDeck))) {
            putToHand(unit,  self);
            game.startChoiceToTargetCard(self, {isUnit}, AllyHand);
        }
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.boost(self, consume(target, self), self);
    };
    return res;
}

Card *Cards::createFiend()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createFiend, this);

    res->id = "112405";
    res->power = res->powerBase = 11;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Relict };
    return res;
}

Card *Cards::createMorvudd()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMorvudd, this);

    res->id = "112405";
    res->power = res->powerBase = 6;
    res->rarity = Silver;
    res->faction = Monster;
    res->tags = { Relict };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AnyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        toggleLock(target, self);
        if (isOnBoard(target, enemy))
            setPower(target, target->power - half(target->power), self);
    };
    return res;
}

Card *Cards::createEkimmara()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createEkimmara, this);

    res->id = "132313";
    res->power = res->powerBase = 5;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Vampire };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AnyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        drain(target, 3, self);
    };
    return res;
}

Card *Cards::createRotfiend()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createRotfiend, this);

    res->id = "200295";
    res->power = res->powerBase = 8;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Necrophage };

    res->_onDestroy = [](Card *self, IGame &game, const RowAndPos &) {
        for(Card *target : cardsFiltered({isOnOppositeRow(&ally, &enemy, self)}, EnemyBoard))
            game.damage(target, 2, self);
    };
    return res;
}

Card *Cards::createArchespore()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createArchespore, this);

    res->id = "200038";
    res->power = res->powerBase = 7;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Cursed };

    res->_onDestroy = [](Card *self, IGame &game, const RowAndPos &) {
        game.damage(random(cardsFiltered({}, EnemyBoard), ally.rng), 4, self);
    };

    res->_onTurnStart = [](Card *self, IGame &game) {
        if (isOnBoard(self, ally) && moveToRandomRow(self, self))
            game.damage(random(cardsFiltered({}, EnemyBoard), ally.rng), 1, self);
    };
    return res;
}

Card *Cards::createCyclops()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createCyclops, this);

    res->id = "200037";
    res->power = res->powerBase = 11;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Ogroid };

    struct State : StateCopy<State> { int _powerOfDestroyed = 0; };
    res->state = new State();

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AllyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        int &powerOfDestroyed = self->stateAs<State>()->_powerOfDestroyed;
        if(!powerOfDestroyed) {
            powerOfDestroyed = target->power;
            putToDiscard(target, self);
            game.startChoiceToTargetCard(self, {}, EnemyBoard);
            return;
        }
        game.damage(target, powerOfDestroyed, self);
        powerOfDestroyed = 0;
    };
    return res;
}

Card *Cards::createMaerolorn()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMaerolorn, this);

    res->id = "132406";
    res->power = res->powerBase = 4;
    res->rarity = Silver;
    res->faction = Monster;
    res->tags = { Relict };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronze, isDeathwish}, AllyDeckShuffled);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}

Card *Cards::createMonsterNest()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMonsterNest, this);

    res->id = "133302";
    res->isSpecial = true;
    res->rarity = Silver;
    res->faction = Monster;
    res->tags = { Organic };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        startChoiceCreateOptions(self, {isBronze, hasAnyOfTags({Necrophage, Insectoid})}, AnyCard, -1);
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        game.boost(target, 1, self);
        game.spawnNewCard(target, self);
    };
    return res;
}

Card *Cards::createArachasDrone()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createArachasDrone, this);

    res->id = "132304";
    res->power = res->powerBase = 3;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Insectoid };

    res->_onDeploy = [](Card *self, IGame &game) {
        for (Card *copy : cardsFiltered({isCopy(self->name)}, AllyDeck))
            moveExistedUnitToPos(copy, rowAndPosToTheRight(self, ally, 1), self);
    };
    return res;
}

Card *Cards::createAlphaWerewolf()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAlphaWerewolf, this);

    res->id = "200114";
    res->power = res->powerBase = 10;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Beast, Cursed };

    res->_onContactWithFullMoon = [=](Card *self, IGame &game) {
        game.spawnNewUnitToPos(createWolf(), rowAndPosToTheLeft(self, ally, 1), self);
        game.spawnNewUnitToPos(createWolf(), rowAndPosToTheRight(self, ally, 1), self);
    };
    return res;
}

Card *Cards::createWerewolf()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createWerewolf, this);

    res->id = "201600";
    res->power = res->powerBase = 7;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Beast, Cursed };
    res->isImmune = true;

    res->_onContactWithFullMoon = [](Card *self, IGame &game) {
        game.boost(self, 7, self);
    };
    return res;
}

Card *Cards::createEredinBreaccGlas()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createEredinBreaccGlas, this);

    res->id = "131101";
    res->power = res->powerBase = 5;
    res->rarity = Gold;
    res->faction = Monster;
    res->tags = { WildHunt, Leader };

    res->_onDeploy = [](Card *self, IGame &game) {
        startChoiceCreateOptions(self, {isBronze, hasTag(WildHunt)}, AnyCard, -1);
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        game.spawnNewCard(target, self);
    };
    return res;
}

Card *Cards::createCaranthirArFeiniel()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createCaranthirArFeiniel, this);

    res->id = "132104";
    res->power = res->powerBase = 9;
    res->rarity = Gold;
    res->faction = Monster;
    res->tags = { WildHunt, Mage, Officer };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        const Row row = _findRowAndPos(self, ally).row();
        if (moveExistedUnitToPos(target, rowAndPosLastInExactRow(enemy, row), enemy, ally, self))
            applyRowEffect(3 + row, BitingFrostEffect);
    };
    return res;
}

Card *Cards::createImlerithSabbath()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createImlerithSabbath, this);

    res->id = "201781";
    res->power = res->powerBase = 5;
    res->rarity = Gold;
    res->faction = Monster;
    res->tags = { WildHunt, Officer };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.gainArmor(self, 2, self);
    };

    res->_onTurnEnd = [](Card *self, IGame &game) {
        if (!isOnBoard(self, ally))
            return;
        if (duel(self, highest(cardsFiltered({}, EnemyBoard), ally.rng), ally, enemy)) {
            heal(self, 2, self);
            game.gainArmor(self, 2, self);
        }
    };
    return res;
}

Card *Cards::createDagon()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDagon, this);

    res->id = "200158";
    res->power = res->powerBase = 8;
    res->rarity = Gold;
    res->faction = Monster;
    res->tags = { Leader, Vodyanoi };

    res->_onDeploy = [=](Card *self, IGame &game) {
        game.startChoiceToSelectOption(self, {createImpenetrableFog(), createTorrentialRain()});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        game.spawnNewCard(target, self);
    };
    return res;
}

Card *Cards::createIfrit()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createIfrit, this);

    res->id = "132210";
    res->power = res->powerBase = 8;
    res->rarity = Silver;
    res->faction = Monster;
    res->tags = { Construct };

    res->_onDeploy = [=](Card *self, IGame &game) {
        const Row row = _findRowAndPos(self, ally).row();
        const RowAndPos rowAndPos(row, Pos(ally.row(row).size()));
        game.spawnNewUnitToPos(createIfritLesser(), rowAndPos, self);
        game.spawnNewUnitToPos(createIfritLesser(), rowAndPos, self);
        game.spawnNewUnitToPos(createIfritLesser(), rowAndPos, self);
    };
    return res;
}

Card *Cards::createIfritLesser()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createIfritLesser, this);

    res->id = "132404";
    res->power = res->powerBase = 1;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Construct };
    res->isDoomed = true;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.damage(random(cardsFiltered({}, EnemyBoard), ally.rng), 1, self);
    };
    return res;
}

Card *Cards::createSheTrollOfVergen()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSheTrollOfVergen, this);

    res->id = "200534";
    res->power = res->powerBase = 1;
    res->rarity = Silver;
    res->faction = Monster;
    res->tags = { Ogroid };

    struct State : StateCopy<State> { bool _played = false; };
    res->state = new State();

    res->_onDeploy = [](Card *self, IGame &game) {
        self->stateAs<State>()->_played = false;
        game.startChoiceToTargetCard(self, {isBronze, isDeathwish}, AllyDeckShuffled);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        bool &played = self->stateAs<State>()->_played;
        if (!played) {
            played = true;
            game.startChoiceToTargetCard(self, {target});
            game.playExistedCard(target, self);
            return;
        }

        game.boost(self, consume(target, self), self);
    };
    return res;
}

Card *Cards::createWyvern()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createWyvern, this);

    res->id = "132303";
    res->power = res->powerBase = 6;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Draconid };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.damage(target, 5, self);
    };
    return res;
}

Card *Cards::createAbaya()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAbaya, this);

    res->id = "132203";
    res->power = res->powerBase = 4;
    res->rarity = Silver;
    res->faction = Monster;
    res->tags = { Necrophage };

    res->_onDeploy = [=](Card *self, IGame &game) {
        game.startChoiceToSelectOption(self, {createTorrentialRain(), createClearSkies(), createArachasVenom()});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        game.spawnNewCard(target, self);
    };
    return res;
}

Card *Cards::createParasite()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createParasite, this);

    res->id = "201657";
    res->isSpecial = true;
    res->rarity = Silver;
    res->faction = Monster;
    res->tags = { Organic };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        if (isOnBoard(target, ally))
            game.boost(target, 12, self);
        else if (isOnBoard(target, enemy))
            game.damage(target, 12, self);
        else
            throw Error(Error::Unreachable, self);
    };

    return res;
}

Card *Cards::createJotunn()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createJotunn, this);

    res->id = "200218";
    res->power = res->powerBase = 6;
    res->rarity = Silver;
    res->faction = Monster;
    res->tags = { Ogroid };

    res->_onDeploy = [](Card *self, IGame &game) {
        Row rowSelf = _findRowAndPos(self, ally).row();
        game.startChoiceToTargetCard(self, {isNotOnRow(&enemy, rowSelf)}, EnemyBoard, 3);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        Row rowSelf = _findRowAndPos(self, ally).row();
        if (moveExistedUnitToPos(target, rowAndPosLastInExactRow(enemy, rowSelf), enemy, ally, self))
            game.damage(target, rowEffectUnderUnit(target, enemy) == BitingFrostEffect ? 3 : 2, self);
    };
    return res;
}

Card *Cards::createIceGiant()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createIceGiant, this);

    res->id = "132212";
    res->power = res->powerBase = 6;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Ogroid };

    res->_onDeploy = [](Card *self, IGame &game) {
        if (enemy.rowEffect(Meele) == BitingFrostEffect
                || enemy.rowEffect(Range) == BitingFrostEffect
                || enemy.rowEffect(Seige) == BitingFrostEffect
                || ally.rowEffect(Meele) == BitingFrostEffect
                || ally.rowEffect(Range) == BitingFrostEffect
                || ally.rowEffect(Seige) == BitingFrostEffect)
            game.boost(self, 6, self);
    };
    return res;
}

Card *Cards::createIceTroll()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createIceTroll, this);

    res->id = "200502";
    res->power = res->powerBase = 4;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Ogroid };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        // NOTE: just duel with multiplied damage
        const int mult = rowEffectUnderUnit(target, enemy) == BitingFrostEffect ? 2 : 1;
        while (true) {
            if (game.damage(target, self->power * mult, self))
                return true;
            if (game.damage(self, target->power, target))
                return false;
        }
    };
    return res;
}

Card *Cards::createDrowner()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDrowner, this);

    res->id = "132314";
    res->power = res->powerBase = 7;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Necrophage };

    res->_onDeploy = [](Card *self, IGame &game) {
        Row rowSelf = _findRowAndPos(self, ally).row();
        game.startChoiceToTargetCard(self, {isNotOnRow(&enemy, rowSelf)}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        Row rowSelf = _findRowAndPos(self, ally).row();
        if (moveExistedUnitToPos(target, rowAndPosLastInExactRow(enemy, rowSelf), enemy, ally, self))
            game.damage(target, (rowEffectUnderUnit(target, enemy) > 0 && rowEffectUnderUnit(target, enemy) <= 9) ? 4 : 2, self);
    };
    return res;
}

Card *Cards::createFoglet()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createFoglet, this);

    res->id = "132301";
    res->power = res->powerBase = 4;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Necrophage };

    struct State : StateCopy<State> { std::map<Row, const Card *> _rowToCopy; };
    res->state = new State();

    res->_onAllyAppliedRowEffect = [](Card *self, const RowEffect rowEffect, IGame &game, const Row row) {
        std::map<Row, const Card *> &rowToCopy = self->stateAs<State>()->_rowToCopy;
        if (rowEffect != ImpenetrableFogEffect || !isIn(self, ally.deck))
            return;

        for (Card *copy : cardsFiltered({isCopy(self->id), otherThan(self)}, AllyDeckShuffled))
            copy->stateAs<State>()->_rowToCopy.insert({row, self});

        if (rowToCopy.find(row) == rowToCopy.end())
            moveExistedUnitToPos(self, rowAndPosLastInExactRow(ally, row), self);

        rowToCopy.clear();
    };
    return res;
}

Card *Cards::createAncientFoglet()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAncientFoglet, this);

    res->id = "132302";
    res->power = res->powerBase = 10;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Necrophage };

    res->_onTurnEnd = [](Card *self, IGame &game) {
        if (!isOnBoard(self, ally))
            return;
        if (enemy.rowEffect(Meele) == ImpenetrableFogEffect
                || enemy.rowEffect(Range) == ImpenetrableFogEffect
                || enemy.rowEffect(Seige) == ImpenetrableFogEffect
                || ally.rowEffect(Meele) == ImpenetrableFogEffect
                || ally.rowEffect(Range) == ImpenetrableFogEffect
                || ally.rowEffect(Seige) == ImpenetrableFogEffect)
            game.boost(self, 1, self);
    };
    return res;
}

Card *Cards::createDraug()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDraug, this);

    res->id = "132101";
    res->power = res->powerBase = 10;
    res->rarity = Gold;
    res->faction = Monster;
    res->tags = { Cursed, Officer };

    res->_onDeploy = [=](Card *self, IGame &game) {
        // TODO: check interaction w/ Cyris
        if (!isOnBoard(self, ally))
            throw Error(Error::Assert, self);

        const Row row = _findRowAndPos(self, ally).row();
        for (Card *card : cardsFiltered({isUnit}, AllyDiscard)) {
            if (isRowFull(ally.row(row)))
                return;
            banish(card, self);
            if (!game.spawnNewUnitToPos(createDraugir(), rowAndPosToTheRight(self, ally, 1), self))
                break;
        }
    };
    return res;
}

Card *Cards::createDraugir()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDraugir, this);

    // FIXME: incorrect picture
    res->id = "132101";
    res->power = res->powerBase = 1;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Cursed };
    res->isDoomed = true;
    return res;
}

Card *Cards::createCelaenoHarpy()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createCelaenoHarpy, this);

    res->id = "132217";
    res->power = res->powerBase = 6;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Beast };

    res->_onDeploy = [=](Card *self, IGame &game) {
        game.spawnNewUnitToPos(createHarpyEgg(), rowAndPosToTheLeft(self, ally, 1), self);
        game.spawnNewUnitToPos(createHarpyEgg(), rowAndPosToTheLeft(self, ally, 1), self);
    };
    return res;
}

Card *Cards::createHarpyEgg()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createHarpyEgg, this);

    res->id = "132316";
    res->power = res->powerBase = 1;
    res->rarity = Bronze;
    res->faction = Monster;
    res->isDoomed = true;

    res->_onConsumed = [](Card *self, IGame &game, Card *src) {
        game.boost(src, 4, self);
    };

    res->_onDestroy = [=](Card *self, IGame &game, const RowAndPos &) {
        game.spawnNewUnitToPos(createHarpyHatchling(), rowAndPosRandom(ally), self);
    };
    return res;
}

Card *Cards::createHarpyHatchling()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createHarpyHatchling, this);

    res->id = "132315";
    res->power = res->powerBase = 4;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Beast };
    return res;
}


Card *Cards::createArachasBehemoth()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createArachasBehemoth, this);

    res->id = "132201";
    res->power = res->powerBase = 8;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Insectoid };

    res->_onDeploy = [](Card *self, IGame &game) {
        setTimer(self, 4);
    };

    res->_onAllyConsume = [=](Card *self, IGame &game, Card *) {
        if (!isOnBoard(self, ally))
            return;
        if (!tick(self, ally, enemy))
            game.spawnNewUnitToPos(createArachasHatchling(), rowAndPosRandom(ally), self);
    };
    return res;
}


Card *Cards::createArachasHatchling()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createArachasHatchling, this);

    res->id = "132304";
    res->power = res->powerBase = 3;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Insectoid };

    res->_onDeploy = [](Card *self, IGame &game) {
        for (Card *copy : cardsFiltered({isCopy(self->id)}, AllyDeck))
            moveExistedUnitToPos(copy, rowAndPosToTheRight(self, ally, 1), self);
    };
    return res;
}

Card *Cards::createArchgriffin()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createArchgriffin, this);

    res->id = "132307";
    res->power = res->powerBase = 10;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Beast };

    res->_onDeploy = [](Card *self, Field &ally, Field &) {
        clearHazardsFromItsRow(self, ally);
    };
    return res;
}

Card *Cards::createGriffin()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createGriffin, this);

    res->id = "132312";
    res->power = res->powerBase = 9;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Beast };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronze, isDeathwish}, AllyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        target->onDestroy(_findRowAndPos(target, ally));
    };
    return res;
}

Card *Cards::createBridgeTroll()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createBridgeTroll, this);

    res->id = "201700";
    res->power = res->powerBase = 10;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Ogroid };

    struct State : StateCopy<State> { int _rowSelected = -1; };
    res->state = new State();

    res->_onDeploy = [](Card *self, IGame &game) {
        std::vector<int> rowsWithHazzards;
        for (int rowInd = 0; rowInd < 3; ++rowInd) {
            const RowEffect rowEffect = enemy.rowEffect(Row(rowInd));
            const bool isHazzard = (0 < rowEffect) && (rowEffect <= 9);
            if (!isHazzard)
                continue;
            rowsWithHazzards.push_back(rowInd + 3);
        }
        self->stateAs<State>()->_rowSelected = -1;
        startChoiceToSelectRow(self, rowsWithHazzards);
    };

    res->_onTargetRowChoosen = [](Card *self, IGame &game, const int screenRow) {
        int &rowSelected = self->stateAs<State>()->_rowSelected;
        if (rowSelected == -1) {
            rowSelected = screenRow;
            std::vector<int> otherRows = {3, 4, 5};
            otherRows.erase(otherRows.begin() + screenRow - 3);
            startChoiceToSelectRow(self, otherRows);
            return;
        }
        applyRowEffect(screenRow, enemy.rowEffect(Row(rowSelected - 3)));
        applyRowEffect(rowSelected, NoRowEffect);
    };
    return res;
}

Card *Cards::createCockatrice()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createCockatrice, this);

    res->id = "200233";
    res->power = res->powerBase = 6;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Draconid };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AnyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        reset(target, self);
    };
    return res;
}

Card *Cards::createNekurat()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createNekurat, this);

    res->id = "132220";
    res->power = res->powerBase = 5;
    res->rarity = Silver;
    res->faction = Monster;
    res->tags = { Vampire };

    res->_onDeploy = [=](Card *self, IGame &game) {
        game.spawnNewCard(createMoonlight(), self);
    };
    return res;
}

Card *Cards::createSiren()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSiren, this);

    res->id = "200112";
    res->power = res->powerBase = 4;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Beast };

    res->_onDeploy = [](Card *self, IGame &game) {
        // NOTE: 200067 is Moonlight
        if (Card *moonlight = random(cardsFiltered({isCopy("200067")}, AllyDeck), ally.rng))
            game.playExistedCard(moonlight, self);
    };
    return res;
}

Card *Cards::createLamia()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createLamia, this);

    res->id = "132409";
    res->power = res->powerBase = 6;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Beast };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.damage(target, rowEffectUnderUnit(target, enemy) == BloodMoonEffect ? 7 : 4 , self);
    };
    return res;
}

Card *Cards::createNekker()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createNekker, this);

    res->id = "132305";
    res->power = res->powerBase = 4;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Ogroid };

    res->_onAllyConsume = [](Card *self, IGame &game, Card *) {
        if (!isIn(self, ally.discard))
            game.boost(self, 1, self);
    };

    res->_onDestroy = [](Card *self, IGame &game, const RowAndPos &rowAndPos) {
        if (Card *copy = random(cardsFiltered({isCopy(self->id)}, AllyDeck), ally.rng))
            moveExistedUnitToPos(copy, rowAndPos, self);
    };
    return res;
}

Card *Cards::createNekkerWarrior()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createNekkerWarrior, this);

    res->id = "132211";
    res->power = res->powerBase = 9;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Ogroid };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronze}, AllyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        int n = 2;
        while (n--) {
            Card *self = target->defaultCopy();
            addAsNew(ally, self);
            putToDeck(self, DeckPosBottom, self);
        }
    };
    return res;
}

Card *Cards::createSlyzard()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSlyzard, this);

    res->id = "200539";
    res->power = res->powerBase = 2;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Draconid };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronze, isUnit}, AllyDiscard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        consume(target, self);
        if (Card *copy = random(cardsFiltered({isCopy(target->name)}, AllyDeck), ally.rng))
            game.playExistedCard(copy, self);
    };
    return res;
}

Card *Cards::createWerecat()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createWerecat, this);

    res->id = "201599";
    res->power = res->powerBase = 5;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Beast, Cursed };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.damage(target, 5, self);
        for (Card *card : cardsFiltered({}, EnemyBoard))
            if (rowEffectUnderUnit(card, enemy) == BloodMoonEffect)
                game.damage(card, 1, self);
    };
    return res;
}

Card *Cards::createHarpy()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createHarpy, this);

    res->id = "132315";
    res->power = res->powerBase = 4;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Beast };

    struct State : StateCopy<State> { std::map<Card *, Card *> _allyDestroyedToCopy; };
    res->state = new State();

    res->_onOtherAllyDestroyed = [](Card *self, Card *other, IGame &game, const RowAndPos rowAndPos) {
        std::map<Card *, Card *> &allyDestroyedToCopy = self->stateAs<State>()->_allyDestroyedToCopy;
        if (!isIn(self, ally.deck) || !hasTag(other, Beast))
            return;

        for (Card *copy : cardsFiltered({isCopy(self->id), otherThan(self)}, AllyDeckShuffled))
            copy->stateAs<State>()->_allyDestroyedToCopy.insert({other, self});

        if (allyDestroyedToCopy.find(other) == allyDestroyedToCopy.end())
            moveExistedUnitToPos(self, rowAndPos, self);

        allyDestroyedToCopy.clear();
    };
    return res;
}

Card *Cards::createWildHuntDrakkar()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createWildHuntDrakkar, this);

    res->id = "200301";
    res->power = res->powerBase = 7;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { WildHunt, Machine };

    res->_onDeploy = [](Card *self, IGame &game) {
        for (Card *card : cardsFiltered({hasTag(WildHunt)}, AllyBoard))
            game.boost(card, 1, self);
    };

    res->_onOtherAllyAppears = [](Card *self, Card *target, IGame &game) {
        if (!isOnBoard(self, ally) || !hasTag(target, WildHunt))
            return;
        game.boost(target, 1, self);
    };
    return res;
}

Card *Cards::createGeels()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createGeels, this);

    res->id = "131102";
    res->power = res->powerBase = 1;
    res->rarity = Gold;
    res->faction = Monster;
    res->tags = { WildHunt, Officer };

    struct State : StateCopy<State>
    {
        Card *_gold = nullptr;
        Card *_silver = nullptr;
    };
    res->state = new State();

    res->_onDeploy = [](Card *self, IGame &game) {
        Card *&gold = self->stateAs<State>()->_gold;
        Card *&silver = self->stateAs<State>()->_silver;
        std::vector<Card *> variants;
        if ((gold = random(cardsFiltered({isGold}, AllyDeck), ally.rng)))
            variants.push_back(gold);
        if ((silver = random(cardsFiltered({isSilver}, AllyDeck), ally.rng)))
            variants.push_back(silver);
        game.startChoiceToTargetCard(self, variants);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
        Card *gold = self->stateAs<State>()->_gold;
        Card *silver= self->stateAs<State>()->_silver;
        if (target == gold && silver)
            putToDeck(silver, DeckPosTop, self);
        else if (target == silver && gold)
            putToDeck(gold, DeckPosTop, self);
    };

    return res;
}

Card *Cards::createWildHuntRider()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createWildHuntRider, this);

    res->id = "132310";
    res->power = res->powerBase = 10;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { WildHunt, Soldier };

    // NOTE: ability is implemented inside the weather trigger
    return res;
}

Card *Cards::createVranWarrior()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createVranWarrior, this);

    res->id = "132308";
    res->power = res->powerBase = 6;
    res->rarity = Bronze;
    res->faction = Monster;
    res->tags = { Draconid, Soldier };

    res->_onDeploy = [](Card *self, IGame &game) {
        setTimer(self, 2);
        if (Card *card = cardNextTo(self, 1))
            game.boost(self, consume(card, self), self);
    };

    res->_onTurnStart = [](Card *self, IGame &game) {
        if (isOnBoard(self, ally) && tick(self, ally, enemy))
            self->onDeploy(ally, enemy);
    };
    return res;
}

Card *Cards::createAnCraiteArmorsmith()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAnCraiteArmorsmith, this);

    res->id = "152317";
    res->power = res->powerBase = 7;
    res->rarity = Bronze;
    res->faction = Skellige;
    res->tags = { ClanAnCraite, Support };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AllyBoard, 2);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        heal(target, self);
        game.gainArmor(target, 3, self);
    };
    return res;
}

Card *Cards::createAvalach()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAvalach, this);

    res->id = "132105";
    res->power = res->powerBase = 8;
    res->rarity = Gold;
    res->faction = Neutral;
    res->tags = { Elf, Mage };
    res->isDoomed = true;

    res->_onDeploy = [](Card *self, IGame &game) {
        if (ally.passed || enemy.passed)
            return;

        game.drawACard(self);
        game.drawACard(enemy, ally,  self);

        game.drawACard(self);
        game.drawACard(enemy, ally,  self);
    };
    return res;
}

Card *Cards::createAvalachSage()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAvalachSage, this);

    res->id = "112112";
    res->power = res->powerBase = 3;
    res->rarity = Gold;
    res->faction = Neutral;
    res->tags = { Elf, Mage };

    res->_onDeploy = [](Card *self, IGame &game) {
        if (Card *card = random(cardsFiltered({isSilverOrGold, isUnit}, EnemyDeckStarting), ally.rng))
            game.spawnNewCard(card->defaultCopy(), self);
    };
    return res;
}

Card *Cards::createRaghNarRoog()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createRaghNarRoog, this);

    res->id = "113101";
    res->isSpecial = true;
    res->rarity = Gold;
    res->faction = Neutral;
    res->tags = { Hazard, Spell };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        for (int screenRow = 3; screenRow < 6; ++screenRow)
            applyRowEffect(screenRow, RaghNarRoogEffect);
    };
    return res;
}

Card *Cards::createGeraltProfessional()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createGeraltProfessional, this);

    res->id = "201772";
    res->power = res->powerBase = 7;
    res->rarity = Gold;
    res->faction = Neutral;
    res->tags = { Witcher };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        if (target->faction == Monster)
            return putToDiscard(target, self);

        game.damage(target, 4, self);
    };
    return res;
}

Card *Cards::createGeraltAard()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createGeraltAard, this);

    res->id = "112111";
    res->power = res->powerBase = 6;
    res->rarity = Gold;
    res->faction = Neutral;
    res->tags = { Witcher };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, EnemyBoard, 3);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        if (!game.damage(target, 3, self)) {
            const RowAndPos rowAndPos = _findRowAndPos(target, enemy);
            const Row rowAbove = std::min(Row(rowAndPos.row() + 1), Seige);
            if (rowAbove != rowAndPos.row())
                moveExistedUnitToPos(target, rowAndPosLastInExactRow(enemy, rowAbove), enemy, ally, self);
        }
    };
    return res;
}

Card *Cards::createGeraltYrden()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createGeraltYrden, this);

    res->id = "201523";
    res->power = res->powerBase = 6;
    res->rarity = Gold;
    res->faction = Neutral;
    res->tags = { Witcher };

    res->_onDeploy = [](Card *self, IGame &game) {
        startChoiceToSelectRow(self);
    };

    res->_onTargetRowChoosen = [](Card *self, IGame &game, const int screenRow) {
        for (Card *card : cardsInRow(screenRow)) {
            reset(card, self);
            removeAllStatuses(card, self);
        }
    };
    return res;
}

Card *Cards::createCiriDash()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createCiriDash, this);

    res->id = "112110";
    res->power = res->powerBase = 11;
    res->rarity = Gold;
    res->faction = Neutral;
    res->tags = { Cintra, Witcher };

    res->_onDestroy = [](Card *self, IGame &game, const RowAndPos &) {
        self->onDiscard(ally, enemy);
    };

    res->_onDiscard = [](Card *self, IGame &game) {
        putToDeck(self, DeckPosRandom, self);
        strengthen(self, 3, self);
    };
    return res;
}

Card *Cards::createAguara()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAguara, this);

    res->id = "200062";
    res->power = res->powerBase = 5;
    res->rarity = Gold;
    res->faction = Neutral;
    res->tags = { Relict, Cursed };

    struct State : StateCopy<State> { std::vector<Card *> _optionsSelected; };
    res->state = new State();

    enum { BoostLowest, BoostInHand, DamageHighest, CharmElf };
    res->_onDeploy = [](Card *self, Field & ally, Field &enemy) {
        auto *option1 = createOption(self, BoostLowest);
        option1->text = "Boost the Lowest ally by 5.";

        auto *option2 = createOption(self, BoostInHand);
        option2->text = "Boost a random unit in your hand by 5.";

        auto *option3 = createOption(self, DamageHighest);
        option3->text = "Deal 5 damage to the Highest enemy.";

        auto *option4 = createOption(self, CharmElf);
        option4->text = "Charm a random enemy Elf with 5 power or less.";

        self->stateAs<State>()->_optionsSelected.clear();
        game.startChoiceToSelectOption(self, {option1, option2, option3, option4}, 2);
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        if (isOption(target, BoostLowest))
            if (Card *self = lowest(cardsFiltered({}, AllyBoard), ally.rng))
                game.boost(self, 5, self);

        if (isOption(target, BoostInHand))
            if (Card *self = random(cardsFiltered({isUnit}, AllyHand), ally.rng))
                game.boost(self, 5, self);

        if (isOption(target, DamageHighest))
            if (Card *self = highest(cardsFiltered({}, EnemyBoard), ally.rng))
                game.damage(self, 5, self);

        if (isOption(target, CharmElf))
            if (Card *self = random(cardsFiltered({hasTag(Elf), hasPowerXorLess(5)}, EnemyBoard), ally.rng))
                charm(self, self);

        std::vector<Card *> &optionsSelected = self->stateAs<State>()->_optionsSelected;
        optionsSelected.push_back(target);

        /// after 2 choices done, delete selected options
        if (optionsSelected.size() == 2) {
            delete optionsSelected[0];
            delete optionsSelected[1];
            optionsSelected.clear();
        }
    };
    return res;
}

Card *Cards::createAguaraTrueForm()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAguaraTrueForm, this);

    res->id = "200056";
    res->power = res->powerBase = 2;
    res->rarity = Gold;
    res->faction = Neutral;
    res->tags = { Relict, Cursed };

    res->_onDeploy = [](Card *self, IGame &game) {
        startChoiceCreateOptions(self, {isBronzeOrSilver, hasTag(Spell)});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        game.spawnNewCard(target, self);
    };
    return res;
}

Card *Cards::createKorathiHeatwave()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createKorathiHeatwave, this);

    res->id = "200018";
    res->isSpecial = true;
    res->rarity = Gold;
    res->faction = Neutral;
    res->tags = { Hazard };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        for (int screenRow = 3; screenRow < 6; ++screenRow)
            applyRowEffect(screenRow, KorathiHeatwaveEffect);
    };

    return res;
}

Card *Cards::createAleOfTheAncestors()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAleOfTheAncestors, this);

    res->id = "200532";
    res->power = res->powerBase = 10;
    res->rarity = Gold;
    res->faction = Neutral;

    res->_onDeploy = [](Card *self, IGame &game) {
        applyRowEffect(2 - int(_findRowAndPos(self, ally).row()), GoldenFrothEffect);
    };
    return res;
}

Card *Cards::createMahakamAle()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMahakamAle, this);

    res->id = "200519";
    res->isSpecial = true;
    res->rarity = Bronze;
    res->faction = Neutral;
    res->tags = { Alchemy };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        for (const Row row : std::vector<Row>{Meele, Range, Seige})
            if (Card *card = random(ally.row(row), ally.rng))
                game.boost(card, 4, self);
    };
    return res;
}

Card *Cards::createOdrin()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createOdrin, this);

    res->id = "122213";
    res->power = res->powerBase = 8;
    res->rarity = Silver;
    res->faction = NothernRealms;
    res->tags = { Kaedwen, Soldier };

    res->_onTurnStart = [](Card *self, IGame &game) {
        if (!isOnBoard(self, ally))
            return;
        if (!moveToRandomRow(self, self))
            return;
        for (Card *card : cardsFiltered({isOnSameRow(&ally, self), otherThan(self)}, AllyBoard))
            game.boost(card, 1, self);
    };
    return res;
}

Card *Cards::createToruviel()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createToruviel, this);

    res->id = "142204";
    res->power = res->powerBase = 6;
    res->isAmbush = true;
    res->rarity = Silver;
    res->faction = Scoiatael;
    res->tags = { Elf, Officer };

    res->_onDeploy = [](Card *self, Field &, Field &) {
        self->isAmbush = true;
    };

    res->_onOpponentPass = [](Card *self, IGame &game) {
        flipOver(self, ally, enemy);

        const std::vector<Card *> cardsToBoost {
            cardNextTo(self, -2),
            cardNextTo(self, -1),
            cardNextTo(self, 1),
            cardNextTo(self, 2),
        };
        for (Card *card : cardsToBoost)
            if (card != nullptr)
                game.boost(card, 2, self);
    };
    return res;
}

Card *Cards::createCiri()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createCiri, this);

    res->id = "112101";
    res->power = res->powerBase = 6;
    res->rarity = Gold;
    res->faction = Neutral;
    res->tags = { Cintra, Witcher };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.gainArmor(self, 2, self);
    };

    // FIXME: lost second ability
    return res;
}

Card *Cards::createMilva()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMilva, this);

    res->id = "142104";
    res->power = res->powerBase = 6;
    res->rarity = Gold;
    res->faction = Scoiatael;
    res->tags = { Soldier };

    res->_onDeploy = [](Card *self, IGame &game) {
        if (Card *card = highest(cardsFiltered({isBronzeOrSilver}, AllyBoard), ally.rng))
            putToDeck(card, DeckPosRandom, self);
        if (Card *card = highest(cardsFiltered({isBronzeOrSilver}, EnemyBoard), ally.rng))
            putToDeck(card, enemy, ally, DeckPosRandom, self);
    };
    return res;
}


Card *Cards::createPrincessPavetta()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createPrincessPavetta, this);

    res->id = "122210";
    res->power = res->powerBase = 3;
    res->rarity = Silver;
    res->faction = NothernRealms;
    res->tags = { Cintra, Mage };

    res->_onDeploy = [](Card *self, IGame &game) {
        if (Card *card = lowest(cardsFiltered({isBronzeOrSilver}, AllyBoard), ally.rng))
            putToDeck(card, DeckPosRandom, self);
        if (Card *card = lowest(cardsFiltered({isBronzeOrSilver}, EnemyBoard), ally.rng))
            putToDeck(card, enemy, ally, DeckPosRandom, self);
    };
    return res;
}

Card *Cards::createTheGuardian()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createTheGuardian, this);

    res->id = "162401";
    res->power = res->powerBase = 11;
    res->rarity = Silver;
    res->faction = Nilfgaard;
    res->tags = { Construct };

    res->_onDeploy = [=](Card *self, IGame &game) {
        Card *card = createLesserGuardian();
        addAsNew(enemy, card);
        putToDeck(card, enemy, ally, DeckPosTop, self);
    };
    return res;
}

Card *Cards::createLesserGuardian()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createLesserGuardian, this);

    res->id = "162401";
    res->power = res->powerBase = 6;
    res->rarity = Bronze;
    res->faction = Nilfgaard;
    res->tags = { Construct };
    return res;
}

Card *Cards::createGaunterODimm()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createGaunterODimm, this);

    res->id = "132215";
    res->power = res->powerBase = 6;
    res->rarity = Gold;
    res->faction = Neutral;
    res->tags = { Relict };

    struct State : StateCopy<State> { Card *_picked = nullptr; };
    res->state = new State();

    enum { Less6, Equal6, More6 };
    res->_onDeploy = [=](Card *self, IGame &game) {
        self->stateAs<State>()->_picked = random(createAll(), ally.rng);

        auto *option1 = createOption(self, Less6);
        option1->text = "Picked self power is less than 6.";

        auto *option2 = createOption(self, Equal6);
        option2->text = "Picked self power is 6.";

        auto *option3 = createOption(self, More6);
        option3->text = "Picked self power is more than 6.";

        game.startChoiceToSelectOption(self, {option1, option2, option3});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        Card *&_picked = self->stateAs<State>()->_picked;
        const bool guessed =
                (isOption(target, Less6) && (_picked->power < 6))
                || (isOption(target, Equal6) && (_picked->power == 6))
                || (isOption(target, More6) && (_picked->power > 6));
        delete target;
        if (!guessed) {
            _picked = nullptr;
            return;
        }
        game.spawnNewCard(_picked, self);
        _picked = nullptr;
    };
    return res;
}

Card *Cards::createKaedweniSergeant()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createKaedweniSergeant, this);

    res->id = "122214";
    res->power = res->powerBase = 9;
    res->rarity = Bronze;
    res->faction = NothernRealms;
    res->tags = { Kaedwen };
    res->isCrew = true;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.gainArmor(self, 3, self);
        clearHazardsFromItsRow(self, ally);
    };
    return res;
}

Card *Cards::createReinforcedBallista()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createReinforcedBallista, this);

    res->id = "122302";
    res->power = res->powerBase = 7;
    res->rarity = Bronze;
    res->faction = NothernRealms;
    res->tags = { Machine };

    res->_onDeploy = [](Card *self, IGame &game) {
        int n = 1 + nCrewed(self, ally);
        while (n--)
            game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.damage(target, 2, self);
    };
    return res;
}

Card *Cards::createSigismundDijkstra()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSigismundDijkstra, this);

    res->id = "122105";
    res->isLoyal = false;
    res->power = res->powerBase = 4;
    res->rarity = Gold;
    res->faction = NothernRealms;
    res->tags = { Redania };

    res->_onDeploy = [](Card *self, IGame &game) {
        for (Card *self : firsts(ally.deck, 2))
            game.playExistedCard(self, self);
    };
    return res;
}

Card *Cards::createWhiteFrost()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createWhiteFrost, this);

    res->id = "113206";
    res->isSpecial = true;
    res->rarity = Silver;
    res->faction = Neutral;
    res->tags = { Hazard };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        startChoiceToSelectRow(self, {3, 4, 5});
    };

    res->_onTargetRowChoosen = [](Card *self, IGame &game, const int screenRow) {
        for (int _screenRow = std::max(3, screenRow - 1); _screenRow <= screenRow; ++_screenRow)
            applyRowEffect(_screenRow, BitingFrostEffect);
    };
    return res;
}


Card *Cards::createWolfsbane()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createWolfsbane, this);

    res->id = "200226";
    res->rarity = Gold;
    res->faction = Neutral;
    res->isSpecial = true;
    res->tags = { Organic, Alchemy };

    res->_onDiscard = [](Card *self, IGame &game) {
        setTimer(self, 3);
    };

    res->_onTurnEnd = [](Card *self, IGame &game) {
        if (!isIn(self, ally.discard))
            return;
        if (!tick(self, ally, enemy))
            return;
        if (Card *card = highest(cardsFiltered({}, EnemyBoard), ally.rng))
            game.damage(card, 6, self);
        if (Card *card = lowest(cardsFiltered({}, AllyBoard), ally.rng))
            game.boost(card, 6, self);
    };
    return res;
}

Card *Cards::createDunBanner()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDunBanner, this);

    res->id = "122313";
    res->power = res->powerBase = 4;
    res->rarity = Bronze;
    res->faction = NothernRealms;
    res->tags = { Kaedwen, Soldier };

    res->_onTurnStart = [](Card *self, IGame &game) {
        if (!isIn(self, ally.deck))
            return;
        const int scoreDiff = powerField(enemy) - powerField(ally);
        if (scoreDiff <= 25)
            return;
        for (Card *card : cardsFiltered({isCopy(self->id)}, AllyDeck))
            moveExistedUnitToPos(card, rowAndPosRandom(ally), self);
    };
    return res;
}

Card *Cards::createAelirenn()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAelirenn, this);

    res->id = "142211";
    res->power = res->powerBase = 6;
    res->rarity = Silver;
    res->faction = Scoiatael;
    res->tags = { Elf, Officer };

    res->_onTurnEnd = [](Card *self, IGame &game) {
        if (!isIn(self, ally.deck))
            return;
        const int nElfs = int(cardsFiltered({hasTag(Elf)}, AllyBoard).size());
        if (nElfs < 5)
            return;
        moveExistedUnitToPos(self, rowAndPosRandom(ally), self);
    };
    return res;
}

Card *Cards::createHanmarvynsDream()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createHanmarvynsDream, this);

    res->id = "200079";
    res->rarity = Gold;
    res->faction = Neutral;
    res->isSpecial = true;
    res->tags = { Alchemy };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isGold, isUnit, hasNoTag(Leader)}, EnemyDiscard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        Card *copy = target->defaultCopy();
        game.spawnNewCard(copy, self);
        game.boost(copy, 2, self);
    };
    return res;
}

Card *Cards::createBlackBlood()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createBlackBlood, this);

    res->id = "201697";
    res->rarity = Silver;
    res->faction = Neutral;
    res->isSpecial = true;
    res->tags = { Alchemy, Item };
    res->state = new StateChoosen();

    enum { Create, Destroy };
    res->_onPlaySpecial = [](Card *self, IGame &game) {
        auto *option1 = createOption(self, Create);
        option1->text = "Create a Bronze Necrophage or Vampire and boost it by 2";

        auto *option2 = createOption(self, Destroy);
        option2->text = "Destroy a Bronze or Silver Necrophage or Vampire.";

        self->stateAs<StateChoosen>()->_choosen = nullptr;
        game.startChoiceToSelectOption(self, {option1, option2});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        Card *&choosen = self->stateAs<StateChoosen>()->_choosen;
        if (!choosen && isOption(target, Create)) {
            choosen = target;
            startChoiceCreateOptions(self, {isBronze, hasAnyOfTags({Necrophage, Vampire})});
            return;
        }

        if (!choosen && isOption(target, Destroy)) {
            choosen = target;
            game.startChoiceToTargetCard(self, {isBronzeOrSilver, hasAnyOfTags({Necrophage, Vampire})}, AnyBoard);
            return;
        }

        if (isOption(choosen, Create)) {
            game.boost(target, 2, self);
            game.spawnNewCard(target, self);

            delete choosen;
            choosen = nullptr;
            return;
        }

        throw Error(Error::Unreachable, self);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        Card *&choosen = self->stateAs<StateChoosen>()->_choosen;
        if (!isOption(choosen, Destroy))
            throw Error(Error::Assert, self);

        putToDiscard(target, self);

        delete choosen;
        choosen = nullptr;
    };
    return res;
}

Card *Cards::createBekkersRockslide()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createBekkersRockslide, this);

    res->id = "201634";
    res->rarity = Silver;
    res->faction = Neutral;
    res->isSpecial = true;
    res->tags = { Spell };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        for (Card *card : randoms(cardsFiltered({}, EnemyBoard), 10, ally.rng))
            game.damage(card, 2, self);
    };
    return res;
}

Card *Cards::createBekkersDarkMirror()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createBekkersDarkMirror, this);

    res->id = "113315";
    res->rarity = Silver;
    res->faction = Neutral;
    res->isSpecial = true;
    res->tags = { Spell };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        Card *high = highest(cardsFiltered({}, AnyBoard), ally.rng);
        Card *low = lowest(cardsFiltered({otherThan(high)}, AnyBoard), ally.rng);
        if (high == low)
            return;
        int transPower = std::min(10, high->power - low->power);
        setPower(high, high->power - transPower, self);
        setPower(low, low->power + transPower, self);
    };
    return res;
}

Card *Cards::createMerigoldsHailstorm()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMerigoldsHailstorm, this);

    res->id = "113202";
    res->rarity = Silver;
    res->faction = Neutral;
    res->isSpecial = true;
    res->tags = { Spell };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        startChoiceToSelectRow(self);
    };

    res->_onTargetRowChoosen = [](Card *self, IGame &game, const int screenRow) {
        for (Card *card : cardsInRow(screenRow)) {
            if (isBronzeOrSilver(card))
                setPower(card, card->power - half(card->power), self);
        }
    };
    return res;
}

Card *Cards::createNecromancy()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createNecromancy, this);

    res->id = "200020";
    res->rarity = Silver;
    res->faction = Neutral;
    res->isSpecial = true;
    res->tags = { Spell };

    struct State : StateCopy<State> { int transPower = 0; };
    res->state = new State();

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronzeOrSilver, isUnit}, BothDiscard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        if(isOnBoard(target, ally)) {
            game.boost(target, self->stateAs<State>()->transPower, self);
            return;
        }
        self->stateAs<State>()->transPower = target->power;
        banish(target, self);
        game.startChoiceToTargetCard(self, {}, AllyBoard);
    };
    return res;
}

Card *Cards::createStammelfordsTremor()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createStammelfordsTremor, this);

    res->id = "113204";
    res->rarity = Bronze;
    res->faction = Neutral;
    res->isSpecial = true;
    res->tags = { Spell };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        for (Card *card : cardsFiltered({}, EnemyBoard))
            game.damage(card, 1, self);
    };
    return res;
}

Card *Cards::createExpiredAle()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createExpiredAle, this);

    res->id = "200530";
    res->rarity = Silver;
    res->faction = Neutral;
    res->isSpecial = true;
    res->tags = { Spell };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        for (const Row row : std::vector<Row>{Meele, Range, Seige})
            if (Card *card = highest(enemy.row(row), enemy.rng))
                game.damage(card, 6, self);
    };
    return res;
}

Card *Cards::createTrialOfTheGrasses()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createTrialOfTheGrasses, this);

    res->id = "200078";
    res->rarity = Gold;
    res->faction = Neutral;
    res->isSpecial = true;
    res->tags = { Alchemy };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AnyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        if ((hasTag(target, Witcher) || !game.damage(target, 10, self)) && target->power < 25)
            setPower(target, 25, self);
    };
    return res;
}

Card *Cards::createDimeritiumBomb()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDimeritiumBomb, this);

    res->id = "113205";
    res->rarity = Silver;
    res->faction = Neutral;
    res->isSpecial = true;
    res->tags = { Alchemy };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        startChoiceToSelectRow(self);
    };

    res->_onTargetRowChoosen = [](Card *self, IGame &game, const int screenRow) {
        for (Card *card : cardsInRow(screenRow)) {
            if (isBoosted(card))
                reset(card, self);
        }
    };
    return res;
}

Card *Cards::createGarrison()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createGarrison, this);

    res->id = "201639";
    res->rarity = Silver;
    res->faction = Neutral;
    res->isSpecial = true;
    res->tags = { Tactics };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        startChoiceCreateOptions(self, {isBronzeOrSilver, isUnit}, EnemyDeckStarting);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        Card *copy = target->defaultCopy();
        game.boost(copy, 2, self);
        game.spawnNewCard(copy, self);
    };
    return res;
}

Card *Cards::createTheLastWish()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createTheLastWish, this);

    res->id = "113102";
    res->rarity = Silver;
    res->faction = Neutral;
    res->isSpecial = true;
    res->tags = { Spell };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, randoms(cardsFiltered({}, AllyDeck), 2, ally.rng));
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}

Card *Cards::createDimeritiumShackles()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDimeritiumShackles, this);

    res->id = "113319";
    res->rarity = Bronze;
    res->faction = Neutral;
    res->isSpecial = true;
    res->tags = { Alchemy, Item };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AnyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        toggleLock(target, self);
        if (isOnBoard(target, enemy))
            game.damage(target, 4, self);
    };
    return res;
}

Card *Cards::createWyvernScaleShield()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createWyvernScaleShield, this);

    res->id = "133301";
    res->rarity = Bronze;
    res->faction = Neutral;
    res->isSpecial = true;
    res->tags = { Item };

    struct State : StateCopy<State> { int _boostAmount = 0; };
    res->state = new State();

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        if (cardsFiltered({}, AnyBoard).size() == 0)
            return;
        game.startChoiceToTargetCard(self, {isBronzeOrSilver, isUnit}, AllyHand);
        self->stateAs<State>()->_boostAmount = 0;
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        int &boostAmount = self->stateAs<State>()->_boostAmount;
        if (boostAmount <= 0) {
            boostAmount = target->powerBase;
            game.startChoiceToTargetCard(self, {}, AnyBoard);
            return;
        }
        game.boost(target, boostAmount, self);
        boostAmount = 0;
    };
    return res;
}

Card *Cards::createMastercraftedSpear()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMastercraftedSpear, this);

    res->id = "201656";
    res->rarity = Bronze;
    res->faction = Neutral;
    res->isSpecial = true;
    res->tags = { Item };

    struct State : StateCopy<State> { int _damageAmount = 0; };
    res->state = new State();

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        if (cardsFiltered({}, AnyBoard).size() == 0)
            return;
        game.startChoiceToTargetCard(self, {isBronzeOrSilver, isUnit}, AllyHand);
        self->stateAs<State>()->_damageAmount = 0;
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        int &damageAmount = self->stateAs<State>()->_damageAmount;
        if (damageAmount <= 0) {
            damageAmount = target->powerBase;
            game.startChoiceToTargetCard(self, {}, AnyBoard);
            return;
        }
        game.damage(target, damageAmount, self);
        damageAmount = 0;
    };
    return res;
}

Card *Cards::createPetrisPhilter()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createPetrisPhilter, this);

    res->id = "200008";
    res->rarity = Bronze;
    res->faction = Neutral;
    res->isSpecial = true;
    res->tags = { Alchemy, Item };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        for (Card *card : randoms(cardsFiltered({}, AllyBoard), 6, ally.rng))
            game.boost(card, 2, self);
    };
    return res;
}

Card *Cards::createShrike()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createShrike, this);

    res->id = "200009";
    res->rarity = Bronze;
    res->faction = Neutral;
    res->isSpecial = true;
    res->tags = { Alchemy, Item };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        for (Card *card : randoms(cardsFiltered({}, EnemyBoard), 6, ally.rng))
            game.damage(card, 2, self);
    };
    return res;
}

Card *Cards::createRoyalDecree()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createRoyalDecree, this);

    res->id = "200154";
    res->rarity = Gold;
    res->faction = Neutral;
    res->isSpecial = true;
    res->tags = { Tactics };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isGold, isUnit}, AllyDeck);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.boost(target, 2, self);
        game.playExistedCard(target, self);
    };
    return res;
}

Card *Cards::createUmasCurse()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createUmasCurse, this);

    res->id = "200058";
    res->rarity = Gold;
    res->faction = Neutral;
    res->isSpecial = true;
    res->tags = { Spell };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        startChoiceCreateOptions(self, {isGold, isUnit, hasNoTag(Leader)});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        game.spawnNewCard(target, self);
    };
    return res;
}

Card *Cards::createLacerate()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createLacerate, this);

    res->id = "153301";
    res->rarity = Bronze;
    res->faction = Neutral;
    res->isSpecial = true;
    res->tags = { Organic };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        startChoiceToSelectRow(self);
    };

    res->_onTargetRowChoosen = [](Card *self, IGame &game, const int screenRow) {
        for (Card *card : cardsInRow(screenRow))
            game.damage(card, 3, self);
    };
    return res;
}

Card *Cards::createCrowsEye()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createCrowsEye, this);

    res->id = "200224";
    res->rarity = Bronze;
    res->faction = Neutral;
    res->isSpecial = true;
    res->tags = { Alchemy, Organic };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        const int extraDamage = int(cardsFiltered({isCopy(self->id)}, AllyDiscard).size());
        for (const Row row : std::vector<Row>{Meele, Range, Seige})
            if (Card *card = highest(enemy.row(row), enemy.rng))
                game.damage(card, 4 + extraDamage, self);
    };
    return res;
}

Card *Cards::createDoppler()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDoppler, this);

    res->id = "201631";
    res->rarity = Bronze;
    res->faction = Neutral;
    res->isSpecial = true;

    res->_onPlaySpecial = [=](Card *self, IGame &game) {
        const int currentFaction = ally.leader ? ally.leader->faction : Neutral;
        Card *card = random(_filtered({isFaction(currentFaction), isBronze, isUnit}, createAll()), ally.rng)->defaultCopy();
        game.spawnNewCard(card, self);
    };
    return res;
}

Card *Cards::createSpores()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSpores, this);

    res->id = "201744";
    res->rarity = Bronze;
    res->faction = Neutral;
    res->isSpecial = true;
    res->tags = { Organic };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        startChoiceToSelectRow(self);
    };

    res->_onTargetRowChoosen = [](Card *self, IGame &game, const int screenRow) {
        for (Card *card : cardsInRow(screenRow))
            game.damage(card, 2, self);
        if (rowEffectInSreenRow(screenRow) > 9)
            applyRowEffect(screenRow, NoRowEffect);
    };
    return res;
}

Card *Cards::createMardroeme()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMardroeme, this);

    res->id = "113320";
    res->rarity = Bronze;
    res->faction = Neutral;
    res->isSpecial = true;
    res->tags = { Alchemy, Organic };
    res->state = new StateChoosen();

    enum { Strengthen, Weaken };
    res->_onPlaySpecial = [](Card *self, IGame &game) {
        auto *option1 = createOption(self, Strengthen);
        option1->text = "Reset a unit and Strengthen it by 3.";

        auto *option2 = createOption(self, Weaken);
        option2->text = "Reset a unit and Weaken it by 3.";

        self->stateAs<StateChoosen>()->_choosen = nullptr;
        game.startChoiceToSelectOption(self, {option1, option2});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        self->stateAs<StateChoosen>()->_choosen = target;
        game.startChoiceToTargetCard(self, {}, AnyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        Card *&choosen = self->stateAs<StateChoosen>()->_choosen;
        if (!choosen)
            throw Error(Error::ChoosenIsNullptr, self);

        reset(target, self);
        if (isOption(choosen, Strengthen))
            strengthen(target, 3, self);

        if (isOption(choosen, Weaken))
            weaken(target, 3, self);

        delete choosen;
        choosen = nullptr;
    };
    return res;
}

Card *Cards::createSihil()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSihil, this);

    res->id = "201632";
    res->rarity = Gold;
    res->faction = Neutral;
    res->isSpecial = true;
    res->tags = { Item };

    enum { DamageOdd, DamageEven, PlayFromDeck };
    res->_onPlaySpecial = [](Card *self, IGame &game) {
        auto *option1 = createOption(self, DamageOdd);
        option1->text = "Deal 3 damage to all enemies with odd power.";

        auto *option2 = createOption(self, DamageEven);
        option2->text = "Deal 3 damage to all enemies with even power.";

        auto *option3 = createOption(self, PlayFromDeck);
        option3->text = "Play a random Bronze or Silver unit from your deck.";

        game.startChoiceToSelectOption(self, {option1, option2, option3});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        if (isOption(target, DamageOdd)) {
            for (Card *self : cardsFiltered({hasOddPower}, EnemyBoard))
                game.damage(self, 3, self);
            return;
        }

        if (isOption(target, DamageEven)) {
            for (Card *self : cardsFiltered({hasEvenPower}, EnemyBoard))
                game.damage(self, 3, self);
            return;
        }

        if (isOption(target, PlayFromDeck)) {
            if (Card *self = random(cardsFiltered({isBronzeOrSilver, isUnit}, AllyDeck), ally.rng))
                game.playExistedCard(self, self);
            return;
        }

        throw Error(Error::Unreachable, self);
    };
    return res;
}

Card *Cards::createDragonsDream()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDragonsDream, this);

    res->id = "201637";
    res->rarity = Silver;
    res->faction = Neutral;
    res->isSpecial = true;
    res->tags = { Alchemy, Item };

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        startChoiceToSelectRow(self, {3, 4, 5});
    };

    res->_onTargetRowChoosen = [](Card *self, IGame &game, const int screenRow) {
        applyRowEffect(screenRow, DragonsDreamEffect);
    };
    return res;
}

Card *Cards::createEskelPathfinder()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createEskelPathfinder, this);

    res->id = "200236";
    res->power = res->powerBase = 7;
    res->rarity = Gold;
    res->faction = Neutral;
    res->tags = { Witcher };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronzeOrSilver, isNotBoosted}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        putToDiscard(target, self);
    };
    return res;
}

Card *Cards::createVesemirMentor()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createVesemirMentor, this);

    res->id = "200237";
    res->tags = { Witcher };
    res->power = res->powerBase = 6;
    res->faction = Neutral;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronzeOrSilver, hasTag(Alchemy)}, AllyDeckShuffled);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}

Card *Cards::createLambertSwordmaster()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createLambertSwordmaster, this);

    res->id = "200235";
    res->tags = { Witcher };
    res->power = res->powerBase = 8;
    res->faction = Neutral;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        for (Card *copy : findCopies(target, cardsFiltered({}, EnemyBoard)))
            game.damage(copy, 4, self);
    };
    return res;
}

Card *Cards::createRegisHigherVampire()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createRegisHigherVampire, this);

    res->id = "112105";
    res->tags = { Witcher };
    res->power = res->powerBase = 6;
    res->faction = Neutral;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, randoms(cardsFiltered({isBronze, isUnit}, EnemyDeck), 3, ally.rng));
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.boost(self, consume(target, self), self);
    };
    return res;
}

Card *Cards::createZoltanScoundrel()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createZoltanScoundrel, this);

    res->id = "112109";
    res->tags = { Dwarf };
    res->power = res->powerBase = 8;
    res->faction = Neutral;
    res->rarity = Gold;

    res->_onDeploy = [=](Card *self, IGame &game) {
        game.startChoiceToSelectOption(self, {createDudaCompanion(), createDudaAgitator()});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        game.spawnNewCard(target, self);
    };
    return res;
}

Card *Cards::createDudaCompanion()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDudaCompanion, this);

    res->id = "112403";
    res->tags = { Beast };
    res->isDoomed = true;
    res->power = res->powerBase = 1;
    res->faction = Neutral;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        const std::vector<Card *> cardsToBoost {
            cardNextTo(self, -2),
            cardNextTo(self, -1),
            cardNextTo(self, 1),
            cardNextTo(self, 2),
        };
        for (Card *card : cardsToBoost)
            if (card != nullptr)
                game.boost(card, 2, self);
    };
    return res;
}

Card *Cards::createDudaAgitator()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDudaAgitator, this);

    res->id = "112404";
    res->tags = { Beast };
    res->isDoomed = true;
    res->isLoyal = false;
    res->power = res->powerBase = 1;
    res->faction = Neutral;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        const std::vector<Card *> cardsToDamage {
            cardNextTo(self, -2),
            cardNextTo(self, -1),
            cardNextTo(self, 1),
            cardNextTo(self, 2),
        };
        for (Card *card : cardsToDamage)
            if (card != nullptr)
                game.damage(card, 2, self);
    };
    return res;
}

Card *Cards::createYenneferConjurer()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createYenneferConjurer, this);

    res->id = "112113";
    res->tags = { Mage, Aedirn };
    res->power = res->powerBase = 10;
    res->faction = Neutral;
    res->rarity = Gold;

    res->_onTurnEnd = [](Card *self, IGame &game) {
        if (!isOnBoard(self, ally))
            return;
        for (Card *card : highests(cardsFiltered({}, EnemyBoard)))
            game.damage(card, 1, self);
    };
    return res;
}

Card *Cards::createTrissMerigold()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createTrissMerigold, this);

    res->id = "112106";
    res->tags = { Mage, Temeria };
    res->power = res->powerBase = 10;
    res->faction = Neutral;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.damage(target, 5, self);
    };
    return res;
}

Card *Cards::createTrissTelekinesis()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createTrissTelekinesis, this);

    res->id = "201773";
    res->tags = { Mage, Temeria };
    res->power = res->powerBase = 6;
    res->faction = Neutral;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        startChoiceCreateOptions(self, {isBronze, ::isSpecial}, BothDeckStarting);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        Card *copy = target->defaultCopy();
        game.spawnNewCard(copy, self);
    };
    return res;
}

Card *Cards::createDorregarayOfVole()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDorregarayOfVole, this);

    res->id = "200087";
    res->tags = { Mage };
    res->power = res->powerBase = 1;
    res->faction = Neutral;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        startChoiceCreateOptions(self, {isBronzeOrSilver, hasAnyOfTags({Beast, Draconid})});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        game.spawnNewCard(target, self);
    };
    return res;
}

Card *Cards::createDandelionVainglory()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDandelionVainglory, this);

    res->id = "201774";
    res->power = res->powerBase = 9;
    res->rarity = Gold;
    res->faction = Neutral;
    res->tags = { Support };

    res->_onDeploy = [](Card *self, IGame &game) {
        const auto isFellow = [](Card *card) {
            /// NOTE: GeraltAard
            return isCopy("112111")(card)
                    /// NOTE: GeraltIgni
                    || isCopy("112102")(card)
                    /// NOTE: GeraltYrden
                    || isCopy("201523")(card)
                    /// NOTE: GeraltOfRivia
                    || isCopy("112103")(card)
                    /// NOTE: GeraltProfessional
                    || isCopy("201772")(card)
                    /// NOTE: Yennefer
                    || isCopy("112108")(card)
                    /// NOTE: YenneferConjurer
                    || isCopy("112113")(card)
                    /// NOTE: YenneferEnchantress
                    || isCopy("201601")(card)
                    /// NOTE: YenneferNecromancer
                    || isCopy("201780")(card)
                    /// NOTE: TrissMerigold
                    || isCopy("112106")(card)
                    /// NOTE: TrissButterflies
                    || isCopy("122107")(card)
                    /// NOTE: TrissTelekinesis
                    || isCopy("201773")(card)
                    /// NOTE: ZoltanChivay
                    || isCopy("142105")(card)
                    /// NOTE: ZoltanScoundrel
                    || isCopy("112109")(card);
        };

        int boostNumber = cardsFiltered({isFellow}, AllyDeckStarting).size();
        if (boostNumber <= 0)
            return;
        game.boost(self, boostNumber * 3, self);
    };
    return res;
}

Card *Cards::createCyprianWiley()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createCyprianWiley, this);

    res->id = "112214";
    res->power = res->powerBase = 8;
    res->rarity = Silver;
    res->faction = Neutral;
    res->tags = { Redania };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        weaken(target, 4, self);
    };
    return res;
}

Card *Cards::createDudu()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDudu, this);

    res->id = "112201";
    res->power = res->powerBase = 1;
    res->rarity = Silver;
    res->faction = Neutral;
    res->tags = { Relict };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        setPower(self, target->power, self);
    };
    return res;
}

Card *Cards::createIhuarraquax()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createIhuarraquax, this);

    res->id = "201817";
    res->tags = { Beast };
    res->power = res->powerBase = 7;
    res->faction = Neutral;
    res->rarity = Gold;

    struct State : StateCopy<State> { bool damageDone = false; };
    res->state = new State();

    res->_onDeploy = [](Card *self, IGame &game) {
        self->stateAs<State>()->damageDone = false;
        setTimer(self, 1);
        game.damage(self, 5, self);
    };

    res->_onPowerChanged = [](Card *self, IGame &game, const Card *, const PowerChangeType) {
        if ((self->timer > 0) && (self->power == self->powerBase))
            tick(self, ally, enemy);
    };

    res->_onTurnEnd = [](Card *self, IGame &game) {
        bool &damageDone = self->stateAs<State>()->damageDone;
        if((self->timer != -1) || (damageDone) || (!isOnBoard(self, ally)))
            return;
        for (Card *self : randoms(cardsFiltered({}, EnemyBoard), 3, ally.rng))
            game.damage(self, 7, self);
        damageDone = true;
    };
    return res;
}

Card *Cards::createMahakamMarauder()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMahakamMarauder, this);

    res->id = "200042";
    res->power = res->powerBase = 7;
    res->rarity = Bronze;
    res->faction = Scoiatael;
    res->tags = { Dwarf, Soldier };

    res->_onPowerChanged = [](Card *self, IGame &game, const Card *src, const PowerChangeType type) {
        if((!isOnBoard(self, ally)) || (type == Reset) || (src == self))
            return;
        game.boost(self, 2, self);
    };
    return res;
}

Card *Cards::createZoltanChivay()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createZoltanChivay, this);

    res->id = "142105";
    res->tags = { Dwarf };
    res->power = res->powerBase = 8;
    res->faction = Scoiatael;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AnyBoard, 3);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        const Row row = _findRowAndPos(self, ally).row();
        if (isOnBoard(target, ally)) {
            strengthen(target, 2, self);
            moveExistedUnitToPos(target, rowAndPosLastInExactRow(ally, row), self);
            return;
        }
        if (isOnBoard(target, enemy)) {
            game.damage(target, 2, self);
            moveExistedUnitToPos(target, rowAndPosLastInExactRow(enemy, row), enemy, ally, self);
            return;
        }
        throw Error(Error::Unreachable, self);
    };
    return res;
}

Card *Cards::createYenneferNecromancer()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createYenneferNecromancer, this);

    res->id = "201780";
    res->tags = { Mage, Aedirn };
    res->power = res->powerBase = 5;
    res->faction = Nilfgaard;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronzeOrSilver, hasTag(Soldier)}, EnemyDiscard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}

Card *Cards::createPhoenix()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createPhoenix, this);

    res->id = "201579";
    res->tags = { Draconid };
    res->isDoomed = true;
    res->power = res->powerBase = 5;
    res->faction = Neutral;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronzeOrSilver, hasTag(Draconid)}, AllyDiscard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}

Card *Cards::createSaesenthessisBlaze()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSaesenthessisBlaze, this);

    res->id = "201613";
    res->tags = { Aedirn, Draconid };
    res->power = res->powerBase = 11;
    res->faction = Neutral;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        const std::vector<Card *> hand = ally.hand;
        const int64_t nCards = hand.size();
        for (Card *card : hand)
            banish(card, self);
        for (int cardInd = 0; cardInd < nCards; ++cardInd)
            game.drawACard(self);
    };
    return res;
}

Card *Cards::createVillentretenmerth()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createVillentretenmerth, this);

    res->id = "112107";
    res->tags = { Draconid };
    res->power = res->powerBase = 10;
    res->faction = Neutral;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        setTimer(self, 3);
    };

    res->_onTurnStart = [](Card *self, IGame &game) {
        if (!tick(self, ally, enemy))
            return;
        for (Card *card : highests(cardsFiltered({otherThan(self)}, AnyBoard)))
            putToDiscard(card, self);
    };
    return res;
}

Card *Cards::createOcvist()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createOcvist, this);

    res->id = "112206";
    res->tags = { Draconid };
    res->power = res->powerBase = 8;
    res->faction = Neutral;
    res->rarity = Silver;
    res->timer = 4;

    res->_onTurnStart = [](Card *self, IGame &game) {
        if (!isOnBoard(self, ally) || !tick(self, ally, enemy))
            return;
        for (Card *card : cardsFiltered({}, EnemyBoard))
            game.damage(card, 1, self);
        putToHand(self,  self);
    };
    return res;
}

Card *Cards::createMyrgtabrakke()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMyrgtabrakke, this);

    res->id = "112205";
    res->tags = { Draconid };
    res->power = res->powerBase = 7;
    res->faction = Neutral;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        for (int n = 0; n < 3; ++n)
            game.startChoiceToTargetCard(self, {}, AnyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.damage(target, 2, self);
    };
    return res;
}

Card *Cards::createKingOfBeggars()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createKingOfBeggars, this);

    res->id = "112213";
    res->tags = { Support };
    res->power = res->powerBase = 5;
    res->faction = Neutral;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        const int boost = std::min(powerField(enemy) - powerField(ally), 10);
        if (boost > 0)
            strengthen(self, boost, self);
    };
    return res;
}

Card *Cards::createOlgierdVonEverec()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createOlgierdVonEverec, this);

    res->id = "112207";
    res->tags = { Redania, Cursed };
    res->power = res->powerBase = 5;
    res->faction = Neutral;
    res->rarity = Silver;

    res->_onDestroy = [](Card *self, IGame &game, const RowAndPos &) {
        moveExistedUnitToPos(self, rowAndPosRandom(ally), self);
    };
    return res;
}

Card *Cards::createIrisVonEverec()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createIrisVonEverec, this);

    res->id = "112215";
    res->tags = { Redania, Cursed };
    res->isLoyal = false;
    res->power = res->powerBase = 3;
    res->faction = Neutral;
    res->rarity = Silver;

    res->_onDestroy = [](Card *self, IGame &game, const RowAndPos &) {
        for (Card *card : randoms(cardsFiltered({}, EnemyBoard), 5, ally.rng))
            game.boost(card, 5, self);
    };
    return res;
}

Card *Cards::createIrisCompanions()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createIrisCompanions, this);

    res->id = "200083";
    res->tags = { Relict };
    res->power = res->powerBase = 11;
    res->faction = Neutral;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AllyDeck);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        putToHand(target,  self);
        putToDiscard(random(ally.hand, ally.rng), self);
    };
    return res;
}

Card *Cards::createJohnny()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createJohnny, this);

    res->id = "112211";
    res->tags = { Relict };
    res->power = res->powerBase = 9;
    res->faction = Neutral;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AllyHand);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        putToDiscard(target, self);
        if(Card *card = random(cardsFiltered({isColor(target->rarity)}, EnemyDeckStarting), ally.rng)) {
            Card *cardCopy = card->defaultCopy();
            addAsNew(ally, cardCopy);
            putToHand(cardCopy,  self);
        }
    };
    return res;
}

Card *Cards::createStregobor()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createStregobor, this);

    res->id = "200091";
    res->tags = { Mage };
    res->power = res->powerBase = 10;
    res->faction = Neutral;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        if (ally.passed || enemy.passed)
            return;
        if (Card *unit = first(cardsFiltered({isUnit}, AllyDeck))) {
            putToHand(unit,  self);
            setPower(unit, 1, self);
        }
        if (Card *unit = first(cardsFiltered({isUnit}, EnemyDeck))) {
            putToHand(unit, enemy, ally,  self);
            setPower(unit, 1, self);
        }
    };

    return res;
}

Card *Cards::createSarah()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSarah, this);

    res->id = "112212";
    res->tags = { Relict };
    res->power = res->powerBase = 11;
    res->faction = Neutral;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AllyHand);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        if (Card *self = first(cardsFiltered({isColor(target->rarity)}, AllyDeck))) {
            putToDeck(target, DeckPosRandomButNotFirst, self);
            putToHand(self,  self);
            // TODO: check if here we need to trigger onSwap or etc.
        }
    };
    return res;
}

Card *Cards::createPeasantMilitia()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createPeasantMilitia, this);

    res->id = "201753";
    res->tags = { Tactics };
    res->isSpecial = true;
    res->faction = Neutral;
    res->rarity = Bronze;

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        startChoiceToSelectRow(self, {0, 1, 2});
    };

    res->_onTargetRowChoosen = [=](Card *self, IGame &game, const int screenRow) {
        for(int i = 0; i < 3; i++) {
            if (isRowFull(cardsInRow(screenRow)))
                return;
            Card *peasant = createPeasant();
            addAsNew(ally, peasant);
            moveExistedUnitToPos(peasant, rowAndPosLastInExactRow(screenRow, ally, enemy), self);
        }
    };
    return res;
}

Card *Cards::createPeasant()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createPeasant, this);

    res->id = "201753";
    res->power = res->powerBase = 3;
    res->isDoomed = true;
    res->faction = Neutral;
    res->rarity = Bronze;
    return res;
}

Card *Cards::createPrizeWinningCow()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createPrizeWinningCow, this);

    //https://gwent.one/image/gwent/assets/self/art/medium/1498.jpg
    res->id = "112209";
    res->power = res->powerBase = 1;
    res->tags = { Beast };
    res->faction = Neutral;
    res->rarity = Silver;

    res->_onDestroy = [=](Card *self, IGame &game, const RowAndPos &) {
        Card *chort = createChort();
        addAsNew(ally, chort);
        moveExistedUnitToPos(chort, rowAndPosRandom(ally), self);
    };
    return res;
}

Card *Cards::createChort()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createChort, this);

    // FIXME: missing image and incorrect id
    res->id = "112209";
    // TODO: place this picture somehow
    //https://gwent.one/image/gwent/assets/self/art/medium/1498.jpg
    res->power = res->powerBase = 15;
    res->tags = { Relict };
    res->faction = Neutral;
    res->rarity = Bronze;
    return res;
}

Card *Cards::createPrincessAdda()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createPrincessAdda, this);

    res->id = "201595";
    res->power = res->powerBase = 6;
    res->tags = { Leader, Cursed };
    res->faction = NothernRealms;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        startChoiceCreateOptions(self, {isBronzeOrSilver, isUnit, hasTag(Cursed)});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        game.spawnNewCard(target, self);
    };
    return res;
}

Card *Cards::createKingFoltest()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createKingFoltest, this);

    res->id = "200168";
    res->power = res->powerBase = 5;
    res->tags = { Leader, Temeria };
    res->isCrew = true;
    res->faction = NothernRealms;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        std::vector<Card *> cards = cardsFiltered({otherThan(self)}, AllyBoard);
        std::vector<Card *> cardsDeck = cardsFiltered({isUnit, otherThan(self), isNonSpying}, AllyDeck);
        std::vector<Card *> cardsHand = cardsFiltered({isUnit, otherThan(self), isNonSpying}, AllyHand);
        cards.insert(cards.end(), cardsDeck.begin(), cardsDeck.end());
        cards.insert(cards.end(), cardsHand.begin(), cardsHand.end());
        for (Card *card : cards)
            game.boost(card, 1, self);
    };
    return res;
}

Card *Cards::createKingRadovidV()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createKingRadovidV, this);

    res->id = "200169";
    res->power = res->powerBase = 6;
    res->rarity = Gold;
    res->faction = NothernRealms;
    res->tags = { Leader, Redania };
    res->isCrew = true;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AnyBoard, 2);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        toggleLock(target, self);
        if (isOnBoard(target, enemy))
            game.damage(target, 4, self);
    };
    return res;
}

Card *Cards::createEmhyrVarEmreis()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createEmhyrVarEmreis, this);

    res->id = "200162";
    res->power = res->powerBase = 7;
    res->rarity = Gold;
    res->faction = Nilfgaard;
    res->tags = { Leader, Officer };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AllyHand);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        if (isIn(target, ally.hand)) {
            // reverse due to choice stack: play a self, then return something to hand
            game.startChoiceToTargetCard(self, {isBronzeOrSilver}, AllyBoard);
            game.playExistedCard(target, self);
            return;
        }
        putToHand(target,  self);
    };
    return res;
}

Card *Cards::createUsurper()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createUsurper, this);

    res->id = "201580";
    res->power = res->powerBase = 1;
    res->rarity = Gold;
    res->faction = Nilfgaard;
    res->tags = { Leader, Officer };
    res->isLoyal = false;

    res->_onDeploy = [](Card *self, IGame &game) {
        startChoiceCreateOptions(self, {hasTag(Leader)});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        game.boost(target, 2, self);
        game.spawnNewCard(target, self);
    };
    return res;
}

Card *Cards::createBrouverHoog()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createBrouverHoog, this);

    res->id = "200167";
    res->power = res->powerBase = 4;
    res->tags = { Leader, Dwarf };
    res->faction = Scoiatael;
    res->rarity = Gold;

    const auto isOk = [](Card *card) {
        return isUnit(card) && ((isNonSpying(card) && isSilver(card)) || (hasTag(card, Dwarf) && isBronze(card)));
    };

    res->_onDeploy = [isOk](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isOk}, AllyDeckShuffled);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}

Card *Cards::createEithne()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createEithne, this);

    res->id = "200166";
    res->power = res->powerBase = 5;
    res->tags = { Leader, Dryad };
    res->faction = Scoiatael;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronzeOrSilver, ::isSpecial}, AllyDiscard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}

Card *Cards::createFilavandrel()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createFilavandrel, this);

    res->id = "201589";
    res->power = res->powerBase = 4;
    res->tags = { Leader, Elf };
    res->faction = Scoiatael;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        startChoiceCreateOptions(self, {isSilver, ::isSpecial});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        game.spawnNewCard(target, self);
    };
    return res;
}

Card *Cards::createFrancescaFindabair()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createFrancescaFindabair, this);

    res->id = "200165";
    res->power = res->powerBase = 7;
    res->tags = { Leader, Mage, Elf };
    res->faction = Scoiatael;
    res->rarity = Gold;

    struct State : StateCopy<State> { Card *_cardToSwap = nullptr; };
    res->state = new State();

    res->_onDeploy = [](Card *self, IGame &game) {
        self->stateAs<State>()->_cardToSwap = nullptr;
        game.startChoiceToTargetCard(self, {}, AllyHand);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        Card *&cardToSwap = self->stateAs<State>()->_cardToSwap;
        if (cardToSwap == nullptr) {
            cardToSwap = target;
            game.startChoiceToTargetCard(self, {}, AllyDeckShuffled);
            return;
        }
        putToDeck(cardToSwap, DeckPosRandom, self);
        putToHand(target,  self);
        game.boost(target, 3, self);
    };
    return res;
}

Card *Cards::createAglais()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAglais, this);

    res->id = "142106";
    res->power = res->powerBase = 8;
    res->tags = { Dryad };
    res->faction = Scoiatael;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronzeOrSilver, ::isSpecial}, EnemyDiscard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
        banish(target, self);
    };
    return res;
}

Card *Cards::createIorveth()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createIorveth, this);

    res->id = "142103";
    res->power = res->powerBase = 6;
    res->tags = { Elf, Officer };
    res->faction = Scoiatael;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        if (game.damage(target, 8, self))
            for (Card *card : cardsFiltered({isUnit, hasTag(Elf)}, AllyHand))
                game.boost(card, 1, self);
    };
    return res;
}

Card *Cards::createIorvethMeditation()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createIorvethMeditation, this);

    res->id = "201611";
    res->power = res->powerBase = 2;
    res->tags = { Elf, Officer };
    res->faction = Scoiatael;
    res->rarity = Gold;
    res->state = new StateChoosen();

    res->_onDeploy = [](Card *self, IGame &game) {
        // TODO: check for new choices system and overall tests required
        std::vector<Card *>cards;
        for (const int _screenRow : std::vector<int>{3, 4, 5}) {
            std::vector<Card *> rowCards = cardsInRow(_screenRow);
            if (rowCards.size() >= 2)
                cards.insert(cards.end(), rowCards.begin(), rowCards.end());
        }
        if (cards.size() <= 0)
            return;
        game.startChoiceToTargetCard(self, cards);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        Card *&choosen = self->stateAs<StateChoosen>()->_choosen;
        if (choosen == nullptr) {
            choosen = target;
            const int screenRow = _findScreenRow(target, ally, enemy);
            std::vector<Card *>cards = cardsInRow(screenRow);
            for (int i = 0; i < int(cards.size()); i++)
                if (cards[i] == choosen)
                    cards.erase(cards.begin() + i);
            game.startChoiceToTargetCard(self, cards);
            return;
        }
        duel(choosen, target, ally, enemy);
    };
    return res;
}

Card *Cards::createIsengrimFaoiltiarna()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createIsengrimFaoiltiarna, this);

    res->id = "142102";
    res->power = res->powerBase = 7;
    res->tags = { Elf, Officer };
    res->faction = Scoiatael;
    res->rarity = Gold;

    const auto isCardAmbush = [](Card *card) {
        return card->defaultCopy()->isAmbush;
    };

    res->_onDeploy = [isCardAmbush](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronzeOrSilver, isCardAmbush}, AllyDeckShuffled);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}

Card *Cards::createIsengrimOutlaw()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createIsengrimOutlaw, this);

    res->id = "201615";
    res->power = res->powerBase = 2;
    res->tags = { Elf, Officer };
    res->faction = Scoiatael;
    res->rarity = Gold;
    res->state = new StateChoosen();

    enum { Create, Play };
    res->_onDeploy = [](Card *self, IGame &game) {
        auto *option1 = createOption(self, Create);
        option1->text = "Create a Silver Elf.";

        auto *option2 = createOption(self, Play);
        option2->text = "Play a Bronze or Silver special self from your deck.";

        self->stateAs<StateChoosen>()->_choosen = nullptr;
        game.startChoiceToSelectOption(self, {option1, option2});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        Card *&choosen = self->stateAs<StateChoosen>()->_choosen;
        if (!choosen && isOption(target, Create)) {
            choosen = target;
            startChoiceCreateOptions(self, {isSilver, hasTag(Elf)});
            return;
        }
        if (!choosen && isOption(target, Play)) {
            choosen = target;
            game.startChoiceToTargetCard(self, {isBronzeOrSilver, ::isSpecial}, AllyDeckShuffled);
            return;
        }

        if (isOption(choosen, Create)) {
            delete choosen;
            choosen = nullptr;
            game.spawnNewCard(target, self);
        }
        return;
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        Card *&choosen = self->stateAs<StateChoosen>()->_choosen;
        if (!isOption(choosen, Create))
            throw Error(Error::Assert, self);

        delete choosen;
        choosen = nullptr;
        game.spawnNewCard(target, self);
    };
    return res;
}

Card *Cards::createIthlinneAegli()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createIthlinneAegli, this);

    res->id = "142107";
    res->power = res->powerBase = 2;
    res->tags = { Elf, Mage };
    res->faction = Scoiatael;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronze, hasAnyOfTags({Boon, Hazard, Spell})}, AllyDeckShuffled);
    };
    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
        game.playExistedCard(target, self);
    };
    return res;
}

Card *Cards::createSchirru()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSchirru, this);

    res->id = "142108";
    res->power = res->powerBase = 4;
    res->tags = { Elf, Soldier };
    res->faction = Scoiatael;
    res->rarity = Gold;

    res->_onDeploy = [=](Card *self, IGame &game) {
        game.startChoiceToSelectOption(self, {createScorch(), createEpidemic()});
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.spawnNewCard(target, self);
    };

    return res;
}

Card *Cards::createSaesenthessis()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSaesenthessis, this);

    res->id = "142108";
    res->power = res->powerBase = 10;
    res->tags = { Aedirn, Draconid };
    res->faction = Scoiatael;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        if (const int dwarfsCount = cardsFiltered({hasTag(Dwarf)}, AllyBoard).size() > 0)
            game.boost(self, dwarfsCount, self);
        if (const int elfsCount = cardsFiltered({hasTag(Elf)}, AllyBoard).size() > 0)
            game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        if (const int elfsCount = cardsFiltered({hasTag(Elf)}, AllyBoard).size() > 0)
            game.damage(target, elfsCount, self);
    };
    return res;
}

Card *Cards::createSaskia()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSaskia, this);

    res->id = "200209";
    res->power = res->powerBase = 11;
    res->tags = { Aedirn, Draconid };
    res->faction = Scoiatael;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronze}, AllyHand, 2, true);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        Card *newBronze = nullptr;
        if (!(newBronze = first(cardsFiltered({isBronze}, AllyDeck))))
            return;
        putToHand(newBronze,  self);
        putToDeck(target, DeckPosRandomButNotFirst, self);
    };
    return res;
}

Card *Cards::createBarclayEls()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createBarclayEls, this);

    res->id = "142207";
    res->power = res->powerBase = 2;
    res->tags = { Dwarf, Officer };
    res->faction = Scoiatael;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        if (Card *self = random(cardsFiltered({isBronzeOrSilver, isUnit, hasTag(Dwarf)}, AllyDeck), ally.rng)) {
            strengthen(self, 3, self);
            game.playExistedCard(self, self);
        }
    };
    return res;
}

Card *Cards::createDennisCranmer()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDennisCranmer, this);

    res->id = "142211";
    res->power = res->powerBase = 8;
    res->tags = { Dwarf, Officer };
    res->faction = Scoiatael;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        for (Card *card : cardsFiltered({hasTag(Dwarf), otherThan(self), isUnit}, AllyBoardHandDeck))
            strengthen(card, 1, self);
    };
    return res;
}

Card *Cards::createSheldonSkaggs()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSheldonSkaggs, this);

    res->id = "142212";
    res->power = res->powerBase = 9;
    res->tags = { Dwarf, Officer };
    res->faction = Scoiatael;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        int boostAmount = 0;
        const int screenRow = _findScreenRow(self, ally, enemy);
        const std::vector<Card *> cards = cardsInRow(screenRow);
        for (Card *card : cards)
            if (card != self)
                if (moveToRandomRow(card, self))
                    boostAmount++;
        if (boostAmount > 0)
            game.boost(self, boostAmount, self);
    };
    return res;
}

Card *Cards::createYarpenZigrin()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createYarpenZigrin, this);

    res->id = "142213";
    res->power = res->powerBase = 8;
    res->tags = { Dwarf, Soldier };
    res->faction = Scoiatael;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, Field &, Field &) {
        self->isResilient = true;
    };

    res->_onOtherAllyAppears = [](Card *self, Card *target, IGame &game) {
        if (!isOnBoard(self, ally) || !hasTag(target, Dwarf))
            return;
        game.boost(target, 1, self);
    };
    return res;
}

Card *Cards::createYaevinn()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createYaevinn, this);

    res->id = "142203";
    res->power = res->powerBase = 13;
    res->tags = { Elf };
    res->isLoyal = false;
    res->faction = Scoiatael;
    res->rarity = Silver;

    struct State : StateCopy<State> { std::vector<Card *> _drawn; };
    res->state = new State();

    res->_onDeploy = [](Card *self, IGame &game) {
        if (!tick(self, ally, enemy))
            return;

        Card *unit = first(cardsFiltered({isUnit}, AllyDeck));
        Card *special = first(cardsFiltered({::isSpecial}, AllyDeck));
        if (unit) {
            putToHand(unit,  self);
        }
        if (special) {
            putToHand(special,  self);
        }
        if (!unit || !special)
            return;

        std::vector<Card *> &drawn = self->stateAs<State>()->_drawn;
        drawn.push_back(unit);
        drawn.push_back(special);
        game.startChoiceToTargetCard(self, drawn);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        std::vector<Card *> &drawn = self->stateAs<State>()->_drawn;
        for (Card *self : drawn)
            if (self != target)
                putToDeck(self, DeckPosRandom, self);
        drawn.clear();
    };
    return res;
}

Card *Cards::createIdaEmeanAepSivney()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createIdaEmeanAepSivney, this);

    res->id = "142202";
    res->power = res->powerBase = 4;
    res->tags = { Elf, Mage };
    res->faction = Scoiatael;
    res->rarity = Silver;

    res->_onDeploy = [=](Card *self, IGame &game) {
        game.startChoiceToSelectOption(self, {createImpenetrableFog(), createClearSkies(), createAlzursThunder()});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        game.spawnNewCard(target, self);
    };
    return res;
}

Card *Cards::createPavkoGale()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createPavkoGale, this);

    res->id = "201676";
    res->power = res->powerBase = 5;
    res->tags = { Soldier };
    res->faction = Scoiatael;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronzeOrSilver, hasTag(Item)}, AllyDeckShuffled);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}

Card *Cards::createCiaranAepEasnillen()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createCiaranAepEasnillen, this);

    res->id = "142206";
    res->power = res->powerBase = 9;
    res->tags = { Elf, Soldier };
    res->faction = Scoiatael;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {otherThan(self)}, AnyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        // TODO: fix the in-same-line moving issue (DwarvenMercenary has the same)
        toggleLock(target, self);
        const Row row = _findRowAndPos(self, ally).row();
        if (isOnBoard(target, ally) && _findRowAndPos(target, ally).row() != row) {
            moveExistedUnitToPos(target, rowAndPosLastInExactRow(ally, row), self);
            return;
        }
        if (isOnBoard(target, enemy) && _findRowAndPos(target, ally).row() != row) {
            moveExistedUnitToPos(target, rowAndPosLastInExactRow(enemy, row), enemy, ally, self);
            return;
        }
    };
    return res;
}

Card *Cards::createEibhearHattori()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createEibhearHattori, this);

    res->id = "200520";
    res->power = res->powerBase = 3;
    res->tags = { Elf, Support };
    res->isDoomed = true;
    res->faction = Scoiatael;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronzeOrSilver, isUnit, isFaction(Scoiatael), hasPowerXorLess(self->power)}, AllyDiscard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}


Card *Cards::createMilaen()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMilaen, this);

    res->id = "200030";
    res->power = res->powerBase = 4;
    res->tags = { Elf };
    res->faction = Scoiatael;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        startChoiceToSelectRow(self);
    };

    res->_onTargetRowChoosen = [](Card *self, IGame &game, const int screenRow) {
        std::vector<Card *> cards = cardsInRow(screenRow);
        if (cards.size() <= 0)
            return;
        Card *first;
        game.damage(first = cards[0], 6, self);
        if (cards[cards.size()] != first)
            game.damage(cards[cards.size()], 6, self);
    };
    return res;
}

Card *Cards::createBraenn()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createBraenn, this);

    res->id = "142209";
    res->power = res->powerBase = 6;
    res->tags = { Dryad };
    res->faction = Scoiatael;
    res->rarity = Silver;

    const auto isCardOk = [](Card *self) {
        return hasTag(self, Dryad) || self->defaultCopy()->isAmbush;
        // || (self->defaultCopy()->isAmbush && !isOnBoard(self, ally)); // don't know how to get '&ally' here
        // TODO: check how does the Braenn buff allies in Ambush on board
    };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AnyBoard);
    };

    res->_onTargetChoosen = [isCardOk](Card *self, Card *target, IGame &game) {
        if (game.damage(target, self->power, self))
            for (Card *self : cardsFiltered({isCardOk}, AllyBoardHandDeck))
                game.boost(self, 1, self);
    };
    return res;
}

Card *Cards::createMorenn()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMorenn, this);

    res->id = "142208";
    res->power = res->powerBase = 8;
    res->tags = { Dryad };
    res->isAmbush = true;
    res->faction = Scoiatael;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, Field &, Field &) {
        self->isAmbush = true;
    };

    res->_onOtherEnemyAppears = [](Card *self, Card *target, IGame &game) {
        // TODO: check how should it works with cases like resurrect, spawn, summon
        // maybe have to replace onOtherEnemyAppears call
        if (!isOnBoard(self, ally) || !self->isAmbush)
            return;
        flipOver(self, ally, enemy);
        damage (target, 7, self);
    };

    res->_onOtherSpyAppears = [](Card *self, Card *target, IGame &game) {
        if (!isOnBoard(target, enemy))
            return;
        self->onOtherEnemyAppears(target, ally, enemy);
    };
    return res;
}

Card *Cards::createPaulieDahlberg()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createPaulieDahlberg, this);

    res->id = "201696";
    res->power = res->powerBase = 3;
    res->tags = { Dwarf, Support };
    res->isDoomed = true;
    res->faction = Scoiatael;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronze, isUnit, hasTag(Dwarf), hasNoTag(Support)}, AllyDiscard);
    };

    res->_onTargetChoosen = [](Card *self, Card * target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}

Card *Cards::createMahakamHorn()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMahakamHorn, this);

    res->id = "201653";
    res->isSpecial = true;
    res->tags = { Item };
    res->faction = Scoiatael;
    res->rarity = Silver;
    res->state = new StateChoosen();

    enum { Create, Strengthen };
    res->_onPlaySpecial = [](Card *self, IGame &game) {
        auto *option1 = createOption(self, Create);
        option1->text = "Create a Bronze or Silver Dwarf.";

        auto *option2 = createOption(self, Strengthen);
        option2->text = "Strengthen a unit by 7.";

        self->stateAs<StateChoosen>()->_choosen = nullptr;
        game.startChoiceToSelectOption(self, {option1, option2});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        Card *&choosen = self->stateAs<StateChoosen>()->_choosen;
        if (!choosen && isOption(target, Create)) {
            choosen = target;
            startChoiceCreateOptions(self, {isBronzeOrSilver, hasTag(Dwarf)});
            return;
        }

        if (!choosen && isOption(target, Strengthen)) {
            choosen = target;
            game.startChoiceToTargetCard(self, {}, AnyBoard);
            return;
        }

        if (isOption(choosen, Create)) {
            game.spawnNewCard(target, self);
            delete choosen;
            choosen = nullptr;
            return;
        }

        throw Error(Error::Unreachable, self);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        Card *&choosen = self->stateAs<StateChoosen>()->_choosen;
        if (!isOption(choosen, Strengthen))
            throw Error(Error::Assert, self);

        strengthen(target, 7, self);

        delete choosen;
        choosen = nullptr;
    };
    return res;
}

Card *Cards::createNaturesGift()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createNaturesGift, this);

    res->id = "143201";
    res->isSpecial = true;
    res->tags = { Spell };
    res->faction = Scoiatael;
    res->rarity = Silver;

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronzeOrSilver, ::isSpecial}, AllyDeckShuffled);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}

Card *Cards::createPitTrap()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createPitTrap, this);

    res->id = "200228";
    res->isSpecial = true;
    res->tags = { Item };
    res->faction = Scoiatael;
    res->rarity = Silver;

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        startChoiceToSelectRow(self, { 3, 4, 5 });
    };

    res->_onTargetRowChoosen = [](Card *self, IGame &game, const int screenRow) {
        applyRowEffect(screenRow, PitTrapEffect);
    };
    return res;
}

Card *Cards::createCrushingTrap()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createCrushingTrap, this);

    res->id = "201645";
    res->isSpecial = true;
    res->tags = { Item };
    res->faction = Scoiatael;
    res->rarity = Bronze;

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        startChoiceToSelectRow(self);
    };

    res->_onTargetRowChoosen = [](Card *self, IGame &game, const int screenRow) {
        std::vector<Card *> cards = cardsInRow(screenRow);
        if (cards.size() <= 0)
            return;
        Card *first;
        game.damage(first = cards[0], 6, self);
        if (cards[cards.size()] != first)
            game.damage(cards[cards.size()], 6, self);
    };
    return res;
}

Card *Cards::createElvenBlade()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createElvenBlade, this);

    res->id = "201643";
    res->isSpecial = true;
    res->tags = { Item };
    res->faction = Scoiatael;
    res->rarity = Bronze;

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {hasNoTag(Elf)}, AnyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.damage(target, 10, self);
    };
    return res;
}

Card *Cards::createIncineratingTrap()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createIncineratingTrap, this);

    res->id = "143301";
    res->power = res->powerBase = 1;
    res->tags = { Machine };
    res->isDoomed = true;
    res->isLoyal = false;
    res->faction = Scoiatael;
    res->rarity = Bronze;

    res->_onTurnEnd = [](Card *self, IGame &game) {
        if (!isOnBoard(self, enemy))
            return;
        for (Card *card : cardsInRow(_findScreenRow(self, ally, enemy)))
            if (card != self)
                game.damage(card, 2, self);
        banish(self, self);
    };
    return res;
}

Card *Cards::createBlueMountainElite()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createBlueMountainElite, this);

    res->id = "142316";
    res->power = res->powerBase = 3;
    res->tags = { Elf, Soldier };
    res->faction = Scoiatael;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        for (Card *copy : cardsFiltered({isCopy(self->name)}, AllyDeck))
            moveExistedUnitToPos(copy, _findRowAndPos(self, ally), self);
    };

    res->_onMoveFromRowToRow = [](Card *self, IGame &game) {
        game.boost(self, 2, self);
    };
    return res;
}

Card *Cards::createDolBlathannaBomber()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDolBlathannaBomber, this);

    res->id = "142316";
    res->power = res->powerBase = 6;
    res->tags = { Elf, Soldier };
    res->faction = Scoiatael;
    res->rarity = Bronze;

    res->_onDeploy = [=](Card *self, IGame &game) {
        game.spawnNewCard(createIncineratingTrap(), self);
    };
    return res;
}

Card *Cards::createDolBlathannaBowman()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDolBlathannaBowman, this);

    res->id = "142314";
    res->power = res->powerBase = 7;
    res->tags = { Elf, Soldier };
    res->faction = Scoiatael;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.damage(target, 2, self);
    };

    res->_onMoveFromRowToRow = [](Card *self, IGame &game) {
        game.damage(random(cardsFiltered({}, EnemyBoard), ally.rng), 2, self);
    };

    res->_onEnemyMoved = [](Card *self, Card *target, IGame &game) {
        if (!isOnBoard(self, ally))
            return;
        game.damage(target, 2, self);
    };
    return res;
}

Card *Cards::createDolBlathannaSentry()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDolBlathannaSentry, this);

    res->id = "200039";
    res->power = res->powerBase = 2;
    res->tags = { Elf, Soldier };
    res->faction = Scoiatael;
    res->rarity = Bronze;

    res->_onSpecialPlayed = [](Card *self, Card *target, IGame &game) {
        if(!isOnBoard(self, ally) && !isIn(self, ally.deck) && !isIn(self, ally.hand))
            return;
        if (!target->isSpecial || !(isIn(target, ally.discard) || isIn(target, ally.hand)))
            //(target != ally.cardsAppeared.end()) ??
            return;
        game.boost(self, 1, self);
    };
    return res;
}

Card *Cards::createElvenScout()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createElvenScout, this);

    res->id = "201638";
    res->power = res->powerBase = 10;
    res->tags = { Elf, Soldier };
    res->faction = Scoiatael;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AllyHand);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.swapACard(target, self);
    };
    return res;
}

Card *Cards::createElvenSwordmaster()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createElvenSwordmaster, this);

    res->id = "200535";
    res->power = res->powerBase = 5;
    res->tags = { Elf, Soldier };
    res->faction = Scoiatael;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.damage(target, self->power, self);
    };
    return res;
}

Card *Cards::createDwarvenAgitator()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDwarvenAgitator, this);

    res->id = "200293";
    res->power = res->powerBase = 1;
    res->tags = { Dwarf, Support };
    res->faction = Scoiatael;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        if (Card *card = random(cardsFiltered({isBronze, hasTag(Dwarf), isNotCopy(self->id)}, AllyDeck), ally.rng))
            game.spawnNewCard(card->defaultCopy(), self);
    };
    return res;
}

Card *Cards::createDwarvenMercenary()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDwarvenMercenary, this);

    res->id = "142311";
    res->power = res->powerBase = 8;
    res->tags = { Dwarf, Soldier };
    res->faction = Scoiatael;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        // NOTE: check if otherThan(self) required
        // TODO: fix ability, wrong filters
        game.startChoiceToTargetCard(self, {otherThan(self)}, AnyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        // TODO: fix the in-same-line moving issue (CiaranAepEasnillen has the same)
        const Row row = _findRowAndPos(self, ally).row();
        if (isOnBoard(target, ally)) {
            game.boost(target, 3, self);
            // TODO: check if it's check really needed, and can `moveExistedUnitToPos` work with both fields?
            if (_findRowAndPos(target, ally).row() != row)
                moveExistedUnitToPos(target, rowAndPosLastInExactRow(ally, row), self);
            return;
        }
        if (isOnBoard(target, enemy) && _findRowAndPos(target, ally).row() != row) {
            moveExistedUnitToPos(target, rowAndPosLastInExactRow(enemy, row), enemy, ally, self);
            return;
        }
    };
    return res;
}

Card *Cards::createDwarvenSkirmisher()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createDwarvenSkirmisher, this);

    res->id = "142305";
    res->power = res->powerBase = 6;
    res->tags = { Dwarf, Soldier };
    res->faction = Scoiatael;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        if (!game.damage(target, 3, self))
            game.boost(self, 3, self);
    };
    return res;
}

Card *Cards::createHawkerHealer()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createHawkerHealer, this);

    res->id = "142301";
    res->power = res->powerBase = 5;
    res->tags = { Elf, Support };
    res->faction = Scoiatael;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AllyBoard, 2);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.boost(target, 3, self);
    };
    return res;
}

Card *Cards::createHawkerSupport()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createHawkerSupport, this);

    res->id = "142312";
    res->power = res->powerBase = 7;
    res->tags = { Elf, Support };
    res->faction = Scoiatael;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AllyHand);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.boost(target, 3, self);
    };
    return res;
}

Card *Cards::createMahakamDefender()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMahakamDefender, this);

    res->id = "142306";
    res->power = res->powerBase = 6;
    res->tags = { Dwarf, Soldier };
    res->faction = Scoiatael;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game){
        game.toggleResilient(self, self);
    };
    return res;
}

Card *Cards::createMahakamGuard()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMahakamGuard, this);

    res->id = "142317";
    res->power = res->powerBase = 4;
    res->tags = { Dwarf, Soldier };
    res->faction = Scoiatael;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AllyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.boost(target, 7, self);
    };
    return res;
}

Card *Cards::createMahakamVolunteers()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMahakamVolunteers, this);

    res->id = "201559";
    res->power = res->powerBase = 3;
    res->tags = { Dwarf, Soldier };
    res->faction = Scoiatael;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        for (Card *copy : cardsFiltered({isCopy(self->name)}, AllyDeck))
            moveExistedUnitToPos(copy, _findRowAndPos(self, ally), self);
    };
    return res;
}

Card *Cards::createPyrotechnician()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createPyrotechnician, this);

    res->id = "200135";
    res->power = res->powerBase = 5;
    res->tags = { Dwarf, Soldier };
    res->faction = Scoiatael;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        for (const Row row : std::vector<Row>{Meele, Range, Seige})
            if (Card *card = random(enemy.row(row), enemy.rng))
                game.damage(card, 3, self);
    };

    return res;
}

Card *Cards::createWardancer()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createWardancer, this);

    res->id = "142313";
    res->power = res->powerBase = 3;
    res->tags = { Elf, Soldier };
    res->faction = Scoiatael;
    res->rarity = Bronze;

    res->_onSwap = [](Card *self, IGame &game) {
        moveExistedUnitToPos(self, rowAndPosRandom(ally), self);
    };
    return res;
}

Card *Cards::createVriheddVanguard()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createVriheddVanguard, this);

    res->id = "142309";
    res->power = res->powerBase = 6;
    res->tags = { Elf, Soldier };
    res->faction = Scoiatael;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, Field &ally, Field & enemy) {
        for (Card *card : cardsFiltered({hasTag(Elf)}, AllyBoard))
            game.boost(card, 1, self);
    };

    res->_onSwap = [](Card *self, IGame &game) {
        self->onDeploy(ally, enemy);
    };
    return res;
}

Card *Cards::createVriheddOfficer()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createVriheddOfficer, this);

    res->id = "142303";
    res->power = res->powerBase = 5;
    res->tags = { Elf, Officer };
    res->faction = Scoiatael;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AllyHand);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.boost(self, target->powerBase, self);
        game.swapACard(target, self);
    };
    return res;
}

Card *Cards::createVriheddNeophyte()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createVriheddNeophyte, this);

    res->id = "142301";
    res->power = res->powerBase = 10;
    res->tags = { Elf, Soldier };
    res->faction = Scoiatael;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, Field &ally, Field & enemy) {
        for (Card *card : randoms(cardsFiltered({}, AllyHand), 2, ally.rng))
            game.boost(card, 1, self);
    };
    return res;
}

Card *Cards::createVriheddBrigade()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createVriheddBrigade, this);

    res->id = "142302";
    res->power = res->powerBase = 9;
    res->tags = { Elf, Soldier };
    res->faction = Scoiatael;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, Field &ally, Field & enemy) {
        clearHazardsFromItsRow(self, ally);
        game.startChoiceToTargetCard(self, {}, AnyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        // TODO: fix the in-same-line moving issue (CiaranAepEasnillen and DwarvenMecenary has the same)
        const Row row = _findRowAndPos(self, ally).row();
        if (isOnBoard(target, ally) && _findRowAndPos(target, ally).row() != row) {
            moveExistedUnitToPos(target, rowAndPosLastInExactRow(ally, row), self);
            return;
        }
        if (isOnBoard(target, enemy) && _findRowAndPos(target, ally).row() != row) {
            moveExistedUnitToPos(target, rowAndPosLastInExactRow(enemy, row), enemy, ally, self);
            return;
        }
    };
    return res;
}

Card *Cards::createHawkerSmuggler()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createHawkerSmuggler, this);

    res->id = "142315";
    res->power = res->powerBase = 7;
    res->tags = { Elf, Support };
    res->faction = Scoiatael;
    res->rarity = Bronze;

    res->_onOtherEnemyAppears = [](Card *self, Card *, IGame &game) {
        // TODO: check how should it works with cases like resurrect, spawn, summon
        // maybe have to replace onOtherEnemyAppears call
        if (!isOnBoard(self, ally))
            return;
        game.boost(self, 1, self);
    };
    return res;
}

Card *Cards::createMennoCoehoorn()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMennoCoehoorn, this);

    res->id = "162102";
    res->power = res->powerBase = 8;
    res->tags = { Officer };
    res->faction = Nilfgaard;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, Field &ally, Field & enemy) {
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        if (target->isSpy == false)
            return putToDiscard(target, self);
        game.damage(target, 4, self);
    };
    return res;
}

Card *Cards::createRainfarnOfAttre()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createRainfarnOfAttre, this);

    res->id = "200032";
    res->power = res->powerBase = 5;
    res->tags = { Officer };
    res->faction = Nilfgaard;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, Field &ally, Field & enemy) {
        game.startChoiceToTargetCard(self, {isSpying, isBronzeOrSilver}, AllyDeckShuffled);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}

Card *Cards::createAssassination()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAssassination, this);

    res->id = "163101";
    res->isSpecial = true;
    res->tags = { Tactics };
    res->faction = Nilfgaard;
    res->rarity = Gold;

    res->_onPlaySpecial = [](Card *self, Field &ally, Field & enemy) {
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.damage(target, 8, self);
    };

    return res;
}

Card *Cards::createStefanSkellen()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createStefanSkellen, this);

    res->id = "162106";
    res->power = res->powerBase = 10;
    res->tags = { Officer };
    res->faction = Nilfgaard;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AllyDeckShuffled);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        putToDeck(target, DeckPosTop, self);
        if (!target->isSpecial && !target->isSpy)
            game.boost(target, 5, self);
    };
    return res;
}

Card *Cards::createShilard()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createShilard, this);

    res->id = "200071";
    res->power = res->powerBase = 9;
    res->tags = { Officer };
    res->faction = Nilfgaard;
    res->rarity = Gold;

    struct State : StateCopy<State>
    {
        Card *_allyCard = nullptr;
        Card *_enemyCard = nullptr;
    };
    res->state = new State();

    res->_onDeploy = [](Card *self, IGame &game) {
        if (ally.passed || enemy.passed)
            return;
        std::vector<Card *> variants;
        Card *&allyCard = self->stateAs<State>()->_allyCard;
        Card *&enemyCard = self->stateAs<State>()->_enemyCard;
        if ((allyCard = first(cardsFiltered({}, AllyDeck))))
            variants.push_back(allyCard);
        if ((enemyCard = random(cardsFiltered({}, EnemyDeck), ally.rng)))
            variants.push_back(enemyCard);
        game.startChoiceToTargetCard(self, variants);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        putToHand(target, self);
        Card *allyCard = self->stateAs<State>()->_allyCard;
        Card *enemyCard = self->stateAs<State>()->_enemyCard;
        if (target == allyCard && enemyCard)
            putToHand(enemyCard, enemy, ally, self);
        else if (target == enemyCard && allyCard)
            putToHand(allyCard, enemy, ally, self);
    };
    return res;
}

Card *Cards::createXarthisius()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createXarthisius, this);

    res->id = "162108";
    res->power = res->powerBase = 13;
    res->tags = { Mage };
    res->faction = Nilfgaard;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, EnemyDeck);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        putToDeck(target, enemy, ally, DeckPosBottom, self);
    };
    return res;
}

Card *Cards::createCantarella()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createCantarella, this);

    res->id = "162108";
    res->power = res->powerBase = 13;
    res->tags = {};
    res->isLoyal = false;
    res->faction = Nilfgaard;
    res->rarity = Silver;

    struct State : StateCopy<State> { std::vector<Card *> _drawn; };
    res->state = new State();

    res->_onDeploy = [](Card *self, IGame &game) {
        if (tick(self, ally, enemy)) {
            Card *firstCard = first(cardsFiltered({}, AllyDeck));
            Card *secondCard = first(cardsFiltered({}, AllyDeck));
            if (firstCard) {
                putToHand(firstCard,  self);
            }
            if (secondCard) {
                putToHand(secondCard,  self);
            }
            if (!firstCard || !secondCard)
                return;
            std::vector<Card *> &drawn = self->stateAs<State>()->_drawn;
            drawn.push_back(firstCard);
            drawn.push_back(secondCard);
            game.startChoiceToTargetCard(self, drawn);
        }
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        std::vector<Card *> &drawn = self->stateAs<State>()->_drawn;
        for (Card *card : drawn)
            if (card != target)
                putToDeck(card, DeckPosBottom, self);
        drawn.clear();
    };
    return res;
}

Card *Cards::createPanther()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createPanther, this);

    res->id = "200139";
    res->power = res->powerBase = 4;
    res->tags = { Beast };
    res->faction = Scoiatael;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        const Field *enemyPtr = &enemy;
        const auto isOk = [enemyPtr](Card *self) {
            const Row row = _findRowAndPos(self, *enemyPtr).row();
            return enemyPtr->row(row).size() < 4;
        };
        game.startChoiceToTargetCard(self, {isOk}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.damage(target, 7, self);
    };
    return res;
}

Card *Cards::createVicovaroMedic()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createVicovaroMedic, this);

    res->id = "162304";
    res->power = res->powerBase = 1;
    res->tags = { Support };
    res->isDoomed = true;
    res->faction = Nilfgaard;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronze, isUnit}, EnemyDiscard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}

Card *Cards::createAssireVarAnahid()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAssireVarAnahid, this);

    res->id = "162202";
    res->power = res->powerBase = 11;
    res->tags = { Mage };
    res->faction = Nilfgaard;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronzeOrSilver}, AllyDiscard);
        game.startChoiceToTargetCard(self, {isBronzeOrSilver}, EnemyDiscard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        if (isIn(target, ally.discard)){
            putToDeck(target, DeckPosRandom, self);
            return;
        }
        if (isIn(target, enemy.discard)){
            putToDeck(target, enemy, ally, DeckPosRandom, self);
            return;
        }
        throw Error(Error::Unreachable, self);
    };
    return res;
}

Card *Cards::createFringillaVigo()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createFringillaVigo, this);

    res->id = "162205";
    res->power = res->powerBase = 1;
    res->isLoyal = false;
    res->tags = { Mage };
    res->faction = Nilfgaard;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        Card *left = cardNextTo(self, -1);
        Card *right = cardNextTo(self, 1);
        if (left != nullptr && right != nullptr)
            setPower(right, left->power, self);
    };
    return res;
}

Card *Cards::createFalseCiri()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createFalseCiri, this);

    res->id = "162212";
    res->power = res->powerBase = 8;
    res->isLoyal = false;
    res->faction = Nilfgaard;
    res->rarity = Silver;

    res->_onTurnStart = [](Card *self, IGame &game) {
        if (!self->isLoyal)
            game.boost(self, 1, self);
    };

    res->_onDestroy = [](Card *self, IGame &game, const RowAndPos &rowAndPos) {
        if (Card *self = lowest(cardsInRow(rowAndPos.row()), ally.rng))
            putToDiscard(self, self);
    };

    res->_onAllyPass = [](Card *self, IGame &game) {
        // NOTE: for spying creatures logic of this event is inverted
        // so an ally is an original enemy for FalseCiri
        if (self->isLoyal)
            return;
        const Row row = _findRowAndPos(self, ally).row();
        moveExistedUnitToPos(self, rowAndPosLastInExactRow(enemy, row), enemy, ally, self);
    };
    return res;
}

Card *Cards::createDandelion()
{
    Card *res = new Card();
    res->_constructor = std::bind(&Cards::createDandelion, this);

    res->id = "122201";
    res->power = res->powerBase = 11;
    res->tags = { Support };
    res->faction = NothernRealms;
    res->rarity = Gold;
    res->sounds = {
        "https://gwent.one/audio/self/ob/en/DAND_Q302_00490269.mp3",
        "https://gwent.one/audio/self/ob/en/DAND_DANDELION_00429307.mp3",
        "https://gwent.one/audio/self/ob/en/DAND_Q302_00489393.mp3",
        "https://gwent.one/audio/self/ob/en/VO_JSKR_100926_0188.mp3",
        "https://gwent.one/audio/self/ob/en/SAY.Battlecries.5.mp3",
        "https://gwent.one/audio/self/ob/en/SAY.Battlecries.6.mp3",
        "https://gwent.one/audio/self/ob/en/SAY.Battlecries.7.mp3",
    };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isUnit}, AllyDeckShuffled, 3, false);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.boost(target, 2, self);
    };
    return res;
}

Card *Cards::createKiyan()
{
    Card *res = new Card();
    res->_constructor = std::bind(&Cards::createKiyan, this);

    res->id = "201621";
    res->power = res->powerBase = 4;
    res->tags = { Cursed, Witcher };
    res->faction = NothernRealms;
    res->rarity = Gold;
    res->state = new StateChoosen();

    enum { Create, Play };
    res->_onDeploy = [](Card *self, IGame &game) {
        auto *option1 = createOption(self, Create);
        option1->text = "Create a Bronze or Silver Alchemy self.";

        auto *option2 = createOption(self, Play);
        option2->text = "Play a Bronze or Silver Item from your deck.";

        self->stateAs<StateChoosen>()->_choosen = nullptr;
        game.startChoiceToSelectOption(self, {option1, option2});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        Card *&_choosen = self->stateAs<StateChoosen>()->_choosen;
        if (!_choosen && isOption(target, Play)) {
            _choosen = target;
            return game.startChoiceToTargetCard(self, {isBronzeOrSilver, hasTag(Item)}, AllyDeckShuffled);
        }

        if (!_choosen && isOption(target, Create)) {
            _choosen = target;
            return startChoiceCreateOptions(self, {isBronzeOrSilver, hasTag(Alchemy)}, AnyCard);
        }

        if (isOption(_choosen, Create)) {
            game.spawnNewCard(target, self);
            delete _choosen;
            _choosen = nullptr;
            return;
        }

        throw Error(Error::Unreachable, self);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}

Card *Cards::createPhilippaEilhart()
{
    Card *res = new Card();
    res->_constructor = std::bind(&Cards::createPhilippaEilhart, this);

    res->id = "122104";
    res->power = res->powerBase = 1;
    res->tags = { Mage, Redania };
    res->faction = NothernRealms;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.damage(target, 5, self);

        for (int dmg = 4; dmg > 0; --dmg) {
            target = random(cardsFiltered({otherThan(target)}, EnemyBoard), ally.rng);
            if (!target)
                return;
            game.damage(target, dmg, self);
        }
    };
    return res;
}

Card *Cards::createRocheMerciless()
{
    Card *res = new Card();
    res->_constructor = std::bind(&Cards::createRocheMerciless, this);

    res->id = "201777";
    res->tags = { Temeria, Officer };
    res->power = res->powerBase = 6;
    res->faction = NothernRealms;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        // FIXME: test, because it won't work
        game.startChoiceToTargetCard(self, {isAmbushing}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        putToDiscard(target, self);
    };
    return res;
}

Card *Cards::createShani()
{
    Card *res = new Card();
    res->_constructor = std::bind(&Cards::createShani, this);

    res->id = "122106";
    res->tags = { Redania, Support };
    res->power = res->powerBase = 4;
    res->faction = NothernRealms;
    res->rarity = Gold;
    res->isDoomed = true;

    res->sounds = {
        "https://gwent.one/audio/self/ob/en/SHNI_SHANI_01130725.mp3",
        "https://gwent.one/audio/self/ob/en/SHNI_Q601_01101942.mp3",
        "https://gwent.one/audio/self/ob/en/SHNI_Q602_01119358.mp3",
    };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isUnit, isBronzeOrSilver, hasNoTag(Cursed),}, AllyDiscard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
        game.gainArmor(target, 2, self);
    };
    return res;
}

Card *Cards::createVandergrift()
{
    Card *res = new Card();
    res->_constructor = std::bind(&Cards::createVandergrift, this);

    res->id = "201620";
    res->tags = { Cursed, Kaedwen, Officer };
    res->power = res->powerBase = 7;
    res->faction = NothernRealms;
    res->rarity = Gold;

    res->_onDeploy = [](Card *self, IGame &game) {
        for (Card *self : cardsFiltered({}, EnemyBoard)) {
            if (game.damage(self, 1, self)) {
                const Row row = _findRowAndPos(self, enemy).row();
                applyRowEffect(toScreenRow(row, false), RaghNarRoogEffect);
            }
        }
    };
    return res;
}

Card *Cards::createBotchling()
{
    Card *res = new Card();
    res->_constructor = std::bind(&Cards::createBotchling, this);

    res->id = "122401";
    res->tags = { Cursed };
    res->power = res->powerBase = 10;
    res->faction = NothernRealms;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        // NOTE: 122402 is Lubberkin
        for (Card *lubberkin : cardsFiltered({isCopy("122402")}, AllyDeck))
            moveExistedUnitToPos(lubberkin, rowAndPosToTheRight(self, ally, 1), self);
    };
    return res;
}

Card *Cards::createLubberkin()
{
    Card *res = new Card();
    res->_constructor = std::bind(&Cards::createLubberkin, this);

    res->id = "122402";
    res->tags = { Cursed };
    res->power = res->powerBase = 5;
    res->faction = NothernRealms;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        // NOTE: 122401 is Botchling
        for (Card *botchling : cardsFiltered({isCopy("122401")}, AllyDeck))
            moveExistedUnitToPos(botchling, rowAndPosToTheLeft(self, ally, 1), self);
    };
    return res;
}

Card *Cards::createNilfgaardianGate()
{
    Card *res = new Card();
    res->_constructor = std::bind(&Cards::createNilfgaardianGate, this);

    res->id = "201699";
    res->tags = { Tactics };
    res->isSpecial = true;
    res->faction = Nilfgaard;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {hasTag(Officer), isBronzeOrSilver}, AllyDeckShuffled);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.boost(target, 1, self);
        game.playExistedCard(target, self);
    };
    return res;
}

Card *Cards::createPeterSaarGwynleve()
{
    Card *res = new Card();
    res->_constructor = std::bind(&Cards::createPeterSaarGwynleve, this);

    res->id = "162204";
    res->tags = { Officer };
    res->power = res->powerBase = 6;
    res->faction = Nilfgaard;
    res->rarity = Silver;
    res->sounds = {
        "https://gwent.one/audio/self/ob/en/SAY.Battlecries_part3.426.mp3",
        "https://gwent.one/audio/self/ob/en/SAY.Battlecries_part3.427.mp3",
        "https://gwent.one/audio/self/ob/en/SAY.Battlecries_part3.428.mp3",
    };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        reset(target, self);
        if (isOnBoard(target, ally))
            strengthen(target, 3, self);
        else if (isOnBoard(target, enemy))
            weaken(target, 3, self);
        else
            throw Error(Error::Unreachable, self);
    };
    return res;
}

Card *Cards::createVicovaroNovice()
{
    Card *res = new Card();
    res->_constructor = std::bind(&Cards::createVicovaroNovice, this);

    res->id = "122403";
    res->tags = { Mage };
    res->power = res->powerBase = 2;
    res->faction = Nilfgaard;
    res->rarity = Bronze;
    res->sounds = {
        "https://gwent.one/audio/self/ob/en/SAY.Battlecries.820.mp3",
        "https://gwent.one/audio/self/ob/en/SAY.Battlecries.821.mp3",
        "https://gwent.one/audio/self/ob/en/SAY.Battlecries.819.mp3",
    };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, randoms(cardsFiltered({isBronze, hasTag(Alchemy)}, AllyDeck), 2, ally.rng));
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}

Card *Cards::createCadaverine()
{
    Card *res = new Card();
    res->_constructor = std::bind(&Cards::createCadaverine, this);

    res->id = "201662";
    res->tags = { Alchemy, Item };
    res->isSpecial = true;
    res->faction = Nilfgaard;
    res->rarity = Silver;
    res->state = new StateChoosen();

    enum { DealDamage, Destroy };
    res->_onPlaySpecial = [](Card *self, IGame &game) {
        auto *option1 = createOption(self, DealDamage);
        option1->text = "Deal 2 damage to an enemy and all units that share its categories.";

        auto *option2 = createOption(self, Destroy);
        option2->text = "Destroy a Bronze or Silver Neutral unit.";

        self->stateAs<StateChoosen>()->_choosen = nullptr;
        game.startChoiceToSelectOption(self, {option1, option2});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        Card *&_choosen = self->stateAs<StateChoosen>()->_choosen;
        if (!_choosen && isOption(target, DealDamage)) {
            _choosen = target;
            game.startChoiceToTargetCard(self, {}, EnemyBoard);
            return;
        }

        if (!_choosen && isOption(target, Destroy)) {
            _choosen = target;
            game.startChoiceToTargetCard(self, {isBronzeOrSilver, isFaction(Neutral)}, AnyBoard);
            return;
        }

        throw Error(Error::Unreachable, self);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        Card *&choosen = self->stateAs<StateChoosen>()->_choosen;
        if (!choosen)
            throw Error(Error::ChoosenIsNullptr, self);

        if (isOption(choosen, DealDamage)) {
            for (Card *self : cardsFiltered({hasAnyOfTags(target->tags)}, EnemyBoard))
                game.damage(self, 2, self);
            delete choosen;
            choosen = nullptr;
            return;choosen;
        }

        if (isOption(choosen, Destroy)) {
            putToDiscard(target, self);
            choosen = nullptr;
            return;
        }

        throw Error(Error::Unreachable, self);
    };
    return res;
}

Card *Cards::createJoachimDeWett()
{
    Card *res = new Card();
    res->_constructor = std::bind(&Cards::createJoachimDeWett, this);

    res->id = "162211";
    res->tags = { Officer };
    res->power = res->powerBase = 5;
    res->faction = Nilfgaard;
    res->rarity = Silver;
    res->sounds = {
        "https://gwent.one/audio/self/ob/en/SAY.Battlecries_part3.19.mp3",
        "https://gwent.one/audio/self/ob/en/SAY.Battlecries_part3.18.mp3",
        "https://gwent.one/audio/self/ob/en/SAY.Battlecries_part3.17.mp3",
    };

    res->_onDeploy = [](Card *self, IGame &game) {
        if (Card* self = first(cardsFiltered({isBronzeOrSilver, isNonSpying, isUnit}, AllyDeck))) {
            game.boost(self, 10, self);
            game.playExistedCard(self, self);
        }
    };
    return res;
}

Card *Cards::createTreason()
{
    Card *res = new Card();
    res->_constructor = std::bind(&Cards::createTreason, this);

    res->id = "163201";
    res->tags = { Tactics };
    res->isSpecial = true;
    res->faction = Nilfgaard;
    res->rarity = Silver;
    res->state = new StateChoosen();

    res->_onPlaySpecial = [](Card *self, IGame &game) {
        std::vector<Card *> cardsToChoice;
        for(Card *self : cardsFiltered({}, EnemyBoard)) {
            if (!self->isAmbush) {
                Card *left = cardNextTo(self, -1);
                Card *right = cardNextTo(self, 1);
                if ((left != nullptr && !left->isAmbush) || (right != nullptr && !right->isAmbush))
                   cardsToChoice.push_back(self);
            }
        }
        game.startChoiceToTargetCard(self, cardsToChoice);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        Card *&_choosen = self->stateAs<StateChoosen>()->_choosen;
        if (_choosen == nullptr) {
            _choosen = target;
            std::vector<Card *> cards;
            if (Card *left = cardNextTo(target, -1))
                if(!left->isAmbush)
                    cards.push_back(left);
            if (Card *right = cardNextTo(target, 1))
                if(!right->isAmbush)
                    cards.push_back(right);
            if (!cards.size())
                throw Error(Error::Assert, self);
            game.startChoiceToTargetCard(self, cards);
            return;
        }
        duel(_choosen, target, ally, enemy);
    };
    return res;
}

Card *Cards::createVanhemar()
{
    Card *res = new Card();
    res->_constructor = std::bind(&Cards::createVanhemar, this);

    res->id = "162207";
    res->tags = { Mage };
    res->power = res->powerBase = 4;
    res->faction = Nilfgaard;
    res->rarity = Silver;
    res->sounds = {
        "https://gwent.one/audio/self/ob/en/VO_NM01_200057_0187.mp3",
        "https://gwent.one/audio/self/ob/en/VO_NM01_200996_0005.mp3",
        "https://gwent.one/audio/self/ob/en/VO_NM01_200049_0007.mp3",
    };

    res->_onDeploy = [=](Card *self, IGame &game) {
        game.startChoiceToSelectOption(self, {createBitingFrost(), createClearSkies(), createShrike()});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        game.spawnNewCard(target, self);
    };
    return res;
}

Card *Cards::createVrygheff()
{
    Card *res = new Card();
    res->_constructor = std::bind(&Cards::createVrygheff, this);

    res->id = "201664";
    res->tags = { Officer };
    res->power = res->powerBase = 5;
    res->faction = Nilfgaard;
    res->rarity = Silver;
    res->sounds = {
        "https://gwent.one/audio/self/ob/en/SAY.Battlecries_part4.256.mp3",
        "https://gwent.one/audio/self/ob/en/SAY.Battlecries_part4.255.mp3",
        "https://gwent.one/audio/self/ob/en/SAY.Battlecries_part4.253.mp3",
        "https://gwent.one/audio/self/ob/en/SAY.Battlecries_part4.254.mp3",
    };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronze, hasTag({Machine})}, AllyDeckShuffled);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}

Card *Cards::createAlbaPikeman()
{
    Card *res = new Card();
    res->_constructor = std::bind(&Cards::createAlbaPikeman, this);

    res->id = "162311";
    res->tags = { Soldier };
    res->power = res->powerBase = 3;
    res->faction = Nilfgaard;
    res->rarity = Bronze;
    res->sounds = {
        "https://gwent.one/audio/self/ob/en/NILF3_VSET_00514121.mp3",
        "https://gwent.one/audio/self/ob/en/NILF3_VSET_00514091.mp3",
        "https://gwent.one/audio/self/ob/en/NILF3_VSET_00514113.mp3",
    };

    res->_onDeploy = [](Card *self, IGame &game) {
        for (Card *copy : cardsFiltered({isCopy(self->id)}, AllyDeck))
            moveExistedUnitToPos(copy, _findRowAndPos(self, ally), self);
    };
    return res;
}

Card *Cards::createCombatEngineer()
{
    Card *res = new Card();
    res->_constructor = std::bind(&Cards::createCombatEngineer, this);

    res->id = "162313";
    res->tags = { Support };
    res->isCrew = true;
    res->power = res->powerBase = 6;
    res->faction = Nilfgaard;
    res->rarity = Bronze;
    res->sounds = {
        "https://gwent.one/audio/self/ob/en/NILF2_Q502_00556520.mp3",
        "https://gwent.one/audio/self/ob/en/NILF2_VSET_00513907.mp3",
        "https://gwent.one/audio/self/ob/en/NILF2_VSET_01072393.mp3",
    };

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AllyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.boost(target, 5, self);
    };
    return res;
}

Card *Cards::createMagneDivision()
{
    Card *res = new Card();
    res->_constructor = std::bind(&Cards::createMagneDivision, this);

    res->id = "200044";
    res->tags = { Soldier };
    res->power = res->powerBase = 3;
    res->faction = Nilfgaard;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        if (Card *card = random(cardsFiltered({isBronze, hasTag(Item)}, AllyDeck), ally.rng))
            game.playExistedCard(card, self);
    };
    return res;
}

Card *Cards::createNauzicaaBrigade()
{
    Card *res = new Card();
    res->_constructor = std::bind(&Cards::createNauzicaaBrigade, this);

    res->id = "162310";
    res->tags = { Soldier };
    res->power = res->powerBase = 5;
    res->faction = Nilfgaard;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isSpying}, AnyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        if (game.damage(target, 7, self))
            strengthen(self, 4, self);
    };
    return res;
}

Card *Cards::createSlaveDriver()
{
    Card *res = new Card();
    res->_constructor = std::bind(&Cards::createSlaveDriver, this);

    res->id = "201612";
    res->tags = { Officer };
    res->power = res->powerBase = 10;
    res->faction = Nilfgaard;
    res->rarity = Bronze;

    struct State : StateCopy<State> { int _lostPower = -1; };
    res->state = new State();

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AllyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        int &_lostPower = self->stateAs<State>()->_lostPower;
        if (_lostPower == -1) {
            _lostPower = target->power - 1;
            setPower(target, 1, self);
            if (_lostPower == 0)
                return;
            game.startChoiceToTargetCard(self, {}, EnemyBoard);
            return;
        }
        game.damage(target, _lostPower, self);
    };
    return res;
}

Card *Cards::createSlaveHunter()
{
    Card *res = new Card();
    res->_constructor = std::bind(&Cards::createSlaveHunter, this);

    res->id = "201609";
    res->tags = { Soldier };
    res->power = res->powerBase = 8;
    res->faction = Nilfgaard;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronze, hasPowerXorLess(3)}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        charm(target, self);
    };
    return res;
}

Card *Cards::createViperWitcher()
{
    Card *res = new Card();
    res->_constructor = std::bind(&Cards::createViperWitcher, this);

    res->id = "200124";
    res->tags = { Witcher };
    res->power = res->powerBase = 5;
    res->faction = Nilfgaard;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        if (cardsFiltered({hasTag(Alchemy)}, AllyDeckStarting).size() > 0)
            game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        const int dmg = cardsFiltered({hasTag(Alchemy)}, AllyDeckStarting).size();
        game.damage(target, dmg, self);
    };
    return res;
}

Card *Cards::createRotTosser()
{
    Card *res = new Card();
    res->_constructor = std::bind(&Cards::createRotTosser, this);

    res->id = "162302";
    res->tags = { Machine };
    res->power = res->powerBase = 8;
    res->faction = Nilfgaard;
    res->rarity = Bronze;

    res->_onDeploy = [=](Card *self, IGame &game) {
        game.spawnNewCard(createCowCarcass(), self);
    };
    return res;
}

Card *Cards::createCowCarcass()
{
    Card *res = new Card();
    res->_constructor = std::bind(&Cards::createCowCarcass, this);

    res->id = "162402";
    res->isDoomed = true;
    res->isLoyal = false;
    res->power = res->powerBase = 1;
    res->faction = Nilfgaard;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        setTimer(self, 2);
    };

    res->_onTurnEnd = [](Card *self, IGame &game) {
        if (!tick(self, ally, enemy))
            return;
        for (Card *self : lowests(cardsFiltered( {otherThan(self), isOnSameRow(&ally, self)}, AllyBoard)))
            putToDiscard(self, self);
        banish(self, self);
    };
    return res;
}

Card *Cards::createStandardBearer()
{
    Card *res = new Card();
    res->_constructor = std::bind(&Cards::createStandardBearer, this);

    res->id = "200294";
    res->tags = { Soldier };
    res->power = res->powerBase = 8;
    res->faction = Nilfgaard;
    res->rarity = Bronze;

    res->_onOtherAllyPlayedFromHand = [](Card *self, Card *target, IGame &game) {
        if (!isOnBoard(self, ally))
            return;
        if (hasTag(target, Soldier))
            game.boost(target, 2, self);
    };
    return res;
}

Card *Cards::createCursedKnight()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createCursedKnight, this);

    res->id = "201625";
    res->power = res->powerBase = 8;
    res->tags = { Cursed, Aedirn };
    res->faction = NothernRealms;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.gainArmor(self, 2, self);
        startChoiceCreateOptions(self, {hasTag(Cursed)}, AllyBoard);
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        transform(target, self->defaultCopy(), self);
        game.gainArmor(target, 2, target);
    };
    return res;
}

Card *Cards::createMargaritaOfAretuza()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createMargaritaOfAretuza, this);

    res->id = "122211";
    res->tags = { Temeria, Mage };
    res->power = res->powerBase = 6;
    res->faction = NothernRealms;
    res->rarity = Silver;

    res->_onDeploy = [=](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AnyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        reset(target, self);
        toggleLock(target, self);
    };
    return res;
}

Card *Cards::createNenneke()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createNenneke, this);

    res->id = "122212";
    res->tags = { Temeria, Support };
    res->power = res->powerBase = 10;
    res->faction = NothernRealms;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronzeOrSilver, isUnit}, AllyDiscard, 3);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        putToDeck(target, DeckPosRandom, self);
    };
    return res;
}

Card *Cards::createSabrinasSpecter()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSabrinasSpecter, this);

    res->id = "201650";
    res->tags = { Mage, Cursed };
    res->isDoomed = true;
    res->power = res->powerBase = 3;
    res->faction = NothernRealms;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {isBronze, hasTag(Cursed)}, AllyDiscard);
    };

    res->_onTargetChoosen = [=](Card *self, Card *target, IGame &game) {
        game.playExistedCard(target, self);
    };
    return res;
}

Card *Cards::createSabrinaGlevissig()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSabrinaGlevissig, this);

    res->id = "122206";
    res->tags = { Kaedwen, Mage };
    res->isLoyal = false;
    res->power = res->powerBase = 3;
    res->faction = NothernRealms;
    res->rarity = Silver;

    res->_onDestroy = [](Card *self, IGame &game, const RowAndPos &rowAndPos) {
        const std::vector<Card *> cards = ally.row(rowAndPos.row());
        const int power = lowest(cards, ally.rng)->power;
        for (Card *card : cards)
            setPower(card, power, self);
    };
    return res;
}

Card *Cards::createThaler()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createThaler, this);

    res->id = "122203";
    res->tags = { Temeria };
    res->isLoyal = false;
    res->timer = 1;
    res->power = res->powerBase = 13;
    res->faction = NothernRealms;
    res->rarity = Silver;

    res->_onDeploy = [](Card *self, IGame &game) {
        if (tick(self, ally, enemy))
            game.startChoiceToTargetCard(self, randoms(cardsFiltered({}, AllyDeck), 2, ally.rng));
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        putToHand(target,  self);
    };
    return res;
}

Card *Cards::createAedirnianMauler()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAedirnianMauler, this);

    res->id = "200540";
    res->tags = { Aedirn, Soldier };
    res->power = res->powerBase = 7;
    res->faction = NothernRealms;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        game.damage(target, 4, self);
    };
    return res;
}

Card *Cards::createAretuzaAdept()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createAretuzaAdept, this);

    res->id = "200033";
    res->tags = { Temeria, Mage };
    res->power = res->powerBase = 3;
    res->faction = NothernRealms;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        if (Card *card = random(cardsFiltered({isBronze, hasTag(Hazard)}, AllyDeck), ally.rng))
            game.playExistedCard(card, self);
    };
    return res;
}

Card *Cards::createVandergriftsBlade()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createVandergriftsBlade, this);

    res->id = "201648";
    res->tags = { Item };
    res->isSpecial = true;
    res->faction = NothernRealms;
    res->rarity = Silver;
    res->state = new StateChoosen();

    enum { Destroy, Damage };
    res->_onPlaySpecial = [](Card *self, IGame &game) {
        auto *option1 = createOption(self, Destroy);
        option1->text = "Destroy a Bronze or Silver Cursed enemy.";

        auto *option2 = createOption(self, Damage);
        option2->text = "Deal 9 damage and, if the unit was destroyed, Banish it.";

        self->stateAs<StateChoosen>()->_choosen = nullptr;
        game.startChoiceToSelectOption(self, {option1, option2});
    };

    res->_onOptionChoosen = [](Card *self, Card *target, IGame &game) {
        Card *&_choosen = self->stateAs<StateChoosen>()->_choosen;
        _choosen = target;
        if (isOption(_choosen, Destroy)) {
            game.startChoiceToTargetCard(self, {isBronzeOrSilver, hasTag(Cursed)}, EnemyBoard);
            return;
        }
        if (isOption(_choosen, Damage)) {
            game.startChoiceToTargetCard(self, {}, EnemyBoard);
            return;
        }
        throw Error(Error::Unreachable, self);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        Card *&choosen = self->stateAs<StateChoosen>()->_choosen;
        if (!choosen)
            throw Error(Error::ChoosenIsNullptr, self);

        if (isOption(choosen, Destroy)) {
            putToDiscard(target, self);

            delete choosen;
            choosen = nullptr;
            return;
        }

        if (isOption(choosen, Damage)) {
            if (game.damage(target, 9, self))
                banish(target, self);

            delete choosen;
            choosen = nullptr;
            return;
        }

        throw Error(Error::Unreachable, self);
    };
    return res;
}

Card *Cards::createReinforcedTrebuchet()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createReinforcedTrebuchet, this);

    res->id = "122315";
    res->tags = { Machine };
    res->power = res->powerBase = 8;
    res->faction = NothernRealms;
    res->rarity = Bronze;

    res->_onTurnEnd = [](Card *self, IGame &game) {
        if (!isOnBoard(self, ally))
            return;
        game.damage(random(cardsFiltered({}, EnemyBoard), ally.rng), 1, self);
    };
    return res;
}

Card *Cards::createBallista()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createBallista, this);

    res->id = "122301";
    res->tags = { Machine };
    res->power = res->powerBase = 6;
    res->faction = NothernRealms;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        int n = 1 + nCrewed(self, ally);
        while (n--)
            game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        std::vector<Card *> cards = randoms(cardsFiltered({hasPowerX(target->power), otherThan(target)}, EnemyBoard), 4, ally.rng);
        cards.push_back(target);
        for (Card *card : cards)
            game.damage(card, 1, self);
    };
    return res;
}

Card *Cards::createBloodyFlail()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createBloodyFlail, this);

    res->id = "201633";
    res->tags = { Item };
    res->isSpecial = true;
    res->faction = NothernRealms;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [this](Card *self, Card *target, IGame &game) {
        game.damage(target, 5, self);
        game.spawnNewUnitToPos(createSpecter(), rowAndPosRandom(ally), self);
    };
    return res;
}

Card *Cards::createSpecter()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createSpecter, this);

    // FIXME: missing picture
    res->id = "201633";
    res->tags = { Cursed };
    res->isDoomed = true;
    res->power = res->powerBase = 5;
    res->faction = NothernRealms;
    res->rarity = Bronze;

    return res;
}

Card *Cards::createBatteringRam()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createBatteringRam, this);

    res->id = "200049";
    res->tags = { Machine };
    res->power = res->powerBase = 6;
    res->faction = NothernRealms;
    res->rarity = Bronze;

    struct State : StateCopy<State> { bool _isFirstChoice = false; };
    res->state = new State();

    res->_onDeploy = [](Card *self, IGame &game) {
        self->stateAs<State>()->_isFirstChoice = true;
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        bool &_isFirstChoice = self->stateAs<State>()->_isFirstChoice;
        int x = 3 + _isFirstChoice * nCrewed(self, ally);
        if (game.damage(target, x, self) && _isFirstChoice) {
            _isFirstChoice = false;
            game.startChoiceToTargetCard(self, {}, EnemyBoard);
        }
    };

    return res;
}

Card *Cards::createTrebuchet()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createTrebuchet, this);

    res->id = "122303";
    res->tags = { Machine };
    res->power = res->powerBase = 7;
    res->faction = NothernRealms;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, EnemyBoard);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        int x = 1 + nCrewed(self, ally);
        Card *left = cardNextTo(target, -1);
        Card *right = cardNextTo(target, 1);
        for (Card *card : std::vector<Card *>{left, target, right})
            if (card != nullptr)
                game.damage(card, x, self);
    };
    return res;
}

Card *Cards::createBanArdTutor()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createBanArdTutor, this);

    res->id = "200048";
    res->tags = { Kaedwen, Mage };
    res->power = res->powerBase = 9;
    res->faction = NothernRealms;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        game.startChoiceToTargetCard(self, {}, AllyHand);
    };

    res->_onTargetChoosen = [](Card *self, Card *target, IGame &game) {
        putToDeck(target, DeckPosRandom, self);
        putToHand(first(cardsFiltered({isBronze, ::isSpecial}, AllyDeck)), self);
    };
    return res;
}

Card *Cards::createFieldMedic()
{
    auto *res = new Card();
    res->_constructor = std::bind(&Cards::createFieldMedic, this);

    res->id = "122312";
    res->tags = { Support };
    res->power = res->powerBase = 8;
    res->faction = NothernRealms;
    res->rarity = Bronze;

    res->_onDeploy = [](Card *self, IGame &game) {
        for (Card* card : cardsFiltered({hasTag(Soldier)}, AllyBoard))
            game.boost(card, 1, self);
    };
    return res;
}
