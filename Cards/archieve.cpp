#include "archieve.h"

#include <cassert>
#include <random>

#include "filters.h"

std::vector<Card *> allCards(const Patch)
{
    return {
        new AddaStriga(),
        new Dao(),
        new PoorFingInfantry(),
        new DeithwenArbalest(),
        new TemerianDrummer(),
        new DandelionPoet(),
        new SileDeTansarville(),
        new RedanianKnightElect(),
        new KaedweniKnight(),
        new AnCraiteMarauder(),
        new AnCraiteGreatsword(),
        new DimunLightLongship(),
        new TuirseachBearmaster(),
        new TuirseachHunter(),
        new RedanianElite(),
        new RedanianKnight(),
        new KaedweniCavalry(),
        new AlzursThunder(),
        new Swallow(),
        new Thunderbolt(),
        new ArachasVenom(),
        new KeiraMetz(),
        new DolBlathannaArcher(),
        new HalfElfHunter(),
        new Ambassador(),
        new Assassin(),
        new Emissary(),
        new CeallachDyffryn(),
        new TuirseachArcher(),
        new Infiltrator(),
        new ImpenetrableFog(),
        new TorrentialRain(),
        new BitingFrost(),
        new GoldenFroth(),
        new SkelligeStorm(),
        new ImperialManticore(),
        new ManticoreVenom(),
        new GloriousHunt(),
        new Ves(),
        new Vaedermakar(),
        new Frightener(),
        new Cleaver(),
        new Scorch(),
        new Reinforcements(),
        new JohnNatalis(),
        new Eleyas(),
        new ReaverScout(),
        new HeymaeySpearmaiden(),
        new VriheddSappers(),
        new PriestessOfFreya(),
        new DimunCorsair(),
        new Sigrdrifa(),
        new DrummondQueensguard(),
        new Sage(),
        new Reconnaissance(),
        new ElvenMercenary(),
        new ChampionOfHov(),
        new Priscilla(),
        new SeltkirkOfGulet(),
        new AdrenalineRush(),
        new Mandrake(),
        new BoneTalisman(),
        new Restore(),
        new Decoy(),
        new ShupesDayOff(),
        new FirstLight(),
        new Epidemic(),
        new Moonlight(),
        new CiriNova(),
        new HaraldTheCripple(),
        new BranTuirseach(),
        new DrummondWarmonger(),
        new DimunPirate(),
        new AnCraiteRaider(),
        new MadmanLugos(),
        new Ermion(),
        new CerysFearless(),
        new CerysAnCraite(),
        new WoodlandSpirit(),
        new Trollololo(),
        new PrinceStennis(),
        new VincentMeis(),
        new Morkvarg(),
        new ArtefactCompression(),
        new HjalmarAnCraite(),
        new Regis(),
        new LethoOfGulet(),
        new AnCraiteLongship(),
        new GeraltIgni(),
        new GeraltOfRivia(),
        new TuirseachVeteran(),
        new Udalryk(),
        new BloodcurdlingRoar(),
        new Gremist(),
        new ZoriaRunestone(),
        new Operator(),
        new Renew(),
        new EistTuirseach(),
        new TuirseachAxeman(),
        new Derran(),
        new TuirseachSkirmisher(),
        new Roach(),
        new JanCalveit(),
        new CahirDyffryn(),
        new LethoKingslayer(),
        new KingHenselt(),
        new BloodyBaron(),
        new HubertRejk(),
        new Dethmold(),
        new RonvidTheIncessant(),
        new CrachAnCraite(),
        new BirnaBran(),
        new Coral(),
        new Vabjorn(),
        new BlueboyLugos(),
        new DjengeFrett(),
        new DonarAnHindar(),
        new DraigBonDhu(),
        new HolgerBlackhand(),
        new JuttaAnDimun(),
        new SavageBear(),
        new SvanrigeTuirseach(),
        new Skjall(),
        new HaraldHoundsnout(),
        new Yoana(),
        new AnCraiteBlacksmith(),
        new AnCraiteWarcrier(),
        new AnCraiteWarrior(),
        new BerserkerMarauder(),
        new DimunPirateCaptain(),
        new DimunSmuggler(),
        new DrummondShieldmaid(),
        new HeymaeyFlaminica(),
        new HeymaeyHerbalist(),
        new HeymaeyProtector(),
        new HeymaeySkald(),
        new RagingBerserker(),
        new Hym(),
        new Kambi(),
        new Olaf(),
        new Ulfhedinn(),
        new WildBoarOfTheSea(),
        new GiantBoar(),
        new OrnamentalSword(),
        new DimunWarship(),
        new Vilgefortz(),
        new TrissButterflies(),
        new Yennefer(),
        new GermainPiquant(),
        new CommandersHorn(),
        new MarchingOrders(),
        new AlzursDoubleCross(),
        new AlbaArmoredCavalry(),
        new Sentry(),
        new NauzicaaSergeant(),
        new SlaveInfantry(),
        new Recruit(),
        new Ointment(),
        new Vreemde(),
        new Lambert(),
        new Eskel(),
        new Vesemir(),
        new TridamInfantry(),
        new VriheddDragoon(),
        new Malena(),
        new UnseenElder(),
        new DevanaRunestone(),
        new DazhbogRunestone(),
        new MoranaRunestone(),
        new StribogRunestone(),
        new Muzzle(),
        new WhisperingHillock(),
        new Brewess(),
        new Weavess(),
        new Whispess(),
        new WeavessIncantation(),
        new BrewessRitual(),
        new WhispessTribute(),
        new LeoBonhart(),
        new MorvranVoorhis(),
        new Cynthia(),
        new Serrit(),
        new Sweers(),
        new WildHuntHound(),
        new WildHuntWarrior(),
        new WildHuntNavigator(),
        new Nithral(),
        new Miruna(),
        new Imlerith(),
        new Caretaker(),
        new Ruehin(),
        new OldSpeartipAsleep(),
        new OldSpeartip(),
        new Golyat(),
        new Barbegazi(),
        new Ghoul(),
        new Forktail(),
        new ArachasQueen(),
        new Ozzrel(),
        new Kayran(),
        new Mourntart(),
        new ToadPrince(),
        new Fiend(),
        new Morvudd(),
        new Ekimmara(),
        new Rotfiend(),
        new Archespore(),
        new Cyclops(),
        new Maerolorn(),
        new MonsterNest(),
        new ArachasDrone(),
        new EredinBreaccGlas(),
    };
};

std::map<std::string, std::string> keywordDescriptions(const Patch patch)
{
    if (patch == PublicBeta_0_9_24_3_432)
        return {
            {"Charm", "Move an enemy to the opposite row."},
            {"Highest", "Highest power, ties are resolved randomly."},
            {"Lowest", "Lowest power, ties are resolved randomly."},
            {"Truce", "If neither player has passed."},
            {"Spawn", "Add a card to the game."},
            {"Armor", "Absorbs a given amount of damage, then is removed."},
            {"Discard", "Move a card from your hand to the graveyard. Note: Related abilities are not triggered when discarding manually."},
            {"Strengthen", "Increase the base power of a unit."},
            {"Weaken", "Decrease the base power of a unit. If it falls below 1, remove it from the game. Does not trigger Deathwish abilities."},
            {"Reset", "Restore a card to its default state (as it would appear in the Deck Builder)."},
            {"Drain", "Deal damage and boost self by the same amount."},
            {"Consume", "Eat a unit and boost by its power. If it's on the battlefield, destroy it. If in hand or deck, move it to the graveyard. If in the graveyard, remove it from the game."},
            {"Create", "Spawn one of three randomly selected cards from the specified source."},
            {"Summon", "Move automatically to the battlefield (not considered played)."},
            {"Deathwish", "Trigger this ability when destroyed and moved from the battlefield to the graveyard. Note: Banished units are not sent to the graveyard."},
            {"Spying", "Status for a unit played on or moved to the opposite side of the battlefield."},
            {"Single-Use", "This card's ability can be used only once per game."},
            {"Resurrect", "Play from your graveyard."},
            {"Hazard", "Negative row effect. Replaced by other row effects and removed on round end."},
            {"Banish", "Remove from the game. Note: Does not count as being destroyed."},
            {"Heal", "If a unit's current power is lower than its base power, restore it either to base power or by the amount specified."},
            {"Lock", "Status that disables a unit's abilities."},
            {"Boon", "Positive row effect. Replaced by other row effects and removed on round end."},
            {"Duel", "Units take turns dealing damage equal to their power until one of them is destroyed."},
            {"Reveal", "Show a card to both players, then hide it back in the hand or deck."},
            {"Revealed", "A card in the hand that has been turned over."},
            {"Crew", "This unit triggers the ability of Crewed units played adjacent to it."},
            {"Ambush", "Played face down, then flips over when the ability's condition is met."},
            {"Crewed", "When played, trigger this ability once for each adjacent Crew unit."},
            {"Swap", "Move a card from hand to deck and draw another in its place during your turn."},
            {"Resilience", "Status that allows a unit to remain on the board at round end, and if boosted restores it to its base power."},
            {"Doomed", "Banish instead of putting in a Discard."},
            {"Immunity", "Status whereby this card cannot be manually targeted."},
        };
    return {};
}

AddaStriga::AddaStriga()
{
    id = "200073";
    name = "Adda: Striga";
    text = "Deal 8 damage to a non-Monster faction unit.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 6;
    rarity = Silver;
    faction = Monster;
    tags = { Relict, Cursed };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isNonMonsterFaction});
    };

    _onTargetChoosen = [=](Card *card, Field &ally, Field &enemy) {
        damage(card, 8, ally, enemy, this);
    };
};

Dao::Dao()
{
    id = "132213";
    name = "D'ao";
    text = "Deathwish: Spawn 2 Lesser D'ao on this row.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 6;
    rarity = Bronze;
    faction = Monster;
    tags = { Construct };

    _onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &rowAndPos) {
        spawnNewUnitToPos(new DaoLesser(), rowAndPos, ally, enemy, this);
        spawnNewUnitToPos(new DaoLesser(), rowAndPos, ally, enemy, this);
    };
};

Dao::DaoLesser::DaoLesser()
{
    id = "132405";
    name = "D'ao Lesser";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 4;
    rarity = Bronze;
    faction = Monster;
    tags = { Construct };
    isDoomed = true;
};

PoorFingInfantry::LeftFlankInfantry::LeftFlankInfantry()
{
    id = "200302";
    name = "Left Flank Infantry";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 2;
    rarity = Bronze;
    faction = NothernRealms;
    tags = { Temeria, Soldier };
    isDoomed = true;
};

PoorFingInfantry::RightFlankInfantry::RightFlankInfantry()
{
    id = "200303";
    name = "Right Flank Infantry";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 2;
    rarity = Bronze;
    faction = NothernRealms;
    tags = { Temeria, Soldier };
    isDoomed = true;
}

PoorFingInfantry::PoorFingInfantry()
{
    id = "200234";
    name = "Poor F'ing Infantry";
    text = "Spawn Left Flank Infantry and Right Flank Infantry to the left and right of this unit, respectively.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/VPEA1_VSET_00521643.mp3",
        "https://gwent.one/audio/card/ob/en/VPEA1_VSET_00519831.mp3",
        "https://gwent.one/audio/card/ob/en/VPEA1_VSET_00518009.mp3",
    };
    power = powerBase = 6;
    rarity = Bronze;
    faction = NothernRealms;
    tags = { Temeria, Soldier };

    _onDeploy = [=](Field &ally, Field &enemy) {
        spawnNewUnitToPos(new LeftFlankInfantry(), rowAndPosToTheLeft(this, ally, 1), ally, enemy, this);
        spawnNewUnitToPos(new RightFlankInfantry(), rowAndPosToTheRight(this, ally, 1), ally, enemy, this);
    };
}

DeithwenArbalest::DeithwenArbalest()
{
    id = "162305";
    name = "Deithwen Arbalest";
    text = "Deal 3 damage to an enemy. If it's Spying, deal 6 damage instead.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/NILF3_VSET_00514109.mp3",
        "https://gwent.one/audio/card/ob/en/NILF3_SQ102_00591494.mp3",
        "https://gwent.one/audio/card/ob/en/NILF3_VSET_00514105.mp3",
    };
    power = powerBase = 7;
    rarity = Bronze;
    faction = Nilfgaard;
    tags = { Soldier };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {}, EnemyBoard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        damage(target, target->isSpy ? 6 : 3, ally, enemy, this);
    };
};

TemerianDrummer::TemerianDrummer()
{
    id = "200299";
    name = "Temerian Drummer";
    text = "Boost an ally by 6.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.407.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.408.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.409.mp3",
    };
    power = powerBase = 5;
    rarity = Bronze;
    faction = NothernRealms;
    tags = { Temeria, Support };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {}, AllyBoard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        boost(target, 6, ally, enemy, this);
    };
};

DandelionPoet::DandelionPoet()
{
    id = "201776";
    name = "Dandelion: Poet";
    text = "Draw a card, then play a card.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/DAND_Q302_00490269.mp3",
        "https://gwent.one/audio/card/ob/en/DAND_DANDELION_00429307.mp3",
        "https://gwent.one/audio/card/ob/en/DAND_Q302_00489393.mp3",
        "https://gwent.one/audio/card/ob/en/VO_JSKR_100926_0188.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.5.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.6.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.7.mp3",
    };
    power = powerBase = 5;
    rarity = Gold;
    faction = Neutral;
    tags = { Support };

    _onDeploy = [=](Field &ally, Field &enemy) {
        if (drawACard(ally, enemy))
            startChoiceToTargetCard(ally, enemy, this, {}, AllyHand);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, this);
    };
};

SileDeTansarville::SileDeTansarville()
{
    id = "122205";
    name = "S'ile de Tansarville";
    text = "Play a Bronze or Silver special card, then draw a card.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.29.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.30.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.31.mp3",
    };
    power = powerBase = 4;
    rarity = Silver;
    faction = NothernRealms;
    tags = { Mage };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilver, ::isSpecial}, AllyHand);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, this);
        drawACard(ally, enemy);
    };
};

RedanianKnightElect::RedanianKnightElect()
{
    id = "123301";
    name = "Redanian Knight Elect";
    text = "If this unit has Armor on turn end, boost adjacent units by 1. 2 Armor.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.320.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.321.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.322.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.323.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.324.mp3",
    };
    power = powerBase = 7;
    rarity = Bronze;
    faction = NothernRealms;
    tags = { Redania, Soldier };

    _onDeploy = [=](Field &ally, Field &enemy) {
        gainArmor(this, 2, ally, enemy, this);
    };

    _onTurnEnd = [=](Field &ally, Field &enemy) {
        if (armor == 0)
            return;

        Card *left = cardNextTo(this, ally, enemy, -1);
        Card *right = cardNextTo(this, ally, enemy, 1);

        if (left != nullptr)
            boost(left, 1, ally, enemy, this);
        if (right != nullptr)
            boost(right, 1, ally, enemy, this);
    };
};

AnCraiteMarauder::AnCraiteMarauder()
{
    id = "201578";
    name = "An Craite Marauder";
    text = "Deal 4 damage. If Resurrected, deal 6 damage instead.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.395.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.396.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.397.mp3",
    };
    power = powerBase = 7;
    rarity = Bronze;
    faction = Skellige;
    tags = { ClanAnCraite, Soldier };
};

AnCraiteGreatsword::AnCraiteGreatsword()
{
    id = "200040";
    name = "An Craite Greatsword";
    text = "Every 2 turns, if damaged, Heal self and Strengthen by 2 on turn start.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.314.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.315.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.316.mp3",
    };
    power = powerBase = 8;
    rarity = Bronze;
    faction = Skellige;
    tags = { ClanAnCraite, Soldier };

    _onDeploy = [=](Field &ally, Field &enemy) {
        setTimer(this, ally, enemy, 2);
    };

    _onTurnStart = [=](Field &ally, Field &enemy) {
        if (!tick(this, ally, enemy, 2))
            return;

        if (power >= powerBase)
            return;

        heal(this, ally, enemy);
        strengthen(this, 2, ally, enemy);
    };
};

DimunLightLongship::DimunLightLongship()
{
    id = "152309";
    name = "Dimun Light Longship";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    text = "On turn end, damage the unit to the right by 1, then boost self by 2.";
    power = powerBase = 7;
    rarity = Bronze;
    faction = Skellige;
    tags = { ClanDimun, Machine };

    _onTurnEnd = [=](Field &ally, Field &enemy) {
        if (Card *right = cardNextTo(this, ally, enemy, 1)) {
            damage(right, 1, ally, enemy, this);
            boost(this, 2, ally, enemy, this);
        }
    };
};

Bear::Bear()
{
    id = "152406";
    name = "Bear";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 11;
    rarity = Bronze;
    faction = Neutral;
    tags = { Beast, Cursed };
};

Wolf::Wolf()
{
    id = "132403";
    name = "Wolf";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 1;
    isDoomed = true;
    rarity = Bronze;
    faction = Monster;
    tags = { Beast };
};

TuirseachBearmaster::TuirseachBearmaster()
{
    id = "200144";
    name = "Tuirseach Bearmaster";
    text = "Spawn a Bear.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.26.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.27.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.28.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.29.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.30.mp3",
    };
    power = powerBase = 1;
    rarity = Bronze;
    faction = Skellige;
    tags = { ClanTuirseach, Soldier };

    _onDeploy = [=](Field &ally, Field &enemy) {
        spawnNewCard(new Bear(), ally, enemy, this);
    };
};

RedanianElite::RedanianElite()
{
    id = "122317";
    name = "Redanian Elite";
    text = "Whenever this unit's Armor reaches 0, boost self by 5. 4 Armor.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/REOF1_VSET_00516089.mp3",
        "https://gwent.one/audio/card/ob/en/REOF1_VSET_00516091.mp3",
        "https://gwent.one/audio/card/ob/en/REOF1_VSET_00516093.mp3",
    };
    power = powerBase = 8;
    rarity = Bronze;
    faction = NothernRealms;
    tags = { Redania, Soldier };

    _onDeploy = [=](Field &ally, Field &enemy) {
        gainArmor(this, 4, ally, enemy, this);
    };

    _onArmorLost = [=](Field &ally, Field &enemy) {
        boost(this, 5, ally, enemy, this);
    };
};

RedanianKnight::RedanianKnight()
{
    id = "122308";
    name = "Redanian Knight";
    text = "If this unit has no Armor, boost it by 2 and give it 2 Armor on turn end.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/RES1_VSET_00508445.mp3",
        "https://gwent.one/audio/card/ob/en/RES1_VSET_00508451.mp3",
        "https://gwent.one/audio/card/ob/en/RES1_VSET_00508237.mp3",
    };
    power = powerBase = 7;
    rarity = Bronze;
    faction = NothernRealms;
    tags = { Redania, Soldier };

    _onTurnEnd = [=](Field &ally, Field &enemy) {
        if (armor != 0)
            return;
        boost(this, 2, ally, enemy, this);
        gainArmor(this, 2, ally, enemy, this);
    };
};

KaedweniCavalry::KaedweniCavalry()
{
    id = "122314";
    name = "Kaedweni Cavalry";
    text = "Destroy a unit's Armor, then boost self by the amount destroyed.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/VO_KG02_202929_0003.mp3",
        "https://gwent.one/audio/card/ob/en/VO_KG02_202929_0004.mp3",
        "https://gwent.one/audio/card/ob/en/VO_KG02_200565_0005.mp3",
    };
    power = powerBase = 8;
    rarity = Bronze;
    faction = NothernRealms;
    tags = { Kaedwen, Soldier };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {hasArmor});
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        const int armorTarget = target->armor;
        damage(target, armorTarget, ally, enemy, this);
        boost(this, armorTarget, ally, enemy, this);
    };
};

AlzursThunder::AlzursThunder()
{
    id = "113301";
    name = "Alzur's Thunder";
    text = "Deal 9 damage.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    rarity = Bronze;
    faction = Neutral;
    tags = { Spell };
    isSpecial = true;

    _onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        saveFieldsSnapshot(ally, enemy, DealDamage, this, {target}, "", 9);
        damage(target, 9, ally, enemy, this);
    };
};

Swallow::Swallow()
{
    id = "113310";
    name = "Swallow";
    text = "Boost a unit by 10.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    rarity = Bronze;
    faction = Neutral;
    tags = { Alchemy, Item };
    isSpecial = true;

    _onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        boost(target, 10, ally, enemy, this);
    };
};

