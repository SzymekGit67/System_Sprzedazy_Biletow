#ifndef BILETNORMALNY_H
#define BILETNORMALNY_H

#include "Bilet.h"
using namespace std;

class BiletNormalny : public Bilet {
public:
    BiletNormalny(const Seans& seans, int rzad, int miejsce);

    double cena() const override;
    string typ() const override;
};

#endif