#ifndef CARD_H
#define CARD_H

#include <random>
#include <exception>

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


struct State
{
    virtual ~State() = default;
    virtual State *exactCopy() const = 0;
    virtual State *defaultCopy() const = 0;
};


template <class T>
struct StateCopy : State
{
    StateCopy<T> *exactCopy() const override
    {
        return new T(*dynamic_cast<const T *>(this));
    }
    StateCopy<T> *defaultCopy() const override
    {
        return new T();
    }
};


struct Card
{
    Card() = default;
    virtual ~Card();
    Card *exactCopy() const;
    Card *defaultCopy() const;
    // NOTE: given target card will be deleted
    void transform(Card *target);

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
    // special state if needed
    State *state = nullptr;

    Id id;
    std::string name;
    std::string text;
    std::string url;
    std::vector<std::string> sounds;

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
    void onOptionChoosen(Card *card, Field &ally, Field &enemy);
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
    void onPowerChanged(Field &ally, Field &enemy, const Card *src, const PowerChangeType type);
    void onArmorLost(Field &ally, Field &enemy);
    void onContactWithFullMoon(Field &ally, Field &enemy);
    /// check whether self on board, in hand/deck/discard
    void onOtherEnemyDamaged(Card *card, Field &ally, Field &enemy);
    void onOtherEnemyDestroyed(Card *card, Field &ally, Field &enemy);
    void onOtherAllyDiscarded(Card *card, Field &ally, Field &enemy);
    void onOtherAllyDestroyed(Card * card, Field &ally, Field &enemy, const RowAndPos &rowAndPos);
    void onOtherAllyPlayedFromHand(Card *card, Field &ally, Field &enemy);
    void onOtherAllyAppears(Card *card, Field &ally, Field &enemy);
    void onOtherEnemyAppears(Card *card, Field &ally, Field &enemy);
    void onOtherSpyAppears(Card *card, Field &ally, Field &enemy);
    void onOtherEnemyPlayedFromHand(Card *card, Field &ally, Field &enemy);
    void onOtherAllyResurrecteded(Card *card, Field &ally, Field &enemy);
    void onSpecialPlayed(Card *card, Field &ally, Field &enemy);
    void onAllySpecialPlayed(Card *card, Field &ally, Field &enemy);
    void onEnemyMoved(Card *card, Field &ally, Field &enemy);
    void onOpponentPass(Field &ally, Field &enemy);
    void onAllyPass(Field &ally, Field &enemy);
    void onRoundLose(Field &ally, Field &enemy);
    // TODO: test and find all the cases
    /// check whether self on board, in hand/deck/discard
    void onAllyAppliedRowEffect(const RowEffect rowEffect, Field &ally, Field &enemy, const Row row);
    // TODO: test and find all the cases
    /// check whether self on board, in hand/deck/discard
    void onConsumed(Field &ally, Field &enemy, Card *src);
    void onAllyConsume(Field &ally, Field &enemy, Card *src);

