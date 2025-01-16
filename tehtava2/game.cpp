#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;

//Konstruktorin määritelmä
Game::Game(int maxNumber) : maxNumber(maxNumber), numOfGuesses(0), playerGuess(0) {
    srand(time(NULL));
    randomNumber = rand() % maxNumber +1;

    cout << "GAME CONSTRUCT: max value given " << maxNumber << endl;

}

Game::~Game() {

    cout << "GAME DESTRUCTOR: object cleared " << endl;

}

void Game::play() {

    while (true) {
        cout << "Arvaa numero (1 - " << maxNumber << "): ";
        cin >> playerGuess;
        numOfGuesses++;

        if (playerGuess == randomNumber) {
            cout << "Arvasit oikein!" << endl;
            printGameResult();
            break;
        }
        else if (playerGuess < randomNumber) {
            cout << "Numero oli liian pieni. Arvaa uudestaan." << endl;
        }
        else {
            cout << "Numero oli liian iso. Arvaa uudestaan." << endl;
        }
    }
}

void Game::printGameResult() {
    cout << "Oikea vastaus: " << randomNumber << endl;
    cout << "Arvauksia: " << numOfGuesses << endl;
}
