#include <iostream>

using namespace std;

class Uzytkownik
{
    int id = 0;
    string login;
    string haslo;

public:
    void ustawID(int noweId);
    void ustawLogin(string nowyLogin);
    void ustawHaslo(string noweHaslo);

    int pobierzId();
    string pobierzLogin();
    string pobierzHaslo();
};
