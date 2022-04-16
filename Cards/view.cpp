#include "view.h"

#include <map>
#include <cassert>

#include "card.h"

CardView cardView(const Card *card, const int id)
{
    CardView view;
    view.id = id;
    view.power = card->power;
    view.powerBase = card->powerBase;
    view.armor = card->armor;
    view.rarity = card->rarity;
    view.timer = card->timer;
    view.faction = card->faction;
    view.tags = card->tags;
    view.isLocked = card->isLocked;
    view.isSpy = card->isSpy;
    view.isResilient = card->isResilient;
    view.isAmbush = card->isAmbush;
    view.isImmune = card->isImmune;
    view.isDoomed = card->isDoomed;
    view.name = card->name;
    view.text = card->text;
    view.url = card->url;
    return view;
}

FieldView fieldView(const Field &ally, const Field &enemy)
{
    std::map<const Card *, CardView> cardToView;

    int cardViewId = 0;
    for (const Card *card : ally.deckStarting)
        cardToView.insert({card, cardView(card, cardViewId++)});
    for (const Card *card : ally.cardsAdded)
        cardToView.insert({card, cardView(card, cardViewId++)});
    for (const Card *card : enemy.deckStarting)
        cardToView.insert({card, cardView(card, cardViewId++)});
    for (const Card *card : enemy.cardsAdded)
        cardToView.insert({card, cardView(card, cardViewId++)});
    /// add extra crads that are just options)
    for (const Choice &choice : ally.cardStack)
        for (const Card *card : choice.cardOptions)
            cardToView.insert({card, cardView(card, cardViewId++)});

    const auto id = [cardToView](const Card *card) -> int {
        if (card == nullptr)
            return -1;
        if (cardToView.find(card) == cardToView.end())
            return -1;
        return cardToView.at(card).id;
    };

    std::vector<ChoiceView> choiceViews;

    int choiceViewId = 0;
    for (const Choice &choice : ally.cardStack) {
        ChoiceView view;
        view.id = choiceViewId++;
        view.choiceType = choice.choiceType;
        view.cardSourceId = id(choice.cardSource);
        view.nTargets = choice.nTargets;
        view.isOptional = choice.isOptional;
        for (const Card *card : choice.cardOptions)
            view.cardOptionIds.push_back(id(card));
        for (const Card *card : choice.cardOptionsSelected)
            view.cardOptionIdsSelected.push_back(id(card));
        choiceViews.push_back(view);
    }

    FieldView res;

    // TODO: check hidden cards
    for (const Card *card : ally.rowMeele)
        res.allyRowMeeleIds.push_back(id(card));
    for (const Card *card : ally.rowRange)
        res.allyRowRangeIds.push_back(id(card));
    for (const Card *card : ally.rowSeige)
        res.allyRowSeigeIds.push_back(id(card));
    for (const Card *card : ally.hand)
        res.allyHandIds.push_back(id(card));
    for (const Card *card : ally.deck)
        res.allyDeckIds.push_back(id(card));
    for (const Card *card : ally.discard)
        res.allyDiscardIds.push_back(id(card));
    for (const Card *card : enemy.rowMeele)
        res.enemyRowMeeleIds.push_back(id(card));
    for (const Card *card : enemy.rowRange)
        res.enemyRowRangeIds.push_back(id(card));
    for (const Card *card : enemy.rowSeige)
        res.enemyRowSeigeIds.push_back(id(card));
    for (const Card *card : enemy.hand)
        res.enemyHandIds.push_back(id(card));
    for (const Card *card : enemy.deck)
        res.enemyDeckIds.push_back(id(card));
    for (const Card *card : enemy.discard)
        res.enemyDiscardIds.push_back(id(card));
    res.allyRowEffectMeele = ally.rowEffectMeele;
    res.allyRowEffectRange = ally.rowEffectRange;
    res.allyRowEffectSeige = ally.rowEffectSeige;
    res.enemyRowEffectMeele = enemy.rowEffectMeele;
    res.enemyRowEffectRange = enemy.rowEffectRange;
    res.enemyRowEffectSeige = enemy.rowEffectSeige;
    res.nPowerRowAllyMeele = powerRow(ally.rowMeele);
    res.nPowerRowAllyRange = powerRow(ally.rowRange);
    res.nPowerRowAllySeige = powerRow(ally.rowSeige);
    res.nPowerRowEnemyMeele = powerRow(enemy.rowMeele);
    res.nPowerRowEnemyRange = powerRow(enemy.rowRange);
    res.nPowerRowEnemySeige = powerRow(enemy.rowSeige);
    res.nTurns = ally.nTurns;
    res.nRounds = ally.nRounds;
    res.nAllyWins = ally.nWins;
    res.allyPassed = ally.passed; 
    res.nEnemyWins = enemy.nWins;
    res.enemyPassed = enemy.passed;

    /// move all cards to a vector
    for (const std::pair<const Card *, CardView> &cardAndViewPair : cardToView)
        res.cards.push_back(std::move(cardAndViewPair.second));
    /// move all choices
    res.choices = std::move(choiceViews);

    return res;
}

