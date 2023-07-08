#include "Cards/archieve.h"
#include "Cards/testcase.h"


int main()
{
    Cards cards;
    Card *adda = cards.createAddaStriga();

    adda->power = 10;
    Card *addaDefaultCopy = adda->defaultCopy();
    Card *addaExactCopy = adda->exactCopy();
    assert_(10 == adda->power);
    assert_(10 == addaExactCopy->power);
    assert_(6 == addaDefaultCopy->power);

    delete adda;
    delete addaDefaultCopy;
    delete addaExactCopy;
    pass_();
    return 0;
}