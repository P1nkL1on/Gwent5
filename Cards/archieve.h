#ifndef CARDS_H
#define CARDS_H

#include "card.h"


/// returns all cards in games (no tokens included)
std::vector<Card *> allCards(const Patch);


struct AddaStriga : CardCollectible<AddaStriga>
{
    AddaStriga();
};


struct Dao : CardCollectible<Dao>
{
    struct DaoLesser : CardCollectible<DaoLesser>
    {
        DaoLesser();
    };
    Dao();
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
};


struct DeithwenArbalest : CardCollectible<DeithwenArbalest>
{
    DeithwenArbalest();
};


struct TemerianDrummer : CardCollectible<TemerianDrummer>
{
    TemerianDrummer();
};


struct TridamInfantry : CardCollectible<TridamInfantry>
{
    TridamInfantry();
};


struct DandelionPoet : CardCollectible<DandelionPoet>
{
    DandelionPoet();
};


struct SileDeTansarville : CardCollectible<SileDeTansarville>
{
    SileDeTansarville();
};


struct RedanianKnightElect : CardCollectible<RedanianKnightElect>
{
    RedanianKnightElect();
};


struct KaedweniKnight : CardCollectible<KaedweniKnight>
{
    KaedweniKnight();
};


struct AnCraiteMarauder : CardCollectible<AnCraiteMarauder>
{
    AnCraiteMarauder();
};


struct AnCraiteGreatsword : CardCollectible<AnCraiteGreatsword>
{
    AnCraiteGreatsword();
};


struct DimunLightLongship : CardCollectible<DimunLightLongship>
{
    DimunLightLongship();
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
};


struct TuirseachHunter : CardCollectible<TuirseachHunter>
{
    TuirseachHunter();
};


struct RedanianElite : CardCollectible<RedanianElite>
{
    RedanianElite();
};


struct RedanianKnight : CardCollectible<RedanianKnight>
{
    RedanianKnight();
};


struct KaedweniCavalry : CardCollectible<KaedweniCavalry>
{
    KaedweniCavalry();
};


struct AlzursThunder : CardCollectible<AlzursThunder>
{
    AlzursThunder();
};


struct Swallow : CardCollectible<Swallow>
{
    Swallow();
};


struct Thunderbolt : CardCollectible<Thunderbolt>
{
    Thunderbolt();
};


struct ArachasVenom : CardCollectible<ArachasVenom>
{
    ArachasVenom();
};


struct KeiraMetz : CardCollectible<KeiraMetz>
{
    KeiraMetz();
};


struct DolBlathannaArcher : CardCollectible<DolBlathannaArcher>
{
    DolBlathannaArcher();
private:
    int _nShots = 0;
};


struct HalfElfHunter : CardCollectible<HalfElfHunter>
{
    HalfElfHunter();
};


struct Ambassador : CardCollectible<Ambassador>
{
    Ambassador();
};


struct Assassin : CardCollectible<Assassin>
{
    Assassin();
};


struct Emissary : CardCollectible<Emissary>
{
    Emissary();
};


struct CeallachDyffryn : CardCollectible<CeallachDyffryn>
{
    CeallachDyffryn();
};


struct TuirseachArcher : CardCollectible<TuirseachArcher>
{
    TuirseachArcher();
};


struct Infiltrator : CardCollectible<Infiltrator>
{
    Infiltrator();
};


struct ImpenetrableFog : CardCollectible<ImpenetrableFog>
{
    ImpenetrableFog();
};


struct TorrentialRain : CardCollectible<TorrentialRain>
{
    TorrentialRain();
};


struct BitingFrost : CardCollectible<BitingFrost>
{
    BitingFrost();
};


struct GoldenFroth : CardCollectible<GoldenFroth>
{
    GoldenFroth();
};


struct SkelligeStorm : CardCollectible<SkelligeStorm>
{
    SkelligeStorm();
};


struct ImperialManticore : CardCollectible<ImperialManticore>
{
    ImperialManticore();
};


struct ManticoreVenom : CardCollectible<ManticoreVenom>
{
    ManticoreVenom();
};


struct GloriousHunt : CardCollectible<GloriousHunt>
{
    GloriousHunt();
};


struct Ves : CardCollectible<Ves>
{
    Ves();
};


struct Vaedermakar : CardCollectible<Vaedermakar>
{
    Vaedermakar();
};


