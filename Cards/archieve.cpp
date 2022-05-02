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
    };
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
}

void AddaStriga::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isNonMonsterFaction});
}

void AddaStriga::onTargetChoosen(Card *card, Field &ally, Field &enemy)
{
    damage(card, 8, ally, enemy);
}

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
}

void Dao::onDestroy(Field &ally, Field &enemy, const Row row, const Pos pos)
{
    spawn(new DaoLesser(), row, pos, ally, enemy);
    spawn(new DaoLesser(), row, pos, ally, enemy);
}

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
}

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
}

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
}

void PoorFingInfantry::onDeploy(Field &ally, Field &enemy)
{
    Row row;
    Pos pos;
    if (!rowAndPos(this, ally, row, pos))
        return;
    spawn(new LeftFlankInfantry(), row, pos, ally, enemy);
    spawn(new RightFlankInfantry(), row, pos + 2, ally, enemy);
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
}

void DeithwenArbalest::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {}, EnemyBoard);
}

void DeithwenArbalest::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
//    ally.snapshots.push_back(new Animation("", Animation::LineDamage, this, target));
    damage(target, target->isSpy ? 6 : 3, ally, enemy);
}

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
}

void TemerianDrummer::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {}, AllyBoard);
}

void TemerianDrummer::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    boost(target, 6, ally, enemy);
}

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
}

void DandelionPoet::onDeploy(Field &ally, Field &enemy)
{
    drawACard(ally, enemy);
    startChoiceToTargetCard(ally, enemy, this, {}, AllyHand);
}

void DandelionPoet::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    playCard(target, ally, enemy);
}

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
}

void SileDeTansarville::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilver, ::isSpecial}, AllyHand);
}

void SileDeTansarville::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    playCard(target, ally, enemy);
    drawACard(ally, enemy);
}

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
}

void RedanianKnightElect::onDeploy(Field &ally, Field &enemy)
{
    gainArmor(this, 2, ally, enemy);
}

void RedanianKnightElect::onTurnEnd(Field &ally, Field &enemy)
{
    if (armor == 0)
        return;

    Card *left = cardNextTo(this, ally, enemy, -1);
    Card *right = cardNextTo(this, ally, enemy, 1);

    if (left != nullptr)
        boost(left, 1, ally, enemy);
    if (right != nullptr)
        boost(right, 1, ally, enemy);
}

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
}

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
}

void AnCraiteGreatsword::onDeploy(Field &, Field &)
{
    timer = 2;
}

void AnCraiteGreatsword::onTurnStart(Field &ally, Field &enemy)
{
    if (--timer)
        return;

    timer = 2;

    if (power >= powerBase)
        return;

    heal(this, ally, enemy);
    strengthen(this, 2, ally, enemy);
}

DimunLightLongship::DimunLightLongship()
{
    name = "Dimun Light Longship";
    url = "https://gwent.one/img/assets/medium/art/1263.jpg";
    text = "On turn end, damage the unit to the right by 1, then boost self by 2.";
    power = powerBase = 7;
    rarity = Bronze;
    faction = Skellige;
    tags = { ClanDimun, Machine };
}

void DimunLightLongship::onTurnEnd(Field &ally, Field &enemy)
{
    Row row;
    Pos pos;
    if (!rowAndPos(this, ally, row, pos))
        return;
    if (Card *right = cardAtRowAndPos(row, pos + 1, ally)) {
//        ally.snapshots.push_back(new Animation("", Animation::LineDamage, this, right));
        damage(right, 1, ally, enemy);
        boost(this, 2, ally, enemy);
    }
}

Bear::Bear()
{
    id = "152406";
    name = "Bear";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 11;
    rarity = Bronze;
    faction = Neutral;
    tags = { Beast, Cursed };
}

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
}

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
}

void TuirseachBearmaster::onDeploy(Field &ally, Field &enemy)
{
    spawn(new Bear(), ally, enemy);
}

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
}

void RedanianElite::onDeploy(Field &ally, Field &enemy)
{
    gainArmor(this, 4, ally, enemy);
}

void RedanianElite::onArmorLost(Field &ally, Field &enemy)
{
    boost(this, 5, ally, enemy);
}

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
}

void RedanianKnight::onTurnEnd(Field &ally, Field &enemy)
{
    if (armor != 0)
        return;
    boost(this, 2, ally, enemy);
    gainArmor(this, 2, ally, enemy);
}

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
}

void KaedweniCavalry::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {hasArmor});
}

void KaedweniCavalry::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    const int armorTarget = target->armor;
    damage(target, armorTarget, ally, enemy);
    boost(this, armorTarget, ally, enemy);
}

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
}

void AlzursThunder::onPlaySpecial(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this);
}

void AlzursThunder::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
//    ally.snapshots.push_back(new Animation("", Animation::LineDamage, this, target));
    damage(target, 9, ally, enemy);
}

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
}

void Swallow::onPlaySpecial(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this);
}

void Swallow::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    boost(target, 10, ally, enemy);
}

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
}

void Thunderbolt::onPlaySpecial(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this);
}

void Thunderbolt::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    boost(target, 3, ally, enemy);
    gainArmor(target, 2, ally, enemy);

    Card *left = cardNextTo(target, ally, enemy, -1);
    Card *right = cardNextTo(target, ally, enemy, 1);

    if (left != nullptr) {
        boost(left, 3, ally, enemy);
        gainArmor(left, 2, ally, enemy);
    }
    if (right != nullptr) {
        boost(right, 3, ally, enemy);
        gainArmor(right, 2, ally, enemy);
    }
}

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
}

void ArachasVenom::onPlaySpecial(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this);
}

void ArachasVenom::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    Card *left = cardNextTo(target, ally, enemy, -1);
    Card *right = cardNextTo(target, ally, enemy, 1);

//    ally.snapshots.push_back(new Animation("", Animation::LineDamage, this, target));
    damage(target, 4, ally, enemy);
    if (left != nullptr) {
//        ally.snapshots.push_back(new Animation("", Animation::LineDamage, this, left));
        damage(left, 4, ally, enemy);
    }
    if (right != nullptr) {
//        ally.snapshots.push_back(new Animation("", Animation::LineDamage, this, right));
        damage(right, 4, ally, enemy);
    }
}

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
}

