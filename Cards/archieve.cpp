#include "archieve.h"

AddaStriga::AddaStriga()
{
    name = "Adda: Striga";
    url = "https://gwent.one/image/card/low/cid/png/200073.png";
    power = powerBase = 6;
    rarity = Silver;
    faction = Monster;
    tags = { Cursed, Relict };
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
    url = "https://gwent.one/image/card/low/cid/png/132213.png";
    power = powerBase = 6;
    rarity = Bronze;
    faction = Monster;
    tags = { Construct };
}

void Dao::onDie(Field &, Field &)
{
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
    tags = { Soldier, Temeria };
    isDoomed = true;
}

PoorFingInfantry::RightFlankInfantry::RightFlankInfantry()
{
    name = "Right Flank Infantry";
    url = "https://gwent.one/image/card/low/cid/png/200303.png";
    power = powerBase = 2;
    rarity = Bronze;
    faction = NothernRealms;
    tags = { Soldier, Temeria };
    isDoomed = true;
}

PoorFingInfantry::PoorFingInfantry()
{
    name = "Poor F'ing Infantry";
    url = "https://gwent.one/image/card/low/cid/png/200234.png";
    power = powerBase = 6;
    rarity = Bronze;
    faction = NothernRealms;
    tags = { Soldier, Temeria };
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
    tags = { Nilfgaard };
}

void DeithwenArbalest::onEnter(Field &ally, Field &enemy)
{
    startChoiceToTargetCard(ally, enemy, this, {}, Enemy);
}

void DeithwenArbalest::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    damage(target, target->isSpy ? 6 : 3, ally, enemy);
}

TemerianDrummer::TemerianDrummer()
{
    name = "Temerian Drummer";
    url = "https://gwent.one/image/card/low/cid/png/200299.png";
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
    playACard(target, ally, enemy);
}

SileDeTansarville::SileDeTansarville()
{
    name = "S'ile de Tansarville";
    url = "https://gwent.one/image/card/low/cid/png/122205.png";
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
    playACard(target, ally, enemy);
    drawACard(ally, enemy);
}

RedanianKnightElect::RedanianKnightElect()
{
    name = "Redanian Knight Elect";
    url = "https://gwent.one/image/card/low/cid/png/123301.png";
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
    if (Card *left = cardNextTo(this, ally, enemy, -1))
        boost(left, 1, ally, enemy);
    if (Card *right = cardNextTo(this, ally, enemy, 1))
        boost(right, 1, ally, enemy);
}

AnCraiteMarauder::AnCraiteMarauder()
{
    name = "An Craite Marauder";
    url = "https://gwent.one/image/card/low/cid/png/201578.png";
    power = powerBase = 7;
    rarity = Bronze;
    faction = Skellige;
    tags = { Soldier, ClanAnCraite };
}

AnCraiteGreatsword::AnCraiteGreatsword()
{
    name = "An Craite Greatsword";
    url = "https://gwent.one/image/card/low/cid/png/200040.png";
    power = powerBase = 8;
    rarity = Bronze;
    faction = Skellige;
    tags = { Soldier, ClanAnCraite };
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

    boost(this, powerBase - power, ally, enemy);
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
    url = "https://gwent.one/image/card/low/cid/png/200144.png";
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
    damage(target, armorTarget, ally, enemy);
    boost(this, armorTarget, ally, enemy);
}

AlzursThunder::AlzursThunder()
{
    name = "Alzur's Thunder";
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
    damage(target, 9, ally, enemy);
}

Swallow::Swallow()
{
    name = "Swallow";
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
    if (Card *left = cardNextTo(target, ally, enemy, -1)) {
        boost(left, 3, ally, enemy);
        gainArmor(left, 2, ally, enemy);
    }
    if (Card *right = cardNextTo(target, ally, enemy, 1)) {
        boost(right, 3, ally, enemy);
        gainArmor(right, 2, ally, enemy);
    }
}

ArachasVenom::ArachasVenom()
{
    name = "Arachas Venom";
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
    damage(target, 4, ally, enemy);
    if (Card *left = cardNextTo(target, ally, enemy, -1))
        damage(left, 4, ally, enemy);
    if (Card *right = cardNextTo(target, ally, enemy, 1))
        damage(right, 4, ally, enemy);
}

KeiraMetz::KeiraMetz()
{
    name = "Keira Metz";
    url = "https://gwent.one/image/card/low/cid/png/122108.png";
    power = powerBase = 6;
    rarity = Gold;
    faction = NothernRealms;
    tags = { Mage, Temeria };
}

