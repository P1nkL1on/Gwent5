// #define CMAKE_TESTS
#ifdef  CMAKE_TESTS
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
    Field ally;
    Field enemy;
    initField({}, nullptr, ally);
    initField({}, nullptr, enemy);
    startNextRound(ally, enemy);
    Testcase testcase;
    if (testcase.add(int(ally.snapshots.size()), 13, "Snapshots count and data:")) {
        testcase.add(ally.snapshots[0].actionType, RoundStart, "RoundStart");
        testcase.add(ally.snapshots[1].actionType, MulliganSkipAlly, "MulliganSkipAlly");
        testcase.add(ally.snapshots[2].actionType, MulliganSkipEnemy, "MulliganSkipEnemy");
        testcase.add(ally.snapshots[3].actionType, PassedAlly, "PassedAlly");
        testcase.add(ally.snapshots[4].actionType, PassedEnemy, "PassedEnemy");
        testcase.add(ally.snapshots[5].actionType, WonRoundBoth, "WonRoundBoth");
        testcase.add(ally.snapshots[6].actionType, RoundStart, "RoundStart");
        testcase.add(ally.snapshots[7].actionType, MulliganSkipAlly, "MulliganSkipAlly");
        testcase.add(ally.snapshots[8].actionType, MulliganSkipEnemy, "MulliganSkipEnemy");
        testcase.add(ally.snapshots[9].actionType, PassedEnemy, "PassedEnemy"); // swap order after draw
        testcase.add(ally.snapshots[10].actionType, PassedAlly, "PassedAlly");
        testcase.add(ally.snapshots[11].actionType, WonRoundBoth, "WonRoundBoth");
        testcase.add(ally.snapshots[12].actionType, WonGameBoth, "WonGameBoth");
    }

    initField({}, nullptr, ally);
    initField({}, nullptr, enemy);
    auto *c = new Card;
    c->power = c->powerBase = 1;
    ally.rowMeele = {c};
    startNextRound(ally, enemy);
    if (testcase.add(int(ally.snapshots.size()), 15, "Snapshots count and data:")) {
        testcase.add(ally.snapshots[0].actionType, RoundStart, "RoundStart");
        testcase.add(ally.snapshots[1].actionType, MulliganSkipAlly, "MulliganSkipAlly");
        testcase.add(ally.snapshots[2].actionType, MulliganSkipEnemy, "MulliganSkipEnemy");
        testcase.add(ally.snapshots[3].actionType, PassedAlly, "PassedAlly");
        testcase.add(ally.snapshots[4].actionType, PassedEnemy, "PassedEnemy");
        testcase.add(ally.snapshots[5].actionType, WonRoundAlly, "WonRoundAlly");
        testcase.add(ally.snapshots[6].actionType, ResetInPower, "ResetInPower");
        testcase.add(ally.snapshots[7].actionType, Destroyed, "Destroyed");
        testcase.add(ally.snapshots[8].actionType, RoundStart, "RoundStart");
        testcase.add(ally.snapshots[9].actionType, MulliganSkipAlly, "MulliganSkipAlly");
        testcase.add(ally.snapshots[10].actionType, MulliganSkipEnemy, "MulliganSkipEnemy");
        testcase.add(ally.snapshots[11].actionType, PassedAlly, "PassedAlly"); // winner goes first
        testcase.add(ally.snapshots[12].actionType, PassedEnemy, "PassedEnemy");
        testcase.add(ally.snapshots[13].actionType, WonRoundBoth, "WonRoundBoth");
        testcase.add(ally.snapshots[14].actionType, WonGameAlly, "WonGameAlly");
    }

    return testcase.process();
}

#else

#include "tests.h"


int main(int argc, char **argv)
{
    using namespace Tests;
    return testStateCopyVsExactCopy()
            + testStatelessCardCopyVsExactCopy()
            + testStateCopyBlathannaArcher()
            + testBlathannaArcherSeparatedShots()
            + testHalfElfHunder()
            + testOptionsMandrake()
            + testCreateFilavandrel()
            ;
}

#endif