Thunderbolt::Thunderbolt()
{
    id = "113311";
    name = "Thunderbolt";
    text = "Boost 3 adjacent units by 3 and give them 2 Armor.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    rarity = Bronze;
    faction = Neutral;
    tags = { Alchemy, Item };
    isSpecial = true;

    _onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        boost(target, 3, ally, enemy, this);
        gainArmor(target, 2, ally, enemy, this);

        Card *left = cardNextTo(target, ally, enemy, -1);
        Card *right = cardNextTo(target, ally, enemy, 1);

        if (left != nullptr) {
            boost(left, 3, ally, enemy, this);
            gainArmor(left, 2, ally, enemy, this);
        }
        if (right != nullptr) {
            boost(right, 3, ally, enemy, this);
            gainArmor(right, 2, ally, enemy, this);
        }
    };
};

ArachasVenom::ArachasVenom()
{
    id = "200023";
    name = "Arachas Venom";
    text = "Deal 4 damage to 3 adjacent units.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    rarity = Bronze ;
    faction = Neutral;
    tags = { Organic };
    isSpecial = true;

    _onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        Card *left = cardNextTo(target, ally, enemy, -1);
        Card *right = cardNextTo(target, ally, enemy, 1);
        for (Card *card : std::vector<Card *>{left, target, right})
            if (card != nullptr)
                damage(card, 4, ally, enemy, this);
    };
};

KeiraMetz::KeiraMetz()
{
    id = "122108";
    name = "Keira Metz";
    text = "Spawn Alzur's Thunder, Thunderbolt or Arachas Venom.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/KEIR_KEIRA_01040781.mp3",
        "https://gwent.one/audio/card/ob/en/KEIR_SQ101_00565661.mp3",
        "https://gwent.one/audio/card/ob/en/KEIR_KEIRA_00475332.mp3",
    };
    power = powerBase = 6;
    rarity = Gold;
    faction = NothernRealms;
    tags = { Temeria, Mage };

    _onDeploy = [=](Field &ally, Field &) {
        startChoiceToSelectOption(ally, this, {new AlzursThunder(), new Thunderbolt(), new ArachasVenom()});
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        acceptOptionAndDeleteOthers(this, target);
        spawnNewCard(target, ally, enemy, this);
    };
};

DolBlathannaArcher::DolBlathannaArcher()
{
    id = "142310";
    name = "Dol Blathanna Archer";
    text = "Deal 3 damage, then deal 1 damage.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 7;
    rarity = Bronze;
    faction = Scoiatael;
    tags = { Elf, Soldier };
    sounds = {
        "https://gwent.one/audio/card/ob/en/VO_SF07_100515_0011.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.801.mp3",
        "https://gwent.one/audio/card/ob/en/VO_SF07_100515_0001.mp3",
        "https://gwent.one/audio/card/ob/en/VO_SF07_108969_0002.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.802.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.803.mp3",
    };

    _onDeploy = [=](Field &ally, Field &enemy) {
        _nShots = 0;
        startChoiceToTargetCard(ally, enemy, this);
        startChoiceToTargetCard(ally, enemy, this);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        damage(target, ++_nShots == 1 ? 3 : 1, ally, enemy, this);
    };
};

HalfElfHunter::HalfElfHunter()
{
    id = "201636";
    name = "Half-Elf Hunter";
    text = "Spawn a Doomed default copy of this unit to the right of this unit.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 6;
    rarity = Bronze;
    faction = Scoiatael;
    tags = { Elf, Soldier };

    _onDeploy = [=](Field &ally, Field &enemy) {
        Card *copy = defaultCopy();
        copy->isDoomed = true;
        spawnNewUnitToPos(copy, rowAndPosToTheRight(this, ally, 1), ally, enemy, this);
    };
};

Ambassador::Ambassador()
{
    id = "162315";
    name = "Ambassador";
    text = "Spying. Boost an ally by 12.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 2;
    isLoyal = false;
    rarity = Bronze;
    faction = Nilfgaard;
    tags = {};

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {}, AllyBoard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        boost(target, 12, ally, enemy, this);
    };
};

Assassin::Assassin()
{
    id = "200115";
    name = "Assassin";
    text = "Spying. Deal 10 damage to the unit to the left.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 1;
    isLoyal = false;
    rarity = Bronze;
    faction = Nilfgaard;
    tags = {};

    _onDeploy = [=](Field &ally, Field &enemy) {
        if (Card *left = cardNextTo(this, ally, enemy, -1)) {
            damage(left, 10, ally, enemy, this);
        }
    };
};

TuirseachArcher::TuirseachArcher()
{
    id = "152315";
    name = "Tuirseach Archer";
    text = "Deal 1 damage to 3 units.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 8;
    rarity = Bronze;
    faction = Skellige;
    tags = { ClanTuirseach, Soldier };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {}, AnyBoard, 3);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        saveFieldsSnapshot(ally, enemy, DealDamage, this, {target}, "", 1);
        damage(target, 1, ally, enemy, this);
    };
};

Infiltrator::Infiltrator()
{
    id = "200118";
    name = "Infiltrator";
    text = "Toggle a unit's Spying status.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 10;
    rarity = Bronze;
    faction = Nilfgaard;
    tags = {};

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        toggleSpy(target, ally, enemy, this);
    };
};

ImpenetrableFog::ImpenetrableFog()
{
    id = "113305";
    name = "Impenetrable Fog";
    text = "Apply a Hazard to an enemy row that deals 2 damage to the Highest unit on turn start.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    rarity = Bronze;
    faction = Neutral;
    tags = { Hazard };

    _onPlaySpecial = [=](Field &ally, Field &) {
        startChoiceToSelectEnemyRow(ally, this);
    };

    _onTargetRowEnemyChoosen = [=](Field &ally, Field &enemy, const Row row) {
        applyRowEffect(enemy, ally, row, ImpenetrableFogEffect);
    };
};

TorrentialRain::TorrentialRain()
{
    id = "113312";
    name = "Torrential Rain";
    text = "Apply a Hazard to an enemy row that deals 1 damage to 2 random units on turn start.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    rarity = Bronze;
    faction = Neutral;
    tags = { Hazard };

    _onPlaySpecial = [=](Field &ally, Field &) {
        startChoiceToSelectEnemyRow(ally, this);
    };

    _onTargetRowEnemyChoosen = [=](Field &ally, Field &enemy, const Row row) {
        applyRowEffect(enemy, ally, row, TorrentialRainEffect);
    };
};

BitingFrost::BitingFrost()
{
    id = "113302";
    name = "Biting Frost";
    text = "Apply a Hazard to an enemy row that deals 2 damage to the Lowest unit on turn start.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    rarity = Bronze;
    faction = Neutral;
    tags = { Hazard };

    _onPlaySpecial = [=](Field &ally, Field &) {
        startChoiceToSelectEnemyRow(ally, this);
    };

    _onTargetRowEnemyChoosen = [=](Field &ally, Field &enemy, const Row row) {
        applyRowEffect(enemy, ally, row, BitingFrostEffect);
    };
};

GoldenFroth::GoldenFroth()
{
    id = "201749";
    name = "Golden Froth";
    text = "Apply a Boon to an allied row that boosts 2 random units by 1 on turn start.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    rarity = Bronze;
    faction = Neutral;
    tags = { Hazard };

    _onPlaySpecial = [=](Field &ally, Field &) {
        startChoiceToSelectAllyRow(ally, this);
    };

    _onTargetRowAllyChoosen = [=](Field &ally, Field &enemy, const Row row) {
        applyRowEffect(ally, enemy, row, GoldenFrothEffect);
    };
};

SkelligeStorm::SkelligeStorm()
{
    id = "113203";
    name = "Skellige Storm";
    text = "Apply a Hazard to an enemy row that deals 2, 1 and 1 damage to the leftmost units on the row on turn start.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    rarity = Silver;
    faction = Neutral;
    tags = { Hazard };

    _onPlaySpecial = [=](Field &ally, Field &) {
        startChoiceToSelectEnemyRow(ally, this);
    };

    _onTargetRowEnemyChoosen = [=](Field &ally, Field &enemy, const Row row) {
        applyRowEffect(enemy, ally, row, SkelligeStormEffect);
    };
};

ImperialManticore::ImperialManticore()
{
    id = "132209";
    name = "Imperial Manticore";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 13;
    rarity = Silver;
    faction = Monster;
    tags = { Beast };
};

ManticoreVenom::ManticoreVenom()
{
    id = "113306";
    name = "Manticore Venom";
    text = "Deal 13 damage.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    rarity = Silver;
    faction = Neutral;
    tags = { Organic };

    _onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        damage(target, 13, ally, enemy, this);
    };
};

GloriousHunt::GloriousHunt()
{
    id = "201635";
    name = "Glorious Hunt";
    text = "If losing, Spawn an Imperial Manticore, otherwise Spawn Manticore Venom.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    rarity = Silver;
    faction = Neutral;
    tags = { Tactics };

    _onPlaySpecial = [=](Field &ally, Field &enemy) {
        if (powerField(ally) < powerField(enemy))
            return spawnNewCard(new ImperialManticore(), ally, enemy, this);

        return spawnNewCard(new ManticoreVenom(), ally, enemy, this);
    };
};

Ves::Ves()
{
    id = "122204";
    name = "Ves";
    text = "Swap up to 2 cards.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/VESS_Q403_00546798.mp3",
        "https://gwent.one/audio/card/ob/en/VESS_VES_01070698.mp3",
        "https://gwent.one/audio/card/ob/en/VESS_MQ3035_01064809.mp3",
        "https://gwent.one/audio/card/ob/en/VESS_MQ3035_01071150.mp3",
    };
    power = powerBase = 12;
    rarity = Silver;
    faction = NothernRealms;
    tags = { Temeria, Soldier };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {}, AllyHand, 2, true);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        swapACard(target, ally, enemy);
    };
};

Vaedermakar::Vaedermakar()
{
    id = "113208";
    name = "Vaedermakar";
    text = "Spawn Biting Frost, Impenetrable Fog or Alzur's Thunder.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 4;
    rarity = Silver;
    faction = Neutral;
    tags = { Mage };

    _onDeploy = [=](Field &ally, Field &) {
        startChoiceToSelectOption(ally, this, {new BitingFrost(), new ImpenetrableFog(), new AlzursThunder()});
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        acceptOptionAndDeleteOthers(this, target);
        spawnNewCard(target, ally, enemy, this);
    };
};

Frightener::Frightener()
{
    id = "132204";
    name = "Frightener";
    text = "Spying. Single-Use: Move an enemy to this row and draw a card.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 13;
    isLoyal = false;
    timer = 1;
    rarity = Silver;
    faction = Monster;
    tags = { Construct, Agent };

    _onDeploy = [=](Field &ally, Field &enemy) {
        if (tick(this, ally, enemy))
            drawACard(ally, enemy);

        /// can't move another to this row, if its already full
        startChoiceToTargetCard(ally, enemy, this, {isOnAnotherRow(&enemy, this)}, EnemyBoard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        moveExistedUnitToPos(target, rowAndPosLastInTheSameRow(this, enemy), enemy, ally, this);
    };
};

Cleaver::Cleaver()
{
    id = "122216";
    name = "Cleaver";
    text = "Deal 1 damage for each card in your hand.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 7;
    rarity = Silver;
    faction = Neutral;
    tags = { Dwarf };

    _onDeploy = [=](Field &ally, Field &enemy) {
        if (ally.hand.size() != 0)
            startChoiceToTargetCard(ally, enemy, this, {}, AnyBoard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        damage(target, int(ally.hand.size()), ally, enemy, this);
    };
};

Scorch::Scorch()
{
    id = "113309";
    name = "Scorch";
    text = "Destroy all the Highest units.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    rarity = Silver;
    faction = Neutral;
    tags = { Spell };

    _onPlaySpecial = [=](Field &ally, Field &enemy) {
        for (Card *card : highests(cardsFiltered(ally, enemy, {}, AnyBoard)))
            putToDiscard(card, ally, enemy, this);
    };
};

Reinforcements::Reinforcements()
{
    id = "123201";
    name = "Reinforcements";
    text = "Play a Bronze or Silver Soldier, Machine, Officer or Support unit from your deck.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    rarity = Silver;
    faction = NothernRealms;
    tags = { Tactics };

    _onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilver, hasAnyOfTags({Soldier, Support, Machine, Officer})}, AllyDeckShuffled);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, this);
    };
};

JohnNatalis::JohnNatalis()
{
    id = "122103";
    name = "John Natalis";
    text = "Play a Bronze or Silver Tactic from your deck.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/VO_JANT_900381_0141.mp3",
        "https://gwent.one/audio/card/ob/en/VO_JANT_300862_0253.mp3",
    };
    power = powerBase = 6;
    rarity = Gold;
    faction = NothernRealms;
    tags = { Temeria, Officer };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilver, hasTag(Tactics)}, AllyDeckShuffled);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, this);
    };
};

Eleyas::Eleyas()
{
    id = "142214";
    name = "Ele'yas";
    text = "Whenever you draw this unit or return it to your deck, boost self by 2.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 10;
    rarity = Silver;
    faction = Scoiatael;
    tags = { Elf, Soldier };

    _onDraw = [=](Field &ally, Field &enemy) {
        boost(this, 2, ally, enemy, this);
    };

    _onSwap = [=](Field &ally, Field &enemy) {
        boost(this, 2, ally, enemy, this);
    };
};

ReaverScout::ReaverScout()
{
    id = "122307";
    name = "Reaver Scout";
    text = "Choose a different Bronze ally and play a copy of it from your deck.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/VO_NG01_003478_0126.mp3",
        "https://gwent.one/audio/card/ob/en/VO_NG01_003478_0060.mp3",
        "https://gwent.one/audio/card/ob/en/VO_NG01_003478_0008.mp3",
    };
    power = powerBase = 1;
    rarity = Bronze;
    faction = NothernRealms;
    tags = { Redania, Support };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isBronze, otherThan(name), hasCopyInADeck(&ally)}, AllyBoard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (Card *copy = findCopy(target, ally.deck))
            playExistedCard(copy, ally, enemy, this);
    };
};

HeymaeySpearmaiden::HeymaeySpearmaiden()
{
    id = "200528";
    name = "Heymaey Spearmaiden";
    text = "Deal 1 damage to a Bronze Machine or Soldier ally, then play a copy of it from your deck.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.83.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.84.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.85.mp3",
    };
    power = powerBase = 2;
    rarity = Bronze;
    faction = Skellige;
    tags = { ClanAnCraite, Support };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isBronze, hasAnyOfTags({Soldier, Machine}), hasCopyInADeck(&ally)}, AllyBoard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        damage(target, 1, ally, enemy, this);
        if (Card *copy = findCopy(target, ally.deck))
            playExistedCard(copy, ally, enemy, this);
    };
};

KaedweniKnight::KaedweniKnight()
{
    id = "201622";
    name = "Kaedweni Knight";
    text = "Boost self by 5 if played from the deck. 2 Armor.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.9.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.10.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.11.mp3",
    };
    power = powerBase = 8;
    rarity = Bronze;
    faction = NothernRealms;
    tags = { Kaedwen, Soldier };

    _onDeploy = [=](Field &ally, Field &enemy) {
        gainArmor(this, 2, ally, enemy, this);
    };

    _onDeployFromDeck = [=](Field &ally, Field &enemy) {
        gainArmor(this, 2, ally, enemy, this);
        boost(this, 5, ally, enemy, this);
    };
};

VriheddSappers::VriheddSappers()
{
    id = "142307";
    name = "Vrihedd Sappers";
    text = "Ambush: After 2 turns, flip over on turn start.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 11;
    isAmbush = true;
    rarity = Bronze;
    faction = Scoiatael;
    tags = { Elf, Soldier };
    sounds = {
        "https://gwent.one/audio/card/ob/en/VO_SMV2_202963_0006.mp3",
        "https://gwent.one/audio/card/ob/en/VO_SMV2_202963_0007.mp3",
        "https://gwent.one/audio/card/ob/en/VO_SMV2_202544_0022.mp3",
    };

    _onDeploy = [=](Field &ally, Field &enemy) {
        setTimer(this, ally, enemy, 2);
    };

    _onTurnStart = [=](Field &ally, Field &enemy) {
        if (tick(this, ally, enemy))
            flipOver(this, ally, enemy);
    };
};

PriestessOfFreya::PriestessOfFreya()
{
    id = "152310";
    name = "Priestess of Freya";
    text = "Resurrect a Bronze Soldier.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SPR2_VSET_00553534.mp3",
        "https://gwent.one/audio/card/ob/en/SPR2_VSET_00553573.mp3",
        "https://gwent.one/audio/card/ob/en/SPR2_VSET_00553583.mp3",
    };
    power = powerBase = 1;
    rarity = Bronze;
    faction = Skellige;
    tags = { ClanHeymaey, Support };
    isDoomed = true;

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isBronze, hasTag(Soldier)}, AllyDiscard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, this);
    };
};

DimunCorsair::DimunCorsair()
{
    id = "200145";
    name = "Dimun Corsair";
    text = "Resurrect a Bronze Machine.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.71.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.72.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.73.mp3",
    };
    power = powerBase = 3;
    rarity = Bronze;
    faction = Skellige;
    tags = { ClanDimun, Support };
    isDoomed = true;

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isBronze, hasTag(Machine)}, AllyDiscard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, this);
    };
};

Sigrdrifa::Sigrdrifa()
{
    id = "152211";
    name = "Sigrdrifa";
    text = "Resurrect a Bronze or Silver Clan unit.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SPR1_VSET_00553157.mp3",
        "https://gwent.one/audio/card/ob/en/SPR1_SQ201_00499249.mp3",
        "https://gwent.one/audio/card/ob/en/SPR1_SHOP_00437650.mp3",
    };
    power = powerBase = 3;
    rarity = Silver;
    faction = Skellige;
    tags = { Support };
    isDoomed = true;

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilver, hasAnyOfTags({ClanAnCraite, ClanDimun, ClanDrummond, ClanHeymaey, ClanTuirseach, ClanBrokvar, ClanTordarroch})}, AllyDiscard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, this);
    };
};

Sage::Sage()
{
    id = "200138";
    name = "Sage";
    text = "Resurrect a Bronze Alchemy or Spell card, then Banish it.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 2;
    rarity = Bronze;
    faction = Scoiatael;
    tags = { Elf, Mage };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isBronze, hasAnyOfTags({Alchemy, Spell})}, AllyDiscard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        target->isDoomed = true;
        playExistedCard(target, ally, enemy, this);
    };
};

Reconnaissance::Reconnaissance()
{
    id = "201704";
    name = "Reconnaissance";
    text = "Look at 2 random Bronze units in your deck, then play 1.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    rarity = Bronze;
    faction = Neutral;
    tags = { Tactics };

    _onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, randoms(cardsFiltered(ally, enemy, {isBronze, isUnit}, AllyDeck), 2, ally.rng));
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, this);
    };
};

ElvenMercenary::ElvenMercenary()
{
    id = "142308";
    name = "Elven Mercenary";
    text = "Look at 2 random Bronze special cards from your deck, then play 1.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 1;
    rarity = Bronze;
    faction = Scoiatael;
    tags = { Elf, Soldier };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, randoms(cardsFiltered(ally, enemy, {isBronze, ::isSpecial}, AllyDeck), 2, ally.rng));
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, this);
    };
};

ChampionOfHov::ChampionOfHov()
{
    id = "152202";
    name = "Champion of Hov";
    text = "Duel an enemy.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/TRL3_FF205_01053125.mp3",
        "https://gwent.one/audio/card/ob/en/TRL3_FF205_01053127.mp3",
    };
    power = powerBase = 7;
    rarity = Silver;
    faction = Skellige;
    tags = { Ogroid };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {}, EnemyBoard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        duel(this, target, ally, enemy);
    };
};

GeraltIgni::GeraltIgni(const Lang)
{
    id = "112102";
    name = "Geralt: Igni";
    text = "Destroy the Highest units on an enemy row if that row has a total of 25 or more.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/GRLT_GERALT_01129033.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.2.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.1.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.3.mp3",
        "https://gwent.one/audio/card/ob/en/GRLT_GERALT_01054169.mp3",
    };
    power = powerBase = 5;
    rarity = Gold;
    faction = Neutral;
    tags = { Witcher };
};

