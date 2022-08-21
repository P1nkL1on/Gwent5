#include "testcase.h"

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

void Testcase::add(const int res, const int expected, const std::string &description)
{
    _res.push_back(res);
    _expected.push_back(expected);
    _descriptions.push_back(description);
}

int Testcase::process() const
{
    return compareArrays(_res, _expected, &_descriptions);
}
