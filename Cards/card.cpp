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

void take(const Card *card, Field &field)
{
    std::vector<std::vector<Card *> *> cards {&field.rowMeele, &field.rowRange, &field.rowSeige, &field.hand, &field.deck, &field.discard};
    for (std::vector<Card *> *_cards : cards)
        for (size_t i = 0; i < _cards->size(); ++i)
            if (_cards->at(i) == card) {
                _cards->erase(_cards->begin() + int(i));
                return;
            }
    assert(false);
}

void playAsSpecial(Card *card, Field &ally, Field &enemy)
{
    card->onPlaySpecial();

    for (std::vector<Card *> &_vector : Rows{ally.rowMeele, ally.rowRange, ally.rowSeige, ally.hand, ally.deck})
        for (Card *_card : _vector)
            if (_card != card)
                _card->onOtherAllySpecialPlayed(card);

    for (std::vector<Card *> &_vector : Rows{enemy.rowMeele, enemy.rowRange, enemy.rowSeige, enemy.hand, enemy.deck})
        for (Card *_card : _vector)
            _card->onOtherEnemySpecialPlayed(card);
}

void putOnField(Card *card, const Row row, const Pos pos, Field &ally, Field &enemy)
{
    assert(isOkRowAndPos(row, pos, ally));

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
    }

    card->onEnter(row, pos, ally, enemy);

    for (std::vector<Card *> &_vector : Rows{ally.rowMeele, ally.rowRange, ally.rowSeige, ally.hand, ally.deck})
        for (Card *_card : _vector)
            if (_card != card)
                _card->onOtherAllyEntered(card);

    for (std::vector<Card *> &_vector : Rows{enemy.rowMeele, enemy.rowRange, enemy.rowSeige, enemy.hand, enemy.deck})
        for (Card *_card : _vector)
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

bool startChoiceToPlayCard(Field &field, const Filters &filters)
{
    if (field.hand.size() == 0)
        return false;

    field.choice = Play;
    field.choiceBetween = filtered(filters, field.hand);
    return true;
}

/// no need to pass self (leave as nullptr), if no ally cards involved
Filters canBeSelected(Card *self)
{
    return Filters{
        [self](Card *card) {
            return !card->isImmune && !card->isAmbush && (card != self);
        },
    };
}

bool startChoiceToTargetCard(Field &field, Card *self, const Filters &filters)
{
    const std::vector<Card *> allies = united(Rows{field.rowMeele, field.rowRange, field.rowSeige});
    field.choiceBetween = filtered(canBeSelected(self), filtered(filters, allies));
    if (field.choiceBetween.size() == 0)
        return false;

    field.choice = Target;
    field.cardStack.push_back(self);
    return true;
}

void onChoiceDoneCard(Card *card, Field &ally, Field &enemy)
{
    if (ally.choice == Play) {
        assert(card != nullptr);
        if (card->isSpecial) {
            playAsSpecial(card, ally, enemy);
            return;
        }
        ally.choice = card->isSpy ? SelectEnemyRowAndPos : SelectAllyRowAndPos;
        ally.cardStack.push_back(card);
        ally.choiceBetween.clear();
        return;

    } else if (ally.choice == Target) {
        if (card == nullptr)
            return disposeChoice(ally);;

        Card *cardSrc = ally.cardStack.back();
        disposeChoice(ally);

        cardSrc->onTargetChoosen(card, ally, enemy);
        return;
    }

    assert(false);
}

void onChoiceDoneRowAndPlace(const Row row, const Pos pos, Field &ally, Field &enemy)
{
    assert(ally.cardStack.size() > 0);

    Card *card = ally.cardStack.back();
    ally.cardStack.pop_back();

    const Choice choice = ally.choice;
    disposeChoice(ally);

    if (choice == SelectAllyRowAndPos) {
        take(card, ally);
        putOnField(card, row, pos, ally, enemy);
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

    switch (field.choice) {
    case NoChoice:
        return;
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

    for (Card *card : field.choiceBetween)
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

const std::vector<Card *> &Field::row(Row _row) const
{
    assert(_row == Meele || _row == Range || _row == Seige);

    switch (_row) {
    case Meele:
        return rowMeele;
    case Range:
        return rowRange;
    case Seige:
        return rowSeige;
    }
}

std::vector<Card *> &Field::row(Row _row)
{
    assert(_row == Meele || _row == Range || _row == Seige);

    switch (_row) {
    case Meele:
        return rowMeele;
    case Range:
        return rowRange;
    case Seige:
        return rowSeige;
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

void disposeChoice(Field &field)
{
    field.choice = NoChoice;
    field.cardStack.clear();
    field.choiceBetween.clear();
}
