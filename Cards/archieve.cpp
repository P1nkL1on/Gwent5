#include "archieve.h"

#include <cassert>
#include <random>

AddaStriga::AddaStriga()
{
    name = "Adda: Striga";
    url = "https://gwent.one/image/card/low/cid/png/200073.png";
    power = powerBase = 6;
    rarity = Silver;
    faction = Monster;
    tags = { Relict, Cursed };
}

bool AddaStriga::isNonMonster(Card *card)
{
    return card->faction != Monster;
}

void AddaStriga::onEnter(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isNonMonster});
}

void AddaStriga::onTargetChoosen(Card *, Field &, Field &)
{
    // deal 8 dmg
}

Dao::Dao()
{
    name = "D'ao";
    text = "Deathwish: Spawn 2 Lesser D'ao on this row.";
    url = "https://gwent.one/image/card/low/cid/png/132213.png";
    power = powerBase = 6;
    rarity = Bronze;
    faction = Monster;
    tags = { Construct };
}

void Dao::onDestroy(Field &ally, Field &enemy, const Row row, const Pos pos)
{
    spawn(new DaoLesser, row, pos, ally, enemy);
    spawn(new DaoLesser, row, pos, ally, enemy);
}

Dao::DaoLesser::DaoLesser()
{
    name = "D'ao Lesser";
    url = "https://gwent.one/image/card/low/cid/png/132405.png";
    power = powerBase = 4;
    rarity = Bronze;
    faction = Monster;
    tags = { Construct };
    isDoomed = true;
}

PoorFingInfantry::LeftFlankInfantry::LeftFlankInfantry()
{
    name = "Left Flank Infantry";
    url = "https://gwent.one/image/card/low/cid/png/200302.png";
    power = powerBase = 2;
    rarity = Bronze;
    faction = NothernRealms;
    tags = { Temeria, Soldier };
    isDoomed = true;
}

PoorFingInfantry::RightFlankInfantry::RightFlankInfantry()
{
    name = "Right Flank Infantry";
    url = "https://gwent.one/image/card/low/cid/png/200303.png";
    power = powerBase = 2;
    rarity = Bronze;
    faction = NothernRealms;
    tags = { Temeria, Soldier };
    isDoomed = true;
}

PoorFingInfantry::PoorFingInfantry()
{
    name = "Poor F'ing Infantry";
    url = "https://gwent.one/image/card/low/cid/png/200234.png";
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

void PoorFingInfantry::onEnter(Field &ally, Field &enemy)
{
    Row row;
    Pos pos;
    if (!rowAndPos(this, ally, row, pos))
        return;
    spawn(new LeftFlankInfantry, row, pos, ally, enemy);
    spawn(new RightFlankInfantry, row, pos + 2, ally, enemy);
}

DeithwenArbalest::DeithwenArbalest()
{
    name = "Deithwen Arbalest";
    url = "https://gwent.one/image/card/low/cid/png/162305.png";
    power = powerBase = 7;
    rarity = Bronze;
    faction = Nilfgaard;
    tags = { Soldier };
}

void DeithwenArbalest::onEnter(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {}, Enemy);
}

void DeithwenArbalest::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
//    ally.snapshots.push_back(new Animation("", Animation::LineDamage, this, target));
    damage(target, target->isSpy ? 6 : 3, ally, enemy);
}

TemerianDrummer::TemerianDrummer()
{
    name = "Temerian Drummer";
    url = "https://gwent.one/image/card/low/cid/png/200299.png";
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

void TemerianDrummer::onEnter(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {}, Ally);
}

void TemerianDrummer::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    boost(target, 6, ally, enemy);
}

DandelionPoet::DandelionPoet()
{
    name = "Dandelion: Poet";
    url = "https://gwent.one/image/card/low/cid/png/201776.png";
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

void DandelionPoet::onEnter(Field &ally, Field &enemy)
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
    name = "S'ile de Tansarville";
    url = "https://gwent.one/image/card/low/cid/png/122205.png";
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

bool SileDeTansarville::isBronzeOrSilverSpecialCard(Card *card)
{
    return card->isSpecial && (card->rarity == Bronze || card->rarity == Silver);
}

void SileDeTansarville::onEnter(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilverSpecialCard}, AllyHand);
}

void SileDeTansarville::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    playCard(target, ally, enemy);
    drawACard(ally, enemy);
}

RedanianKnightElect::RedanianKnightElect()
{
    name = "Redanian Knight Elect";
    url = "https://gwent.one/image/card/low/cid/png/123301.png";
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

void RedanianKnightElect::onEnter(Field &ally, Field &enemy)
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
    name = "An Craite Marauder";
    url = "https://gwent.one/image/card/low/cid/png/201578.png";
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
    name = "An Craite Greatsword";
    url = "https://gwent.one/image/card/low/cid/png/200040.png";
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

void AnCraiteGreatsword::onEnter(Field &, Field &)
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

DimunDracar::DimunDracar()
{
    name = "Dimun Dracard";
    power = powerBase = 7;
    rarity = Bronze;
    faction = Skellige;
    tags = { ClanDimun, Machine };
}

void DimunDracar::onTurnEnd(Field &ally, Field &enemy)
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
    name = "Bear";
    url = "https://gwent.one/image/card/low/cid/png/152406.png";
    power = powerBase = 11;
    rarity = Bronze;
    faction = Neutral;
    tags = { Beast, Cursed };
}

