#ifndef CARDINFO_H
#define CARDINFO_H

#include <string>
#include <vector>

#include "Cards/enums.h"

/// e.x.
/// https://gwent.one/en/beta/card/200164
///                   ^^           ^^^^^^
///                   lang         id
/// urlImageLow:    https://gwent.one/image/card/low/cid/png/200164.png
/// urlImageMedium: https://gwent.one/image/card/medium/cid/png/200164.png
/// urlVideo:       https://gwent.one/video/card/loop/ob/200164.mp4

struct CardStringsAndUrls
{
    std::string lang;

    std::string name;
    std::string text;
    std::vector<std::string> textSounds;

    std::string urlImageLow;
    std::string urlImageMedium;
    std::string urlVideo;
    std::vector<std::string> urlSounds;
};


bool requestCardInfo(const std::string &id, const std::string &lang = "en");

#endif // CARDINFO_H
