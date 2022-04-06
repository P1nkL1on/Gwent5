#include "../Cards/cards.h"

#include <QTextStream>
#include <iostream>

int main(int, char *[])
{
    Field ally;
    Field enemy;

    AddaStriga c;
    ally.hand.push_back(&c);
    DeithwenArbalest d;
    ally.hand.push_back(&d);
    DandelionPoet dp;
    ally.hand.push_back(&dp);
    TemerianDrummer td;
    ally.hand.push_back(&td);

    const auto traceFields = [&]{
        std::cout << "ally:\n";
        traceField(ally);
        std::cout << "\n\nenemy:\n";
        traceField(enemy);
    };
    {
        startChoiceToPlayCard(ally);
        traceFields();
        onChoiceDoneCard(&dp, ally, enemy);
        onChoiceDoneRowAndPlace(Meele, 0, ally, enemy);
        onChoiceDoneCard(&td, ally, enemy);
        onChoiceDoneRowAndPlace(Meele, 0, ally, enemy);
        onChoiceDoneCard(&dp, ally, enemy);

        traceFields();
    }
    return 0;
}
