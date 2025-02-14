#include "seuraaja.h"
#include <iostream>
using namespace std;

Seuraaja::Seuraaja(string n) : nimi(n){
    cout<<"Luodaan seuraaja: "<<nimi<<endl;
}

string Seuraaja::getNimi()
{
    return nimi;
}

void Seuraaja::paivitys(string viesti)
{
    cout<<"Nimi: "<<nimi<<". Viesti: "<<viesti<<endl;
}
