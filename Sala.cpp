#include "Sala.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Sala::Sala(): numer(0), liczbaRzedow(0), miejscaWRzedzie(0) {}

Sala::Sala(int numer, int liczbaRzedow, int miejscaWRzedzie)
    : numer(numer), liczbaRzedow(liczbaRzedow), miejscaWRzedzie(miejscaWRzedzie) {
    if (liczbaRzedow <= 0 || miejscaWRzedzie <= 0)
        throw invalid_argument("Wymiary sali musza byc dodatnie");
    zajete.assign(liczbaRzedow, vector<bool>(miejscaWRzedzie, false));
}
int Sala::getNumer() const { return numer; }
int Sala::getLiczbaRzedow() const { return liczbaRzedow; }
int Sala::getMiejscaWRzedzie() const { return miejscaWRzedzie; }

bool Sala::czyWolne(int rzad, int miejsce) const {
    if (rzad < 1 || rzad >liczbaRzedow || miejsce < 1 ||miejsce >miejscaWRzedzie)
        return false;
    return !zajete[rzad - 1][miejsce - 1];
}

void Sala::zajmij(int rzad, int miejsce) {
    if (rzad < 1 || rzad > liczbaRzedow || miejsce < 1 || miejsce > miejscaWRzedzie)
        throw out_of_range("Nie ma takiego miejsca w sali");
    if (zajete[rzad - 1][miejsce - 1])
        throw runtime_error("Miejsce jest juz zajete");
    zajete[rzad - 1][miejsce - 1] = true;
}

void Sala::zwolnij(int rzad, int miejsce) {
    if (rzad < 1 || rzad > liczbaRzedow || miejsce < 1 || miejsce > miejscaWRzedzie)
        throw out_of_range("Nie ma takiego miejsca w sali");
    if (!zajete[rzad - 1][miejsce - 1])
        throw runtime_error("Miejsce nie jest zajete");
    zajete[rzad - 1][miejsce - 1] = false;
}

int Sala::liczbaWolnych() const {
    int licznik = 0;
    for (int i = 0; i < liczbaRzedow; i++)
        for (int j = 0; j < miejscaWRzedzie; j++)
            if (!zajete[i][j])
                licznik++;
    return licznik;
}

void Sala::wyswietl() const {
    cout << "Sala " << numer << " (X = zajete)\n   ";
    for (int j = 1; j <= miejscaWRzedzie; j++)
        cout << j << " ";
    cout << "\n";
    for (int i = 0; i < liczbaRzedow; i++) {
        cout << i + 1 << ": ";
        for (int j = 0; j < miejscaWRzedzie; j++)
            cout << (zajete[i][j] ? "X " : "O ");
        cout << "\n";
    }
}