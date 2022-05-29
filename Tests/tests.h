#ifndef TESTS_H
#define TESTS_H

#include <QObject>

class Field;

class Tests : public QObject
{
    Q_OBJECT
public:
    static int writeExpected(const int argc, char **argv);
    static int matchWithExpected(const int argc, char **argv);

private slots:
    void singleUnitDeploy();

private:
    static void writeToFile(const std::string &filename, const std::string &text);
    static bool compareFiles(const std::string &res, const std::string &expect);
    static void fieldToFile(const Field *field, std::string &s);
    void test(const std::string &name, const std::string &text) const;
    std::string _dir = "../Tests/Cases/";
    bool _writeExpected = false;
};

#endif // TESTS_H
