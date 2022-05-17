#ifndef ENUMS_H
#define ENUMS_H

enum Row
{
    Meele,
    Range,
    Seige,
    Hand,
    Deck,
    Discard,
    /// special place, where leaders are played
    HandLeader,
    /// cards, spawned by other cards
    AlreadyCreated
};


using Pos = int;


struct RowAndPos
{
    RowAndPos() = default;
    RowAndPos(const Row row, const Pos pos) : row(row), pos(pos) {}

    Row row = Row(-1);
    Pos pos = Pos(-1);
};


enum Rarity
{
    Bronze,
    Silver,
    Gold
};


enum Tag
{
    Beast,
    Relict,
    Vampire,
    Construct,
    Elf,
    Dwarf,
    Aedirn,
    Temeria,
    Redania,
    Kaedwen,
    Cintra,
    ClanAnCraite,
    ClanBrokvar,
    ClanHeymaey,
    ClanDimun,
    ClanTordarroch,
    ClanTuirseach,
    ClanDrummond,
    Ogroid,

    Cursed,
    Support,
    Officer,
    Mage,
    Soldier,
    Machine,
    Agent,
    Witcher,
    Leader,
    Cultist,

    Alchemy,
    Tactics,
    Spell,
    Item,
    Organic,
    Hazard,
    Boon,

    Neutral,
    Monster,
    Nilfgaard,
    NothernRealms,
    Scoiatael,
    Skellige,
};


enum RowEffect
{
    NoRowEffect,
    /// Hazards
    TorrentialRainEffect,
    BitingFrostEffect,
    ImpenetrableFogEffect,
    SkelligeStormEffect,
    DragonsDreamEffect,
    KorathiHeatwaveEffect,
    RaghNarRoogEffect,
    BloodMoonEffect,
    PitTrapEffect,
    /// Boons
    GoldenFrothEffect,
    FullMoonEffect,
};


enum ChoiceType
{
    RoundStartPlay,
    SelectAllyRowAndPos,
    SelectEnemyRowAndPos,
    SelectAllyRow,
    SelectEnemyRow,
    Target,
    RoundStartSwap,
};


enum ChoiceGroup
{
    /// on a board
    AnyBoard,
    AllyBoard,
    EnemyBoard,
    /// others
    AllyHand,
    AllyDiscard,
    AllyDeckShuffled,
    AllyDeck,
    AllyDeckStarting,
    AllyBoardHandDeck,
    AllyAnywhere,
    EnemyAnywhere,
};


enum ActionType {
    Invalid,
    PlaySpecial,
    PutOnField,
    DealDamage,
    Damaged,
    GainArmor,
};


enum Lang
{
    En,
    Ru,
};


enum Patch
{
    PublicBeta_0_9_24_3_432,
};

#endif // ENUMS_H
