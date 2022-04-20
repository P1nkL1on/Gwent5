#ifndef FILTERS_H
#define FILTERS_H

#include "card.h"

/// inline bool (Card *card) { return card->; }
inline bool isUnit(Card *card) { return !card->isSpecial; }
inline bool isSpecial(Card *card) { return card->isSpecial; }
inline bool isBronze(Card *card) { return card->rarity == Bronze; }
inline bool isSilver(Card *card) { return card->rarity == Silver; }
inline bool isBronzeOrSilver(Card *card) { return (card->rarity == Bronze) || (card->rarity == Silver); }
inline bool hasArmor(Card *card) { return card->armor > 0; }
inline bool isSkelligeFaction(Card *card) { return card->faction == Skellige; }
inline bool isNonMonsterFaction(Card *card) { return card->faction != Monster; }
inline bool isNonSpying(Card *card) { return card->isLoyal; }
inline bool isBoosted(Card *card) { return card->power > card->powerBase; }



using Filter = std::function<bool(Card *)>;

inline Filter hasAnyOfTags(const std::vector<Tag> &tags)
{
    return [tags](Card *card) {
        for (const Tag &tag : tags)
            if (hasTag(card, tag))
                return true;
        return false;
    };
}
inline Filter hasAllOfTags(const std::vector<Tag> &tags)
{
    return [tags](Card *card) {
        for (const Tag &tag : tags)
            if (!hasTag(card, tag))
                return false;
        return true;
    };
}
inline Filter hasTag(const Tag tag)
{
    return [tag](Card *card) {
        return hasTag(card, tag);
    };
}
inline Filter otherThan(const std::string &name)
{
    return [name](Card *card) {
        return card->name != name;
    };
}
inline Filter isCopy(const std::string &name)
{
    return [name](Card *card) {
        return card->name == name;
    };
}
inline Filter hasCopyInADeck(const Field *field)
{
    return [field](Card *card) {
        return findCopy(card, field->deck) != nullptr;
    };
}
inline Filter isOnSameRow(const Field *field, const Card *self)
{
    return [field, self](Card *card) {
        Row rowSelf;
        Pos _;
        if (!rowAndPos(self, *field, rowSelf, _))
            return false;
        Row rowCard;
        if (!rowAndPos(card, *field, rowCard, _))
            return false;
        return rowSelf == rowCard;
    };
}
inline Filter isOnAnotherRow(const Field *field, const Card *self)
{
    return [field, self](Card *card) {
        Row rowSelf;
        Pos _;
        if (!rowAndPos(self, *field, rowSelf, _))
            return false;
        Row rowCard;
        if (!rowAndPos(card, *field, rowCard, _))
            return false;
        return rowSelf != rowCard;
    };
}

#endif // FILTERS_H
