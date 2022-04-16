#include "card.h"

#include <assert.h>
#include <iostream>
#include <algorithm>
#include <random>
#include <map>

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

Row takeCard(const Card *card, Field &ally, Field &enemy, bool *isAlly)
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
                return Row(i % 6);
            }
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
            for (Card *card : randoms(rowFiltered, 2))
                damage(card, 1, ally, enemy);
            break;
        case BitingFrostEffect:
        case KorathiHeatwaveEffect:
            if (Card *target = lowest(rowFiltered))
                damage(target, 2, ally, enemy);
            break;
        case RaghNarRoogEffect:
        case ImpenetrableFogEffect:
            if (Card *target = highest(rowFiltered))
                damage(target, 2, ally, enemy);
            break;
        case GoldenFrothEffect:
            for (Card *target : randoms(rowFiltered, 2))
                boost(target, 1, ally, enemy);
            break;
        case SkelligeStormEffect: {
            Card *targetFirst=   (row.size() >= 1) && (!row[0]->isAmbush) ? row[0] : nullptr;
            Card *targetSecond = (row.size() >= 2) && (!row[1]->isAmbush) ? row[1] : nullptr;
            Card *targetThird =  (row.size() >= 3) && (!row[2]->isAmbush) ? row[2] : nullptr;
            if (targetFirst != nullptr)
                damage(targetFirst, 2, ally, enemy);
            if (targetSecond != nullptr)
                damage(targetSecond, 1, ally, enemy);
            if (targetThird != nullptr)
                damage(targetThird, 1, ally, enemy);
            break;
        }
        case FullMoonEffect: {
            const std::vector<Card *> beastOrVampire = _filtered({[](Card *card){ return !card->isAmbush && (hasTag(card, Beast) || hasTag(card, Vampire)); }}, row);
            if (Card *target = random(beastOrVampire))
                boost(target, 2, ally, enemy);
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

void initField(const std::vector<Card *> &deckStarting, Field &field)
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
    field.rowEffectMeele = NoRowEffect;
    field.rowEffectRange = NoRowEffect;
    field.rowEffectSeige = NoRowEffect;
    field.nTurns = 0;

    /// shuffle a deck
    shuffle(field.deck);
}

void startNextRound(Field &ally, Field &enemy)
{
    /// if prev round wasn't first, check winners
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
        // TODO: check winners
    }

    /// clean all the mess from previous round
    for (const Row row : std::vector<Row>{Meele, Range, Seige}) {
        ally.rowEffect(row) = NoRowEffect;
        enemy.rowEffect(row) = NoRowEffect;

        const std::vector<Card *> rowAlly = ally.row(row);
        for (Card *card : rowAlly)
            if (!card->isResilient) {
                takeCard(card, ally, enemy);
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
                enemy.discard.push_back(card);
            } else {
                card->isResilient = false;
                if (card->power > card->powerBase)
                    card->power = card->powerBase;
            }
    }

    /// start next round
    ally.nRounds++;
    ally.passed = false;

    enemy.nRounds++;
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

    /// start a round start swapping
    ally.cardStack.push_back(Choice(RoundStartSwap, nullptr, ally.hand, nSwap, true));
    enemy.cardStack.push_back(Choice(RoundStartSwap, nullptr, enemy.hand, nSwap, true));
}

std::default_random_engine _rng;

void shuffle(std::vector<Card *> &cards)
{
    // TODO: random must be used
    std::shuffle(std::begin(cards), std::end(cards), _rng);
}

std::vector<Card *> randoms(const std::vector<Card *> &cards, const int nRandoms)
{
    std::vector<Card *> res;

    std::vector<Card *> tmp = cards;
    for (int n = 0; n < nRandoms; ++n) {
        if (tmp.size() == 0)
            break;
        const auto ind = _rng() % tmp.size();
        res.push_back(tmp[ind]);
        tmp.erase(tmp.begin() + int(ind));
    }

    return res;
}

