#ifndef CARDS_H
#define CARDS_H

#include "card.h"

struct AddaStriga : Card
{
    inline AddaStriga()
    {
        name = "Adda: Striga";
        url = "https://gwent.one/image/card/low/cid/png/200073.png";
        power = powerBase = 6;
        rarity = Silver;
        faction = Monster;
        tags = { Cursed, Relict };
    }
    inline static bool isNonMonster(Card *card)
    {
        return card->faction != Monster;
    }
    inline void onEnter(Field &ally, Field &enemy) override
    {
        startChoiceToTargetCard(ally, enemy, this, {isNonMonster});
    }
    inline void onTargetChoosen(Card *, Field &, Field &) override
    {
        // deal 8 dmg
    }
};


struct Dao : Card
{
    struct DaoLesser : Card
    {
        inline DaoLesser()
        {
            name = "D'ao Lesser";
            url = "https://gwent.one/image/card/low/cid/png/132405.png";
            power = powerBase = 4;
            rarity = Bronze;
            faction = Monster;
            tags = { Construct };
            isDoomed = true;
        }
    };

    inline Dao()
    {
        name = "D'ao";
        url = "https://gwent.one/image/card/low/cid/png/132213.png";
        power = powerBase = 6;
        rarity = Bronze;
        faction = Monster;
        tags = { Construct };
    }
    inline void onDie(Field &, Field &) override
    {
    }
};

struct PoorFingInfantry : Card
{
    struct LeftFlankInfantry : Card
    {
        inline LeftFlankInfantry()
        {
            name = "Left Flank Infantry";
            url = "https://gwent.one/image/card/low/cid/png/200302.png";
            power = powerBase = 2;
            rarity = Bronze;
            faction = NothernRealms;
            tags = { Soldier, Temeria };
            isDoomed = true;
        }

    };
    struct RightFlankInfantry : Card
    {
        inline RightFlankInfantry()
        {
            name = "Right Flank Infantry";
            url = "https://gwent.one/image/card/low/cid/png/200303.png";
            power = powerBase = 2;
            rarity = Bronze;
            faction = NothernRealms;
            tags = { Soldier, Temeria };
            isDoomed = true;
        }
    };
    inline PoorFingInfantry()
    {
        name = "Poor F'ing Infantry";
        url = "https://gwent.one/image/card/low/cid/png/200234.png";
        power = powerBase = 6;
        rarity = Bronze;
        faction = NothernRealms;
        tags = { Soldier, Temeria };
    }
    inline void onEnter(Field &ally, Field &enemy) override
    {
        Row row;
        Pos pos;
        if (!rowAndPos(this, ally, row, pos))
            return;
        spawn(new LeftFlankInfantry, row, pos, ally, enemy);
        spawn(new RightFlankInfantry, row, pos + 2, ally, enemy);
    }
};

struct DeithwenArbalest : Card
{
    inline DeithwenArbalest()
    {
        name = "Deithwen Arbalest";
        url = "https://gwent.one/image/card/low/cid/png/162305.png";
        power = powerBase = 7;
        rarity = Bronze;
        faction = Nilfgaard;
        tags = { Nilfgaard };
    }
    inline void onEnter(Field &ally, Field &enemy) override
    {
        startChoiceToTargetCard(ally, enemy, this, {}, Enemy);
    }
    inline void onTargetChoosen(Card *target, Field &ally, Field &enemy) override
    {
        damage(target, target->isSpy ? 6 : 3, ally, enemy);
    }
};

struct TemerianDrummer : Card
{
    inline TemerianDrummer()
    {
        name = "Temerian Drummer";
        url = "https://gwent.one/image/card/low/cid/png/200299.png";
        power = powerBase = 5;
        rarity = Bronze;
        faction = NothernRealms;
        tags = { Temeria, Support };
    }
    inline void onEnter(Field &ally, Field &enemy) override
    {
        startChoiceToTargetCard(ally, enemy, this, {}, Ally);
    }
    inline void onTargetChoosen(Card *target, Field &ally, Field &enemy) override
    {
        boost(target, 6, ally, enemy);
    }
};

struct DandelionPoet : Card
{
    inline DandelionPoet()
    {
        name = "Dandelion: Poet";
        url = "https://gwent.one/image/card/low/cid/png/201776.png";
        power = powerBase = 5;
        rarity = Gold;
        faction = Neutral;
        tags = { Support };
    }
    inline void onEnter(Field &ally, Field &enemy) override
    {
        drawACard(ally, enemy);
        startChoiceToPlayCard(ally, this);
    }
};

