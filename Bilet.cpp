#include "Bilet.h"
#include <iostream>
using namespace std;

Bilet::Bilet() : tytul(""), godzina(""), numerSali(0), rzad(0), miejsce(0), cenaBazowa(0.0) {}

Bilet::Bilet(const Seans& seans, int rzad, int miejsce)
    : tytul(seans.getFilm().getTytul()), godzina(seans.getGodzina()),
      numerSali(seans.getSala().getNumer()), rzad(rzad), miejsce(miejsce),
      cenaBazowa(seans.getCenaBazowa()) {}

Bilet::~Bilet() {}

double Bilet::cena() const { return cenaBazowa; }

string Bilet::typ() const { return "Bilet"; }

void Bilet::wyswietl() const {
    cout << "[" << typ() << "] " << tytul << ", " << godzina
         << ", sala " << numerSali << ", rzad " << rzad
         << ", miejsce " << miejsce << ", cena: " << cena() << " zl\n";
}

int Bilet::getRzad() const { return rzad; }
int Bilet::getMiejsce() const { return miejsce; }