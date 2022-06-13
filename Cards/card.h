#ifndef CARD_H
#define CARD_H

#include <random>

#include "iterator.h"
#include "view.h"


struct Field;


struct RowAndPos
{
    static const int posMax = 9;
    RowAndPos() = default;
    RowAndPos(const Row row, const Pos pos);
    operator bool() const;
    Row row() const;
    Pos pos() const;
private:
    int _row = -1;
    int _pos = -1;
};


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
    // BUG: still can damage unit in ambush (with near)
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

    void onGameStart(Field &ally, Field &enemy);
    void onDeploy(Field &ally, Field &enemy);
    void onDeployFromDiscard(Field &ally, Field &enemy);
    void onDeployFromDeck(Field &ally, Field &enemy);
    void onMoveFromRowToRow(Field &ally, Field &enemy);
    void onTurnStart(Field &ally, Field &enemy);
    void onTurnEnd(Field &ally, Field &enemy);
    void onTargetChoosen(Card *card, Field &ally, Field &enemy);
    void onTargetRowChoosen(Field &ally, Field &enemy, const int screenRow);
    void onDraw(Field &ally, Field &enemy);
    void onSwap(Field &ally, Field &enemy);
    void onDiscard(Field &ally, Field &enemy);
    void onDestroy(Field &ally, Field &enemy, const RowAndPos &rowAndPos);
    void onPlaySpecial(Field &ally, Field &enemy);
    void onBoost(const int x, Field &ally, Field &enemy);
    void onRevealed(Field &ally, Field &enemy, const Card *src);
    void onOtherRevealed(Field &ally, Field &enemy, Card *card, const Card *src);
    void onDamaged(const int x, Field &ally, Field &enemy, const Card *src);
    void onWeakened(const int x, Field &ally, Field &enemy, const Card *src);
    void onArmorLost(Field &ally, Field &enemy);
    void onContactWithFullMoon(Field &ally, Field &enemy);
    /// check whether self on board, in hand/deck/discard
    void onOtherEnemyDamaged(Card *card, Field &ally, Field &enemy);
    void onOtherEnemyDestroyed(Card *card, Field &ally, Field &enemy);
    void onOtherAllyDiscarded(Card *card, Field &ally, Field &enemy);
    void onOtherAllyDestroyed(Card * card, Field &ally, Field &enemy, const RowAndPos &rowAndPos);
    void onOtherAllyPlayedFromHand(Card *card, Field &ally, Field &enemy);
    void onOtherAllyAppears(Card *card, Field &ally, Field &enemy);
    void onOtherEnemyPlayedFromHand(Card *card, Field &ally, Field &enemy);
    void onOtherAllyResurrecteded(Card *card, Field &ally, Field &enemy);
    void onOpponentPass(Field &ally, Field &enemy);
    void onRoundLose(Field &ally, Field &enemy);
    // TODO: test and find all the cases
    /// check whether self on board, in hand/deck/discard
    void onAllyAppliedRowEffect(const RowEffect rowEffect, Field &ally, Field &enemy, const Row row);
    // TODO: test and find all the cases
    /// check whether self on board, in hand/deck/discard
    void onConsumed(Field &ally, Field &enemy, Card *src);
    void onAllyConsume(Field &ally, Field &enemy, Card *src);

    inline virtual Card *defaultCopy() const { return new Card; }
    inline virtual Card *exactCopy() const { return new Card; }
    inline bool hasDeathwish() const { return _onDestroy != nullptr; }
    inline bool hasOnAllyApplyEffect() const { return _onAllyAppliedRowEffect != nullptr; }