TuirseachBearmaster::TuirseachBearmaster()
{
    name = "Tuirseach Bearmaster";
    text = "Spawn a Bear.";
    url = "https://gwent.one/image/card/low/cid/png/200144.png";
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

void TuirseachBearmaster::onEnter(Field &ally, Field &enemy)
{
    spawn(new Bear, ally, enemy);
}

RedanianElite::RedanianElite()
{
    name = "Redanian Elite";
    url = "https://gwent.one/image/card/low/cid/png/122317.png";
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

void RedanianElite::onEnter(Field &ally, Field &enemy)
{
    gainArmor(this, 4, ally, enemy);
}

void RedanianElite::onArmorLost(Field &ally, Field &enemy)
{
    boost(this, 5, ally, enemy);
}

RedanianKnight::RedanianKnight()
{
    name = "Redanian Knight";
    url = "https://gwent.one/image/card/low/cid/png/122308.png";
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

void RedanianKnight::onEnter(Field &ally, Field &enemy)
{
    gainArmor(this, 2, ally, enemy);
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
    name = "Kaedweni Cavalry";
    url = "https://gwent.one/image/card/low/cid/png/122314.png";
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

bool KaedweniCavalry::hasArmor(Card *card)
{
    return card->armor > 0;
}

void KaedweniCavalry::onEnter(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {hasArmor});
}

void KaedweniCavalry::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    const int armorTarget = target->armor;
//    ally.snapshots.push_back(new Animation("", Animation::LineDamage, this, target));
    damage(target, armorTarget, ally, enemy);
    boost(this, armorTarget, ally, enemy);
}

AlzursThunder::AlzursThunder()
{
    name = "Alzur's Thunder";
    text = "Deal 9 damage.";
    url = "https://gwent.one/image/card/low/cid/png/113301.png";
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
    name = "Swallow";
    text = "Boost a unit by 10.";
    url = "https://gwent.one/image/card/low/cid/png/113310.png";
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
    name = "Thunderbolt";
    url = "https://gwent.one/image/card/low/cid/png/113311.png";
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
    name = "Arachas Venom";
    text = "Deal 4 damage to 3 adjacent units.";
    url = "https://gwent.one/image/card/low/cid/png/200023.png";
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
    name = "Keira Metz";
    url = "https://gwent.one/image/card/low/cid/png/122108.png";
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

void KeiraMetz::onEnter(Field &ally, Field &)
{
    startChoiceToSelectOption(ally, this, {new AlzursThunder, new Thunderbolt, new ArachasVenom});
}

void KeiraMetz::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    acceptOptionAndDeleteOthers(this, target);
    spawn(target, ally, enemy);
}

DolBlathannaArcher::DolBlathannaArcher()
{
    name = "Dol Blathanna Archer";
    url = "https://gwent.one/image/card/low/cid/png/142310.png";
    power = powerBase = 7;
    rarity = Bronze;
    faction = Scoiatael;
    tags = { Elf, Soldier };
}

void DolBlathannaArcher::onEnter(Field &ally, Field &enemy)
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
    name = "Half-Elf Hunter";
    url = "https://gwent.one/image/card/low/cid/png/201636.png";
    power = powerBase = 6;
    rarity = Bronze;
    faction = Scoiatael;
    tags = { Elf, Soldier };
}

void HalfElfHunter::onEnter(Field &ally, Field &enemy)
{
    if (!_maySpawnCopy)
        return;

    Row row;
    Pos pos;
    if (!rowAndPos(this, ally, row, pos))
        return;

    auto *copy = new HalfElfHunter;
    copy->isDoomed = true;
    copy->_maySpawnCopy = false;

    spawn(copy, row, pos + 1, ally, enemy);
}

Ambassador::Ambassador()
{
    name = "Ambassador";
    url = "https://gwent.one/image/card/low/cid/png/162315.png";
    power = powerBase = 2;
    isLoyal = false;
    rarity = Bronze;
    faction = Nilfgaard;
    tags = {};
}

void Ambassador::onEnter(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {}, Ally);
}

void Ambassador::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    boost(target, 12, ally, enemy);
}

Assassin::Assassin()
{
    name = "Assassin";
    url = "https://gwent.one/image/card/low/cid/png/200115.png";
    power = powerBase = 1;
    isLoyal = false;
    rarity = Bronze;
    faction = Nilfgaard;
    tags = {};
}

void Assassin::onEnter(Field &ally, Field &enemy)
{
    if (Card *left = cardNextTo(this, ally, enemy, -1)) {
//        ally.snapshots.push_back(new Animation("", Animation::LineDamage, this, left));
        damage(left, 10, ally, enemy);
    }
}

TuirseachArcher::TuirseachArcher()
{
    name = "Tuirseach Archer";
    url = "https://gwent.one/image/card/low/cid/png/152315.png";
    power = powerBase = 8;
    rarity = Bronze;
    faction = Skellige;
    tags = { ClanTuirseach, Soldier };
}

void TuirseachArcher::onEnter(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {}, Any, 3);
}

void TuirseachArcher::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
//    ally.snapshots.push_back(new Animation("", Animation::LineDamage, this, target));
    damage(target, 1, ally, enemy);
}

Infiltrator::Infiltrator()
{
    name = "Infiltrator";
    url = "https://gwent.one/image/card/low/cid/png/200118.png";
    power = powerBase = 10;
    rarity = Bronze;
    faction = Nilfgaard;
    tags = {};
}

void Infiltrator::onEnter(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this);
}

void Infiltrator::onTargetChoosen(Card *target, Field &, Field &)
{
    target->isSpy = !target->isSpy;
}

