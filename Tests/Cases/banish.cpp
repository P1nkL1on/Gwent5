#include "Cards/archieve.h"
#include "Cards/testcase.h"

int main()
{
    Field ally;
    Field enemy;
    auto *dao = new Dao();
    ally.rowMeele = { dao };
    weaken(dao, 10, ally, enemy, nullptr);

    Testcase testcase;
    testcase.add(int(ally.rowMeele.size()), 0, "Should ignore deathwish");
    testcase.add(isIn(dao, ally.discard), 0, "Shouldn't be in discard");

    return testcase.process();
}