GeraltOfRivia::GeraltOfRivia()
{
    id = "112103";
    name = "Geralt of Rivia";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/GRLT_GERALT_01129033.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.2.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.1.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.3.mp3",
        "https://gwent.one/audio/card/ob/en/GRLT_GERALT_01054169.mp3",
    };
    power = powerBase = 15;
    rarity = Gold;
    faction = Neutral;
    tags = { Witcher };

    _onDeploy = [=](Field &ally, Field &) {
        // TODO: select only between rows with 25 or more power
        startChoiceToSelectEnemyRow(ally, this);
    };

    _onTargetRowEnemyChoosen = [=](Field &ally, Field &enemy, const Row row) {
        if (powerRow(enemy.row(row)) < 25)
            return;

        for (Card *card : highests(enemy.row(row)))
            putToDiscard(card, ally, enemy, this);
    };
};

Priscilla::Priscilla()
{
    id = "122202";
    name = "Priscilla";
    text = "Boost 5 random allies by 3.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/PRIS_Q305_00489643.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.9.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.10.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.11.mp3",
    };
    power = powerBase = 3;
    rarity = Gold;
    faction = NothernRealms;
    tags = { Support };

    _onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *card : randoms(cardsFiltered(ally, enemy, {[=](Card *card){ return card != this; }}, AllyBoard), 5, ally.rng))
            boost(card, 3, ally, enemy, this);
    };
};

SeltkirkOfGulet::SeltkirkOfGulet()
{
    id = "201618";
    name = "Seltkirk of Gulet";
    text = "Duel an enemy. 3 Armor.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.117.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.118.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.119.mp3",
    };
    power = powerBase = 8;
    rarity = Gold;
    faction = NothernRealms;
    tags = { Aedirn, Officer, Cursed };

    _onDeploy = [=](Field &ally, Field &enemy) {
        gainArmor(this, 3, ally, enemy, this);
        startChoiceToTargetCard(ally, enemy, this, {}, EnemyBoard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        duel(this, target, ally, enemy);
    };
};

AdrenalineRush::AdrenalineRush()
{
    id = "113307";
    name = "Adrenaline Rush";
    text = "Toggle a unit's Resilience status.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    rarity = Bronze;
    faction = Neutral;
    tags = { Organic };

    _onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this);
    };

    _onTargetChoosen = [=](Card *target, Field &, Field &) {
        target->isResilient = !target->isResilient;
    };
};

ShupesDayOff::ShupesDayOff()
{
    id = "201627";
    name = "Shupe's Day Off";
    text = "If your starting deck has no duplicates, Spawn a Shupe: Knight, Shupe: Hunter or Supe: Mage";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.168.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.169.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.170.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.171.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.172.mp3",
    };
    isSpecial = true;
    rarity = Gold;
    faction = Neutral;
    tags = { Organic };

    _onPlaySpecial = [=](Field &ally, Field &) {
        if (!hasNoDuplicates(ally.deckStarting))
            return;

        startChoiceToSelectOption(ally, this, {new ShupeKnight(), new ShupeHunter(), new ShupeMage()});
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        acceptOptionAndDeleteOthers(this, target);
        spawnNewCard(target, ally, enemy, this);
    };
};

ShupeHunter::ShupeHunter()
{
    id = "201731";
    name = "Shupe: Hunter";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 8;
    isDoomed = true;
    rarity = Gold;
    faction = Neutral;
    tags = { Ogroid };

    _onDeploy = [=](Field &ally, Field &) {
        auto *option1 = new ShupeHunter::Play;
        copyCardText(this, option1);
        option1->text = "Play a Bronze or Silver unit from Deck.";

        auto *option2 = new ShupeHunter::Shot;
        copyCardText(this, option2);
        option2->text = "Deal 15 damage.";

        auto *option3 = new ShupeHunter::Replay;
        copyCardText(this, option3);
        option3->text = "Replay a Bronze or Silver unit and Boost it by 5.";

        auto *option4 = new ShupeHunter::Clear;
        copyCardText(this, option4);
        option4->text = "Clear all Hazards from your side and Boost allies by 1.";

        auto *option5 = new ShupeHunter::Barrage;
        copyCardText(this, option5);
        option5->text = "Deal 2 damage to a random enemy. Repeat 8 times.";

        startChoiceToSelectOption(ally, this, {option1, option2, option3, option4, option5}, 1, 3);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (_options.size() > 0) {
            _choosen = target;
            acceptOptionAndDeleteOthers(this, target);

            if (dynamic_cast<ShupeHunter::Play *>(_choosen)) {
                startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilver, isUnit}, AllyDeck);
                return;
            }

            if (dynamic_cast<ShupeHunter::Shot *>(_choosen)) {
                startChoiceToTargetCard(ally, enemy, this);
                return;
            }

            if (dynamic_cast<ShupeHunter::Replay *>(_choosen)) {
                startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilver, isUnit}, AllyBoard);
                return;
            }

            if (dynamic_cast<ShupeHunter::Clear *>(_choosen)) {
                for (Card *card : cardsFiltered(ally, enemy, {}, AllyBoard))
                    boost(card, 1, ally, enemy, this);
                clearAllHazards(ally);
                delete _choosen;
                _choosen = nullptr;
                return;
            }

            if (dynamic_cast<ShupeHunter::Barrage *>(_choosen)) {
                for (int n = 0; n < 8; ++n)
                    if (Card *card = random(cardsFiltered(ally, enemy, {}, EnemyBoard), ally.rng)) {
                        damage(card, 2, ally, enemy, this);
                    }
                delete _choosen;
                _choosen = nullptr;
                return;
            }

            assert(false);
        }

        if (dynamic_cast<ShupeHunter::Play *>(_choosen)) {
            playExistedCard(target, ally, enemy, this);
            delete _choosen;
            _choosen = nullptr;
            return;
        }

        if (dynamic_cast<ShupeHunter::Shot *>(_choosen)) {
            damage(target, 15, ally, enemy, this);
            delete _choosen;
            _choosen = nullptr;
            return;
        }

        if (dynamic_cast<ShupeHunter::Replay *>(_choosen)) {
            putToHand(target, ally, enemy);
            boost(target, 5, ally, enemy, this);
            playExistedCard(target, ally, enemy, this);
            delete _choosen;
            _choosen = nullptr;
            return;
        }

        assert(false);
    };
};

ShupeMage::ShupeMage()
{
    id = "201725";
    name = "Shupe: Mage";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 4;
    isDoomed = true;
    rarity = Gold;
    faction = Neutral;
    tags = { Ogroid };

    _onDeploy = [=](Field &ally, Field &) {
        auto *option1 = new ShupeMage::Draw;
        copyCardText(this, option1);
        option1->text = "Draw a card.";

        auto *option2 = new ShupeMage::Charm;
        copyCardText(this, option2);
        option2->text = "Charm a random enemy.";

        auto *option3 = new ShupeMage::Hazards;
        copyCardText(this, option3);
        option3->text = "Spawn a random Hazard on each enemy row.";

        auto *option4 = new ShupeMage::Meteor;
        copyCardText(this, option4);
        option4->text = "Deal 10 damage to an enemy and 5 damage to each adjacent enemy.";

        auto *option5 = new ShupeMage::Play;
        copyCardText(this, option5);
        option5->text = "Play a Bronze or Silver special card from your deck.";

        startChoiceToSelectOption(ally, this, {option1, option2, option3, option4, option5}, 1, 3);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (_options.size() > 0) {
            _choosen = target;
            acceptOptionAndDeleteOthers(this, target);

            if (dynamic_cast<ShupeMage::Draw *>(_choosen)) {
                drawACard(ally, enemy);
                delete _choosen;
                _choosen = nullptr;
                return;
            }

            if (dynamic_cast<ShupeMage::Charm *>(_choosen)) {
                if (Card *card = random(cardsFiltered(ally, enemy, {}, EnemyBoard), ally.rng))
                    charm(card, ally, enemy, this);
                delete _choosen;
                _choosen = nullptr;
                return;
            }

            if (dynamic_cast<ShupeMage::Hazards *>(_choosen)) {
                applyRowEffect(enemy, ally, Meele, randomHazardEffect(ally.rng));
                applyRowEffect(enemy, ally, Range, randomHazardEffect(ally.rng));
                applyRowEffect(enemy, ally, Seige, randomHazardEffect(ally.rng));
                delete _choosen;
                _choosen = nullptr;
                return;
            }

            if (dynamic_cast<ShupeMage::Meteor *>(_choosen)) {
                startChoiceToTargetCard(ally, enemy, this, {}, EnemyBoard);
                return;
            }

            if (dynamic_cast<ShupeMage::Play *>(_choosen)) {
                startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilver, ::isSpecial}, AllyDeckShuffled);
                return;
            }

            assert(false);
        }

        if (dynamic_cast<ShupeMage::Meteor *>(_choosen)) {
            Card *left = cardNextTo(target, ally, enemy, -1);
            Card *right = cardNextTo(target, ally, enemy, 1);

            damage(target, 10, ally, enemy, this);
            if (left != nullptr) {
                damage(left, 5, ally, enemy, this);
            }
            if (right != nullptr) {
                damage(right, 5, ally, enemy, this);
            }

            delete _choosen;
            _choosen = nullptr;
            return;
        }

        if (dynamic_cast<ShupeMage::Play *>(_choosen)) {
            playExistedCard(target, ally, enemy, this);

            delete _choosen;
            _choosen = nullptr;
            return;
        }

        assert(false);
    };
};

Mandrake::Mandrake()
{
    id = "200223";
    name = "Mandrake";
    text = "Choose One: Heal a unit and Strengthen it by 6; or Reset a unit and Weaken it by 6.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    rarity = Silver;
    faction = Neutral;
    tags = { Alchemy, Organic };

    _onPlaySpecial = [=](Field &ally, Field &) {
        auto *option1 = new Mandrake::Buff;
        copyCardText(this, option1);
        option1->text = "Heal a unit and and Strengthen it by 6.";

        auto *option2 = new Mandrake::Debuff;
        copyCardText(this, option2);
        option2->text = "Reset a unit and Weaken it by 6.";

        startChoiceToSelectOption(ally, this, {option1, option2});
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (_options.size() > 0) {
            _choosen = target;
            acceptOptionAndDeleteOthers(this, target);
            startChoiceToTargetCard(ally, enemy, this);
            return;
        }

        if (dynamic_cast<Mandrake::Buff *>(_choosen)) {
            heal(target, ally, enemy);
            strengthen(target, 6, ally, enemy);

            delete _choosen;
            _choosen = nullptr;
            return;
        }

        if (dynamic_cast<Mandrake::Debuff *>(_choosen)) {
            reset(target, ally, enemy);
            weaken(target, 6, ally, enemy, this);

            delete _choosen;
            _choosen = nullptr;
            return;
        }

        assert(false);
    };
};

BoneTalisman::BoneTalisman()
{
    id = "201598";
    name = "Bone Talisman";
    text = "Choose One: Resurrect a Bronze Beast or Cultist; or Heal an ally and Strengthen it by 3.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    rarity = Bronze;
    faction = Skellige;
    tags = { Item };

    _onPlaySpecial = [=](Field &ally, Field &) {
        auto *option1 = new BoneTalisman::Resurrect;
        copyCardText(this, option1);
        option1->text = "Resurrect a Bronze Beast or Cultist.";

        auto *option2 = new BoneTalisman::Buff;
        copyCardText(this, option2);
        option2->text = "Heal an ally and Strengthen it by 3.";

        startChoiceToSelectOption(ally, this, {option1, option2});
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (_options.size() > 0) {
            _choosen = target;
            acceptOptionAndDeleteOthers(this, target);

            if (dynamic_cast<BoneTalisman::Resurrect *>(target)) {
                startChoiceToTargetCard(ally, enemy, this, {isBronze, hasAnyOfTags({Beast, Cultist})}, AllyDiscard);
                return;
            }
            if (dynamic_cast<BoneTalisman::Buff *>(target)) {
                startChoiceToTargetCard(ally, enemy, this, {}, AllyBoard);
                return;
            }
            assert(false);
        }

        if (dynamic_cast<BoneTalisman::Resurrect *>(_choosen)) {
            playExistedCard(target, ally, enemy, this);

            delete _choosen;
            _choosen = nullptr;
            return;
        }
        if (dynamic_cast<BoneTalisman::Buff *>(_choosen)) {
            heal(target, ally, enemy);
            strengthen(target, 3, ally, enemy);

            delete _choosen;
            _choosen = nullptr;
            return;
        }
        assert(false);
    };
};

ShupeKnight::ShupeKnight()
{
    id = "201737";
    name = "Shupe: Knight";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 12;
    isDoomed = true;
    rarity = Gold;
    faction = Neutral;
    tags = { Ogroid };

    _onDeploy = [=](Field &ally, Field &) {
        auto *option1 = new ShupeKnight::Destroy;
        copyCardText(this, option1);
        option1->text = "Destroy enemies with 4 or less power.";

        auto *option2 = new ShupeKnight::Reset;
        copyCardText(this, option2);
        option2->text = "Reset a unit.";

        auto *option3 = new ShupeKnight::Duel;
        copyCardText(this, option3);
        option3->text = "Duel an enemy.";

        auto *option4 = new ShupeKnight::Strengthen;
        copyCardText(this, option4);
        option4->text = "Strengthen self to 25.";

        auto *option5 = new ShupeKnight::Resilient;
        copyCardText(this, option5);
        option5->text = "Resilent.";

        startChoiceToSelectOption(ally, this, {option1, option2, option3, option4, option5}, 1, 3);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (_options.size() > 0) {
            _choosen = target;
            acceptOptionAndDeleteOthers(this, target);

            if (dynamic_cast<ShupeKnight::Destroy *>(_choosen)) {
                for (Card *card : cardsFiltered(ally, enemy, {hasPowerXorLess(4)}, EnemyBoard))
                    putToDiscard(card, ally, enemy, this);
                delete _choosen;
                _choosen = nullptr;
                return;
            }

            if (dynamic_cast<ShupeKnight::Reset *>(_choosen)) {
                startChoiceToTargetCard(ally, enemy, this);
                return;
            }

            if (dynamic_cast<ShupeKnight::Duel *>(_choosen)) {
                startChoiceToTargetCard(ally, enemy, this, {}, EnemyBoard);
                return;
            }

            if (dynamic_cast<ShupeKnight::Strengthen *>(_choosen)) {
                strengthen(this, 25 - powerBase, ally, enemy);
                delete _choosen;
                _choosen = nullptr;
                return;
            }

            if (dynamic_cast<ShupeKnight::Resilient *>(_choosen)) {
                isResilient = true;
                delete _choosen;
                _choosen = nullptr;
                return;
            }

            assert(false);
        }

        if (dynamic_cast<ShupeKnight::Reset *>(_choosen)) {
            target->power = target->powerBase;
            delete _choosen;
            _choosen = nullptr;
            return;
        }

        if (dynamic_cast<ShupeKnight::Duel *>(_choosen)) {
            duel(this, target, ally, enemy);
            delete _choosen;
            _choosen = nullptr;
            return;
        }

        assert(false);
    };
};

Decoy::Decoy()
{
    id = "113201";
    name = "Decoy";
    text = "Replay a Bronze or Silver ally and boost it by 3.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    rarity = Silver;
    faction = Neutral;
    tags = { Tactics };

    _onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, { isBronzeOrSilver }, AllyBoard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        putToHand(target, ally, enemy);
        boost(target, 3, ally, enemy, this);
        playExistedCard(target, ally, enemy, this);
    };
};

FirstLight::FirstLight()
{
    id = "113303";
    name = "First Light";
    text = "Choose One: Boost all damaged allies under Hazards by 2 and clear all Hazards from your side; or Play a random Bronze unit from your deck.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    rarity = Bronze;
    faction = Neutral;
    tags = { Tactics };

    _onPlaySpecial = [=](Field &ally, Field &) {
        auto *option1 = new FirstLight::Clear;
        copyCardText(this, option1);
        option1->text = "Boost all damaged allies under Hazards by 2 and clear all Hazards from your side.";

        auto *option2 = new FirstLight::Play;
        copyCardText(this, option2);
        option2->text = "Play a random Bronze unit from your deck.";

        startChoiceToSelectOption(ally, this, {option1, option2});
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
         acceptOptionAndDeleteOthers(this, target);

         if (dynamic_cast<FirstLight::Clear *>(target)) {
             std::vector<Card *> damagedUnitsUnderHazards;
             clearAllHazards(ally, &damagedUnitsUnderHazards);
             for (Card *card : damagedUnitsUnderHazards)
                 boost(card, 2, ally, enemy, this);
             delete target;
             return;
         }

         if (dynamic_cast<FirstLight::Play *>(target)) {
             if (Card *card = random(cardsFiltered(ally, enemy, { isBronze, isUnit }, AllyDeck), ally.rng))
                 playExistedCard(card, ally, enemy, this);
             delete target;
             return;
         }

         assert(false);
    };
};

ClearSkies::ClearSkies()
{
    id = "113303";
    name = "Clear Skies";
    text = "Boost all damaged allies under Hazards by 2 and clear all Hazards from your side.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    rarity = Bronze;
    faction = Neutral;
    tags = { Tactics };

    _onPlaySpecial = [=](Field &ally, Field &enemy) {
        std::vector<Card *> damagedUnitsUnderHazards;
        clearAllHazards(ally, &damagedUnitsUnderHazards);
        for (Card *card : damagedUnitsUnderHazards)
            boost(card, 2, ally, enemy, this);
    };
};

Epidemic::Epidemic()
{
    id = "113308";
    name = "Epidemic";
    text = "Destroy all the Lowest units.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    rarity = Bronze;
    faction = Neutral;
    tags = { Organic, Spell };

    _onPlaySpecial = [=](Field &ally, Field &enemy) {
        for (Card *card : lowests(cardsFiltered(ally, enemy, {}, AnyBoard)))
            putToDiscard(card, ally, enemy, this);
    };
};

Moonlight::Moonlight()
{
    id = "200067";
    name = "Moonlight";
    text = "Choose One: Apply a Full Moon Boon; or Apply a Blood Moon Hazard.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    rarity = Bronze;
    faction = Monster;
    tags = { Hazard, Boon };

    _onPlaySpecial = [=](Field &ally, Field &) {
        auto *option1 = new Moonlight::FullMoon;
        copyCardText(this, option1);
        option1->name = "Full Moon";
        option1->text = "Apply a Boon to an allied row that boosts a random Beast or Vampire by 2 on turn start.";

        auto *option2 = new Moonlight::BloodMoon;
        copyCardText(this, option2);
        option2->name = "Blood Moon";
        option2->text = "Apply a Hazard to an enemy row that deals 2 damage to all units on contact.";

        startChoiceToSelectOption(ally, this, {option1, option2});
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &) {
        acceptOptionAndDeleteOthers(this, target);
        if (dynamic_cast<Moonlight::FullMoon *>(target)) {
            startChoiceToSelectAllyRow(ally, this);

        } else if (dynamic_cast<Moonlight::BloodMoon *>(target)) {
            startChoiceToSelectEnemyRow(ally, this);

        } else
            assert(false);

        delete target;
    };

    _onTargetRowAllyChoosen = [=](Field &ally, Field &enemy, const Row row) {
        applyRowEffect(ally, enemy, row, FullMoonEffect);
    };

    _onTargetRowEnemyChoosen = [=](Field &ally, Field &enemy, const Row row) {
        applyRowEffect(enemy, ally, row, BloodMoonEffect);
    };
};

CiriNova::CiriNova()
{
    id = "201626";
    name = "Ciri: Nova";
    text = "If you have exactly 2 copies of each Bronze card in your starting deck, set base power to 22.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/CIRI_CIRILLA_01040512.mp3",
        "https://gwent.one/audio/card/ob/en/CIRI_Q310_00579530.mp3",
        "https://gwent.one/audio/card/ob/en/CIRI_CIRILLA_01040548.mp3",
        "https://gwent.one/audio/card/ob/en/CIRI_Q111_00536478.mp3",
    };
    power = powerBase = 1;
    isDoomed = true;
    rarity = Gold;
    faction = Neutral;
    tags = { Cintra, Witcher };

    _onDeploy = [=](Field &ally, Field &enemy) {
        if (!hasExactTwoDuplicatesOfBronze(ally.deckStarting))
            return;

        strengthen(this, 22 - powerBase, ally, enemy);
    };
};

HaraldTheCripple::HaraldTheCripple()
{
    id = "200161";
    name = "Harald the Cripple";
    text = "Deal 1 damage to a random enemy on the opposite row. Repeat 9 times.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.196.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.197.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.198.mp3",
    };
    power = powerBase = 6;
    rarity = Gold;
    faction = Skellige;
    tags = { ClanAnCraite, Leader };

    _onDeploy = [=](Field &ally, Field &enemy) {
        Row row;
        Pos pos;
        if (!_findRowAndPos(this, ally, row, pos))
            return;
        for (int n = 0; n < 9; ++n)
            if (Card *card = random(enemy.row(row), ally.rng)) {
                damage(card, 1, ally, enemy, this);
            }
    };
};

