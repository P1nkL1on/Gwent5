#ifndef TESTS_H
#define TESTS_H

#include <QObject>

class Tests : public QObject
{
    Q_OBJECT
public:
    static int writeExpected(const int argc, char **argv);
    static int matchWithExpected(const int argc, char **argv);

private slots:
    void a();

private:
    static void writeToFile(const std::string &filename, const std::string &text);
    static bool compareFiles(const std::string &res, const std::string &expect);
    bool test(const std::string &name, const std::string &text) const;
    bool _writeExpected = false;
};

#endif // TESTS_H
