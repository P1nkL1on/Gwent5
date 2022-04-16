#include "view.h"

#include <map>
#include <cassert>


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

FieldView fieldView(const Field &field)
{
    std::map<const Card *, CardView> cardToView;

    int cardViewId = 0;
    for (const Card *card : field.deckStarting)
        cardToView.insert({card, cardView(card, cardViewId++)});
    for (const Card *card : field.cardsAdded)
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
    for (const Choice &choice : field.cardStack) {
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
    for (const Card *card : field.rowMeele)
        res.rowMeeleIds.push_back(id(card));
    for (const Card *card : field.rowRange)
        res.rowRangeIds.push_back(id(card));
    for (const Card *card : field.rowSeige)
        res.rowSeigeIds.push_back(id(card));
    for (const Card *card : field.hand)
        res.handIds.push_back(id(card));
    for (const Card *card : field.deck)
        res.deckIds.push_back(id(card));
    for (const Card *card : field.discard)
        res.discardIds.push_back(id(card));
    res.rowEffectMeele = field.rowEffectMeele;
    res.rowEffectRange = field.rowEffectRange;
    res.rowEffectSeige = field.rowEffectSeige;
    res.nTurns = field.nTurns;
    res.nRounds = field.nRounds;
    res.nWins = field.nWins;
    res.passed = field.passed;

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
