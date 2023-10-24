#include "Warengruppe.h"
#include <iostream>
#include <iomanip>
using namespace std;

int Warengruppe::artID = 100000;
Warengruppe::Warengruppe()
    :artikelnummer(artID++), preis(0.0), anzahl(0), bezeichnung("name") {
}

Warengruppe::Warengruppe(string bezeichnung, double preis, int anzahl)
    :artikelnummer(artID++), preis(preis), anzahl(anzahl), bezeichnung(bezeichnung) {
}

Warengruppe::Warengruppe(int artikelnummer, string bezeichnung, double preis, int anzahl)
    :artikelnummer(artikelnummer), preis(preis), anzahl(anzahl), bezeichnung(bezeichnung) {
    artID = artikelnummer >= artID ? artikelnummer+1 : artID;
}

Warengruppe::~Warengruppe(){

}

void Warengruppe::print () const {
    cout << setfill(' ') << setw(25) << bezeichnung << setw(10)
         << artikelnummer << setw(10) << anzahl << setw(10) << setprecision(2) << fixed <<preis;
}

bool Warengruppe::hasID(int id) {
    return id == artikelnummer;
}

void Warengruppe::setArtID(int id) {
    Warengruppe::artID = id;
}
void Warengruppe::setAnzahl(int anz) {
    anzahl = anz>0? anz:0;
}
int Warengruppe::getAnzahl() const {
    return anzahl;
}
void Warengruppe::setPreis(double preis) {
    this->preis = preis > 0 ?preis : 0;
}
double Warengruppe::getPreis() const {
    return preis;
}

int Warengruppe::getID() const {
    return artikelnummer;
}
string Warengruppe::getBezeichnung() const {
    return bezeichnung;
}
void Warengruppe::setType(char type){
    this->type=type;
}
char Warengruppe::getType()const{
    return type;
}
string Warengruppe::getExtra()const{
    return "warengruppe";
}

bool compareArtNum(Warengruppe* a, Warengruppe* b)
{
    return a->getID() < b->getID();
}

bool compareBez(Warengruppe* a, Warengruppe* b)
{
    return a->getBezeichnung() < b->getBezeichnung();
}
