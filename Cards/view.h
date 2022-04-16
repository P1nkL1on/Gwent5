#ifndef VIEW_H
#define VIEW_H

#include "card.h"


struct CardView
{
    int id = -1;
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
    int id = -1;
    ChoiceType choiceType;
    int cardSourceId = -1;
    std::vector<int> cardOptionIds;
    std::vector<int> cardOptionIdsSelected;
    int nTargets = 1;
    bool isOptional = false;

    std::string toString() const;
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
    int srcId = -1;
    int dstId = -1;
};


struct FieldView
{
    std::vector<CardView> cards; /// ally + enemy
    std::vector<ChoiceView> choices;
    std::vector<int> allyRowMeeleIds;
    std::vector<int> allyRowRangeIds;
    std::vector<int> allyRowSeigeIds;
    std::vector<int> allyHandIds;
    std::vector<int> allyDeckIds;
    std::vector<int> allyDiscardIds;
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

    CardView &cardView(const int id);
    const CardView &cardView(const int id) const;
    bool idAtRowAndPos(const Row screenRow, const Pos screenPos, int *id = nullptr, int *n = nullptr) const;
    bool rowAndPos(const int id, Row *row = nullptr, Pos *pos = nullptr, bool *isAlly = nullptr) const;
    RowEffect rowEffect(const Row screenRow) const;
    int rowPower(const Row screenRow) const;
};

bool isIn(const int id, const std::vector<int> &vector);
CardView cardView(const Card *card, const int id);
FieldView fieldView(const Field &ally, const Field &enemy);

#endif // VIEW_H