Card *random(const std::vector<Card *> &cards)
{
    const std::vector<Card *> _cards = randoms(cards, 1);
    return _cards.size() == 0 ? nullptr : _cards[0];
}

void playAsSpecial(Card *card, Field &ally, Field &enemy)
{
//    ally.animations.push_back(new Animation(randomSound(card), Animation::PlaySpecial, card));

    card->onPlaySpecial(ally, enemy);

    // TODO: others trigger special
}

void playCard(Card *card, Field &ally, Field &enemy)
{
    assert(card != nullptr);
    if (card->isSpecial) {
        playAsSpecial(card, ally, enemy);
        putOnDiscard(card, ally, enemy);
        return;
    }
    return ally.cardStack.push_back(Choice(card->isLoyal ? SelectAllyRowAndPos : SelectEnemyRowAndPos, card));
}

void putOnField(Card *card, const Row row, const Pos pos, Field &ally, Field &enemy)
{
    assert(isOkRowAndPos(row, pos, ally));

    const Row takenFrom = takeCard(card, ally, enemy);

    switch (row) {
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
        damage(card, 2, ally, enemy);
    else if (ally.rowEffect(row) == PitTrapEffect)
        damage(card, 3, ally, enemy);

    if (takenFrom == Meele || takenFrom == Range || takenFrom == Seige)
        return card->onMoveFromRowToRow(ally, enemy);

//    ally.animations.push_back(new Animation(randomSound(card), Animation::PutOnField, card));

    if (card->isLoyal) {
        if (takenFrom == Deck)
            card->onEnterFromDeck(ally, enemy);
        else if (takenFrom == Discard)
            card->onEnterFromDiscard(ally, enemy);
        else if (takenFrom == Hand || takenFrom == AlreadyCreated)
            card->onEnter(ally, enemy);
        else
            assert(false);

    } else {
        card->isSpy = true;
        if (takenFrom == Deck)
            card->onEnterFromDeck(enemy, ally);
        else if (takenFrom == Discard)
            card->onEnterFromDiscard(enemy, ally);
        else if (takenFrom == Hand || takenFrom == AlreadyCreated)
            card->onEnter(enemy, ally);
        else
            assert(false);
    }

    // TODO: others trigger enter
}

void putOnDiscard(Card *card, Field &ally, Field &enemy)
{
    const Row takenFrom = takeCard(card, ally, enemy);

    if (takenFrom == Meele || takenFrom == Range || takenFrom == Seige) {
        assert(!card->isSpecial);
        // TODO: check 0 power
        card->onDestroy(ally, enemy);
    } else if (takenFrom == Hand || takenFrom == Deck) {
        if (!card->isSpecial)
            card->onDiscard(ally, enemy);
    }

    ally.discard.push_back(card);
}

bool rowAndPos(const Card *card, const Field &field, Row &row, Pos &pos)
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

void startChoiceToSelectOption(Field &ally, Card *self, const std::vector<Card *> &options, const int nTargets, const int nWindow)
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
    shuffle(optionsShuffled);

    /// remove last nTargets - nWindow
    for (int i = nWindow; i < nTargets; ++i)
        delete optionsShuffled.at(size_t(i));
    optionsShuffled.resize(size_t(nWindow));

    self->_options = optionsShuffled;
    ally.cardStack.push_back(Choice(Target, self, optionsShuffled, nTargets, true));
}

