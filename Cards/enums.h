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
    Insectoid,
    Necrophage,
    Draconid,

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
    WildHunt,

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
    EnemyHand,
    EnemyDeck,
    AnyHandShuffled,
    EnemyDiscard,
    AnyHandsShuffled,
    EnemyBoardAndHandRevealed,
    AllyBoardAndHandRevealed,
    AllyAppeared,
    BothAppeared,
};


enum ActionType {
    Invalid,
    TurnStart,
    PlaySpecial,
    PutOnField,
    PutToHand,
    PutToDiscard,
    Destroyed,
    Banished,
    DealDamage,
    Damaged,
    DamagedInArmor,
    Boosted,
    GainArmor,
    MoveFromRowToRow,
    TimerSet,
    FlipOver,
    GainLock,
    LostLock,
    GainSpy,
    LostSpy,
    Reveal,
    Conceal,
    Transform,
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