struct Frightener : CardCollectible<Frightener>
{
    Frightener();
};


struct Cleaver : CardCollectible<Cleaver>
{
    Cleaver();
};


struct Scorch : CardCollectible<Scorch>
{
    Scorch();
};


struct Reinforcements : CardCollectible<Reinforcements>
{
    Reinforcements();
};


struct JohnNatalis : CardCollectible<JohnNatalis>
{
    JohnNatalis();
};


struct Eleyas : CardCollectible<Eleyas>
{
    Eleyas();
};


struct ReaverScout : CardCollectible<ReaverScout>
{
    ReaverScout();
};


struct HeymaeySpearmaiden : CardCollectible<HeymaeySpearmaiden>
{
    HeymaeySpearmaiden();
};


struct VriheddSappers : CardCollectible<VriheddSappers>
{
    VriheddSappers();
};


struct PriestessOfFreya : CardCollectible<PriestessOfFreya>
{
    PriestessOfFreya();
};


struct DimunCorsair : CardCollectible<DimunCorsair>
{
    DimunCorsair();
};


struct Sigrdrifa : CardCollectible<Sigrdrifa>
{
    Sigrdrifa();
};


struct DrummondQueensguard : CardCollectible<DrummondQueensguard>
{
    DrummondQueensguard();
};


struct Sage : CardCollectible<Sage>
{
    Sage();
};


struct Reconnaissance : CardCollectible<Reconnaissance>
{
    Reconnaissance();
};


struct ElvenMercenary : CardCollectible<ElvenMercenary>
{
    ElvenMercenary();
};


struct ChampionOfHov : CardCollectible<ChampionOfHov>
{
    ChampionOfHov();
};


struct Priscilla : CardCollectible<Priscilla>
{
    Priscilla();
};


struct SeltkirkOfGulet : CardCollectible<SeltkirkOfGulet>
{
    SeltkirkOfGulet();
};


struct AdrenalineRush : CardCollectible<AdrenalineRush>
{
    AdrenalineRush();
};


struct Mandrake : CardCollectible<Mandrake>
{
    Mandrake();
private:
    struct Buff : CardCollectible<Buff> {};
    struct Debuff : CardCollectible<Debuff> {};
    Card *_choosen = nullptr;
};


struct BoneTalisman : CardCollectible<BoneTalisman>
{
    BoneTalisman();
private:
    struct Buff : CardCollectible<Buff> {};
    struct Resurrect : CardCollectible<Resurrect> {};
    Card *_choosen = nullptr;
};


struct Restore : CardCollectible<Restore>
{
    Restore();
};


struct Decoy : CardCollectible<Decoy>
{
    Decoy();
};


struct ShupesDayOff : CardCollectible<ShupesDayOff>
{
    ShupesDayOff();
};


struct ShupeKnight : CardCollectible<ShupeKnight>
{
    ShupeKnight();
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
private:
    struct Clear : CardCollectible<Clear> {};
    struct Play : CardCollectible<Play> {};
};


struct ClearSkies : CardCollectible<ClearSkies>
{
    ClearSkies();
};


struct Epidemic : CardCollectible<Epidemic>
{
    Epidemic();
};


struct Moonlight : CardCollectible<Moonlight>
{
    Moonlight();
private:
    struct FullMoon : CardCollectible<FullMoon> {};
    struct BloodMoon : CardCollectible<BloodMoon> {};
};


struct CiriNova : CardCollectible<CiriNova>
{
    CiriNova();
};


struct HaraldTheCripple : CardCollectible<HaraldTheCripple>
{
    HaraldTheCripple();
};


struct BranTuirseach : CardCollectible<BranTuirseach>
{
    BranTuirseach();
};


struct DrummondWarmonger : CardCollectible<DrummondWarmonger>
{
    DrummondWarmonger();
};


struct DimunPirate : CardCollectible<DimunPirate>
{
    DimunPirate();
};


struct AnCraiteRaider : CardCollectible<AnCraiteRaider>
{
    AnCraiteRaider();
};


struct MadmanLugos : CardCollectible<MadmanLugos>
{
    MadmanLugos();
private:
    Card *_discarded = nullptr;
};


struct Ermion : CardCollectible<Ermion>
{
    Ermion();
};


struct CerysFearless : CardCollectible<CerysFearless>
{
    CerysFearless();
};


