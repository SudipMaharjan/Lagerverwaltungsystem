
#ifndef VERBRAUCHSMATERIAL_H
#define VERBRAUCHSMATERIAL_H

#include "Warengruppe.h"
#include "datum.h"

class Verbrauchsmaterial:public Warengruppe{
private:
    Datum* haltbarkeitsdatum;

public:
    Verbrauchsmaterial();
    Verbrauchsmaterial(string,double,int,Datum*);
    ~Verbrauchsmaterial();
    void set_haltbarkeitsdatum();
    Datum* getHaltbarkeitsdatum()const;
    void print()const;
    //char getType()const;
    void setType(char type)override;
};

#endif // VERBRAUCHSMATERIAL_H