struct SileDeTansarville : Card
{
    inline SileDeTansarville()
    {
        name = "S'ile de Tansarville";
        url = "https://gwent.one/image/card/low/cid/png/122205.png";
        power = powerBase = 4;
        rarity = Silver;
        faction = NothernRealms;
        tags = { Mage };
    }
    inline static bool isBronzeOrSilverSpecialCard(Card *card)
    {
        return card->isSpecial && (card->rarity == Bronze || card->rarity == Silver);
    }
    inline void onEnter(Field &ally, Field &) override
    {
        startChoiceToPlayCard(ally, this, {isBronzeOrSilverSpecialCard});
    }
};

struct RedanianKnightElect : Card
{
    inline RedanianKnightElect()
    {
        name = "Redanian Knight Elect";
        url = "https://gwent.one/image/card/low/cid/png/123301.png";
        power = powerBase = 7;
        rarity = Bronze;
        faction = NothernRealms;
        tags = { Redania, Soldier };
    }
    inline void onEnter(Field &ally, Field &enemy) override
    {
        gainArmor(this, 2, ally, enemy);
    }
    inline void onTurnEnd(Field &ally, Field &enemy) override
    {
        if (armor == 0)
            return;
        if (Card *left = cardNextTo(this, ally, enemy, -1))
            boost(left, 1, ally, enemy);
        if (Card *right = cardNextTo(this, ally, enemy, 1))
            boost(right, 1, ally, enemy);
    }
};

struct KaedweniKnight : Card
{
    inline KaedweniKnight()
    {
        name = "Kaedweni Knight";
        url = "https://gwent.one/image/card/low/cid/png/201622.png";
        power = powerBase = 8;
        rarity = Bronze;
        faction = NothernRealms;
        tags = { Soldier, Kaedwen };
    }
    inline void onEnter(Field &ally, Field &enemy) override
    {
        gainArmor(this, 2, ally, enemy);
    }
    inline void onEnterFromDeck(Field &ally, Field &enemy) override
    {
        gainArmor(this, 2, ally, enemy);
        boost(this, 5, ally, enemy);
    }
};

struct AnCraiteMarauder : Card
{
    inline AnCraiteMarauder()
    {
        name = "An Craite Marauder";
        url = "https://gwent.one/image/card/low/cid/png/201578.png";
        power = powerBase = 7;
        rarity = Bronze;
        faction = Skellige;
        tags = { Soldier, ClanAnCraite };
    }
};

struct AnCraiteGreatsword : Card
{
    inline AnCraiteGreatsword()
    {
        name = "An Craite Greatsword";
        url = "https://gwent.one/image/card/low/cid/png/200040.png";
        power = powerBase = 8;
        rarity = Bronze;
        faction = Skellige;
        tags = { Soldier, ClanAnCraite };
    }
    inline void onEnter(Field &, Field &) override
    {
        timer = 2;
    }
    inline void onTurnStart(Field &ally, Field &enemy) override
    {
        if (--timer)
            return;

        timer = 2;

        if (power >= powerBase)
            return;

        boost(this, powerBase - power, ally, enemy);
        strengthen(this, 2, ally, enemy);
    }
};

struct DimunDracar : Card
{
    inline DimunDracar()
    {
        name = "Dimun Dracard";
        power = powerBase = 7;
        rarity = Bronze;
        faction = Skellige;
        tags = { ClanDimun, Machine };
    }
    inline void onTurnEnd(Field &ally, Field &enemy) override
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
};

struct Bear : Card
{
    inline Bear()
    {
        name = "Bear";
        url = "https://gwent.one/image/card/low/cid/png/152406.png";
        power = powerBase = 11;
        rarity = Bronze;
        faction = Neutral;
        tags = { Beast, Cursed };
    }
};

struct TuirseachBearmaster : Card
{
    inline TuirseachBearmaster()
    {
        name = "Tuirseach Bearmaster";
        url = "https://gwent.one/image/card/low/cid/png/200144.png";
        power = powerBase = 1;
        rarity = Bronze;
        faction = Skellige;
        tags = { ClanTuirseach, Soldier };
    }
    inline void onEnter(Field &ally, Field &enemy) override
    {
        spawn(new Bear, ally, enemy);
    }
};

