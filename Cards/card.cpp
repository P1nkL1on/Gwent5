#include "card.h"

#include <assert.h>
#include <climits>
#include <iostream>
#include <algorithm>
#include <map>

#include "archieve.h"
#include "filters.h"

using Rows = std::vector<std::vector<Card *>>;

bool isRowFull(const std::vector<Card *> &row)
{
    return row.size() >= 9;
}

bool isIn(const Card *card, const std::vector<Card *> &vector)
{
    for (Card *_card : vector)
        if (_card == card)
            return true;

    return false;
}

bool hasTag(const Card *card, const Tag tag)
{
    for (const Tag _tag : card->tags)
        if (_tag == tag)
            return true;

    return false;
}

Row takeCard(const Card *card, Field &ally, Field &enemy, Pos *pos, bool *isAlly)
{
    const std::vector<std::vector<Card *> *> cards {
        &ally.rowMeele,
        &ally.rowRange,
        &ally.rowSeige,
        &ally.hand,
        &ally.deck,
        &ally.discard,
        &enemy.rowMeele,
        &enemy.rowRange,
        &enemy.rowSeige,
        &enemy.hand,
        &enemy.deck,
        &enemy.discard
    };
    for (size_t i = 0; i < cards.size(); ++i) {
        std::vector<Card *> *_cards = cards[i];
        for (size_t j = 0; j < _cards->size(); ++j)
            if (_cards->at(j) == card) {
                _cards->erase(_cards->begin() + int(j));
                if (isAlly != nullptr)
                    *isAlly = i < 6;
                if (pos != nullptr)
                    *pos = Pos(j);
                return Row(i % 6);
            }
    }
    if (ally.leader == card) {
        ally.leader = nullptr;
        if (isAlly != nullptr)
            *isAlly = true;
        return HandLeader;
    }
    if (enemy.leader == card) {
        enemy.leader = nullptr;
        if (isAlly != nullptr)
            *isAlly = false;
        return HandLeader;
    }
    /// assume, that all cards, that weren't
    /// previously anywhere, were already created
    return AlreadyCreated;
}

/// return filter: `can be manually selected`
/// pass self (card source), if any
Filters canBeSelected(Card *self, const Field &ally, const Field &enemy)
{
    return Filters{
        [self, &ally, &enemy](Card *card) {
            if (card == self)
                return false;
            const bool _isOnBoard = isOnBoard(card, ally) || isOnBoard(card, enemy);
            const bool _canBeSelectedOnBoard = !card->isImmune && !card->isAmbush;
            return !_isOnBoard || _canBeSelectedOnBoard;
        },
    };
}

/// return filter: `must be counted to count row(field) power`
Filters canBeCount()
{
    return Filters{
        [](Card *card) {
            return !card->isAmbush;
        },
    };
}

void triggerRowEffects(Field &ally, Field &enemy)
{
    const auto applyRowEffect = [&](const std::vector<Card *> &row, const RowEffect effect) {
        const std::vector<Card *> rowFiltered = _filtered(canBeCount(), row);
        switch (effect) {
        case TorrentialRainEffect:
            for (Card *card : randoms(rowFiltered, 2, ally.rng))
                damage(card, 1, ally, enemy, nullptr);
            break;
        case BitingFrostEffect:
            if (Card *target = lowest(rowFiltered, ally.rng)) {
                // NOTE: 132310 is a WildHuntRider
                const size_t n = cardsFiltered(ally, enemy, {isOnOppositeRow(&ally, &enemy, target), isCopy("132310"), isNotLocked}, EnemyBoard).size();
                damage(target, 2 + int(n), ally, enemy, nullptr);
            }
            break;
        case KorathiHeatwaveEffect:
            if (Card *target = lowest(rowFiltered, ally.rng))
                damage(target, 2, ally, enemy, nullptr);
            break;
        case RaghNarRoogEffect:
        case ImpenetrableFogEffect:
            if (Card *target = highest(rowFiltered, ally.rng))
                damage(target, 2, ally, enemy, nullptr);
            break;
        case GoldenFrothEffect:
            for (Card *target : randoms(rowFiltered, 2, ally.rng))
                boost(target, 1, ally, enemy, nullptr);
            break;
        case SkelligeStormEffect: {
            Card *targetFirst  = (row.size() >= 1) && (!row[0]->isAmbush) ? row[0] : nullptr;
            Card *targetSecond = (row.size() >= 2) && (!row[1]->isAmbush) ? row[1] : nullptr;
            Card *targetThird  = (row.size() >= 3) && (!row[2]->isAmbush) ? row[2] : nullptr;
            if (targetFirst != nullptr)
                damage(targetFirst, 2, ally, enemy, nullptr);
            if (targetSecond != nullptr)
                damage(targetSecond, 1, ally, enemy, nullptr);
            if (targetThird != nullptr)
                damage(targetThird, 1, ally, enemy, nullptr);
            break;
        }
        case FullMoonEffect: {
            const std::vector<Card *> beastOrVampire = _filtered({[](Card *card){ return !card->isAmbush && (hasTag(card, Beast) || hasTag(card, Vampire)); }}, row);
            if (Card *target = random(beastOrVampire, ally.rng))
                boost(target, 2, ally, enemy, nullptr);
            break;
        }
        case BloodMoonEffect:
            break;
        case PitTrapEffect:
            break;
        case DragonsDreamEffect:
            break;
        case NoRowEffect:
            break;
        }
    };
    applyRowEffect(ally.rowMeele, ally.rowEffectMeele);
    applyRowEffect(ally.rowRange, ally.rowEffectRange);
    applyRowEffect(ally.rowSeige, ally.rowEffectSeige);
}

void initField(const std::vector<Card *> &deckStarting, Card *leader, Field &field)
{
    if (field.leaderStarting != nullptr)
        delete field.leaderStarting;
    for (Card *card : field.deckStarting)
        delete card;
    for (Card *card : field.cardsAdded)
        delete card;

    /// clear all the current stuff
    field.rowMeele = std::vector<Card *>();
    field.rowRange = std::vector<Card *>();
    field.rowSeige = std::vector<Card *>();
    field.hand = std::vector<Card *>();
    field.deck = std::vector<Card *>();
    field.discard = std::vector<Card *>();
    field.cardsAppeared = std::vector<Card *>();
    field.cardsAppearedBoth = std::vector<Card *>();
    field.leader = nullptr;

    field.cardStack2 = CardStack();
    field.snapshots = std::vector<FieldView>();
    field.nTurns = 0;
    field.nRounds = 0;
    field.nWins = 0;
    field.nSwaps = 0;
    field.passed = false;
    field.canPass = true;

    /// init a deck
    field.deck = field.deckStarting = deckStarting;
    field.cardsAdded = std::vector<Card *>();
    field.leaderStarting = field.leader = leader;
    field.rowEffectMeele = NoRowEffect;
    field.rowEffectRange = NoRowEffect;
    field.rowEffectSeige = NoRowEffect;

    /// shuffle a deck
    shuffle(field.deck, field.rng);
}

void startNextRound(Field &ally, Field &enemy)
{
    /// assert no choices left
    assert(ally.cardStack2.isEmpty());
    assert(enemy.cardStack2.isEmpty());
    /// check winners:
    /// if prev round wasn't first, and no winner already, then check it
    if (ally.nWins == 2 || enemy.nWins == 2)
        return;

    /// if any rounds was already, count a winner
    if (ally.nRounds) {
        const int nPowerAlly = powerField(ally);
        const int nPowerEnemy = powerField(enemy);
        const bool isLoosing = nPowerAlly < nPowerEnemy;
        const bool isTied = nPowerAlly == nPowerEnemy;
        if (isLoosing) {
            enemy.nWins++;
            ally.isMyTurn = false;
            enemy.isMyTurn = true;
            saveFieldsSnapshot(ally, enemy, WonRoundEnemy, nullptr, {}, "", ally.nRounds, WonRoundAlly);
            for (Card *card : cardsFiltered(ally, enemy, {}, AllyBoard))
                card->onRoundLose(ally, enemy);
        } else if (isTied) {
            ally.nWins++;
            enemy.nWins++;
            ally.isMyTurn = !ally.isMyTurn;
            enemy.isMyTurn = !enemy.isMyTurn;
            saveFieldsSnapshot(ally, enemy, WonRoundBoth, nullptr, {}, "", ally.nRounds);
        } else {
            ally.nWins++;
            ally.isMyTurn = true;
            enemy.isMyTurn = false;
            saveFieldsSnapshot(ally, enemy, WonRoundAlly, nullptr, {}, "", ally.nRounds, WonRoundEnemy);
            for (Card *card : cardsFiltered(ally, enemy, {}, EnemyBoard))
                card->onRoundLose(enemy, ally);
        }
        if (ally.nWins == 2 && enemy.nWins == 2) {
            saveFieldsSnapshot(ally, enemy, WonGameBoth);
            return;
        }
        if (ally.nWins == 2) {
            saveFieldsSnapshot(ally, enemy, WonGameAlly, nullptr, {}, "", -1, WonGameEnemy);
            return;
        }
        if (enemy.nWins == 2) {
            saveFieldsSnapshot(ally, enemy, WonGameEnemy, nullptr, {}, "", -1, WonGameAlly);
            return;
        }

        /// clean all the mess from previous round
        for (const Row row : std::vector<Row>{Meele, Range, Seige}) {
            ally.rowEffect(row) = NoRowEffect;
            enemy.rowEffect(row) = NoRowEffect;

            const auto cleanRow = [&ally, &enemy](const std::vector<Card *> &cards) {
                for (Card *card : cards) {
                    if (card->isResilient) {
                        card->isResilient = false;
                        resetPower(card, ally, enemy, nullptr);
                        continue;
                    }
                    if (card->isDoomed) {
                        banish(card, ally, enemy, nullptr);
                        continue;
                    }

                    putToDiscard(card, ally, enemy, nullptr, false);
                }
            };
            cleanRow(ally.row(row));
            cleanRow(enemy.row(row));
        }
    } else {
        ///determine an order of playing by random
        // FIXME: tmp disabled, always ally start
        ally.isMyTurn = true;
        enemy.isMyTurn = false;
    }

    /// start next round
    ally.nRounds++;
    ally.nTurns = 0;
    ally.passed = false;

    enemy.nRounds++;
    enemy.nTurns = 0;
    enemy.passed = false;

    saveFieldsSnapshot(ally, enemy, RoundStart, nullptr, {}, "", ally.nRounds);

    // add a draw and mulligan step
    int nDraw = 0;
    int nSwap = 0;
    if (ally.nRounds == 1) {
        nDraw = 10;
        nSwap = 3;
    } else if (ally.nRounds == 2) {
        nDraw = 2;
        nSwap = 1;
    } else if (ally.nRounds == 3) {
        nDraw = 1;
        nSwap = 1;
    } else {
        assert(false);
    }

    while (nDraw--) {
        drawACard(ally, enemy, nullptr);
        drawACard(enemy, ally, nullptr);
    }

    ally.nSwaps = nSwap;
    enemy.nSwaps = nSwap;
    startChoiceRoundStartSwap(ally, enemy);
    startChoiceRoundStartSwap(enemy, ally);
}

void shuffle(std::vector<Card *> &cards, Rng &rng)
{
    std::shuffle(std::begin(cards), std::end(cards), rng);
}

