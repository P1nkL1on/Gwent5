#include "tests.h"

#include "Cards/archieve.h"
#include "Cards/testcase.h"

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

int testIsIn()
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

int testFirstsAndLasts()
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

int testPowerRow()
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

int testHighests()
{
    using Cards = std::vector<Card *>;
    auto *a = new Card();
    auto *b = new Card();
    auto *c = new Card();
    auto *d = new Card();
    a->power = 1;
    b->power = 2;
    c->power = 3;
    d->power = 4;
    d->isAmbush = true;

    assert_(highests({}) == Cards{});
    assert_(highests({a}) == Cards{a});
    assert_(highests({a, b}) == Cards{b});
    assert_(highests({a, b, c}) == Cards{c});
    assert_((highests({a, b, c, b, c}) == Cards{c, c}));
    assert_((highests({a, b, c, a, c}) == Cards{c, c}));
    assert_((highests({b, b}) == Cards{b, b}));
    assert_(highests({d}) == Cards{});
    assert_(highests({a, d}) == Cards{a});
    assert_((highests({a, b, d, b, a}) == Cards{b, b}));

    assert_(lowests({}) == Cards{});
    assert_(lowests({a}) == Cards{a});
    assert_(lowests({a, b}) == Cards{a});
    assert_(lowests({b, c}) == Cards{b});
    assert_(lowests({a, b, c, b, c}) == Cards{a});
    assert_((lowests({a, b, c, a, c}) == Cards{a, a}));
    assert_((lowests({b, b}) == Cards{b, b}));
    assert_(lowests({d}) == Cards{});
    assert_(lowests({d, c}) == Cards{c});

    delete a;
    delete b;
    delete c;
    delete d;
    pass_();
    return 0;
}

int testHasNoDuplicates()
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

int testHasExactTwoCopiesOfEachBronze()
{
    auto *a = new Card();
    auto *b = new Card();
    auto *c = new Card();
    auto *d = new Card();
    a->id = "a";
    b->id = "b";
    c->id = "c";
    d->id = "d";
    a->rarity = Bronze;
    b->rarity = Bronze;
    c->rarity = Bronze;
    d->rarity = Silver;
    assert_(hasExactTwoDuplicatesOfBronze({}));
    assert_(hasExactTwoDuplicatesOfBronze({a, a}));
    assert_(hasExactTwoDuplicatesOfBronze({a, a, d, d}));
    assert_(hasExactTwoDuplicatesOfBronze({a, a, b, d, b}));
    assert_(!hasExactTwoDuplicatesOfBronze({a, b, d, b}));
    assert_(!hasExactTwoDuplicatesOfBronze({a, a, b, d}));
    assert_(!hasExactTwoDuplicatesOfBronze({a, a, a, b, b, c, c, d, d}));
    assert_(hasExactTwoDuplicatesOfBronze({a, a, b, b, c, c, d, d}));
    assert_(hasExactTwoDuplicatesOfBronze({d, d}));
    assert_(hasExactTwoDuplicatesOfBronze({d}));
    delete a;
    delete b;
    delete c;
    delete d;
    pass_();
    return 0;
}

}