void KeiraMetz::onDeploy(Field &ally, Field &)
{
    startChoiceToSelectOption(ally, this, {new AlzursThunder(), new Thunderbolt(), new ArachasVenom()});
}

void KeiraMetz::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    acceptOptionAndDeleteOthers(this, target);
    spawn(target, ally, enemy);
}

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
}

void DolBlathannaArcher::onDeploy(Field &ally, Field &enemy)
{
    _nShots = 0;
    startChoiceToTargetCard(ally, enemy, this);
    startChoiceToTargetCard(ally, enemy, this);
}

void DolBlathannaArcher::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
//    ally.snapshots.push_back(new Animation("", Animation::LineDamage, this, target));
    damage(target, ++_nShots == 1 ? 3 : 1, ally, enemy);
}

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
}

void HalfElfHunter::onDeploy(Field &ally, Field &enemy)
{
    if (!_maySpawnCopy)
        return;

    Row row;
    Pos pos;
    if (!rowAndPos(this, ally, row, pos))
        return;

    HalfElfHunter *copy = static_cast<HalfElfHunter *>(defaultCopy());
    copy->isDoomed = true;
    copy->_maySpawnCopy = false;

    spawn(copy, row, pos + 1, ally, enemy);
}

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
}

void Ambassador::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {}, AllyBoard);
}

void Ambassador::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    boost(target, 12, ally, enemy);
}

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
}

void Assassin::onDeploy(Field &ally, Field &enemy)
{
    if (Card *left = cardNextTo(this, ally, enemy, -1)) {
//        ally.snapshots.push_back(new Animation("", Animation::LineDamage, this, left));
        damage(left, 10, ally, enemy);
    }
}

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
}

void TuirseachArcher::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {}, AnyBoard, 3);
}

void TuirseachArcher::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
//    ally.snapshots.push_back(new Animation("", Animation::LineDamage, this, target));
    damage(target, 1, ally, enemy);
}

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
}

void Infiltrator::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this);
}

void Infiltrator::onTargetChoosen(Card *target, Field &, Field &)
{
    target->isSpy = !target->isSpy;
}

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
}

void ImpenetrableFog::onPlaySpecial(Field &ally, Field &)
{
    startChoiceToSelectEnemyRow(ally, this);
}

void ImpenetrableFog::onTargetRowEnemyChoosen(Field &ally, Field &enemy, const Row row)
{
    applyRowEffect(enemy, ally, row, ImpenetrableFogEffect);
}

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
}

void TorrentialRain::onPlaySpecial(Field &ally, Field &)
{
    startChoiceToSelectEnemyRow(ally, this);
}

void TorrentialRain::onTargetRowEnemyChoosen(Field &ally, Field &enemy, const Row row)
{
    applyRowEffect(enemy, ally, row, TorrentialRainEffect);
}

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
}

void BitingFrost::onPlaySpecial(Field &ally, Field &)
{
    startChoiceToSelectEnemyRow(ally, this);
}

void BitingFrost::onTargetRowEnemyChoosen(Field &ally, Field &enemy, const Row row)
{
    applyRowEffect(enemy, ally, row, BitingFrostEffect);
}

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
}

void GoldenFroth::onPlaySpecial(Field &ally, Field &)
{
    startChoiceToSelectAllyRow(ally, this);
}

void GoldenFroth::onTargetRowAllyChoosen(Field &ally, Field &enemy, const Row row)
{
    applyRowEffect(ally, enemy, row, GoldenFrothEffect);
}

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
}

void SkelligeStorm::onPlaySpecial(Field &ally, Field &)
{
    startChoiceToSelectEnemyRow(ally, this);
}

void SkelligeStorm::onTargetRowEnemyChoosen(Field &ally, Field &enemy, const Row row)
{
    applyRowEffect(enemy, ally, row, SkelligeStormEffect);
}

ImperialManticore::ImperialManticore()
{
    id = "132209";
    name = "Imperial Manticore";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 13;
    rarity = Silver;
    faction = Monster;
    tags = { Beast };
}

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
}

void ManticoreVenom::onPlaySpecial(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this);
}

void ManticoreVenom::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
//    ally.snapshots.push_back(new Animation("", Animation::LineDamage, this, target));
    damage(target, 13, ally, enemy);
}

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
}

void GloriousHunt::onPlaySpecial(Field &ally, Field &enemy)
{
    if (powerField(ally) < powerField(enemy))
        return spawn(new ImperialManticore(), ally, enemy);

    return spawn(new ManticoreVenom(), ally, enemy);
}

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
}

void Ves::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {}, AllyHand, 2, true);
}

void Ves::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    swapACard(target, ally, enemy);
}

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
}

void Vaedermakar::onDeploy(Field &ally, Field &)
{
    startChoiceToSelectOption(ally, this, {new BitingFrost(), new ImpenetrableFog(), new AlzursThunder()});
}

void Vaedermakar::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    acceptOptionAndDeleteOthers(this, target);
    spawn(target, ally, enemy);
}

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
}

void Frightener::onDeploy(Field &ally, Field &enemy)
{
    if (timer == 1) {
        timer--;
        drawACard(ally, enemy);
    }

    /// can't move another to this row, if its already full
    startChoiceToTargetCard(ally, enemy, this, {isOnAnotherRow(&enemy, this)}, EnemyBoard);
}

void Frightener::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    Row row;
    Pos pos;
    if (!rowAndPos(this, enemy, row, pos))
        return;
    if (isRowFull(enemy.row(row)))
        return;
    putOnField(target, row, Pos(enemy.row(row).size()), enemy, ally);
}

Cleaver::Cleaver()
{
    id = "122216";
    name = "Cleaver";
    text = "Deal 1 damage for each card in your hand.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 7;
    rarity = Silver;
    faction = Scoiatael;
    tags = { Dwarf };
}

void Cleaver::onDeploy(Field &ally, Field &enemy)
{
    if (ally.hand.size() != 0)
        startChoiceToTargetCard(ally, enemy, this, {}, AnyBoard);
}

void Cleaver::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
//    ally.snapshots.push_back(new Animation("", Animation::LineDamage, this, target));
    damage(target, int(ally.hand.size()), ally, enemy);
}

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
}

