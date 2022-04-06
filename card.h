#ifndef CARD_H
#define CARD_H

#include <vector>
#include <string>

enum Row
{
    Meele,
    Range,
    Seige
};

using Pos = int;

enum Rarity
{
    Bronze,
    Silver,
    Gold
};


enum Tag
{
    Special,

    Beast,
    Cursed,
    Relict,
    Construct,
    Doomed,

    Neutral,
    Monster,
    Nilfgaard,
};

enum Choice
{
    NoChoice,
    Play,
    SelectAllyRowAndPos,
    SelectEnemyRowAndPos,
    Target
};


struct Field;

struct Card
{
    Card() = default;
    virtual ~Card() = default;

    int power = 0;
    int powerBase = 0;
    int armor = 0;
    int rarity = 0;
    int timer = 0;
    int faction = Neutral;
    std::vector<Tag> tags;
    bool isLocked = false;
    bool isSpy = false;
    bool isAmbush = false;

    inline virtual void onEnter(const Row, const Pos, Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onTargetChoosen(Card *) {}
    inline virtual void onDraw() {}
    inline virtual void onDiscard() {}
    inline virtual void onDie(const Row, const Pos, Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onOtherAllyEnter(Card *) {}
    inline virtual void onOtherEnemyEnter(Card *) {}
    inline virtual void onPlaySpecial() {}
    inline virtual void onOtherAllyPlaySpecial(Card *) {}
    inline virtual void onOtherEnemyPlaySpecial(Card *) {}
};


struct Field
{
    std::vector<Card *> rowMeele;
    std::vector<Card *> rowRange;
    std::vector<Card *> rowSeige;
    std::vector<Card *> hand;
    std::vector<Card *> discard;

    Choice choice = NoChoice;
    std::vector<Card *> cardStack;
    std::vector<Card *> choiceBetween;

    const std::vector<Card *> &row(Row _row) const;
    std::vector<Card *> &row(Row _row);
};


bool isIn(const Card *card, const std::vector<Card *> &vector);
bool hasTag(const Card *card, const Tag tag);
bool isRowFull(const std::vector<Card *> &row);
bool isOkRowAndPos(const Row row, const Pos pos, const Field &field);

/// find a place of a card in the field. returns false if non found
bool rowAndPos(Card *card, const Field &field, Row &row, Pos &pos);

/// put a non-special card on exact place, then resolve it enter abilities, then resolve others' otherEnter abilities
void putOnField(Card *card, const Row row, const Pos pos, Field &ally, Field &enemy);

/// resolve a specia card ability, then resolve others' otherPlaySpecial abilities
void playAsSpecial(Card *card, Field &ally, Field &enemy);

bool drawACard(Field &field);
void traceField(Field &field);

bool startChoiceToPlayCard(Field &field);
void onChoiceDoneCard(Card *card, Field &ally, Field &enemy);
void onChoiceDoneRowAndPlace(const Row row, const Pos pos, Field &ally, Field &enemy);


#endif // CARD_H
