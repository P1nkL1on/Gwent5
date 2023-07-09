#include "Cards/archieve.h"
#include "Cards/testcase.h"


#ifdef QT_TESTS
inline int exactCopyDolBlathannaArcher()
#else
int main()
#endif
{
    Cards cards;
    Card *archer = cards.createDolBlathannaArcher();
    Card *adda = cards.createAddaStriga();
    Card *adda2 = cards.createAddaStriga();

    Field ally;
    ally.cardsAdded = {archer};
    ally.rowRange = {archer};

    // NOTE: creating 2 enemies to
    // prevent choice autoresolving
    Field enemy;
    enemy.cardsAdded = {adda, adda2};
    enemy.rowRange = {adda, adda2};

    assert_(ally.cardStack2.isEmpty());
    archer->onDeploy(ally, enemy);
    assert_(!ally.cardStack2.isEmpty());
    assert_(6 == adda->power);

    onChoiceDoneCard(adda, ally, enemy);
    assert_(3 == adda->power);

    // NOTE: copying archer with intermediate state,
    // so after using his ability he will shot once
    Card *archerCopy = archer->exactCopy();
    ally.cardsAdded.push_back(archerCopy);

    onChoiceDoneCard(adda, ally, enemy);
    assert_(2 == adda->power);

    archerCopy->onTargetChoosen(adda, ally, enemy);
    assert_(1 == adda->power);

    delete adda;
    delete adda2;
    delete archer;
    delete archerCopy;
    pass_();
    return 0;
}