void Scorch::onPlaySpecial(Field &ally, Field &enemy)
{
    for (Card *card : highests(cardsFiltered(ally, enemy, {}, AnyBoard)))
        putOnDiscard(card, ally, enemy);
}

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
}

void Reinforcements::onPlaySpecial(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilver, hasAnyOfTags({Soldier, Support, Machine, Officer})}, AllyDeckShuffled);
}

void Reinforcements::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    playCard(target, ally, enemy);
}

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
}

void JohnNatalis::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilver, hasTag(Tactics)}, AllyDeckShuffled);
}

void JohnNatalis::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    playCard(target, ally, enemy);
}

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
}

void Eleyas::onDraw(Field &ally, Field &enemy)
{
    boost(this, 2, ally, enemy);
}

void Eleyas::onSwap(Field &ally, Field &enemy)
{
    boost(this, 2, ally, enemy);
}

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
}

void ReaverScout::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isBronze, otherThan(name), hasCopyInADeck(&ally)}, AllyBoard);
}

void ReaverScout::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    if (Card *copy = findCopy(target, ally.deck))
        playCard(copy, ally, enemy);
}

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
}

void HeymaeySpearmaiden::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isBronze, hasAnyOfTags({Soldier, Machine}), hasCopyInADeck(&ally)}, AllyBoard);
}

void HeymaeySpearmaiden::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
//    ally.snapshots.push_back(new Animation("", Animation::LineDamage, this, target));
    damage(target, 1, ally, enemy);
    if (Card *copy = findCopy(target, ally.deck))
        playCard(copy, ally, enemy);
}

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
}

void KaedweniKnight::onDeploy(Field &ally, Field &enemy)
{
    gainArmor(this, 2, ally, enemy);
}

void KaedweniKnight::onDeployFromDeck(Field &ally, Field &enemy)
{
    gainArmor(this, 2, ally, enemy);
    boost(this, 5, ally, enemy);
}

VriheddSappers::VriheddSappers()
{
    id = "142307";
    name = "Vrihedd Sappers";
    text = "Ambush: After 2 turns, flip over on turn start.";
    url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";
    power = powerBase = 11;
    rarity = Bronze;
    faction = Scoiatael;
    tags = { Elf, Soldier };
}

void VriheddSappers::onDeploy(Field &, Field &)
{
    timer = 2;
    isAmbush = true;
}

void VriheddSappers::onTurnStart(Field &, Field &)
{
    if (!timer)
        return;
    if (--timer)
        return;
    isAmbush = false;
}

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
}

void PriestessOfFreya::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isBronze, hasTag(Soldier)}, AllyDiscard);
}

void PriestessOfFreya::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    playCard(target, ally, enemy);
}

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
}

void DimunCorsair::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isBronze, hasTag(Machine)}, AllyDiscard);
}

void DimunCorsair::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    playCard(target, ally, enemy);
}

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
}

void Sigrdrifa::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilver, hasAnyOfTags({ClanAnCraite, ClanDimun, ClanDrummond, ClanHeymaey, ClanTuirseach, ClanBrokvar, ClanTordarroch})}, AllyDiscard);
}

void Sigrdrifa::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    playCard(target, ally, enemy);
}

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
}

void Sage::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isBronze, hasAnyOfTags({Alchemy, Spell})}, AllyDiscard);
}

void Sage::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    playCard(target, ally, enemy);
    banish(target, ally, enemy);
}

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
}

void Reconnaissance::onPlaySpecial(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, randoms(cardsFiltered(ally, enemy, {isBronze, isUnit}, AllyDeck), 2, ally.rng));
}

void Reconnaissance::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    playCard(target, ally, enemy);
}

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
}

void ElvenMercenary::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, randoms(cardsFiltered(ally, enemy, {isBronze, ::isSpecial}, AllyDeck), 2, ally.rng));
}

void ElvenMercenary::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    playCard(target, ally, enemy);
}

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
}

void ChampionOfHov::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {}, EnemyBoard);
}

void ChampionOfHov::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    duel(this, target, ally, enemy);
}

GeraltIgni::GeraltIgni(const Lang lang)
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
}

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
}

void GeraltIgni::onDeploy(Field &ally, Field &)
{
    // TODO: select only between rows with 25 or more power
    startChoiceToSelectEnemyRow(ally, this);
}

void GeraltIgni::onTargetRowEnemyChoosen(Field &ally, Field &enemy, const Row row)
{
    if (powerRow(enemy.row(row)) < 25)
        return;

    for (Card *card : highests(enemy.row(row)))
        putOnDiscard(card, ally, enemy);
}

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
}

void Priscilla::onDeploy(Field &ally, Field &enemy)
{
    for (Card *card : randoms(cardsFiltered(ally, enemy, {[=](Card *card){ return card != this; }}, AllyBoard), 5, ally.rng))
        boost(card, 3, ally, enemy);
}

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
}

void SeltkirkOfGulet::onDeploy(Field &ally, Field &enemy)
{
    gainArmor(this, 3, ally, enemy);
    startChoiceToTargetCard(ally, enemy, this, {}, EnemyBoard);
}

void SeltkirkOfGulet::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    duel(this, target, ally, enemy);
}

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
}

void AdrenalineRush::onPlaySpecial(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this);
}

void AdrenalineRush::onTargetChoosen(Card *target, Field &, Field &)
{
    target->isResilient = !target->isResilient;
}

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
}

void ShupesDayOff::onPlaySpecial(Field &ally, Field &)
{
    if (!hasNoDuplicates(ally.deckStarting))
        return;

    startChoiceToSelectOption(ally, this, {new ShupeKnight(), new ShupeHunter(), new ShupeMage()});
}

void ShupesDayOff::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    acceptOptionAndDeleteOthers(this, target);
    spawn(target, ally, enemy);
}

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
}

void ShupeHunter::onDeploy(Field &ally, Field &)
{
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
}