struct RedanianElite : Card
{
    inline RedanianElite()
    {
        name = "Redanian Elite";
        url = "https://gwent.one/image/card/low/cid/png/122317.png";
        power = powerBase = 8;
        rarity = Bronze;
        faction = NothernRealms;
        tags = { Redania, Soldier };
    }
    inline void onEnter(Field &ally, Field &enemy) override
    {
        gainArmor(this, 4, ally, enemy);
    }
    inline void onArmorLost(Field &ally, Field &enemy) override
    {
        boost(this, 5, ally, enemy);
    }
};

struct RedanianKnight : Card
{
    inline RedanianKnight()
    {
        name = "Redanian Knight";
        url = "https://gwent.one/image/card/low/cid/png/122308.png";
        power = powerBase = 7;
        rarity = Bronze;
        faction = NothernRealms;
        tags = { Redania, Soldier };
    }
    inline void onEnter(Field &ally, Field &enemy) override
    {
        gainArmor(this, 2, ally, enemy);
    }
    inline void onTurnEnd(Field &ally, Field &enemy) override
    {
        if (armor != 0)
            return;
        boost(this, 2, ally, enemy);
        gainArmor(this, 2, ally, enemy);
    }
};

struct KaedweniCavalry : Card
{
    inline KaedweniCavalry()
    {
        name = "Kaedweni Cavalry";
        url = "https://gwent.one/image/card/low/cid/png/122314.png";
        power = powerBase = 8;
        rarity = Bronze;
        faction = NothernRealms;
        tags = { Kaedwen, Soldier };
    }
    inline static bool hasArmor(Card *card)
    {
        return card->armor > 0;
    }
    inline void onEnter(Field &ally, Field &enemy) override
    {
        startChoiceToTargetCard(ally, enemy, this, {hasArmor});
    }
    inline void onTargetChoosen(Card *target, Field &ally, Field &enemy) override
    {
        const int armorTarget = target->armor;
        damage(target, armorTarget, ally, enemy);
        boost(this, armorTarget, ally, enemy);
    }
};

struct AlzursThunder : Card
{
    inline AlzursThunder()
    {
        name = "Alzur's Thunder";
        url = "https://gwent.one/image/card/low/cid/png/113301.png";
        rarity = Bronze;
        faction = Neutral;
        tags = { Spell };
        isSpecial = true;
    }
    inline void onPlaySpecial(Field &ally, Field &enemy) override
    {
        startChoiceToTargetCard(ally, enemy, this);
    }
    inline void onTargetChoosen(Card *target, Field &ally, Field &enemy) override
    {
        damage(target, 9, ally, enemy);
    }
};

struct Swallow : Card
{
    inline Swallow()
    {
        name = "Swallow";
        url = "https://gwent.one/image/card/low/cid/png/113310.png";
        rarity = Bronze;
        faction = Neutral;
        tags = { Alchemy, Item };
        isSpecial = true;
    }
    inline void onPlaySpecial(Field &ally, Field &enemy) override
    {
        startChoiceToTargetCard(ally, enemy, this);
    }
    inline void onTargetChoosen(Card *target, Field &ally, Field &enemy) override
    {
        boost(target, 10, ally, enemy);
    }
};

struct Thunderbolt : Card
{
    inline Thunderbolt()
    {
        name = "Thunderbolt";
        url = "https://gwent.one/image/card/low/cid/png/113311.png";
        rarity = Bronze;
        faction = Neutral;
        tags = { Alchemy, Item };
        isSpecial = true;
    }
    inline void onPlaySpecial(Field &ally, Field &enemy) override
    {
        startChoiceToTargetCard(ally, enemy, this);
    }
    inline void onTargetChoosen(Card *target, Field &ally, Field &enemy) override
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
};

struct ArachasVenom : Card
{
    inline ArachasVenom()
    {
        name = "Arachas Venom";
        url = "https://gwent.one/image/card/low/cid/png/200023.png";
        rarity = Bronze ;
        faction = Neutral;
        tags = { Organic };
        isSpecial = true;
    }
    inline void onPlaySpecial(Field &ally, Field &enemy) override
    {
        startChoiceToTargetCard(ally, enemy, this);
    }
    inline void onTargetChoosen(Card *target, Field &ally, Field &enemy) override
    {
        damage(target, 4, ally, enemy);
        if (Card *left = cardNextTo(target, ally, enemy, -1))
            damage(left, 4, ally, enemy);
        if (Card *right = cardNextTo(target, ally, enemy, 1))
            damage(right, 4, ally, enemy);
    }
};

