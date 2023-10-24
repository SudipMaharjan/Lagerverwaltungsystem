
#include "Elektroartikel.h"



Elektroartikel::Elektroartikel()
    :Warengruppe(),leistung{0}
{}

Elektroartikel::Elektroartikel(string bezeichnung, double preis, int anzahl, int leistung)
    :Warengruppe(bezeichnung,preis,anzahl),leistung{leistung}
{}

Elektroartikel::~Elektroartikel(){

}

int Elektroartikel::getLeistung() const{
    return leistung;
}

void Elektroartikel::print() const{
    Warengruppe::print();
    cout << leistung << setw(28) << " Watt";
}

string Elektroartikel::getExtra()const{
    return to_string(leistung);
}

void Elektroartikel::setType(char type){
    Warengruppe::setType(type);
}