void ShupeHunter::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
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
                boost(card, 1, ally, enemy);
            clearAllHazards(ally);
            delete _choosen;
            _choosen = nullptr;
            return;
        }

        if (dynamic_cast<ShupeHunter::Barrage *>(_choosen)) {
            for (int n = 0; n < 8; ++n)
                if (Card *card = random(cardsFiltered(ally, enemy, {}, EnemyBoard), ally.rng)) {
//                    ally.snapshots.push_back(new Animation("", Animation::LineDamage, this, card));
                    damage(card, 2, ally, enemy);
                }
            delete _choosen;
            _choosen = nullptr;
            return;
        }

        assert(false);
    }

    if (dynamic_cast<ShupeHunter::Play *>(_choosen)) {
        playCard(target, ally, enemy);
        delete _choosen;
        _choosen = nullptr;
        return;
    }

    if (dynamic_cast<ShupeHunter::Shot *>(_choosen)) {
//        ally.snapshots.push_back(new Animation("", Animation::LineDamage, this, target));
        damage(target, 15, ally, enemy);
        delete _choosen;
        _choosen = nullptr;
        return;
    }

    if (dynamic_cast<ShupeHunter::Replay *>(_choosen)) {
        putToHand(target, ally, enemy);
        boost(target, 5, ally, enemy);
        playCard(target, ally, enemy);
        delete _choosen;
        _choosen = nullptr;
        return;
    }

    assert(false);
}

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
}

void ShupeMage::onDeploy(Field &ally, Field &)
{
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
}

void ShupeMage::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
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
                charm(card, ally, enemy);
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

//        ally.snapshots.push_back(new Animation("", Animation::LineDamage, this, target));
        damage(target, 10, ally, enemy);
        if (left != nullptr) {
//            ally.snapshots.push_back(new Animation("", Animation::LineDamage, this, left));
            damage(left, 5, ally, enemy);
        }
        if (right != nullptr) {
//            ally.snapshots.push_back(new Animation("", Animation::LineDamage, this, right));
            damage(right, 5, ally, enemy);
        }

        delete _choosen;
        _choosen = nullptr;
        return;
    }

    if (dynamic_cast<ShupeMage::Play *>(_choosen)) {
        playCard(target, ally, enemy);

        delete _choosen;
        _choosen = nullptr;
        return;
    }

    assert(false);
}

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
}

void Mandrake::onPlaySpecial(Field &ally, Field &)
{
    auto *option1 = new Mandrake::Buff;
    copyCardText(this, option1);
    option1->text = "Heal a unit and and Strengthen it by 6.";

    auto *option2 = new Mandrake::Debuff;
    copyCardText(this, option2);
    option2->text = "Reset a unit and Weaken it by 6.";

    startChoiceToSelectOption(ally, this, {option1, option2});
}

void Mandrake::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
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
        weaken(target, 6, ally, enemy);

        delete _choosen;
        _choosen = nullptr;
        return;
    }

    assert(false);
}

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
}

void BoneTalisman::onPlaySpecial(Field &ally, Field &)
{
    auto *option1 = new BoneTalisman::Resurrect;
    copyCardText(this, option1);
    option1->text = "Resurrect a Bronze Beast or Cultist.";

    auto *option2 = new BoneTalisman::Buff;
    copyCardText(this, option2);
    option2->text = "Heal an ally and Strengthen it by 3.";

    startChoiceToSelectOption(ally, this, {option1, option2});
}

void BoneTalisman::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
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
        playCard(target, ally, enemy);

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
}

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
}

bool ShupeKnight::isFourOrLessPower(Card *card)
{
    return card->power <= 4;
}

void ShupeKnight::onDeploy(Field &ally, Field &)
{
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
}

void ShupeKnight::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    if (_options.size() > 0) {
        _choosen = target;
        acceptOptionAndDeleteOthers(this, target);

        if (dynamic_cast<ShupeKnight::Destroy *>(_choosen)) {
            for (Card *card : cardsFiltered(ally, enemy, {isFourOrLessPower}, EnemyBoard))
                putOnDiscard(card, ally, enemy);
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
}

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
}

void Decoy::onPlaySpecial(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, { isBronzeOrSilver }, AllyBoard);
}

void Decoy::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    putToHand(target, ally, enemy);
    boost(target, 3, ally, enemy);
    playCard(target, ally, enemy);
}

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
}

void FirstLight::onPlaySpecial(Field &ally, Field &)
{
    auto *option1 = new FirstLight::Clear;
    copyCardText(this, option1);
    option1->text = "Boost all damaged allies under Hazards by 2 and clear all Hazards from your side.";

    auto *option2 = new FirstLight::Play;
    copyCardText(this, option2);
    option2->text = "Play a random Bronze unit from your deck.";

    startChoiceToSelectOption(ally, this, {option1, option2});
}

void FirstLight::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
     acceptOptionAndDeleteOthers(this, target);

     if (dynamic_cast<FirstLight::Clear *>(target)) {
         std::vector<Card *> damagedUnitsUnderHazards;
         clearAllHazards(ally, &damagedUnitsUnderHazards);
         for (Card *card : damagedUnitsUnderHazards)
             boost(card, 2, ally, enemy);
         delete target;
         return;
     }

     if (dynamic_cast<FirstLight::Play *>(target)) {
         if (Card *card = random(cardsFiltered(ally, enemy, { isBronze, isUnit }, AllyDeck), ally.rng))
             playCard(card, ally, enemy);
         delete target;
         return;
     }

     assert(false);
}

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
}

void ClearSkies::onPlaySpecial(Field &ally, Field &enemy)
{
    std::vector<Card *> damagedUnitsUnderHazards;
    clearAllHazards(ally, &damagedUnitsUnderHazards);
    for (Card *card : damagedUnitsUnderHazards)
        boost(card, 2, ally, enemy);
}

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
}

void Epidemic::onPlaySpecial(Field &ally, Field &enemy)
{
    for (Card *card : lowests(cardsFiltered(ally, enemy, {}, AnyBoard)))
        putOnDiscard(card, ally, enemy);
}

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
}

void Moonlight::onPlaySpecial(Field &ally, Field &)
{
    auto *option1 = new Moonlight::FullMoon;
    copyCardText(this, option1);
    option1->name = "Full Moon";
    option1->text = "Apply a Boon to an allied row that boosts a random Beast or Vampire by 2 on turn start.";

    auto *option2 = new Moonlight::BloodMoon;
    copyCardText(this, option2);
    option2->name = "Blood Moon";
    option2->text = "Apply a Hazard to an enemy row that deals 2 damage to all units on contact.";

    startChoiceToSelectOption(ally, this, {option1, option2});
}

