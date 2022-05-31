#ifndef IO_H
#define IO_H

#include <string.h>
#include <map>
#include <fstream>
#include <iostream>

struct Deck2
{
    std::string leader;
    std::map<std::string, int> nameToCount;
};


bool write(std::ofstream &out, const Deck2 &deck);
bool write(const std::string &filename, const Deck2 &deck);
bool read(std::ifstream &in, Deck2 &deck);
bool read(const std::string &filename, Deck2 &deck);

#endif // IO_H
