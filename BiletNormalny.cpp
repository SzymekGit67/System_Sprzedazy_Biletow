#include "BiletNormalny.h"
using namespace std;

BiletNormalny::BiletNormalny(const Seans& seans, int rzad, int miejsce)
    : Bilet(seans, rzad, miejsce) {}

double BiletNormalny::cena() const { return cenaBazowa; }

string BiletNormalny::typ() const { return "Normalny"; }