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

#endif // FILTERS_H
