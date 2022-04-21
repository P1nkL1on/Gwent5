#ifndef CARDS_H
#define CARDS_H

#include "card.h"


/// returns all cards in games (no tokens included)
std::vector<Card *> allCards(const Patch);


struct AddaStriga : CardCollectable<AddaStriga>
{
    AddaStriga();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *, Field &, Field &) override;
};


struct Dao : CardCollectable<Dao>
{
    struct DaoLesser : CardCollectable<DaoLesser>
    {
        DaoLesser();
    };
    Dao();
    void onDestroy(Field &ally, Field &enemy, const Row row, const Pos pos) override;
};


struct PoorFingInfantry : CardCollectable<PoorFingInfantry>
{
    struct LeftFlankInfantry : CardCollectable<LeftFlankInfantry>
    {
        LeftFlankInfantry();

    };
    struct RightFlankInfantry : CardCollectable<RightFlankInfantry>
    {
        RightFlankInfantry();
    };
    PoorFingInfantry();
    void onDeploy(Field &ally, Field &enemy) override;
};


struct DeithwenArbalest : CardCollectable<DeithwenArbalest>
{
    DeithwenArbalest();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct TemerianDrummer : CardCollectable<TemerianDrummer>
{
    TemerianDrummer();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct DandelionPoet : CardCollectable<DandelionPoet>
{
    DandelionPoet();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct SileDeTansarville : CardCollectable<SileDeTansarville>
{
    SileDeTansarville();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct RedanianKnightElect : CardCollectable<RedanianKnightElect>
{
    RedanianKnightElect();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTurnEnd(Field &ally, Field &enemy) override;
};


struct KaedweniKnight : CardCollectable<KaedweniKnight>
{
    KaedweniKnight();
    void onDeploy(Field &ally, Field &enemy) override;
    void onDeployFromDeck(Field &ally, Field &enemy) override;
};


struct AnCraiteMarauder : CardCollectable<AnCraiteMarauder>
{
    AnCraiteMarauder();
};


struct AnCraiteGreatsword : CardCollectable<AnCraiteGreatsword>
{
    AnCraiteGreatsword();
    void onDeploy(Field &, Field &) override;
    void onTurnStart(Field &ally, Field &enemy) override;
};


struct DimunDracar : CardCollectable<DimunDracar>
{
    DimunDracar();
    void onTurnEnd(Field &ally, Field &enemy) override;
};


struct Bear : CardCollectable<Bear>
{
    Bear();
};


struct Wolf : CardCollectable<Wolf>
{
    Wolf();
};


struct TuirseachBearmaster : CardCollectable<TuirseachBearmaster>
{
    TuirseachBearmaster();
    void onDeploy(Field &ally, Field &enemy) override;
};


struct TuirseachHunter : CardCollectable<TuirseachHunter>
{
    TuirseachHunter();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct RedanianElite : CardCollectable<RedanianElite>
{
    RedanianElite();
    void onDeploy(Field &ally, Field &enemy) override;
    void onArmorLost(Field &ally, Field &enemy) override;
};


struct RedanianKnight : CardCollectable<RedanianKnight>
{
    RedanianKnight();
    void onTurnEnd(Field &ally, Field &enemy) override;
};


struct KaedweniCavalry : CardCollectable<KaedweniCavalry>
{
    KaedweniCavalry();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct AlzursThunder : CardCollectable<AlzursThunder>
{
    AlzursThunder();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Swallow : CardCollectable<Swallow>
{
    Swallow();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Thunderbolt : CardCollectable<Thunderbolt>
{
    Thunderbolt();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct ArachasVenom : CardCollectable<ArachasVenom>
{
    ArachasVenom();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct KeiraMetz : CardCollectable<KeiraMetz>
{
    KeiraMetz();
    void onDeploy(Field &ally, Field &/*enemy*/) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct DolBlathannaArcher : CardCollectable<DolBlathannaArcher>
{
    DolBlathannaArcher();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
private:
    int _nShots = 0;
};


struct HalfElfHunter : CardCollectable<HalfElfHunter>
{
    HalfElfHunter();
    void onDeploy(Field &ally, Field &enemy) override;
private:
    bool _maySpawnCopy = true;
};


struct Ambassador : CardCollectable<Ambassador>
{
    Ambassador();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Assassin : CardCollectable<Assassin>
{
    Assassin();
    void onDeploy(Field &ally, Field &enemy) override;
};


struct Emissary : CardCollectable<Emissary>
{
    Emissary();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct CeallachDyffryn : CardCollectable<CeallachDyffryn>
{
    CeallachDyffryn();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct TuirseachArcher : CardCollectable<TuirseachArcher>
{
    TuirseachArcher();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Infiltrator : CardCollectable<Infiltrator>
{
    Infiltrator();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &, Field &) override;
};


struct ImpenetrableFog : CardCollectable<ImpenetrableFog>
{
    ImpenetrableFog();
    void onPlaySpecial(Field &ally, Field &) override;
    void onTargetRowEnemyChoosen(Field &ally, Field &enemy, const Row row) override;
};


struct TorrentialRain : CardCollectable<TorrentialRain>
{
    TorrentialRain();
    void onPlaySpecial(Field &ally, Field &) override;
    void onTargetRowEnemyChoosen(Field &ally, Field &enemy, const Row row) override;
};


struct BitingFrost : CardCollectable<BitingFrost>
{
    BitingFrost();
    void onPlaySpecial(Field &ally, Field &) override;
    void onTargetRowEnemyChoosen(Field &ally, Field &enemy, const Row row) override;
};


struct GoldenFroth : CardCollectable<GoldenFroth>
{
    GoldenFroth();
    void onPlaySpecial(Field &ally, Field &) override;
    void onTargetRowAllyChoosen(Field &ally, Field &enemy, const Row row) override;
};


struct SkelligeStorm : CardCollectable<SkelligeStorm>
{
    SkelligeStorm();
    void onPlaySpecial(Field &ally, Field &) override;
    void onTargetRowEnemyChoosen(Field &ally, Field &enemy, const Row row) override;
};


struct ImperialManticore : CardCollectable<ImperialManticore>
{
    ImperialManticore();
};


struct ManticoreVenom : CardCollectable<ManticoreVenom>
{
    ManticoreVenom();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct GloriousHunt : CardCollectable<GloriousHunt>
{
    GloriousHunt();
    void onPlaySpecial(Field &ally, Field &enemy) override;
};


struct Ves : CardCollectable<Ves>
{
    Ves();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Vaedermakar : CardCollectable<Vaedermakar>
{
    Vaedermakar();
    void onDeploy(Field &ally, Field &) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Frightener : CardCollectable<Frightener>
{
    Frightener();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Cleaver : CardCollectable<Cleaver>
{
    Cleaver();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Scorch : CardCollectable<Scorch>
{
    Scorch();
    void onPlaySpecial(Field &ally, Field &enemy) override;
};


struct Reinforcements : CardCollectable<Reinforcements>
{
    Reinforcements();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct JohnNatalis : CardCollectable<JohnNatalis>
{
    JohnNatalis();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Eleyas : CardCollectable<Eleyas>
{
    Eleyas();
    void onDraw(Field &ally, Field &enemy) override;
    void onSwap(Field &ally, Field &enemy) override;
};


struct ReaverScout : CardCollectable<ReaverScout>
{
    ReaverScout();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct HeymaeySpearmaiden : CardCollectable<HeymaeySpearmaiden>
{
    HeymaeySpearmaiden();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct VriheddSappers : CardCollectable<VriheddSappers>
{
    VriheddSappers();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTurnStart(Field &ally, Field &enemy) override;
};


struct PriestessOfFreya : CardCollectable<PriestessOfFreya>
{
    PriestessOfFreya();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct DimunCorsair : CardCollectable<DimunCorsair>
{
    DimunCorsair();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Sigrdrifa : CardCollectable<Sigrdrifa>
{
    Sigrdrifa();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct DrummondQueensguard : CardCollectable<DrummondQueensguard>
{
    DrummondQueensguard();
    void onDeploy(Field &ally, Field &enemy) override;
};


struct Sage : CardCollectable<Sage>
{
    Sage();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Reconnaissance : CardCollectable<Reconnaissance>
{
    Reconnaissance();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct ElvenMercenary : CardCollectable<ElvenMercenary>
{
    ElvenMercenary();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct ChampionOfHov : CardCollectable<ChampionOfHov>
{
    ChampionOfHov();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Priscilla : CardCollectable<Priscilla>
{
    Priscilla();
    void onDeploy(Field &ally, Field &enemy) override;
};


struct SeltkirkOfGulet : CardCollectable<SeltkirkOfGulet>
{
    SeltkirkOfGulet();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct AdrenalineRush : CardCollectable<AdrenalineRush>
{
    AdrenalineRush();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Mandrake : CardCollectable<Mandrake>
{
    Mandrake();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
private:
    struct Buff : CardCollectable<Buff> {};
    struct Debuff : CardCollectable<Debuff> {};
    Card *_choosen = nullptr;
};


struct BoneTalisman : CardCollectable<BoneTalisman>
{
    BoneTalisman();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
private:
    struct Buff : CardCollectable<Buff> {};
    struct Resurrect : CardCollectable<Resurrect> {};
    Card *_choosen = nullptr;
};


struct Restore : CardCollectable<Restore>
{
    Restore();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Decoy : CardCollectable<Decoy>
{
    Decoy();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct ShupesDayOff : CardCollectable<ShupesDayOff>
{
    ShupesDayOff();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct ShupeKnight : CardCollectable<ShupeKnight>
{
    ShupeKnight();
    static bool isFourOrLessPower(Card *card);
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
private:
    struct Destroy : CardCollectable<Destroy> {};
    struct Reset : CardCollectable<Reset> {};
    struct Duel : CardCollectable<Duel> {};
    struct Strengthen : CardCollectable<Strengthen> {};
    struct Resilient : CardCollectable<Resilient> {};
    Card *_choosen = nullptr;
};


struct ShupeHunter : CardCollectable<ShupeHunter>
{
    ShupeHunter();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
private:
    struct Play : CardCollectable<Play> {};
    struct Shot : CardCollectable<Shot> {};
    struct Replay : CardCollectable<Replay> {};
    struct Clear : CardCollectable<Clear> {};
    struct Barrage : CardCollectable<Barrage> {};
    Card *_choosen = nullptr;
};


struct ShupeMage : CardCollectable<ShupeMage>
{
    ShupeMage();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
private:
    struct Draw : CardCollectable<Draw> {};
    struct Charm : CardCollectable<Charm> {};
    struct Hazards : CardCollectable<Hazards> {};
    struct Meteor : CardCollectable<Meteor> {};
    struct Play : CardCollectable<Play> {};
    Card *_choosen = nullptr;
};


struct FirstLight : CardCollectable<FirstLight>
{
    FirstLight();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
private:
    struct Clear : CardCollectable<Clear> {};
    struct Play : CardCollectable<Play> {};
};


struct ClearSkies : CardCollectable<ClearSkies>
{
    ClearSkies();
    void onPlaySpecial(Field &ally, Field &enemy) override;
};


struct Epidemic : CardCollectable<Epidemic>
{
    Epidemic();
    void onPlaySpecial(Field &ally, Field &enemy) override;
};


struct Moonlight : CardCollectable<Moonlight>
{
    Moonlight();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
    void onTargetRowAllyChoosen(Field &ally, Field &enemy, const Row row) override;
    void onTargetRowEnemyChoosen(Field &ally, Field &enemy, const Row row) override;
private:
    struct FullMoon : CardCollectable<FullMoon> {};
    struct BloodMoon : CardCollectable<BloodMoon> {};
};


struct CiriNova : CardCollectable<CiriNova>
{
    CiriNova();
    void onDeploy(Field &ally, Field &enemy) override;
};


struct HaraldTheCripple : CardCollectable<HaraldTheCripple>
{
    HaraldTheCripple();
    void onDeploy(Field &ally, Field &enemy) override;
};


struct BranTuirseach : CardCollectable<BranTuirseach>
{
    BranTuirseach();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct DrummondWarmonger : CardCollectable<DrummondWarmonger>
{
    DrummondWarmonger();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct DimunPirate : CardCollectable<DimunPirate>
{
    DimunPirate();
    void onDeploy(Field &ally, Field &enemy) override;
};


struct AnCraiteRaider : CardCollectable<AnCraiteRaider>
{
    AnCraiteRaider();
    void onDiscard(Field &ally, Field &enemy) override;
};


struct MadmanLugos : CardCollectable<MadmanLugos>
{
    MadmanLugos();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
private:
    Card *_discarded = nullptr;
};


struct Ermion : CardCollectable<Ermion>
{
    Ermion();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct CerysFearless : CardCollectable<CerysFearless>
{
    CerysFearless();
    void onDeploy(Field &ally, Field &enemy) override;
    void onOtherAllyDiscarded(Card *other, Field &ally, Field &enemy) override;
};


struct CerysAnCraite : CardCollectable<CerysAnCraite>
{
    CerysAnCraite();
    void onDiscard(Field &ally, Field &enemy) override;
    void onDestroy(Field &ally, Field &enemy, const Row, const Pos) override;
    void onOtherAllyResurrectededWhileOnDiscard(Card *other, Field &ally, Field &enemy) override;
};


struct WoodlandSpirit : CardCollectable<WoodlandSpirit>
{
    WoodlandSpirit();
    void onDeploy(Field &ally, Field &enemy) override;
};


struct Trollololo : CardCollectable<Trollololo>
{
    Trollololo();
    void onDeploy(Field &ally, Field &enemy) override;
};


struct PrinceStennis : CardCollectable<PrinceStennis>
{
    PrinceStennis();
    void onDeploy(Field &ally, Field &enemy) override;
};

struct VincentMeis : CardCollectable<VincentMeis>
{
    VincentMeis();
    void onDeploy(Field &ally, Field &enemy) override;
};


struct Morkvarg : CardCollectable<Morkvarg>
{
    Morkvarg();
    void onDiscard(Field &ally, Field &enemy) override;
    void onDestroy(Field &ally, Field &enemy, const Row row, const Pos pos) override;
};


struct ArtefactCompression : CardCollectable<ArtefactCompression>
{
    ArtefactCompression();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct HjalmarAnCraite : CardCollectable<HjalmarAnCraite>
{
    struct  LordOfUndvik : CardCollectable<LordOfUndvik>
    {
        LordOfUndvik();
        void onDestroy(Field &ally, Field &enemy, const Row, const Pos) override;
    };
    HjalmarAnCraite();
    void onDeploy(Field &ally, Field &enemy) override;
};

struct Regis : CardCollectable<Regis>
{
    Regis();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct LethoOfGulet : CardCollectable<LethoOfGulet>
{
    LethoOfGulet();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct AnCraiteLongship : CardCollectable<AnCraiteLongship>
{
    AnCraiteLongship();
    void onDeploy(Field &ally, Field &enemy) override;
    void onOtherAllyDiscarded(Card *other, Field &ally, Field &enemy) override;
};


struct GeraltIgni : CardCollectable<GeraltIgni>
{
    GeraltIgni(const Lang lang = En);
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetRowEnemyChoosen(Field &ally, Field &enemy, const Row row) override;
};


struct TuirseachVeteran : CardCollectable<TuirseachVeteran>
{
    TuirseachVeteran();
    void onDeploy(Field &ally, Field &enemy) override;
};


struct Udalryk : CardCollectable<Udalryk>
{
    Udalryk();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
private:
    std::vector<Card *> _drawn;
};


struct BloodcurdlingRoar : CardCollectable<BloodcurdlingRoar>
{
    BloodcurdlingRoar();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Gremist : CardCollectable<Gremist>
{
    Gremist();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct ZoriaRunestone : CardCollectable<ZoriaRunestone>
{
    ZoriaRunestone();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Operator : CardCollectable<Operator>
{
    Operator();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};

#endif // CARDS_H