struct CerysAnCraite : CardCollectible<CerysAnCraite>
{
    CerysAnCraite();
};


struct WoodlandSpirit : CardCollectible<WoodlandSpirit>
{
    WoodlandSpirit();
};


struct Trollololo : CardCollectible<Trollololo>
{
    Trollololo();
};


struct PrinceStennis : CardCollectible<PrinceStennis>
{
    PrinceStennis();
};

struct VincentMeis : CardCollectible<VincentMeis>
{
    VincentMeis();
};


struct Morkvarg : CardCollectible<Morkvarg>
{
    Morkvarg();
};


struct ArtefactCompression : CardCollectible<ArtefactCompression>
{
    struct JadeFigurine : CardCollectible<JadeFigurine>
    {
        JadeFigurine();
    };
    ArtefactCompression();
};


struct HjalmarAnCraite : CardCollectible<HjalmarAnCraite>
{
    struct LordOfUndvik : CardCollectible<LordOfUndvik>
    {
        LordOfUndvik();

    };
    HjalmarAnCraite();
};

struct Regis : CardCollectible<Regis>
{
    Regis();
};


struct LethoOfGulet : CardCollectible<LethoOfGulet>
{
    LethoOfGulet();
};


struct Auckes : CardCollectible<Auckes>
{
    Auckes();
};


struct AnCraiteLongship : CardCollectible<AnCraiteLongship>
{
    AnCraiteLongship();
};


struct GeraltIgni : CardCollectible<GeraltIgni>
{
    GeraltIgni(const Lang lang = En);
};


struct GeraltOfRivia : CardCollectible<GeraltOfRivia>
{
    GeraltOfRivia();
};


struct TuirseachVeteran : CardCollectible<TuirseachVeteran>
{
    TuirseachVeteran();
};


struct Udalryk : CardCollectible<Udalryk>
{
    Udalryk();
private:
    std::vector<Card *> _drawn;
};


struct BloodcurdlingRoar : CardCollectible<BloodcurdlingRoar>
{
    BloodcurdlingRoar();
};


struct Gremist : CardCollectible<Gremist>
{
    Gremist();
};


struct ZoriaRunestone : CardCollectible<ZoriaRunestone>
{
    ZoriaRunestone();
};


struct Operator : CardCollectible<Operator>
{
    Operator();
};


struct Renew : CardCollectible<Renew>
{
    Renew();
};


struct EistTuirseach : CardCollectible<EistTuirseach>
{
    EistTuirseach();
};


struct TuirseachAxeman : CardCollectible<TuirseachAxeman>
{
    TuirseachAxeman();
};


struct Derran : CardCollectible<Derran>
{
    Derran();
};


struct TuirseachSkirmisher : CardCollectible<TuirseachSkirmisher>
{
    TuirseachSkirmisher();
};


struct Roach : CardCollectible<Roach>
{
    Roach();
};


struct JanCalveit : CardCollectible<JanCalveit>
{
    JanCalveit();
};


struct CahirDyffryn : CardCollectible<CahirDyffryn>
{
    CahirDyffryn();
};


struct LethoKingslayer : CardCollectible<LethoKingslayer>
{
    LethoKingslayer();
private:
    struct Destroy : CardCollectible<Destroy> {};
    struct Play : CardCollectible<Play> {};
    Card *_choosen = nullptr;
};


struct KingHenselt : CardCollectible<KingHenselt>
{
    KingHenselt();
};


struct BloodyBaron : CardCollectible<BloodyBaron>
{
    BloodyBaron();
};


struct Dethmold : CardCollectible<Dethmold>
{
    Dethmold();
};


struct RonvidTheIncessant : CardCollectible<Dethmold>
{
    RonvidTheIncessant();
};


struct HubertRejk : CardCollectible<HubertRejk>
{
    HubertRejk();
};


struct CrachAnCraite : CardCollectible<CrachAnCraite>
{
    CrachAnCraite();
};


struct BirnaBran : CardCollectible<BirnaBran>
{
    BirnaBran();
};


struct Coral : CardCollectible<Coral>
{
    Coral();
};


struct Vabjorn : CardCollectible<Vabjorn>
{
    Vabjorn();
};


struct BlueboyLugos : CardCollectible<BlueboyLugos>
{
    struct SpectralWhale : CardCollectible<SpectralWhale>
    {
        SpectralWhale();

    };
    BlueboyLugos();
};


