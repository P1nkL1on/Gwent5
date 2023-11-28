#include "textsen.h"

#include <vector>


std::map<std::string, std::string> keywordDescriptions(const Patch)
{
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
                        })},
        {"122201", Info(
                        "Dandelion",
                        "Boost 3 units in your deck by 2.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/DAND_Q302_00490269.mp3",
                            "https://gwent.one/audio/card/ob/en/DAND_DANDELION_00429307.mp3",
                            "https://gwent.one/audio/card/ob/en/DAND_Q302_00489393.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_JSKR_100926_0188.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.5.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.6.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.7.mp3",
                        })},
        {"201621", Info(
                        "Kiyan",
                        "Choose One: Create a Bronze or Silver Alchemy card; or Play a Bronze or Silver Item from your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.14.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.15.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.16.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.17.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.18.mp3",
                        })},

        {"122104", Info(
                        "Philippa Eilhart",
                        "Deal 5 damage to an enemy, then deal 4, 3, 2 and 1 damage to random enemies. Cannot damage the same enemy twice in a row.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/PHIL_Q502_00555967.mp3",
                            "https://gwent.one/audio/card/ob/en/PHIL_Q310_00533376.mp3",
                            "https://gwent.one/audio/card/ob/en/PHIL_PHILIPPA_01041426.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_FLPA_200102_0065.mp3",
                            "https://gwent.one/audio/card/ob/en/PHIL_PHILIPPA_01041424.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_FLPA_300358_0012.mp3",
                        })},

        {"201777", Info(
                        "Roche: Merciless",
                        "Destroy a face-down Ambush enemy.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/ROCH_ROCHE_00541126.mp3",
                            "https://gwent.one/audio/card/ob/en/ROCH_MQ3035_01064844.mp3",
                        })},
        {"122106", Info(
                        "Shani",
                        "Resurrect a non-Cursed Bronze or Silver unit and give it 2 Armor.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SHNI_SHANI_01130725.mp3",
                            "https://gwent.one/audio/card/ob/en/SHNI_Q601_01101942.mp3",
                            "https://gwent.one/audio/card/ob/en/SHNI_Q602_01119358.mp3",
                        })},
        {"201620", Info(
                        "Vandergrift",
                        "Deal 1 damage to all enemies. If a unit is destroyed, apply Ragh Nar Roog to its row.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.11.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.10.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.9.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.8.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.7.mp3",
                        })},
        {"122401", Info(
                        "Botchling",
                        "Summon a Lubberkin to this row.")},
        {"122402", Info(
                        "Lubberkin",
                        "Summon a Botchling to this row.")},
        {"201699", Info(
                        "Nilfgaardian Gate",
                        "Play a Bronze or Silver Officer from your deck and boost it by 1.")},
        {"162204", Info(
                        "Peter Saar Gwynleve",
                        "Reset an ally and Strengthen it by 3; or Reset an enemy and Weaken it by 3.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.426.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.427.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.428.mp3",
                        })},
        {"122403", Info(
                        "Vicovaro Novice",
                        "Look at 2 random Bronze Alchemy cards from your deck, then play 1.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.820.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.821.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.819.mp3",
                        })},
        {"201662", Info(
                        "Cadaverine",
                        "Choose One: Deal 2 damage to an enemy and all units that share its categories; or Destroy a Bronze or Silver Neutral unit.")},
        {"162211", Info(
                        "Joachim de Wett",
                        "Spying. Play the top non-Spying Bronze or Silver unit from your deck and boost it by 10.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.19.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.18.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.17.mp3",
                        })},
        {"163201", Info(
                        "Treason",
                        "Force 2 adjacent enemies to Duel each other.")},
        {"162207", Info(
                        "Vanhemar",
                        "Spawn Biting Frost, Clear Skies or Shrike.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_NM01_200057_0187.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_NM01_200996_0005.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_NM01_200049_0007.mp3",
                        })},
        {"201664", Info(
                        "Vrygheff",
                        "Play a Bronze Machine from your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.256.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.255.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.253.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.254.mp3",
                        })},
        {"162311", Info(
                        "Alba Pikeman",
                        "Summon all copies of this unit to this row.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/NILF3_VSET_00514121.mp3",
                            "https://gwent.one/audio/card/ob/en/NILF3_VSET_00514091.mp3",
                            "https://gwent.one/audio/card/ob/en/NILF3_VSET_00514113.mp3",
                        })},
        {"162313", Info(
                        "Combat Engineer",
                        "Boost an ally by 5. Crew.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/NILF2_Q502_00556520.mp3",
                            "https://gwent.one/audio/card/ob/en/NILF2_VSET_00513907.mp3",
                            "https://gwent.one/audio/card/ob/en/NILF2_VSET_01072393.mp3",
                        })},
        {"200044", Info(
                        "Magne Division",
                        "Play a random Bronze Item from your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.35.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.37.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.36.mp3",
                        })},
        {"162310", Info(
                        "Nauzicaa Brigade",
                        "Deal 7 damage to a Spying unit. If it was destroyed, Strengthen self by 4.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/NILF2_VSET_00513916.mp3",
                            "https://gwent.one/audio/card/ob/en/NILF2_VSET_00513914.mp3",
                            "https://gwent.one/audio/card/ob/en/NILF2_VSET_00513922.mp3",
                        })},
        {"201612", Info(
                        "Slave Driver",
                        "Set an ally's power to 1 and deal damage to an enemy by the amount of power lost.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.113.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.114.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.115.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.116.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.117.mp3",
                        })},
        {"201609", Info(
                        "Slave Hunter",
                        "Charm a Bronze enemy with 3 power or less.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.105.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.104.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.103.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.106.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.107.mp3",
                        })},
        {"200124", Info(
                        "Viper Witcher",
                        "Deal 1 damage for each Alchemy card in your starting deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.339.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.338.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.337.mp3",
                        })},
        {"162302", Info(
                        "Rot Tosser",
                        "Spawn a Cow Carcass on an enemy row.")},
        {"162402", Info(
                        "Cow Carcass",
                        "Spying. After 2 turns, destroy all the other Lowest units on the row and Banish self on turn end.")},
        {"200294", Info(
                        "Standard Bearer",
                        "Boost an ally by 2 whenever you play a Soldier.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.338.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.339.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.340.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.341.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.342.mp3",
                        })},
        {"122211", Info(
                        "Margarita of Aretuza",
                        "Reset a unit and toggle its Lock status.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/MGLA_Q210_00584250.mp3",
                            "https://gwent.one/audio/card/ob/en/MGLA_Q310_00562485.mp3",
                            "https://gwent.one/audio/card/ob/en/MGLA_MARGARITTA_01012961.mp3",
                        })},
        {"122212", Info(
                        "Nenneke",
                        "Return 3 Bronze or Silver units from the graveyard to your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.43.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.42.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries.44.mp3",
                        })},
        {"201650", Info(
                        "Sabrina's Specter",
                        "Resurrect a Bronze Cursed unit.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_SABR_200216_0064.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_SABR_200216_0101.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_SABR_200216_0037.mp3",
                        })},
        {"122206", Info(
                        "Sabrina Glevissig",
                        "Spying. Deathwish: Set the power of all units on the row to the power of the Lowest unit on the row.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/VO_SABR_200216_0064.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_SABR_200216_0101.mp3",
                            "https://gwent.one/audio/card/ob/en/VO_SABR_200216_0037.mp3",
                        })},
        {"122203", Info(
                        "Thaler",
                        "Spying. Single-Use: Draw 2 cards, keep one and return the other to your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/TALA_SQ315_01067599.mp3",
                            "https://gwent.one/audio/card/ob/en/TALA_SQ315_01067657.mp3",
                            "https://gwent.one/audio/card/ob/en/TALA_SQ315_01067677.mp3",
                        })},
        {"200540", Info(
                        "Aedirnian Mauler",
                        "Deal 4 damage to an enemy.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.82.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.81.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.80.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.79.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part4.78.mp3",
                        })},
        {"200033", Info(
                        "Aretuza Adept",
                        "Play a random Bronze Hazard from your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.376.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.377.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.378.mp3",
                        })},
        {"201648", Info(
                        "Vandergrift's Blade",
                        "Choose One: Destroy a Bronze or Silver Cursed enemy; or Deal 9 damage and, if the unit was destroyed,,Banish it.")},
        {"122315", Info(
                        "Reinforced Trebuchet",
                        "Deal 1 damage to a random enemy on turn end.")},
        {"122301", Info(
                        "Ballista",
                        "Deal 1 damage to an enemy and 4 other random enemies with the same power. Crewed: Repeat its,ability.")},
        {"201633", Info(
                        "Bloody Flail",
                        "Deal 5 damage and Spawn a Specter on a random row.")},
        {"201633", Info("Specter")},
        {"200049", Info(
                        "Battering Ram",
                        "Deal 3 damage to an enemy. If it's destroyed, deal 3 damage to another enemy. Crewed: Increase,initial damage by 1.")},
        {"122303", Info(
                        "Trebuchet",
                        "Deal 1 damage to 3 adjacent enemies. Crewed: Increase damage by 1.")},
        {"200048", Info(
                        "Ban Ard Tutor",
                        "Swap a card in your hand with a Bronze special card from your deck.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.13.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.14.mp3",
                            "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part3.15.mp3",
                        })},
        {"122312", Info(
                        "Field Medic",
                        "Boost Soldier allies by 1.",
                        Urls{
                            "https://gwent.one/audio/card/ob/en/NCIW1_VSET_00566917.mp3",
                            "https://gwent.one/audio/card/ob/en/NCIW1_VSET_00564889.mp3",
                            "https://gwent.one/audio/card/ob/en/NCIW1_VSET_00564891.mp3",
                        })},
        {"201748", Info(
                       "Foltest's Pride",
                       "Deal 2 damage to an enemy and move it to the row above. Crewed: Repeat its ability.")},
        {"201630", Info(
                       "Damned Sorceress",
                       "If there is a Cursed unit on this row, deal 7 damage.",
                       Urls{
                           "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.52.mp3",
                           "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.51.mp3",
                           "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.53.mp3",
                           "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.50.mp3",
                           "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.54.mp3",
                       })},
        {"201624", Info(
                       "Kaedweni Revenant",
                       "When you play your next Spell or Item, Spawn a Doomed default copy of this unit on its row. 1 Armor.",
                       Urls{
                           "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.41.mp3",
                           "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.40.mp3",
                           "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.42.mp3",
                           "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.38.mp3",
                           "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.39.mp3",
                       })},
        {"201628", Info(
                       "Tormented Mage",
                       "Look at 2 Bronze Spells or Items from your deck, then play 1.",
                       Urls{
                           "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.58.mp3",
                           "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.59.mp3",
                           "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.57.mp3",
                           "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.56.mp3",
                           "https://gwent.one/audio/card/ob/en/SAY.Battlecries_part5.60.mp3",
                       })},
        {"122304", Info(
                       "Siege Tower",
                       "Boost self by 2. Crewed: Repeat its ability.",
                       )},
    };
    // return infos;
}