Emissary::Emissary()
{
    id = "162314";
    name = "Emissary";
    text = "Look at 2 random Bronze units from your deck, then play 1.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/NIS1_VSET_00526372.mp3",
        "https://gwent.one/audio/card/ob/en/NIS1_Q002_01048548.mp3",
        "https://gwent.one/audio/card/ob/en/NIS1_VSET_00526356.mp3",
    };
    isLoyal = false;
    power = powerBase = 2;
    rarity = Bronze;
    faction = Nilfgaard;
    tags = { };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, randoms(cardsFiltered(ally, enemy, {isBronze, isUnit}, AllyDeckShuffled), 2, ally.rng));
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, this);
    };
};

CeallachDyffryn::CeallachDyffryn()
{
    id = "162213";
    name = "Ceallach Dyffryn";
    text = "Spawn an Ambassador, Assassin or Emissary.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.109.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.110.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.111.mp3",
    };
    power = powerBase = 2;
    rarity = Silver;
    faction = Nilfgaard;
    tags = { Officer };

    _onDeploy = [=](Field &ally, Field &) {
        startChoiceToSelectOption(ally, this, {new Ambassador(), new Assassin(), new Emissary()});
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        acceptOptionAndDeleteOthers(this, target);
        spawnNewCard(target, ally, enemy, this);
    };
};

Restore::Restore()
{
    id = "153201";
    name = "Restore";
    text = "Return a Bronze or Silver Skellige unit from your graveyard to your hand, add the Doomed category to it, and set its base power to 8. Then play a card.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    rarity = Silver;
    faction = Skellige;
    tags = { Spell };

    _onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilver, isUnit, isSkelligeFaction}, AllyDiscard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        putToHand(target, ally, enemy);
        target->isDoomed = true;
        target->powerBase = target->power = 8;
        playExistedCard(target, ally, enemy, this);
    };
};

DrummondQueensguard::DrummondQueensguard()
{
    id = "152307";
    name = "Drummond Queensguard";
    text = "Resurrect all copies of this unit on this row.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SWO5_Q205_00482375.mp3",
        "https://gwent.one/audio/card/ob/en/SWO5_FF201_00521383.mp3",
        "https://gwent.one/audio/card/ob/en/SWO5_FF201_00521512.mp3",
    };
    power = powerBase = 4;
    rarity = Bronze;
    faction = Skellige;
    tags = { ClanDrummond, Soldier };

    _onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *card : cardsFiltered(ally, enemy, {isCopy(name)}, AllyDiscard))
            moveExistedUnitToPos(card, rowAndPosToTheRight(this, ally, 1), ally, enemy, this);
    };
};

BranTuirseach::BranTuirseach()
{
    id = "200159";
    name = "Bran Tuirseach";
    text = "Discard up to 3 cards from your deck and Strengthen them by 1.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.193.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.194.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.195.mp3",
    };
    power = powerBase = 2;
    rarity = Gold;
    faction = Skellige;
    tags = { ClanTuirseach, Leader };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {}, AllyDeckShuffled, 3, true);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        putToDiscard(target, ally, enemy, this);
        if (!target->isSpecial)
            strengthen(target, 1, ally, enemy);
    };
};

DrummondWarmonger::DrummondWarmonger()
{
    id = "200036";
    name = "Drummond Warmonger";
    text = "Discard a Bronze card from your deck.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.5.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.6.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.7.mp3",
    };
    power = powerBase = 8;
    rarity = Bronze;
    faction = Skellige;
    tags = { ClanDrummond, Soldier };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isBronze}, AllyDeckShuffled);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        putToDiscard(target, ally, enemy, this);
    };
};

DimunPirate::DimunPirate()
{
    id = "152305";
    name = "Dimun Pirate";
    text = "Discard all copies of this unit from your deck.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SBD3_VSET_00526925.mp3",
        "https://gwent.one/audio/card/ob/en/SBD3_VSET_00527400.mp3",
        "https://gwent.one/audio/card/ob/en/SBD3_MQ2034_01013429.mp3",
    };
    power = powerBase = 11;
    rarity = Bronze;
    faction = Skellige;
    tags = { ClanDimun, Soldier };

    _onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *card : cardsFiltered(ally, enemy, {isCopy(name)}, AllyDeck))
            putToDiscard(card, ally, enemy, this);
    };
};

AnCraiteRaider::AnCraiteRaider()
{
    id = "152316";
    name = "An Craite Raider";
    text = "Whenever you Discard this unit, Resurrect it on a random row.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SGD1_CHAT_01024106.mp3",
        "https://gwent.one/audio/card/ob/en/SGD1_VSET_00541470.mp3",
        "https://gwent.one/audio/card/ob/en/SGD1_FF204_00523558.mp3",
    };
    power = powerBase = 4;
    rarity = Bronze;
    faction = Skellige;
    tags = { ClanAnCraite, Soldier };

    _onDiscard = [=](Field &ally, Field &enemy) {
        moveExistedUnitToPos(this, rowAndPosRandom(ally), ally, enemy, this);
    };
};

MadmanLugos::MadmanLugos()
{
    id = "152106";
    name = "Madman Lugos";
    text = "Discard a Bronze unit from your deck, then deal damage equal to its base power to an enemy.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/LUTM_Q210_00561116.mp3",
        "https://gwent.one/audio/card/ob/en/LUTM_SQ209_00593785.mp3",
        "https://gwent.one/audio/card/ob/en/LUTM_LUGOS_01016673.mp3",
        "https://gwent.one/audio/card/ob/en/LUTM_LUGOS_00437813.mp3",
    };
    power = powerBase = 6;
    rarity = Gold;
    faction = Skellige;
    tags = { ClanDrummond, Officer };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isBronze, isUnit}, AllyDeckShuffled);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (_discarded == nullptr) {
            _discarded = target;
            putToDiscard(target, ally, enemy, this);
            startChoiceToTargetCard(ally, enemy, this, {}, EnemyBoard);
            return;
        }
        damage(target, _discarded->powerBase, ally, enemy, this);
    };
};

Ermion::Ermion()
{
    id = "152103";
    name = "Ermion";
    text = "Draw 2 cards, then Discard 2 cards.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/MOUS_Q203_01040282.mp3",
        "https://gwent.one/audio/card/ob/en/MOUS_Q403_00566059.mp3",
        "https://gwent.one/audio/card/ob/en/MOUS_Q201_00439012.mp3",
        "https://gwent.one/audio/card/ob/en/MOUS_Q210_00558067.mp3",
    };
    power = powerBase = 10;
    rarity = Gold;
    faction = Skellige;
    tags = { ClanAnCraite, Support };

    _onDeploy = [=](Field &ally, Field &enemy) {
        drawACard(ally, enemy);
        drawACard(ally, enemy);
        startChoiceToTargetCard(ally, enemy, this, {}, AllyHand, 2);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        putToDiscard(target, ally, enemy, this);
    };
};

CerysFearless::CerysFearless()
{
    id = "201778";
    name = "Cerys: Fearless";
    text = "Resurrect the next unit you Discard.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/BECC_Q201_00500731.mp3",
        "https://gwent.one/audio/card/ob/en/BECC_Q201_00500712.mp3",
        "https://gwent.one/audio/card/ob/en/BECC_BECCA_01040277.mp3",
        "https://gwent.one/audio/card/ob/en/BECC_BECCA_01040275.mp3",
    };
    power = powerBase = 6;
    rarity = Gold;
    faction = Skellige;
    tags = { ClanAnCraite, Officer };

    _onDeploy = [=](Field &ally, Field &enemy) {
        setTimer(this, ally, enemy, 1);
    };

    _onOtherAllyDiscarded = [=](Card *other, Field &ally, Field &enemy) {
        if (other->isSpecial || !isOnBoard(this, ally))
            return;

        if (tick(this, ally, enemy))
            playExistedCard(other, ally, enemy, this);
    };
};

CerysAnCraite::CerysAnCraite()
{
    id = "200177";
    name = "Cerys An Craite";
    text = "When 4 units are Resurrected while this unit is in the graveyard, Resurrect it on a random row.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/BECC_Q201_00500731.mp3",
        "https://gwent.one/audio/card/ob/en/BECC_Q201_00500712.mp3",
        "https://gwent.one/audio/card/ob/en/BECC_BECCA_01040277.mp3",
        "https://gwent.one/audio/card/ob/en/BECC_BECCA_01040275.mp3",
    };
    power = powerBase = 6;
    rarity = Gold;
    faction = Skellige;
    tags = { ClanAnCraite, Officer };

    _onDiscard = [=](Field &ally, Field &enemy) {
        setTimer(this, ally, enemy, 4);
    };

    _onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
        setTimer(this, ally, enemy, 4);
    };

    _onOtherAllyResurrecteded = [=](Card *, Field &ally, Field &enemy) {
        if (!isIn(this, ally.discard))
            return;

        if (tick(this, ally, enemy))
            moveExistedUnitToPos(this, rowAndPosRandom(ally), ally, enemy, this);
    };
};

WoodlandSpirit::WoodlandSpirit()
{
    id = "132103";
    name = "Woodland Spirit";
    text = "Spawn 3 Wolves on the melee row and apply Impenetrable Fog to the opposite row.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 5;
    rarity = Gold;
    faction = Monster;
    tags = { Relict };

    _onDeploy = [=](Field &ally, Field &enemy) {
        Row row;
        Pos pos;
        if (!_findRowAndPos(this, ally, row, pos))
            return;
        applyRowEffect(enemy, ally, row, ImpenetrableFogEffect);
        for (int n = 0; n < 3; ++n)
            spawnNewUnitToPos(new Wolf(), rowAndPosLastInExactRow(ally, Meele), ally, enemy, this);
    };
};

Trollololo::Trollololo()
{
    id = "122209";
    name = "Trollololo";
    text = "9 Armor.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/TRL1_MQ1022_00411733.mp3",
        "https://gwent.one/audio/card/ob/en/TRL1_MQ1022_00468246.mp3",
        "https://gwent.one/audio/card/ob/en/TRL1_MQ1022_00466604.mp3",
        "https://gwent.one/audio/card/ob/en/TRL1_MQ1022_00468244.mp3",
        "https://gwent.one/audio/card/ob/en/TRL1_MQ1022_00468248.mp3",
    };
    power = powerBase = 11;
    rarity = Silver;
    faction = NothernRealms;
    tags = { Redania, Ogroid };

    _onDeploy = [=](Field &ally, Field &enemy) {
        gainArmor(this, 9, ally, enemy, this);
    };
};

PrinceStennis::PrinceStennis()
{
    id = "122208";
    name = "Prince Stennis";
    text = "Play the top non-Spying Bronze or Silver unit from your deck and give it 5 Armor. 3 Armor.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/VO_STEN_200046_0302.mp3",
        "https://gwent.one/audio/card/ob/en/VO_STEN_200098_0258.mp3",
        "https://gwent.one/audio/card/ob/en/VO_STEN_200046_0316.mp3",
    };
    power = powerBase = 3;
    rarity = Silver;
    faction = NothernRealms;
    tags = { Aedirn, Officer };

    _onDeploy = [=](Field &ally, Field &enemy) {
        gainArmor(this, 3, ally, enemy, this);
        const std::vector<Card *> cards = cardsFiltered(ally, enemy, {isNonSpying, isBronzeOrSilver, isUnit}, AllyDeck);
        if (cards.size() == 0)
            return;

        Card *target = cards.front();
        playExistedCard(target, ally, enemy, this);
        gainArmor(target, 5, ally, enemy, this);
    };
};

VincentMeis::VincentMeis()
{
    id = "200098";
    name = "Vincent Meis";
    text = "Destroy the Armor of all units, then boost self by half the value destroyed.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.203.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.202.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.201.mp3",
    };
    power = powerBase = 9;
    rarity = Silver;
    faction = NothernRealms;
    tags = { Beast, Cursed };

    _onDeploy = [=](Field &ally, Field &enemy) {
        int _armor = 0;
        for (Card *target: cardsFiltered(ally, enemy, {hasArmor}, AnyBoard)) {
            const int armorTarget = target->armor;
            damage(target, armorTarget, ally, enemy, this);
            _armor += armorTarget;
        }
        if (_armor)
            boost(this, _armor / 2, ally, enemy, this);
    };
};

Morkvarg::Morkvarg()
{
    id = "152209";
    name = "Morkvarg";
    text = "Whenever Discarded, Resurrect on a random row; and whenever destroyed, Resurrect in the same position. Then, Weaken self by half.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/MRKV_SQ201_00499647.mp3",
        "https://gwent.one/audio/card/ob/en/MRKV_SQ201_00501979.mp3",
        "https://gwent.one/audio/card/ob/en/MRKV_SQ201_00504630.mp3",
    };
    power = powerBase = 9;
    rarity = Silver;
    faction = Skellige;
    tags = { Beast, Cursed };

    _onDiscard = [=](Field &ally, Field &enemy) {
        if (weaken(this, int(std::ceil(powerBase / 2.0)), ally, enemy, this))
            return;

        moveExistedUnitToPos(this, rowAndPosRandom(ally), ally, enemy, this);
    };

    _onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &rowAndPos) {
        if (weaken(this, int(std::ceil(powerBase / 2.0)), ally, enemy, this))
            return;

        moveExistedUnitToPos(this, rowAndPos, ally, enemy, this);
    };
};

ArtefactCompression::ArtefactCompression()
{
    id = "200053";
    name = "Artefact Compression";
    text = "Transform a Bronze or Silver unit into a Jade Figurine.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    rarity = Silver;
    faction = Neutral;
    tags = { Spell };

    _onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilver});
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        transform(target, JadeFigurine(), ally, enemy, this);
    };
};

ArtefactCompression::JadeFigurine::JadeFigurine()
{
    name = "Jade Figurine";
    isDoomed = true;
    power = powerBase = 2;
    rarity = Bronze;
    faction = Neutral;
    tags = {};
}

HjalmarAnCraite::LordOfUndvik::LordOfUndvik()
{
    name = "Lord of Undvik";
    text = "Spying. Deathwish: Boost enemy Hjalmars by 10.";
    isLoyal = false;
    isDoomed = true;
    power = powerBase = 5;
    rarity = Silver;
    faction = Skellige;
    tags = { Ogroid };

    _onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
        for (Card *card : cardsFiltered(ally, enemy, {isCopy("Hjalmar an Craite")}, EnemyBoard))
            boost(card, 10, ally, enemy, this);
    };
};

HjalmarAnCraite::HjalmarAnCraite()
{
    id = "152101";
    name = "Hjalmar an Craite";
    text = "Spawn the Lord of Undvik on the opposite row.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/HJAL_HJALMAR_01037900.mp3",
        "https://gwent.one/audio/card/ob/en/HJAL_HJALMAR_01037904.mp3",
        "https://gwent.one/audio/card/ob/en/HJAL_HJALMAR_01037912.mp3",
        "https://gwent.one/audio/card/ob/en/HJAL_Q501_00568598.mp3",
    };
    power = powerBase = 16;
    rarity = Gold;
    faction = Skellige;
    tags = { ClanAnCraite, Officer };

    _onDeploy = [=](Field &ally, Field &enemy) {
        spawnNewUnitToPos(new LordOfUndvik(), rowAndPosLastInExactRow(enemy, _findRowAndPos(this, ally).row()), enemy, ally, this);
    };
};

Regis::Regis()
{
    id = "112104";
    name = "Regis";
    text = "Drain all boosts from a unit.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/REGI_Q702_01155490.mp3",
        "https://gwent.one/audio/card/ob/en/REGI_Q702_01155230.mp3",
        "https://gwent.one/audio/card/ob/en/REGI_Q702_01178597.mp3",
    };
    power = powerBase = 1;
    rarity = Gold;
    faction = Neutral;
    tags = { Vampire };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isBoosted}, AnyBoard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        const int x = target->power - target->powerBase;
        drain(target, x, ally, enemy, this);
    };
};

LethoOfGulet::LethoOfGulet()
{
    id = "162101";
    name = "Letho of Gulet";
    text = "Spying. Apply Lock status to 2 units on this row, then Drain all their power.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/LETO_Q403_00319901.mp3",
        "https://gwent.one/audio/card/ob/en/LETO_SQ102_00590678.mp3",
        "https://gwent.one/audio/card/ob/en/LETO_LETHO_01038588.mp3",
        "https://gwent.one/audio/card/ob/en/LETO_SQ102_00593857.mp3",
    };
    isLoyal = false;
    power = powerBase = 1;
    rarity = Gold;
    faction = Nilfgaard;
    tags = { Witcher };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isOnSameRow(&enemy, this)}, EnemyBoard, 2);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        lock(target, ally, enemy, this);
        drain(target, target->power, ally, enemy, this);
    };
};

AnCraiteLongship::AnCraiteLongship()
{
    id = "152314";
    name = "An Craite Longship";
    text = "Deal 2 damage to a random enemy. Repeat this ability whenever you Discard a card.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 7;
    rarity = Bronze;
    faction = Skellige;
    tags = { ClanAnCraite, Machine };

    _onDeploy = [=](Field &ally, Field &enemy) {
        if (Card *card = random(cardsFiltered(ally, enemy, {}, EnemyBoard), ally.rng))
            damage(card, 2, ally, enemy, this);
    };

    _onOtherAllyDiscarded = [=](Card *, Field &ally, Field &enemy) {
        if (isOnBoard(this, ally))
            AnCraiteLongship::onDeploy(ally, enemy);
    };
};

TuirseachVeteran::TuirseachVeteran()
{
    id = "200046";
    name = "Tuirseach Veteran";
    text = "Strengthen all your other Clan Tuirseach units in hand, deck, and on board by 1.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.410.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.411.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.412.mp3",
    };
    power = powerBase = 7;
    rarity = Bronze;
    faction = Skellige;
    tags = { ClanTuirseach, Support };

    _onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *card : cardsFiltered(ally, enemy, {hasTag(ClanTuirseach), otherThan(this)}, AllyBoardHandDeck))
            strengthen(card, 1, ally, enemy);
    };
};

TuirseachHunter::TuirseachHunter()
{
    id = "152304";
    name = "Tuirseach Hunter";
    text = "Deal 5 damage.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SGD6_VSET_00544501.mp3",
        "https://gwent.one/audio/card/ob/en/SGD6_VSET_00544569.mp3",
        "https://gwent.one/audio/card/ob/en/SGD6_VSET_00544491.mp3",
    };
    power = powerBase = 6;
    rarity = Bronze;
    faction = Skellige;
    tags = { ClanTuirseach, Soldier };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        damage(target, 5, ally, enemy, this);
    };
};

Udalryk::Udalryk()
{
    id = "152214";
    name = "Udalryk";
    text = "Spying. Single-Use: Look at 2 cards from your deck. Draw one and Discard the other.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 13;
    isLoyal = false;
    timer = 1;
    rarity = Silver;
    faction = Skellige;
    tags = { ClanBrokvar, Cursed, Agent };

    _onDeploy = [=](Field &ally, Field &enemy) {
        if (tick(this, ally, enemy))
            startChoiceToTargetCard(ally, enemy, this, _drawn = randoms(cardsFiltered(ally, enemy, {}, AllyDeck), 2, ally.rng));
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        putToHand(target, ally, enemy);
        for (Card *card : _drawn)
            if (card != target)
                putToDiscard(card, ally, enemy, this);

        _drawn.clear();
    };
};

BloodcurdlingRoar::BloodcurdlingRoar()
{
    id = "152406";
    name = "Bloodcurdling Roar";
    text = "Destroy an ally. Spawn a bear.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    rarity = Bronze;
    faction = Neutral;
    tags = { Organic };

    _onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {}, AllyBoard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        putToDiscard(target, ally, enemy, this);
        spawnNewCard(new Bear(), ally, enemy, this);
    };
};

Gremist::Gremist()
{
    id = "152206";
    name = "Gremist";
    text = "Spawn Torrential Rain, Clear Skies or Bloodcurdling Roar.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.828.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.829.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.830.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.834.mp3",
    };
    power = powerBase = 4;
    rarity = Silver;
    faction = Skellige;
    tags = { Support };

    _onDeploy = [=](Field &ally, Field &) {
        startChoiceToSelectOption(ally, this, {new TorrentialRain(), new ClearSkies(), new BloodcurdlingRoar()});
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        acceptOptionAndDeleteOthers(this, target);
        spawnNewCard(target, ally, enemy, this);
    };
};

