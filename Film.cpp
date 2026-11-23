#include "Film.h"
#include <iostream>
using namespace std;

Film::Film():tytul(""), czasTrwania(0),gatunek(""){}
Film::Film(const string& tytul, int czasTrwania, const string& gatunek): tytul(tytul), czasTrwania(czasTrwania), gatunek(gatunek){}
string Film::getTytul() const {return tytul;}
int Film::getCzasTrwania() const {return czasTrwania;}
string Film::getGatunek() const {return gatunek;}
void Film::setTytul(const string& tytul) {this->tytul = tytul;}
void Film::setCzasTrwania(int czasTrwania) {this->czasTrwania = czasTrwania;}
void Film::setGatunek(const string& gatunek) {this->gatunek = gatunek;}
void Film::wyswietl() const {
    cout << tytul << " (" << gatunek << ", " << czasTrwania << " min)"<<endl;
}
bool Film::operator==(const Film& inny) const {
    return tytul == inny.tytul && czasTrwania == inny.czasTrwania && gatunek == inny.gatunek;
}