bool isIn(const int id, const std::vector<int> &vector)
{
    for (const int _id : vector)
        if (id == _id)
            return true;
    return false;
}

CardView &FieldView::cardView(const int id)
{
    assert(id > -1);
    for (CardView &cardView : cards)
        if (cardView.id == id)
            return cardView;
    assert(false);
}

const CardView &FieldView::cardView(const int id) const
{
    assert(id > -1);
    for (const CardView &cardView : cards)
        if (cardView.id == id)
            return cardView;
    assert(false);
}

bool FieldView::idAtRowAndPos(const Row screenRow, const Pos screenPos, int *id, int *n) const
{
    assert((0 <= screenRow) && (screenRow < 6));
    assert((0 <= screenPos) && (screenPos < 9));

    const std::vector<int> *rowIds = nullptr;
    switch (screenRow) {
    case 0: rowIds = &enemyRowSeigeIds; break;
    case 1: rowIds = &enemyRowRangeIds; break;
    case 2: rowIds = &enemyRowMeeleIds; break;
    case 3: rowIds = &allyRowMeeleIds;  break;
    case 4: rowIds = &allyRowRangeIds;  break;
    case 5: rowIds = &allyRowSeigeIds;  break;
    default: assert(false);             break;
    }

    if (n)
        *n = int(rowIds->size());

    if (size_t(screenPos) >= rowIds->size())
        return false;

    if (id)
        *id = rowIds->at(size_t(screenPos));

    return true;
}

bool FieldView::rowAndPos(const int id, Row *row, Pos *pos, bool *isAlly) const
{
    Row _row;
    Pos _pos;
    bool _isAlly;
    for (size_t i = 0; i < allyRowMeeleIds.size(); ++i)
        if (id == allyRowMeeleIds[i]) {
            _row = Meele;
            _pos = Pos(i);
            _isAlly = true;
            goto found;
        }
    for (size_t i = 0; i < allyRowRangeIds.size(); ++i)
        if (id == allyRowRangeIds[i]) {
            _row = Range;
            _pos = Pos(i);
            _isAlly = true;
            goto found;
        }
    for (size_t i = 0; i < allyRowSeigeIds.size(); ++i)
        if (id == allyRowSeigeIds[i]) {
            _row = Seige;
            _pos = Pos(i);
            _isAlly = true;
            goto found;
        }
    for (size_t i = 0; i < enemyRowMeeleIds.size(); ++i)
        if (id == enemyRowMeeleIds[i]) {
            _row = Meele;
            _pos = Pos(i);
            _isAlly = false;
            goto found;
        }
    for (size_t i = 0; i < enemyRowRangeIds.size(); ++i)
        if (id == enemyRowRangeIds[i]) {
            _row = Range;
            _pos = Pos(i);
            _isAlly = false;
            goto found;
        }
    for (size_t i = 0; i < enemyRowSeigeIds.size(); ++i)
        if (id == enemyRowSeigeIds[i]) {
            _row = Seige;
            _pos = Pos(i);
            _isAlly = false;
            goto found;
        }
    return false;

found:
    if (row)
        *row = _row;
    if (pos)
        *pos = _pos;
    if (isAlly)
        *isAlly = _isAlly;
    return true;
}

RowEffect FieldView::rowEffect(const Row screenRow) const
{
    assert((0 <= screenRow) && (screenRow < 6));
    switch (screenRow) {
    case 0: return enemyRowEffectSeige;
    case 1: return enemyRowEffectRange;
    case 2: return enemyRowEffectMeele;
    case 3: return allyRowEffectMeele;
    case 4: return allyRowEffectRange;
    case 5: return allyRowEffectSeige;
    default: assert(false);
    }
    return NoRowEffect;
}

int FieldView::rowPower(const Row screenRow) const
{
    assert((0 <= screenRow) && (screenRow < 6));
    switch (screenRow) {
    case 0: return nPowerRowEnemySeige;
    case 1: return nPowerRowEnemyRange;
    case 2: return nPowerRowEnemyMeele;
    case 3: return nPowerRowAllyMeele;
    case 4: return nPowerRowAllyRange;
    case 5: return nPowerRowAllySeige;
    default: assert(false);
    }
    return 0;
}

std::string ChoiceView::toString() const
{
    switch (choiceType) {
    case RoundStartPlay:
        return "Choose a card to play";
    case SelectAllyRowAndPos:
        return "Choose an allied row and pos";
    case SelectEnemyRowAndPos:
        return "Choose an enemy row and pos";
    case SelectAllyRow:
        return "Choose an allied row";
    case SelectEnemyRow:
        return "Choose an enemy row";
    case Target: {
        std::string res = "Choose an ability option";
        if ((nTargets > 1) || isOptional) {
            res += " [";
            if (isOptional)
                res += "optional";
            if (nTargets > 1) {
                if (isOptional)
                    res += " ";
                res += std::to_string(cardOptionIdsSelected.size()) + "/" + std::to_string(nTargets);
            }
            res += "]";
        }
        return res;
    }
    case RoundStartSwap:
        return "Choose a card to swap [" + std::to_string(nTargets) + " left]";
    }
    assert(false);
}