ImpenetrableFog::ImpenetrableFog()
{
    name = "Impenetrable Fog";
    text = "Apply a Hazard to an enemy row that deals 2 damage to the Highest unit on turn start.";
    url = "https://gwent.one/image/card/low/cid/png/113305.png";
    isSpecial = true;
    rarity = Bronze;
    faction = Neutral;
    tags = { Hazard };
}

void ImpenetrableFog::onPlaySpecial(Field &ally, Field &)
{
    startChoiceToSelectEnemyRow(ally, this);
}

RowEffect ImpenetrableFog::rowEffect() const
{
    return ImpenetrableFogEffect;
}

TorrentialRain::TorrentialRain()
{
    name = "Torrential Rain";
    text = "Apply a Hazard to an enemy row that deals 1 damage to 2 random units on turn start.";
    url = "https://gwent.one/image/card/low/cid/png/113312.png";
    isSpecial = true;
    rarity = Bronze;
    faction = Neutral;
    tags = { Hazard };
}

void TorrentialRain::onPlaySpecial(Field &ally, Field &)
{
    startChoiceToSelectEnemyRow(ally, this);
}

RowEffect TorrentialRain::rowEffect() const
{
    return TorrentialRainEffect;
}

BitingFrost::BitingFrost()
{
    name = "Biting Frost";
    text = "Apply a Hazard to an enemy row that deals 2 damage to the Lowest unit on turn start.";
    url = "https://gwent.one/image/card/low/cid/png/113302.png";
    isSpecial = true;
    rarity = Bronze;
    faction = Neutral;
    tags = { Hazard };
}

void BitingFrost::onPlaySpecial(Field &ally, Field &)
{
    startChoiceToSelectEnemyRow(ally, this);
}

RowEffect BitingFrost::rowEffect() const
{
    return BitingFrostEffect;
}

GoldenFroth::GoldenFroth()
{
    name = "Golden Froth";
    url = "https://gwent.one/image/card/low/cid/png/201749.png";
    isSpecial = true;
    rarity = Bronze;
    faction = Neutral;
    tags = { Hazard };
}

void GoldenFroth::onPlaySpecial(Field &ally, Field &)
{
    startChoiceToSelectAllyRow(ally, this);
}

RowEffect GoldenFroth::rowEffect() const
{
    return GoldenFrothEffect;
}

SkelligeStorm::SkelligeStorm()
{
    name = "Skellige Storm";
    url = "https://gwent.one/image/card/low/cid/png/113203.png";
    isSpecial = true;
    rarity = Silver;
    faction = Neutral;
    tags = { Hazard };
}

void SkelligeStorm::onPlaySpecial(Field &ally, Field &)
{
    startChoiceToSelectEnemyRow(ally, this);
}

RowEffect SkelligeStorm::rowEffect() const
{
    return SkelligeStormEffect;
}

ImperialManticore::ImperialManticore()
{
    name = "Imperial Manticore";
    url = "https://gwent.one/image/card/low/cid/png/132209.png";
    power = powerBase = 13;
    rarity = Silver;
    faction = Monster;
    tags = { Beast };
}

ManticoreVenom::ManticoreVenom()
{
    name = "Manticore Venom";
    text = "Deal 13 damage.";
    url = "https://gwent.one/image/card/low/cid/png/113306.png";
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
    name = "Glorious Hunt";
    text = "If losing, Spawn an Imperial Manticore, otherwise Spawn Manticore Venom.";
    url = "https://gwent.one/image/card/low/cid/png/201635.png";
    isSpecial = true;
    rarity = Silver;
    faction = Neutral;
    tags = { Tactics };
}

void GloriousHunt::onPlaySpecial(Field &ally, Field &enemy)
{
    if (powerField(ally) < powerField(enemy))
        return spawn(new ImperialManticore, ally, enemy);

    return spawn(new ManticoreVenom, ally, enemy);
}

Ves::Ves()
{
    name = "Ves";
    url = "https://gwent.one/image/card/low/cid/png/122204.png";
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

void Ves::onEnter(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {}, AllyHand, 2, true);
}

void Ves::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    swapACard(target, ally, enemy);
}

Vaedermakar::Vaedermakar()
{
    name = "Vaedermakar";
    text = "Spawn Biting Frost, Impenetrable Fog or Alzur's Thunder.";
    url = "https://gwent.one/image/card/low/cid/png/113208.png";
    power = powerBase = 4;
    rarity = Silver;
    faction = Neutral;
    tags = { Mage };
}

void Vaedermakar::onEnter(Field &ally, Field &)
{
    startChoiceToSelectOption(ally, this, {new BitingFrost, new ImpenetrableFog, new AlzursThunder});
}

void Vaedermakar::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    acceptOptionAndDeleteOthers(this, target);
    spawn(target, ally, enemy);
}

Frightener::Frightener()
{
    name = "Frightener";
    url = "https://gwent.one/image/card/low/cid/png/132204.png";
    power = powerBase = 13;
    isLoyal = false;
    timer = 1;
    rarity = Silver;
    faction = Monster;
    tags = { Construct, Agent };
}

bool Frightener::isOnAnotherRow(Card *self, Card *card, const Field &field)
{
    Row rowSelf;
    Pos _;
    if (!rowAndPos(self, field, rowSelf, _))
        return false;
    Row rowCard;
    Pos __;
    if (!rowAndPos(card, field, rowCard, __))
        return false;
    return rowSelf != rowCard;
}