void Moonlight::onTargetChoosen(Card *target, Field &ally, Field &)
{
    acceptOptionAndDeleteOthers(this, target);
    if (dynamic_cast<Moonlight::FullMoon *>(target)) {
        startChoiceToSelectAllyRow(ally, this);

    } else if (dynamic_cast<Moonlight::BloodMoon *>(target)) {
        startChoiceToSelectEnemyRow(ally, this);

    } else
        assert(false);

    delete target;
}

void Moonlight::onTargetRowAllyChoosen(Field &ally, Field &enemy, const Row row)
{
    applyRowEffect(ally, enemy, row, FullMoonEffect);
}

void Moonlight::onTargetRowEnemyChoosen(Field &ally, Field &enemy, const Row row)
{
    applyRowEffect(enemy, ally, row, BloodMoonEffect);
}

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
}

void CiriNova::onDeploy(Field &ally, Field &enemy)
{
    if (!hasExactTwoDuplicatesOfBronze(ally.deckStarting))
        return;

    strengthen(this, 22 - powerBase, ally, enemy);
}

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
}

void HaraldTheCripple::onDeploy(Field &ally, Field &enemy)
{
    Row row;
    Pos pos;
    if (!rowAndPos(this, ally, row, pos))
        return;
    for (int n = 0; n < 9; ++n)
        if (Card *card = random(enemy.row(row), ally.rng)) {
//            ally.snapshots.push_back(new Animation("", Animation::LineDamage, this, card));
            damage(card, 1, ally, enemy);
        }
}

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
}

void Emissary::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, randoms(cardsFiltered(ally, enemy, {isBronze, isUnit}, AllyDeckShuffled), 2, ally.rng));
}

void Emissary::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    playCard(target, ally, enemy);
}

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
}

void CeallachDyffryn::onDeploy(Field &ally, Field &)
{
    startChoiceToSelectOption(ally, this, {new Ambassador(), new Assassin(), new Emissary()});
}

void CeallachDyffryn::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    acceptOptionAndDeleteOthers(this, target);
    spawn(target, ally, enemy);
}

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
}

void Restore::onPlaySpecial(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilver, isUnit, isSkelligeFaction}, AllyDiscard);
}

void Restore::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    putToHand(target, ally, enemy);
    target->isDoomed = true;
    target->powerBase = target->power = 8;
    playCard(target, ally, enemy);
}

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
}

void DrummondQueensguard::onDeploy(Field &ally, Field &enemy)
{
    Row row;
    Pos pos;
    if (!rowAndPos(this, ally, row, pos))
        return;
    for (Card *card : cardsFiltered(ally, enemy, {isCopy(name)}, AllyDiscard)) {
        if (isRowFull(ally.row(row)))
            break;
        putOnField(card, row, ++pos, ally, enemy);
    }
}

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
}

void BranTuirseach::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {}, AllyDeckShuffled, 3, true);
}

void BranTuirseach::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    putOnDiscard(target, ally, enemy);
    if (!target->isSpecial)
        strengthen(target, 1, ally, enemy);
}

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
}

void DrummondWarmonger::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isBronze}, AllyDeckShuffled);
}

void DrummondWarmonger::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    putOnDiscard(target, ally, enemy);
}

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
}

void DimunPirate::onDeploy(Field &ally, Field &enemy)
{
    for (Card *card : cardsFiltered(ally, enemy, {isCopy(name)}, AllyDeck))
        putOnDiscard(card, ally, enemy);
}

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
}

void AnCraiteRaider::onDiscard(Field &ally, Field &enemy)
{
    Row row;
    Pos pos;
    if (randomRowAndPos(ally, row, pos))
        putOnField(this, row, pos, ally, enemy);
}

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
}

void MadmanLugos::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isBronze, isUnit}, AllyDeckShuffled);
}

void MadmanLugos::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    if (_discarded == nullptr) {
        _discarded = target;

        putOnDiscard(target, ally, enemy);
        startChoiceToTargetCard(ally, enemy, this, {}, EnemyBoard);
        return;
    }

    damage(target, _discarded->powerBase, ally, enemy);
}

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
}

void Ermion::onDeploy(Field &ally, Field &enemy)
{
    drawACard(ally, enemy);
    drawACard(ally, enemy);
    startChoiceToTargetCard(ally, enemy, this, {}, AllyHand, 2);
}

void Ermion::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    putOnDiscard(target, ally, enemy);
}

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
}

void CerysFearless::onDeploy(Field &, Field &)
{
    timer = 1;
}

void CerysFearless::onOtherAllyDiscarded(Card *other, Field &ally, Field &enemy)
{
    if (timer == 0 || other->isSpecial)
        return;

    if (!isOnBoard(this, ally))
        return;

    timer--;
    playCard(other, ally, enemy);
}

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
}

void CerysAnCraite::onDiscard(Field &, Field &)
{
    timer = 4;
}

void CerysAnCraite::onDestroy(Field &, Field &, const Row, const Pos)
{
    timer = 4;
}

void CerysAnCraite::onOtherAllyResurrecteded(Card *, Field &ally, Field &enemy)
{
    if (!isIn(this, ally.discard))
        return;

    if (timer > 0)
        timer--;

    Row row;
    Pos pos;
    if (timer == 0 && randomRowAndPos(ally, row, pos))
        putOnField(this, row, pos, ally, enemy);
}

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
}

void WoodlandSpirit::onDeploy(Field &ally, Field &enemy)
{
    Row row;
    Pos pos;
    if (!rowAndPos(this, ally, row, pos))
        return;
    applyRowEffect(enemy, ally, row, ImpenetrableFogEffect);
    for (int n = 0; n < 3; ++n)
        if (!isRowFull(ally.rowMeele))
            spawn(new Wolf(), Meele, Pos(ally.rowMeele.size()), ally, enemy);
}

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
}

