#include "Seans.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Seans::Seans():godzina(""), cenaBazowa(0.0) {}

Seans::Seans(const Film& film, const Sala& sala, const string& godzina, double cenaBazowa)
    : film(film), sala(sala), godzina(godzina), cenaBazowa(cenaBazowa) {
    if (cenaBazowa < 0)
        throw invalid_argument("Cena nie moze byc ujemna");
}
const Film& Seans::getFilm() const { return film; }
Sala& Seans::getSala() { return sala; }
const Sala& Seans::getSala() const { return sala; }
string Seans::getGodzina() const { return godzina; }
double Seans::getCenaBazowa() const { return cenaBazowa; }
void Seans::setCenaBazowa(double cenaBazowa) {
    if (cenaBazowa < 0)
        throw invalid_argument("Cena nie moze byc ujemna");
    this->cenaBazowa = cenaBazowa;
}
void Seans::setGodzina(const string& godzina) { this->godzina = godzina; }

void Seans::wyswietl() const {
    cout << godzina << " | ";
    film.wyswietl();
    cout << "   sala " << sala.getNumer() << ", cena: " << cenaBazowa
         << " zl, wolnych miejsc: " << sala.liczbaWolnych() << "\n";
}