#include "card.h"

#include <assert.h>
#include <iostream>
#include <algorithm>
#include <map>

#include "archieve.h"

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
Filters canBeSelected(Card *self)
{
    return Filters{
        [self](Card *card) {
            return !card->isImmune && !card->isAmbush && (card != self);
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
            Card *targetFirst=   (row.size() >= 1) && (!row[0]->isAmbush) ? row[0] : nullptr;
            Card *targetSecond = (row.size() >= 2) && (!row[1]->isAmbush) ? row[1] : nullptr;
            Card *targetThird =  (row.size() >= 3) && (!row[2]->isAmbush) ? row[2] : nullptr;
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
    assert(field.rowMeele.size() == 0);
    assert(field.rowRange.size() == 0);
    assert(field.rowSeige.size() == 0);
    assert(field.hand.size() == 0);
    assert(field.discard.size() == 0);
    assert(field.cardsAdded.size() == 0);
    assert(field.cardStack.size() == 0);

    /// init a deck
    field.deck = field.deckStarting = deckStarting;
    field.leaderStarting = field.leader = leader;
    field.rowEffectMeele = NoRowEffect;
    field.rowEffectRange = NoRowEffect;
    field.rowEffectSeige = NoRowEffect;
    field.nTurns = 0;

    /// shuffle a deck
    shuffle(field.deck, field.rng);
}

void startNextRound(Field &ally, Field &enemy)
{
    /// if prev round wasn't first, and no winner already, check winners
    if (ally.nWins == 2 || enemy.nWins == 2)
        return;
    if (ally.nRounds) {
        const int nPowerAlly = powerField(ally);
        const int nPowerEnemy = powerField(ally);
        const bool isLoosing = nPowerAlly < nPowerEnemy;
        const bool isTied = nPowerAlly == nPowerEnemy;
        if (isLoosing) {
            enemy.nWins++;
        } else if (isTied) {
            ally.nWins++;
            enemy.nWins++;
        } else {
            ally.nWins++;
        }
        if (ally.nWins == 2 && enemy.nWins == 2)
            return;
        if (ally.nWins == 2)
            return;
        if (enemy.nWins == 2)
            return;
    }
    /// clean all the mess from previous round
    for (const Row row : std::vector<Row>{Meele, Range, Seige}) {
        ally.rowEffect(row) = NoRowEffect;
        enemy.rowEffect(row) = NoRowEffect;

        const std::vector<Card *> rowAlly = ally.row(row);
        for (Card *card : rowAlly)
            if (!card->isResilient) {
                takeCard(card, ally, enemy);
                reset(card, ally, enemy);
                ally.discard.push_back(card);
            } else {
                card->isResilient = false;
                if (card->power > card->powerBase)
                    card->power = card->powerBase;
            }

        const std::vector<Card *> rowEnemy = enemy.row(row);
        for (Card *card : rowEnemy)
            if (!card->isResilient) {
                takeCard(card, enemy, enemy);
                reset(card, ally, enemy);
                enemy.discard.push_back(card);
            } else {
                card->isResilient = false;
                if (card->power > card->powerBase)
                    card->power = card->powerBase;
            }
    }

    /// start next round
    ally.nRounds++;
    ally.nTurns = 0;
    ally.passed = false;

    enemy.nRounds++;
    enemy.nTurns = 0;
    enemy.passed = false;

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
        drawACard(ally, enemy);
        drawACard(enemy, ally);
    }

    ally.nSwaps = nSwap;
    enemy.nSwaps = nSwap;

    // TODO: flip a coin to determine first player
    ally.cardStack.push_back(Choice(RoundStartSwap, nullptr, ally.hand, ally.nSwaps, true));
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
    const std::vector<Card *> _cards = randoms(cards, 1, rng);
    return _cards.size() == 0 ? nullptr : _cards[0];
}

void playAsSpecial(Card *card, Field &ally, Field &enemy, const Card *src)
{
    saveFieldsSnapshot(ally, enemy, PlaySpecial, src, {card}, randomSound(card, ally.rng));

    card->onPlaySpecial(ally, enemy);

    // TODO: others trigger special
}

void playCard(Card *card, Field &ally, Field &enemy, const Card *src)
{
    assert(card != nullptr);
    if (card->isSpecial) {
        playAsSpecial(card, ally, enemy, src);
        putOnDiscard(card, ally, enemy);
        return;
    }
    return ally.cardStack.push_back(Choice(card->isLoyal ? SelectAllyRowAndPos : SelectEnemyRowAndPos, card));
}

void putOnField(Card *card, const RowAndPos &rowAndPos, Field &ally, Field &enemy, const bool triggerDeploy, const Card *src)
{
    if (!isOkRowAndPos(rowAndPos, ally))
        return;

    const Row row = rowAndPos.row;
    const Pos pos = rowAndPos.pos;

    const Row takenFrom = takeCard(card, ally, enemy);

    switch (rowAndPos.row) {
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

    if (takenFrom == Meele || takenFrom == Range || takenFrom == Seige)
        return card->onMoveFromRowToRow(ally, enemy);

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

    } else {
        card->isSpy = true;
        if (takenFrom == Deck) {
            if (triggerDeploy)
                card->onDeployFromDeck(enemy, ally);
        } else if (takenFrom == Discard) {
            if (triggerDeploy)
                card->onDeployFromDiscard(enemy, ally);
            for (Card *other : cardsFiltered(enemy, ally, {}, AllyAnywhere))
                other->onOtherAllyResurrecteded(card, enemy, ally);
        } else if (takenFrom == Hand || takenFrom == AlreadyCreated || takenFrom == HandLeader) {
            if (triggerDeploy)
                card->onDeploy(enemy, ally);
        } else
            assert(false);
    }

    // TODO: others trigger enter
}

void putOnDiscard(Card *card, Field &ally, Field &enemy)
{
    Pos pos;
    bool isAlly;
    const Row takenFrom = takeCard(card, ally, enemy, &pos, &isAlly);
    const bool mayPutOnDiscard = !card->isDoomed && (card->isSpecial || card->powerBase > 0);
    const bool mayTriggerDeathwish = card->powerBase > 0;

    Field *cardAlly = &ally;
    Field *cardEnemy = &enemy;
    if (!isAlly)
        std::swap(cardAlly, cardEnemy);

    if (!card->isSpecial)
        reset(card, ally, enemy);

    if (takenFrom == Meele || takenFrom == Range || takenFrom == Seige) {
        assert(!card->isSpecial);
        if (mayPutOnDiscard)
            cardAlly->discard.push_back(card);
        if (mayTriggerDeathwish)
            card->onDestroy(*cardAlly, *cardEnemy, RowAndPos(takenFrom, pos));
        for (Card *other : cardsFiltered(*cardAlly, *cardEnemy, {}, EnemyAnywhere))
            other->onOtherEnemyDestroyed(card, *cardEnemy, *cardAlly);

    } else if (takenFrom == Hand || takenFrom == Deck) {
        if (mayPutOnDiscard)
            cardAlly->discard.push_back(card);
        if (!card->isSpecial)
            card->onDiscard(*cardAlly, *cardEnemy);
        for (Card *other : cardsFiltered(*cardAlly, *cardEnemy, {}, AllyAnywhere))
            other->onOtherAllyDiscarded(card, *cardAlly, *cardEnemy);
    } else {
        assert(takenFrom == AlreadyCreated);
        if (mayPutOnDiscard)
            cardAlly->discard.push_back(card);
    }

}

bool findRowAndPos(const Card *card, const Field &field, Row &row, Pos &pos)
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

RowAndPos findRowAndPos(const Card *card, const Field &field)
{
    for (const Row _row : std::vector<Row>{Meele, Range, Seige}) {
        const std::vector<Card *> &__row = field.row(_row);
        for (size_t index = 0; index < __row.size(); ++index)
            if (__row[index] == card)
                return RowAndPos(_row, Pos(index));
    }
    return RowAndPos();
}

RowAndPos rowAndPosLastInRow(const Field &field, const Row row)
{
    assert(row == Meele || row == Range || row == Seige);
    const Pos size = Pos(field.row(row).size());
    return size == 9 ? RowAndPos(row, size) : RowAndPos();
}

RowAndPos rowAndPosNextTo(const Card *card, const Field &field, const int offset)
{
    const RowAndPos rowAndPos = findRowAndPos(card, field);
    return isOkRowAndPos(rowAndPos, field) ? RowAndPos(rowAndPos.row, rowAndPos.pos + offset) : RowAndPos();
}

void startChoiceToSelectOption(Field &ally, Card *self, const std::vector<Card *> &options, const int nTargets, const int nWindow, const bool isOptional)
{
    assert(self != nullptr);
    assert(self->_options.size() == 0);

    const int nOptions = int(options.size());

    /// if no window given -> show all options
    /// if window is to wide, then show all options as well
    if ((nWindow < 0) || (nOptions <= nWindow)) {
        self->_options = options;
        ally.cardStack.push_back(Choice(Target, self, options, nTargets, true));
        return;
    }

    assert(nWindow > 1);
    std::vector<Card *> optionsShuffled = options;
    shuffle(optionsShuffled, ally.rng);

    /// remove last nTargets - nWindow
    for (int i = nWindow; i < nOptions; ++i)
        delete optionsShuffled.at(size_t(i));
    optionsShuffled.resize(size_t(nWindow));

    self->_options = optionsShuffled;
    ally.cardStack.push_back(Choice(Target, self, optionsShuffled, nTargets, isOptional));
}

void startChoiceCreateOptions(Field &ally, Card *self, const Filters &filters, const bool isOptional)
{
    // TODO: empty allCards, so not implemented
//    assert(false);
    assert(self != nullptr);
    assert(self->_options.size() == 0);

    std::vector<Card *> options = _filtered(filters, allCards(self->patch));
    shuffle(options, ally.rng);

    for (size_t i = 3; i < options.size(); ++i)
        delete options.at(size_t(i));
    options.resize(3);

    self->_options = options;
    ally.cardStack.push_back(Choice(Target, self, options, 1, isOptional));
}

bool startChoiceToTargetCard(Field &ally, Field &enemy, Card *self, const Filters &filters, const ChoiceGroup group, const int nTargets, const bool isOptional)
{
    const std::vector<Card *> cards = _filtered(canBeSelected(self), cardsFiltered(ally, enemy, filters, group));
    return startChoiceToTargetCard(ally, enemy, self, cards, nTargets, isOptional);
}

bool startChoiceToTargetCard(Field &ally, Field &enemy, Card *self, const std::vector<Card *> &options, const int nTargets, const bool isOptional)
{
    if (options.size() == 0)
        return false;

    /// checking if already can be selected
    if (!isOptional && int(options.size()) <= nTargets) {
        for (Card *card : options)
            self->onTargetChoosen(card, ally, enemy);
        return true;
    }

    ally.cardStack.push_back(Choice(Target, self, options, nTargets, isOptional));
    return true;
}

void startChoiceToSelectAllyRow(Field &field, Card *self)
{
    field.cardStack.push_back(Choice(SelectAllyRow, self));
}

void startChoiceToSelectEnemyRow(Field &field, Card *self)
{
    field.cardStack.push_back(Choice(SelectEnemyRow, self));
}

void onChoiceDoneCard(Card *card, Field &ally, Field &enemy)
{
    const Choice choice = ally.takeChoice();

    if (choice.choiceType == RoundStartPlay) {
        /// passed
        if (card == nullptr) {
            ally.passed = true;
            return;
        }
        assert(choice.nTargets == 1);
        return playCard(card, ally, enemy, nullptr);
    }
    if (choice.choiceType == Target) {
        Choice choiceNext = choice;
        if (card != nullptr) {
            /// remove a previously selected card
            for (size_t j = 0; j < choiceNext.cardOptions.size(); ++j)
                if (choiceNext.cardOptions.at(j) == card) {
                    choiceNext.cardOptions.erase(choiceNext.cardOptions.begin() + int(j));
                    break;
                }
            /// add it to selected cards
            choiceNext.cardOptionsSelected.push_back(card);

            if ((int(choiceNext.cardOptionsSelected.size()) < choiceNext.nTargets) && (choiceNext.cardOptions.size() > 0)) {
                ally.cardStack.push_back(choiceNext);
                return;
            }
        } else {
            assert(choice.isOptional);
        }

        for (Card *card : choiceNext.cardOptionsSelected)
            choice.cardSource->onTargetChoosen(card, ally, enemy);
        return;
    }
    assert(false);
}

void onChoiceDoneRowAndPlace(const RowAndPos &rowAndPos, Field &ally, Field &enemy)
{
    // TODO: moved a card to be placed to the options instead of
    // src. and move src to player/

    const Choice Choice = ally.takeChoice();
    if (Choice.choiceType == SelectAllyRowAndPos) {
        putOnField(Choice.cardSource, rowAndPos, ally, enemy, true, nullptr);
        return;
    }

    if (Choice.choiceType == SelectEnemyRowAndPos) {
        putOnField(Choice.cardSource, rowAndPos, enemy, ally, true, nullptr);
        return;
    }

    assert(false);
}

void onChoiceDoneRow(const Row row, Field &ally, Field &enemy)
{
    const Choice choice = ally.takeChoice();
    if (choice.choiceType == SelectAllyRow)
        return choice.cardSource->onTargetRowAllyChoosen(ally, enemy, row);

    if (choice.choiceType == SelectEnemyRow)
        return choice.cardSource->onTargetRowEnemyChoosen(ally, enemy, row);

    assert(false);
}

void onChoiceDoneRoundStartSwap(Card *card, Field &ally, Field &enemy)
{
    const Choice choice = ally.takeChoice();
    assert(choice.choiceType == RoundStartSwap);

    if (card != nullptr) {
        swapACard(card, ally, enemy);

        if (choice.nTargets > 1) {
            ally.cardStack.push_back(Choice(RoundStartSwap, choice.cardSource, ally.hand, choice.nTargets - 1, choice.isOptional));
            return;
        }
    }

    /// start a game after start swap
    ally.nSwaps = 0;
    // TODO: add leader to hand, move to separate function
    std::vector<Card *> cardsToPlay = ally.hand;
    if (ally.leader != nullptr)
        cardsToPlay.insert(cardsToPlay.begin(), ally.leader);
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, cardsToPlay, 1, ally.canPass));
}