struct KeiraMetz : Card
{
    inline KeiraMetz()
    {
        name = "Keira Metz";
        url = "https://gwent.one/image/card/low/cid/png/122108.png";
        power = powerBase = 6;
        rarity = Gold;
        faction = NothernRealms;
        tags = { Mage, Temeria };
    }
    inline void onEnter(Field &ally, Field &/*enemy*/) override
    {
        _c1 = new AlzursThunder;
        _c2 = new Thunderbolt;
        _c3 = new ArachasVenom;
        ally.cardStack.push_back({Target, this, {_c1, _c2, _c3}});
    }
    inline void onTargetChoosen(Card *target, Field &ally, Field &enemy) override
    {
        if (_c1 != target)
            delete _c1;
        if (_c2 != target)
            delete _c2;
        if (_c3 != target)
            delete _c3;
        spawn(target, ally, enemy);
    }
private:
    Card *_c1 = nullptr;
    Card *_c2 = nullptr;
    Card *_c3 = nullptr;
};

struct DolBlathannaArcher : Card
{
    inline DolBlathannaArcher()
    {
        name = "Dol Blathanna Archer";
        url = "https://gwent.one/image/card/low/cid/png/142310.png";
        power = powerBase = 7;
        rarity = Bronze;
        faction = Scoiatael;
        tags = { Soldier, Elf };
    }
    inline void onEnter(Field &ally, Field &enemy) override
    {
        _nShots = 0;
        startChoiceToTargetCard(ally, enemy, this);
        startChoiceToTargetCard(ally, enemy, this);
    }
    inline void onTargetChoosen(Card *target, Field &ally, Field &enemy) override
    {
        damage(target, ++_nShots == 1 ? 3 : 1, ally, enemy);
    }
private:
    int _nShots = 0;
};

struct HalfElfHunter : Card
{
    inline HalfElfHunter()
    {
        name = "Half-Elf Hunter";
        url = "https://gwent.one/image/card/low/cid/png/201636.png";
        power = powerBase = 6;
        rarity = Bronze;
        faction = Scoiatael;
        tags = { Soldier, Elf };
    }
    inline void onEnter(Field &ally, Field &enemy) override
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
private:
    bool _maySpawnCopy = true;
};

struct Ambassador : Card
{
    inline Ambassador()
    {
        name = "Ambassador";
        url = "https://gwent.one/image/card/low/cid/png/162315.png";
        power = powerBase = 2;
        isSpy = true;
        rarity = Bronze;
        faction = Nilfgaard;
        tags = {};
    }
    inline void onEnter(Field &ally, Field &enemy) override
    {
        startChoiceToTargetCard(ally, enemy, this, {}, Ally);
    }
    inline void onTargetChoosen(Card *target, Field &ally, Field &enemy) override
    {
        boost(target, 12, ally, enemy);
    }
};

struct Assassin : Card
{
    inline Assassin()
    {
        name = "Assassin";
        url = "https://gwent.one/image/card/low/cid/png/200115.png";
        power = powerBase = 1;
        isSpy = true;
        rarity = Bronze;
        faction = Nilfgaard;
        tags = {};
    }
    inline void onEnter(Field &ally, Field &enemy) override
    {
        if (Card *left = cardNextTo(this, ally, enemy, -1))
            damage(left, 10, ally, enemy);
    }
};

struct Infiltrator : Card
{
    inline Infiltrator()
    {
        name = "Infiltrator";
        url = "https://gwent.one/image/card/low/cid/png/200118.png";
        power = powerBase = 10;
        rarity = Bronze;
        faction = Nilfgaard;
        tags = {};
    }
    inline void onEnter(Field &ally, Field &enemy) override
    {
        startChoiceToTargetCard(ally, enemy, this);
    }
    inline void onTargetChoosen(Card *target, Field &, Field &) override
    {
        target->isSpy = !target->isSpy;
    }
};

struct ImpenetrableFog : Card
{
    inline ImpenetrableFog()
    {
        name = "Impenetrable Fog";
        url = "https://gwent.one/image/card/low/cid/png/113305.png";
        isSpecial = true;
        rarity = Bronze;
        faction = Neutral;
        tags = { Hazard };
    }
    inline void onPlaySpecial(Field &ally, Field &) override
    {
        startChoiceToSelectEnemyRow(ally, this);
    }

    inline RowEffect rowEffect() const override
    {
        return ImpenetrableFogEffect;
    }
};

