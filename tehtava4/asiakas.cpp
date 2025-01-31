#include "asiakas.h"

asiakas::asiakas(string nimi, double luottoraja) : nimi(nimi), kayttotili(nimi), creditili(nimi, luottoraja) {}

void asiakas::showSaldo() {
    cout << "User: " << nimi << endl;
    cout << "Bank account balance: " << kayttotili.getBalance() << " EUR" << endl;
    cout << "Credit account balance: " << creditili.getBalance() << " EUR" << endl << endl;
}

string asiakas::getNimi()
{
    return nimi;
}

bool asiakas::talletus(double amount)
{

    return kayttotili.deposit(amount);
}

bool asiakas::nosto(double amount)
{
    return kayttotili.withdraw(amount);
}

bool asiakas::luotonMaksu(double amount)
{
    return creditili.deposit(amount);
}

bool asiakas::luotonNosto(double amount)
{
    return creditili.withdraw(amount);
}

bool asiakas::tiliSiirto(double amount, asiakas &T)
{
    if (amount <= 0) {
        return false;
    }

    // Yritetään nostaa rahat lähettäjän tililtä
    if (!kayttotili.withdraw(amount)) {
        return false;
    }

    // Jos nosto onnistui, talletetaan rahat vastaanottajan tilille
    if (!T.kayttotili.deposit(amount)) {
        return false;
    }

    cout << "Transfer successful!" << endl << endl;
    return true;
}




