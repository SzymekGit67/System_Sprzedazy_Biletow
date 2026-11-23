#ifndef BILET_H
#define BILET_H

#include <string>
#include <iostream>
#include "Seans.h"
using namespace std;

class Bilet {
protected:
    string tytul;
    string godzina;
    int numerSali;
    int rzad;
    int miejsce;
    double cenaBazowa;

public:
    Bilet();
    Bilet(const Seans& seans, int rzad, int miejsce);
    virtual ~Bilet();

    virtual double cena() const;
    virtual string typ() const;
    virtual void wyswietl() const;

    int getRzad() const;
    int getMiejsce() const;

    friend ostream& operator<<(ostream& os, const Bilet& b);
};

ostream& operator<<(ostream& os, const Bilet& b);

#endif