void Frightener::onEnter(Field &ally, Field &enemy)
{
    if (timer--)
        drawACard(ally, enemy);

    /// can't move another to this row, if its already full
    Row row;
    Pos pos;
    if (!rowAndPos(this, enemy, row, pos) || isRowFull(enemy.row(row)))
        return;
    startChoiceToTargetCard(ally, enemy, this, {std::bind(isOnAnotherRow, std::placeholders::_1, this, enemy)}, Enemy);
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
    name = "Cleaver";
    url = "https://gwent.one/image/card/low/cid/png/122216.png";
    power = powerBase = 7;
    rarity = Silver;
    faction = Scoiatael;
    tags = { Dwarf };
}

void Cleaver::onEnter(Field &ally, Field &enemy)
{
    if (ally.hand.size() != 0)
        startChoiceToTargetCard(ally, enemy, this, {}, Any);
}

void Cleaver::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
//    ally.snapshots.push_back(new Animation("", Animation::LineDamage, this, target));
    damage(target, int(ally.hand.size()), ally, enemy);
}

Scorch::Scorch()
{
    name = "Scorch";
    text = "Destroy all the Highest units.";
    url = "https://gwent.one/image/card/low/cid/png/113309.png";
    isSpecial = true;
    rarity = Silver;
    faction = Neutral;
    tags = { Spell };
}

void Scorch::onPlaySpecial(Field &ally, Field &enemy)
{
    for (Card *card : highests(cardsFiltered(ally, enemy, {}, Any)))
        putOnDiscard(card, ally, enemy);
}

Reinforcements::Reinforcements()
{
    name = "Reinforcements";
    url = "https://gwent.one/image/card/low/cid/png/123201.png";
    isSpecial = true;
    rarity = Silver;
    faction = NothernRealms;
    tags = { Tactics };
}

bool Reinforcements::isBronzeOrSilverSoldierMachineOfficerOrSupport(Card *card)
{
    return (card->rarity == Bronze || card->rarity == Silver) && (hasTag(card, Soldier) || hasTag(card, Support) || hasTag(card, Machine) || hasTag(card, Officer));
}

void Reinforcements::onPlaySpecial(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilverSoldierMachineOfficerOrSupport}, AllyDeckShuffled);
}

void Reinforcements::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    playCard(target, ally, enemy);
}

JohnNatalis::JohnNatalis()
{
    name = "John Natalis";
    url = "https://gwent.one/image/card/low/cid/png/122103.png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/VO_JANT_900381_0141.mp3",
        "https://gwent.one/audio/card/ob/en/VO_JANT_300862_0253.mp3",
    };
    power = powerBase = 6;
    rarity = Gold;
    faction = NothernRealms;
    tags = { Temeria, Officer };
}

bool JohnNatalis::isBronzeOrSilverTactics(Card *card)
{
    return (card->rarity == Bronze || card->rarity == Silver) && hasTag(card, Tactics);
}

void JohnNatalis::onEnter(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilverTactics}, AllyDeckShuffled);
}

void JohnNatalis::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    playCard(target, ally, enemy);
}

Eleyas::Eleyas()
{
    name = "Ele'yas";
    url = "https://gwent.one/image/card/low/cid/png/142214.png";
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
    name = "Reaver Scout";
    url = "https://gwent.one/image/card/low/cid/png/122307.png";
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

bool ReaverScout::isDifferentBronzeAllyWhichHasCopyInADeck(Card *card, const Field &field)
{
    return (card->name != "Reaver Scout") && (card->rarity == Bronze) && (findCopy(card, field.deck) != nullptr);
}

void ReaverScout::onEnter(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {std::bind(isDifferentBronzeAllyWhichHasCopyInADeck, std::placeholders::_1, ally)}, Ally);
}

void ReaverScout::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    if (Card *copy = findCopy(target, ally.deck))
        playCard(copy, ally, enemy);
}

HeymaeySpearmaiden::HeymaeySpearmaiden()
{
    name = "Heymaey Spearmaiden";
    url = "https://gwent.one/image/card/low/cid/png/200528.png";
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

bool HeymaeySpearmaiden::isBronzeSoldierOrMachineAllyWhichHasCopyInADeck(Card *card, const Field &field)
{
    return (card->rarity == Bronze) && (hasTag(card, Soldier) || hasTag(card, Machine)) && (findCopy(card, field.deck) != nullptr);
}

void HeymaeySpearmaiden::onEnter(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {std::bind(isBronzeSoldierOrMachineAllyWhichHasCopyInADeck, std::placeholders::_1, ally)}, Ally);
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
    name = "Kaedweni Knight";
    url = "https://gwent.one/image/card/low/cid/png/201622.png";
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

void KaedweniKnight::onEnter(Field &ally, Field &enemy)
{
    gainArmor(this, 2, ally, enemy);
}

void KaedweniKnight::onEnterFromDeck(Field &ally, Field &enemy)
{
    gainArmor(this, 2, ally, enemy);
    boost(this, 5, ally, enemy);
}

VriheddSappers::VriheddSappers()
{
    name = "Vrihedd Sappers";
    url = "https://gwent.one/image/card/low/cid/png/142307.png";
    power = powerBase = 11;
    rarity = Bronze;
    faction = Scoiatael;
    tags = { Elf, Soldier };
}

void VriheddSappers::onEnter(Field &, Field &)
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
    name = "Priestess of Freya";
    text = "Resurrect a Bronze Soldier.";
    url = "https://gwent.one/image/card/low/cid/png/152310.png";
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

bool PriestessOfFreya::isBronzeSoldier(Card *card)
{
    return (card->rarity == Bronze) && hasTag(card, Soldier);
}

void PriestessOfFreya::onEnter(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isBronzeSoldier}, AllyDiscard);
}

