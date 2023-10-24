#include "Lagerverwaltung.h"
#include "Elektroartikel.h"
#include "Verbrauchsmaterial.h"
#include <typeinfo>

using namespace std;

Lagerverwaltung::Lagerverwaltung() {

}
Lagerverwaltung::~Lagerverwaltung(){// Schutz vor memory leak
    for(Warengruppe* w: waren){
        delete w;
    }
}

void Lagerverwaltung::addWare(Warengruppe* ware) {
    this->waren.push_back(ware);
}

void Lagerverwaltung::starteMenu(){
    cout << left;
    int gesamtAnzahl;
    double gesamtPreis;
    bool isMenu = true;
    int menuEingabe;
    string inputString;
    double inputDouble;
    Warengruppe* artikel = nullptr;
    char type{};
    int inputInt;
    while (isMenu) {
        cout << "\n--- myDepot Lagerverwaltung ---\n"
                "(1) Warengruppe einbuchen\n"
                "(2) Warengruppe ausbuchen\n"
                "(3) Artikel entnehmen\n"
                "(4) Artikel auffuellen\n"
                "(5) Preisanpassung durchfuehren\n"
                "(6) Warenbestand nach Nummer ausgeben\n"
                "(7) Warenbestand nach Artikel ausgeben\n"
                "(8) Inventur durchfuehren\n"
                "(9) Lagerbestand exportieren\n"
                "(10) Lagerbestand importieren\n"
                "(0) Programm - Ende\n";

        cin >> menuEingabe;
        pruefeEingabe(menuEingabe);

        switch (menuEingabe) {
        case 1:
            cout << "Warenname?" << endl;// nächstes Mal anstelle cases Funktionen
            cin.ignore(80, '\n');
            getline(cin, inputString, '\n');
            cout << "Preis?" << endl;
            cin >> inputDouble;
            pruefeEingabe(inputDouble);
            cout << "Anzahl?" << endl;
            cin >> inputInt;
            pruefeEingabe(inputInt);
            cout<<"'e' fuer Elektroartikel und 'v' fuer Verbrauchsmaterial eingeben"<<endl;
            cin>>type;
            pruefeEingabe(type);


            while(true){
                if(type == 'v' || type == 'V'){
                    Datum* haltbarkeitsdatum = nullptr;
                    Verbrauchsmaterial* verbrauchsmaterial = new Verbrauchsmaterial(inputString, inputDouble, inputInt, haltbarkeitsdatum->add_datum());
                    verbrauchsmaterial->setType('v');
                    this->addWare(verbrauchsmaterial);
                    delete haltbarkeitsdatum;
                    break;
                }
                else if(type == 'e' || type == 'E'){
                    int leistung{};
                    cout<<"leistung der Ware in Watt eingeben"<<endl;
                    cin>>leistung;
                    pruefeEingabe(leistung);
                    Elektroartikel* elektroartikel = new Elektroartikel(inputString, inputDouble, inputInt,leistung);
                    elektroartikel->setType('e');
                    this->addWare(elektroartikel);
                    break;
                }
                else{
                    cout<<"Ungueltige Eingabe. 'e' fuer Elektroartikel und 'v' fuer Verbrauchsmaterial eingeben"<<endl;
                    cin>>type;
                    pruefeEingabe(type);
                }
            }
            break;

        case 2:
            cout << "Waren ID?" << endl;
            cin >> inputInt;
            pruefeEingabe(inputInt);
            for (unsigned int i = 0; i < waren.size(); i++) {
                if (waren[i]->hasID(inputInt)) {
                    delete waren[i];
                    waren.erase(waren.begin() + i);
                }
            }
            break;

        case 3:
            cout << "Artikel-ID?" << endl;
            cin >> inputInt;
            pruefeEingabe(inputInt);
            artikel = nullptr;
            for (unsigned int i = 0; i < waren.size(); i++) {
                if (waren[i]->hasID(inputInt)) {
                    artikel = waren[i];
                }
            }
            if (artikel == nullptr) {
                cout << "Id nicht vorhanden!" << endl;
                break;
            }
            cout << "Anzahl zu entnehmen?" << endl;
            cin >> inputInt;
            pruefeEingabe(inputInt);
            artikel->setAnzahl(artikel->getAnzahl() - inputInt);
            break;

        case 4:
            cout << "Artikel-ID?" << endl;
            cin >> inputInt;
            pruefeEingabe(inputInt);
            artikel = nullptr;
            for (unsigned int i = 0; i < waren.size(); i++) {
                if (waren[i]->hasID(inputInt)) {
                    artikel = waren[i];
                }
            }
            if (artikel == nullptr) {
                cout << "Id nicht vorhanden!" << endl;
                break;
            }
            cout << "Anzahl zu fuellen?" << endl;
            cin >> inputInt;
            pruefeEingabe(inputInt);
            artikel->setAnzahl(artikel->getAnzahl() + inputInt);
            break;

        case 5:
            cout << "Prozentwert als Ganzzahl angeben" << endl;
            cin >> inputInt;
            pruefeEingabe(inputInt);
            for (Warengruppe* ware : waren) {
                ware->setPreis(ware->getPreis() * (inputInt / 100.0));
            }
            break;

        case 6:
            sort(waren.begin(), waren.end(), compareArtNum);// Zur Klausur selber implementieren
            cout << "--- Lager nach Nummer sortiert ---\n\n";
            cout << setw(25) << "Artikel" << setw(10) << "Nummer" << setw(10) << "Anzahl" <<setw(10) <<  "Preis" <<setw(10)<< "haltbarkeitsdatum/leistung\n";
            cout << setfill('-') << setw(70) << '-' << endl;
            for (Warengruppe* ware : waren) {
                ware->print();
                cout<<endl;
            }
            break;

        case 7:
            sort(waren.begin(), waren.end(), compareBez);
            cout << "--- Lager nach Artikel sortiert ---\n\n";
            cout << setw(25) << "Artikel" << setw(10) << "Nummer" << setw(10) << "Anzahl" <<setw(10) <<  "Preis" << setw(10) << "haltbarkeitsdatum/leistung\n";
            cout << setfill('-') << setw(70) << '-' << endl;
            for (Warengruppe* ware : waren) {
                ware->print();
                cout<<endl;
            }
            break;

        case 8:
            sort(waren.begin(), waren.end(), compareBez);
            cout << "--- Lager ---\n\n";
            cout << setw(25) << "Artikel" << setw(10) << "Nummer" << setw(10) << "Anzahl" << setw(10)
                 << "Preis" << setw(30) << "haltbarkeitsdatum/leistung" << "Gesamt\n";
            cout << setfill('-') << setw(90) << '-' << endl;
            gesamtAnzahl = 0;
            gesamtPreis = 0.0;

            for (Warengruppe* ware : waren) {
                ware->print();
                /*
                cout << setfill(' ') << setw(25) << ware->getBezeichnung() << setw(10)
                     << ware->getID() << setw(10) << ware->getAnzahl() << setw(40)
                     << setprecision(2) << fixed << ware->getPreis() << setw(10) <<*/
                cout << setw(5)<<ware->getAnzahl() * ware->getPreis() << endl;
                gesamtAnzahl += ware->getAnzahl();
                gesamtPreis += ware->getAnzahl() * ware->getPreis();
            }
            cout << setfill('-') << setw(90) << "-" << endl;
            cout << setfill(' ') << setw(35) << "Bestand insgesamt" << setw(50) << gesamtAnzahl << gesamtPreis << endl;
            break;

        case 9:
            cout<<"t fuer Export in txt und b fuer Export in binaer"<<endl;
            cin>>type;
            while(true){
                if(type == 't' || type =='T'){
                    InTxtExportieren();
                    break;
                }
                else if(type == 'b' || type == 'B'){
                    InBinaerExportieren();
                    break;
                }
                else{
                    cout<<"ungultige Eingabe. Erneut eingeben"<<endl;
                }
            }
            break;

        case 10:

            cout<<"t fuer Export in txt und b fuer Import in binaer"<<endl;
            cin>>type;
            while(true){
                if(type == 't' || type =='T'){
                    InTxtImportieren();
                    break;
                }
                else if(type == 'b' || type == 'B'){
                    InBinaerImportieren();
                    break;
                }
                else{
                    cout<<"ungultige Eingabe. Erneut eingeben"<<endl;
                }
            }
            break;

        case 0:
            isMenu = false;
            break;
        default: cout << "Menüpunkt nicht enthalten" << endl;
        }
    }
};

