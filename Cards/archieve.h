#ifndef CARDS_H
#define CARDS_H

#include "card.h"


/// returns all cards in games (no tokens included)
std::vector<Card *> allCards(const Patch);


struct AddaStriga : CardCollectible<AddaStriga>
{
    AddaStriga();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *, Field &, Field &) override;
};


struct Dao : CardCollectible<Dao>
{
    struct DaoLesser : CardCollectible<DaoLesser>
    {
        DaoLesser();
    };
    Dao();
    void onDestroy(Field &ally, Field &enemy, const Row row, const Pos pos) override;
};


struct PoorFingInfantry : CardCollectible<PoorFingInfantry>
{
    struct LeftFlankInfantry : CardCollectible<LeftFlankInfantry>
    {
        LeftFlankInfantry();

    };
    struct RightFlankInfantry : CardCollectible<RightFlankInfantry>
    {
        RightFlankInfantry();
    };
    PoorFingInfantry();
    void onDeploy(Field &ally, Field &enemy) override;
};


struct DeithwenArbalest : CardCollectible<DeithwenArbalest>
{
    DeithwenArbalest();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct TemerianDrummer : CardCollectible<TemerianDrummer>
{
    TemerianDrummer();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct DandelionPoet : CardCollectible<DandelionPoet>
{
    DandelionPoet();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct SileDeTansarville : CardCollectible<SileDeTansarville>
{
    SileDeTansarville();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct RedanianKnightElect : CardCollectible<RedanianKnightElect>
{
    RedanianKnightElect();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTurnEnd(Field &ally, Field &enemy) override;
};


struct KaedweniKnight : CardCollectible<KaedweniKnight>
{
    KaedweniKnight();
    void onDeploy(Field &ally, Field &enemy) override;
    void onDeployFromDeck(Field &ally, Field &enemy) override;
};


struct AnCraiteMarauder : CardCollectible<AnCraiteMarauder>
{
    AnCraiteMarauder();
};


struct AnCraiteGreatsword : CardCollectible<AnCraiteGreatsword>
{
    AnCraiteGreatsword();
    void onDeploy(Field &, Field &) override;
    void onTurnStart(Field &ally, Field &enemy) override;
};


struct DimunLightLongship : CardCollectible<DimunLightLongship>
{
    DimunLightLongship();
    void onTurnEnd(Field &ally, Field &enemy) override;
};


struct Bear : CardCollectible<Bear>
{
    Bear();
};


struct Wolf : CardCollectible<Wolf>
{
    Wolf();
};


struct TuirseachBearmaster : CardCollectible<TuirseachBearmaster>
{
    TuirseachBearmaster();
    void onDeploy(Field &ally, Field &enemy) override;
};


struct TuirseachHunter : CardCollectible<TuirseachHunter>
{
    TuirseachHunter();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct RedanianElite : CardCollectible<RedanianElite>
{
    RedanianElite();
    void onDeploy(Field &ally, Field &enemy) override;
    void onArmorLost(Field &ally, Field &enemy) override;
};


struct RedanianKnight : CardCollectible<RedanianKnight>
{
    RedanianKnight();
    void onTurnEnd(Field &ally, Field &enemy) override;
};


struct KaedweniCavalry : CardCollectible<KaedweniCavalry>
{
    KaedweniCavalry();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct AlzursThunder : CardCollectible<AlzursThunder>
{
    AlzursThunder();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Swallow : CardCollectible<Swallow>
{
    Swallow();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Thunderbolt : CardCollectible<Thunderbolt>
{
    Thunderbolt();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct ArachasVenom : CardCollectible<ArachasVenom>
{
    ArachasVenom();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct KeiraMetz : CardCollectible<KeiraMetz>
{
    KeiraMetz();
    void onDeploy(Field &ally, Field &/*enemy*/) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct DolBlathannaArcher : CardCollectible<DolBlathannaArcher>
{
    DolBlathannaArcher();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
private:
    int _nShots = 0;
};


struct HalfElfHunter : CardCollectible<HalfElfHunter>
{
    HalfElfHunter();
    void onDeploy(Field &ally, Field &enemy) override;
private:
    bool _maySpawnCopy = true;
};


struct Ambassador : CardCollectible<Ambassador>
{
    Ambassador();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Assassin : CardCollectible<Assassin>
{
    Assassin();
    void onDeploy(Field &ally, Field &enemy) override;
};


struct Emissary : CardCollectible<Emissary>
{
    Emissary();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct CeallachDyffryn : CardCollectible<CeallachDyffryn>
{
    CeallachDyffryn();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct TuirseachArcher : CardCollectible<TuirseachArcher>
{
    TuirseachArcher();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Infiltrator : CardCollectible<Infiltrator>
{
    Infiltrator();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &, Field &) override;
};


struct ImpenetrableFog : CardCollectible<ImpenetrableFog>
{
    ImpenetrableFog();
    void onPlaySpecial(Field &ally, Field &) override;
    void onTargetRowEnemyChoosen(Field &ally, Field &enemy, const Row row) override;
};


struct TorrentialRain : CardCollectible<TorrentialRain>
{
    TorrentialRain();
    void onPlaySpecial(Field &ally, Field &) override;
    void onTargetRowEnemyChoosen(Field &ally, Field &enemy, const Row row) override;
};


struct BitingFrost : CardCollectible<BitingFrost>
{
    BitingFrost();
    void onPlaySpecial(Field &ally, Field &) override;
    void onTargetRowEnemyChoosen(Field &ally, Field &enemy, const Row row) override;
};


struct GoldenFroth : CardCollectible<GoldenFroth>
{
    GoldenFroth();
    void onPlaySpecial(Field &ally, Field &) override;
    void onTargetRowAllyChoosen(Field &ally, Field &enemy, const Row row) override;
};


struct SkelligeStorm : CardCollectible<SkelligeStorm>
{
    SkelligeStorm();
    void onPlaySpecial(Field &ally, Field &) override;
    void onTargetRowEnemyChoosen(Field &ally, Field &enemy, const Row row) override;
};


struct ImperialManticore : CardCollectible<ImperialManticore>
{
    ImperialManticore();
};


struct ManticoreVenom : CardCollectible<ManticoreVenom>
{
    ManticoreVenom();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct GloriousHunt : CardCollectible<GloriousHunt>
{
    GloriousHunt();
    void onPlaySpecial(Field &ally, Field &enemy) override;
};


struct Ves : CardCollectible<Ves>
{
    Ves();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Vaedermakar : CardCollectible<Vaedermakar>
{
    Vaedermakar();
    void onDeploy(Field &ally, Field &) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Frightener : CardCollectible<Frightener>
{
    Frightener();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Cleaver : CardCollectible<Cleaver>
{
    Cleaver();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Scorch : CardCollectible<Scorch>
{
    Scorch();
    void onPlaySpecial(Field &ally, Field &enemy) override;
};


struct Reinforcements : CardCollectible<Reinforcements>
{
    Reinforcements();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct JohnNatalis : CardCollectible<JohnNatalis>
{
    JohnNatalis();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Eleyas : CardCollectible<Eleyas>
{
    Eleyas();
    void onDraw(Field &ally, Field &enemy) override;
    void onSwap(Field &ally, Field &enemy) override;
};


struct ReaverScout : CardCollectible<ReaverScout>
{
    ReaverScout();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct HeymaeySpearmaiden : CardCollectible<HeymaeySpearmaiden>
{
    HeymaeySpearmaiden();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct VriheddSappers : CardCollectible<VriheddSappers>
{
    VriheddSappers();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTurnStart(Field &ally, Field &enemy) override;
};


struct PriestessOfFreya : CardCollectible<PriestessOfFreya>
{
    PriestessOfFreya();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct DimunCorsair : CardCollectible<DimunCorsair>
{
    DimunCorsair();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Sigrdrifa : CardCollectible<Sigrdrifa>
{
    Sigrdrifa();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct DrummondQueensguard : CardCollectible<DrummondQueensguard>
{
    DrummondQueensguard();
    void onDeploy(Field &ally, Field &enemy) override;
};


struct Sage : CardCollectible<Sage>
{
    Sage();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Reconnaissance : CardCollectible<Reconnaissance>
{
    Reconnaissance();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct ElvenMercenary : CardCollectible<ElvenMercenary>
{
    ElvenMercenary();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct ChampionOfHov : CardCollectible<ChampionOfHov>
{
    ChampionOfHov();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Priscilla : CardCollectible<Priscilla>
{
    Priscilla();
    void onDeploy(Field &ally, Field &enemy) override;
};


struct SeltkirkOfGulet : CardCollectible<SeltkirkOfGulet>
{
    SeltkirkOfGulet();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct AdrenalineRush : CardCollectible<AdrenalineRush>
{
    AdrenalineRush();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Mandrake : CardCollectible<Mandrake>
{
    Mandrake();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
private:
    struct Buff : CardCollectible<Buff> {};
    struct Debuff : CardCollectible<Debuff> {};
    Card *_choosen = nullptr;
};


struct BoneTalisman : CardCollectible<BoneTalisman>
{
    BoneTalisman();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
private:
    struct Buff : CardCollectible<Buff> {};
    struct Resurrect : CardCollectible<Resurrect> {};
    Card *_choosen = nullptr;
};


struct Restore : CardCollectible<Restore>
{
    Restore();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Decoy : CardCollectible<Decoy>
{
    Decoy();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct ShupesDayOff : CardCollectible<ShupesDayOff>
{
    ShupesDayOff();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct ShupeKnight : CardCollectible<ShupeKnight>
{
    ShupeKnight();
    static bool isFourOrLessPower(Card *card);
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
private:
    struct Destroy : CardCollectible<Destroy> {};
    struct Reset : CardCollectible<Reset> {};
    struct Duel : CardCollectible<Duel> {};
    struct Strengthen : CardCollectible<Strengthen> {};
    struct Resilient : CardCollectible<Resilient> {};
    Card *_choosen = nullptr;
};


struct ShupeHunter : CardCollectible<ShupeHunter>
{
    ShupeHunter();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
private:
    struct Play : CardCollectible<Play> {};
    struct Shot : CardCollectible<Shot> {};
    struct Replay : CardCollectible<Replay> {};
    struct Clear : CardCollectible<Clear> {};
    struct Barrage : CardCollectible<Barrage> {};
    Card *_choosen = nullptr;
};


struct ShupeMage : CardCollectible<ShupeMage>
{
    ShupeMage();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
private:
    struct Draw : CardCollectible<Draw> {};
    struct Charm : CardCollectible<Charm> {};
    struct Hazards : CardCollectible<Hazards> {};
    struct Meteor : CardCollectible<Meteor> {};
    struct Play : CardCollectible<Play> {};
    Card *_choosen = nullptr;
};


struct FirstLight : CardCollectible<FirstLight>
{
    FirstLight();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
private:
    struct Clear : CardCollectible<Clear> {};
    struct Play : CardCollectible<Play> {};
};


struct ClearSkies : CardCollectible<ClearSkies>
{
    ClearSkies();
    void onPlaySpecial(Field &ally, Field &enemy) override;
};


struct Epidemic : CardCollectible<Epidemic>
{
    Epidemic();
    void onPlaySpecial(Field &ally, Field &enemy) override;
};


struct Moonlight : CardCollectible<Moonlight>
{
    Moonlight();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
    void onTargetRowAllyChoosen(Field &ally, Field &enemy, const Row row) override;
    void onTargetRowEnemyChoosen(Field &ally, Field &enemy, const Row row) override;
private:
    struct FullMoon : CardCollectible<FullMoon> {};
    struct BloodMoon : CardCollectible<BloodMoon> {};
};


struct CiriNova : CardCollectible<CiriNova>
{
    CiriNova();
    void onDeploy(Field &ally, Field &enemy) override;
};


struct HaraldTheCripple : CardCollectible<HaraldTheCripple>
{
    HaraldTheCripple();
    void onDeploy(Field &ally, Field &enemy) override;
};


struct BranTuirseach : CardCollectible<BranTuirseach>
{
    BranTuirseach();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct DrummondWarmonger : CardCollectible<DrummondWarmonger>
{
    DrummondWarmonger();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct DimunPirate : CardCollectible<DimunPirate>
{
    DimunPirate();
    void onDeploy(Field &ally, Field &enemy) override;
};


struct AnCraiteRaider : CardCollectible<AnCraiteRaider>
{
    AnCraiteRaider();
    void onDiscard(Field &ally, Field &enemy) override;
};


struct MadmanLugos : CardCollectible<MadmanLugos>
{
    MadmanLugos();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
private:
    Card *_discarded = nullptr;
};


struct Ermion : CardCollectible<Ermion>
{
    Ermion();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct CerysFearless : CardCollectible<CerysFearless>
{
    CerysFearless();
    void onDeploy(Field &ally, Field &enemy) override;
    void onOtherAllyDiscarded(Card *other, Field &ally, Field &enemy) override;
};


struct CerysAnCraite : CardCollectible<CerysAnCraite>
{
    CerysAnCraite();
    void onDiscard(Field &ally, Field &enemy) override;
    void onDestroy(Field &ally, Field &enemy, const Row, const Pos) override;
    void onOtherAllyResurrectededWhileOnDiscard(Card *other, Field &ally, Field &enemy) override;
};


struct WoodlandSpirit : CardCollectible<WoodlandSpirit>
{
    WoodlandSpirit();
    void onDeploy(Field &ally, Field &enemy) override;
};


struct Trollololo : CardCollectible<Trollololo>
{
    Trollololo();
    void onDeploy(Field &ally, Field &enemy) override;
};


struct PrinceStennis : CardCollectible<PrinceStennis>
{
    PrinceStennis();
    void onDeploy(Field &ally, Field &enemy) override;
};

struct VincentMeis : CardCollectible<VincentMeis>
{
    VincentMeis();
    void onDeploy(Field &ally, Field &enemy) override;
};


struct Morkvarg : CardCollectible<Morkvarg>
{
    Morkvarg();
    void onDiscard(Field &ally, Field &enemy) override;
    void onDestroy(Field &ally, Field &enemy, const Row row, const Pos pos) override;
};


struct ArtefactCompression : CardCollectible<ArtefactCompression>
{
    ArtefactCompression();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct HjalmarAnCraite : CardCollectible<HjalmarAnCraite>
{
    struct LordOfUndvik : CardCollectible<LordOfUndvik>
    {
        LordOfUndvik();
        void onDestroy(Field &ally, Field &enemy, const Row, const Pos) override;
    };
    HjalmarAnCraite();
    void onDeploy(Field &ally, Field &enemy) override;
};

struct Regis : CardCollectible<Regis>
{
    Regis();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct LethoOfGulet : CardCollectible<LethoOfGulet>
{
    LethoOfGulet();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct AnCraiteLongship : CardCollectible<AnCraiteLongship>
{
    AnCraiteLongship();
    void onDeploy(Field &ally, Field &enemy) override;
    void onOtherAllyDiscarded(Card *other, Field &ally, Field &enemy) override;
};


struct GeraltIgni : CardCollectible<GeraltIgni>
{
    GeraltIgni(const Lang lang = En);
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetRowEnemyChoosen(Field &ally, Field &enemy, const Row row) override;
};


struct GeraltOfRivia : CardCollectible<GeraltOfRivia>
{
    GeraltOfRivia();
};


struct TuirseachVeteran : CardCollectible<TuirseachVeteran>
{
    TuirseachVeteran();
    void onDeploy(Field &ally, Field &enemy) override;
};


struct Udalryk : CardCollectible<Udalryk>
{
    Udalryk();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
private:
    std::vector<Card *> _drawn;
};


struct BloodcurdlingRoar : CardCollectible<BloodcurdlingRoar>
{
    BloodcurdlingRoar();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Gremist : CardCollectible<Gremist>
{
    Gremist();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct ZoriaRunestone : CardCollectible<ZoriaRunestone>
{
    ZoriaRunestone();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Operator : CardCollectible<Operator>
{
    Operator();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct Renew : CardCollectible<Renew>
{
    Renew();
    void onPlaySpecial(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct EistTuirseach : CardCollectible<EistTuirseach>
{
    EistTuirseach();
    void onDeploy(Field &ally, Field &enemy) override;
    void onTargetChoosen(Card *target, Field &ally, Field &enemy) override;
};


struct TuirseachAxeman : CardCollectible<TuirseachAxeman>
{
    TuirseachAxeman();
    void onDeploy(Field &ally, Field &enemy) override;
    void onOtherEnemyDamaged(Card *other, Field &ally, Field &enemy) override;
};


struct Derran : CardCollectible<Derran>
{
    Derran();
    void onOtherEnemyDamaged(Card *, Field &ally, Field &enemy) override;
};


struct TuirseachSkirmisher : CardCollectible<TuirseachSkirmisher>
{
    TuirseachSkirmisher();
    void onDeployFromDiscard(Field &ally, Field &enemy) override;
};


struct Roach : CardCollectible<Roach>
{
    Roach();
    void onOtherAllyPlayedWhileOnDeck(Card *other, Field &ally, Field &enemy) override;
};


#endif // CARDS_H
