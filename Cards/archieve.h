#ifndef CARDS_H
#define CARDS_H

#include "card.h"


/// returns all cards in games (no tokens included)
std::vector<Card *> allCards(const Patch);
std::map<std::string, std::string> keywordDescriptions(const Patch patch = PublicBeta_0_9_24_3_432);


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
    GeraltIgni();
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
};


struct DrummondShieldmaid : CardCollectible<DrummondShieldmaid>
{
    DrummondShieldmaid();
};


struct HeymaeyFlaminica : CardCollectible<HeymaeyFlaminica>
{
    HeymaeyFlaminica();
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
private:
    struct Play : CardCollectible<Play> {};
    struct Create : CardCollectible<Create> {};
    Card *_choosen = nullptr;
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
};


struct DimunWarship : CardCollectible<DimunWarship>
{
    DimunWarship();
};


struct Vilgefortz : CardCollectible<Vilgefortz>
{
    Vilgefortz();
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


struct Ciri : CardCollectible<Ciri>
{
    Ciri();
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


struct TiborEggebracht : CardCollectible<TiborEggebracht>
{
    TiborEggebracht();
};


struct VattierDeRideaux : CardCollectible<VattierDeRideaux>
{
    VattierDeRideaux();
};


struct Albrich : CardCollectible<Albrich>
{
    Albrich();
};


struct HeftyHelge : CardCollectible<HeftyHelge>
{
    HeftyHelge();
};


struct Alchemist : CardCollectible<Alchemist>
{
    Alchemist();
};


struct DaerlanSoldier : CardCollectible<DaerlanSoldier>
{
    DaerlanSoldier();
};


struct FireScorpion : CardCollectible<FireScorpion>
{
    FireScorpion();
};


struct Mangonel : CardCollectible<Mangonel>
{
    Mangonel();
};


struct NilfgaardianKnight : CardCollectible<NilfgaardianKnight>
{
    NilfgaardianKnight();
};


struct Spotter : CardCollectible<Spotter>
{
    Spotter();
};


struct VenendalElite : CardCollectible<VenendalElite>
{
    VenendalElite();
};


struct MasterOfDisguise : CardCollectible<MasterOfDisguise>
{
    MasterOfDisguise();
};


struct HenryVarAttre : CardCollectible<HenryVarAttre>
{
    HenryVarAttre();
};


struct SummoningCircle : CardCollectible<SummoningCircle>
{
    SummoningCircle();
};


struct XavierMoran : CardCollectible<XavierMoran>
{
    XavierMoran();
};


struct YenneferEnchantress : CardCollectible<YenneferEnchantress>
{
    YenneferEnchantress();
};


struct VernonRoche : CardCollectible<VernonRoche>
{
    VernonRoche();
};


struct BlueStripeScout : CardCollectible<BlueStripeScout>
{
    BlueStripeScout();
};


struct BlueStripeCommando : CardCollectible<BlueStripeCommando>
{
    BlueStripeCommando();
private:
    std::map<Card *, Card *> _allyPlayedToCopy;
};


struct ImperialGolem : CardCollectible<ImperialGolem>
{
    ImperialGolem();
private:
    std::map<Card *, Card *> _cardRevealedToCopy;
};


struct WildHuntHound : CardCollectible<WildHuntHound>
{
    WildHuntHound();
};


struct WildHuntWarrior : CardCollectible<WildHuntWarrior>
{
    WildHuntWarrior();
};


struct WildHuntNavigator : CardCollectible<WildHuntNavigator>
{
    WildHuntNavigator();
};


struct Nithral : CardCollectible<Nithral>
{
    Nithral();
};


struct Miruna : CardCollectible<Miruna>
{
    Miruna();
};


struct Imlerith : CardCollectible<Imlerith>
{
    Imlerith();
};


struct Caretaker : CardCollectible<Caretaker>
{
    Caretaker();
};


struct Ruehin : CardCollectible<Ruehin>
{
    Ruehin();
};


struct OldSpeartipAsleep : CardCollectible<OldSpeartipAsleep>
{
    OldSpeartipAsleep();
};


struct OldSpeartip : CardCollectible<OldSpeartip>
{
    OldSpeartip();
};


struct Golyat : CardCollectible<Golyat>
{
    Golyat();
};


struct Barbegazi : CardCollectible<Barbegazi>
{
    Barbegazi();
};


struct Ghoul : CardCollectible<Ghoul>
{
    Ghoul();
};


struct Forktail: CardCollectible<Forktail>
{
    Forktail();
};


struct ArachasQueen : CardCollectible<ArachasQueen>
{
    ArachasQueen();
};



struct Ozzrel : CardCollectible<Ozzrel>
{
    Ozzrel();
};


struct Kayran : CardCollectible<Kayran>
{
    Kayran();
};


struct Mourntart : CardCollectible<Mourntart>
{
    Mourntart();
};


struct ToadPrince : CardCollectible<ToadPrince>
{
    ToadPrince();
};


struct Fiend : CardCollectible<Fiend>
{
    Fiend();
};


struct Morvudd : CardCollectible<Morvudd>
{
    Morvudd();
};


struct Ekimmara : CardCollectible<Ekimmara>
{
    Ekimmara();
};


struct Rotfiend : CardCollectible<Rotfiend>
{
    Rotfiend();
};


struct Archespore : CardCollectible<Archespore>
{
    Archespore();
};


struct Cyclops : CardCollectible<Cyclops>
{
    Cyclops();
private:
    int _powerOfDestroyed = 0;
};


struct Maerolorn : CardCollectible<Maerolorn>
{
    Maerolorn();
};


struct MonsterNest : CardCollectible<MonsterNest>
{
    MonsterNest();
};


struct ArachasDrone : CardCollectible<ArachasDrone>
{
    ArachasDrone();
};


struct Werewolf : CardCollectible<Werewolf>
{
    Werewolf();
};


struct AlphaWerewolf : CardCollectible<AlphaWerewolf>
{
    AlphaWerewolf();
};


struct EredinBreaccGlas : CardCollectible<EredinBreaccGlas>
{
    EredinBreaccGlas();
};


struct CaranthirArFeiniel : CardCollectible<CaranthirArFeiniel>
{
    CaranthirArFeiniel();
};


struct ImlerithSabbath : CardCollectible<ImlerithSabbath>
{
    ImlerithSabbath();
};


struct Dagon : CardCollectible<Dagon>
{
    Dagon();
};


struct Ifrit : CardCollectible<Ifrit>
{
    Ifrit();
    struct IfritLesser : CardCollectible<IfritLesser>
    {
        IfritLesser();
    };
};


struct SheTrollOfVergen : CardCollectible<SheTrollOfVergen>
{
    SheTrollOfVergen();
private:
    bool _played = false;
};


struct Wyvern : CardCollectible<Wyvern>
{
    Wyvern();
};


struct Abaya : CardCollectible<Abaya>
{
    Abaya();
};


struct Parasite : CardCollectible<Parasite>
{
    Parasite();
};


struct Jotunn : CardCollectible<Jotunn>
{
    Jotunn();
};


struct IceGiant : CardCollectible<IceGiant>
{
    IceGiant();
};


struct IceTroll : CardCollectible<IceTroll>
{
    IceTroll();
};


struct Drowner : CardCollectible<Drowner>
{
    Drowner();
};


struct Foglet : CardCollectible<Foglet>
{
    Foglet();
private:
    std::map<Row, const Card *> _rowToCopy;
};


struct AncientFoglet : CardCollectible<AncientFoglet>
{
    AncientFoglet();
};


struct Draug : CardCollectible<Draug>
{
    Draug();
private:
    struct Draugir : CardCollectible<Draugir>
    {
        Draugir();
    };
};


struct CelaenoHarpy : CardCollectible<CelaenoHarpy>
{
    CelaenoHarpy();
private:
    struct HarpyEgg : CardCollectible<HarpyEgg>
    {
        HarpyEgg();
    };
    struct HarpyHatchling : CardCollectible<HarpyHatchling>
    {
        HarpyHatchling();
    };
};


struct ArachasBehemoth : CardCollectible<ArachasBehemoth>
{
    ArachasBehemoth();
private:
    struct ArachasHatchling : CardCollectible<ArachasHatchling>
    {
        ArachasHatchling();
    };
};


struct Archgriffin : CardCollectible<Archgriffin>
{
    Archgriffin();
};


struct Griffin : CardCollectible<Griffin>
{
    Griffin();
};


struct BridgeTroll : CardCollectible<BridgeTroll>
{
    BridgeTroll();
private:
    int _rowSelected = -1;
};


struct Cockatrice : CardCollectible<Cockatrice>
{
    Cockatrice();
};


struct Nekurat : CardCollectible<Nekurat>
{
    Nekurat();
};


struct Siren : CardCollectible<Siren>
{
    Siren();
};


struct Lamia : CardCollectible<Lamia>
{
    Lamia();
};


struct Nekker : CardCollectible<Nekker>
{
    Nekker();
};


struct NekkerWarrior : CardCollectible<NekkerWarrior>
{
    NekkerWarrior();
};


struct Slyzard : CardCollectible<Slyzard>
{
    Slyzard();
};


struct Werecat : CardCollectible<Werecat>
{
    Werecat();
};


struct Harpy : CardCollectible<Harpy>
{
    Harpy();
private:
    std::map<Card *, Card *> _allyDestroyedToCopy;
};


struct WildHuntDrakkar : CardCollectible<WildHuntDrakkar>
{
    WildHuntDrakkar();
};


struct Geels : CardCollectible<Geels>
{
    Geels();
private:
    Card *_gold = nullptr;
    Card *_silver = nullptr;
};


struct WildHuntRider : CardCollectible<WildHuntRider>
{
    WildHuntRider();
};


struct VranWarrior : CardCollectible<VranWarrior>
{
    VranWarrior();
};


struct AnCraiteArmorsmith : CardCollectible<AnCraiteArmorsmith>
{
    AnCraiteArmorsmith();
};

struct Avalach : CardCollectible<Avalach>
{
    Avalach();
};


struct AvalachSage : CardCollectible<AvalachSage>
{
    AvalachSage();
};


struct RaghNarRoog : CardCollectible<RaghNarRoog>
{
    RaghNarRoog();
};


struct GeraltProfessional : CardCollectible<GeraltProfessional>
{
    GeraltProfessional();
};


struct GeraltAard : CardCollectible<GeraltAard>
{
    GeraltAard();
};


struct GeraltYrden : CardCollectible<GeraltYrden>
{
    GeraltYrden();
};


struct CiriDash : CardCollectible<CiriDash>
{
    CiriDash();
};


struct Aguara : CardCollectible<Aguara>
{
    Aguara();
private:
    struct BoostLowest : CardCollectible<BoostLowest> {};
    struct BoostInHand : CardCollectible<BoostInHand> {};
    struct DamageHighest : CardCollectible<DamageHighest> {};
    struct CharmElf : CardCollectible<CharmElf> {};
    int _nOptionsLeft = 0;
};


struct AguaraTrueForm : CardCollectible<AguaraTrueForm>
{
    AguaraTrueForm();
};


struct KorathiHeatwave : CardCollectible<KorathiHeatwave>
{
    KorathiHeatwave();
};


struct AleOfTheAncestors : CardCollectible<AleOfTheAncestors>
{
    AleOfTheAncestors();
};


struct MahakamAle : CardCollectible<MahakamAle>
{
    MahakamAle();
};


struct Odrin : CardCollectible<Odrin>
{
    Odrin();
};


struct Toruviel : CardCollectible<Toruviel>
{
    Toruviel();
};


struct Milva : CardCollectible<Milva>
{
    Milva();
};


struct PrincessPavetta : CardCollectible<PrincessPavetta>
{
    PrincessPavetta();
};


struct TheGuardian : CardCollectible<TheGuardian>
{
    struct LesserGuardian : CardCollectible<LesserGuardian>
    {
        LesserGuardian();
    };
    TheGuardian();
};


struct GaunterODimm : CardCollectible<GaunterODimm>
{
    GaunterODimm();
private:
    struct Less6 : CardCollectible<Less6> {};
    struct Equal6 : CardCollectible<Equal6> {};
    struct More6 : CardCollectible<More6> {};
    Card *_picked = nullptr;
};


struct KaedweniSergeant : CardCollectible<KaedweniSergeant>
{
    KaedweniSergeant();
};


struct ReinforcedBallista : CardCollectible<ReinforcedBallista>
{
    ReinforcedBallista();
};


struct SigismundDijkstra : CardCollectible<SigismundDijkstra>
{
    SigismundDijkstra();
};


struct WhiteFrost : CardCollectible<WhiteFrost>
{
    WhiteFrost();  
};


struct Wolfsbane : CardCollectible<Wolfsbane>
{
    Wolfsbane();
};


struct DunBanner : CardCollectible<DunBanner>
{
    DunBanner();
};


struct Aelirenn : CardCollectible<Aelirenn>
{
    Aelirenn();
};


struct HanmarvynsDream : CardCollectible<HanmarvynsDream>
{
    HanmarvynsDream();
};


struct BlackBlood : CardCollectible<BlackBlood>
{
    BlackBlood();
private:
    struct Create : CardCollectible<Create> {};
    struct Destroy : CardCollectible<Destroy> {};
    Card *_choosen = nullptr;
};


struct BekkersRockslide : CardCollectible<BekkersRockslide>
{
    BekkersRockslide();
};


struct BekkersDarkMirror : CardCollectible<BekkersDarkMirror>
{
    BekkersDarkMirror();
};


struct MerigoldsHailstorm: CardCollectible<MerigoldsHailstorm>
{
    MerigoldsHailstorm();
};


struct Necromancy: CardCollectible<Necromancy>
{
    Necromancy();
private:
    int transPower = 0;
};


struct StammelfordsTremor : CardCollectible<StammelfordsTremor>
{
    StammelfordsTremor();
};


struct ExpiredAle : CardCollectible<ExpiredAle>
{
    ExpiredAle();
};


struct TrialOfTheGrasses : CardCollectible<TrialOfTheGrasses>
{
    TrialOfTheGrasses();
};


struct DimeritiumBomb : CardCollectible<DimeritiumBomb>
{
    DimeritiumBomb();
};


struct Garrison : CardCollectible<Garrison>
{
    Garrison();
};


struct TheLastWish : CardCollectible<TheLastWish>
{
    TheLastWish();
};


struct DimeritiumShackles : CardCollectible<DimeritiumShackles>
{
    DimeritiumShackles();
};


struct WyvernScaleShield : CardCollectible<WyvernScaleShield>
{
    WyvernScaleShield();
private:
    int _boostAmount = 0;
};


struct MastercraftedSpear : CardCollectible<MastercraftedSpear>
{
    MastercraftedSpear();
private:
    int _damageAmount = 0;
};


struct PetrisPhilter : CardCollectible<PetrisPhilter>
{
    PetrisPhilter();
};


struct Shrike : CardCollectible<Shrike>
{
    Shrike();
};


struct RoyalDecree : CardCollectible<RoyalDecree>
{
    RoyalDecree();
};


struct UmasCurse : CardCollectible<UmasCurse>
{
    UmasCurse();
};


struct Lacerate : CardCollectible<Lacerate>
{
    Lacerate();
};


struct CrowsEye : CardCollectible<CrowsEye>
{
    CrowsEye();
};


struct Doppler : CardCollectible<Doppler>
{
    Doppler();
};


struct Spores : CardCollectible<Spores>
{
    Spores();
};


struct Mardroeme : CardCollectible<Mardroeme>
{
    Mardroeme();
private:
    struct Strengthen : CardCollectible<Strengthen> {};
    struct Weaken : CardCollectible<Weaken> {};
    Card *_choosen = nullptr;
};


struct Sihil : CardCollectible<Sihil>
{
    Sihil();
private:
    struct DamageOdd : CardCollectible<DamageOdd> {};
    struct DamageEven : CardCollectible<DamageEven> {};
    struct PlayFromDeck : CardCollectible<PlayFromDeck> {};
    Card *_choosen = nullptr;
};


struct DragonsDream : CardCollectible<DragonsDream>
{
    DragonsDream();
};


struct EskelPathfinder : CardCollectible<EskelPathfinder>
{
    EskelPathfinder();
};


struct VesemirMentor : CardCollectible<VesemirMentor>
{
    VesemirMentor();
};


struct LambertSwordmaster : CardCollectible<LambertSwordmaster>
{
    LambertSwordmaster();
};


struct RegisHigherVampire : CardCollectible<RegisHigherVampire>
{
    RegisHigherVampire();
};


struct ZoltanScoundrel : CardCollectible<ZoltanScoundrel>
{