template<typename T>
void pruefeEingabe(T& num) {
    while (cin.fail()) {
        cin.clear();
        cin.ignore(80, '\n');
        cerr << "Bitte nochmal eingeben \n";
        cin >> num;
    }
};

void Lagerverwaltung::InTxtImportieren(){
    string quelldateiName{};
    ifstream quelle;
    if (!waren.size()) {
        cout << "Filenamen angeben\n";
        cin >> quelldateiName;
        quelle.open(quelldateiName, ios::out);
        string data;
        if (quelle.is_open())
        {
            while (quelle.peek()!= EOF) {
                getline(quelle, data);
                stringstream strm(data);
                string bezeichnung,stringPreis,stringAnzahl,stringType;

                getline(strm,stringType,';');

                if(stringType=="Elektroartikel"){
                    getline(strm,bezeichnung,';');
                    getline(strm,stringPreis,';');
                    getline(strm,stringAnzahl,';');

                    double preis = stod(stringPreis);
                    int anzahl = stoi(stringAnzahl);

                    string stringLeistung;
                    getline(strm,stringLeistung,';');
                    int leistung = stoi(stringLeistung);
                    Elektroartikel* e = new Elektroartikel(bezeichnung,preis,anzahl,leistung);
                    e->setType('e');
                    addWare(e);
                }
                else if(stringType=="Verbrauchswaren"){
                    getline(strm,bezeichnung,';');
                    getline(strm,stringPreis,';');
                    getline(strm,stringAnzahl,';');

                    double preis = stod(stringPreis);
                    int anzahl = stoi(stringAnzahl);

                    string stringJahr,stringMonat,stringTag;
                    getline(strm,stringJahr,'.');
                    getline(strm,stringMonat, '.');
                    getline(strm,stringTag,'.');
                    int jahr= stoi(stringJahr);
                    int monat= stoi(stringMonat);
                    int tag= stoi(stringTag);

                    Datum* datum = new Datum(jahr,monat,tag);
                    Verbrauchsmaterial* v = new Verbrauchsmaterial(bezeichnung,preis,anzahl,datum);
                    v->setType('v');
                    addWare(v);
                }

            }
        }
        else{
            cerr<<"Datei kann nicht geoeffnet werden"<<endl;
        }
    }
    else{
        cout<<"Waren schon vorhanden"<<endl;
    }
}

