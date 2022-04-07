#ifndef CARDS_H
#define CARDS_H

#include "card.h"

struct AddaStriga : Card
{
    inline AddaStriga()
    {
        name = "Adda: Striga";
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
        power = powerBase = 6;
        rarity = Bronze;
        faction = Monster;
        tags = { Construct };
    }
    inline void onDie(const Row, const Pos, Field &, Field &) override
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
        if (isOkRowAndPos(row, pos, ally))
            putOnField(new LeftFlankInfantry, row, pos, ally, enemy);
        if (!rowAndPos(this, ally, row, pos))
            return;
        if (isOkRowAndPos(row, pos + 1, ally))
            putOnField(new RightFlankInfantry, row, pos + 1, ally, enemy);
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
        power = powerBase = 5;
        rarity = Gold;
        faction = Neutral;
        tags = {  };
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

#endif // CARDS_H