std::vector<Card *> randoms(const std::vector<Card *> &cards, const int nRandoms, Rng &rng)
{
    std::vector<Card *> res;

    std::vector<Card *> tmp = cards;
    for (int n = 0; n < nRandoms; ++n) {
        if (tmp.size() == 0)
            break;
        const auto ind = rng() % tmp.size();
        res.push_back(tmp[ind]);
        tmp.erase(tmp.begin() + int(ind));
    }

    return res;
}

Card *random(const std::vector<Card *> &cards, Rng &rng)
{
    return first(randoms(cards, 1, rng));
}

void _activateSpecial(Card *card, Field &ally, Field &enemy, const Card *src)
{
    /// reveal the spell at the moment of playing
    /// but not with reveal function to not prok
    /// self and other onReveals
    card->isRevealed = true;

    saveFieldsSnapshot(ally, enemy, PlaySpecial, src, {card}, randomSound(card, ally.rng));

    card->onPlaySpecial(ally, enemy);

    // TODO: others trigger special
    for (Card * other : cardsFiltered(ally, enemy, {otherThan(card)}, AllyAnywhere))
        other->onSpecialPlayed(card, ally, enemy);
    for (Card * other : cardsFiltered(ally, enemy, {otherThan(card)}, EnemyAnywhere))
        other->onSpecialPlayed(card, enemy, ally);

    // DragonsDreamEffect works here
    for (int screenRow = 0; screenRow < 6; screenRow++) {
        if (rowEffectInSreenRow(ally, enemy, screenRow) != DragonsDreamEffect)
            continue;
        const std::vector<Card *> rowFiltered = cardsInRow(ally, enemy, screenRow);
        for (Card *card : rowFiltered)
            damage(card, 4, ally, enemy, nullptr);
        applyRowEffect(ally, enemy, screenRow, NoRowEffect);
    }
}

bool _putOnField(Card *card, const RowAndPos &rowAndPos, Field &ally, Field &enemy, const bool triggerDeploy, const Card *src)
{
    assert(!card->isSpecial);
    if (!isOkRowAndPos(rowAndPos, ally))
        return false;

    const Row row = rowAndPos.row();
    const Pos pos = rowAndPos.pos();
    const Row takenFrom = takeCard(card, ally, enemy);

    switch (rowAndPos.row()) {
    case Meele:
        assert(!isIn(card, ally.rowMeele));
        ally.rowMeele.insert(ally.rowMeele.begin() + pos, card);
        break;

    case Range:
        assert(!isIn(card, ally.rowRange));
        ally.rowRange.insert(ally.rowRange.begin() + pos, card);
        break;

    case Seige:
        assert(!isIn(card, ally.rowSeige));
        ally.rowSeige.insert(ally.rowSeige.begin() + pos, card);
        break;

    default:
        assert(row == Meele || row == Range || row == Seige);
    }

    if (ally.rowEffect(row) == BloodMoonEffect)
        damage(card, 2, ally, enemy, nullptr);

    else if (ally.rowEffect(row) == PitTrapEffect)
        damage(card, 3, ally, enemy, nullptr);

    else if (ally.rowEffect(row) == FullMoonEffect)
        // FIXME: probably not working right
        card->onContactWithFullMoon(ally, enemy);

    if (takenFrom == Meele || takenFrom == Range || takenFrom == Seige) {
        saveFieldsSnapshot(ally, enemy, MoveFromRowToRow, src, {card}, randomSound(card, ally.rng));
        card->onMoveFromRowToRow(ally, enemy);
        for (Card *other : cardsFiltered(ally, enemy, {}, EnemyAnywhere))
            other->onEnemyMoved(card, enemy, ally);
        return true;
    }

    saveFieldsSnapshot(ally, enemy, PutOnField, src, {card}, randomSound(card, ally.rng));

    if (card->isLoyal) {
        if (takenFrom == Deck) {
            if (triggerDeploy)
                card->onDeployFromDeck(ally, enemy);
        } else if (takenFrom == Discard) {
            if (triggerDeploy)
                card->onDeployFromDiscard(ally, enemy);
            for (Card *other : cardsFiltered(ally, enemy, {}, AllyAnywhere))
                other->onOtherAllyResurrecteded(card, ally, enemy);
        } else if (takenFrom == Hand || takenFrom == AlreadyCreated || takenFrom == HandLeader) {
            if (triggerDeploy)
                card->onDeploy(ally, enemy);
            for (Card *other : cardsFiltered(ally, enemy, {}, AllyAnywhere))
                other->onOtherAllyPlayedFromHand(card, ally, enemy);
            for (Card *other : cardsFiltered(ally, enemy, {}, EnemyAnywhere))
                other->onOtherEnemyPlayedFromHand(card, enemy, ally);
        } else
            assert(false);
        for (Card *other : cardsFiltered(ally, enemy, {otherThan(card)}, AllyAnywhere))
            other->onOtherAllyAppears(card, ally, enemy);
        for (Card *other : cardsFiltered(ally, enemy, {otherThan(card)}, EnemyAnywhere))
            other->onOtherEnemyAppears(card, ally, enemy);

    } else {
        spy(card, ally, enemy, card);
        if (takenFrom == Deck) {
            if (triggerDeploy)
                card->onDeployFromDeck(enemy, ally);
        } else if (takenFrom == Discard) {
            if (triggerDeploy)
                card->onDeployFromDiscard(enemy, ally);
            for (Card *other : cardsFiltered(enemy, ally, {}, AllyAnywhere)) // NOTE: maybe should use ..{otherThan(card)}.. when talking about Other Ally/Enemy ?
                other->onOtherAllyResurrecteded(card, enemy, ally);
        } else if (takenFrom == Hand || takenFrom == AlreadyCreated || takenFrom == HandLeader) {
            if (triggerDeploy)
                card->onDeploy(enemy, ally);
        } else
            assert(false);
        for (Card *other : cardsFiltered(ally, enemy, {otherThan(card)}, AllyAnywhere))
            other->onOtherSpyAppears(card, ally, enemy);
        for (Card *other : cardsFiltered(ally, enemy, {otherThan(card)}, EnemyAnywhere))
            other->onOtherSpyAppears(card, enemy, ally);
    }

    // TODO: others trigger enter
    return true;
}

void putToDiscard(Card *card, Field &ally, Field &enemy, const Card *src, const bool triggerDeathwish)
{
    Pos pos;
    bool isAlly;
    const Row takenFrom = takeCard(card, ally, enemy, &pos, &isAlly);
    const bool mayPutOnDiscard = !card->isDoomed && (card->isSpecial || card->powerBase > 0);
    const bool mayTriggerDeathwish = card->powerBase > 0 && triggerDeathwish;

    Field *cardAlly = &ally;
    Field *cardEnemy = &enemy;
    if (!isAlly)
        std::swap(cardAlly, cardEnemy);

    if (!card->isSpecial)
        resetPower(card, ally, enemy, nullptr);

    if (takenFrom == Meele || takenFrom == Range || takenFrom == Seige) {
        assert(!card->isSpecial);
        if (mayPutOnDiscard) {
            cardAlly->discard.push_back(card);
            saveFieldsSnapshot(ally, enemy, Destroyed, src, {card});
        }
        if (mayTriggerDeathwish)
            card->onDestroy(*cardAlly, *cardEnemy, RowAndPos(takenFrom, pos));
        for (Card *other : cardsFiltered(*cardAlly, *cardEnemy, {}, EnemyAnywhere))
            other->onOtherEnemyDestroyed(card, *cardEnemy, *cardAlly);
        for (Card *other : cardsFiltered(*cardAlly, *cardEnemy, {}, AllyAnywhere))
            other->onOtherAllyDestroyed(card, *cardAlly, *cardEnemy, RowAndPos(takenFrom, pos));

    } else if (takenFrom == Hand || takenFrom == Deck) {
        if (mayPutOnDiscard) {
            cardAlly->discard.push_back(card);
            saveFieldsSnapshot(ally, enemy, PutToDiscard, src, {card});
        }
        // NOTE: special for Wolfsbane
        card->onDiscard(*cardAlly, *cardEnemy);
        for (Card *other : cardsFiltered(*cardAlly, *cardEnemy, {}, AllyAnywhere))
            other->onOtherAllyDiscarded(card, *cardAlly, *cardEnemy);
    } else {
        // NOTE: Eithne ability: Discard -> Discard
        assert(takenFrom == AlreadyCreated || takenFrom == Discard);
        if (mayPutOnDiscard) {
            cardAlly->discard.push_back(card);
        }
    }
}

bool _findRowAndPos(const Card *card, const Field &field, Row &row, Pos &pos)
{
    for (const Row _row : std::vector<Row>{Meele, Range, Seige}) {
        const std::vector<Card *> &__row = field.row(_row);
        for (size_t index = 0; index < __row.size(); ++index) {
            if (__row[index] == card) {
                row = _row;
                pos = int(index);
                return true;
            }
        }
    }
    row = Row(-1);
    pos = -1;
    return false;
}

RowAndPos _findRowAndPos(const Card *card, const Field &field)
{
    for (const Row _row : std::vector<Row>{Meele, Range, Seige}) {
        const std::vector<Card *> &__row = field.row(_row);
        for (size_t index = 0; index < __row.size(); ++index)
            if (__row[index] == card)
                return RowAndPos(_row, Pos(index));
    }
    return RowAndPos();
}

int _findScreenRow(const Card *card, const Field &ally, const Field &enemy)
{
    if (isOnBoard(card, ally))
        if (RowAndPos rowAndPos = _findRowAndPos(card, ally))
            return (toScreenRow(rowAndPos.row(), true));
    if (isOnBoard(card, enemy))
        if (RowAndPos rowAndPos = _findRowAndPos(card, enemy))
            return (toScreenRow(rowAndPos.row(), false));
    assert(false);
}

RowAndPos rowAndPosToTheRight(const Card *card, const Field &field, const int offset)
{
    assert(offset > 0);
    const RowAndPos p = _findRowAndPos(card, field);
    return p ? RowAndPos(p.row(), p.pos() + offset) : RowAndPos();
}

RowAndPos rowAndPosToTheLeft(const Card *card, const Field &field, const int offset)
{
    assert(offset > 0);
    const RowAndPos p = _findRowAndPos(card, field);
    return p ? RowAndPos(p.row(), p.pos() + 1 - offset) : RowAndPos();
}

RowAndPos rowAndPosLastInExactRow(const Field &field, const Row row)
{
    return field.lastPosInARow(row);
}

RowAndPos rowAndPosLastInExactRow(const int screenRow, const Field &ally, const Field &enemy)
{
    bool isAlly;
    Row row = fromScreenRow(screenRow, isAlly);
    if (isAlly)
        return ally.lastPosInARow(row);
    return enemy.lastPosInARow(row);
}

RowAndPos rowAndPosLastInTheOppositeRow(const Card *card, const Field &ally, const Field &enemy)
{
    if (const RowAndPos p = _findRowAndPos(card, ally))
        return enemy.lastPosInARow(p.row());
    if (const RowAndPos p = _findRowAndPos(card, enemy))
        return ally.lastPosInARow(p.row());
    return RowAndPos();
}

RowAndPos rowAndPosLastInTheSameRow(const Card *card, const Field &field)
{
    if (const RowAndPos p = _findRowAndPos(card, field))
        return field.lastPosInARow(p.row());
    return RowAndPos();
}