void traceField(Field &field)
{
    std::cout << "meele: ";
    for (Card *_card : field.rowMeele)
        std::cout << _card->power << " ";
    std::cout << "\nrange: ";
    for (Card *_card : field.rowRange)
        std::cout << _card->power << " ";
    std::cout << "\nseige: ";
    for (Card *_card : field.rowSeige)
        std::cout << _card->power << " ";

    if (field.cardStack.size() == 0)
        return;

    switch (field.choice().choiceType) {
    case RoundStartPlay:
        std::cout << "\n\nSelect a card to play:\n";
        break;
    case SelectAllyRowAndPos:
        std::cout << "\n\nSelect a row and a pos to play a card:\n";
        break;
    case SelectEnemyRowAndPos:
        std::cout << "\n\nSelect an opponent row and pos to play a card:\n";
        break;
    case SelectAllyRow:
        std::cout << "\n\nSelect a row:\n";
        break;
    case SelectEnemyRow:
        std::cout << "\n\nSelect an opponent row:\n";
        break;
    case Target:
        std::cout << "\n\nChoose target:\n";
        break;
    case RoundStartSwap:
        std::cout << "\n\nChoose a card to swap:\n";
        break;
    }

    for (Card *card : field.choice().cardOptions)
        std::cout << card->power << "\n";
}