void Lagerverwaltung::InTxtExportieren(){
    string inputString{};
    ofstream outStream;
    cout << "Filenamen angeben\n";
    cin >> inputString;
    outStream.open(inputString);
    if (outStream.is_open())
    {
        for (Warengruppe* w : waren) {
            if(w->getType()=='e')
            {              
                outStream << "Elektroartikel"<<';';               
                outStream << w->getBezeichnung()<<';';
                outStream << w->getPreis()<<';';
                outStream << w->getAnzahl()<<';';
                outStream<< dynamic_cast<Elektroartikel*>(w)->getLeistung();
            }
            else if(w->getType()=='v'){
                outStream << "Verbrauchswaren"<<';';
                outStream << w->getBezeichnung()<<';';
                outStream << w->getPreis()<<';';
                outStream << w->getAnzahl()<<';';

                outStream << dynamic_cast<Verbrauchsmaterial*>(w)->getHaltbarkeitsdatum()->getJahr()<<'.';
                outStream << dynamic_cast<Verbrauchsmaterial*>(w)->getHaltbarkeitsdatum()->getMonat()<<'.';
                outStream << dynamic_cast<Verbrauchsmaterial*>(w)->getHaltbarkeitsdatum()->getTag()<<'.';
            }
            else{
                cout<<"Ungueltige Typ"<<endl;
            }            
        }
        cout << "File erstellt" << endl;
        outStream.close();
    }
    else{
        cout << "File kann nicht geöffnet werden" << endl;
    }
}

