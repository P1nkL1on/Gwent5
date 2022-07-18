#include "view.h"

#include <cassert>
#include <algorithm>

#include "card.h"

CardView cardView(const Card *card, const int id)
{
    CardView view;
    view.id = id;
    view.power = card->power;
    view.powerBase = card->powerBase;
    view.armor = card->armor;
    view.rarity = card->rarity;
    view.timer = card->timer;
    view.faction = card->faction;
    view.tags = card->tags;
    view.isLocked = card->isLocked;
    view.isSpy = card->isSpy;
    view.isResilient = card->isResilient;
    view.isAmbush = card->isAmbush;
    view.isImmune = card->isImmune;
    view.isDoomed = card->isDoomed;
    view.isRevealed = card->isRevealed;
    view.name = card->name;
    view.text = card->text;
    view.url = "https://gwent.one/image/card/low/cid/png/" + card->id + ".png";
    view.urlLarge = "https://gwent.one/image/card/medium/cid/png/" + card->id + ".png";
    return view;
}

FieldView fieldView(
        const Field &ally,
        const Field &enemy,
        const ActionType actionType,
        const Card *src,
        const std::vector<Card *> &dst,
        const std::string &sound,
        const int actionValue,
        const bool computeOptionScoreGaps)
{
    ally.cardStack2.trace();

    std::map<const Card *, CardView> cardToView;

    int cardViewId = 0;
    if (ally.leaderStarting != nullptr)
        cardToView.insert({ally.leaderStarting, cardView(ally.leaderStarting, cardViewId++)});
    for (const Card *card : ally.deckStarting)
        cardToView.insert({card, cardView(card, cardViewId++)});
    for (const Card *card : ally.cardsAdded)
        cardToView.insert({card, cardView(card, cardViewId++)});

    if (enemy.leaderStarting != nullptr)
        cardToView.insert({enemy.leaderStarting, cardView(enemy.leaderStarting, cardViewId++)});
    for (const Card *card : enemy.deckStarting)
        cardToView.insert({card, cardView(card, cardViewId++)});
    for (const Card *card : enemy.cardsAdded)
        cardToView.insert({card, cardView(card, cardViewId++)});

    /// add extra crads that are just options)
    if (!ally.cardStack2.isEmpty())
        for (const Card *card : ally.cardStack2.peekChoice().options)
            cardToView.insert({card, cardView(card, cardViewId++)});

    const auto id = [cardToView](const Card *card) -> int {
        if (card == nullptr)
            return -1;
        if (cardToView.find(card) == cardToView.end())
            return -1;
        return cardToView.at(card).id;
    };

    // TODO: remove a vector, because its a max 1 choice
    std::vector<ChoiceView> choiceViews;

    int choiceViewId = 0;

    if (!ally.cardStack2.isEmpty()) {
        const Choice2 &choice = ally.cardStack2.peekChoice();
        ChoiceView view;
        view.id = choiceViewId++;
        view.choiceType = choice.type;
        view.cardSourceId = id(choice.src);
        view.nTargets = choice.nTargets;
        view.isOptional = choice.isOptional;
        for (const Card *card : choice.options)
            view.cardOptionIds.push_back(id(card));
        for (const Card *card : choice.optionsSelected)
            view.cardOptionIdsSelected.push_back(id(card));
        view.valuesOptions = choice.screenRows;
        choiceViews.push_back(view);
    }

    /// checking hidden cards
    std::vector<int> choiceCardIds;
    for (const ChoiceView &choiceView : choiceViews) {
        for (const int id : choiceView.cardOptionIds)
            choiceCardIds.push_back(id);
        /// not bad if duplicates. if id isn't given, skip
        if (choiceView.cardSourceId >= 0)
            choiceCardIds.push_back(choiceView.cardSourceId);
    }
    const auto isInChoice = [=](const int id) {
        return std::find(choiceCardIds.begin(), choiceCardIds.end(), id) != choiceCardIds.end();
    };
    /// in a deck -> check if an ally option choice
    for (const Card *card : ally.deck)
        cardToView[card].isVisible = isInChoice(cardToView[card].id);
    for (const Card *card : enemy.deck)
        cardToView[card].isVisible = isInChoice(cardToView[card].id);

    /// in a hand -> check if revealed (if in choice, shouldn't reveal,
    /// its no card, which allows you to see opp's hand before reveal)
    for (const Card *card : enemy.hand)
        cardToView[card].isVisible = card->isRevealed;

    /// in a field -> check if ambush
    for (auto it = cardToView.begin(); it != cardToView.end(); ++it){
        bool isOnBoard = false;
        for (const Row row : std::vector<Row>{Meele, Range, Seige})
            if (isIn(it->first, ally.row(row)) || isIn(it->first, enemy.row(row))) {
                isOnBoard = true;
                break;
            }
        if (isOnBoard && it->first->isAmbush)
            it->second.isVisible = false;
    }

    /// obfuscate invisible cards
    for (auto it = cardToView.begin(); it != cardToView.end(); ++it) {
        CardView &view = it->second;
        if (view.isVisible)
            continue;

        const int id = view.id;
        view = CardView();
        view.id = id;
        view.name = "???";
        view.isVisible = false;
    }

    FieldView res;

    for (const Card *card : ally.rowMeele)
        res.allyRowMeeleIds.push_back(id(card));
    for (const Card *card : ally.rowRange)
        res.allyRowRangeIds.push_back(id(card));
    for (const Card *card : ally.rowSeige)
        res.allyRowSeigeIds.push_back(id(card));
    for (const Card *card : ally.hand)
        res.allyHandIds.push_back(id(card));
    for (const Card *card : ally.deck)
        res.allyDeckIds.push_back(id(card));
    for (const Card *card : ally.discard)
        res.allyDiscardIds.push_back(id(card));
    for (const Card *card : enemy.rowMeele)
        res.enemyRowMeeleIds.push_back(id(card));
    for (const Card *card : enemy.rowRange)
        res.enemyRowRangeIds.push_back(id(card));
    for (const Card *card : enemy.rowSeige)
        res.enemyRowSeigeIds.push_back(id(card));
    for (const Card *card : enemy.hand)
        res.enemyHandIds.push_back(id(card));
    for (const Card *card : enemy.deck)
        res.enemyDeckIds.push_back(id(card));
    for (const Card *card : enemy.discard)
        res.enemyDiscardIds.push_back(id(card));
    for (const Card *card : ally.cardsAppearedBoth)
        res.cardsAppearedIds.push_back(id(card));
    for (const Card *card : ally.cardsAppeared)
        res.cardsPlayedIds.push_back(id(card));
    res.allyLeader = ally.leader ? -1 : id(ally.leader);
    res.enemyLeader = enemy.leader ? -1 : id(enemy.leader);
    res.allyRowEffectMeele = ally.rowEffectMeele;
    res.allyRowEffectRange = ally.rowEffectRange;
    res.allyRowEffectSeige = ally.rowEffectSeige;
    res.enemyRowEffectMeele = enemy.rowEffectMeele;
    res.enemyRowEffectRange = enemy.rowEffectRange;
    res.enemyRowEffectSeige = enemy.rowEffectSeige;
    res.nPowerRowAllyMeele = powerRow(ally.rowMeele);
    res.nPowerRowAllyRange = powerRow(ally.rowRange);
    res.nPowerRowAllySeige = powerRow(ally.rowSeige);
    res.nPowerRowEnemyMeele = powerRow(enemy.rowMeele);
    res.nPowerRowEnemyRange = powerRow(enemy.rowRange);
    res.nPowerRowEnemySeige = powerRow(enemy.rowSeige);
    res.nTurns = ally.nTurns;
    res.nRounds = ally.nRounds;
    res.nAllyWins = ally.nWins;
    res.allyPassed = ally.passed; 
    res.nEnemyWins = enemy.nWins;
    res.enemyPassed = enemy.passed;

    /// move all cards to a vector
    for (const std::pair<const Card *, CardView> &cardAndViewPair : cardToView)
        res.cards.push_back(std::move(cardAndViewPair.second));
    /// move all choices
    res.choices = std::move(choiceViews);

    /// animation data of current action
    res.actionType = actionType;
    res.actionIdSrc = id(src);
    res.actionIdsDst = {};
    res.actionValue = actionValue;
    for (const Card *card : dst)
        res.actionIdsDst.push_back(id(card));
    res.actionSound = sound;

    /// value computation for hand cards
    if (computeOptionScoreGaps && !ally.cardStack2.isEmpty() && ally.cardStack2.peekChoice().type == CardRoundStartPlay) {
        const std::map<const Card *, int> options = optionToGap(ally, enemy);
        std::cout << std::endl << "HAND OPTIONS (" << options.size() << ")" << std::endl;
        for (const auto &it : options) {
            const int valueGain = (it.second - powerField(ally) + powerField(enemy));
            std::cout << it.first->name << " -> " << (valueGain > 0 ? "+" : "") << valueGain << std::endl;
        }
    }

    return res;
}

