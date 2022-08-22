#include "Cards/card.h"
#include "Cards/testcase.h"

int main()
{
    using Cards = std::vector<Card *>;
    auto *a = new Card();
    auto *b = new Card();
    auto *c = new Card();
    auto *d = new Card();

    const Cards empty = Cards{};
    const Card *none = nullptr;

    Testcase testcase;

    testcase.add(Cards{a, b} == Cards{a, b}, 1, "Cards{a, b} is Cards{a, b}");

    testcase.add(!isIn(a, {}), 1, "isIn(a, {}) is false");
    testcase.add(!isIn(none, {a}), 1, "isIn(none, {a}) is false");
    testcase.add(isIn(a, {a}), 1, "isIn(a, {a})");
    testcase.add(!isIn(a, {b}), 1, "isIn(a, {b}) is false");
    testcase.add(!isIn(b, {a}), 1, "isIn(b, {a}) is false");
    testcase.add(isIn(b, {a, b}), 1, "isIn(b, {a, b})");
    testcase.add(isIn(a, {a, b}), 1, "isIn(a, {a, b})");
    testcase.add(isIn(a, {a, a}), 1, "isIn(a, {a, a})");

    testcase.add(firsts({}, 0) == empty, 1, "firsts({}, 0) is empty");
    testcase.add(firsts({}, 1) == empty, 1, "firsts({}, 1) is empty");
    testcase.add(firsts({}, 2) == empty, 1, "firsts({}, 2) is empty");
    testcase.add(firsts({a}, 0) == empty, 1, "firsts({a}, 0) is empty");
    testcase.add(firsts({a, b}, 0) == empty, 1, "firsts({a, b}, 0) is empty");
    testcase.add(firsts({a}, 1) == Cards{a}, 1, "firsts({a}, 1) is Cards{a}");
    testcase.add(firsts({a}, 2) == Cards{a}, 1, "firsts({a}, 2) is Cards{a}");
    testcase.add(firsts({a, b}, 1) == Cards{a}, 1, "firsts({a, b}, 1) is Cards{a}");
    testcase.add(firsts({b, a}, 1) == Cards{b}, 1, "firsts({b, a}, 1) is Cards{b}");
    testcase.add(firsts({b, a}, 2) == Cards{b, a}, 1, "firsts({b, a}, 2) is (Cards{b, a})");
    testcase.add(firsts({a, b}, 3) == Cards{a, b}, 1, "firsts({a, b}, 3) is (Cards{a, b})");

    testcase.add(first({}) == none, 1, "first({}) is none");
    testcase.add(first({a}) == a, 1, "first({a}) is a");
    testcase.add(first({a, a}) == a, 1, "first({a, a}) is a");
    testcase.add(first({b, a}) == b, 1, "first({b, a}) is b");

    testcase.add(last({}) == none, 1, "last({}) is none");
    testcase.add(last({a}) == a, 1, "last({a}) is a");
    testcase.add(last({a, a}) == a, 1, "last({a, a}) is a");
    testcase.add(last({b, a}) == a, 1, "last({b, a}) is a");

    a->power = 1;
    b->power = 2;
    c->power = 3;
    testcase.add(powerRow({}) == 0, 1, "powerRow({}) is 0");
    testcase.add(powerRow({a}) == 1, 1, "powerRow({a}) is 1");
    testcase.add(powerRow({a, a}) == 2, 1, "powerRow({a, a}) is 2");
    testcase.add(powerRow({a, b, c}) == 6, 1, "powerRow({a, b, c}) is 6");

    d->isAmbush = true;
    testcase.add(powerRow({a, b, c, d}) == 6, 1, "powerRow({a, b, c, d}) is 6");
    testcase.add(powerRow({b, d, a}) == 3, 1, "powerRow({b, d, a}) is 3");
    testcase.add(powerRow({d, d, d}) == 0, 1, "powerRow({d, d, d}) is 0");

    testcase.add(highests({}) == empty, 1, "highests({}) is empty");
    testcase.add(highests({a}) == Cards{a}, 1, "highests({a}) is Cards{a}");
    testcase.add(highests({a, b}) == Cards{b}, 1, "highests({a, b}) is Cards{b}");
    testcase.add(highests({a, b, c}) == Cards{c}, 1, "highests({a, b, c}) is Cards{c}");
    testcase.add(highests({a, b, c, b, c}) == Cards{c, c}, 1, "highests({a, b, c, b, c}) is (Cards{c, c})");
    testcase.add(highests({a, b, c, a, c}) == Cards{c, c}, 1, "highests({a, b, c, a, c}) is (Cards{c, c})");
    testcase.add(highests({b, b}) == Cards{b, b}, 1, "highests({b, b}) is (Cards{b, b})");

    testcase.add(lowests({}) == empty, 1, "lowests({}) is empty");
    testcase.add(lowests({a}) == Cards{a}, 1, "lowests({a}) is Cards{a}");
    testcase.add(lowests({a, b}) == Cards{a}, 1, "lowests({a, b}) is Cards{a}");
    testcase.add(lowests({b, c}) == Cards{b}, 1, "lowests({b, c}) is Cards{b}");
    testcase.add(lowests({a, b, c, b, c}) == Cards{a}, 1, "lowests({a, b, c, b, c}) is Cards{a}");
    testcase.add(lowests({a, b, c, a, c}) == Cards{a, a}, 1, "lowests({a, b, c, a, c}) is (Cards{a, a})");
    testcase.add(lowests({b, b}) == Cards{b, b}, 1, "lowests({b, b}) is (Cards{b, b})");

    testcase.add(!isRowFull({}), 1, "isRowFull({}) is false");
    testcase.add(!isRowFull({a}), 1, "isRowFull({a}) is false");
    testcase.add(!isRowFull({a, b}), 1, "isRowFull({a, b}) is false");
    testcase.add(isRowFull({a, b, c, a, b, c, a, b, c}), 1, "isRowFull({a, b, c, a, b, c, a, b, c})");
    testcase.add(isRowFull({a, b, c, a, b, c, a, b, c, d}), 1, "isRowFull({a, b, c, a, b, c, a, b, c, d})");

    a->name = "a";
    b->name = "b";
    c->name = "b";
    d->name = "d";
    testcase.add(findCopies(a, {}) == empty, 1);
    testcase.add(findCopies(b, {a}) == empty, 1);
    testcase.add(findCopies(c, {a, b}) == Cards{b}, 1);
    testcase.add(findCopies(c, {a, b, c}) == Cards{b, c}, 1);
    testcase.add(findCopies(a, {a, b, c}) == Cards{a}, 1);

    testcase.add(findCopy(a, {}) == none, 1);
    testcase.add(findCopy(b, {a}) == none, 1);
    testcase.add(findCopy(c, {a, b}) == b, 1);
    testcase.add(findCopy(c, {a, b, c}) == b, 1);
    testcase.add(findCopy(a, {a, b, c}) == a, 1);

    testcase.add(hasNoDuplicates({}), 1);
    testcase.add(hasNoDuplicates({a}), 1);
    testcase.add(hasNoDuplicates({a, b}), 1);
    testcase.add(hasNoDuplicates({a, b, d}), 1);
    testcase.add(hasNoDuplicates({a, b, d, d}), 0);
    testcase.add(hasNoDuplicates({a, b, c}), 0);
    testcase.add(hasNoDuplicates({a, a}), 0);

    a->rarity = Bronze;
    b->rarity = Bronze;
    d->rarity = Silver;
    testcase.add(hasExactTwoDuplicatesOfBronze({}), 1);
    testcase.add(hasExactTwoDuplicatesOfBronze({a, a}), 1);
    testcase.add(hasExactTwoDuplicatesOfBronze({a, a, d, d}), 1);
    testcase.add(hasExactTwoDuplicatesOfBronze({a, a, b, d, b}), 1);
    testcase.add(hasExactTwoDuplicatesOfBronze({a, b, d, b}), 0);
    testcase.add(hasExactTwoDuplicatesOfBronze({a, a, b, d}), 0);

    bool isAlly;
    testcase.add(fromScreenRow(5, isAlly), Seige, "screenRow 5 is Seige");
    testcase.add(isAlly, 0,                       "screenRow 5 is Enemy");
    testcase.add(fromScreenRow(4, isAlly), Range, "screenRow 4 is Range");
    testcase.add(isAlly, 0,                       "screenRow 4 is Enemy");
    testcase.add(fromScreenRow(3, isAlly), Meele, "screenRow 3 is Meele");
    testcase.add(isAlly, 0,                       "screenRow 3 is Enemy");
    testcase.add(fromScreenRow(2, isAlly), Meele, "screenRow 2 is Meele");
    testcase.add(isAlly, 1,                       "screenRow 2 is Ally");
    testcase.add(fromScreenRow(1, isAlly), Range, "screenRow 1 is Range");
    testcase.add(isAlly, 1,                       "screenRow 1 is Ally");
    testcase.add(fromScreenRow(0, isAlly), Seige, "screenRow 0 is Seige");
    testcase.add(isAlly, 1,                       "screenRow 0 is Ally");

    delete a;
    delete b;
    delete c;
    delete d;
    return testcase.process();
}
