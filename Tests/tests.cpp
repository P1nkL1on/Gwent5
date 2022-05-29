#include "tests.h"

#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>

#include <QTest>
#include <QtDebug>

#include "Cards/archieve.h"

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

void Tests::singleUnitDeploy()
{
    Field a, e;
    auto *t = new TridamInfantry();
    initField({t}, nullptr, a);
    a.cardStack.push_back(Choice(RoundStartPlay, nullptr, a.deck));
    onChoiceDoneCard(t, a, e);
    onChoiceDoneRowAndPlace(RowAndPos(Meele, 0), a, e);

    std::string s;
    fieldToFile(&a, s);

    test("simple", s);
}

void Tests::fieldToFile(const Field *field, std::string &s)
{
    if (!field->snapshots.size())
        return;

    const auto vectorToFile = [](const std::vector<int> &v, std::string &s) {
        s += "[";
        for (size_t ind = 0; ind < v.size(); ++ind)
            s += (ind == 0 ? "" : ", ") + std::to_string(v[ind]);
        s += "]";
    };
    const auto rowEffectToFile = [](const RowEffect &r, std::string &s) {
        switch (r) {
        case NoRowEffect:           s += "NO"; break;
        case TorrentialRainEffect:  s += "TORRENTIAL_RAIN"; break;
        case BitingFrostEffect:     s += "BITING_FROST"; break;
        case ImpenetrableFogEffect: s += "IMPENETRATABLE_FOG"; break;
        case SkelligeStormEffect:   s += "SKELLIGE_STORM"; break;
        case DragonsDreamEffect:    s += "DRAGONS_DREAM"; break;
        case KorathiHeatwaveEffect: s += "KORATHI_HEATHWAVE"; break;
        case RaghNarRoogEffect:     s += "RAGH_NAR_ROOG"; break;
        case BloodMoonEffect:       s += "BLOODMOON"; break;
        case PitTrapEffect:         s += "PIT_TRAP"; break;
        case GoldenFrothEffect:     s += "GOLDEN_FROTH"; break;
        case FullMoonEffect:        s += "FULL_MOON"; break;
        }
    };

    s += "ACTIONS:\n";
    for (const FieldView &snapshot : field->snapshots) {
        s += "type = ";
        switch (snapshot.actionType) {
        case Invalid:           Q_ASSERT(false); break;
        case TurnStart:         s += "TURN_START";  break;
        case PlaySpecial:       s += "PLAY_SPECIAL"; break;
        case PutOnField:        s += "PUT_ON_FIELD"; break;
        case PutToHand:         s += "PUT_TO_HAND"; break;
        case PutToDiscard:      s += "PUT_TO_DISCARD"; break;
        case Destroyed:         s += "DESTROYED"; break;
        case Banished:          s += "BANISHED"; break;
        case DealDamage:        s += "DEAL_DAMAGE"; break;
        case Damaged:           s += "DAMAGED"; break;
        case DamagedInArmor:    s += "DAMAGED_IN_ARMOR"; break;
        case Boosted:           s += "BOOSTED"; break;
        case GainArmor:         s += "GAIN_ARMOR"; break;
        case MoveFromRowToRow:  s += "MOVE_FROM_ROW_TO_ROW"; break;
        case TimerSet:          s += "TIMER_SET"; break;
        case FlipOver:          s += "FLIP_OVER"; break;
        case GainLock:          s += "GAIN_LOCK"; break;
        case LostLock:          s += "LOST_LOCK"; break;
        case GainSpy:           s += "GAIN_SPY"; break;
        case LostSpy:           s += "LOST_SPY"; break;
        case Reveal:            s += "REVEAL"; break;
        case Conceal:           s += "CONCEAL"; break;
        case Transform:         s += "TRANSFORM"; break;
        }
        s += ", src = " + std::to_string(snapshot.actionIdSrc);
        s += ", dst = ";
        vectorToFile(snapshot.actionIdsDst, s);
        s += ", value = " + std::to_string(snapshot.actionValue);
        s += "\n";
    }

    s += "LAST SNAPSHOT:\n";
    const FieldView &snapshot = field->snapshots.back();

    for (const CardView &card : snapshot.cards) {
        s += "id = " + std::to_string(card.id);
        s += ", name = \"" + card.name;
        s += "\", power = " + std::to_string(card.power);
        s += ", powerBase = " + std::to_string(card.powerBase);
        s += ", armor = " + std::to_string(card.armor);
        s += ", rarity = " + std::to_string(card.rarity);
        s += ", timer = " + std::to_string(card.timer);

        if (card.isLocked)      s += ", LOCKED";
        if (card.isSpy)         s += ", SPYING";
        if (card.isResilient)   s += ", RESILIENT";
        if (card.isAmbush)      s += ", AMBUSH";
        if (card.isImmune)      s += ", IMMUNE";
        if (card.isDoomed)      s += ", DOOMED";
        if (card.isRevealed)    s += ", REVEALED";
        s += "\n";
    }

    s += "allyLeader = " + std::to_string(snapshot.allyLeader);
    s += ",\nallyRowMeeleIds = ";
    vectorToFile(snapshot.allyRowMeeleIds, s);
    s += ",\nallyRowRangeIds = ";
    vectorToFile(snapshot.allyRowRangeIds, s);
    s += ",\nallyRowSeigeIds = ";
    vectorToFile(snapshot.allyRowSeigeIds, s);
    s += ",\nallyHandIds = ";
    vectorToFile(snapshot.allyHandIds, s);
    s += ",\nallyDeckIds = ";
    vectorToFile(snapshot.allyDeckIds, s);
    s += ",\nallyDiscardIds = ";
    vectorToFile(snapshot.allyDiscardIds, s);
    s += ",\nenemyLeader = " + std::to_string(snapshot.enemyLeader);
    s += ",\nenemyRowMeeleIds = ";
    vectorToFile(snapshot.enemyRowMeeleIds, s);
    s += ",\nenemyRowRangeIds = ";
    vectorToFile(snapshot.enemyRowRangeIds, s);
    s += ",\nenemyRowSeigeIds = ";
    vectorToFile(snapshot.enemyRowSeigeIds, s);
    s += ",\nenemyHandIds = ";
    vectorToFile(snapshot.enemyHandIds, s);
    s += ",\nenemyDeckIds = ";
    vectorToFile(snapshot.enemyDeckIds, s);
    s += ",\nenemyDiscardIds = ";
    vectorToFile(snapshot.enemyDiscardIds, s);
    s += ",\ncardsAppearedIds = ";
    vectorToFile(snapshot.cardsAppearedIds, s);
    s += ",\ncardsPlayedIds = ";
    vectorToFile(snapshot.cardsPlayedIds, s);
    s += ",\nnPowerRowAllyMeele = " + std::to_string(snapshot.nPowerRowAllyMeele);
    s += ",\nnPowerRowAllyRange = " + std::to_string(snapshot.nPowerRowAllyRange);
    s += ",\nnPowerRowAllySeige = " + std::to_string(snapshot.nPowerRowAllySeige);
    s += ",\nnPowerRowEnemyMeele = " + std::to_string(snapshot.nPowerRowEnemyMeele);
    s += ",\nnPowerRowEnemyRange = " + std::to_string(snapshot.nPowerRowEnemyRange);
    s += ",\nnPowerRowEnemySeige = " + std::to_string(snapshot.nPowerRowEnemySeige);
    s += ",\nnTurns = " + std::to_string(snapshot.nTurns);
    s += ",\nnRounds = " + std::to_string(snapshot.nRounds);
    s += ",\nnAllyWins = " + std::to_string(snapshot.nAllyWins);
    s += ",\nnEnemyWins = " + std::to_string(snapshot.nEnemyWins);
    s += ",\nallyPassed = " + std::to_string(snapshot.allyPassed);
    s += ",\nenemyPassed = " + std::to_string(snapshot.enemyPassed);
    s += ",\nallyRowEffectMeele = ";
    rowEffectToFile(snapshot.allyRowEffectMeele, s);
    s += ",\nallyRowEffectRange = ";
    rowEffectToFile(snapshot.allyRowEffectRange, s);
    s += ",\nallyRowEffectSeige = ";
    rowEffectToFile(snapshot.allyRowEffectSeige, s);
    s += ",\nenemyRowEffectMeele = ";
    rowEffectToFile(snapshot.enemyRowEffectMeele, s);
    s += ",\nenemyRowEffectRange = ";
    rowEffectToFile(snapshot.enemyRowEffectRange, s);
    s += ",\nenemyRowEffectSeige = ";
    rowEffectToFile(snapshot.enemyRowEffectSeige, s);
    s += "\n";
}

void Tests::test(const std::string &name, const std::string &text) const
{
    const std::string suffixExpected = "_expected";
    const std::string suffixActual = "_actual";
    const std::string filename = _dir + name
            + (_writeExpected ? suffixExpected : suffixActual);
    writeToFile(filename, text);
    const bool isOk = _writeExpected || compareFiles(
                _dir + name + suffixActual,
                _dir + name + suffixExpected);
    QVERIFY(isOk);
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
