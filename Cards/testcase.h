#ifndef TESTCASE_H
#define TESTCASE_H

#include <ostream>


namespace TestTools {

void printPosAtFile(
        std::ostream &os,
        const char *file,
        const char *func,
        const int line);

bool assert(
        std::ostream &os,
        const bool statement,
        const char *statementStr,
        const char *file,
        const char *func,
        const int line);

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


#endif // TESTCASE_H
