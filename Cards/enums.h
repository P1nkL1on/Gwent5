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
    ClanHeymaey,
    ClanDimun,
    ClanTuirseach,
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
    /// on a table
    Any,
    Ally,
    Enemy,
    /// others
    AllyHand,
    AllyDiscard,
    AllyDeckShuffled,
    AllyDeck,
    AllyDeckStarting,
};


enum Lang
{
    En,
    Ru,
};

#endif // ENUMS_H
