#include "Cards/archieve.h"
#include "Cards/testcase.h"


int main()
{
    Cards cards;
    Card *comp = cards.createArtefactCompression();
    Card *knight = cards.createRedanianKnight();

    Field ally;
    Field enemy;
    ally.cardsAdded = {comp, knight};
    ally.rowMeele = {knight};

    assert_("122308" == knight->id);
    assert_(7 == knight->power);
    assert_(0 == knight->armor);
    knight->onTurnEnd(ally, enemy);
    assert_(9 == knight->power);
    assert_(2 == knight->armor);

    // NOTE: target is autoselected
    comp->onPlaySpecial(ally, enemy);
    assert_("200053" == knight->id);
    assert_(2 == knight->power);
    assert_(0 == knight->armor);

    // NOTE: ability removed
    knight->onTurnEnd(ally, enemy);
    assert_(2 == knight->power);
    assert_(0 == knight->armor);

    delete comp;
    delete knight;
    pass_();
    return 0;
}