Operator::Operator()
{
    id = "112208";
    name = "Operator";
    text = "Single-Use, Truce: Make a default copy of a Bronze unit in your hand for both players.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/VO_OPRT_204113_0001.mp3",
        "https://gwent.one/audio/card/ob/en/VO_OPRT_204113_0012.mp3",
    };
    power = powerBase = 5;
    timer = 1;
    rarity = Silver;
    faction = Neutral;
    tags = { Mage };

    _onDeploy = [=](Field &ally, Field &enemy) {
        if (ally.passed || enemy.passed)
            return;
        if (tick(this, ally, enemy))
            startChoiceToTargetCard(ally, enemy, this, {isBronze, isUnit}, AllyHand);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        Card *copyAlly = target->defaultCopy();
        ally.cardsAdded.push_back(copyAlly);
        putToHand(copyAlly, ally, enemy);

        Card *copyEnemy = target->defaultCopy();
        enemy.cardsAdded.push_back(copyEnemy);
        putToHand(copyEnemy, enemy, ally);
    };
};

ZoriaRunestone::ZoriaRunestone()
{
    id = "201582";
    name = "Zoria Runestone";
    text = "Create a Bronze or Silver Northern Realms card.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    rarity = Silver;
    faction = NothernRealms;
    tags = { Alchemy, Item };

    _onPlaySpecial = [=](Field &ally, Field &) {
        startChoiceCreateOptions(ally, this, {isBronzeOrSilver, isNothernRealmsFaction});
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        acceptOptionAndDeleteOthers(this, target);
        spawnNewCard(target, ally, enemy, this);
    };
};

Renew::Renew()
{
    id = "113316";
    name = "Renew";
    text = "Resurrect a non-Leader Gold unit.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    rarity = Gold;
    faction = Neutral;
    tags = { Spell };

    _onPlaySpecial = [=](Field &ally, Field &) {
        startChoiceCreateOptions(ally, this, {isGold, isNonLeader}, AllyDiscard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, this);
    };
};

EistTuirseach::EistTuirseach()
{
    id = "201597";
    name = "Eist Tuirseach";
    text = "Spawn a Bronze Clan Tuirseach Soldier.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.47.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.48.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.49.mp3",
    };
    power = powerBase = 5;
    rarity = Gold;
    faction = Skellige;
    tags = { ClanTuirseach, Leader };

    _onDeploy = [=](Field &ally, Field &) {
        startChoiceToSelectOption(ally, this, {new TuirseachArcher, new TuirseachAxeman, new TuirseachBearmaster, new TuirseachHunter, new TuirseachSkirmisher});
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        acceptOptionAndDeleteOthers(this, target);
        spawnNewCard(target, ally, enemy, this);
    };
};

TuirseachAxeman::TuirseachAxeman()
{
    id = "152312";
    name = "Tuirseach Axeman";
    text = "Whenever an enemy on the opposite row is damaged, boost self by 1. 2 Armor.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.807.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.808.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.809.mp3",
    };
    power = powerBase = 6;
    rarity = Bronze;
    faction = Skellige;
    tags = { ClanTuirseach, Soldier };

    _onDeploy = [=](Field &ally, Field &enemy) {
        gainArmor(this, 2, ally, enemy, this);
    };

    _onOtherEnemyDamaged = [=](Card *other, Field &ally, Field &enemy) {
        Pos _;
        Row row;
        if (!_findRowAndPos(other, enemy, row, _))
            return;
        if (isIn(this, ally.row(row)))
            boost(this, 1, ally, enemy, this);
    };
};

TuirseachSkirmisher::TuirseachSkirmisher()
{
    id = "152313";
    name = "Tuirseach Skirmisher";
    text = "Whenever this unit is Resurrected, Strengthen it by 3.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SGD2_VSET_00165758.mp3",
        "https://gwent.one/audio/card/ob/en/SGD2_VSET_00526547.mp3",
        "https://gwent.one/audio/card/ob/en/SGD2_CHAT2_00165400.mp3",
    };
    power = powerBase = 8;
    rarity = Bronze;
    faction = Skellige;
    tags = { ClanTuirseach, Soldier };

    _onDeployFromDiscard = [=](Field &ally, Field &enemy) {
        strengthen(this, 3, ally, enemy);
    };
};

Derran::Derran()
{
    id = "201646";
    name = "Derran";
    text = "Whenever an enemy is damaged, boost self by 1.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.232.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.233.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.234.mp3",
    };
    power = powerBase = 6;
    rarity = Silver;
    faction = Skellige;
    tags = { ClanTuirseach, Cursed };

    _onOtherEnemyDamaged = [=](Card *, Field &ally, Field &enemy) {
        if (isOnBoard(this, ally))
            boost(this, 1, ally, enemy, this);
    };
};

Roach::Roach()
{
    id = "112210";
    name = "Roach";
    text = "Whenever you play a Gold unit from your hand, Summon this unit to a random row.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 4;
    rarity = Silver;
    faction = Neutral;
    tags = { Beast };

    _onOtherAllyPlayedFromHand = [=](Card *other, Field &ally, Field &enemy) {
        if (other->rarity != Gold)
            return;

        if (!isIn(this, ally.deck))
            return;

        spawnNewUnitToPos(this, rowAndPosRandom(ally), ally, enemy, this);
    };
};

JanCalveit::JanCalveit()
{
    id = "200164";
    name = "Jan Calveit";
    text = "Look at the top 3 cards from your deck, then play 1.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.55.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.56.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.57.mp3",
    };
    power = powerBase = 5;
    rarity = Gold;
    faction = Nilfgaard;
    tags = { Officer, Leader };

    _onDeploy = [=](Field &ally, Field &enemy) {
        const std::vector<Card *> topThreeCards(ally.deck.begin(), ally.deck.begin() + std::min(int(ally.deck.size()), 3));
        startChoiceToTargetCard(ally, enemy, this, topThreeCards);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, this);
    };
};

CahirDyffryn::CahirDyffryn()
{
    id = "162104";
    name = "Cahir Dyffryn";
    text = "Resurrect a Leader.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.69.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.70.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.71.mp3",
    };
    power = powerBase = 1;
    isDoomed = true;
    rarity = Gold;
    faction = Nilfgaard;
    tags = { Officer };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {hasTag(Leader)}, AllyDiscard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, this);
    };
};

LethoKingslayer::LethoKingslayer()
{
    id = "201603";
    name = "Letho: Kingslayer";
    text = "Choose One: Destroy an enemy Leader, then boost self by 5; or Play a Bronze or Silver Tactic from your deck.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/LETO_Q403_00319901.mp3",
        "https://gwent.one/audio/card/ob/en/LETO_SQ102_00590678.mp3",
        "https://gwent.one/audio/card/ob/en/LETO_LETHO_01038588.mp3",
        "https://gwent.one/audio/card/ob/en/LETO_SQ102_00593857.mp3",
    };
    power = powerBase = 5;
    rarity = Gold;
    faction = Nilfgaard;
    tags = { Witcher };

    _onDeploy = [=](Field &ally, Field &) {
        auto *option1 = new LethoKingslayer::Destroy;
        copyCardText(this, option1);
        option1->text = "Destroy an enemy Leader, then boost self by 5.";

        auto *option2 = new LethoKingslayer::Play;
        copyCardText(this, option2);
        option2->text = "Play a Bronze or Silver Tactic from your deck.";

        startChoiceToSelectOption(ally, this, {option1, option2});
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (_options.size() > 0) {
            _choosen = target;
            acceptOptionAndDeleteOthers(this, target);

            if (dynamic_cast<LethoKingslayer::Destroy *>(_choosen)) {
                startChoiceToTargetCard(ally, enemy, this, {hasTag(Leader)}, EnemyBoard);
                return;
            }

            if (dynamic_cast<LethoKingslayer::Play *>(_choosen)) {
                startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilver, hasTag(Tactics)}, AllyDeckShuffled);
                return;
            }

            assert(false);
        }

        if (dynamic_cast<LethoKingslayer::Destroy *>(_choosen)) {
            putToDiscard(target, ally, enemy, this);
            boost(this, 5, ally, enemy, this);

            delete _choosen;
            _choosen = nullptr;
            return;
        }

        if (dynamic_cast<LethoKingslayer::Play *>(_choosen)) {
            playExistedCard(target, ally, enemy, this);

            delete _choosen;
            _choosen = nullptr;
            return;
        }

        assert(false);
    };
};

KingHenselt::KingHenselt()
{
    id = "200170";
    name = "King Henselt";
    text = "Choose a Bronze Machine or Kaedweni ally and play all copies of it from your deck. Crew.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/VO_HSLT_200098_0265.mp3",
        "https://gwent.one/audio/card/ob/en/VO_HSLT_200497_0001.mp3",
        "https://gwent.one/audio/card/ob/en/VO_HSLT_200098_0254.mp3",
    };
    power = powerBase = 3;
    rarity = Gold;
    faction = NothernRealms;
    tags = { Kaedwen, Leader };

    _onDeploy = [=](Field &ally, Field &enemy) {
        isCrew = true;
        startChoiceToTargetCard(ally, enemy, this, {isBronze, hasAnyOfTags({Machine, Kaedwen})}, AllyBoard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        for (Card *copy : findCopies(target, ally.deck))
            playExistedCard(copy, ally, enemy, this);
    };
};

BloodyBaron::BloodyBaron()
{
    id = "122101";
    name = "Bloody Baron";
    text = "If in hand, deck, or on board, boost self by 1 whenever an enemy is destroyed.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/BARN_Q103_00473473.mp3",
        "https://gwent.one/audio/card/ob/en/BARN_Q107_00515406.mp3",
        "https://gwent.one/audio/card/ob/en/BARN_BARON_00402523.mp3",
        "https://gwent.one/audio/card/ob/en/BARN_Q102_00408798.mp3",
        "https://gwent.one/audio/card/ob/en/BARN_Q103_00487067.mp3",
    };
    power = powerBase = 9;
    rarity = Gold;
    faction = NothernRealms;
    tags = { Temeria, Officer };

    _onOtherEnemyDestroyed = [=](Card *, Field &ally, Field &enemy) {
        if (isOnBoard(this, ally) || isIn(this, ally.deck) || isIn(this, ally.hand))
            boost(this, 1, ally, enemy, this);
    };
};

Dethmold::Dethmold()
{
    id = "122207";
    name = "Dethmold";
    text = "Spawn Torrential Rain, Clear Skies or Alzur's Thunder.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/VO_DETM_200219_0001.mp3",
        "https://gwent.one/audio/card/ob/en/VO_DETM_200182_0001.mp3",
        "https://gwent.one/audio/card/ob/en/VO_DETM_200338_0412.mp3",
    };
    power = powerBase = 4;
    rarity = Silver;
    faction = NothernRealms;
    tags = { Kaedwen, Mage };

    _onDeploy = [=](Field &ally, Field &) {
        startChoiceToSelectOption(ally, this, {new TorrentialRain(), new ClearSkies(), new AlzursThunder()});
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        acceptOptionAndDeleteOthers(this, target);
        spawnNewCard(target, ally, enemy, this);
    };
};

RonvidTheIncessant::RonvidTheIncessant()
{
    id = "200529";
    name = "Ronvid the Incessant";
    text = "Resurrect on a random row with 1 power on turn end. Crew.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.401.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.402.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.403.mp3",
    };
    power = powerBase = 11;
    rarity = Silver;
    faction = NothernRealms;
    tags = { Kaedwen, Soldier };

    _onDeploy = [=](Field &, Field &) {
        isCrew = true;
    };

    _onTurnEnd = [=](Field &, Field &) {
        // FIXME: ability is missing
    };
};

HubertRejk::HubertRejk()
{
    id = "200088";
    name = "Hubert Rejk";
    text = "Drain all boosts from units in your deck.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.177.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.175.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.176.mp3",
    };
    power = powerBase = 7;
    rarity = Silver;
    faction = NothernRealms;
    tags = { Vampire };

    _onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *card : cardsFiltered(ally, enemy, {isBoosted}, AllyDeck))
            drain(card, card->power - card->powerBase, ally, enemy, this);
    };
};

CrachAnCraite::CrachAnCraite()
{
    id = "200160";
    name = "Crach an Craite";
    text = "Strengthen the Highest non-Spying Bronze or Silver unit in your deck by 2 and play it.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/CRCH_CRACH_01040579.mp3",
        "https://gwent.one/audio/card/ob/en/CRCH_CRACH_01040589.mp3",
        "https://gwent.one/audio/card/ob/en/CRCH_CRACH_01040591.mp3",
        "https://gwent.one/audio/card/ob/en/CRCH_CRACH_01001923.mp3",
    };
    power = powerBase = 5;
    faction = Skellige;
    rarity = Gold;
    tags = { ClanAnCraite, Leader };

    _onDeploy = [=](Field &ally, Field &enemy) {
        if (Card *card = highest(cardsFiltered(ally, enemy, {isUnit, isBronzeOrSilver, isNonSpying}, AllyDeck), ally.rng)) {
            strengthen(card, 2, ally, enemy);
            playExistedCard(card, ally, enemy, this);
        }
    };
};

BirnaBran::BirnaBran()
{
    id = "152105";
    name = "Birna Bran";
    text = "Apply Skellige Storm to an enemy row.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.206.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.207.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.205.mp3",
    };
    power = powerBase = 6;
    faction = Skellige; 
    rarity = Gold;
    tags = { ClanTuirseach, Officer };

    _onDeploy = [=](Field &ally, Field &) {
        startChoiceToSelectEnemyRow(ally, this);
    };

    _onTargetRowEnemyChoosen = [=](Field &ally, Field &enemy, const Row row) {
        applyRowEffect(enemy, ally, row, SkelligeStormEffect);
    };
};

Coral::Coral()
{
    id = "152107";
    name = "Coral";
    text = "Transform a Bronze or Silver unit into a Jade Figurine.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.202.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.204.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.203.mp3",
    };
    power = powerBase = 5;
    faction = Skellige; 
    rarity = Gold;
    tags = { Mage };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilver, isUnit}, AnyBoard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        transform(target, ArtefactCompression::JadeFigurine(), ally, enemy, this);
    };
};

Kambi::Hemdall::Hemdall()
{
    id = "152402";
    name = "Hemdall";
    text = "Destroy all other units and clear all Boons and Hazards.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.199.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.201.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.200.mp3"
    };
    isDoomed = true;
    power = powerBase = 20;
    faction = Skellige;
    rarity = Gold;
    tags = {};

    _onDeploy = [=](Field &ally, Field &enemy) {
        for (const Row row : std::vector<Row>{Meele, Range, Seige}) {
            ally.rowEffect(row) = NoRowEffect;
            enemy.rowEffect(row) = NoRowEffect;
        }
        for (Card *card : cardsFiltered(ally, enemy, {}, AnyBoard))
            putToDiscard(card, ally, enemy, this);
    };
};

Vabjorn::Vabjorn()
{
    id = "200028";
    name = "Vabjorn";
    text = "Deal 2 damage to an enemy. If it was already damaged, destroy it instead.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.211.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.213.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.214.mp3",
    };
    power = powerBase = 11;
    faction = Skellige;
    rarity = Gold;
    tags = { Cursed, Cultist };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {}, EnemyBoard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (isDamaged(target))
            putToDiscard(target, ally, enemy, this);
        else
            damage(target, 2, ally, enemy, this);
    };
};

BlueboyLugos::BlueboyLugos()
{
    id = "152201";
    name = "Blueboy Lugos";
    text = "Spawn a Spectral Whale on an enemy row.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/LUTG_SQ209_00594723.mp3",
        "https://gwent.one/audio/card/ob/en/LUTG_LUGOS_01038779.mp3",
    };
    power = powerBase = 9;
    faction = Skellige;
    rarity = Silver;
    tags = { ClanDrummond, Soldier };

    _onDeploy = [=](Field &ally, Field &enemy) {
        spawnNewCard(new SpectralWhale(), ally, enemy, this);
    };
};

DjengeFrett::DjengeFrett()
{
    id = "152203";
    name = "Djenge Frett";
    text = "Deal 1 damage to 2 allies and Strengthen self by 2 for each.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.806.mp3",
        "https://gwent.one/audio/card/ob/en/SWR3_MQ2013_00349800.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.804.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.805.mp3",
    };
    power = powerBase = 10;
    faction = Skellige;
    rarity = Silver;
    tags = { Soldier, ClanDimun };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {}, AllyBoard, 2);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        damage(target, 1, ally, enemy, this);
        strengthen(this, 2, ally, enemy);
    };
};

DonarAnHindar::DonarAnHindar()
{
    id = "152204";
    name = "Donar an Hindar";
    text = "Toggle a unit's Lock status, then move a Bronze unit from your opponent's graveyard to yours.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/DONR_Q206_00587479.mp3",
        "https://gwent.one/audio/card/ob/en/DONR_DONAR_01037057.mp3",
        "https://gwent.one/audio/card/ob/en/DONR_DONAR_01037055.mp3",
    };
    power = powerBase = 8;
    faction = Skellige;
    rarity = Silver;
    tags = { ClanHeymaey, Officer };
};

DraigBonDhu::DraigBonDhu()
{
    id = "152205";
    name = "Draig Bon-Dhu";
    text = "Strengthen 2 non-Leader units in your graveyard by 3.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SBR1_VSET_00527986.mp3",
        "https://gwent.one/audio/card/ob/en/SBR1_VSET_00528002.mp3",
    };
    power = powerBase = 6;
    faction = Skellige;
    rarity = Silver;
    tags = { Support };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isNonLeader, isUnit}, AllyDiscard, 2);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        strengthen(target, 3, ally, enemy);
    };
};

HolgerBlackhand::HolgerBlackhand()
{
    id = "152207";
    name = "Holger Blackhand";
    text = "Deal 6 damage. If the unit was destroyed, Strengthen the Highest unit in your graveyard by 3.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/HOLG_Q201_00387298.mp3",
        "https://gwent.one/audio/card/ob/en/HOLG_HOLGER_01038014.mp3",
        "https://gwent.one/audio/card/ob/en/HOLG_HOLGER_01038016.mp3",
    };
    power = powerBase = 6;
    faction = Skellige;
    rarity = Silver;
    tags = { ClanDimun, Officer };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {}, AnyBoard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (damage(target, 6, ally, enemy, this))
            if (Card *card = highest(ally.discard, ally.rng))
                strengthen(card, 3, ally, enemy);
    };
};

JuttaAnDimun::JuttaAnDimun()
{
    id = "152208";
    name = "Jutta an Dimun";
    text = "Deal 1 damage to self.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SWO4_MQ2038_00509731.mp3",
        "https://gwent.one/audio/card/ob/en/SWO4_MQ2038_00507987.mp3",
        "https://gwent.one/audio/card/ob/en/SWO4_MQ2038_00509565.mp3",
    };
    power = powerBase = 13;
    faction = Skellige;
    rarity = Silver;
    tags = { ClanDimun, Soldier };

    _onDeploy = [=](Field &ally, Field &enemy) {
        damage(this, 1, ally, enemy, this);
    };
};

SavageBear::SavageBear()
{
    id = "152210";
    name = "Savage Bear";
    text = "Whenever a unit is played from either hand on your opponent's side, deal 1 damage to it.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 9;
    faction = Skellige;
    rarity = Bronze;
    tags = { Beast, Cursed };

    _onOtherEnemyPlayedFromHand = [=](Card *other, Field &ally, Field &enemy) {
        if (isOnBoard(this, ally))
            damage(other, 1, ally, enemy, this);
    };
};

SvanrigeTuirseach::SvanrigeTuirseach()
{
    id = "152213";
    name = "Svanrige Tuirseach";
    text = "Draw a card, then Discard a card.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.209.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.210.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.208.mp3",
        "https://gwent.one/audio/card/ob/en/SVAN_Q210_00558425.mp3",
        "https://gwent.one/audio/card/ob/en/SVAN_Q210_01069128.mp3",
    };
    power = powerBase = 9;
    faction = Skellige;
    rarity = Silver;
    tags = { ClanTuirseach, Officer };

    _onDeploy = [=](Field &ally, Field &enemy) {
        if (drawACard(ally, enemy))
            startChoiceToTargetCard(ally, enemy, this, {}, AllyHand);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        putToDiscard(target, ally, enemy, this);
    };
};

