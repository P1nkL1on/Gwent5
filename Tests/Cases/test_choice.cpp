#include "Cards/archieve.h"
#include "Cards/testcase.h"

int main()
{
    Field ally;
    Field enemy;
    Testcase testcase;

    // row selection
    Card *frost = new BitingFrost();

    testcase.add(ally.cardStack2.isEmpty(), 1, "Choice stack should be empty");
    startChoiceToSelectRow(ally, enemy, frost, {3, 4, 5}, {});
    testcase.add(ally.cardStack2.isEmpty(), 0, "Choice stack shouldn't be empty");
    testcase.add(enemy.rowEffectMeele, NoRowEffect, "No frost should be at the start");
    onChoiceDoneRow(3, ally, enemy);
    testcase.add(ally.cardStack2.isEmpty(), 1, "Choice stack should be empty again");
    testcase.add(enemy.rowEffectMeele, BitingFrostEffect, "A frost should after selection");

    startChoiceToSelectRow(enemy, ally, frost, {3, 4, 5}, {});
    testcase.add(ally.rowEffectMeele, NoRowEffect, "Same for enemy choice:");
    onChoiceDoneRow(3, enemy, ally);
    testcase.add(ally.rowEffectMeele, BitingFrostEffect);

    // row selection expand
    Card *geralt = new GeraltIgni();
    Card *griffin = new Griffin();

    griffin->power = 25;
    enemy.rowRange = {griffin};
    ally.cardStack2.isRemovingExpandedChoice = false;
    geralt->onDeploy(ally, enemy);
    geralt->onDeploy(ally, enemy);

    // First choice autoexpanded, but not autoresolved (due to settings)
    testcase.add(int(ally.cardStack2.queue()[0].screenRows.size()), 1, "First Igni should contain 1 option, expanded");
    testcase.add(int(ally.cardStack2.queue()[1].screenRows.size()), 3, "Second Igni should contain 3 options, unexpanded");
    testcase.add(int(ally.cardStack2.queue().size()), 2, "Choice stack should contain 2 choices");
    onChoiceDoneRow(4, ally, enemy);
    testcase.add(int(ally.cardStack2.queue().size()), 0, "Second Igni should be autoresolved anyway, "
                                                         "cause has no vaible options after expand");
    testcase.add(isIn(griffin, enemy.discard), 1, "Grifin should be destroyed");

    // create
    Card *runestone = new ZoriaRunestone();

    testcase.add(ally.cardStack2.isEmpty(), 1, "Choice stack should be empty");
    runestone->onPlaySpecial(ally, enemy);
    testcase.add(ally.cardStack2.isEmpty(), 0, "Choice stack shouldn't be empty");
    testcase.add(int(ally.cardStack2.peekChoice().options.size()), 3, "Create should has 3 cards");
    onChoiceDoneCard(ally.cardStack2.peekChoice().options[0], ally, enemy);
    testcase.add(ally.cardStack2.isEmpty(), 0, "Choice stack shouldn't be empty still");

    return testcase.process();
}
