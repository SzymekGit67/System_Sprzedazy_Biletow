#ifndef SALA_H
#define SALA_H
#include <vector>

using namespace std;

class Sala {
private:
    int numer;
    int liczbaRzedow;
    int miejscaWRzedzie;
    vector<vector<bool>> zajete;    //true - zajęte,false -wolne

public:
    Sala();
    Sala(int numer, int liczbaRzedow, int miejscaWRzedzie);
    int getNumer() const;
    int getLiczbaRzedow() const;
    int getMiejscaWRzedzie() const;
    bool czyWolne(int rzad, int miejsce) const;
    void zajmij(int rzad, int miejsce);
    void zwolnij(int rzad, int miejsce);
    int liczbaWolnych() const;
    void wyswietl() const;
};

#endif
