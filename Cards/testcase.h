#ifndef TESTCASE_H
#define TESTCASE_H

#include <vector>
#include <string>
#include <iomanip>
#include <iostream>


int compareArrays(
        const std::vector<int> &res,
        const std::vector<int> &expected,
        const std::vector<std::string> *descriptions);

struct Testcase
{
    bool add(const int res, const int expected, const std::string &description = "");
    int process() const;
private:
    std::vector<int> _res;
    std::vector<int> _expected;
    std::vector<std::string> _descriptions;
};

#define ADD_TESTCASE_IMPL(TESTCASE, RES, EXPECTED) \
    (TESTCASE).add((RES), (EXPECTED), (std::string(#RES) + " is " + std::string(#EXPECTED)))

#define ADD_TESTCASE(TESTCASE, RES, ...) CHOOSE_IMPL(,##__VA_ARGS__, \
    ADD_TESTCASE_IMPL(TESTCASE, RES, (__VA_ARGS__)), \
    ADD_TESTCASE_IMPL(TESTCASE, RES, 1))

#define CHOOSE_IMPL(_, __, FUNC, ...) (FUNC)

#endif // TESTCASE_H