void KeiraMetz::onEnter(Field &ally, Field &)
{
    _c1 = new AlzursThunder;
    _c2 = new Thunderbolt;
    _c3 = new ArachasVenom;
    ally.cardStack.push_back({Target, this, {_c1, _c2, _c3}});
}

void KeiraMetz::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    if (_c1 != target)
        delete _c1;
    if (_c2 != target)
        delete _c2;
    if (_c3 != target)
        delete _c3;
    spawn(target, ally, enemy);
}

DolBlathannaArcher::DolBlathannaArcher()
{
    name = "Dol Blathanna Archer";
    url = "https://gwent.one/image/card/low/cid/png/142310.png";
    power = powerBase = 7;
    rarity = Bronze;
    faction = Scoiatael;
    tags = { Soldier, Elf };
}

void DolBlathannaArcher::onEnter(Field &ally, Field &enemy)
{
    _nShots = 0;
    startChoiceToTargetCard(ally, enemy, this);
    startChoiceToTargetCard(ally, enemy, this);
}

void DolBlathannaArcher::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    damage(target, ++_nShots == 1 ? 3 : 1, ally, enemy);
}

HalfElfHunter::HalfElfHunter()
{
    name = "Half-Elf Hunter";
    url = "https://gwent.one/image/card/low/cid/png/201636.png";
    power = powerBase = 6;
    rarity = Bronze;
    faction = Scoiatael;
    tags = { Soldier, Elf };
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
    isSpy = true;
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
    isSpy = true;
    rarity = Bronze;
    faction = Nilfgaard;
    tags = {};
}

void Assassin::onEnter(Field &ally, Field &enemy)
{
    if (Card *left = cardNextTo(this, ally, enemy, -1))
        damage(left, 10, ally, enemy);
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
    damage(target, 13, ally, enemy);
}

GloriousHunt::GloriousHunt()
{
    name = "Glorious Hunt";
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
    power = powerBase = 12;
    rarity = Silver;
    faction = NothernRealms;
    tags = { Soldier, Temeria };
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
    url = "https://gwent.one/image/card/low/cid/png/113208.png";
    power = powerBase = 4;
    rarity = Silver;
    faction = Neutral;
    tags = { Mage };
}

void Vaedermakar::onEnter(Field &ally, Field &)
{
    _c1 = new BitingFrost;
    _c2 = new ImpenetrableFog;
    _c3 = new AlzursThunder;
    ally.cardStack.push_back({Target, this, {_c1, _c2, _c3}});
}

void Vaedermakar::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    if (_c1 != target)
        delete _c1;
    if (_c2 != target)
        delete _c2;
    if (_c3 != target)
        delete _c3;
    spawn(target, ally, enemy);
}

Frightener::Frightener()
{
    name = "Frightener";
    url = "https://gwent.one/image/card/low/cid/png/132204.png";
    power = powerBase = 13;
    isSpy = true;
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
    startChoiceToTargetCard(ally, enemy, this, {}, Any);
}

void Cleaver::onTargetChoosen(Card *target, Field &ally, Field &enemy)
{
    damage(target, int(ally.hand.size()), ally, enemy);
}

Scorch::Scorch()
{
    name = "Scorch";
    url = "https://gwent.one/image/card/low/cid/png/113309.png";
    isSpecial = true;
    rarity = Silver;
    faction = Neutral;
    tags = { Spell };
}

void Scorch::onPlaySpecial(Field &ally, Field &enemy)
{
    for (Card *card : highests(_united(std::vector<std::vector<Card *>>{ally.rowMeele, ally.rowRange, ally.rowSeige, enemy.rowMeele, enemy.rowRange, enemy.rowSeige})))
        destroy(card, ally, enemy);
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
    playACard(target, ally, enemy);
}

JohnNatalis::JohnNatalis()
{
    name = "John Natalis";
    url = "https://gwent.one/image/card/low/cid/png/122103.png";
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
    playACard(target, ally, enemy);
}

Eleyas::Eleyas()
{
    name = "Ele'yas";
    url = "https://gwent.one/image/card/low/cid/png/142214.png";
    power = powerBase = 10;
    rarity = Silver;
    faction = Scoiatael;
    tags = { Soldier, Elf };
}

void Eleyas::onDraw(Field &ally, Field &enemy)
{
    boost(this, 2, ally, enemy);
}

void Eleyas::onSwap(Field &ally, Field &enemy)
{
    boost(this, 2, ally, enemy);
}