void Trollololo::onDeploy(Field &ally, Field &enemy)
{
    gainArmor(this, 9, ally, enemy);
}

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
}

void PrinceStennis::onDeploy(Field &ally, Field &enemy)
{
    gainArmor(this, 3, ally, enemy);
    const std::vector<Card *> cards = cardsFiltered(ally, enemy, {isNonSpying, isBronzeOrSilver, isUnit}, AllyDeck);
    if (cards.size() == 0)
        return;

    Card *target = cards.front();
    playCard(target, ally, enemy);
    gainArmor(target, 5, ally, enemy);
}

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
}

void VincentMeis::onDeploy(Field &ally, Field &enemy)
{
    int _armor = 0;
    for (Card *target: cardsFiltered(ally, enemy, {hasArmor}, AnyBoard)) {
        const int armorTarget = target->armor;
        damage(target, armorTarget, ally, enemy);
        _armor += armorTarget;
    }
    boost(this, _armor / 2, ally, enemy);
}

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
}

void Morkvarg::onDiscard(Field &ally, Field &enemy)
{
    if (weaken(this, int(std::ceil(powerBase / 2.0)), ally, enemy))
        return;

    Row row;
    Pos pos;
    if (randomRowAndPos(ally, row, pos))
        putOnField(this, row, pos, ally, enemy);
}

void Morkvarg::onDestroy(Field &ally, Field &enemy, const Row row, const Pos pos)
{
    if (weaken(this, int(std::ceil(powerBase / 2.0)), ally, enemy))
        return;

    putOnField(this, row, pos, ally, enemy);
}

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
}

void ArtefactCompression::onPlaySpecial(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilver});
}

void ArtefactCompression::onTargetChoosen(Card *target, Field &, Field &)
{
    transform(target, id, "Jade Figurine", "", url, 2, Bronze, Neutral);
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
}

void HjalmarAnCraite::LordOfUndvik::onDestroy(Field &ally, Field &enemy, const Row, const Pos)
{
    // FIXME: not working, because its doomed
    for (Card *card : cardsFiltered(ally, enemy, {isCopy("Hjalmar an Craite")}, EnemyBoard))
        boost(card, 10, ally, enemy);
}

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
}

void HjalmarAnCraite::onDeploy(Field &ally, Field &enemy)
{
    Row row;
    Pos pos;
    if (!rowAndPos(this, ally, row, pos))
        return;
    if (isRowFull(enemy.row(row)))
        return;
    spawn(new LordOfUndvik(), row, Pos(enemy.row(row).size()), enemy, ally);
}

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
}

void Regis::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isBoosted}, AnyBoard);
}

void Regis::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    const int x = target->power - target->powerBase;
    drain(target, x, ally, enemy, this);
}

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
}

void LethoOfGulet::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isOnSameRow(&enemy, this)}, EnemyBoard, 2);
}

void LethoOfGulet::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    target->isLocked = true;
    drain(target, target->power, ally, enemy, this);
}

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
}

void AnCraiteLongship::onDeploy(Field &ally, Field &enemy)
{
    if (Card *card = random(cardsFiltered(ally, enemy, {}, EnemyBoard), ally.rng))
        damage(card, 2, ally, enemy);
}

void AnCraiteLongship::onOtherAllyDiscarded(Card *, Field &ally, Field &enemy)
{
    if (isOnBoard(this, ally))
        AnCraiteLongship::onDeploy(ally, enemy);
}

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
}

void TuirseachVeteran::onDeploy(Field &ally, Field &enemy)
{
    for (Card *card : cardsFiltered(ally, enemy, {hasTag(ClanTuirseach), otherThan(this)}, AllyBoardHandDeck))
        strengthen(card, 1, ally, enemy);
}

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
}

void TuirseachHunter::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this);
}

void TuirseachHunter::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    damage(target, 5, ally, enemy);
}

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
}

void Udalryk::onDeploy(Field &ally, Field &enemy)
{
    if (timer != 1)
        return;

    timer--;
    startChoiceToTargetCard(ally, enemy, this, _drawn = randoms(cardsFiltered(ally, enemy, {}, AllyDeck), 2, ally.rng));
}

void Udalryk::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    putToHand(target, ally, enemy);
    for (Card *card : _drawn)
        if (card != target)
            putOnDiscard(card, ally, enemy);

    _drawn.clear();
}

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
}

void BloodcurdlingRoar::onPlaySpecial(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {}, AllyBoard);
}

void BloodcurdlingRoar::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    putOnDiscard(target, ally, enemy);
    spawn(new Bear(), ally, enemy);
}

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
}

void Gremist::onDeploy(Field &ally, Field &)
{
    startChoiceToSelectOption(ally, this, {new TorrentialRain(), new ClearSkies(), new BloodcurdlingRoar()});
}

void Gremist::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    acceptOptionAndDeleteOthers(this, target);
    spawn(target, ally, enemy);
}

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
}

void Operator::onDeploy(Field &ally, Field &enemy)
{
    if (ally.passed || enemy.passed)
        return;
    if (timer != 1)
        return;

    timer--;
    startChoiceToTargetCard(ally, enemy, this, {isBronze, isUnit}, AllyHand);
}

void Operator::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    Card *copyAlly = target->defaultCopy();
    ally.cardsAdded.push_back(copyAlly);
    putToHand(copyAlly, ally, enemy);

    Card *copyEnemy = target->defaultCopy();
    enemy.cardsAdded.push_back(copyEnemy);
    putToHand(copyEnemy, enemy, ally);
}

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
}

void ZoriaRunestone::onPlaySpecial(Field &ally, Field &)
{
    startChoiceCreateOptions(ally, this, {isBronzeOrSilver, isNothernRealmsFaction});
}

void ZoriaRunestone::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    acceptOptionAndDeleteOthers(this, target);
    spawn(target, ally, enemy);
}

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
}

void Renew::onPlaySpecial(Field &ally, Field &)
{
    startChoiceCreateOptions(ally, this, {isGold, isNonLeader}, AllyDiscard);
}

void Renew::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    playCard(target, ally, enemy);
}

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
}

void EistTuirseach::onDeploy(Field &ally, Field &)
{
    startChoiceToSelectOption(ally, this, {new TuirseachArcher, new TuirseachAxeman, new TuirseachBearmaster, new TuirseachHunter, new TuirseachSkirmisher});
}

