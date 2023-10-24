
#ifndef ELEKTROARTIKEL_H
#define ELEKTROARTIKEL_H

#include "Warengruppe.h"

class Elektroartikel:public Warengruppe{
private:
    int leistung;

public:
    Elektroartikel();
    Elektroartikel(string,double,int,int);
   ~Elektroartikel();
    void print() const;
   int getLeistung()const;
   // char getType()const;
   string getExtra()const;
    void setType(char type)override;

};

#endif // ELEKTROARTIKEL_H
