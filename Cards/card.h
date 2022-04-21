#ifndef CARD_H
#define CARD_H

#include "iterator.h"
#include "view.h"


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
    bool isLoyal = true;
    bool isSpecial = false;

    bool isLocked = false;
    bool isSpy = false;
    bool isResilient = false;
    // TODO: still can damage unit in ambush (with near)
    bool isAmbush = false;
    bool isImmune = false;
    bool isDoomed = false;

    std::string name;
    std::string text;
    std::string url;
    std::vector<std::string> sounds;
    Patch _patch = PublicBeta_0_9_24_3_432;

    /// temporary created options
    std::vector<Card *> _options;

    inline virtual void onDeploy(Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onDeployFromDiscard(Field &ally, Field &enemy) { return onDeploy(ally, enemy); }
    inline virtual void onDeployFromDeck(Field &ally, Field &enemy) { return onDeploy(ally, enemy); }
    inline virtual void onMoveFromRowToRow(Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onTurnStart(Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onTurnEnd(Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onTargetChoosen(Card *, Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onTargetRowAllyChoosen(Field &/*ally*/, Field &/*enemy*/, const Row) {}
    inline virtual void onTargetRowEnemyChoosen(Field &/*ally*/, Field &/*enemy*/, const Row) {}
    inline virtual void onDraw(Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onSwap(Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onDiscard(Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onDestroy(Field &/*ally*/, Field &/*enemy*/, const Row, const Pos) {}
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
    inline virtual void onOtherAllyDiscarded(Card *, Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onOtherAllyResurrectededWhileOnDiscard(Card *, Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual Card *defaultCopy() { return new Card; }
};


template <class T>
struct CardCollectable : Card
{
    static Card *create(const Patch patch)
    {
        Card *base = new Card;
        base->_patch = patch;
        T *res = new(base) T();
        return res;
    }
    Card *defaultCopy() override
    {
        return CardCollectable<T>::create(_patch);
    }
};


struct Choice
{
    inline Choice(const ChoiceType choiceType, Card *cardSource = nullptr, const std::vector<Card *> &cardOptions = {}, const int nTargets = 1, const bool isOptional = false) :
        choiceType(choiceType),
        cardSource(cardSource),
        cardOptions(cardOptions),
        nTargets(nTargets),
        isOptional(isOptional)
    {
    }
    ChoiceType choiceType;
    Card *cardSource = nullptr;
    std::vector<Card *> cardOptions;
    std::vector<Card *> cardOptionsSelected;
    int nTargets = 1;
    bool isOptional = false;
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
    std::vector<Choice> cardStack;
    int nTurns = 0;
    int nRounds = 0;
    int nWins = 0;
    int nSwaps = 0;
    bool passed = false;
    std::vector<FieldView> snapshots;

    const Choice &choice() const;
    Choice &choice();
    Choice takeChoice();
    const std::vector<Card *> &row(const Row _row) const;
    std::vector<Card *> &row(const Row _row);
    RowEffect &rowEffect(const Row _row);
};


int powerField(const Field &field);
int powerRow(const std::vector<Card *> &vector);
std::string stringChoices(const std::vector<Choice> &cardStack);
bool isIn(const Card *card, const std::vector<Card *> &vector);
bool hasTag(const Card *card, const Tag tag);
bool isRowFull(const std::vector<Card *> &row);
bool isOkRowAndPos(const Row row, const Pos pos, const Field &field);
Card *cardAtRowAndPos(const Row row, const Pos pos, const Field &field);
Card *cardNextTo(const Card *card, const Field &ally, const Field &enemy, const int offset);
std::vector<Card *> highests(const std::vector<Card *> &row);
Card *highest(const std::vector<Card *> &row);
std::vector<Card *> lowests(const std::vector<Card *> &row);
Card *lowest(const std::vector<Card *> &row);
std::vector<Card *> findCopies(const Card *card, const std::vector<Card *> &cards);
Card *findCopy(const Card *card, const std::vector<Card *> &cards);
Row takeCard(const Card *card, Field &ally, Field &enemy, Pos *pos = nullptr, bool *isAlly = nullptr);
void triggerRowEffects(Field &ally, Field &enemy);
void initField(const std::vector<Card *> &deckStarting, Field &field);
void startNextRound(Field &ally, Field &enemy);
void shuffle(std::vector<Card *> &cards);
std::vector<Card *> randoms(const std::vector<Card *> &cards, const int nRandoms);
Card *random(const std::vector<Card *> &cards);
void copyCardText(const Card *card, Card *dst);
void acceptOptionAndDeleteOthers(Card *card, const Card *option);
void clearAllHazards(Field &field, std::vector<Card *> *damagedUnitsUnderHazards = nullptr);
std::string randomSound(const Card *card);
RowEffect randomHazardEffect();
bool hasNoDuplicates(const std::vector<Card *> &cards);
bool hasExactTwoDuplicatesOfBronze(const std::vector<Card *> &cards);
bool randomRowAndPos(const Field &field, Row &row, Pos &pos);

/// find a place of a card in the field. returns false if non found
bool rowAndPos(const Card *card, const Field &field, Row &row, Pos &pos);

/// put a non-special card on exact place, then resolve it enter abilities, then resolve others' otherEnter abilities
void putOnField(Card *card, const Row row, const Pos pos, Field &ally, Field &enemy);

/// put any card to discard
void putOnDiscard(Card *card, Field &ally, Field &enemy);

/// resolve a special card ability, then resolve others' otherPlaySpecial abilities
void playAsSpecial(Card *card, Field &ally, Field &enemy);

/// call play as special or start choosing a row and pos to play a unit
void playCard(Card *card, Field &ally, Field &enemy);

/// returns true if destroyed a unit
bool damage(Card *card, const int x, Field &ally, Field &enemy);
void drain(Card *target, const int x, Field &ally, Field &enemy, Card *self);

void applyRowEffect(Field &ally, Field &enemy, const Row row, const RowEffect rowEffect);

void spawn(Card *card, Field &ally, Field &enemy);
void spawn(Card *card, const Row row, const Pos pos, Field &ally, Field &enemy);
void heal(Card *card, Field &ally, Field &enemy);
void reset(Card *card, Field &ally, Field &enemy);
void putToHand(Card *card, Field &ally, Field &enemy);
void boost(Card *card, const int x, Field &ally, Field &enemy);
void strengthen(Card *card, const int x, Field &ally, Field &enemy);
bool weaken(Card *card, const int x, Field &ally, Field &enemy);
void gainArmor(Card *card, const int x, Field &ally, Field &enemy);
bool drawACard(Field &ally, Field &enemy);
void swapACard(Card *card, Field &ally, Field &enemy);
void banish(Card *card, Field &ally, Field &enemy);
void duel(Card *first, Card *second, Field &ally, Field &enemy);
void charm(Card *card, Field &ally, Field &enemy);

void traceField(Field &field);

using Filters = std::vector<std::function<bool(Card *)> >;

std::vector<Card *> cardsFiltered(const Field &ally, const Field &enemy, const Filters &filters, const ChoiceGroup group);
void startChoiceToSelectAllyRow(Field &field, Card *self);
void startChoiceToSelectEnemyRow(Field &field, Card *self);
/// if nWindow > 0, then its a random shuffled options out of all givne options. Mainly for create / Shupe abilities
void startChoiceToSelectOption(Field &ally, Card *self, const std::vector<Card *> &options, const int nTargets = 1, const int nWindow = -1, const bool isOptional = false);
void startChoiceCreateOptions(Field &ally, Card *self, const Filters &filters = {}, const bool isOptional = false);
bool startChoiceToTargetCard(Field &ally, Field &enemy, Card *self, const Filters &filters = {}, const ChoiceGroup group = AnyBoard, const int nTargets = 1, const bool isOptional = false);
void onChoiceDoneCard(Card *card, Field &ally, Field &enemy);
void onChoiceDoneRowAndPlace(const Row row, const Pos pos, Field &ally, Field &enemy);
void onChoiceDoneRow(const Row row, Field &ally, Field &enemy);
void onChoiceDoneRoundStartSwap(Card *card, Field &ally, Field &enemy);
void saveFieldsSnapshot(Field &ally, Field &enemy, const std::string &sound = "");
/// returns false when no choice left (game end)
bool tryFinishTurn(Field &ally, Field &enemy);


#endif // CARD_H
