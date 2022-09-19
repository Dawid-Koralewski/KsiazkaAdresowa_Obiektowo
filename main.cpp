#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    while (true)
    {
        ksiazkaAdresowa.pokazMenuGlowne();
    }

    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    return 0;
}
