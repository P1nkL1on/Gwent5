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
    /// on a field
    Any,
    Ally,
    Enemy,
    /// others
    AllyHand,
    AllyDiscard,
    AllyDeckShuffled,
    AllyDeck,
    AllyDeckStarting,
    AllyBoardHandDeck,
};


enum Lang
{
    En,
    Ru,
};

#endif // ENUMS_H