struct TorrentialRain : Card
{
    inline TorrentialRain()
    {
        name = "Torrential Rain";
        url = "https://gwent.one/image/card/low/cid/png/113312.png";
        isSpecial = true;
        rarity = Bronze;
        faction = Neutral;
        tags = { Hazard };
    }
    inline void onPlaySpecial(Field &ally, Field &) override
    {
        startChoiceToSelectEnemyRow(ally, this);
    }

    inline RowEffect rowEffect() const override
    {
        return TorrentialRainEffect;
    }
};

struct BitingFrost : Card
{
    inline BitingFrost()
    {
        name = "Biting Frost";
        url = "https://gwent.one/image/card/low/cid/png/113302.png";
        isSpecial = true;
        rarity = Bronze;
        faction = Neutral;
        tags = { Hazard };
    }
    inline void onPlaySpecial(Field &ally, Field &) override
    {
        startChoiceToSelectEnemyRow(ally, this);
    }

    inline RowEffect rowEffect() const override
    {
        return BitingFrostEffect;
    }
};

struct GoldenFroth : Card
{
    inline GoldenFroth()
    {
        name = "Golden Froth";
        url = "https://gwent.one/image/card/low/cid/png/201749.png";
        isSpecial = true;
        rarity = Bronze;
        faction = Neutral;
        tags = { Hazard };
    }
    inline void onPlaySpecial(Field &ally, Field &) override
    {
        startChoiceToSelectAllyRow(ally, this);
    }

    inline RowEffect rowEffect() const override
    {
        return GoldenFrothEffect;
    }
};

struct SkelligeStorm : Card
{
    inline SkelligeStorm()
    {
        name = "Skellige Storm";
        url = "https://gwent.one/image/card/low/cid/png/113203.png";
        isSpecial = true;
        rarity = Silver;
        faction = Neutral;
        tags = { Hazard };
    }
    inline void onPlaySpecial(Field &ally, Field &) override
    {
        startChoiceToSelectEnemyRow(ally, this);
    }

    inline RowEffect rowEffect() const override
    {
        return SkelligeStormEffect;
    }
};

struct ImperialManticore : Card
{
    inline ImperialManticore()
    {
        name = "Imperial Manticore";
        url = "https://gwent.one/image/card/low/cid/png/132209.png";
        power = powerBase = 13;
        rarity = Silver;
        faction = Monster;
        tags = { Beast };
    }
};

struct ManticoreVenom : Card
{
    inline ManticoreVenom()
    {
        name = "Manticore Venom";
        url = "https://gwent.one/image/card/low/cid/png/113306.png";
        isSpecial = true;
        rarity = Silver;
        faction = Neutral;
        tags = { Organic };
    }
    inline void onPlaySpecial(Field &ally, Field &enemy) override
    {
        startChoiceToTargetCard(ally, enemy, this);
    }
    inline void onTargetChoosen(Card *target, Field &ally, Field &enemy) override
    {
        damage(target, 13, ally, enemy);
    }
};

struct GloriousHunt : Card
{
    inline GloriousHunt()
    {
        name = "Glorious Hunt";
        url = "https://gwent.one/image/card/low/cid/png/201635.png";
        isSpecial = true;
        rarity = Silver;
        faction = Neutral;
        tags = { Tactics };
    }
    inline void onPlaySpecial(Field &ally, Field &enemy) override
    {
        if (powerField(ally) < powerField(enemy))
            return spawn(new ImperialManticore, ally, enemy);

        return spawn(new ManticoreVenom, ally, enemy);
    }
};

struct Vaedermakar : Card
{
    inline Vaedermakar()
    {
        name = "Vaedermakar";
        url = "https://gwent.one/image/card/low/cid/png/113208.png";
        power = powerBase = 4;
        rarity = Silver;
        faction = Neutral;
        tags = { Mage };
    }
    inline void onEnter(Field &ally, Field &/*enemy*/) override
    {
        _c1 = new BitingFrost;
        _c2 = new ImpenetrableFog;
        _c3 = new AlzursThunder;
        ally.cardStack.push_back({Target, this, {_c1, _c2, _c3}});
    }
    inline void onTargetChoosen(Card *target, Field &ally, Field &enemy) override
    {
        if (_c1 != target)
            delete _c1;
        if (_c2 != target)
            delete _c2;
        if (_c3 != target)
            delete _c3;
        spawn(target, ally, enemy);
    }
private:
    Card *_c1 = nullptr;
    Card *_c2 = nullptr;
    Card *_c3 = nullptr;
};

#endif // CARDS_H