Skjall::Skjall()
{
    id = "200212";
    name = "Skjall";
    text = "Play a random Bronze or Silver Cursed unit from your deck.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.822.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.823.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.825.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.827.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.824.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.826.mp3",
    };
    power = powerBase = 5;
    faction = Skellige;
    rarity = Silver;
    tags = { ClanHeymaey, Cursed };

    _onDeploy = [=](Field &ally, Field &enemy) {
        if (Card *card = random(cardsFiltered(ally, enemy, {isUnit, isBronzeOrSilver, hasTag(Cursed)}, AllyDeck), ally.rng))
            playExistedCard(card, ally, enemy, this);
    };
};

HaraldHoundsnout::HaraldHoundsnout()
{
    id = "200043";
    name = "Harald Houndsnout";
    text = "Spawn Wilfred to the left of this unit, Wilhelm to the right, and Wilmar on the opposite row.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.130.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.131.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.129.mp3",
    };
    power = powerBase = 6;
    faction = Skellige;
    rarity = Silver;
    tags = { ClanTordarroch, Cursed };

    _onDeploy = [=](Field &ally, Field &enemy) {
        spawnNewUnitToPos(new Wilfred(), rowAndPosToTheLeft(this, ally, 1), ally, enemy, this);
        spawnNewUnitToPos(new Wilhelm(), rowAndPosToTheRight(this, ally, 1), ally, enemy, this);
        spawnNewUnitToPos(new Wilmar(), rowAndPosLastInExactRow(enemy, _findRowAndPos(this, ally).row()), enemy, ally, this);
    };
};

HaraldHoundsnout::Wilfred::Wilfred()
{
    name = "Wilfred";
    text = "Deathwish: damage all unit on the opposite row by 1.";
    power = powerBase = 1;
    faction = Skellige;
    rarity = Bronze;
    isDoomed = true;

    _onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &rowAndPos) {
        for (Card *card : enemy.row(rowAndPos.row()))
            damage(card, 1, ally, enemy, this);
    };
};

HaraldHoundsnout::Wilhelm::Wilhelm()
{
    name = "Wilhelm";
    text = "Deathwish: strengthen a random ally by 3.";
    power = powerBase = 1;
    faction = Skellige;
    rarity = Bronze;
    isDoomed = true;

    _onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
        if (Card *card = random(cardsFiltered(ally, enemy, {}, AllyBoard), ally.rng))
            strengthen(card, 3, ally, enemy);
    };
};

HaraldHoundsnout::Wilmar::Wilmar()
{
    name = "Wilmar";
    text = "Deathwish: spawn a Bear on a random opponent row.";
    power = powerBase = 1;
    faction = Skellige;
    rarity = Bronze;
    isDoomed = true;

    _onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
        spawnNewUnitToPos(new Bear(), rowAndPosRandom(enemy), ally, enemy, this);
    };
};

Yoana::Yoana()
{
    id = "201644";
    name = "Yoana";
    text = "Heal an ally, then boost it by the amount Healed.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.20.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.24.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.22.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.21.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.23.mp3",
    };
    power = powerBase = 6;
    faction = Skellige;
    rarity = Silver;
    tags = { ClanTordarroch, Support };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isUnit, isDamaged}, AllyBoard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        const int x = target->powerBase - target->power;
        heal(target, ally, enemy);
        boost(target, x, ally, enemy, this);
    };
};

AnCraiteBlacksmith::AnCraiteBlacksmith()
{
    id = "152311";
    name = "An Craite Blacksmith";
    text = "Strengthen an ally by 2 and give it 2 Armor.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAR3_VSET_00550878.mp3",
        "https://gwent.one/audio/card/ob/en/SAR3_CHAT_01050115.mp3",
        "https://gwent.one/audio/card/ob/en/SAR3_VSET_00550859.mp3",
    };
    power = powerBase = 9;
    faction = Skellige;
    rarity = Bronze;
    tags = { ClanAnCraite, Support };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {}, AllyBoard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        strengthen(target, 2, ally, enemy);
        gainArmor(target, 2, ally, enemy, this);
    };
};

AnCraiteWarcrier::AnCraiteWarcrier()
{
    id = "113313";
    name = "An Craite Warcrier";
    text = "Boost an ally by half its power.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.327.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.330.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.329.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.326.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.328.mp3",
    };
    power = powerBase = 5;
    faction = Skellige;
    rarity = Bronze;
    tags = { ClanAnCraite, Support};

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {}, AllyBoard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        boost(target, int(std::floor(target->power / 2.0)), ally, enemy, this);
    };
};

AnCraiteWarrior::AnCraiteWarrior()
{
    id = "152303";
    name = "An Craite Warrior";
    text = "Deal 1 damage to self.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SGD2_CHAT2_00165312.mp3",
        "https://gwent.one/audio/card/ob/en/SGD2_VSET_00541769.mp3",
        "https://gwent.one/audio/card/ob/en/SGD2_Q208_01071227.mp3",
    };
    power = powerBase = 12;
    faction = Skellige;
    rarity = Bronze;
    tags = { ClanAnCraite, Soldier };

    _onDeploy = [=](Field &ally, Field &enemy) {
        damage(this, 1, ally, enemy, this);
    };
};

BerserkerMarauder::BerserkerMarauder()
{
    id = "152302";
    name = "Berserker Marauder";
    text = "Boost self by 1 for each damaged or Cursed ally.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SBE1_VSET_00536097.mp3",
        "https://gwent.one/audio/card/ob/en/SBE1_Q206_00413021.mp3",
        "https://gwent.one/audio/card/ob/en/SBE1_VSET_00536089.mp3",
    };
    power = powerBase = 9;
    faction = Skellige;
    rarity = Bronze;
    tags = { Cursed, Soldier, Cultist };

    _onDeploy = [=](Field &ally, Field &enemy) {
        const auto isDamagedOrCursed = [=](Card *card) {
            return (card != this) && (isDamaged(card) || hasTag(card, Cursed));
        };
        const int nUnits = int(cardsFiltered(ally, enemy, {isDamagedOrCursed}, AllyBoard).size());
        if (nUnits)
            boost(this, nUnits, ally, enemy, this);
    };
};

DimunPirateCaptain::DimunPirateCaptain()
{
    id = "152306";
    name = "Dimun Pirate Captain";
    text = "Play a different Bronze Dimun unit from your deck.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SBD1_MQ2003_01054136.mp3",
        "https://gwent.one/audio/card/ob/en/SBD1_Q202_00307483.mp3",
        "https://gwent.one/audio/card/ob/en/SBD1_MQ2002_00442097.mp3",
        "https://gwent.one/audio/card/ob/en/SBD1_MQ2034_01028167.mp3",
    };
    power = powerBase = 1;
    faction = Skellige;
    rarity = Bronze;
    tags = { ClanDimun, Officer };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isBronze, otherThan(name), hasTag(ClanDimun)}, AllyDeckShuffled);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, this);
    };
};

DimunSmuggler::DimunSmuggler()
{
    id = "200146";
    name = "Dimun Smuggler";
    text = "Return a Bronze unit from your graveyard to your deck.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.76.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.75.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.77.mp3",
    };
    power = powerBase = 10;
    faction = Skellige;
    rarity = Bronze;
    tags = { ClanDimun, Soldier };
};

DrummondShieldmaid::DrummondShieldmaid()
{
    id = "152318";
    name = "Drummond Shieldmaid";
    text = "Summon all copies of this unit to this row.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.2.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.1.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.3.mp3",
    };
    power = powerBase = 3;
    faction = Skellige;
    rarity = Bronze;
    tags = { ClanDrummond, Soldier };

    // TODO: test an ability
    _onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *copy : cardsFiltered(ally, enemy, {isCopy(this->name)}, AllyDeck))
            moveExistedUnitToPos(copy, _findRowAndPos(this, ally), ally, enemy, this);
    };
};

HeymaeyFlaminica::HeymaeyFlaminica()
{
    id = "200147";
    name = "Heymaey Flaminica";
    text = "Clear Hazards from the row and move 2 allies to it.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.89.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.88.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.87.mp3",
    };
    power = powerBase = 10;
    faction = Skellige;
    rarity = Bronze;
    tags = { ClanHeymaey, Support };
};


HeymaeyHerbalist::HeymaeyHerbalist()
{
    id = "200081";
    name = "Heymaey Herbalist";
    text = "Play a random Bronze Organic or Hazard card from your deck.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.121.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.123.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.122.mp3",
    };
    power = powerBase = 3;
    faction = Skellige;
    rarity = Bronze;
    tags = { ClanHeymaey, Support };

    _onDeploy = [=](Field &ally, Field &enemy) {
        if (Card *target = random(cardsFiltered(ally, enemy, {isBronze, hasAnyOfTags({Organic, Hazard})}, AllyDeck), ally.rng))
            playExistedCard(target, ally, enemy, this);
    };
};

HeymaeyProtector::HeymaeyProtector()
{
    id = "200149";
    name = "Heymaey Protector";
    text = "Play a Bronze Item from your deck.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.80.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.81.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.79.mp3",
    };
    power = powerBase = 2;
    faction = Skellige;
    rarity = Bronze;
    tags = { ClanHeymaey, Soldier };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isBronze, hasTag(Item)}, AllyDeck);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, this);
    };
};

HeymaeySkald::HeymaeySkald()
{
    id = "152308";
    name = "Heymaey Skald";
    text = "Boost all allies from a Clan of your choice by 1.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/DROG_Q206_01072830.mp3",
        "https://gwent.one/audio/card/ob/en/DROG_BARD_01036857.mp3",
        "https://gwent.one/audio/card/ob/en/DROG_Q206_00329460.mp3",
    };
    power = powerBase = 9;
    faction = Skellige;
    rarity = Bronze;
    tags = { ClanHeymaey, Support };
};

RagingBerserker::RagingBerserker()
{
    id = "152301";
    name = "Raging Berserker";
    text = "When this unit is damaged or Weakened, transform into a Raging Bear.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SBE2_VSET_00536507.mp3",
        "https://gwent.one/audio/card/ob/en/SBE2_VSET_00536513.mp3",
        "https://gwent.one/audio/card/ob/en/SBE2_VSET_00536587.mp3",
    };
    power = powerBase = 8;
    faction = Skellige;
    rarity = Bronze;
    tags = { Cursed, Soldier, Cultist };

    _onDamaged = [=](const int, Field &ally, Field &enemy, const Card *) {
        transform(this, RagingBear(), ally, enemy, this);
    };
};

RagingBerserker::RagingBear::RagingBear()
{
    id = "152405";
    name = "Raging Bear";
    text = "No ability.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 12;
    faction = Skellige;
    rarity = Bronze;
    tags = { Cursed, Beast, Cultist };
};

Hym::Hym()
{
    id = "200102";
    name = "Hym";
    text = "Choose One: Play a Bronze or Silver Cursed unit from your deck; or Create a Silver unit from your opponent's starting deck.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 3;
    faction = Skellige;
    rarity = Gold;
    tags = { Cursed };
};

Kambi::Kambi()
{
    id = "152104";
    name = "Kambi";
    text = "Spying. Deathwish: Spawn Hemdall on a random row on this unit's side.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isLoyal = false;
    power = powerBase = 1;
    faction = Skellige;
    rarity = Gold;
    tags = { };

    _onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
        spawnNewUnitToPos(new Hemdall(), rowAndPosRandom(ally), ally, enemy, this);
    };
};

Olaf::Olaf()
{
    id = "200103";
    name = "Olaf";
    text = "Deal 10 damage to self. Reduce the damage inflicted by 2 for each Beast you played this match.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 20;
    faction = Skellige;
    rarity = Gold;
    tags = { Beast, Cursed };
};

Ulfhedinn::Ulfhedinn()
{
    id = "200104";
    name = "Ulfhedinn";
    text = "Deal 1 damage to all enemies. If they were already damaged, deal 2 damage instead.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 6;
    faction = Skellige;
    rarity = Gold;
    tags = { Beast, Cursed };

    _onDeploy = [=](Field &ally, Field &enemy) {
        const std::vector<Card *> damaged = cardsFiltered(ally, enemy, {isDamaged}, EnemyBoard);
        const std::vector<Card *> other   = cardsFiltered(ally, enemy, {isUndamaged}, EnemyBoard);
        for (Card *card : other)
            damage(card, 1, ally, enemy, this);
        for (Card *card : damaged)
            damage(card, 2, ally, enemy, this);
    };
};

WildBoarOfTheSea::WildBoarOfTheSea()
{
    id = "152109";
    name = "Wild Boar of the Sea";
    text = "On turn end, Strengthen the unit to the left by 1, then deal 1 damage to the unit to the right. 5 Armor.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 8;
    faction = Skellige;
    rarity = Gold;
    tags = { ClanAnCraite, Machine };

    _onDeploy = [=](Field &ally, Field &enemy) {
        gainArmor(this, 5, ally, enemy, this);
    };

    _onTurnEnd = [=](Field &ally, Field &enemy) {
        Row row;
        Pos pos;
        if (!_findRowAndPos(this, ally, row, pos))
            return;
        if (Card *left = cardAtRowAndPos(row, pos + 1, ally))
            strengthen(left, 1, ally, enemy);
        if (Card *right = cardAtRowAndPos(row, pos + 1, ally))
            damage(right, 1, ally, enemy, this);
    };
};

GiantBoar::GiantBoar()
{
    id = "201623";
    name = "Giant Boar";
    text = "Destroy a random ally, excluding this unit, then boost self by 10.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 8;
    faction = Skellige;
    rarity = Silver;
    tags = { Beast };

    _onDeploy = [=](Field &ally, Field &enemy) {
        if (Card *card = random(cardsFiltered(ally, enemy, {otherThan(this)}, AllyBoard), ally.rng)) {
            putToDiscard(card, ally, enemy, this);
            boost(this, 10, ally, enemy, this);
        }
    };
};

OrnamentalSword::OrnamentalSword()
{
    id = "201642";
    name = "Ornamental Sword";
    text = "Create a Bronze or Silver Skellige Soldier and Strengthen it by 3.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    faction = Skellige;
    rarity = Silver;
    tags = { Item };
};

BlueboyLugos::SpectralWhale::SpectralWhale()
{
    id = "152403";
    name = "Spectral Whale";
    text = "Spying. Move to a random row and deal 1 damage to all other units on it on turn end.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isDoomed = true;
    power = powerBase = 3;
    faction = Skellige;
    rarity = Silver;
    tags = { Cursed };

    _onTurnEnd = [=](Field &, Field &) {
        // FIXME: ability missing
    };
};

DimunWarship::DimunWarship()
{
    id = "200105";
    name = "Dimun Warship";
    text = "Deal 1 damage to the same unit 4 times.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 7;
    faction = Skellige;
    rarity = Bronze;
    tags = { ClanDimun, Machine };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {}, AnyBoard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        /// break if killed already
        for (int n = 0; n < 4; ++n)
            if (damage(target, 1, ally, enemy, this))
                break;
    };
};

TrissButterflies::TrissButterflies()
{
    id = "122107";
    name = "Triss: Butterflies";
    text = "Boost the Lowest allies by 1 on turn end.";
    url = "https://gwent.one/image/card/low/cid/png/122107.png";
    tags = { Mage, Temeria };
    power = powerBase = 8;
    faction = Neutral;
    rarity = Gold;
    sounds = {
        "https://gwent.one/audio/card/ob/en/VO_TRIS_104122_2446.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.17.mp3",
        "https://gwent.one/audio/card/ob/en/TRSS_Q310_00545347.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.18.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.19.mp3",
        "https://gwent.one/audio/card/ob/en/VO_TRIS_100285_0008.mp3",
    };

    _onTurnEnd = [=](Field &ally, Field &enemy) {
        for (Card *card : lowests(cardsFiltered(ally, enemy, {}, AllyBoard)))
            boost(card, 1, ally, enemy, this);
    };
};

Yennefer::Yennefer()
{
    id = "112108";
    name = "Yennefer";
    text = "Choose One: Spawn a Unicorn that boosts all other units by 2; or Spawn a Chironex that deals 2 damage to all other units.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    tags = { Mage, Aedirn };
    power = powerBase = 6;
    faction = Neutral;
    rarity = Gold;
    sounds = {
        "https://gwent.one/audio/card/ob/en/YENN_YENNEFER_01041495.mp3",
        "https://gwent.one/audio/card/ob/en/YENN_YENNEFER_01041488.mp3",
        "https://gwent.one/audio/card/ob/en/YENN_YENNEFER_01041493.mp3",
    };

    _onDeploy = [=](Field &ally, Field &) {
        startChoiceToSelectOption(ally, this, {new Unicorn(), new Chironex()});
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        acceptOptionAndDeleteOthers(this, target);
        spawnNewCard(target, ally, enemy, this);
    };
};

GermainPiquant::GermainPiquant()
{
    id = "200523";
    name = "Germain Piquant";
    text = "Spawn 2 Cows on each side of this unit.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    tags = { Officer };
    power = powerBase = 10;
    faction = Neutral;
    rarity = Silver;
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.261.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.260.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.262.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.244.mp3",
    };

    _onDeploy = [=](Field &ally, Field &enemy) {
        spawnNewUnitToPos(new Cow(), rowAndPosToTheLeft(this, ally, 1), ally, enemy, this);
        spawnNewUnitToPos(new Cow(), rowAndPosToTheLeft(this, ally, 1), ally, enemy, this);
        spawnNewUnitToPos(new Cow(), rowAndPosToTheRight(this, ally, 1), ally, enemy, this);
        spawnNewUnitToPos(new Cow(), rowAndPosToTheRight(this, ally, 1), ally, enemy, this);
    };
};

CommandersHorn::CommandersHorn()
{
    id = "113207";
    name = "Commander's Horn";
    text = "Boost 5 adjacent units by 3.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    tags = { Tactics };
    isSpecial = true;
    faction = Neutral;
    rarity = Silver;

    _onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        Card *target1 = cardNextTo(target, ally, enemy, -2);
        Card *target2 = cardNextTo(target, ally, enemy, -1);
        Card *target3 = cardNextTo(target, ally, enemy, 1);
        Card *target4 = cardNextTo(target, ally, enemy, 2);
        for (Card *card : std::vector<Card *>{target1, target2, target, target3, target4})
            if (card != nullptr)
                boost(card, 3, ally, enemy, this);
    };
};

MarchingOrders::MarchingOrders()
{
    id = "200019";
    name = "Marching Orders";
    text = "Boost the Lowest Bronze or Silver unit in your deck by 2, then play it.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    tags = { Tactics };
    isSpecial = true;
    faction = Neutral;
    rarity = Silver;

    _onPlaySpecial = [=](Field &ally, Field &enemy) {
        Card *card = lowest(cardsFiltered(ally, enemy, {isBronzeOrSilver, isUnit}, AllyDeck), ally.rng);
        if (card != nullptr) {
            boost(card, 2, ally, enemy, this);
            playExistedCard(card, ally, enemy, this);
        }
    };
};

AlzursDoubleCross::AlzursDoubleCross()
{
    id = "113209";
    name = "Alzur's Double–Cross";
    text = "Boost the Highest Bronze or Silver unit in your deck by 2, then play it.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    tags = { Spell };
    isSpecial = true;
    faction = Neutral;
    rarity = Silver;

    _onPlaySpecial = [=](Field &ally, Field &enemy) {
        Card *card = highest(cardsFiltered(ally, enemy, {isBronzeOrSilver, isUnit}, AllyDeck), ally.rng);
        if (card != nullptr) {
            boost(card, 2, ally, enemy, this);
            playExistedCard(card, ally, enemy, this);
        }
    };
};

AlbaArmoredCavalry::AlbaArmoredCavalry()
{
    id = "200296";
    name = "Alba Armored Cavalry";
    text = "Whenever an ally appears, boost self by 1.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    tags = { Soldier };
    power = powerBase = 7;
    faction = Nilfgaard;
    rarity = Bronze;
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.379.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.380.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.381.mp3",
    };
};

Sentry::Sentry()
{
    id = "201661";
    name = "Sentry";
    text = "Boost all allied copies of a Soldier by 2.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    tags = { Soldier };
    power = powerBase = 8;
    faction = Nilfgaard;
    rarity = Bronze;

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {hasTag(Soldier), hasCopyOnABoard(&ally)}, AllyBoard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        for (Card *card : cardsFiltered(ally, enemy, {isCopy(target->name), otherThan(this)}, AllyBoard))
            boost(card, 2, ally, enemy, this);
    };
};

