#include "Cards/card.h"
#include "Cards/testcase.h"


#ifdef QT_TESTS
inline int highestsAndLowests()
#else
int main()
#endif
{
    using Cards = std::vector<Card *>;
    auto *a = new Card();
    auto *b = new Card();
    auto *c = new Card();
    auto *d = new Card();
    a->power = 1;
    b->power = 2;
    c->power = 3;
    d->power = 4;
    d->isAmbush = true;

    assert_(highests({}) == Cards{});
    assert_(highests({a}) == Cards{a});
    assert_(highests({a, b}) == Cards{b});
    assert_(highests({a, b, c}) == Cards{c});
    assert_((highests({a, b, c, b, c}) == Cards{c, c}));
    assert_((highests({a, b, c, a, c}) == Cards{c, c}));
    assert_((highests({b, b}) == Cards{b, b}));
    assert_(highests({d}) == Cards{});
    assert_(highests({a, d}) == Cards{a});
    assert_((highests({a, b, d, b, a}) == Cards{b, b}));

    assert_(lowests({}) == Cards{});
    assert_(lowests({a}) == Cards{a});
    assert_(lowests({a, b}) == Cards{a});
    assert_(lowests({b, c}) == Cards{b});
    assert_(lowests({a, b, c, b, c}) == Cards{a});
    assert_((lowests({a, b, c, a, c}) == Cards{a, a}));
    assert_((lowests({b, b}) == Cards{b, b}));
    assert_(lowests({d}) == Cards{});
    assert_(lowests({d, c}) == Cards{c});

    delete a;
    delete b;
    delete c;
    delete d;
    pass_();
    return 0;
}
