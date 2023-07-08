#ifndef TEXTSEN_H
#define TEXTSEN_H

#include <map>
#include <string>
#include "enums.h"

/// returns all cards in games (no tokens included)
void allCardsInfos(const Patch);

std::map<std::string, std::string> keywordDescriptions(const Patch patch = PublicBeta_0_9_24_3_432);

#endif // TEXTSEN_H
