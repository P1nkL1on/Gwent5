#include "Cards/archieve.h"
#include "Cards/testcase.h"


int main()
{
    Cards cards;
    Card *fila = cards.createFilavandrel();

    Field ally;
    ally.cardsAll = cards.createAll();

    Field enemy;
    fila->onDeploy(ally, enemy);
    assert_(!ally.cardStack2.isEmpty());

    const Choice choice = ally.cardStack2.peek();
    assert_(choice.options.size() >= 1);

    for (Card *card : choice.options) {
        assert_(card->isSpecial);
        delete card;
    }
    delete fila;
    pass_();
    return 0;
}