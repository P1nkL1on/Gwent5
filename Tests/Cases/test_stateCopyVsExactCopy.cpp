#include "Cards/card.h"
#include "Cards/testcase.h"


#ifdef QT_TESTS
inline int stateCopyVsExactCopy()
#else
int main()
#endif
{
    struct State1 : StateCopy<State1>
    {
        int x = 42;
    };

    State *state1 = new State1();
    assert_(dynamic_cast<State1 *>(state1));
    assert_(42 == static_cast<State1 *>(state1)->x);

    static_cast<State1 *>(state1)->x = 69;
    State* state2 = state1->exactCopy();
    assert_(69 == static_cast<State1 *>(state2)->x);

    State* state3 = state1->defaultCopy();
    assert_(42 == static_cast<State1 *>(state3)->x);

    delete state1;
    delete state2;
    delete state3;
    pass_();
    return 0;
}
