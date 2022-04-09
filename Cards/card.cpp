#include "card.h"

#include <assert.h>
#include <iostream>
#include <algorithm>
#include <random>

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

Row takeCard(const Card *card, Field &ally, Field &enemy)
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
                // isAlly = i < 6;
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
        const std::vector<Card *> rowFiltered = filtered(canBeCount(), row);
        switch (effect) {
        case NoRowEffect:
            break;
        case TorrentialRainEffect:
            break;
        case BitingFrostEffect:
        case KorathiHeatwaveEffect:
            break;
        case RaghNarRoogEffect:
        case ImpenetrableFogEffect:
            if (Card *target = highest(rowFiltered))
                damage(target, 2, ally, enemy);
            break;
        case GoldenFrothEffect:
            break;
        case SkelligeStormEffect:
            break;
        case DragonsDreamEffect:
            break;
        case FullMoonEffect:
            break;
        case BloodMoonEffect:
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
}

void shuffle(std::vector<Card *> &cards)
{
    // TODO: random must be used
    std::shuffle(std::begin(cards), std::end(cards), std::default_random_engine {});
}

void playAsSpecial(Card *card, Field &ally, Field &enemy)
{
    card->onPlaySpecial(ally, enemy);

    for (Card *_card : united(Rows{ally.rowMeele, ally.rowRange, ally.rowSeige, ally.hand, ally.deck}))
        if (_card != card)
            _card->onOtherAllySpecialPlayed(card);

    for (Card *_card : united(Rows{enemy.rowMeele, enemy.rowRange, enemy.rowSeige, enemy.hand, enemy.deck}))
        _card->onOtherEnemySpecialPlayed(card);
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

    if (takenFrom == Meele || takenFrom == Range || takenFrom == Seige)
        return card->onMoveFromRowToRow(ally, enemy);

    if (!card->isSpy) {
        if (takenFrom == Deck)
            card->onEnterFromDeck(ally, enemy);
        else if (takenFrom == Discard)
            card->onEnterFromDiscard(ally, enemy);
        else if (takenFrom == Hand || takenFrom == AlreadyCreated)
            card->onEnter(ally, enemy);
        else
            assert(false);

    } else {
        if (takenFrom == Deck)
            card->onEnterFromDeck(enemy, ally);
        else if (takenFrom == Discard)
            card->onEnterFromDiscard(enemy, ally);
        else if (takenFrom == Hand || takenFrom == AlreadyCreated)
            card->onEnter(enemy, ally);
        else
            assert(false);
    }

    for (Card *_card : united(Rows{ally.rowMeele, ally.rowRange, ally.rowSeige, ally.hand, ally.deck}))
        if (_card != card)
                _card->onOtherAllyEntered(card);

    for (Card *_card : united(Rows{enemy.rowMeele, enemy.rowRange, enemy.rowSeige, enemy.hand, enemy.deck}))
         _card->onOtherEnemyEntered(card);

}

