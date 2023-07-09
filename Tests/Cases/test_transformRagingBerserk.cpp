#include "Cards/archieve.h"
#include "Cards/testcase.h"


int main()
{
    Cards cards;
    Card *bear = cards.createRagingBerserker();
    Card *venom = cards.createArachasVenom();

    Field ally;
    Field enemy;
    ally.cardsAdded = {bear, venom};
    ally.rowMeele = {bear};

    assert_("152301" == bear->id);
    assert_(8 == bear->power);
    bear->onTurnEnd(ally, enemy);

    // NOTE: target is autoselected
    venom->onPlaySpecial(ally, enemy);
    assert_("152405" == bear->id);
    assert_(12 == bear->power);
    assert_(0 == bear->armor);

    delete bear;
    delete venom;
    pass_();
    return 0;
}
