#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <windows.h>
#include <fstream>

using namespace std;

class MetodyPomocnicze
{

public:
    static string konwerjsaIntNaString(int liczba);
    static string wczytajLinie();
    static char wczytajZnak();
};

#endif
