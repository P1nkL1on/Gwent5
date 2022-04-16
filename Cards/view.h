#ifndef VIEW_H
#define VIEW_H

#include "card.h"

struct CardView
{
    int id = 0;
    int power = 0;
    int powerBase = 0;
    int armor = 0;
    int rarity = 0;
    int timer = 0;

    int faction = Neutral;
    std::vector<Tag> tags;

    bool isLocked = false;
    bool isSpy = false;
    bool isResilient = false;
    bool isAmbush = false;
    bool isImmune = false;
    bool isDoomed = false;

    std::string name;
    std::string text;
    std::string url;
};

struct ChoiceView
{
    int id = 0;
    ChoiceType choiceType;
    Card *cardSource = nullptr;
    std::vector<int> cardOptionIds;
    std::vector<int> cardOptionIdsSelected;
    int nTargets = 1;
    bool isOptional = false;
};

struct Animation
{
    enum Type {
        Draw,
        PutOnField,
        Spawn,
        PlaySpecial,
        ArmorAllLost,
        /// Line
        LineDamage,
        /// Texts
        ArmorGainText,
        DamageText,
        BoostText,
        StrengthenText,
        WeakenText
    };
    std::string sound;
    Type type;
    int srcId = 0;
    int dstId = 0;
};

struct FieldView
{
    std::vector<CardView> cards;
    std::vector<ChoiceView> choices;
    std::vector<int> rowMeeleIds;
    std::vector<int> rowRangeIds;
    std::vector<int> rowSeigeIds;
    std::vector<int> handIds;
    std::vector<int> deckIds;
    std::vector<int> discardIds;
    std::vector<int> cardStackIds;
    RowEffect rowEffectMeele = NoRowEffect;
    RowEffect rowEffectRange = NoRowEffect;
    RowEffect rowEffectSeige = NoRowEffect;
    int nTurns = 0;
    int nRounds = 0;
    int nWins = 0;
    bool passed = false;
};

#endif // VIEW_H
