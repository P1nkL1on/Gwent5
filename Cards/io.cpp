#include "io.h"
#include <assert.h>
#include <sstream>
#include <regex>

bool write(std::ofstream &out, const Deck2 &deck)
{
    out << deck.leader;
    for (const auto &it : deck.nameToCount) {
        out << std::endl << it.first;
        const int count = it.second;
        assert(count > 0);
        if (count == 1)
            continue;
        out << " x" << count;
    }
    return true;
}

bool read(std::ifstream &in, Deck2 &deck)
{
    // TODO: better err matching
    // TODO: write it with single regex for a line
    const std::regex regexNumber("x[0-9]+");

    std::string line;
    bool isLeaderReaded = false;
    while (std::getline(in, line, '\n')) {
        if (!isLeaderReaded) {
            deck.leader = line;
            continue;
        }
        std::stringstream ss(line);
        std::string name;
        int count = 1;
        std::string word;
        while (std::getline(ss, word, ' ')) {
            if (!word.size())
                return false;
            if (std::regex_match(word, regexNumber)) {
                word.erase(0, 1);
                count = std::stoi(word);
                break;
            }
            name += (name.size() ? " " : "") + word;
        }
        deck.nameToCount.insert({name, count});
    }
    return true;
}

bool write(const std::string &filename, const Deck2 &deck)
{
    std::ofstream out(filename);
    return write(out, deck);
}

bool read(const std::string &filename, Deck2 &deck)
{
    std::ifstream in(filename);
    return read(in, deck);
}