bool isIn(const int id, const std::vector<int> &vector)
{
    for (const int _id : vector)
        if (id == _id)
            return true;
    return false;
}

CardView &FieldView::cardView(const int id)
{
    assert(id > -1);
    for (CardView &cardView : cards)
        if (cardView.id == id)
            return cardView;
    assert(false);
}

const CardView &FieldView::cardView(const int id) const
{
    assert(id > -1);
    for (const CardView &cardView : cards)
        if (cardView.id == id)
            return cardView;
    assert(false);
}

bool FieldView::idAtRowAndPos(const Row screenRow, const Pos screenPos, int *id, int *n) const
{
    assert((0 <= screenRow) && (screenRow < 6));
    assert((0 <= screenPos) && (screenPos < 9));

    const std::vector<int> *rowIds = nullptr;
    switch (screenRow) {
    case 0: rowIds = &enemyRowSeigeIds; break;
    case 1: rowIds = &enemyRowRangeIds; break;
    case 2: rowIds = &enemyRowMeeleIds; break;
    case 3: rowIds = &allyRowMeeleIds;  break;
    case 4: rowIds = &allyRowRangeIds;  break;
    case 5: rowIds = &allyRowSeigeIds;  break;
    default: assert(false);             break;
    }

    if (n)
        *n = int(rowIds->size());

    if (size_t(screenPos) >= rowIds->size())
        return false;

    if (id)
        *id = rowIds->at(size_t(screenPos));

    return true;
}

