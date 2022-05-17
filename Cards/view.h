#ifndef VIEW_H
#define VIEW_H

#include <string>
#include <map>
#include <vector>

#include "enums.h"

struct CardView
{
    int id = -1;
    int power = 0;
    int powerBase = 0;
    int armor = 0;
    int rarity = 0;
    int timer = 0;
    int count = 1;

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
    std::string urlLarge;
};


struct ChoiceView
{
    int id = -1;
    ChoiceType choiceType;
    int cardSourceId = -1;
    std::vector<int> cardOptionIds;
    std::vector<int> cardOptionIdsSelected;
    int nTargets = 1;
    bool isOptional = false;

    std::string toString() const;
};


struct FieldView
{
    std::vector<CardView> cards; /// ally + enemy
    std::vector<ChoiceView> choices;
    int allyLeader = -1;
    std::vector<int> allyRowMeeleIds;
    std::vector<int> allyRowRangeIds;
    std::vector<int> allyRowSeigeIds;
    std::vector<int> allyHandIds;
    std::vector<int> allyDeckIds;
    std::vector<int> allyDiscardIds;
    int enemyLeader = -1;
    std::vector<int> enemyRowMeeleIds;
    std::vector<int> enemyRowRangeIds;
    std::vector<int> enemyRowSeigeIds;
    std::vector<int> enemyHandIds;
    std::vector<int> enemyDeckIds;
    std::vector<int> enemyDiscardIds;
    RowEffect allyRowEffectMeele = NoRowEffect;
    RowEffect allyRowEffectRange = NoRowEffect;
    RowEffect allyRowEffectSeige = NoRowEffect;
    RowEffect enemyRowEffectMeele = NoRowEffect;
    RowEffect enemyRowEffectRange = NoRowEffect;
    RowEffect enemyRowEffectSeige = NoRowEffect;
    int nPowerRowAllyMeele = 0;
    int nPowerRowAllyRange = 0;
    int nPowerRowAllySeige = 0;
    int nPowerRowEnemyMeele = 0;
    int nPowerRowEnemyRange = 0;
    int nPowerRowEnemySeige = 0;
    int nTurns = 0;
    int nRounds = 0;
    int nAllyWins = 0;
    int nEnemyWins = 0;
    bool allyPassed = false;
    bool enemyPassed = false;

    std::string actionSound;
    ActionType actionType;
    int actionIdSrc = -1;
    int actionValue = -1;
    std::vector<int> actionIdsDst;

    CardView &cardView(const int id);
    const CardView &cardView(const int id) const;
    bool idAtRowAndPos(const Row screenRow, const Pos screenPos, int *id = nullptr, int *n = nullptr) const;
    bool rowAndPos(const int id, Row *row = nullptr, Pos *pos = nullptr, bool *isAlly = nullptr) const;
    RowEffect rowEffect(const Row screenRow) const;
    int rowPower(const Row screenRow) const;
};

struct Card;
struct Field;

bool isIn(const int id, const std::vector<int> &vector);
CardView cardView(const Card *card, const int id);
std::vector<CardView> cardOptionViews(const Card *card);
/// returns a field view and a cardToCardViewMap if any pointer given
FieldView fieldView(const Field &ally, const Field &enemy, const ActionType actionType = Invalid, const Card *src = nullptr, const std::vector<Card *> &dst = {}, const std::string &sound = "", const int actionValue = -1);
std::string stringRarity(const Rarity rarity);
std::string stringTag(const Tag tag);
bool isLeader(const CardView &view);

#endif // VIEW_H