NauzicaaSergeant::NauzicaaSergeant()
{
    id = "162309";
    name = "Nauzicaa Sergeant";
    text = "Clear Hazards from its row and boost an ally or a Revealed unit in your hand by 3.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    tags = { Officer };
    power = powerBase = 7;
    faction = Nilfgaard;
    rarity = Bronze;
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.439.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.440.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.438.mp3",
    };

    _onDeploy = [=](Field &ally, Field &enemy) {
        clearHazardsFromItsRow(this, ally);
        startChoiceToTargetCard(ally, enemy, this, {isUnit}, AllyBoardAndHandRevealed);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        boost(target, 3, ally, enemy, this);
    };
};

SlaveInfantry::SlaveInfantry()
{
    id = "201610";
    name = "Slave Infantry";
    text = "Spawn a Doomed default copy of this unit on your other rows.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    tags = { Soldier };
    power = powerBase = 3;
    faction = Nilfgaard;
    rarity = Bronze;
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.108.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.110.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.112.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.109.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.111.mp3",
    };

    _onDeploy = [=](Field &ally, Field &enemy) {
        Row row;
        Pos pos;
        if (!_findRowAndPos(this, ally, row, pos))
            return;

        for (int _row = Meele; _row <= Seige; ++_row)
            if (_row != row) {
                Card *copy = defaultCopy();
                copy->isDoomed = true;
                spawnNewUnitToPos(copy, rowAndPosLastInExactRow(ally, Row(_row)), ally, enemy, this);
            }
    };
};

Recruit::Recruit()
{
    id = "201617";
    name = "Recruit";
    text = "Play a random different Bronze Soldier from your deck.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    tags = { Soldier };
    power = powerBase = 1;
    faction = Nilfgaard;
    rarity = Bronze;
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.36.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.35.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.34.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.33.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.32.mp3",
    };

    _onDeploy = [=](Field &ally, Field &enemy) {
        if (Card *card = random(cardsFiltered(ally, enemy, {isBronze, hasTag(Soldier), otherThan(this->name)}, AllyDeckShuffled), ally.rng))
            playExistedCard(card, ally, enemy, this);
    };
};

Ointment::Ointment()
{
    id = "201619";
    name = "Ointment";
    text = "Resurrect a Bronze unit with 5 power or less.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    tags = { Alchemy, Item };
    isSpecial = true;
    faction = Nilfgaard;
    rarity = Bronze;

    _onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isBronze, isUnit, hasPowerXorLess(5)}, AllyDiscard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, this);
    };
};

Vilgefortz::Vilgefortz()
{
    id = "162105";
    name = "Vilgefortz";
    text = "Destroy an ally, then play the top card of your deck; or Truce: Destroy an enemy, then your opponent draws and Reveals a Bronze card.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    tags = { Mage };
    power = powerBase = 9;
    faction = Nilfgaard;
    rarity = Gold;
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.72.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.73.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.74.mp3",
    };
};

Vreemde::Vreemde()
{
    id = "200050";
    name = "Vreemde";
    text = "Create a Bronze Nilfgaardian Soldier.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    tags = { Officer };
    power = powerBase = 4;
    faction = Nilfgaard;
    rarity = Silver;
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.109.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.110.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.111.mp3",
    };
};

Yennefer::Chironex::Chironex()
{
    id = "112402";
    name = "Chironex";
    text = "Deal 2 damage to all other units.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    tags = { Cursed };
    isDoomed = true;
    power = powerBase = 4;
    faction = Neutral;
    rarity = Silver;

    _onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *card : cardsFiltered(ally, enemy, {}, AnyBoard))
            damage(card, 2, ally, enemy, this);
    };
};

Yennefer::Unicorn::Unicorn()
{
    id = "112401";
    name = "Unicorn";
    text = "Boost all other units by 2.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    tags = { Beast };
    isDoomed = true;
    power = powerBase = 1;
    faction = Neutral;
    rarity = Silver;

    _onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *card : cardsFiltered(ally, enemy, {}, AnyBoard))
            boost(card, 2, ally, enemy, this);
    };
};

GermainPiquant::Cow::Cow()
{
    name = "Cow";
    tags = { Beast };
    isDoomed = true;
    power = powerBase = 1;
    faction = Neutral;
    rarity = Bronze;
};

Auckes::Auckes()
{
    id = "162208";
    name = "Auckes";
    text = "Toggle 2 units' Lock statuses.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    tags = { Witcher };
    power = powerBase = 7;
    faction = Nilfgaard;
    rarity = Silver;
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.112.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.113.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.114.mp3",
    };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {}, AnyBoard, 2);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        toggleLock(target, ally, enemy, this);
    };
};

Eskel::Eskel()
{
    id = "112202";
    name = "Eskel";
    text = "Summon Vesemir and Lambert to this row.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    tags = { Witcher };
    power = powerBase = 6;
    faction = Neutral;
    rarity = Silver;
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.21.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.22.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.23.mp3",
        "https://gwent.one/audio/card/ob/en/ESKL_ESKEL_01037262.mp3",
    };

    _onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *lambert : cardsFiltered(ally, enemy, {isCopy("Lambert")}, AllyDeck))
            moveExistedUnitToPos(lambert, rowAndPosToTheLeft(this, ally, 1), ally, enemy, this);

        for (Card *vesemir : cardsFiltered(ally, enemy, {isCopy("Vesemir")}, AllyDeck))
            moveExistedUnitToPos(vesemir, rowAndPosToTheLeft(this, ally, 1), ally, enemy, this);
    };
};

Lambert::Lambert()
{
    id = "112204";
    name = "Lambert";
    text = "Summon Eskel and Vesemir to this row.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    tags = { Witcher };
    power = powerBase = 6;
    faction = Neutral;
    rarity = Silver;
    sounds = {
        "https://gwent.one/audio/card/ob/en/LMBT_Q401_00523875.mp3",
        "https://gwent.one/audio/card/ob/en/LMBT_SQ106_00586496.mp3",
        "https://gwent.one/audio/card/ob/en/LMBT_Q401_01058899.mp3",
        "https://gwent.one/audio/card/ob/en/LMBT_Q403_00572964.mp3",
        "https://gwent.one/audio/card/ob/en/LMBT_Q401_00531130.mp3",
        "https://gwent.one/audio/card/ob/en/LMBT_Q403_00550012.mp3",
    };

    _onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *eskel : cardsFiltered(ally, enemy, {isCopy("Eskel")}, AllyDeck))
            moveExistedUnitToPos(eskel, rowAndPosToTheRight(this, ally, 1), ally, enemy, this);

        for (Card *vesemir : cardsFiltered(ally, enemy, {isCopy("Vesemir")}, AllyDeck))
            moveExistedUnitToPos(vesemir, rowAndPosToTheRight(this, ally, 1), ally, enemy, this);
    };
};

Vesemir::Vesemir()
{
    id = "112203";
    name = "Vesemir";
    text = "Summon Eskel and Lambert to this row.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    tags = { Witcher };
    power = powerBase = 7;
    faction = Neutral;
    rarity = Silver;
    sounds = {
        "https://gwent.one/audio/card/ob/en/VSMR_VESEMIR_01040765.mp3",
        "https://gwent.one/audio/card/ob/en/VSMR_VESEMIR_01000012.mp3",
        "https://gwent.one/audio/card/ob/en/VSMR_Q001_00546725.mp3",
    };

    _onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *lambert : cardsFiltered(ally, enemy, {isCopy("Lambert")}, AllyDeck))
            moveExistedUnitToPos(lambert, rowAndPosToTheLeft(this, ally, 1), ally, enemy, this);

        for (Card *eskel : cardsFiltered(ally, enemy, {isCopy("Eskel")}, AllyDeck))
            moveExistedUnitToPos(eskel, rowAndPosToTheRight(this, ally, 1), ally, enemy, this);
    };
}

TridamInfantry::TridamInfantry()
{
    id = "200171";
    name = "Tridam Infantry";
    text = "4 Armor.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    tags = { Soldier };
    power = powerBase = 10;
    faction = NothernRealms;
    rarity = Bronze;
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.230.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.231.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.226.mp3",
    };

    _onDeploy = [=](Field &ally, Field &enemy) {
        gainArmor(this, 4, ally, enemy, this);
    };
};

VriheddDragoon::VriheddDragoon()
{
    id = "142205";
    name = "Vrihedd Dragoon";
    text = "Boost a random non-Spying unit in your hand by 1 on turn end.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    tags = { Elf, Soldier };
    power = powerBase = 8;
    faction = Scoiatael;
    rarity = Bronze;
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.779.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.781.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.780.mp3",
    };

    _onTurnEnd = [=](Field &ally, Field &enemy) {
        if (Card *card = random(cardsFiltered(ally, enemy, {isUnit, isNonSpying}, AllyHand), ally.rng))
            boost(card, 1, ally, enemy, this);
    };
};

Malena::Malena()
{
    id = "142210";
    name = "Malena";
    text = "Ambush: After 2 turns, flip over and Charm the Highest Bronze or Silver enemy with 5 power or less on turn start.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 7;
    isAmbush = true;
    rarity = Silver;
    faction = Scoiatael;
    tags = { Elf };
    sounds = {
        "https://gwent.one/audio/card/ob/en/VO_MALN_106817_0005.mp3",
        "https://gwent.one/audio/card/ob/en/VO_MALN_106745_0017.mp3",
        "https://gwent.one/audio/card/ob/en/VO_MALN_106657_0009.mp3",
    };

    _onDeploy = [=](Field &ally, Field &enemy) {
        setTimer(this, ally, enemy, 2);
    };

    _onTurnStart = [=](Field &ally, Field &enemy) {
        if (!tick(this, ally, enemy))
            return;
        flipOver(this, ally, enemy);
        if (Card *card = highest(cardsFiltered(ally, enemy, {isBronzeOrSilver, hasPowerXorLess(5)}, EnemyBoard), ally.rng))
            charm(card, ally, enemy, this);
    };
};

UnseenElder::UnseenElder()
{
    id = "200055";
    name = "Unseen Elder";
    text = "Drain a unit by half.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 5;
    rarity = Gold;
    faction = Monster;
    tags = { Vampire, Leader };
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.255.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.256.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.257.mp3",
    };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {}, AnyBoard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        const int x = int(std::ceil(target->power / 2.0));
        drain(target, x, ally, enemy, this);
    };
};

DevanaRunestone::DevanaRunestone()
{
    id = "201584";
    name = "Devana Runestone";
    text = "Create a Bronze or Silver Monster card.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    rarity = Silver;
    faction = Monster;
    tags = { Alchemy, Item };

    _onPlaySpecial = [=](Field &ally, Field &) {
        startChoiceCreateOptions(ally, this, {isBronzeOrSilver, isMonsterFaction});
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        acceptOptionAndDeleteOthers(this, target);
        spawnNewCard(target, ally, enemy, this);
    };
};

DazhbogRunestone::DazhbogRunestone()
{
    id = "201583";
    name = "Dazhbog Runestone";
    text = "Create a Bronze or Silver Nilfgaard card.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    rarity = Silver;
    faction = Nilfgaard;
    tags = { Alchemy, Item };

    _onPlaySpecial = [=](Field &ally, Field &) {
        startChoiceCreateOptions(ally, this, {isBronzeOrSilver, isNilfgaardFaction});
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        acceptOptionAndDeleteOthers(this, target);
        spawnNewCard(target, ally, enemy, this);
    };
};

MoranaRunestone::MoranaRunestone()
{
    id = "201585";
    name = "Morana Runestone";
    text = "Create a Bronze or Silver Scoia'tael card.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    rarity = Silver;
    faction = Scoiatael;
    tags = { Alchemy, Item };

    _onPlaySpecial = [=](Field &ally, Field &) {
        startChoiceCreateOptions(ally, this, {isBronzeOrSilver, isScoiataelFaction});
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        acceptOptionAndDeleteOthers(this, target);
        spawnNewCard(target, ally, enemy, this);
    };
};

StribogRunestone::StribogRunestone()
{
    id = "201581";
    name = "Stribog Runestone";
    text = "Create a Bronze or Silver Skellige card.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    rarity = Silver;
    faction = Skellige;
    tags = { Alchemy, Item };

    _onPlaySpecial = [=](Field &ally, Field &) {
        startChoiceCreateOptions(ally, this, {isBronzeOrSilver, isSkelligeFaction});
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        acceptOptionAndDeleteOthers(this, target);
        spawnNewCard(target, ally, enemy, this);
    };
};

Muzzle::Muzzle()
{
    id = "200225";
    name = "Muzzle";
    text = "Charm a Bronze or Silver enemy with 8 power or less.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    rarity = Gold;
    faction = Neutral;
    tags = { Item };

    _onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilver, hasPowerXorLess(8)}, EnemyBoard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        charm(target, ally, enemy, this);
    };
};

RockBarrage::RockBarrage()
{
    id = "201647";
    name = "Rock Barrage";
    text = "Deal 7 damage to an enemy and move it to the row above. If the row is full, destroy the enemy instead.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    rarity = Bronze;
    faction = Neutral;
    tags = {};

    _onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {}, EnemyBoard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        const RowAndPos rowAndPos = _findRowAndPos(target, enemy);

        if (rowAndPos.row() == Seige || moveExistedUnitToPos(target, rowAndPosLastInExactRow(enemy, Row(rowAndPos.row() + 1)), enemy, ally, this)) {
            damage(target, 7, ally, enemy, this);
            return;
        }
        putToDiscard(target, ally, enemy, this);
    };
};

WhisperingHillock::WhisperingHillock()
{
    id = "201587";
    name = "Whispering Hillock";
    text = "Create a Bronze or Silver Organic card.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 6;
    rarity = Gold;
    faction = Monster;
    tags = { Leader, Relict };
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.4.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.5.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.2.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.3.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.1.mp3",
    };

    _onDeploy = [=](Field &ally, Field &) {
        startChoiceCreateOptions(ally, this, {isBronzeOrSilver, hasTag(Organic)});
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        acceptOptionAndDeleteOthers(this, target);
        spawnNewCard(target, ally, enemy, this);
    };
}

Brewess::Brewess()
{
    id = "132207";
    name = "Brewess";
    text = "Summon Whispess and Weavess to this row.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    tags = { Mage, Relict };
    power = powerBase = 8;
    faction = Monster;
    rarity = Silver;
    sounds = {
        "https://gwent.one/audio/card/ob/en/BREW_Q105_00418675.mp3",
        "https://gwent.one/audio/card/ob/en/BREW_Q105_00531820.mp3",
        "https://gwent.one/audio/card/ob/en/BREW_Q111_00576135.mp3",
    };

    _onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *weavess: cardsFiltered(ally, enemy, {isCopy("Weavess")}, AllyDeck))
            moveExistedUnitToPos(weavess, rowAndPosToTheRight(this, ally, 1), ally, enemy, this);

        for (Card *whispess : cardsFiltered(ally, enemy, {isCopy("Whispess")}, AllyDeck))
            moveExistedUnitToPos(whispess, rowAndPosToTheLeft(this, ally, 1), ally, enemy, this);
    };
}

Weavess::Weavess()
{
    id = "132208";
    name = "Weavess";
    text = "Summon Brewess and Whispess to this row.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    tags = { Mage, Relict };
    power = powerBase = 6;
    faction = Monster;
    rarity = Silver;
    sounds = {
        "https://gwent.one/audio/card/ob/en/WEAV_Q105_00531814.mp3",
        "https://gwent.one/audio/card/ob/en/WEAV_Q503_00579064.mp3",
        "https://gwent.one/audio/card/ob/en/WEAV_Q503_00578937.mp3",
    };
    
    _onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *whispess : cardsFiltered(ally, enemy, {isCopy("Whispess")}, AllyDeck))
            moveExistedUnitToPos(whispess, rowAndPosToTheLeft(this, ally, 1), ally, enemy, this);

        for (Card *brewess: cardsFiltered(ally, enemy, {isCopy("Brewess")}, AllyDeck))
            moveExistedUnitToPos(brewess, rowAndPosToTheLeft(this, ally, 1), ally, enemy, this);
    };
}


Whispess::Whispess()
{
    id = "132206";
    name = "Whispess";
    text = "Summon Brewess and Weavess to this row.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    tags = { Mage, Relict };
    power = powerBase = 6;
    faction = Monster;
    rarity = Silver;
    sounds = {
        "https://gwent.one/audio/card/ob/en/WHSP_Q105_00419061.mp3",
        "https://gwent.one/audio/card/ob/en/WHSP_Q105_00531816.mp3",
        "https://gwent.one/audio/card/ob/en/WHSP_Q105_00419057.mp3",
        "https://gwent.one/audio/card/ob/en/WHSP_Q105_00382577.mp3",
        "https://gwent.one/audio/card/ob/en/LMBT_Q401_00531130.mp3",
        "https://gwent.one/audio/card/ob/en/WHSP_Q105_00382587.mp3",
    };

    _onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *weavess: cardsFiltered(ally, enemy, {isCopy("Weavess")}, AllyDeck))
            moveExistedUnitToPos(weavess, rowAndPosToTheRight(this, ally, 1), ally, enemy, this);

        for (Card *brewess: cardsFiltered(ally, enemy, {isCopy("Brewess")}, AllyDeck))
            moveExistedUnitToPos(brewess, rowAndPosToTheRight(this, ally, 1), ally, enemy, this);
    };
}

WeavessIncantation::WeavessIncantation()
{
    id = "200222";
    name = "Weavess: Incantation";
    text = "Choose One: Strengthen all your other Relicts in hand, deck, and on board by 2; or Play a Bronze or Silver Relict from your deck and Strengthen it by 2.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    tags = { Mage, Relict };
    power = powerBase = 4;
    faction = Monster;
    rarity = Gold;
    sounds = {
        "https://gwent.one/audio/card/ob/en/WEAV_Q105_00531814.mp3",
        "https://gwent.one/audio/card/ob/en/WEAV_Q503_00579064.mp3",
        "https://gwent.one/audio/card/ob/en/WEAV_Q503_00578937.mp3",
    };

    _onDeploy = [=](Field &ally, Field &) {
        auto *option1 = new WeavessIncantation::StrengthenAll;
        copyCardText(this, option1);
        option1->text = "Strengthen all your other Relicts in hand, deck, and on board by 2.";

        auto *option2 = new WeavessIncantation::PlayAndStrengthen;
        copyCardText(this, option2);
        option2->text = "Play a Bronze or Silver Relict from your deck and Strengthen it by 2.";

        startChoiceToSelectOption(ally, this, {option1, option2});
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (_options.size() > 0) {
            _choosen = target;
            acceptOptionAndDeleteOthers(this, target);
            if (dynamic_cast<WeavessIncantation::StrengthenAll *>(_choosen)) {
                for (Card *card : cardsFiltered(ally, enemy, {hasTag(Relict), otherThan(this)}, AllyBoardHandDeck))
                    strengthen(card, 2, ally, enemy);
                delete _choosen;
                _choosen = nullptr;
                return;
            }
            if (dynamic_cast<WeavessIncantation::PlayAndStrengthen *>(_choosen)) {
                startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilver, hasTag(Relict)}, AllyDeckShuffled);
                delete _choosen;
                _choosen = nullptr;
                return;
            }
            assert(false);
        }
        strengthen(target, 2, ally, enemy);
        playExistedCard(target, ally, enemy, this);
    };
}

BrewessRitual::BrewessRitual()
{
    id = "200221";
    name = "Brewess: Ritual";
    text = "Resurrect 2 Bronze Deathwish units.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    tags = { Mage, Relict };
    power = powerBase = 1;
    faction = Monster;
    rarity = Gold;
    sounds = {
        "https://gwent.one/audio/card/ob/en/BREW_Q105_00418675.mp3",
        "https://gwent.one/audio/card/ob/en/BREW_Q105_00531820.mp3",
        "https://gwent.one/audio/card/ob/en/BREW_Q111_00576135.mp3",
    };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isDeathwish}, AllyDiscard, 2);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        // TODO: play order is inverted
        // look demoMonsterSisters
        playExistedCard(target, ally, enemy, this);
    };
}

WhispessTribute::WhispessTribute()
{
    id = "200220";
    name = "Whispess: Tribute";
    text = "Play a Bronze or Silver Organic card from your deck.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    tags = { Mage, Relict };
    power = powerBase = 6;
    faction = Monster;
    rarity = Gold;
    sounds = {
        "https://gwent.one/audio/card/ob/en/WHSP_Q105_00419061.mp3",
        "https://gwent.one/audio/card/ob/en/WHSP_Q105_00531816.mp3",
        "https://gwent.one/audio/card/ob/en/WHSP_Q105_00419057.mp3",
        "https://gwent.one/audio/card/ob/en/WHSP_Q105_00382577.mp3",
        "https://gwent.one/audio/card/ob/en/LMBT_Q401_00531130.mp3",
        "https://gwent.one/audio/card/ob/en/WHSP_Q105_00382587.mp3",
    };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilver, hasTag(Organic)}, AllyDeckShuffled);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, this);
    };
}

