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
    inline void onEnter(const Row, const Pos, Field &, Field &) override
    {

    }
};

struct DaoLesser : Card
{
    inline DaoLesser()
    {
        power = 4;
        rarity = Bronze;
        faction = Monster;
        tags = { Construct, Doomed };
    }
};

struct Dao : Card
{
    inline Dao()
    {
        power = 6;
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
        power = 7;
        rarity = Bronze;
        faction = Nilfgaard;
        tags = { Nilfgaard };
    }
    inline void onEnter(const Row, const Pos, Field &, Field &) override
    {
    }
};

struct DandelionPoet : Card
{
    inline DandelionPoet()
    {
        power = 5;
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

#endif // CARDS_H
