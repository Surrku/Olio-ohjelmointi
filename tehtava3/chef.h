#ifndef CHEF_H
#define CHEF_H
#include <iostream>

using namespace std;

class chef
{
public:
    chef(string);
    ~chef();
    string getName();
    int makeSalad(int ingredients);
    int makeSoup(int ingredients);

protected:
    string chefName;
};

#endif // CHEF_H
