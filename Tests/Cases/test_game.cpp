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

#include <cassert>

#include "Cards/archieve.h"


int main(int argc, char **argv)
{
    Card *adda = new AddaStriga();
    adda->power = 10;

    Card *addaRef = adda;
    assert(10 == addaRef->power);
    assert(adda->id == addaRef->id);

    Card *addaDefault = adda->defaultCopy();
    assert(6 == addaDefault->power);
    assert(adda->id == addaDefault->id);

    Card *addaDuplicate = adda->exactCopy();
    assert(10 == addaDuplicate->power);
    assert(adda->id == addaDuplicate->id);

    delete adda;
    delete addaDefault;
    delete addaDuplicate;


    struct State1 : StateCopy<State1>
    {
        int x = 42;
    };

    State *state1 = new State1();
    assert(dynamic_cast<State1 *>(state1));
    assert(42 == static_cast<State1 *>(state1)->x);

    static_cast<State1 *>(state1)->x = 69;
    State* state2 = state1->exactCopy();
    assert(69 == static_cast<State1 *>(state2)->x);

    State* state3 = state1->defaultCopy();
    assert(42 == static_cast<State1 *>(state3)->x);

    delete state1;
    delete state2;
    delete state3;


    Card *card = new AddaStriga();
    Card *card1 = card->copy();
    assert(card1->id == card->id);

    card->power = 10;
    Card *card2 = card->copy();
    assert(card2->id == card->id);
    assert(10 == card2->power);
    assert(6 == card1->power);

    delete card;
    delete card1;
    delete card2;


    return 0;
}

#endif