void startChoiceToSelectOption(Field &ally, Field &enemy, Card *src, const std::vector<Card *> &options, const int nTargets, const int nWindow, const bool isOptional)
{
    // TODO: agreagate to function choice
    Choice choice;
    choice.type = CardOption;
    choice.options = options;
    choice.src = src;
    choice.fieldPtrAlly = &ally;
    choice.fieldPtrEnemy = &enemy;
    choice.nTargets = nTargets;
    choice.nWindow = nWindow;
    choice.isOptional = isOptional;

    ally.cardStack2.push(choice);
}

void startChoiceCreateOptions(Field &ally, Field &enemy, Card *src, const Filters &filters, const ChoiceGroup group, const int nWindow, const bool isOptional)
{
    // TODO: agreagate to function choice
    Choice choice;
    choice.type = CardOption;
    choice.src = src;
    choice.fieldPtrAlly = &ally;
    choice.fieldPtrEnemy = &enemy;
    choice.group = group;
    choice.filters = filters;
    choice.nTargets = 1;
    choice.nWindow = nWindow;
    choice.isOptional = isOptional;

    ally.cardStack2.push(choice);
    ally.cardStack2.expandNextChoiceAndTryResolveIt();
}

void startChoiceToTargetCard(Field &ally, Field &enemy, Card *src, const Filters &filters, const ChoiceGroup group, const int nTargets, const bool isOptional)
{
    // TODO: agreagate to function choice
    Choice choice;
    choice.type = CardTarget;
    choice.src = src;
    choice.fieldPtrAlly = &ally;
    choice.fieldPtrEnemy = &enemy;
    choice.group = group;
    choice.filters = filters;
    choice.nTargets = nTargets;
    choice.isOptional = isOptional;

    ally.cardStack2.push(choice);
    ally.cardStack2.expandNextChoiceAndTryResolveIt();
}

void startChoiceToTargetCard(Field &ally, Field &enemy, Card *src, const std::vector<Card *> &options, const int nTargets, const bool isOptional)
{
    // WARNING: this function may contain a buggy behaviour, because
    // it expands before it's time in a choice queue, which is agains #37
    // TODO: agreagate to function choice
    Choice choice;
    choice.type = CardTarget;
    choice.src = src;
    choice.fieldPtrAlly = &ally;
    choice.fieldPtrEnemy = &enemy;
    choice.options = options;
    choice.nTargets = nTargets;
    choice.isOptional = isOptional;

    ally.cardStack2.push(choice);
    ally.cardStack2.expandNextChoiceAndTryResolveIt();
}

void startChoiceToSelectRow(Field &ally, Field &enemy, Card *self, const std::vector<int> &screenRowsOptions, const RowFilters &rowFilters)
{
    // TODO: agreagate to function choice
    Choice choice;
    choice.type = RowSelect;
    choice.screenRows = screenRowsOptions;
    choice.screenRowFilters = rowFilters;
    choice.fieldPtrAlly = &ally;
    choice.fieldPtrEnemy = &enemy;
    choice.src = self;

    ally.cardStack2.push(choice);
}

void onChoiceDoneCard(Card *card, Field &ally, Field &enemy)
{
    const Choice choice = ally.cardStack2.take();

    if (choice.type == CardRoundStartPlay) {
        /// passed
        if (card == nullptr) {
            pass(ally, enemy);
            return;
        }
        assert(choice.nTargets == 1);
        playExistedCard(card, ally, enemy, nullptr);
        return;
    }
    if (choice.type == CardTarget || choice.type == CardOption) {
        Choice choiceNext = choice;
        if (card != nullptr) {
            /// remove a previously selected card
            for (size_t j = 0; j < choiceNext.options.size(); ++j)
                if (choiceNext.options.at(j) == card) {
                    choiceNext.options.erase(choiceNext.options.begin() + int(j));
                    break;
                }
            /// add it to selected cards
            choiceNext.optionsSelected.push_back(card);

            if ((int(choiceNext.optionsSelected.size()) < choiceNext.nTargets) && (choiceNext.options.size() > 0)) {
                ally.cardStack2.push(choiceNext);
                return;
            }
        } else {
            assert(choice.isOptional);
        }

        if (choice.type == CardTarget) {
            for (Card *card : choiceNext.optionsSelected)
                choice.src->onTargetChoosen(card, ally, enemy);
            return;
        }

        if (choice.type == CardOption) {
            for (Card *card : choiceNext.optionsSelected)
                choice.src->onOptionChoosen(card, ally, enemy);

            /// delete other options
            for (Card *card : choiceNext.options)
                delete card;
            return;
        }
    }
    assert(false);
}

void onChoiceDoneRowAndPlace(const RowAndPos &rowAndPos, Field &ally, Field &enemy)
{
    // TODO: moved a card to be placed to the options instead of
    // src. and move src to player/
    const Choice choice = ally.cardStack2.take();

    if (choice.type == RowAndPosAlly) {
        _putOnField(choice.src, rowAndPos, ally, enemy, true, nullptr);
        return;
    }

    if (choice.type == RowAndPosEnemy) {
        _putOnField(choice.src, rowAndPos, enemy, ally, true, nullptr);
        return;
    }

    assert(false);
}

void onChoiceDoneRow(const int screenRow, Field &ally, Field &enemy)
{
    const Choice choice = ally.cardStack2.take();
    assert(choice.type == RowSelect);
    choice.src->onTargetRowChoosen(ally, enemy, screenRow);
}

void onChoiceDoneRoundStartSwap(Card *card, Field &ally, Field &enemy)
{
    const Choice choicePopped = ally.cardStack2.take();
    assert(choicePopped.type == CardRoundStartSwap);

    if (card != nullptr) {
        swapACard(card, ally, enemy, nullptr);
        /// if any swaps left, then retry the choice
        if (--ally.nSwaps)
            return startChoiceRoundStartSwap(ally, enemy);
    }

    return tryStartRoundAfterSwap(ally, enemy);
}

bool isOkRowAndPos(const RowAndPos &rowAndPos, const Field &field)
{
    if (rowAndPos.pos() < 0)
        return false;

    if (rowAndPos.pos() >= 9)
        return false;

    const std::vector<Card *> &_row = field.row(rowAndPos.row());
    return !isRowFull(_row) && (rowAndPos.pos() <= int(_row.size()));
}


Card *cardAtRowAndPos(const Row row, const Pos pos, const Field &field)
{
    if (pos < 0)
        return nullptr;

    const std::vector<Card *> &_row = field.row(row);

    if (size_t(pos) >= _row.size())
        return nullptr;

    return _row[size_t(pos)];
}

Card *cardNextTo(const Card *card, const Field &ally, const Field &enemy, const int offset)
{
    Row row;
    Pos pos;
    if (_findRowAndPos(card, ally, row, pos))
        return cardAtRowAndPos(row, pos + offset, ally);
    if (_findRowAndPos(card, enemy, row, pos))
        return cardAtRowAndPos(row, pos + offset, enemy);
    return nullptr;
}

std::vector<Card *> cardsFiltered(Field &ally, Field &enemy, const Filters &filters, const ChoiceGroup group)
{
    const std::vector<Card *> cards = [&]{
        if (group == AllyBoard)
            return _united(Rows{ally.rowMeele, ally.rowRange, ally.rowSeige});

        if (group == EnemyBoard)
            return _united(Rows{enemy.rowMeele, enemy.rowRange, enemy.rowSeige});

        if (group == AllyHand)
            return ally.hand;

        if (group == AllyDiscard)
            return ally.discard;

        if (group == AllyDeck)
            return ally.deck;

        if (group == AllyDeckStarting)
            return ally.deckStarting;

        if (group == AllyDeckShuffled) {
            std::vector<Card *> deck = ally.deck;
            shuffle(deck, ally.rng);
            return deck;
        }

        if (group == AllyBoardHandDeck)
            return _united(Rows{ally.rowMeele, ally.rowRange, ally.rowSeige, ally.hand, ally.deck});

        if (group == AllyAnywhere)
            return _united(Rows{ally.rowMeele, ally.rowRange, ally.rowSeige, ally.hand, ally.deck, ally.discard});

        if (group == EnemyAnywhere)
            return _united(Rows{enemy.rowMeele, enemy.rowRange, enemy.rowSeige, enemy.hand, enemy.deck, enemy.discard});

        if (group == EnemyHand)
            return enemy.hand;

        if (group == EnemyDeck)
            return enemy.deck;

        if (group == EnemyDeckStarting)
            return enemy.deckStarting;

        // BUG: enemy hand is visible during REVEAL choice
        if (group == EnemyDiscard)
            return enemy.discard;
        if (group == BothDiscard)
            return _united(Rows{ally.discard, enemy.discard});

        // FIXME: enemy hand is visible during REVEAL choice
        // because its a choice
        if (group == AnyHandShuffled) {
            std::vector<Card *> allyHand = ally.hand;
            std::vector<Card *> enemyHand = enemy.hand;
            shuffle(allyHand, ally.rng);
            shuffle(enemyHand, ally.rng);
            return _united(Rows{allyHand, enemyHand});
        }

        if (group == EnemyBoardAndHandRevealed)
            return _united(Rows{enemy.rowMeele, enemy.rowRange, enemy.rowSeige, _filtered({::isRevealed}, enemy.hand)});

        if (group == AllyBoardAndHandRevealed)
            return _united(Rows{ally.rowMeele, ally.rowRange, ally.rowSeige, _filtered({::isRevealed}, ally.hand)});

        if (group == AllyAppeared)
            return ally.cardsAppeared;

        if (group == BothAppeared)
            return ally.cardsAppearedBoth;

        if (group == AnyCard)
            return ally.cardsAll;

        assert(group == AnyBoard);
        return _united(Rows{ally.rowMeele, ally.rowRange, ally.rowSeige, enemy.rowMeele, enemy.rowRange, enemy.rowSeige});
    }();

    return _filtered(filters, cards);
}

std::vector<Card *> highests(const std::vector<Card *> &row)
{
    const std::vector<Card *> rowFiltered = _filtered(canBeCount(), row);

    int powerMax = INT_MIN;
    for (Card *card : rowFiltered)
        powerMax = std::max(card->power, powerMax);

    std::vector<Card *> res;
    for (Card *card : rowFiltered)
        if (card->power == powerMax)
            res.push_back(card);

    return res;
}

Card *highest(const std::vector<Card *> &row, Rng &rng)
{
    std::vector<Card *> res = highests(row);
    if (res.size() == 0)
        return nullptr;

    return res[rng() % res.size()];
}

std::vector<Card *> lowests(const std::vector<Card *> &row)
{
    const std::vector<Card *> rowFiltered = _filtered(canBeCount(), row);

    int powerMin = INT_MAX;
    for (Card *card : rowFiltered)
        powerMin = std::min(card->power, powerMin);

    std::vector<Card *> res;
    for (Card *card : rowFiltered)
        if (card->power == powerMin)
            res.push_back(card);

    return res;
}

Card *lowest(const std::vector<Card *> &row, Rng &rng)
{
    std::vector<Card *> res = lowests(row);
    if (res.size() == 0)
        return nullptr;

    return res[rng() % res.size()];
}