void putOnDiscard(Card *card, Field &ally, Field &enemy)
{
    const Row takenFrom = takeCard(card, ally, enemy);

    if (takenFrom == Meele || takenFrom == Range || takenFrom == Seige) {
        assert(!card->isSpecial);
        // TODO: check 0 power
        card->onDie(ally, enemy);
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

bool startChoiceToPlayCard(Field &field, Card *self, const Filters &filters)
{
    if (field.hand.size() == 0)
        return false;
    // TODO: if hand has exact 1 card
    const std::vector<Card *> hand = field.hand;
    field.cardStack.push_back(Snapshot(RoundStartPlay, self, filtered(filters, hand)));
    return true;
}

bool startChoiceToTargetCard(Field &ally, Field &enemy, Card *self, const Filters &filters, const ChoiceGroup group, const int nTargets, const bool isOptional)
{
    const std::vector<Card *> allies = [&]{
        if (group == Ally)
            return united(Rows{ally.rowMeele, ally.rowRange, ally.rowSeige});
        if (group == Enemy)
            return united(Rows{enemy.rowMeele, enemy.rowRange, enemy.rowSeige});
        if (group == AllyHand)
            return ally.hand;
        assert(group == Any);
        return united(Rows{ally.rowMeele, ally.rowRange, ally.rowSeige, enemy.rowMeele, enemy.rowRange, enemy.rowSeige});
    }();
    const std::vector<Card *> alliesFiltered = filtered(canBeSelected(self), filtered(filters, allies));
    if (alliesFiltered.size() == 0)
        return false;
    // TODO: if alliesFiltered has exact 1 card
    ally.cardStack.push_back(Snapshot(Target, self, alliesFiltered, nTargets, isOptional));
    return true;
}

void startChoiceToSelectAllyRow(Field &field, Card *self)
{
    field.cardStack.push_back(Snapshot(SelectAllyRow, self));
}

void startChoiceToSelectEnemyRow(Field &field, Card *self)
{
    field.cardStack.push_back(Snapshot(SelectEnemyRow, self));
}

void onChoiceDoneCard(Card *card, Field &ally, Field &enemy)
{
    const Snapshot snapshot = ally.takeSnapshot();

    if (snapshot.choice == RoundStartPlay) {
        assert(card != nullptr);
        assert(snapshot.nTargets == 1);
        if (card->isSpecial) {
            playAsSpecial(card, ally, enemy);
            putOnDiscard(card, ally, enemy);
            return;
        }
        return ally.cardStack.push_back(Snapshot(card->isSpy ? SelectEnemyRowAndPos : SelectAllyRowAndPos, card));
    }
    if (snapshot.choice == Target) {
        Snapshot snapshotNext = snapshot;
        if (card != nullptr) {
            /// remove a previously selected card
            for (size_t j = 0; j < snapshotNext.cardOptions.size(); ++j)
                if (snapshotNext.cardOptions.at(j) == card) {
                    snapshotNext.cardOptions.erase(snapshotNext.cardOptions.begin() + int(j));
                    break;
                }
            /// add it to selected cards
            snapshotNext.cardOptionsSelected.push_back(card);

            if ((int(snapshotNext.cardOptionsSelected.size()) < snapshotNext.nTargets) && (snapshotNext.cardOptions.size() > 0)) {
                ally.cardStack.push_back(snapshotNext);
                return;
            }
        } else {
            assert(snapshot.isOptional);
        }

        for (Card *card : snapshotNext.cardOptionsSelected)
            snapshot.cardSource->onTargetChoosen(card, ally, enemy);
        return;
    }
    assert(false);
}

void onChoiceDoneRowAndPlace(const Row row, const Pos pos, Field &ally, Field &enemy)
{
    const Snapshot snapshot = ally.takeSnapshot();
    if (snapshot.choice == SelectAllyRowAndPos) {
        putOnField(snapshot.cardSource, row, pos, ally, enemy);
        return;
    }

    if (snapshot.choice == SelectEnemyRowAndPos) {
        putOnField(snapshot.cardSource, row, pos, enemy, ally);
        return;
    }

    assert(false);
}

void onChoiceDoneRow(const Row row, Field &ally, Field &enemy)
{
    const Snapshot snapshot = ally.takeSnapshot();
    if (snapshot.choice == SelectAllyRow)
        return applyRowEffect(ally, row, snapshot.cardSource->rowEffect());

    if (snapshot.choice == SelectEnemyRow)
        return applyRowEffect(enemy, row, snapshot.cardSource->rowEffect());

    assert(false);
}

void onChoiceDoneRoundStartSwap(Card *card, Field &ally, Field &enemy)
{
    const Snapshot snapshot = ally.takeSnapshot();
    assert(snapshot.choice == RoundStartSwap);

    if (card != nullptr) {
        swapACard(card, ally, enemy);

        if (snapshot.nTargets > 1) {
            ally.cardStack.push_back(Snapshot(RoundStartSwap, snapshot.cardSource, ally.hand, snapshot.nTargets - 1, snapshot.isOptional));
            return;
        }
    }

    /// start a game after start swap
    startChoiceToPlayCard(ally, nullptr);
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

    switch (field.snapshot().choice) {
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

    for (Card *card : field.snapshot().cardOptions)
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

Card *highest(const std::vector<Card *> &row)
{
    int powerMax = INT_MIN;
    Card *res = nullptr;
    for (Card *c : row) {
        if (c->power < powerMax)
            continue;
        powerMax = c->power;
        res = c;
    }
    return res;
}

const Snapshot &Field::snapshot() const
{
    assert(cardStack.size() > 0);
    return cardStack.back();
}

Snapshot &Field::snapshot()
{
    assert(cardStack.size() > 0);
    return cardStack.back();
}

Snapshot Field::takeSnapshot()
{
    assert(cardStack.size() > 0);
    Snapshot res = cardStack.back();
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
        assert(_row == Meele || _row == Range || _row == Seige);
    }
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
        assert(_row == Meele || _row == Range || _row == Seige);
    }
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
        assert(_row == Meele || _row == Range || _row == Seige);
    }
}

bool drawACard(Field &ally, Field &)
{
    if (ally.deck.size() == 0)
        return false;

    Card *card = ally.deck.front();
    ally.deck.erase(ally.deck.begin());
    ally.hand.push_back(card);

    // TODO: trigger all onDrawn abilities

    return true;
}

void swapACard(Card *card, Field &ally, Field &enemy)
{
    if (ally.deck.size() == 0) {
        // TODO: trigger all onSwap abilities
        return;
    }

    const Row from = takeCard(card, ally, enemy);
    assert(from == Hand);

    /// move to any place in the deck, but not first
    // TODO: use random
    const int ind = 1 + (std::default_random_engine {})() % ally.deck.size();
    ally.deck.insert(ally.deck.begin() + ind, card);

    // TODO: trigger all onSwap abilities
    const bool drawn = drawACard(ally, enemy);
    assert(drawn);
}

void damage(Card *card, const int x, Field &ally, Field &enemy)
{
    // TODO: check death and rest
    assert(x > 0);

    int dmgInPower = x;

    if (card->armor > 0) {
        const int dmgInArmor = std::min(card->armor, x);
        dmgInPower = std::max(0, x - card->armor);
        card->armor -= dmgInArmor;

        if (card->power > dmgInPower)
            card->onArmorLost(ally, enemy);

        if (dmgInPower == 0)
            return;
    }
    card->power -= dmgInPower;
}

void boost(Card *card, const int x, Field &, Field &)
{
    assert(x > 0);

    card->power += x;
}

void strengthen(Card *card, const int x, Field &, Field &)
{
    assert(x > 0);

    card->power += x;
    card->powerBase += x;
}

void gainArmor(Card *card, const int x, Field &, Field &)
{
    assert(x > 0);

    card->armor += x;
}

std::string stringSnapShots(const std::vector<Snapshot> &cardStack)
{
    std::string res;
    for (const Snapshot &snapShot : cardStack) {
        if (res.size() > 0)
            res += " -> ";
        switch (snapShot.choice) {
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
            res += "Choose a card to swap [" + std::to_string(snapShot.nTargets) + " left]";
            break;
        }
        if (snapShot.cardSource != nullptr)
            res += " (Source: " + snapShot.cardSource->name + ")";

        if ((snapShot.choice == Target) && ((snapShot.nTargets > 1) || (snapShot.isOptional))) {
            res += " [";
            if (snapShot.isOptional)
                res += "optional ";
            res += std::to_string(snapShot.cardOptionsSelected.size()) + "/" + std::to_string(snapShot.nTargets);
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

    // finish turn
    for (Card *_card : united(Rows{ally.rowMeele, ally.rowRange, ally.rowSeige}))
        _card->onTurnEnd(ally, enemy);

    ally.nTurns++;


    // enemy turn
    triggerRowEffects(enemy, ally);

    for (Card *_card : united(Rows{enemy.rowMeele, enemy.rowRange, enemy.rowSeige}))
        _card->onTurnStart(ally, enemy);

    for (Card *_card : united(Rows{enemy.rowMeele, enemy.rowRange, enemy.rowSeige}))
        _card->onTurnEnd(ally, enemy);

    enemy.nTurns++;


    // start next turn
    triggerRowEffects(ally, enemy);

    for (Card *_card : united(Rows{ally.rowMeele, ally.rowRange, ally.rowSeige}))
        _card->onTurnStart(ally, enemy);

    // play a new card on a new turn
    return startChoiceToPlayCard(ally, nullptr);
}

int powerField(const Field &field)
{
    int res = 0;
    const std::vector<Card *> units = united(Rows{field.rowMeele, field.rowRange, field.rowSeige});
    for (const Card *card : filtered(canBeCount(), units))
        res += card->power;
    return res;
}

int powerRow(const std::vector<Card *> &vector)
{
    int res = 0;
    for (const Card *card : filtered(canBeCount(), vector))
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
    if (card->isSpecial) {
        playAsSpecial(card, ally, enemy);
        putOnDiscard(card, ally, enemy);
        return;
    }
    return ally.cardStack.push_back(Snapshot(card->isSpy ? SelectEnemyRowAndPos : SelectAllyRowAndPos, card));
}

void applyRowEffect(Field &field, const Row row, const RowEffect rowEffect)
{
    assert(row == Meele || row == Range || row == Seige);

    field.rowEffect(row) = rowEffect;
}