void Lagerverwaltung::InBinaerImportieren(){
    string fileName,temp_name;
    cout<<"FileName?"<<endl;
    cin>>fileName;
    char terminator = '\0';
    double temp_preis = 0;
    int temp_anzahl = 0;
    string temp_bez;
    string temp_typ;
    int LagerSize = 0;
    int stringSize = 0;
    char bez[160]{};
    char typ[160]{};

    ifstream inStream(fileName,ios::binary | ios::in);
    if(inStream.is_open()){
        inStream.read((char*)(&temp_anzahl),sizeof(temp_anzahl));
        LagerSize = temp_anzahl;
        for(int i{};i<LagerSize;i++){
            inStream.read((char*)(&stringSize),sizeof(stringSize));
            temp_typ.resize(stringSize);
            inStream.read((char*)typ,stringSize);
            inStream.read((char*)&terminator,1);
            stringSize = 0;

            string type(typ);   //char in string umgewandelt (string konstruktur)
            if(type == "Elektroartikel"){
                int temp_leistung{};
                inStream.read((char*)(&stringSize),sizeof(stringSize));
                temp_bez.resize(stringSize);
                inStream.read((char*)bez,stringSize);
                inStream.read((char*)&terminator,1);

                inStream.read((char*)(&temp_preis),sizeof(temp_preis));
                inStream.read((char*)(&temp_anzahl),sizeof(temp_anzahl));

                inStream.read((char*)(&temp_leistung),sizeof(temp_leistung));

                Elektroartikel* elektroartikel = new Elektroartikel(bez,temp_preis,temp_anzahl,temp_leistung);
                elektroartikel->setType('e');
                addWare(elektroartikel);
            }
            else if(type == "Verbrauchswaren"){
                int temp_jahr{},temp_monat{},temp_tag{};
                inStream.read((char*)(&stringSize),sizeof(stringSize));
                temp_bez.resize(stringSize);
                inStream.read((char*)bez,stringSize);
                inStream.read((char*)&terminator,1);

                inStream.read((char*)(&temp_preis),sizeof(temp_preis));
                inStream.read((char*)(&temp_anzahl),sizeof(temp_anzahl));

                //inStream.read((char*)(&temp_Date),sizeof(temp_Date));
                inStream.read((char*)(&temp_jahr),sizeof(temp_jahr));
                inStream.read((char*)(&temp_monat),sizeof(temp_monat));
                inStream.read((char*)(&temp_tag),sizeof(temp_tag));

                Datum* temp_Date = new Datum(temp_jahr,temp_monat,temp_tag);

                Verbrauchsmaterial* verbrauchswaren = new Verbrauchsmaterial(bez,temp_preis,temp_anzahl,temp_Date);
                verbrauchswaren->setType('v');
                addWare(verbrauchswaren);
            }
        }
    }
}
void Lagerverwaltung::InBinaerExportieren(){
    ofstream outStream;
    string dateiName,bez;
    char terminator = '\0';
    int anz;
    double pre;
    int lagerSize=waren.size();
    cout<<"Dateiname eingeben"<<endl;
    cin>>dateiName;

    outStream.open(dateiName.c_str(),ios::out |ios::binary);
    if(!outStream){
        cerr<<dateiName <<" kann nicht geoeffnet werden"<<endl;
        exit(-1);
    }

    outStream.write((char*)(&lagerSize),sizeof(lagerSize));
    for(int i{};i<lagerSize;i++){
        if(waren[i]->getType()=='e'){
            string type = "Elektroartikel";
            unsigned int typeSize = type.length()+1;
            outStream.write((char*)(&typeSize),sizeof(typeSize));
            outStream.write(type.c_str(),typeSize);
            outStream.write((&terminator),1);

            bez=waren[i]->getBezeichnung();
            unsigned int bezSize = bez.length()+1;
            outStream.write((char*)(&bezSize),sizeof(bezSize));
            outStream.write(bez.c_str(),bezSize);
            outStream.write((&terminator),1);

            pre= waren[i]->getPreis();
            outStream.write((char*)(&pre),sizeof(pre));

            anz = waren[i]->getAnzahl();
            outStream.write((char*)(&anz),sizeof(anz));

            int leist = dynamic_cast<Elektroartikel*>(waren[i])->getLeistung();
            outStream.write((char*)(&leist),sizeof(leist));
        }
        else if(waren[i]->getType()=='v'){
            string type = "Verbrauchswaren";
            unsigned int typeSize = type.length()+1;
            outStream.write((char*)(&typeSize),sizeof(typeSize));
            outStream.write(type.c_str(),typeSize);
            outStream.write((&terminator),1);

            bez=waren[i]->getBezeichnung();
            unsigned int bezSize = bez.length()+1;
            outStream.write((char*)(&bezSize),sizeof(bezSize));
            outStream.write(bez.c_str(),bezSize);
            outStream.write((&terminator),1);

            pre= waren[i]->getPreis();
            outStream.write((char*)(&pre),sizeof(pre));

            anz = waren[i]->getAnzahl();
            outStream.write((char*)(&anz),sizeof(anz));


            int year = dynamic_cast<Verbrauchsmaterial*>(waren[i])->getHaltbarkeitsdatum()->getJahr();
            outStream.write((char*)(&year),sizeof(year));

            int month = dynamic_cast<Verbrauchsmaterial*>(waren[i])->getHaltbarkeitsdatum()->getMonat();
            outStream.write((char*)(&month),sizeof(month));

            int day = dynamic_cast<Verbrauchsmaterial*>(waren[i])->getHaltbarkeitsdatum()->getTag();
            outStream.write((char*)(&day),sizeof(day));
        }
        else{
            cout<<"ungueltige Typ"<<endl;
        }
    }
}

