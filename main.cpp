#include <iostream>
#include <vector>
#include "Film.h"
#include "Sala.h"
#include "Seans.h"
#include "Bilet.h"
#include "BiletNormalny.h"
#include "BiletUlgowy.h"
using namespace std;

int main() {
    Film f("Interstellar", 169, "sci-fi");
    Seans s(f, Sala(1, 5, 8), "18:30", 25.0);

    vector<Bilet*> bilety;

    if (s.getSala().zajmij(2, 3))
        bilety.push_back(new BiletNormalny(s, 2, 3));
    if (s.getSala().zajmij(2, 4))
        bilety.push_back(new BiletUlgowy(s, 2, 4));

    s.wyswietl();
    s.getSala().wyswietl();

    for (const Bilet* b : bilety)
        b->wyswietl();

    for (Bilet* b : bilety)
        delete b;

    return 0;
}