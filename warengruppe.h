#ifndef WARENGRUPPE_H
#define WARENGRUPPE_H
#include <string>
#include <iostream>
#include<iomanip>
using namespace std;

class Warengruppe
{
    static int artID;
    const int artikelnummer;
    double preis;
    int anzahl;
    string bezeichnung;
    char type;

public:
    Warengruppe();
    Warengruppe(string bezeichnung,double preis,int anzahl);
    Warengruppe(int artikelnummer, string bezeichnung, double preis, int anzahl);
    virtual ~Warengruppe();
    virtual void print()const;
    bool hasID(int id);
    void setArtID(int id);
    void setAnzahl(int anz);
    int getAnzahl() const;
    void setPreis(double preis);
    virtual void setType(char type);
    virtual char getType()const;
    double getPreis()const;
    int getID()const;
    string getBezeichnung()const;
    virtual string getExtra()const;
};


bool compareArtNum(Warengruppe* a, Warengruppe* b);
bool compareBez(Warengruppe* a, Warengruppe* b);

#endif // WARENGRUPPE_H
