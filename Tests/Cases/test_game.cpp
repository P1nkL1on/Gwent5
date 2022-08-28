#include "Cards/testcase.h"
#include "Cards/card.h"

const char* actionTypeName[] = {
    "Invalid",
    "TurnStart",
    "PassedAlly",
    "PassedEnemy",
    "WonRoundAlly",
    "WonRoundEnemy",
    "WonRoundBoth",
    "WonGameAlly",
    "WonGameEnemy",
    "WonGameBoth",
    "RoundStart",
    "MulliganSkipAlly",
    "MulliganSkipEnemy",
    "PlaySpecial",
    "PutOnField",
    "PutToHand",
    "PutToDiscard",
    "PutToTopDeck",
    "PutToBottomDeck",
    "ShuffleToDeck",
    "Destroyed",
    "Banished",
    "DealDamage",
    "Damaged",
    "DamagedInArmor",
    "Weakened",
    "ResetAsInDeckBuilder",
    "ResetInPower",
    "StrippedOfAllStatuses",
    "Boosted",
    "Strengthened",
    "Healed",
    "HealedBy",
    "GainArmor",
    "MoveFromRowToRow",
    "TimerSet",
    "FlipOver",
    "GainLock",
    "LostLock",
    "GainSpy",
    "LostSpy",
    "Reveal",
    "Conceal",
    "Transform",
};

int main()
{
    {
        std::cout << "---------" << std::endl;
        Field ally;
        Field enemy;
        Testcase testcase;
        startNextRound(ally, enemy);
        for (size_t i = 0; i < ally.snapshots.size(); ++i)
            std::cout << i << ") " << actionTypeName[ally.snapshots[i].actionType]
                      << " \t" << ally.snapshots[i].actionValue << std::endl;
    }
    {
        std::cout << "---------" << std::endl;
        Field ally;
        Field enemy;
        auto *c = new Card;
        c->power = c->powerBase = 1;
        ally.rowMeele = {c};

        Testcase testcase;
        startNextRound(ally, enemy);
        for (size_t i = 0; i < ally.snapshots.size(); ++i)
            std::cout << i << ") " << actionTypeName[ally.snapshots[i].actionType]
                      << " \t" << ally.snapshots[i].actionValue << std::endl;
    }

    return 0;


//    testcase.add(int(ally.snapshots.size()), 9, "Number of snapshots");
//    if (testcase.process())
//        return 1;

//    std::vector<Card *> cards;
//    for (int i = 0; i < 25; ++i) {
//        auto *card = new Card();
//        card->name = std::to_string(i);
//        card->power = card->powerBase = i + 1;
//        cards.push_back(card);
//    }

//    testcase.add(ally.snapshots[0].actionType, RoundStart, "Round Start");
//    testcase.add(ally.snapshots[0].actionValue, 1, "Round number");
//    testcase.add(ally.snapshots[1].actionType, MulliganSkipEnemy, "Round Mulligan Skip");
//    testcase.add(ally.snapshots[1].actionValue, 3, "Cards to mulligan");
//    testcase.add(ally.snapshots[2].actionType, PassedAlly, "Passed Ally");
//    testcase.add(ally.snapshots[2].actionValue, -1, "No info");
//    testcase.add(ally.snapshots[3].actionType, PassedEnemy, "Passed Enemy");
//    testcase.add(ally.snapshots[3].actionValue, -1, "No info");
//    testcase.add(ally.snapshots[4].actionType, WonRoundBoth, "Won Round Both");
//    testcase.add(ally.snapshots[4].actionValue, 1, "Round number");
//    testcase.add(ally.snapshots[5].actionType, RoundStart, "Round Start");
//    testcase.add(ally.snapshots[5].actionValue, 2, "Round number");
//    testcase.add(ally.snapshots[6].actionType, MulliganSkipEnemy, "Round Mulligan Skip");
//    testcase.add(ally.snapshots[6].actionValue, 1, "Cards to mulligan");
//    testcase.add(ally.snapshots[7].actionType, WonRoundBoth, "Won Round Both");
//    testcase.add(ally.snapshots[7].actionValue, 2, "Round number");
//    testcase.add(ally.snapshots[8].actionType, WonGameBoth, "Won Game Both");
//    testcase.add(ally.snapshots[8].actionValue, -1, "No info");

//    return testcase.process();
}