struct DjengeFrett : CardCollectible<DjengeFrett>
{
    DjengeFrett();
};


struct DonarAnHindar : CardCollectible<DonarAnHindar>
{
    DonarAnHindar();
    // FIXME: no ability
};


struct DraigBonDhu : CardCollectible<DraigBonDhu>
{
    DraigBonDhu();
};


struct HolgerBlackhand : CardCollectible<HolgerBlackhand>
{
    HolgerBlackhand();
};


struct JuttaAnDimun : CardCollectible<JuttaAnDimun>
{
    JuttaAnDimun();
};


struct SavageBear : CardCollectible<SavageBear>
{
    SavageBear();
};


struct SvanrigeTuirseach : CardCollectible<SvanrigeTuirseach>
{
    SvanrigeTuirseach();
};


struct Skjall : CardCollectible<Skjall>
{
    Skjall();
};


struct HaraldHoundsnout : CardCollectible<HaraldHoundsnout>
{
    struct Wilfred : CardCollectible<Wilfred>
    {
        Wilfred();

    };
    struct Wilhelm : CardCollectible<Wilhelm>
    {
        Wilhelm();

    };
    struct Wilmar : CardCollectible<Wilmar>
    {
        Wilmar();

    };
    HaraldHoundsnout();
};


struct Yoana : CardCollectible<Yoana>
{
    Yoana();
};


struct AnCraiteBlacksmith : CardCollectible<AnCraiteBlacksmith>
{
    AnCraiteBlacksmith();
};


struct AnCraiteWarcrier : CardCollectible<AnCraiteWarcrier>
{
    AnCraiteWarcrier();
};


struct AnCraiteWarrior : CardCollectible<AnCraiteWarrior>
{
    AnCraiteWarrior();
};


struct BerserkerMarauder : CardCollectible<BerserkerMarauder>
{
    BerserkerMarauder();
};


struct DimunPirateCaptain : CardCollectible<DimunPirateCaptain>
{
    DimunPirateCaptain();
};


struct DimunSmuggler : CardCollectible<DimunSmuggler>
{
    DimunSmuggler();
    // FIXME: ability isn't implemented
};


struct DrummondShieldmaid : CardCollectible<DrummondShieldmaid>
{
    DrummondShieldmaid();
    // FIXME: ability isn't implemented
};


struct HeymaeyFlaminica : CardCollectible<HeymaeyFlaminica>
{
    HeymaeyFlaminica();
    // FIXME: ability isn't implemented
};


struct HeymaeyHerbalist : CardCollectible<HeymaeyHerbalist>
{
    HeymaeyHerbalist();
};


struct HeymaeyProtector : CardCollectible<HeymaeyProtector>
{
    HeymaeyProtector();
};


struct HeymaeySkald : CardCollectible<HeymaeySkald>
{
    HeymaeySkald();
    // FIXME: ability isn't implemented
};


struct RagingBerserker : CardCollectible<RagingBerserker>
{
    struct RagingBear : CardCollectible<RagingBear>
    {
        RagingBear();
    };
    RagingBerserker();
};


struct Hym : CardCollectible<Hym>
{
    Hym();
    // FIXME: ability isn't implemented
};


struct Kambi : CardCollectible<Kambi>
{
    struct Hemdall : CardCollectible<Hemdall>
    {
        Hemdall();

    };
    Kambi();
};


struct Olaf : CardCollectible<Olaf>
{
    Olaf();
    // FIXME: ability isn't implemented
};


struct Ulfhedinn : CardCollectible<Ulfhedinn>
{
    Ulfhedinn();
};


struct WildBoarOfTheSea : CardCollectible<WildBoarOfTheSea>
{
    WildBoarOfTheSea();
};


struct GiantBoar : CardCollectible<GiantBoar>
{
    GiantBoar();
};


struct OrnamentalSword : CardCollectible<OrnamentalSword>
{
    OrnamentalSword();
    // FIXME: ability isn't implemented
};


struct DimunWarship : CardCollectible<DimunWarship>
{
    DimunWarship();
};


struct Vilgefortz : CardCollectible<Vilgefortz>
{
    Vilgefortz();
    // FIXME: ability isn't implemented
};


struct TrissButterflies : CardCollectible<TrissButterflies>
{
    TrissButterflies();
};


