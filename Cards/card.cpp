#include "card.h"

#include <assert.h>
#include <iostream>

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

Row takeCard(const Card *card, Field &field)
{
    const std::vector<std::vector<Card *> *> cards {
        &field.rowMeele,
        &field.rowRange,
        &field.rowSeige,
        &field.hand,
        &field.deck,
        &field.discard
    };
    for (size_t i = 0; i < cards.size(); ++i) {
        std::vector<Card *> *_cards = cards[i];
        for (size_t j = 0; j < _cards->size(); ++j)
            if (_cards->at(j) == card) {
                _cards->erase(_cards->begin() + int(j));
                return Row(i);
            }
    }
    /// assume, that all cards, that weren't
    /// previously anywhere, were already created
    return AlreadyCreated;
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

    const Row takenFrom = takeCard(card, ally);

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

    assert(takenFrom == Hand || takenFrom == Deck || takenFrom == Discard || takenFrom == AlreadyCreated);
    card->onEnter(ally, enemy, takenFrom);

    for (Card *_card : united(Rows{ally.rowMeele, ally.rowRange, ally.rowSeige, ally.hand, ally.deck}))
        if (_card != card)
                _card->onOtherAllyEntered(card);

    for (Card *_card : united(Rows{enemy.rowMeele, enemy.rowRange, enemy.rowSeige, enemy.hand, enemy.deck}))
         _card->onOtherEnemyEntered(card);

}

bool rowAndPos(Card *card, const Field &field, Row &row, Pos &pos)
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

bool startChoiceToPlayCard(Field &field, Card *self, const Filters &filters)
{
    if (field.hand.size() == 0)
        return false;
    // TODO: if hand has exact 1 card
    const std::vector<Card *> hand = field.hand;
    field.cardStack.push_back({Play, self, filtered(filters, hand)});
    return true;
}

bool startChoiceToTargetCard(Field &field, Card *self, const Filters &filters)
{
    const std::vector<Card *> allies = united(Rows{field.rowMeele, field.rowRange, field.rowSeige});
    const std::vector<Card *> alliesFiltered = filtered(canBeSelected(self), filtered(filters, allies));
    if (alliesFiltered.size() == 0)
        return false;
    // TODO: if alliesFiltered has exact 1 card
    field.cardStack.push_back({Target, self, alliesFiltered});
    return true;
}

void onChoiceDoneCard(Card *card, Field &ally, Field &enemy)
{
    const Snapshot snapshot = ally.takeSnapshot();

    if (snapshot.choice == Play) {
        assert(card != nullptr);
        if (card->isSpecial) {
            playAsSpecial(card, ally, enemy);
            return;
        }
        return ally.cardStack.push_back({card->isSpy ? SelectEnemyRowAndPos : SelectAllyRowAndPos, card, {}});
    }
    if (snapshot.choice == Target) {
        return snapshot.cardSource->onTargetChoosen(card, ally, enemy);
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

    assert(false);
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
    case Play:
        std::cout << "\n\nSelect a card to play:\n";
        break;
    case SelectAllyRowAndPos:
        std::cout << "\n\nSelect a row and a pos to play a card:\n";
        break;
    case SelectEnemyRowAndPos:
        std::cout << "\n\nSelect an opponent row and pos to play a card:\n";
        break;
    case Target:
        std::cout << "\n\nChoose target:\n";
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

const std::vector<Card *> &Field::row(Row _row) const
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

std::vector<Card *> &Field::row(Row _row)
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

bool drawACard(Field &)
{
    return true;
}

void boost(Card *card, const int x, Field &, Field &)
{
    assert(x > 0);

    card->power += x;
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
        case Play:
            res += "Choose a card to play";
            break;
        case SelectAllyRowAndPos:
            res += "Chosse an allied row and pos";
            break;
        case SelectEnemyRowAndPos:
            res += "Chosse an enemy row and pos";
            break;
        case Target:
            res += "Chosse an ability option";
            break;
        }
        if (snapShot.cardSource != nullptr)
            res += " (" + snapShot.cardSource->name + ")";
    }
    if (res.size() == 0)
        return "Card stack is empty...";
    return res;
}

// TODO: is only 1 player
bool tryFinishTurn(Field &ally, Field &enemy)
{
    if (ally.cardStack.size() > 0) {
        std::cout << stringSnapShots(ally.cardStack) << " (" << (ally.cardStack.size() ? ally.snapshot().cardOptions.size() : 0) << ")" << std::endl;
        return false;
    }

    // finish turn
    for (Card *_card : united(Rows{ally.rowMeele, ally.rowRange, ally.rowSeige}))
        _card->onTurnEnd(ally, enemy);

    ally.nTurns++;

    // start next turn
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