bool FieldView::rowAndPos(const int id, Row *row, Pos *pos, bool *isAlly) const
{
    Row _row;
    Pos _pos;
    bool _isAlly;
    for (size_t i = 0; i < allyRowMeeleIds.size(); ++i)
        if (id == allyRowMeeleIds[i]) {
            _row = Meele;
            _pos = Pos(i);
            _isAlly = true;
            goto found;
        }
    for (size_t i = 0; i < allyRowRangeIds.size(); ++i)
        if (id == allyRowRangeIds[i]) {
            _row = Range;
            _pos = Pos(i);
            _isAlly = true;
            goto found;
        }
    for (size_t i = 0; i < allyRowSeigeIds.size(); ++i)
        if (id == allyRowSeigeIds[i]) {
            _row = Seige;
            _pos = Pos(i);
            _isAlly = true;
            goto found;
        }
    for (size_t i = 0; i < enemyRowMeeleIds.size(); ++i)
        if (id == enemyRowMeeleIds[i]) {
            _row = Meele;
            _pos = Pos(i);
            _isAlly = false;
            goto found;
        }
    for (size_t i = 0; i < enemyRowRangeIds.size(); ++i)
        if (id == enemyRowRangeIds[i]) {
            _row = Range;
            _pos = Pos(i);
            _isAlly = false;
            goto found;
        }
    for (size_t i = 0; i < enemyRowSeigeIds.size(); ++i)
        if (id == enemyRowSeigeIds[i]) {
            _row = Seige;
            _pos = Pos(i);
            _isAlly = false;
            goto found;
        }
    return false;

found:
    if (row)
        *row = _row;
    if (pos)
        *pos = _pos;
    if (isAlly)
        *isAlly = _isAlly;
    return true;
}

