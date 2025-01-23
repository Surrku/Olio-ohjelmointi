#include "chef.h"
#include <iostream>

using namespace std;

chef::chef(string n):chefName(n) {
    cout<<"Chef "<<chefName<<" created"<<endl;
}

chef::~chef() {
    cout<<"Chef "<<chefName<<" destroyed"<<endl;
}

string chef::getName()
{
    return chefName;

}

int chef::makeSalad(int ingredients)
{
    if (ingredients < 5) {
        return 0;
    }

    return ingredients / 5;

}

int chef::makeSoup(int ingredients)
{
    if (ingredients < 3) {
        return 0;
    }
    return ingredients / 3;
}
