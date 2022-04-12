#ifndef CARDS_H
#define CARDS_H

#include "card.h"

struct AddaStriga : Card
{
    AddaStriga();
    static bool isNonMonster(Card *card);
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *, Field &, Field &) override;
};


struct Dao : Card
{
    struct DaoLesser : Card
    {
        DaoLesser();
    };
    Dao();
    void onDestroy(Field &, Field &) override;
};

struct PoorFingInfantry : Card
{
    struct LeftFlankInfantry : Card
    {
        LeftFlankInfantry();

    };
    struct RightFlankInfantry : Card
    {
        RightFlankInfantry();
    };
    PoorFingInfantry();
    void onEnter(Field &ally, Field &enemy) override;
};

struct DeithwenArbalest : Card
{
    DeithwenArbalest();
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};

struct TemerianDrummer : Card
{
    TemerianDrummer();
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};

struct DandelionPoet : Card
{
    DandelionPoet();
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};

struct SileDeTansarville : Card
{
    SileDeTansarville();
    static bool isBronzeOrSilverSpecialCard(Card *card);
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};

struct RedanianKnightElect : Card
{
    RedanianKnightElect();
    void onEnter(Field &ally, Field &enemy) override;
    void onTurnEnd(Field &ally, Field &enemy) override;
};

struct KaedweniKnight : Card
{
    KaedweniKnight();
    void onEnter(Field &ally, Field &enemy) override;
    void onEnterFromDeck(Field &ally, Field &enemy) override;
};

struct AnCraiteMarauder : Card
{
    AnCraiteMarauder();
};

struct AnCraiteGreatsword : Card
{
    AnCraiteGreatsword();
    void onEnter(Field &, Field &) override;
    void onTurnStart(Field &ally, Field &enemy) override;
};

struct DimunDracar : Card
{
    DimunDracar();
    void onTurnEnd(Field &ally, Field &enemy) override;
};

struct Bear : Card
{
    Bear();
};

struct TuirseachBearmaster : Card
{
    TuirseachBearmaster();
    void onEnter(Field &ally, Field &enemy) override;
};

struct RedanianElite : Card
{
    RedanianElite();
    void onEnter(Field &ally, Field &enemy) override;
    void onArmorLost(Field &ally, Field &enemy) override;
};

struct RedanianKnight : Card
{
    RedanianKnight();
    void onEnter(Field &ally, Field &enemy) override;
    void onTurnEnd(Field &ally, Field &enemy) override;
};

struct KaedweniCavalry : Card
{
    KaedweniCavalry();
    static bool hasArmor(Card *card);
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};

struct AlzursThunder : Card
{
    AlzursThunder();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};

struct Swallow : Card
{
    Swallow();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};

struct Thunderbolt : Card
{
    Thunderbolt();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};

struct ArachasVenom : Card
{
    ArachasVenom();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};

struct KeiraMetz : Card
{
    KeiraMetz();
    void onEnter(Field &ally, Field &/*enemy*/) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
private:
    Card *_c1 = nullptr;
    Card *_c2 = nullptr;
    Card *_c3 = nullptr;
};

struct DolBlathannaArcher : Card
{
    DolBlathannaArcher();
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
private:
    int _nShots = 0;
};

struct HalfElfHunter : Card
{
    HalfElfHunter();
    void onEnter(Field &ally, Field &enemy) override;
private:
    bool _maySpawnCopy = true;
};

struct Ambassador : Card
{
    Ambassador();
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};

struct Assassin : Card
{
    Assassin();
    void onEnter(Field &ally, Field &enemy) override;
};

struct TuirseachArcher : Card
{
    TuirseachArcher();
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};

struct Infiltrator : Card
{
    Infiltrator();
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &, Field &) override;
};

struct ImpenetrableFog : Card
{
    ImpenetrableFog();
    void onPlaySpecial(Field &ally, Field &) override;
    RowEffect rowEffect() const override;
};

struct TorrentialRain : Card
{
    TorrentialRain();
    void onPlaySpecial(Field &ally, Field &) override;
    RowEffect rowEffect() const override;
};

struct BitingFrost : Card
{
    BitingFrost();
    void onPlaySpecial(Field &ally, Field &) override;
    RowEffect rowEffect() const override;
};

struct GoldenFroth : Card
{
    GoldenFroth();
    void onPlaySpecial(Field &ally, Field &) override;
    RowEffect rowEffect() const override;
};

struct SkelligeStorm : Card
{
    SkelligeStorm();
    void onPlaySpecial(Field &ally, Field &) override;
    RowEffect rowEffect() const override;
};

struct ImperialManticore : Card
{
    ImperialManticore();
};

struct ManticoreVenom : Card
{
    ManticoreVenom();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};

struct GloriousHunt : Card
{
    GloriousHunt();
    void onPlaySpecial(Field &ally, Field &enemy) override;
};

struct Ves : Card
{
    Ves();
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};

struct Vaedermakar : Card
{
    Vaedermakar();
    void onEnter(Field &ally, Field &) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
private:
    Card *_c1 = nullptr;
    Card *_c2 = nullptr;
    Card *_c3 = nullptr;
};

struct Frightener : Card
{
    Frightener();
    static bool isOnAnotherRow(Card *self, Card *card, const Field &field);
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};

struct Cleaver : Card
{
    Cleaver();
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};

struct Scorch : Card
{
    Scorch();
    void onPlaySpecial(Field &ally, Field &enemy) override;
};

struct Reinforcements : Card
{
    Reinforcements();
    static bool isBronzeOrSilverSoldierMachineOfficerOrSupport(Card *card);
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};

struct JohnNatalis : Card
{
    JohnNatalis();
    static bool isBronzeOrSilverTactics(Card *card);
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};

struct Eleyas : Card
{
    Eleyas();
    void onDraw(Field &ally, Field &enemy) override;
    void onSwap(Field &ally, Field &enemy) override;
};

struct ReaverScout : Card
{
    ReaverScout();
    static bool isDifferentBronzeAllyWhichHasCopyInADeck(Card *card, const Field &field);
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;

};

struct HeymaeySpearmaiden : Card
{
    HeymaeySpearmaiden();
    static bool isBronzeSoldierOrMachineAllyWhichHasCopyInADeck(Card *card, const Field &field);
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};

struct VriheddSappers : Card
{
    VriheddSappers();
    void onEnter(Field &ally, Field &enemy) override;
    void onTurnStart(Field &ally, Field &enemy) override;
};

struct PriestessOfFreya : Card
{
    PriestessOfFreya();
    static bool isBronzeSoldier(Card *card);
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};

#endif // CARDS_H
