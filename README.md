# Gwent5

C++ procedural Fan Gwent OBT (based on patch PublicBeta_0.9.24.3.432) card game with Qt forms.

# Fan Content
Please note that this project is in no way associated or affiliated with CD PROJEKT RED.
All art and audio is property of their respective artists and/or CD PROJEKT RED.

[Fan Content Guidelines](https://cdprojektred.com/en/fan-content)

# Road Map

- [x] Basic card mechanics (damage, boost, death, ressurect, etc)
- [x] Some cards to test it
- [x] Hotseat game version
- [x] Demos w/ various card setups for manual testing
- [x] Advanced Card Mechanics (create, options, ambush, statuses, etc)
- [ ] All Faction Cards (~300 cards alread done)
- [x] Sample client app w/ visuals
- [x] Sample gallery app w/ visuals
- [x] Deck buiding in gallery app
- [ ] Advanced app w/ Qt widgets
- [ ] Advanced Client-Server w/ Qt Network
- [ ] Card Mechanic Unit Tests
- [ ] CMake + Qt Test tests
- [ ] Github CMake CI for Various Tests
- [ ] ...

## Client

Hotseat app with hardcoded deck. Controls by mouse only. Use wheel to switch views.

<img src="https://user-images.githubusercontent.com/22278488/166415736-eaba6d91-fc44-49e0-a428-5c4c1ae7d1e1.png" width="640" height="720" />

## Widgets

App for watching all the card collection and building a deck. Has filters of factions and rarity, as well as string search.

<img src="https://github.com/P1nkL1on/Gwent5/blob/1-implement-basics/Widgets/preview.gif" width="640" height="720" />

## Tools

* [.sh script for card data fetching](https://github.com/P1nkL1on/Gwent5/blob/1-implement-basics/Tools/FetchInfo.sh)
