#include "Cards/archieve.h"
#include "Cards/testcase.h"


int main()
{
    Cards cards;
    Card *adda = cards.createAddaStriga();
    Card *mandrake = cards.createMandrake();

    Field ally;
    ally.cardsAdded = {adda, mandrake};
    ally.rowMeele = {adda};

    Field enemy;
    mandrake->onPlaySpecial(ally, enemy);

    assert_(!ally.cardStack2.isEmpty());
    const Choice choice = ally.cardStack2.peek();
    assert_(2 == choice.options.size());

    Card *option1 = choice.options.at(0);
    assert_(isOption(option1, 0));
    assert_(option1->isSpecial);
    assert_(mandrake->id == option1->id);

    Card *option2 = choice.options.at(1);
    assert_(isOption(option2, 1));
    assert_(option2->isSpecial);
    assert_(mandrake->id == option2->id);

    onChoiceDoneCard(option1, ally, enemy);
    assert_(12 == adda->powerBase);

    delete adda;
    delete mandrake;
    pass_();
    return 0;
}