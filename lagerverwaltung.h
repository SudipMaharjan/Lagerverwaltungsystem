#ifndef LAGERVERWALTUNG_H
#define LAGERVERWALTUNG_H
#include <vector>
#include "Warengruppe.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

class Lagerverwaltung
{
    vector<Warengruppe*> waren;
public:
    Lagerverwaltung();
    ~Lagerverwaltung();
    void addWare(Warengruppe* ware);
    void starteMenu();
    void InTxtExportieren();
    void InTxtImportieren();
    void InBinaerExportieren();
    void InBinaerImportieren();
};

template<typename T>
void pruefeEingabe(T& num);
#endif // LAGERVERWALTUNG_H