bool isOkRowAndPos(const RowAndPos &rowAndPos, const Field &field)
{
    if (rowAndPos.pos < 0)
        return false;

    if (rowAndPos.pos >= 9)
        return false;

    const std::vector<Card *> &_row = field.row(rowAndPos.row);
    return !isRowFull(_row) && (rowAndPos.pos <= int(_row.size()));
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
    if (findRowAndPos(card, ally, row, pos))
        return cardAtRowAndPos(row, pos + offset, ally);
    if (findRowAndPos(card, enemy, row, pos))
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

        assert(group == AnyBoard);
        return _united(Rows{ally.rowMeele, ally.rowRange, ally.rowSeige, enemy.rowMeele, enemy.rowRange, enemy.rowSeige});
    }();

    return _filtered(filters, cards);
}

std::vector<Card *> highests(const std::vector<Card *> &row)
{
    int powerMax = INT_MIN;
    for (Card *card : row)
        powerMax = std::max(card->power, powerMax);

    std::vector<Card *> res;
    for (Card *card : row)
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
    int powerMin = INT_MAX;
    for (Card *card : row)
        powerMin = std::min(card->power, powerMin);

    std::vector<Card *> res;
    for (Card *card : row)
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
    std::vector<Card *> res = findCopies(card, cards);
    if (res.size() == 0)
        return nullptr;

    return res[0];
}

