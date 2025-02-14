#ifndef NOTIFIKAATTORI_H
#define NOTIFIKAATTORI_H
#include "seuraaja.h"
#include <iostream>
using namespace std;

class notifikaattori
{
public:
    notifikaattori();
    void lisaa(Seuraaja* );
    void poista(Seuraaja* );
    void tulosta();
    void postita (string);

private:
    Seuraaja* seuraajat = nullptr;
};

#endif // NOTIFIKAATTORI_H
