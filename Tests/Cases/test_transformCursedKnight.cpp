#include "Cards/archieve.h"
#include "Cards/testcase.h"


int main()
{
    {
        // NOTE: moving std function
        // and removing the source t
        int counter = 0;
        struct T
        {
            std::function<void()> foo = nullptr;
        };

        T *t = new T();
        t->foo = [&counter]{ ++counter; };
        t->foo();
        assert_(1 == counter);

        T *t2 = new T();
        t2->foo = t->foo;
        t2->foo();
        assert_(2 == counter);

        delete t;
        t2->foo();
        assert_(3 == counter);
        delete t2;
    }
    {
        Cards cards;
        Card *knight = cards.createCursedKnight();
        Card *copy = knight->defaultCopy();
        Card *target = new Card();
        Field ally;
        Field enemy;
        // NOTE: copy will be deleted in `transform`
        transform(target, copy, ally, enemy, knight);
        delete knight;
        delete target;
    }
    {
        Cards cards;
        Card *adda = cards.createAddaStriga();
        Card *knight = cards.createCursedKnight();
        knight->power = 10;

        Field ally;
        Field enemy;
        ally.cardsAdded = {knight, adda};
        ally.rowMeele = {adda};

        assert_("200073" == adda->id);
        assert_(6 == adda->power);
        assert_(0 == adda->armor);

        knight->onDeploy(ally, enemy);
        assert_(knight->id == adda->id);
        assert_(8 == adda->power);
        assert_(2 == adda->armor);

        adda->onDeploy(ally, enemy);

//        // NOTE: choice is done automatically
//        adda->onDeploy(ally, enemy);
//        onChoiceDoneCard(adda2, ally, enemy);
//        assert_(knight->id == adda2->id);
//        assert_(8 == adda2->power);
//        assert_(2 == adda2->armor);

        delete knight;
        delete adda;
    }
    pass_();
    return 0;
}
