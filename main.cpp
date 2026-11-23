#include <iostream>
#include <limits>
#include <string>
#include "Kino.h"
using namespace std;

int wczytajInt(const string& komunikat) {
    int x;
    cout << komunikat;
    while (!(cin >> x)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Niepoprawna wartosc, sprobuj ponownie: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return x;
}

double wczytajDouble(const string& komunikat) {
    double x;
    cout << komunikat;
    while (!(cin >> x)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Niepoprawna wartosc, sprobuj ponownie: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return x;
}

string wczytajTekst(const string& komunikat) {
    string s;
    cout << komunikat;
    getline(cin, s);
    return s;
}

bool poprawnyNumer(int nr, int max) {
    return nr >= 1 && nr <= max;
}

void wyswietlMenu() {
    cout << "\n===== SYSTEM SPRZEDAZY BILETOW =====\n";
    cout << "1.  Pokaz filmy\n";
    cout << "2.  Dodaj film\n";
    cout << "3.  Usun film\n";
    cout << "4.  Szukaj filmu\n";
    cout << "5.  Pokaz seanse\n";
    cout << "6.  Dodaj seans\n";
    cout << "7.  Zmien cene seansu\n";
    cout << "8.  Pokaz sale seansu\n";
    cout << "9.  Sprzedaj bilet\n";
    cout << "10. Pokaz sprzedane bilety\n";
    cout << "0.  Wyjscie\n";
}

int main() {
    Kino kino("Kino Studyjne");

    kino.dodajFilm(Film("Interstellar", 169, "sci-fi"));
    kino.dodajFilm(Film("Incepcja", 148, "sci-fi"));
    kino.dodajSeans(Seans(kino.getFilm(0), Sala(1, 5, 8), "18:30", 25.0));
    kino.dodajSeans(Seans(kino.getFilm(1), Sala(2, 4, 6), "20:00", 28.0));

    int wybor;
    do {
        wyswietlMenu();
        wybor = wczytajInt("Wybor: ");

        switch (wybor) {
        case 1:
            kino.wyswietlFilmy();
            break;
        case 2: {
            string tytul = wczytajTekst("Tytul: ");
            int czas = wczytajInt("Czas trwania (min): ");
            string gatunek = wczytajTekst("Gatunek: ");
            kino.dodajFilm(Film(tytul, czas, gatunek));
            cout << "Dodano film\n";
            break;
        }
        case 3: {
            string tytul = wczytajTekst("Tytul filmu do usuniecia: ");
            if (kino.usunFilm(tytul))
                cout << "Usunieto film i jego seanse\n";
            else
                cout << "Nie ma takiego filmu\n";
            break;
        }
        case 4: {
            string tytul = wczytajTekst("Szukany tytul: ");
            int i = kino.szukajFilmu(tytul);
            if (i == -1)
                cout << "Nie ma takiego filmu\n";
            else
                kino.getFilm(i).wyswietl();
            break;
        }
        case 5:
            kino.wyswietlSeanse();
            break;
        case 6: {
            if (kino.liczbaFilmow() == 0) {
                cout << "Najpierw dodaj film\n";
                break;
            }
            kino.wyswietlFilmy();
            int nrFilmu = wczytajInt("Numer filmu: ");
            if (!poprawnyNumer(nrFilmu, kino.liczbaFilmow())) {
                cout << "Niepoprawny numer filmu\n";
                break;
            }
            int numerSali = wczytajInt("Numer sali: ");
            int rzedy = wczytajInt("Liczba rzedow: ");
            int miejsca = wczytajInt("Miejsc w rzedzie: ");
            if (rzedy <= 0 || miejsca <= 0) {
                cout << "Wymiary sali musza byc dodatnie\n";
                break;
            }
            string godzina = wczytajTekst("Godzina (np. 18:30): ");
            double cena = wczytajDouble("Cena bazowa: ");
            kino.dodajSeans(Seans(kino.getFilm(nrFilmu - 1), Sala(numerSali, rzedy, miejsca), godzina, cena));
            cout << "Dodano seans\n";
            break;
        }
        case 7: {
            kino.wyswietlSeanse();
            int nr = wczytajInt("Numer seansu: ");
            if (!poprawnyNumer(nr, kino.liczbaSeansow())) {
                cout << "Niepoprawny numer seansu\n";
                break;
            }
            double cena = wczytajDouble("Nowa cena bazowa: ");
            kino.getSeans(nr - 1).setCenaBazowa(cena);
            cout << "Zmieniono cene\n";
            break;
        }
        case 8: {
            kino.wyswietlSeanse();
            int nr = wczytajInt("Numer seansu: ");
            if (!poprawnyNumer(nr, kino.liczbaSeansow())) {
                cout << "Niepoprawny numer seansu\n";
                break;
            }
            kino.getSeans(nr - 1).getSala().wyswietl();
            break;
        }
        case 9: {
            kino.wyswietlSeanse();
            int nr = wczytajInt("Numer seansu: ");
            if (!poprawnyNumer(nr, kino.liczbaSeansow())) {
                cout << "Niepoprawny numer seansu\n";
                break;
            }
            kino.getSeans(nr - 1).getSala().wyswietl();
            int rzad = wczytajInt("Rzad: ");
            int miejsce = wczytajInt("Miejsce: ");
            int typ = wczytajInt("Typ biletu (1 - normalny, 2 - ulgowy): ");
            if (kino.sprzedajBilet(nr - 1, rzad, miejsce, typ == 2))
                cout << "Sprzedano bilet\n";
            else
                cout << "Nie mozna sprzedac biletu (zle miejsce lub zajete)\n";
            break;
        }
        case 10:
            kino.wyswietlBilety();
            break;
        case 0:
            cout << "Koniec programu\n";
            break;
        default:
            cout << "Nie ma takiej opcji\n";
        }
    } while (wybor != 0);

    return 0;
}