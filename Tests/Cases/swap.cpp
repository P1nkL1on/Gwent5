#include <iomanip>

#include "Cards/archieve.h"
#include "Cards/card.h"


int compareArrays(
        const std::vector<int> &res,
        const std::vector<int> &expected,
        const std::vector<std::string> *descriptions)
{
    if (res == expected)
        return 0;
    const size_t align = 8;
    const size_t l = std::max(res.size(), expected.size());
    std::cout << std::setw(align) << "Result" << std::setw(align + 2) << "Expected" << "\n";
    for (size_t ind = 0; ind < l; ++ind) {
        const bool hasRes = ind < res.size();
        const bool hasExp = ind < expected.size();
        const bool isEq   = hasRes && hasExp && (res[ind] == expected[ind]);
        std::cout << std::setw(align) << (hasRes ? std::to_string(res[ind])      : "*")
                  << (isEq ? "==" : "!=")
                  << std::setw(align) << (hasExp ? std::to_string(expected[ind]) : "*")
                  << " " << (descriptions ? descriptions->at(ind) : "") << std::endl;
    }
    return 1;
}

struct Testcase
{
    void add(const int res, const int expected, const std::string &description = "")
    {
        _res.push_back(res);
        _expected.push_back(expected);
        _descriptions.push_back(description);
    }
    int process() const
    {
        return compareArrays(_res, _expected, &_descriptions);
    }
private:
    std::vector<int> _res;
    std::vector<int> _expected;
    std::vector<std::string> _descriptions;
};


int main()
{
    Field ally;
    Field enemy;
    Card *vanguard = new VriheddVanguard();
    Card *neophyte = new VriheddNeophyte();
    Card *scout    = new ElvenScout();

    ally.cardsAdded = {};
    ally.hand = {scout, vanguard};
    ally.rowMeele = {neophyte};

    Testcase testcase;
    testcase.add(neophyte->power, 10);
    testcase.add(scout->power, 10);

    // swapping while count is in hand should boost neophyte only
    swapACard(vanguard, ally, enemy, scout);
    testcase.add(neophyte->power, 11, "Should proc while deck is empty");
    testcase.add(scout->power, 10);

    // swapping again, but putting a scout to the deck
    // it should garantee working, and drawing scout next
    ally.hand = {vanguard};
    ally.deck = {scout};
    swapACard(vanguard, ally, enemy, scout);
    testcase.add(neophyte->power, 12, "Should proc while deck isn't empty");
    testcase.add(scout->power, 10);
    testcase.add(ally.hand == std::vector<Card *>{scout}, 1, "Should draw another card after swap");
    testcase.add(ally.deck == std::vector<Card *>{vanguard}, 1);

    return testcase.process();
}
