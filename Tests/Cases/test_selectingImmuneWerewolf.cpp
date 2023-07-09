#include "Cards/archieve.h"
#include "Cards/testcase.h"


#ifdef QT_TESTS
inline int selectingImmuneWerewolf()
#else
int main()
#endif
{
    {
        // NOTE: selecting wolf from field
        Cards cards;
        Card *wolf = cards.createWerewolf();
        Card *arba = cards.createDeithwenArbalest();

        Field ally;
        ally.cardsAdded = {arba};
        ally.rowRange = {arba};
        assert_(7 == wolf->power);

        Field enemy;
        enemy.cardsAdded = {wolf};
        enemy.rowMeele = {wolf};

        // NOTE: choice is automatically done
        // with zero acceptable targets (immune)
        arba->onDeploy(ally, enemy);
        assert_(7 == wolf->power);

        delete wolf;
        delete arba;
    }
    {
        // NOTE: selecting wolf from deck
        Cards cards;
        Card *wolf = cards.createWerewolf();
        Card *wolf2 = cards.createWerewolf();
        Card *reco = cards.createReconnaissance();

        Field ally;
        Field enemy;
        ally.cardsAdded = {wolf, wolf2, reco};
        ally.deck = {wolf, wolf2};
        ally.hand = {reco};

        reco->onPlaySpecial(ally, enemy);
        assert_(!ally.cardStack2.isEmpty());

        const Choice choice = ally.cardStack2.peek();
        assert_(2 == choice.options.size());
        assert_(isIn(wolf, choice.options));
        assert_(isIn(wolf2, choice.options));

        delete reco;
        delete wolf;
        delete wolf2;
    }
    pass_();
    return 0;
}
