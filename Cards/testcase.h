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
    void add(const int res, const int expected, const std::string &description = "");
    int process() const;
private:
    std::vector<int> _res;
    std::vector<int> _expected;
    std::vector<std::string> _descriptions;
};

#endif // TESTCASE_H
