#include "Cards/archieve.h"
#include "Cards/testcase.h"


int main()
{
    using Cards = std::vector<Card *>;
    auto *a = new Card();
    auto *b = new Card();
    assert_(firsts({}, 0) == Cards{});
    assert_(firsts({}, 1) == Cards{});
    assert_(firsts({}, 2) == Cards{});
    assert_(firsts({a}, 0) == Cards{});
    assert_(firsts({a, b}, 0) == Cards{});
    assert_(firsts({a}, 1) == Cards{a});
    assert_(firsts({a}, 2) == Cards{a});
    assert_((firsts({a, b}, 1) == Cards{a}));
    assert_((firsts({b, a}, 1) == Cards{b}));
    assert_((firsts({b, a}, 2) == Cards{b, a}));
    assert_((firsts({a, b}, 3) == Cards{a, b}));

    assert_(first({}) == nullptr);
    assert_(first({a}) == a);
    assert_(first({a, a}) == a);
    assert_(first({b, a}) == b);

    assert_(last({}) == nullptr);
    assert_(last({a}) == a);
    assert_(last({a, a}) == a);
    assert_(last({b, a}) == a);

    delete a;
    delete b;
    pass_();
    return 0;
}