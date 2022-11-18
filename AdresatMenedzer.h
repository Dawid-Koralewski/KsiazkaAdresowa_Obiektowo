#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Adresat.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMenedzer
{
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    PlikZAdresatami tymczasowyPlikZAdresatami;
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    int idOstatniegoAdresata = 0;
    int idUsunietegoAdresata = 0;

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami, string nazwaTymczasowegoPlikuZAdresatami, int idZalogowanegoUzytkownika)
        : plikZAdresatami(nazwaPlikuZAdresatami), tymczasowyPlikZAdresatami(nazwaTymczasowegoPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };
    Adresat podajDaneNowegoAdresata();
    void dodajAdresata();
    void ustawIdOstatniegoAdresata(int noweID);
    void ustawidUsunietegoAdresata(int noweID);
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdZalogowanegoUzytkownika();
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    vector <Adresat> pobierzAdresatow();
    void wyswietlWszystkichAdresatow();
    int usunAdresata();
    int podajIdWybranegoAdresata();
    int pobierzIdOstatniegoAdresata();
    int pobierzIdUsunietegoAdresata();
    int podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsunietegoAdresata, int idOstatniegoAdresata);
    void zaktualizujDaneWybranegoAdresata(Adresat adresat);
    void edytujAdresata();
    char wybierzOpcjeZMenuEdycja();
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
};

#endif
