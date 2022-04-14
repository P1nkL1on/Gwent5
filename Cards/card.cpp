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

    /// shuffle a deck
    shuffle(field.deck);

    // TODO: remove test units
    for (int i = 1; i <= 9; ++i) {
        auto *c = new Card;
        c->name = "Dummy";
        c->url = "https://gwent.one/image/card/low/cid/png/113201.png";
        c->power = c->powerBase = i;
        field.rowMeele.push_back(c);
    }
    for (int i = 10; i <= 15; ++i) {
        auto *c = new Card;
        c->name = "Dummy";
        c->url = "https://gwent.one/image/card/low/cid/png/113201.png";
        c->power = c->powerBase = i;
        field.rowRange.push_back(c);
    }
}

void startNextRound(Field &ally, Field &enemy)
{
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
    ally.cardStack.push_back(Snapshot(RoundStartSwap, nullptr, ally.hand, nSwap, true));
    enemy.cardStack.push_back(Snapshot(RoundStartSwap, nullptr, enemy.hand, nSwap, true));
}

void shuffle(std::vector<Card *> &cards)
{
    // TODO: random must be used
    std::shuffle(std::begin(cards), std::end(cards), std::default_random_engine {});
}

std::vector<Card *> randoms(const std::vector<Card *> &cards, const int nRandoms)
{
    std::vector<Card *> res;

    std::vector<Card *> tmp = cards;
    for (int n = 0; n < nRandoms; ++n) {
        if (tmp.size() == 0)
            break;
        const auto ind = std::default_random_engine{}() % tmp.size();
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
    card->onPlaySpecial(ally, enemy);

    // TODO: others trigger special
}

void playACard(Card *card, Field &ally, Field &enemy)
{
    assert(card != nullptr);
    if (card->isSpecial) {
        playAsSpecial(card, ally, enemy);
        putOnDiscard(card, ally, enemy);
        return;
    }
    return ally.cardStack.push_back(Snapshot(card->isSpy ? SelectEnemyRowAndPos : SelectAllyRowAndPos, card));
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

    // TODO: others trigger enter

    const std::string sound = [=]{
        if (card->sounds.size() > 0) {
            // TODO: random
            const size_t ind = std::default_random_engine{}() % card->sounds.size();
            return card->sounds[ind];
        }
        return std::string();
    }();

    ally.animations.push_back(new Animation(sound, Animation::PutOnField, card));
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

    ally.cardStack.push_back(Snapshot(Target, self, cards, nTargets, isOptional));
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
        /// passed
        if (card == nullptr) {
            ally.passed = true;
            return;
        }
        assert(snapshot.nTargets == 1);
        return playACard(card, ally, enemy);
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
    ally.cardStack.push_back(Snapshot(RoundStartPlay, nullptr, ally.hand, 1, true));
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
    return res[std::default_random_engine{}() % res.size()];
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
    return res[std::default_random_engine{}() % res.size()];
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
    const int ind = 1 + (std::default_random_engine {})() % ally.deck.size();
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
        if (damage(second, first->power, ally, enemy))
            break;
        std::swap(first, second);
    }
}

bool damage(Card *card, const int x, Field &ally, Field &enemy)
{
    // TODO: check death and rest
    assert(x > 0);

    int dmgInPower = x;

    if (card->armor > 0) {
        const int dmgInArmor = std::min(card->armor, x);
        dmgInPower = std::max(0, x - card->armor);
        card->armor -= dmgInArmor;

        if (card->power > dmgInPower){
            card->onArmorLost(ally, enemy);
//            addAnimation(new AnimationText(card->name + " armor lost"), ally, enemy);
        }

        if (dmgInPower == 0)
            return false;
    }
    card->power -= dmgInPower;

    if (card->power > 0) {
        card->onDamaged(dmgInPower, ally, enemy);
//        addAnimation(new AnimationText(card->name + " damaged"), ally, enemy);
        // TODO: trigger other on damaged
        return false;
    }

    destroy(card, ally, enemy);
    return true;
}

void boost(Card *card, const int x, Field &ally, Field &enemy)
{
    assert(x > 0);

    card->power += x;

//    addAnimation(new AnimationText(card->name + " boosted"), ally, enemy);

    // TODO: others trigger on boosted
}

void strengthen(Card *card, const int x, Field &ally, Field &enemy)
{
    assert(x > 0);

    card->power += x;
    card->powerBase += x;

//    addAnimation(new AnimationText(card->name + " strenghten"), ally, enemy);

    // TODO: others trigger on strengthen
}

void weaken(Card *card, const int x, Field &ally, Field &enemy)
{
    assert(x > 0);

    card->power -= x;
    card->powerBase -= x;

//    addAnimation(new AnimationText(card->name + " weaken"), ally, enemy);

    if (card->powerBase < 0)
        return banish(card, ally, enemy);

    // TODO: others trigger on weaken
}

void gainArmor(Card *card, const int x, Field &ally, Field &enemy)
{
    assert(x > 0);

    card->armor += x;

//    addAnimation(new AnimationText(card->name + " gain armor"), ally, enemy);
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
                res += "optional";
            if (snapShot.nTargets > 1) {
                if (snapShot.isOptional)
                    res += " ";
                res += std::to_string(snapShot.cardOptionsSelected.size()) + "/" + std::to_string(snapShot.nTargets);
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
    enemy.cardStack.push_back(Snapshot(RoundStartPlay, nullptr, enemy.hand, 1, true));
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
