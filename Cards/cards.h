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
    inline void onEnter(Field &, Field &enemy) override
    {
        startChoiceToTargetCard(enemy, this, {isNonMonster});
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
        power = powerBase = 7;
        rarity = Bronze;
        faction = Nilfgaard;
        tags = { Nilfgaard };
    }
    inline void onEnter(Field &, Field &) override
    {
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
    inline void onEnter(Field &ally, Field &) override
    {
        startChoiceToTargetCard(ally, this);
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
    inline void onEnter(Field &ally, Field &) override
    {
        drawACard(ally);
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
        if (!this->armor)
            return;
        Row row;
        Pos pos;
        if (!rowAndPos(this, ally, row, pos))
            return;

        if (Card *left = cardAtRowAndPos(row, pos - 1, ally))
            boost(left, 1, ally, enemy);
        if (Card *right = cardAtRowAndPos(row, pos + 1, ally))
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

struct AlzursThunder : Card
{
    inline AlzursThunder()
    {
        name = "Alzur's Thunder";
        rarity = Bronze;
        faction = Neutral;
        tags = { Spell };
        isSpecial = true;
        url = "https://gwent.one/image/card/low/cid/png/113301.png";
    }
    inline void onPlaySpecial(Field &ally, Field &) override
    {
        // TODO: change to any taget
        startChoiceToTargetCard(ally, this);
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
        rarity = Bronze;
        faction = Neutral;
        tags = { Alchemy, Item };
        isSpecial = true;
        url = "https://gwent.one/image/card/low/cid/png/113310.png";
    }
    inline void onPlaySpecial(Field &ally, Field &) override
    {
        startChoiceToTargetCard(ally, this);
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
        rarity = Bronze;
        faction = Neutral;
        tags = { Alchemy, Item };
        isSpecial = true;
        url = "https://gwent.one/image/card/low/cid/png/113311.png";
    }
    inline void onPlaySpecial(Field &ally, Field &) override
    {
        // TODO: change to any target
        startChoiceToTargetCard(ally, this);
    }
    inline void onTargetChoosen(Card *target, Field &ally, Field &enemy) override
    {
        Row row;
        Pos pos;
        if (!rowAndPos(target, ally, row, pos))
            return;
        boost(target, 3, ally, enemy);
        gainArmor(target, 2, ally, enemy);
        if (Card *left = cardAtRowAndPos(row, pos - 1, ally)) {
            boost(left, 3, ally, enemy);
            gainArmor(left, 2, ally, enemy);
        }
        if (Card *right = cardAtRowAndPos(row, pos + 1, ally)) {
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
        rarity = Bronze;
        faction = Neutral;
        tags = { Organic };
        isSpecial = true;
        url = "https://gwent.one/image/card/low/cid/png/200023.png";
    }
    inline void onPlaySpecial(Field &ally, Field &) override
    {
        // TODO: change to any target
        startChoiceToTargetCard(ally, this);
    }
    inline void onTargetChoosen(Card *target, Field &ally, Field &enemy) override
    {
        Row row;
        Pos pos;
        if (!rowAndPos(target, ally, row, pos))
            return;
        damage(target, 4, ally, enemy);
        if (Card *left = cardAtRowAndPos(row, pos - 1, ally))
            damage(left, 4, ally, enemy);
        if (Card *right = cardAtRowAndPos(row, pos + 1, ally))
            damage(right, 4, ally, enemy);
    }
};

struct KeiraMetz : Card
{
    inline KeiraMetz()
    {
        name = "Keira Metz";
        power = powerBase = 6;
        rarity = Gold;
        faction = NothernRealms;
        tags = { Mage, Temeria };
        url = "https://gwent.one/image/card/low/cid/png/122108.png";
    }
    Card *c1 = nullptr;
    Card *c2 = nullptr;
    Card *c3 = nullptr;
    inline void onEnter(Field &ally, Field &/*enemy*/) override
    {
        c1 = new AlzursThunder;
        c2 = new Thunderbolt;
        c3 = new ArachasVenom;
        ally.cardStack.push_back({Target, this, {c1, c2, c3}});
    }
    inline void onTargetChoosen(Card *target, Field &ally, Field &enemy) override
    {
        if (c1 != target)
            delete c1;
        if (c2 != target)
            delete c2;
        if (c3 != target)
            delete c3;
        spawn(target, ally, enemy);
    }
};

#endif // CARDS_H
