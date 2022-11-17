#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::pokazMenuGlowne()
{
    char wybor;
        if (zalogowanyUzytkownik.pobierzId() == 0)
        {
            wybor = wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                rejestracjaUzytkownika();
                break;
            case '2':
                zalogowanyUzytkownik = uzytkownikMenedzer.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, "AdresaciTEMP.txt", zalogowanyUzytkownik.pobierzId());

            wybor = wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                adresatMenedzer -> dodajAdresata();
                break;

            case '4':
                adresatMenedzer -> wyswietlWszystkichAdresatow();
                break;

            case '5':
                adresatMenedzer->ustawidUsunietegoAdresata(adresatMenedzer->usunAdresata());
                adresatMenedzer->ustawIdOstatniegoAdresata(adresatMenedzer->podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(adresatMenedzer->pobierzIdUsunietegoAdresata(), adresatMenedzer->pobierzIdOstatniegoAdresata()));
                break;

            case '6':
                adresatMenedzer->edytujAdresata();
                break;

            case '7':
                uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
                break;

            case '8':
                zalogowanyUzytkownik.ustawID(0);
                delete adresatMenedzer;
                adresatMenedzer = NULL;
                break;
            }
        }
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego()
{
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika()
{
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}
