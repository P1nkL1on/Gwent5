#ifndef CARD_H
#define CARD_H

#include <random>

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
    bool isCrew = false;
    bool isRevealed = false;

    std::string id;
    std::string name;
    std::string text;
    std::string url;
    std::vector<std::string> sounds;
    Patch patch = PublicBeta_0_9_24_3_432;

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
    inline virtual void onDestroy(Field &/*ally*/, Field &/*enemy*/, const RowAndPos &) {}
    inline virtual void onPlaySpecial(Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onBoost(const int, Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onDamaged(const int, Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onArmorLost(Field &/*ally*/, Field &/*enemy*/) {}
    /// check whether self on board, in hand/deck/discard
    inline virtual void onOtherEnemyDamaged(Card *, Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onOtherEnemyDestroyed(Card *, Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onOtherAllyDiscarded(Card *, Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onOtherAllyPlayedFromHand(Card *, Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onOtherEnemyPlayedFromHand(Card *, Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual void onOtherAllyResurrecteded(Card *, Field &/*ally*/, Field &/*enemy*/) {}
    inline virtual Card *defaultCopy() const { return new Card; }
};


template <class T>
struct CardCollectible : Card
{
    static Card *create(const Patch patch)
    {
        Card *base = new Card;
        base->patch = patch;
        T *res = new(base) T();
        return res;
    }
    Card *defaultCopy() const override
    {
        return CardCollectible<T>::create(patch);
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


using Rng = std::default_random_engine;

struct Field
{
    std::vector<Card *> rowMeele;
    std::vector<Card *> rowRange;
    std::vector<Card *> rowSeige;
    std::vector<Card *> hand;
    std::vector<Card *> deck;
    std::vector<Card *> discard;
    Card *leader = nullptr;

    RowEffect rowEffectMeele = NoRowEffect;
    RowEffect rowEffectRange = NoRowEffect;
    RowEffect rowEffectSeige = NoRowEffect;

    Card *leaderStarting = nullptr;
    std::vector<Card *> deckStarting;
    std::vector<Card *> cardsAdded;
    std::vector<Choice> cardStack;
    int nTurns = 0;
    int nRounds = 0;
    int nWins = 0;
    int nSwaps = 0;
    bool passed = false;
    bool canPass = true;

    Rng rng;

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
bool isOnBoard(const Card *card, const Field &field);
bool hasTag(const Card *card, const Tag tag);
bool isRowFull(const std::vector<Card *> &row);
bool isOkRowAndPos(const RowAndPos &rowAndPos, const Field &field);
Card *cardAtRowAndPos(const Row row, const Pos pos, const Field &field);
Card *cardNextTo(const Card *card, const Field &ally, const Field &enemy, const int offset);
RowAndPos findRowAndPos(const Card *card, const Field &field);
RowAndPos rowAndPosLastInExactRow(const Field &field, const Row row);
RowAndPos rowAndPosNextTo(const Card *card, const Field &field, const int offset);
RowAndPos rowAndPosRandom(Field &field);
std::vector<Card *> highests(const std::vector<Card *> &row);
Card *highest(const std::vector<Card *> &row, Rng &rng);
std::vector<Card *> lowests(const std::vector<Card *> &row);
Card *lowest(const std::vector<Card *> &row, Rng &rng);
std::vector<Card *> findCopies(const Card *card, const std::vector<Card *> &cards);
Card *findCopy(const Card *card, const std::vector<Card *> &cards);
Row takeCard(const Card *card, Field &ally, Field &enemy, Pos *pos = nullptr, bool *isAlly = nullptr);
void triggerRowEffects(Field &ally, Field &enemy);
void initField(const std::vector<Card *> &deckStarting, Card *leader, Field &field);
void startNextRound(Field &ally, Field &enemy);
void shuffle(std::vector<Card *> &cards, Rng &rng);
std::vector<Card *> randoms(const std::vector<Card *> &cards, const int nRandoms, Rng &rng);
Card *random(const std::vector<Card *> &cards, Rng &rng);
void copyCardText(const Card *card, Card *dst);
void acceptOptionAndDeleteOthers(Card *card, const Card *option);
std::string randomSound(const Card *card, Rng &rng);
RowEffect randomHazardEffect(Rng &rng);
bool hasNoDuplicates(const std::vector<Card *> &cards);
bool hasExactTwoDuplicatesOfBronze(const std::vector<Card *> &cards);
// TODO: remove old function
bool randomRowAndPos(Field &field, Row &row, Pos &pos);

/// find a place of a card in the field. returns false if non found
bool findRowAndPos(const Card *card, const Field &field, Row &row, Pos &pos);

/// put a non-special card on exact place, then resolve it enter abilities, then resolve others' otherEnter abilities
bool _putOnField(Card *card, const RowAndPos &rowAndPos, Field &ally, Field &enemy, const bool triggerDeploy, const Card *src);

/// put any card to discard
void putOnDiscard(Card *card, Field &ally, Field &enemy, const Card *src);

/// resolve a special card ability, then resolve others' otherPlaySpecial abilities
void _activateSpecial(Card *card, Field &ally, Field &enemy, const Card *src);

void playExistedCard(Card *card, Field &ally, Field &enemy, const Card *src);
/// spawn in a place or move from row to row
void moveExistedUnitToPos(Card *card, const RowAndPos &rowAndPos, Field &ally, Field &enemy, const Card *src);
void spawnNewCard(Card *card, Field &ally, Field &enemy, const Card *src);
void spawnNewUnitToPos(Card *card, const RowAndPos &rowAndPos, Field &ally, Field &enemy, const Card *src);

/// returns true if destroyed a unit
bool damage(Card *card, const int x, Field &ally, Field &enemy, const Card *src);
void drain(Card *target, const int x, Field &ally, Field &enemy, Card *self);
void applyRowEffect(Field &ally, Field &enemy, const Row row, const RowEffect rowEffect);
void clearAllHazards(Field &field, std::vector<Card *> *damagedUnitsUnderHazards = nullptr);
void transform(Card *card, const std::string &id, const std::string &name, const std::string &text, const std::string &url, const int power, const Rarity rarity, const Tag faction = Neutral, const std::vector<Tag> &tags = {});
void heal(Card *card, Field &ally, Field &enemy);
void reset(Card *card, Field &ally, Field &enemy);
void putToHand(Card *card, Field &ally, Field &enemy);
void boost(Card *card, const int x, Field &ally, Field &enemy, const Card *src);
void strengthen(Card *card, const int x, Field &ally, Field &enemy);
bool weaken(Card *card, const int x, Field &ally, Field &enemy);
void gainArmor(Card *card, const int x, Field &ally, Field &enemy, const Card *src);
bool drawACard(Field &ally, Field &enemy);
void swapACard(Card *card, Field &ally, Field &enemy);
void banish(Card *card, Field &ally, Field &enemy);
void duel(Card *first, Card *second, Field &ally, Field &enemy);
void charm(Card *card, Field &ally, Field &enemy, const Card *src);
void toggleLock(Card *card, Field &ally, Field &enemy);
void lock(Card *card, Field &ally, Field &enemy);
bool tick(Card *card, Field &ally, Field &enemy, const int resetTo = -1);
void setTimer(Card *card, Field &ally, Field &enemy, const int x);
void flipOver(Card *card, Field &ally, Field &enemy);

using Filters = std::vector<std::function<bool(Card *)> >;

std::vector<Card *> cardsFiltered(Field &ally, Field &enemy, const Filters &filters, const ChoiceGroup group);
void startChoiceToSelectAllyRow(Field &field, Card *self);
void startChoiceToSelectEnemyRow(Field &field, Card *self);
/// if nWindow > 0, then its a random shuffled options out of all givne options. Mainly for create / Shupe abilities
void startChoiceToSelectOption(Field &ally, Card *self, const std::vector<Card *> &options, const int nTargets = 1, const int nWindow = -1, const bool isOptional = false);
void startChoiceCreateOptions(Field &ally, Card *self, const Filters &filters = {}, const bool isOptional = false);
void startChoiceToTargetCard(Field &ally, Field &enemy, Card *self, const Filters &filters = {}, const ChoiceGroup group = AnyBoard, const int nTargets = 1, const bool isOptional = false);
void startChoiceToTargetCard(Field &ally, Field &enemy, Card *self, const std::vector<Card *> &options, const int nTargets = 1, const bool isOptional = false);
void onChoiceDoneCard(Card *card, Field &ally, Field &enemy);
void onChoiceDoneRowAndPlace(const RowAndPos &findRowAndPos, Field &ally, Field &enemy);
void onChoiceDoneRow(const Row row, Field &ally, Field &enemy);
void onChoiceDoneRoundStartSwap(Card *card, Field &ally, Field &enemy);
void saveFieldsSnapshot(Field &ally, Field &enemy, const ActionType actionType = Invalid, const Card *src = nullptr, const std::vector<Card *> &dst = {}, const std::string &sound = "", const int value = -1);
/// returns false when no choice left (game end)
bool tryFinishTurn(Field &ally, Field &enemy);


#endif // CARD_H
