#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H

#include "chef.h"
#include <iostream>
using namespace std;

class italianChef : public chef {
public:
    italianChef(string);
    ~italianChef();

    bool askSecret(string givenPassword, int, int);

private:
    string password = "pizza";
    int makePizza(int flour, int water);

};

#endif // ITALIANCHEF_H