void PriestessOfFreya::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    playCard(target, ally, enemy);
}

DimunCorsair::DimunCorsair()
{
    name = "Dimun Corsair";
    url = "https://gwent.one/image/card/low/cid/png/200145.png";
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

bool DimunCorsair::isBronzeMachine(Card *card)
{
    return (card->rarity == Bronze) && hasTag(card, Machine);
}

void DimunCorsair::onEnter(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isBronzeMachine}, AllyDiscard);
}

void DimunCorsair::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    playCard(target, ally, enemy);
}

Sigrdrifa::Sigrdrifa()
{
    name = "Sigrdrifa";
    url = "https://gwent.one/image/card/low/cid/png/152211.png";
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

bool Sigrdrifa::isBronzeOrSilverClanUnit(Card *card)
{
    return (card->rarity == Bronze
            || card->rarity == Silver)
            && (hasTag(card, ClanAnCraite)
             || hasTag(card, ClanDimun)
             || hasTag(card, ClanDrummond)
             || hasTag(card, ClanHeymaey)
             || hasTag(card, ClanTuirseach));
}

void Sigrdrifa::onEnter(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilverClanUnit}, AllyDiscard);
}

void Sigrdrifa::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    playCard(target, ally, enemy);
}

Sage::Sage()
{
    name = "Sage";
    url = "https://gwent.one/image/card/low/cid/png/200138.png";
    power = powerBase = 2;
    rarity = Bronze;
    faction = Scoiatael;
    tags = { Elf, Mage };
}

bool Sage::isBronzeAlchemyOrSpell(Card *card)
{
    return (card->rarity == Bronze) && (hasTag(card, Alchemy) || hasTag(card, Spell));
}

void Sage::onEnter(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isBronzeAlchemyOrSpell}, AllyDiscard);
}

void Sage::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    playCard(target, ally, enemy);
    banish(target, ally, enemy);
}

Reconnaissance::Reconnaissance()
{
    name = "Reconnaissance";
    text = "Look at 2 random Bronze units in your deck, then play 1.";
    url = "https://gwent.one/image/card/low/cid/png/201704.png";
    isSpecial = true;
    rarity = Bronze;
    faction = Neutral;
    tags = { Tactics };
}

bool Reconnaissance::isBronzeUnit(Card *card)
{
    return !card->isSpecial && (card->rarity == Bronze);
}

void Reconnaissance::onPlaySpecial(Field &ally, Field &enemy)
{
    ally.cardStack.push_back(Choice(Target, this, randoms(cardsFiltered(ally, enemy, {isBronzeUnit}, AllyDeckShuffled), 2), 1, true));
}

void Reconnaissance::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    playCard(target, ally, enemy);
}

ElvenMercenary::ElvenMercenary()
{
    name = "Elven Mercenary";
    url = "https://gwent.one/image/card/low/cid/png/142308.png";
    power = powerBase = 1;
    rarity = Bronze;
    faction = Scoiatael;
    tags = { Elf, Soldier };
}

bool ElvenMercenary::isBronzeSpecial(Card *card)
{
    return (card->rarity == Bronze) && card->isSpecial;
}

void ElvenMercenary::onEnter(Field &ally, Field &enemy)
{
    ally.cardStack.push_back(Choice(Target, this, randoms(cardsFiltered(ally, enemy, {isBronzeSpecial}, AllyDeckShuffled), 2), 1, true));
}

void ElvenMercenary::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    playCard(target, ally, enemy);
}

ChampionOfHov::ChampionOfHov()
{
    name = "Champion of Hov";
    url = "https://gwent.one/image/card/low/cid/png/152202.png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/TRL3_FF205_01053125.mp3",
        "https://gwent.one/audio/card/ob/en/TRL3_FF205_01053127.mp3",
    };
    power = powerBase = 7;
    rarity = Silver;
    faction = Skellige;
    tags = { Ogroid };
}

void ChampionOfHov::onEnter(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {}, Enemy);
}

void ChampionOfHov::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    duel(this, target, ally, enemy);
}

GeraltIgni::GeraltIgni(const Lang lang)
{
    name = "Geralt: Igni";
    url = "https://gwent.one/image/card/low/cid/png/112102.png";
    if (lang == En) {
        sounds = {
            "https://gwent.one/audio/card/ob/en/GRLT_GERALT_01129033.mp3",
            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.2.mp3",
            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.1.mp3",
            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.3.mp3",
            "https://gwent.one/audio/card/ob/en/GRLT_GERALT_01054169.mp3",
        };
    } else if (lang == Ru) {
        sounds = {
            "https://gwent.one/audio/card/ob/ru/GRLT_GERALT_01129033.mp3",
            "https://gwent.one/audio/card/ob/ru/SAY.Battlecries.2.mp3",
            "https://gwent.one/audio/card/ob/ru/SAY.Battlecries.1.mp3",
            "https://gwent.one/audio/card/ob/ru/SAY.Battlecries.3.mp3",
            "https://gwent.one/audio/card/ob/ru/GRLT_GERALT_01054169.mp3",
        };
    }
    power = powerBase = 5;
    rarity = Gold;
    faction = Neutral;
    tags = { Witcher };
}

