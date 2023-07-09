#include "Cards/card.h"
#include "Cards/testcase.h"


#ifdef QT_TESTS
inline int hasExactTwoDuplicatesOfBronze()
#else
int main()
#endif
{
    auto *a = new Card();
    auto *b = new Card();
    auto *c = new Card();
    auto *d = new Card();
    a->id = "a";
    b->id = "b";
    c->id = "c";
    d->id = "d";
    a->rarity = Bronze;
    b->rarity = Bronze;
    c->rarity = Bronze;
    d->rarity = Silver;
    assert_(hasExactTwoDuplicatesOfBronze({}));
    assert_(hasExactTwoDuplicatesOfBronze({a, a}));
    assert_(hasExactTwoDuplicatesOfBronze({a, a, d, d}));
    assert_(hasExactTwoDuplicatesOfBronze({a, a, b, d, b}));
    assert_(!hasExactTwoDuplicatesOfBronze({a, b, d, b}));
    assert_(!hasExactTwoDuplicatesOfBronze({a, a, b, d}));
    assert_(!hasExactTwoDuplicatesOfBronze({a, a, a, b, b, c, c, d, d}));
    assert_(hasExactTwoDuplicatesOfBronze({a, a, b, b, c, c, d, d}));
    assert_(hasExactTwoDuplicatesOfBronze({d, d}));
    assert_(hasExactTwoDuplicatesOfBronze({d}));
    delete a;
    delete b;
    delete c;
    delete d;
    pass_();
    return 0;
}
