#include "Cards/archieve.h"
#include "Cards/testcase.h"


int main()
{
    auto *a = new Card();
    auto *b = new Card();
    auto *c = new Card();
    auto *d = new Card();
    a->id = "a";
    b->id = "b";
    c->id = "c";
    d->id = "d";
    assert_(hasNoDuplicates({}));
    assert_(hasNoDuplicates({a}));
    assert_(hasNoDuplicates({a, b}));
    assert_(hasNoDuplicates({a, b, d}));
    assert_(!hasNoDuplicates({a, b, d, d}));
    assert_(hasNoDuplicates({a, b, c}));
    assert_(!hasNoDuplicates({a, a}));
    delete a;
    delete b;
    delete c;
    delete d;
    pass_();
    return 0;
}