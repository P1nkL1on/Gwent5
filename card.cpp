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

void playAsSpecial(Card *card, Field &ally, Field &enemy)
{
    card->onPlaySpecial();

    for (std::vector<Card *> &_vector : Rows{ally.rowMeele, ally.rowRange, ally.rowSeige})
        for (Card *_card : _vector)
            if (_card != card)
                _card->onOtherAllyPlaySpecial(card);

    for (std::vector<Card *> &_vector : Rows{enemy.rowMeele, enemy.rowRange, enemy.rowSeige})
        for (Card *_card : _vector)
            _card->onOtherEnemyPlaySpecial(card);
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

    for (std::vector<Card *> &_vector : Rows{ally.rowMeele, ally.rowRange, ally.rowSeige})
        for (Card *_card : _vector)
            if (_card != card)
                _card->onOtherAllyEnter(card);

    for (std::vector<Card *> &_vector : Rows{enemy.rowMeele, enemy.rowRange, enemy.rowSeige})
        for (Card *_card : _vector)
            _card->onOtherEnemyEnter(card);

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

bool startChoiceToPlayCard(Field &field)
{
    if (field.hand.size() == 0)
        return false;

    field.choice = Play;
    field.choiceBetween = field.hand;
    return true;
}

void onChoiceDoneCard(Card *card, Field &ally, Field &enemy)
{
    if (ally.choice == Play) {
        assert(card != nullptr);
        if (hasTag(card, Special)) {
            playAsSpecial(card, ally, enemy);
            return;
        }
        ally.choice = card->isSpy ? SelectEnemyRowAndPos : SelectAllyRowAndPos;
        ally.cardStack.push_back(card);
        return;

    } else if (ally.choice == Target) {
        if (card == nullptr) {
            ally.choice = NoChoice;
            ally.cardStack.pop_back();
            return;
        }

        ally.cardStack.back()->onTargetChoosen(card);
        ally.choice = NoChoice;
        ally.cardStack.pop_back();
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
    ally.choice = NoChoice;

    if (choice == SelectAllyRowAndPos)
        return putOnField(card, row, pos, ally, enemy);

    if (choice == SelectEnemyRowAndPos)
        return putOnField(card, row, pos, enemy, ally);

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

    for (size_t i = 0; i < field.choiceBetween.size(); ++i)
        std::cout << i << ": " << field.choiceBetween[i]->power << "\n";
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
    switch (_row) {
    case Meele:
        return rowMeele;
    case Range:
        return rowRange;
    case Seige:
        return rowSeige;
    }
    assert(false);
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
    }
    assert(false);
}

bool drawACard(Field &)
{
    return true;
}
