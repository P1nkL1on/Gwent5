#ifndef FILTERS_H
#define FILTERS_H

#include "card.h"

/// inline bool (Card *card) { return card->; }
inline bool isUnit(Card *card) { return !card->isSpecial; }
inline bool isSpecial(Card *card) { return card->isSpecial; }
inline bool isBronze(Card *card) { return card->rarity == Bronze; }
inline bool isSilver(Card *card) { return card->rarity == Silver; }
inline bool isGold(Card *card) { return card->rarity == Gold; }
inline bool isLeader(Card *card) { return hasTag(card, Leader); }
inline bool isNonLeader(Card *card) { return !hasTag(card, Leader); }
inline bool isBronzeOrSilver(Card *card) { return (card->rarity == Bronze) || (card->rarity == Silver); }
inline bool isSilverOrGold(Card *card) { return card->rarity == Silver || card->rarity == Gold; }
inline bool isNonRevealed(Card *card) { return !card->isRevealed; }
inline bool isRevealed(Card *card) { return card->isRevealed; }
inline bool hasArmor(Card *card) { return card->armor > 0; }
inline bool isNothernRealmsFaction(Card *card) { return card->faction == NothernRealms; }
inline bool isSkelligeFaction(Card *card) { return card->faction == Skellige; }
inline bool isNonMonsterFaction(Card *card) { return card->faction != Monster; }
inline bool isNilfgaardFaction(Card *card) { return card->faction == Nilfgaard; }
inline bool isScoiataelFaction(Card *card) { return card->faction == Scoiatael; }
inline bool isMonsterFaction(Card *card) { return card->faction == Monster; }
inline bool isNonSpying(Card *card) { return card->isLoyal; }
inline bool isBoosted(Card *card) { return card->power > card->powerBase; }
inline bool isNotLocked(Card *card) { return !card->isLocked; }
inline bool isUndamaged(Card *card) { return card->power >= card->powerBase; }
inline bool isDamaged(Card *card) { return card->power < card->powerBase; }
inline bool isNonAgent(Card *card) { return !hasTag(card, Agent); }
inline bool isDeathwish(Card *card) { return card->hasDeathwish(); }
inline bool isCrew(Card *card) { return card->isCrew && !card->isLocked; }
inline bool isOnAllyApplyEffect(Card *card) { return card->hasOnAllyApplyEffect(); }
inline bool hasOddPower(Card *card) { return card->power % 2 != 0; }
inline bool hasEvenPower(Card *card) { return card->power % 2 == 0; }
template <typename T> inline bool isCopy(Card *card) { return dynamic_cast<T *>(card) != nullptr; }


using Filter = std::function<bool(Card *)>;

inline Filter isFaction(const int faction)
{
    return [faction](Card *card) {
        return card->faction == faction;
    };
}
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
inline Filter hasNoneOfTags(const std::vector<Tag> &tags)
{
    return [tags](Card *card) {
        for (const Tag &tag : tags)
            if (hasTag(card, tag))
                return false;
        return true;
    };
}
inline Filter hasNoTag(const Tag tag)
{
    return  [tag](Card *card) {
        return !hasTag(card, tag);
    };
}
inline Filter otherThan(const std::string &name)
{
    return [name](Card *card) {
        return card->name != name;
    };
}
inline Filter otherThan(const Card *card)
{
    return [card](Card *_card) {
        return card != _card;
    };
}
inline Filter isCopy(const std::string &name)
{
    return [name](Card *card) {
        return card->name == name;
    };
}
inline Filter hasPowerXorLess(const int x)
{
    return [x](Card *card) {
        return card->power <= x;
    };
}
inline Filter hasPowerX(const int x)
{
    return [x](Card *card) {
        return card->power == x;
    };
}
inline Filter hasCopyInADeck(const Field *field)
{
    return [field](Card *card) {
        return findCopy(card, field->deck) != nullptr;
    };
}
inline Filter hasCopyOnABoard(const Field *field)
{
    return [field](Card *card) {
        return findCopy(card, field->rowMeele) != nullptr
                || findCopy(card, field->rowRange) != nullptr
                || findCopy(card, field->rowSeige) != nullptr;
    };
}
inline Filter isOnSameRow(const Field *field, const Card *self)
{
    return [field, self](Card *card) {
        Row rowSelf;
        Pos _;
        if (!_findRowAndPos(self, *field, rowSelf, _))
            return false;
        Row rowCard;
        if (!_findRowAndPos(card, *field, rowCard, _))
            return false;
        return rowSelf == rowCard;
    };
}
inline Filter isOnAnotherRow(const Field *field, const Card *self)
{
    return [field, self](Card *card) {
        Row rowSelf;
        Pos _;
        if (!_findRowAndPos(self, *field, rowSelf, _))
            return false;
        Row rowCard;
        if (!_findRowAndPos(card, *field, rowCard, _))
            return false;
        return rowSelf != rowCard;
    };
}
inline Filter isOnOppositeRow(const Field *ally, const Field *enemy, const Card *self)
{
    return [ally, enemy, self](Card *card) {
        Row rowSelf;
        Pos _;
        if (!_findRowAndPos(self, *ally, rowSelf, _))
            return false;
        Row rowCard;
        if (!_findRowAndPos(card, *enemy, rowCard, _))
            return false;
        return rowSelf == rowCard;
    };
}
inline Filter isOnRow(const Field *field, const Row row)
{
    return [field, row](Card *card) {
        Row rowCard;
        Pos _;
        if (!_findRowAndPos(card, *field, rowCard, _))
            return false;
        return row == rowCard;
    };
}
inline Filter isNotOnRow(const Field *field, const Row row)
{
    return [field, row](Card *card) {
        Row rowCard;
        Pos _;
        if (!_findRowAndPos(card, *field, rowCard, _))
            return false;
        return row != rowCard;
    };
}

#endif // FILTERS_H