Priscilla::Priscilla()
{
    name = "Priscilla";
    url = "https://gwent.one/image/card/low/cid/png/122202.png";
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

void Priscilla::onEnter(Field &ally, Field &enemy)
{
    for (Card *card : randoms(cardsFiltered(ally, enemy, {[=](Card *card){ return card != this; }}, Ally), 5))
        boost(card, 3, ally, enemy);
}

SeltkirkOfGulet::SeltkirkOfGulet()
{
    name = "Seltkirk of Gulet";
    url = "https://gwent.one/image/card/low/cid/png/201618.png";
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

void SeltkirkOfGulet::onEnter(Field &ally, Field &enemy)
{
    gainArmor(this, 3, ally, enemy);
    startChoiceToTargetCard(ally, enemy, this, {}, Enemy);
}

void SeltkirkOfGulet::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    duel(this, target, ally, enemy);
}

AdrenalineRush::AdrenalineRush()
{
    name = "Adrenaline Rush";
    text = "Toggle a unit's Resilience status.";
    url = "https://gwent.one/image/card/low/cid/png/113307.png";
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
    name = "Shupe's Day Off";
    text = "If your starting deck has no duplicates, Spawn a Shupe: Knight, Shupe: Hunter or Supe: Mage";
    url = "https://gwent.one/image/card/low/cid/png/201627.png";
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

    startChoiceToSelectOption(ally, this, {new ShupeKnight, new ShupeHunter, new ShupeMage});
}

void ShupesDayOff::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    acceptOptionAndDeleteOthers(this, target);
    spawn(target, ally, enemy);
}

ShupeHunter::ShupeHunter()
{
    name = "Shupe: Hunter";
    url = "https://gwent.one/image/card/low/cid/png/201731.png";
    power = powerBase = 8;
    isDoomed = true;
    rarity = Gold;
    faction = Neutral;
    tags = { Ogroid };
}

bool ShupeHunter::isBronzeOrSilverUnit(Card *card)
{
    return !card->isSpecial && ((card->rarity == Bronze) || (card->rarity == Silver));
}

void ShupeHunter::onEnter(Field &ally, Field &)
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
            startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilverUnit}, AllyDeck);
            return;
        }

        if (dynamic_cast<ShupeHunter::Shot *>(_choosen)) {
            startChoiceToTargetCard(ally, enemy, this);
            return;
        }

        if (dynamic_cast<ShupeHunter::Replay *>(_choosen)) {
            startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilverUnit}, Ally);
            return;
        }

        if (dynamic_cast<ShupeHunter::Clear *>(_choosen)) {
            for (Card *card : cardsFiltered(ally, enemy, {}, Ally))
                boost(card, 1, ally, enemy);
            clearAllHazards(ally);
            delete _choosen;
            _choosen = nullptr;
            return;
        }

        if (dynamic_cast<ShupeHunter::Barrage *>(_choosen)) {
            for (int n = 0; n < 8; ++n)
                if (Card *card = random(cardsFiltered(ally, enemy, {}, Enemy))) {
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
        returnToHand(target, ally, enemy);
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
    name = "Shupe: Mage";
    url = "https://gwent.one/image/card/low/cid/png/201725.png";
    power = powerBase = 4;
    isDoomed = true;
    rarity = Gold;
    faction = Neutral;
    tags = { Ogroid };
}

bool ShupeMage::isBronzeOrSilverSpecial(Card *card)
{
    return card->isSpecial && ((card->rarity == Bronze) || (card->rarity == Silver));
}

void ShupeMage::onEnter(Field &ally, Field &)
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
            if (Card *card = random(cardsFiltered(ally, enemy, {}, Enemy)))
                charm(card, ally, enemy);
            delete _choosen;
            _choosen = nullptr;
            return;
        }

        if (dynamic_cast<ShupeMage::Hazards *>(_choosen)) {
            applyRowEffect(enemy, ally, Meele, randomHazardEffect());
            applyRowEffect(enemy, ally, Range, randomHazardEffect());
            applyRowEffect(enemy, ally, Seige, randomHazardEffect());
            delete _choosen;
            _choosen = nullptr;
            return;
        }

        if (dynamic_cast<ShupeMage::Meteor *>(_choosen)) {
            startChoiceToTargetCard(ally, enemy, this, {}, Enemy);
            return;
        }

        if (dynamic_cast<ShupeMage::Play *>(_choosen)) {
            startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilverSpecial}, AllyDeckShuffled);
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
    name = "Mandrake";
    text = "Choose One: Heal a unit and Strengthen it by 6; or Reset a unit and Weaken it by 6.";
    url = "https://gwent.one/image/card/low/cid/png/200223.png";
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
    name = "Bone Talisman";
    text = "Choose One: Resurrect a Bronze Beast or Cultist; or Heal an ally and Strengthen it by 3.";
    url = "https://gwent.one/image/card/low/cid/png/201598.png";
    isSpecial = true;
    rarity = Bronze;
    faction = Skellige;
    tags = { Item };
}

