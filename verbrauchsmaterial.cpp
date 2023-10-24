
#include "verbrauchsmaterial.h"

Verbrauchsmaterial::Verbrauchsmaterial()
    :Warengruppe(),haltbarkeitsdatum{nullptr}
{}
Verbrauchsmaterial::Verbrauchsmaterial(string bezeichnung, double preis, int anzahl, Datum * haltbarkeitsdatum)
    :Warengruppe(bezeichnung,preis,anzahl),haltbarkeitsdatum{haltbarkeitsdatum}
{}

Verbrauchsmaterial::~Verbrauchsmaterial(){
    delete haltbarkeitsdatum;
}

void Verbrauchsmaterial::print() const{
    Warengruppe::print();
    haltbarkeitsdatum->print_datum();
}
Datum* Verbrauchsmaterial::getHaltbarkeitsdatum()const{
    return haltbarkeitsdatum;
}

void Verbrauchsmaterial::setType(char type){
    Warengruppe::setType(type);
}