std::vector<Card *> findCopies(const Card *card, const std::vector<Card *> &cards)
{
    std::vector<Card *> res;
    for (Card *_card : cards)
        if (_card->name == card->name)
            res.push_back(_card);

    return res;
}

Card *findCopy(const Card *card, const std::vector<Card *> &cards)
{
    return first(findCopies(card, cards));
}

RowAndPos Field::lastPosInARow(const Row _row) const
{
    assert(_row == Meele || _row == Range || _row == Seige);
    return RowAndPos(_row, Pos(row(_row).size()));
}

const std::vector<Card *> &Field::row(const Row _row) const
{
    switch (_row) {
    case Meele:
        return rowMeele;
    case Range:
        return rowRange;
    case Seige:
        return rowSeige;
    default:
        break;
    }
    assert(_row == Meele || _row == Range || _row == Seige);
    return rowMeele;
}

std::vector<Card *> &Field::row(const Row _row)
{
    switch (_row) {
    case Meele:
        return rowMeele;
    case Range:
        return rowRange;
    case Seige:
        return rowSeige;
    default:
        break;
    }
    assert(_row == Meele || _row == Range || _row == Seige);
    return rowMeele;
}

RowEffect &Field::rowEffect(const Row _row)
{
    switch (_row) {
    case Meele:
        return rowEffectMeele;
    case Range:
        return rowEffectRange;
    case Seige:
        return rowEffectSeige;
    default:
        break;
    }
    assert(_row == Meele || _row == Range || _row == Seige);
    return rowEffectMeele;
}

RowEffect Field::rowEffect(const Row _row) const
{
    switch (_row) {
    case Meele:
        return rowEffectMeele;
    case Range:
        return rowEffectRange;
    case Seige:
        return rowEffectSeige;
    default:
        break;
    }
    assert(_row == Meele || _row == Range || _row == Seige);
    return rowEffectMeele;
}

bool drawACard(Field &ally, Field &enemy, const Card *src)
{
    if (ally.deck.size() == 0)
        return false;

    putToHand(ally.deck.front(), ally, enemy, src);
    return true;
}

void swapACard(Card *card, Field &ally, Field &enemy, const Card *src)
{
    // assert is in hand
    assert(isIn(card, ally.hand) || isIn(card, enemy.hand));

    if (ally.deck.size() == 0) {
        card->onSwap(ally, enemy);
        card->onDraw(ally, enemy);
        // TODO: trigger all others onSwap abilities
        // TODO: trigger all others onDrawn abilities
        return;
    }

    putToDeck(card, ally, enemy, DeckPosRandomButNotFirst, src);

    const bool drawn = drawACard(ally, enemy, nullptr);
    assert(drawn);
    card->onDraw(ally, enemy);
}

void banish(Card *card, Field &ally, Field &enemy, const Card *src)
{
    const Row row = takeCard(card, ally, enemy);
    saveFieldsSnapshot(ally, enemy, Banished, src, {card});
    assert(row != AlreadyCreated);
}

bool duel(Card *first, Card *second, Field &ally, Field &enemy)
{
    assert(!first->isSpecial);
    assert(!second->isSpecial);

    while (true) {
        if (damage(second, first->power, ally, enemy, first))
            return true;
        if (damage(first, second->power, ally, enemy, second))
            return false;
    }
}

bool damage(Card *card, const int x, Field &ally, Field &enemy, const Card *src)
{
    assert(x > 0);
    assert(!card->isSpecial);

    int dmgInPower = x;

    if (card->armor > 0) {
        const int dmgInArmor = std::min(card->armor, x);
        dmgInPower = std::max(0, x - card->armor);

        card->armor -= dmgInArmor;
        saveFieldsSnapshot(ally, enemy, DamagedInArmor, src, {card}, "", dmgInArmor);

        /// if armor broken, but will survive
        if ((card->armor == 0) && (card->power > dmgInPower)){
            card->onArmorLost(ally, enemy);
        }

        if (dmgInPower == 0)
            return false;
    }
    card->power -= dmgInPower;
    saveFieldsSnapshot(ally, enemy, Damaged, src, {card}, "", dmgInPower);

    // trigger others on damaged (even if destroyed)
    for (Card *other : cardsFiltered(ally, enemy, {}, EnemyBoard))
        other->onOtherEnemyDamaged(card, enemy, ally);

    if (card->power > 0) {
        card->onDamaged(dmgInPower, ally, enemy, src);
        card->onPowerChanged(ally, enemy, src, Damage);
        return false;
    }

    putToDiscard(card, ally, enemy, src);
    return true;
}

void drain(Card *target, const int x, Field &ally, Field &enemy, Card *self)
{
    assert(x > 0);
    assert(!target->isSpecial);
    assert(!self->isSpecial);

    const int powerDrained =  std::min(target->power, x);
    target->power -= powerDrained;
    self->power += powerDrained;
    saveFieldsSnapshot(ally, enemy, Damaged, self, {target}, "", powerDrained);
    saveFieldsSnapshot(ally, enemy, Boosted, self, {self}, "", powerDrained);
    // TODO: trigger other on boosted
    if (target->power > 0) {
        target->onDamaged(powerDrained, ally, enemy, self);
        target->onPowerChanged(ally, enemy, self, Damage);
        // TODO: trigger other on damaged
        return;
    }

    putToDiscard(target, ally, enemy, self);
}

int consume(Card *target, Field &ally, Field &enemy, Card *src)
{
    assert(!target->isSpecial);
    assert(!src->isSpecial);
    const int powerConsumed = target->power;
    target->onConsumed(ally, enemy, src);
    if (isIn(target, ally.discard) || isIn(target, enemy.discard))
        banish(target, ally, enemy, src);
    else
        putToDiscard(target, ally, enemy, src);

    for (Card *card : cardsFiltered(ally, enemy, {}, AllyAnywhere))
        card->onAllyConsume(ally, enemy, src);

    return powerConsumed;
}

void heal(Card *card, Field &ally, Field &enemy, const Card *src)
{
    assert(!card->isSpecial);

    if (card->power < card->powerBase) {
        card->power = card->powerBase;
        saveFieldsSnapshot(ally, enemy, Healed, src, {card});
        card->onPowerChanged(ally, enemy, src, Boost);
    }
}

void heal(Card *card, const int x, Field &ally, Field &enemy, const Card *src)
{
    assert(!card->isSpecial);

    if (card->power < card->powerBase) {
        const int boost = std::min(x, card->powerBase - card->power);
        card->power += boost;
        saveFieldsSnapshot(ally, enemy, HealedBy, src, {card}, "", x);
        card->onPowerChanged(ally, enemy, src, Boost);

        // TODO: check if heal is actually a boost
        // in case of triggers and other stuff.
        // probably, its correct to call `boost` here instead
    }
}

void reset(Card *card, Field &ally, Field &enemy, const Card *src)
{
    assert(!card->isSpecial);


    // TODO: check if need smt else
    // FIXME: fix on class -> function
    assert(false);
    Card *copy = card->exactCopy(); // defaultCopy here is needed

    card->powerBase = copy->powerBase;
    card->power = copy->power;
    card->armor = copy->armor;

    card->isLocked = copy->isLocked;
    card->isSpy = copy->isSpy;
    card->isResilient = copy->isResilient;
    card->isImmune = copy->isImmune;
    card->isDoomed = copy->isDoomed;

    // TODO: check if it produce a correct behevior
    card->tags = copy->tags;
    delete(copy);
    card->onPowerChanged(ally, enemy, src, Reset);
    saveFieldsSnapshot(ally, enemy, ResetAsInDeckBuilder, src, {card});
}

void resetPower(Card *card, Field &ally, Field &enemy, const Card *src)
{
    // NOTE: only for non-card resetings of power - between-rounds and in-game put on discard cases
    card->power = card->powerBase;
    saveFieldsSnapshot(ally, enemy, ResetInPower, src, {card});
}

void removeAllStatuses(Card *card, Field &ally, Field &enemy, const Card *src)
{
    // TODO: determine all the statuses we may clear and replace them here
    card->isSpy = false;
    card->isResilient = false;
    card->isLocked = false;
    card->isImmune = false;
    saveFieldsSnapshot(ally, enemy, StrippedOfAllStatuses, src, {card});
}

void putToHand(Card *card, Field &ally, Field &enemy, const Card *src)
{
    const Row row = takeCard(card, ally, enemy);
    assert(row != Hand);

    /// if drawing, thean leave boosts
    /// otherwise reset power
    if (row != Deck)
        card->power = card->powerBase;

    /// reset a card statuses
    card->isSpy = false;
    card->isResilient = false;
    card->isLocked = false;

    ally.hand.push_back(card);
    saveFieldsSnapshot(ally, enemy, PutToHand, src, {card});

    if (row == Deck) {
        card->onDraw(ally, enemy);

        // TODO: other trigger on draw
    }
}

void boost(Card *card, const int x, Field &ally, Field &enemy, const Card *src)
{
    assert(x > 0);
    assert(!card->isSpecial);

    card->power += x;
    saveFieldsSnapshot(ally, enemy, Boosted, src, {card}, "", x);

    card->onBoost(x, ally, enemy);
    card->onPowerChanged(ally, enemy, src, Boost);

    // TODO: others trigger on boosted
}

void strengthen(Card *card, const int x, Field &ally, Field &enemy, const Card *src)
{
    assert(x > 0);
    assert(!card->isSpecial);

    card->power += x;
    card->powerBase += x;
    saveFieldsSnapshot(ally, enemy, Strengthened, src, {card}, "", x);
    card->onPowerChanged(ally, enemy, src, Boost);

//    ally.snapshots.push_back(new Animation("", Animation::StrengthenText, card));

    // TODO: others trigger on strengthen
}

bool weaken(Card *card, const int x, Field &ally, Field &enemy, const Card *src)
{
    assert(x > 0);
    assert(!card->isSpecial);

    card->power -= x;
    card->powerBase -= x;

    saveFieldsSnapshot(ally, enemy, Weakened, src, {card}, "", x);
//    ally.snapshots.push_back(new Animation("", Animation::WeakenText, card));

    if (card->powerBase <= 0) {
        banish(card, ally, enemy, src);
        return true;
    }

    card->onWeakened(x, ally, enemy, src);
    card->onPowerChanged(ally, enemy, src, Damage);

    return false;
}

void gainArmor(Card *card, const int x, Field &ally, Field &enemy, const Card *src)
{
    assert(x > 0);
    assert(!card->isSpecial);

    card->armor += x;

    saveFieldsSnapshot(ally, enemy, GainArmor, src, {card}, "", x);
}

void tryFinishTurn(Field &ally, Field &enemy)
{
    ally.cardStack2.expandNextChoiceAndTryResolveIt();

    /// can't finish a turn now, choices are to be done.
    /// any btw, they are now correctly expanded
    if (!ally.cardStack2.isEmpty())
        return;

    /// if tryFinishTurn after a pass, if both passed
    /// go to the next round
    if (ally.passed && enemy.passed) {
        startNextRound(ally, enemy);
        return;
    }

    /// finish turn if noone passed
    // BUG: Ronvid on turn end in discard
    for (Card *_card : _united(Rows{ally.rowMeele, ally.rowRange, ally.rowSeige, ally.deck, ally.discard}))
        _card->onTurnEnd(ally, enemy);

    ally.nTurns++;
    saveFieldsSnapshot(ally, enemy, TurnStart, nullptr, {}, "", ally.nTurns);

    // enemy turn
    triggerRowEffects(enemy, ally);

    for (Card *_card : _united(Rows{enemy.rowMeele, enemy.rowRange, enemy.rowSeige, enemy.deck, enemy.discard}))
        _card->onTurnStart(enemy, ally);

    /// skip enemy tun if they passed
    if (enemy.passed)
        return tryFinishTurn(enemy, ally);

    /// give a choice to enemy
    startChoiceRoundStartPlay(enemy, ally);
}

