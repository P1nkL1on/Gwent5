#ifndef CARD_H
#define CARD_H

#include <string>

#include "iterator.h"

enum Row
{
    Meele,
    Range,
    Seige,
    Hand,
    Deck,
    Discard,
    AlreadyCreated
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
    Temeria,
    Redania,
    Kaedwen,
    ClanAnCraite,
    ClanDimun,
    ClanTuirseach,
    Support,
    Mage,
    Soldier,
    Elf,
    Machine,
    Alchemy,
    Item,
    Organic,
    Spell,

    Neutral,
    Monster,
    Nilfgaard,
    NothernRealms,
    Scoiatael,
    Skellige,
};

enum Choice
{
    Play,
    SelectAllyRowAndPos,
    SelectEnemyRowAndPos,
    Target,
};

enum ChoiceGroup
{
    /// on a table
    Any,
    Ally,
    Enemy,
    /// others
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
    std::string url;

    inline virtual void onEnter(Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onEnterFromDiscard(Field &ally, Field &enemy) { return onEnter(ally, enemy); }
    inline virtual void onEnterFromDeck(Field &ally, Field &enemy) { return onEnter(ally, enemy); }
    inline virtual void onMoveFromRowToRow(Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onTurnStart(Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onTurnEnd(Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onTargetChoosen(Card *, Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onDraw() {}
    inline virtual void onDiscard(Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onDie(Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onOtherAllyEntered(Card *) {}
    inline virtual void onOtherEnemyEntered(Card *) {}
    inline virtual void onPlaySpecial(Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onOtherAllySpecialPlayed(Card *) {}
    inline virtual void onOtherEnemySpecialPlayed(Card *) {}
    inline virtual void onBoost(const int, Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onOtherAllyBoosted(const int, Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onOtherEnemyBoosted(const int, Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onArmorLost(Field &/*ally*/, Field &/*enemy*/) {}
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

    std::vector<Card *> deckStarting;
    std::vector<Card *> cardsAdded;
    std::vector<Snapshot> cardStack;
    int nTurns = 0;

    const Snapshot &snapshot() const;
    Snapshot &snapshot();
    Snapshot takeSnapshot();
    const std::vector<Card *> &row(Row _row) const;
    std::vector<Card *> &row(Row _row);
};



int powerField(const Field &field);
int powerRow(const std::vector<Card *> &vector);
std::string stringSnapShots(const std::vector<Snapshot> &cardStack);
bool isIn(const Card *card, const std::vector<Card *> &vector);
bool hasTag(const Card *card, const Tag tag);
bool isRowFull(const std::vector<Card *> &row);
bool isOkRowAndPos(const Row row, const Pos pos, const Field &field);
Card *cardAtRowAndPos(const Row row, const Pos pos, const Field &field);
Card *cardNextTo(const Card *card, const Field &ally, const Field &enemy, const int offset);
Row takeCard(const Card *card, Field &ally, Field &enemy);

/// find a place of a card in the field. returns false if non found
bool rowAndPos(const Card *card, const Field &field, Row &row, Pos &pos);

/// put a non-special card on exact place, then resolve it enter abilities, then resolve others' otherEnter abilities
void putOnField(Card *card, const Row row, const Pos pos, Field &ally, Field &enemy);

/// put any card to discard
void putOnDiscard(Card *card, Field &ally, Field &enemy);

/// resolve a special card ability, then resolve others' otherPlaySpecial abilities
void playAsSpecial(Card *card, Field &ally, Field &enemy);

void spawn(Card *card, Field &ally, Field &enemy);
void spawn(Card *card, const Row row, const Pos pos, Field &ally, Field &enemy);
void damage(Card *card, const int x, Field &ally, Field &enemy);
void boost(Card *card, const int x, Field &ally, Field &enemy);
void strengthen(Card *card, const int x, Field &ally, Field &enemy);
void gainArmor(Card *card, const int x, Field &ally, Field &enemy);

bool drawACard(Field &field);
void traceField(Field &field);

using Filters = std::vector<std::function<bool(Card *)> >;

bool startChoiceToPlayCard(Field &field, Card *self, const Filters &filters = {});
bool startChoiceToTargetCard(Field &ally, Field &enemy, Card *self, const Filters &filters = {}, const ChoiceGroup group = Any);
void onChoiceDoneCard(Card *card, Field &ally, Field &enemy);
void onChoiceDoneRowAndPlace(const Row row, const Pos pos, Field &ally, Field &enemy);
bool tryFinishTurn(Field &ally, Field &enemy);


#endif // CARD_H