Nivellen::Nivellen() 
{
    id = "200089";
    name = "Nivellen";
    text = "Move all units on a row to random rows.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 10;
    rarity = Silver;
    faction = Neutral;
    tags = { Cursed };
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.167.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.168.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.169.mp3",
    };
};


LeoBonhart::LeoBonhart()
{
    id = "200031";
    name = "Leo Bonhart";
    text = "Reveal one of your units and deal damage equal to its base power to an enemy.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 7;
    rarity = Gold;
    faction = Nilfgaard;
    tags = { Soldier };
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.13.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.14.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.15.mp3",
    };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isNonRevealed, isUnit}, AllyHand);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (_revealed == nullptr) {
            _revealed = target;
            reveal(target, ally, enemy, this);
            startChoiceToTargetCard(ally, enemy, this, {}, EnemyBoard);
            return;
        }
        damage(target, _revealed->powerBase, ally, enemy, this);
    };
};


MorvranVoorhis::MorvranVoorhis()
{
    id = "200163";
    name = "Morvran Voorhis";
    text = "Reveal up to 4 cards.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 7;
    rarity = Gold;
    faction = Nilfgaard;
    tags = { Officer, Leader };
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.52.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.53.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.54.mp3",
    };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isNonRevealed}, AnyHandsShuffled, 4, false);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        reveal(target, ally, enemy, this);
    };
};


Cynthia::Cynthia()
{
    id = "162203";
    name = "Cynthia";
    text = "Reveal the Highest unit in your opponent's hand and boost self by its power.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 5;
    rarity = Silver;
    faction = Nilfgaard;
    tags = { Mage };
    sounds = {
        "https://gwent.one/audio/card/ob/en/VO_CNTH_303653_0335.mp3",
        "https://gwent.one/audio/card/ob/en/VO_CNTH_303743_0002.mp3",
        "https://gwent.one/audio/card/ob/en/VO_CNTH_303656_0001.mp3",
    };

    _onDeploy = [=](Field &ally, Field &enemy) {
        if (Card *card = highest(cardsFiltered(ally, enemy, {isUnit, isNonRevealed}, EnemyHand), ally.rng)) {
            reveal(card, ally, enemy, this);
            boost(this, card->power, ally, enemy, this);
        }
    };
};

Serrit::Serrit()
{
    id = "162209";
    name = "Serrit";
    text = "Deal 7 damage to an enemy; or Set a Revealed opposing unit's power to 1.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 6;
    rarity = Silver;
    faction = Nilfgaard;
    tags = { Witcher };
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.115.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.116.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.117.mp3",
    };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isUnit}, EnemyBoardAndHandRevealed);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        const int x = isOnBoard(target, enemy) ? 7 : (target->power - 1);
        damage(target, x, ally, enemy, this);
    };
};

Sweers::Sweers()
{
    id = "162206";
    name = "Sweers";
    text = "Choose an enemy or a Revealed unit in your opponent's hand, then move all copies of it from their deck to the graveyard.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 9;
    rarity = Silver;
    faction = Nilfgaard;
    tags = { Officer };
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.100.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.101.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.102.mp3",
    };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isUnit, hasCopyInADeck(&enemy)}, EnemyBoardAndHandRevealed);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        for (Card *copy : findCopies(target, enemy.deck))
            putToDiscard(copy, ally, enemy, this);
    };
};

WildHuntHound::WildHuntHound()
{
    id = "132402";
    name = "Wild Hunt Hound";
    text = "Play Biting Frost from your deck.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 4;
    rarity = Bronze;
    faction = Monster;
    tags = { WildHunt, Construct };

    _onDeploy = [=](Field &ally, Field &enemy) {
        if (Card *card = random(cardsFiltered(ally, enemy, {isCopy("Biting Frost")}, AllyDeck), ally.rng))
            playExistedCard(card, ally, enemy, this);
    };
}

WildHuntWarrior::WildHuntWarrior()
{
    id = "132309";
    name = "Wild Hunt Warrior";
    text = "Deal 3 damage to an enemy. If the enemy is destroyed or is under Biting Frost, boost self by 2.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 7;
    rarity = Bronze;
    faction = Monster;
    tags = { WildHunt, Soldier };
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.793.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.792.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.794.mp3",
    };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {}, EnemyBoard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        const bool isUnderFrost = rowEffectUnderUnit(target, enemy) == BitingFrostEffect;
        if (damage(target, 3, ally, enemy, this) || isUnderFrost)
            boost(this, 2, ally, enemy, this);
    };
}

WildHuntNavigator::WildHuntNavigator()
{
    id = "200026";
    name = "Wild Hunt Navigator";
    text = "Choose a Bronze non-Mage Wild Hunt ally and play a copy of it from your deck.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 3;
    rarity = Bronze;
    faction = Monster;
    tags = { WildHunt, Mage };
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.45.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.44.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.43.mp3",
    };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isBronze, hasTag(WildHunt), hasNoTag(Mage), hasCopyInADeck(&ally)}, AllyBoard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (Card *copy = findCopy(target, ally.deck))
            playExistedCard(copy, ally, enemy, this);
    };
}

Nithral::Nithral()
{
    id = "132214";
    name = "Nithral";
    text = "Deal 6 damage to an enemy. Increase damage by 1 for each Wild Hunt unit in your hand.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 6;
    rarity = Silver;
    faction = Monster;
    tags = { WildHunt, Officer };
    sounds = {
        "https://gwent.one/audio/card/ob/en/WHW1_Q104_00555151.mp3",
        "https://gwent.one/audio/card/ob/en/WHW1_Q104_00555148.mp3",
        "https://gwent.one/audio/card/ob/en/WHW1_Q104_00555150.mp3",
    };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {}, EnemyBoard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        const int nWildHuntUnits = cardsFiltered(ally, enemy, {hasTag(WildHunt), isUnit}, AllyHand).size();
        damage(target, 6 + nWildHuntUnits, ally, enemy, this);
    };
}

Miruna::Miruna()
{
    id = "132108";
    name = "Miruna";
    text = "After 2 turns, Charm the Highest enemy on the opposite row on turn start.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 4;
    rarity = Gold;
    faction = Monster;
    tags = { Beast };
    sounds = {
        "https://gwent.one/audio/card/ob/en/SCC3_VSET_01053075.mp3",
        "https://gwent.one/audio/card/ob/en/SCC3_VSET_01053091.mp3",
        "https://gwent.one/audio/card/ob/en/SCC3_VSET_01053077.mp3",
    };

    _onDeploy = [=](Field &ally, Field &enemy) {
        setTimer(this, ally, enemy, 2);
    };

    _onTurnStart = [=](Field &ally, Field &enemy) {
        if (!tick(this, ally, enemy))
            return;
        if (Card *card = highest(cardsFiltered(ally, enemy, {isOnOppositeRow(&ally, &enemy, this)}, EnemyBoard), ally.rng))
            charm(card, ally, enemy, this);
    };
}

Imlerith::Imlerith()
{
    id = "132102";
    name = "Imlerith";
    text = "Deal 4 damage to an enemy. If the enemy is under Biting Frost, deal 8 damage instead.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 9;
    rarity = Gold;
    faction = Monster;
    tags = { WildHunt, Officer };
    sounds = {
        "https://gwent.one/audio/card/ob/en/IMLR_Q403_00524739.mp3",
        "https://gwent.one/audio/card/ob/en/IMLR_Q403_00524776.mp3",
        "https://gwent.one/audio/card/ob/en/IMLR_Q111_01062046.mp3",
    };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {}, EnemyBoard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        const bool isUnderFrost = rowEffectUnderUnit(target, enemy) == BitingFrostEffect;
        damage(target, isUnderFrost ? 8 : 4, ally, enemy, this);
    };
}

Caretaker::Caretaker()
{
    id = "132106";
    name = "Caretaker";
    text = "Resurrect a Bronze or Silver unit from your opponent's graveyard.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 4;
    rarity = Gold;
    faction = Monster;
    isDoomed = true;
    tags = { Relict };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isUnit, isBronzeOrSilver}, EnemyDiscard);
    };
    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, this);
    };
}

Ruehin::Ruehin()
{
    id = "201660";
    name = "Ruehin";
    text = "Strengthen all your other Insectoids and Cursed units in hand, deck, and on board by 1.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 8;
    rarity = Silver;
    faction = Monster;
    tags = { Insectoid, Cursed };

    _onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *card : cardsFiltered(ally, enemy, {hasAnyOfTags({Insectoid, Cursed}), otherThan(this), isUnit}, AllyBoardHandDeck))
            strengthen(card, 1, ally, enemy);
    };
}

OldSpeartipAsleep::OldSpeartipAsleep()
{
    id = "132218";
    name = "Old Speartip: Asleep";
    text = "Strengthen all your other Ogroids in hand, deck, and on board by 1.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 12;
    rarity = Gold;
    faction = Monster;
    tags = { Ogroid };

    _onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *card : cardsFiltered(ally, enemy, {hasTag(Ogroid), otherThan(this), isUnit}, AllyBoardHandDeck))
            strengthen(card, 1, ally, enemy);
    };
}

OldSpeartip::OldSpeartip()
{
    id = "132408";
    name = "Old Speartip";
    text = "Deal 2 damage to 5 random enemies on the opposite row.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 10;
    rarity = Gold;
    faction = Monster;
    tags = { Ogroid };

    _onDeploy = [=](Field &ally, Field &enemy) {
        for(Card *card : randoms(cardsFiltered(ally, enemy, {isOnOppositeRow(&ally, &enemy, this)}, EnemyBoard), 5, ally.rng))
            damage(card, 2, ally, enemy, this);
    };
}

Golyat::Golyat()
{
    id = "200052";
    name = "Golyat";
    text = "Boost self by 7. Whenever this unit is damaged, deal 2 damage to self.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 10;
    rarity = Gold;
    faction = Monster;
    tags = { Ogroid };

    _onDeploy = [=](Field &ally, Field &enemy) {
        boost(this, 7, ally, enemy, this);
    };

    _onDamaged = [=](const int, Field &ally, Field &enemy, const Card *src) {
        if (src != this)
            damage(this, 2, ally, enemy, this);
    };
}

Barbegazi::Barbegazi()
{
    id = "201701";
    name = "Barbegazi";
    text = "Resilience. Consume an ally and boost self by its power.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 6;
    rarity = Bronze;
    faction = Monster;
    tags = { Insectoid };

    _onDeploy = [=](Field &ally, Field &enemy) {
        isResilient = true;
        startChoiceToTargetCard(ally, enemy, this, {}, AllyBoard);
    };

    _onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
        boost(this, consume(target, ally, enemy, this), ally, enemy, this);
    };
}

Ghoul::Ghoul()
{
    id = "132306";
    name = "Ghoul";
    text = "Consume a Bronze or Silver unit from your graveyard and boost self by its power.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 4;
    rarity = Bronze;
    faction = Monster;
    tags = { Necrophage };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilver, isUnit}, AllyDiscard);
    };

    _onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
        boost(this, consume(target, ally, enemy, this), ally, enemy, this);
    };
}

Forktail::Forktail()
{
    id = "201606";
    name = "Forktail";
    text = "Consume 2 allies and boost self by their power.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 8;
    rarity = Bronze;
    faction = Monster;
    tags = { Draconid };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {}, AllyBoard, 2);
    };

    _onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
        boost(this, consume(target, ally, enemy, this), ally, enemy, this);
    };
}

ArachasQueen::ArachasQueen()
{
    id = "201743";
    name = "Arachas Queen";
    text = "Immune. Consume 3 allies and boost self by their power.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 7;
    rarity = Gold;
    faction = Monster;
    tags = { Leader, Insectoid };

    _onDeploy = [=](Field &ally, Field &enemy) {
        isImmune = true;
        startChoiceToTargetCard(ally, enemy, this, {}, AllyBoard, 3);
    };

    _onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
        boost(this, consume(target, ally, enemy, this), ally, enemy, this);
    };
}

Ozzrel::Ozzrel()
{
    id = "201698";
    name = "Ozzrel";
    text = "Consume a Bronze or Silver unit from either graveyard and boost by its power.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 5;
    rarity = Silver;
    faction = Monster;
    tags = { Necrophage };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilver, isUnit}, BothDiscard);
    };

    _onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
        boost(this, consume(target, ally, enemy, this), ally, enemy, this);
    };
}

Kayran::Kayran()
{
    id = "132107";
    name = "Kayran";
    text = "Consume a unit with 7 power or less and boost self by its power.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 5;
    rarity = Gold;
    faction = Monster;
    tags = { Insectoid };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {hasPowerXorLess(7)}, AnyBoard);
    };

    _onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
        boost(this, consume(target, ally, enemy, this), ally, enemy, this);
    };
}

Mourntart::Mourntart()
{
    id = "132202";
    name = "Mourntart";
    text = "Consume all Bronze and Silver units in your graveyard and boost self by 1 for each.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 4;
    rarity = Silver;
    faction = Monster;
    tags = { Necrophage };

    _onDeploy = [=](Field &ally, Field &enemy) {
            for (Card *card : cardsFiltered(ally, enemy, {isBronzeOrSilver, isUnit}, AllyDiscard)) {
                consume(card, ally, enemy, this);
                boost(this, 1, ally, enemy, this);
            };
        };
}

ToadPrince::ToadPrince()
{
    id = "132216";
    name = "Toad Prince";
    text = "Draw a unit, then Consume a unit in your hand and boost self by its power.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 6;
    rarity = Silver;
    faction = Monster;
    tags = { Cursed };

    _onDeploy = [=](Field &ally, Field &enemy) {
        if (Card *unit = first(cardsFiltered(ally, enemy, {isUnit}, AllyDeck))) {
            putToHand(unit, ally, enemy);
            startChoiceToTargetCard(ally, enemy, this, {isUnit}, AllyHand);
        }
    };

    _onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
        boost(this, consume(target, ally, enemy, this), ally, enemy, this);
    };
}

Fiend::Fiend()
{
    id = "112405";
    name = "Fiend";
    text = "No ability.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 11;
    rarity = Bronze;
    faction = Monster;
    tags = { Relict };
}

Morvudd::Morvudd()
{
    id = "112405";
    name = "Morvudd";
    text = "Toggle a unit's Lock status. If it was an enemy, halve its power.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 6;
    rarity = Silver;
    faction = Monster;
    tags = { Relict };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {}, AnyBoard);
    };

    _onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
        toggleLock(target, ally, enemy, this);
        if (isOnBoard(target, enemy))
            damage(target, int(std::ceil(target->power / 2.0)), ally, enemy, this);
    };
}

Ekimmara::Ekimmara()
{
    id = "132313";
    name = "Ekimmara";
    text = "Drain a unit by 3.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 5;
    rarity = Bronze;
    faction = Monster;
    tags = { Vampire };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {}, AnyBoard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        drain(target, 3, ally, enemy, this);
    };
}

Rotfiend::Rotfiend()
{
    id = "200295";
    name = "Rotfiend";
    text = "Deathwish: Deal 2 damage to units on the opposite row.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 8;
    rarity = Bronze;
    faction = Monster;
    tags = { Necrophage };

    _onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
        for(Card *target : cardsFiltered(ally, enemy, {isOnOppositeRow(&ally, &enemy, this)}, EnemyBoard))
            damage(target, 2, ally, enemy, this);
    };
}

Archespore::Archespore()
{
    id = "200038";
    name = "Archespore";
    text = "Move to a random row and deal 1 damage to a random enemy on turn start. Deathwish: Deal 4 damage to a random enemy.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 7;
    rarity = Bronze;
    faction = Monster;
    tags = { Cursed };

    _onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
        damage(random(cardsFiltered(ally, enemy, {}, EnemyBoard), ally.rng),
               4, ally, enemy, this);
    };

    _onTurnStart = [=](Field &ally, Field &enemy) {
        if(moveSelfToRandomRow(this, ally, enemy))
            damage(random(cardsFiltered(ally, enemy, {}, EnemyBoard), ally.rng),
                    1, ally, enemy, this);
    };
}

Cyclops::Cyclops()
{
    id = "200037";
    name = "Cyclops";
    text = "Destroy an ally and deal damage equal to its power to an enemy.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 11;
    rarity = Bronze;
    faction = Monster;
    tags = { Ogroid };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {}, AllyBoard);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if(_destroyed == nullptr) {
            _destroyed = target;
            startChoiceToTargetCard(ally, enemy, this, {}, EnemyBoard);
            return;
        }
        damage(target, _destroyed->power, ally, enemy, this);
        damage(_destroyed, _destroyed->power + _destroyed->armor, ally, enemy, this);
        _destroyed = nullptr;
    };
}

Maerolorn::Maerolorn()
{
    id = "132406";
    name = "Maerolorn";
    text = "Play a Bronze Deathwish unit from your deck.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 4;
    rarity = Silver;
    faction = Monster;
    tags = { Relict };

    _onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, this, {isBronze, isDeathwish}, AllyDeckShuffled);
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, this);
    };
}

MonsterNest::MonsterNest()
{
    id = "133302";
    name = "Monster Nest";
    text = "Spawn a Bronze Necrophage or Insectoid and boost it by 1.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    isSpecial = true;
    rarity = Silver;
    faction = Monster;
    tags = { Organic };

    _onPlaySpecial = [=](Field &ally, Field &) {
        startChoiceSpawnOptions(ally, this, {isBronze, hasAnyOfTags({Necrophage, Insectoid})});
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        acceptOptionAndDeleteOthers(this, target);
        spawnNewCard(target, ally, enemy, this);
    };
}

ArachasDrone::ArachasDrone()
{
    id = "132304";
    name = "Arachas Drone";
    text = "Summon all copies of this unit to this row.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 3;
    rarity = Bronze;
    faction = Monster;
    tags = { Insectoid };

    _onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *copy : cardsFiltered(ally, enemy, {isCopy(this->name)}, AllyDeck))
            moveExistedUnitToPos(copy, _findRowAndPos(this, ally), ally, enemy, this);
        // if wanna play from hand
//        for (Card *copy : cardsFiltered(ally, enemy, {isCopy(this->name)}, AllyHand))
//            moveExistedUnitToPos(copy, _findRowAndPos(this, ally), ally, enemy, this);
    };
}

AlphaWerewolf::AlphaWerewolf()
{
    id = "200114";
    name = "Alpha Werewolf";
    text = "Spawn a Wolf on each side of this unit on contact with Full Moon.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 10;
    rarity = Bronze;
    faction = Monster;
    tags = { Beast, Cursed };

    _onContactWithFullMoon = [=](Field &ally, Field &enemy) {
        spawnNewUnitToPos(new Wolf(), rowAndPosToTheLeft(this, ally, 1), ally, enemy, this);
        spawnNewUnitToPos(new Wolf(), rowAndPosToTheRight(this, ally, 1), ally, enemy, this);
    };
}

Werewolf::Werewolf()
{
    id = "201600";
    name = "Werewolf";
    text = "Immune. Boost this unit by 7 on first contact with Full Moon.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 7;
    rarity = Bronze;
    faction = Monster;
    tags = { Beast, Cursed };
    isImmune = true;

    _onContactWithFullMoon = [=](Field &ally, Field &enemy) {
        boost(this, 7, ally, enemy, this);
    };
}

EredinBreaccGlas::EredinBreaccGlas()
{
    id = "131101";
    name = "Eredin Bréacc Glas";
    text = "Spawn a Bronze Wild Hunt unit.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 5;
    rarity = Gold;
    faction = Monster;
    tags = { WildHunt, Leader };
    sounds = {
        "https://gwent.one/audio/card/ob/en/ERDN_Q501_00534051.mp3",
        "https://gwent.one/audio/card/ob/en/ERDN_EREDIN_01040841.mp3",
        "https://gwent.one/audio/card/ob/en/ERDN_EREDIN_01040845.mp3",
        "https://gwent.one/audio/card/ob/en/ERDN_Q311_00312654.mp3",
        "https://gwent.one/audio/card/ob/en/ERDN_EREDIN_01040754.mp3",
    };

    _onDeploy = [=](Field &ally, Field &) {
        startChoiceSpawnOptions(ally, this, {isBronze, hasTag(WildHunt)});
    };

    _onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        acceptOptionAndDeleteOthers(this, target);
        spawnNewCard(target, ally, enemy, this);
    };
}