void EistTuirseach::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    acceptOptionAndDeleteOthers(this, target);
    spawn(target, ally, enemy);
}

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
}

void TuirseachAxeman::onDeploy(Field &ally, Field &enemy)
{
    gainArmor(this, 2, ally, enemy);
}

void TuirseachAxeman::onOtherEnemyDamaged(Card *other, Field &ally, Field &enemy)
{
    Pos _;
    Row row;
    if (!rowAndPos(other, enemy, row, _))
        return;
    if (isIn(this, ally.row(row)))
        boost(this, 1, ally, enemy);
}

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
}

void TuirseachSkirmisher::onDeployFromDiscard(Field &ally, Field &enemy)
{
    strengthen(this, 3, ally, enemy);
}

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
}

void Derran::onOtherEnemyDamaged(Card *, Field &ally, Field &enemy)
{
    if (isOnBoard(this, ally))
        boost(this, 1, ally, enemy);
}

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
}

void Roach::onOtherAllyPlayedFromHand(Card *other, Field &ally, Field &enemy)
{
    if (other->rarity != Gold)
        return;

    if (!isIn(this, ally.deck))
        return;

    Row row;
    Pos pos;
    if (randomRowAndPos(ally, row, pos))
        putOnField(this, row, pos, ally, enemy);
}

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
}

void JanCalveit::onDeploy(Field &ally, Field &enemy)
{
    const std::vector<Card *> topThreeCards(ally.deck.begin(), ally.deck.begin() + std::min(int(ally.deck.size()), 3));
    startChoiceToTargetCard(ally, enemy, this, topThreeCards);
}

void JanCalveit::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    playCard(target, ally, enemy);
}

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
}

void CahirDyffryn::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {hasTag(Leader)}, AllyDiscard);
}

void CahirDyffryn::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    playCard(target, ally, enemy);
}

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
}

void LethoKingslayer::onDeploy(Field &ally, Field &)
{
    auto *option1 = new LethoKingslayer::Destroy;
    copyCardText(this, option1);
    option1->text = "Destroy an enemy Leader, then boost self by 5.";

    auto *option2 = new LethoKingslayer::Play;
    copyCardText(this, option2);
    option2->text = "Play a Bronze or Silver Tactic from your deck.";

    startChoiceToSelectOption(ally, this, {option1, option2});
}

void LethoKingslayer::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    if (_options.size() > 0) {
        _choosen = target;
        acceptOptionAndDeleteOthers(this, target);

        if (dynamic_cast<LethoKingslayer::Destroy *>(_choosen)) {
            startChoiceToTargetCard(ally, enemy, this, {hasTag(Leader)}, EnemyBoard);
            return;
        }

        if (dynamic_cast<LethoKingslayer::Play *>(_choosen)) {
            startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilver, hasTag(Tactics)}, AllyDeck);
            return;
        }

        assert(false);
    }

    if (dynamic_cast<LethoKingslayer::Destroy *>(_choosen)) {
        putOnDiscard(target, ally, enemy);
        boost(this, 5, ally, enemy);

        delete _choosen;
        _choosen = nullptr;
        return;
    }

    if (dynamic_cast<LethoKingslayer::Play *>(_choosen)) {
        playCard(target, ally, enemy);

        delete _choosen;
        _choosen = nullptr;
        return;
    }

    assert(false);
}

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
}

void KingHenselt::onDeploy(Field &ally, Field &enemy)
{
    isCrew = true;
    startChoiceToTargetCard(ally, enemy, this, {isBronze, hasAnyOfTags({Machine, Kaedwen})}, AllyBoard);
}

void KingHenselt::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    for (Card *copy : findCopies(target, ally.deck))
        playCard(copy, ally, enemy);
}

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
}

void BloodyBaron::onOtherEnemyDestroyed(Card *, Field &ally, Field &enemy)
{
    if (isOnBoard(this, ally) || isIn(this, ally.deck) || isIn(this, ally.hand))
        boost(this, 1, ally, enemy);
}

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
}

void Dethmold::onDeploy(Field &ally, Field &)
{
    startChoiceToSelectOption(ally, this, {new TorrentialRain(), new ClearSkies(), new AlzursThunder()});
}

void Dethmold::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    acceptOptionAndDeleteOthers(this, target);
    spawn(target, ally, enemy);
}

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
}

void RonvidTheIncessant::onDeploy(Field &, Field &)
{
    isCrew = true;
}

void RonvidTheIncessant::onTurnEnd(Field &ally, Field &enemy)
{

}

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
}

void HubertRejk::onDeploy(Field &ally, Field &enemy)
{
    for (Card *card : cardsFiltered(ally, enemy, {isBoosted}, AllyDeck))
        drain(card, card->power - card->powerBase, ally, enemy, this);
}

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
    rarity = Leader;
    tags = { ClanAnCraite, Leader };
}

void CrachAnCraite::onDeploy(Field &ally, Field &enemy)
{
    if (Card *card = highest(cardsFiltered(ally, enemy, {isUnit, isBronzeOrSilver, isNonSpying}, AllyDeck), ally.rng)) {
        strengthen(card, 2, ally, enemy);
        playCard(card, ally, enemy);
    }
}

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
}

void BirnaBran::onDeploy(Field &ally, Field &)
{
    startChoiceToSelectEnemyRow(ally, this);
}

void BirnaBran::onTargetRowEnemyChoosen(Field &ally, Field &enemy, const Row row)
{
    applyRowEffect(enemy, ally, row, SkelligeStormEffect);
}

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
}

void Coral::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilver, isUnit}, AnyBoard);
}

void Coral::onTargetChoosen(Card *target, Field &, Field &)
{
    transform(target, id, "Jade Figurine", "", "https://gwent.one/image/card/low/cid/png/200053.png", 2, Bronze, Neutral);
}

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
}

void Kambi::Hemdall::onDeploy(Field &ally, Field &enemy)
{
    for (const Row row : std::vector<Row>{Meele, Range, Seige}) {
        ally.rowEffect(row) = NoRowEffect;
        enemy.rowEffect(row) = NoRowEffect;
    }
    for (Card *card : cardsFiltered(ally, enemy, {}, AnyBoard))
        putOnDiscard(card, ally, enemy);
}

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
}

