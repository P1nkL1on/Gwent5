#ifndef ENUMS_H
#define ENUMS_H

#include <string>

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
using Id = std::string;

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
    Ogroid,
    Insectoid,
    Necrophage,
    Draconid,
    Vodyanoi,
    Elf,
    Dwarf,
    Dryad,
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
    CardRoundStartPlay,
    CardRoundStartSwap,
    CardTarget,
    CardOption,
    RowAndPosAlly,
    RowAndPosEnemy,
    RowSelect,
};


enum ChoiceGroup
{
    /// on a board
    AnyBoard,
    AllyBoard,
    EnemyBoard,
    /// on a board or smt
    AllyBoardHandDeck,
    EnemyBoardAndHandRevealed,
    AllyBoardAndHandRevealed,
    AllyAnywhere,
    EnemyAnywhere,
    AllyAppeared,
    BothAppeared,
    /// others
    AllyHand,
    EnemyHand,
    AnyHandShuffled,
    AllyDiscard,
    EnemyDiscard,
    BothDiscard,
    AllyDeck,
    EnemyDeck,
    AllyDeckShuffled,
    AllyDeckStarting,
    EnemyDeckStarting,
    BothDeckStarting,
    AnyCard,
};


enum DeckPos
{
    DeckPosTop,
    DeckPosBottom,
    DeckPosRandom,
    DeckPosRandomButNotFirst,
};


enum PowerChangeType
{
    Damage,
    Reset,
    Boost
};


enum ActionType
{
    Invalid,
    TurnStart,
    PassedAlly,
    PassedEnemy,
    WonRoundAlly,
    WonRoundEnemy,
    WonRoundBoth,
    WonGameAlly,
    WonGameEnemy,
    WonGameBoth,
    RoundStart,
    MulliganSkipAlly,
    MulliganSkipEnemy,
    PlaySpecial,
    PutOnField,
    PutToHand,
    PutToDiscard,
    PutToTopDeck,
    PutToBottomDeck,
    ShuffleToDeck,
    Destroyed,
    Banished,
    DealDamage,
    Damaged,
    DamagedInArmor,
    Weakened,
    ResetAsInDeckBuilder,
    ResetInPower,
    StrippedOfAllStatuses,
    Boosted,
    Strengthened,
    Healed,
    HealedBy,
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
