#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikZAdresatami : public PlikTekstowy
{
    //const string nazwaPlikuZAdresatami;
    //const string nazwaTymczasowegoPlikuZAdresatami;
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);

public:
    //PlikZAdresatami(string NAZWAPLIKUZADRESATAMI) : nazwaPlikuZAdresatami(NAZWAPLIKUZADRESATAMI) {};
    PlikZAdresatami(string nazwaPliku) : PlikTekstowy(nazwaPliku) {};
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku(vector <Adresat> &adresaci, int idZalogowanegoUzytkownika);
    void dopiszAdresataDoPliku(Adresat adresat);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    //bool czyPlikJestPusty(fstream &plikTekstowy);
    int usunWybranegoAdresataZPliku(int idUsuwanegoAdresata);
    int pobierzZPlikuIdOstatniegoAdresata();
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);
    void edytujDaneWybranegoAdresataWPliku(int idEdytowanegoAdresata, string liniaZDanymiAdresata);
};

#endif