    inline bool hasDeathwish() const { return _onDestroy != nullptr; }
    inline bool hasOnAllyApplyEffect() const { return _onAllyAppliedRowEffect != nullptr; }
    template <typename T> T *stateAs() { return static_cast<T *>(state); }

public:
    Card(const Card &card) = default;
    Card(Card &&card) = default;
    Card &operator=(Card &&card) = default;
    Card &operator=(const Card &card) = default;

public:
    using Self = Card;
    using Constructor = std::function<Card *()>;
    using AllyEnemyRowAndPos = std::function<void(Self *, Field &, Field &, const RowAndPos &)>;
    using CardAllyEnemy = std::function<void(Self *, Card *, Field &, Field &)>;
    using CardAllyEnemyRowAndPos = std::function<void(Self *, Card *, Field &, Field &, const RowAndPos &)>;
    using AllyEnemy = std::function<void(Self *, Field &, Field &)>;
    using IntAllyEnemy = std::function<void(Self *, const int, Field &, Field &)>;
    using AllyEnemyCardSrc = std::function<void(Self *, Field &, Field &, Card *, const Card *)>;
    using AllyEnemySrc = std::function<void(Self *, Field &, Field &, const Card *)>;
    using AllyEnemySrcChangable = std::function<void(Self *, Field &, Field &, Card *)>;
    using IntAllyEnemySrc = std::function<void(Self *, const int, Field &, Field &, const Card *)>;
    using AllyEnemyInt = std::function<void(Self *, Field &, Field &, const int)>;
    using RowEffectAllyEnemyRow = std::function<void(Self *, const RowEffect, Field &, Field &, const Row)>;
    using AllyEnemySrcPowerChangeType = std::function<void(Self *, Field &, Field &, const Card *src, const PowerChangeType)>;
    Constructor _constructor = nullptr;
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
    AllyEnemy _onAllyPass = nullptr;
    AllyEnemy _onRoundLose = nullptr;
    AllyEnemyInt _onTargetRowChoosen = nullptr;
    IntAllyEnemy _onBoost = nullptr;
    AllyEnemySrc _onRevealed = nullptr;
    AllyEnemyCardSrc _onOtherRevealed = nullptr;
    IntAllyEnemySrc _onDamaged = nullptr;
    IntAllyEnemySrc _onWeakened = nullptr;
    CardAllyEnemy _onOtherEnemyDamaged = nullptr;
    CardAllyEnemy _onTargetChoosen = nullptr;
    CardAllyEnemy _onOptionChoosen = nullptr;
    CardAllyEnemy _onOtherEnemyDestroyed = nullptr;
    CardAllyEnemy _onOtherAllyPlayedFromHand = nullptr;
    CardAllyEnemy _onOtherAllyDiscarded = nullptr;
    CardAllyEnemy _onOtherAllyAppears = nullptr;
    CardAllyEnemy _onOtherEnemyAppears = nullptr;
    CardAllyEnemy _onOtherSpyAppears = nullptr;
    CardAllyEnemy _onOtherEnemyPlayedFromHand = nullptr;
    CardAllyEnemy _onOtherAllyResurrecteded = nullptr;
    CardAllyEnemy _onSpecialPlayed = nullptr;
    CardAllyEnemy _onAllySpecialPlayed = nullptr;
    CardAllyEnemy _onEnemyMoved = nullptr;
    RowEffectAllyEnemyRow _onAllyAppliedRowEffect = nullptr;
    AllyEnemySrcChangable _onConsumed = nullptr;
    AllyEnemySrcChangable _onAllyConsume = nullptr;
    AllyEnemySrcPowerChangeType _onPowerChanged = nullptr;
};


struct Error : std::runtime_error
{
    enum Code
    {
        Assert,
        Unreachable,
        ChoosenIsNullptr,
    };
    Error(
            const Code code,
            const Card *card,
            const char *message = nullptr) :
        std::runtime_error(message)
    {}
};


/// The Choice:
///     1) rows, rowFilters, adjacent = 0|1
///     2) options, nTargets, nWindow (Shupe), isOptional
///     3) create, filters, isOptional
///     4) variants (spawnOptions), which are card play variants. same as create btw, but not 3 options
///     5) target, filters, group, nTargets, isOptional
///     6) target, filters, options, nTargets, isOptional


using Filters = std::vector<std::function<bool(Card *)> >;
using RowFilters = std::vector<std::function<bool(const std::vector<Card *> &)>>;


struct Choice
{
    ChoiceType type = CardTarget;
    Card *src = nullptr;
    std::vector<Card *> options;
    std::vector<Card *> optionsSelected;
    Field *fieldPtrAlly = nullptr;
    Field *fieldPtrEnemy = nullptr;
    ChoiceGroup group = AnyBoard;
    Filters filters;
    int nTargets = 1;
    int nWindow = -1;
    bool isOptional = false;
    std::vector<int> screenRows;
    RowFilters screenRowFilters;
};