protected:
    using AllyEnemyRowAndPos = std::function<void(Field &, Field &, const RowAndPos &)>;
    using CardAllyEnemy = std::function<void(Card *, Field &, Field &)>;
    using CardAllyEnemyRowAndPos = std::function<void(Card *, Field &, Field &, const RowAndPos &)>;
    using AllyEnemy = std::function<void(Field &, Field &)>;
    using IntAllyEnemy = std::function<void(const int, Field &, Field &)>;
    using AllyEnemyCardSrc = std::function<void(Field &, Field &, Card *, const Card *)>;
    using AllyEnemySrc = std::function<void(Field &, Field &, const Card *)>;
    using AllyEnemySrcChangable = std::function<void(Field &, Field &, Card *)>;
    using IntAllyEnemySrc = std::function<void(const int, Field &, Field &, const Card *)>;
    using AllyEnemyInt = std::function<void(Field &, Field &, const int)>;
    using RowEffectAllyEnemyRow = std::function<void(const RowEffect, Field &, Field &, const Row)>;
    AllyEnemyRowAndPos _onDestroy = nullptr;
    CardAllyEnemyRowAndPos _onOtherAllyDestroyed = nullptr;
    AllyEnemy _onGameStart = nullptr;
    AllyEnemy _onDeploy = nullptr;
    AllyEnemy _onDeployFromDiscard = nullptr;
    AllyEnemy _onDeployFromDeck = nullptr;
    AllyEnemy _onPlaySpecial = nullptr;
    AllyEnemy _onDraw = nullptr;
    AllyEnemy _onMoveFromRowToRow = nullptr;
    AllyEnemy _onTurnStart = nullptr;
    AllyEnemy _onTurnEnd = nullptr;
    AllyEnemy _onSwap = nullptr;
    AllyEnemy _onDiscard = nullptr;
    AllyEnemy _onArmorLost = nullptr;
    AllyEnemy _onContactWithFullMoon = nullptr;
    AllyEnemy _onOpponentPass = nullptr;
    AllyEnemy _onRoundLose = nullptr;
    AllyEnemyInt _onTargetRowChoosen = nullptr;
    IntAllyEnemy _onBoost = nullptr;
    AllyEnemySrc _onRevealed = nullptr;
    AllyEnemyCardSrc _onOtherRevealed = nullptr;
    IntAllyEnemySrc _onDamaged = nullptr;
    IntAllyEnemySrc _onWeakened = nullptr;
    CardAllyEnemy _onOtherEnemyDamaged = nullptr;
    CardAllyEnemy _onTargetChoosen = nullptr;
    CardAllyEnemy _onOtherEnemyDestroyed = nullptr;
    CardAllyEnemy _onOtherAllyPlayedFromHand = nullptr;
    CardAllyEnemy _onOtherAllyDiscarded = nullptr;
    CardAllyEnemy _onOtherAllyAppears = nullptr;
    CardAllyEnemy _onOtherEnemyPlayedFromHand = nullptr;
    CardAllyEnemy _onOtherAllyResurrecteded = nullptr;
    RowEffectAllyEnemyRow _onAllyAppliedRowEffect = nullptr;
    AllyEnemySrcChangable _onConsumed = nullptr;
    AllyEnemySrcChangable _onAllyConsume = nullptr;
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
    Card *exactCopy() const override
    {
        const T *self = dynamic_cast<const T*>(this);
        return new T(*self);
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
    std::vector<int> valuesOptions;
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
    /// cards, that didn't start in the deck,
    /// but were added in the process of game
    /// with `spawn`, `create`, etc
    std::vector<Card *> cardsAdded;
    /// current choices player should resolve
    std::vector<Choice> cardStack;
    /// cards played in order for history
    /// and retrograde effects
    std::vector<Card *> cardsAppearedBoth;
    std::vector<Card *> cardsAppeared;
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
    RowAndPos lastPosInARow(const Row _row) const;
    const std::vector<Card *> &row(const Row _row) const;
    std::vector<Card *> &row(const Row _row);
    RowEffect &rowEffect(const Row _row);
    RowEffect rowEffect(const Row _row) const;
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
RowAndPos _findRowAndPos(const Card *card, const Field &field);
RowAndPos rowAndPosToTheRight(const Card *card, const Field &field, const int offset);
RowAndPos rowAndPosToTheLeft(const Card *card, const Field &field, const int offset);
RowAndPos rowAndPosLastInExactRow(const Field &field, const Row row);
RowAndPos rowAndPosLastInTheOppositeRow(const Card *card, const Field &ally, const Field &enemy);
RowAndPos rowAndPosLastInTheSameRow(const Card *card, const Field &field);
//RowAndPos rowAndPosLastInExactRow(const Field &field);
RowAndPos rowAndPosRandom(Field &field);
Row fromScreenRow(const int screenRow, bool &isAlly);

/// may be used as top or most-left
std::vector<Card *> firsts(const std::vector<Card *> &cards, const int nFirsts);
Card *first(const std::vector<Card *> &cards);
/// may be used as bottom or most-right
Card *last(const std::vector<Card *> &cards);
std::vector<Card *> highests(const std::vector<Card *> &row);
Card *highest(const std::vector<Card *> &row, Rng &rng);
std::vector<Card *> lowests(const std::vector<Card *> &row);
Card *lowest(const std::vector<Card *> &row, Rng &rng);
Card *first(const std::vector<Card *> &row);
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
RowEffect rowEffectUnderUnit(const Card* card, const Field &field);
// TODO: remove old function
bool randomRowAndPos(Field &field, Row &row, Pos &pos);

/// find a place of a card in the field. returns false if non found
bool _findRowAndPos(const Card *card, const Field &field, Row &row, Pos &pos);

/// put a non-special card on exact place, then resolve it enter abilities, then resolve others' otherEnter abilities
bool _putOnField(Card *card, const RowAndPos &rowAndPos, Field &ally, Field &enemy, const bool triggerDeploy, const Card *src);

/// put any card to discard
void putToDiscard(Card *card, Field &ally, Field &enemy, const Card *src);

void putToDeck(Card *card, Field &ally, Field &enemy, const DeckPos deckPos, const Card *src);

/// resolve a special card ability, then resolve others' otherPlaySpecial abilities
void _activateSpecial(Card *card, Field &ally, Field &enemy, const Card *src);

void playExistedCard(Card *card, Field &ally, Field &enemy, const Card *src);
/// spawn in a place or move from row to row
// BUG: doesn't work with the same row (move from row X to itself)
bool moveExistedUnitToPos(Card *card, const RowAndPos &rowAndPos, Field &ally, Field &enemy, const Card *src);
bool moveSelfToRandomRow(Card *card, Field &ally, Field &enemy);
void spawnNewCard(Card *card, Field &ally, Field &enemy, const Card *src);
bool spawnNewUnitToPos(Card *card, const RowAndPos &rowAndPos, Field &ally, Field &enemy, const Card *src);
bool summonNewUnitToPos(Card *card, const RowAndPos &rowAndPos, Field &ally, Field &enemy, const Card *src);
void addAsNew(Field &field, Card *card);

/// returns true if destroyed a unit
bool damage(Card *card, const int x, Field &ally, Field &enemy, const Card *src);
void setPower(Card *card, const int x, Field &ally, Field &enemy, const Card *src);
void drain(Card *target, const int x, Field &ally, Field &enemy, Card *self);
int consume(Card *target, Field &ally, Field &enemy, Card *src);
void applyRowEffect(Field &ally, Field &enemy, const int screenRow, const RowEffect rowEffect);
std::vector<Card *> cardsInRow(Field &ally, Field &enemy, const int screenRow);
void clearHazardsFromItsRow(const Card *card, Field &field);
void clearAllHazards(Field &field, std::vector<Card *> *damagedUnitsUnderHazards = nullptr);
void transform(Card *card, const Card &target, Field &ally, Field &enemy, const Card *src);
void heal(Card *card, Field &ally, Field &enemy);
void heal(Card *card, const int x, Field &ally, Field &enemy);
/// always takes bigger half. 1 of 1, 2 of 3, 3 of 5, etc
int half(const int x);
void reset(Card *card, Field &ally, Field &enemy);
void resetPower(Card *card, Field &ally, Field &enemy);
void removeAllStatuses(Card *card, Field &ally, Field &enemy);
void putToHand(Card *card, Field &ally, Field &enemy);
void boost(Card *card, const int x, Field &ally, Field &enemy, const Card *src);
void strengthen(Card *card, const int x, Field &ally, Field &enemy);
bool weaken(Card *card, const int x, Field &ally, Field &enemy, const Card *src);
void gainArmor(Card *card, const int x, Field &ally, Field &enemy, const Card *src);
bool drawACard(Field &ally, Field &enemy);
void swapACard(Card *card, Field &ally, Field &enemy, const Card *src);
void banish(Card *card, Field &ally, Field &enemy, const Card *src);
/// returns true if wins a duel
bool duel(Card *first, Card *second, Field &ally, Field &enemy);
void charm(Card *card, Field &ally, Field &enemy, const Card *src);
void toggleLock(Card *card, Field &ally, Field &enemy, const Card *src);
void lock(Card *card, Field &ally, Field &enemy, const Card *src);
void toggleSpy(Card *card, Field &ally, Field &enemy, const Card *src);
void spy(Card *card, Field &ally, Field &enemy, const Card *src);
/// returns true if timer ends, otherwise returns false
/// if resetTo >0 then timer ll go to the loop, otherwise is singleshot
bool tick(Card *card, Field &ally, Field &enemy, const int resetTo = -1);
void setTimer(Card *card, Field &ally, Field &enemy, const int x);
void flipOver(Card *card, Field &ally, Field &enemy);
void reveal(Card *card, Field &ally, Field &enemy, const Card *src);
void conceal(Card *card, Field &ally, Field &enemy, const Card *src);
/// returns number of ability calls for a crewed units
int nCrewed(Card *card, Field &ally);
void pass(Field &ally, Field &enemy);

using Filters = std::vector<std::function<bool(Card *)> >;
using RowFilters = std::vector<std::function<bool(const std::vector<Card *> &)>>;

std::vector<Card *> cardsFiltered(Field &ally, Field &enemy, const Filters &filters, const ChoiceGroup group);
void startChoiceToSelectRow(Field &ally, Field &enemy, Card *self, const std::vector<int> &screenRowsOptions = {0, 1, 2, 3, 4, 5}, const RowFilters &rowFilters = {});
/// if nWindow > 0, then its a random shuffled options out of all givne options. Mainly for create / Shupe abilities
void startChoiceToSelectOption(Field &ally, Card *self, const std::vector<Card *> &options, const int nTargets = 1, const int nWindow = -1, const bool isOptional = false);
void startChoiceCreateOptions(Field &ally, Card *src, const Filters &filters = {}, const bool isOptional = false);
void startChoiceSpawnOptions(Field &ally, Card *src, const Filters &filters = {}, const bool isOptional = false);
void startChoiceToTargetCard(Field &ally, Field &enemy, Card *self, const Filters &filters = {}, const ChoiceGroup group = AnyBoard, const int nTargets = 1, const bool isOptional = false);
void startChoiceToTargetCard(Field &ally, Field &enemy, Card *self, const std::vector<Card *> &options, const int nTargets = 1, const bool isOptional = false);
void onChoiceDoneCard(Card *card, Field &ally, Field &enemy);
void onChoiceDoneRowAndPlace(const RowAndPos &_findRowAndPos, Field &ally, Field &enemy);
void onChoiceDoneRow(const int screenRow, Field &ally, Field &enemy);
void onChoiceDoneRoundStartSwap(Card *card, Field &ally, Field &enemy);
void saveFieldsSnapshot(Field &ally, Field &enemy, const ActionType actionType, const Card *src = nullptr, const std::vector<Card *> &dst = {}, const std::string &sound = "", const int value = -1, const ActionType actionTypeEnemy = Invalid);
/// returns false when no choice left (game end)
bool tryFinishTurn(Field &ally, Field &enemy);

/// value computation
std::map<const Card *, int> optionToGap(const Field &ally, const Field &enemy);

#endif // CARD_H
