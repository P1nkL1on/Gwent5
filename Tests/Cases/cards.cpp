#include "Cards/archieve.h"
#include "Cards/testcase.h"

int main()
{
    /// Test plan:
    /// * banish
    /// * damage
    /// * destroy

    Field ally;
    Field enemy;
    auto *dao = new Dao();
    ally.rowMeele = { dao };
    weaken(dao, 10, ally, enemy, nullptr);

    Testcase testcase;
    testcase.add(int(ally.rowMeele.size()), 0, "Banished unit should ignore deathwish");
    testcase.add(isIn(dao, ally.discard), 0, "Banished unit shouldn't be in discard");
    delete dao;

    dao = new Dao();
    ally.rowMeele = { dao };
    damage(dao, 10, ally, enemy, nullptr);
    testcase.add(int(ally.rowMeele.size()), 2, "Should trigger deathwish");
    testcase.add(isIn(dao, ally.discard), 1, "Destroyed unit should be in discard");
    testcase.add(dao->power, dao->powerBase, "Destroyed unit should has full power");

    auto *lesserDao = dynamic_cast<Dao::DaoLesser *>(ally.rowMeele.at(0));
    testcase.add(lesserDao != nullptr, 1);

    damage(lesserDao, 3, ally, enemy, nullptr);
    testcase.add(lesserDao->power, 1);

    damage(lesserDao, 1, ally, enemy, nullptr);
    testcase.add(lesserDao->power, 4, "Doomed unit should still be reset on death");
    testcase.add(lesserDao->isDoomed, 1);
    testcase.add(int(ally.rowMeele.size()), 1);
    testcase.add(isIn(lesserDao, ally.discard), 0, "Doomed unit should be banished");

    auto *lesserDao2 = dynamic_cast<Dao::DaoLesser *>(ally.rowMeele.at(0));
    testcase.add(lesserDao2 != nullptr, 1);

    return testcase.process();
}
