#include "Kino.h"
#include "BiletNormalny.h"
#include "BiletUlgowy.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Kino::Kino(const string& nazwa) : nazwa(nazwa) {}

Kino::~Kino() {
    for (Bilet* b : bilety)
        delete b;
}
string Kino::getNazwa() const { return nazwa; }
bool Kino::dodajFilm(const Film& film) {
    for (const Film& f : filmy)
        if (f == film)
            return false;
    filmy.push_back(film);
    return true;
}
bool Kino::usunFilm(const string& tytul) {
    int i = szukajFilmu(tytul);
    if (i == -1)
        return false;
    filmy.erase(filmy.begin() + i);
    for (int j = (int)seanse.size() - 1; j >= 0; j--)
        if (seanse[j].getFilm().getTytul() == tytul)
            seanse.erase(seanse.begin() + j);
    return true;
}
int Kino::szukajFilmu(const string& tytul) const {
    for (int i = 0; i<(int)filmy.size(); i++)
        if (filmy[i].getTytul() == tytul)
            return i;
    return -1;
}

const Film& Kino::getFilm(int indeks) const {
    if (indeks < 0 || indeks >= (int)filmy.size())
        throw out_of_range("Nie ma filmu o takim numerze");
    return filmy[indeks];
}

int Kino::liczbaFilmow() const { return filmy.size(); }

void Kino::wyswietlFilmy() const {
    if (filmy.empty()) {
        cout << "Brak filmow\n";
        return;
    }
    for (int i = 0; i < (int)filmy.size(); i++) {
        cout << i + 1 << ". ";
        filmy[i].wyswietl();
    }
}

void Kino::dodajSeans(const Seans&seans) {
    seanse.push_back(seans);
}
Seans& Kino::getSeans(int indeks) {
    if (indeks < 0 || indeks >= (int)seanse.size())
        throw out_of_range("Nie ma seansu o takim numerze");
    return seanse[indeks];
}

int Kino::liczbaSeansow() const { return seanse.size(); }

void Kino::wyswietlSeanse() const {
    if (seanse.empty()) {
        cout << "Brak seansow\n";
        return;
    }
    for (int i = 0; i < (int)seanse.size(); i++) {
        cout << i + 1 << ". ";
        seanse[i].wyswietl();
    }
}

void Kino::sprzedajBilet(int indeksSeansu, int rzad, int miejsce, bool ulgowy) {
    Seans& s = getSeans(indeksSeansu);
    s.getSala().zajmij(rzad, miejsce);
    if (ulgowy)
        bilety.push_back(new BiletUlgowy(s, rzad, miejsce));
    else
        bilety.push_back(new BiletNormalny(s, rzad, miejsce));
}

void Kino::wyswietlBilety() const {
    if (bilety.empty()) {
        cout << "Nie sprzedano jeszcze zadnych biletow\n";
        return;
    }
    for (int i = 0; i < (int)bilety.size(); i++) {
        cout << i + 1 << ". ";
        cout << *bilety[i] << "\n";
    }
    cout << "Utarg: " << utarg() << " zl\n";
}

double Kino::utarg() const {
    double suma = 0;
    for (const Bilet* b : bilety)
        suma += b->cena();
    return suma;
}