int powerField(const Field &field)
{
    int res = 0;
    const std::vector<Card *> units = _united(Rows{field.rowMeele, field.rowRange, field.rowSeige});
    for (const Card *card : _filtered(canBeCount(), units))
        res += card->power;
    return res;
}

int powerRow(const std::vector<Card *> &vector)
{
    int res = 0;
    for (const Card *card : _filtered(canBeCount(), vector))
        res += card->power;
    return res;
}

Row fromScreenRow(const int screenRow, bool &isAlly)
{
    assert((0 <= screenRow) && (screenRow < 6));
    if (screenRow < 3) {
        isAlly = true;
        return Row(2 - screenRow);
    }
    isAlly = false;
    return Row(screenRow - 3);
}

int toScreenRow(const Row row, const bool isAlly)
{
    switch (row) {
    case Meele:
        return isAlly ? 2 : 3;
    case Range:
        return isAlly ? 1 : 4;
    case Seige:
        return isAlly ? 0 : 5;
    default:
        assert(false);
    }
}

void applyRowEffect(Field &ally, Field &enemy, const int screenRow, const RowEffect rowEffect)
{
    bool isAlly;
    const Row row = fromScreenRow(screenRow, isAlly);
    Field *fieldTargetPtr = isAlly ? &ally : &enemy;

    fieldTargetPtr->rowEffect(row) = rowEffect;

    for (Card *card : cardsFiltered(ally, enemy, {}, AllyAnywhere))
        card->onAllyAppliedRowEffect(rowEffect, ally, enemy, row);

    for (Card *card : fieldTargetPtr->row(row))
        if (rowEffect == BloodMoonEffect)
            damage(card, 2, ally, enemy, nullptr);
        else if (rowEffect == PitTrapEffect)
            damage(card, 3, ally, enemy, nullptr);
}

std::vector<Card *> cardsInRow(Field &ally, Field &enemy, const int screenRow)
{
    bool isAlly;
    const Row row = fromScreenRow(screenRow, isAlly);
    Field *fieldTargetPtr = isAlly ? &ally : &enemy;
    return fieldTargetPtr->row(row);
}

void charm(Card *card, Field &ally, Field &enemy, const Card *src)
{
    Field *allyPtr = &ally;
    Field *enemyPtr = &enemy;

    if (isOnBoard(card, ally))
        /// `card` is alway on `enemyPtr`
        std::swap(allyPtr, enemyPtr);

    if (moveExistedUnitToPos(card, rowAndPosLastInExactRow(*allyPtr, _findRowAndPos(card, *enemyPtr).row()), *allyPtr, *enemyPtr, src))
        spy(card, ally, enemy, card);
}

std::string randomSound(const Card *card, Rng &rng)
{
    /// don't talk, when ambushed
    if (card->sounds.size() == 0 || card->isAmbush)
        return std::string();

    const size_t ind = rng() % card->sounds.size();
    return card->sounds[ind];
}

RowEffect randomHazardEffect(Rng &rng)
{
    return RowEffect(rng() % 9 + 1);
}

bool hasNoDuplicates(const std::vector<Card *> &cards)
{
    std::map<std::string, int> idToCount;
    for (Card *card : cards) {
        auto it = idToCount.find(card->id);
        if (it != idToCount.end())
            return false;
        idToCount.insert({card->id, 1});
    }
    return true;
}

bool hasExactTwoDuplicatesOfBronze(const std::vector<Card *> &cards)
{
    std::map<std::string, int> idToCount;
    for (Card *card : cards) {
        if (card->rarity != Bronze)
            continue;
        auto it = idToCount.find(card->id);
        if (it != idToCount.end()) {
            ++it->second;
        } else {
            idToCount.insert({card->id, 1});
        }
    }

    for (const std::pair<std::string, int> &idAndCount : idToCount)
        if (idAndCount.second != 2)
            return false;

    return true;
}

void clearHazardsFromItsRow(const Card *card, Field &field)
{
    if (const RowAndPos rowAndPos = _findRowAndPos(card, field))
        field.rowEffect(rowAndPos.row()) = NoRowEffect;
}

void clearAllHazards(Field &field, std::vector<Card *> *damagedUnitsUnderHazards)
{
    if (damagedUnitsUnderHazards != nullptr)
        damagedUnitsUnderHazards->clear();

    for (const Row row : std::vector<Row>{ Meele, Range, Seige }) {
        RowEffect &rowEffect = field.rowEffect(row);
        if ((int(rowEffect) > 9) || (rowEffect == NoRowEffect))
            continue;

        if (damagedUnitsUnderHazards != nullptr)
            for (Card *card : field.row(row))
                if (card->power < card->powerBase)
                    damagedUnitsUnderHazards->push_back(card);

        rowEffect = NoRowEffect;
    }
}

void saveFieldsSnapshot(
        Field &ally,
        Field &enemy,
        const ActionType actionType,
        const Card *src,
        const std::vector<Card *> &dst,
        const std::string &sound,
        const int value,
        const ActionType actionTypeEnemy)
{
    const auto pushSnapshot = [=](Field &field, const FieldView &snapshot) {

        for (size_t i = 0; i < field.snapshots.size(); ++i) {
            const size_t j = field.snapshots.size() - 1 - i;

            // if uncollapsable type, then stop it
            // TODO: check what is it...
            const ActionType type = field.snapshots[j].actionType;
            if (type == PlaySpecial
                    || type == PutOnField
                    || type == PassedAlly
                    || type == PassedEnemy
                    || type == WonRoundAlly
                    || type == WonRoundEnemy
                    || type == WonRoundBoth
                    || type == WonGameAlly
                    || type == WonGameEnemy
                    || type == WonGameBoth
                    || type == RoundStart
                    || type == MulliganSkipAlly
                    || type == MulliganSkipEnemy)
                break;

            // find previous snapshot with same animation type and src
            if (field.snapshots[j].actionIdSrc != snapshot.actionIdSrc)
                continue;
            if (field.snapshots[j].actionType != snapshot.actionType)
                continue;
            if (field.snapshots[j].actionValue != snapshot.actionValue)
                continue;

            // try merge
            const std::vector<int> idsPrev = field.snapshots[j].actionIdsDst;
            bool partlySameIdsInPrevAndCurrentSnapshot = false;
            for (const int id : snapshot.actionIdsDst)
                if (std::find(idsPrev.begin(), idsPrev.end(), id) != idsPrev.end()) {
                    partlySameIdsInPrevAndCurrentSnapshot = true;
                    break;
                }
            if (partlySameIdsInPrevAndCurrentSnapshot)
                break;

            field.snapshots[j] = snapshot;
            for (const int id : idsPrev)
                field.snapshots[j].actionIdsDst.push_back(id);

            return;
        }
        field.snapshots.push_back(snapshot);
    };
    FieldView viewAlly = fieldView(ally, enemy, actionType, src, dst, sound, value);
    pushSnapshot(ally, viewAlly);

    const ActionType actionTypeShownToEnemy = actionTypeEnemy == Invalid ? actionType : actionTypeEnemy;
    FieldView viewEnemy = fieldView(enemy, ally, actionTypeShownToEnemy, src, dst, sound, value);
    /// don't show actions of hidden cards to enemy
    bool canShowActionToEnemy = true;
    if (viewEnemy.actionIdSrc >= 0 && !viewEnemy.cardView(viewEnemy.actionIdSrc).isVisible)
        canShowActionToEnemy = false;
    for (const int id : viewEnemy.actionIdsDst)
        if (id >= 0 && !viewEnemy.cardView(id).isVisible)
            canShowActionToEnemy = false;
    const bool showEvenHidden =
            viewEnemy.actionType == PutOnField
            || viewEnemy.actionType == PlaySpecial
            || viewEnemy.actionType == PutToHand
            || viewEnemy.actionType == PutToDiscard;
    if (canShowActionToEnemy || showEvenHidden)
        pushSnapshot(enemy, viewEnemy);
}

bool isOnBoard(const Card *card, const Field &field)
{
    return isIn(card, field.rowMeele) || isIn(card, field.rowRange) || isIn(card, field.rowSeige);
}

void transform(Card *card, Card *target, Field &ally, Field &enemy, const Card *src)
{
    card->transform(target);
    saveFieldsSnapshot(ally, enemy, Transform, src, {card});
}

void toggleLock(Card *card, Field &ally, Field &enemy, const Card *src)
{
    card->isLocked = !card->isLocked;
    saveFieldsSnapshot(ally, enemy, card->isLocked ? GainLock : LostLock, src, {card});
}

void toggleSpy(Card *card, Field &ally, Field &enemy, const Card *src)
{
    card->isSpy = !card->isSpy;
    saveFieldsSnapshot(ally, enemy, card->isSpy ? GainSpy : LostSpy, src, {card});
}

void lock(Card *card, Field &ally, Field &enemy, const Card *src)
{
    if (!card->isLocked)
        toggleLock(card, ally, enemy, src);
}

void spy(Card *card, Field &ally, Field &enemy, const Card *src)
{
    if (!card->isSpy)
        toggleSpy(card, ally, enemy, src);
}

bool tick(Card *card, Field &ally, Field &enemy, const int resetTo)
{
    if (card->timer > 0)
        card->timer--;

    if (card->timer == -1)
        return false;

    if (card->timer > 0) {
        saveFieldsSnapshot(ally, enemy, TimerSet, card, {}, "", card->timer);
        return false;
    }

    card->timer = resetTo;
    saveFieldsSnapshot(ally, enemy, TimerSet, card, {}, "", card->timer);
    return true;
}

void setTimer(Card *card, Field &ally, Field &enemy, const int x)
{
    card->timer = x;
    saveFieldsSnapshot(ally, enemy, TimerSet, card, {}, "", x);
}

void flipOver(Card *card, Field &ally, Field &enemy)
{
    assert(card->isAmbush);
    card->isAmbush = false;
    saveFieldsSnapshot(ally, enemy, FlipOver, card, {}, randomSound(card, ally.rng));
}

RowAndPos rowAndPosRandom(Field &field)
{
    std::vector<Row> hasFreeSpace;
    for (const Row _row : std::vector<Row>{Meele, Range, Seige}) {
        if (isRowFull(field.row(_row)))
            continue;
        hasFreeSpace.push_back(_row);
    }
    if (hasFreeSpace.size() == 0)
        return RowAndPos();

    const Row row = hasFreeSpace[field.rng() % hasFreeSpace.size()];
    const Pos pos = Pos(field.row(row).size());
    return RowAndPos(row, pos);
}

/// cases:
///     play existed unit -> choose a place | discard (if no place)
///     play existed special -> straight run, then discard
///     summon existed unit -> exact position | do nothing if no place
///
///     play new unit -> add to game and choose a place | delete (if no place)
///     summon new unit -> add to game at exact position | do nothing if no place
///     play new special -> add to game and straight run, then discard

