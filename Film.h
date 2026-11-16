#ifndef FILM_H
#define FILM_H
#include <string>
using namespace std;


class Film {
private:
    string tytul;
    int czasTrwania;
    string gatunek;

public:
    Film();
    Film(const string& tytul, int czasTrwania, const string& gatunek);
    string getTytul() const;
    int getCzasTrwania() const;
    string getGatunek() const;
    void setTytul(const string& tytul);
    void setCzasTrwania(int czasTrwania);
    void setGatunek(const string& gatunek);
    void wyswietl() const;
};

#endif