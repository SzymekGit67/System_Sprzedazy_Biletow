#ifndef SEANS_H
#define SEANS_H
#include "Sala.h"
#include "Film.h"
#include <string>
using namespace std;

class Seans {
private:
    Film film;
    Sala sala;
    string godzina;
    double cenaBazowa;
public:
    Seans();
    Seans(const Film& film, const Sala& sala, const string& godzina, double cenaBazowa);

    const Film& getFilm() const;
    Sala& getSala();
    const Sala& getSala() const;
    string getGodzina() const;
    double getCenaBazowa() const;

    void setGodzina(const string& godzina);
    void setCenaBazowa(double cenaBazowa);

    void wyswietl() const;
};

#endif