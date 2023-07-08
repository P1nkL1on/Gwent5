#include "tests.h"

#include <iostream>
#include "Cards/archieve.h"

namespace TestTools {

void printPosAtFile(
        std::ostream &os,
        const char *file,
        const char *func,
        const int line)
{
    os << "File \"" << file << "\", func \"" << func << "\"";
    if (line > 0) os << ", line " << line << ": "; else os << ": ";
}

bool assert(
        std::ostream &os,
        const bool statement,
        const char *statementStr,
        const char *file,
        const char *func,
        const int line)
{
    if (statement)
        return true;
    printPosAtFile(os, file, func, line);
    os << "assert failed (" << statementStr << ")" << "\n";
    return false;
}

}


#define assert_(statement)\
{\
    if (!TestTools::assert(std::cerr, statement, #statement, __FILE__, __func__, __LINE__))\
        return 1;\
}

#define pass_()\
{\
    TestTools::printPosAtFile(std::cout, __FILE__, __func__, 0);\
    std::cout << "pass!\n";\
}

namespace Tests {

int testStateCopyVsExactCopy()
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

int testStatelessCardCopyVsExactCopy()
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

int testStateCopyBlathannaArcher()
{
    Cards cards;
    Card *archer = cards.createDolBlathannaArcher();
    Card *adda = cards.createAddaStriga();
    Card *adda2 = cards.createAddaStriga();

    Field ally;
    ally.cardsAdded = {archer};
    ally.rowRange = {archer};

    // NOTE: creating 2 enemies to
    // prevent choice autoresolving
    Field enemy;
    enemy.cardsAdded = {adda, adda2};
    enemy.rowRange = {adda, adda2};

    assert_(ally.cardStack2.isEmpty());
    archer->onDeploy(ally, enemy);
    assert_(!ally.cardStack2.isEmpty());
    assert_(6 == adda->power);

    onChoiceDoneCard(adda, ally, enemy);
    assert_(3 == adda->power);

    // NOTE: copying archer with intermediate state,
    // so after using his ability he will shot once
    Card *archerCopy = archer->exactCopy();
    ally.cardsAdded.push_back(archerCopy);

    onChoiceDoneCard(adda, ally, enemy);
    assert_(2 == adda->power);

    archerCopy->onTargetChoosen(adda, ally, enemy);
    assert_(1 == adda->power);

    delete archer;
    delete archerCopy;
    delete adda;
    pass_();
    return 0;
}

int testBlathannaArcherSeparatedShots()
{
    Cards cards;
    Card *archer = cards.createDolBlathannaArcher();
    Card *dao = cards.createDao();

    Field ally;
    ally.cardsAdded = {archer};
    ally.rowRange = {archer};

    Field enemy;
    enemy.cardsAdded = {dao};
    enemy.rowRange = {dao};
    dao->power = 2;

    // NOTE: autochoosing dao and destroying it
    archer->onDeploy(ally, enemy);
    assert_(std::vector<Card *>{dao} == enemy.discard);

    assert_(!ally.cardStack2.isEmpty());
    const Choice choice = ally.cardStack2.peek();

    assert_(2 == choice.options.size());
    const Card *daoLesser = choice.options.at(0);
    assert_("132405" == daoLesser->id);
    assert_(4 == daoLesser->power);

    const Card *daoLesser2 = choice.options.at(1);

    delete archer;
    delete dao;
    delete daoLesser;
    delete daoLesser2;
    pass_();
    return 0;
}

int testHalfElfHunder()
{
    Cards cards;
    Card *hunter = cards.createHalfElfHunter();
    hunter->power = 8;

    Field ally;
    ally.cardsAdded = {hunter};
    ally.rowMeele = {hunter};

    Field enemy;
    hunter->onDeploy(ally, enemy);
    Card *copy = ally.rowMeele.at(1);
    assert_(hunter->id == copy->id);
    assert_(8 == hunter->power);
    assert_(6 == copy->power);
    assert_(2 == ally.rowMeele.size());

    delete hunter;
    delete copy;
    pass_();
    return 0;
}

int testOptionsMandrake()
{
    Cards cards;
    Card *adda = cards.createAddaStriga();
    Card *mandrake = cards.createMandrake();

    Field ally;
    ally.cardsAdded = {adda, mandrake};
    ally.rowMeele = {adda};

    Field enemy;
    mandrake->onPlaySpecial(ally, enemy);

    assert_(!ally.cardStack2.isEmpty());
    const Choice choice = ally.cardStack2.peek();
    assert_(2 == choice.options.size());

    Card *option1 = choice.options.at(0);
    assert_(isOption(option1, 0));
    assert_(option1->isSpecial);
    assert_(mandrake->id == option1->id);

    Card *option2 = choice.options.at(1);
    assert_(isOption(option2, 1));
    assert_(option2->isSpecial);
    assert_(mandrake->id == option2->id);

    onChoiceDoneCard(option1, ally, enemy);
    assert_(12 == adda->powerBase);

    delete adda;
    delete mandrake;
    pass_();
    return 0;
}

int testCreateFilavandrel()
{
    Cards cards;
    Card *fila = cards.createFilavandrel();

    Field ally;
    ally.cardsAll = cards.createAll();

    Field enemy;
    fila->onDeploy(ally, enemy);
    assert_(!ally.cardStack2.isEmpty());

    const Choice choice = ally.cardStack2.peek();
    assert_(choice.options.size() >= 1);

    for (Card *card : choice.options) {
        assert_(card->isSpecial);
        delete card;
    }
    delete fila;
    pass_();
    return 0;
}

}
