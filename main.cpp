#include "cards.h"

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

    const auto traceFields = [&]{
        std::cout << "ally:\n";
        traceField(ally);
        std::cout << "\n\nenemy:\n";
        traceField(enemy);
    };
    {

        startChoiceToPlayCard(ally);
        onChoiceDoneCard(&dp, ally, enemy);
        onChoiceDoneRowAndPlace(Meele, 0, ally, enemy);
        onChoiceDoneCard(&c, ally, enemy);
        onChoiceDoneRowAndPlace(Meele, 0, ally, enemy);
        traceFields();
    }

    return 0;
}
