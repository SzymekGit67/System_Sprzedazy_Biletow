#include "BiletUlgowy.h"
using namespace std;

BiletUlgowy::BiletUlgowy(const Seans& seans, int rzad, int miejsce)
    : Bilet(seans, rzad, miejsce) {}

double BiletUlgowy::cena() const { return cenaBazowa * 0.7; }

string BiletUlgowy::typ() const { return "Ulgowy"; }