#include "pankkitili.h"
#include <iostream>
using namespace std;

pankkitili::pankkitili(string name) : omistaja(name), saldo(1000) {
    cout<<"Bank account was created " << omistaja << ". Current bank balance: " << saldo <<endl;
}

double pankkitili::getBalance()
{
    return saldo;
}

bool pankkitili::deposit(double amount)
{
    if (amount <= 0) {
        cout<<"Deposit failed. Given sum was negative"<<endl;
            return false;
    }
    saldo += amount;
    return true;
}

bool pankkitili::withdraw(double amount)
{
    if (amount <= 0) {
        cout<<"Withdrawn failed. Given sum was negative"<<endl;
        return false;
    }
    if (amount > saldo){
        cout<<"Withdrawn failed. Not enough money in the account"<<endl;
        return false;
    }
    saldo -= amount;
    return true;
}
