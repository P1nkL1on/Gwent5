#include "testcase.h"

void TestTools::printPosAtFile(
        std::ostream &os,
        const char *file,
        const char *func,
        const int line)
{
    os << "File \"" << file << "\", func \"" << func << "\"";
    if (line > 0) os << ", line " << line << ": "; else os << ": ";
}

bool TestTools::assert(
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
