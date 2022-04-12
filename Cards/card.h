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
    Relict,
    Construct,
    Elf,
    Dwarf,
    Temeria,
    Redania,
    Kaedwen,
    ClanAnCraite,
    ClanHeymaey,
    ClanDimun,
    ClanTuirseach,

    Cursed,
    Support,
    Officer,
    Mage,
    Soldier,
    Machine,
    Agent,

    Alchemy,
    Tactics,
    Spell,
    Item,
    Organic,
    Hazard,
    Boon,

    Neutral,
    Monster,
    Nilfgaard,
    NothernRealms,
    Scoiatael,
    Skellige,
};

enum RowEffect
{
    NoRowEffect,
    TorrentialRainEffect,
    BitingFrostEffect,
    ImpenetrableFogEffect,
    GoldenFrothEffect,
    SkelligeStormEffect,
    DragonsDreamEffect,
    KorathiHeatwaveEffect,
    RaghNarRoogEffect,
    FullMoonEffect,
    BloodMoonEffect,
};

enum Choice
{
    RoundStartPlay,
    SelectAllyRowAndPos,
    SelectEnemyRowAndPos,
    SelectAllyRow,
    SelectEnemyRow,
    Target,
    RoundStartSwap,
};

enum ChoiceGroup
{
    /// on a table
    Any,
    Ally,
    Enemy,
    /// others
    AllyHand,
    AllyDiscard,
    AllyDeckShuffled,
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
    // TODO: still can damage unit in ambush (with near)
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
    inline virtual void onDraw(Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onSwap(Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onDiscard(Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onDestroy(Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onPlaySpecial(Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onBoost(const int, Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onDamaged(const int, Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onArmorLost(Field &/*ally*/, Field &/*enemy*/) {}
//    inline virtual void onOtherAllyEntered(Card *) {}
//    inline virtual void onOtherEnemyEntered(Card *) {}
//    inline virtual void onOtherAllySpecialPlayed(Card *) {}
//    inline virtual void onOtherEnemySpecialPlayed(Card *) {}
//    inline virtual void onOtherAllyBoosted(Card *, const int, Field &/*ally*/, Field &/*enemy*/) {}
//    inline virtual void onOtherEnemyBoosted(Card *, const int, Field &/*ally*/, Field &/*enemy*/) {}
//    inline virtual void onOtherAllyDamaged(Card *, const int, Field &/*ally*/, Field &/*enemy*/) {}
//    inline virtual void onOtherEnemyDamaged(Card *, const int, Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual RowEffect rowEffect() const { return NoRowEffect; }
};

struct Snapshot
{
    inline Snapshot(const Choice choice, Card *cardSource = nullptr, const std::vector<Card *> &cardOptions = {}, const int nTargets = 1, const bool isOptional = false) :
        choice(choice),
        cardSource(cardSource),
        cardOptions(cardOptions),
        nTargets(nTargets),
        isOptional(isOptional)
    {
    }
    Choice choice;
    Card *cardSource = nullptr;
    std::vector<Card *> cardOptions;
    int nTargets = 1;
    bool isOptional = false;

    /// for nTargets > 1
    std::vector<Card *> cardOptionsSelected;
};

struct Animation
{
    virtual ~Animation() = default;
    virtual void run() = 0;
};

struct Field
{
    std::vector<Card *> rowMeele;
    std::vector<Card *> rowRange;
    std::vector<Card *> rowSeige;
    std::vector<Card *> hand;
    std::vector<Card *> deck;
    std::vector<Card *> discard;
    RowEffect rowEffectMeele = NoRowEffect;
    RowEffect rowEffectRange = NoRowEffect;
    RowEffect rowEffectSeige = NoRowEffect;

    std::vector<Card *> deckStarting;
    std::vector<Card *> cardsAdded;
    std::vector<Snapshot> cardStack;
    int nTurns = 0;
    int nRounds = 0;
    std::vector<Animation *> animations;

    const Snapshot &snapshot() const;
    Snapshot &snapshot();
    Snapshot takeSnapshot();
    const std::vector<Card *> &row(const Row _row) const;
    std::vector<Card *> &row(const Row _row);
    RowEffect &rowEffect(const Row _row);
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
std::vector<Card *> highests(const std::vector<Card *> &row);
Card *highest(const std::vector<Card *> &row);
std::vector<Card *> findCopies(const Card *card, const std::vector<Card *> &cards);
Card *findCopy(const Card *card, const std::vector<Card *> &cards);
Row takeCard(const Card *card, Field &ally, Field &enemy, bool *isAlly = nullptr);
void triggerRowEffects(Field &ally, Field &enemy);
void initField(const std::vector<Card *> &deckStarting, Field &field);
void startNextRound(Field &ally, Field &enemy);
void shuffle(std::vector<Card *> &cards);

/// find a place of a card in the field. returns false if non found
bool rowAndPos(const Card *card, const Field &field, Row &row, Pos &pos);

/// put a non-special card on exact place, then resolve it enter abilities, then resolve others' otherEnter abilities
void putOnField(Card *card, const Row row, const Pos pos, Field &ally, Field &enemy);

/// put any card to discard
void putOnDiscard(Card *card, Field &ally, Field &enemy);

/// resolve a special card ability, then resolve others' otherPlaySpecial abilities
void playAsSpecial(Card *card, Field &ally, Field &enemy);

/// call play as special or start choosing a row and pos to play a unit
void playACard(Card *card, Field &ally, Field &enemy);


void applyRowEffect(Field &field, const Row row, const RowEffect rowEffect);

void spawn(Card *card, Field &ally, Field &enemy);
void spawn(Card *card, const Row row, const Pos pos, Field &ally, Field &enemy);
void damage(Card *card, const int x, Field &ally, Field &enemy);
void boost(Card *card, const int x, Field &ally, Field &enemy);
void strengthen(Card *card, const int x, Field &ally, Field &enemy);
void weaken(Card *card, const int x, Field &ally, Field &enemy);
void gainArmor(Card *card, const int x, Field &ally, Field &enemy);
bool drawACard(Field &ally, Field &enemy);
void swapACard(Card *card, Field &ally, Field &enemy);
void destroy(Card *card, Field &ally, Field &enemy);
void banish(Card *card, Field &ally, Field &enemy);

void traceField(Field &field);

using Filters = std::vector<std::function<bool(Card *)> >;

std::vector<Card *> cardsFiltered(const Field &ally, const Field &enemy, const Filters &filters, const ChoiceGroup group);
void startChoiceToSelectAllyRow(Field &field, Card *self);
void startChoiceToSelectEnemyRow(Field &field, Card *self);
bool startChoiceToTargetCard(Field &ally, Field &enemy, Card *self, const Filters &filters = {}, const ChoiceGroup group = Any, const int nTargets = 1, const bool isOptional = false);
void onChoiceDoneCard(Card *card, Field &ally, Field &enemy);
void onChoiceDoneRowAndPlace(const Row row, const Pos pos, Field &ally, Field &enemy);
void onChoiceDoneRow(const Row row, Field &ally, Field &enemy);
void onChoiceDoneRoundStartSwap(Card *card, Field &ally, Field &enemy);
bool tryFinishTurn(Field &ally, Field &enemy);


#endif // CARD_H
