#include <iomanip>

#include "Cards/archieve.h"
#include "Cards/card.h"


int compareArrays(const std::vector<int> &res, const std::vector<int> &expected)
{
    using namespace std;
    const size_t align = 10;
    const size_t l = max(res.size(), expected.size());
    cout << setw(align) << "Result" << setw(align + 2) << "Expected" << "\n";
    for (size_t ind = 0; ind < l; ++ind) {
        const bool hasRes = ind < res.size();
        const bool hasExp = ind < expected.size();
        const bool isEq   = hasRes && hasExp && (res[ind] == expected[ind]);
        cout << setw(align) << (hasRes ? to_string(res[ind])      : "*")
             << (isEq ? "==" : "!=")
             << setw(align) << (hasExp ? to_string(expected[ind]) : "*")
             << "\n";
    }
    cout << endl;
    return res != expected;
}

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

    std::vector<int> res;
    res.push_back(neophyte->power);
    res.push_back(scout->power);

    // swapping while count is in hand should boost neophyte only
    swapACard(vanguard, ally, enemy, scout);
    res.push_back(neophyte->power);
    res.push_back(scout->power);

    // swapping again, but putting a scout to the deck
    // it should garantee working, and drawing scout next
    ally.hand = {vanguard};
    ally.deck = {scout};
    swapACard(vanguard, ally, enemy, scout);
    res.push_back(neophyte->power);
    res.push_back(scout->power);
    res.push_back(ally.hand == std::vector<Card *>{scout});
    res.push_back(ally.deck == std::vector<Card *>{vanguard});

    const std::vector<int> expected {10, 10, 11, 10, 12, 10, 1, 1};
    return compareArrays(res, expected);
}
