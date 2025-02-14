#include <iostream>
#include "seuraaja.h"
#include "notifikaattori.h"

using namespace std;

int main()
{
    notifikaattori noti;

    Seuraaja a("Morgan");
    Seuraaja b("Marston");
    Seuraaja c("Adler");

    noti.lisaa(&a);
    noti.lisaa(&b);
    noti.lisaa(&c);
    noti.tulosta();

    noti.postita("Hei moi!");
    noti.poista(&b);

    noti.postita("Moi hei!");

    return 0;
}