    struct DudaCompanion : CardCollectible<DudaCompanion>
    {
        DudaCompanion();

    };
    struct DudaAgitator : CardCollectible<DudaAgitator>
    {
        DudaAgitator();

    };
    ZoltanScoundrel();
};


struct YenneferConjurer : CardCollectible<YenneferConjurer>
{
    YenneferConjurer();
};


struct TrissMerigold : CardCollectible<TrissMerigold>
{
    TrissMerigold();
};

struct TrissTelekinesis : CardCollectible<TrissTelekinesis>
{
    TrissTelekinesis();
};


struct DorregarayOfVole : CardCollectible<DorregarayOfVole>
{
    DorregarayOfVole();
};


struct DandelionVainglory : CardCollectible<DandelionVainglory>
{
    DandelionVainglory();
};


struct CyprianWiley : CardCollectible<CyprianWiley>
{
    CyprianWiley();
};


struct Dudu : CardCollectible<Dudu>
{
    Dudu();
};


struct Ihuarraquax : CardCollectible<Ihuarraquax>
{
    Ihuarraquax();
private:
    bool damageDone = false;
};


struct MahakamMarauder : CardCollectible<MahakamMarauder>
{
    MahakamMarauder();
};


struct ZoltanChivay : CardCollectible<ZoltanChivay>
{
    ZoltanChivay();
};


struct YenneferNecromancer : CardCollectible<YenneferNecromancer>
{
    YenneferNecromancer();
};


struct Phoenix : CardCollectible<Phoenix>
{
    Phoenix();
};


struct SaesenthessisBlaze : CardCollectible<SaesenthessisBlaze>
{
    SaesenthessisBlaze();
};


struct Villentretenmerth : CardCollectible<Villentretenmerth>
{
    Villentretenmerth();
};


struct Ocvist : CardCollectible<Ocvist>
{
    Ocvist();
};


struct Myrgtabrakke : CardCollectible<Myrgtabrakke>
{
    Myrgtabrakke();
};


struct KingOfBeggars : CardCollectible<KingOfBeggars>
{
    KingOfBeggars();
};


struct OlgierdVonEverec : CardCollectible<OlgierdVonEverec>
{
    OlgierdVonEverec();
};


struct IrisVonEverec : CardCollectible<IrisVonEverec>
{
    IrisVonEverec();
};


struct IrisCompanions : CardCollectible<IrisCompanions>
{
    IrisCompanions();
};


struct Johnny : CardCollectible<Johnny>
{
    Johnny();
};


struct Stregobor : CardCollectible<Stregobor>
{
    Stregobor();
};


struct Sarah : CardCollectible<Sarah>
{
    Sarah();
};


struct PeasantMilitia : CardCollectible<PeasantMilitia>
{
    PeasantMilitia();
private:
    struct Peasant : CardCollectible<Peasant>
    {
        Peasant();
    };
};


struct PrizeWinningCow : CardCollectible<PrizeWinningCow>
{
    PrizeWinningCow();
private:
    struct Chort : CardCollectible<Chort>
    {
        Chort();
    };
};


struct PrincessAdda : CardCollectible<PrincessAdda>
{
    PrincessAdda();
};


struct KingFoltest : CardCollectible<KingFoltest>
{
    KingFoltest();
};


struct KingRadovidV : CardCollectible<KingRadovidV>
{
    KingRadovidV();
};


struct EmhyrVarEmreis : CardCollectible<EmhyrVarEmreis>
{
    EmhyrVarEmreis();
};


struct Usurper : CardCollectible<Usurper>
{
    Usurper();
};


struct BrouverHoog : CardCollectible<BrouverHoog>
{
    BrouverHoog();
};


struct Eithne : CardCollectible<Eithne>
{
    Eithne();
};


struct Filavandrel : CardCollectible<Filavandrel>
{
    Filavandrel();
};


struct FrancescaFindabair : CardCollectible<FrancescaFindabair>
{
    FrancescaFindabair();
private:
    Card *_cardToSwap = nullptr;
};


#endif // CARDS_H