class CardStack
{
public:
    bool isEmpty() const;
    /// add a choice to the top of queue (resolves first)
    void push(const Choice &choice);
    /// return a next choice, while removing it from a stack
    Choice take();
    /// same as take, but doesn't remove. Must be used by views, etc
    Choice peek() const;
    /// TODO: make tests for it
    /// call tryAutoResolveTopChoice
    void expandNextChoiceAndTryResolveIt();
    /// friend for tests
    const std::vector<Choice> &stack() const { return _stack; }
    using Iterator = std::vector<Choice>::iterator;
    Iterator begin() { return _stack.begin(); }
    Iterator end() { return _stack.end(); }
    void trace() const;
    /// if set, options w/ 1 obvious choice are still not removed
    /// and can be decided by a player himself. options w/ zero
    /// options are still can be autoresolved and removed
    bool isRemovingExpandedChoice = true;
private:
    /// returns true if removed a first choice
    bool tryAutoResolveTopChoice();
    std::vector<Choice> _stack;
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
    CardStack cardStack2;
    /// cards played in order for history
    /// and retrograde effects
    std::vector<Card *> cardsAppearedBoth;
    std::vector<Card *> cardsAppeared;
    // FIXME: tmp solution. remove it with paired ally,
    // enemy. Replace it with proxy field implementation!
    std::vector<Card *> cardsAll;
    int nTurns = 0;
    int nRounds = 0;
    int nWins = 0;
    int nSwaps = 0;
    bool passed = false;
    bool canPass = true;
    bool isMyTurn = false;

    Rng rng;

    std::vector<FieldView> snapshots;

    RowAndPos lastPosInARow(const Row _row) const;
    const std::vector<Card *> &row(const Row _row) const;
    std::vector<Card *> &row(const Row _row);
    RowEffect &rowEffect(const Row _row);
    RowEffect rowEffect(const Row _row) const;
};


int powerField(const Field &field);
int powerRow(const std::vector<Card *> &vector);
bool isIn(const Card *card, const std::vector<Card *> &vector);
bool isOnBoard(const Card *card, const Field &field);
bool hasTag(const Card *card, const Tag tag);
bool isRowFull(const std::vector<Card *> &row);
bool isOkRowAndPos(const RowAndPos &rowAndPos, const Field &field);
Card *cardAtRowAndPos(const Row row, const Pos pos, const Field &field);
Card *cardNextTo(const Card *card, const Field &ally, const Field &enemy, const int offset);
RowAndPos _findRowAndPos(const Card *card, const Field &field);
int _findScreenRow(const Card *card, const Field &ally, const Field &enemy);
RowAndPos rowAndPosToTheRight(const Card *card, const Field &field, const int offset);
RowAndPos rowAndPosToTheLeft(const Card *card, const Field &field, const int offset);
RowAndPos rowAndPosLastInExactRow(const Field &field, const Row row);
RowAndPos rowAndPosLastInExactRow(const int screenRow, const Field &ally, const Field &enemy);
RowAndPos rowAndPosLastInTheOppositeRow(const Card *card, const Field &ally, const Field &enemy);
RowAndPos rowAndPosLastInTheSameRow(const Card *card, const Field &field);
//RowAndPos rowAndPosLastInExactRow(const Field &field);
RowAndPos rowAndPosRandom(Field &field);
Row fromScreenRow(const int screenRow, bool &isAlly);
int toScreenRow(const Row row, const bool isAlly);

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
void startDemo(Field &ally, Field &enemy, const bool hasEnemyPassed = true, const bool canAllyPass = false);
void shuffle(std::vector<Card *> &cards, Rng &rng);
std::vector<Card *> randoms(const std::vector<Card *> &cards, const int nRandoms, Rng &rng);
Card *random(const std::vector<Card *> &cards, Rng &rng);
std::string randomSound(const Card *card, Rng &rng);
RowEffect randomHazardEffect(Rng &rng);
bool hasNoDuplicates(const std::vector<Card *> &cards);
bool hasExactTwoDuplicatesOfBronze(const std::vector<Card *> &cards);
RowEffect rowEffectUnderUnit(const Card* card, const Field &field);
RowEffect rowEffectInSreenRow(const Field &ally, const Field &enemy, const int screenRow);

/// find a place of a card in the field. returns false if non found
bool _findRowAndPos(const Card *card, const Field &field, Row &row, Pos &pos);

/// put a non-special card on exact place, then resolve it enter abilities, then resolve others' otherEnter abilities
bool _putOnField(Card *card, const RowAndPos &rowAndPos, Field &ally, Field &enemy, const bool triggerDeploy, const Card *src);

/// put any card to discard
void putToDiscard(Card *card, Field &ally, Field &enemy, const Card *src, const bool triggerDeathwish = true);