void addAsNew(Field &field, Card *card)
{
    assert(std::find(field.cardsAdded.begin(), field.cardsAdded.end(), card) == field.cardsAdded.end());
    assert(std::find(field.deckStarting.begin(), field.deckStarting.end(), card) == field.deckStarting.end());
    assert(card != field.leaderStarting);
    field.cardsAdded.push_back(card);
}

bool canPlay(Card *card, const Field &field)
{
    return card->isSpecial || (!isRowFull(field.rowMeele) || !isRowFull(field.rowRange) || !isRowFull(field.rowSeige));
}

// TODO: test it!
bool playCard2(Card *card, Field &ally, Field &enemy, const Card *src, const bool isNew, const RowAndPos &rowAndPos, const bool triggerDeploy)
{
    // *puts to discard by itself
    const bool play = canPlay(card, card->isLoyal ? ally : enemy);
    if (!play) {
        if (isNew) {
            delete card;
        } else {
            putToDiscard(card, ally, enemy, card);
        }
        return false;
    }
    /// remember it in the stack of played units
    /// TODO: its definetly should be one structure for both player
    ally.cardsAppearedBoth.push_back(card);
    enemy.cardsAppearedBoth.push_back(card);
    ally.cardsAppeared.push_back(card);

    if (isNew)
        addAsNew(ally, card);

    if (card->isSpecial) {
        _activateSpecial(card, ally, enemy, src);
        putToDiscard(card, ally, enemy, card);
        return true;
    }


    if (rowAndPos.row() < 0 && rowAndPos.pos() < 0) {
        /// if no row and pos given, then start rowAndPos selection
        Choice choice;
        choice.type = card->isLoyal ? RowAndPosAlly : RowAndPosEnemy;
        choice.src = card;
        ally.cardStack2.push(choice);
        return true;
    }

    /// if given pos then try set it there
    return _putOnField(card, rowAndPos, ally, enemy, triggerDeploy, src);
}

void playExistedCard(Card *card, Field &ally, Field &enemy, const Card *src)
{
    playCard2(card, ally, enemy, src, false, RowAndPos(), true);
}

bool moveExistedUnitToPos(Card *card, const RowAndPos &rowAndPos, Field &ally, Field &enemy, const Card *src)
{
    return playCard2(card, ally, enemy, src, false, rowAndPos, false);
}

bool moveToRandomRow(Card *card, Field &ally, Field &enemy, const Card *src)
{
    std::vector<Row> possibleRows;
    const Row rowCurrent = _findRowAndPos(card, ally).row();
    if(rowCurrent != Meele && rowCurrent != Range && rowCurrent != Seige)
        return false;

    for (const Row row : std::vector<Row>{Meele, Range, Seige})
        if (row != rowCurrent && !isRowFull(ally.row(row)))
            possibleRows.push_back(row);

    if (possibleRows.size() == 0)
        return false;

    const Row rowNext = possibleRows[ally.rng() % possibleRows.size()];
    const RowAndPos rowAndPosNext(rowNext, Pos(ally.row(rowNext).size()));
    return moveExistedUnitToPos(card, rowAndPosNext, ally, enemy, src);
}

void spawnNewCard(Card *card, Field &ally, Field &enemy, const Card *src)
{
    playCard2(card, ally, enemy, src, true, RowAndPos(), true);
}

bool spawnNewUnitToPos(Card *card, const RowAndPos &rowAndPos, Field &ally, Field &enemy, const Card *src)
{
    return playCard2(card, ally, enemy, src, true, rowAndPos, true);
}

bool summonNewUnitToPos(Card *card, const RowAndPos &rowAndPos, Field &ally, Field &enemy, const Card *src)
{
    return playCard2(card, ally, enemy, src, true, rowAndPos, false);
}

RowAndPos::operator bool() const
{
    return (0 <= _row && _row < 3) && (0 <= _pos && _pos < posMax);
}

RowAndPos::RowAndPos(const Row row, const Pos pos) :
    _row(row), _pos(pos)
{}

Row RowAndPos::row() const
{
    return Row(_row);
}

Pos RowAndPos::pos() const
{
    return _pos;
}

void _copyFields(
        const Field &ally,
        const Field &enemy,
        Field &allyCopy,
        Field &enemyCopy,
        std::map<const Card *, Card *> &origCardToCopyMap)
{
    const auto copyCard = [&](const Card *card) -> Card * {
        if (card == nullptr)
            return nullptr;

        if (origCardToCopyMap.find(card) != origCardToCopyMap.end())
            return origCardToCopyMap[card];

        Card *copy = card->exactCopy();
        origCardToCopyMap[card] = copy;
        return copy;
    };
    const auto copyCards = [&](const std::vector<Card *> &cards) {
        std::vector<Card *> copies;
        for (const Card *card : cards)
            copies.push_back(copyCard(card));
        return copies;
    };

    allyCopy = Field(ally);
    allyCopy.rowMeele = copyCards(ally.rowMeele);
    allyCopy.rowRange = copyCards(ally.rowRange);
    allyCopy.rowSeige = copyCards(ally.rowSeige);
    allyCopy.hand = copyCards(ally.hand);
    allyCopy.deck = copyCards(ally.deck);
    allyCopy.discard = copyCards(ally.discard);
    allyCopy.leader = copyCard(ally.leader);
    allyCopy.leaderStarting = copyCard(ally.leaderStarting);
    allyCopy.deckStarting = copyCards(ally.deckStarting);
    allyCopy.cardsAdded = copyCards(ally.cardsAdded);
    allyCopy.rowMeele = copyCards(ally.rowMeele);
    for (Choice &choice : allyCopy.cardStack2) {
        choice.src = copyCard(choice.src);
        choice.options = copyCards(choice.options);
        choice.optionsSelected = copyCards(choice.optionsSelected);
    }
    enemyCopy = Field(enemy);
    enemyCopy.rowMeele = copyCards(enemy.rowMeele);
    enemyCopy.rowRange = copyCards(enemy.rowRange);
    enemyCopy.rowSeige = copyCards(enemy.rowSeige);
    enemyCopy.hand = copyCards(enemy.hand);
    enemyCopy.deck = copyCards(enemy.deck);
    enemyCopy.discard = copyCards(enemy.discard);
    enemyCopy.leader = copyCard(enemy.leader);
    enemyCopy.leaderStarting = copyCard(enemy.leaderStarting);
    enemyCopy.deckStarting = copyCards(enemy.deckStarting);
    enemyCopy.cardsAdded = copyCards(enemy.cardsAdded);
    enemyCopy.rowMeele = copyCards(enemy.rowMeele);
};

std::map<const Card *, int> optionToGap(const Field &ally, const Field &enemy)
{
    assert(false);
    return {};
//    assert(ally.cardStack.size());

//    /// okey for `Target` and `RoundStartPlay`
//    if (ally.choice().choiceType == CardRoundStartPlay || ally.choice().choiceType == CardTarget) {
//        std::map<const Card *, int> res;
//        for (const Card *_option : ally.choice().cardOptions) {
//            /// copy all the fields to work w/ consts
//            Field allyCopy;
//            Field enemyCopy;
//            std::map<const Card *, Card *> origCardToCopyMap;
//            _copyFields(ally, enemy, allyCopy, enemyCopy, origCardToCopyMap);

//            /// run an option in new proxy copy
//            Card *option = origCardToCopyMap[_option];
//            onChoiceDoneCard(option, allyCopy, enemyCopy);

//            if (allyCopy.cardStack.size() == 0) {
//                const int gapNew = powerField(allyCopy) - powerField(enemyCopy);
//                res.insert({_option, gapNew});
//                continue;
//            }
//            /// if new choice found, then restart in recursion
//            const std::map<const Card *, int> optionToValue = optionToGap(allyCopy, enemyCopy);
//            int gapBest = INT_MIN;
//            for (const auto &it : optionToValue)
//                gapBest = std::max(gapBest, it.second);

//            res.insert({_option, gapBest});
//        }
//        return res;
//    }

//    if (ally.choice().choiceType == RowAndPosAlly || ally.choice().choiceType == RowAndPosEnemy) {
//        std::map<RowAndPos, int> res;
//        for (int i = 0; i < 27; ++i) {
//            const RowAndPos rowAndPos(Row(i / 9), Pos(i % 9));
//            if (ally.choice().choiceType == RowAndPosAlly && !isOkRowAndPos(rowAndPos, ally))
//                continue;
//            if (ally.choice().choiceType == RowAndPosEnemy && !isOkRowAndPos(rowAndPos, enemy))
//                continue;

//            Field allyCopy;
//            Field enemyCopy;
//            std::map<const Card *, Card *> origCardToCopyMap;
//            _copyFields(ally, enemy, allyCopy, enemyCopy, origCardToCopyMap);
//            onChoiceDoneRowAndPlace(rowAndPos, allyCopy, enemyCopy);

//            if (allyCopy.cardStack.size() == 0) {
//                const int gapNew = powerField(allyCopy) - powerField(enemyCopy);
//                res.insert({rowAndPos, gapNew});
//                continue;
//            }
//            /// if new choice found, then restart in recursion
//            const std::map<const Card *, int> optionToValue = optionToGap(allyCopy, enemyCopy);
//            int gapBest = INT_MIN;
//            for (const auto &it : optionToValue)
//                gapBest = std::max(gapBest, it.second);

//            res.insert({rowAndPos, gapBest});
//        }
//        /// find better pos, return it (but w/ itself)
//        int gapBest = 0;
//        for (const auto &it : res)
//            gapBest = std::max(gapBest, it.second);
//        return {{ally.choice().cardSource, gapBest}};
//    }

//    return {};
}

void reveal(Card *card, Field &ally, Field &enemy, const Card *src)
{
    assert(!card->isRevealed);

    card->isRevealed = true;
    saveFieldsSnapshot(ally, enemy, Reveal, src, {card});

    card->onRevealed(ally, enemy, src);

    /// trigger only for allies
    for (Card *other : cardsFiltered(ally, enemy, {}, AllyAnywhere))
        other->onOtherRevealed(ally, enemy, card, src);
}

void conceal(Card *card, Field &ally, Field &enemy, const Card *src)
{
    assert(card->isRevealed);

    saveFieldsSnapshot(ally, enemy, Conceal, src, {card});
    card->isRevealed = false;
}

Card::~Card()
{
    delete state;
}

void Card::onGameStart(Field &ally, Field &enemy)
{
    if (_onGameStart)
        return _onGameStart(this, ally, enemy);
}

void Card::onDeploy(Field &ally, Field &enemy)
{
    if (_onDeploy && !isLocked)
        return _onDeploy(this, ally, enemy);
}

void Card::onDeployFromDiscard(Field &ally, Field &enemy)
{
    if (_onDeployFromDiscard && !isLocked)
        return _onDeployFromDiscard(this, ally, enemy);
    return onDeploy(ally, enemy);
}

void Card::onDeployFromDeck(Field &ally, Field &enemy)
{
    if (_onDeployFromDeck && !isLocked)
        return _onDeployFromDeck(this, ally, enemy);
    return onDeploy(ally, enemy);
}

void Card::onMoveFromRowToRow(Field &ally, Field &enemy)
{
    if (_onMoveFromRowToRow && !isLocked)
        return _onMoveFromRowToRow(this, ally, enemy);
}

