#include "Cards/archieve.h"
#include "Cards/testcase.h"


int main()
{
    Cards cards;
    Card *archer = cards.createDolBlathannaArcher();
    Card *dao = cards.createDao();

    Field ally;
    ally.cardsAdded = {archer};
    ally.rowRange = {archer};

    Field enemy;
    enemy.cardsAdded = {dao};
    enemy.rowRange = {dao};
    dao->power = 2;

    // NOTE: autochoosing dao and destroying it
    archer->onDeploy(ally, enemy);
    assert_(std::vector<Card *>{dao} == enemy.discard);

    assert_(!ally.cardStack2.isEmpty());
    const Choice choice = ally.cardStack2.peek();

    assert_(2 == choice.options.size());
    const Card *daoLesser = choice.options.at(0);
    assert_("132405" == daoLesser->id);
    assert_(4 == daoLesser->power);

    const Card *daoLesser2 = choice.options.at(1);

    delete archer;
    delete dao;
    delete daoLesser;
    delete daoLesser2;
    pass_();
    return 0;
}