bool BoneTalisman::isBronzeBeastOrCultist(Card *card)
{
    return (card->rarity == Bronze) && (hasTag(card, Beast) || hasTag(card, Cultist));
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
            startChoiceToTargetCard(ally, enemy, this, {isBronzeBeastOrCultist}, AllyDiscard);
            return;
        }
        if (dynamic_cast<BoneTalisman::Buff *>(target)) {
            startChoiceToTargetCard(ally, enemy, this, {}, Ally);
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
    name = "Shupe: Knight";
    url = "https://gwent.one/image/card/low/cid/png/201737.png";
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

void ShupeKnight::onEnter(Field &ally, Field &)
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
            for (Card *card : cardsFiltered(ally, enemy, {isFourOrLessPower}, Enemy))
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
            startChoiceToTargetCard(ally, enemy, this, {}, Enemy);
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
    name = "Decoy";
    text = "Replay a Bronze or Silver ally and boost it by 3.";
    url = "https://gwent.one/image/card/low/cid/png/113201.png";
    isSpecial = true;
    rarity = Silver;
    faction = Neutral;
    tags = { Tactics };
}

bool Decoy::isBronzeOrSilver(Card *card)
{
    return (card->rarity == Bronze) || (card->rarity == Silver);
}

void Decoy::onPlaySpecial(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, { isBronzeOrSilver }, Ally);
}

void Decoy::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    returnToHand(target, ally, enemy);
    boost(target, 3, ally, enemy);
    playCard(target, ally, enemy);
}

FirstLight::FirstLight()
{
    name = "First Light";
    text = "Choose One: Boost all damaged allies under Hazards by 2 and clear all Hazards from your side; or Play a random Bronze unit from your deck.";
    url = "https://gwent.one/image/card/low/cid/png/113303.png";
    isSpecial = true;
    rarity = Bronze;
    faction = Neutral;
    tags = { Tactics };
}

bool FirstLight::isBronzeUnit(Card *card)
{
    return !card->isSpecial && (card->rarity == Bronze);
}

void FirstLight::onPlaySpecial(Field &ally, Field &enemy)
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
         if (Card *card = random(cardsFiltered(ally, enemy, { isBronzeUnit }, AllyDeck)))
             playCard(card, ally, enemy);
         delete target;
         return;
     }

     assert(false);
}

Epidemic::Epidemic()
{
    name = "Epidemic";
    text = "Destroy all the Lowest units.";
    url = "https://gwent.one/image/card/low/cid/png/113308.png";
    isSpecial = true;
    rarity = Bronze;
    faction = Neutral;
    tags = { Organic, Spell };
}

void Epidemic::onPlaySpecial(Field &ally, Field &enemy)
{
    for (Card *card : lowests(cardsFiltered(ally, enemy, {}, Any)))
        putOnDiscard(card, ally, enemy);
}

Moonlight::Moonlight()
{
    name = "Moonlight";
    text = "Choose One: Apply a Full Moon Boon; or Apply a Blood Moon Hazard.";
    url = "https://gwent.one/image/card/low/cid/png/200067.png";
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
        _isFullMoon = true;
        startChoiceToSelectAllyRow(ally, this);

    } else if (dynamic_cast<Moonlight::BloodMoon *>(target)) {
        _isFullMoon = false;
        startChoiceToSelectEnemyRow(ally, this);

    } else
        assert(false);

    delete target;
}

RowEffect Moonlight::rowEffect() const
{
    return _isFullMoon ? FullMoonEffect : BloodMoonEffect;
}

CiriNova::CiriNova()
{
    name = "Ciri: Nova";
    text = "If you have exactly 2 copies of each Bronze card in your starting deck, set base power to 22.";
    url = "https://gwent.one/image/card/low/cid/png/201626.png";
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

void CiriNova::onEnter(Field &ally, Field &enemy)
{
    if (!hasExactTwoDuplicatesOfBronze(ally.deckStarting))
        return;

    strengthen(this, 22 - powerBase, ally, enemy);
}

HaraldTheCripple::HaraldTheCripple()
{
    name = "Harald the Cripple";
    text = "Deal 1 damage to a random enemy on the opposite row. Repeat 9 times.";
    url = "https://gwent.one/image/card/low/cid/png/200161.png";
    sounds = {
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.196.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.197.mp3",
        "https://gwent.one/audio/card/ob/en/SAY.Battlecries.198.mp3",
    };
    power = powerBase = 6;
    rarity = Gold;
    faction = Neutral;
    tags = { ClanAnCraite, Leader };
}

void HaraldTheCripple::onEnter(Field &ally, Field &enemy)
{
    Row row;
    Pos pos;
    if (!rowAndPos(this, ally, row, pos))
        return;
    for (int n = 0; n < 9; ++n)
        if (Card *card = random(enemy.row(row))) {
//            ally.snapshots.push_back(new Animation("", Animation::LineDamage, this, card));
            damage(card, 1, ally, enemy);
        }
}

Emissary::Emissary()
{
    name = "Emissary";
    text = "Look at 2 random Bronze units from your deck, then play 1.";
    url = "https://gwent.one/image/card/low/cid/png/162314.png";
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

bool Emissary::isBronzeUnit(Card *card)
{
    return (card->rarity == Bronze) && !card->isSpecial;
}

void Emissary::onEnter(Field &ally, Field &enemy)
{
    ally.cardStack.push_back(Choice(Target, this, randoms(cardsFiltered(ally, enemy, {isBronzeUnit}, AllyDeckShuffled), 2), 1, true));
}

void Emissary::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    playCard(target, ally, enemy);
}

CeallachDyffryn::CeallachDyffryn()
{
    name = "Ceallach Dyffryn";
    text = "Spawn an Ambassador, Assassin or Emissary.";
    url = "https://gwent.one/image/card/low/cid/png/162213.png";
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

void CeallachDyffryn::onEnter(Field &ally, Field &)
{
    startChoiceToSelectOption(ally, this, {new Ambassador, new Assassin, new Emissary});
}

void CeallachDyffryn::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    acceptOptionAndDeleteOthers(this, target);
    spawn(target, ally, enemy);
}

Restore::Restore()
{
    name = "Moonlight";
    text = "Return a Bronze or Silver Skellige unit from your graveyard to your hand, add the Doomed category to it, and set its base power to 8. Then play a card.";
    url = "https://gwent.one/image/card/low/cid/png/153201.png";
    isSpecial = true;
    rarity = Silver;
    faction = Monster;
    tags = { Spell };
}

bool Restore::isBronzeOrSilverSkelligeUnit(Card *card)
{
    return (card->rarity == Bronze || card->rarity == Silver) && (card->faction == Skellige);
}

void Restore::onPlaySpecial(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isBronzeOrSilverSkelligeUnit}, AllyDiscard);
}