void Card::onTurnStart(Field &ally, Field &enemy)
{
    if (_onTurnStart && !isLocked)
        return _onTurnStart(this, ally, enemy);
}

void Card::onTurnEnd(Field &ally, Field &enemy)
{
    if (_onTurnEnd && !isLocked)
        return _onTurnEnd(this, ally, enemy);
}

void Card::onTargetChoosen(Card *card, Field &ally, Field &enemy)
{
    if (_onTargetChoosen && !isLocked)
        return _onTargetChoosen(this, card, ally, enemy);
}

void Card::onOptionChoosen(Card *card, Field &ally, Field &enemy)
{
    if (_onOptionChoosen)
        return _onOptionChoosen(this, card, ally, enemy);
}

void Card::onTargetRowChoosen(Field &ally, Field &enemy, const int screenRow)
{
    if (_onTargetRowChoosen && !isLocked)
        return _onTargetRowChoosen(this, ally, enemy, screenRow);
}

void Card::onDraw(Field &ally, Field &enemy)
{
    if (_onDraw && !isLocked)
        return _onDraw(this, ally, enemy);
}

void Card::onSwap(Field &ally, Field &enemy)
{
    if (_onSwap && !isLocked)
        return _onSwap(this, ally, enemy);
}

void Card::onDiscard(Field &ally, Field &enemy)
{
    if (_onDiscard && !isLocked)
        return _onDiscard(this, ally, enemy);
}

void Card::onDestroy(Field &ally, Field &enemy, const RowAndPos &rowAndPos)
{
    if (_onDestroy && !isLocked)
        return _onDestroy(this, ally, enemy, rowAndPos);
}

void Card::onPlaySpecial(Field &ally, Field &enemy)
{
    if (_onPlaySpecial && !isLocked)
        return _onPlaySpecial(this, ally, enemy);
}

void Card::onBoost(const int x, Field &ally, Field &enemy)
{
    if (_onBoost && !isLocked)
        return _onBoost(this, x, ally, enemy);
}

void Card::onDamaged(const int x, Field &ally, Field &enemy, const Card *src)
{
    if (_onDamaged && !isLocked)
        return _onDamaged(this, x, ally, enemy, src);
}

void Card::onWeakened(const int x, Field &ally, Field &enemy, const Card *src)
{
    if (_onWeakened && !isLocked)
        return _onWeakened(this, x, ally, enemy, src);
}

void Card::onPowerChanged(Field &ally, Field &enemy, const Card *src, const PowerChangeType type)
{
    if (_onPowerChanged && !isLocked)
        return _onPowerChanged(this, ally, enemy, src, type);
}

void Card::onRevealed(Field &ally, Field &enemy, const Card *src)
{
    if (_onRevealed && !isLocked)
        return _onRevealed(this, ally, enemy, src);
}

void Card::onOtherRevealed(Field &ally, Field &enemy, Card *card, const Card *src)
{
    if (_onOtherRevealed && !isLocked)
        return _onOtherRevealed(this, ally, enemy, card, src);
}

void Card::onArmorLost(Field &ally, Field &enemy)
{
    if (_onArmorLost && !isLocked)
        return _onArmorLost(this, ally, enemy);
}

void Card::onContactWithFullMoon(Field &ally, Field &enemy)
{
    if (_onContactWithFullMoon && !isLocked)
        return _onContactWithFullMoon(this, ally, enemy);
}

void Card::onOtherEnemyDamaged(Card *card, Field &ally, Field &enemy)
{
    if (_onOtherEnemyDamaged && !isLocked)
        return _onOtherEnemyDamaged(this, card, ally, enemy);
}

void Card::onOtherEnemyDestroyed(Card *card, Field &ally, Field &enemy)
{
    if (_onOtherEnemyDestroyed && !isLocked)
        return _onOtherEnemyDestroyed(this, card, ally, enemy);
}

void Card::onOtherAllyDiscarded(Card *card, Field &ally, Field &enemy)
{
    if (_onOtherAllyDiscarded && !isLocked)
        return _onOtherAllyDiscarded(this, card, ally, enemy);
}

void Card::onOtherAllyDestroyed(Card *card, Field &ally, Field &enemy, const RowAndPos &rowAndPos)
{
    if (_onOtherAllyDestroyed && !isLocked)
        return _onOtherAllyDestroyed(this, card, ally, enemy, rowAndPos);
}

void Card::onOtherAllyPlayedFromHand(Card *card, Field &ally, Field &enemy)
{
    if (_onOtherAllyPlayedFromHand && !isLocked)
        return _onOtherAllyPlayedFromHand(this, card, ally, enemy);
}

void Card::onOtherAllyAppears(Card *card, Field &ally, Field &enemy)
{
    if (_onOtherAllyAppears && !isLocked)
        return _onOtherAllyAppears(this, card, ally, enemy);
}

void Card::onOtherEnemyAppears(Card *card, Field &ally, Field &enemy)
{
    if (_onOtherEnemyAppears && !isLocked)
        return _onOtherEnemyAppears(this, card, ally, enemy);
}

void Card::onOtherSpyAppears(Card *card, Field &ally, Field &enemy)
{
    if (_onOtherSpyAppears && !isLocked)
        return _onOtherSpyAppears(this, card, ally, enemy);
}

void Card::onOtherEnemyPlayedFromHand(Card *card, Field &ally, Field &enemy)
{
    if (_onOtherEnemyPlayedFromHand && !isLocked)
        return _onOtherEnemyPlayedFromHand(this, card, ally, enemy);
}

void Card::onOtherAllyResurrecteded(Card *card, Field &ally, Field &enemy)
{
    if (_onOtherAllyResurrecteded && !isLocked)
        return _onOtherAllyResurrecteded(this, card, ally, enemy);
}

void Card::onSpecialPlayed(Card *card, Field &ally, Field &enemy)
{
    if (_onSpecialPlayed && !isLocked)
        return _onSpecialPlayed(this, card, ally, enemy);
}

void Card::onEnemyMoved(Card *card, Field &ally, Field &enemy)
{
    if (_onEnemyMoved && !isLocked)
        return _onEnemyMoved(this, card, ally, enemy);
}

void Card::onOpponentPass(Field &ally, Field &enemy)
{
    if (_onOpponentPass && !isLocked)
        return _onOpponentPass(this, ally, enemy);
}

void Card::onAllyPass(Field &ally, Field &enemy)
{
    if (_onAllyPass && !isLocked)
        return _onAllyPass(this, ally, enemy);
}

void Card::onRoundLose(Field &ally, Field &enemy)
{
    if (_onRoundLose && !isLocked)
        return _onRoundLose(this, ally, enemy);
}

void Card::onAllyAppliedRowEffect(const RowEffect rowEffect, Field &ally, Field &enemy, const Row row)
{
    if (_onAllyAppliedRowEffect && !isLocked)
        return _onAllyAppliedRowEffect(this, rowEffect, ally, enemy, row);
}

void Card::onConsumed(Field &ally, Field &enemy, Card *src)
{
    if (_onConsumed && !isLocked)
        return _onConsumed(this, ally, enemy, src);
}

void Card::onAllyConsume(Field &ally, Field &enemy, Card *src)
{
    if (_onAllyConsume && !isLocked)
        return _onAllyConsume(this, ally, enemy, src);
}

Card *Card::exactCopy() const
{
    Card *res = defaultCopy();
    res->power = power;
    res->powerBase = powerBase;
    res->armor = armor;
    res->timer = timer;
    res->isLocked = isLocked;
    res->isSpy = isSpy;
    res->isResilient = isResilient;
    res->isAmbush = isAmbush;
    res->isImmune = isImmune;
    res->isDoomed = isDoomed;
    res->isRevealed = isRevealed;
    res->state = state ? state->exactCopy() : nullptr;
    // NOTE: commented out due to regular cards
    // can't change any of this non-const props
    //    res->rarity = rarity;
    //    res->faction = faction;
    //    res->isLoyal = isLoyal;
    //    res->isSpecial = isSpecial;
    //    res->isCrew = isCrew;
    return res;
}

Card *Card::defaultCopy() const
{
    assert(_constructor);
    return _constructor();
}

void Card::transform(Card *target)
{
    assert(target);
    *this = std::move(*target);
    target->state = nullptr;
    delete target;
}

struct StateOption : StateCopy<StateOption>
{
    int _option = -1;
};


Card *createOption(const Card *card, const int optionInd)
{
    assert(isSpecial);
    assert(card->armor == 0);
    assert(card->timer == 0);
    Card *res = new Card();

    auto *stateOption = new StateOption;
    stateOption->_option = optionInd;
    res->state = stateOption;

    res->power = card->power;
    res->powerBase = card->powerBase;
    res->rarity = card->rarity;
    res->faction = card->faction;
    res->tags = card->tags;
    res->isLoyal = card->isLoyal;
    res->name = card->name;
    res->text = card->text;
    res->url = card->url;
    res->id = card->id;
    res->sounds = card->sounds;
    res->isSpecial = card->isSpecial;
    return res;
}

int isOption(const Card *card, const int optionInd)
{
    assert(card->state);
    return static_cast<StateOption *>(card->state)->_option == optionInd;
}

RowEffect rowEffectUnderUnit(const Card *card, const Field &field)
{
    if (const RowAndPos rowAndPos = _findRowAndPos(card, field))
        return field.rowEffect(rowAndPos.row());
    assert(false);
    return NoRowEffect;
}


RowEffect rowEffectInSreenRow(const Field &ally, const Field &enemy, const int screenRow)
{
    bool isAlly;
    const Row row = fromScreenRow(screenRow, isAlly);
    return isAlly ? ally.rowEffect(row) : enemy.rowEffect(row);
}

std::vector<Card *> firsts(const std::vector<Card *> &cards, const int nFirsts)
{
    std::vector<Card *> res;
    for (size_t ind = 0; ind < std::min(cards.size(), size_t(nFirsts)); ++ind)
        res.push_back(cards[ind]);
    return res;
}

Card *first(const std::vector<Card *> &cards)
{
    return cards.size() ? cards.front() : nullptr;
}

Card *last(const std::vector<Card *> &cards)
{
    return cards.size() ? cards.back() : nullptr;
}

void setPower(Card *card, const int x, Field &ally, Field &enemy, const Card *src)
{
    if (card->power > x) {
        damage(card, card->power - x, ally, enemy, src);
        return;
    }
    if (card->power < x)
        return boost(card, x - card->power, ally, enemy, src);
}

int half(const int x)
{
    return int(std::ceil(x / 2.0));
}

void putToDeck(Card *card, Field &ally, Field &enemy, const DeckPos deckPos, const Card *src)
{
    const Row row = takeCard(card, ally, enemy);
    if (row == Hand)
        // TODO: trigger all others onSwap abilities
        card->onSwap(ally, enemy);
    assert(row != HandLeader);
    switch (deckPos) {
    case DeckPosTop:
        ally.deck.insert(ally.deck.begin(), card);
        saveFieldsSnapshot(ally, enemy, PutToTopDeck, src, {card});
        return;
    case DeckPosBottom:
        ally.deck.push_back(card);
        saveFieldsSnapshot(ally, enemy, PutToBottomDeck, src, {card});
        return;
    case DeckPosRandom: {
        const int ind = int(ally.rng() % (ally.deck.size() + 1));
        ally.deck.insert(ally.deck.begin() + ind, card);
        saveFieldsSnapshot(ally, enemy, ShuffleToDeck, src, {card});
        return;
    }
    case DeckPosRandomButNotFirst: {
        const int ind = 1 + int(ally.rng() % ally.deck.size());
        ally.deck.insert(ally.deck.begin() + ind, card);
        saveFieldsSnapshot(ally, enemy, ShuffleToDeck, src, {card});
        return;
    }
    default:
        assert(false);
    }
}

