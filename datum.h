
#ifndef DATUM_H
#define DATUM_H
#include<iostream>
#include<iomanip>

using namespace std;

class Datum
{
private:
    int jahr;
    int monat;
    int tag;

public:
    Datum();
    Datum(int,int,int);
    ~Datum();
    void print_datum()const;
    int getJahr() const;
    int getMonat() const;
    int getTag() const;
    Datum* add_datum();
};

#endif // DATUM_H