void Restore::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    returnToHand(target, ally, enemy);
    target->isDoomed = true;
    target->powerBase = target->power = 8;
    playCard(target, ally, enemy);
}

DrummondQueensguard::DrummondQueensguard()
{
    name = "Drummond Queensguard";
    text = "Resurrect all copies of this unit on this row.";
    url = "https://gwent.one/image/card/low/cid/png/152307.png";
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

bool DrummondQueensguard::isCopy(Card *card)
{
    return card->name == "Drummond Queensguard";
}

void DrummondQueensguard::onEnter(Field &ally, Field &enemy)
{
    Row row;
    Pos pos;
    if (!rowAndPos(this, ally, row, pos))
        return;
    for (Card *card : cardsFiltered(ally, enemy, {isCopy}, AllyDiscard)) {
        if (isRowFull(ally.row(row)))
            break;
        putOnField(card, row, ++pos, ally, enemy);
    }
}

BranTuirseach::BranTuirseach()
{
    name = "Bran Tuirseach";
    text = "Discard up to 3 cards from your deck and Strengthen them by 1.";
    url = "https://gwent.one/image/card/low/cid/png/200159.png";
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

void BranTuirseach::onEnter(Field &ally, Field &enemy)
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
    name = "Drummond Warmonger";
    text = "Discard a Bronze card from your deck.";
    url = "https://gwent.one/image/card/low/cid/png/200036.png";
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

bool DrummondWarmonger::isBronze(Card *card)
{
    return card->rarity == Bronze;
}

void DrummondWarmonger::onEnter(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isBronze}, AllyDeckShuffled);
}

void DrummondWarmonger::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    putOnDiscard(target, ally, enemy);
}

DimunPirate::DimunPirate()
{
    name = "Dimun Pirate";
    text = "Discard all copies of this unit from your deck.";
    url = "https://gwent.one/image/card/low/cid/png/152305.png";
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

bool DimunPirate::isCopy(Card *card)
{
    return card->name == "Dimun Pirate";
}

void DimunPirate::onEnter(Field &ally, Field &enemy)
{
    for (Card *card : cardsFiltered(ally, enemy, {isCopy}, AllyDeck))
        putOnDiscard(card, ally, enemy);
}

AnCraiteRaider::AnCraiteRaider()
{
    name = "An Craite Raider";
    text = "Whenever you Discard this unit, Resurrect it on a random row.";
    url = "https://gwent.one/image/card/low/cid/png/152316.png";
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
    if (randomRowAndPos(ally, row, pos)) {
        putOnField(this, row, pos, ally, enemy);
    }
}

MadmanLugos::MadmanLugos()
{
    name = "Madman Lugos";
    text = "Discard a Bronze unit from your deck, then deal damage equal to its base power to an enemy.";
    url = "https://gwent.one/image/card/low/cid/png/152106.png";
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

bool MadmanLugos::isBronzeUnit(Card *card)
{
    return (card->rarity == Bronze) && !card->isSpecial;
}

void MadmanLugos::onEnter(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {isBronzeUnit}, AllyDeckShuffled);
}

void MadmanLugos::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    if (_discarded == nullptr) {
        _discarded = target;

        putOnDiscard(target, ally, enemy);
        startChoiceToTargetCard(ally, enemy, this, {}, Enemy);
        return;
    }

    damage(target, _discarded->powerBase, ally, enemy);
}

Ermion::Ermion()
{
    name = "Ermion";
    text = "Draw 2 cards, then Discard 2 cards.";
    url = "https://gwent.one/image/card/low/cid/png/152103.png";
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

void Ermion::onEnter(Field &ally, Field &enemy)
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
    name = "Cerys: Fearless";
    text = "Resurrect the next unit you Discard.";
    url = "https://gwent.one/image/card/low/cid/png/201778.png";
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

void CerysFearless::onEnter(Field &, Field &)
{
    timer = 1;
}

void CerysFearless::onOtherAllyDiscarded(Card *other, Field &ally, Field &enemy)
{
    if (timer == 0 || other->isSpecial)
        return;

    timer--;
    playCard(other, ally, enemy);
}

CerysAnCraite::CerysAnCraite()
{
    name = "Cerys: Fearless";
    text = "When 4 units are Resurrected while this unit is in the graveyard, Resurrect it on a random row.";
    url = "https://gwent.one/image/card/low/cid/png/200177.png";
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

void CerysAnCraite::onOtherAllyResurrectededWhileOnDiscard(Card *, Field &ally, Field &enemy)
{
    if (timer > 0)
        timer--;

    Row row;
    Pos pos;
    if (timer == 0 && randomRowAndPos(ally, row, pos))
        putOnField(this, row, pos, ally, enemy);
}
