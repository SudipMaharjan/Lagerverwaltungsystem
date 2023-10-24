
#include "datum.h"

Datum::Datum()
    :jahr{0},monat{0},tag{0}
{}

Datum::Datum(int jahr,int monat,int tag)
    :jahr{jahr},monat{monat},tag{tag}
{}
Datum::~Datum(){

}
void Datum::print_datum()const{
    cout<<jahr<<'.'<<monat<<'.'<< setw(23) <<tag;
}

Datum* Datum::add_datum(){
    int jahr{},monat{},tag{};
    cout<<"haltbarkeitsjahr eingeben"<<endl;
    cin>>jahr;
    while(cin.fail() || jahr<2023){
        cout<<"Ungueltiges Jahr"<<endl;
        cin>>jahr;
    }

    cout<<"haltbarkeitsmonat eingeben"<<endl;
    cin>>monat;
    while(cin.fail() || monat<0 || monat>12){
        cout<<"Ungueltige Monat"<<endl;
        cin>>monat;
    }

    cout<<"haltbarkeitstag eingaben"<<endl;
    cin>>tag;
    while(cin.fail() || (monat==2 && tag>28) || ((monat==1 || monat==3 || monat==5|| monat==7|| monat==8|| monat==10|| monat==12) && tag>31)||((monat==4||monat==6||monat==9||monat==11) && tag>30)){
        cout<<"Ungueltige Tag. Erneut eingeben"<<endl;
        cin>>tag;
    }
    return (new Datum(jahr,monat,tag));
}

int Datum::getJahr() const{
    return jahr;
}
int Datum::getMonat() const{
    return monat;
}
int Datum::getTag() const{
    return tag;
}
