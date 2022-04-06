#ifndef CARDS_H
#define CARDS_H

#include "card.h"

struct AddaStriga : Card
{
    inline AddaStriga()
    {
        power = powerBase = 6;
        rarity = Silver;
        faction = Monster;
        tags = { Cursed, Relict };
    }
    inline static bool isNonMonster(Card *card)
    {
        return card->faction != Monster;
    }
    inline void onEnter(const Row, const Pos, Field &, Field &enemy) override
    {
        startChoiceToTargetCard(enemy, this, {isNonMonster});
    }
    inline void onTargetChoosen(Card *, Field &, Field &) override
    {
        // deal 8 dmg
    }
};

struct DaoLesser : Card
{
    inline DaoLesser()
    {
        power = powerBase = 4;
        rarity = Bronze;
        faction = Monster;
        tags = { Construct };
        isDoomed = true;
    }
};

struct Dao : Card
{
    inline Dao()
    {
        power = powerBase = 6;
        rarity = Bronze;
        faction = Monster;
        tags = { Construct };
    }
    inline void onDie(const Row, const Pos, Field &, Field &) override
    {
    }
};

struct DeithwenArbalest : Card
{
    inline DeithwenArbalest()
    {
        power = powerBase = 7;
        rarity = Bronze;
        faction = Nilfgaard;
        tags = { Nilfgaard };
    }
    inline void onEnter(const Row, const Pos, Field &, Field &) override
    {
    }
};

struct TemerianDrummer : Card
{
    inline TemerianDrummer()
    {
        power = powerBase = 5;
        rarity = Bronze;
        faction = NothernRealms;
        tags = { Temerian, Support };
    }
    inline void onEnter(const Row, const Pos, Field &ally, Field &) override
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
        power = powerBase = 5;
        rarity = Gold;
        faction = Neutral;
        tags = {  };
    }
    inline void onEnter(const Row, const Pos, Field &ally, Field &) override
    {
        drawACard(ally);
        startChoiceToPlayCard(ally);
    }
};

struct SileDeTansarville : Card
{
    inline SileDeTansarville()
    {
        power = powerBase = 4;
        rarity = Silver;
        faction = NothernRealms;
        tags = { Mage };
    }
    inline static bool isBronzeOrSilverSpecialCard(Card *card)
    {
        return card->isSpecial && (card->rarity == Bronze || card->rarity == Silver);
    }
    inline void onEnter(const Row, const Pos, Field &ally, Field &) override
    {
        startChoiceToPlayCard(ally, {isBronzeOrSilverSpecialCard});
    }
};

#endif // CARDS_H
