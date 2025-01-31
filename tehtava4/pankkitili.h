#ifndef PANKKITILI_H
#define PANKKITILI_H
#include <iostream>
using namespace std;

class pankkitili
{
public:
    pankkitili(string);
    virtual double getBalance();
    virtual bool deposit(double);
    virtual bool withdraw(double);

protected:
    string omistaja;
    double saldo;
};

#endif // PANKKITILI_H