void putToDeck(Card *card, Field &ally, Field &enemy, const DeckPos deckPos, const Card *src);

/// resolve a special card ability, then resolve others' otherPlaySpecial abilities
void _activateSpecial(Card *card, Field &ally, Field &enemy, const Card *src);

void playExistedCard(Card *card, Field &ally, Field &enemy, const Card *src);
/// spawn in a place or move from row to row
// BUG: doesn't work with the same row (move from row X to itself)
bool moveExistedUnitToPos(Card *card, const RowAndPos &rowAndPos, Field &ally, Field &enemy, const Card *src);
bool moveToRandomRow(Card *card, Field &ally, Field &enemy, const Card *src);
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
/// NOTE: given target card will be deleted
void transform(Card *card, Card *target, Field &ally, Field &enemy, const Card *src);
void heal(Card *card, Field &ally, Field &enemy, const Card *src);
void heal(Card *card, const int x, Field &ally, Field &enemy, const Card *src);
/// always takes bigger half. 1 of 1, 2 of 3, 3 of 5, etc
int half(const int x);
void reset(Card *card, Field &ally, Field &enemy, const Card *src);
///// NOTE: only for non-card resetings
void resetPower(Card *card, Field &ally, Field &enemy, const Card *src);
void removeAllStatuses(Card *card, Field &ally, Field &enemy, const Card *src);
void putToHand(Card *card, Field &ally, Field &enemy, const Card *src);
void boost(Card *card, const int x, Field &ally, Field &enemy, const Card *src);
void strengthen(Card *card, const int x, Field &ally, Field &enemy, const Card *src);
bool weaken(Card *card, const int x, Field &ally, Field &enemy, const Card *src);
void gainArmor(Card *card, const int x, Field &ally, Field &enemy, const Card *src);
bool drawACard(Field &ally, Field &enemy, const Card *src);
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
Card *createOption(const Card *card, const int optionInd);
int isOption(const Card *card, const int optionInd);

std::vector<Card *> cardsFiltered(Field &ally, Field &enemy, const Filters &filters, const ChoiceGroup group);
void startChoiceToSelectRow(Field &ally, Field &enemy, Card *self, const std::vector<int> &screenRowsOptions = {0, 1, 2, 3, 4, 5}, const RowFilters &rowFilters = {});
/// if nWindow > 0, then its a random shuffled options out of all givne options. Mainly for create / Shupe abilities
void startChoiceToSelectOption(Field &ally, Field &enemy, Card *src, const std::vector<Card *> &options, const int nTargets = 1, const int nWindow = -1, const bool isOptional = false);
void startChoiceCreateOptions(Field &ally, Field &enemy, Card *src, const Filters &filters = {}, const ChoiceGroup group = AnyCard, const int nWindow = 3, const bool isOptional = false);
void startChoiceToTargetCard(Field &ally, Field &enemy, Card *src, const Filters &filters = {}, const ChoiceGroup group = AnyBoard, const int nTargets = 1, const bool isOptional = false);
void startChoiceToTargetCard(Field &ally, Field &enemy, Card *src, const std::vector<Card *> &options, const int nTargets = 1, const bool isOptional = false);
/// may result in autopass, cause instantly ties autoresolve
void startChoiceRoundStartPlay(Field &ally, Field &enemy);
void startChoiceRoundStartSwap(Field &ally, Field &enemy);
void tryStartRoundAfterSwap(Field &ally, Field &enemy);

void onChoiceDoneCard(Card *card, Field &ally, Field &enemy);
void onChoiceDoneRowAndPlace(const RowAndPos &_findRowAndPos, Field &ally, Field &enemy);
void onChoiceDoneRow(const int screenRow, Field &ally, Field &enemy);
void onChoiceDoneRoundStartSwap(Card *card, Field &ally, Field &enemy);
void saveFieldsSnapshot(Field &ally, Field &enemy, const ActionType actionType, const Card *src = nullptr, const std::vector<Card *> &dst = {}, const std::string &sound = "", const int value = -1, const ActionType actionTypeEnemy = Invalid);
/// returns false when no choice left (game end)
void tryFinishTurn(Field &ally, Field &enemy);

/// value computation
std::map<const Card *, int> optionToGap(const Field &ally, const Field &enemy);

#endif // CARD_H