const Choice &Field::choice() const
{
    assert(cardStack.size() > 0);
    return cardStack.back();
}

Choice &Field::choice()
{
    assert(cardStack.size() > 0);
    return cardStack.back();
}

Choice Field::takeChoice()
{
    assert(cardStack.size() > 0);
    Choice res = cardStack.back();
    cardStack.pop_back();
    return res;
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

bool drawACard(Field &ally, Field &enemy)
{
    if (ally.deck.size() == 0)
        return false;

    putToHand(ally.deck.front(), ally, enemy);
    return true;
}

void swapACard(Card *card, Field &ally, Field &enemy)
{
    if (ally.deck.size() == 0) {
        card->onSwap(ally, enemy);
        // TODO: trigger all others onSwap abilities
        card->onDraw(ally, enemy);
        // TODO: trigger all others onDrawn abilities
        return;
    }

    const Row from = takeCard(card, ally, enemy);
    assert(from == Hand);

    /// move to any place in the deck, but not first
    const int ind = 1 + int(ally.rng() % ally.deck.size());
    ally.deck.insert(ally.deck.begin() + ind, card);
    card->onSwap(ally, enemy);
    // TODO: trigger all others onSwap abilities

    const bool drawn = drawACard(ally, enemy);
    assert(drawn);
}

void banish(Card *card, Field &ally, Field &enemy)
{
    const Row row = takeCard(card, ally, enemy);
    assert(row != AlreadyCreated);
}

void duel(Card *first, Card *second, Field &ally, Field &enemy)
{
    assert(!first->isSpecial);
    assert(!second->isSpecial);

    while (true) {
//        ally.snapshots.push_back(new Animation("", Animation::LineDamage, first, second));
        if (damage(second, first->power, ally, enemy, first))
            break;
        std::swap(first, second);
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
        card->onDamaged(dmgInPower, ally, enemy);
        return false;
    }

    putOnDiscard(card, ally, enemy);
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
    // TODO: trigger other on boosted
    if (target->power > 0) {
        target->onDamaged(powerDrained, ally, enemy);
        // TODO: trigger other on damaged
        return;
    }

    putOnDiscard(target, ally, enemy);
}

void heal(Card *card, Field &, Field &)
{
    assert(!card->isSpecial);

    if (card->power < card->powerBase)
        card->power = card->powerBase;
}

void reset(Card *card, Field &, Field &)
{
    assert(!card->isSpecial);

    card->power = card->powerBase;
}

void putToHand(Card *card, Field &ally, Field &enemy)
{
    const Row row = takeCard(card, ally, enemy);
    assert(row != Hand);

    /// reset a card statuses
    card->power = card->powerBase;
    card->isSpy = false;
    card->isResilient = false;
    card->isLocked = false;

    ally.hand.push_back(card);

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

    // TODO: others trigger on boosted
}

void strengthen(Card *card, const int x, Field &ally, Field &enemy)
{
    assert(x > 0);
    assert(!card->isSpecial);

    card->power += x;
    card->powerBase += x;

//    ally.snapshots.push_back(new Animation("", Animation::StrengthenText, card));

    // TODO: others trigger on strengthen
}

bool weaken(Card *card, const int x, Field &ally, Field &enemy)
{
    assert(x > 0);
    assert(!card->isSpecial);

    card->power -= x;
    card->powerBase -= x;

//    ally.snapshots.push_back(new Animation("", Animation::WeakenText, card));

    if (card->powerBase <= 0) {
        banish(card, ally, enemy);
        return true;
    }

    // TODO: others trigger on weaken
    return false;
}

void gainArmor(Card *card, const int x, Field &ally, Field &enemy, const Card *src)
{
    assert(x > 0);
    assert(!card->isSpecial);

    card->armor += x;

    saveFieldsSnapshot(ally, enemy, GainArmor, src, {card}, "", x);
}

std::string stringChoices(const std::vector<Choice> &cardStack)
{
    std::string res;
    for (const Choice &choice : cardStack) {
        if (res.size() > 0)
            res += " -> ";
        switch (choice.choiceType) {
        case RoundStartPlay:
            res += "Choose a card to play";
            break;
        case SelectAllyRowAndPos:
            res += "Choose an allied row and pos";
            break;
        case SelectEnemyRowAndPos:
            res += "Choose an enemy row and pos";
            break;
        case SelectAllyRow:
            res += "Choose an allied row";
            break;
        case SelectEnemyRow:
            res += "Choose an enemy row";
            break;
        case Target:
            res += "Choose an ability option";
            break;
        case RoundStartSwap:
            res += "Choose a card to swap [" + std::to_string(choice.nTargets) + " left]";
            break;
        }
        if (choice.cardSource != nullptr)
            res += " (Source: " + choice.cardSource->name + ")";

        if ((choice.choiceType == Target) && ((choice.nTargets > 1) || (choice.isOptional))) {
            res += " [";
            if (choice.isOptional)
                res += "optional";
            if (choice.nTargets > 1) {
                if (choice.isOptional)
                    res += " ";
                res += std::to_string(choice.cardOptionsSelected.size()) + "/" + std::to_string(choice.nTargets);
            }
            res += "]";
        }
    }
    if (res.size() == 0)
        return "Card stack is empty...";
    return res;
}

bool tryFinishTurn(Field &ally, Field &enemy)
{
    if (ally.cardStack.size() > 0)
        return false;

    /// finish turn if neither of player has been passed
    if (ally.passed && enemy.passed) {
        startNextRound(ally, enemy);
        return true;
    }

    /// finish turn if noone passed
    // TODO: Ronvid on turn end in discard
    for (Card *_card : _united(Rows{ally.rowMeele, ally.rowRange, ally.rowSeige}))
        _card->onTurnEnd(ally, enemy);

    ally.nTurns++;


    // enemy turn
    triggerRowEffects(enemy, ally);

    for (Card *_card : _united(Rows{enemy.rowMeele, enemy.rowRange, enemy.rowSeige}))
        _card->onTurnStart(ally, enemy);

    /// finish turn if only enemy passed
    if (enemy.passed)
        return tryFinishTurn(enemy, ally);

    // TODO: remove later, only for a hot-seat
    if (enemy.nTurns == 0 && enemy.nSwaps != 0){
        enemy.cardStack.push_back(Choice(RoundStartSwap, nullptr, enemy.hand, enemy.nSwaps, true));
        return true;
    }

    /// give a choice to enemy
    // TODO: add leader to hand, move to separate function
    std::vector<Card *> cardsToPlay = enemy.hand;
    if (enemy.leader != nullptr)
        cardsToPlay.insert(cardsToPlay.begin(), enemy.leader);
    enemy.cardStack.push_back(Choice(RoundStartPlay, nullptr, cardsToPlay, 1, enemy.canPass));
    return true;
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

void spawn(Card *card, const RowAndPos &rowAndPos, Field &ally, Field &enemy, const bool addAsNew, const bool triggerDeploy, const Card *src)
{
    assert(card != nullptr);
    assert(!card->isSpecial);

    /// delete card if position is bad
    if (!isOkRowAndPos(rowAndPos, ally)) {
        delete card;
        return;
    }

    if (addAsNew)
        ally.cardsAdded.push_back(card);

    putOnField(card, rowAndPos, ally, enemy, triggerDeploy, src);
}

void spawn(Card *card, Field &ally, Field &enemy, const Card *src)
{
    assert(card != nullptr);

    ally.cardsAdded.push_back(card);

    if (card->isSpecial) {
        playAsSpecial(card, ally, enemy, src);
        putOnDiscard(card, ally, enemy);
        return;
    }
    return ally.cardStack.push_back(Choice(card->isLoyal? SelectAllyRowAndPos : SelectEnemyRowAndPos, card));
}

void applyRowEffect(Field &ally, Field &enemy, const Row row, const RowEffect rowEffect)
{
    assert(row == Meele || row == Range || row == Seige);

    ally.rowEffect(row) = rowEffect;

    for (Card *card : ally.row(row))
        if (rowEffect == BloodMoonEffect)
            damage(card, 2, ally, enemy, nullptr);
        else if (ally.rowEffect(row) == PitTrapEffect)
            damage(card, 3, ally, enemy, nullptr);
}

void charm(Card *card, Field &ally, Field &enemy)
{
    // FIXME: charm isn't working at all
}

void copyCardText(const Card *card, Card *dst)
{
    assert(card->armor == 0);
    assert(card->timer == 0);
    dst->power = card->power;
    dst->powerBase = card->powerBase;
    dst->rarity = card->rarity;
    dst->faction = card->faction;
    dst->tags = card->tags;
    dst->isLoyal = card->isLoyal;
    dst->isSpecial = card->isSpecial;
    dst->name = card->name;
    dst->text = card->text;
    dst->url = card->url;
    dst->sounds = card->sounds;
}
void acceptOptionAndDeleteOthers(Card *card, const Card *option)
{
    assert(card != nullptr);
    assert(card->_options.size() > 0);

    for (Card *_option : card->_options)
        if (_option != option)
            delete _option;

    card->_options.clear();
}

std::string randomSound(const Card *card, Rng &rng)
{
    if (card->sounds.size() == 0)
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
    std::map<std::string, int> nameToCount;
    for (Card *card : cards) {
        auto it = nameToCount.find(card->name);
        if (it != nameToCount.end()) {
            return false;
        } else {
            nameToCount.insert({card->name, 1});
        }
    }
    return true;
}

bool hasExactTwoDuplicatesOfBronze(const std::vector<Card *> &cards)
{
    std::map<std::string, int> nameToCount;
    for (Card *card : cards) {
        if (card->rarity != Bronze)
            continue;
        auto it = nameToCount.find(card->name);
        if (it != nameToCount.end()) {
            ++it->second;
        } else {
            nameToCount.insert({card->name, 1});
        }
    }

    for (const std::pair<std::string, int> &nameAndCount : nameToCount)
        if (nameAndCount.second != 2)
            return false;

    return true;
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
        Field &ally, Field &enemy,
        const ActionType actionType,
        const Card *src,
        const std::vector<Card *> &dst,
        const std::string &sound,
        const int value)
{
    FieldView viewAlly = fieldView(ally, enemy, actionType, src, dst, sound, value);
    ally.snapshots.push_back(viewAlly);

    FieldView viewEnemy = fieldView(enemy, ally, actionType, src, dst, sound, value);
    enemy.snapshots.push_back(viewEnemy);
}

bool randomRowAndPos(Field &field, Row &row, Pos &pos)
{
    std::vector<Row> hasFreeSpace;
    for (const Row _row : std::vector<Row>{Meele, Range, Seige}) {
        if (isRowFull(field.row(_row)))
            continue;
        hasFreeSpace.push_back(_row);
    }
    if (hasFreeSpace.size() == 0)
        return false;

    row = hasFreeSpace[field.rng() % hasFreeSpace.size()];
    pos = Pos(field.row(row).size());
    return true;
}

bool isOnBoard(const Card *card, const Field &field)
{
    return isIn(card, field.rowMeele) || isIn(card, field.rowRange) || isIn(card, field.rowSeige);
}

void transform(
        Card *card,
        const std::string &id,
        const std::string &name,
        const std::string &text,
        const std::string &url,
        const int power,
        const Rarity rarity,
        const Tag faction,
        const std::vector<Tag> &tags)
{
    card->id = id;
    card->name = name;
    card->text = text;
    card->url = url;
    card->power = card->powerBase = power;
    card->rarity = rarity;
    card->faction = faction;
    card->tags = tags;

    card->timer = 0;
    card->armor = 0;
    card->isDoomed = true;
    card->isLocked = true;
    card->isSpy = false;
    card->isResilient = false;
}

void toggleLock(Card *card, Field &, Field &)
{
    card->isLocked = !card->isLocked;
}

void lock(Card *card, Field &ally, Field &enemy)
{
    if (!card->isLocked)
        toggleLock(card, ally, enemy);
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
