#include "Cards/archieve.h"
#include "Cards/testcase.h"


#ifdef QT_TESTS
inline int defaultCopyHalfElfHunter()
#else
int main()
#endif
{
    Cards cards;
    Card *hunter = cards.createHalfElfHunter();
    hunter->power = 8;

    Field ally;
    ally.cardsAdded = {hunter};
    ally.rowMeele = {hunter};

    Field enemy;
    hunter->onDeploy(ally, enemy);
    Card *copy = ally.rowMeele.at(1);
    assert_(hunter->id == copy->id);
    assert_(8 == hunter->power);
    assert_(6 == copy->power);
    assert_(2 == ally.rowMeele.size());

    delete hunter;
    delete copy;
    pass_();
    return 0;
}
