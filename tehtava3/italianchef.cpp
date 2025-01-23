#include "italianchef.h"
#include <iostream>
using namespace std;

italianChef::italianChef(string i): chef(i) {
    cout << "Italian chef " << getName() << " created" << endl;
}

italianChef::~italianChef() {
    cout << "Italian chef " << getName() << " destroyed" << endl;
}


bool italianChef::askSecret(string givenPassword, int flour, int water) {
    if (password.compare(givenPassword) == 0) {
        cout<<"Password was correct"<<endl;
        return makePizza(flour, water) == 0;
    } else {
        cout<<"Password was wrong"<<endl;
        return false;
    }

}

int italianChef::makePizza(int flour, int water) {
    if (flour >= 5 && water >= 5)    {
        cout<<"Italian chef made pizza!"<<endl<<endl;

    return 0;
   }
    cout<<"Italian chef didn't have enough flour and/or water to make pizza"<<endl<<endl;
    return 1;
}
