#include "archieve.h"

#include <cassert>
#include <random>

#include "filters.h"

std::map<std::string, std::string> keywordDescriptions(const Patch patch)
{
    if (patch == PublicBeta_0_9_24_3_432)
        return {
            {"Charm", "Move an enemy to the opposite row."},
            {"Highest", "Highest power, ties are resolved randomly."},
            {"Lowest", "Lowest power, ties are resolved randomly."},
            {"Truce", "If neither player has passed."},
            {"Spawn", "Add a card to the game."},
            {"Armor", "Absorbs a given amount of damage, then is removed."},
            {"Discard", "Move a card from your hand to the graveyard. Note: Related abilities are not triggered when discarding manually."},
            {"Strengthen", "Increase the base power of a unit."},
            {"Weaken", "Decrease the base power of a unit. If it falls below 1, remove it from the game. Does not trigger Deathwish abilities."},
            {"Reset", "Restore a card to its default state (as it would appear in the Deck Builder)."},
            {"Drain", "Deal damage and boost self by the same amount."},
            {"Consume", "Eat a unit and boost by its power. If it's on the battlefield, destroy it. If in hand or deck, move it to the graveyard. If in the graveyard, remove it from the game."},
            {"Create", "Spawn one of three randomly selected cards from the specified source."},
            {"Summon", "Move automatically to the battlefield (not considered played)."},
            {"Deathwish", "Trigger this ability when destroyed and moved from the battlefield to the graveyard. Note: Banished units are not sent to the graveyard."},
            {"Spying", "Status for a unit played on or moved to the opposite side of the battlefield."},
            {"Single-Use", "This card's ability can be used only once per game."},
            {"Resurrect", "Play from your graveyard."},
            {"Hazard", "Negative row effect. Replaced by other row effects and removed on round end."},
            {"Banish", "Remove from the game. Note: Does not count as being destroyed."},
            {"Heal", "If a unit's current power is lower than its base power, restore it either to base power or by the amount specified."},
            {"Lock", "Status that disables a unit's abilities."},
            {"Boon", "Positive row effect. Replaced by other row effects and removed on round end."},
            {"Duel", "Units take turns dealing damage equal to their power until one of them is destroyed."},
            {"Reveal", "Show a card to both players, then hide it back in the hand or deck."},
            {"Conceal", "Turn over a face-up card in hand."},
            {"Revealed", "A card in the hand that has been turned over."},
            {"Crew", "This unit triggers the ability of Crewed units played adjacent to it."},
            {"Ambush", "Played face down, then flips over when the ability's condition is met."},
            {"Crewed", "When played, trigger this ability once for each adjacent Crew unit."},
            {"Swap", "Move a card from hand to deck and draw another in its place during your turn."},
            {"Resilience", "Status that allows a unit to remain on the board at round end, and if boosted restores it to its base power."},
            {"Doomed", "Banish instead of putting in a Discard."},
            {"Immunity", "Status whereby this card cannot be manually targeted."},
        };
    return {};
}

void allCardsInfos(const Patch)
{
    using Name = std::string;
    using Text = std::string;
    using Urls = std::vector<std::string>;
    struct Info
    {
        Info(const Name &name, const Text &text = "", const Urls &sounds = {}) :
            name(name), text(text), sounds(sounds)
        {}
    private:
        Name name;
        Text text;
        Urls sounds;
    };

    const std::map<std::string, Info> infos {
        {"200073", Info(
                        "Adda: Striga",
                        "Deal 8 damage to a non-Monster faction unit.")},
        {"132213", Info(
                        "D'ao",
                        "Deathwish: Spawn 2 Lesser D'ao on this row.")},
        {"132405", Info(
                        "D'ao Lesser")},
        {"200302", Info(
                        "Left Flank Infantry")},
        {"200303", Info(
                        "Right Flank Infantry")},
        {"200234", Info(
                        "Poor F'ing Infantry",
                        "Spawn Left Flank Infantry and Right Flank Infantry to the left and right of this unit, respectively.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VPEA1_VSET_00521643.mp3",
                            "https://gwent.one/audio/card/ob/en/VPEA1_VSET_00519831.mp3",
                            "https://gwent.one/audio/card/ob/en/VPEA1_VSET_00518009.mp3",
                        })},
        {"162305", Info(
                        "Deithwen Arbalest",
                        "Deal 3 damage to an enemy. If it's Spying, deal 6 damage instead.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/NILF3_VSET_00514109.mp3",
                            "https://gwent.one/audio/card/ob/en/NILF3_SQ102_00591494.mp3",
                            "https://gwent.one/audio/card/ob/en/NILF3_VSET_00514105.mp3",
                        })},
        {"200299", Info(
                        "Temerian Drummer",
                        "Boost an ally by 6.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.407.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.408.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.409.mp3",
                        })},
        {"201776", Info(
                        "Dandelion: Poet",
                        "Draw a card, then play a card.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/DAND_Q302_00490269.mp3",
                            "https://gwent.one/audio/card/ob/en/DAND_DANDELION_00429307.mp3",
                            "https://gwent.one/audio/card/ob/en/DAND_Q302_00489393.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_JSKR_100926_0188.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.5.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.6.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.7.mp3",
                        })},
        {"122205", Info(
                        "S'ile de Tansarville",
                        "Play a Bronze or Silver special card, then draw a card.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.29.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.30.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.31.mp3",
                        })},
        {"123301", Info(
                        "Redanian Knight Elect",
                        "If this unit has Armor on turn end, boost adjacent units by 1. 2 Armor.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.320.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.321.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.322.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.323.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.324.mp3",
                        })},
        {"201578", Info(
                        "An Craite Marauder",
                        "Deal 4 damage. If Resurrected, deal 6 damage instead.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.395.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.396.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.397.mp3",
                        })},
        {"200040", Info(
                        "An Craite Greatsword",
                        "Every 2 turns, if damaged, Heal self and Strengthen by 2 on turn start.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.314.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.315.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.316.mp3",
                        })},
        {"152309", Info(
                        "Dimun Light Longship",
                        "On turn end, damage the unit to the right by 1, then boost self by 2.")},
        {"152406", Info(
                        "Bear")},
        {"132403", Info(
                        "Wolf")},
        {"200144", Info(
                        "Tuirseach Bearmaster",
                        "Spawn a Bear.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.26.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.27.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.28.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.29.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.30.mp3",
                        })},
        {"122317", Info(
                        "Redanian Elite",
                        "Whenever this unit's Armor reaches 0, boost self by 5. 4 Armor.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/REOF1_VSET_00516089.mp3",
                            "https://gwent.one/audio/card/ob/en/REOF1_VSET_00516091.mp3",
                            "https://gwent.one/audio/card/ob/en/REOF1_VSET_00516093.mp3",
                        })},
        {"122308", Info(
                        "Redanian Knight",
                        "If this unit has no Armor, boost it by 2 and give it 2 Armor on turn end.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/RES1_VSET_00508445.mp3",
                            "https://gwent.one/audio/card/ob/en/RES1_VSET_00508451.mp3",
                            "https://gwent.one/audio/card/ob/en/RES1_VSET_00508237.mp3",
                        })},
        {"122314", Info(
                        "Kaedweni Cavalry",
                        "Destroy a unit's Armor, then boost self by the amount destroyed.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_KG02_202929_0003.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_KG02_202929_0004.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_KG02_200565_0005.mp3",
                        })},
        {"113301", Info(
                        "Alzur's Thunder",
                        "Deal 9 damage.")},
        {"113310", Info(
                        "Swallow",
                        "Boost a unit by 10.")},
        {"113311", Info(
                        "Thunderbolt",
                        "Boost 3 adjacent units by 3 and give them 2 Armor.")},
        {"200023", Info(
                        "Arachas Venom",
                        "Deal 4 damage to 3 adjacent units.")},
        {"122108", Info(
                        "Keira Metz",
                        "Spawn Alzur's Thunder, Thunderbolt or Arachas Venom.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/KEIR_KEIRA_01040781.mp3",
                            "https://gwent.one/audio/card/ob/en/KEIR_SQ101_00565661.mp3",
                            "https://gwent.one/audio/card/ob/en/KEIR_KEIRA_00475332.mp3",
                        })},
        {"142310", Info(
                        "Dol Blathanna Archer",
                        "Deal 3 damage, then deal 1 damage.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_SF07_100515_0011.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.801.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_SF07_100515_0001.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_SF07_108969_0002.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.802.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.803.mp3",
                        })},
        {"201636", Info(
                        "Half-Elf Hunter",
                        "Spawn a Doomed default copy of this unit to the right of this unit.")},
        {"162315", Info(
                        "Ambassador",
                        "Spying. Boost an ally by 12.")},
        {"200115", Info(
                        "Assassin",
                        "Spying. Deal 10 damage to the unit to the left.")},
        {"152315", Info(
                        "Tuirseach Archer",
                        "Deal 1 damage to 3 units.")},
        {"200118", Info(
                        "Infiltrator",
                        "Toggle a unit's Spying status.")},
        {"113305", Info(
                        "Impenetrable Fog",
                        "Apply a Hazard to an enemy row that deals 2 damage to the Highest unit on turn start.")},
        {"113312", Info(
                        "Torrential Rain",
                        "Apply a Hazard to an enemy row that deals 1 damage to 2 random units on turn start.")},
        {"113302", Info(
                        "Biting Frost",
                        "Apply a Hazard to an enemy row that deals 2 damage to the Lowest unit on turn start.")},
        {"201749", Info(
                        "Golden Froth",
                        "Apply a Boon to an allied row that boosts 2 random units by 1 on turn start.")},
        {"113203", Info(
                        "Skellige Storm",
                        "Apply a Hazard to an enemy row that deals 2, 1 and 1 damage to the leftmost units on the row on turn start.")},
        {"132209", Info(
                        "Imperial Manticore")},
        {"113306", Info(
                        "Manticore Venom",
                        "Deal 13 damage.")},
        {"201635", Info(
                        "Glorious Hunt",
                        "If losing, Spawn an Imperial Manticore, otherwise Spawn Manticore Venom.")},
        {"122204", Info(
                        "Ves",
                        "Swap up to 2 cards.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VESS_Q403_00546798.mp3",
                            "https://gwent.one/audio/card/ob/en/VESS_VES_01070698.mp3",
                            "https://gwent.one/audio/card/ob/en/VESS_MQ3035_01064809.mp3",
                            "https://gwent.one/audio/card/ob/en/VESS_MQ3035_01071150.mp3",
                        })},
        {"113208", Info(
                        "Vaedermakar",
                        "Spawn Biting Frost, Impenetrable Fog or Alzur's Thunder.")},
        {"132204", Info(
                        "Frightener",
                        "Spying. Single-Use: Move an enemy to this row and draw a card.")},
        {"122216", Info(
                        "Cleaver",
                        "Deal 1 damage for each card in your hand.")},
        {"113309", Info(
                        "Scorch",
                        "Destroy all the Highest units.")},
        {"123201", Info(
                        "Reinforcements",
                        "Play a Bronze or Silver Soldier, Machine, Officer or Support unit from your deck.")},
        {"122103", Info(
                        "John Natalis",
                        "Play a Bronze or Silver Tactic from your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_JANT_900381_0141.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_JANT_300862_0253.mp3",
                        })},
        {"142214", Info(
                        "Ele'yas",
                        "Whenever you draw this unit or return it to your deck, boost self by 2.")},
        {"122307", Info(
                        "Reaver Scout",
                        "Choose a different Bronze ally and play a copy of it from your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_NG01_003478_0126.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_NG01_003478_0060.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_NG01_003478_0008.mp3",
                        })},
        {"200528", Info(
                        "Heymaey Spearmaiden",
                        "Deal 1 damage to a Bronze Machine or Soldier ally, then play a copy of it from your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.83.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.84.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.85.mp3",
                        })},
        {"201622", Info(
                        "Kaedweni Knight",
                        "Boost self by 5 if played from the deck. 2 Armor.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.9.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.10.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.11.mp3",
                        })},
        {"142307", Info(
                        "Vrihedd Sappers",
                        "Ambush: After 2 turns, flip over on turn start.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_SMV2_202963_0006.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_SMV2_202963_0007.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_SMV2_202544_0022.mp3",
                        })},
        {"152310", Info(
                        "Priestess of Freya",
                        "Resurrect a Bronze Soldier.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SPR2_VSET_00553534.mp3",
                            "https://gwent.one/audio/card/ob/en/SPR2_VSET_00553573.mp3",
                            "https://gwent.one/audio/card/ob/en/SPR2_VSET_00553583.mp3",
                        })},
        {"200145", Info(
                        "Dimun Corsair",
                        "Resurrect a Bronze Machine.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.71.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.72.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.73.mp3",
                        })},
        {"152211", Info(
                        "Sigrdrifa",
                        "Resurrect a Bronze or Silver Clan unit.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SPR1_VSET_00553157.mp3",
                            "https://gwent.one/audio/card/ob/en/SPR1_SQ201_00499249.mp3",
                            "https://gwent.one/audio/card/ob/en/SPR1_SHOP_00437650.mp3",
                        })},
        {"200138", Info(
                        "Sage",
                        "Resurrect a Bronze Alchemy or Spell card, then Banish it.")},
        {"201704", Info(
                        "Reconnaissance",
                        "Look at 2 random Bronze units in your deck, then play 1.")},
        {"142308", Info(
                        "Elven Mercenary",
                        "Look at 2 random Bronze special cards from your deck, then play 1.")},
        {"152202", Info(
                        "Champion of Hov",
                        "Duel an enemy.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/TRL3_FF205_01053125.mp3",
                            "https://gwent.one/audio/card/ob/en/TRL3_FF205_01053127.mp3",
                        })},
        {"112102", Info(
                        "Geralt: Igni",
                        "Destroy the Highest units on an enemy row if that row has a total of 25 or more.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/GRLT_GERALT_01129033.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.2.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.1.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.3.mp3",
                            "https://gwent.one/audio/card/ob/en/GRLT_GERALT_01054169.mp3",
                        })},
        {"112103", Info(
                        "Geralt of Rivia",
                        "",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/GRLT_GERALT_01129033.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.2.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.1.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.3.mp3",
                            "https://gwent.one/audio/card/ob/en/GRLT_GERALT_01054169.mp3",
                        })},
        {"122202", Info(
                        "Priscilla",
                        "Boost 5 random allies by 3.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/PRIS_Q305_00489643.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.9.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.10.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.11.mp3",
                        })},
        {"201618", Info(
                        "Seltkirk of Gulet",
                        "Duel an enemy. 3 Armor.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.117.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.118.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.119.mp3",
                        })},
        {"113307", Info(
                        "Adrenaline Rush",
                        "Toggle a unit's Resilience status.")},
        {"201627", Info(
                        "Shupe's Day Off",
                        "If your starting deck has no duplicates, Spawn a Shupe: Knight, Shupe: Hunter or Supe: Mage",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.168.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.169.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.170.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.171.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.172.mp3",
                        })},
        {"201731", Info(
                        "Shupe: Hunter")},
        {"201725", Info(
                        "Shupe: Mage")},
        {"200223", Info(
                        "Mandrake",
                        "Choose One: Heal a unit and Strengthen it by 6; or Reset a unit and Weaken it by 6.")},
        {"201598", Info(
                        "Bone Talisman",
                        "Choose One: Resurrect a Bronze Beast or Cultist; or Heal an ally and Strengthen it by 3.")},
        {"201737", Info(
                        "Shupe: Knight")},
        {"113201", Info(
                        "Decoy",
                        "Replay a Bronze or Silver ally and boost it by 3.")},
        {"113303", Info(
                        "First Light",
                        "Choose One: Boost all damaged allies under Hazards by 2 and clear all Hazards from your side; or Play a random Bronze unit from your deck.")},
        {"113303", Info(
                        "Clear Skies",
                        "Boost all damaged allies under Hazards by 2 and clear all Hazards from your side.")},
        {"113308", Info(
                        "Epidemic",
                        "Destroy all the Lowest units.")},
        {"200067", Info(
                        "Moonlight",
                        "Choose One: Apply a Full Moon Boon; or Apply a Blood Moon Hazard.")},
        {"201626", Info(
                        "Ciri: Nova",
                        "If you have exactly 2 copies of each Bronze card in your starting deck, set base power to 22.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/CIRI_CIRILLA_01040512.mp3",
                            "https://gwent.one/audio/card/ob/en/CIRI_Q310_00579530.mp3",
                            "https://gwent.one/audio/card/ob/en/CIRI_CIRILLA_01040548.mp3",
                            "https://gwent.one/audio/card/ob/en/CIRI_Q111_00536478.mp3",
                        })},
        {"200161", Info(
                        "Harald the Cripple",
                        "Deal 1 damage to a random enemy on the opposite row. Repeat 9 times.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.196.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.197.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.198.mp3",
                        })},
        {"162314", Info(
                        "Emissary",
                        "Look at 2 random Bronze units from your deck, then play 1.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/NIS1_VSET_00526372.mp3",
                            "https://gwent.one/audio/card/ob/en/NIS1_Q002_01048548.mp3",
                            "https://gwent.one/audio/card/ob/en/NIS1_VSET_00526356.mp3",
                        })},
        {"162213", Info(
                        "Ceallach Dyffryn",
                        "Spawn an Ambassador, Assassin or Emissary.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.109.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.110.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.111.mp3",
                        })},
        {"153201", Info(
                        "Restore",
                        "Return a Bronze or Silver Skellige unit from your graveyard to your hand, add the Doomed category to it, and set its base power to 8. Then play a card.")},
        {"152307", Info(
                        "Drummond Queensguard",
                        "Resurrect all copies of this unit on this row.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SWO5_Q205_00482375.mp3",
                            "https://gwent.one/audio/card/ob/en/SWO5_FF201_00521383.mp3",
                            "https://gwent.one/audio/card/ob/en/SWO5_FF201_00521512.mp3",
                        })},
        {"200159", Info(
                        "Bran Tuirseach",
                        "Discard up to 3 cards from your deck and Strengthen them by 1.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.193.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.194.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.195.mp3",
                        })},
        {"200036", Info(
                        "Drummond Warmonger",
                        "Discard a Bronze card from your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.5.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.6.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.7.mp3",
                        })},
        {"152305", Info(
                        "Dimun Pirate",
                        "Discard all copies of this unit from your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SBD3_VSET_00526925.mp3",
                            "https://gwent.one/audio/card/ob/en/SBD3_VSET_00527400.mp3",
                            "https://gwent.one/audio/card/ob/en/SBD3_MQ2034_01013429.mp3",
                        })},
        {"152316", Info(
                        "An Craite Raider",
                        "Whenever you Discard this unit, Resurrect it on a random row.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SGD1_CHAT_01024106.mp3",
                            "https://gwent.one/audio/card/ob/en/SGD1_VSET_00541470.mp3",
                            "https://gwent.one/audio/card/ob/en/SGD1_FF204_00523558.mp3",
                        })},
        {"152106", Info(
                        "Madman Lugos",
                        "Discard a Bronze unit from your deck, then deal damage equal to its base power to an enemy.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/LUTM_Q210_00561116.mp3",
                            "https://gwent.one/audio/card/ob/en/LUTM_SQ209_00593785.mp3",
                            "https://gwent.one/audio/card/ob/en/LUTM_LUGOS_01016673.mp3",
                            "https://gwent.one/audio/card/ob/en/LUTM_LUGOS_00437813.mp3",
                        })},
        {"152103", Info(
                        "Ermion",
                        "Draw 2 cards, then Discard 2 cards.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/MOUS_Q203_01040282.mp3",
                            "https://gwent.one/audio/card/ob/en/MOUS_Q403_00566059.mp3",
                            "https://gwent.one/audio/card/ob/en/MOUS_Q201_00439012.mp3",
                            "https://gwent.one/audio/card/ob/en/MOUS_Q210_00558067.mp3",
                        })},
        {"201778", Info(
                        "Cerys: Fearless",
                        "Resurrect the next unit you Discard.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/BECC_Q201_00500731.mp3",
                            "https://gwent.one/audio/card/ob/en/BECC_Q201_00500712.mp3",
                            "https://gwent.one/audio/card/ob/en/BECC_BECCA_01040277.mp3",
                            "https://gwent.one/audio/card/ob/en/BECC_BECCA_01040275.mp3",
                        })},
        {"200177", Info(
                        "Cerys An Craite",
                        "When 4 units are Resurrected while this unit is in the graveyard, Resurrect it on a random row.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/BECC_Q201_00500731.mp3",
                            "https://gwent.one/audio/card/ob/en/BECC_Q201_00500712.mp3",
                            "https://gwent.one/audio/card/ob/en/BECC_BECCA_01040277.mp3",
                            "https://gwent.one/audio/card/ob/en/BECC_BECCA_01040275.mp3",
                        })},
        {"132103", Info(
                        "Woodland Spirit",
                        "Spawn 3 Wolves on the melee row and apply Impenetrable Fog to the opposite row.")},
        {"122209", Info(
                        "Trollololo",
                        "9 Armor.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/TRL1_MQ1022_00411733.mp3",
                            "https://gwent.one/audio/card/ob/en/TRL1_MQ1022_00468246.mp3",
                            "https://gwent.one/audio/card/ob/en/TRL1_MQ1022_00466604.mp3",
                            "https://gwent.one/audio/card/ob/en/TRL1_MQ1022_00468244.mp3",
                            "https://gwent.one/audio/card/ob/en/TRL1_MQ1022_00468248.mp3",
                        })},
        {"122208", Info(
                        "Prince Stennis",
                        "Play the top non-Spying Bronze or Silver unit from your deck and give it 5 Armor. 3 Armor.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_STEN_200046_0302.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_STEN_200098_0258.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_STEN_200046_0316.mp3",
                        })},
        {"200098", Info(
                        "Vincent Meis",
                        "Destroy the Armor of all units, then boost self by half the value destroyed.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.203.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.202.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.201.mp3",
                        })},
        {"152209", Info(
                        "Morkvarg",
                        "Whenever Discarded, Resurrect on a random row; and whenever destroyed, Resurrect in the same position. Then, Weaken self by half.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/MRKV_SQ201_00499647.mp3",
                            "https://gwent.one/audio/card/ob/en/MRKV_SQ201_00501979.mp3",
                            "https://gwent.one/audio/card/ob/en/MRKV_SQ201_00504630.mp3",
                        })},
        {"200053", Info(
                        "Artefact Compression",
                        "Transform a Bronze or Silver unit into a Jade Figurine.")},
        {"200053", Info(
                        "Jade Figurine")},
        {"", Info(
                        "Lord of Undvik",
                        "Spying. Deathwish: Boost enemy Hjalmars by 10.")},
        {"152101", Info(
                        "Hjalmar an Craite",
                        "Spawn the Lord of Undvik on the opposite row.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/HJAL_HJALMAR_01037900.mp3",
                            "https://gwent.one/audio/card/ob/en/HJAL_HJALMAR_01037904.mp3",
                            "https://gwent.one/audio/card/ob/en/HJAL_HJALMAR_01037912.mp3",
                            "https://gwent.one/audio/card/ob/en/HJAL_Q501_00568598.mp3",
                        })},
        {"112104", Info(
                        "Regis",
                        "Drain all boosts from a unit.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/REGI_Q702_01155490.mp3",
                            "https://gwent.one/audio/card/ob/en/REGI_Q702_01155230.mp3",
                            "https://gwent.one/audio/card/ob/en/REGI_Q702_01178597.mp3",
                        })},
        {"162101", Info(
                        "Letho of Gulet",
                        "Spying. Apply Lock status to 2 units on this row, then Drain all their power.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/LETO_Q403_00319901.mp3",
                            "https://gwent.one/audio/card/ob/en/LETO_SQ102_00590678.mp3",
                            "https://gwent.one/audio/card/ob/en/LETO_LETHO_01038588.mp3",
                            "https://gwent.one/audio/card/ob/en/LETO_SQ102_00593857.mp3",
                        })},
        {"152314", Info(
                        "An Craite Longship",
                        "Deal 2 damage to a random enemy. Repeat this ability whenever you Discard a card.")},
        {"200046", Info(
                        "Tuirseach Veteran",
                        "Strengthen all your other Clan Tuirseach units in hand, deck, and on board by 1.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.410.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.411.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.412.mp3",
                        })},
        {"152304", Info(
                        "Tuirseach Hunter",
                        "Deal 5 damage.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SGD6_VSET_00544501.mp3",
                            "https://gwent.one/audio/card/ob/en/SGD6_VSET_00544569.mp3",
                            "https://gwent.one/audio/card/ob/en/SGD6_VSET_00544491.mp3",
                        })},
        {"152214", Info(
                        "Udalryk",
                        "Spying. Single-Use: Look at 2 cards from your deck. Draw one and Discard the other.")},
        {"152406", Info(
                        "Bloodcurdling Roar",
                        "Destroy an ally. Spawn a bear.")},
        {"152206", Info(
                        "Gremist",
                        "Spawn Torrential Rain, Clear Skies or Bloodcurdling Roar.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.828.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.829.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.830.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.834.mp3",
                        })},
        {"112208", Info(
                        "Operator",
                        "Single-Use, Truce: Make a default copy of a Bronze unit in your hand for both players.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_OPRT_204113_0001.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_OPRT_204113_0012.mp3",
                        })},
        {"201582", Info(
                        "Zoria Runestone",
                        "Create a Bronze or Silver Northern Realms card.")},
        {"113316", Info(
                        "Renew",
                        "Resurrect a non-Leader Gold unit.")},
        {"201597", Info(
                        "Eist Tuirseach",
                        "Spawn a Bronze Clan Tuirseach Soldier.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.47.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.48.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.49.mp3",
                        })},
        {"152312", Info(
                        "Tuirseach Axeman",
                        "Whenever an enemy on the opposite row is damaged, boost self by 1. 2 Armor.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.807.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.808.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.809.mp3",
                        })},
        {"152313", Info(
                        "Tuirseach Skirmisher",
                        "Whenever this unit is Resurrected, Strengthen it by 3.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SGD2_VSET_00165758.mp3",
                            "https://gwent.one/audio/card/ob/en/SGD2_VSET_00526547.mp3",
                            "https://gwent.one/audio/card/ob/en/SGD2_CHAT2_00165400.mp3",
                        })},
        {"201646", Info(
                        "Derran",
                        "Whenever an enemy is damaged, boost self by 1.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.232.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.233.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.234.mp3",
                        })},
        {"112210", Info(
                        "Roach",
                        "Whenever you play a Gold unit from your hand, Summon this unit to a random row.")},
        {"200164", Info(
                        "Jan Calveit",
                        "Look at the top 3 cards from your deck, then play 1.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.55.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.56.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.57.mp3",
                        })},
        {"162104", Info(
                        "Cahir Dyffryn",
                        "Resurrect a Leader.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.69.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.70.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.71.mp3",
                        })},
        {"201603", Info(
                        "Letho: Kingslayer",
                        "Choose One: Destroy an enemy Leader, then boost self by 5; or Play a Bronze or Silver Tactic from your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/LETO_Q403_00319901.mp3",
                            "https://gwent.one/audio/card/ob/en/LETO_SQ102_00590678.mp3",
                            "https://gwent.one/audio/card/ob/en/LETO_LETHO_01038588.mp3",
                            "https://gwent.one/audio/card/ob/en/LETO_SQ102_00593857.mp3",
                        })},
        {"200170", Info(
                        "King Henselt",
                        "Choose a Bronze Machine or Kaedweni ally and play all copies of it from your deck. Crew.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_HSLT_200098_0265.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_HSLT_200497_0001.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_HSLT_200098_0254.mp3",
                        })},
        {"122101", Info(
                        "Bloody Baron",
                        "If in hand, deck, or on board, boost self by 1 whenever an enemy is destroyed.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/BARN_Q103_00473473.mp3",
                            "https://gwent.one/audio/card/ob/en/BARN_Q107_00515406.mp3",
                            "https://gwent.one/audio/card/ob/en/BARN_BARON_00402523.mp3",
                            "https://gwent.one/audio/card/ob/en/BARN_Q102_00408798.mp3",
                            "https://gwent.one/audio/card/ob/en/BARN_Q103_00487067.mp3",
                        })},
        {"122207", Info(
                        "Dethmold",
                        "Spawn Torrential Rain, Clear Skies or Alzur's Thunder.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_DETM_200219_0001.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_DETM_200182_0001.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_DETM_200338_0412.mp3",
                        })},
        {"200529", Info(
                        "Ronvid the Incessant",
                        "Resurrect on a random row with 1 power on turn end. Crew.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.401.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.402.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.403.mp3",
                        })},
        {"200088", Info(
                        "Hubert Rejk",
                        "Drain all boosts from units in your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.177.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.175.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.176.mp3",
                        })},
        {"200160", Info(
                        "Crach an Craite",
                        "Strengthen the Highest non-Spying Bronze or Silver unit in your deck by 2 and play it.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/CRCH_CRACH_01040579.mp3",
                            "https://gwent.one/audio/card/ob/en/CRCH_CRACH_01040589.mp3",
                            "https://gwent.one/audio/card/ob/en/CRCH_CRACH_01040591.mp3",
                            "https://gwent.one/audio/card/ob/en/CRCH_CRACH_01001923.mp3",
                        })},
        {"152105", Info(
                        "Birna Bran",
                        "Apply Skellige Storm to an enemy row.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.206.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.207.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.205.mp3",
                        })},
        {"152107", Info(
                        "Coral",
                        "Transform a Bronze or Silver unit into a Jade Figurine.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.202.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.204.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.203.mp3",
                        })},
        {"152402", Info(
                        "Hemdall",
                        "Destroy all other units and clear all Boons and Hazards.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.199.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.201.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.200.mp3",
                        })},
        {"200028", Info(
                        "Vabjorn",
                        "Deal 2 damage to an enemy. If it was already damaged, destroy it instead.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.211.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.213.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.214.mp3",
                        })},
        {"152201", Info(
                        "Blueboy Lugos",
                        "Spawn a Spectral Whale on an enemy row.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/LUTG_SQ209_00594723.mp3",
                            "https://gwent.one/audio/card/ob/en/LUTG_LUGOS_01038779.mp3",
                        })},
        {"152203", Info(
                        "Djenge Frett",
                        "Deal 1 damage to 2 allies and Strengthen self by 2 for each.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.806.mp3",
                            "https://gwent.one/audio/card/ob/en/SWR3_MQ2013_00349800.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.804.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.805.mp3",
                        })},
        {"152204", Info(
                        "Donar an Hindar",
                        "Toggle a unit's Lock status, then move a Bronze unit from your opponent's graveyard to yours.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/DONR_Q206_00587479.mp3",
                            "https://gwent.one/audio/card/ob/en/DONR_DONAR_01037057.mp3",
                            "https://gwent.one/audio/card/ob/en/DONR_DONAR_01037055.mp3",
                        })},
        {"152205", Info(
                        "Draig Bon-Dhu",
                        "Strengthen 2 non-Leader units in your graveyard by 3.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SBR1_VSET_00527986.mp3",
                            "https://gwent.one/audio/card/ob/en/SBR1_VSET_00528002.mp3",
                        })},
        {"152207", Info(
                        "Holger Blackhand",
                        "Deal 6 damage. If the unit was destroyed, Strengthen the Highest unit in your graveyard by 3.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/HOLG_Q201_00387298.mp3",
                            "https://gwent.one/audio/card/ob/en/HOLG_HOLGER_01038014.mp3",
                            "https://gwent.one/audio/card/ob/en/HOLG_HOLGER_01038016.mp3",
                        })},
        {"152208", Info(
                        "Jutta an Dimun",
                        "Deal 1 damage to self.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SWO4_MQ2038_00509731.mp3",
                            "https://gwent.one/audio/card/ob/en/SWO4_MQ2038_00507987.mp3",
                            "https://gwent.one/audio/card/ob/en/SWO4_MQ2038_00509565.mp3",
                        })},
        {"152210", Info(
                        "Savage Bear",
                        "Whenever a unit is played from either hand on your opponent's side, deal 1 damage to it.")},
        {"152213", Info(
                        "Svanrige Tuirseach",
                        "Draw a card, then Discard a card.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.209.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.210.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.208.mp3",
                            "https://gwent.one/audio/card/ob/en/SVAN_Q210_00558425.mp3",
                            "https://gwent.one/audio/card/ob/en/SVAN_Q210_01069128.mp3",
                        })},
        {"200212", Info(
                        "Skjall",
                        "Play a random Bronze or Silver Cursed unit from your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.822.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.823.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.825.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.827.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.824.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.826.mp3",
                        })},
        {"200043", Info(
                        "Harald Houndsnout",
                        "Spawn Wilfred to the left of this unit, Wilhelm to the right, and Wilmar on the opposite row.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.130.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.131.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.129.mp3",
                        })},
        {"", Info(
                        "Wilfred"
                        "Deathwish: damage all unit on the opposite row by 1."
                        )},
        {"", Info(
                        "Wilhelm",
                        "Deathwish: strengthen a random ally by 3.")},
        {"", Info(
                        "Wilmar",
                        "Deathwish: spawn a Bear on a random opponent row.")},
        {"201644", Info(
                        "Yoana",
                        "Heal an ally, then boost it by the amount Healed.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.20.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.24.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.22.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.21.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.23.mp3",
                        })},
        {"152311", Info(
                        "An Craite Blacksmith",
                        "Strengthen an ally by 2 and give it 2 Armor.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAR3_VSET_00550878.mp3",
                            "https://gwent.one/audio/card/ob/en/SAR3_CHAT_01050115.mp3",
                            "https://gwent.one/audio/card/ob/en/SAR3_VSET_00550859.mp3",
                        })},
        {"113313", Info(
                        "An Craite Warcrier",
                        "Boost an ally by half its power.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.327.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.330.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.329.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.326.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.328.mp3",
                        })},
        {"152303", Info(
                        "An Craite Warrior",
                        "Deal 1 damage to self.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SGD2_CHAT2_00165312.mp3",
                            "https://gwent.one/audio/card/ob/en/SGD2_VSET_00541769.mp3",
                            "https://gwent.one/audio/card/ob/en/SGD2_Q208_01071227.mp3",
                        })},
        {"152302", Info(
                        "Berserker Marauder",
                        "Boost self by 1 for each damaged or Cursed ally.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SBE1_VSET_00536097.mp3",
                            "https://gwent.one/audio/card/ob/en/SBE1_Q206_00413021.mp3",
                            "https://gwent.one/audio/card/ob/en/SBE1_VSET_00536089.mp3",
                        })},
        {"152306", Info(
                        "Dimun Pirate Captain",
                        "Play a different Bronze Dimun unit from your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SBD1_MQ2003_01054136.mp3",
                            "https://gwent.one/audio/card/ob/en/SBD1_Q202_00307483.mp3",
                            "https://gwent.one/audio/card/ob/en/SBD1_MQ2002_00442097.mp3",
                            "https://gwent.one/audio/card/ob/en/SBD1_MQ2034_01028167.mp3",
                        })},
        {"200146", Info(
                        "Dimun Smuggler",
                        "Return a Bronze unit from your graveyard to your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.76.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.75.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.77.mp3",
                        })},
        {"152318", Info(
                        "Drummond Shieldmaid",
                        "Summon all copies of this unit to this row.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.2.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.1.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.3.mp3",
                        })},
        {"200147", Info(
                        "Heymaey Flaminica",
                        "Clear Hazards from the row and move 2 allies to it.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.89.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.88.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.87.mp3",
                        })},
        {"200081", Info(
                        "Heymaey Herbalist",
                        "Play a random Bronze Organic or Hazard card from your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.121.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.123.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.122.mp3",
                        })},
        {"200149", Info(
                        "Heymaey Protector",
                        "Play a Bronze Item from your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.80.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.81.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.79.mp3",
                        })},
        {"152308", Info(
                        "Heymaey Skald",
                        "Boost all allies from a Clan of your choice by 1.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/DROG_Q206_01072830.mp3",
                            "https://gwent.one/audio/card/ob/en/DROG_BARD_01036857.mp3",
                            "https://gwent.one/audio/card/ob/en/DROG_Q206_00329460.mp3",
                        })},
        {"152301", Info(
                        "Raging Berserker",
                        "When this unit is damaged or Weakened, transform into a Raging Bear.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SBE2_VSET_00536507.mp3",
                            "https://gwent.one/audio/card/ob/en/SBE2_VSET_00536513.mp3",
                            "https://gwent.one/audio/card/ob/en/SBE2_VSET_00536587.mp3",
                        })},
        {"152405", Info(
                        "Raging Bear",
                        "No ability.")},
        {"200102", Info(
                        "Hym",
                        "Choose One: Play a Bronze or Silver Cursed unit from your deck; or Create a Silver unit from your opponent's starting deck.")},
        {"152104", Info(
                        "Kambi",
                        "Spying. Deathwish: Spawn Hemdall on a random row on this unit's side.")},
        {"200103", Info(
                        "Olaf",
                        "Deal 10 damage to self. Reduce the damage inflicted by 2 for each Beast you played this match.")},
        {"200104", Info(
                        "Ulfhedinn",
                        "Deal 1 damage to all enemies. If they were already damaged, deal 2 damage instead.")},
        {"152109", Info(
                        "Wild Boar of the Sea",
                        "On turn end, Strengthen the unit to the left by 1, then deal 1 damage to the unit to the right. 5 Armor.")},
        {"201623", Info(
                        "Giant Boar",
                        "Destroy a random ally, excluding this unit, then boost self by 10.")},
        {"201642", Info(
                        "Ornamental Sword",
                        "Create a Bronze or Silver Skellige Soldier and Strengthen it by 3.")},
        {"152403", Info(
                        "Spectral Whale",
                        "Spying. Move to a random row and deal 1 damage to all other units on it on turn end.")},
        {"200105", Info(
                        "Dimun Warship",
                        "Deal 1 damage to the same unit 4 times.")},
        {"122107", Info(
                        "Triss: Butterflies",
                        "Boost the Lowest allies by 1 on turn end.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_TRIS_104122_2446.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.17.mp3",
                            "https://gwent.one/audio/card/ob/en/TRSS_Q310_00545347.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.18.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.19.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_TRIS_100285_0008.mp3",
                        })},
        {"112108", Info(
                        "Yennefer",
                        "Choose One: Spawn a Unicorn that boosts all other units by 2; or Spawn a Chironex that deals 2 damage to all other units.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/YENN_YENNEFER_01041495.mp3",
                            "https://gwent.one/audio/card/ob/en/YENN_YENNEFER_01041488.mp3",
                            "https://gwent.one/audio/card/ob/en/YENN_YENNEFER_01041493.mp3",
                        })},
        {"112402", Info(
                        "Chironex",
                        "Deal 2 damage to all other units.")},
        {"112401", Info(
                        "Unicorn",
                        "Boost all other units by 2.")},
        {"200523", Info(
                        "Germain Piquant",
                        "Spawn 2 Cows on each side of this unit.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.261.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.260.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.262.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.244.mp3",
                        })},
        {"113207", Info(
                        "Commander's Horn",
                        "Boost 5 adjacent units by 3.")},
        {"200019", Info(
                        "Marching Orders",
                        "Boost the Lowest Bronze or Silver unit in your deck by 2, then play it.")},
        {"113209", Info(
                        "Alzur's Double Cross",
                        "Boost the Highest Bronze or Silver unit in your deck by 2, then play it.")},
        {"200296", Info(
                        "Alba Armored Cavalry",
                        "Whenever an ally appears, boost self by 1.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.379.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.380.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.381.mp3",
                        })},
        {"201661", Info(
                        "Sentry",
                        "Boost all allied copies of a Soldier by 2.")},
        {"162309", Info(
                        "Nauzicaa Sergeant",
                        "Clear Hazards from its row and boost an ally or a Revealed unit in your hand by 3.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.439.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.440.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.438.mp3",
                        })},
        {"201610", Info(
                        "Slave Infantry",
                        "Spawn a Doomed default copy of this unit on your other rows.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.108.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.110.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.112.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.109.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.111.mp3",
                        })},
        {"201617", Info(
                        "Recruit",
                        "Play a random different Bronze Soldier from your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.36.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.35.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.34.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.33.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.32.mp3",
                        })},
        {"201619", Info(
                        "Ointment",
                        "Resurrect a Bronze unit with 5 power or less.")},
        {"162105", Info(
                        "Vilgefortz",
                        "Destroy an ally, then play the top card of your deck; or Truce: Destroy an enemy, then your opponent draws and Reveals a Bronze card.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.72.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.73.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.74.mp3",
                        })},
        {"200050", Info(
                        "Vreemde",
                        "Create a Bronze Nilfgaardian Soldier.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.109.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.110.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.111.mp3",
                        })},
        {"201576", Info(
                        "Cow")},
        {"162208", Info(
                        "Auckes",
                        "Toggle 2 units' Lock statuses.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.112.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.113.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.114.mp3",
                        })},
        {"112202", Info(
                        "Eskel",
                        "Summon Vesemir and Lambert to this row.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.21.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.22.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.23.mp3",
                            "https://gwent.one/audio/card/ob/en/ESKL_ESKEL_01037262.mp3",
                        })},
        {"112204", Info(
                        "Lambert",
                        "Summon Eskel and Vesemir to this row.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/LMBT_Q401_00523875.mp3",
                            "https://gwent.one/audio/card/ob/en/LMBT_SQ106_00586496.mp3",
                            "https://gwent.one/audio/card/ob/en/LMBT_Q401_01058899.mp3",
                            "https://gwent.one/audio/card/ob/en/LMBT_Q403_00572964.mp3",
                            "https://gwent.one/audio/card/ob/en/LMBT_Q401_00531130.mp3",
                            "https://gwent.one/audio/card/ob/en/LMBT_Q403_00550012.mp3",
                        })},
        {"112203", Info(
                        "Vesemir",
                        "Summon Eskel and Lambert to this row.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VSMR_VESEMIR_01040765.mp3",
                            "https://gwent.one/audio/card/ob/en/VSMR_VESEMIR_01000012.mp3",
                            "https://gwent.one/audio/card/ob/en/VSMR_Q001_00546725.mp3",
                        })},
        {"200171", Info(
                        "Tridam Infantry",
                        "4 Armor.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.230.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.231.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.226.mp3",
                        })},
        {"142205", Info(
                        "Vrihedd Dragoon",
                        "Boost a random non-Spying unit in your hand by 1 on turn end.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.779.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.781.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.780.mp3",
                        })},
        {"142210", Info(
                        "Malena",
                        "Ambush: After 2 turns, flip over and Charm the Highest Bronze or Silver enemy with 5 power or less on turn start.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_MALN_106817_0005.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_MALN_106745_0017.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_MALN_106657_0009.mp3",
                        })},
        {"200055", Info(
                        "Unseen Elder",
                        "Drain a unit by half.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.255.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.256.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.257.mp3",
                        })},
        {"201584", Info(
                        "Devana Runestone",
                        "Create a Bronze or Silver Monster card.")},
        {"201583", Info(
                        "Dazhbog Runestone",
                        "Create a Bronze or Silver Nilfgaard card.")},
        {"201585", Info(
                        "Morana Runestone",
                        "Create a Bronze or Silver Scoia'tael card.")},
        {"201581", Info(
                        "Stribog Runestone",
                        "Create a Bronze or Silver Skellige card.")},
        {"200225", Info(
                        "Muzzle",
                        "Charm a Bronze or Silver enemy with 8 power or less.")},
        {"201647", Info(
                        "Rock Barrage",
                        "Deal 7 damage to an enemy and move it to the row above. If the row is full, destroy the enemy instead.")},
        {"201587", Info(
                        "Whispering Hillock",
                        "Create a Bronze or Silver Organic card.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.4.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.5.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.2.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.3.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.1.mp3",
                        })},
        {"132207", Info(
                        "Brewess",
                        "Summon Whispess and Weavess to this row.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/BREW_Q105_00418675.mp3",
                            "https://gwent.one/audio/card/ob/en/BREW_Q105_00531820.mp3",
                            "https://gwent.one/audio/card/ob/en/BREW_Q111_00576135.mp3",
                        })},
        {"132208", Info(
                        "Weavess",
                        "Summon Brewess and Whispess to this row.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/WEAV_Q105_00531814.mp3",
                            "https://gwent.one/audio/card/ob/en/WEAV_Q503_00579064.mp3",
                            "https://gwent.one/audio/card/ob/en/WEAV_Q503_00578937.mp3",
                        })},
        {"132206", Info(
                        "Whispess",
                        "Summon Brewess and Weavess to this row.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/WHSP_Q105_00419061.mp3",
                            "https://gwent.one/audio/card/ob/en/WHSP_Q105_00531816.mp3",
                            "https://gwent.one/audio/card/ob/en/WHSP_Q105_00419057.mp3",
                            "https://gwent.one/audio/card/ob/en/WHSP_Q105_00382577.mp3",
                            "https://gwent.one/audio/card/ob/en/LMBT_Q401_00531130.mp3",
                            "https://gwent.one/audio/card/ob/en/WHSP_Q105_00382587.mp3",
                        })},
        {"200222", Info(
                        "Weavess: Incantation",
                        "Choose One: Strengthen all your other Relicts in hand, deck, and on board by 2; or Play a Bronze or Silver Relict from your deck and Strengthen it by 2.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/WEAV_Q105_00531814.mp3",
                            "https://gwent.one/audio/card/ob/en/WEAV_Q503_00579064.mp3",
                            "https://gwent.one/audio/card/ob/en/WEAV_Q503_00578937.mp3",
                        })},
        {"200221", Info(
                        "Brewess: Ritual",
                        "Resurrect 2 Bronze Deathwish units.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/BREW_Q105_00418675.mp3",
                            "https://gwent.one/audio/card/ob/en/BREW_Q105_00531820.mp3",
                            "https://gwent.one/audio/card/ob/en/BREW_Q111_00576135.mp3",
                        })},
        {"200220", Info(
                        "Whispess: Tribute",
                        "Play a Bronze or Silver Organic card from your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/WHSP_Q105_00419061.mp3",
                            "https://gwent.one/audio/card/ob/en/WHSP_Q105_00531816.mp3",
                            "https://gwent.one/audio/card/ob/en/WHSP_Q105_00419057.mp3",
                            "https://gwent.one/audio/card/ob/en/WHSP_Q105_00382577.mp3",
                            "https://gwent.one/audio/card/ob/en/LMBT_Q401_00531130.mp3",
                            "https://gwent.one/audio/card/ob/en/WHSP_Q105_00382587.mp3",
                        })},
        {"200089", Info(
                        "Nivellen",
                        "Move all units on a row to random rows.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.167.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.168.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.169.mp3",
                        })},
        {"200031", Info(
                        "Leo Bonhart",
                        "Reveal one of your units and deal damage equal to its base power to an enemy.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.13.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.14.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.15.mp3",
                        })},
        {"200163", Info(
                        "Morvran Voorhis",
                        "Reveal up to 4 cards.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.52.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.53.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.54.mp3",
                        })},
        {"162203", Info(
                        "Cynthia",
                        "Reveal the Highest unit in your opponent's hand and boost self by its power.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_CNTH_303653_0335.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_CNTH_303743_0002.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_CNTH_303656_0001.mp3",
                        })},
        {"162209", Info(
                        "Serrit",
                        "Deal 7 damage to an enemy; or Set a Revealed opposing unit's power to 1.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.115.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.116.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.117.mp3",
                        })},
        {"162206", Info(
                        "Sweers",
                        "Choose an enemy or a Revealed unit in your opponent's hand, then move all copies of it from their deck to the graveyard.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.100.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.101.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.102.mp3",
                        })},
        {"162107", Info(
                        "Tibor Eggebracht",
                        "Truce: Boost self by 15, then your opponent draws a Revealed Bronze card.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.66.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.67.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.68.mp3",
                        })},
        {"162103", Info(
                        "Vattier de Rideaux",
                        "Reveal up to 2 of your cards, then Reveal the same number of your opponent's randomly.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.106.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.107.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.108.mp3",
                        })},
        {"162201", Info(
                        "Albrich",
                        "Truce: Each player draws a card. The opponent's card is Revealed.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.78.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.79.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.80.mp3",
                        })},
        {"200041", Info(
                        "Hefty Helge",
                        "Deal 1 damage to all enemies except those on the opposite row. If this unit was Revealed, deal damage to all enemies instead.")},
        {"162316", Info(
                        "Alchemist",
                        "Reveal up to 2 cards.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/MAG1_SHOP_00423237.mp3",
                            "https://gwent.one/audio/card/ob/en/MAG1_SHOP_00459610.mp3",
                            "https://gwent.one/audio/card/ob/en/MAG1_SHOP_00423227.mp3",
                        })},
        {"162301", Info(
                        "Daerlan Soldier",
                        "Whenever you Reveal this unit, play it automatically on a random row and draw a card.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.417.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.418.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.419.mp3",
                        })},
        {"162306", Info(
                        "Fire Scorpion",
                        "Deal 5 damage to an enemy. Whenever you Reveal this unit, trigger its ability.")},
        {"132402", Info(
                        "Wild Hunt Hound",
                        "Play Biting Frost from your deck.")},
        {"132309", Info(
                        "Wild Hunt Warrior",
                        "Deal 3 damage to an enemy. If the enemy is destroyed or is under Biting Frost, boost self by 2.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.793.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.792.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.794.mp3",
                        })},
        {"162317", Info(
                        "Mangonel",
                        "Deal 2 damage to a random enemy. Repeat this ability whenever you Reveal a card.")},
        {"162318", Info(
                        "Nilfgaardian Knight",
                        "Reveal a random card in your hand, with priority given to Bronze, then Silver, then Gold. 2 Armor.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.441.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.442.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.443.mp3",
                        })},
        {"162303", Info(
                        "Spotter",
                        "Boost self by the base power of a Revealed Bronze or Silver unit.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/NILF4_CHAT_01051421.mp3",
                            "https://gwent.one/audio/card/ob/en/NILF4_VSET_00514238.mp3",
                            "https://gwent.one/audio/card/ob/en/NILF4_CHAT_01051417.mp3",
                        })},
        {"200518", Info(
                        "Venendal Elite",
                        "Switch this unit's power with that of a Revealed unit.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.383.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.384.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.382.mp3",
                        })},
        {"201616", Info(
                        "Master of Disguise",
                        "Conceal 2 cards.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.359.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.360.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.361.mp3",
                        })},
        {"200227", Info(
                        "Henry var Attre",
                        "Conceal any number of units. If allies, boost by 2. If enemies, deal 2 damage.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.435.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.436.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.437.mp3",
                        })},
        {"200022", Info(
                        "Summoning Circle",
                        "Spawn a default copy of the last Bronze or Silver non-Agent unit that appeared.")},
        {"200080", Info(
                        "Xavier Moran",
                        "Boost this unit by the default power of the last other Dwarf you played.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.290.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.291.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.292.mp3",
                        })},
        {"201601", Info(
                        "Yennefer",
                        "Spawn the last Bronze or Silver Spell you played.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/YENN_YENNEFER_01041495.mp3",
                            "https://gwent.one/audio/card/ob/en/YENN_YENNEFER_01041488.mp3",
                            "https://gwent.one/audio/card/ob/en/YENN_YENNEFER_01041493.mp3",
                        })},
        {"122102", Info(
                        "Vernon Roche",
                        "Deal 7 damage to an enemy. At game start, add a Blue Stripe Commando to your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/ROCH_ROCHE_00541126.mp3",
                            "https://gwent.one/audio/card/ob/en/ROCH_MQ3035_01064844.mp3",
                        })},
        {"122310", Info(
                        "Blue Stripe Scout",
                        "Boost all Temerian allies and your non-Spying Temerian units in hand and deck with the same power as this unit by 1. Crew.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_RS01_101992_0004.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_ROS1_102779_0005.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_RS01_106541_0014.mp3",
                        })},
        {"122311", Info(
                        "Blue Stripe Commando",
                        "Whenever a different Temerian ally with the same power is played, Summon a copy of this unit to a random row.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_ROS3_102779_0003.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_RS03_106543_0003.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_RS03_106543_0004.mp3",
                        })},
        {"132407", Info(
                        "Imperial Golem",
                        "Summon a copy of this unit to a random row whenever you Reveal a card in your opponent's hand.")},
        {"200026", Info(
                        "Wild Hunt Navigator",
                        "Choose a Bronze non-Mage Wild Hunt ally and play a copy of it from your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.45.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.44.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.43.mp3",
                        })},
        {"132214", Info(
                        "Nithral",
                        "Deal 6 damage to an enemy. Increase damage by 1 for each Wild Hunt unit in your hand.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/WHW1_Q104_00555151.mp3",
                            "https://gwent.one/audio/card/ob/en/WHW1_Q104_00555148.mp3",
                            "https://gwent.one/audio/card/ob/en/WHW1_Q104_00555150.mp3",
                        })},
        {"132108", Info(
                        "Miruna",
                        "After 2 turns, Charm the Highest enemy on the opposite row on turn start.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SCC3_VSET_01053075.mp3",
                            "https://gwent.one/audio/card/ob/en/SCC3_VSET_01053091.mp3",
                            "https://gwent.one/audio/card/ob/en/SCC3_VSET_01053077.mp3",
                        })},
        {"132102", Info(
                        "Imlerith",
                        "Deal 4 damage to an enemy. If the enemy is under Biting Frost, deal 8 damage instead.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/IMLR_Q403_00524739.mp3",
                            "https://gwent.one/audio/card/ob/en/IMLR_Q403_00524776.mp3",
                            "https://gwent.one/audio/card/ob/en/IMLR_Q111_01062046.mp3",
                        })},
        {"132106", Info(
                        "Caretaker",
                        "Resurrect a Bronze or Silver unit from your opponent's graveyard.")},
        {"201660", Info(
                        "Ruehin",
                        "Strengthen all your other Insectoids and Cursed units in hand, deck, and on board by 1.")},
        {"132218", Info(
                        "Old Speartip: Asleep",
                        "Strengthen all your other Ogroids in hand, deck, and on board by 1.")},
        {"132408", Info(
                        "Old Speartip",
                        "Deal 2 damage to 5 random enemies on the opposite row.")},
        {"200052", Info(
                        "Golyat",
                        "Boost self by 7. Whenever this unit is damaged, deal 2 damage to self.")},
        {"201701", Info(
                        "Barbegazi",
                        "Resilience. Consume an ally and boost self by its power.")},
        {"132306", Info(
                        "Ghoul",
                        "Consume a Bronze or Silver unit from your graveyard and boost self by its power.")},
        {"201606", Info(
                        "Forktail",
                        "Consume 2 allies and boost self by their power.")},
        {"201743", Info(
                        "Arachas Queen",
                        "Immune. Consume 3 allies and boost self by their power.")},
        {"201698", Info(
                        "Ozzrel",
                        "Consume a Bronze or Silver unit from either graveyard and boost by its power.")},
        {"132107", Info(
                        "Kayran",
                        "Consume a unit with 7 power or less and boost self by its power.")},
        {"132202", Info(
                        "Mourntart",
                        "Consume all Bronze and Silver units in your graveyard and boost self by 1 for each.")},
        {"132216", Info(
                        "Toad Prince",
                        "Draw a unit, then Consume a unit in your hand and boost self by its power.")},
        {"112405", Info(
                        "Fiend",
                        "No ability.")},
        {"112405", Info(
                        "Morvudd",
                        "Toggle a unit's Lock status. If it was an enemy, halve its power.")},
        {"132313", Info(
                        "Ekimmara",
                        "Drain a unit by 3.")},
        {"200295", Info(
                        "Rotfiend",
                        "Deathwish: Deal 2 damage to units on the opposite row.")},
        {"200038", Info(
                        "Archespore",
                        "Move to a random row and deal 1 damage to a random enemy on turn start. Deathwish: Deal 4 damage to a random enemy.")},
        {"200037", Info(
                        "Cyclops",
                        "Destroy an ally and deal damage equal to its power to an enemy.")},
        {"132406", Info(
                        "Maerolorn",
                        "Play a Bronze Deathwish unit from your deck.")},
        {"133302", Info(
                        "Monster Nest",
                        "Spawn a Bronze Necrophage or Insectoid and boost it by 1.")},
        {"132304", Info(
                        "Arachas Drone",
                        "Summon all copies of this unit to this row.")},
        {"200114", Info(
                        "Alpha Werewolf",
                        "Spawn a Wolf on each side of this unit on contact with Full Moon.")},
        {"201600", Info(
                        "Werewolf",
                        "Immune. Boost this unit by 7 on first contact with Full Moon.")},
        {"131101", Info(
                        "Eredin Bréacc Glas",
                        "Spawn a Bronze Wild Hunt unit.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/ERDN_Q501_00534051.mp3",
                            "https://gwent.one/audio/card/ob/en/ERDN_EREDIN_01040841.mp3",
                            "https://gwent.one/audio/card/ob/en/ERDN_EREDIN_01040845.mp3",
                            "https://gwent.one/audio/card/ob/en/ERDN_Q311_00312654.mp3",
                            "https://gwent.one/audio/card/ob/en/ERDN_EREDIN_01040754.mp3",
                        })},
        {"132104", Info(
                        "Caranthir Ar-Feiniel",
                        "Move an enemy to the row opposite this unit and apply Biting Frost to that row.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.192.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.191.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.189.mp3",
                        })},
        {"201781", Info(
                        "Imlerith: Sabbath",
                        "Every turn, Duel the Highest enemy on turn end. If this unit survives, Heal it by 2 and give it 2 Armor. 2 Armor.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.852.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.853.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.851.mp3",
                        })},
        {"200158", Info(
                        "Dagon",
                        "Spawn Impenetrable Fog or Torrential Rain.")},
        {"132210", Info(
                        "Ifrit",
                        "Spawn 3 Lesser Ifrits to the right of this unit.")},
        {"132404", Info(
                        "Lesser Ifrit",
                        "Deal 1 damage to a random enemy.")},
        {"200534", Info(
                        "She-Troll of Vergen",
                        "Play a Bronze Deathwish unit from your deck, Consume it and boost self by its base power.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.406.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.405.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.404.mp3",
                        })},
        {"132303", Info(
                        "Wyvern",
                        "Deal 5 damage to an enemy.")},
        {"132203", Info(
                        "Abaya",
                        "Spawn Torrential Rain, Clear Skies or Arachas Venom.")},
        {"201657", Info(
                        "Parasite",
                        "Deal 12 damage to an enemy; or Boost an ally by 12.")},
        {"200218", Info(
                        "Jotunn",
                        "Move 3 enemies to the row opposite this unit and deal 2 damage to them. If that row is under Biting Frost, deal 3 damage instead.")},
        {"132212", Info(
                        "Ice Giant",
                        "Boost by 6 if Biting Frost is anywhere on the board.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/ice_giant_aggro07.mp3",
                            "https://gwent.one/audio/card/ob/en/ice_giant_aggro06.mp3",
                        })},
        {"200502", Info(
                        "Ice Troll",
                        "Duel an enemy. If it's under Biting Frost, deal double damage.")},
        {"132314", Info(
                        "Drowner",
                        "Move an enemy to the row opposite this unit and deal 2 damage to it. If that row is under a Hazard, deal 4 damage instead.")},
        {"132301", Info(
                        "Foglet",
                        "Whenever you apply Impenetrable Fog to an enemy row, Summon a copy of this unit to the opposite row.")},
        {"132302", Info(
                        "Ancient Foglet",
                        "Boost by 1 if Impenetrable Fog is on the board on turn end.")},
        {"132101", Info(
                        "Draug",
                        "Resurrect units as 1-power Draugirs until you fill this row.")},
        {"132101", Info(
                        "Draugir")},
        {"132217", Info(
                        "Celaeno Harpy",
                        "Spawn 2 Harpy Eggs to the left of this unit.")},
        {"132316", Info(
                        "Harpy Egg",
                        "When Consumed, boost Consuming unit by 4. Deathwish: Spawn a Harpy Hatchling on a random row.")},
        {"132315", Info(
                        "Harpy Hatchling")},
        {"132201", Info(
                        "Arachas Behemoth",
                        "The next 4 times you Consume a unit, Spawn an Arachas Hatchling on a random row.")},
        {"132304", Info(
                        "Arachas Hatchling",
                        "Summon all Arachas Drones.")},
        {"132307", Info(
                        "Archgriffin",
                        "Clear Hazards on its row.")},
        {"132312", Info(
                        "Griffin",
                        "Trigger the Deathwish of a Bronze ally.")},
        {"201700", Info(
                        "Bridge Troll",
                        "Move a Hazard on an enemy row to a different enemy row.")},
        {"200233", Info(
                        "Cockatrice",
                        "Reset a unit.")},
        {"132220", Info(
                        "Nekurat",
                        "Spawn Moonlight.")},
        {"200112", Info(
                        "Siren",
                        "Play Moonlight from your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.91.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.93.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.92.mp3",
                        })},
        {"132409", Info(
                        "Lamia",
                        "Deal 4 damage to an enemy. If the enemy is under Blood Moon, deal 7 damage instead.")},
        {"132305", Info(
                        "Nekker",
                        "If in hand, deck, or on board, boost self by 1 whenever you Consume a card. Deathwish: Summon a copy of this unit to the same position.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/nekker_mumble_003.mp3",
                            "https://gwent.one/audio/card/ob/en/nekker_attack_004.mp3",
                            "https://gwent.one/audio/card/ob/en/nekker_attack_009.mp3",
                        })},
        {"132211", Info(
                        "Nekker Warrior",
                        "Choose a Bronze ally and add 2 copies of it to the bottom of your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/nekker_scream_006.mp3",
                            "https://gwent.one/audio/card/ob/en/nekker_scream_004.mp3",
                        })},
        {"200539", Info(
                        "Slyzard",
                        "Consume a different Bronze unit from your graveyard, then play a copy of it from your deck.")},
        {"201599", Info(
                        "Werecat",
                        "Deal 5 damage to an enemy, then deal 1 damage to all enemies under Blood Moon.")},
        {"132315", Info(
                        "Harpy",
                        "Whenever you destroy an allied Beast, Summon a copy of this unit to the same position.")},
        {"200301", Info(
                        "Wild Hunt Drakkar",
                        "Boost all Wild Hunt allies by 1. Whenever another Wild Hunt ally appears, boost it by 1.")},
        {"131102", Info(
                        "Ge'els",
                        "Look at a random Gold and Silver card from your deck, then play 1 and move the other to the top of the deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/GEEL_Q311_00312005.mp3",
                            "https://gwent.one/audio/card/ob/en/GEEL_Q311_00312236.mp3",
                        })},
        {"132310", Info(
                        "Wild Hunt Rider",
                        "Increase the damage dealt by Biting Frost on the opposite row by 1.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.798.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.796.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.797.mp3",
                        })},
        {"132308", Info(
                        "Vran Warrior",
                        "Consume the unit to the right and boost self by its power. Every 2 turns, repeat its ability on turn start.")},
        {"152317", Info(
                        "An Craite Armorsmith",
                        "Heal 2 allies and give them 3 Armor.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAR1_SHOP_00422532.mp3",
                            "https://gwent.one/audio/card/ob/en/SAR1_VSET_00550731.mp3",
                            "https://gwent.one/audio/card/ob/en/SAR1_SHOP_00434397.mp3",
                        })},
        {"132105", Info(
                        "Avallac'h",
                        "Truce: Each player draws 2 cards.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/AVLC_Q311_01022646.mp3",
                            "https://gwent.one/audio/card/ob/en/AVLC_Q311_00454814.mp3",
                            "https://gwent.one/audio/card/ob/en/AVLC_Q311_00584753.mp3",
                            "https://gwent.one/audio/card/ob/en/AVLC_AVALLACH_01040188.mp3",
                            "https://gwent.one/audio/card/ob/en/AVLC_Q311_00312745.mp3",
                        })},
        {"112112", Info(
                        "Avallac'h: Sage",
                        "Spawn a default copy of a random Gold or Silver unit from your opponent's starting deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/AVLC_Q311_01022646.mp3",
                            "https://gwent.one/audio/card/ob/en/AVLC_Q311_00454814.mp3",
                            "https://gwent.one/audio/card/ob/en/AVLC_Q311_00584753.mp3",
                            "https://gwent.one/audio/card/ob/en/AVLC_AVALLACH_01040188.mp3",
                            "https://gwent.one/audio/card/ob/en/AVLC_Q311_00312745.mp3",
                        })},
        {"113101", Info(
                        "Ragh Nar Roog",
                        "Apply a Hazard to each enemy row that deals 2 damage to the Highest unit on turn start..")},
        {"201772", Info(
                        "Geralt: Professional",
                        "Deal 4 damage to an enemy. If it's a Monster faction unit, destroy it instead.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/GRLT_GERALT_01129033.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.2.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.1.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.3.mp3",
                            "https://gwent.one/audio/card/ob/en/GRLT_GERALT_01054169.mp3",
                        })},
        {"112111", Info(
                        "Geralt: Aard",
                        "Deal 3 damage to 3 enemies and move them to the row above.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/GRLT_GERALT_01129033.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.2.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.1.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.3.mp3",
                            "https://gwent.one/audio/card/ob/en/GRLT_GERALT_01054169.mp3",
                        })},
        {"201523", Info(
                        "Geralt: Yrden",
                        "Reset all units on a row and remove their statuses.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/GRLT_GERALT_01129033.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.2.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.1.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.3.mp3",
                            "https://gwent.one/audio/card/ob/en/GRLT_GERALT_01054169.mp3",
                        })},
        {"112110", Info(
                        "Ciri: Dash",
                        "Whenever this unit is Discarded or destroyed, return it to your deck and Strengthen it by 3.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/CIRI_CIRILLA_01040512.mp3",
                            "https://gwent.one/audio/card/ob/en/CIRI_Q310_00579530.mp3",
                            "https://gwent.one/audio/card/ob/en/CIRI_CIRILLA_01040548.mp3",
                            "https://gwent.one/audio/card/ob/en/CIRI_Q111_00536478.mp3",
                        })},
        {"200062", Info(
                        "Aguara",
                        "Choose Two: Boost the Lowest ally by 5; Boost a random unit in your hand by 5; Deal 5 damage to the Highest enemy; Charm a random enemy Elf with 5 power or less.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.156.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.155.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.154.mp3",
                        })},
        {"200056", Info(
                        "Aguara: True Form",
                        "Create any Bronze or Silver Spell.")},
        {"200018", Info(
                        "Korathi Heatwave",
                        "Apply a Hazard to each enemy row that deals 2 damage to the Lowest unit on turn start.")},
        {"200532", Info(
                        "Ale of the Ancestors",
                        "Apply Golden Froth to the row.")},
        {"200519", Info(
                        "Mahakam Ale",
                        "Boost a random ally on each row by 4.")},
        {"122213", Info(
                        "Odrin",
                        "Move to a random row and boost all other allies on it by 1 on turn start.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_ODRI_200546_0002.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_ODRI_200481_0002.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_ODRI_200546_0001.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_ODRI_200559_0001.mp3",
                        })},
        {"142204", Info(
                        "Toruviel",
                        "Ambush: When your opponent passes, flip over and boost 2 units on each side by 2.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.775.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.777.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.776.mp3",
                        })},
        {"112101", Info(
                        "Ciri",
                        "Whenever you lose a round, return this unit to your hand. 2 Armor.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/CIRI_CIRILLA_01040512.mp3",
                            "https://gwent.one/audio/card/ob/en/CIRI_Q310_00579530.mp3",
                            "https://gwent.one/audio/card/ob/en/CIRI_CIRILLA_01040548.mp3",
                            "https://gwent.one/audio/card/ob/en/CIRI_Q111_00536478.mp3",
                        })},
        {"142104", Info(
                        "Milva",
                        "Return each player's Highest Bronze or Silver unit to their deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.142.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.144.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.143.mp3",
                        })},
        {"122210", Info(
                        "Princess Pavetta",
                        "Return each player's Lowest Bronze or Silver unit to their deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.38.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.40.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.37.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.39.mp3",
                        })},
        {"162401", Info(
                        "The Guardian",
                        "Add a Lesser Guardian to the top of your opponent's deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.386.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.387.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.385.mp3",
                        })},
        {"162401", Info(
                        "Lesser Guardian")},
        {"132215", Info(
                        "Gaunter O'Dimm",
                        "Gamble with Gaunter: Guess the power of the card he's picked to play it.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/MRRR_Q602_01116657.mp3",
                            "https://gwent.one/audio/card/ob/en/MRRR_Q605_01108178.mp3",
                            "https://gwent.one/audio/card/ob/en/MRRR_Q605_01132010.mp3",
                            "https://gwent.one/audio/card/ob/en/MRRR_Q605_01108152.mp3",
                            "https://gwent.one/audio/card/ob/en/MRRR_Q605_01110505.mp3",
                        })},
        {"122214", Info(
                        "Kaedweni Sergeant",
                        "Clear Hazards from its row. 3 Armor. Crew.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.46.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.47.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.48.mp3",
                        })},
        {"122302", Info(
                        "Reinforced Ballista",
                        "Deal 2 damage to an enemy. Crewed: Repeat its ability.")},
        {"122105", Info(
                        "Sigismund Dijkstra",
                        "Spying. Play the top 2 cards from your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/DJKS_Q303_00486613.mp3",
                            "https://gwent.one/audio/card/ob/en/DJKS_Q303_00378559.mp3",
                            "https://gwent.one/audio/card/ob/en/DJKS_MQ3035_01067766.mp3",
                            "https://gwent.one/audio/card/ob/en/DJKS_Q303_00417640.mp3",
                        })},
        {"113206", Info(
                        "White Frost",
                        "Apply Biting Frost to 2 adjacent enemy rows.")},
        {"200226", Info(
                        "Wolfsbane",
                        "After 3 turns in the graveyard, deal 6 damage to the Highest enemy and boost the Lowest ally by 6 on turn end.")},
        {"122313", Info(
                        "Dun Banner",
                        "If you are losing by more than 25 on turn start, Summon this unit to a random row.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_KG06_202931_0012.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_KG06_200420_0005.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_KG06_202931_0005.mp3",
                        })},
        {"142211", Info(
                        "Aelirenn",
                        "If 5 Elf allies are on the board on any turn end, Summon this unit to a random row.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.183.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.184.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.185.mp3",
                        })},
        {"200079", Info(
                        "HanmarvynsDream",
                        "Spawn a default copy of a non-Leader Gold unit from your opponent's graveyard and boost it by 2.")},
        {"201697", Info(
                        "Black Blood",
                        "Choose One: Create a Bronze Necrophage or Vampire and boost it by 2; or Destroy a Bronze or Silver Necrophage or Vampire.")},
        {"201634", Info(
                        "Bekker's Rockslide",
                        "Deal 2 damage to 10 random enemies.")},
        {"113315", Info(
                        "Bekker's Dark Mirror",
                        "Transfer up to 10 power between the Highest and Lowest unit.")},
        {"113202", Info(
                        "Merigold's Hailstorm",
                        "Halve the power of all Bronze and Silver units on a row.")},
        {"200020", Info(
                        "Necromancy",
                        "Banish a Bronze or Silver unit from either graveyard, then boost an ally by its power.")},
        {"113204", Info(
                        "Stammelford's Tremor",
                        "Deal 1 damage to all enemies.")},
        {"200530", Info(
                        "Expired Ale",
                        "Deal 6 damage to the Highest enemy on each row.")},
        {"200078", Info(
                        "Trial of the Grasses",
                        "Boost a Witcher to 25 power; or Deal 10 damage to a non-Witcher unit. If it survives, boost it to 25 power.")},
        {"113205", Info(
                        "Dimeritium Bomb",
                        "Reset all boosted units on a row.")},
        {"201639", Info(
                        "Garrison",
                        "Create a Bronze or Silver unit from your opponent's starting deck and boost it by 2.")},
        {"113102", Info(
                        "The Last Wish",
                        "Look at 2 random cards from your deck, then play 1.")},
        {"113319", Info(
                        "Dimeritium Shackles",
                        "Toggle a unit's Lock status. If an enemy, deal 4 damage to it.")},
        {"133301", Info(
                        "Wyvern Scale Shield",
                        "Boost a unit by the base power of a Bronze or Silver unit in your hand.")},
        {"201656", Info(
                        "Mastercrafted Spear",
                        "Deal damage equal to the base power of a Bronze or Silver unit in your hand.")},
        {"200008", Info(
                        "Petri's Philter",
                        "Boost 6 random allies by 2.")},
        {"200009", Info(
                        "Shrike",
                        "Deal 2 damage to 6 random enemies.")},
        {"200154", Info(
                        "Royal Decree",
                        "Play a Gold unit from your deck and boost it by 2.")},
        {"200058", Info(
                        "Uma's Curse",
                        "Create any non-Leader Gold unit.")},
        {"153301", Info(
                        "Lacerate",
                        "Deal 3 damage to all units on a row.")},
        {"200224", Info(
                        "Crow's Eye",
                        "Deal 4 damage to the Highest enemy on each row. Deal 1 extra damage for each copy of this card in your graveyard.")},
        {"201631", Info(
                        "Doppler",
                        "Spawn a random Bronze unit from your faction.")},
        {"201744", Info(
                        "Spores",
                        "Deal 2 damage to all units on a row and clear a Boon from it.")},
        {"113320", Info(
                        "Mardroeme",
                        "Choose One: Reset a unit and Strengthen it by 3; or Reset a unit and Weaken it by 3.")},
        {"201632", Info(
                        "Sihil",
                        "Choose One: Deal 3 damage to all enemies with odd power; or Deal 3 damage to all enemies with even power; or Play a random Bronze or Silver unit from your")},
        {"201637", Info(
                        "Dragon's Dream",
                        "Apply a Hazard to an enemy row that will explode and deal 4 damage to all units when a different special card is played.")},
        {"200236", Info(
                        "Eskel: Pathfinder",
                        "Destroy a Bronze or Silver enemy that is not boosted.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.23.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.21.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.22.mp3",
                            "https://gwent.one/audio/card/ob/en/ESKL_ESKEL_01037262.mp3",
                        })},
        {"200237", Info(
                        "Vesemir: Mentor",
                        "Play a Bronze or Silver Alchemy card from your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VSMR_VESEMIR_01040765.mp3",
                            "https://gwent.one/audio/card/ob/en/VSMR_VESEMIR_01000012.mp3",
                            "https://gwent.one/audio/card/ob/en/VSMR_Q001_00546725.mp3",
                        })},
        {"200235", Info(
                        "Lambert",
                        "Deal 4 damage to all copies of an enemy unit.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/LMBT_Q401_00523875.mp3",
                            "https://gwent.one/audio/card/ob/en/LMBT_SQ106_00586496.mp3",
                            "https://gwent.one/audio/card/ob/en/LMBT_Q401_01058899.mp3",
                            "https://gwent.one/audio/card/ob/en/LMBT_Q403_00572964.mp3",
                            "https://gwent.one/audio/card/ob/en/LMBT_Q401_00531130.mp3",
                            "https://gwent.one/audio/card/ob/en/LMBT_Q403_00550012.mp3",
                        })},
        {"112105", Info(
                        "Regis: Higher Vampire",
                        "Look at 3 Bronze units from your opponent's deck. Consume 1, then boost self by its base power.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/katakan_taunt_short_003.mp3",
                        })},
        {"112109", Info(
                        "Zoltan: Scoundrel",
                        "Choose One: Spawn a Duda: Companion that boosts 2 units on each side of it by 2; or Spawn a Duda: Agitator that deals 2 damage to 2 units on each side of",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/ZOLT_Q310_01062198.mp3",
                            "https://gwent.one/audio/card/ob/en/ZOLT_ZOLTAN_01040651.mp3",
                            "https://gwent.one/audio/card/ob/en/ZOLT_ZOLTAN_01040649.mp3",
                            "https://gwent.one/audio/card/ob/en/ZOLT_Q403_00575678.mp3",
                            "https://gwent.one/audio/card/ob/en/ZOLT_ZOLTAN_01040657.mp3",
                        })},
        {"112403", Info(
                        "Duda: Companion",
                        "Boost 2 units on each side of this unit by 2.")},
        {"112404", Info(
                        "Duda: Agitator",
                        "Deal 2 damage to 2 units on each side of this unit.")},
        {"112113", Info(
                        "Yennefer: Conjurer",
                        "Deal 1 damage to the Highest enemies on turn end.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/YENN_YENNEFER_01041495.mp3",
                            "https://gwent.one/audio/card/ob/en/YENN_YENNEFER_01041488.mp3",
                            "https://gwent.one/audio/card/ob/en/YENN_YENNEFER_01041493.mp3",
                        })},
        {"112106", Info(
                        "Triss Merigold",
                        "Deal 5 damage.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_TRIS_104122_2446.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.17.mp3",
                            "https://gwent.one/audio/card/ob/en/TRSS_Q310_00545347.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.18.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.19.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_TRIS_100285_0008.mp3",
                        })},
        {"201773", Info(
                        "Triss: Telekinesis",
                        "Create a Bronze special card from either player's starting deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_TRIS_104122_2446.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.17.mp3",
                            "https://gwent.one/audio/card/ob/en/TRSS_Q310_00545347.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.18.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.19.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_TRIS_100285_0008.mp3",
                        })},
        {"200087", Info(
                        "Dorregaray of Vole",
                        "Create any Bronze or Silver Beast or Draconid.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_TRIS_104122_2446.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.17.mp3",
                            "https://gwent.one/audio/card/ob/en/TRSS_Q310_00545347.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.18.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.19.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_TRIS_100285_0008.mp3",
                        })},
        {"201774", Info(
                        "Dandelion: Vainglory",
                        "Boost self by 3 for each Geralt, Yennefer, Triss and Zoltan card in your starting deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/DAND_Q302_00490269.mp3",
                            "https://gwent.one/audio/card/ob/en/DAND_DANDELION_00429307.mp3",
                            "https://gwent.one/audio/card/ob/en/DAND_Q302_00489393.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_JSKR_100926_0188.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.5.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.6.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.7.mp3",
                        })},
        {"112214", Info(
                        "Cyprian Wiley",
                        "Weaken a unit by 4.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/WILY_Q302_00514329.mp3",
                            "https://gwent.one/audio/card/ob/en/WILY_Q302_00443324.mp3",
                            "https://gwent.one/audio/card/ob/en/WILY_Q302_00547590.mp3",
                        })},
        {"112201", Info(
                        "Dudu",
                        "Copy the power of an enemy.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.816.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.818.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.817.mp3",
                        })},
        {"201817", Info(
                        "Ihuarraquax",
                        "Deal 5 damage to self. The next time this unit's current power equals its base power, deal 7 damage to 3 random enemies on turn end.")},
        {"200042", Info(
                        "Mahakam Marauder",
                        "Whenever this unit's power changes, except when Reset, boost self by 2.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.41.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.39.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.40.mp3",
                        })},
        {"142105", Info(
                        "Zoltan Chivay",
                        "Choose 3 units. Strengthen allies by 2 and move them to this row. Deal 2 damage to enemies and move them to the row opposite this unit.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/ZOLT_Q310_01062198.mp3",
                            "https://gwent.one/audio/card/ob/en/ZOLT_ZOLTAN_01040651.mp3",
                            "https://gwent.one/audio/card/ob/en/ZOLT_ZOLTAN_01040649.mp3",
                            "https://gwent.one/audio/card/ob/en/ZOLT_Q403_00575678.mp3",
                            "https://gwent.one/audio/card/ob/en/ZOLT_ZOLTAN_01040657.mp3",
                        })},
        {"201780", Info(
                        "Yennefer: Necromancer",
                        "Resurrect a Bronze or Silver Soldier from your opponent's graveyard.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/YENN_YENNEFER_01041495.mp3",
                            "https://gwent.one/audio/card/ob/en/YENN_YENNEFER_01041488.mp3",
                            "https://gwent.one/audio/card/ob/en/YENN_YENNEFER_01041493.mp3",
                        })},
        {"201579", Info(
                        "Phoenix",
                        "                                                                          a Bronze or Silver Draconid.")},
        {"201613", Info(
                        "Saesenthessis: Blaze",
                        "Banish your hand and draw that many cards.")},
        {"112107", Info(
                        "Villentretenmerth",
                        "After 3 turns, destroy all the other Highest units on turn start. 3 Armor.")},
        {"112206", Info(
                        "Ocvist",
                        "Single-Use: After 4 turns, deal 1 damage to all enemies, then return to your hand on turn start.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/wyvern_v2_vo_ADD_008.mp3",
                            "https://gwent.one/audio/card/ob/en/wyvern_v2_vo_ADD_009.mp3",
                            "https://gwent.one/audio/card/ob/en/wyvern_v2_vo_ADD_010.mp3",
                        })},
        {"112205", Info(
                        "Myrgtabrakke",
                        "Deal 2 damage. Repeat 2 times.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/wyvern_v2_vo_ADD_009_OB.mp3",
                            "https://gwent.one/audio/card/ob/en/wyvern_v2_vo_ADD_010_OB.mp3",
                            "https://gwent.one/audio/card/ob/en/wyvern_v2_vo_ADD_008_OB.mp3",
                        })},
        {"112213", Info(
                        "King of Beggars",
                        "If losing, Strengthen self up to a maximum of 15 until scores are tied.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/KGBG_Q302_00487960.mp3",
                            "https://gwent.one/audio/card/ob/en/KGBG_Q301_00486502.mp3",
                            "https://gwent.one/audio/card/ob/en/KGBG_Q301_00499725.mp3",
                            "https://gwent.one/audio/card/ob/en/KGBG_Q301_00487409.mp3",
                        })},
        {"112207", Info(
                        "Olgierd von Everec",
                        "Deathwish: Resurrect this unit on a random row.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/OLGD_Q603_01101145.mp3",
                            "https://gwent.one/audio/card/ob/en/OLGD_Q604_01137773.mp3",
                            "https://gwent.one/audio/card/ob/en/OLGD_Q603_01101591.mp3",
                        })},
        {"112215", Info(
                        "Iris von Everec",
                        "Spying. Deathwish: Boost 5 random units on the opposite side by 5.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/IRIS_Q604_01106159.mp3",
                            "https://gwent.one/audio/card/ob/en/IRIS_Q604_01106875.mp3",
                            "https://gwent.one/audio/card/ob/en/IRIS_Q604_01106944.mp3",
                        })},
        {"200083", Info(
                        "Iris' Companions",
                        "Move a card from your deck to your hand, then Discard a random card.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.268.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.265.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.264.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.267.mp3",
                        })},
        {"112211", Info(
                        "Johnny",
                        "Discard a card. Then make a default copy of a card of the same color from your opponent's starting deck in your hand.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/GJHN_Q105_00420525.mp3",
                            "https://gwent.one/audio/card/ob/en/GJHN_Q111_01011367.mp3",
                            "https://gwent.one/audio/card/ob/en/GJHN_Q105_00417768.mp3",
                            "https://gwent.one/audio/card/ob/en/GJHN_GODLING_01059659.mp3",
                            "https://gwent.one/audio/card/ob/en/GJHN_Q105_00373361.mp3",
                        })},
        {"200091", Info(
                        "Stregobor",
                        "Truce: Each player draws a unit and sets its power to 1.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.165.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.162.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.163.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.164.mp3",
                        })},
        {"112212", Info(
                        "Sarah",
                        "Swap a card for one of the same color.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/GSAR_Q301_00493632.mp3",
                            "https://gwent.one/audio/card/ob/en/GSAR_Q301_00484178.mp3",
                            "https://gwent.one/audio/card/ob/en/GSAR_GODLING_01059640.mp3",
                        })},
        {"201753", Info(
                        "Peasant Militia",
                        "Spawn 3 Peasants on a row.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.86.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.87.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.84.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.85.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.83.mp3",
                        })},
        {"201753", Info(
                        "Peasant Militia",
                        "No ability.")},
        {"112209", Info(
                        "Prize-Winning Cow",
                        "Deathwish: Spawn a Chort on a random row.")},
        {"112209", Info(
                        "Chort",
                        "No ability.")},
        {"201595", Info(
                        "Princess Adda",
                        "Create a Bronze or Silver Cursed unit.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.194.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.195.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.193.mp3",
                        })},
        {"200168", Info(
                        "King Foltest",
                        "Boost all other allies and your non-Spying units in hand and deck by 1.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_FLTS_000811_0002.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_FLTS_000811_0004.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_FLTS_000811_0012.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_FLTS_000811_0001.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_FLTS_000006_0068.mp3",
                        })},
        {"200169", Info(
                        "King Radovid V",
                        "Toggle 2 units' Lock statuses. If enemies, deal 4 damage to them. Crew.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/RADV_SQ302_00302977.mp3",
                            "https://gwent.one/audio/card/ob/en/RADV_Q302_00512777.mp3",
                            "https://gwent.one/audio/card/ob/en/RADV_RADOVID_01040720.mp3",
                            "https://gwent.one/audio/card/ob/en/RADV_MQ3035_01064783.mp3",
                            "https://gwent.one/audio/card/ob/en/RADV_MQ3035_01064777.mp3",
                            "https://gwent.one/audio/card/ob/en/RADV_MQ3035_01064716.mp3",
                        })},
        {"200162", Info(
                        "Emhyr var Emreis",
                        "Play a card, then return a Bronze or Silver ally to your hand.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.236.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.238.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.237.mp3",
                        })},
        {"201580", Info(
                        "Usurper",
                        "Spying. Create any Leader and boost it by 2.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.433.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.432.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.434.mp3",
                        })},
        {"200167", Info(
                        "Brouver Hoog",
                        "Play a non-Spying Silver unit or a Bronze Dwarf from your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.136.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.137.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.138.mp3",
                        })},
        {"200166", Info(
                        "Eithne",
                        "Resurrect a Bronze or Silver special card.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.133.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.135.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.134.mp3",
                        })},
        {"201589", Info(
                        "Filavandrel",
                        "Create a Silver special card.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.279.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.278.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.280.mp3",
                        })},
        {"200165", Info(
                        "Francesca Findabair",
                        "Swap a card with one of your choice and boost it by 3.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.130.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.131.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.132.mp3",
                        })},
        {"142106", Info(
                        "Aglais",
                        "Resurrect a Bronze or Silver special card from your opponent's graveyard, then Banish it.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.154.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.153.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.152.mp3",
                        })},
        {"142103", Info(
                        "Iorveth",
                        "Deal 8 damage to an enemy. If the unit was destroyed, boost all Elves in your hand by 1.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_IORW_101064_0046.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_IORW_101048_0181.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_IORW_102216_0006.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_IORW_100241_4474.mp3",
                        })},
        {"201611", Info(
                        "Iorveth: Meditation",
                        "Force 2 enemies on the same row to Duel each other.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_IORW_101064_0046.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_IORW_101048_0181.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_IORW_102216_0006.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_IORW_100241_4474.mp3",
                        })},
        {"142102", Info(
                        "Isengrim Faoiltiarna",
                        "Play a Bronze or Silver Ambush from your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.141.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.140.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.139.mp3",
                        })},
        {"201615", Info(
                        "Isengrim: Outlaw",
                        "Choose One: Play a Bronze or Silver special card from your deck; or Create a Silver Elf.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.141.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.140.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.139.mp3",
                        })},
        {"142107", Info(
                        "Ithlinne Aegli",
                        "Play a Bronze Spell, Boon or Hazard from your deck twice.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.170.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.172.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.171.mp3",
                        })},
        {"142108", Info(
                        "Schirru",
                        "Spawn Scorch or Epidemic.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.187.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.186.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.188.mp3",
                        })},
        {"142108", Info(
                        "Saesenthessis",
                        "Boost self by 1 for each Dwarf ally and deal 1 damage to an enemy for each Elf ally.")},
        {"200209", Info(
                        "Saskia",
                        "Swap up to 2 cards for Bronze cards.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_TARM_200423_0023.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_TARM_200154_0192.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_TARM_200423_0011.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_TARM_200991_0019.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_TARM_200423_0024.mp3",
                        })},
        {"142207", Info(
                        "Barclay Els",
                        "Play a random Bronze or Silver Dwarf from your deck and Strengthen it by 3.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.162.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.163.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.161.mp3",
                        })},
        {"142211", Info(
                        "Dennis Cranmer",
                        "Strengthen all your other Dwarves in hand, deck, and on board by 1.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.157.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.156.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.155.mp3",
                        })},
        {"142212", Info(
                        "Sheldon Skaggs",
                        "Move all allies on this row to random rows and boost self by 1 for each.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.33.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.34.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.35.mp3",
                        })},
        {"142213", Info(
                        "Yarpen Zigrin",
                        "Resilience. Whenever a Dwarf ally appears, boost self by 1.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.786.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.784.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.785.mp3",
                        })},
        {"142203", Info(
                        "Yaevinn",
                        "Spying. Single-Use: Draw a special card and a unit. Keep one and return the other to your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.786.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.784.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.785.mp3",
                        })},
        {"142202", Info(
                        "Ida Emean aep Sivney",
                        "Spawn Impenetrable Fog, Clear Skies or Alzur's Thunder.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/IDEM_Q401_00532088.mp3",
                            "https://gwent.one/audio/card/ob/en/IDEM_Q401_00517579.mp3",
                        })},
        {"201676", Info(
                        "Pavko Gale",
                        "Play a Bronze or Silver Item from your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.32.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.31.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.34.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.35.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.33.mp3",
                        })},
        {"142206", Info(
                        "Ciaran aep Easnillen",
                        "Toggle a unit's Lock status and move it to this row on its side.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.159.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.160.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.158.mp3",
                        })},
        {"200520", Info(
                        "Eibhear Hattori",
                        "Resurrect a lower or equal Bronze or Silver Scoia'tael unit.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/HTRI_HATTORI_00507925.mp3",
                            "https://gwent.one/audio/card/ob/en/HTRI_SQ304_00539954.mp3",
                            "https://gwent.one/audio/card/ob/en/HTRI_HATTORI_01032235.mp3",
                        })},
        {"200030", Info(
                        "Milaen",
                        "Deal 6 damage to the units at the end of a row.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.220.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.222.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.221.mp3",
                        })},
        {"142209", Info(
                        "Braenn",
                        "Deal damage equal to this unit's power. If a unit was destroyed, boost all your other Dryads and Ambush units in hand, deck, and on board by 1.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.168.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.169.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.167.mp3",
                        })},
        {"142208", Info(
                        "Morenn",
                        "Ambush: When a unit is played on your opponent's side, flip over and deal 7 damage to it.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.165.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.164.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.166.mp3",
                        })},
        {"201696", Info(
                        "Paulie Dahlberg",
                        "Resurrect a non-Support Bronze Dwarf.")},
        {"201653", Info(
                        "Mahakam Horn",
                        "Choose One: Create a Bronze or Silver Dwarf; or Strengthen a unit by 7.")},
        {"143201", Info(
                        "Nature's Gift",
                        "Play a Bronze or Silver special card from your deck.")},
        {"200228", Info(
                        "Pit Trap",
                        "Apply a Hazard to an enemy row that deals 3 damage to units on contact.")},
        {"201645", Info(
                        "Crushing Trap",
                        "Deal 6 damage to the units at the end of an enemy row.")},
        {"201643", Info(
                        "Elven Blade",
                        "Deal 10 damage to a non-Elf unit.")},
        {"143301", Info(
                        "Incinerating Trap",
                        "Spying. Damage all other units on its row by 2 and Banish self on turn end.")},
        {"142316", Info(
                        "Blue Mountain Elite",
                        "Summon all copies of this unit to this row. Whenever this unit moves, boost it by 2.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_SWV5_202972_0006.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_SWV5_202972_0004.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_SWV5_202972_0007.mp3",
                        })},
        {"142316", Info(
                        "Dol Blathanna Bomber",
                        "Spawn an Incinerating Trap on an enemy row.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_SWF1_107697_0003.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_SWF1_100532_0009.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_SWF1_109383_0001.mp3",
                        })},
        {"142314", Info(
                        "Dol Blathanna Bowman",
                        "Deal 2 damage to an enemy. Whenever an enemy moves, deal 2 damage to it. Whenever this unit moves, deal 2 damage to a random enemy.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_SWV1_202968_0006.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_SWV1_202968_0007.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_SWV1_202968_0012.mp3",
                        })},
        {"200039", Info(
                        "Dol Blathanna Bowman",
                        "If in hand, deck or on board, boost self by 1 whenever you play a special card.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.310.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.312.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.311.mp3",
                        })},
        {"201638", Info(
                        "Elven Scout",
                        "Swap a card.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.92.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.91.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.89.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.90.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.88.mp3",
                        })},
        {"200535", Info(
                        "Elven Swordmaster",
                        "Deal damage equal to this unit's power to an enemy.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.398.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.400.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.399.mp3",
                        })},
        {"200293", Info(
                        "Dwarven Agitator",
                        "Spawn a default copy of a random different Bronze Dwarf from your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.96.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.94.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.97.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.95.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.93.mp3",
                        })},
        {"142311", Info(
                        "Dwarven Mercenary",
                        "Move a unit to this row on its side. If it's an ally, boost it by 3.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SCD1_VSET_00526104.mp3",
                            "https://gwent.one/audio/card/ob/en/SCD1_VSET_00526102.mp3",
                            "https://gwent.one/audio/card/ob/en/SCD1_VSET_00525272.mp3",
                        })},
        {"142305", Info(
                        "Dwarven Skirmisher",
                        "Deal 3 damage to an enemy. If the unit was not destroyed, boost self by 3.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SCD1_VSET_00525271.mp3",
                            "https://gwent.one/audio/card/ob/en/SCD1_VSET_00525421.mp3",
                            "https://gwent.one/audio/card/ob/en/SCD1_VSET_00525423.mp3",
                        })},
        {"142301", Info(
                        "Hawker Healer",
                        "Boost 2 allies by 3.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VSCF2_VSET_00523670.mp3",
                            "https://gwent.one/audio/card/ob/en/VSCF2_VSET_00523680.mp3",
                            "https://gwent.one/audio/card/ob/en/VSCF2_VSET_00523672.mp3",
                        })},
        {"142312", Info(
                        "Hawker Support",
                        "Boost a unit in your hand by 3.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VBAN1_MQ1005_00358151.mp3",
                            "https://gwent.one/audio/card/ob/en/VBAN1_MQ1005_00357973.mp3",
                            "https://gwent.one/audio/card/ob/en/VBAN1_VSET_00592242.mp3",
                        })},
        {"142306", Info(
                        "Mahakam Defender",
                        "Resilience.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SCD1_VSET_00525429.mp3",
                            "https://gwent.one/audio/card/ob/en/SCD1_VSET_00525431.mp3",
                            "https://gwent.one/audio/card/ob/en/SCD1_VSET_00525279.mp3",
                        })},
        {"142317", Info(
                        "Mahakam Guard",
                        "Boost an ally by 7.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SCD34_VSET_01013381.mp3",
                            "https://gwent.one/audio/card/ob/en/SCD34_VSET_01013385.mp3",
                            "https://gwent.one/audio/card/ob/en/SCD34_VSET_01013371.mp3",
                        })},
        {"201559", Info(
                        "Mahakam Volunteers",
                        "Summon all copies of this unit.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.101.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.99.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.102.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.100.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.98.mp3",
                        })},
        {"200135", Info(
                        "Pyrotechnician",
                        "Deal 3 damage to a random enemy on each row.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.318.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.320.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.319.mp3",
                        })},
        {"142313", Info(
                        "Wardancer",
                        "Whenever you Swap this unit, play it automatically on a random row.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part2.4.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part2.3.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part2.2.mp3",
                        })},
        {"142309", Info(
                        "Vrihedd Vanguard",
                        "Boost Elf allies by 1. Whenever you Swap this card, trigger its ability.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_SF01_107685_0001.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_SF01_102746_0042.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_SF01_102746_0054.mp3",
                        })},
        {"142303", Info(
                        "Vrihedd Officer",
                        "Swap a card and boost self by its base power.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_SF02_108969_0001.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_SF02_101662_0066.mp3",
                        })},
        {"142301", Info(
                        "Vrihedd Neophyte",
                        "Boost 2 random units in your hand by 1.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.788.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.789.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.790.mp3",
                        })},
        {"142302", Info(
                        "Vrihedd Brigade",
                        "Clear Hazards from its row and move a unit to this row on its side.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_SF01_102780_0001.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_SF01_102746_0035.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_SF01_102746_0038.mp3",
                        })},
        {"142315", Info(
                        "Hawker Smuggler",
                        "Whenever an enemy appears, boost self by 1.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part2.5.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part2.6.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part2.7.mp3",
                        })},
        {"162102", Info(
                        "Menno Coehoorn",
                        "Deal 4 damage to an enemy. If it's Spying, destroy it instead.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.59.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.58.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.60.mp3",
                        })},
        {"200032", Info(
                        "Rainfarn of Attre",
                        "Play a Bronze or Silver Spying unit from your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.91.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.93.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.92.mp3",
                        })},
        {"163101", Info(
                        "Assassination",
                        "Deal 8 damage to an enemy. Repeat once.")},
        {"162106", Info(
                        "Stefan Skellen",
                        "Move any card in your deck to the top. If it's a non-Spying unit, boost it by 5.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.98.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.99.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.97.mp3",
                        })},
        {"200071", Info(
                        "Shilard",
                        "Truce: Draw a card from both decks. Keep one and give the other to your opponent.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.96.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.94.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.95.mp3",
                        })},
        {"162108", Info(
                        "Xarthisius",
                        "Look at your opponent's deck and move a card to the bottom.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.118.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.119.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.120.mp3",
                        })},
        {"162108", Info(
                        "Cantarella",
                        "Spying. Single-Use: Draw 2 cards. Keep one and move the other to the bottom of your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.127.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.128.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.129.mp3",
                        })},
        {"200139", Info(
                        "Panther",
                        "Deal 7 damage to an enemy on a row with less than 4 units.")},
        {"162304", Info(
                        "Vicovaro Medic",
                        "Resurrect a Bronze unit from your opponent's graveyard.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.431.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.430.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.429.mp3",
                        })},
        {"162202", Info(
                        "Assire var Anahid",
                        "Return 2 Bronze or Silver cards from either graveyard to their respective decks.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.76.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.77.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.75.mp3",
                        })},
        {"162205", Info(
                        "Fringilla Vigo",
                        "Spying. Copy the power from the unit to the left to the unit to the right.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.90.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.88.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.89.mp3",
                        })},
        {"162212", Info(
                        "False Ciri",
                        "Spying. If Spying, boost self by 1 on turn start and when this player passes, move to the opposite row. Deathwish: Destroy the Lowest unit on the row.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.105.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.107.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.106.mp3",
                        })}};
    return infos;
}


namespace CardsObt {

std::vector<Card *> createAll()
{
    return {
        createAddaStriga(),
        createDao(),
        createPoorFingInfantry(),
        createDeithwenArbalest(),
        createTemerianDrummer(),
        createDandelionPoet(),
        createSileDeTansarville(),
        createRedanianKnightElect(),
        createKaedweniKnight(),
        createAnCraiteMarauder(),
        createAnCraiteGreatsword(),
        createDimunLightLongship(),
        createTuirseachBearmaster(),
        createTuirseachHunter(),
        createRedanianElite(),
        createRedanianKnight(),
        createKaedweniCavalry(),
        createAlzursThunder(),
        createSwallow(),
        createThunderbolt(),
        createArachasVenom(),
        createKeiraMetz(),
        createDolBlathannaArcher(),
        createHalfElfHunter(),
        createAmbassador(),
        createAssassin(),
        createEmissary(),
        createCeallachDyffryn(),
        createTuirseachArcher(),
        createInfiltrator(),
        createImpenetrableFog(),
        createTorrentialRain(),
        createBitingFrost(),
        createGoldenFroth(),
        createSkelligeStorm(),
        createImperialManticore(),
        createManticoreVenom(),
        createGloriousHunt(),
        createVes(),
        createVaedermakar(),
        createFrightener(),
        createCleaver(),
        createScorch(),
        createReinforcements(),
        createJohnNatalis(),
        createEleyas(),
        createReaverScout(),
        createHeymaeySpearmaiden(),
        createVriheddSappers(),
        createPriestessOfFreya(),
        createDimunCorsair(),
        createSigrdrifa(),
        createDrummondQueensguard(),
        createSage(),
        createReconnaissance(),
        createElvenMercenary(),
        createChampionOfHov(),
        createPriscilla(),
        createSeltkirkOfGulet(),
        createAdrenalineRush(),
        createMandrake(),
        createBoneTalisman(),
        createRestore(),
        createDecoy(),
        createShupesDayOff(),
        createFirstLight(),
        createEpidemic(),
        createMoonlight(),
        createCiriNova(),
        createHaraldTheCripple(),
        createBranTuirseach(),
        createDrummondWarmonger(),
        createDimunPirate(),
        createAnCraiteRaider(),
        createMadmanLugos(),
        createErmion(),
        createCerysFearless(),
        createCerysAnCraite(),
        createWoodlandSpirit(),
        createTrollololo(),
        createPrinceStennis(),
        createVincentMeis(),
        createMorkvarg(),
        createArtefactCompression(),
        createHjalmarAnCraite(),
        createRegis(),
        createLethoOfGulet(),
        createAnCraiteLongship(),
        createGeraltIgni(),
        createGeraltOfRivia(),
        createTuirseachVeteran(),
        createUdalryk(),
        createBloodcurdlingRoar(),
        createGremist(),
        createZoriaRunestone(),
        createOperator(),
        createRenew(),
        createEistTuirseach(),
        createTuirseachAxeman(),
        createDerran(),
        createTuirseachSkirmisher(),
        createRoach(),
        createJanCalveit(),
        createCahirDyffryn(),
        createLethoKingslayer(),
        createKingHenselt(),
        createBloodyBaron(),
        createHubertRejk(),
        createDethmold(),
        createRonvidTheIncessant(),
        createCrachAnCraite(),
        createBirnaBran(),
        createCoral(),
        createVabjorn(),
        createBlueboyLugos(),
        createDjengeFrett(),
        createDonarAnHindar(),
        createDraigBonDhu(),
        createHolgerBlackhand(),
        createJuttaAnDimun(),
        createSavageBear(),
        createSvanrigeTuirseach(),
        createSkjall(),
        createHaraldHoundsnout(),
        createYoana(),
        createAnCraiteBlacksmith(),
        createAnCraiteWarcrier(),
        createAnCraiteWarrior(),
        createBerserkerMarauder(),
        createDimunPirateCaptain(),
        createDimunSmuggler(),
        createDrummondShieldmaid(),
        createHeymaeyFlaminica(),
        createHeymaeyHerbalist(),
        createHeymaeyProtector(),
        createHeymaeySkald(),
        createRagingBerserker(),
        createHym(),
        createKambi(),
        createOlaf(),
        createUlfhedinn(),
        createWildBoarOfTheSea(),
        createGiantBoar(),
        createOrnamentalSword(),
        createDimunWarship(),
        createVilgefortz(),
        createTrissButterflies(),
        createYennefer(),
        createGermainPiquant(),
        createCommandersHorn(),
        createMarchingOrders(),
        createAlzursDoubleCross(),
        createAlbaArmoredCavalry(),
        createSentry(),
        createNauzicaaSergeant(),
        createSlaveInfantry(),
        createRecruit(),
        createOintment(),
        createVreemde(),
        createLambert(),
        createEskel(),
        createVesemir(),
        createTridamInfantry(),
        createVriheddDragoon(),
        createMalena(),
        createUnseenElder(),
        createDevanaRunestone(),
        createDazhbogRunestone(),
        createMoranaRunestone(),
        createStribogRunestone(),
        createMuzzle(),
        createWhisperingHillock(),
        createBrewess(),
        createWeavess(),
        createWhispess(),
        createWeavessIncantation(),
        createBrewessRitual(),
        createWhispessTribute(),
        createNivellen(),
        createLeoBonhart(),
        createMorvranVoorhis(),
        createCynthia(),
        createSerrit(),
        createSweers(),
        createTiborEggebracht(),
        createVattierDeRideaux(),
        createAlbrich(),
        createHeftyHelge(),
        createAlchemist(),
        createDaerlanSoldier(),
        createFireScorpion(),
        createMangonel(),
        createNilfgaardianKnight(),
        createSpotter(),
        createVenendalElite(),
        createMasterOfDisguise(),
        createHenryVarAttre(),
        createWildHuntHound(),
        createWildHuntWarrior(),
        createWildHuntNavigator(),
        createNithral(),
        createMiruna(),
        createImlerith(),
        createCaretaker(),
        createRuehin(),
        createOldSpeartipAsleep(),
        createOldSpeartip(),
        createGolyat(),
        createBarbegazi(),
        createGhoul(),
        createForktail(),
        createArachasQueen(),
        createOzzrel(),
        createKayran(),
        createMourntart(),
        createToadPrince(),
        createFiend(),
        createMorvudd(),
        createEkimmara(),
        createRotfiend(),
        createArchespore(),
        createCyclops(),
        createMaerolorn(),
        createMonsterNest(),
        createArachasDrone(),
        createEredinBreaccGlas(),
        createCaranthirArFeiniel(),
        createImlerithSabbath(),
        createDagon(),
        createIfrit(),
        createSheTrollOfVergen(),
        createWyvern(),
        createAbaya(),
        createParasite(),
        createJotunn(),
        createIceGiant(),
        createIceTroll(),
        createDrowner(),
        createFoglet(),
        createAncientFoglet(),
        createDraug(),
        createCelaenoHarpy(),
        createArachasBehemoth(),
        createArchgriffin(),
        createGriffin(),
        createBridgeTroll(),
        createCockatrice(),
        createSiren(),
        createLamia(),
        createNekker(),
        createNekkerWarrior(),
        createSlyzard(),
        createWerecat(),
        createHarpy(),
        createWildHuntDrakkar(),
        createGeels(),
        createWildHuntRider(),
        createVranWarrior(),
        createAnCraiteArmorsmith(),
        createAvalach(),
        createAvalachSage(),
        createNekurat(),
        createRaghNarRoog(),
        createGeraltProfessional(),
        createGeraltAard(),
        createGeraltYrden(),
        createCiriDash(),
        createAguara(),
        createAguaraTrueForm(),
        createKorathiHeatwave(),
        createAleOfTheAncestors(),
        createMahakamAle(),
        createOdrin(),
        createToruviel(),
        createCiri(),
        createMilva(),
        createPrincessPavetta(),
        createTheGuardian(),
        createGaunterODimm(),
        createKaedweniSergeant(),
        createReinforcedBallista(),
        createSigismundDijkstra(),
        createWhiteFrost(),
        createWolfsbane(),
        createDunBanner(),
        createAelirenn(),
        createHanmarvynsDream(),
        createBlackBlood(),
        createBekkersRockslide(),
        createBekkersDarkMirror(),
        createMerigoldsHailstorm(),
        createNecromancy(),
        createStammelfordsTremor(),
        createExpiredAle(),
        createTrialOfTheGrasses(),
        createDimeritiumBomb(),
        createGarrison(),
        createTheLastWish(),
        createDimeritiumShackles(),
        createWyvernScaleShield(),
        createMastercraftedSpear(),
        createPetrisPhilter(),
        createShrike(),
        createRoyalDecree(),
        createUmasCurse(),
        createLacerate(),
        createCrowsEye(),
        createDoppler(),
        createSpores(),
        createMardroeme(),
        createSihil(),
        createEskelPathfinder(),
        createVesemirMentor(),
        createLambertSwordmaster(),
        createRegisHigherVampire(),
        createZoltanScoundrel(),
        createYenneferConjurer(),
        createTrissMerigold(),
        createTrissTelekinesis(),
        createDorregarayOfVole(),
        createDandelionVainglory(),
        createCyprianWiley(),
        createDudu(),
        createIhuarraquax(),
        createMahakamMarauder(),
        createZoltanChivay(),
        createYenneferNecromancer(),
        createPhoenix(),
        createSaesenthessisBlaze(),
        createVillentretenmerth(),
        createOcvist(),
        createMyrgtabrakke(),
        createKingOfBeggars(),
        createOlgierdVonEverec(),
        createIrisVonEverec(),
        createIrisCompanions(),
        createJohnny(),
        createStregobor(),
        createSarah(),
        createPeasantMilitia(),
        createPrizeWinningCow(),
        createPrincessAdda(),
        createKingFoltest(),
        createKingRadovidV(),
        createEmhyrVarEmreis(),
        createUsurper(),
        createBrouverHoog(),
        createEithne(),
        createFilavandrel(),
        createFrancescaFindabair(),
        createAglais(),
        createIorveth(),
        createIorvethMeditation(),
        createIsengrimFaoiltiarna(),
        createIsengrimOutlaw(),
        createSchirru(),
        createSaesenthessis(),
        createSaskia(),
        createBarclayEls(),
        createDennisCranmer(),
        createSheldonSkaggs(),
        createYarpenZigrin(),
        createYaevinn(),
        createIdaEmeanAepSivney(),
        createPavkoGale(),
        createCiaranAepEasnillen(),
        createEibhearHattori(),
        createMilaen(),
        createBraenn(),
        createMorenn(),
        createPaulieDahlberg(),
        createMahakamHorn(),
        createNaturesGift(),
        createPitTrap(),
        createCrushingTrap(),
        createElvenBlade(),
        createIncineratingTrap(),
        createBlueMountainElite(),
        createDolBlathannaBomber(),
        createDolBlathannaBowman(),
        createDolBlathannaSentry(),
        createElvenScout(),
        createElvenSwordmaster(),
        createDwarvenAgitator(),
        createDwarvenMercenary(),
        createDwarvenSkirmisher(),
        createHawkerHealer(),
        createHawkerSupport(),
        createMahakamDefender(),
        createMahakamGuard(),
        createMahakamVolunteers(),
        createPyrotechnician(),
        createWardancer(),
        createVriheddVanguard(),
        createVriheddOfficer(),
        createVriheddNeophyte(),
        createVriheddBrigade(),
        createHawkerSmuggler(),
        createMennoCoehoorn(),
        createRainfarnOfAttre(),
        createAssassination(),
        createStefanSkellen(),
        createShilard(),
        createCantarella(),
        createPanther(),
        createVicovaroMedic(),
        createAssireVarAnahid(),
        createFringillaVigo(),
        createFalseCiri(),
    };
}

Card *createAddaStriga()
{
    auto *card = new Card();
    card->id = "200073";
    card->power = card->powerBase = 6;
    card->rarity = Silver;
    card->faction = Monster;
    card->tags = { Relict, Cursed };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isNonMonsterFaction});
    };

    card->_onTargetChoosen = [=](Card *card, Field &ally, Field &enemy) {
        damage(card, 8, ally, enemy, card);
    };

    return card;
}

Card *createDao()
{
    auto *card = new Card();
    card->id = "132213";
    card->power = card->powerBase = 6;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Construct };

    const auto createDaoLesser = []{
        auto *card = new Card();
        card->id = "132405";
        card->power = card->powerBase = 4;
        card->rarity = Bronze;
        card->faction = Monster;
        card->tags = { Construct };
        card->isDoomed = true;
        return card;
    };

    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &rowAndPos) {
        spawnNewUnitToPos(createDaoLesser(), rowAndPos, ally, enemy, card);
        spawnNewUnitToPos(createDaoLesser(), rowAndPos, ally, enemy, card);
    };

    return card;
}

Card *createPoorFingInfantry()
{
    auto *card = new Card();
    card->id = "200234";
    card->power = card->powerBase = 6;
    card->rarity = Bronze;
    card->faction = NothernRealms;
    card->tags = { Temeria, Soldier };


    const auto createLeftFlankInfantry = []{
        auto *card = new Card();
        card->id = "200302";
        card->power = card->powerBase = 2;
        card->rarity = Bronze;
        card->faction = NothernRealms;
        card->tags = { Temeria, Soldier };
        card->isDoomed = true;
        return card;
    };


    const auto createRightFlankInfantry = []{
        auto *card = new Card();
        card->id = "200303";
        card->power = card->powerBase = 2;
        card->rarity = Bronze;
        card->faction = NothernRealms;
        card->tags = { Temeria, Soldier };
        card->isDoomed = true;
        return card;
    };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        spawnNewUnitToPos(createLeftFlankInfantry(), rowAndPosToTheLeft(card, ally, 1), ally, enemy, card);
        spawnNewUnitToPos(createRightFlankInfantry(), rowAndPosToTheRight(card, ally, 1), ally, enemy, card);
    };
    return card;
}

Card *createDeithwenArbalest()
{
    auto *card = new Card();
    card->id = "162305";
    card->power = card->powerBase = 7;
    card->rarity = Bronze;
    card->faction = Nilfgaard;
    card->tags = { Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        damage(target, target->isSpy ? 6 : 3, ally, enemy, card);
    };
    return card;
}


Card *createTemerianDrummer()
{
    auto *card = new Card();
    card->id = "200299";
    card->power = card->powerBase = 5;
    card->rarity = Bronze;
    card->faction = NothernRealms;
    card->tags = { Temeria, Support };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AllyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        boost(target, 6, ally, enemy, card);
    };
    return card;
}


Card *createDandelionPoet()
{
    auto *card = new Card();
    card->id = "201776";
    card->power = card->powerBase = 5;
    card->rarity = Gold;
    card->faction = Neutral;
    card->tags = { Support };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (drawACard(ally, enemy,  card))
            startChoiceToTargetCard(ally, enemy, card, {}, AllyHand);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}


Card *createSileDeTansarville()
{
    auto *card = new Card();
    card->id = "122205";
    card->power = card->powerBase = 4;
    card->rarity = Silver;
    card->faction = NothernRealms;
    card->tags = { Mage };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, ::isSpecial}, AllyHand);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
        drawACard(ally, enemy,  card);
    };
    return card;
}


Card *createRedanianKnightElect()
{
    auto *card = new Card();
    card->id = "123301";
    card->power = card->powerBase = 7;
    card->rarity = Bronze;
    card->faction = NothernRealms;
    card->tags = { Redania, Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        gainArmor(card, 2, ally, enemy, card);
    };

    card->_onTurnEnd = [=](Field &ally, Field &enemy) {
        if (card->armor == 0)
            return;

        Card *left = cardNextTo(card, ally, enemy, -1);
        Card *right = cardNextTo(card, ally, enemy, 1);

        if (left != nullptr)
            boost(left, 1, ally, enemy, card);
        if (right != nullptr)
            boost(right, 1, ally, enemy, card);
    };
    return card;
}


Card *createAnCraiteMarauder()
{
    auto *card = new Card();
    card->id = "201578";
    card->power = card->powerBase = 7;
    card->rarity = Bronze;
    card->faction = Skellige;
    card->tags = { ClanAnCraite, Soldier };
    return card;
}


Card *createAnCraiteGreatsword()
{
    auto *card = new Card();
    card->id = "200040";
    card->power = card->powerBase = 8;
    card->rarity = Bronze;
    card->faction = Skellige;
    card->tags = { ClanAnCraite, Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        setTimer(card, ally, enemy, 2);
    };

    card->_onTurnStart = [=](Field &ally, Field &enemy) {
        if (!isOnBoard(card, ally) || !tick(card, ally, enemy, 2))
            return;

        if (card->power >= card->powerBase)
            return;

        heal(card, ally, enemy, card);
        strengthen(card, 2, ally, enemy, card);
    };
    return card;
}


Card *createDimunLightLongship()
{
    auto *card = new Card();
    card->id = "152309";
    card->power = card->powerBase = 7;
    card->rarity = Bronze;
    card->faction = Skellige;
    card->tags = { ClanDimun, Machine };

    card->_onTurnEnd = [=](Field &ally, Field &enemy) {
        if (Card *right = cardNextTo(card, ally, enemy, 1)) {
            damage(right, 1, ally, enemy, card);
            boost(card, 2, ally, enemy, card);
        }
    };
    return card;
}


Card *createBear()
{
    auto *card = new Card();
    card->id = "152406";
    card->power = card->powerBase = 11;
    card->rarity = Bronze;
    card->faction = Neutral;
    card->tags = { Beast, Cursed };
    return card;
}


Card *createWolf()
{
    auto *card = new Card();
    card->id = "132403";
    card->power = card->powerBase = 1;
    card->isDoomed = true;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Beast };
    return card;
}


Card *createTuirseachBearmaster()
{
    auto *card = new Card();
    card->id = "200144";
    card->power = card->powerBase = 1;
    card->rarity = Bronze;
    card->faction = Skellige;
    card->tags = { ClanTuirseach, Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        spawnNewCard(createBear(), ally, enemy, card);
    };
    return card;
}


Card *createRedanianElite()
{
    auto *card = new Card();
    card->id = "122317";
    card->power = card->powerBase = 8;
    card->rarity = Bronze;
    card->faction = NothernRealms;
    card->tags = { Redania, Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        gainArmor(card, 4, ally, enemy, card);
    };

    card->_onArmorLost = [=](Field &ally, Field &enemy) {
        boost(card, 5, ally, enemy, card);
    };
    return card;
}


Card *createRedanianKnight()
{
    auto *card = new Card();
    card->id = "122308";
    card->power = card->powerBase = 7;
    card->rarity = Bronze;
    card->faction = NothernRealms;
    card->tags = { Redania, Soldier };

    card->_onTurnEnd = [=](Field &ally, Field &enemy) {
        if (card->armor != 0)
            return;
        boost(card, 2, ally, enemy, card);
        gainArmor(card, 2, ally, enemy, card);
    };
    return card;
}


Card *createKaedweniCavalry()
{
    auto *card = new Card();
    card->id = "122314";
    card->power = card->powerBase = 8;
    card->rarity = Bronze;
    card->faction = NothernRealms;
    card->tags = { Kaedwen, Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {hasArmor});
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        const int armorTarget = target->armor;
        damage(target, armorTarget, ally, enemy, card);
        boost(card, armorTarget, ally, enemy, card);
    };
    return card;
}


Card *createAlzursThunder()
{
    auto *card = new Card();
    card->id = "113301";
    card->rarity = Bronze;
    card->faction = Neutral;
    card->tags = { Spell };
    card->isSpecial = true;

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        saveFieldsSnapshot(ally, enemy, DealDamage, card, {target}, "", 9);
        damage(target, 9, ally, enemy, card);
    };
    return card;
}


Card *createSwallow()
{
    auto *card = new Card();
    card->id = "113310";
    card->rarity = Bronze;
    card->faction = Neutral;
    card->tags = { Alchemy, Item };
    card->isSpecial = true;

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        boost(target, 10, ally, enemy, card);
    };
    return card;
}


Card *createThunderbolt()
{
    auto *card = new Card();
    card->id = "113311";
    card->rarity = Bronze;
    card->faction = Neutral;
    card->tags = { Alchemy, Item };
    card->isSpecial = true;

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        boost(target, 3, ally, enemy, card);
        gainArmor(target, 2, ally, enemy, card);

        Card *left = cardNextTo(target, ally, enemy, -1);
        Card *right = cardNextTo(target, ally, enemy, 1);

        if (left != nullptr) {
            boost(left, 3, ally, enemy, card);
            gainArmor(left, 2, ally, enemy, card);
        }
        if (right != nullptr) {
            boost(right, 3, ally, enemy, card);
            gainArmor(right, 2, ally, enemy, card);
        }
    };
    return card;
}


Card *createArachasVenom()
{
    auto *card = new Card();
    card->id = "200023";
    card->rarity = Bronze ;
    card->faction = Neutral;
    card->tags = { Organic };
    card->isSpecial = true;

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        Card *left = cardNextTo(target, ally, enemy, -1);
        Card *right = cardNextTo(target, ally, enemy, 1);
        for (Card *card : std::vector<Card *>{left, target, right})
            if (card != nullptr)
                damage(card, 4, ally, enemy, card);
    };
    return card;
}


Card *createKeiraMetz()
{
    auto *card = new Card();
    card->id = "122108";
    card->power = card->powerBase = 6;
    card->rarity = Gold;
    card->faction = NothernRealms;
    card->tags = { Temeria, Mage };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToSelectOption(ally, enemy, card, {createAlzursThunder(), createThunderbolt(), createArachasVenom()});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}


Card *createDolBlathannaArcher()
{
    auto *card = new Card();
    card->id = "142310";
    card->power = card->powerBase = 7;
    card->rarity = Bronze;
    card->faction = Scoiatael;
    card->tags = { Elf, Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        _nShots = 0;
        startChoiceToTargetCard(ally, enemy, card);
        startChoiceToTargetCard(ally, enemy, card);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        damage(target, ++_nShots == 1 ? 3 : 1, ally, enemy, card);
    };
    return card;
}


Card *createHalfElfHunter()
{
    auto *card = new Card();
    card->id = "201636";
    card->power = card->powerBase = 6;
    card->rarity = Bronze;
    card->faction = Scoiatael;
    card->tags = { Elf, Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        Card *copy = defaultCopy();
        copy->isDoomed = true;
        summonNewUnitToPos(copy, rowAndPosToTheRight(card, ally, 1), ally, enemy, card);
    };
    return card;
}


Card *createAmbassador()
{
    auto *card = new Card();
    card->id = "162315";
    card->power = card->powerBase = 2;
    card->isLoyal = false;
    card->rarity = Bronze;
    card->faction = Nilfgaard;
    card->tags = {};

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AllyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        boost(target, 12, ally, enemy, card);
    };
    return card;
}


Card *createAssassin()
{
    auto *card = new Card();
    card->id = "200115";
    card->power = card->powerBase = 1;
    card->isLoyal = false;
    card->rarity = Bronze;
    card->faction = Nilfgaard;
    card->tags = {};

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (Card *left = cardNextTo(card, ally, enemy, -1)) {
            damage(left, 10, ally, enemy, card);
        }
    };
    return card;
}


Card *createTuirseachArcher()
{
    auto *card = new Card();
    card->id = "152315";
    card->power = card->powerBase = 8;
    card->rarity = Bronze;
    card->faction = Skellige;
    card->tags = { ClanTuirseach, Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard, 3);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        saveFieldsSnapshot(ally, enemy, DealDamage, card, {target}, "", 1);
        damage(target, 1, ally, enemy, card);
    };
    return card;
}


Card *createInfiltrator()
{
    auto *card = new Card();
    card->id = "200118";
    card->power = card->powerBase = 10;
    card->rarity = Bronze;
    card->faction = Nilfgaard;
    card->tags = {};

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        toggleSpy(target, ally, enemy, card);
    };
    return card;
}


Card *createImpenetrableFog()
{
    auto *card = new Card();
    card->id = "113305";
    card->isSpecial = true;
    card->rarity = Bronze;
    card->faction = Neutral;
    card->tags = { Hazard };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToSelectRow(ally, enemy, card, {3, 4, 5});
    };

    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
        applyRowEffect(ally, enemy, screenRow, ImpenetrableFogEffect);
    };
    return card;
}


Card *createTorrentialRain()
{
    auto *card = new Card();
    card->id = "113312";
    card->isSpecial = true;
    card->rarity = Bronze;
    card->faction = Neutral;
    card->tags = { Hazard };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToSelectRow(ally, enemy, card, {3, 4, 5});
    };

    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
        applyRowEffect(ally, enemy, screenRow, TorrentialRainEffect);
    };
    return card;
}


Card *createBitingFrost()
{
    auto *card = new Card();
    card->id = "113302";
    card->isSpecial = true;
    card->rarity = Bronze;
    card->faction = Neutral;
    card->tags = { Hazard };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToSelectRow(ally, enemy, card, {3, 4, 5});
    };

    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
        applyRowEffect(ally, enemy, screenRow, BitingFrostEffect);
    };
    return card;
}


Card *createGoldenFroth()
{
    auto *card = new Card();
    card->id = "201749";
    card->isSpecial = true;
    card->rarity = Bronze;
    card->faction = Neutral;
    card->tags = { Boon };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToSelectRow(ally, enemy, card, {0, 1, 2});
    };

    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
        applyRowEffect(ally, enemy, screenRow, GoldenFrothEffect);
    };
    return card;
}


Card *createSkelligeStorm()
{
    auto *card = new Card();
    card->id = "113203";
    card->isSpecial = true;
    card->rarity = Silver;
    card->faction = Neutral;
    card->tags = { Hazard };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToSelectRow(ally, enemy, card, {3, 4, 5});
    };

    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
        applyRowEffect(ally, enemy, screenRow, SkelligeStormEffect);
    };
    return card;
}


Card *createImperialManticore()
{
    auto *card = new Card();
    card->id = "132209";
    card->power = card->powerBase = 13;
    card->rarity = Silver;
    card->faction = Monster;
    card->tags = { Beast };
    return card;
}


Card *createManticoreVenom()
{
    auto *card = new Card();
    card->id = "113306";
    card->isSpecial = true;
    card->rarity = Silver;
    card->faction = Neutral;
    card->tags = { Organic };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        damage(target, 13, ally, enemy, card);
    };
    return card;
}


Card *createGloriousHunt()
{
    auto *card = new Card();
    card->id = "201635";
    card->isSpecial = true;
    card->rarity = Silver;
    card->faction = Neutral;
    card->tags = { Tactics };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        if (powerField(ally) < powerField(enemy))
            return spawnNewCard(createImperialManticore(), ally, enemy, card);

        return spawnNewCard(createManticoreVenom(), ally, enemy, card);
    };
    return card;
}


Card *createVes()
{
    auto *card = new Card();
    card->id = "122204";
    card->power = card->powerBase = 12;
    card->rarity = Silver;
    card->faction = NothernRealms;
    card->tags = { Temeria, Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AllyHand, 2, true);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        swapACard(target, ally, enemy, card);
    };
    return card;
}


Card *createVaedermakar()
{
    auto *card = new Card();
    card->id = "113208";
    card->power = card->powerBase = 4;
    card->rarity = Silver;
    card->faction = Neutral;
    card->tags = { Mage };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToSelectOption(ally, enemy, card, {createBitingFrost(), createImpenetrableFog(), createAlzursThunder()});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}


Card *createFrightener()
{
    auto *card = new Card();
    card->id = "132204";
    card->power = card->powerBase = 13;
    card->isLoyal = false;
    card->timer = 1;
    card->rarity = Silver;
    card->faction = Monster;
    card->tags = { Construct, Agent };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (tick(card, ally, enemy))
            drawACard(ally, enemy,  card);

        /// can't move another to this row, if its already full
        startChoiceToTargetCard(ally, enemy, card, {isOnAnotherRow(&enemy, card)}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        moveExistedUnitToPos(target, rowAndPosLastInTheSameRow(card, enemy), enemy, ally, card);
    };
    return card;
}


Card *createCleaver()
{
    auto *card = new Card();
    card->id = "122216";
    card->power = card->powerBase = 7;
    card->rarity = Silver;
    card->faction = Neutral;
    card->tags = { Dwarf };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (ally.hand.size() != 0)
            startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        damage(target, int(ally.hand.size()), ally, enemy, card);
    };
    return card;
}


Card *createScorch()
{
    auto *card = new Card();
    card->id = "113309";
    card->isSpecial = true;
    card->rarity = Silver;
    card->faction = Neutral;
    card->tags = { Spell };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        for (Card *card : highests(cardsFiltered(ally, enemy, {}, AnyBoard)))
            putToDiscard(card, ally, enemy, card);
    };
    return card;
}


Card *createReinforcements()
{
    auto *card = new Card();
    card->id = "123201";
    card->isSpecial = true;
    card->rarity = Silver;
    card->faction = NothernRealms;
    card->tags = { Tactics };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, hasAnyOfTags({Soldier, Support, Machine, Officer})}, AllyDeckShuffled);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}


Card *createJohnNatalis()
{
    auto *card = new Card();
    card->id = "122103";
    card->power = card->powerBase = 6;
    card->rarity = Gold;
    card->faction = NothernRealms;
    card->tags = { Temeria, Officer };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, hasTag(Tactics)}, AllyDeckShuffled);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}


Card *createEleyas()
{
    auto *card = new Card();
    card->id = "142214";
    card->power = card->powerBase = 10;
    card->rarity = Silver;
    card->faction = Scoiatael;
    card->tags = { Elf, Soldier };

    // NOTE: when Eleyas goes to deck, it loses all the boosts - so it doesn't work properly
    card->_onDraw = [=](Field &ally, Field &enemy) {
        boost(card, 2, ally, enemy, card);
    };

    card->_onSwap = [=](Field &ally, Field &enemy) {
        boost(card, 2, ally, enemy, card);
    };
    return card;
}


Card *createReaverScout()
{
    auto *card = new Card();
    card->id = "122307";
    card->power = card->powerBase = 1;
    card->rarity = Bronze;
    card->faction = NothernRealms;
    card->tags = { Redania, Support };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronze, otherThan(name), hasCopyInADeck(&ally)}, AllyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (Card *copy = findCopy(target, ally.deck))
            playExistedCard(copy, ally, enemy, card);
    };
    return card;
}


Card *createHeymaeySpearmaiden()
{
    auto *card = new Card();
    card->id = "200528";
    card->power = card->powerBase = 2;
    card->rarity = Bronze;
    card->faction = Skellige;
    card->tags = { ClanAnCraite, Support };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronze, hasAnyOfTags({Soldier, Machine}), hasCopyInADeck(&ally)}, AllyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        damage(target, 1, ally, enemy, card);
        if (Card *copy = findCopy(target, ally.deck))
            playExistedCard(copy, ally, enemy, card);
    };
    return card;
}


Card *createKaedweniKnight()
{
    auto *card = new Card();
    card->id = "201622";
    card->power = card->powerBase = 8;
    card->rarity = Bronze;
    card->faction = NothernRealms;
    card->tags = { Kaedwen, Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        gainArmor(card, 2, ally, enemy, card);
    };

    card->_onDeployFromDeck = [=](Field &ally, Field &enemy) {
        gainArmor(card, 2, ally, enemy, card);
        boost(card, 5, ally, enemy, card);
    };
    return card;
}


Card *createVriheddSappers()
{
    auto *card = new Card();
    card->id = "142307";
    card->power = card->powerBase = 11;
    card->isAmbush = true;
    card->rarity = Bronze;
    card->faction = Scoiatael;
    card->tags = { Elf, Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        card->isAmbush = true;
        setTimer(card, ally, enemy, 2);
    };

    card->_onTurnStart = [=](Field &ally, Field &enemy) {
        if (!isOnBoard(card, ally) || tick(card, ally, enemy))
            flipOver(card, ally, enemy);
    };
    return card;
}


Card *createPriestessOfFreya()
{
    auto *card = new Card();
    card->id = "152310";
    card->power = card->powerBase = 1;
    card->rarity = Bronze;
    card->faction = Skellige;
    card->tags = { ClanHeymaey, Support };
    card->isDoomed = true;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronze, hasTag(Soldier)}, AllyDiscard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}


Card *createDimunCorsair()
{
    auto *card = new Card();
    card->id = "200145";
    card->power = card->powerBase = 3;
    card->rarity = Bronze;
    card->faction = Skellige;
    card->tags = { ClanDimun, Support };
    card->isDoomed = true;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronze, hasTag(Machine)}, AllyDiscard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}


Card *createSigrdrifa()
{
    auto *card = new Card();
    card->id = "152211";
    card->power = card->powerBase = 3;
    card->rarity = Silver;
    card->faction = Skellige;
    card->tags = { Support };
    card->isDoomed = true;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, hasAnyOfTags({ClanAnCraite, ClanDimun, ClanDrummond, ClanHeymaey, ClanTuirseach, ClanBrokvar, ClanTordarroch})}, AllyDiscard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}


Card *createSage()
{
    auto *card = new Card();
    card->id = "200138";
    card->power = card->powerBase = 2;
    card->rarity = Bronze;
    card->faction = Scoiatael;
    card->tags = { Elf, Mage };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronze, hasAnyOfTags({Alchemy, Spell})}, AllyDiscard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        target->isDoomed = true;
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}


Card *createReconnaissance()
{
    auto *card = new Card();
    card->id = "201704";
    card->isSpecial = true;
    card->rarity = Bronze;
    card->faction = Neutral;
    card->tags = { Tactics };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, randoms(cardsFiltered(ally, enemy, {isBronze, isUnit}, AllyDeck), 2, ally.rng));
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}


Card *createElvenMercenary()
{
    auto *card = new Card();
    card->id = "142308";
    card->power = card->powerBase = 1;
    card->rarity = Bronze;
    card->faction = Scoiatael;
    card->tags = { Elf, Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, randoms(cardsFiltered(ally, enemy, {isBronze, ::isSpecial}, AllyDeck), 2, ally.rng));
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}


Card *createChampionOfHov()
{
    auto *card = new Card();
    card->id = "152202";
    card->power = card->powerBase = 7;
    card->rarity = Silver;
    card->faction = Skellige;
    card->tags = { Ogroid };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        duel(card, target, ally, enemy);
    };
    return card;
}


Card *createGeraltIgni()
{
    auto *card = new Card();
    card->id = "112102";
    card->power = card->powerBase = 5;
    card->rarity = Gold;
    card->faction = Neutral;
    card->tags = { Witcher };

    const auto isOkRow = [](const std::vector<Card *> &cards) {
        return powerRow(cards) >= 25;
    };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToSelectRow(ally, enemy, card, {3, 4, 5}, {isOkRow});
    };

    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
        for (Card *card : highests(cardsInRow(ally, enemy, screenRow)))
            putToDiscard(card, ally, enemy, card);
    };
    return card;
}


Card *createGeraltOfRivia()
{
    auto *card = new Card();
    card->id = "112103";
    card->power = card->powerBase = 15;
    card->rarity = Gold;
    card->faction = Neutral;
    card->tags = { Witcher };
    return card;
}


Card *createPriscilla()
{
    auto *card = new Card();
    card->id = "122202";
    card->power = card->powerBase = 3;
    card->rarity = Gold;
    card->faction = NothernRealms;
    card->tags = { Support };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *card : randoms(cardsFiltered(ally, enemy, {[=](Card *card){ return card != card; }}, AllyBoard), 5, ally.rng))
            boost(card, 3, ally, enemy, card);
    };
    return card;
}


Card *createSeltkirkOfGulet()
{
    auto *card = new Card();
    card->id = "201618";
    card->power = card->powerBase = 8;
    card->rarity = Gold;
    card->faction = NothernRealms;
    card->tags = { Aedirn, Officer, Cursed };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        gainArmor(card, 3, ally, enemy, card);
        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        duel(card, target, ally, enemy);
    };
    return card;
}


Card *createAdrenalineRush()
{
    auto *card = new Card();
    card->id = "113307";
    card->isSpecial = true;
    card->rarity = Bronze;
    card->faction = Neutral;
    card->tags = { Organic };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card);
    };

    card->_onTargetChoosen = [=](Card *target, Field &, Field &) {
        target->isResilient = !target->isResilient;
    };
    return card;
}


Card *createShupesDayOff()
{
    auto *card = new Card();
    card->id = "201627";
    card->isSpecial = true;
    card->rarity = Gold;
    card->faction = Neutral;
    card->tags = { Organic };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        if (!hasNoDuplicates(ally.deckStarting))
            return;

        startChoiceToSelectOption(ally, enemy, card, {createShupeKnight(), createShupeHunter(), createShupeMage()});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}


Card *createShupeHunter()
{
    auto *card = new Card();
    card->id = "201731";
    card->power = card->powerBase = 8;
    card->isDoomed = true;
    card->rarity = Gold;
    card->faction = Neutral;
    card->tags = { Ogroid };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        auto *option1 = new ShupeHunter::Play;
        copyCardText(card, option1);
        option1->text = "Play a Bronze or Silver unit from Deck.";

        auto *option2 = new ShupeHunter::Shot;
        copyCardText(card, option2);
        option2->text = "Deal 15 damage.";

        auto *option3 = new ShupeHunter::Replay;
        copyCardText(card, option3);
        option3->text = "Replay a Bronze or Silver unit and Boost it by 5.";

        auto *option4 = new ShupeHunter::Clear;
        copyCardText(card, option4);
        option4->text = "Clear all Hazards from your side and Boost allies by 1.";

        auto *option5 = new ShupeHunter::Barrage;
        copyCardText(card, option5);
        option5->text = "Deal 2 damage to a random enemy. Repeat 8 times.";

        _choosen = nullptr;
        startChoiceToSelectOption(ally, enemy, card, {option1, option2, option3, option4, option5}, 1, 3);
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (dynamic_cast<ShupeHunter::Play *>(target)) {
            _choosen = target;
            startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, isUnit}, AllyDeck);
            return;
        }

        if (dynamic_cast<ShupeHunter::Shot *>(target)) {
            _choosen = target;
            startChoiceToTargetCard(ally, enemy, card);
            return;
        }

        if (dynamic_cast<ShupeHunter::Replay *>(_choosen)) {
            _choosen = target;
            startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, isUnit}, AllyBoard);
            return;
        }

        if (dynamic_cast<ShupeHunter::Clear *>(target)) {
            for (Card *card : cardsFiltered(ally, enemy, {}, AllyBoard))
                boost(card, 1, ally, enemy, card);
            clearAllHazards(ally);
            return;
        }

        if (dynamic_cast<ShupeHunter::Barrage *>(target)) {
            for (int n = 0; n < 8; ++n)
                if (Card *card = random(cardsFiltered(ally, enemy, {}, EnemyBoard), ally.rng)) {
                    damage(card, 2, ally, enemy, card);
                }
            return;
        }

        assert(false);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        assert(_choosen);

        if (dynamic_cast<ShupeHunter::Play *>(_choosen)) {
            playExistedCard(target, ally, enemy, card);
            delete _choosen;
            _choosen = nullptr;
            return;
        }

        if (dynamic_cast<ShupeHunter::Shot *>(_choosen)) {
            damage(target, 15, ally, enemy, card);
            delete _choosen;
            _choosen = nullptr;
            return;
        }

        if (dynamic_cast<ShupeHunter::Replay *>(_choosen)) {
            putToHand(target, ally, enemy,  card);
            boost(target, 5, ally, enemy, card);
            playExistedCard(target, ally, enemy, card);
            delete _choosen;
            _choosen = nullptr;
            return;
        }

        assert(false);
    };
    return card;
}


Card *createShupeMage()
{
    auto *card = new Card();
    card->id = "201725";
    card->power = card->powerBase = 4;
    card->isDoomed = true;
    card->rarity = Gold;
    card->faction = Neutral;
    card->tags = { Ogroid };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        auto *option1 = new ShupeMage::Draw;
        copyCardText(card, option1);
        option1->text = "Draw a card.";

        auto *option2 = new ShupeMage::Charm;
        copyCardText(card, option2);
        option2->text = "Charm a random enemy.";

        auto *option3 = new ShupeMage::Hazards;
        copyCardText(card, option3);
        option3->text = "Spawn a random Hazard on each enemy row.";

        auto *option4 = new ShupeMage::Meteor;
        copyCardText(card, option4);
        option4->text = "Deal 10 damage to an enemy and 5 damage to each adjacent enemy.";

        auto *option5 = new ShupeMage::Play;
        copyCardText(card, option5);
        option5->text = "Play a Bronze or Silver special card from your deck.";

        _choosen = nullptr;
        startChoiceToSelectOption(ally, enemy, card, {option1, option2, option3, option4, option5}, 1, 3);
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (dynamic_cast<ShupeMage::Draw *>(target)) {
            drawACard(ally, enemy,  card);
            return;
        }

        if (dynamic_cast<ShupeMage::Charm *>(target)) {
            if (Card *card = random(cardsFiltered(ally, enemy, {}, EnemyBoard), ally.rng))
                charm(card, ally, enemy, card);
            return;
        }

        if (dynamic_cast<ShupeMage::Hazards *>(target)) {
            for (int screenRow = 3; screenRow < 6; ++screenRow)
                applyRowEffect(ally, enemy, screenRow, randomHazardEffect(ally.rng));
            return;
        }

        if (dynamic_cast<ShupeMage::Meteor *>(target)) {
            _choosen = target;
            startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
            return;
        }

        if (dynamic_cast<ShupeMage::Play *>(target)) {
            _choosen = target;
            startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, ::isSpecial}, AllyDeckShuffled);
            return;
        }

        assert(false);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        assert(_choosen);

        if (dynamic_cast<ShupeMage::Meteor *>(_choosen)) {
            Card *left = cardNextTo(target, ally, enemy, -1);
            Card *right = cardNextTo(target, ally, enemy, 1);

            damage(target, 10, ally, enemy, card);
            if (left != nullptr) {
                damage(left, 5, ally, enemy, card);
            }
            if (right != nullptr) {
                damage(right, 5, ally, enemy, card);
            }

            delete _choosen;
            _choosen = nullptr;
            return;
        }

        if (dynamic_cast<ShupeMage::Play *>(_choosen)) {
            playExistedCard(target, ally, enemy, card);

            delete _choosen;
            _choosen = nullptr;
            return;
        }

        assert(false);
    };
    return card;
}


Card *createMandrake()
{
    auto *card = new Card();
    card->id = "200223";
    card->isSpecial = true;
    card->rarity = Silver;
    card->faction = Neutral;
    card->tags = { Alchemy, Organic };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        auto *option1 = new Mandrake::Buff;
        copyCardText(card, option1);
        option1->text = "Heal a unit and and Strengthen it by 6.";

        auto *option2 = new Mandrake::Debuff;
        copyCardText(card, option2);
        option2->text = "Reset a unit and Weaken it by 6.";

        _choosen = nullptr;
        startChoiceToSelectOption(ally, enemy, card, {option1, option2});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        _choosen = target;
        startChoiceToTargetCard(ally, enemy, card);
        return;
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        assert(_choosen);

        if (dynamic_cast<Mandrake::Buff *>(_choosen)) {
            heal(target, ally, enemy, card);
            strengthen(target, 6, ally, enemy, card);

            delete _choosen;
            _choosen = nullptr;
            return;
        }

        if (dynamic_cast<Mandrake::Debuff *>(_choosen)) {
            reset(target, ally, enemy, card);
            weaken(target, 6, ally, enemy, card);

            delete _choosen;
            _choosen = nullptr;
            return;
        }

        assert(false);
    };
    return card;
}


Card *createBoneTalisman()
{
    auto *card = new Card();
    card->id = "201598";
    card->isSpecial = true;
    card->rarity = Bronze;
    card->faction = Skellige;
    card->tags = { Item };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        auto *option1 = new BoneTalisman::Resurrect;
        copyCardText(card, option1);
        option1->text = "Resurrect a Bronze Beast or Cultist.";

        auto *option2 = new BoneTalisman::Buff;
        copyCardText(card, option2);
        option2->text = "Heal an ally and Strengthen it by 3.";

        _choosen = nullptr;
        startChoiceToSelectOption(ally, enemy, card, {option1, option2});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        _choosen = target;

        if (dynamic_cast<BoneTalisman::Resurrect *>(target))
            return startChoiceToTargetCard(ally, enemy, card, {isBronze, hasAnyOfTags({Beast, Cultist})}, AllyDiscard);

        if (dynamic_cast<BoneTalisman::Buff *>(target))
            return startChoiceToTargetCard(ally, enemy, card, {}, AllyBoard);

        assert(false);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        assert(_choosen);

        if (dynamic_cast<BoneTalisman::Resurrect *>(_choosen)) {
            playExistedCard(target, ally, enemy, card);

            delete _choosen;
            _choosen = nullptr;
            return;
        }

        if (dynamic_cast<BoneTalisman::Buff *>(_choosen)) {
            heal(target, ally, enemy, card);
            strengthen(target, 3, ally, enemy, card);

            delete _choosen;
            _choosen = nullptr;
            return;
        }

        assert(false);
    };
    return card;
}


Card *createShupeKnight()
{
    auto *card = new Card();
    card->id = "201737";
    card->power = card->powerBase = 12;
    card->isDoomed = true;
    card->rarity = Gold;
    card->faction = Neutral;
    card->tags = { Ogroid };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        auto *option1 = new ShupeKnight::Destroy;
        copyCardText(card, option1);
        option1->text = "Destroy enemies with 4 or less power.";

        auto *option2 = new ShupeKnight::Reset;
        copyCardText(card, option2);
        option2->text = "Reset a unit.";

        auto *option3 = new ShupeKnight::Duel;
        copyCardText(card, option3);
        option3->text = "Duel an enemy.";

        auto *option4 = new ShupeKnight::Strengthen;
        copyCardText(card, option4);
        option4->text = "Strengthen self to 25.";

        auto *option5 = new ShupeKnight::Resilient;
        copyCardText(card, option5);
        option5->text = "Resilent.";

        _choosen = nullptr;
        startChoiceToSelectOption(ally, enemy, card, {option1, option2, option3, option4, option5}, 1, 3);
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (dynamic_cast<ShupeKnight::Destroy *>(target)) {
            for (Card *card : cardsFiltered(ally, enemy, {hasPowerXorLess(4)}, EnemyBoard))
                putToDiscard(card, ally, enemy, card);
            return;
        }

        if (dynamic_cast<ShupeKnight::Reset *>(target)) {
            _choosen = target;
            startChoiceToTargetCard(ally, enemy, card);
            return;
        }

        if (dynamic_cast<ShupeKnight::Duel *>(target)) {
            _choosen = target;
            startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
            return;
        }

        if (dynamic_cast<ShupeKnight::Strengthen *>(target)) {
            strengthen(card, 25 - powerBase, ally, enemy, card);
            return;
        }

        if (dynamic_cast<ShupeKnight::Resilient *>(target)) {
            isResilient = true;
            return;
        }

        assert(false);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        assert(_choosen);

        if (dynamic_cast<ShupeKnight::Reset *>(_choosen)) {
            //target->power = target->powerBase;
            reset(target, ally, enemy, card);
            delete _choosen;
            _choosen = nullptr;
            return;
        }

        if (dynamic_cast<ShupeKnight::Duel *>(_choosen)) {
            duel(card, target, ally, enemy);
            delete _choosen;
            _choosen = nullptr;
            return;
        }

        assert(false);
    };
    return card;
}


Card *createDecoy()
{
    auto *card = new Card();
    card->id = "113201";
    card->isSpecial = true;
    card->rarity = Silver;
    card->faction = Neutral;
    card->tags = { Tactics };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, { isBronzeOrSilver }, AllyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        putToHand(target, ally, enemy,  card);
        boost(target, 3, ally, enemy, card);
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}


Card *createFirstLight()
{
    auto *card = new Card();
    card->id = "113303";
    card->isSpecial = true;
    card->rarity = Bronze;
    card->faction = Neutral;
    card->tags = { Tactics };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        auto *option1 = new FirstLight::Clear;
        copyCardText(card, option1);
        option1->text = "Boost all damaged allies under Hazards by 2 and clear all Hazards from your side.";

        auto *option2 = new FirstLight::Play;
        copyCardText(card, option2);
        option2->text = "Play a random Bronze unit from your deck.";

        startChoiceToSelectOption(ally, enemy, card, {option1, option2});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (dynamic_cast<FirstLight::Clear *>(target)) {
            std::vector<Card *> damagedUnitsUnderHazards;
            clearAllHazards(ally, &damagedUnitsUnderHazards);
            for (Card *card : damagedUnitsUnderHazards)
                boost(card, 2, ally, enemy, card);
            delete target;
            return;
        }

        if (dynamic_cast<FirstLight::Play *>(target)) {
            if (Card *card = random(cardsFiltered(ally, enemy, { isBronze, isUnit }, AllyDeck), ally.rng))
                playExistedCard(card, ally, enemy, card);
            delete target;
            return;
        }

        assert(false);
    };
    return card;
}


Card *createClearSkies()
{
    auto *card = new Card();
    card->id = "113303";
    card->isSpecial = true;
    card->rarity = Bronze;
    card->faction = Neutral;
    card->tags = { Tactics };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        std::vector<Card *> damagedUnitsUnderHazards;
        clearAllHazards(ally, &damagedUnitsUnderHazards);
        for (Card *card : damagedUnitsUnderHazards)
            boost(card, 2, ally, enemy, card);
    };
    return card;
}


Card *createEpidemic()
{
    auto *card = new Card();
    card->id = "113308";
    card->isSpecial = true;
    card->rarity = Bronze;
    card->faction = Neutral;
    card->tags = { Organic, Spell };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        for (Card *card : lowests(cardsFiltered(ally, enemy, {}, AnyBoard)))
            putToDiscard(card, ally, enemy, card);
    };
    return card;
}


Card *createMoonlight()
{
    auto *card = new Card();
    card->id = "200067";
    card->isSpecial = true;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Hazard, Boon };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        auto *option1 = new Moonlight::FullMoon;
        copyCardText(card, option1);
        option1->name = "Full Moon";
        option1->text = "Apply a Boon to an allied row that boosts a random Beast or Vampire by 2 on turn start.";

        auto *option2 = new Moonlight::BloodMoon;
        copyCardText(card, option2);
        option2->name = "Blood Moon";
        option2->text = "Apply a Hazard to an enemy row that deals 2 damage to all units on contact.";

        startChoiceToSelectOption(ally, enemy, card, {option1, option2});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (dynamic_cast<Moonlight::FullMoon *>(target)) {
            startChoiceToSelectRow(ally, enemy, card, {0, 1, 2});
            delete target;
            return;
        }

        if (dynamic_cast<Moonlight::BloodMoon *>(target)) {
            startChoiceToSelectRow(ally, enemy, card, {3, 4, 5});
            delete target;
            return;
        }

        assert(false);
    };

    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
        applyRowEffect(ally, enemy, screenRow, screenRow < 3 ? FullMoonEffect : BloodMoonEffect);
    };
    return card;
}


Card *createCiriNova()
{
    auto *card = new Card();
    card->id = "201626";
    card->power = card->powerBase = 1;
    card->isDoomed = true;
    card->rarity = Gold;
    card->faction = Neutral;
    card->tags = { Cintra, Witcher };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (!hasExactTwoDuplicatesOfBronze(ally.deckStarting))
            return;

        strengthen(card, 22 - powerBase, ally, enemy, card);
    };
    return card;
}


Card *createHaraldTheCripple()
{
    auto *card = new Card();
    card->id = "200161";
    card->power = card->powerBase = 6;
    card->rarity = Gold;
    card->faction = Skellige;
    card->tags = { ClanAnCraite, Leader };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        Row row;
        Pos pos;
        if (!_findRowAndPos(card, ally, row, pos))
            return;
        for (int n = 0; n < 9; ++n)
            if (Card *card = random(enemy.row(row), ally.rng))
                damage(card, 1, ally, enemy, card);
    };
    return card;
}


Card *createEmissary()
{
    auto *card = new Card();
    card->id = "162314";
    card->isLoyal = false;
    card->power = card->powerBase = 2;
    card->rarity = Bronze;
    card->faction = Nilfgaard;
    card->tags = { };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, randoms(cardsFiltered(ally, enemy, {isBronze, isUnit}, AllyDeckShuffled), 2, ally.rng));
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}


Card *createCeallachDyffryn()
{
    auto *card = new Card();
    card->id = "162213";
    card->power = card->powerBase = 2;
    card->rarity = Silver;
    card->faction = Nilfgaard;
    card->tags = { Officer };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToSelectOption(ally, enemy, card, {new Ambassador(), new Assassin(), new Emissary()});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}


Card *createRestore()
{
    auto *card = new Card();
    card->id = "153201";
    card->isSpecial = true;
    card->rarity = Silver;
    card->faction = Skellige;
    card->tags = { Spell };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, isUnit, isSkelligeFaction}, AllyDiscard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        putToHand(target, ally, enemy,  card);
        target->isDoomed = true;
        target->powerBase = target->power = 8;
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}


Card *createDrummondQueensguard()
{
    auto *card = new Card();
    card->id = "152307";
    card->power = card->powerBase = 4;
    card->rarity = Bronze;
    card->faction = Skellige;
    card->tags = { ClanDrummond, Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *card : cardsFiltered(ally, enemy, {isCopy<DrummondQueensguard>}, AllyDiscard))
            moveExistedUnitToPos(card, rowAndPosToTheRight(card, ally, 1), ally, enemy, card);
    };
    return card;
}


Card *createBranTuirseach()
{
    auto *card = new Card();
    card->id = "200159";
    card->power = card->powerBase = 2;
    card->rarity = Gold;
    card->faction = Skellige;
    card->tags = { ClanTuirseach, Leader };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AllyDeckShuffled, 3, true);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        putToDiscard(target, ally, enemy, card);
        if (!target->isSpecial)
            strengthen(target, 1, ally, enemy, card);
    };
    return card;
}


Card *createDrummondWarmonger()
{
    auto *card = new Card();
    card->id = "200036";
    card->power = card->powerBase = 8;
    card->rarity = Bronze;
    card->faction = Skellige;
    card->tags = { ClanDrummond, Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronze}, AllyDeckShuffled);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        putToDiscard(target, ally, enemy, card);
    };
    return card;
}


Card *createDimunPirate()
{
    auto *card = new Card();
    card->id = "152305";
    card->power = card->powerBase = 11;
    card->rarity = Bronze;
    card->faction = Skellige;
    card->tags = { ClanDimun, Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *card : cardsFiltered(ally, enemy, {isCopy<DimunPirate>}, AllyDeck))
            putToDiscard(card, ally, enemy, card);
    };
    return card;
}


Card *createAnCraiteRaider()
{
    auto *card = new Card();
    card->id = "152316";
    card->power = card->powerBase = 4;
    card->rarity = Bronze;
    card->faction = Skellige;
    card->tags = { ClanAnCraite, Soldier };

    card->_onDiscard = [=](Field &ally, Field &enemy) {
        moveExistedUnitToPos(card, rowAndPosRandom(ally), ally, enemy, card);
    };
    return card;
}


Card *createMadmanLugos()
{
    auto *card = new Card();
    card->id = "152106";
    card->power = card->powerBase = 6;
    card->rarity = Gold;
    card->faction = Skellige;
    card->tags = { ClanDrummond, Officer };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronze, isUnit}, AllyDeckShuffled);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (_discarded == nullptr) {
            _discarded = target;
            putToDiscard(target, ally, enemy, card);
            startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
            return;
        }
        damage(target, _discarded->powerBase, ally, enemy, card);
    };
    return card;
}


Card *createErmion()
{
    auto *card = new Card();
    card->id = "152103";
    card->power = card->powerBase = 10;
    card->rarity = Gold;
    card->faction = Skellige;
    card->tags = { ClanAnCraite, Support };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        drawACard(ally, enemy,  card);
        drawACard(ally, enemy,  card);
        startChoiceToTargetCard(ally, enemy, card, {}, AllyHand, 2);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        putToDiscard(target, ally, enemy, card);
    };
    return card;
}


Card *createCerysFearless()
{
    auto *card = new Card();
    card->id = "201778";
    card->power = card->powerBase = 6;
    card->rarity = Gold;
    card->faction = Skellige;
    card->tags = { ClanAnCraite, Officer };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        setTimer(card, ally, enemy, 1);
    };

    card->_onOtherAllyDiscarded = [=](Card *other, Field &ally, Field &enemy) {
        if (other->isSpecial || !isOnBoard(card, ally))
            return;

        if (tick(card, ally, enemy))
            playExistedCard(other, ally, enemy, card);
    };
    return card;
}


Card *createCerysAnCraite()
{
    auto *card = new Card();
    card->id = "200177";
    card->power = card->powerBase = 6;
    card->rarity = Gold;
    card->faction = Skellige;
    card->tags = { ClanAnCraite, Officer };

    card->_onDiscard = [=](Field &ally, Field &enemy) {
        setTimer(card, ally, enemy, 4);
    };

    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
        setTimer(card, ally, enemy, 4);
    };

    card->_onOtherAllyResurrecteded = [=](Card *, Field &ally, Field &enemy) {
        if (!isIn(card, ally.discard))
            return;

        if (tick(card, ally, enemy))
            moveExistedUnitToPos(card, rowAndPosRandom(ally), ally, enemy, card);
    };
    return card;
}


Card *createWoodlandSpirit()
{
    auto *card = new Card();
    card->id = "132103";
    card->power = card->powerBase = 5;
    card->rarity = Gold;
    card->faction = Monster;
    card->tags = { Relict };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        Row row;
        Pos pos;
        if (!_findRowAndPos(card, ally, row, pos))
            return;
        applyRowEffect(ally, enemy, 3 + row, ImpenetrableFogEffect);
        for (int n = 0; n < 3; ++n)
            spawnNewUnitToPos(createWolf(), rowAndPosLastInExactRow(ally, Meele), ally, enemy, card);
    };
    return card;
}


Card *createTrollololo()
{
    auto *card = new Card();
    card->id = "122209";
    card->power = card->powerBase = 11;
    card->rarity = Silver;
    card->faction = NothernRealms;
    card->tags = { Redania, Ogroid };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        gainArmor(card, 9, ally, enemy, card);
    };
    return card;
}


Card *createPrinceStennis()
{
    auto *card = new Card();
    card->id = "122208";
    card->power = card->powerBase = 3;
    card->rarity = Silver;
    card->faction = NothernRealms;
    card->tags = { Aedirn, Officer };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        gainArmor(card, 3, ally, enemy, card);
        const std::vector<Card *> cards = cardsFiltered(ally, enemy, {isNonSpying, isBronzeOrSilver, isUnit}, AllyDeck);
        if (cards.size() == 0)
            return;

        Card *target = cards.front();
        playExistedCard(target, ally, enemy, card);
        gainArmor(target, 5, ally, enemy, card);
    };
    return card;
}


Card *createVincentMeis()
{
    auto *card = new Card();
    card->id = "200098";
    card->power = card->powerBase = 9;
    card->rarity = Silver;
    card->faction = NothernRealms;
    card->tags = { Beast, Cursed };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        int _armor = 0;
        for (Card *target: cardsFiltered(ally, enemy, {hasArmor}, AnyBoard)) {
            const int armorTarget = target->armor;
            damage(target, armorTarget, ally, enemy, card);
            _armor += armorTarget;
        }
        if (_armor)
            boost(card, _armor / 2, ally, enemy, card);
    };
    return card;
}


Card *createMorkvarg()
{
    auto *card = new Card();
    // BUG: isn't carry over...
    // Add a onPutOnDiscard for Morkvarg and golden spell which strikes after 3 turns
    card->id = "152209";
    card->power = card->powerBase = 9;
    card->rarity = Silver;
    card->faction = Skellige;
    card->tags = { Beast, Cursed };

    card->_onDiscard = [=](Field &ally, Field &enemy) {
        if (!weaken(card, half(card->powerBase), ally, enemy, card))
            moveExistedUnitToPos(card, rowAndPosRandom(ally), ally, enemy, card);
    };

    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &rowAndPos) {
        if (!weaken(card, half(card->powerBase), ally, enemy, card))
            moveExistedUnitToPos(card, rowAndPos, ally, enemy, card);
    };
    return card;
}


Card *createArtefactCompression()
{
    auto *card = new Card();
    card->id = "200053";
    card->isSpecial = true;
    card->rarity = Silver;
    card->faction = Neutral;
    card->tags = { Spell };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver});
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        transform(target, JadeFigurine(), ally, enemy, card);
    };
    return card;
}


ArtefactCompression::JadeFigurine::JadeFigurine()
{
    auto *card = new Card();
    card->id = "200053";
    card->isDoomed = true;
    card->power = card->powerBase = 2;
    card->rarity = Bronze;
    card->faction = Neutral;
    card->tags = {};
    return card;
}

HjalmarAnCraite::LordOfUndvik::LordOfUndvik()
{
    auto *card = new Card();
    card->isLoyal = false;
    card->isDoomed = true;
    card->power = card->powerBase = 5;
    card->rarity = Silver;
    card->faction = Skellige;
    card->tags = { Ogroid };

    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
        for (Card *card : cardsFiltered(ally, enemy, {isCopy<HjalmarAnCraite>}, EnemyBoard))
            boost(card, 10, ally, enemy, card);
    };
    return card;
}


Card *createHjalmarAnCraite()
{
    auto *card = new Card();
    card->id = "152101";
    card->power = card->powerBase = 16;
    card->rarity = Gold;
    card->faction = Skellige;
    card->tags = { ClanAnCraite, Officer };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        spawnNewUnitToPos(new LordOfUndvik(), rowAndPosLastInExactRow(enemy, _findRowAndPos(card, ally).row()), enemy, ally, card);
    };
    return card;
}


Card *createRegis()
{
    auto *card = new Card();
    card->id = "112104";
    card->power = card->powerBase = 1;
    card->rarity = Gold;
    card->faction = Neutral;
    card->tags = { Vampire };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBoosted}, AnyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        const int x = target->power - target->powerBase;
        drain(target, x, ally, enemy, card);
    };
    return card;
}


Card *createLethoOfGulet()
{
    auto *card = new Card();
    card->id = "162101";
    card->isLoyal = false;
    card->power = card->powerBase = 1;
    card->rarity = Gold;
    card->faction = Nilfgaard;
    card->tags = { Witcher };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isOnSameRow(&enemy, card)}, EnemyBoard, 2);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        lock(target, ally, enemy, card);
        drain(target, target->power, ally, enemy, card);
    };
    return card;
}


Card *createAnCraiteLongship()
{
    auto *card = new Card();
    card->id = "152314";
    card->power = card->powerBase = 7;
    card->rarity = Bronze;
    card->faction = Skellige;
    card->tags = { ClanAnCraite, Machine };

    const auto onDeploy = [=](Field &ally, Field &enemy) {
        if (Card *card = random(cardsFiltered(ally, enemy, {}, EnemyBoard), ally.rng))
            damage(card, 2, ally, enemy, card);
    };

    card->_onDeploy = onDeploy;

    card->_onOtherAllyDiscarded = [=](Card *, Field &ally, Field &enemy) {
        if (isOnBoard(card, ally))
            onDeploy(ally, enemy);
    };
    return card;
}


Card *createTuirseachVeteran()
{
    auto *card = new Card();
    card->id = "200046";
    card->power = card->powerBase = 7;
    card->rarity = Bronze;
    card->faction = Skellige;
    card->tags = { ClanTuirseach, Support };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *card : cardsFiltered(ally, enemy, {hasTag(ClanTuirseach), otherThan(card)}, AllyBoardHandDeck))
            strengthen(card, 1, ally, enemy, card);
    };
    return card;
}


Card *createTuirseachHunter()
{
    auto *card = new Card();
    card->id = "152304";
    card->power = card->powerBase = 6;
    card->rarity = Bronze;
    card->faction = Skellige;
    card->tags = { ClanTuirseach, Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        damage(target, 5, ally, enemy, card);
    };
    return card;
}


Card *createUdalryk()
{
    auto *card = new Card();
    card->id = "152214";
    card->power = card->powerBase = 13;
    card->isLoyal = false;
    card->timer = 1;
    card->rarity = Silver;
    card->faction = Skellige;
    card->tags = { ClanBrokvar, Cursed, Agent };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (tick(card, ally, enemy))
            startChoiceToTargetCard(ally, enemy, card, _drawn = randoms(cardsFiltered(ally, enemy, {}, AllyDeck), 2, ally.rng));
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        putToHand(target, ally, enemy,  card);
        for (Card *card : _drawn)
            if (card != target)
                putToDiscard(card, ally, enemy, card);

        _drawn.clear();
    };
    return card;
}


Card *createBloodcurdlingRoar()
{
    auto *card = new Card();
    card->id = "152406";
    card->isSpecial = true;
    card->rarity = Bronze;
    card->faction = Neutral;
    card->tags = { Organic };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AllyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        putToDiscard(target, ally, enemy, card);
        spawnNewCard(createBear(), ally, enemy, card);
    };
    return card;
}


Card *createGremist()
{
    auto *card = new Card();
    card->id = "152206";
    card->power = card->powerBase = 4;
    card->rarity = Silver;
    card->faction = Skellige;
    card->tags = { Support };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToSelectOption(ally, enemy, card, {createTorrentialRain(), createClearSkies(), createBloodcurdlingRoar()});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}


Card *createOperator()
{
    auto *card = new Card();
    card->id = "112208";
    card->power = card->powerBase = 5;
    card->timer = 1;
    card->rarity = Silver;
    card->faction = Neutral;
    card->tags = { Mage };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (ally.passed || enemy.passed)
            return;
        if (tick(card, ally, enemy))
            startChoiceToTargetCard(ally, enemy, card, {isBronze, isUnit}, AllyHand);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        Card *copyAlly = target->defaultCopy();
        ally.cardsAdded.push_back(copyAlly);
        putToHand(copyAlly, ally, enemy,  card);

        Card *copyEnemy = target->defaultCopy();
        enemy.cardsAdded.push_back(copyEnemy);
        putToHand(copyEnemy, enemy, ally,  card);
    };
    return card;
}


Card *createZoriaRunestone()
{
    auto *card = new Card();
    card->id = "201582";
    card->isSpecial = true;
    card->rarity = Silver;
    card->faction = NothernRealms;
    card->tags = { Alchemy, Item };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceCreateOptions(ally, enemy, card, {isBronzeOrSilver, isNothernRealmsFaction});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}


Card *createRenew()
{
    auto *card = new Card();
    card->id = "113316";
    card->isSpecial = true;
    card->rarity = Gold;
    card->faction = Neutral;
    card->tags = { Spell };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceCreateOptions(ally, enemy, card, {isGold, isNonLeader}, AllyDiscard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}


Card *createEistTuirseach()
{
    auto *card = new Card();
    card->id = "201597";
    card->power = card->powerBase = 5;
    card->rarity = Gold;
    card->faction = Skellige;
    card->tags = { ClanTuirseach, Leader };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToSelectOption(ally, enemy, card, {new TuirseachArcher, new TuirseachAxeman, new TuirseachBearmaster, new TuirseachHunter, new TuirseachSkirmisher});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}


Card *createTuirseachAxeman()
{
    auto *card = new Card();
    card->id = "152312";
    card->power = card->powerBase = 6;
    card->rarity = Bronze;
    card->faction = Skellige;
    card->tags = { ClanTuirseach, Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        gainArmor(card, 2, ally, enemy, card);
    };

    card->_onOtherEnemyDamaged = [=](Card *other, Field &ally, Field &enemy) {
        Pos _;
        Row row;
        if (!_findRowAndPos(other, enemy, row, _))
            return;
        if (isIn(card, ally.row(row)))
            boost(card, 1, ally, enemy, card);
    };
    return card;
}


Card *createTuirseachSkirmisher()
{
    auto *card = new Card();
    card->id = "152313";
    card->power = card->powerBase = 8;
    card->rarity = Bronze;
    card->faction = Skellige;
    card->tags = { ClanTuirseach, Soldier };

    card->_onDeployFromDiscard = [=](Field &ally, Field &enemy) {
        strengthen(card, 3, ally, enemy, card);
    };
    return card;
}


Card *createDerran()
{
    auto *card = new Card();
    card->id = "201646";
    card->power = card->powerBase = 6;
    card->rarity = Silver;
    card->faction = Skellige;
    card->tags = { ClanTuirseach, Cursed };

    card->_onOtherEnemyDamaged = [=](Card *, Field &ally, Field &enemy) {
        if (isOnBoard(card, ally))
            boost(card, 1, ally, enemy, card);
    };
    return card;
}


Card *createRoach()
{
    auto *card = new Card();
    card->id = "112210";
    card->power = card->powerBase = 4;
    card->rarity = Silver;
    card->faction = Neutral;
    card->tags = { Beast };

    card->_onOtherAllyPlayedFromHand = [=](Card *other, Field &ally, Field &enemy) {
        if (other->rarity != Gold)
            return;

        if (!isIn(card, ally.deck))
            return;

        moveExistedUnitToPos(card, rowAndPosRandom(ally), ally, enemy, card);
    };
    return card;
}


Card *createJanCalveit()
{
    auto *card = new Card();
    card->id = "200164";
    card->power = card->powerBase = 5;
    card->rarity = Gold;
    card->faction = Nilfgaard;
    card->tags = { Officer, Leader };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        const std::vector<Card *> topThreeCards(ally.deck.begin(), ally.deck.begin() + std::min(int(ally.deck.size()), 3));
        startChoiceToTargetCard(ally, enemy, card, topThreeCards);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}


Card *createCahirDyffryn()
{
    auto *card = new Card();
    card->id = "162104";
    card->power = card->powerBase = 1;
    card->isDoomed = true;
    card->rarity = Gold;
    card->faction = Nilfgaard;
    card->tags = { Officer };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {hasTag(Leader)}, AllyDiscard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}


Card *createLethoKingslayer()
{
    auto *card = new Card();
    card->id = "201603";
    card->power = card->powerBase = 5;
    card->rarity = Gold;
    card->faction = Nilfgaard;
    card->tags = { Witcher };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        auto *option1 = new LethoKingslayer::Destroy;
        copyCardText(card, option1);
        option1->text = "Destroy an enemy Leader, then boost self by 5.";

        auto *option2 = new LethoKingslayer::Play;
        copyCardText(card, option2);
        option2->text = "Play a Bronze or Silver Tactic from your deck.";

        _choosen = nullptr;
        startChoiceToSelectOption(ally, enemy, card, {option1, option2});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        _choosen = target;

        if (dynamic_cast<LethoKingslayer::Destroy *>(_choosen))
            return startChoiceToTargetCard(ally, enemy, card, {hasTag(Leader)}, EnemyBoard);

        if (dynamic_cast<LethoKingslayer::Play *>(_choosen))
            return startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, hasTag(Tactics)}, AllyDeckShuffled);

        assert(false);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        assert(_choosen);

        if (dynamic_cast<LethoKingslayer::Destroy *>(_choosen)) {
            putToDiscard(target, ally, enemy, card);
            boost(card, 5, ally, enemy, card);

            delete _choosen;
            _choosen = nullptr;
            return;
        }

        if (dynamic_cast<LethoKingslayer::Play *>(_choosen)) {
            playExistedCard(target, ally, enemy, card);

            delete _choosen;
            _choosen = nullptr;
            return;
        }

        assert(false);
    };
    return card;
}


Card *createKingHenselt()
{
    auto *card = new Card();
    card->id = "200170";
    card->power = card->powerBase = 3;
    card->rarity = Gold;
    card->isCrew = true;
    card->faction = NothernRealms;
    card->tags = { Kaedwen, Leader };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronze, hasAnyOfTags({Machine, Kaedwen})}, AllyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        for (Card *copy : findCopies(target, ally.deck))
            playExistedCard(copy, ally, enemy, card);
    };
    return card;
}


Card *createBloodyBaron()
{
    auto *card = new Card();
    card->id = "122101";
    card->power = card->powerBase = 9;
    card->rarity = Gold;
    card->faction = NothernRealms;
    card->tags = { Temeria, Officer };

    card->_onOtherEnemyDestroyed = [=](Card *, Field &ally, Field &enemy) {
        if (isOnBoard(card, ally) || isIn(card, ally.deck) || isIn(card, ally.hand))
            boost(card, 1, ally, enemy, card);
    };
    return card;
}


Card *createDethmold()
{
    auto *card = new Card();
    card->id = "122207";
    card->power = card->powerBase = 4;
    card->rarity = Silver;
    card->faction = NothernRealms;
    card->tags = { Kaedwen, Mage };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToSelectOption(ally, enemy, card, {new TorrentialRain(), new ClearSkies(), new AlzursThunder()});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}


Card *createRonvidTheIncessant()
{
    auto *card = new Card();
    card->id = "200529";
    card->power = card->powerBase = 11;
    card->rarity = Silver;
    card->faction = NothernRealms;
    card->tags = { Kaedwen, Soldier };
    card->isCrew = true;

    card->_onTurnEnd = [=](Field &ally, Field &enemy) {
        if (!isIn(card, ally.discard))
            return;
        moveExistedUnitToPos(card, rowAndPosRandom(ally), ally, enemy, card);
        if (powerBase > 1)
            weaken(card, powerBase - 1, ally, enemy, card);
    };
    return card;
}


Card *createHubertRejk()
{
    auto *card = new Card();
    card->id = "200088";
    card->power = card->powerBase = 7;
    card->rarity = Silver;
    card->faction = NothernRealms;
    card->tags = { Vampire };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *card : cardsFiltered(ally, enemy, {isBoosted}, AllyDeck))
            drain(card, card->power - card->powerBase, ally, enemy, card);
    };
    return card;
}


Card *createCrachAnCraite()
{
    auto *card = new Card();
    card->id = "200160";
    card->power = card->powerBase = 5;
    card->faction = Skellige;
    card->rarity = Gold;
    card->tags = { ClanAnCraite, Leader };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (Card *card = highest(cardsFiltered(ally, enemy, {isUnit, isBronzeOrSilver, isNonSpying}, AllyDeck), ally.rng)) {
            strengthen(card, 2, ally, enemy, card);
            playExistedCard(card, ally, enemy, card);
        }
    };
    return card;
}


Card *createBirnaBran()
{
    auto *card = new Card();
    card->id = "152105";
    card->power = card->powerBase = 6;
    card->faction = Skellige;
    card->rarity = Gold;
    card->tags = { ClanTuirseach, Officer };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToSelectRow(ally, enemy, card, {3, 4, 5});
    };

    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
        applyRowEffect(ally, enemy, screenRow, SkelligeStormEffect);
    };
    return card;
}


Card *createCoral()
{
    auto *card = new Card();
    card->id = "152107";
    card->power = card->powerBase = 5;
    card->faction = Skellige;
    card->rarity = Gold;
    card->tags = { Mage };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, isUnit}, AnyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        transform(target, ArtefactCompression::JadeFigurine(), ally, enemy, card);
    };
    return card;
}


Kambi::Hemdall::Hemdall()
{
    auto *card = new Card();
    card->id = "152402";
    card->isDoomed = true;
    card->power = card->powerBase = 20;
    card->faction = Skellige;
    card->rarity = Gold;
    card->tags = {};

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        for (int screenRow = 0; screenRow < 6; ++screenRow)
            applyRowEffect(ally, enemy, screenRow, NoRowEffect);
        for (Card *card : cardsFiltered(ally, enemy, {}, AnyBoard))
            putToDiscard(card, ally, enemy, card);
    };
    return card;
}


Card *createVabjorn()
{
    auto *card = new Card();
    card->id = "200028";
    card->power = card->powerBase = 11;
    card->faction = Skellige;
    card->rarity = Gold;
    card->tags = { Cursed, Cultist };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (isDamaged(target))
            putToDiscard(target, ally, enemy, card);
        else
            damage(target, 2, ally, enemy, card);
    };
    return card;
}


Card *createBlueboyLugos()
{
    auto *card = new Card();
    card->id = "152201";
    card->power = card->powerBase = 9;
    card->faction = Skellige;
    card->rarity = Silver;
    card->tags = { ClanDrummond, Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        spawnNewCard(new SpectralWhale(), ally, enemy, card);
    };
    return card;
}


Card *createDjengeFrett()
{
    auto *card = new Card();
    card->id = "152203";
    card->power = card->powerBase = 10;
    card->faction = Skellige;
    card->rarity = Silver;
    card->tags = { Soldier, ClanDimun };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AllyBoard, 2);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        damage(target, 1, ally, enemy, card);
        strengthen(card, 2, ally, enemy, card);
    };
    return card;
}


Card *createDonarAnHindar()
{
    auto *card = new Card();
    card->id = "152204";
    card->power = card->powerBase = 8;
    card->faction = Skellige;
    card->rarity = Silver;
    card->tags = { ClanHeymaey, Officer };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronze, isUnit}, EnemyDiscard);
        startChoiceToTargetCard(ally, enemy, card);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (!isIn(target, enemy.discard)) {
            toggleLock(target, ally, enemy, card);
            return;
        }
        // FIXME: discard moving will crash
        putToDiscard(target, ally, enemy, card);
    };
    return card;
}


Card *createDraigBonDhu()
{
    auto *card = new Card();
    card->id = "152205";
    card->power = card->powerBase = 6;
    card->faction = Skellige;
    card->rarity = Silver;
    card->tags = { Support };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isNonLeader, isUnit}, AllyDiscard, 2);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        strengthen(target, 3, ally, enemy, card);
    };
    return card;
}


Card *createHolgerBlackhand()
{
    auto *card = new Card();
    card->id = "152207";
    card->power = card->powerBase = 6;
    card->faction = Skellige;
    card->rarity = Silver;
    card->tags = { ClanDimun, Officer };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (damage(target, 6, ally, enemy, card))
            if (Card *card = highest(ally.discard, ally.rng))
                strengthen(card, 3, ally, enemy, card);
    };
    return card;
}


Card *createJuttaAnDimun()
{
    auto *card = new Card();
    card->id = "152208";
    card->power = card->powerBase = 13;
    card->faction = Skellige;
    card->rarity = Silver;
    card->tags = { ClanDimun, Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        damage(card, 1, ally, enemy, card);
    };
    return card;
}


Card *createSavageBear()
{
    auto *card = new Card();
    card->id = "152210";
    card->power = card->powerBase = 9;
    card->faction = Skellige;
    card->rarity = Bronze;
    card->tags = { Beast, Cursed };

    card->_onOtherEnemyPlayedFromHand = [=](Card *other, Field &ally, Field &enemy) {
        if (isOnBoard(card, ally))
            damage(other, 1, ally, enemy, card);
    };
    return card;
}


Card *createSvanrigeTuirseach()
{
    auto *card = new Card();
    card->id = "152213";
    card->power = card->powerBase = 9;
    card->faction = Skellige;
    card->rarity = Silver;
    card->tags = { ClanTuirseach, Officer };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (drawACard(ally, enemy,  card))
            startChoiceToTargetCard(ally, enemy, card, {}, AllyHand);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        putToDiscard(target, ally, enemy, card);
    };
    return card;
}


Card *createSkjall()
{
    auto *card = new Card();
    card->id = "200212";
    card->power = card->powerBase = 5;
    card->faction = Skellige;
    card->rarity = Silver;
    card->tags = { ClanHeymaey, Cursed };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (Card *card = random(cardsFiltered(ally, enemy, {isUnit, isBronzeOrSilver, hasTag(Cursed)}, AllyDeck), ally.rng))
            playExistedCard(card, ally, enemy, card);
    };
    return card;
}


Card *createHaraldHoundsnout()
{
    auto *card = new Card();
    card->id = "200043";
    card->power = card->powerBase = 6;
    card->faction = Skellige;
    card->rarity = Silver;
    card->tags = { ClanTordarroch, Cursed };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        spawnNewUnitToPos(new Wilfred(), rowAndPosToTheLeft(card, ally, 1), ally, enemy, card);
        spawnNewUnitToPos(new Wilhelm(), rowAndPosToTheRight(card, ally, 1), ally, enemy, card);
        spawnNewUnitToPos(new Wilmar(), rowAndPosLastInExactRow(enemy, _findRowAndPos(card, ally).row()), enemy, ally, card);
    };
    return card;
}


HaraldHoundsnout::Wilfred::Wilfred()
{
    auto *card = new Card();
    card->power = card->powerBase = 1;
    card->faction = Skellige;
    card->rarity = Bronze;
    card->isDoomed = true;

    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &rowAndPos) {
        for (Card *card : enemy.row(rowAndPos.row()))
            damage(card, 1, ally, enemy, card);
    };
    return card;
}


HaraldHoundsnout::Wilhelm::Wilhelm()
{
    auto *card = new Card();
    card->power = card->powerBase = 1;
    card->faction = Skellige;
    card->rarity = Bronze;
    card->isDoomed = true;

    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
        if (Card *card = random(cardsFiltered(ally, enemy, {}, AllyBoard), ally.rng))
            strengthen(card, 3, ally, enemy, card);
    };
    return card;
}


HaraldHoundsnout::Wilmar::Wilmar()
{
    auto *card = new Card();
    card->power = card->powerBase = 1;
    card->faction = Skellige;
    card->rarity = Bronze;
    card->isDoomed = true;

    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
        spawnNewUnitToPos(new Bear(), rowAndPosRandom(enemy), ally, enemy, card);
    };
    return card;
}


Card *createYoana()
{
    auto *card = new Card();
    card->id = "201644";
    card->power = card->powerBase = 6;
    card->faction = Skellige;
    card->rarity = Silver;
    card->tags = { ClanTordarroch, Support };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isUnit, isDamaged}, AllyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        const int x = target->powerBase - target->power;
        heal(target, ally, enemy, card);
        boost(target, x, ally, enemy, card);
    };
    return card;
}


Card *createAnCraiteBlacksmith()
{
    auto *card = new Card();
    card->id = "152311";
    card->power = card->powerBase = 9;
    card->faction = Skellige;
    card->rarity = Bronze;
    card->tags = { ClanAnCraite, Support };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AllyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        strengthen(target, 2, ally, enemy, card);
        gainArmor(target, 2, ally, enemy, card);
    };
    return card;
}

Card *createAnCraiteWarcrier()
{
    auto *card = new Card();
    card->id = "113313";
    card->power = card->powerBase = 5;
    card->faction = Skellige;
    card->rarity = Bronze;
    card->tags = { ClanAnCraite, Support};

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AllyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        boost(target, int(std::floor(target->power / 2.0)), ally, enemy, card);
    };
    return card;
}

Card *createAnCraiteWarrior()
{
    auto *card = new Card();
    card->id = "152303";
    card->power = card->powerBase = 12;
    card->faction = Skellige;
    card->rarity = Bronze;
    card->tags = { ClanAnCraite, Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        damage(card, 1, ally, enemy, card);
    };
    return card;
}

Card *createBerserkerMarauder()
{
    auto *card = new Card();
    card->id = "152302";
    card->power = card->powerBase = 9;
    card->faction = Skellige;
    card->rarity = Bronze;
    card->tags = { Cursed, Soldier, Cultist };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        const auto isDamagedOrCursed = [=](Card *card) {
            return (card != card) && (isDamaged(card) || hasTag(card, Cursed));
        };
        const int nUnits = int(cardsFiltered(ally, enemy, {isDamagedOrCursed}, AllyBoard).size());
        if (nUnits)
            boost(card, nUnits, ally, enemy, card);
    };
    return card;
}

Card *createDimunPirateCaptain()
{
    auto *card = new Card();
    card->id = "152306";
    card->power = card->powerBase = 1;
    card->faction = Skellige;
    card->rarity = Bronze;
    card->tags = { ClanDimun, Officer };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronze, otherThan(name), hasTag(ClanDimun)}, AllyDeckShuffled);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}

Card *createDimunSmuggler()
{
    auto *card = new Card();
    card->id = "200146";
    card->power = card->powerBase = 10;
    card->faction = Skellige;
    card->rarity = Bronze;
    card->tags = { ClanDimun, Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronze, isUnit}, AllyDiscard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        putToDeck(target, ally, enemy, DeckPosRandom, card);
    };
    return card;
}

Card *createDrummondShieldmaid()
{
    auto *card = new Card();
    card->id = "152318";
    card->power = card->powerBase = 3;
    card->faction = Skellige;
    card->rarity = Bronze;
    card->tags = { ClanDrummond, Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *copy : cardsFiltered(ally, enemy, {isCopy(card->name)}, AllyDeck))
            moveExistedUnitToPos(copy, _findRowAndPos(card, ally), ally, enemy, card);
    };
    return card;
}

Card *createHeymaeyFlaminica()
{
    auto *card = new Card();
    card->id = "200147";
    card->power = card->powerBase = 10;
    card->faction = Skellige;
    card->rarity = Bronze;
    card->tags = { ClanHeymaey, Support };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        clearHazardsFromItsRow(card, ally);
        startChoiceToTargetCard(ally, enemy, card, {isOnAnotherRow(&ally, card)}, AllyBoard, 2);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        moveExistedUnitToPos(target, rowAndPosLastInTheSameRow(card, ally), ally, enemy, card);
    };
    return card;
}

Card *createHeymaeyHerbalist()
{
    auto *card = new Card();
    card->id = "200081";
    card->power = card->powerBase = 3;
    card->faction = Skellige;
    card->rarity = Bronze;
    card->tags = { ClanHeymaey, Support };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (Card *target = random(cardsFiltered(ally, enemy, {isBronze, hasAnyOfTags({Organic, Hazard})}, AllyDeck), ally.rng))
            playExistedCard(target, ally, enemy, card);
    };
    return card;
}

Card *createHeymaeyProtector()
{
    auto *card = new Card();
    card->id = "200149";
    card->power = card->powerBase = 2;
    card->faction = Skellige;
    card->rarity = Bronze;
    card->tags = { ClanHeymaey, Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronze, hasTag(Item)}, AllyDeck);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}

Card *createHeymaeySkald()
{
    auto *card = new Card();
    card->id = "152308";
    card->power = card->powerBase = 9;
    card->faction = Skellige;
    card->rarity = Bronze;
    card->tags = { ClanHeymaey, Support };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {hasAnyOfTags({ClanAnCraite, ClanDimun, ClanDrummond, ClanHeymaey, ClanTuirseach, ClanBrokvar, ClanTordarroch})}, AllyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        for (const Tag tag : std::vector<Tag>{ClanAnCraite, ClanDimun, ClanDrummond, ClanHeymaey, ClanTuirseach, ClanBrokvar, ClanTordarroch}) {
            if (!hasTag(target, tag))
                continue;
            for (Card *card : cardsFiltered(ally, enemy, {hasTag(tag), otherThan(card)}, AllyBoard))
                boost(card, 1, ally, enemy, card);
            break;
        }
    };
    return card;
}

Card *createRagingBerserker()
{
    auto *card = new Card();
    card->id = "152301";
    card->power = card->powerBase = 8;
    card->faction = Skellige;
    card->rarity = Bronze;
    card->tags = { Cursed, Soldier, Cultist };

    card->_onDamaged = [=](const int, Field &ally, Field &enemy, const Card *) {
        transform(card, RagingBear(), ally, enemy, card);
    };

    card->_onWeakened = [=](const int x, Field &ally, Field &enemy, const Card *src) {
        onDamaged(x, ally, enemy, src);
    };
    return card;
}

RagingBerserker::RagingBear::RagingBear()
{
    auto *card = new Card();
    card->id = "152405";
    card->power = card->powerBase = 12;
    card->faction = Skellige;
    card->rarity = Bronze;
    card->tags = { Cursed, Beast, Cultist };
    return card;
}

Card *createHym()
{
    auto *card = new Card();
    card->id = "200102";
    card->power = card->powerBase = 3;
    card->faction = Skellige;
    card->rarity = Gold;
    card->tags = { Cursed };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        auto *option1 = new Hym::Play;
        copyCardText(card, option1);
        option1->text = "Play a Bronze or Silver Cursed unit from your deck.";

        auto *option2 = new Hym::Create;
        copyCardText(card, option2);
        option2->text = "Create a Silver unit from your opponent's starting deck.";

        _choosen = nullptr;
        startChoiceToSelectOption(ally, enemy, card, {option1, option2});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {

        if (!_choosen && dynamic_cast<Hym::Play *>(target)) {
            _choosen = target;
            return startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, hasTag(Cursed)}, AllyDeckShuffled);
        }

        if (!_choosen && dynamic_cast<Hym::Create *>(target)) {
            _choosen = target;
            return startChoiceCreateOptions(ally, enemy, card, {isSilver, isUnit, isNonAgent}, EnemyDeckStarting);
        }

        if (dynamic_cast<Hym::Create *>(_choosen)) {
            spawnNewCard(target, ally, enemy, card);
            delete _choosen;
            _choosen = nullptr;
            return;
        }

        assert(false);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        assert(dynamic_cast<Hym::Play *>(_choosen));

        playExistedCard(target, ally, enemy, card);
        delete _choosen;
        _choosen = nullptr;
    };
    return card;
}

Card *createKambi()
{
    auto *card = new Card();
    card->id = "152104";
    card->isLoyal = false;
    card->power = card->powerBase = 1;
    card->faction = Skellige;
    card->rarity = Gold;
    card->tags = { };

    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
        spawnNewUnitToPos(new Hemdall(), rowAndPosRandom(ally), ally, enemy, card);
        // TODO: Check if Hemdall doesn't wipe a board!
    };
    return card;
}

Card *createOlaf()
{
    auto *card = new Card();
    card->id = "200103";
    card->power = card->powerBase = 20;
    card->faction = Skellige;
    card->rarity = Gold;
    card->tags = { Beast, Cursed };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        const int n = cardsFiltered(ally, enemy, {hasTag(Beast)}, AllyAppeared).size();
        const int x = std::max(0, 10 - 2 * n);
        damage(card, x, ally, enemy, card);
    };
    return card;
}

Card *createUlfhedinn()
{
    auto *card = new Card();
    card->id = "200104";
    card->power = card->powerBase = 6;
    card->faction = Skellige;
    card->rarity = Gold;
    card->tags = { Beast, Cursed };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        const std::vector<Card *> damaged = cardsFiltered(ally, enemy, {isDamaged}, EnemyBoard);
        const std::vector<Card *> other   = cardsFiltered(ally, enemy, {isUndamaged}, EnemyBoard);
        for (Card *card : other)
            damage(card, 1, ally, enemy, card);
        for (Card *card : damaged)
            damage(card, 2, ally, enemy, card);
    };
    return card;
}

Card *createWildBoarOfTheSea()
{
    auto *card = new Card();
    card->id = "152109";
    card->power = card->powerBase = 8;
    card->faction = Skellige;
    card->rarity = Gold;
    card->tags = { ClanAnCraite, Machine };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        gainArmor(card, 5, ally, enemy, card);
    };

    card->_onTurnEnd = [=](Field &ally, Field &enemy) {
        if (Card *left = cardNextTo(card, ally, enemy, -1)) {
            strengthen(left, 1, ally, enemy, card);
            if (Card *right = cardNextTo(card, ally, enemy, 1))
                damage(right, 1, ally, enemy, card);
        }
    };
    return card;
}

Card *createGiantBoar()
{
    auto *card = new Card();
    card->id = "201623";
    card->power = card->powerBase = 8;
    card->faction = Skellige;
    card->rarity = Silver;
    card->tags = { Beast };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (Card *card = random(cardsFiltered(ally, enemy, {otherThan(card)}, AllyBoard), ally.rng)) {
            putToDiscard(card, ally, enemy, card);
            boost(card, 10, ally, enemy, card);
        }
    };
    return card;
}

Card *createOrnamentalSword()
{
    auto *card = new Card();
    card->id = "201642";
    card->isSpecial = true;
    card->faction = Skellige;
    card->rarity = Silver;
    card->tags = { Item };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceCreateOptions(ally, enemy, card, {isBronzeOrSilver, isSkelligeFaction, hasTag(Soldier)});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        strengthen(target, 3, ally, enemy, card);
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}

BlueboyLugos::SpectralWhale::SpectralWhale()
{
    auto *card = new Card();
    card->id = "152403";
    card->isDoomed = true;
    card->power = card->powerBase = 3;
    card->faction = Skellige;
    card->rarity = Silver;
    card->tags = { Cursed };

    card->_onTurnEnd = [=](Field &ally, Field &enemy) {
        if (!isOnBoard(card, ally) || !moveToRandomRow(card, ally, enemy, card))
            return;
        for (Card *card : cardsFiltered(ally, enemy, {isOnSameRow(&ally, card)}, AllyBoard))
            damage(card, 1, ally, enemy, card);
    };
    return card;
}

Card *createDimunWarship()
{
    auto *card = new Card();
    card->id = "200105";
    card->power = card->powerBase = 7;
    card->faction = Skellige;
    card->rarity = Bronze;
    card->tags = { ClanDimun, Machine };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        /// break if killed already
        for (int n = 0; n < 4; ++n)
            if (damage(target, 1, ally, enemy, card))
                break;
    };
    return card;
}

Card *createTrissButterflies()
{
    auto *card = new Card();
    card->id = "122107";
    card->tags = { Mage, Temeria };
    card->power = card->powerBase = 8;
    card->faction = Neutral;
    card->rarity = Gold;

    card->_onTurnEnd = [=](Field &ally, Field &enemy) {
        if (!isOnBoard(card, ally))
            return;
        for (Card *card : lowests(cardsFiltered(ally, enemy, {}, AllyBoard)))
            boost(card, 1, ally, enemy, card);
    };
    return card;
}

Card *createYennefer()
{
    auto *card = new Card();
    card->id = "112108";
    card->tags = { Mage, Aedirn };
    card->power = card->powerBase = 6;
    card->faction = Neutral;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToSelectOption(ally, enemy, card, {new Unicorn(), new Chironex()});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}

Yennefer::Chironex::Chironex()
{
    auto *card = new Card();
    card->id = "112402";
    card->tags = { Cursed };
    card->isDoomed = true;
    card->power = card->powerBase = 4;
    card->faction = Neutral;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *card : cardsFiltered(ally, enemy, {}, AnyBoard))
            damage(card, 2, ally, enemy, card);
    };
    return card;
}


Yennefer::Unicorn::Unicorn()
{
    auto *card = new Card();
    card->id = "112401";
    card->tags = { Beast };
    card->isDoomed = true;
    card->power = card->powerBase = 1;
    card->faction = Neutral;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *card : cardsFiltered(ally, enemy, {}, AnyBoard))
            boost(card, 2, ally, enemy, card);
    };
    return card;
}

Card *createGermainPiquant()
{
    auto *card = new Card();
    card->id = "200523";
    card->tags = { Officer };
    card->power = card->powerBase = 10;
    card->faction = Neutral;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        spawnNewUnitToPos(new Cow(), rowAndPosToTheLeft(card, ally, 1), ally, enemy, card);
        spawnNewUnitToPos(new Cow(), rowAndPosToTheLeft(card, ally, 1), ally, enemy, card);
        spawnNewUnitToPos(new Cow(), rowAndPosToTheRight(card, ally, 1), ally, enemy, card);
        spawnNewUnitToPos(new Cow(), rowAndPosToTheRight(card, ally, 1), ally, enemy, card);
    };
    return card;
}


Card *createCommandersHorn()
{
    auto *card = new Card();
    card->id = "113207";
    card->tags = { Tactics };
    card->isSpecial = true;
    card->faction = Neutral;
    card->rarity = Silver;

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        const std::vector<Card *> cardsToBoost {
            cardNextTo(target, ally, enemy, -2),
                    cardNextTo(target, ally, enemy, -1),
                    target,
                    cardNextTo(target, ally, enemy, 1),
                    cardNextTo(target, ally, enemy, 2),
        };
        for (Card *card : cardsToBoost)
            if (card != nullptr)
                boost(card, 3, ally, enemy, card);
    };
    return card;
}


Card *createMarchingOrders()
{
    auto *card = new Card();
    card->id = "200019";
    card->tags = { Tactics };
    card->isSpecial = true;
    card->faction = Neutral;
    card->rarity = Silver;

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        Card *card = lowest(cardsFiltered(ally, enemy, {isBronzeOrSilver, isUnit}, AllyDeck), ally.rng);
        if (card != nullptr) {
            boost(card, 2, ally, enemy, card);
            playExistedCard(card, ally, enemy, card);
        }
    };
    return card;
}


Card *createAlzursDoubleCross()
{
    auto *card = new Card();
    card->id = "113209";
    card->tags = { Spell };
    card->isSpecial = true;
    card->faction = Neutral;
    card->rarity = Silver;

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        Card *card = highest(cardsFiltered(ally, enemy, {isBronzeOrSilver, isUnit}, AllyDeck), ally.rng);
        if (card != nullptr) {
            boost(card, 2, ally, enemy, card);
            playExistedCard(card, ally, enemy, card);
        }
    };
    return card;
}


Card *createAlbaArmoredCavalry()
{
    auto *card = new Card();
    card->id = "200296";
    card->tags = { Soldier };
    card->power = card->powerBase = 7;
    card->faction = Nilfgaard;
    card->rarity = Bronze;
    return card;
}


Card *createSentry()
{
    auto *card = new Card();
    card->id = "201661";
    card->tags = { Soldier };
    card->power = card->powerBase = 8;
    card->faction = Nilfgaard;
    card->rarity = Bronze;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {hasTag(Soldier), hasCopyOnABoard(&ally)}, AllyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        for (Card *card : cardsFiltered(ally, enemy, {isCopy(target->name), otherThan(card)}, AllyBoard))
            boost(card, 2, ally, enemy, card);
    };
    return card;
}


Card *createNauzicaaSergeant()
{
    auto *card = new Card();
    card->id = "162309";
    card->tags = { Officer };
    card->power = card->powerBase = 7;
    card->faction = Nilfgaard;
    card->rarity = Bronze;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        clearHazardsFromItsRow(card, ally);
        startChoiceToTargetCard(ally, enemy, card, {isUnit}, AllyBoardAndHandRevealed);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        boost(target, 3, ally, enemy, card);
    };
    return card;
}


Card *createSlaveInfantry()
{
    auto *card = new Card();
    card->id = "201610";
    card->tags = { Soldier };
    card->power = card->powerBase = 3;
    card->faction = Nilfgaard;
    card->rarity = Bronze;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        Row row;
        Pos pos;
        if (!_findRowAndPos(card, ally, row, pos))
            return;

        for (int _row = Meele; _row <= Seige; ++_row)
            if (_row != row) {
                Card *copy = defaultCopy();
                copy->isDoomed = true;
                summonNewUnitToPos(copy, rowAndPosLastInExactRow(ally, Row(_row)), ally, enemy, card);
            }
    };
    return card;
}


Card *createRecruit()
{
    auto *card = new Card();
    card->id = "201617";
    card->tags = { Soldier };
    card->power = card->powerBase = 1;
    card->faction = Nilfgaard;
    card->rarity = Bronze;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (Card *card = random(cardsFiltered(ally, enemy, {isBronze, hasTag(Soldier), otherThan(card->name)}, AllyDeckShuffled), ally.rng))
            playExistedCard(card, ally, enemy, card);
    };
    return card;
}


Card *createOintment()
{
    auto *card = new Card();
    card->id = "201619";
    card->tags = { Alchemy, Item };
    card->isSpecial = true;
    card->faction = Nilfgaard;
    card->rarity = Bronze;

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronze, isUnit, hasPowerXorLess(5)}, AllyDiscard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}


Card *createVilgefortz()
{
    auto *card = new Card();
    card->id = "162105";
    card->tags = { Mage };
    card->power = card->powerBase = 9;
    card->faction = Nilfgaard;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        const bool isTruce = !ally.passed && !enemy.passed;
        const ChoiceGroup choiceGroup = isTruce ? AnyBoard : AllyBoard;
        startChoiceToTargetCard(ally, enemy, card, {}, choiceGroup);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        const bool isAlly = isOnBoard(target, ally);
        putToDiscard(target, ally, enemy, card);
        if (isAlly) {
            if (Card *copy = first(ally.deck))
                playExistedCard(copy, ally, enemy, card);
        } else {
            if (Card *card = random(cardsFiltered(ally, enemy, {isBronze}, EnemyDeck), ally.rng)) {
                putToHand(card, enemy, ally,  card);
                reveal(card, ally, enemy, card);
            }
        }
    };
    return card;
}


Card *createVreemde()
{
    auto *card = new Card();
    card->id = "200050";
    card->tags = { Officer };
    card->power = card->powerBase = 4;
    card->faction = Nilfgaard;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceCreateOptions(ally, enemy, card, {isBronze, isNilfgaardFaction, hasTag(Soldier)});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}

GermainPiquant::Cow::Cow()
{
    auto *card = new Card();
    card->id = "201576";
    card->tags = { Beast };
    card->isDoomed = true;
    card->power = card->powerBase = 1;
    card->faction = Neutral;
    card->rarity = Bronze;
    return card;
}


Card *createAuckes()
{
    auto *card = new Card();
    card->id = "162208";
    card->tags = { Witcher };
    card->power = card->powerBase = 7;
    card->faction = Nilfgaard;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard, 2);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        toggleLock(target, ally, enemy, card);
    };
    return card;
}


Card *createEskel()
{
    auto *card = new Card();
    card->id = "112202";
    card->tags = { Witcher };
    card->power = card->powerBase = 6;
    card->faction = Neutral;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *lambert : cardsFiltered(ally, enemy, {isCopy<Lambert>}, AllyDeck))
            moveExistedUnitToPos(lambert, rowAndPosToTheLeft(card, ally, 1), ally, enemy, card);

        for (Card *vesemir : cardsFiltered(ally, enemy, {isCopy<Vesemir>}, AllyDeck))
            moveExistedUnitToPos(vesemir, rowAndPosToTheLeft(card, ally, 1), ally, enemy, card);
    };
    return card;
}


Card *createLambert()
{
    auto *card = new Card();
    card->id = "112204";
    card->tags = { Witcher };
    card->power = card->powerBase = 6;
    card->faction = Neutral;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *eskel : cardsFiltered(ally, enemy, {isCopy<Eskel>}, AllyDeck))
            moveExistedUnitToPos(eskel, rowAndPosToTheRight(card, ally, 1), ally, enemy, card);

        for (Card *vesemir : cardsFiltered(ally, enemy, {isCopy<Vesemir>}, AllyDeck))
            moveExistedUnitToPos(vesemir, rowAndPosToTheRight(card, ally, 1), ally, enemy, card);
    };
    return card;
}


Card *createVesemir()
{
    auto *card = new Card();
    card->id = "112203";
    card->tags = { Witcher };
    card->power = card->powerBase = 7;
    card->faction = Neutral;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *lambert : cardsFiltered(ally, enemy, {isCopy<Lambert>}, AllyDeck))
            moveExistedUnitToPos(lambert, rowAndPosToTheLeft(card, ally, 1), ally, enemy, card);

        for (Card *eskel : cardsFiltered(ally, enemy, {isCopy<Eskel>}, AllyDeck))
            moveExistedUnitToPos(eskel, rowAndPosToTheRight(card, ally, 1), ally, enemy, card);
    };
    return card;
}

Card *createTridamInfantry()
{
    auto *card = new Card();
    card->id = "200171";
    card->tags = { Soldier };
    card->power = card->powerBase = 10;
    card->faction = NothernRealms;
    card->rarity = Bronze;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        gainArmor(card, 4, ally, enemy, card);
    };
    return card;
}


Card *createVriheddDragoon()
{
    auto *card = new Card();
    card->id = "142205";
    card->tags = { Elf, Soldier };
    card->power = card->powerBase = 8;
    card->faction = Scoiatael;
    card->rarity = Bronze;

    card->_onTurnEnd = [=](Field &ally, Field &enemy) {
        if (!isOnBoard(card, ally))
            return;
        if (Card *card = random(cardsFiltered(ally, enemy, {isUnit, isNonSpying}, AllyHand), ally.rng))
            boost(card, 1, ally, enemy, card);
    };
    return card;
}


Card *createMalena()
{
    auto *card = new Card();
    card->id = "142210";
    card->power = card->powerBase = 7;
    card->isAmbush = true;
    card->rarity = Silver;
    card->faction = Scoiatael;
    card->tags = { Elf };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        isAmbush = true;
        setTimer(card, ally, enemy, 2);
    };

    card->_onTurnStart = [=](Field &ally, Field &enemy) {
        if (!isOnBoard(card, ally) || !tick(card, ally, enemy))
            return;
        flipOver(card, ally, enemy);
        if (Card *card = highest(cardsFiltered(ally, enemy, {isBronzeOrSilver, hasPowerXorLess(5)}, EnemyBoard), ally.rng))
            charm(card, ally, enemy, card);
    };
    return card;
}


Card *createUnseenElder()
{
    auto *card = new Card();
    card->id = "200055";
    card->power = card->powerBase = 5;
    card->rarity = Gold;
    card->faction = Monster;
    card->tags = { Vampire, Leader };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        drain(target, half(target->power), ally, enemy, card);
    };
    return card;
}


Card *createDevanaRunestone()
{
    auto *card = new Card();
    card->id = "201584";
    card->isSpecial = true;
    card->rarity = Silver;
    card->faction = Monster;
    card->tags = { Alchemy, Item };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceCreateOptions(ally, enemy, card, {isBronzeOrSilver, isMonsterFaction});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}


Card *createDazhbogRunestone()
{
    auto *card = new Card();
    card->id = "201583";
    card->isSpecial = true;
    card->rarity = Silver;
    card->faction = Nilfgaard;
    card->tags = { Alchemy, Item };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceCreateOptions(ally, enemy, card, {isBronzeOrSilver, isNilfgaardFaction});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}


Card *createMoranaRunestone()
{
    auto *card = new Card();
    card->id = "201585";
    card->isSpecial = true;
    card->rarity = Silver;
    card->faction = Scoiatael;
    card->tags = { Alchemy, Item };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceCreateOptions(ally, enemy, card, {isBronzeOrSilver, isScoiataelFaction});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}


Card *createStribogRunestone()
{
    auto *card = new Card();
    card->id = "201581";
    card->isSpecial = true;
    card->rarity = Silver;
    card->faction = Skellige;
    card->tags = { Alchemy, Item };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceCreateOptions(ally, enemy, card, {isBronzeOrSilver, isSkelligeFaction});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}


Card *createMuzzle()
{
    auto *card = new Card();
    card->id = "200225";
    card->isSpecial = true;
    card->rarity = Gold;
    card->faction = Neutral;
    card->tags = { Item };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, hasPowerXorLess(8)}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        charm(target, ally, enemy, card);
    };
    return card;
}


Card *createRockBarrage()
{
    auto *card = new Card();
    card->id = "201647";
    card->isSpecial = true;
    card->rarity = Bronze;
    card->faction = Neutral;
    card->tags = {};

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        const RowAndPos rowAndPos = _findRowAndPos(target, enemy);
        const Row rowAbove = std::min(Row(rowAndPos.row() + 1), Seige);

        const bool shouldDestroy = isRowFull(enemy.row(rowAbove));
        if (shouldDestroy) {
            putToDiscard(target, ally, enemy, card);
            return;
        }

        if (!damage(target, 7, ally, enemy, card) && (rowAndPos.row() != Seige))
            moveExistedUnitToPos(target, rowAndPosLastInExactRow(enemy, rowAbove), enemy, ally, card);
    };
    return card;
}


Card *createWhisperingHillock()
{
    auto *card = new Card();
    card->id = "201587";
    card->power = card->powerBase = 6;
    card->rarity = Gold;
    card->faction = Monster;
    card->tags = { Leader, Relict };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceCreateOptions(ally, enemy, card, {isBronzeOrSilver, hasTag(Organic)});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}

Card *createBrewess()
{
    auto *card = new Card();
    card->id = "132207";
    card->tags = { Mage, Relict };
    card->power = card->powerBase = 8;
    card->faction = Monster;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *weavess: cardsFiltered(ally, enemy, {isCopy<Weavess>}, AllyDeck))
            moveExistedUnitToPos(weavess, rowAndPosToTheRight(card, ally, 1), ally, enemy, card);

        for (Card *whispess : cardsFiltered(ally, enemy, {isCopy<Whispess>}, AllyDeck))
            moveExistedUnitToPos(whispess, rowAndPosToTheLeft(card, ally, 1), ally, enemy, card);
    };
    return card;
}

Card *createWeavess()
{
    auto *card = new Card();
    card->id = "132208";
    card->tags = { Mage, Relict };
    card->power = card->powerBase = 6;
    card->faction = Monster;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *whispess : cardsFiltered(ally, enemy, {isCopy<Whispess>}, AllyDeck))
            moveExistedUnitToPos(whispess, rowAndPosToTheLeft(card, ally, 1), ally, enemy, card);

        for (Card *brewess: cardsFiltered(ally, enemy, {isCopy<Brewess>}, AllyDeck))
            moveExistedUnitToPos(brewess, rowAndPosToTheLeft(card, ally, 1), ally, enemy, card);
    };
    return card;
}


Card *createWhispess()
{
    auto *card = new Card();
    card->id = "132206";
    card->tags = { Mage, Relict };
    card->power = card->powerBase = 6;
    card->faction = Monster;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *weavess: cardsFiltered(ally, enemy, {isCopy<Weavess>}, AllyDeck))
            moveExistedUnitToPos(weavess, rowAndPosToTheRight(card, ally, 1), ally, enemy, card);

        for (Card *brewess: cardsFiltered(ally, enemy, {isCopy<Brewess>}, AllyDeck))
            moveExistedUnitToPos(brewess, rowAndPosToTheRight(card, ally, 1), ally, enemy, card);
    };
    return card;
}

Card *createWeavessIncantation()
{
    auto *card = new Card();
    card->id = "200222";
    card->tags = { Mage, Relict };
    card->power = card->powerBase = 4;
    card->faction = Monster;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        auto *option1 = new WeavessIncantation::StrengthenAll;
        copyCardText(card, option1);
        option1->text = "Strengthen all your other Relicts in hand, deck, and on board by 2.";

        auto *option2 = new WeavessIncantation::PlayAndStrengthen;
        copyCardText(card, option2);
        option2->text = "Play a Bronze or Silver Relict from your deck and Strengthen it by 2.";

        startChoiceToSelectOption(ally, enemy, card, {option1, option2});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (dynamic_cast<WeavessIncantation::StrengthenAll *>(target)) {
            for (Card *card : cardsFiltered(ally, enemy, {hasTag(Relict), otherThan(card)}, AllyBoardHandDeck))
                strengthen(card, 2, ally, enemy, card);
            return;
        }

        if (dynamic_cast<WeavessIncantation::PlayAndStrengthen *>(target)) {
            startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, hasTag(Relict)}, AllyDeckShuffled);
            return;
        }

        assert(false);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        strengthen(target, 2, ally, enemy, card);
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}

Card *createBrewessRitual()
{
    auto *card = new Card();
    card->id = "200221";
    card->tags = { Mage, Relict };
    card->power = card->powerBase = 1;
    card->faction = Monster;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isDeathwish, isBronze, isUnit}, AllyDiscard, 2);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}

Card *createWhispessTribute()
{
    auto *card = new Card();
    card->id = "200220";
    card->tags = { Mage, Relict };
    card->power = card->powerBase = 6;
    card->faction = Monster;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, hasTag(Organic)}, AllyDeckShuffled);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}

Card *createNivellen()
{
    auto *card = new Card();
    card->id = "200089";
    card->power = card->powerBase = 10;
    card->rarity = Silver;
    card->faction = Neutral;
    card->tags = { Cursed };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToSelectRow(ally, enemy, card);
    };

    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
        for (Card *card : cardsInRow(ally, enemy, screenRow)) {
            if (isOnBoard(card, ally)) {
                moveToRandomRow(card, ally, enemy, card);
            } else {
                moveToRandomRow(card, enemy, ally, card);
            }
        }
    };
    return card;
}



Card *createLeoBonhart()
{
    auto *card = new Card();
    card->id = "200031";
    card->power = card->powerBase = 7;
    card->rarity = Gold;
    card->faction = Nilfgaard;
    card->tags = { Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isNonRevealed, isUnit}, AllyHand);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (_revealed == nullptr) {
            _revealed = target;
            reveal(target, ally, enemy, card);
            startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
            return;
        }
        damage(target, _revealed->powerBase, ally, enemy, card);
    };
    return card;
}



Card *createMorvranVoorhis()
{
    auto *card = new Card();
    card->id = "200163";
    card->power = card->powerBase = 7;
    card->rarity = Gold;
    card->faction = Nilfgaard;
    card->tags = { Officer, Leader };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isNonRevealed}, AnyHandShuffled, 4, true);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        reveal(target, ally, enemy, card);
    };
    return card;
}



Card *createCynthia()
{
    auto *card = new Card();
    card->id = "162203";
    card->power = card->powerBase = 5;
    card->rarity = Silver;
    card->faction = Nilfgaard;
    card->tags = { Mage };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (Card *card = highest(cardsFiltered(ally, enemy, {isUnit, isNonRevealed}, EnemyHand), ally.rng)) {
            reveal(card, ally, enemy, card);
            boost(card, card->power, ally, enemy, card);
        }
    };
    return card;
}


Card *createSerrit()
{
    auto *card = new Card();
    card->id = "162209";
    card->power = card->powerBase = 6;
    card->rarity = Silver;
    card->faction = Nilfgaard;
    card->tags = { Witcher };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isUnit}, EnemyBoardAndHandRevealed);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        const int x = isOnBoard(target, enemy) ? 7 : (target->power - 1);
        damage(target, x, ally, enemy, card);
    };
    return card;
}


Card *createSweers()
{
    auto *card = new Card();
    card->id = "162206";
    card->power = card->powerBase = 9;
    card->rarity = Silver;
    card->faction = Nilfgaard;
    card->tags = { Officer };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isUnit, hasCopyInADeck(&enemy)}, EnemyBoardAndHandRevealed);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        for (Card *copy : findCopies(target, enemy.deck))
            putToDiscard(copy, ally, enemy, card);
    };
    return card;
}


Card *createTiborEggebracht()
{
    auto *card = new Card();
    card->id = "162107";
    card->power = card->powerBase = 10;
    card->rarity = Gold;
    card->faction = Nilfgaard;
    card->tags = { Officer };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (ally.passed || enemy.passed)
            return;
        if (Card *card = random(cardsFiltered(ally, enemy, {isBronze}, EnemyDeck), ally.rng)) {
            putToHand(card, enemy, ally,  card);
            reveal(card, ally, enemy, card);
        }
    };
    return card;
}

Card *createVattierDeRideaux()
{
    auto *card = new Card();
    card->id = "162103";
    card->power = card->powerBase = 10;
    card->rarity = Gold;
    card->faction = Nilfgaard;
    card->tags = { Officer };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isNonRevealed}, AllyHand, 2, true);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        reveal(target, ally, enemy, card);
        if (Card *card = random(cardsFiltered(ally, enemy, {isNonRevealed}, EnemyHand), ally.rng))
            reveal(card, ally, enemy, card);
    };
    return card;
}

Card *createAlbrich()
{
    auto *card = new Card();
    card->id = "162201";
    card->power = card->powerBase = 10;
    card->rarity = Silver;
    card->faction = Nilfgaard;
    card->tags = { Mage };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (ally.passed || enemy.passed)
            return;
        drawACard(ally, enemy,  card);
        if (Card *card = first(enemy.deck)) {
            putToHand(card, ally, enemy,  card);
            reveal(card, ally, enemy, card);
        }
    };
    return card;
}

Card *createHeftyHelge()
{
    auto *card = new Card();
    card->id = "200041";
    card->power = card->powerBase = 8;
    card->rarity = Silver;
    card->faction = Nilfgaard;
    card->tags = { Machine };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        const Filters filters = isRevealed ? Filters{} : Filters{isOnAnotherRow(&ally, &enemy, card)};
        for (Card *card : cardsFiltered(ally, enemy, filters, EnemyBoard))
            damage(card, 1, ally, enemy, card);
    };
    return card;
}

Card *createAlchemist()
{
    auto *card = new Card();
    card->id = "162316";
    card->power = card->powerBase = 9;
    card->rarity = Bronze;
    card->faction = Nilfgaard;
    card->tags = { Mage };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isNonRevealed}, AnyHandShuffled, 2, true);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        reveal(target, ally, enemy, card);
    };
    return card;
}

Card *createDaerlanSoldier()
{
    auto *card = new Card();
    card->id = "162301";
    card->power = card->powerBase = 4;
    card->rarity = Bronze;
    card->faction = Nilfgaard;
    card->tags = { Soldier };

    card->_onRevealed = [=](Field &ally, Field &enemy, const Card *src) {
        /// reveal is possible only by units on a board
        /// check if revealed by an you
        if (!isOnBoard(src, ally))
            return;
        /// don't jump and draw a card, if no place on a field
        if (moveExistedUnitToPos(card, rowAndPosRandom(ally), ally, enemy, card))
            drawACard(ally, enemy,  card);
    };
    return card;
}

Card *createFireScorpion()
{
    auto *card = new Card();
    card->id = "162306";
    card->power = card->powerBase = 5;
    card->rarity = Bronze;
    card->faction = Nilfgaard;
    card->tags = { Machine };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        damage(target, 5, ally, enemy, card);
    };
    card->_onRevealed = [=](Field &ally, Field &enemy, const Card *src) {
        if (isOnBoard(src, ally))
            onDeploy(ally, enemy);
    };
    return card;
}

Card *createWildHuntHound()
{
    auto *card = new Card();
    card->id = "132402";
    card->power = card->powerBase = 4;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { WildHunt, Construct };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (Card *card = random(cardsFiltered(ally, enemy, {isCopy("Biting Frost")}, AllyDeck), ally.rng))
            playExistedCard(card, ally, enemy, card);
    };
    return card;
}

Card *createWildHuntWarrior()
{
    auto *card = new Card();
    card->id = "132309";
    card->power = card->powerBase = 7;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { WildHunt, Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        const bool isUnderFrost = rowEffectUnderUnit(target, enemy) == BitingFrostEffect;
        if (damage(target, 3, ally, enemy, card) || isUnderFrost)
            boost(card, 2, ally, enemy, card);
    };
    return card;
}


Card *createMangonel()
{
    auto *card = new Card();
    card->id = "162317";
    card->power = card->powerBase = 7;
    card->rarity = Bronze;
    card->faction = Nilfgaard;
    card->tags = { Machine };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (Card *card = random(cardsFiltered(ally, enemy, {}, EnemyBoard), ally.rng))
            damage(card, 2, ally, enemy, card);
    };

    card->_onOtherRevealed = [=](Field &ally, Field &enemy, Card *, const Card *) {
        if (isOnBoard(card, ally))
            onDeploy(ally, enemy);
    };
    return card;
}

Card *createNilfgaardianKnight()
{
    auto *card = new Card();
    card->id = "162318";
    card->power = card->powerBase = 12;
    card->rarity = Bronze;
    card->faction = Nilfgaard;
    card->tags = { Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        gainArmor(card, 2, ally, enemy, card);

        for (const Filter &filter : Filters{isBronze, isSilver, isGold})
            if (Card *card = random(cardsFiltered(ally, enemy, {filter, isNonRevealed}, AllyHand), ally.rng)) {
                reveal(card, ally, enemy, card);
                break;
            }
    };
    return card;
}

Card *createSpotter()
{
    auto *card = new Card();
    card->id = "162303";
    card->power = card->powerBase = 5;
    card->rarity = Bronze;
    card->faction = Nilfgaard;
    card->tags = { Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isUnit, isBronzeOrSilver, ::isRevealed}, AnyHandShuffled);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        boost(card, target->powerBase, ally, enemy, card);
    };
    return card;
}

Card *createVenendalElite()
{
    auto *card = new Card();
    card->id = "200518";
    card->power = card->powerBase = 1;
    card->rarity = Bronze;
    card->faction = Nilfgaard;
    card->tags = { Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isUnit, ::isRevealed}, AnyHandShuffled);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        const int powerTarget = target->power;
        // TODO: check if triggered onDamaged and onDamaged of other units,
        // because it shouldn't
        setPower(target, power, ally, enemy, card);
        setPower(card, powerTarget, ally, enemy, card);
    };
    return card;
}

Card *createMasterOfDisguise()
{
    auto *card = new Card();
    card->id = "201616";
    card->power = card->powerBase = 11;
    card->rarity = Bronze;
    card->faction = Nilfgaard;
    card->tags = { Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {::isRevealed}, AnyHandShuffled, 2);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        conceal(target, ally, enemy, card);
    };
    return card;
}

Card *createHenryVarAttre()
{
    auto *card = new Card();
    card->id = "200227";
    card->power = card->powerBase = 9;
    card->rarity = Silver;
    card->faction = Nilfgaard;
    card->tags = { Support };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        const Filters filters {::isRevealed, isUnit};
        const int nRevealed = int(cardsFiltered(ally, enemy, filters, AnyHandShuffled).size());
        if (nRevealed)
            startChoiceToTargetCard(ally, enemy, card, filters, AnyHandShuffled, nRevealed);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (isIn(target, ally.hand)) {
            boost(target, 2, ally, enemy, card);
            conceal(target, ally, enemy, card);
            return;
        }
        damage(target, 2, ally, enemy, card);
        conceal(target, ally, enemy, card);
    };
    return card;
}

Card *createSummoningCircle()
{
    auto *card = new Card();
    card->id = "200022";
    card->isSpecial = true;
    card->rarity = Silver;
    card->faction = Neutral;
    card->tags = { Spell };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        if (Card *card = last(cardsFiltered(ally, enemy, {isUnit, isBronzeOrSilver, isNonAgent, otherThan(card)}, BothAppeared)))
            spawnNewCard(card->defaultCopy(), ally, enemy, card);
    };
    return card;
}

Card *createXavierMoran()
{
    auto *card = new Card();
    card->id = "200080";
    card->power = card->powerBase = 10;
    card->rarity = Gold;
    card->faction = Scoiatael;
    card->tags = { Dwarf };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (Card *card = last(cardsFiltered(ally, enemy, {hasTag(Dwarf), otherThan(card)}, AllyAppeared)))
            boost(card, card->powerBase, ally, enemy, card);
    };
    return card;
}

Card *createYenneferEnchantress()
{
    auto *card = new Card();
    card->id = "201601";
    card->tags = { Mage, Aedirn };
    card->power = card->powerBase = 5;
    card->faction = Nilfgaard;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (Card *card = last(cardsFiltered(ally, enemy, {hasTag(Spell), isBronzeOrSilver}, AllyAppeared)))
            spawnNewCard(card->defaultCopy(), ally, enemy, card);
    };
    return card;
}

Card *createVernonRoche()
{
    auto *card = new Card();
    card->id = "122102";
    card->tags = { Temeria, Officer };
    card->power = card->powerBase = 3;
    card->faction = NothernRealms;
    card->rarity = Gold;

    card->_onGameStart = [=](Field &ally, Field &enemy) {
        Card *card = new BlueStripeCommando();
        addAsNew(ally, card);
        putToDeck(card, ally, enemy, DeckPosRandom, card);
    };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *card, Field &ally, Field &enemy) {
        damage(card, 7, ally, enemy, card);
    };
    return card;
}

Card *createBlueStripeScout()
{
    auto *card = new Card();
    card->id = "122310";
    card->tags = { Temeria, Soldier };
    card->power = card->powerBase = 3;
    card->isCrew = true;
    card->faction = NothernRealms;
    card->rarity = Bronze;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *card : cardsFiltered(ally, enemy, {hasTag(Temeria), isNonSpying, hasPowerX(power)}, AllyBoardHandDeck))
            boost(card, 1, ally, enemy, card);
    };
    return card;
}

Card *createBlueStripeCommando()
{
    auto *card = new Card();
    card->id = "122311";
    card->tags = { Temeria, Soldier };
    card->power = card->powerBase = 3;
    card->faction = NothernRealms;
    card->rarity = Bronze;

    card->_onOtherAllyPlayedFromHand = [=](Card *target, Field &ally, Field &enemy) {
        if (!hasTag(Temeria) || !hasPowerX(power) || !isIn(card, ally.deck))
            return;

        for (Card *card : cardsFiltered(ally, enemy, {isCopy<BlueStripeCommando>, otherThan(card)}, AllyDeckShuffled)) {
            BlueStripeCommando *commando = static_cast<BlueStripeCommando *>(card);
            commando->_allyPlayedToCopy.insert({target, card});
        }

        if (_allyPlayedToCopy.find(target) == _allyPlayedToCopy.end())
            moveExistedUnitToPos(card, rowAndPosRandom(ally), ally, enemy, card);

        _allyPlayedToCopy.clear();
    };
    return card;
}

Card *createImperialGolem()
{
    auto *card = new Card();
    card->id = "132407";
    card->tags = { Construct };
    card->power = card->powerBase = 3;
    card->faction = Nilfgaard;
    card->rarity = Bronze;

    card->_onOtherRevealed = [=](Field &ally, Field &enemy, Card *target, const Card *) {
        if (!isIn(card, ally.deck) || !isIn(target, enemy.hand))
            return;

        for (Card *card : cardsFiltered(ally, enemy, {isCopy<ImperialGolem>, otherThan(card)}, AllyDeckShuffled)) {
            ImperialGolem *golem = static_cast<ImperialGolem *>(card);
            golem->_cardRevealedToCopy.insert({target, card});
        }

        if (_cardRevealedToCopy.find(target) == _cardRevealedToCopy.end())
            moveExistedUnitToPos(card, rowAndPosRandom(ally), ally, enemy, card);

        _cardRevealedToCopy.clear();
    };
    return card;
}

Card *createWildHuntNavigator()
{
    auto *card = new Card();
    card->id = "200026";
    card->power = card->powerBase = 3;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { WildHunt, Mage };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronze, hasTag(WildHunt), hasNoTag(Mage), hasCopyInADeck(&ally)}, AllyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (Card *copy = findCopy(target, ally.deck))
            playExistedCard(copy, ally, enemy, card);
    };
    return card;
}

Card *createNithral()
{
    auto *card = new Card();
    card->id = "132214";
    card->power = card->powerBase = 6;
    card->rarity = Silver;
    card->faction = Monster;
    card->tags = { WildHunt, Officer };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        const int nWildHuntUnits = cardsFiltered(ally, enemy, {hasTag(WildHunt), isUnit}, AllyHand).size();
        damage(target, 6 + nWildHuntUnits, ally, enemy, card);
    };
    return card;
}

Card *createMiruna()
{
    auto *card = new Card();
    card->id = "132108";
    card->power = card->powerBase = 4;
    card->rarity = Gold;
    card->faction = Monster;
    card->tags = { Beast };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        setTimer(card, ally, enemy, 2);
    };

    card->_onTurnStart = [=](Field &ally, Field &enemy) {
        if (!isOnBoard(card, ally) || !tick(card, ally, enemy))
            return;
        if (Card *card = highest(cardsFiltered(ally, enemy, {isOnOppositeRow(&ally, &enemy, card)}, EnemyBoard), ally.rng))
            charm(card, ally, enemy, card);
    };
    return card;
}

Card *createImlerith()
{
    auto *card = new Card();
    card->id = "132102";
    card->power = card->powerBase = 9;
    card->rarity = Gold;
    card->faction = Monster;
    card->tags = { WildHunt, Officer };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        const bool isUnderFrost = rowEffectUnderUnit(target, enemy) == BitingFrostEffect;
        damage(target, isUnderFrost ? 8 : 4, ally, enemy, card);
    };
    return card;
}

Card *createCaretaker()
{
    auto *card = new Card();
    card->id = "132106";
    card->power = card->powerBase = 4;
    card->rarity = Gold;
    card->faction = Monster;
    card->isDoomed = true;
    card->tags = { Relict };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isUnit, isBronzeOrSilver}, EnemyDiscard);
    };
    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}

Card *createRuehin()
{
    auto *card = new Card();
    card->id = "201660";
    card->power = card->powerBase = 8;
    card->rarity = Silver;
    card->faction = Monster;
    card->tags = { Insectoid, Cursed };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *card : cardsFiltered(ally, enemy, {hasAnyOfTags({Insectoid, Cursed}), otherThan(card), isUnit}, AllyBoardHandDeck))
            strengthen(card, 1, ally, enemy, card);
    };
    return card;
}

Card *createOldSpeartipAsleep()
{
    auto *card = new Card();
    card->id = "132218";
    card->power = card->powerBase = 12;
    card->rarity = Gold;
    card->faction = Monster;
    card->tags = { Ogroid };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *card : cardsFiltered(ally, enemy, {hasTag(Ogroid), otherThan(card), isUnit}, AllyBoardHandDeck))
            strengthen(card, 1, ally, enemy, card);
    };
    return card;
}

Card *createOldSpeartip()
{
    auto *card = new Card();
    card->id = "132408";
    card->power = card->powerBase = 10;
    card->rarity = Gold;
    card->faction = Monster;
    card->tags = { Ogroid };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        for(Card *card : randoms(cardsFiltered(ally, enemy, {isOnOppositeRow(&ally, &enemy, card)}, EnemyBoard), 5, ally.rng))
            damage(card, 2, ally, enemy, card);
    };
    return card;
}

Card *createGolyat()
{
    auto *card = new Card();
    card->id = "200052";
    card->power = card->powerBase = 10;
    card->rarity = Silver;
    card->faction = Monster;
    card->tags = { Ogroid };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        boost(card, 7, ally, enemy, card);
    };

    card->_onDamaged = [=](const int, Field &ally, Field &enemy, const Card *src) {
        if (src != card)
            damage(card, 2, ally, enemy, card);
    };
    return card;
}

Card *createBarbegazi()
{
    auto *card = new Card();
    card->id = "201701";
    card->power = card->powerBase = 6;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Insectoid };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        isResilient = true;
        startChoiceToTargetCard(ally, enemy, card, {}, AllyBoard);
    };

    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
        boost(card, consume(target, ally, enemy, card), ally, enemy, card);
    };
    return card;
}

Card *createGhoul()
{
    auto *card = new Card();
    card->id = "132306";
    card->power = card->powerBase = 4;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Necrophage };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, isUnit}, AllyDiscard);
    };

    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
        boost(card, consume(target, ally, enemy, card), ally, enemy, card);
    };
    return card;
}

Card *createForktail()
{
    auto *card = new Card();
    card->id = "201606";
    card->power = card->powerBase = 8;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Draconid };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AllyBoard, 2);
    };

    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
        boost(card, consume(target, ally, enemy, card), ally, enemy, card);
    };
    return card;
}

Card *createArachasQueen()
{
    auto *card = new Card();
    card->id = "201743";
    card->power = card->powerBase = 7;
    card->rarity = Gold;
    card->faction = Monster;
    card->tags = { Leader, Insectoid };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        isImmune = true;
        startChoiceToTargetCard(ally, enemy, card, {}, AllyBoard, 3);
    };

    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
        boost(card, consume(target, ally, enemy, card), ally, enemy, card);
    };
    return card;
}

Card *createOzzrel()
{
    auto *card = new Card();
    card->id = "201698";
    card->power = card->powerBase = 5;
    card->rarity = Silver;
    card->faction = Monster;
    card->tags = { Necrophage };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, isUnit}, BothDiscard);
    };

    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
        boost(card, consume(target, ally, enemy, card), ally, enemy, card);
    };
    return card;
}

Card *createKayran()
{
    auto *card = new Card();
    card->id = "132107";
    card->power = card->powerBase = 5;
    card->rarity = Gold;
    card->faction = Monster;
    card->tags = { Insectoid };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {hasPowerXorLess(7)}, AnyBoard);
    };

    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
        boost(card, consume(target, ally, enemy, card), ally, enemy, card);
    };
    return card;
}

Card *createMourntart()
{
    auto *card = new Card();
    card->id = "132202";
    card->power = card->powerBase = 4;
    card->rarity = Silver;
    card->faction = Monster;
    card->tags = { Necrophage };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        const std::vector<Card *> cards = cardsFiltered(ally, enemy, {isBronzeOrSilver, isUnit}, AllyDiscard);

        for (Card *card : cards)
            consume(card, ally, enemy, card);

        boost(card, cards.size(), ally, enemy, card);
    };
    return card;
}

Card *createToadPrince()
{
    auto *card = new Card();
    card->id = "132216";
    card->power = card->powerBase = 6;
    card->rarity = Silver;
    card->faction = Monster;
    card->tags = { Cursed };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (Card *unit = first(cardsFiltered(ally, enemy, {isUnit}, AllyDeck))) {
            putToHand(unit, ally, enemy,  card);
            startChoiceToTargetCard(ally, enemy, card, {isUnit}, AllyHand);
        }
    };

    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
        boost(card, consume(target, ally, enemy, card), ally, enemy, card);
    };
    return card;
}

Card *createFiend()
{
    auto *card = new Card();
    card->id = "112405";
    card->power = card->powerBase = 11;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Relict };
    return card;
}

Card *createMorvudd()
{
    auto *card = new Card();
    card->id = "112405";
    card->power = card->powerBase = 6;
    card->rarity = Silver;
    card->faction = Monster;
    card->tags = { Relict };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
    };

    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
        toggleLock(target, ally, enemy, card);
        if (isOnBoard(target, enemy))
            setPower(target, target->power - half(target->power), ally, enemy, card);
    };
    return card;
}

Card *createEkimmara()
{
    auto *card = new Card();
    card->id = "132313";
    card->power = card->powerBase = 5;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Vampire };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        drain(target, 3, ally, enemy, card);
    };
    return card;
}

Card *createRotfiend()
{
    auto *card = new Card();
    card->id = "200295";
    card->power = card->powerBase = 8;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Necrophage };

    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
        for(Card *target : cardsFiltered(ally, enemy, {isOnOppositeRow(&ally, &enemy, card)}, EnemyBoard))
            damage(target, 2, ally, enemy, card);
    };
    return card;
}

Card *createArchespore()
{
    auto *card = new Card();
    card->id = "200038";
    card->power = card->powerBase = 7;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Cursed };

    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
        damage(random(cardsFiltered(ally, enemy, {}, EnemyBoard), ally.rng),
               4, ally, enemy, card);
    };

    card->_onTurnStart = [=](Field &ally, Field &enemy) {
        if (isOnBoard(card, ally) && moveToRandomRow(card, ally, enemy, card))
            damage(random(cardsFiltered(ally, enemy, {}, EnemyBoard), ally.rng),
                   1, ally, enemy, card);
    };
    return card;
}

Card *createCyclops()
{
    auto *card = new Card();
    card->id = "200037";
    card->power = card->powerBase = 11;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Ogroid };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AllyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if(!_powerOfDestroyed) {
            _powerOfDestroyed = target->power;
            putToDiscard(target, ally, enemy, card);
            startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
            return;
        }
        damage(target, _powerOfDestroyed, ally, enemy, card);
        _powerOfDestroyed = 0;
    };
    return card;
}

Card *createMaerolorn()
{
    auto *card = new Card();
    card->id = "132406";
    card->power = card->powerBase = 4;
    card->rarity = Silver;
    card->faction = Monster;
    card->tags = { Relict };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronze, isDeathwish}, AllyDeckShuffled);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}

Card *createMonsterNest()
{
    auto *card = new Card();
    card->id = "133302";
    card->isSpecial = true;
    card->rarity = Silver;
    card->faction = Monster;
    card->tags = { Organic };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceCreateOptions(ally, enemy, card, {isBronze, hasAnyOfTags({Necrophage, Insectoid})}, AnyCard, -1);
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        boost(target, 1, ally, enemy, card);
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}

Card *createArachasDrone()
{
    auto *card = new Card();
    card->id = "132304";
    card->power = card->powerBase = 3;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Insectoid };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *copy : cardsFiltered(ally, enemy, {isCopy(card->name)}, AllyDeck))
            moveExistedUnitToPos(copy, rowAndPosToTheRight(card, ally, 1), ally, enemy, card);
    };
    return card;
}

Card *createAlphaWerewolf()
{
    auto *card = new Card();
    card->id = "200114";
    card->power = card->powerBase = 10;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Beast, Cursed };

    card->_onContactWithFullMoon = [=](Field &ally, Field &enemy) {
        spawnNewUnitToPos(new Wolf(), rowAndPosToTheLeft(card, ally, 1), ally, enemy, card);
        spawnNewUnitToPos(new Wolf(), rowAndPosToTheRight(card, ally, 1), ally, enemy, card);
    };
    return card;
}

Card *createWerewolf()
{
    auto *card = new Card();
    card->id = "201600";
    card->power = card->powerBase = 7;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Beast, Cursed };
    card->isImmune = true;

    card->_onContactWithFullMoon = [=](Field &ally, Field &enemy) {
        boost(card, 7, ally, enemy, card);
    };
    return card;
}

Card *createEredinBreaccGlas()
{
    auto *card = new Card();
    card->id = "131101";
    card->power = card->powerBase = 5;
    card->rarity = Gold;
    card->faction = Monster;
    card->tags = { WildHunt, Leader };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceCreateOptions(ally, enemy, card, {isBronze, hasTag(WildHunt)}, AnyCard, -1);
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}

Card *createCaranthirArFeiniel()
{
    auto *card = new Card();
    card->id = "132104";
    card->power = card->powerBase = 9;
    card->rarity = Gold;
    card->faction = Monster;
    card->tags = { WildHunt, Mage, Officer };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        const Row row = _findRowAndPos(card, ally).row();
        if (moveExistedUnitToPos(target, rowAndPosLastInExactRow(enemy, row), enemy, ally, card))
            applyRowEffect(ally, enemy, 3 + row, BitingFrostEffect);
    };
    return card;
}

Card *createImlerithSabbath()
{
    auto *card = new Card();
    card->id = "201781";
    card->power = card->powerBase = 5;
    card->rarity = Gold;
    card->faction = Monster;
    card->tags = { WildHunt, Officer };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        gainArmor(card, 2, ally, enemy, card);
    };

    card->_onTurnEnd = [=](Field &ally, Field &enemy) {
        if (!isOnBoard(card, ally))
            return;
        if (duel(card, highest(cardsFiltered(ally, enemy, {}, EnemyBoard), ally.rng), ally, enemy)) {
            heal(card, 2, ally, enemy, card);
            gainArmor(card, 2, ally, enemy, card);
        }
    };
    return card;
}

Card *createDagon()
{
    auto *card = new Card();
    card->id = "200158";
    card->power = card->powerBase = 8;
    card->rarity = Gold;
    card->faction = Monster;
    card->tags = { Leader, Vodyanoi };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToSelectOption(ally, enemy, card, {new ImpenetrableFog(), new TorrentialRain()});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}

Card *createIfrit()
{
    auto *card = new Card();
    card->id = "132210";
    card->power = card->powerBase = 8;
    card->rarity = Silver;
    card->faction = Monster;
    card->tags = { Construct };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        const Row row = _findRowAndPos(card, ally).row();
        const RowAndPos rowAndPos(row, Pos(ally.row(row).size()));
        spawnNewUnitToPos(new IfritLesser(), rowAndPos, ally, enemy, card);
        spawnNewUnitToPos(new IfritLesser(), rowAndPos, ally, enemy, card);
        spawnNewUnitToPos(new IfritLesser(), rowAndPos, ally, enemy, card);
    };
    return card;
}

Ifrit::IfritLesser::IfritLesser()
{
    auto *card = new Card();
    card->id = "132404";
    card->power = card->powerBase = 1;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Construct };
    card->isDoomed = true;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        damage(random(cardsFiltered(ally, enemy, {}, EnemyBoard), ally.rng), 1, ally, enemy, card);
    };
    return card;
}

Card *createSheTrollOfVergen()
{
    auto *card = new Card();
    card->id = "200534";
    card->power = card->powerBase = 1;
    card->rarity = Silver;
    card->faction = Monster;
    card->tags = { Ogroid };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        _played = false;
        startChoiceToTargetCard(ally, enemy, card, {isBronze, isDeathwish}, AllyDeckShuffled);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (!_played) {
            _played = true;
            startChoiceToTargetCard(ally, enemy, card, {target});
            playExistedCard(target, ally, enemy, card);
            return;
        }

        boost(card, consume(target, ally, enemy, card), ally, enemy, card);
    };
    return card;
}

Card *createWyvern()
{
    auto *card = new Card();
    card->id = "132303";
    card->power = card->powerBase = 6;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Draconid };

    card->_onDeploy = [=] (Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
    };

    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
        damage(target, 5, ally, enemy, card);
    };
    return card;
}

Card *createAbaya()
{
    auto *card = new Card();
    card->id = "132203";
    card->power = card->powerBase = 4;
    card->rarity = Silver;
    card->faction = Monster;
    card->tags = { Necrophage };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToSelectOption(ally, enemy, card, {new TorrentialRain(), new ClearSkies(), new ArachasVenom()});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}

Card *createParasite()
{
    auto *card = new Card();
    card->id = "201657";
    card->isSpecial = true;
    card->rarity = Silver;
    card->faction = Monster;
    card->tags = { Organic };

    card->_onPlaySpecial = [=] (Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card);
    };

    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
        if (isOnBoard(target, ally))
            boost(target, 12, ally, enemy, card);
        else if (isOnBoard(target, enemy))
            damage(target, 12, ally, enemy, card);
        else
            assert(false);
    };

    return card;
}

Card *createJotunn()
{
    auto *card = new Card();
    card->id = "200218";
    card->power = card->powerBase = 6;
    card->rarity = Silver;
    card->faction = Monster;
    card->tags = { Ogroid };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        Row rowSelf = _findRowAndPos(card, ally).row();
        startChoiceToTargetCard(ally, enemy, card, {isNotOnRow(&enemy, rowSelf)}, EnemyBoard, 3);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        Row rowSelf = _findRowAndPos(card, ally).row();
        if (moveExistedUnitToPos(target, rowAndPosLastInExactRow(enemy, rowSelf), enemy, ally, card))
            damage(target, rowEffectUnderUnit(target, enemy) == BitingFrostEffect ? 3 : 2, ally, enemy, card);
    };
    return card;
}

Card *createIceGiant()
{
    auto *card = new Card();
    card->id = "132212";
    card->power = card->powerBase = 6;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Ogroid };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (enemy.rowEffect(Meele) == BitingFrostEffect
                || enemy.rowEffect(Range) == BitingFrostEffect
                || enemy.rowEffect(Seige) == BitingFrostEffect
                || ally.rowEffect(Meele) == BitingFrostEffect
                || ally.rowEffect(Range) == BitingFrostEffect
                || ally.rowEffect(Seige) == BitingFrostEffect)
            boost(card, 6, ally, enemy, card);
    };
    return card;
}

Card *createIceTroll()
{
    auto *card = new Card();
    card->id = "200502";
    card->power = card->powerBase = 4;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Ogroid };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        const int mult = rowEffectUnderUnit(target, enemy) == BitingFrostEffect ? 2 : 1;
        while (true) {
            if (damage(target, power * mult, ally, enemy, card))
                return true;
            if (damage(card, target->power, ally, enemy, target))
                return false;
        }
    };
    return card;
}

Card *createDrowner()
{
    auto *card = new Card();
    card->id = "132314";
    card->power = card->powerBase = 7;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Necrophage };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        Row rowSelf = _findRowAndPos(card, ally).row();
        startChoiceToTargetCard(ally, enemy, card, {isNotOnRow(&enemy, rowSelf)}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        Row rowSelf = _findRowAndPos(card, ally).row();
        if (moveExistedUnitToPos(target, rowAndPosLastInExactRow(enemy, rowSelf), enemy, ally, card))
            damage(target, (rowEffectUnderUnit(target, enemy) > 0 && rowEffectUnderUnit(target, enemy) <= 9) ? 4 : 2, ally, enemy, card);
    };
    return card;
}

Card *createFoglet()
{
    auto *card = new Card();
    card->id = "132301";
    card->power = card->powerBase = 4;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Necrophage };

    card->_onAllyAppliedRowEffect = [=](const RowEffect rowEffect, Field &ally, Field &enemy, const Row row) {
        if (rowEffect != ImpenetrableFogEffect || !isIn(card, ally.deck))
            return;

        for (Card *card : cardsFiltered(ally, enemy, {isCopy<Foglet>, otherThan(card)}, AllyDeckShuffled)) {
            Foglet *foglet = static_cast<Foglet *>(card);
            foglet->_rowToCopy.insert({row, card});
        }

        if (_rowToCopy.find(row) == _rowToCopy.end())
            moveExistedUnitToPos(card, rowAndPosLastInExactRow(ally, row), ally, enemy, card);

        _rowToCopy.clear();
    };
    return card;
}

Card *createAncientFoglet()
{
    auto *card = new Card();
    card->id = "132302";
    card->power = card->powerBase = 10;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Necrophage };

    card->_onTurnEnd = [=](Field &ally, Field &enemy) {
        if (!isOnBoard(card, ally))
            return;
        if (enemy.rowEffect(Meele) == ImpenetrableFogEffect
                || enemy.rowEffect(Range) == ImpenetrableFogEffect
                || enemy.rowEffect(Seige) == ImpenetrableFogEffect
                || ally.rowEffect(Meele) == ImpenetrableFogEffect
                || ally.rowEffect(Range) == ImpenetrableFogEffect
                || ally.rowEffect(Seige) == ImpenetrableFogEffect)
            boost(card, 1, ally, enemy, card);
    };
    return card;
}

Card *createDraug()
{
    auto *card = new Card();
    card->id = "132101";
    card->power = card->powerBase = 10;
    card->rarity = Gold;
    card->faction = Monster;
    card->tags = { Cursed, Officer };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        // TODO: check interaction w/ Cyris
        assert(isOnBoard(card, ally));
        const Row row = _findRowAndPos(card, ally).row();
        for (Card *card : cardsFiltered(ally, enemy, {isUnit}, AllyDiscard)) {
            if (isRowFull(ally.row(row)))
                return;
            banish(card, ally, enemy, card);
            if (!spawnNewUnitToPos(new Draugir(), rowAndPosToTheRight(card, ally, 1), ally, enemy, card))
                break;
        }
    };
    return card;
}

Draug::Draugir::Draugir()
{
    auto *card = new Card();
    // TODO: find picture
    card->id = "132101";
    card->power = card->powerBase = 1;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Cursed };
    card->isDoomed = true;
    return card;
}

Card *createCelaenoHarpy()
{
    auto *card = new Card();
    card->id = "132217";
    card->power = card->powerBase = 6;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Beast };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        spawnNewUnitToPos(new HarpyEgg(), rowAndPosToTheLeft(card, ally, 1), ally, enemy, card);
        spawnNewUnitToPos(new HarpyEgg(), rowAndPosToTheLeft(card, ally, 1), ally, enemy, card);
    };
    return card;
}

CelaenoHarpy::HarpyEgg::HarpyEgg()
{
    auto *card = new Card();
    card->id = "132316";
    card->power = card->powerBase = 1;
    card->rarity = Bronze;
    card->faction = Monster;
    card->isDoomed = true;

    card->_onConsumed = [=](Field &ally, Field &enemy, Card *src) {
        boost(src, 4, ally, enemy, card);
    };

    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
        spawnNewUnitToPos(new HarpyHatchling(), rowAndPosRandom(ally), ally, enemy, card);
    };
    return card;
}

CelaenoHarpy::HarpyHatchling::HarpyHatchling()
{
    auto *card = new Card();
    card->id = "132315";
    card->power = card->powerBase = 4;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Beast };
    return card;
}

Card *createArachasBehemoth()
{
    auto *card = new Card();
    card->id = "132201";
    card->power = card->powerBase = 8;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Insectoid };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        setTimer(card, ally, enemy, 4);
    };

    card->_onAllyConsume = [=](Field &ally, Field &enemy, Card *) {
        if (!isOnBoard(card, ally))
            return;
        if (!tick(card, ally, enemy))
            spawnNewUnitToPos(new ArachasHatchling(), rowAndPosRandom(ally), ally, enemy, card);
    };
    return card;
}

ArachasBehemoth::ArachasHatchling::ArachasHatchling()
{
    auto *card = new Card();
    card->id = "132304";
    card->power = card->powerBase = 3;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Insectoid };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *copy : cardsFiltered(ally, enemy, {isCopy<ArachasDrone>}, AllyDeck))
            moveExistedUnitToPos(copy, rowAndPosToTheRight(card, ally, 1), ally, enemy, card);
    };
    return card;
}

Card *createArchgriffin()
{
    auto *card = new Card();
    card->id = "132307";
    card->power = card->powerBase = 10;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Beast };

    card->_onDeploy = [=](Field &ally, Field &) {
        clearHazardsFromItsRow(card, ally);
    };
    return card;
}

Card *createGriffin()
{
    auto *card = new Card();
    card->id = "132312";
    card->power = card->powerBase = 9;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Beast };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronze, isDeathwish}, AllyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        target->onDestroy(ally, enemy, _findRowAndPos(target, ally));
    };
    return card;
}

Card *createBridgeTroll()
{
    auto *card = new Card();
    card->id = "201700";
    card->power = card->powerBase = 10;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Ogroid };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        std::vector<int> rowsWithHazzards;
        for (int rowInd = 0; rowInd < 3; ++rowInd) {
            const RowEffect rowEffect = enemy.rowEffect(Row(rowInd));
            const bool isHazzard = (0 < rowEffect) && (rowEffect <= 9);
            if (!isHazzard)
                continue;
            rowsWithHazzards.push_back(rowInd + 3);
        }
        _rowSelected = -1;
        startChoiceToSelectRow(ally, enemy, card, rowsWithHazzards);
    };

    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
        if (_rowSelected == -1) {
            _rowSelected = screenRow;
            std::vector<int> otherRows = {3, 4, 5};
            otherRows.erase(otherRows.begin() + screenRow - 3);
            startChoiceToSelectRow(ally, enemy, card, otherRows);
            return;
        }
        applyRowEffect(ally, enemy, screenRow, enemy.rowEffect(Row(_rowSelected - 3)));
        applyRowEffect(ally, enemy, _rowSelected, NoRowEffect);
    };
    return card;
}

Card *createCockatrice()
{
    auto *card = new Card();
    card->id = "200233";
    card->power = card->powerBase = 6;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Draconid };


    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        reset(target, ally, enemy, card);
    };
    return card;
}

Card *createNekurat()
{
    auto *card = new Card();
    card->id = "132220";
    card->power = card->powerBase = 5;
    card->rarity = Silver;
    card->faction = Monster;
    card->tags = { Vampire };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        spawnNewCard(new Moonlight(), ally, enemy, card);
    };
    return card;
}

Card *createSiren()
{
    auto *card = new Card();
    card->id = "200112";
    card->power = card->powerBase = 4;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Beast };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (Card *moonlight = random(cardsFiltered(ally, enemy, {isCopy<Moonlight>}, AllyDeck), ally.rng))
            playExistedCard(moonlight, ally, enemy, card);
    };
    return card;
}

Card *createLamia()
{
    auto *card = new Card();
    card->id = "132409";
    card->power = card->powerBase = 6;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Beast };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        damage(target, rowEffectUnderUnit(target, enemy) == BloodMoonEffect ? 7 : 4 , ally, enemy, card);
    };
    return card;
}

Card *createNekker()
{
    auto *card = new Card();
    card->id = "132305";
    card->power = card->powerBase = 4;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Ogroid };

    card->_onAllyConsume = [=](Field &ally, Field &enemy, Card *) {
        if (!isIn(card, ally.discard))
            boost(card, 1, ally, enemy, card);
    };

    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &rowAndPos) {
        if (Card *copy = random(cardsFiltered(ally, enemy, {isCopy<Nekker>}, AllyDeck), ally.rng))
            moveExistedUnitToPos(copy, rowAndPos, ally, enemy, card);
    };
    return card;
}

Card *createNekkerWarrior()
{
    auto *card = new Card();
    card->id = "132211";
    card->power = card->powerBase = 9;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Ogroid };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronze}, AllyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        int n = 2;
        while (n--) {
            Card *card = target->defaultCopy();
            addAsNew(ally, card);
            putToDeck(card, ally, enemy, DeckPosBottom, card);
        }
    };
    return card;
}

Card *createSlyzard()
{
    auto *card = new Card();
    card->id = "200539";
    card->power = card->powerBase = 2;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Draconid };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronze, isUnit}, AllyDiscard);
    };

    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
        consume(target, ally, enemy, card);
        if (Card *copy = random(cardsFiltered(ally, enemy, {isCopy(target->name)}, AllyDeck), ally.rng))
            playExistedCard(copy, ally, enemy, card);
    };
    return card;
}

Card *createWerecat()
{
    auto *card = new Card();
    card->id = "201599";
    card->power = card->powerBase = 5;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Beast, Cursed };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
    };

    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
        damage(target, 5, ally, enemy, card);
        for (Card *card : cardsFiltered(ally, enemy, {}, EnemyBoard))
            if (rowEffectUnderUnit(card, enemy) == BloodMoonEffect)
                damage(card, 1, ally, enemy, card);
    };
    return card;
}

Card *createHarpy()
{
    auto *card = new Card();
    card->id = "132315";
    card->power = card->powerBase = 4;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Beast };

    card->_onOtherAllyDestroyed = [=](Card *other, Field &ally, Field &enemy, const RowAndPos rowAndPos) {
        if (!isIn(card, ally.deck) || !hasTag(other, Beast))
            return;

        for (Card *card : cardsFiltered(ally, enemy, {isCopy<Harpy>, otherThan(card)}, AllyDeckShuffled)) {
            Harpy *harpy = static_cast<Harpy *>(card);
            harpy->_allyDestroyedToCopy.insert({other, card});
        }

        if (_allyDestroyedToCopy.find(other) == _allyDestroyedToCopy.end())
            moveExistedUnitToPos(card, rowAndPos, ally, enemy, card);

        _allyDestroyedToCopy.clear();
    };
    return card;
}

Card *createWildHuntDrakkar()
{
    auto *card = new Card();
    card->id = "200301";
    card->power = card->powerBase = 7;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { WildHunt, Machine };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *card : cardsFiltered(ally, enemy, {hasTag(WildHunt)}, AllyBoard))
            boost(card, 1, ally, enemy, card);
    };

    card->_onOtherAllyAppears = [=](Card *card, Field &ally, Field &enemy) {
        if (!isOnBoard(card, ally) || !hasTag(card, WildHunt))
            return;
        boost(card, 1, ally, enemy, card);
    };
    return card;
}

Card *createGeels()
{
    auto *card = new Card();
    card->id = "131102";
    card->power = card->powerBase = 1;
    card->rarity = Gold;
    card->faction = Monster;
    card->tags = { WildHunt, Officer };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        std::vector<Card *> variants;
        if ((_gold = random(cardsFiltered(ally, enemy, {isGold}, AllyDeck), ally.rng)))
            variants.push_back(_gold);
        if ((_silver = random(cardsFiltered(ally, enemy, {isSilver}, AllyDeck), ally.rng)))
            variants.push_back(_silver);
        startChoiceToTargetCard(ally, enemy, card, variants);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
        if (target == _gold && _silver)
            putToDeck(_silver, ally, enemy, DeckPosTop, card);
        else if (target == _silver && _gold)
            putToDeck(_gold, ally, enemy, DeckPosTop, card);
    };

    return card;
}

Card *createWildHuntRider()
{
    auto *card = new Card();
    card->id = "132310";
    card->power = card->powerBase = 10;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { WildHunt, Soldier };

    // NOTE: ability is implemented inside the weather trigger
    return card;
}

Card *createVranWarrior()
{
    auto *card = new Card();
    card->id = "132308";
    card->power = card->powerBase = 6;
    card->rarity = Bronze;
    card->faction = Monster;
    card->tags = { Draconid, Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        setTimer(card, ally, enemy, 2);
        if (Card *card = cardNextTo(card, ally, enemy, 1))
            boost(card, consume(card, ally, enemy, card), ally, enemy, card);
    };

    card->_onTurnStart = [=](Field &ally, Field &enemy) {
        if (isOnBoard(card, ally) && tick(card, ally, enemy))
            onDeploy(ally, enemy);
    };
    return card;
}

Card *createAnCraiteArmorsmith()
{
    auto *card = new Card();
    card->id = "152317";
    card->power = card->powerBase = 7;
    card->rarity = Bronze;
    card->faction = Skellige;
    card->tags = { ClanAnCraite, Support };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AllyBoard, 2);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        heal(target, ally, enemy, card);
        gainArmor(target, 3, ally, enemy, card);
    };
    return card;
}

Card *createAvalach()
{
    auto *card = new Card();
    card->id = "132105";
    card->power = card->powerBase = 8;
    card->rarity = Gold;
    card->faction = Neutral;
    card->tags = { Elf, Mage };
    card->isDoomed = true;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (ally.passed || enemy.passed)
            return;

        drawACard(ally, enemy,  card);
        drawACard(enemy, ally,  card);

        drawACard(ally, enemy,  card);
        drawACard(enemy, ally,  card);
    };
    return card;
}

Card *createAvalachSage()
{
    auto *card = new Card();
    card->id = "112112";
    card->power = card->powerBase = 3;
    card->rarity = Gold;
    card->faction = Neutral;
    card->tags = { Elf, Mage };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (Card *card = random(cardsFiltered(ally, enemy, {isSilverOrGold, isUnit}, EnemyDeckStarting), ally.rng))
            spawnNewCard(card->defaultCopy(), ally, enemy, card);
    };
    return card;
}

Card *createRaghNarRoog()
{
    auto *card = new Card();
    card->id = "113101";
    card->isSpecial = true;
    card->rarity = Gold;
    card->faction = Neutral;
    card->tags = { Hazard, Spell };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        for (int screenRow = 3; screenRow < 6; ++screenRow)
            applyRowEffect(ally, enemy, screenRow, RaghNarRoogEffect);
    };
    return card;
}

Card *createGeraltProfessional()
{
    auto *card = new Card();
    card->id = "201772";
    card->power = card->powerBase = 7;
    card->rarity = Gold;
    card->faction = Neutral;
    card->tags = { Witcher };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (target->faction == Monster)
            return putToDiscard(target, ally, enemy, card);

        damage(target, 4, ally, enemy, card);
    };
    return card;
}

Card *createGeraltAard()
{
    auto *card = new Card();
    card->id = "112111";
    card->power = card->powerBase = 6;
    card->rarity = Gold;
    card->faction = Neutral;
    card->tags = { Witcher };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard, 3);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (!damage(target, 3, ally, enemy, card)) {
            const RowAndPos rowAndPos = _findRowAndPos(target, enemy);
            const Row rowAbove = std::min(Row(rowAndPos.row() + 1), Seige);
            if (rowAbove != rowAndPos.row())
                moveExistedUnitToPos(target, rowAndPosLastInExactRow(enemy, rowAbove), enemy, ally, card);
        }
    };
    return card;
}

Card *createGeraltYrden()
{
    auto *card = new Card();
    card->id = "201523";
    card->power = card->powerBase = 6;
    card->rarity = Gold;
    card->faction = Neutral;
    card->tags = { Witcher };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToSelectRow(ally, enemy, card);
    };

    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
        for (Card *card : cardsInRow(ally, enemy, screenRow)) {
            reset(card, ally, enemy, card);
            removeAllStatuses(card, ally, enemy, card);
        }
    };
    return card;
}

Card *createCiriDash()
{
    auto *card = new Card();
    card->id = "112110";
    card->power = card->powerBase = 11;
    card->rarity = Gold;
    card->faction = Neutral;
    card->tags = { Cintra, Witcher };

    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
        onDiscard(ally, enemy);
    };

    card->_onDiscard = [=](Field &ally, Field &enemy) {
        putToDeck(card, ally, enemy, DeckPosRandom, card);
        strengthen(card, 3, ally, enemy, card);
    };
    return card;
}

Card *createAguara()
{
    auto *card = new Card();
    card->id = "200062";
    card->power = card->powerBase = 5;
    card->rarity = Gold;
    card->faction = Neutral;
    card->tags = { Relict, Cursed };

    card->_onDeploy = [=](Field & ally, Field &enemy) {
        auto *option1 = new Aguara::BoostLowest;
        copyCardText(card, option1);
        option1->text = "Boost the Lowest ally by 5.";

        auto *option2 = new Aguara::BoostInHand;
        copyCardText(card, option2);
        option2->text = "Boost a random unit in your hand by 5.";

        auto *option3 = new Aguara::DamageHighest;
        copyCardText(card, option3);
        option3->text = "Deal 5 damage to the Highest enemy.";

        auto *option4 = new Aguara::CharmElf;
        copyCardText(card, option4);
        option4->text = "Charm a random enemy Elf with 5 power or less.";

        _optionsSelected.clear();
        startChoiceToSelectOption(ally, enemy, card, {option1, option2, option3, option4}, 2);
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (dynamic_cast<Aguara::BoostLowest *>(target))
            if (Card *card = lowest(cardsFiltered(ally, enemy, {}, AllyBoard), ally.rng))
                boost(card, 5, ally, enemy, card);

        if (dynamic_cast<Aguara::BoostInHand *>(target))
            if (Card *card = random(cardsFiltered(ally, enemy, {isUnit}, AllyHand), ally.rng))
                boost(card, 5, ally, enemy, card);

        if (dynamic_cast<Aguara::DamageHighest *>(target))
            if (Card *card = highest(cardsFiltered(ally, enemy, {}, EnemyBoard), ally.rng))
                damage(card, 5, ally, enemy, card);

        if (dynamic_cast<Aguara::CharmElf *>(target))
            if (Card *card = random(cardsFiltered(ally, enemy, {hasTag(Elf), hasPowerXorLess(5)}, EnemyBoard), ally.rng))
                charm(card, ally, enemy, card);

        _optionsSelected.push_back(target);

        /// after 2 choices done, delete selected options
        if (_optionsSelected.size() == 2) {
            delete _optionsSelected[0];
            delete _optionsSelected[1];
            _optionsSelected.clear();
        }
    };
    return card;
}

Card *createAguaraTrueForm()
{
    auto *card = new Card();
    card->id = "200056";
    card->power = card->powerBase = 2;
    card->rarity = Gold;
    card->faction = Neutral;
    card->tags = { Relict, Cursed };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceCreateOptions(ally, enemy, card, {isBronzeOrSilver, hasTag(Spell)});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}

Card *createKorathiHeatwave()
{
    auto *card = new Card();
    card->id = "200018";
    card->isSpecial = true;
    card->rarity = Gold;
    card->faction = Neutral;
    card->tags = { Hazard };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        for (int screenRow = 3; screenRow < 6; ++screenRow)
            applyRowEffect(ally, enemy, screenRow, KorathiHeatwaveEffect);
    };

    return card;
}

Card *createAleOfTheAncestors()
{
    auto *card = new Card();
    card->id = "200532";
    card->power = card->powerBase = 10;
    card->rarity = Gold;
    card->faction = Neutral;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        applyRowEffect(ally, enemy, 2 - int(_findRowAndPos(card, ally).row()), GoldenFrothEffect);
    };
    return card;
}

Card *createMahakamAle()
{
    auto *card = new Card();
    card->id = "200519";
    card->isSpecial = true;
    card->rarity = Bronze;
    card->faction = Neutral;
    card->tags = { Alchemy };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        for (const Row row : std::vector<Row>{Meele, Range, Seige})
            if (Card *card = random(ally.row(row), ally.rng))
                boost(card, 4, ally, enemy, card);
    };
    return card;
}

Card *createOdrin()
{
    auto *card = new Card();
    card->id = "122213";
    card->power = card->powerBase = 8;
    card->rarity = Silver;
    card->faction = NothernRealms;
    card->tags = { Kaedwen, Soldier };

    card->_onTurnStart = [=](Field &ally, Field &enemy) {
        if (!isOnBoard(card, ally))
            return;
        if (!moveToRandomRow(card, ally, enemy, card))
            return;
        for (Card *card : cardsFiltered(ally, enemy, {isOnSameRow(&ally, card), otherThan(card)}, AllyBoard))
            boost(card, 1, ally, enemy, card);
    };
    return card;
}

Card *createToruviel()
{
    auto *card = new Card();
    card->id = "142204";
    card->power = card->powerBase = 6;
    card->isAmbush = true;
    card->rarity = Silver;
    card->faction = Scoiatael;
    card->tags = { Elf, Officer };

    card->_onDeploy = [=](Field &, Field &) {
        isAmbush = true;
    };

    card->_onOpponentPass = [=](Field &ally, Field &enemy) {
        flipOver(card, ally, enemy);

        const std::vector<Card *> cardsToBoost {
            cardNextTo(card, ally, enemy, -2),
                    cardNextTo(card, ally, enemy, -1),
                    cardNextTo(card, ally, enemy, 1),
                    cardNextTo(card, ally, enemy, 2),
        };
        for (Card *card : cardsToBoost)
            if (card != nullptr)
                boost(card, 2, ally, enemy, card);
    };
    return card;
}

Card *createCiri()
{
    auto *card = new Card();
    card->id = "112101";
    card->power = card->powerBase = 6;
    card->rarity = Gold;
    card->faction = Neutral;
    card->tags = { Cintra, Witcher };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        gainArmor(card, 2, ally, enemy, card);
    };
    return card;
}

Card *createMilva()
{
    auto *card = new Card();
    card->id = "142104";
    card->power = card->powerBase = 6;
    card->rarity = Gold;
    card->faction = Scoiatael;
    card->tags = { Soldier };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (Card *card = highest(cardsFiltered(ally, enemy, {isBronzeOrSilver}, AllyBoard), ally.rng))
            putToDeck(card, ally, enemy, DeckPosRandom, card);
        if (Card *card = highest(cardsFiltered(ally, enemy, {isBronzeOrSilver}, EnemyBoard), ally.rng))
            putToDeck(card, enemy, ally, DeckPosRandom, card);
    };
    return card;
}


Card *createPrincessPavetta()
{
    auto *card = new Card();
    card->id = "122210";
    card->power = card->powerBase = 3;
    card->rarity = Silver;
    card->faction = NothernRealms;
    card->tags = { Cintra, Mage };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (Card *card = lowest(cardsFiltered(ally, enemy, {isBronzeOrSilver}, AllyBoard), ally.rng))
            putToDeck(card, ally, enemy, DeckPosRandom, card);
        if (Card *card = lowest(cardsFiltered(ally, enemy, {isBronzeOrSilver}, EnemyBoard), ally.rng))
            putToDeck(card, enemy, ally, DeckPosRandom, card);
    };
    return card;
}

Card *createTheGuardian()
{
    auto *card = new Card();
    card->id = "162401";
    card->power = card->powerBase = 11;
    card->rarity = Silver;
    card->faction = Nilfgaard;
    card->tags = { Construct };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        auto *guardian = new LesserGuardian();
        addAsNew(enemy, guardian);
        putToDeck(guardian, enemy, ally, DeckPosTop, card);
    };
    return card;
}

TheGuardian::LesserGuardian::LesserGuardian()
{
    auto *card = new Card();
    card->id = "162401";
    card->power = card->powerBase = 6;
    card->rarity = Bronze;
    card->faction = Nilfgaard;
    card->tags = { Construct };
    return card;
}

Card *createGaunterODimm()
{
    auto *card = new Card();
    card->id = "132215";
    card->power = card->powerBase = 6;
    card->rarity = Gold;
    card->faction = Neutral;
    card->tags = { Relict };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        _picked = random(createAll(patch), ally.rng);

        auto *option1 = new GaunterODimm::Less6;
        copyCardText(card, option1);
        option1->text = "Picked card power is less than 6.";

        auto *option2 = new GaunterODimm::Equal6;
        copyCardText(card, option2);
        option2->text = "Picked card power is 6.";

        auto *option3 = new GaunterODimm::More6;
        copyCardText(card, option3);
        option3->text = "Picked card power is more than 6.";

        startChoiceToSelectOption(ally, enemy, card, {option1, option2, option3});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        const bool guessed =
                (dynamic_cast<GaunterODimm::Less6 *>(target) && (_picked->power < 6))
                || (dynamic_cast<GaunterODimm::Equal6 *>(target) && (_picked->power == 6))
                || (dynamic_cast<GaunterODimm::More6 *>(target) && (_picked->power > 6));
        delete target;
        if (!guessed) {
            _picked = nullptr;
            return;
        }
        spawnNewCard(_picked, ally, enemy, card);
        _picked = nullptr;
    };
    return card;
}

Card *createKaedweniSergeant()
{
    auto *card = new Card();
    card->id = "122214";
    card->power = card->powerBase = 9;
    card->rarity = Bronze;
    card->faction = NothernRealms;
    card->tags = { Kaedwen };
    card->isCrew = true;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        gainArmor(card, 3, ally, enemy, card);
        clearHazardsFromItsRow(card, ally);
    };
    return card;
}

Card *createReinforcedBallista()
{
    auto *card = new Card();
    card->id = "122302";
    card->power = card->powerBase = 7;
    card->rarity = Bronze;
    card->faction = NothernRealms;
    card->tags = { Machine };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        int n = nCrewed(card, ally);
        while (n--)
            startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        damage(target, 2, ally, enemy, card);
    };
    return card;
}

Card *createSigismundDijkstra()
{
    auto *card = new Card();
    card->id = "122105";
    card->isLoyal = false;
    card->power = card->powerBase = 4;
    card->rarity = Gold;
    card->faction = NothernRealms;
    card->tags = { Redania };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *card : firsts(ally.deck, 2))
            playExistedCard(card, ally, enemy, card);
    };
    return card;
}

Card *createWhiteFrost()
{
    auto *card = new Card();
    card->id = "113206";
    card->isSpecial = true;
    card->rarity = Silver;
    card->faction = Neutral;
    card->tags = { Hazard };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToSelectRow(ally, enemy, card, {3, 4, 5});
    };

    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
        for (int _screenRow = std::max(3, screenRow - 1); _screenRow <= screenRow; ++_screenRow)
            applyRowEffect(ally, enemy, _screenRow, BitingFrostEffect);
    };
    return card;
}


Card *createWolfsbane()
{
    auto *card = new Card();
    card->id = "200226";
    card->rarity = Gold;
    card->faction = Neutral;
    card->isSpecial = true;
    card->tags = { Organic, Alchemy };

    card->_onDiscard = [=](Field &ally, Field &enemy) {
        setTimer(card, ally, enemy, 3);
    };

    card->_onTurnEnd = [=](Field &ally, Field &enemy) {
        if (!isIn(card, ally.discard))
            return;
        if (!tick(card, ally, enemy))
            return;
        if (Card *card = highest(cardsFiltered(ally, enemy, {}, EnemyBoard), ally.rng))
            damage(card, 6, ally, enemy, card);
        if (Card *card = lowest(cardsFiltered(ally, enemy, {}, AllyBoard), ally.rng))
            boost(card, 6, ally, enemy, card);
    };
    return card;
}

Card *createDunBanner()
{
    auto *card = new Card();
    card->id = "122313";
    card->power = card->powerBase = 4;
    card->rarity = Bronze;
    card->faction = NothernRealms;
    card->tags = { Kaedwen, Soldier };

    card->_onTurnStart = [=](Field &ally, Field &enemy) {
        if (!isIn(card, ally.deck))
            return;
        const int scoreDiff = powerField(enemy) - powerField(ally);
        if (scoreDiff <= 25)
            return;
        for (Card *card : cardsFiltered(ally, enemy, {isCopy<DunBanner>}, AllyDeck))
            moveExistedUnitToPos(card, rowAndPosRandom(ally), ally, enemy, card);
    };
    return card;
}

Card *createAelirenn()
{
    auto *card = new Card();
    card->id = "142211";
    card->power = card->powerBase = 6;
    card->rarity = Silver;
    card->faction = Scoiatael;
    card->tags = { Elf, Officer };

    card->_onTurnEnd = [=](Field &ally, Field &enemy) {
        if (!isIn(card, ally.deck))
            return;
        const int nElfs = int(cardsFiltered(ally, enemy, {hasTag(Elf)}, AllyBoard).size());
        if (nElfs < 5)
            return;
        moveExistedUnitToPos(card, rowAndPosRandom(ally), ally, enemy, card);
    };
    return card;
}

Card *createHanmarvynsDream()
{
    auto *card = new Card();
    card->id = "200079";
    card->rarity = Gold;
    card->faction = Neutral;
    card->isSpecial = true;
    card->tags = { Alchemy };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isGold, isUnit, hasNoTag(Leader)}, EnemyDiscard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        Card *copy = target->defaultCopy();
        spawnNewCard(copy, ally, enemy, card);
        boost(copy, 2, ally, enemy, card);
    };
    return card;
}

Card *createBlackBlood()
{
    auto *card = new Card();
    card->id = "201697";
    card->rarity = Silver;
    card->faction = Neutral;
    card->isSpecial = true;
    card->tags = { Alchemy, Item };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        auto *option1 = new BlackBlood::Create;
        copyCardText(card, option1);
        option1->text = "Create a Bronze Necrophage or Vampire and boost it by 2";

        auto *option2 = new BlackBlood::Destroy;
        copyCardText(card, option2);
        option2->text = "Destroy a Bronze or Silver Necrophage or Vampire.";

        _choosen = nullptr;
        startChoiceToSelectOption(ally, enemy, card, {option1, option2});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (!_choosen && dynamic_cast<BlackBlood::Create *>(target)) {
            _choosen = target;
            startChoiceCreateOptions(ally, enemy, card, {isBronze, hasAnyOfTags({Necrophage, Vampire})});
            return;
        }

        if (!_choosen && dynamic_cast<BlackBlood::Destroy *>(target)) {
            _choosen = target;
            startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, hasAnyOfTags({Necrophage, Vampire})}, AnyBoard);
            return;
        }

        if (dynamic_cast<BlackBlood::Create *>(_choosen)) {
            boost(target, 2, ally, enemy, card);
            spawnNewCard(target, ally, enemy, card);

            delete _choosen;
            _choosen = nullptr;
            return;
        }

        assert(false);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        assert(dynamic_cast<BlackBlood::Destroy *>(_choosen));

        putToDiscard(target, ally, enemy, card);

        delete _choosen;
        _choosen = nullptr;
    };
    return card;
}

Card *createBekkersRockslide()
{
    auto *card = new Card();
    card->id = "201634";
    card->rarity = Silver;
    card->faction = Neutral;
    card->isSpecial = true;
    card->tags = { Spell };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        for (Card * card : randoms(cardsFiltered(ally, enemy, {}, EnemyBoard), 10, ally.rng))
            damage(card, 2, ally, enemy, card);
    };
    return card;
}

Card *createBekkersDarkMirror()
{
    auto *card = new Card();
    card->id = "113315";
    card->rarity = Silver;
    card->faction = Neutral;
    card->isSpecial = true;
    card->tags = { Spell };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        Card *high = highest(cardsFiltered(ally, enemy, {}, AnyBoard), ally.rng);
        Card *low = lowest(cardsFiltered(ally, enemy, {}, AnyBoard), ally.rng);
        if (/*highest == nullptr ||*/ high == low)
            return;
        int transPower = std::min(10, high->power - low->power);
        setPower(high, high->power - transPower, ally, enemy, card);
        setPower(low, low->power + transPower, ally, enemy, card);
    };
    return card;
}

Card *createMerigoldsHailstorm()
{
    auto *card = new Card();
    card->id = "113202";
    card->rarity = Silver;
    card->faction = Neutral;
    card->isSpecial = true;
    card->tags = { Spell };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToSelectRow(ally, enemy, card);
    };

    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
        for (Card *card : cardsInRow(ally, enemy, screenRow)) {
            if (isBronzeOrSilver(card))
                setPower(card, card->power - half(card->power), ally, enemy, card);
        }
    };
    return card;
}

Card *createNecromancy()
{
    auto *card = new Card();
    card->id = "200020";
    card->rarity = Silver;
    card->faction = Neutral;
    card->isSpecial = true;
    card->tags = { Spell };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, isUnit}, BothDiscard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if(isOnBoard(target, ally)) {
            boost(target, transPower, ally, enemy, card);
            return;
        }
        transPower = target->power;
        banish(target, ally, enemy, card);
        startChoiceToTargetCard(ally, enemy, card, {}, AllyBoard);
    };
    return card;
}

Card *createStammelfordsTremor()
{
    auto *card = new Card();
    card->id = "113204";
    card->rarity = Bronze;
    card->faction = Neutral;
    card->isSpecial = true;
    card->tags = { Spell };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        for (Card *card : cardsFiltered(ally, enemy, {}, EnemyBoard))
            damage(card, 1, ally, enemy, card);
    };
    return card;
}

Card *createExpiredAle()
{
    auto *card = new Card();
    card->id = "200530";
    card->rarity = Silver;
    card->faction = Neutral;
    card->isSpecial = true;
    card->tags = { Spell };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        for (const Row row : std::vector<Row>{Meele, Range, Seige})
            if (Card *card = highest(enemy.row(row), enemy.rng))
                damage(card, 6, ally, enemy, card);
    };
    return card;
}

Card *createTrialOfTheGrasses()
{
    auto *card = new Card();
    card->id = "200078";
    card->rarity = Gold;
    card->faction = Neutral;
    card->isSpecial = true;
    card->tags = { Alchemy };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if ((hasTag(target, Witcher) || !damage(target, 10, ally, enemy, card)) && target->power < 25)
            setPower(target, 25, ally, enemy, card);
    };
    return card;
}

Card *createDimeritiumBomb()
{
    auto *card = new Card();
    card->id = "113205";
    card->rarity = Silver;
    card->faction = Neutral;
    card->isSpecial = true;
    card->tags = { Alchemy };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToSelectRow(ally, enemy, card);
    };

    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
        for (Card *card : cardsInRow(ally, enemy, screenRow)) {
            if (isBoosted(card))
                reset(card, ally, enemy, card);
        }
    };
    return card;
}

Card *createGarrison()
{
    auto *card = new Card();
    card->id = "201639";
    card->rarity = Silver;
    card->faction = Neutral;
    card->isSpecial = true;
    card->tags = { Tactics };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        // TODO: implenemt an ability
        // NOTE: the same ability in TrissTelekinesis
        //startChoiceCreateOptions(ally, card);
    };
    return card;
}

Card *createTheLastWish()
{
    auto *card = new Card();
    card->id = "113102";
    card->rarity = Silver;
    card->faction = Neutral;
    card->isSpecial = true;
    card->tags = { Spell };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, randoms(cardsFiltered(ally, enemy, {}, AllyDeck), 2, ally.rng));
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}

Card *createDimeritiumShackles()
{
    auto *card = new Card();
    card->id = "113319";
    card->rarity = Bronze;
    card->faction = Neutral;
    card->isSpecial = true;
    card->tags = { Alchemy, Item };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
    };

    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
        toggleLock(target, ally, enemy, card);
        if (isOnBoard(target, enemy))
            damage(target, 4, ally, enemy, card);
    };
    return card;
}

Card *createWyvernScaleShield()
{
    auto *card = new Card();
    card->id = "133301";
    card->rarity = Bronze;
    card->faction = Neutral;
    card->isSpecial = true;
    card->tags = { Item };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        if (cardsFiltered(ally, enemy, {}, AnyBoard).size() == 0)
            return;
        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, isUnit}, AllyHand);
        _boostAmount = 0;
    };

    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
        if (_boostAmount <= 0) {
            _boostAmount = target->powerBase;
            startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
            return;
        }
        boost(target, _boostAmount, ally, enemy, card);
        _boostAmount = 0;
    };
    return card;
}

Card *createMastercraftedSpear()
{
    auto *card = new Card();
    card->id = "201656";
    card->rarity = Bronze;
    card->faction = Neutral;
    card->isSpecial = true;
    card->tags = { Item };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        if (cardsFiltered(ally, enemy, {}, AnyBoard).size() == 0)
            return;
        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, isUnit}, AllyHand);
        _damageAmount = 0;
    };

    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
        if (_damageAmount <= 0) {
            _damageAmount = target->powerBase;
            startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
            return;
        }
        damage(target, _damageAmount, ally, enemy, card);
        _damageAmount = 0;
    };
    return card;
}

Card *createPetrisPhilter()
{
    auto *card = new Card();
    card->id = "200008";
    card->rarity = Bronze;
    card->faction = Neutral;
    card->isSpecial = true;
    card->tags = { Alchemy, Item };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        for (Card *card : randoms(cardsFiltered(ally, enemy, {}, AllyBoard), 6, ally.rng))
            boost(card, 2, ally, enemy, card);
    };
    return card;
}

Card *createShrike()
{
    auto *card = new Card();
    card->id = "200009";
    card->rarity = Bronze;
    card->faction = Neutral;
    card->isSpecial = true;
    card->tags = { Alchemy, Item };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        for (Card *card : randoms(cardsFiltered(ally, enemy, {}, EnemyBoard), 6, ally.rng))
            damage(card, 2, ally, enemy, card);
    };
    return card;
}

Card *createRoyalDecree()
{
    auto *card = new Card();
    card->id = "200154";
    card->rarity = Gold;
    card->faction = Neutral;
    card->isSpecial = true;
    card->tags = { Tactics };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isGold, isUnit}, AllyDeck);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        boost(target, 2, ally, enemy, card);
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}

Card *createUmasCurse()
{
    auto *card = new Card();
    card->id = "200058";
    card->rarity = Gold;
    card->faction = Neutral;
    card->isSpecial = true;
    card->tags = { Spell };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceCreateOptions(ally, enemy, card, {isGold, isUnit, hasNoTag(Leader)});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}

Card *createLacerate()
{
    auto *card = new Card();
    card->id = "153301";
    card->rarity = Bronze;
    card->faction = Neutral;
    card->isSpecial = true;
    card->tags = { Organic };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToSelectRow(ally, enemy, card);
    };

    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
        for (Card *card : cardsInRow(ally, enemy, screenRow))
            damage(card, 3, ally, enemy, card);
    };
    return card;
}

Card *createCrowsEye()
{
    auto *card = new Card();
    card->id = "200224";
    card->rarity = Bronze;
    card->faction = Neutral;
    card->isSpecial = true;
    card->tags = { Alchemy, Organic };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        const int extraDamage = int(cardsFiltered(ally, enemy, {isCopy<CrowsEye>}, AllyDiscard).size());
        for (const Row row : std::vector<Row>{Meele, Range, Seige})
            if (Card *card = highest(enemy.row(row), enemy.rng))
                damage(card, 4 + extraDamage, ally, enemy, card);
    };
    return card;
}

Card *createDoppler()
{
    auto *card = new Card();
    card->id = "201631";
    card->rarity = Bronze;
    card->faction = Neutral;
    card->isSpecial = true;
    card->tags = { };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        const int currentFaction = ally.leader ? ally.leader->faction : Neutral;
        Card *card = random(_filtered({isFaction(currentFaction), isBronze, isUnit}, createAll(card->patch)), ally.rng)->defaultCopy();
        spawnNewCard(card, ally, enemy, card);
    };
    return card;
}

Card *createSpores()
{
    auto *card = new Card();
    card->id = "201744";
    card->rarity = Bronze;
    card->faction = Neutral;
    card->isSpecial = true;
    card->tags = { Organic };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToSelectRow(ally, enemy, card);
    };

    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
        for (Card *card : cardsInRow(ally, enemy, screenRow))
            damage(card, 2, ally, enemy, card);
        if (rowEffectInSreenRow(ally, enemy, screenRow) > 9)
            applyRowEffect(ally, enemy, screenRow, NoRowEffect);
    };
    return card;
}

Card *createMardroeme()
{
    auto *card = new Card();
    card->id = "113320";
    card->rarity = Bronze;
    card->faction = Neutral;
    card->isSpecial = true;
    card->tags = { Alchemy, Organic };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        auto *option1 = new Mardroeme::Strengthen;
        copyCardText(card, option1);
        option1->text = "Reset a unit and Strengthen it by 3.";

        auto *option2 = new Mardroeme::Weaken;
        copyCardText(card, option2);
        option2->text = "Reset a unit and Weaken it by 3.";

        _choosen = nullptr;
        startChoiceToSelectOption(ally, enemy, card, {option1, option2});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        _choosen = target;
        startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        assert(_choosen);

        reset(target, ally, enemy, card);
        if (dynamic_cast<Mardroeme::Strengthen *>(_choosen))
            strengthen(target, 3, ally, enemy, card);

        if (dynamic_cast<Mardroeme::Weaken *>(_choosen))
            weaken(target, 3, ally, enemy, card);

        delete _choosen;
        _choosen = nullptr;
    };
    return card;
}

Card *createSihil()
{
    auto *card = new Card();
    card->id = "201632";
    card->rarity = Gold;
    card->faction = Neutral;
    card->isSpecial = true;
    card->tags = { Item };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        auto *option1 = new Sihil::DamageOdd;
        copyCardText(card, option1);
        option1->text = "Deal 3 damage to all enemies with odd power.";

        auto *option2 = new Sihil::DamageEven;
        copyCardText(card, option2);
        option2->text = "Deal 3 damage to all enemies with even power.";

        auto *option3 = new Sihil::PlayFromDeck;
        copyCardText(card, option3);
        option3->text = "Play a random Bronze or Silver unit from your deck.";

        startChoiceToSelectOption(ally, enemy, card, {option1, option2, option3});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (dynamic_cast<Sihil::DamageOdd *>(target)) {
            for (Card *card : cardsFiltered(ally, enemy, {hasOddPower}, EnemyBoard))
                damage(card, 3, ally, enemy, card);
            return;
        }

        if (dynamic_cast<Sihil::DamageEven *>(target)) {
            for (Card *card : cardsFiltered(ally, enemy, {hasEvenPower}, EnemyBoard))
                damage(card, 3, ally, enemy, card);
            return;
        }

        if (dynamic_cast<Sihil::PlayFromDeck *>(target)) {
            if (Card *card = random(cardsFiltered(ally, enemy, {isBronzeOrSilver, isUnit}, AllyDeck), ally.rng))
                playExistedCard(card, ally, enemy, card);
            return;
        }

        assert(false);
    };
    return card;
}

Card *createDragonsDream()
{
    auto *card = new Card();
    card->id = "201637";
    card->rarity = Silver;
    card->faction = Neutral;
    card->isSpecial = true;
    card->tags = { Alchemy, Item };

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToSelectRow(ally, enemy, card, {3, 4, 5});
    };

    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
        applyRowEffect(ally, enemy, screenRow, DragonsDreamEffect);
    };
    return card;
}

Card *createEskelPathfinder()
{
    auto *card = new Card();
    card->id = "200236";
    card->power = card->powerBase = 7;
    card->rarity = Gold;
    card->faction = Neutral;
    card->tags = { Witcher };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, isNotBoosted}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        putToDiscard(target, ally, enemy, card);
    };
    return card;
}

Card *createVesemirMentor()
{
    auto *card = new Card();
    card->id = "200237";
    card->tags = { Witcher };
    card->power = card->powerBase = 6;
    card->faction = Neutral;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, hasTag(Alchemy)}, AllyDeckShuffled);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}

Card *createLambertSwordmaster()
{
    auto *card = new Card();
    card->id = "200235";
    card->tags = { Witcher };
    card->power = card->powerBase = 8;
    card->faction = Neutral;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        for (Card *card : findCopies(target, cardsFiltered(ally, enemy, {}, EnemyBoard)))
            damage(card, 4, ally, enemy, card);
    };
    return card;
}

Card *createRegisHigherVampire()
{
    auto *card = new Card();
    card->id = "112105";
    card->tags = { Witcher };
    card->power = card->powerBase = 6;
    card->faction = Neutral;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, randoms(cardsFiltered(ally, enemy, {isBronze, isUnit}, EnemyDeck), 3, ally.rng));
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        boost(card, consume(target, ally, enemy, card), ally, enemy, card);
    };
    return card;
}

Card *createZoltanScoundrel()
{
    auto *card = new Card();
    card->id = "112109";
    card->tags = { Dwarf };
    card->power = card->powerBase = 8;
    card->faction = Neutral;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToSelectOption(ally, enemy, card, {new DudaCompanion(), new DudaAgitator()});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}

ZoltanScoundrel::DudaCompanion::DudaCompanion()
{
    auto *card = new Card();
    card->id = "112403";
    card->tags = { Beast };
    card->isDoomed = true;
    card->power = card->powerBase = 1;
    card->faction = Neutral;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        const std::vector<Card *> cardsToBoost {
            cardNextTo(card, ally, enemy, -2),
                    cardNextTo(card, ally, enemy, -1),
                    cardNextTo(card, ally, enemy, 1),
                    cardNextTo(card, ally, enemy, 2),
        };
        for (Card *card : cardsToBoost)
            if (card != nullptr)
                boost(card, 2, ally, enemy, card);
    };
    return card;
}

ZoltanScoundrel::DudaAgitator::DudaAgitator()
{
    auto *card = new Card();
    card->id = "112404";
    card->tags = { Beast };
    card->isDoomed = true;
    card->isLoyal = false;
    card->power = card->powerBase = 1;
    card->faction = Neutral;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        const std::vector<Card *> cardsToDamage {
            cardNextTo(card, ally, enemy, -2),
                    cardNextTo(card, ally, enemy, -1),
                    cardNextTo(card, ally, enemy, 1),
                    cardNextTo(card, ally, enemy, 2),
        };
        for (Card *card : cardsToDamage)
            if (card != nullptr)
                damage(card, 2, ally, enemy, card);
    };
    return card;
}

Card *createYenneferConjurer()
{
    auto *card = new Card();
    card->id = "112113";
    card->tags = { Mage, Aedirn };
    card->power = card->powerBase = 10;
    card->faction = Neutral;
    card->rarity = Gold;

    card->_onTurnEnd = [=](Field &ally, Field &enemy) {
        if (!isOnBoard(card, ally))
            return;
        for (Card *card : highests(cardsFiltered(ally, enemy, {}, EnemyBoard)))
            damage(card, 1, ally, enemy, card);
    };
    return card;
}

Card *createTrissMerigold()
{
    auto *card = new Card();
    card->id = "112106";
    card->tags = { Mage, Temeria };
    card->power = card->powerBase = 10;
    card->faction = Neutral;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        damage(target, 5, ally, enemy, card);
    };
    return card;
}

Card *createTrissTelekinesis()
{
    auto *card = new Card();
    card->id = "201773";
    card->tags = { Mage, Temeria };
    card->power = card->powerBase = 6;
    card->faction = Neutral;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        // TODO: implenemt an ability
        // NOTE: the same ability in Garrison
        //startChoiceCreateOptions(ally, card);
    };
    return card;
}

Card *createDorregarayOfVole()
{
    auto *card = new Card();
    card->id = "200087";
    card->tags = { Mage };
    card->power = card->powerBase = 1;
    card->faction = Neutral;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceCreateOptions(ally, enemy, card, {isBronzeOrSilver, hasAnyOfTags({Beast, Draconid})});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}

Card *createDandelionVainglory()
{
    auto *card = new Card();
    card->id = "201774";
    card->power = card->powerBase = 9;
    card->rarity = Gold;
    card->faction = Neutral;
    card->tags = { Support };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        const auto isFellow = [](Card *card) {
            return isCopy<GeraltAard>(card)
                    || isCopy<GeraltIgni>(card)
                    || isCopy<GeraltYrden>(card)
                    || isCopy<GeraltOfRivia>(card)
                    || isCopy<GeraltProfessional>(card)
                    || isCopy<Yennefer>(card)
                    || isCopy<YenneferConjurer>(card)
                    || isCopy<YenneferEnchantress>(card)
                    || isCopy<YenneferNecromancer>(card)
                    || isCopy<TrissMerigold>(card)
                    || isCopy<TrissButterflies>(card)
                    || isCopy<TrissTelekinesis>(card)
                    || isCopy<ZoltanChivay>(card)
                    || isCopy<ZoltanScoundrel>(card);
        };

        int boostNumber = cardsFiltered(ally, enemy, {isFellow}, AllyDeckStarting).size();
        if (boostNumber <= 0)
            return;
        boost(card, boostNumber * 3, ally, enemy, card);
    };
    return card;
}

Card *createCyprianWiley()
{
    auto *card = new Card();
    card->id = "112214";
    card->power = card->powerBase = 8;
    card->rarity = Silver;
    card->faction = Neutral;
    card->tags = { Redania };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        weaken(target, 4, ally, enemy, card);
    };
    return card;
}

Card *createDudu()
{
    auto *card = new Card();
    card->id = "112201";
    card->power = card->powerBase = 1;
    card->rarity = Silver;
    card->faction = Neutral;
    card->tags = { Relict };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        setPower(card, target->power, ally, enemy, card);
    };
    return card;
}

Card *createIhuarraquax()
{
    auto *card = new Card();
    card->id = "201817";
    card->tags = { Beast };
    card->power = card->powerBase = 7;
    card->faction = Neutral;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        damageDone = false;
        setTimer(card, ally, enemy, 1);
        damage(card, 5, ally, enemy, card);
    };

    card->_onPowerChanged = [=](Field &ally, Field &enemy, const Card *, const PowerChangeType) {
        if ((timer > 0) && (power == powerBase))
            tick(card, ally, enemy);
    };

    card->_onTurnEnd = [=](Field &ally, Field &enemy) {
        if((timer != -1) || (damageDone) || (!isOnBoard(card, ally)))
            return;
        for (Card *card : randoms(cardsFiltered(ally, enemy, {}, EnemyBoard), 3, ally.rng))
            damage(card, 7, ally, enemy, card);
        damageDone = true;
    };
    return card;
}

Card *createMahakamMarauder()
{
    auto *card = new Card();
    card->id = "200042";
    card->power = card->powerBase = 7;
    card->rarity = Bronze;
    card->faction = Scoiatael;
    card->tags = { Dwarf, Soldier };

    card->_onPowerChanged = [=](Field &ally, Field &enemy, const Card *src, const PowerChangeType type) {
        if((!isOnBoard(card, ally)) || (type == Reset) || (src == card))
            return;
        boost(card, 2, ally, enemy, card);
    };
    return card;
}

Card *createZoltanChivay()
{
    auto *card = new Card();
    card->id = "142105";
    card->tags = { Dwarf };
    card->power = card->powerBase = 8;
    card->faction = Scoiatael;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard, 3);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        const Row row = _findRowAndPos(card, ally).row();
        if (isOnBoard(target, ally)) {
            strengthen(target, 2, ally, enemy, card);
            moveExistedUnitToPos(target, rowAndPosLastInExactRow(ally, row), ally, enemy, card);
            return;
        }
        if (isOnBoard(target, enemy)) {
            damage(target, 2, ally, enemy, card);
            moveExistedUnitToPos(target, rowAndPosLastInExactRow(enemy, row), enemy, ally, card);
            return;
        }
        assert(false);
    };
    return card;
}

Card *createYenneferNecromancer()
{
    auto *card = new Card();
    card->id = "201780";
    card->tags = { Mage, Aedirn };
    card->power = card->powerBase = 5;
    card->faction = Nilfgaard;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, hasTag(Soldier)}, EnemyDiscard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}

Card *createPhoenix()
{
    auto *card = new Card();
    card->id = "201579";
    card->tags = { Draconid };
    card->isDoomed = true;
    card->power = card->powerBase = 5;
    card->faction = Neutral;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, hasTag(Draconid)}, AllyDiscard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}

Card *createSaesenthessisBlaze()
{
    auto *card = new Card();
    card->id = "201613";
    card->tags = { Aedirn, Draconid };
    card->power = card->powerBase = 11;
    card->faction = Neutral;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        const std::vector<Card *> hand = ally.hand;
        const int64_t nCards = hand.size();
        for (Card *card : hand)
            banish(card, ally, enemy, card);
        for (int cardInd = 0; cardInd < nCards; ++cardInd)
            drawACard(ally, enemy,  card);
    };
    return card;
}

Card *createVillentretenmerth()
{
    auto *card = new Card();
    card->id = "112107";
    card->tags = { Draconid };
    card->power = card->powerBase = 10;
    card->faction = Neutral;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        setTimer(card, ally, enemy, 3);
    };

    card->_onTurnStart = [=](Field &ally, Field &enemy) {
        if (!tick(card, ally, enemy))
            return;
        for (Card *card : highests(cardsFiltered(ally, enemy, {otherThan(card)}, AnyBoard)))
            putToDiscard(card, ally, enemy, card);
    };
    return card;
}

Card *createOcvist()
{
    auto *card = new Card();
    card->id = "112206";
    card->tags = { Draconid };
    card->power = card->powerBase = 8;
    card->faction = Neutral;
    card->rarity = Silver;
    card->timer = 4;

    card->_onTurnStart = [=](Field &ally, Field &enemy) {
        if (!isOnBoard(card, ally) || !tick(card, ally, enemy))
            return;
        for (Card *card : cardsFiltered(ally, enemy, {}, EnemyBoard))
            damage(card, 1, ally, enemy, card);
        putToHand(card, ally, enemy,  card);
    };
    return card;
}

Card *createMyrgtabrakke()
{
    auto *card = new Card();
    card->id = "112205";
    card->tags = { Draconid };
    card->power = card->powerBase = 7;
    card->faction = Neutral;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        for (int n = 0; n < 3; ++n)
            startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        damage(target, 2, ally, enemy, card);
    };
    return card;
}

Card *createKingOfBeggars()
{
    auto *card = new Card();
    card->id = "112213";
    card->tags = { Support };
    card->power = card->powerBase = 5;
    card->faction = Neutral;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        const int boost = std::min(powerField(enemy) - powerField(ally), 10);
        if (boost > 0)
            strengthen(card, boost, ally, enemy, card);
    };
    return card;
}

Card *createOlgierdVonEverec()
{
    auto *card = new Card();
    card->id = "112207";
    card->tags = { Redania, Cursed };
    card->power = card->powerBase = 5;
    card->faction = Neutral;
    card->rarity = Silver;

    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
        moveExistedUnitToPos(card, rowAndPosRandom(ally), ally, enemy, card);
    };
    return card;
}

Card *createIrisVonEverec()
{
    auto *card = new Card();
    card->id = "112215";
    card->tags = { Redania, Cursed };
    card->isLoyal = false;
    card->power = card->powerBase = 3;
    card->faction = Neutral;
    card->rarity = Silver;

    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
        for (Card *card : randoms(cardsFiltered(ally, enemy, {}, EnemyBoard), 5, ally.rng))
            boost(card, 5, ally, enemy, card);
    };
    return card;
}

Card *createIrisCompanions()
{
    auto *card = new Card();
    card->id = "200083";
    card->tags = { Relict };
    card->power = card->powerBase = 11;
    card->faction = Neutral;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AllyDeck);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        putToHand(target, ally, enemy,  card);
        putToDiscard(random(ally.hand, ally.rng), ally, enemy, card);
    };
    return card;
}

Card *createJohnny()
{
    auto *card = new Card();
    card->id = "112211";
    card->tags = { Relict };
    card->power = card->powerBase = 9;
    card->faction = Neutral;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AllyHand);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        putToDiscard(target, ally, enemy, card);
        if(Card *card = random(cardsFiltered(ally, enemy, {isColor(target->rarity)}, EnemyDeckStarting), ally.rng)) {
            Card *cardCopy = card->defaultCopy();
            addAsNew(ally, cardCopy);
            putToHand(cardCopy, ally, enemy,  card);
        }
    };
    return card;
}

Card *createStregobor()
{
    auto *card = new Card();
    card->id = "200091";
    card->tags = { Mage };
    card->power = card->powerBase = 10;
    card->faction = Neutral;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (ally.passed || enemy.passed)
            return;
        if (Card *unit = first(cardsFiltered(ally, enemy, {isUnit}, AllyDeck))) {
            putToHand(unit, ally, enemy,  card);
            setPower(unit, 1, ally, enemy, card);
        }
        if (Card *unit = first(cardsFiltered(ally, enemy, {isUnit}, EnemyDeck))) {
            putToHand(unit, enemy, ally,  card);
            setPower(unit, 1, ally, enemy, card);
        }
    };

    return card;
}

Card *createSarah()
{
    auto *card = new Card();
    card->id = "112212";
    card->tags = { Relict };
    card->power = card->powerBase = 11;
    card->faction = Neutral;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AllyHand);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (Card *card = first(cardsFiltered(ally, enemy, {isColor(target->rarity)}, AllyDeck))) {
            putToDeck(target, ally, enemy, DeckPosRandomButNotFirst, card);
            putToHand(card, ally, enemy,  card);
            // TODO: check if here we need to trigger onSwap or etc.
        }
    };
    return card;
}

Card *createPeasantMilitia()
{
    auto *card = new Card();
    card->id = "201753";
    card->tags = { Tactics };
    card->isSpecial = true;
    card->faction = Neutral;
    card->rarity = Bronze;

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToSelectRow(ally, enemy, card, {0, 1, 2});
    };

    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
        for(int i = 0; i < 3; i++) {
            if (isRowFull(cardsInRow(ally, enemy, screenRow)))
                return;
            Card *card = new Peasant();
            addAsNew(ally, card);
            moveExistedUnitToPos(card, rowAndPosLastInExactRow(screenRow, ally, enemy), ally, enemy, card);
        }
    };
    return card;
}

PeasantMilitia::Peasant::Peasant()
{
    auto *card = new Card();
    card->id = "201753";
    card->power = card->powerBase = 3;
    card->tags = { };
    card->isDoomed = true;
    card->faction = Neutral;
    card->rarity = Bronze;
    //    sounds = {
    //        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.86.mp3",
    //        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.87.mp3",
    //        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.84.mp3",
    //        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.85.mp3",
    //        "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.83.mp3",
    //    };
    return card;
}

Card *createPrizeWinningCow()
{
    auto *card = new Card();
    //https://gwent.one/image/gwent/assets/card/art/medium/1498.jpg
    card->id = "112209";
    card->power = card->powerBase = 1;
    card->tags = { Beast };
    card->faction = Neutral;
    card->rarity = Silver;

    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &) {
        Card *card = new Chort();
        addAsNew(ally, card);
        moveExistedUnitToPos(card, rowAndPosRandom(ally), ally, enemy, card);
    };
    return card;
}

PrizeWinningCow::Chort::Chort()
{
    auto *card = new Card();
    // FIXME: check all the details
    card->id = "112209";
    // TODO: place this picture somehow
    //https://gwent.one/image/gwent/assets/card/art/medium/1498.jpg
    card->power = card->powerBase = 15;
    card->tags = { Relict };
    card->faction = Neutral;
    card->rarity = Bronze;
    return card;
}

Card *createPrincessAdda()
{
    auto *card = new Card();
    card->id = "201595";
    card->power = card->powerBase = 6;
    card->tags = { Leader, Cursed };
    card->faction = NothernRealms;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceCreateOptions(ally, enemy, card, {isBronzeOrSilver, isUnit, hasTag(Cursed)});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}

Card *createKingFoltest()
{
    auto *card = new Card();
    card->id = "200168";
    card->power = card->powerBase = 5;
    card->tags = { Leader, Temeria };
    card->isCrew = true;
    card->faction = NothernRealms;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        std::vector<Card *> cards = cardsFiltered(ally, enemy, {otherThan(card)}, AllyBoard);
        std::vector<Card *> cardsDeck = cardsFiltered(ally, enemy, {isUnit, otherThan(card), isNonSpying}, AllyDeck);
        std::vector<Card *> cardsHand = cardsFiltered(ally, enemy, {isUnit, otherThan(card), isNonSpying}, AllyHand);
        cards.insert(cards.end(), cardsDeck.begin(), cardsDeck.end());
        cards.insert(cards.end(), cardsHand.begin(), cardsHand.end());
        for (Card *card : cards)
            boost(card, 1, ally, enemy, card);
    };
    return card;
}

Card *createKingRadovidV()
{
    auto *card = new Card();
    card->id = "200169";
    card->power = card->powerBase = 6;
    card->rarity = Gold;
    card->faction = NothernRealms;
    card->tags = { Leader, Redania };
    card->isCrew = true;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard, 2);
    };

    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
        toggleLock(target, ally, enemy, card);
        if (isOnBoard(target, enemy))
            damage(target, 4, ally, enemy, card);
    };
    return card;
}

Card *createEmhyrVarEmreis()
{
    auto *card = new Card();
    card->id = "200162";
    card->power = card->powerBase = 7;
    card->rarity = Gold;
    card->faction = Nilfgaard;
    card->tags = { Leader, Officer };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AllyHand);
    };

    card->_onTargetChoosen = [=] (Card *target, Field &ally, Field &enemy) {
        if (isIn(target, ally.hand)) {
            // reverse due to choice stack: play a card, then return something to hand
            startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver}, AllyBoard);
            playExistedCard(target, ally, enemy, card);
            return;
        }
        putToHand(target, ally, enemy,  card);
    };
    return card;
}

Card *createUsurper()
{
    auto *card = new Card();
    card->id = "201580";
    card->power = card->powerBase = 1;
    card->rarity = Gold;
    card->faction = Nilfgaard;
    card->tags = { Leader, Officer };
    card->isLoyal = false;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceCreateOptions(ally, enemy, card, {hasTag(Leader)});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        boost(target, 2, ally, enemy, card);
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}

Card *createBrouverHoog()
{
    auto *card = new Card();
    card->id = "200167";
    card->power = card->powerBase = 4;
    card->tags = { Leader, Dwarf };
    card->faction = Scoiatael;
    card->rarity = Gold;

    card->const auto isOk = [=](Card *card) {
        return isUnit(card) && ((isNonSpying(card) && isSilver(card)) || (hasTag(card, Dwarf) && isBronze(card)));
    };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isOk}, AllyDeckShuffled);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}

Card *createEithne()
{
    auto *card = new Card();
    card->id = "200166";
    card->power = card->powerBase = 5;
    card->tags = { Leader, Dryad };
    card->faction = Scoiatael;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, ::isSpecial}, AllyDiscard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}

Card *createFilavandrel()
{
    auto *card = new Card();
    card->id = "201589";
    card->power = card->powerBase = 4;
    card->tags = { Leader, Elf };
    card->faction = Scoiatael;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceCreateOptions(ally, enemy, card, {isSilver, ::isSpecial});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}

Card *createFrancescaFindabair()
{
    auto *card = new Card();
    card->id = "200165";
    card->power = card->powerBase = 7;
    card->tags = { Leader, Mage, Elf };
    card->faction = Scoiatael;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        _cardToSwap = nullptr;
        startChoiceToTargetCard(ally, enemy, card, {}, AllyHand);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (_cardToSwap == nullptr) {
            _cardToSwap = target;
            startChoiceToTargetCard(ally, enemy, card, {}, AllyDeckShuffled);
            return;
        }
        putToDeck(_cardToSwap, ally, enemy, DeckPosRandom, card);
        putToHand(target, ally, enemy,  card);
        boost(target, 3, ally, enemy, card);
    };
    return card;
}

Card *createAglais()
{
    auto *card = new Card();
    card->id = "142106";
    card->power = card->powerBase = 8;
    card->tags = { Dryad };
    card->faction = Scoiatael;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, ::isSpecial}, EnemyDiscard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
        banish(target, ally, enemy, card);
    };
    return card;
}

Card *createIorveth()
{
    auto *card = new Card();
    card->id = "142103";
    card->power = card->powerBase = 6;
    card->tags = { Elf, Officer };
    card->faction = Scoiatael;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (damage(target, 8, ally, enemy, card))
            for (Card *card : cardsFiltered(ally, enemy, {isUnit, hasTag(Elf)}, AllyHand))
                boost(card, 1, ally, enemy, card);
    };
    return card;
}

Card *createIorvethMeditation()
{
    auto *card = new Card();
    card->id = "201611";
    card->power = card->powerBase = 2;
    card->tags = { Elf, Officer };
    card->faction = Scoiatael;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        // TODO: check for new choices system and overall tests required
        std::vector<Card *>cards;
        for (const int _screenRow : std::vector<int>{3, 4, 5}) {
            std::vector<Card *> rowCards = cardsInRow(ally, enemy, _screenRow);
            if (rowCards.size() >= 2)
                cards.insert(cards.end(), rowCards.begin(), rowCards.end());
        }
        if (cards.size() <= 0)
            return;
        startChoiceToTargetCard(ally, enemy, card, cards);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (_choosen == nullptr) {
            _choosen = target;
            const int screenRow = _findScreenRow(target, ally, enemy);
            std::vector<Card *>cards = cardsInRow(ally, enemy, screenRow);
            for (int i = 0; i < int(cards.size()); i++)
                if (cards[i] == _choosen)
                    cards.erase(cards.begin() + i);
            startChoiceToTargetCard(ally, enemy, card, cards);
            return;
        }
        duel(_choosen, target, ally, enemy);
    };
    return card;
}

Card *createIsengrimFaoiltiarna()
{
    auto *card = new Card();
    card->id = "142102";
    card->power = card->powerBase = 7;
    card->tags = { Elf, Officer };
    card->faction = Scoiatael;
    card->rarity = Gold;

    card->const auto isCardAmbush = [=](Card *card) {
        return card->defaultCopy()->isAmbush;
    };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, isCardAmbush}, AllyDeckShuffled);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}

Card *createIsengrimOutlaw()
{
    auto *card = new Card();
    card->id = "201615";
    card->power = card->powerBase = 2;
    card->tags = { Elf, Officer };
    card->faction = Scoiatael;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        auto *option1 = new IsengrimOutlaw::Create;
        copyCardText(card, option1);
        option1->text = "Create a Silver Elf.";

        auto *option2 = new IsengrimOutlaw::Play;
        copyCardText(card, option2);
        option2->text = "Play a Bronze or Silver special card from your deck.";

        _choosen = nullptr;
        startChoiceToSelectOption(ally, enemy, card, {option1, option2});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (!_choosen && dynamic_cast<IsengrimOutlaw::Create *>(target)) {
            _choosen = target;
            startChoiceCreateOptions(ally, enemy, card, {isSilver, hasTag(Elf)});
            return;
        }
        if (!_choosen && dynamic_cast<IsengrimOutlaw::Play *>(target)) {
            _choosen = target;
            startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, ::isSpecial}, AllyDeckShuffled);
            return;
        }

        if (dynamic_cast<IsengrimOutlaw::Create *>(_choosen)) {
            delete _choosen;
            _choosen = nullptr;
            spawnNewCard(target, ally, enemy, card);
        }
        return;
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        assert(dynamic_cast<IsengrimOutlaw::Create *>(_choosen));
        delete _choosen;
        _choosen = nullptr;
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}

Card *createIthlinneAegli()
{
    auto *card = new Card();
    card->id = "142107";
    card->power = card->powerBase = 2;
    card->tags = { Elf, Mage };
    card->faction = Scoiatael;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronze, hasAnyOfTags({Boon, Hazard, Spell})}, AllyDeckShuffled);
    };
    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}

Card *createSchirru()
{
    auto *card = new Card();
    card->id = "142108";
    card->power = card->powerBase = 4;
    card->tags = { Elf, Soldier };
    card->faction = Scoiatael;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToSelectOption(ally, enemy, card, {new Scorch(), new Epidemic()});
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        spawnNewCard(target, ally, enemy, card);
    };

    return card;
}

Card *createSaesenthessis()
{
    auto *card = new Card();
    card->id = "142108";
    card->power = card->powerBase = 10;
    card->tags = { Aedirn, Draconid };
    card->faction = Scoiatael;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (const int dwarfsCount = cardsFiltered(ally, enemy, {hasTag(Dwarf)}, AllyBoard).size() > 0)
            boost(card, dwarfsCount, ally, enemy, card);
        if (const int elfsCount = cardsFiltered(ally, enemy, {hasTag(Elf)}, AllyBoard).size() > 0)
            startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (const int elfsCount = cardsFiltered(ally, enemy, {hasTag(Elf)}, AllyBoard).size() > 0)
            damage(target, elfsCount, ally, enemy, card);
    };
    return card;
}

Card *createSaskia()
{
    auto *card = new Card();
    card->id = "200209";
    card->power = card->powerBase = 11;
    card->tags = { Aedirn, Draconid };
    card->faction = Scoiatael;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronze}, AllyHand, 2, true);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        Card *newBronze;
        if (!(newBronze = first(cardsFiltered(ally, enemy, {isBronze}, AllyDeck))))
            return;
        putToHand(newBronze, ally, enemy,  card);
        putToDeck(target, ally, enemy, DeckPosRandomButNotFirst, card);
    };
    return card;
}

Card *createBarclayEls()
{
    auto *card = new Card();
    card->id = "142207";
    card->power = card->powerBase = 2;
    card->tags = { Dwarf, Officer };
    card->faction = Scoiatael;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (Card *card = random(cardsFiltered(ally, enemy, {isBronzeOrSilver, isUnit, hasTag(Dwarf)}, AllyDeck), ally.rng)) {
            strengthen(card, 3, ally, enemy, card);
            playExistedCard(card, ally, enemy, card);
        }
    };
    return card;
}

Card *createDennisCranmer()
{
    auto *card = new Card();
    card->id = "142211";
    card->power = card->powerBase = 8;
    card->tags = { Dwarf, Officer };
    card->faction = Scoiatael;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *card : cardsFiltered(ally, enemy, {hasTag(Dwarf), otherThan(card), isUnit}, AllyBoardHandDeck))
            strengthen(card, 1, ally, enemy, card);
    };
    return card;
}

Card *createSheldonSkaggs()
{
    auto *card = new Card();
    card->id = "142212";
    card->power = card->powerBase = 9;
    card->tags = { Dwarf, Officer };
    card->faction = Scoiatael;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        int boostAmount = 0;
        const int screenRow = _findScreenRow(card, ally, enemy);
        std::vector<Card *>cards = cardsInRow(ally, enemy, screenRow);
        for (Card *card : cards)
            if (card != card)
                if (moveToRandomRow(card, ally, enemy, card))
                    boostAmount++;
        if (boostAmount > 0)
            boost(card, boostAmount, ally, enemy, card);
    };
    return card;
}

Card *createYarpenZigrin()
{
    auto *card = new Card();
    card->id = "142213";
    card->power = card->powerBase = 8;
    card->tags = { Dwarf, Soldier };
    card->faction = Scoiatael;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &, Field &) {
        isResilient = true;
    };

    card->_onOtherAllyAppears = [=](Card *card, Field &ally, Field &enemy) {
        if (!isOnBoard(card, ally) || !hasTag(card, Dwarf))
            return;
        boost(card, 1, ally, enemy, card);
    };
    return card;
}

Card *createYaevinn()
{
    auto *card = new Card();
    card->id = "142203";
    card->power = card->powerBase = 13;
    card->tags = { Elf };
    card->isLoyal = false;
    card->faction = Scoiatael;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (tick(card, ally, enemy)) {
            Card *unit = first(cardsFiltered(ally, enemy, {isUnit}, AllyDeck));
            Card *special = first(cardsFiltered(ally, enemy, {::isSpecial}, AllyDeck));
            if (unit) {
                putToHand(unit, ally, enemy,  card);
            }
            if (special) {
                putToHand(special, ally, enemy,  card);
            }
            if (!unit || !special)
                return;
            _drawn.push_back(unit);
            _drawn.push_back(special);
            startChoiceToTargetCard(ally, enemy, card, _drawn);
        }
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        for (Card *card : _drawn)
            if (card != target)
                putToDeck(card, ally, enemy, DeckPosRandom, card);
        _drawn.clear();
    };
    return card;
}

Card *createIdaEmeanAepSivney()
{
    auto *card = new Card();
    card->id = "142202";
    card->power = card->powerBase = 4;
    card->tags = { Elf, Mage };
    card->faction = Scoiatael;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToSelectOption(ally, enemy, card, {new ImpenetrableFog(), new ClearSkies(), new AlzursThunder()});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        spawnNewCard(target, ally, enemy, card);
    };
    return card;
}

Card *createPavkoGale()
{
    auto *card = new Card();
    card->id = "201676";
    card->power = card->powerBase = 5;
    card->tags = { Soldier };
    card->faction = Scoiatael;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, hasTag(Item)}, AllyDeckShuffled);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}

Card *createCiaranAepEasnillen()
{
    auto *card = new Card();
    card->id = "142206";
    card->power = card->powerBase = 9;
    card->tags = { Elf, Soldier };
    card->faction = Scoiatael;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {otherThan(card)}, AnyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        // TODO: fix the in-same-line moving issue (DwarvenMercenary has the same)
        toggleLock(target, ally, enemy, card);
        const Row row = _findRowAndPos(card, ally).row();
        if (isOnBoard(target, ally) && _findRowAndPos(target, ally).row() != row) {
            moveExistedUnitToPos(target, rowAndPosLastInExactRow(ally, row), ally, enemy, card);
            return;
        }
        if (isOnBoard(target, enemy) && _findRowAndPos(target, ally).row() != row) {
            moveExistedUnitToPos(target, rowAndPosLastInExactRow(enemy, row), enemy, ally, card);
            return;
        }
    };
    return card;
}

Card *createEibhearHattori()
{
    auto *card = new Card();
    card->id = "200520";
    card->power = card->powerBase = 3;
    card->tags = { Elf, Support };
    card->isDoomed = true;
    card->faction = Scoiatael;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, isUnit, isFaction(Scoiatael), hasPowerXorLess(power)}, AllyDiscard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}


Card *createMilaen()
{
    auto *card = new Card();
    card->id = "200030";
    card->power = card->powerBase = 4;
    card->tags = { Elf };
    card->faction = Scoiatael;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToSelectRow(ally, enemy, card);
    };

    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
        std::vector<Card *> cards = cardsInRow(ally, enemy, screenRow);
        if (cards.size() <= 0)
            return;
        Card *first;
        damage(first = cards[0], 6, ally, enemy, card);
        if (cards[cards.size()] != first)
            damage(cards[cards.size()], 6, ally, enemy, card);
    };
    return card;
}

Card *createBraenn()
{
    auto *card = new Card();
    card->id = "142209";
    card->power = card->powerBase = 6;
    card->tags = { Dryad };
    card->faction = Scoiatael;
    card->rarity = Silver;

    card->const auto isCardOk = [=](Card *card) {
        return hasTag(card, Dryad) || card->defaultCopy()->isAmbush;
        // || (card->defaultCopy()->isAmbush && !isOnBoard(card, ally)); // don't know how to get '&ally' here
        // TODO: check how does the Braenn buff allies in Ambush on board
    };

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (damage(target, power, ally, enemy, card))
            for (Card *card : cardsFiltered(ally, enemy, {isCardOk}, AllyBoardHandDeck))
                boost(card, 1, ally, enemy, card);
    };
    return card;
}

Card *createMorenn()
{
    auto *card = new Card();
    card->id = "142208";
    card->power = card->powerBase = 8;
    card->tags = { Dryad };
    card->isAmbush = true;
    card->faction = Scoiatael;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &, Field &) {
        isAmbush = true;
    };

    card->_onOtherEnemyAppears = [=](Card *target, Field &ally, Field &enemy) {
        // TODO: check how should it works with cases like resurrect, spawn, summon
        // maybe have to replace onOtherEnemyAppears call
        if (!isOnBoard(card, ally) || !isAmbush)
            return;
        flipOver(card, ally, enemy);
        damage (target, 7, ally, enemy, card);
    };

    card->_onOtherSpyAppears = [=](Card *target, Field &ally, Field &enemy) {
        if (!isOnBoard(target, enemy))
            return;
        onOtherEnemyAppears(target, ally, enemy);
    };
    return card;
}

Card *createPaulieDahlberg()
{
    auto *card = new Card();
    card->id = "201696";
    card->power = card->powerBase = 3;
    card->tags = { Dwarf, Support };
    card->isDoomed = true;
    card->faction = Scoiatael;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronze, isUnit, hasTag(Dwarf), hasNoTag(Support)}, AllyDiscard);
    };

    card->_onTargetChoosen = [=](Card * target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}

Card *createMahakamHorn()
{
    auto *card = new Card();
    card->id = "201653";
    card->isSpecial = true;
    card->tags = { Item };
    card->faction = Scoiatael;
    card->rarity = Silver;

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        auto *option1 = new MahakamHorn::Create;
        copyCardText(card, option1);
        option1->text = "Create a Bronze or Silver Dwarf.";

        auto *option2 = new MahakamHorn::Strengthen;
        copyCardText(card, option2);
        option2->text = "Strengthen a unit by 7.";

        _choosen = nullptr;
        startChoiceToSelectOption(ally, enemy, card, {option1, option2});
    };

    card->_onOptionChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (!_choosen && dynamic_cast<MahakamHorn::Create *>(target)) {
            _choosen = target;
            startChoiceCreateOptions(ally, enemy, card, {isBronzeOrSilver, hasTag(Dwarf)});
            return;
        }

        if (!_choosen && dynamic_cast<MahakamHorn::Strengthen *>(target)) {
            _choosen = target;
            startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
            return;
        }

        if (dynamic_cast<MahakamHorn::Create *>(_choosen)) {
            spawnNewCard(target, ally, enemy, card);
            delete _choosen;
            _choosen = nullptr;
            return;
        }

        assert(false);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        assert(dynamic_cast<MahakamHorn::Strengthen *>(_choosen));

        strengthen(target, 7, ally, enemy, card);

        delete _choosen;
        _choosen = nullptr;
    };
    return card;
}

Card *createNaturesGift()
{
    auto *card = new Card();
    card->id = "143201";
    card->isSpecial = true;
    card->tags = { Spell };
    card->faction = Scoiatael;
    card->rarity = Silver;

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver, ::isSpecial}, AllyDeckShuffled);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}

Card *createPitTrap()
{
    auto *card = new Card();
    card->id = "200228";
    card->isSpecial = true;
    card->tags = { Item };
    card->faction = Scoiatael;
    card->rarity = Silver;

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToSelectRow(ally, enemy, card, { 3, 4, 5 });
    };

    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
        applyRowEffect(ally, enemy, screenRow, PitTrapEffect);
    };
    return card;
}

Card *createCrushingTrap()
{
    auto *card = new Card();
    card->id = "201645";
    card->isSpecial = true;
    card->tags = { Item };
    card->faction = Scoiatael;
    card->rarity = Bronze;

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToSelectRow(ally, enemy, card);
    };

    card->_onTargetRowChoosen = [=](Field &ally, Field &enemy, const int screenRow) {
        std::vector<Card *> cards = cardsInRow(ally, enemy, screenRow);
        if (cards.size() <= 0)
            return;
        Card *first;
        damage(first = cards[0], 6, ally, enemy, card);
        if (cards[cards.size()] != first)
            damage(cards[cards.size()], 6, ally, enemy, card);
    };
    return card;
}

Card *createElvenBlade()
{
    auto *card = new Card();
    card->id = "201643";
    card->isSpecial = true;
    card->tags = { Item };
    card->faction = Scoiatael;
    card->rarity = Bronze;

    card->_onPlaySpecial = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {hasNoTag(Elf)}, AnyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        damage(target, 10, ally, enemy, card);
    };
    return card;
}

Card *createIncineratingTrap()
{
    auto *card = new Card();
    card->id = "143301";
    card->power = card->powerBase = 1;
    card->tags = { Machine };
    card->isDoomed = true;
    card->isLoyal = false;
    card->faction = Scoiatael;
    card->rarity = Bronze;

    card->_onTurnEnd = [=](Field &ally, Field &enemy) {
        if (!isOnBoard(card, enemy))
            return;
        for (Card *card : cardsInRow(ally, enemy, _findScreenRow(card, ally, enemy)))
            if (card != card)
                damage(card, 2, ally, enemy, card);
        banish(card, ally, enemy, card);
    };
    return card;
}

Card *createBlueMountainElite()
{
    auto *card = new Card();
    card->id = "142316";
    card->power = card->powerBase = 3;
    card->tags = { Elf, Soldier };
    card->faction = Scoiatael;
    card->rarity = Bronze;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *copy : cardsFiltered(ally, enemy, {isCopy(card->name)}, AllyDeck))
            moveExistedUnitToPos(copy, _findRowAndPos(card, ally), ally, enemy, card);
    };

    card->_onMoveFromRowToRow = [=](Field &ally, Field &enemy) {
        boost(card, 2, ally, enemy, card);
    };
    return card;
}

Card *createDolBlathannaBomber()
{
    auto *card = new Card();
    card->id = "142316";
    card->power = card->powerBase = 6;
    card->tags = { Elf, Soldier };
    card->faction = Scoiatael;
    card->rarity = Bronze;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        spawnNewCard(new IncineratingTrap(), ally, enemy, card);
    };
    return card;
}

Card *createDolBlathannaBowman()
{
    auto *card = new Card();
    card->id = "142314";
    card->power = card->powerBase = 7;
    card->tags = { Elf, Soldier };
    card->faction = Scoiatael;
    card->rarity = Bronze;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        damage(target, 2, ally, enemy, card);
    };

    card->_onMoveFromRowToRow = [=](Field &ally, Field &enemy) {
        damage(random(cardsFiltered(ally, enemy, {}, EnemyBoard), ally.rng), 2, ally, enemy, card);
    };

    card->_onEnemyMoved = [=](Card *target, Field &ally, Field &enemy) {
        if (!isOnBoard(card, ally))
            return;
        damage(target, 2, ally, enemy, card);
    };
    return card;
}

Card *createDolBlathannaSentry()
{
    auto *card = new Card();
    card->id = "200039";
    card->power = card->powerBase = 2;
    card->tags = { Elf, Soldier };
    card->faction = Scoiatael;
    card->rarity = Bronze;

    card->_onSpecialPlayed = [=](Card *target, Field &ally, Field &enemy) {
        if(!isOnBoard(card, ally) && !isIn(card, ally.deck) && !isIn(card, ally.hand))
            return;
        if (!target->isSpecial || !(isIn(target, ally.discard) || isIn(target, ally.hand)))
            //(target != ally.cardsAppeared.end()) ??
            return;
        boost(card, 1, ally, enemy, card);
    };
    return card;
}

Card *createElvenScout()
{
    auto *card = new Card();
    card->id = "201638";
    card->power = card->powerBase = 10;
    card->tags = { Elf, Soldier };
    card->faction = Scoiatael;
    card->rarity = Bronze;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AllyHand);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        swapACard(target, ally, enemy, card);
    };
    return card;
}

Card *createElvenSwordmaster()
{
    auto *card = new Card();
    card->id = "200535";
    card->power = card->powerBase = 5;
    card->tags = { Elf, Soldier };
    card->faction = Scoiatael;
    card->rarity = Bronze;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        damage(target, power, ally, enemy, card);
    };
    return card;
}

Card *createDwarvenAgitator()
{
    auto *card = new Card();
    card->id = "200293";
    card->power = card->powerBase = 1;
    card->tags = { Dwarf, Support };
    card->faction = Scoiatael;
    card->rarity = Bronze;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (Card *card = random(cardsFiltered(ally, enemy, {isBronze, hasTag(Dwarf), isNotCopy<DwarvenAgitator>}, AllyDeck), ally.rng))
            spawnNewCard(card->defaultCopy(), ally, enemy, card);
    };
    return card;
}

Card *createDwarvenMercenary()
{
    auto *card = new Card();
    card->id = "142311";
    card->power = card->powerBase = 8;
    card->tags = { Dwarf, Soldier };
    card->faction = Scoiatael;
    card->rarity = Bronze;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        // NOTE: check if otherThan(card) required
        // TODO: fix ability, wrong filters
        startChoiceToTargetCard(ally, enemy, card, {otherThan(card)}, AnyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        // TODO: fix the in-same-line moving issue (CiaranAepEasnillen has the same)
        const Row row = _findRowAndPos(card, ally).row();
        if (isOnBoard(target, ally)) {
            boost(target, 3, ally, enemy, card);
            // TODO: check if it's check really needed, and can `moveExistedUnitToPos` work with both fields?
            if (_findRowAndPos(target, ally).row() != row)
                moveExistedUnitToPos(target, rowAndPosLastInExactRow(ally, row), ally, enemy, card);
            return;
        }
        if (isOnBoard(target, enemy) && _findRowAndPos(target, ally).row() != row) {
            moveExistedUnitToPos(target, rowAndPosLastInExactRow(enemy, row), enemy, ally, card);
            return;
        }
    };
    return card;
}

Card *createDwarvenSkirmisher()
{
    auto *card = new Card();
    card->id = "142305";
    card->power = card->powerBase = 6;
    card->tags = { Dwarf, Soldier };
    card->faction = Scoiatael;
    card->rarity = Bronze;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (!damage(target, 3, ally, enemy, card))
            boost(card, 3, ally, enemy, card);
    };
    return card;
}

Card *createHawkerHealer()
{
    auto *card = new Card();
    card->id = "142301";
    card->power = card->powerBase = 5;
    card->tags = { Elf, Support };
    card->faction = Scoiatael;
    card->rarity = Bronze;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AllyBoard, 2);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        boost(target, 3, ally, enemy, card);
    };
    return card;
}

Card *createHawkerSupport()
{
    auto *card = new Card();
    card->id = "142312";
    card->power = card->powerBase = 7;
    card->tags = { Elf, Support };
    card->faction = Scoiatael;
    card->rarity = Bronze;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AllyHand);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        boost(target, 3, ally, enemy, card);
    };
    return card;
}

Card *createMahakamDefender()
{
    auto *card = new Card();
    card->id = "142306";
    card->power = card->powerBase = 6;
    card->tags = { Dwarf, Soldier };
    card->faction = Scoiatael;
    card->rarity = Bronze;

    card->_onDeploy = [=](Field &, Field &) {
        isResilient = true;
    };
    return card;
}

Card *createMahakamGuard()
{
    auto *card = new Card();
    card->id = "142317";
    card->power = card->powerBase = 4;
    card->tags = { Dwarf, Soldier };
    card->faction = Scoiatael;
    card->rarity = Bronze;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AllyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        boost(target, 7, ally, enemy, card);
    };
    return card;
}

Card *createMahakamVolunteers()
{
    auto *card = new Card();
    card->id = "201559";
    card->power = card->powerBase = 3;
    card->tags = { Dwarf, Soldier };
    card->faction = Scoiatael;
    card->rarity = Bronze;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        for (Card *copy : cardsFiltered(ally, enemy, {isCopy(card->name)}, AllyDeck))
            moveExistedUnitToPos(copy, _findRowAndPos(card, ally), ally, enemy, card);
    };
    return card;
}

Card *createPyrotechnician()
{
    auto *card = new Card();
    card->id = "200135";
    card->power = card->powerBase = 5;
    card->tags = { Dwarf, Soldier };
    card->faction = Scoiatael;
    card->rarity = Bronze;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        for (const Row row : std::vector<Row>{Meele, Range, Seige})
            if (Card *card = random(enemy.row(row), enemy.rng))
                damage(card, 3, ally, enemy, card);
    };

    return card;
}

Card *createWardancer()
{
    auto *card = new Card();
    card->id = "142313";
    card->power = card->powerBase = 3;
    card->tags = { Elf, Soldier };
    card->faction = Scoiatael;
    card->rarity = Bronze;

    card->_onSwap = [=](Field &ally, Field &enemy) {
        moveExistedUnitToPos(card, rowAndPosRandom(ally), ally, enemy, card);
    };
    return card;
}

Card *createVriheddVanguard()
{
    auto *card = new Card();
    card->id = "142309";
    card->power = card->powerBase = 6;
    card->tags = { Elf, Soldier };
    card->faction = Scoiatael;
    card->rarity = Bronze;

    card->_onDeploy = [=](Field &ally, Field & enemy) {
        for (Card *card : cardsFiltered(ally, enemy, {hasTag(Elf)}, AllyBoard))
            boost(card, 1, ally, enemy, card);
    };

    card->_onSwap = [=](Field &ally, Field &enemy) {
        onDeploy(ally, enemy);
    };
    return card;
}

Card *createVriheddOfficer()
{
    auto *card = new Card();
    card->id = "142303";
    card->power = card->powerBase = 5;
    card->tags = { Elf, Officer };
    card->faction = Scoiatael;
    card->rarity = Bronze;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AllyHand);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        boost(card, target->powerBase, ally, enemy, card);
        swapACard(target, ally, enemy, card);
    };
    return card;
}

Card *createVriheddNeophyte()
{
    auto *card = new Card();
    card->id = "142301";
    card->power = card->powerBase = 10;
    card->tags = { Elf, Soldier };
    card->faction = Scoiatael;
    card->rarity = Bronze;

    card->_onDeploy = [=](Field &ally, Field & enemy) {
        for (Card *card : randoms(cardsFiltered(ally, enemy, {}, AllyHand), 2, ally.rng))
            boost(card, 1, ally, enemy, card);
    };
    return card;
}

Card *createVriheddBrigade()
{
    auto *card = new Card();
    card->id = "142302";
    card->power = card->powerBase = 9;
    card->tags = { Elf, Soldier };
    card->faction = Scoiatael;
    card->rarity = Bronze;

    card->_onDeploy = [=](Field &ally, Field & enemy) {
        clearHazardsFromItsRow(card, ally);
        startChoiceToTargetCard(ally, enemy, card, {}, AnyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        // TODO: fix the in-same-line moving issue (CiaranAepEasnillen and DwarvenMecenary has the same)
        const Row row = _findRowAndPos(card, ally).row();
        if (isOnBoard(target, ally) && _findRowAndPos(target, ally).row() != row) {
            moveExistedUnitToPos(target, rowAndPosLastInExactRow(ally, row), ally, enemy, card);
            return;
        }
        if (isOnBoard(target, enemy) && _findRowAndPos(target, ally).row() != row) {
            moveExistedUnitToPos(target, rowAndPosLastInExactRow(enemy, row), enemy, ally, card);
            return;
        }
    };
    return card;
}

Card *createHawkerSmuggler()
{
    auto *card = new Card();
    card->id = "142315";
    card->power = card->powerBase = 7;
    card->tags = { Elf, Support };
    card->faction = Scoiatael;
    card->rarity = Bronze;

    card->_onOtherEnemyAppears = [=](Card *, Field &ally, Field &enemy) {
        // TODO: check how should it works with cases like resurrect, spawn, summon
        // maybe have to replace onOtherEnemyAppears call
        if (!isOnBoard(card, ally))
            return;
        boost(card, 1, ally, enemy, card);
    };
    return card;
}

Card *createMennoCoehoorn()
{
    auto *card = new Card();
    card->id = "162102";
    card->power = card->powerBase = 8;
    card->tags = { Officer };
    card->faction = Nilfgaard;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field & enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (target->isSpy == false)
            return putToDiscard(target, ally, enemy, card);
        damage(target, 4, ally, enemy, card);
    };
    return card;
}

Card *createRainfarnOfAttre()
{
    auto *card = new Card();
    card->id = "200032";
    card->power = card->powerBase = 5;
    card->tags = { Officer };
    card->faction = Nilfgaard;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field & enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isSpying, isBronzeOrSilver}, AllyDeckShuffled);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}

Card *createAssassination()
{
    auto *card = new Card();
    card->id = "163101";
    card->isSpecial = true;
    card->tags = { Tactics };
    card->faction = Nilfgaard;
    card->rarity = Gold;

    card->_onPlaySpecial = [=](Field &ally, Field & enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
        startChoiceToTargetCard(ally, enemy, card, {}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        damage(target, 8, ally, enemy, card);
    };

    return card;
}

Card *createStefanSkellen()
{
    auto *card = new Card();
    card->id = "162106";
    card->power = card->powerBase = 10;
    card->tags = { Officer };
    card->faction = Nilfgaard;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, AllyDeckShuffled);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        putToDeck(target, ally, enemy, DeckPosTop, card);
        if (!target->isSpecial && !target->isSpy)
            boost(target, 5, ally, enemy, card);
    };
    return card;
}

Card *createShilard()
{
    auto *card = new Card();
    card->id = "200071";
    card->power = card->powerBase = 9;
    card->tags = { Officer };
    card->faction = Nilfgaard;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (ally.passed || enemy.passed)
            return;
        std::vector<Card *> variants;
        if ((_allyCard = first(cardsFiltered(ally, enemy, {}, AllyDeck))))
            variants.push_back(_allyCard);
        if ((_enemyCard = random(cardsFiltered(ally, enemy, {}, EnemyDeck), ally.rng)))
            variants.push_back(_enemyCard);
        startChoiceToTargetCard(ally, enemy, card, variants);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        putToHand(target, ally, enemy, card);
        if (target == _allyCard && _enemyCard)
            putToHand(_enemyCard, enemy, ally, card);
        else if (target == _enemyCard && _allyCard)
            putToHand(_allyCard, enemy, ally, card);
    };
    return card;
}

Card *createXarthisius()
{
    auto *card = new Card();
    card->id = "162108";
    card->power = card->powerBase = 13;
    card->tags = { Mage };
    card->faction = Nilfgaard;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {}, EnemyDeck);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        putToDeck(target, enemy, ally, DeckPosBottom, card);
    };
    return card;
}

Card *createCantarella()
{
    auto *card = new Card();
    card->id = "162108";
    card->power = card->powerBase = 13;
    card->tags = {};
    card->isLoyal = false;
    card->faction = Nilfgaard;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        if (tick(card, ally, enemy)) {
            Card *firstCard = first(cardsFiltered(ally, enemy, {}, AllyDeck));
            Card *secondCard = first(cardsFiltered(ally, enemy, {}, AllyDeck));
            if (firstCard) {
                putToHand(firstCard, ally, enemy,  card);
            }
            if (secondCard) {
                putToHand(secondCard, ally, enemy,  card);
            }
            if (!firstCard || !secondCard)
                return;
            _drawn.push_back(firstCard);
            _drawn.push_back(secondCard);
            startChoiceToTargetCard(ally, enemy, card, _drawn);
        }
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        for (Card *card : _drawn)
            if (card != target)
                putToDeck(card, ally, enemy, DeckPosBottom, card);
        _drawn.clear();
    };
    return card;
}

Card *createPanther()
{
    auto *card = new Card();
    card->id = "200139";
    card->power = card->powerBase = 4;
    card->tags = { Beast };
    card->faction = Scoiatael;
    card->rarity = Bronze;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        const Field *enemyPtr = &enemy;
        const auto isOk = [enemyPtr](Card *card) {
            const Row row = _findRowAndPos(card, *enemyPtr).row();
            return enemyPtr->row(row).size() < 4;
        };
        startChoiceToTargetCard(ally, enemy, card, {isOk}, EnemyBoard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        damage(target, 7, ally, enemy, card);
    };
    return card;
}

Card *createVicovaroMedic()
{
    auto *card = new Card();
    card->id = "162304";
    card->power = card->powerBase = 1;
    card->tags = { Support };
    card->isDoomed = true;
    card->faction = Nilfgaard;
    card->rarity = Bronze;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronze, isUnit}, EnemyDiscard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        playExistedCard(target, ally, enemy, card);
    };
    return card;
}

Card *createAssireVarAnahid()
{
    auto *card = new Card();
    card->id = "162202";
    card->power = card->powerBase = 11;
    card->tags = { Mage };
    card->faction = Nilfgaard;
    card->rarity = Gold;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver}, AllyDiscard);
        startChoiceToTargetCard(ally, enemy, card, {isBronzeOrSilver}, EnemyDiscard);
    };

    card->_onTargetChoosen = [=](Card *target, Field &ally, Field &enemy) {
        if (isIn(target, ally.discard)){
            putToDeck(target, ally, enemy, DeckPosRandom, card);
            return;
        }
        else if (isIn(target, enemy.discard)){
            putToDeck(target, enemy, ally, DeckPosRandom, card);
            return;
        }
        assert(false);
    };
    return card;
}

Card *createFringillaVigo()
{
    auto *card = new Card();
    card->id = "162205";
    card->power = card->powerBase = 1;
    card->isLoyal = false;
    card->tags = { Mage };
    card->faction = Nilfgaard;
    card->rarity = Silver;

    card->_onDeploy = [=](Field &ally, Field &enemy) {
        Card *left = cardNextTo(card, ally, enemy, -1);
        Card *right = cardNextTo(card, ally, enemy, 1);
        if (left != nullptr && right != nullptr)
            setPower(right, left->power, ally, enemy, card);
    };
    return card;
}

Card *createFalseCiri()
{
    auto *card = new Card();
    card->id = "162212";
    card->power = card->powerBase = 8;
    card->isLoyal = false;
    card->tags = { };
    card->faction = Nilfgaard;
    card->rarity = Silver;

    card->_onTurnStart = [=](Field &ally, Field &enemy) {
        if (!this->isLoyal)
            boost(card, 1, ally, enemy, card);
    };

    card->_onDestroy = [=](Field &ally, Field &enemy, const RowAndPos &rowAndPos) {
        if (Card *card = lowest(cardsInRow(ally, enemy, rowAndPos.row()), ally.rng))
            putToDiscard(card, ally, enemy, card);
    };

    card->_onAllyPass = [=](Field &ally, Field &enemy) {
        // NOTE: for spying creatures logic of this event is inverted
        // so an ally is an original enemy for FalseCiri
        if (!this->isLoyal) {
            const Row row = _findRowAndPos(card, ally).row();
            moveExistedUnitToPos(card, rowAndPosLastInExactRow(enemy, row), enemy, ally, card);
        }
    };
    return card;
}

}
