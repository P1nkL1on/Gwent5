#include "tests.h"

#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>

#include <QTest>
#include <QtDebug>

int Tests::writeExpected(const int argc, char **argv)
{
    Tests t;
    t._writeExpected = true;
    return QTest::qExec(&t, argc, argv);
}

int Tests::matchWithExpected(const int argc, char **argv)
{
    Tests t;
    t._writeExpected = false;
    return QTest::qExec(&t, argc, argv);
}

void Tests::a()
{
    test("simple", "blablabla\n123\n");
}

bool Tests::test(const std::string &name, const std::string &text) const
{
    const std::string suffixExpected = "_expected";
    const std::string suffixActual = "_actual";
    const std::string filename = name + (_writeExpected ? suffixExpected : suffixActual);
    writeToFile(filename, text);
    return _writeExpected || compareFiles(name + suffixActual, name + suffixExpected);
}

void Tests::writeToFile(const std::string &filename, const std::string &text)
{
    std::ofstream out(filename);
    out << text;
}

bool Tests::compareFiles(const std::string &res, const std::string &expect)
{
    std::ifstream sRes(res, std::ifstream::binary | std::ifstream::ate);
    std::ifstream sExpect(expect, std::ifstream::binary | std::ifstream::ate);

    if (sRes.fail() || sExpect.fail()) {
        return false; //file problem
    }

    if (sRes.tellg() != sExpect.tellg()) {
        return false; //size mismatch
    }

    //seek back to beginning and use std::equal to compare contents
    sRes.seekg(0, std::ifstream::beg);
    sExpect.seekg(0, std::ifstream::beg);
    return std::equal(
                std::istreambuf_iterator<char>(sRes.rdbuf()),
                std::istreambuf_iterator<char>(),
                std::istreambuf_iterator<char>(sExpect.rdbuf()));
}
