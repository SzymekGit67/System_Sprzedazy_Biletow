#ifndef KINO_H
#define KINO_H

#include <string>
#include <vector>
#include "Film.h"
#include "Seans.h"
#include "Bilet.h"
using namespace std;

class Kino {
private:
    string nazwa;
    vector<Film> filmy;
    vector<Seans> seanse;
    vector<Bilet*> bilety;
public:
    Kino(const string& nazwa);
    ~Kino();
    Kino(const Kino&) = delete;
    Kino& operator=(const Kino&) = delete;
    string getNazwa() const;
    bool dodajFilm(const Film& film);
    bool usunFilm(const string& tytul);
    int szukajFilmu(const string& tytul) const;
    const Film& getFilm(int indeks) const;
    int liczbaFilmow() const;
    void wyswietlFilmy() const;
    void dodajSeans(const Seans& seans);
    Seans& getSeans(int indeks);
    int liczbaSeansow() const;
    void wyswietlSeanse() const;

    bool sprzedajBilet(int indeksSeansu, int rzad, int miejsce, bool ulgowy);
    void wyswietlBilety() const;
    double utarg() const;
};

#endif