RowEffect FieldView::rowEffect(const Row screenRow) const
{
    assert((0 <= screenRow) && (screenRow < 6));
    switch (screenRow) {
    case 0: return enemyRowEffectSeige;
    case 1: return enemyRowEffectRange;
    case 2: return enemyRowEffectMeele;
    case 3: return allyRowEffectMeele;
    case 4: return allyRowEffectRange;
    case 5: return allyRowEffectSeige;
    default: assert(false);
    }
    return NoRowEffect;
}

int FieldView::rowPower(const Row screenRow) const
{
    assert((0 <= screenRow) && (screenRow < 6));
    switch (screenRow) {
    case 0: return nPowerRowEnemySeige;
    case 1: return nPowerRowEnemyRange;
    case 2: return nPowerRowEnemyMeele;
    case 3: return nPowerRowAllyMeele;
    case 4: return nPowerRowAllyRange;
    case 5: return nPowerRowAllySeige;
    default: assert(false);
    }
    return 0;
}

std::string ChoiceView::toString() const
{
    switch (choiceType) {
    case CardRoundStartPlay:
        return "Choose a card to play";
    case RowAndPosAlly:
        return "Choose an allied row and pos";
    case RowAndPosEnemy:
        return "Choose an enemy row and pos";
    case RowSelect:
        return "Choose a row";
    case CardOption:
        return "Choose an option";
    case CardTarget: {
        std::string res = "Choose an ability target";
        if ((nTargets > 1) || isOptional) {
            res += " [";
            if (isOptional)
                res += "optional";
            if (nTargets > 1) {
                if (isOptional)
                    res += " ";
                res += std::to_string(cardOptionIdsSelected.size()) + "/" + std::to_string(nTargets);
            }
            res += "]";
        }
        return res;
    }
    case CardRoundStartSwap:
        return "Choose a card to swap [" + std::to_string(nTargets) + " left]";
    }
    assert(false);
}

std::string stringRarity(const Rarity rarity)
{
    switch (rarity) {
    case Bronze: return "Bronze";
    case Silver: return "Silver";
    case Gold: return "Gold";
    default:
        assert(false);
        return "Rarity?";
    }
}

std::string stringTag(const Tag tag)
{
    switch (tag) {
    case Beast: return "Beast";
    case Relict: return "Relict";
    case Vampire: return "Vampire";
    case Construct: return "Construct";
    case Ogroid: return "Ogroid";
    case Insectoid: return "Insectoid";
    case Necrophage: return "Necrophage";
    case Draconid: return "Draconid";
    case Vodyanoi: return "Vodyanoi";
    case Elf: return "Elf";
    case Dwarf: return "Dwarf";
    case Dryad: return "Dryad";
    case Aedirn: return "Aedirn";
    case Temeria: return "Temeria";
    case Redania: return "Redania";
    case Kaedwen: return "Kaedwen";
    case Cintra: return "Cintra";
    case ClanAnCraite: return "Clan an Craite";
    case ClanBrokvar: return "Clan Brokvar";
    case ClanHeymaey: return "Clan Heymaey";
    case ClanDimun: return "Clan Dimun";
    case ClanTordarroch: return "Clan Tordarroch";
    case ClanTuirseach: return "Clan Tuirseach";
    case ClanDrummond: return "Clan Drummond";
    case Cursed: return "Cursed";
    case Support: return "Support";
    case Officer: return "Officer";
    case Mage: return "Mage";
    case Soldier: return "Soldier";
    case Machine: return "Machine";
    case Agent: return "Agent";
    case Witcher: return "Witcher";
    case Leader: return "Leader";
    case Cultist: return "Cultist";
    case WildHunt: return "Wild Hunt";
    case Alchemy: return "Alchemy";
    case Tactics: return "Tactics";
    case Spell: return "Spell";
    case Item: return "Item";
    case Organic: return "Organic";
    case Hazard: return "Hazard";
    case Boon: return "Boon";
    case Neutral: return "Neutral";
    case Monster: return "Monster";
    case Nilfgaard: return "Nilfgaard";
    case NothernRealms: return "Nothern Realms";
    case Scoiatael: return "Scoia'tael";
    case Skellige: return "Skellige";
    default:
        assert(false);
        return "Tag?";
    }
}

bool isLeader(const CardView &view)
{
    for (const Tag tag : view.tags)
        if (tag == Leader)
            return true;
    return false;
}
