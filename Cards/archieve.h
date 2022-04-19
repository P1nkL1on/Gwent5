#ifndef CARDS_H
#define CARDS_H

#include "card.h"


struct AddaStriga : Card
{
    AddaStriga();
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
    void onDestroy(Field &ally, Field &enemy, const Row row, const Pos pos) override;
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


struct Wolf : Card
{
    Wolf();
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
    void onTurnEnd(Field &ally, Field &enemy) override;
};


struct KaedweniCavalry : Card
{
    KaedweniCavalry();
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


struct Emissary : Card
{
    Emissary();
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct CeallachDyffryn : Card
{
    CeallachDyffryn();
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
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
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct JohnNatalis : Card
{
    JohnNatalis();
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
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct HeymaeySpearmaiden : Card
{
    HeymaeySpearmaiden();
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
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct DimunCorsair : Card
{
    DimunCorsair();
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Sigrdrifa : Card
{
    Sigrdrifa();
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct DrummondQueensguard : Card
{
    DrummondQueensguard();
    void onEnter(Field &ally, Field &enemy) override;
};


struct Sage : Card
{
    Sage();
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Reconnaissance : Card
{
    Reconnaissance();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct ElvenMercenary : Card
{
    ElvenMercenary();
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct ChampionOfHov : Card
{
    ChampionOfHov();
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Priscilla : Card
{
    Priscilla();
    void onEnter(Field &ally, Field &enemy) override;
};


struct SeltkirkOfGulet : Card
{
    SeltkirkOfGulet();
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct AdrenalineRush : Card
{
    AdrenalineRush();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Mandrake : Card
{
    Mandrake();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
private:
    struct Buff : Card {};
    struct Debuff : Card {};
    Card *_choosen = nullptr;
};


struct BoneTalisman : Card
{
    BoneTalisman();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
private:
    struct Buff : Card {};
    struct Resurrect : Card {};
    Card *_choosen = nullptr;
};


struct Restore : Card
{
    Restore();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Decoy : Card
{
    Decoy();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct ShupesDayOff : Card
{
    ShupesDayOff();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct ShupeKnight : Card
{
    ShupeKnight();
    static bool isFourOrLessPower(Card *card);
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
private:
    struct Destroy : Card {};
    struct Reset : Card {};
    struct Duel : Card {};
    struct Strengthen : Card {};
    struct Resilient : Card {};
    Card *_choosen = nullptr;
};


struct ShupeHunter : Card
{
    ShupeHunter();
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
private:
    struct Play : Card {};
    struct Shot : Card {};
    struct Replay : Card {};
    struct Clear : Card {};
    struct Barrage : Card {};
    Card *_choosen = nullptr;
};


struct ShupeMage : Card
{
    ShupeMage();
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
private:
    struct Draw : Card {};
    struct Charm : Card {};
    struct Hazards : Card {};
    struct Meteor : Card {};
    struct Play : Card {};
    Card *_choosen = nullptr;
};


struct FirstLight : Card
{
    FirstLight();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
private:
    struct Clear : Card {};
    struct Play : Card {};
};


struct Epidemic : Card
{
    Epidemic();
    void onPlaySpecial(Field &ally, Field &enemy) override;
};


struct Moonlight : Card
{
    Moonlight();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
    RowEffect rowEffect() const override;
private:
    struct FullMoon : Card {};
    struct BloodMoon : Card {};
    bool _isFullMoon = false;
};


struct CiriNova : Card
{
    CiriNova();
    void onEnter(Field &ally, Field &enemy) override;
};


struct HaraldTheCripple : Card
{
    HaraldTheCripple();
    void onEnter(Field &ally, Field &enemy) override;
};


struct BranTuirseach : Card
{
    BranTuirseach();
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct DrummondWarmonger : Card
{
    DrummondWarmonger();
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct DimunPirate : Card
{
    DimunPirate();
    void onEnter(Field &ally, Field &enemy) override;
};


struct AnCraiteRaider : Card
{
    AnCraiteRaider();
    void onDiscard(Field &ally, Field &enemy) override;
};


struct MadmanLugos : Card
{
    MadmanLugos();
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
private:
    Card *_discarded = nullptr;
};


struct Ermion : Card
{
    Ermion();
    void onEnter(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct CerysFearless : Card
{
    CerysFearless();
    void onEnter(Field &ally, Field &enemy) override;
    void onOtherAllyDiscarded(Card *other, Field &ally, Field &enemy) override;
};


struct CerysAnCraite : Card
{
    CerysAnCraite();
    void onDiscard(Field &ally, Field &enemy) override;
    void onDestroy(Field &ally, Field &enemy, const Row, const Pos) override;
    void onOtherAllyResurrectededWhileOnDiscard(Card *other, Field &ally, Field &enemy) override;
};


struct WoodlandSpirit : Card
{
    WoodlandSpirit();
    void onEnter(Field &ally, Field &enemy) override;
};


struct Trollololo : Card
{
    Trollololo();
    void onEnter(Field &ally, Field &enemy) override;
};


struct PrinceStennis : Card
{
    PrinceStennis();
    void onEnter(Field &ally, Field &enemy) override;
};

struct VincentMeis : Card
{
    VincentMeis();
    void onEnter(Field &ally, Field &enemy) override;
};


struct GeraltIgni : Card
{
    GeraltIgni(const Lang lang = En);
};


#endif // CARDS_H