struct Yennefer : CardCollectible<Yennefer>
{
    struct Chironex : CardCollectible<Chironex>
    {
        Chironex();

    };
    struct Unicorn : CardCollectible<Unicorn>
    {
        Unicorn();

    };
    Yennefer();
};


struct GermainPiquant : CardCollectible<GermainPiquant>
{
    struct Cow : CardCollectible<Cow>
    {
        Cow();
    };
    GermainPiquant();
};


struct CommandersHorn : CardCollectible<CommandersHorn>
{
    CommandersHorn();
};


struct MarchingOrders : CardCollectible<MarchingOrders>
{
    MarchingOrders();
};


struct AlzursDoubleCross : CardCollectible<AlzursDoubleCross>
{
    AlzursDoubleCross();
};


struct AlbaArmoredCavalry : CardCollectible<AlbaArmoredCavalry>
{
    AlbaArmoredCavalry();
    // FIXME: ability isn't implemented
};


struct Sentry : CardCollectible<Sentry>
{
    Sentry();
};


struct NauzicaaSergeant : CardCollectible<NauzicaaSergeant>
{
    NauzicaaSergeant();
};


struct SlaveInfantry : CardCollectible<SlaveInfantry>
{
    SlaveInfantry();
};


struct Recruit : CardCollectible<Recruit>
{
    Recruit();
};


struct Ointment : CardCollectible<Ointment>
{
    Ointment();
};


struct Vreemde : CardCollectible<Vreemde>
{
    Vreemde();
    // FIXME: ability isn't implemented
};


struct Eskel : CardCollectible<Eskel>
{
    Eskel();
};


struct Lambert : CardCollectible<Lambert>
{
    Lambert();
};


struct Vesemir : CardCollectible<Vesemir>
{
    Vesemir();
};


struct VriheddDragoon : CardCollectible<VriheddDragoon>
{
    VriheddDragoon();
};


struct Malena : CardCollectible<Malena>
{
    Malena();
};


struct UnseenElder : CardCollectible<UnseenElder>
{
    UnseenElder();
};


struct DevanaRunestone : CardCollectible<DevanaRunestone>
{
    DevanaRunestone();
};


struct DazhbogRunestone : CardCollectible<DazhbogRunestone>
{
    DazhbogRunestone();
};


struct MoranaRunestone : CardCollectible<MoranaRunestone>
{
    MoranaRunestone();
};


struct StribogRunestone : CardCollectible<StribogRunestone>
{
    StribogRunestone();
};


struct Muzzle : CardCollectible<Muzzle>
{
    Muzzle();
};


struct WhisperingHillock : CardCollectible<WhisperingHillock>
{
    WhisperingHillock();
};


struct Brewess : CardCollectible<Brewess>
{
    Brewess();
};


struct Weavess : CardCollectible<Weavess>
{
    Weavess();
};


struct Whispess : CardCollectible<Whispess>
{
    Whispess();
};


struct WeavessIncantation : CardCollectible<WeavessIncantation>
{
    WeavessIncantation();
private:
    struct StrengthenAll : CardCollectible<StrengthenAll> {};
    struct PlayAndStrengthen : CardCollectible<PlayAndStrengthen> {};
    Card *_choosen = nullptr;
};


struct BrewessRitual : CardCollectible<BrewessRitual>
{
    BrewessRitual();
};


struct WhispessTribute : CardCollectible<WhispessTribute>
{
    WhispessTribute();
};


struct RockBarrage : CardCollectible<RockBarrage>
{
    RockBarrage();
};


struct Nivellen : CardCollectible<Nivellen>
{
    Nivellen();
    // FIXME: ability isn't implemented
};


struct LeoBonhart : CardCollectible<LeoBonhart>
{
    LeoBonhart();
private:
    Card *_revealed = nullptr;
};


struct MorvranVoorhis : CardCollectible<MorvranVoorhis>
{
    MorvranVoorhis();
};


struct Cynthia : CardCollectible<Cynthia>
{
    Cynthia();
};


struct Serrit : CardCollectible<Serrit>
{
    Serrit();
};


struct Sweers : CardCollectible<Sweers>
{
    Sweers();
};


struct WildHuntHound : CardCollectible<WildHuntHound>
{
    WildHuntHound();
};


#endif // CARDS_H
