#include "Cards/archieve.h"
#include "Cards/card.h"
#include "Cards/testcase.h"


int main()
{
    Field ally;
    Field enemy;
    Card *vanguard = new VriheddVanguard();
    Card *neophyte = new VriheddNeophyte();
    Card *scout    = new ElvenScout();

    ally.cardsAdded = {};
    ally.hand = {scout, vanguard};
    ally.rowMeele = {neophyte};

    Testcase testcase;
    testcase.add(neophyte->power, 10);
    testcase.add(scout->power, 10);

    // swapping while count is in hand should boost neophyte only
    swapACard(vanguard, ally, enemy, scout);
    testcase.add(neophyte->power, 11, "Should proc while deck is empty");
    testcase.add(scout->power, 10);

    // swapping again, but putting a scout to the deck
    // it should garantee working, and drawing scout next
    ally.hand = {vanguard};
    ally.deck = {scout};
    swapACard(vanguard, ally, enemy, scout);
    testcase.add(neophyte->power, 12, "Should proc while deck isn't empty");
    testcase.add(scout->power, 10);
    testcase.add(ally.hand == std::vector<Card *>{scout}, 1, "Should draw another card after swap");
    testcase.add(ally.deck == std::vector<Card *>{vanguard}, 1);

    return testcase.process();
}
