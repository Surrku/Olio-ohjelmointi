#include "luottotili.h"
#include <iostream>
using namespace std;

luottotili::luottotili(string lnimi, double lraja)
    : pankkitili(lnimi), luottoRaja(lraja) {
    cout<<"Credit account was created " << omistaja << ". Credit limit: " <<luottoRaja<<endl<<endl;
}

bool luottotili::deposit(double amount) {
    if (amount <= 0) {
        cout << "Deposit failed. Given sum was negative" << endl;
        return false;
    }
    saldo += amount;
    return true;
}

bool luottotili::withdraw(double amount) {
    if (amount <= 0) {
        cout << "Withdraw failed. Given sum was negative" << endl;
        return false;
    }
    if (amount > saldo + luottoRaja) {
        cout << "Withdraw failed. Not enough money or credit limit exceeded" << endl;
        return false;
    }
    saldo -= amount;
    return true;
}
