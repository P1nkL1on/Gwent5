#include "Cards/archieve.h"
#include "Cards/testcase.h"


#ifdef QT_TESTS
inline int transformCursedKnight()
#else
int main()
#endif
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
        ally.rowMeele = {knight, adda};

        assert_("200073" == adda->id);
        assert_(6 == adda->power);
        assert_(0 == adda->armor);

        knight->onDeploy(ally, enemy);
        assert_(knight->id == adda->id);
        assert_(8 == adda->power);
        assert_(2 == adda->armor);

        // NOTE: choice is done automatically
        assert_(10 == knight->power);
        assert_(2 == knight->armor);
        adda->onDeploy(ally, enemy);
        assert_(8 == knight->power);
        assert_(2 == knight->armor);

        delete knight;
        delete adda;
    }
    pass_();
    return 0;
}
