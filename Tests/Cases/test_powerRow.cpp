#include "Cards/card.h"
#include "Cards/testcase.h"


int main()
{
    auto *a = new Card();
    auto *b = new Card();
    auto *c = new Card();
    auto *d = new Card();
    a->power = 1;
    b->power = 2;
    c->power = 3;
    d->power = 4;

    assert_(powerRow({}) == 0);
    assert_(powerRow({a}) == 1);
    assert_(powerRow({a, a}) == 2);
    assert_(powerRow({a, b, c}) == 6);

    d->isAmbush = true;
    assert_(powerRow({a, b, c, d}) == 6);
    assert_(powerRow({b, d, a}) == 3);
    assert_(powerRow({d, d, d}) == 0);
    delete a;
    delete b;
    delete c;
    delete d;
    pass_();
    return 0;
}
