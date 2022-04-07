#ifndef CARD_H
#define CARD_H

#include <string>

#include "iterator.h"

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
    Beast,
    Cursed,
    Relict,
    Construct,
    Temerian,
    Support,
    Mage,

    Neutral,
    Monster,
    Nilfgaard,
    NothernRealms,
};

enum Choice
{
    Play,
    SelectAllyRowAndPos,
    SelectEnemyRowAndPos,
    Target,
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
    bool isImmune = false;
    bool isDoomed = false;
    bool isSpecial = false;
    std::string name;

    inline virtual void onEnter(const Row, const Pos, Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onTargetChoosen(Card *, Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onDraw() {}
    inline virtual void onDiscard() {}
    inline virtual void onDie(const Row, const Pos, Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onOtherAllyEntered(Card *) {}
    inline virtual void onOtherEnemyEntered(Card *) {}
    inline virtual void onPlaySpecial() {}
    inline virtual void onOtherAllySpecialPlayed(Card *) {}
    inline virtual void onOtherEnemySpecialPlayed(Card *) {}
    inline virtual void onBoost(const int, Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onOtherAllyBoosted(const int, Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onOtherEnemyBoosted(const int, Field &/*ally*/, Field &/*enemy*/) {}
};

struct Snapshot
{
    Choice choice;
    Card * cardSource;
    std::vector<Card *> cardOptions;
};

struct Field
{
    std::vector<Card *> rowMeele;
    std::vector<Card *> rowRange;
    std::vector<Card *> rowSeige;
    std::vector<Card *> hand;
    std::vector<Card *> deck;
    std::vector<Card *> discard;

    std::vector<Snapshot> cardStack;

    const Snapshot &snapshot() const;
    Snapshot &snapshot();
    Snapshot takeSnapshot();
    const std::vector<Card *> &row(Row _row) const;
    std::vector<Card *> &row(Row _row);
};




std::string stringSnapShots(const std::vector<Snapshot> &cardStack);
bool isIn(const Card *card, const std::vector<Card *> &vector);
bool hasTag(const Card *card, const Tag tag);
bool isRowFull(const std::vector<Card *> &row);
bool isOkRowAndPos(const Row row, const Pos pos, const Field &field);
void takeCard(const Card *card, Field &field);

/// find a place of a card in the field. returns false if non found
bool rowAndPos(Card *card, const Field &field, Row &row, Pos &pos);

/// put a non-special card on exact place, then resolve it enter abilities, then resolve others' otherEnter abilities
void putOnField(Card *card, const Row row, const Pos pos, Field &ally, Field &enemy);

/// resolve a special card ability, then resolve others' otherPlaySpecial abilities
void playAsSpecial(Card *card, Field &ally, Field &enemy);

void boost(Card *card, const int x, Field &ally, Field &enemy);

bool drawACard(Field &field);
void traceField(Field &field);

using Filters = std::vector<std::function<bool(Card *)> >;

bool startChoiceToPlayCard(Field &field, Card *self, const Filters &filters = {});
bool startChoiceToTargetCard(Field &field, Card *self, const Filters &filters = {});
void onChoiceDoneCard(Card *card, Field &ally, Field &enemy);
void onChoiceDoneRowAndPlace(const Row row, const Pos pos, Field &ally, Field &enemy);


#endif // CARD_H
