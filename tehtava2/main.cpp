#include <iostream>
#include "Game.h"

using namespace std;


int main()
{
    int maxNumber;

    cout << "Anna suurin mahdollinen numero" << endl;
    cin >> maxNumber;

    Game game(maxNumber);

    game.play();

    return 0;
}
