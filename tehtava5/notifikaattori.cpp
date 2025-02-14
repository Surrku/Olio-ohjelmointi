#include "notifikaattori.h"
#include "seuraaja.h"
#include <iostream>
using namespace std;

notifikaattori::notifikaattori() {
    cout<<"Notifikaattori luotu"<<endl<<endl;
}

void notifikaattori::lisaa(Seuraaja * s)
{
    uusi->next = seuraajat;
    seuraajat = uusi;
}

void notifikaattori::poista(Seuraaja * s)
{
    if (!seuraajat) return;

    if (seuraajat == poistettava) {
        seuraajat = seuraajat->next;
        delete poistettava;
        return;
    }

    // Muuten etsitään poistettava listasta
    Seuraaja* edellinen = seuraajat;
    while (edellinen->next && edellinen->next != poistettava) {
        edellinen = edellinen->next;
    }

    if (edellinen->next) {
        edellinen->next = poistettava->next;
        delete poistettava;
    }
}

// Tulostaa kaikki seuraajat
void tulosta() {
    Seuraaja* nykyinen = Seuraaja;
    while (nykyinen) {
        std::cout << nykyinen->getNimi() << std::endl;
        nykyinen = nykyinen->next;
    }
}

// Lähettää viestin kaikille seuraajille
void postita(std::string viesti) {
    Seuraaja* nykyinen = Seuraaja;
    while (nykyinen) {
        nykyinen->paivitys(viesti);
        nykyinen = nykyinen->next;
    }
}
}

void notifikaattori::tulosta()
{
    Seuraaja* nykyinen = seuraajat;
    while (nykyinen) {
        std::cout << nykyinen->getNimi() << std::endl;
        nykyinen = nykyinen->next;
}

void notifikaattori::postita(string viesti)
{
    {
        Seuraaja* nykyinen = seuraajat;
        while (nykyinen) {
            nykyinen->paivitys(viesti);
            nykyinen = nykyinen->next;
        }
    }
}
