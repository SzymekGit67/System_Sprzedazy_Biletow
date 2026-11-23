#include <iostream>
#include "Kino.h"
using namespace std;

int main() {
    Kino kino("Kino Studyjne");

    kino.dodajFilm(Film("Interstellar", 169, "sci-fi"));
    kino.dodajFilm(Film("Incepcja", 148, "sci-fi"));

    kino.dodajSeans(Seans(kino.getFilm(0), Sala(1, 5, 8), "18:30", 25.0));
    kino.dodajSeans(Seans(kino.getFilm(1), Sala(2, 4, 6), "20:00", 28.0));

    kino.sprzedajBilet(0, 2, 3, false);
    kino.sprzedajBilet(0, 2, 4, true);
    if (!kino.sprzedajBilet(0, 2, 4, true))
        cout << "Miejsce zajete\n";

    kino.wyswietlFilmy();
    kino.wyswietlSeanse();
    kino.wyswietlBilety();

    return 0;
}