void Vabjorn::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {}, EnemyBoard);
}

void Vabjorn::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    if (isDamaged(target))
        putOnDiscard(target, ally, enemy);
    else
        damage(target, 2, ally, enemy);
}

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
}

void BlueboyLugos::onDeploy(Field &ally, Field &enemy)
{
    spawn(new SpectralWhale(), ally, enemy);
}


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
}

void DjengeFrett::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {}, AllyBoard, 2);
}

void DjengeFrett::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    damage(target, 1, ally, enemy);
    strengthen(this, 2, ally, enemy);
}


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
}

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
}

void DraigBonDhu::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isNonLeader, isUnit}, AllyDiscard, 2);
}

void DraigBonDhu::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    strengthen(target, 3, ally, enemy);
}

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
}

void HolgerBlackhand::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {}, AnyBoard);
}

void HolgerBlackhand::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    if (damage(target, 6, ally, enemy))
        if (Card *card = highest(ally.discard, ally.rng))
            strengthen(card, 3, ally, enemy);
}

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
}

void JuttaAnDimun::onDeploy(Field &ally, Field &enemy)
{
    damage(this, 1, ally, enemy);
}

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
}

void SavageBear::onOtherEnemyPlayedFromHand(Card *other, Field &ally, Field &enemy)
{
    if (isOnBoard(this, ally))
        damage(other, 1, ally, enemy);
}

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
}

void SvanrigeTuirseach::onDeploy(Field &ally, Field &enemy)
{
    drawACard(ally, enemy);
    startChoiceToTargetCard(ally, enemy, this, {}, AllyHand);
}

void SvanrigeTuirseach::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    putOnDiscard(target, ally, enemy);
}

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
}

void Skjall::onDeploy(Field &ally, Field &enemy)
{
    if (Card *card = random(cardsFiltered(ally, enemy, {isUnit, isBronzeOrSilver, hasTag(Cursed)}, AllyDeck), ally.rng))
        playCard(card, ally, enemy);
}

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
}

HaraldHoundsnout::Wilfred::Wilfred()
{
    name = "Wilfred";
    text = "Deathwish: damage all unit on the opposite row by 1.";
    power = powerBase = 1;
    faction = Skellige;
    rarity = Bronze;
    isDoomed = true;
}

void HaraldHoundsnout::Wilfred::onDestroy(Field &ally, Field &enemy, const Row row, const Pos)
{
    for (Card *card : enemy.row(row))
        damage(card, 1, ally, enemy);
}

HaraldHoundsnout::Wilhelm::Wilhelm()
{
    name = "Wilhelm";
    text = "Deathwish: strengthen a random ally by 3.";
    power = powerBase = 1;
    faction = Skellige;
    rarity = Bronze;
    isDoomed = true;
}

void HaraldHoundsnout::Wilhelm::onDestroy(Field &ally, Field &enemy, const Row, const Pos)
{
    if (Card *card = random(cardsFiltered(ally, enemy, {}, AllyBoard), ally.rng))
        strengthen(card, 3, ally, enemy);
}

HaraldHoundsnout::Wilmar::Wilmar()
{
    name = "Wilmar";
    text = "Deathwish: spawn a Bear on a random opponent row.";
    power = powerBase = 1;
    faction = Skellige;
    rarity = Bronze;
    isDoomed = true;
}

void HaraldHoundsnout::Wilmar::onDestroy(Field &ally, Field &enemy, const Row, const Pos)
{
    Row row;
    Pos pos;
    if (randomRowAndPos(enemy, row, pos))
        spawn(new Bear(), row, pos, ally, enemy);
}

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
}

void Yoana::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isUnit, isDamaged}, AllyBoard);
}

void Yoana::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    const int x = target->powerBase - target->power;
    heal(target, ally, enemy);
    boost(target, x, ally, enemy);
}

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
}

void AnCraiteBlacksmith::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {}, AllyBoard);
}

void AnCraiteBlacksmith::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    strengthen(target, 2, ally, enemy);
    gainArmor(target, 2, ally, enemy);
}

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
}

void AnCraiteWarcrier::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {}, AllyBoard);
}

void AnCraiteWarcrier::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    boost(target, int(std::floor(target->power / 2.0)), ally, enemy);
}


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
}

void AnCraiteWarrior::onDeploy(Field &ally, Field &enemy)
{
    damage(this, 1, ally, enemy);
}

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
}

void BerserkerMarauder::onDeploy(Field &ally, Field &enemy)
{
    const auto isDamagedOrCursed = [=](Card *card) {
        return (card != this) && (isDamaged(card) || hasTag(card, Cursed));
    };
    const int nUnits = int(cardsFiltered(ally, enemy, {isDamagedOrCursed}, AllyBoard).size());
    boost(this, nUnits, ally, enemy);
}

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
}

void DimunPirateCaptain::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isBronze, otherThan(name), hasTag(ClanDimun)}, AllyDeckShuffled);
}

void DimunPirateCaptain::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    playCard(target, ally, enemy);
}

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
}

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
}

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
}


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
}

void HeymaeyHerbalist::onDeploy(Field &ally, Field &enemy)
{
    if (Card *target = random(cardsFiltered(ally, enemy, {isBronze, hasAnyOfTags({Organic, Hazard})}, AllyDeck), ally.rng))
        playCard(target, ally, enemy);
}

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
}

void HeymaeyProtector::onDeploy(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isBronze, hasTag(Item)}, AllyDeck);
}

void HeymaeyProtector::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    playCard(target, ally, enemy);
}

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
}

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
}

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
}

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
}

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
}

void Kambi::onDestroy(Field &ally, Field &enemy, const Row, const Pos)
{
    Row row;
    Pos pos;
    if (!randomRowAndPos(ally, row, pos))
        return;
    spawn(new Hemdall(), row, pos, ally, enemy);
}

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
}

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
}

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
}

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
}


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
}


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
}

void BlueboyLugos::SpectralWhale::onTurnEnd(Field &ally, Field &enemy)
{
    // FIXME: ability missing
}

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
}
