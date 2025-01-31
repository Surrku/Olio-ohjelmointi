#include <iostream>
#include "pankkitili.h"
#include "luottotili.h"
#include "asiakas.h"

using namespace std;

int main() {
    asiakas asiakas1("Seppo", 1000);

    cout << "How much money are you going to deposit?" << endl;
    double depositAmount;
    cin >> depositAmount;
    if (asiakas1.talletus(depositAmount)) {
        cout << "Deposit successful!" << endl;
    }

    cout << "How much money are you going to withdraw?" << endl;
    double withdrawAmount;
    cin >> withdrawAmount;
    if (asiakas1.nosto(withdrawAmount)) {
        cout << "Withdraw successful!" << endl;
    }

    cout << "How much money are you going to withdraw from your credit account?" << endl;
    double creditWithdraw;
    cin >> creditWithdraw;
    if (asiakas1.luotonNosto(creditWithdraw)) {
        cout << "Credit withdraw successful!"<<endl;

    }

    cout << "How much money are you going to pay back to your credit account?" << endl;
    double creditDeposit;
    cin >> creditDeposit;
    if (asiakas1.luotonMaksu(creditDeposit)) {
        cout << "Credit payment successful!" << endl<<endl;
    }

    asiakas1.showSaldo();

    asiakas asiakas2("Ismo", 1000);

    cout << "How much money will Seppo transfer to Ismo?" << endl << endl;
    double transfer;
    cin >> transfer;

    if (asiakas1.tiliSiirto(transfer, asiakas2))

    asiakas1.showSaldo();
    asiakas2.showSaldo();

    return 0;
}