bool startChoiceToTargetCard(Field &ally, Field &enemy, Card *self, const Filters &filters, const ChoiceGroup group, const int nTargets, const bool isOptional)
{
    const std::vector<Card *> cards = _filtered(canBeSelected(self), cardsFiltered(ally, enemy, filters, group));
    if (cards.size() == 0)
        return false;

    /// checking if already can be selected
    if (!isOptional && int(cards.size()) <= nTargets) {
        for (Card *card : cards)
            self->onTargetChoosen(card, ally, enemy);
        return true;
    }

    ally.cardStack.push_back(Choice(Target, self, cards, nTargets, isOptional));
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
        return playCard(card, ally, enemy);
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

void onChoiceDoneRowAndPlace(const Row row, const Pos pos, Field &ally, Field &enemy)
{
    const Choice Choice = ally.takeChoice();
    if (Choice.choiceType == SelectAllyRowAndPos) {
        putOnField(Choice.cardSource, row, pos, ally, enemy);
        return;
    }

    if (Choice.choiceType == SelectEnemyRowAndPos) {
        putOnField(Choice.cardSource, row, pos, enemy, ally);
        return;
    }

    assert(false);
}

void onChoiceDoneRow(const Row row, Field &ally, Field &enemy)
{
    const Choice Choice = ally.takeChoice();
    if (Choice.choiceType == SelectAllyRow)
        return applyRowEffect(ally, enemy, row, Choice.cardSource->rowEffect());

    if (Choice.choiceType == SelectEnemyRow)
        return applyRowEffect(enemy, ally, row, Choice.cardSource->rowEffect());

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
    ally.cardStack.push_back(Choice(RoundStartPlay, nullptr, ally.hand, 1, true));
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

bool isOkRowAndPos(const Row row, const Pos pos, const Field &field)
{
    if (pos < 0)
        return false;

    if (pos >= 9)
        return false;

    const std::vector<Card *> &_row = field.row(row);
    return !isRowFull(_row) && (pos <= int(_row.size()));
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
    if (rowAndPos(card, ally, row, pos))
        return cardAtRowAndPos(row, pos + offset, ally);
    if (rowAndPos(card, enemy, row, pos))
        return cardAtRowAndPos(row, pos + offset, enemy);
    return nullptr;
}

std::vector<Card *> cardsFiltered(const Field &ally, const Field &enemy, const Filters &filters, const ChoiceGroup group)
{
    const std::vector<Card *> cards = [ally, enemy, group]{
        if (group == Ally)
            return _united(Rows{ally.rowMeele, ally.rowRange, ally.rowSeige});

        if (group == Enemy)
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
            shuffle(deck);
            return deck;
        }

        assert(group == Any);
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

Card *highest(const std::vector<Card *> &row)
{
    std::vector<Card *> res = highests(row);
    if (res.size() == 0)
        return nullptr;

    // TODO: using random
    return res[_rng() % res.size()];
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

Card *lowest(const std::vector<Card *> &row)
{
    std::vector<Card *> res = lowests(row);
    if (res.size() == 0)
        return nullptr;

    // TODO: using random
    return res[_rng() % res.size()];
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

    // TODO: using random
    return res[_rng() % res.size()];
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

    Card *card = ally.deck.front();
    ally.deck.erase(ally.deck.begin());
    ally.hand.push_back(card);

    card->onDraw(ally, enemy);
    // TODO: trigger all onDrawn abilities

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
    // TODO: use random
    const int ind = 1 + _rng() % ally.deck.size();
    ally.deck.insert(ally.deck.begin() + ind, card);
    card->onSwap(ally, enemy);
    // TODO: trigger all others onSwap abilities

    const bool drawn = drawACard(ally, enemy);
    assert(drawn);
}

void destroy(Card *card, Field &ally, Field &enemy)
{
    if (card->isDoomed) {
        return banish(card, ally, enemy);
    }

    card->onDestroy(ally, enemy);

    bool isAlly = false;
    const Row row = takeCard(card, ally, enemy, &isAlly);
    assert(row != AlreadyCreated);

    card->power = card->powerBase;
    (isAlly ? &ally : &enemy)->discard.push_back(card);

    // TODO: trigger other on destroy
}

void banish(Card *card, Field &ally, Field &enemy)
{
    bool isAlly = false;
    const Row row = takeCard(card, ally, enemy, &isAlly);
    assert(row != AlreadyCreated);
}

void duel(Card *first, Card *second, Field &ally, Field &enemy)
{
    while (true) {
//        ally.animations.push_back(new Animation("", Animation::LineDamage, first, second));
        if (damage(second, first->power, ally, enemy))
            break;
        std::swap(first, second);
    }
}

bool damage(Card *card, const int x, Field &ally, Field &enemy)
{
    assert(x > 0);

    int dmgInPower = x;

    if (card->armor > 0) {
        const int dmgInArmor = std::min(card->armor, x);
        dmgInPower = std::max(0, x - card->armor);
        card->armor -= dmgInArmor;

        /// if armor broken, but will survive
        if ((card->armor == 0) && (card->power > dmgInPower)){
            card->onArmorLost(ally, enemy);
//            ally.animations.push_back(new Animation("", Animation::ArmorAllLost, card));
        }

        if (dmgInPower == 0)
            return false;
    }
    card->power -= dmgInPower;

    if (card->power > 0) {
        card->onDamaged(dmgInPower, ally, enemy);
//        ally.animations.push_back(new Animation("", Animation::DamageText, card));
        // TODO: trigger other on damaged
        return false;
    }

    destroy(card, ally, enemy);
    return true;
}

void heal(Card *card, Field &, Field &)
{
    if (card->power < card->powerBase)
        card->power = card->powerBase;
}

void reset(Card *card, Field &, Field &)
{
    card->power = card->powerBase;
}

void boost(Card *card, const int x, Field &ally, Field &enemy)
{
    assert(x > 0);

    card->power += x;

//    ally.animations.push_back(new Animation("", Animation::BoostText, card));

    // TODO: others trigger on boosted
}

void strengthen(Card *card, const int x, Field &ally, Field &enemy)
{
    assert(x > 0);

    card->power += x;
    card->powerBase += x;

//    ally.animations.push_back(new Animation("", Animation::StrengthenText, card));

    // TODO: others trigger on strengthen
}

void weaken(Card *card, const int x, Field &ally, Field &enemy)
{
    assert(x > 0);

    card->power -= x;
    card->powerBase -= x;

//    ally.animations.push_back(new Animation("", Animation::WeakenText, card));

    if (card->powerBase < 0)
        return banish(card, ally, enemy);

    // TODO: others trigger on weaken
}

void gainArmor(Card *card, const int x, Field &ally, Field &enemy)
{
    assert(x > 0);

    card->armor += x;

//    ally.animations.push_back(new Animation("", Animation::ArmorGainText, card));
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

// TODO: is only 1 player
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

    /// give a choice to enemy
    enemy.cardStack.push_back(Choice(RoundStartPlay, nullptr, enemy.hand, 1, true));
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

void spawn(Card *card, const Row row, const Pos pos, Field &ally, Field &enemy)
{
    assert(card != nullptr);
    assert(!card->isSpecial);

    if (!isOkRowAndPos(row, pos, ally)) {
        delete card;
        return;
    }

    ally.cardsAdded.push_back(card);
    putOnField(card, row, pos, ally, enemy);
}

void spawn(Card *card, Field &ally, Field &enemy)
{
    assert(card != nullptr);

    ally.cardsAdded.push_back(card);
//    ally.animations.push_back(new Animation("", Animation::Spawn, card));

    if (card->isSpecial) {
        playAsSpecial(card, ally, enemy);
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
            damage(card, 2, ally, enemy);
        else if (ally.rowEffect(row) == PitTrapEffect)
            damage(card, 3, ally, enemy);
}

void charm(Card *card, Field &ally, Field &enemy)
{

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

std::string randomSound(const Card *card)
{
    if (card->sounds.size() == 0)
        return std::string();

    // TODO: random
    const size_t ind = _rng() % card->sounds.size();
    return card->sounds[ind];
}

RowEffect randomHazardEffect()
{
    // TODO: random
    return RowEffect(_rng() % 9 + 1);
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
