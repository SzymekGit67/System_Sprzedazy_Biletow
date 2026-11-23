#ifndef BILETULGOWY_H
#define BILETULGOWY_H

#include "Bilet.h"
using namespace std;

class BiletUlgowy : public Bilet {
public:
    BiletUlgowy(const Seans& seans, int rzad, int miejsce);

    double cena() const override;
    string typ() const override;
};

#endif