void pass(Field &ally, Field &enemy)
{
    ally.passed = true;
    saveFieldsSnapshot(ally, enemy, PassedAlly, nullptr, {}, "", -1, PassedEnemy);

    for (Card *card : cardsFiltered(ally, enemy, {}, EnemyBoard))
        card->onOpponentPass(enemy, ally);

    for (Card *card : cardsFiltered(ally, enemy, {}, AllyBoard))
        card->onAllyPass(ally, enemy);
}

int nCrewed(Card *card, Field &ally)
{
    Field _;
    int n = 0;
    if (Card *left = cardNextTo(card, ally, _, -1))
        if (isCrew(left))
            ++n;
    if (Card *right = cardNextTo(card, ally, _, 1))
        if (isCrew(right))
            ++n;
    return n;
}

Choice CardStack::peek() const
{
    assert(_stack.size());
    return _stack.front();
}

Choice CardStack::take()
{
    assert(_stack.size());
    const Choice choice = peek();

    _stack.erase(_stack.begin());

    return choice;
}

void CardStack::expandNextChoiceAndTryResolveIt()
{
    while (tryAutoResolveTopChoice());
}

bool CardStack::isEmpty() const
{
    return !_stack.size();
}

void CardStack::push(const Choice &choice)
{
    _stack.insert(_stack.begin(), choice);
}

void CardStack::trace() const
{
    std::cout << std::endl << "Choice Queue (" << _stack.size() << ")" << std::endl;
    if (_stack.size())
        std::cout << "^ FIRST TO TRIGGER" << std::endl;
    for (size_t i = 0; i < _stack.size(); ++i) {
        std::cout << "| " << i << ". ";
        bool isExpanded = true;
        switch (_stack[i].type) {
        case CardRoundStartPlay: std::cout << "Round Start Play";  isExpanded = _stack[i].options.size() != 0; break;
        case CardRoundStartSwap: std::cout << "Round Start Swap";  isExpanded = _stack[i].options.size() != 0; break;
        case CardTarget:         std::cout << "Card Target";       isExpanded = _stack[i].options.size() != 0; break;
        case CardOption:         std::cout << "Card Option";       isExpanded = _stack[i].options.size() != 0; break;
        case RowAndPosAlly:      std::cout << "Row And Pos Ally";  break;
        case RowAndPosEnemy:     std::cout << "Row And Pos Enemy"; break;
        case RowSelect:          std::cout << "Row";               isExpanded = _stack[i].screenRows.size() != 0; break;
        }
        if (isExpanded)
            std::cout << " (EXPANDED)";
        std::cout << std::endl;
        if (_stack[i].src)
            std::cout << "|    Source:  " << _stack[i].src->name << std::endl;
        if (_stack[i].nTargets > 0)
            std::cout << "|    Targets: " << _stack[i].nTargets << std::endl;
        if (_stack[i].optionsSelected.size())
            std::cout << "|    Selected: " << _stack[i].nTargets << std::endl;
        if (_stack[i].options.size())
            std::cout << "|    Options: " << _stack[i].options.size() << std::endl;
        if (_stack[i].filters.size())
            std::cout << "|    Filters: " << _stack[i].filters.size() << std::endl;
        if (_stack[i].screenRows.size())
            std::cout << "|    Options Rows: " << _stack[i].screenRows.size() << std::endl;
        if (_stack[i].screenRowFilters.size())
            std::cout << "|    Filters Rows: " << _stack[i].screenRowFilters.size() << std::endl;
    }
    if (_stack.size())
        std::cout << "^ LAST" << std::endl;
}

bool CardStack::tryAutoResolveTopChoice()
{
    if (!_stack.size())
        return false;

    Choice &choice = _stack.front();

    if (choice.type == RowSelect) {
        /// expand a choice (filter existed rows)
        std::vector<int> screenRowsRes;
        for (const int screenRow : choice.screenRows) {
            bool isAlly;
            const Row row = fromScreenRow(screenRow, isAlly);
            const std::vector<Card *> cardsInRow = (isAlly ? choice.fieldPtrAlly : choice.fieldPtrEnemy)->row(row);

            bool isOk = true;
            for (const std::function<bool(const std::vector<Card *> &)> &filter : choice.screenRowFilters)
                if (!filter(cardsInRow)) {
                    isOk = false;
                    break;
                }

            if (isOk)
                screenRowsRes.push_back(screenRow);
        }
        choice.screenRows = screenRowsRes;

        /// check if can be auto choosen
        if (choice.screenRows.size() > 1)
            return false;

        if (choice.screenRows.size() == 0) {
            _stack.erase(_stack.begin());
            return true;
        }

        if (!isRemovingExpandedChoice)
            return false;

        /// erase a choice (auto solved) and store its data to exec
        assert(choice.screenRows.size() == 1);
        Card *src = choice.src;
        Field *fieldPtrAlly = choice.fieldPtrAlly;
        Field *fieldPtrEnemy = choice.fieldPtrEnemy;
        const int screenRow = choice.screenRows.at(0);
        _stack.erase(_stack.begin());

        src->onTargetRowChoosen(*fieldPtrAlly, *fieldPtrEnemy, screenRow);
        return true;
    }

    /// if no options in play, then auto pass
    if (choice.type == CardRoundStartPlay) {
        if (choice.options.size() > 0)
            return false;

        onChoiceDoneCard(nullptr, *choice.fieldPtrAlly, *choice.fieldPtrEnemy);
        return true;
    }

    /// if no options in mulligan, then auto finish it
    if (choice.type == CardRoundStartSwap) {
        if (choice.options.size() > 0 && choice.fieldPtrAlly->deck.size())
            return false;

        saveFieldsSnapshot(*choice.fieldPtrAlly, *choice.fieldPtrEnemy, MulliganSkipAlly, nullptr, {}, "", choice.nTargets, MulliganSkipEnemy);
        onChoiceDoneRoundStartSwap(nullptr, *choice.fieldPtrAlly, *choice.fieldPtrEnemy);
        return true;
    }

    // TODO: optimizing row selection
    if (choice.type == RowAndPosAlly || choice.type == RowAndPosEnemy)
        return false;

    /// when no options given (meant a choice must be done in place)
    /// we must assert all the stuff needed to filter existed cards
    /// by `groups`, `filters`, `ally and enemy` and rest
    if (choice.options.size() == 0) {
        assert(choice.fieldPtrAlly != nullptr);
        assert(choice.fieldPtrEnemy != nullptr);
        assert(choice.src != nullptr);
        const std::vector<Card *> filtered = cardsFiltered(*choice.fieldPtrAlly, *choice.fieldPtrEnemy, choice.filters, choice.group);
        choice.options = _filtered(canBeSelected(choice.src, *choice.fieldPtrAlly, *choice.fieldPtrEnemy), filtered);

        /// at this stage, it can left no viable options, anyway.
        /// in this case, or in case number of options match `nTargets`
        /// we can autoresolve the existed choice and remove it.
    }

    /// if `nWindow` given, then apply it
    if (choice.nWindow >= 0 && choice.nWindow < int(choice.options.size())) {
        assert(choice.fieldPtrAlly != nullptr);
        shuffle(choice.options, choice.fieldPtrAlly->rng);
        choice.options = firsts(choice.options, choice.nWindow);
    }

    /// can't resolve, because there are some options
    /// and as well it can be totally cancelled
    if (choice.isOptional && choice.options.size())
        return false;

    /// ambigious choice must be done by player
    /// NOTE: fixed optimizing bug on in the middle of selecting multiple targets
    if (int(choice.options.size() + choice.optionsSelected.size()) > choice.nTargets)
        return false;

    /// don't remove it after expand, if player prefer so
    if (!isRemovingExpandedChoice)
        return false;

    /// store data of choice, because erasing invalidates a reference
    /// remove from queue before resolving it, to not try  autosolve
    /// same choice again, if onTargetChoosen brings new choices to CardStack.
    Card *src = choice.src;
    Field *fieldPtrAlly = choice.fieldPtrAlly;
    Field *fieldPtrEnemy = choice.fieldPtrEnemy;
    const std::vector<Card *> options = choice.options;
    _stack.erase(_stack.begin());

    /// choice can be done automaticly
    assert(choice.type == CardTarget || choice.type == CardOption);
    for (Card *card : options) {
        if (choice.type == CardTarget)
            src->onTargetChoosen(card, *fieldPtrAlly, *fieldPtrEnemy);
        if (choice.type == CardOption)
            src->onOptionChoosen(card, *fieldPtrAlly, *fieldPtrEnemy);
    }
    return true;
}

void startDemo(Field &ally, Field &enemy, const bool hasEnemyPassed, const bool canAllyPass)
{
    enemy.passed = hasEnemyPassed;
    ally.canPass = canAllyPass;
    startChoiceRoundStartPlay(ally, enemy);
}

void startChoiceRoundStartPlay(Field &ally, Field &enemy)
{
    assert(!ally.passed);
    assert(!ally.nSwaps);
    assert(ally.cardStack2.isEmpty());

    // TODO: add leader to hand, move to separate function
    std::vector<Card *> cardsToPlay = ally.hand;
    if (ally.leader != nullptr)
        cardsToPlay.insert(cardsToPlay.begin(), ally.leader);

    Choice choice;
    choice.type = CardRoundStartPlay;
    choice.fieldPtrAlly = &ally;
    choice.fieldPtrEnemy = &enemy;
    choice.options = cardsToPlay;
    choice.nTargets = 1;
    choice.isOptional = ally.canPass;
    ally.cardStack2.push(choice);
    ally.cardStack2.expandNextChoiceAndTryResolveIt();
}

void startChoiceRoundStartSwap(Field &ally, Field &enemy)
{
    assert(ally.nSwaps > 0);
    assert(!ally.passed);

    Choice choice;
    choice.type = CardRoundStartSwap;
    choice.fieldPtrAlly = &ally;
    choice.fieldPtrEnemy = &enemy;
    choice.options = ally.hand;
    choice.nTargets = ally.nSwaps;
    choice.isOptional = true;
    ally.cardStack2.push(choice);
    ally.cardStack2.expandNextChoiceAndTryResolveIt();
}

void tryStartRoundAfterSwap(Field &ally, Field &enemy)
{
    ally.nSwaps = 0;

    /// enemy is still swapping
    if (enemy.nSwaps > 0)
        return;

    Field *firstPtr = &ally;
    Field *secondPtr = &enemy;
    if (enemy.isMyTurn)
        std::swap(firstPtr, secondPtr);

    startChoiceRoundStartPlay(*firstPtr, *secondPtr);
    if (!firstPtr->passed)
        return;

    startChoiceRoundStartPlay(*secondPtr, *firstPtr);
    if (!secondPtr->passed)
        return;

    /// if noone can start a round, go next
    startNextRound(*firstPtr, *secondPtr);
}
