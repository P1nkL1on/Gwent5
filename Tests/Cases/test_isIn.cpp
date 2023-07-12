#include "Cards/card.h"
#include "Cards/testcase.h"


#ifdef QT_TESTS
inline int isIn()
#else
int main()
#endif
{
    using Cards = std::vector<Card *>;
    auto *a = new Card();
    auto *b = new Card();

    assert_((Cards{a, b} == Cards{a, b}));
    assert_(!isIn(a, {}));
    assert_(!isIn(nullptr, {a}));
    assert_(isIn(a, {a}));
    assert_(!isIn(a, {b}));
    assert_(!isIn(b, {a}));
    assert_(isIn(b, {a, b}));
    assert_(isIn(a, {a, b}));
    assert_(isIn(a, {a, a}));

    delete a;
    delete b;
    pass_();
    return 0;
}
