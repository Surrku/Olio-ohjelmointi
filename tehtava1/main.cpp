#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int game(int maxnum);

int main()
{
    int numOfGuess;
    int maxnum;

    cout << "Anna suurin mahdollinen numero" << endl;
    cin >> maxnum;

    numOfGuess = game(maxnum);
    cout << "Arvauksia: " << numOfGuess << endl;

    return 0;
}

int game(int maxnum) {

    srand(time(NULL));
    int randomnum = rand() % maxnum + 1;
    int guess;
    int numOfGuess = 0;

    while (true) {
        cout << "Arvaa numero (1 - " << maxnum << "): ";
        cin >> guess;
        numOfGuess++;

        if (guess == randomnum) {
            cout << "Arvasit oikein!" << endl;
            break;
        }
        else if (guess < randomnum) {
            cout << "Numero oli liian pieni. Arvaa uudestaan." << endl;
        }
        else {
            cout << "Numero oli liian iso. Arvaa uudestaan." << endl;
        }
    }

    return numOfGuess;
}
