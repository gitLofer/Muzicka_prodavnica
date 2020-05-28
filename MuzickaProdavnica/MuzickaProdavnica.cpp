#include<iostream>
#include<fstream>
#include<cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include<cctype>
#include<iomanip>
#include <string>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;

using namespace std;

enum proizvodjaci {fender, gibson, ibanez, taylor, yamaha};
enum zicaVrsta {nikl, celik, najlon};
enum gitaraVrsta {klasicnaGitara, akusticnaGitara, elektroAkusticnaGitara, elektricnaGitara, basGitara};
enum ukuleleVrsta {standard, koncert, tenor, bariton};
enum harfaVrsta {pedala, poluga};
enum bubanjVrsta {kongo, bongo, djambe, tabla, timpani, pahu};
enum cineleVrsta {orchestral, crash, hiHats, suspended, splash, ancient};
enum drvoVrsta {jasen, javor, mahagoni};
enum trubaVrsta {visokaTruba, altTruba, basTruba};
enum duvackiVrsta {limeni, drveni};
enum trombonVrsta {altTrombon, tenorTrombon, basTrombon, tenorBasTrombon};
enum hornaVrsta {jednostruka, dvostruka, odvojivoZvono};
enum tubaVrsta {kontrabasTuba, basTuba, tenorTuba, subKontrabasTuba};
enum klarinetVrsta {klarinetA, klarinetBb, harmonijskiKlarinet};
enum oboaVrsta {baroknaOboa, klasicnaOboa, beckaOboa, modernaOboa};
enum saksofonVrsta {sopranSaksofon, altSaksofon, tenorSaksofon, baritonSaksofon};
enum flautaVrsta {standardna, pikolo, harmonijska};
enum klavirVrsta {elektricni, pianino, koncertni, polukoncertni};
enum violinaVrsta {klasicnaViolina, baroknaViolina, strohViolina, elektricnaViolina, poluelektricnaViolina};
enum violaVrsta {akusticnaViola, elektricnaViola, elektricnoAkusticnaViola};
enum violonceloVrsta {carbonFiberVioloncelo, fullSizeVioloncelo, akusticnoVioloncelo, raznaVioloncela, elektricnoVioloncelo};
enum kontrabasVrsta {dupliBas, violona, oktobas, dalaruan, dadihu};
enum mikserVrsta {saEfektima, bezEfekata, power, digitalni};
enum zvucnaKutijaVrsta {aktivna, pasivna, subwoofer};
enum pojacalaVrsta {tube, solidState, modelling, hybrid};
enum procesoriVrsta {dinamickiProcesor, ekvilajzer};
enum mikrofonVrsta {zicani, bezicni, studijski};
enum zvucnaKarticaVrsta {usb, firewire, thunderbolt};
enum razglasniSistemiVrsta {profesionalni, kompaktni};
enum miksetaVrsta {analogna, digitalna};
enum kontrolerVrsta {recording, keyboard, pad, monitor};
enum harmonikaVrsta {obicna, usnena};
enum instrumentOpremaVrsta {stalak, lampa, stolica, metronom, stimer, zvucnaViljuska, kapodaster};
enum udarackiVisinaTona {odredjena, neodredjena};
enum djOpremaVrsta {djKontroler, djMikseta, djSlusalice, djInterface, djPaket};
enum zaUcenjeVrsta {knjiga, disk, notnaSveska};
enum izvodjacVrsta {solo, grupa};
enum tipMuzike {vokalna, instrumentalna, vokalnoInstrumentalna};
enum zanrovi {alternative, bluz, rege, pop, rok, hiphop, dzez, dens, klasicna, kantri, metal};
enum tipGudala {NEMACKI, FRANCUSKI};
enum tonalitet {C, Csharp, D, Dsharp, E, F, Fsharp, G, Gsharp, A, Asharp, B};
enum lestvica {mol, dur};

template <class T>
class Lista
{
private:
    struct listEl
    {
        T content;
        struct listEl* next;
    };
    listEl* head;
    listEl* tail;
    int noEl;

public:
    Lista()
    {
        head = tail = NULL;
        noEl = 0;
    }

    Lista(const Lista<T>&);

    Lista<T>& operator=(const Lista<T>&);

    virtual ~Lista();

    int velicina() const
    {
        return noEl;
    }

    bool prazno() const
    {
        return head == NULL ? 1 : 0;
    }

    bool dodajElement(int, const T&);

    bool izbrisiElement(int);

    bool izlistaj(int, T&)const;

    void izbrisi();
};


template <class T>
ostream& operator<<(ostream& out, const Lista<T>& rl)
{
    out << endl;
    out << "--------" << endl;
    for (int i = 1; i <= rl.velicina(); i++)
    {
        if (i != 1)
            out << ", ";
        T res;
        rl.izlistaj(i, res);
        out << res;
    }
    out << endl << "--------" << endl;
    return out;
}

template <class T>
Lista<T>::Lista(const Lista<T>& rl)
{
    head = NULL;
    tail = NULL;
    noEl = 0;

    for (int i = 1; i <= rl.noEl; i++)
    {
        T res;
        if (rl.izlistaj(i, res))
            dodajElement(i, res);
    }
}

template <class T>
Lista<T>& Lista<T>::operator=(const Lista<T>& rl)
{
    if (this != &rl)
    {
        izbrisi();
        head = NULL;
        tail = NULL;
        noEl = 0;

        for (int i = 1; i <= rl.noEl; i++)
        {
            T res;
            if (rl.izlistaj(i, res))
                dodajElement(i, res);
        }
    }
    return *this;
}

template <class T>
Lista<T>::~Lista()
{
    while (!prazno())
        izbrisiElement(1);
}

template <class T>
bool Lista<T>::dodajElement(int n, const T& newContent)
{
    if (n < 1 || n > noEl + 1)
        return false;
    else
    {
        listEl* newEl = new listEl;
        if (newEl == NULL)
            return false;
        else
        {
            newEl->content = newContent;
            if (n == 1)
            {
                newEl->next = head;
                head = newEl;
            }
            else if (n == noEl + 1)
            {
                newEl->next = NULL;
                tail->next = newEl;
            }
            else
            {
                listEl* temp = head;
                for (int i = 2; i < n; i++)
                    temp = temp->next;
                newEl->next = temp->next;
                temp->next = newEl;
            }
            noEl++;
            if (newEl->next == NULL)
                tail = newEl;
            return true;
        }
    }
}

template <class T>
bool Lista<T>::izbrisiElement(int n)
{
    if (n < 1 || n > noEl)
        return false;
    else
    {
        if (n == 1)
        {
            listEl* del = head;
            head = head->next;
            if (tail == del)
                tail = NULL;
            delete del;
            noEl--;
        }
        else
        {
            listEl* temp = head;
            for (int i = 2; i < n; i++)
                temp = temp->next;
            listEl* del = temp->next;
            temp->next = del->next;
            if (tail == del)
                tail = temp;
            delete del;
            noEl--;
        }
        return true;
    }
}

template <class T>
bool Lista<T>::izlistaj(int n, T& retVal) const
{
    if (n < 1 || n > noEl)
        return false;
    else
    {
        if (n == 1)
            retVal = head->content;
        else if (n == noEl)
            retVal = tail->content;
        else
        {
            listEl* temp = head;
            for (int i = 1; i < n; i++)
                temp = temp->next;
            retVal = temp->content;
        }
        return true;
    }
}

template <class T>
void Lista<T>::izbrisi()
{
    while (!prazno())
        izbrisiElement(1);
}




class Osoba
{
protected:
    string ime, prezime;
    int godine;

public:
    Osoba()
    {
        ime = "Nije uneto";
        prezime = "Nije uneto";
        godine = 0;
    }

    Osoba(string IME, string PREZIME, int GODINE)
    {
        ime = IME;
        prezime = PREZIME;
        godine = GODINE;
    }

    Osoba(const Osoba &o)
    {
        ime = o.ime;
        prezime = o.prezime;
        godine = o.godine;
    }

    string getIme()const
    {
        return ime;
    }
    string getPrezime()const
    {
        return prezime;
    }
    int getGodine()const
    {
        return godine;
    }

    void setIme(string IME)
    {
        ime = IME;
    }
    void setPrezime(string PREZIME)
    {
        prezime = PREZIME;
    }
    void setGodine(int GODINE)
    {
        godine = GODINE;
    }


    void ispisiOsobu()
    {
        cout<<"Ime: "<<getIme()<<endl;
        cout<<"Prezime: "<<getPrezime()<<endl;
        cout<<"Godine: "<<getGodine()<<endl;
    }

    void unesiOsobu()
    {
        cout<<"Ime: ";
        cin>>ime;
        fflush(stdin);
        cout<<"Prezime: ";
        cin>>prezime;
        fflush(stdin);
        cout<<"Godine: ";
        cin>>godine;
        fflush(stdin);
    }

};

class Proizvod
{
protected:
    char naziv[20];
    float cena;
    float ocena;
    proizvodjaci proizvodjac;
public:
    Proizvod()
    {
        cena = 4500.00;
        ocena = 10.00;
        proizvodjac = ibanez;
    }
    Proizvod( float c, float o,proizvodjaci p)
    {
        cena = c;
        ocena = o;
        proizvodjac = p;
    }
    Proizvod(const Proizvod &p)
    {
        cena = p.cena;
        ocena = p.ocena;
        proizvodjac = p.proizvodjac;
    }


    void setCena(float ce)
    {
        cena = ce;
    }
    void setOcena(float oc)
    {
        ocena = oc;
    }
    void setProizvodjac(proizvodjaci pro)
    {
        proizvodjac = pro;
    }

    const char* getNaziv()const
    {
        return naziv;
    }
    float getCena()const
    {
        return cena;
    }
    float getOcena()const
    {
        return ocena;
    }
    string getProizvodjac()const
    {
        switch(proizvodjac)
        {
        case fender:
            return "FENDER";
            break;
        case gibson:
            return "GIBSON";
            break;
        case ibanez:
            return "IBANEZ";
            break;
        case taylor:
            return "TAYLOR";
            break;
        case yamaha:
            return "YAMAHA";
            break;
        default:
            return "Nema proizvodjaca";
            break;
        }
    }

    void ispisProizvoda()
    {
        cout<<"Naziv proizvoda: "<<getNaziv()<<endl;
        cout<<"Cena proizvoda: "<<getCena()<<endl;
        cout<<"Ocena proizvoda: "<<getOcena()<<endl;
        cout<<"Proizvodjac: "<<getProizvodjac()<<endl;
    }

    void unosProizvoda()
    {
        int br;
        cout<<"Naziv: ";
        cin>>naziv;
        fflush(stdin);
        cout<<"Cena: ";
        cin>>cena;
        fflush(stdin);
        cout<<"Ocena: ";
        cin>>ocena;
        fflush(stdin);
        cout<<"Proizvodjac[1-Fender/2-Gibson/3-Ibanez/4-Taylor/5-Yamaha]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            proizvodjac = fender;
            break;
        case 2:
            proizvodjac = gibson;
            break;
        case 3:
            proizvodjac = ibanez;
            break;
        case 4:
            proizvodjac = taylor;
            break;
        case 5:
            proizvodjac = yamaha;
            break;
        }
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////
class Pojacala : public Proizvod
{
private:
    pojacalaVrsta vrsta;
public:
    int pojacaloID;

    Pojacala() : Proizvod()
    {
        pojacaloID = 0;
        vrsta = hybrid;
    }
    Pojacala( int id, pojacalaVrsta v, float c, float o, proizvodjaci pp) : Proizvod(c,o,pp)
    {
        pojacaloID = id;
        vrsta = v;
    }

    Pojacala(const Pojacala &p)
    {
        pojacaloID = p.pojacaloID;
        cena = p.cena;
        ocena = p.ocena;
        proizvodjac = p.proizvodjac;
        vrsta = p.vrsta;
    }

    void setVrsta(pojacalaVrsta VRSTA)
    {
        vrsta = VRSTA;
    }
    void setPojacaloID(int id)
    {
        pojacaloID = id;
    }

    string getVrsta()
    {
        switch(vrsta)
        {
        case tube:
            return "Tube";
            break;
        case solidState:
            return "Solid state";
            break;
        case modelling:
            return "Modelling";
            break;
        case hybrid:
            return "Hybrid";
            break;
        }
    }
    int getPojacaloID()const;

    void ispisiPojacala()
    {
        cout<<"ID: "<<getPojacaloID()<<endl;
        ispisProizvoda();
        cout<<"Vrsta: "<<getVrsta()<<endl;
    }

    void unesiPojacala()
    {
        int br;
        cout<<"ID: ";
        cin>>pojacaloID;
        unosProizvoda();
        cout<<"Vrsta[1-Tube/2-Solid state/3-Modelling/4-Hybrid]: ";
        cin>>br;
        switch(br)
        {
        case 1:
            vrsta = tube;
            break;
        case 2:
            vrsta = solidState;
            break;
        case 3:
            vrsta = modelling;
            break;
        case 4:
            vrsta = hybrid;
            break;
        }
    }

};

int Pojacala::getPojacaloID()const
{
    return pojacaloID;
}

void dodajUFajlPojacalo()
{
    Pojacala p;
    ofstream outFile;
    outFile.open("POJACALO.dat",ios::binary|ios::app);
    p.unesiPojacala();
    outFile.write(reinterpret_cast<char *> (&p), sizeof(Pojacala));
    outFile.close();
    cout<<"\n\nPojacalo upisano u fajl! ";
    cin.ignore();
    cin.get();
}
void ispisiFajlPojacalo()
{
    Pojacala p;
    ifstream inFile;
    inFile.open("POJACALO.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVA POJACALA U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&p), sizeof(Pojacala)))
    {
        p.ispisiPojacala();
        cout<<"\n\n*************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluPojacalo(int n)
{
    Pojacala p;
    ifstream inFile;
    inFile.open("POJACALO.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&p), sizeof(Pojacala)))
    {
        if(p.getPojacaloID()==n)
        {
            p.ispisiPojacala();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nPojacalo ne postoji!";
    cin.ignore();
    cin.get();
}
void obrisiUFajluPojacalo(int n)
{
    Pojacala p;
    ifstream inFile;
    inFile.open("POJACALO.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempPojacalo.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&p), sizeof(Pojacala)))
    {
        if(p.getPojacaloID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&p), sizeof(Pojacala));
        }
    }
    outFile.close();
    inFile.close();
    remove("POJACALO.dat");
    rename("TempPojacalo.dat","POJACALO.dat");
    cout<<"\n\n\tPojacalo orbisano!";
    cin.ignore();
    cin.get();
}
///////////////////////////////////////////////////////////////////////////////////////////////
class Instrument : public Proizvod
{
protected:
    char boja[20];
    char timbre[20];
public:
    Instrument()
    {
        cena = 15000.00;
        ocena = 9.7;
        proizvodjac = gibson;
    }
    Instrument(float c, float o, proizvodjaci pp)
    {

        cena = c;
        ocena = o;
        proizvodjac = pp;
    }
    Instrument(const Instrument &i)
    {

        cena = i.cena;
        ocena = i.ocena;
        proizvodjac = i.proizvodjac;
    }

    const char* getBoja()const
    {
        return boja;
    }
    const char* getTimbre()const
    {
        return timbre;
    }

    void ispisInstrumenta()
    {
        ispisProizvoda();
        cout<<"Boja: "<<getBoja()<<endl;
        cout<<"Timbre: "<<getTimbre()<<endl;
    }

    void unosInstrumenta()
    {
        unosProizvoda();
        cout<<"Boja: ";
        cin>>boja;
        fflush(stdin);
        cout<<"Timbre:";
        cin>>timbre;
        fflush(stdin);
    }
};
///////////////////////////////////////////////////////////////////////////////////////
class DuvackiInstrument: public Instrument
{
protected:
    duvackiVrsta vrsta;
public:
    DuvackiInstrument()
    {
        cena=1000.00;
        ocena=9.34;
        proizvodjac=yamaha;
        vrsta=drveni;
    }

    DuvackiInstrument( float c, float o, proizvodjaci p, duvackiVrsta v)
    {
        cena=c;
        ocena=o;
        proizvodjac=p;
        vrsta=v;
    }

    DuvackiInstrument(const DuvackiInstrument &di)
    {
        cena=di.cena;
        ocena=di.ocena;
        proizvodjac=di.proizvodjac;
        vrsta=di.vrsta;
    }

    string getVrsta()const
    {
        switch(vrsta)
        {
        case limeni:
            return "Limeni";
            break;
        case drveni:
            return "Drveni";
            break;
        }
    }
    void setVrsta(duvackiVrsta v)
    {
        vrsta=v;
    }

    void ispisDuvackogInstrumenta()
    {
        ispisInstrumenta();
        cout<<"Vrsta :"<<getVrsta()<<endl;
    }

    void unosDuvackogInstrumenta()
    {
        int br;
        unosInstrumenta();
        cout<<"Vrsta duvackog[1-Limeni/2-Drveni]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrsta = limeni;
            break;
        case 2:
            vrsta = drveni;
            break;
        }

    }
};
//////////////////////////////////////////////////////////////////////////////////////////
class UdarackiInstrument : public Instrument
{
protected:
    udarackiVisinaTona ton;
public:
    UdarackiInstrument()
    {
        cena = 5000.00;
        ocena = 10.0;
        proizvodjac = yamaha;
        ton = neodredjena;
    }
    UdarackiInstrument(float cc, float oo, proizvodjaci pp, udarackiVisinaTona visina)
    {
        cena = cc;
        ocena = oo;
        proizvodjac = pp;
        ton = visina;
    }
    UdarackiInstrument(const UdarackiInstrument &u)
    {

        cena = u.cena;
        ocena = u.ocena;
        proizvodjac = u.proizvodjac;
        ton = u.ton;
    }

    void setVisinaTona(udarackiVisinaTona vis)
    {
        ton = vis;
    }

    string getVisinaTona()const
    {
        switch(ton)
        {
        case odredjena:
            return "Odredjena visina tona";
            break;
        case neodredjena:
            return "Neodredjena visina tona";
            break;
        default:
            return "Nema visine tona";
            break;
        }
    }

    void ispisUdarackogInstrumenta()
    {
        ispisInstrumenta();
        cout<<"Visina tona: "<<getVisinaTona()<<endl;
    }

    void unosUdarackogInstrumenta()
    {
        int br;
        unosInstrumenta();
        cout<<"Visina tona[1-Odredjena/2-Neodredjena]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            ton = odredjena;
            break;
        case 2:
            ton = neodredjena;
            break;
        }
    }

};
/////////////////////////////////////////////////////////////
class Bubanj : public UdarackiInstrument
{
private:
    bool glasan;
    bool rezonantan;
    int brojSlojeva;
    bubanjVrsta vrsta;
public:

    int bubanjID;

    Bubanj()
    {
        cena = 2500.00;
        ocena = 9.0;
        proizvodjac = yamaha;
        ton = odredjena;
        glasan = true;
        rezonantan = false;
        brojSlojeva = 2;
        vrsta = bongo;
    }
    Bubanj(int idd,float cc, float oo, proizvodjaci pp, udarackiVisinaTona visina,bool glasnoca, bool rez, int brs, bubanjVrsta bub)
    {
        bubanjID = idd;
        cena = cc;
        ocena = oo;
        proizvodjac = pp;
        ton = visina;
        glasan = glasnoca;
        rezonantan = rez;
        brojSlojeva = brs;
        vrsta = bub;
    }
    Bubanj(const Bubanj &b)
    {
        bubanjID = b.bubanjID;
        cena = b.cena;
        ocena = b.ocena;
        proizvodjac = b.proizvodjac;
        ton = b.ton;
        glasan = b.glasan;
        rezonantan = b.rezonantan;
        brojSlojeva = b.brojSlojeva;
        vrsta = b.vrsta;
    }

    void setGlasnoca(bool glas)
    {
        glasan = glas;
    }
    void setRezonantan(bool rezon)
    {
        rezonantan = rezon;
    }
    void setBrojSlojeva(int br)
    {
        brojSlojeva = br;
    }
    void setVrstaBubnjeva(bubanjVrsta vr)
    {
        vrsta = vr;
    }

    string getGlasnoca()const
    {
        if(glasan == false)
        {
            return "Nije glasan";
        }
        else if (glasan == true)
        {
            return "Glasan";
        }
        else
            return "Nije odredjena glasnoca instrumenta";
    }
    string getRezonantnost()const
    {
        if(rezonantan == false)
        {
            return "Nije rezonantan";
        }
        else if (rezonantan == true)
        {
            return "Rezonantan";
        }
        else
            return "Nije odredjena rezonantnost instrumenta";
    }
    int getBrojSlojeva()const
    {
        return brojSlojeva;
    }
    string getVrstaBubnja()const
    {
        switch(vrsta)
        {
        case kongo:
            return "KONGO";
            break;
        case bongo:
            return "BONGO";
            break;
        case djambe:
            return "DJAMBE";
            break;
        case tabla:
            return "TABLA";
            break;
        case timpani:
            return "TIMPANI";
            break;
        case pahu:
            return "PAHU";
            break;
        default:
            return "Nema vrste bubnjeva";
            break;
        }
    }
    int getBubanjID()const;

    void ispisBubnja()
    {
        cout<<"ID: "<<getBubanjID()<<endl;
        ispisUdarackogInstrumenta();
        cout<<"Glasnost bubnja: "<<getGlasnoca()<<endl;
        cout<<"Rezonantnost bubnja: "<<getRezonantnost()<<endl;
        cout<<"Broj slojeva: "<<getBrojSlojeva()<<endl;
        cout<<"Vrsta bubnjeva: "<<getVrstaBubnja()<<endl;
    }

    void unosBubnja()
    {
        int br;
        cout<<"ID: ";
        cin>>bubanjID;
        fflush(stdin);
        unosUdarackogInstrumenta();
        cout<<"Glasnoca bubnja: ";
        cin>>glasan;
        fflush(stdin);
        cout<<"Rezonantnost bubnja: ";
        cin>>rezonantan;
        fflush(stdin);
        cout<<"Broj slojeva: ";
        cin>>brojSlojeva;
        fflush(stdin);
        cout<<"Vrsta bubnja[1-Bongo/2-Djambe/3-Kongo/4-Pahu/5-Tabla/6-Timpani]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrsta = bongo;
            break;
        case 2:
            vrsta = djambe;
            break;
        case 3:
            vrsta = kongo;
            break;
        case 4:
            vrsta = pahu;
            break;
        case 5:
            vrsta = tabla;
            break;
        case 6:
            vrsta = timpani;
            break;
        }
    }

};
int Bubanj::getBubanjID()const
{
    return bubanjID;
}

void dodajUFajlBubanj()
{
    Bubanj b;
    ofstream outFile;
    outFile.open("BUBANJ.dat",ios::binary|ios::app);
    b.unosBubnja();
    outFile.write(reinterpret_cast<char *> (&b), sizeof(Bubanj));
    outFile.close();
    cout<<"\n\nBubanj dodat u fajl!";
    cin.ignore();
    cin.get();
}
void ispisiFajlBubanj()
{
    Bubanj b;
    ifstream inFile;
    inFile.open("BUBANJ.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVI BUBNJEVI U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&b), sizeof(Bubanj)))
    {
        b.ispisBubnja();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluBubanj(int n)
{
    Bubanj b;
    ifstream inFile;
    inFile.open("BUBANJ.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&b), sizeof(Bubanj)))
    {
        if(b.getBubanjID()==n)
        {
            b.ispisBubnja();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nBubanj ne postoji!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluBubanj(int n)
{
    Bubanj b;
    ifstream inFile;
    inFile.open("BUBANJ.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempBubanj.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&b), sizeof(Bubanj)))
    {
        if(b.getBubanjID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&b), sizeof(Bubanj));
        }
    }
    outFile.close();
    inFile.close();
    remove("BUBANJ.dat");
    rename("TempBubanj.dat","BUBANJ.dat");
    cout<<"\n\n\tBubanj obrisan!";
    cin.ignore();
    cin.get();
}

/////////////////////////////////////////////////////////////////////////////////
class Cinele : public UdarackiInstrument
{
private:
    int precnik;
    cineleVrsta vrsta;
public:

    int cineleID;

    Cinele()
    {
        cena = 1000.00;
        ocena = 8.0;
        proizvodjac = yamaha;
        precnik = 20;
        vrsta = splash;
    }
    Cinele(float cc, float oo, proizvodjaci pp, udarackiVisinaTona visina, int pre, cineleVrsta vrs)
    {
        cena = cc;
        ocena = oo;
        proizvodjac = pp;
        ton = visina;
        precnik = pre;
        vrsta = vrs;
    }
    Cinele(const Cinele &c)
    {
        cena = c.cena;
        ocena = c.ocena;
        proizvodjac = c.proizvodjac;
        ton = c.ton;
        precnik = c.precnik;
        vrsta = c.vrsta;
    }

    void setPrencnik(int prec)
    {
        precnik = prec;
    }
    void setVrstaCinela(cineleVrsta cinela)
    {
        vrsta = cinela;
    }

    int getCineleID()const;
    int getPrecnik()const
    {
        return precnik;
    }
    string getVrstaCinela()const
    {
        switch(vrsta)
        {
        case orchestral:
            return "ORCHESTRAL";
            break;
        case crash:
            return "CRASH";
            break;
        case hiHats:
            return "HIHATS";
            break;
        case suspended:
            return "SUSPENDED";
            break;
        case splash:
            return "SPLASH";
            break;
        case ancient:
            return "ANCIENT";
            break;
        default:
            return "Nema vrste cinela";
            break;
        }
    }

    void ispisCinela()
    {
        cout<<"ID: "<<getCineleID()<<endl;
        ispisUdarackogInstrumenta();
        cout<<"Precnik: "<<getPrecnik()<<endl;
        cout<<"Vrsta cinela: "<<getVrstaCinela()<<endl;
    }

    void unosCinela()
    {
        int br;
        cout<<"ID: ";
        cin>>cineleID;
        unosUdarackogInstrumenta();
        cout<<"Precnik: ";
        cin>>precnik;
        fflush(stdin);
        cout<<"Vrsta cinela[1-Ancient/2-Crash/3-Hi hats/4-Orchestral/5-Splash/6-Suspended]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrsta = ancient;
            break;
        case 2:
            vrsta = crash;
            break;
        case 3:
            vrsta = hiHats;
            break;
        case 4:
            vrsta = orchestral;
            break;
        case 5:
            vrsta = splash;
            break;
        case 6:
            vrsta = suspended;
            break;
        }
    }
};

int Cinele::getCineleID()const
{
    return cineleID;
}

void dodajUFajlCinele()
{
    Cinele c;
    ofstream outFile;
    outFile.open("CINELE.dat",ios::binary|ios::app);
    c.unosCinela();
    outFile.write(reinterpret_cast<char *> (&c), sizeof(Cinele));
    outFile.close();
    cout<<"\n\nCinele dodate u fajl!";
    cin.ignore();
    cin.get();
}
void ispisiFajlCinele()
{
    Cinele c;
    ifstream inFile;
    inFile.open("CINELE.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVE CINELE U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&c), sizeof(Cinele)))
    {
        c.ispisCinela();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluCinele(int n)
{
    Cinele c;
    ifstream inFile;
    inFile.open("CINELE.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&c), sizeof(Cinele)))
    {
        if(c.getCineleID()==n)
        {
            c.ispisCinela();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nCinele ne postoje!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluCinele(int n)
{
    Cinele c;
    ifstream inFile;
    inFile.open("CINELE.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempCinele.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&c), sizeof(Cinele)))
    {
        if(c.getCineleID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&c), sizeof(Cinele));
        }
    }
    outFile.close();
    inFile.close();
    remove("CINELE.dat");
    rename("TempCinele.dat","CINELE.dat");
    cout<<"\n\n\tCinele obrisane!";
    cin.ignore();
    cin.get();
}

//////////////////////////////////////////////////////////////////////
class Daire : public UdarackiInstrument
{
private:
    char obrucMaterijal[20];
public:

    int daireID;

    Daire()
    {
        cena = 700.00;
        ocena = 10.0;
        proizvodjac = yamaha;
        ton = neodredjena;;
    }
    Daire(float cc, float oo, proizvodjaci pp, udarackiVisinaTona visina)
    {
        cena = cc;
        ocena = oo;
        proizvodjac = pp;
        ton = visina;
    }
    Daire(const Daire &d)
    {
        cena = d.cena;
        ocena = d.ocena;
        proizvodjac = d.proizvodjac;
        ton = d.ton;
    }

    //void setMaterijalObruca(string obruc){obrucMaterijal = obruc;}

    const char* getMaterijalObruca()const
    {
        return obrucMaterijal;
    }
    int getDaireID()const;

    void ispisDaira()
    {
        cout<<"ID: "<<getDaireID()<<endl;
        ispisUdarackogInstrumenta();
        cout<<"Materijal obruca: "<<getMaterijalObruca()<<endl;
    }

    void unosDaira()
    {
        cout<<"ID: ";
        cin>>daireID;
        fflush(stdin);
        unosUdarackogInstrumenta();
        cout<<"Materijal obruca: ";
        cin>>obrucMaterijal;
        fflush(stdin);
    }
};

int Daire::getDaireID()const
{
    return daireID;
}

void dodajUFajlDaire()
{
    Daire d;
    ofstream outFile;
    outFile.open("DAIRE.dat",ios::binary|ios::app);
    d.unosDaira();
    outFile.write(reinterpret_cast<char *> (&d), sizeof(Daire));
    outFile.close();
    cout<<"\n\nDaire dodate u fajl!";
    cin.ignore();
    cin.get();
}
void ispisiFajlDaire()
{
    Daire d;
    ifstream inFile;
    inFile.open("DAIRE.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVE DAIRE U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&d), sizeof(Daire)))
    {
        d.ispisDaira();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluDaire(int n)
{
    Daire d;
    ifstream inFile;
    inFile.open("DAIRE.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&d), sizeof(Daire)))
    {
        if(d.getDaireID()==n)
        {
            d.ispisDaira();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nDaire ne postoje!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluDaire(int n)
{
    Daire d;
    ifstream inFile;
    inFile.open("DAIRE.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempDaire.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&d), sizeof(Daire)))
    {
        if(d.getDaireID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&d), sizeof(Daire));
        }
    }
    outFile.close();
    inFile.close();
    remove("DAIRE.dat");
    rename("TempDaire.dat","DAIRE.dat");
    cout<<"\n\n\tDaire obrisane!";
    cin.ignore();
    cin.get();
}
////////////////////////////////////////////////////////////////////////
class Datum
{
protected:
    int dan, mesec, godina;

public:

    Datum(int DAN, int MESEC, int GODINA)
    {
        dan = DAN;
        mesec = MESEC;
        godina = GODINA;
    }

    Datum()
    {
        dan = 20;
        mesec = 1;
        godina = 2004;
    }

    Datum(const Datum &d)
    {
        dan = d.dan;
        mesec = d.mesec;
        godina = d.godina;
    }

    int getDan()const
    {
        return dan;
    }
    int getMesec()const
    {
        return mesec;
    }
    int getGodina()const
    {
        return godina;
    }

    void setDan(int DAN)
    {
        if(DAN<1 || DAN>31)
            cout<<"Dan van opsega! Probajte ponovo."<<endl;
        else
            dan = DAN;
    }
    void setMesec(int MESEC)
    {
        if(MESEC<1 || MESEC>12)
            cout<<"Mesec van opsega! Probajte ponovo."<<endl;
        else
            mesec = MESEC;
    }
    void setGodina(int GODINA)
    {
        if(GODINA<1900|| GODINA>2020)
            cout<<"Godina van opsega! Probajte ponovo."<<endl;
        else
            godina = GODINA;
    }

    void ispisiDatum()
    {
        cout<<"Datum: "<<getDan()<<"-"<<getMesec()<<"-"<<getGodina()<<endl;
    }

    void unesiDatum()
    {
        cout<<"Dan: ";
        cin>>dan;
        fflush(stdin);
        cout<<"Mesec: ";
        cin>>mesec;
        fflush(stdin);
        cout<<"Godina: ";
        cin>>godina;
        fflush(stdin);
    }
};
//////////////////////////////////////////////////////////////////////
class DJOprema : public Proizvod
{
private:
    djOpremaVrsta vrsta;
public:

    int DJOpremaID;

    DJOprema()
    {
        cena = 8000;
        ocena = 9.67;
        proizvodjac = yamaha;
        vrsta = djInterface;
    }

    DJOprema(float CENA, float OCENA, proizvodjaci PROIZVODJAC, djOpremaVrsta VRSTA)
    {
        cena = CENA;
        ocena = OCENA;
        proizvodjac = PROIZVODJAC;
        vrsta = VRSTA;
    }

    DJOprema(const DJOprema &dj)
    {
        cena = dj.cena;
        ocena = dj.ocena;
        proizvodjac = dj.proizvodjac;
        vrsta = dj.vrsta;
    }

    int getDJOpremaID()const;

    string getVrsta()const
    {
        switch(vrsta)
        {
        case djInterface:
            return "DJ interface";
            break;
        case djKontroler:
            return "DJ kontroler";
            break;
        case djMikseta:
            return "DJ mikseta";
            break;
        case djPaket:
            return "DJ paket";
            break;
        case djSlusalice:
            return "DJ Slusalice";
            break;
        }
    }

    void setVrsta()
    {
        int br;
        cout<<"Vrsta [1-DJ interface/2-DJ kontroler/3-DJ mikseta/4-DJ paket/5-DJ slusalice]: ";
        cin>>br;
        fflush(stdin);

        switch(br)
        {
        case 1:
            vrsta = djInterface;
            break;
        case 2:
            vrsta = djKontroler;
            break;
        case 3:
            vrsta = djMikseta;
            break;
        case 4:
            vrsta = djPaket;
            break;
        case 5:
            vrsta = djSlusalice;
            break;
        }
    }

    void ispisiDJOprema()
    {
        cout<<"ID: "<<getDJOpremaID()<<endl;
        ispisProizvoda();
        cout<<"Vrsta: "<<getVrsta()<<endl;
    }

    void unesiDJOprema()
    {
        cout<<"ID: ";
        cin>>DJOpremaID;
        fflush(stdin);
        unosProizvoda();
        setVrsta();
    }
};

int DJOprema::getDJOpremaID()const
{
    return DJOpremaID;
}

void dodajUFajlDJOprema()
{
    DJOprema dj;
    ofstream outFile;
    outFile.open("DJOPREMA.dat",ios::binary|ios::app);
    dj.unesiDJOprema();
    outFile.write(reinterpret_cast<char *> (&dj), sizeof(DJOprema));
    outFile.close();
    cout<<"\n\nDJ oprema dodata u fajl!";
    cin.ignore();
    cin.get();
}
void ispisiFajlDJOprema()
{
    DJOprema dj;
    ifstream inFile;
    inFile.open("DJOPREMA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVA DJ OPREMA U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&dj), sizeof(DJOprema)))
    {
        dj.ispisiDJOprema();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluDJOprema(int n)
{
    DJOprema dj;
    ifstream inFile;
    inFile.open("DJOPREMA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&dj), sizeof(DJOprema)))
    {
        if(dj.getDJOpremaID()==n)
        {
            dj.ispisiDJOprema();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nDJ oprema ne postoji!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluDJOprema(int n)
{
    DJOprema dj;
    ifstream inFile;
    inFile.open("DJOPREMA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempDJoprema.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&dj), sizeof(DJOprema)))
    {
        if(dj.getDJOpremaID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&dj), sizeof(DJOprema));
        }
    }
    outFile.close();
    inFile.close();
    remove("DJOPREMA.dat");
    rename("TempDJoprema.dat","DJOPREMA.dat");
    cout<<"\n\n\tDJ oprema obrisana!";
    cin.ignore();
    cin.get();
}
/////////////////////////////////////////////////////////////////////////////

class Flauta: public DuvackiInstrument
{
private:
    flautaVrsta vrstaf;
public:

    int flautaID;

    Flauta()
    {
        cena=800.00;
        ocena=8.75;
        proizvodjac=yamaha;
        vrsta=drveni;
        vrstaf=standardna;
    }

    Flauta(float c, float o,proizvodjaci p, duvackiVrsta v,  flautaVrsta fv)
    {
        cena=c;
        ocena=o;
        proizvodjac=p;
        vrsta=v;
        vrstaf=fv;
    }

    Flauta(const Flauta &f)
    {
        cena=f.cena;
        ocena=f.ocena;
        proizvodjac=f.proizvodjac;
        vrsta=f.vrsta;
        vrstaf=f.vrstaf;
    }

    int getFlautaID()const;
    string getFlauta()const
    {
        switch(vrstaf)
        {
        case harmonijska:
            return "Harmonijska";
            break;
        case pikolo:
            return "Pikolo";
            break;
        case standardna:
            return "Standardna";
            break;
        }
    }
    void setFlauta(flautaVrsta fv)
    {
        vrstaf=fv;
    }

    void ispisFlaute()
    {
        cout<<"ID: "<<getFlautaID()<<endl;
        ispisDuvackogInstrumenta();
        cout<<"Vrsta flaute :"<<getFlauta()<<endl;
    }

    void unosFlaute()
    {
        int br;
        cout<<"ID: ";
        cin>>flautaID;
        fflush(stdin);
        unosDuvackogInstrumenta();
        cout<<"Vrsta flaute[1-Harmonijska/2-Pikolo/3-Standardna]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrstaf = harmonijska;
            break;
        case 2:
            vrstaf = pikolo;
            break;
        case 3:
            vrstaf = standardna;
            break;
        }
    }
};

int Flauta::getFlautaID()const
{
    return flautaID;
}

void dodajUFajlFlauta()
{
    Flauta f;
    ofstream outFile;
    outFile.open("FLAUTA.dat",ios::binary|ios::app);
    f.unosFlaute();
    outFile.write(reinterpret_cast<char *> (&f), sizeof(Flauta));
    outFile.close();
    cout<<"\n\nFlauta dodata u fajl!";
    cin.ignore();
    cin.get();
}
void ispisiFajlFlauta()
{
    Flauta f;
    ifstream inFile;
    inFile.open("FLAUTA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVE FLAUTE U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&f), sizeof(Flauta)))
    {
        f.ispisFlaute();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluFlauta(int n)
{
    Flauta f;
    ifstream inFile;
    inFile.open("FLAUTA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&f), sizeof(Flauta)))
    {
        if(f.getFlautaID()==n)
        {
            f.ispisFlaute();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nFlauta ne postoji!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluFlauta(int n)
{
    Flauta f;
    ifstream inFile;
    inFile.open("FLAUTA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempFlauta.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&f), sizeof(Flauta)))
    {
        if(f.getFlautaID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&f), sizeof(Flauta));
        }
    }
    outFile.close();
    inFile.close();
    remove("FLAUTA.dat");
    rename("TempFlauta.dat","FLAUTA.dat");
    cout<<"\n\n\tFlauta obrisana!";
    cin.ignore();
    cin.get();
}
////////////////////////////////////////////////////////////////////
class ZicaniInstrument : public Instrument
{
protected:
    int brojZica;
    float duzinaZice;
    zicaVrsta vrstaZica;
public:
    ZicaniInstrument()
    {
        cena = 7000.00;
        ocena = 6.9;
        proizvodjac = taylor;
        brojZica = 6;
        duzinaZice = 1.5;
        vrstaZica = nikl;
    }
    ZicaniInstrument(float cc, float oo, proizvodjaci pp, int broj, float duzina, zicaVrsta vrs)
    {
        cena = cc;
        ocena = oo;
        proizvodjac = pp;
        brojZica = broj;
        duzinaZice = duzina;
        vrstaZica = vrs;
    }
    ZicaniInstrument(const ZicaniInstrument &z)
    {
        cena = z.cena;
        ocena = z.ocena;
        proizvodjac = z.proizvodjac;
        brojZica = z.brojZica;
        duzinaZice = z.duzinaZice;
        vrstaZica = z.vrstaZica;
    }

    void setBrojZica(int br)
    {
        brojZica = br;
    }
    void setDuzinaZica(float duz)
    {
        duzinaZice = duz;
    }
    void setVrztaZica(zicaVrsta vr)
    {
        vrstaZica = vr;
    }

    int getBrojZica()const
    {
        return brojZica;
    }
    float getDuzinaZica()const
    {
        return duzinaZice;
    }
    string getVrstaZica()const
    {
        switch(vrstaZica)
        {
        case nikl:
            return "NIKL ZICE";
            break;
        case celik:
            return "CELIK ZICE";
            break;
        case najlon:
            return "NAJLON ZICE";
            break;
        default:
            return "Nema vrste zica";
            break;
        }
    }

    void ispisZicanogInstrumenta()
    {
        ispisInstrumenta();
        cout<<"Broj zica: "<<getBrojZica()<<endl;
        cout<<"Duzina zica: "<<getDuzinaZica()<<" metara"<<endl;
        cout<<"Vrsta zica: "<<getVrstaZica()<<endl;

    }

    void unosZicanogInstrumenta()
    {
        int br;
        unosInstrumenta();
        cout<<"Broj zica: ";
        cin>>brojZica;
        cout<<"Duzina zica: ";
        cin>>duzinaZice;
        cout<<"Vrsta zice[1-Celik/2-Najlon/3-Nikl]: ";
        cin>>br;
        switch(br)
        {
        case 1:
            vrstaZica = celik;
            break;
        case 2:
            vrstaZica = najlon;
            break;
        case 3:
            vrstaZica = nikl;
            break;
        }
    }
};
////////////////////////////////////////////////////////////////

class Gitara : public ZicaniInstrument
{
private:
    gitaraVrsta vrstaGitare;
public:

    int gitaraID;

    Gitara()
    {
        cena = 9500.00;
        ocena = 9.9;
        proizvodjac = yamaha;
        brojZica = 6;
        duzinaZice = 1.33;
        vrstaZica = nikl;
        vrstaGitare = elektricnaGitara;
    }
    Gitara(float cc, float oo, proizvodjaci pp, int broj, float duzina, zicaVrsta vrs, gitaraVrsta git)
    {
        cena = cc;
        ocena = oo;
        proizvodjac = pp;
        brojZica = broj;
        duzinaZice = duzina;
        vrstaZica = vrs;
        vrstaGitare = git;
    }
    Gitara(const Gitara &g)
    {
        cena = g.cena;
        ocena = g.ocena;
        proizvodjac = g.proizvodjac;
        brojZica = g.brojZica;
        duzinaZice = g.duzinaZice;
        vrstaZica = g.vrstaZica;
        vrstaGitare = g.vrstaGitare;
    }

    void setVrstaGitare(gitaraVrsta vrs)
    {
        vrstaGitare = vrs;
    }

    int getGitaraID()const;
    string getVrstaGitare()const
    {
        switch(vrstaGitare)
        {
        case klasicnaGitara:
            return "KLASICNA GITARA";
            break;
        case akusticnaGitara:
            return "AKUSTICNA GITARA";
            break;
        case elektroAkusticnaGitara:
            return "ELEKTROAKUSTICNA GITARA";
            break;
        case elektricnaGitara:
            return "ELEKTRICNA GITARA";
            break;
        case basGitara:
            return "BAS GITARA";
            break;
        default:
            return "Nema vrste gitare";
            break;
        }
    }

    void ispisGitare()
    {
        cout<<"ID: "<<getGitaraID()<<endl;
        ispisZicanogInstrumenta();
        cout<<"Vrsta gitare: "<<getVrstaGitare()<<endl;
    }

    void unosGitare()
    {
        int br;
        cout<<"ID: ";
        cin>>gitaraID;
        unosZicanogInstrumenta();
        cout<<"Vrsta gitare[1-Akusticna/2-Bas/3-Elektricna/4-Elektro akusticna/5-Klasicna]: ";
        cin>>br;
        switch(br)
        {
        case 1:
            vrstaGitare = akusticnaGitara;
            break;
        case 2:
            vrstaGitare = basGitara;
            break;
        case 3:
            vrstaGitare = elektricnaGitara;
            break;
        case 4:
            vrstaGitare = elektroAkusticnaGitara;
            break;
        case 5:
            vrstaGitare = klasicnaGitara;
            break;

        }
    }
};

int Gitara::getGitaraID()const
{
    return gitaraID;
}

void dodajUFajlGitara()
{
    Gitara g;
    ofstream outFile;
    outFile.open("GITARA.dat",ios::binary|ios::app);
    g.unosGitare();
    outFile.write(reinterpret_cast<char *> (&g), sizeof(Gitara));
    outFile.close();
    cout<<"\n\nGitara dodata u fajl!";
    cin.ignore();
    cin.get();
}
void ispisiFajlGitara()
{
    Gitara g;
    ifstream inFile;
    inFile.open("GITARA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVE GITARE U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&g), sizeof(Gitara)))
    {
        g.ispisGitare();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluGitara(int n)
{
    Gitara g;
    ifstream inFile;
    inFile.open("GITARA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&g), sizeof(Gitara)))
    {
        if(g.getGitaraID()==n)
        {
            g.ispisGitare();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nGitara ne postoji!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluGitara(int n)
{
    Gitara g;
    ifstream inFile;
    inFile.open("GITARA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempGitara.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&g), sizeof(Gitara)))
    {
        if(g.getGitaraID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&g), sizeof(Gitara));
        }
    }
    outFile.close();
    inFile.close();
    remove("GITARA.dat");
    rename("TempGitara.dat","GITARA.dat");
    cout<<"\n\n\tGitara obrisana!";
    cin.ignore();
    cin.get();
}
///////////////////////////////////////////////////////////////////////////////////////////////

class GudackiInstrument : Instrument
{
protected:
    tipGudala gudaloTip;
    int brojZica;
    zicaVrsta vrstaZica;
    bool isElectric;
public:
    GudackiInstrument() : Instrument()
    {
        gudaloTip = NEMACKI;
        brojZica = 4;
        isElectric = false;
    }
    GudackiInstrument( tipGudala tipG, int brojZ,bool electric, float c, float o, proizvodjaci pp) : Instrument( c, o, pp)
    {
        gudaloTip = tipG;
        brojZica = brojZ;
        isElectric = electric;
    }
    GudackiInstrument(const GudackiInstrument &gi) : Instrument((Instrument)gi)
    {
        gudaloTip = gi.gudaloTip;
        brojZica = gi.brojZica;
    }

    tipGudala getGudalo () const
    {
        return gudaloTip;
    }
    int getZicaBroj () const
    {
        return brojZica;
    }
    bool getElectric () const
    {
        return isElectric;
    }

    void setGudalo (tipGudala g)
    {
        gudaloTip = g;
    }
    void setZicaBroj (int b)
    {
        brojZica = b;
    }
    void setElectric (bool e)
    {
        isElectric = e;
    }

    void ispisGudackogInstrumenta()
    {
        ispisInstrumenta();
        cout<<"Tip gudala: "<<getGudalo()<<endl;
        cout<<"Broj zica: "<<getZicaBroj()<<endl;
        cout<<"Elektricna: "<<getElectric()<<endl;
    }

    void unosGudackogInstrumenta()
    {
        int br;
        unosInstrumenta();
        cout<<"Tip gudala[1-Francuski/2-Nemacki]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            gudaloTip = FRANCUSKI;
            break;
        case 2:
            gudaloTip = NEMACKI;
            break;
        }
        cout<<"Broj zica: ";
        cin>>brojZica;
        fflush(stdin);
        cout<<"Elektricna: ";
        cin>>isElectric;
        fflush(stdin);
    }
};
//////////////////////////////////////////////////////////////////////
class Harfa : public ZicaniInstrument
{
private:
    bool elektricna;
    harfaVrsta vrstaHarfe;
public:

    int harfaID;

    Harfa()
    {
        cena = 20590.00;
        ocena = 7.9;
        proizvodjac = yamaha;
        brojZica = 48;
        duzinaZice = 2;
        vrstaZica = celik;
        elektricna = false;
        vrstaHarfe = poluga;
    }
    Harfa( float cc, float oo, proizvodjaci pp, int broj, float duzina, zicaVrsta vrs, bool elektro, harfaVrsta harf )
    {
        ocena = oo;
        proizvodjac = pp;
        brojZica = broj;
        duzinaZice = duzina;
        vrstaZica = vrs;
        elektricna = elektro;
        vrstaHarfe = harf;
    }

    Harfa(const Harfa &h)
    {
        cena = h.cena;
        ocena = h.ocena;
        proizvodjac = h.proizvodjac;
        brojZica = h.brojZica;
        duzinaZice = h.duzinaZice;
        vrstaZica = h.vrstaZica;
        elektricna = h.elektricna;
        vrstaHarfe = h.vrstaHarfe;
    }

    void setElektricna(bool elek)
    {
        elektricna = elek;
    }
    void setVrstaHarfe(harfaVrsta ha)
    {
        vrstaHarfe = ha;
    }

    int getHarfaID()const;
    string getElektricna()const
    {
        if(elektricna == false)
        {
            return "Nije elektricna";
        }
        else if(elektricna == true)
        {
            return "Jeste elektricna";
        }
        else
            return "Nema podataka o elektricnosti";
    }

    string getVrstaHarfe()const
    {
        switch(vrstaHarfe)
        {
        case pedala:
            return "PEDALA";
            break;
        case poluga:
            return "POLUGA";
            break;
        default:
            return "Nema vrste harfe";
            break;
        }
    }

    void ispisHarfe()
    {
        cout<<"ID: "<<getHarfaID()<<endl;
        ispisZicanogInstrumenta();
        cout<<"Elektricna: "<<getElektricna()<<endl;
        cout<<"Vrsta harfe: "<<getVrstaHarfe()<<endl;
    }

    void unosHarfe()
    {
        int br;
        cout<<"ID: ";
        cin>>harfaID;
        unosZicanogInstrumenta();
        cout<<"Elektricna: ";
        cin>>elektricna;
        fflush(stdin);
        cout<<"Vrsta harfe[1-Pedala/2-Poluga]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrstaHarfe = pedala;
            break;
        case 2:
            vrstaHarfe = poluga;
            break;
        }
    }
};

int Harfa::getHarfaID()const
{
    return harfaID;
}

void dodajUFajlHarfa()
{
    Harfa h;
    ofstream outFile;
    outFile.open("HARFA.dat",ios::binary|ios::app);
    h.unosHarfe();
    outFile.write(reinterpret_cast<char *> (&h), sizeof(Harfa));
    outFile.close();
    cout<<"\n\nHarfa dodata u fajl!";
    cin.ignore();
    cin.get();
}
void ispisiFajlHarfa()
{
    Harfa h;
    ifstream inFile;
    inFile.open("HARFA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVE HARFE U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&h), sizeof(Harfa)))
    {
        h.ispisHarfe();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluHarfa(int n)
{
    Harfa h;
    ifstream inFile;
    inFile.open("HARFA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&h), sizeof(Harfa)))
    {
        if(h.getHarfaID()==n)
        {
            h.ispisHarfe();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nHarfa ne postoji!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluHarfa(int n)
{
    Harfa h;
    ifstream inFile;
    inFile.open("HARFA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempHarfa.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&h), sizeof(Harfa)))
    {
        if(h.getHarfaID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&h), sizeof(Harfa));
        }
    }
    outFile.close();
    inFile.close();
    remove("HARFA.dat");
    rename("TempHarfa.dat","HARFA.dat");
    cout<<"\n\n\tHarfa obrisana!";
    cin.ignore();
    cin.get();
}
////////////////////////////////////////////////////////////////////

class Harmonika: public Instrument
{
private:
    harmonikaVrsta vrstah;
public:

    int harmonikaID;

    Harmonika()
    {
        cena=4000.00;
        ocena=9.69;
        proizvodjac=yamaha;
        vrstah=obicna;
    }

    Harmonika(float c, float o, proizvodjaci p, harmonikaVrsta h )
    {
        cena=c;
        ocena=o;
        proizvodjac=p;
        vrstah=h;
    }

    Harmonika(const Harmonika &h)
    {
        cena=h.cena;
        ocena=h.ocena;
        proizvodjac=h.proizvodjac;
        vrstah=h.vrstah;
    }

    string getHarmonika()
    {
        switch(vrstah)
        {
        case obicna:
            return "Obicna";
            break;
        case usnena:
            return "Usnena";
            break;
        }
    }
    void setHarmonika(harmonikaVrsta h)
    {
        vrstah=h;
    }
    int getHarmonikaID()const;

    void ispisHarmonike()
    {
        cout<<"ID: "<<getHarmonikaID()<<endl;
        ispisInstrumenta();
        cout<<"Vrsta harmonike:"<<getHarmonika()<<endl;
    }

    void unosHarmonike()
    {
        int br;
        cout<<"ID: ";
        cin>>harmonikaID;
        unosInstrumenta();
        cout<<"Vrsta harmonike[1-Obicna/2-Usnena]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrstah = obicna;
            break;
        case 2:
            vrstah = usnena;
            break;
        }
    }
};

int Harmonika::getHarmonikaID()const
{
    return harmonikaID;
}

void dodajUFajlHarmonika()
{
    Harmonika h;
    ofstream outFile;
    outFile.open("HARMONIKA.dat",ios::binary|ios::app);
    h.unosHarmonike();
    outFile.write(reinterpret_cast<char *> (&h), sizeof(Harmonika));
    outFile.close();
    cout<<"\n\nHarmonika dodata u fajl!";
    cin.ignore();
    cin.get();
}
void ispisiFajlHarmonika()
{
    Harmonika h;
    ifstream inFile;
    inFile.open("HARMONIKA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVE HARMONIKE U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&h), sizeof(Harmonika)))
    {
        h.ispisHarmonike();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluHarmonika(int n)
{
    Harmonika h;
    ifstream inFile;
    inFile.open("HARMONIKA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&h), sizeof(Harmonika)))
    {
        if(h.getHarmonikaID()==n)
        {
            h.ispisHarmonike();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nHarmonika ne postoji!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluHarmonika(int n)
{
    Harmonika h;
    ifstream inFile;
    inFile.open("HARMONIKA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempHarmonika.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&h), sizeof(Harmonika)))
    {
        if(h.getHarmonikaID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&h), sizeof(Harmonika));
        }
    }
    outFile.close();
    inFile.close();
    remove("HARMONIKA.dat");
    rename("TempHarmonika.dat","HARMONIKA.dat");
    cout<<"\n\n\tHarmonika obrisana!";
    cin.ignore();
    cin.get();
}
///////////////////////////////////////////////////////////////////////

class Horna: public DuvackiInstrument
{
private:
    hornaVrsta vrstah;
public:

    int hornaID;

    Horna()
    {
        cena=2000.00;
        ocena=8.75;
        proizvodjac=yamaha;
        vrsta=limeni;
        vrstah=jednostruka;
    }

    Horna( float c, float o,proizvodjaci p, duvackiVrsta v, hornaVrsta hv)
    {
        cena=c;
        ocena=o;
        proizvodjac=p;
        vrsta=v;
        vrstah=hv;
    }

    Horna(const Horna &h)
    {
        cena=h.cena;
        ocena=h.ocena;
        proizvodjac=h.proizvodjac;
        vrsta=h.vrsta;
    }

    int getHornaID()const;
    string getHorna()const
    {
        switch(vrstah)
        {
        case jednostruka:
            return "Jednostruka";
            break;
        case dvostruka:
            return "Dvostruka";
            break;
        case odvojivoZvono:
            return "Odvojivo zvono";
            break;
        }
    }
    void setHorna(hornaVrsta hv)
    {
        vrstah=hv;
    }

    void ispisHorne()
    {
        cout<<"ID: "<<getHornaID()<<endl;
        ispisDuvackogInstrumenta();
        cout<<"Vrsta horne :"<<getHorna()<<endl;
    }

    void unosHorne()
    {
        int br;
        cout<<"ID: ";
        cin>>hornaID;
        fflush(stdin);
        unosDuvackogInstrumenta();
        cout<<"Vrsta horne[1-Dvostruka/2-Jednostruka/3-Sa odvojivim zvonom]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrstah = dvostruka;
            break;
        case 2:
            vrstah = jednostruka;
            break;
        case 3:
            vrstah = odvojivoZvono;
            break;
        }
    }
};

int Horna::getHornaID()const
{
    return hornaID;
}

void dodajUFajlHorna()
{
    Horna h;
    ofstream outFile;
    outFile.open("HORNA.dat",ios::binary|ios::app);
    h.unosHorne();
    outFile.write(reinterpret_cast<char *> (&h), sizeof(Horna));
    outFile.close();
    cout<<"\n\nHorna dodata u fajl!";
    cin.ignore();
    cin.get();
}
void ispisiFajlHorna()
{
    Horna h;
    ifstream inFile;
    inFile.open("HORNA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVE HORNE U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&h), sizeof(Horna)))
    {
        h.ispisHorne();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluHorna(int n)
{
    Horna h;
    ifstream inFile;
    inFile.open("HORNA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&h), sizeof(Horna)))
    {
        if(h.getHornaID()==n)
        {
            h.ispisHorne();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nHorna ne postoji!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluHorna(int n)
{
    Horna h;
    ifstream inFile;
    inFile.open("HORNA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempHorna.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&h), sizeof(Horna)))
    {
        if(h.getHornaID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&h), sizeof(Horna));
        }
    }
    outFile.close();
    inFile.close();
    remove("HORNA.dat");
    rename("TempHorna.dat","HORNA.dat");
    cout<<"\n\n\tHorna obrisana!";
    cin.ignore();
    cin.get();
}
//////////////////////////////////////////////////////////

class Kastanjete : public UdarackiInstrument
{
private:
    drvoVrsta vrsta;
public:

    int kastanjeteID;

    Kastanjete()
    {
        cena = 800.00;
        ocena = 6.0;
        proizvodjac = yamaha;
        ton = odredjena;
        vrsta = jasen;
    }
    Kastanjete( float cc, float oo, proizvodjaci pp,  udarackiVisinaTona visina, drvoVrsta drv)
    {
        cena = cc;
        ocena = oo;
        proizvodjac = pp;
        ton = visina;
        vrsta = drv;
    }
    Kastanjete(const Kastanjete &k)
    {
        cena = k.cena;
        ocena = k.ocena;
        proizvodjac = k.proizvodjac;
        ton = k.ton;
        vrsta = k.vrsta;
    }

    void setVrsta(drvoVrsta vrs)
    {
        vrsta = vrs;
    }

    int getKastanjeteID()const;
    string getVrstaDrveta()const
    {
        switch(vrsta)
        {
        case jasen:
            return "JASEN";
            break;
        case javor:
            return "JAVOR";
            break;
        case mahagoni:
            return "MAHAGONI";
            break;
        default:
            return "Nema vrste drveta";
            break;
        }
    }

    void ispisKastanjeta()
    {
        cout<<"ID: "<<getKastanjeteID()<<endl;
        ispisUdarackogInstrumenta();
        cout<<"Vrsta drveta: "<<getVrstaDrveta()<<endl;
    }

    void unosKastanjeta()
    {
        int br;
        cout<<"ID: ";
        cin>>kastanjeteID;
        fflush(stdin);
        unosUdarackogInstrumenta();
        cout<<"Vrsta drveta[1-Jasen/2-Javor/3-Mahagoni]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrsta = jasen;
            break;
        case 2:
            vrsta = javor;
            break;
        case 3:
            vrsta = mahagoni;
            break;
        }
    }

};
int Kastanjete::getKastanjeteID()const
{
    return kastanjeteID;
}

void dodajUFajlKastanjete()
{
    Kastanjete k;
    ofstream outFile;
    outFile.open("KASTANJETE.dat",ios::binary|ios::app);
    k.unosKastanjeta();
    outFile.write(reinterpret_cast<char *> (&k), sizeof(Kastanjete));
    outFile.close();
    cout<<"\n\nKastanjete dodate u fajl!";
    cin.ignore();
    cin.get();
}
void ispisiFajlKastanjete()
{
    Kastanjete k;
    ifstream inFile;
    inFile.open("KASTANJETE.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVE KASTANJETE U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&k), sizeof(Kastanjete)))
    {
        k.ispisKastanjeta();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluKastanjete(int n)
{
    Kastanjete k;
    ifstream inFile;
    inFile.open("KASTANJETE.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&k), sizeof(Kastanjete)))
    {
        if(k.getKastanjeteID()==n)
        {
            k.ispisKastanjeta();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nKastanjete ne postoje!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluKastanjete(int n)
{
    Kastanjete k;
    ifstream inFile;
    inFile.open("KASTANJETE.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempKastanjete.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&k), sizeof(Kastanjete)))
    {
        if(k.getKastanjeteID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&k), sizeof(Kastanjete));
        }
    }
    outFile.close();
    inFile.close();
    remove("KASTANJETE.dat");
    rename("TempKastanjete.dat","KASTANJETE.dat");
    cout<<"\n\n\tKastanjete obrisane!";
    cin.ignore();
    cin.get();
}
////////////////////////////////////////////////////////////////


class Klarinet: public DuvackiInstrument
{
private:
    char klarinetMaterijal[20];
    klarinetVrsta vrstak;
public:

    int klarinetID;

    Klarinet()
    {
        cena=800.00;
        ocena=8.75;
        proizvodjac=yamaha;
        vrsta=drveni;
        vrstak=harmonijskiKlarinet;
    }

    Klarinet(float c, float o,proizvodjaci p, duvackiVrsta v, klarinetVrsta kv)
    {
        cena=c;
        ocena=o;
        proizvodjac=p;
        vrsta=v;
        vrstak=kv;
    }

    Klarinet(const Klarinet &k)
    {
        cena=k.cena;
        ocena=k.ocena;
        proizvodjac=k.proizvodjac;
        vrsta=k.vrsta;
        vrstak=k.vrstak;
    }

    int getKlarinetID()const;
    const char* getMaterijal()const
    {
        return klarinetMaterijal;
    }
    string getKlarinet()
    {
        switch(vrstak)
        {
        case harmonijskiKlarinet:
            return "Harmonijski";
            break;
        case klarinetA:
            return "A";
            break;
        case klarinetBb:
            return "Bb";
            break;
        }
    }


    void setKlarinet(klarinetVrsta kv)
    {
        vrstak=kv;
    }

    void ispisKlarineta()
    {
        cout<<"ID: "<<getKlarinetID()<<endl;
        ispisDuvackogInstrumenta();
        cout<<"Vrsta klarineta :"<<getKlarinet()<<endl;
        cout<<"Materijal klarineta :"<<getMaterijal()<<endl;
    }

    void unosKlarineta()
    {
        int br;
        cout<<"ID: ";
        cin>>klarinetID;
        fflush(stdin);
        unosDuvackogInstrumenta();
        cout<<"Vrsta klarineta[1-Harmonijski/2-A/3-Bb]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrstak = harmonijskiKlarinet;
            break;
        case 2:
            vrstak = klarinetA;
            break;
        case 3:
            vrstak = klarinetBb;
            break;
        }
        cout<<"Materijal klarineta: ";
        cin>>klarinetMaterijal;
        fflush(stdin);
    }

};

int Klarinet::getKlarinetID()const
{
    return klarinetID;
}

void dodajUFajlKlarinet()
{
    Klarinet k;
    ofstream outFile;
    outFile.open("KLARINET.dat",ios::binary|ios::app);
    k.unosKlarineta();
    outFile.write(reinterpret_cast<char *> (&k), sizeof(Klarinet));
    outFile.close();
    cout<<"\n\nKlarinet dodat u fajl!";
    cin.ignore();
    cin.get();
}
void ispisiFajlKlarinet()
{
    Klarinet k;
    ifstream inFile;
    inFile.open("KLARINET.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVI KLARINETI U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&k), sizeof(Klarinet)))
    {
        k.ispisKlarineta();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluKlarinet(int n)
{
    Klarinet k;
    ifstream inFile;
    inFile.open("KLARINET.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&k), sizeof(Klarinet)))
    {
        if(k.getKlarinetID()==n)
        {
            k.ispisKlarineta();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nKlarinet ne postoji!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluKlarinet(int n)
{
    Klarinet k;
    ifstream inFile;
    inFile.open("KLARINET.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempKlarinet.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&k), sizeof(Klarinet)))
    {
        if(k.getKlarinetID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&k), sizeof(Klarinet));
        }
    }
    outFile.close();
    inFile.close();
    remove("KLARINET.dat");
    rename("TempKlarinet.dat","KLARINET.dat");
    cout<<"\n\n\tKlarinet obrisan!";
    cin.ignore();
    cin.get();
}
///////////////////////////////////////////////////////////

class Klavir: public Instrument
{
private:
    klavirVrsta vrstak;
public:

    int klavirID;

    Klavir()
    {
        cena=4000.00;
        ocena=9.69;
        proizvodjac=yamaha;
        vrstak=elektricni;
    }

    Klavir( float c, float o, proizvodjaci p, klavirVrsta k)
    {
        cena=c;
        ocena=o;
        proizvodjac=p;
        vrstak=k;
    }

    Klavir(const Klavir &k)
    {
        cena=k.cena;
        ocena=k.ocena;
        proizvodjac=k.proizvodjac;
        vrstak=k.vrstak;
    }

    int getKlavirID()const;
    string getKlavir()const
    {
        switch(vrstak)
        {
        case elektricni:
            return "Elektricni";
            break;
        case koncertni:
            return "Koncertni";
            break;
        case pianino:
            return "Pianino";
            break;
        case polukoncertni:
            return "Polukoncertni";
            break;
        }
    }
    void setKlavir(klavirVrsta k)
    {
        vrstak=k;
    }

    void ispisKlavira()
    {
        cout<<"ID: "<<getKlavirID()<<endl;
        ispisInstrumenta();
        cout<<"Vrsta klavira:"<<getKlavir()<<endl;
    }

    void unosKlavira()
    {
        int br;
        cout<<"ID: ";
        cin>>klavirID;
        fflush(stdin);
        unosInstrumenta();
        cout<<"Vrsta klavira[1-Elektricni/2-Koncertni/3-Pianino/4-Polukoncertni]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrstak = elektricni;
            break;
        case 2:
            vrstak = koncertni;
            break;
        case 3:
            vrstak = pianino;
            break;
        case 4:
            vrstak = polukoncertni;
            break;
        }
    }
};

int Klavir::getKlavirID()const
{
    return klavirID;
}

void dodajUFajlKlavir()
{
    Klavir k;
    ofstream outFile;
    outFile.open("KLAVIR.dat",ios::binary|ios::app);
    k.unosKlavira();
    outFile.write(reinterpret_cast<char *> (&k), sizeof(Klavir));
    outFile.close();
    cout<<"\n\nKlavir dodat u fajl!";
    cin.ignore();
    cin.get();
}
void ispisiFajlKlavir()
{
    Klavir k;
    ifstream inFile;
    inFile.open("KLAVIR.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVI KLAVIRI U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&k), sizeof(Klavir)))
    {
        k.ispisKlavira();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluKlavir(int n)
{
    Klavir k;
    ifstream inFile;
    inFile.open("KLAVIR.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&k), sizeof(Klavir)))
    {
        if(k.getKlavirID()==n)
        {
            k.ispisKlavira();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nKlavir ne postoji!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluKlavir(int n)
{
    Klavir k;
    ifstream inFile;
    inFile.open("KLAVIR.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempKlavir.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&k), sizeof(Klavir)))
    {
        if(k.getKlavirID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&k), sizeof(Klavir));
        }
    }
    outFile.close();
    inFile.close();
    remove("KLAVIR.dat");
    rename("TempKlavir.dat","KLAVIR.dat");
    cout<<"\n\n\tKlavir obrisan!";
    cin.ignore();
    cin.get();
}

//////////////////////////////////////////////////////////////////////////

class Kontrabas : public GudackiInstrument
{
private:
    kontrabasVrsta vrstak;
    char velicina[20];
public:

    int kontrabasID;

    Kontrabas() : GudackiInstrument()
    {
        vrstak = dupliBas;
    }
    Kontrabas(kontrabasVrsta kontrabasType,tipGudala tipG, int brojZ, zicaVrsta typeOfString, bool electric,float c, float o, proizvodjaci pp)
        : GudackiInstrument( tipG, brojZ,electric,c,o,pp)
    {
        vrstak = kontrabasType;
    }
    Kontrabas(const Kontrabas &v) : GudackiInstrument((GudackiInstrument)v)
    {
        vrstak = v.vrstak;
    }

    int getKontrabasID()const
    {
        return kontrabasID;
    }
    const char* getVelicina()const
    {
        return velicina;
    }
    string getKontrabasVrsta() const
    {
        switch(vrstak)
        {
        case dadihu:
            return "Dadihu";
            break;
        case dalaruan:
            return "Dalaruan";
            break;
        case dupliBas:
            return "Dupli bas";
            break;
        case oktobas:
            return "Oktobas";
            break;
        case violona:
            return "Violona";
            break;
        }
    }

    void setKontrabasVrsta(kontrabasVrsta k)
    {
        vrstak = k;
    }

    void ispisKontrabasa()
    {
        cout<<"ID: "<<getKontrabasID()<<endl;
        ispisGudackogInstrumenta();
        cout<<"Vrsta kontrabasa: "<<getKontrabasVrsta()<<endl;
        cout<<"Velicina: "<<getVelicina()<<endl;
    }

    void unosKontrabasa()
    {
        int br;
        cout<<"ID: ";
        cin>>kontrabasID;
        fflush(stdin);
        unosGudackogInstrumenta();
        cout<<"Vrsta kontrabasa[1-Dadihu/2-Dalaruan/3-Dupli bas/4-Oktobas/5-Violona]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrstak = dadihu;
            break;
        case 2:
            vrstak = dalaruan;
            break;
        case 3:
            vrstak = dupliBas;
            break;
        case 4:
            vrstak = oktobas;
            break;
        case 5:
            vrstak = violona;
            break;
        }
        cout<<"Velicina: ";
        cin>>velicina;
    }
};

void dodajUFajlKontrabas()
{
    Kontrabas k;
    ofstream outFile;
    outFile.open("KONTRABAS.dat",ios::binary|ios::app);
    k.unosKontrabasa();
    outFile.write(reinterpret_cast<char *> (&k), sizeof(Kontrabas));
    outFile.close();
    cout<<"\n\nKontrabas dodat u fajl!";
    cin.ignore();
    cin.get();
}
void ispisiFajlKontrabas()
{
    Kontrabas k;
    ifstream inFile;
    inFile.open("KONTRABAS.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVI KONTRABASI U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&k), sizeof(Kontrabas)))
    {
        k.ispisKontrabasa();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluKontrabas(int n)
{
    Kontrabas k;
    ifstream inFile;
    inFile.open("KONTRABAS.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&k), sizeof(Kontrabas)))
    {
        if(k.getKontrabasID()==n)
        {
            k.ispisKontrabasa();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nKontrabas ne postoji!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluKontrabas(int n)
{
    Kontrabas k;
    ifstream inFile;
    inFile.open("KONTRABAS.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempKontrabas.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&k), sizeof(Kontrabas)))
    {
        if(k.getKontrabasID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&k), sizeof(Kontrabas));
        }
    }
    outFile.close();
    inFile.close();
    remove("KONTRABAS.dat");
    rename("TempKontrabas.dat","KONTRABAS.dat");
    cout<<"\n\n\tKontrabas obrisan!";
    cin.ignore();
    cin.get();
}
//////////////////////////////////////////////////////////////

class Kontroler : public Proizvod
{
private:
    kontrolerVrsta vrsta;
public:

    int kontrolerID;

    Kontroler()
    {
        cena = 6799.99;
        ocena = 9;
        proizvodjac = yamaha;
        vrsta = recording;
    }

    Kontroler(float CENA, float OCENA, proizvodjaci PROIZVODJAC, kontrolerVrsta VRSTA)
    {
        cena = CENA;
        ocena = OCENA;
        proizvodjac = PROIZVODJAC;
        vrsta = VRSTA;
    }

    Kontroler(const Kontroler &k)
    {
        cena = k.cena;
        ocena = k.ocena;
        proizvodjac = k.proizvodjac;
        vrsta = k.vrsta;
    }

    int getKontrolerID()const;
    string getVrsta()const
    {
        switch(vrsta)
        {
        case keyboard:
            return "Keyboard";
            break;
        case monitor:
            return "Monitor";
            break;
        case pad:
            return "Pad";
            break;
        case recording:
            return "Recording";
            break;
        }
    }

    void setVrsta()
    {
        int br;
        cout<<"Unesite broj [1-Keyboard/2-Monitor/3-Pad/4-Recording]: "<<endl;
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrsta = keyboard;
            break;
        case 2:
            vrsta = monitor;
            break;
        case 3:
            vrsta = pad;
            break;
        case 4:
            vrsta = recording;
            break;
        }
    }

    void ispisiKontroler()
    {
        cout<<"ID: "<<getKontrolerID()<<endl;
        ispisProizvoda();
        cout<<"Vrsta: "<<getVrsta()<<endl;
    }

    void unesiKontroler()
    {
        int br;
        cout<<"ID: ";
        cin>>kontrolerID;
        fflush(stdin);
        unosProizvoda();
        cout<<"Vrsta[1-Keyboard/2-Monitor/3-Pad/4-Recording]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrsta = keyboard;
            break;
        case 2:
            vrsta = monitor;
            break;
        case 3:
            vrsta = pad;
            break;
        case 4:
            vrsta = recording;
            break;
        }
    }
};

int Kontroler::getKontrolerID()const
{
    return kontrolerID;
}

void dodajUFajlKontroler()
{
    Kontroler k;
    ofstream outFile;
    outFile.open("KONTROLER.dat",ios::binary|ios::app);
    k.unesiKontroler();
    outFile.write(reinterpret_cast<char *> (&k), sizeof(Kontroler));
    outFile.close();
    cout<<"\n\nKontroler dodat u fajl!";
    cin.ignore();
    cin.get();
}
void ispisiFajlKontroler()
{
    Kontroler k;
    ifstream inFile;
    inFile.open("KONTROLER.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVI KONTROLERI U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&k), sizeof(Kontroler)))
    {
        k.ispisiKontroler();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluKontroler(int n)
{
    Kontroler k;
    ifstream inFile;
    inFile.open("KONTROLER.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&k), sizeof(Kontroler)))
    {
        if(k.getKontrolerID()==n)
        {
            k.ispisiKontroler();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nKontroler ne postoji!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluKontroler(int n)
{
    Kontroler k;
    ifstream inFile;
    inFile.open("KONTROLER.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempKontroler.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&k), sizeof(Kontroler)))
    {
        if(k.getKontrolerID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&k), sizeof(Kontroler));
        }
    }
    outFile.close();
    inFile.close();
    remove("KONTROLER.dat");
    rename("TempKontroler.dat","KONTROLER.dat");
    cout<<"\n\n\tKontroler obrisan!";
    cin.ignore();
    cin.get();
}
////////////////////////////////////////////////////////////////////////////

class Kupac : public Osoba
{
private:
    bool unutra;

public:
    Kupac() : Osoba()
    {
        unutra = false;
    }

    Kupac( bool U, string I, string P, int G) : Osoba(I,P,G)
    {
        unutra = U;
    }

    Kupac(const Kupac &k) : Osoba((Osoba)k)
    {
        unutra = k.unutra;
    }

    bool getUnutra()const
    {
        return unutra;
    }

    void setUnutra(bool U)
    {
        unutra = U;
    }

    void ispisiKupca()
    {
        ispisiOsobu();
        cout<<"Unutra: ";
        if(unutra==0)
            cout<<"Ne"<<endl;
        else
            cout<<"Da"<<endl;
    }

    void unesiKupca()
    {
        unesiOsobu();
        cout<<"Unutra: ";
        cin>>unutra;
    }

};
/////////////////////////////////////////////////////////////////////////////////
class Lokacija
{
protected:
    string nazivUlice, grad, drzava;
    int brojUlice, postanskiBroj;

public:
    Lokacija()
    {
        nazivUlice = "Nije unet";
        grad = "Nije unet";
        drzava = "Nije uneta";
        brojUlice = 0;
        postanskiBroj = 0;
    }

    Lokacija(string ULICA, string GRAD, string DRZAVA, int BRU, int BRP)
    {
        nazivUlice = ULICA;
        grad = GRAD;
        drzava = DRZAVA;
        brojUlice = BRU;
        postanskiBroj = BRP;
    }

    Lokacija(const Lokacija &l)
    {
        nazivUlice = l.nazivUlice;
        grad = l.grad;
        drzava = l.drzava;
        brojUlice = l.brojUlice;
        postanskiBroj = l.postanskiBroj;
    }

    string getNazivUlice()const
    {
        return nazivUlice;
    }
    string getGrad()const
    {
        return grad;
    }
    string getDrzava()const
    {
        return drzava;
    }
    int getBrojUlice()const
    {
        return brojUlice;
    }
    int getPostanskiBroj()const
    {
        return postanskiBroj;
    }

    void setNazivUlice(string NAZIV)
    {
        nazivUlice = NAZIV;
    }
    void setGrad(string GRAD)
    {
        grad = GRAD;
    }
    void setDrzava(string DRZAVA)
    {
        drzava = DRZAVA;
    }
    void setBrojUlice(int BRU)
    {
        brojUlice = BRU;
    }
    void setPostanskiBroj(int BRP)
    {
        postanskiBroj = BRP;
    }

    void ispisiLokaciju()
    {
        cout<<"Naziv ulice: "<<getNazivUlice()<<endl;
        cout<<"Broj ulice: "<<getBrojUlice()<<endl;
        cout<<"Grad: "<<getGrad()<<endl;
        cout<<"Postanski broj: "<<getPostanskiBroj()<<endl;
        cout<<"Drzava: "<<getDrzava()<<endl;
    }

    void unesiLokaciju()
    {
        cout<<"Naziv ulice: ";
        cin>>nazivUlice;
        cout<<"Broj ulice: ";
        cin>>brojUlice;
        cout<<"Grad: ";
        cin>>grad;
        cout<<"Postanski broj: ";
        cin>>postanskiBroj;
        cout<<"Drzava: ";
        cin>>drzava;
    }

};
///////////////////////////////////////////////////////////////////////////////
class Metalofon : public UdarackiInstrument
{
private:
    int brojOktava;
public:

    int metalofonID;

    Metalofon()
    {
        cena = 1000.00;
        ocena = 10.0;
        proizvodjac = yamaha;
        ton = odredjena;
        brojOktava = 2;
    }
    Metalofon(float cc, float oo, proizvodjaci pp, udarackiVisinaTona visina, int brO)
    {
        cena = cc;
        ocena = oo;
        proizvodjac = pp;
        ton = visina;
        brojOktava = brO;
    }
    Metalofon(const Metalofon &m)
    {
        cena = m.cena;
        ocena = m.ocena;
        proizvodjac = m.proizvodjac;
        ton = m.ton;
    }

    int getMetalofonID()const;
    void setBrojOktava(int broj)
    {
        brojOktava = broj;
    }

    int getBrojOktava()const
    {
        return brojOktava;
    }

    void ispisMetalofona()
    {
        cout<<"ID: "<<getMetalofonID()<<endl;
        ispisUdarackogInstrumenta();
        cout<<"Broj oktava: "<<getBrojOktava()<<endl;
    }

    void unosMetalofona()
    {
        cout<<"ID: ";
        cin>>metalofonID;
        fflush(stdin);
        unosUdarackogInstrumenta();
        cout<<"Broj oktava: ";
        cin>>brojOktava;
        fflush(stdin);
    }
};

int Metalofon::getMetalofonID()const
{
    return metalofonID;
}

void dodajUFajlMetalofon()
{
    Metalofon m;
    ofstream outFile;
    outFile.open("METALOFON.dat",ios::binary|ios::app);
    m.unosMetalofona();
    outFile.write(reinterpret_cast<char *> (&m), sizeof(Metalofon));
    outFile.close();
    cout<<"\n\nMetalofon dodat u fajl!";
    cin.ignore();
    cin.get();
}
void ispisiFajlMetalofon()
{
    Metalofon m;
    ifstream inFile;
    inFile.open("METALOFON.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVI METALOFONI U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&m), sizeof(Metalofon)))
    {
        m.ispisMetalofona();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluMetalofon(int n)
{
    Metalofon m;
    ifstream inFile;
    inFile.open("METALOFON.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&m), sizeof(Metalofon)))
    {
        if(m.getMetalofonID()==n)
        {
            m.ispisMetalofona();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nMetalofon ne postoji!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluMetalofon(int n)
{
    Metalofon m;
    ifstream inFile;
    inFile.open("METALOFON.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempMetalofon.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&m), sizeof(Metalofon)))
    {
        if(m.getMetalofonID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&m), sizeof(Metalofon));
        }
    }
    outFile.close();
    inFile.close();
    remove("METALOFON.dat");
    rename("TempMetalofon.dat","METALOFON.dat");
    cout<<"\n\n\tMetalofon obrisan!";
    cin.ignore();
    cin.get();
}

///////////////////////////////////////////////////////////////////////////////
class Mikrofon : public Proizvod
{
private:
    mikrofonVrsta vrsta;
public:

    int mikrofonID;

    Mikrofon()
    {
        cena = 7999.99;
        ocena = 9.66;
        proizvodjac = yamaha;
        vrsta = studijski;
    }

    Mikrofon( float CENA, float OCENA, proizvodjaci PROIZVODJAC, mikrofonVrsta VRSTA)
    {
        cena = CENA;
        ocena = OCENA;
        proizvodjac = PROIZVODJAC;
        vrsta = VRSTA;
    }

    Mikrofon(const Mikrofon &m)
    {
        cena = m.cena;
        ocena = m.ocena;
        proizvodjac = m.proizvodjac;
        vrsta = m.vrsta;
    }

    int getMikrofonID()const;
    string getVrsta()const
    {
        switch(vrsta)
        {
        case bezicni:
            return "Bezicni";
            break;
        case studijski:
            return "Studijski";
            break;
        case zicani:
            return "Zicani";
            break;
        }
    }

    void setVrsta()
    {
        int br;
        cout<<"Vrsta mikrofona[1-Bezicni/2-Studijski/3-Zicani]: "<<endl;
        cin>>br;

        switch(br)
        {
        case 1:
            vrsta = bezicni;
            break;
        case 2:
            vrsta = studijski;
            break;
        case 3:
            vrsta = zicani;
            break;
        }

    }

    void ispisiMikrofon()
    {
        cout<<"ID: "<<getMikrofonID()<<endl;
        ispisProizvoda();
        cout<<"Vrsta: "<<getVrsta()<<endl;
    }

    void unesiMikrofon()
    {
        cout<<"ID: ";
        cin>>mikrofonID;
        fflush(stdin);
        unosProizvoda();
        setVrsta();
    }

};

int Mikrofon::getMikrofonID()const
{
    return mikrofonID;
}

void dodajUFajlMikrofon()
{
    Mikrofon m;
    ofstream outFile;
    outFile.open("MIKROFON.dat",ios::binary|ios::app);
    m.unesiMikrofon();
    outFile.write(reinterpret_cast<char *> (&m), sizeof(Mikrofon));
    outFile.close();
    cout<<"\n\nMikrofon dodat u fajl!";
    cin.ignore();
    cin.get();
}
void ispisiFajlMikrofon()
{
    Mikrofon m;
    ifstream inFile;
    inFile.open("MIKROFON.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVI MIKROFONI U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&m), sizeof(Mikrofon)))
    {
        m.ispisiMikrofon();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluMikrofon(int n)
{
    Mikrofon m;
    ifstream inFile;
    inFile.open("MIKROFON.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&m), sizeof(Mikrofon)))
    {
        if(m.getMikrofonID()==n)
        {
            m.ispisiMikrofon();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nMikrofon ne postoji!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluMikrofon(int n)
{
    Mikrofon m;
    ifstream inFile;
    inFile.open("MIKROFON.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempMikrofon.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&m), sizeof(Mikrofon)))
    {
        if(m.getMikrofonID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&m), sizeof(Mikrofon));
        }
    }
    outFile.close();
    inFile.close();
    remove("MIKROFON.dat");
    rename("TempMikrofon.dat","MIKROFON.dat");
    cout<<"\n\n\tMikrofon obrisan!";
    cin.ignore();
    cin.get();
}
/////////////////////////////////////////////////

class Mikser : Proizvod
{
private:
    mikserVrsta vrsta;
public:

    int mikserID;

    Mikser() : Proizvod()
    {
        vrsta = digitalni;
    }
    Mikser(mikserVrsta mikserType,float c, float o, proizvodjaci pp) : Proizvod( c, o, pp)
    {
        vrsta = mikserType;
    }
    Mikser(const Mikser &m) : Proizvod((Proizvod)m)
    {
        vrsta = m.vrsta;
    }

    int getMikserID()const;
    string getMikserVrsta()const
    {
        switch(vrsta)
        {
        case bezEfekata:
            return "Bez efekata";
            break;
        case digitalni:
            return "Digitalni";
            break;
        case power:
            return "Power";
            break;
        case saEfektima:
            return "Sa efektima";
            break;
        }
    }
    void setMikserVrsta (mikserVrsta m)
    {
        vrsta = m;
    }

    void ispisMiksera()
    {
        cout<<"ID: "<<getMikserID()<<endl;
        ispisProizvoda();
        cout<<"Vrsta miksera: "<<getMikserVrsta()<<endl;
    }

    void unosMiksera()
    {
        int br;
        cout<<"ID: ";
        cin>>mikserID;
        fflush(stdin);
        unosProizvoda();
        cout<<"Vrsta miksera[1-Bez efekta/2-Digitalni/3-Power/4-Sa efektima]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrsta = bezEfekata;
            break;
        case 2:
            vrsta = digitalni;
            break;
        case 3:
            vrsta = power;
            break;
        case 4:
            vrsta = saEfektima;
            break;
        }
    }
};

int Mikser::getMikserID()const
{
    return mikserID;
}

void dodajUFajlMikser()
{
    Mikser m;
    ofstream outFile;
    outFile.open("MIKSER.dat",ios::binary|ios::app);
    m.unosMiksera();
    outFile.write(reinterpret_cast<char *> (&m), sizeof(Mikser));
    outFile.close();
    cout<<"\n\nMikser dodat u fajl!";
    cin.ignore();
    cin.get();
}
void ispisiFajlMikser()
{
    Mikser m;
    ifstream inFile;
    inFile.open("MIKSER.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVI MIKSERI U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&m), sizeof(Mikser)))
    {
        m.ispisMiksera();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluMikser(int n)
{
    Mikser m;
    ifstream inFile;
    inFile.open("MIKSER.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&m), sizeof(Mikser)))
    {
        if(m.getMikserID()==n)
        {
            m.ispisMiksera();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nMikser ne postoji!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluMikser(int n)
{
    Mikser m;
    ifstream inFile;
    inFile.open("MIKSER.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempMikser.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&m), sizeof(Mikser)))
    {
        if(m.getMikserID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&m), sizeof(Mikser));
        }
    }
    outFile.close();
    inFile.close();
    remove("MIKSER.dat");
    rename("TempMikser.dat","MIKSER.dat");
    cout<<"\n\n\tMikser obrisan!";
    cin.ignore();
    cin.get();
}
//////////////////////////////////////////////////////////

class Mikseta : public Proizvod
{
private:
    miksetaVrsta vrsta;
public:

    int miksetaID;

    Mikseta() : Proizvod()
    {
        vrsta = analogna;
    }

    Mikseta(miksetaVrsta v, float c, float o, proizvodjaci pp) : Proizvod(c,o,pp)
    {
        vrsta = v;
    }

    Mikseta(const Mikseta &m) : Proizvod((Proizvod)m)
    {
        vrsta = m.vrsta;
    }

    void setVrsta(miksetaVrsta VRSTA)
    {
        vrsta = VRSTA;
    }
    string getVrsta()
    {
        switch(vrsta)
        {
        case analogna:
            return "Analogna";
            break;
        case digitalna:
            return "Digitalna";
            break;
        }
    }
    int getMiksetaID()const;

    void ispisiMiksetu()
    {
        cout<<"ID: "<<getMiksetaID()<<endl;
        ispisProizvoda();
        cout<<"Vrsta: "<<getVrsta()<<endl;
    }

    void unesiMiksetu()
    {
        int br;
        cout<<"ID: ";
        cin>>miksetaID;
        fflush(stdin);
        unosProizvoda();
        cout<<"Vrsta miksete[1-Analogna/2-Digitalna]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrsta = analogna;
            break;
        case 2:
            vrsta = digitalna;
            break;
        }
    }
};

int Mikseta::getMiksetaID()const
{
    return miksetaID;
}

void dodajUFajlMikseta()
{
    Mikseta m;
    ofstream outFile;
    outFile.open("MIKSETA.dat",ios::binary|ios::app);
    m.unesiMiksetu();
    outFile.write(reinterpret_cast<char *> (&m), sizeof(Mikseta));
    outFile.close();
    cout<<"\n\nMikseta dodata u fajl!";
    cin.ignore();
    cin.get();
}
void ispisiFajlMikseta()
{
    Mikseta m;
    ifstream inFile;
    inFile.open("MIKSETA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVE MIKSETE U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&m), sizeof(Mikseta)))
    {
        m.ispisiMiksetu();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluMikseta(int n)
{
    Mikseta m;
    ifstream inFile;
    inFile.open("MIKSETA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&m), sizeof(Mikseta)))
    {
        if(m.getMiksetaID()==n)
        {
            m.ispisiMiksetu();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nMikseta ne postoji!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluMikseta(int n)
{
    Mikseta m;
    ifstream inFile;
    inFile.open("MIKSETA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempMikseta.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&m), sizeof(Mikseta)))
    {
        if(m.getMiksetaID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&m), sizeof(Mikseta));
        }
    }
    outFile.close();
    inFile.close();
    remove("MIKSETA.dat");
    rename("TempMikseta.dat","MIKSETA.dat");
    cout<<"\n\n\tMikseta obrisana!";
    cin.ignore();
    cin.get();
}

//////////////////////////////////////////////////////////////////////////////////////////////

class Oboa: public DuvackiInstrument
{
private:
    oboaVrsta vrstao;
public:

    int oboaID;

    Oboa()
    {
        cena=800.00;
        ocena=8.75;
        proizvodjac=yamaha;
        vrsta=drveni;
        vrstao=baroknaOboa;
    }

    Oboa(float c, float o,proizvodjaci p, duvackiVrsta v,  oboaVrsta ov)
    {
        cena=c;
        ocena=o;
        proizvodjac=p;
        vrsta=v;
        vrstao=ov;
    }

    Oboa(const Oboa &o)
    {
        cena=o.cena;
        ocena=o.ocena;
        proizvodjac=o.proizvodjac;
        vrsta=o.vrsta;
        vrstao=o.vrstao;
    }

    int getOboaID()const;
    string getOboa()const
    {
        switch(vrstao)
        {
        case baroknaOboa:
            return "Barokna";
            break;
        case beckaOboa:
            return "Becka";
            break;
        case klasicnaOboa:
            return "Klasicna";
            break;
        case modernaOboa:
            return "Moderna";
            break;
        }
    }
    void setOboa(oboaVrsta ov)
    {
        vrstao=ov;
    }

    void ispisOboe()
    {
        cout<<"ID: "<<getOboaID()<<endl;
        ispisDuvackogInstrumenta();
        cout<<"Vrsta oboe :"<<getOboa()<<endl;
    }

    void unosOboe()
    {
        int br;
        cout<<"ID: ";
        cin>>oboaID;
        fflush(stdin);
        unosDuvackogInstrumenta();
        cout<<"Vrsta oboe[1-Barokna/2-Becka/3-Klasicna/4-Moderna]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrstao = baroknaOboa;
            break;
        case 2:
            vrstao = beckaOboa;
            break;
        case 3:
            vrstao = klasicnaOboa;
            break;
        case 4:
            vrstao = modernaOboa;
            break;
        }
    }
};

int Oboa::getOboaID()const
{
    return oboaID;
}

void dodajUFajlOboa()
{
    Oboa o;
    ofstream outFile;
    outFile.open("OBOA.dat",ios::binary|ios::app);
    o.unosOboe();
    outFile.write(reinterpret_cast<char *> (&o), sizeof(Oboa));
    outFile.close();
    cout<<"\n\nOboa dodata u fajl!";
    cin.ignore();
    cin.get();
}
void ispisiFajlOboa()
{
    Oboa o;
    ifstream inFile;
    inFile.open("OBOA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVE OBOE U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&o), sizeof(Oboa)))
    {
        o.ispisOboe();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluOboa(int n)
{
    Oboa o;
    ifstream inFile;
    inFile.open("OBOA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&o), sizeof(Oboa)))
    {
        if(o.getOboaID()==n)
        {
            o.ispisOboe();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nOboa ne postoji!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluOboa(int n)
{
    Oboa o;
    ifstream inFile;
    inFile.open("OBOA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempOboa.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&o), sizeof(Oboa)))
    {
        if(o.getOboaID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&o), sizeof(Oboa));
        }
    }
    outFile.close();
    inFile.close();
    remove("OBOA.dat");
    rename("TempOboa.dat","OBOA.dat");
    cout<<"\n\n\tOboa obrisana!";
    cin.ignore();
    cin.get();
}
/////////////////////////////////////////////////////////////////////////////////////////////////

class OpremaZaInstrumente : public Proizvod
{
private:
    instrumentOpremaVrsta vrsta;
public:

    int opremaID;

    OpremaZaInstrumente()
    {
        cena = 500;
        ocena = 8;
        proizvodjac = yamaha;
        vrsta = metronom;
    }

    OpremaZaInstrumente( float CENA, float OCENA, proizvodjaci PROIZVODJAC, instrumentOpremaVrsta VRSTA)
    {
        cena = CENA;
        ocena = OCENA;
        proizvodjac = PROIZVODJAC;
        vrsta = VRSTA;
    }

    OpremaZaInstrumente(const OpremaZaInstrumente &o)
    {
        cena = o.cena;
        ocena = o.ocena;
        proizvodjac = o.proizvodjac;
        vrsta = o.vrsta;
    }

    int getOpremaID()const;
    string getVrsta()const
    {
        switch(vrsta)
        {
        case kapodaster:
            return "Kapodaster";
            break;
        case metronom:
            return "Metronom";
            break;
        case stalak:
            return "Stalak";
            break;
        case stimer:
            return "Stimer";
            break;
        case stolica:
            return "Stolica";
            break;
        case zvucnaViljuska:
            return "Zvucna viljuska";
            break;
        }
    }

    void setVrsta()
    {
        int br;
        cout<<"Unesite broj [1-Kapodaster/2-Metronom/3-Stalak/4-Stimer/5-Stolica/6-Zvucna viljuska]: "<<endl;
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrsta = kapodaster;
            break;
        case 2:
            vrsta = metronom;
            break;
        case 3:
            vrsta = stalak;
            break;
        case 4:
            vrsta = stimer;
            break;
        case 5:
            vrsta = stolica;
            break;
        case 6:
            vrsta = zvucnaViljuska;
            break;
        }
    }

    void ispisiOpremu()
    {
        cout<<"ID: "<<getOpremaID()<<endl;
        ispisProizvoda();
        cout<<"Vrsta: "<<getVrsta()<<endl;
    }

    void unesiOpremu()
    {
        cout<<"ID: ";
        cin>>opremaID;
        fflush(stdin);
        unosProizvoda();
        setVrsta();
    }
};

int OpremaZaInstrumente::getOpremaID()const
{
    return opremaID;
}

void dodajUFajlOpremaZaInstrumente()
{
    OpremaZaInstrumente o;
    ofstream outFile;
    outFile.open("OPREMAZAINSTRUMENTE.dat",ios::binary|ios::app);
    o.unesiOpremu();
    outFile.write(reinterpret_cast<char *> (&o), sizeof(OpremaZaInstrumente));
    outFile.close();
    cout<<"\n\nOprema dodata u fajl!";
    cin.ignore();
    cin.get();
}

void ispisiFajlOpremaZaInstrumente()
{
    OpremaZaInstrumente o;
    ifstream inFile;
    inFile.open("OPREMAZAINSTRUMENTE.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVA OPREMA ZA INSTRUMENTE U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&o), sizeof(OpremaZaInstrumente)))
    {
        o.ispisiOpremu();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluOpremaZaInstrumente(int n)
{
    OpremaZaInstrumente o;
    ifstream inFile;
    inFile.open("OPREMAZAINSTRUMENTE.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&o), sizeof(OpremaZaInstrumente)))
    {
        if(o.getOpremaID()==n)
        {
            o.ispisiOpremu();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nOorema ne postoji!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluOpremaZaInstrumente(int n)
{
    OpremaZaInstrumente o;
    ifstream inFile;
    inFile.open("OPREMAZAINSTRUMENTE.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempOprema.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&o), sizeof(OpremaZaInstrumente)))
    {
        if(o.getOpremaID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&o), sizeof(OpremaZaInstrumente));
        }
    }
    outFile.close();
    inFile.close();
    remove("OPREMAZAINSTRUMENTE.dat");
    rename("TempOprema.dat","OPREMAZAINSTRUMENTE.dat");
    cout<<"\n\n\tOprema obrisana!";
    cin.ignore();
    cin.get();
}
//////////////////////////////////////////////

class Saksofon: public DuvackiInstrument
{
private:
    saksofonVrsta vrstas;
public:

    int saksofonID;

    Saksofon()
    {
        cena=800.00;
        ocena=8.75;
        proizvodjac=yamaha;
        vrsta=drveni;
        vrstas=sopranSaksofon;
    }

    Saksofon(float c, float o,proizvodjaci p, duvackiVrsta v,  saksofonVrsta sv)
    {
        cena=c;
        ocena=o;
        proizvodjac=p;
        vrsta=v;
        vrstas=sv;
    }

    Saksofon(const Saksofon &s)
    {
        cena=s.cena;
        ocena=s.ocena;
        proizvodjac=s.proizvodjac;
        vrsta=s.vrsta;
        vrstas=s.vrstas;
    }

    int getSaksofonID()const;
    string getSaksofon()
    {
        switch(vrstas)
        {
        case altSaksofon:
            return "Alt";
            break;
        case baritonSaksofon:
            return "Bariton";
            break;
        case sopranSaksofon:
            return "Sopran";
            break;
        case tenorSaksofon:
            return "Tenor";
            break;
        }
    }
    void setSaksofon(saksofonVrsta sv)
    {
        vrstas=sv;
    }

    void ispisSaksofona()
    {
        cout<<"ID: "<<getSaksofonID()<<endl;
        ispisDuvackogInstrumenta();
        cout<<"Vrsta saksofona :"<<getSaksofon()<<endl;
    }

    void unosSaksofona()
    {
        int br;
        cout<<"ID: ";
        cin>>saksofonID;
        fflush(stdin);
        unosDuvackogInstrumenta();
        cout<<"Vrsta saksofona[1-Alt/2-Bariton/3-Sopran/4-Tenor]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrstas = altSaksofon;
            break;
        case 2:
            vrstas = baritonSaksofon;
            break;
        case 3:
            vrstas = sopranSaksofon;
            break;
        case 4:
            vrstas = tenorSaksofon;
            break;
        }
    }
};

int Saksofon::getSaksofonID()const
{
    return saksofonID;
}

void dodajUFajlSaksofon()
{
    Saksofon s;
    ofstream outFile;
    outFile.open("SAKSOFON.dat",ios::binary|ios::app);
    s.unosSaksofona();
    outFile.write(reinterpret_cast<char *> (&s), sizeof(Saksofon));
    outFile.close();
    cout<<"\n\nSaksofon dodat u fajl!";
    cin.ignore();
    cin.get();
}
void ispisiFajlSaksofon()
{
    Saksofon s;
    ifstream inFile;
    inFile.open("SAKSOFON.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVI SAKSOFONI U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&s), sizeof(Saksofon)))
    {
        s.ispisSaksofona();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluSaksofon(int n)
{
    Saksofon s;
    ifstream inFile;
    inFile.open("SAKSOFON.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&s), sizeof(Saksofon)))
    {
        if(s.getSaksofonID()==n)
        {
            s.ispisSaksofona();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nSaksofon ne postoji!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluSaksofon(int n)
{
    Saksofon s;
    ifstream inFile;
    inFile.open("SAKSOFON.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempSaksofon.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&s), sizeof(Saksofon)))
    {
        if(s.getSaksofonID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&s), sizeof(Saksofon));
        }
    }
    outFile.close();
    inFile.close();
    remove("SAKSOFON.dat");
    rename("TempSaksofon.dat","SAKSOFON.dat");
    cout<<"\n\n\tSaksofon obrisan!";
    cin.ignore();
    cin.get();
}
////////////////////////////////////////////////////////////////////////////
class Procesori : Proizvod
{
private:
    procesoriVrsta vrsta;
public:

    int procesorID;

    Procesori() : Proizvod()
    {
        vrsta = ekvilajzer;
    }
    Procesori(procesoriVrsta v, float c, float o, proizvodjaci pp) : Proizvod(c,o,pp)
    {
        vrsta = v;
    }

    Procesori(const Procesori &p) : Proizvod((Proizvod)p)
    {
        vrsta = p.vrsta;
    }

    int getProcesorID()const;
    void setVrsta(procesoriVrsta VRSTA)
    {
        vrsta = VRSTA;
    }
    string getVrsta()
    {
        switch(vrsta)
        {
        case dinamickiProcesor:
            return "Dinamicki procesor";
            break;
        case ekvilajzer:
            return "Ekvilajzer";
            break;
        }
    }

    void ispisiProcesor()
    {
        cout<<"ID: "<<getProcesorID()<<endl;
        ispisProizvoda();
        cout<<"Vrsta: "<<getVrsta()<<endl;
    }

    void unesiProcesor()
    {
        int br;
        cout<<"ID: ";
        cin>>procesorID;
        fflush(stdin);
        unosProizvoda();
        cout<<"Vrsta procesora[1-Dinamicki/2-Ekvilajzer]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrsta = dinamickiProcesor;
            break;
        case 2:
            vrsta = ekvilajzer;
            break;
        }
    }
};

int Procesori::getProcesorID()const
{
    return procesorID;
}

void dodajUFajlProcesori()
{
    Procesori p;
    ofstream outFile;
    outFile.open("PROCESOR.dat",ios::binary|ios::app);
    p.unesiProcesor();
    outFile.write(reinterpret_cast<char *> (&p), sizeof(Procesori));
    outFile.close();
    cout<<"\n\nProcesor dodat u fajl!";
    cin.ignore();
    cin.get();
}
void ispisiFajlProcesor()
{
    Procesori p;
    ifstream inFile;
    inFile.open("PROCESOR.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVI PROCESORI U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&p), sizeof(Procesori)))
    {
        p.ispisiProcesor();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluProcesor(int n)
{
    Procesori p;
    ifstream inFile;
    inFile.open("PROCESOR.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&p), sizeof(Procesori)))
    {
        if(p.getProcesorID()==n)
        {
            p.ispisiProcesor();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nProcesor ne postoji!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluProcesor(int n)
{
    Procesori p;
    ifstream inFile;
    inFile.open("PROCESOR.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempProcesor.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&p), sizeof(Procesori)))
    {
        if(p.getProcesorID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&p), sizeof(Procesori));
        }
    }
    outFile.close();
    inFile.close();
    remove("PROCESOR.dat");
    rename("TempProcesor.dat","PROCESOR.dat");
    cout<<"\n\n\tProcesor obrisan!";
    cin.ignore();
    cin.get();
}
////////////////////////////////////////////////////////////////////
class Slusalice : public Proizvod
{
private:
    bool saMikrofonom;
    float duzinaKabla;
    char frekventniOdziv[20], sistem[20];
public:

    int slusaliceID;

    Slusalice()
    {
        cena = 5999.99;
        ocena = 8.89;
        proizvodjac = yamaha;
        saMikrofonom = true;
        duzinaKabla = 2.5;
    }

    Slusalice( float CENA, float OCENA, proizvodjaci PROIZVODJAC, bool MIKROFON, float DUZINA)
    {
        cena = CENA;
        ocena = OCENA;
        proizvodjac = PROIZVODJAC;
        saMikrofonom = MIKROFON;
        duzinaKabla = DUZINA;
    }

    Slusalice(const Slusalice &s)
    {
        cena = s.cena;
        ocena = s.ocena;
        proizvodjac = s.proizvodjac;
        saMikrofonom = s.saMikrofonom;
        duzinaKabla = s.duzinaKabla;
    }

    int getSlusaliceID()const;
    bool getMikrofon()const
    {
        return saMikrofonom;
    }
    float getDuzinaKabla()const
    {
        return duzinaKabla;
    }
    const char* getFrekventniOdziv()const
    {
        return frekventniOdziv;
    }
    const char* getSistem()const
    {
        return sistem;
    }

    void setMikrofon(bool MIKROFON)
    {
        saMikrofonom = MIKROFON;
    }
    void setDuzinaKabla(float DUZINA)
    {
        duzinaKabla = DUZINA;
    }

    void ispisiSlusalice()
    {
        cout<<"ID: "<<getSlusaliceID()<<endl;
        ispisProizvoda();
        cout<<"Ima mikrofon: "<<getMikrofon()<<endl;
        cout<<"Duzina kabla: "<<getDuzinaKabla()<<"m"<<endl;
        cout<<"Frekventni odziv: "<<getFrekventniOdziv()<<endl;
        cout<<"Sistem: "<<getSistem()<<endl;
    }

    void unesiSlusalice()
    {
        cout<<"ID: ";
        cin>>slusaliceID;
        fflush(stdin);
        unosProizvoda();
        cout<<"Ima mikrofon: ";
        cin>>saMikrofonom;
        fflush(stdin);
        cout<<"Duzina kabla: ";
        cin>>duzinaKabla;
        fflush(stdin);
        cout<<"Frekventni odziv: ";
        cin>>frekventniOdziv;
        fflush(stdin);
        cout<<"Sistem: ";
        cin>>sistem;
        fflush(stdin);
    }

};

int Slusalice::getSlusaliceID()const
{
    return slusaliceID;
}

void dodajUFajlSlusalice()
{
    Slusalice s;
    ofstream outFile;
    outFile.open("SLUSALICE.dat",ios::binary|ios::app);
    s.unesiSlusalice();
    outFile.write(reinterpret_cast<char *> (&s), sizeof(Slusalice));
    outFile.close();
    cout<<"\n\nSlusalice dodate u fajl!";
    cin.ignore();
    cin.get();
}
void ispisiFajlSlusalice()
{
    Slusalice s;
    ifstream inFile;
    inFile.open("SLUSALICE.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVE SLUSALICE U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&s), sizeof(Slusalice)))
    {
        s.ispisiSlusalice();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluSlusalice(int n)
{
    Slusalice s;
    ifstream inFile;
    inFile.open("SLUSALICE.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&s), sizeof(Slusalice)))
    {
        if(s.getSlusaliceID()==n)
        {
            s.ispisiSlusalice();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nSlusalice ne postoje!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluSlusalice(int n)
{
    Slusalice s;
    ifstream inFile;
    inFile.open("SLUSALICE.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempSlusalice.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&s), sizeof(Slusalice)))
    {
        if(s.getSlusaliceID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&s), sizeof(Slusalice));
        }
    }
    outFile.close();
    inFile.close();
    remove("SLUSALICE.dat");
    rename("TempSlusalice.dat","SLUSALICE.dat");
    cout<<"\n\n\tSlusalice obrisane!";
    cin.ignore();
    cin.get();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Trombon : public DuvackiInstrument
{
private:
    trombonVrsta vrstat;
public:

    int trombonID;

    Trombon()
    {
        cena=1000.00;
        ocena=7.96;
        proizvodjac=yamaha;
        vrsta=limeni;
        vrstat=altTrombon;
    }

    Trombon(float c, float o,proizvodjaci p, duvackiVrsta v, trombonVrsta tv)
    {
        cena=c;
        ocena=o;
        proizvodjac=p;
        vrsta=v;
        vrstat=tv;
    }

    Trombon(const Trombon &t)
    {
        cena=t.cena;
        ocena=t.ocena;
        proizvodjac=t.proizvodjac;
        vrsta=t.vrsta;
        vrstat=t.vrstat;
    }

    int getTrombonID()const;
    string getTrombon()
    {
        switch(vrstat)
        {
        case altTrombon:
            return "Alt";
            break;
        case basTrombon:
            return "Bas";
            break;
        case tenorBasTrombon:
            return "Tenor bas";
            break;
        case tenorTrombon:
            return "Tenor";
            break;
        }
    }
    void setTrombon(trombonVrsta tv)
    {
        vrstat=tv;
    }

    void ispisTrombona()
    {
        cout<<"ID: "<<getTrombonID()<<endl;
        ispisDuvackogInstrumenta();
        cout<<"Vrsta trombona :"<<getTrombon()<<endl;
    }

    void unosTrombona()
    {
        int br;
        cout<<"ID: ";
        cin>>trombonID;
        fflush(stdin);
        unosDuvackogInstrumenta();
        cout<<"Vrsta trombona[1-Alt/2-Bas/3-Tenor bas/4-Tenor]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrstat = altTrombon;
            break;
        case 2:
            vrstat = basTrombon;
            break;
        case 3:
            vrstat = tenorBasTrombon;
            break;
        case 4:
            vrstat = tenorTrombon;
            break;
        }
    }
};

int Trombon::getTrombonID()const
{
    return trombonID;
}

void dodajUFajlTrombon()
{
    Trombon t;
    ofstream outFile;
    outFile.open("TROMBON.dat",ios::binary|ios::app);
    t.unosTrombona();
    outFile.write(reinterpret_cast<char *> (&t), sizeof(Trombon));
    outFile.close();
    cout<<"\n\nTrombon dodat u fajl!";
    cin.ignore();
    cin.get();
}
void ispisiFajlTrombon()
{
    Trombon t;
    ifstream inFile;
    inFile.open("TROMBON.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVEI TROMBONI U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&t), sizeof(Trombon)))
    {
        t.ispisTrombona();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluTrombon(int n)
{
    Trombon t;
    ifstream inFile;
    inFile.open("TROMBON.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&t), sizeof(Trombon)))
    {
        if(t.getTrombonID()==n)
        {
            t.ispisTrombona();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nTrombon ne postoji!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluTrombon(int n)
{
    Trombon t;
    ifstream inFile;
    inFile.open("TROMBON.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempTrombon.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&t), sizeof(Trombon)))
    {
        if(t.getTrombonID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&t), sizeof(Trombon));
        }
    }
    outFile.close();
    inFile.close();
    remove("TROMBON.dat");
    rename("TempTrombon.dat","TROMBON.dat");
    cout<<"\n\n\tTrombon obrisan!";
    cin.ignore();
    cin.get();
}
////////////////////////////////////////////////////////////////////////////////

class Truba: public DuvackiInstrument
{
private:
    trubaVrsta vrstat;
public:

    int trubaID;

    Truba()
    {
        cena=1500.00;
        ocena=8.75;
        proizvodjac=gibson;
        vrsta=limeni;
        vrstat=basTruba;
    }

    Truba( float c, float o,proizvodjaci p, duvackiVrsta v, trubaVrsta tv)
    {
        cena=c;
        ocena=o;
        proizvodjac=p;
        vrsta=v;
        vrstat=tv;
    }

    Truba(const Truba &t)
    {
        cena=t.cena;
        ocena=t.ocena;
        proizvodjac=t.proizvodjac;
        vrsta=t.vrsta;
        vrstat=t.vrstat;
    }

    int getTrubaID()const;
    string getTruba()const
    {
        switch(vrstat)
        {
        case altTruba:
            return "Alt";
            break;
        case basTruba:
            return "Bas";
            break;
        case visokaTruba:
            return "Visoka";
            break;
        }
    }
    void setTruba(trubaVrsta tv)
    {
        vrstat=tv;
    }

    void ispisTruba()
    {
        cout<<"ID: "<<getTrubaID()<<endl;
        ispisDuvackogInstrumenta();
        cout<<"Vrsta trube :"<<getTruba()<<endl;
    }

    void unosTruba()
    {
        int br;
        cout<<"ID: ";
        cin>>trubaID;
        fflush(stdin);
        unosDuvackogInstrumenta();
        cout<<"Vrsta trube[1-Alt/2-Bas/3-Visoka]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrstat = altTruba;
            break;
        case 2:
            vrstat = basTruba;
            break;
        case 3:
            vrstat = visokaTruba;
            break;
        }
    }
};

int Truba::getTrubaID()const
{
    return trubaID;
}

void dodajUFajlTruba()
{
    Truba t;
    ofstream outFile;
    outFile.open("TRUBA.dat",ios::binary|ios::app);
    t.unosTruba();
    outFile.write(reinterpret_cast<char *> (&t), sizeof(Truba));
    outFile.close();
    cout<<"\n\nTruba dodata u fajl!";
    cin.ignore();
    cin.get();
}
void ispisiFajlTruba()
{
    Truba t;
    ifstream inFile;
    inFile.open("TRUBA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVE TRUBE U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&t), sizeof(Truba)))
    {
        t.ispisTruba();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluTruba(int n)
{
    Truba t;
    ifstream inFile;
    inFile.open("TRUBA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&t), sizeof(Truba)))
    {
        if(t.getTrubaID()==n)
        {
            t.ispisTruba();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nTruba ne postoji!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluTruba(int n)
{
    Truba t;
    ifstream inFile;
    inFile.open("TRUBA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempTruba.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&t), sizeof(Truba)))
    {
        if(t.getTrubaID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&t), sizeof(Truba));
        }
    }
    outFile.close();
    inFile.close();
    remove("TRUBA.dat");
    rename("TempTruba.dat","TRUBA.dat");
    cout<<"\n\n\tTruba obrisana!";
    cin.ignore();
    cin.get();
}
///////////////////////////////////////////////////////////////////////
class Tuba: public DuvackiInstrument
{
private:
    tubaVrsta vrstat;
public:

    int tubaID;

    Tuba()
    {
        cena=1500.00;
        ocena=8.75;
        proizvodjac=fender;
        vrsta=limeni;
        vrstat=kontrabasTuba;
    }

    Tuba(float c, float o,proizvodjaci p, duvackiVrsta v, tubaVrsta tv)
    {
        cena=c;
        ocena=o;
        proizvodjac=p;
        vrsta=v;
        vrstat=tv;
    }

    Tuba(const Tuba &t)
    {
        cena=t.cena;
        ocena=t.ocena;
        proizvodjac=t.proizvodjac;
        vrsta=t.vrsta;
        vrstat=t.vrstat;
    }

    int getTubaID()const;
    string getTuba()const
    {
        switch(vrstat)
        {
        case basTuba:
            return "Bas";
            break;
        case kontrabasTuba:
            return "Kontrabas";
            break;
        case subKontrabasTuba:
            return "Sub kontrabas";
            break;
        case tenorTuba:
            return "Tenor";
            break;
        }
    }
    void setTuba(tubaVrsta tv)
    {
        vrstat=tv;
    }

    void ispisTube()
    {
        cout<<"ID: "<<getTubaID()<<endl;
        ispisDuvackogInstrumenta();
        cout<<"Vrsta tube :"<<getTuba()<<endl;
    }

    void unosTube()
    {
        int br;
        cout<<"ID: ";
        cin>>tubaID;
        fflush(stdin);
        unosDuvackogInstrumenta();
        cout<<"Vrsta tube[1-Bas/2-Kontrabas/3-Sub kontrabas/4-Tenor]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrstat = basTuba;
            break;
        case 2:
            vrstat = kontrabasTuba;
            break;
        case 3:
            vrstat = subKontrabasTuba;
            break;
        case 4:
            vrstat = tenorTuba;
            break;
        }
    }
};

int Tuba::getTubaID()const
{
    return tubaID;
}

void dodajUFajlTuba()
{
    Tuba t;
    ofstream outFile;
    outFile.open("TUBA.dat",ios::binary|ios::app);
    t.unosTube();
    outFile.write(reinterpret_cast<char *> (&t), sizeof(Tuba));
    outFile.close();
    cout<<"\n\nTuba dodata u fajl!";
    cin.ignore();
    cin.get();
}
void ispisiFajlTuba()
{
    Tuba t;
    ifstream inFile;
    inFile.open("TUBA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVE TUBE U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&t), sizeof(Tuba)))
    {
        t.ispisTube();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluTuba(int n)
{
    Tuba t;
    ifstream inFile;
    inFile.open("TUBA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&t), sizeof(Tuba)))
    {
        if(t.getTubaID()==n)
        {
            t.ispisTube();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nTuba ne postoji!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluTuba(int n)
{
    Tuba t;
    ifstream inFile;
    inFile.open("TUBA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempTuba.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&t), sizeof(Tuba)))
    {
        if(t.getTubaID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&t), sizeof(Tuba));
        }
    }
    outFile.close();
    inFile.close();
    remove("TUBA.dat");
    rename("TempTuba.dat","TUBA.dat");
    cout<<"\n\n\tTuba obrisana!";
    cin.ignore();
    cin.get();
}
////////////////////////////////////////////////////////////
class Ukulele : public ZicaniInstrument
{
private:
    ukuleleVrsta vrstaUkulelea;
public:

    int ukuleleID;

    Ukulele()
    {
        cena = 2000.00;
        ocena = 10.0;
        proizvodjac = taylor;
        brojZica = 4;
        duzinaZice = 0.30;
        vrstaZica = najlon;
        vrstaUkulelea = standard;
    }
    Ukulele(float cc, float oo, proizvodjaci pp, int broj, float duzina, zicaVrsta vrs, ukuleleVrsta uku)
    {
        cena = cc;
        ocena = oo;
        proizvodjac = pp;
        brojZica = broj;
        duzinaZice = duzina;
        vrstaZica = vrs;
        vrstaUkulelea = uku;
    }
    Ukulele(const Ukulele &u)
    {
        cena = u.cena;
        ocena = u.ocena;
        proizvodjac = u.proizvodjac;
        brojZica = u.brojZica;
        duzinaZice = u.duzinaZice;
        vrstaZica = u.vrstaZica;
        vrstaUkulelea = u.vrstaUkulelea;
    }

    void setVrstaUkulelea(ukuleleVrsta vrs)
    {
        vrstaUkulelea = vrs;
    }

    int getUkuleleID()const;
    string getVrstaUkulelea()const
    {
        switch(vrstaUkulelea)
        {
        case standard:
            return "STANDARD";
            break;
        case koncert:
            return "KONCERT";
            break;
        case tenor:
            return "TENOR";
            break;
        case bariton:
            return "BARITON";
            break;
        default:
            return "Nema vrste ukulelea";
            break;
        }
    }

    void ispisUkulelea()
    {
        cout<<"ID: "<<getUkuleleID()<<endl;
        ispisZicanogInstrumenta();
        cout<<"Vrsta ukulelea: "<<getVrstaUkulelea()<<endl;
    }

    void unosUkulelea()
    {
        int br;
        cout<<"ID: ";
        cin>>ukuleleID;
        fflush(stdin);
        unosZicanogInstrumenta();
        cout<<"Vrsta ukulelea[1-Bariton/2-Koncert/3-Standard/4-Tenor]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrstaUkulelea = bariton;
            break;
        case 2:
            vrstaUkulelea = koncert;
            break;
        case 3:
            vrstaUkulelea = standard;
            break;
        case 4:
            vrstaUkulelea = tenor;
            break;
        }
    }
};

int Ukulele::getUkuleleID()const
{
    return ukuleleID;
}

void dodajUFajlUkulele()
{
    Ukulele u;
    ofstream outFile;
    outFile.open("UKULELE.dat",ios::binary|ios::app);
    u.unosUkulelea();
    outFile.write(reinterpret_cast<char *> (&u), sizeof(Ukulele));
    outFile.close();
    cout<<"\n\nUkulele dodato u fajl!";
    cin.ignore();
    cin.get();
}
void ispisiFajlUkulele()
{
    Ukulele u;
    ifstream inFile;
    inFile.open("UKULELE.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVI UKULELEI U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&u), sizeof(Ukulele)))
    {
        u.ispisUkulelea();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluUkulele(int n)
{
    Ukulele u;
    ifstream inFile;
    inFile.open("UKULELE.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&u), sizeof(Ukulele)))
    {
        if(u.getUkuleleID()==n)
        {
            u.ispisUkulelea();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nUkulele ne postoji!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluUkulele(int n)
{
    Ukulele u;
    ifstream inFile;
    inFile.open("UKULELE.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempUkulele.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&u), sizeof(Ukulele)))
    {
        if(u.getUkuleleID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&u), sizeof(Ukulele));
        }
    }
    outFile.close();
    inFile.close();
    remove("UKULELE.dat");
    rename("TempUkulele.dat","UKULELE.dat");
    cout<<"\n\n\tUkelele obrisano!";
    cin.ignore();
    cin.get();
}
///////////////////////////////////////////////////////////////////////////////////////
class Viola : GudackiInstrument
{
private:
    violaVrsta vrsta;
    char velicina[20];
public:

    int violaID;

    Viola() : GudackiInstrument()
    {
        vrsta = akusticnaViola;
    }
    Viola(violaVrsta violaType,tipGudala tipG, int brojZ, zicaVrsta typeOfString, bool electric,float c, float o, proizvodjaci pp)
        : GudackiInstrument(tipG, brojZ,electric, c,o,pp)
    {
        vrsta = violaType;
    }
    Viola(const Viola &v) : GudackiInstrument((GudackiInstrument)v)
    {
        vrsta = v.vrsta;
    }

    int getViolaID()const;
    string getViolaVrsta () const
    {
        switch(vrsta)
        {
        case akusticnaViola:
            return "Akusticna";
            break;
        case elektricnaViola:
            return "Elektricna";
            break;
        case elektricnoAkusticnaViola:
            return "Elektricno akusticna";
            break;
        }
    }
    const char* getVelicina () const
    {
        return velicina;
    }

    void setViolaVrsta (violaVrsta v)
    {
        vrsta = v;
    }

    void ispisViole()
    {
        cout<<"ID: "<<getViolaID()<<endl;
        ispisGudackogInstrumenta();
        cout<<"Vrsta viole: "<<getViolaVrsta()<<endl;
        cout<<"Velicina: "<<getVelicina()<<endl;
    }

    void unosViole()
    {
        int br;
        cout<<"ID: ";
        cin>>violaID;
        fflush(stdin);
        unosGudackogInstrumenta();
        cout<<"Vrsta viole[1-Akusticna/2-Elektricna/3-Elektricno akusticna]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrsta = akusticnaViola;
            break;
        case 2:
            vrsta = elektricnaViola;
            break;
        case 3:
            vrsta = elektricnoAkusticnaViola;
            break;
        }
        cout<<"Velicina: ";
        cin>>velicina;
        fflush(stdin);
    }
};
int Viola::getViolaID()const
{
    return violaID;
}

void dodajUFajlViola()
{
    Viola v;
    ofstream outFile;
    outFile.open("VIOLA.dat",ios::binary|ios::app);
    v.unosViole();
    outFile.write(reinterpret_cast<char *> (&v), sizeof(Viola));
    outFile.close();
    cout<<"\n\nViola dodata u fajl!";
    cin.ignore();
    cin.get();
}
void ispisiFajlViola()
{
    Viola v;
    ifstream inFile;
    inFile.open("VIOLA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVE VIOLE U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&v), sizeof(Viola)))
    {
        v.ispisViole();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluViola(int n)
{
    Viola v;
    ifstream inFile;
    inFile.open("VIOLA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&v), sizeof(Viola)))
    {
        if(v.getViolaID()==n)
        {
            v.ispisViole();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nViola ne postoji!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluViola(int n)
{
    Viola v;
    ifstream inFile;
    inFile.open("VIOLA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempViola.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&v), sizeof(Viola)))
    {
        if(v.getViolaID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&v), sizeof(Viola));
        }
    }
    outFile.close();
    inFile.close();
    remove("VIOLA.dat");
    rename("TempViola.dat","VIOLA.dat");
    cout<<"\n\n\tViola obrisana!";
    cin.ignore();
    cin.get();
}
////////////////////////////////////////////////////////////////////////////////////
class Violina : GudackiInstrument
{
private:
    violinaVrsta vrstav;
    char velicina[20];
public:

    int violinaID;

    Violina() : GudackiInstrument()
    {
        vrstav = klasicnaViolina;
    }
    Violina(violinaVrsta violinaType,tipGudala tipG, int brojZ, zicaVrsta typeOfString, bool electric, float c, float o, proizvodjaci pp)
        : GudackiInstrument( tipG, brojZ,electric, c,o,pp)
    {
        vrstav = violinaType;
    }
    Violina(const Violina &v) : GudackiInstrument((GudackiInstrument)v)
    {
        vrstav = v.vrstav;
    }

    int getViolinaID()const;
    string getViolinaVrsta () const
    {
        switch(vrstav)
        {
        case baroknaViolina:
            return "Barokna";
            break;
        case elektricnaViolina:
            return "Elektricna";
            break;
        case klasicnaViolina:
            return "Klasicna";
            break;
        case poluelektricnaViolina:
            return "Polu elektricna";
            break;
        case strohViolina:
            return "Stroh";
            break;
        }
    }
    const char* getVelicina () const
    {
        return velicina;
    }

    void setViolinaVrsta (violinaVrsta v)
    {
        vrstav = v;
    }

    void ispisVioline()
    {
        cout<<"ID: "<<getViolinaID()<<endl;
        ispisGudackogInstrumenta();
        cout<<"Vrsta violine: "<<getViolinaVrsta()<<endl;
        cout<<"Velicina: "<<getVelicina()<<endl;
    }

    void unosVioline()
    {
        int br;
        cout<<"ID: ";
        cin>>violinaID;
        fflush(stdin);
        unosGudackogInstrumenta();
        cout<<"Vrsta violine[1-Barokna/2-Elektricna/3-Klasicna/4-Polu elektricna/5-Stroh]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrstav = baroknaViolina;
            break;
        case 2:
            vrstav = elektricnaViolina;
            break;
        case 3:
            vrstav = klasicnaViolina;
            break;
        case 4:
            vrstav = poluelektricnaViolina;
            break;
        case 5:
            vrstav = strohViolina;
            break;
        }
        cout<<"Velicina: ";
        cin>>velicina;
        fflush(stdin);
    }
};

int Violina::getViolinaID()const
{
    return violinaID;
}

void dodajUFajlViolina()
{
    Violina v;
    ofstream outFile;
    outFile.open("VIOLINA.dat",ios::binary|ios::app);
    v.unosVioline();
    outFile.write(reinterpret_cast<char *> (&v), sizeof(Violina));
    outFile.close();
    cout<<"\n\nViolina dodata u fajl!";
    cin.ignore();
    cin.get();
}
void ispisiFajlViolina()
{
    Violina v;
    ifstream inFile;
    inFile.open("VIOLINA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVE VIOLINE U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&v), sizeof(Violina)))
    {
        v.ispisVioline();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluViolina(int n)
{
    Violina v;
    ifstream inFile;
    inFile.open("VIOLINA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&v), sizeof(Violina)))
    {
        if(v.getViolinaID()==n)
        {
            v.ispisVioline();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nViolina ne postoji!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluViolina(int n)
{
    Violina v;
    ifstream inFile;
    inFile.open("VIOLINA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempViolina.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&v), sizeof(Violina)))
    {
        if(v.getViolinaID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&v), sizeof(Violina));
        }
    }
    outFile.close();
    inFile.close();
    remove("VIOLINA.dat");
    rename("TempViolina.dat","VIOLINA.dat");
    cout<<"\n\nViolina obrisana!";
    cin.ignore();
    cin.get();
}

///////////////////////////////////////////////////////////////////////////////////
class Violoncelo : GudackiInstrument
{
private:
    violonceloVrsta vrstav;
    char velicina[20];
public:

    int violonceloID;

    Violoncelo() : GudackiInstrument()
    {
        vrstav = carbonFiberVioloncelo;
    }
    Violoncelo(violonceloVrsta violonceloType,tipGudala tipG, int brojZ, zicaVrsta typeOfString, bool electric, float c, float o, proizvodjaci pp)
        : GudackiInstrument( tipG, brojZ,electric, c,o,pp)
    {
        vrstav = violonceloType;
    }
    Violoncelo(const Violoncelo &v) : GudackiInstrument((GudackiInstrument)v)
    {
        vrstav = v.vrstav;
    }

    int getViolonceloID()const;
    string getViolonceloVrsta () const
    {
        switch(vrstav)
        {
        case akusticnoVioloncelo:
            return "Akusticno";
            break;
        case carbonFiberVioloncelo:
            return "Carbon fiber";
            break;
        case elektricnoVioloncelo:
            return "Violoncelo";
            break;
        case fullSizeVioloncelo:
            return "Full size";
            break;
        case raznaVioloncela:
            return "Razno";
            break;
        }
    }
    const char* getVelicina () const
    {
        return velicina;
    }

    void setViolonceloVrsta (violonceloVrsta v)
    {
        vrstav = v;
    }


    void ispisVioloncela()
    {
        cout<<"ID: "<<getViolonceloID()<<endl;
        ispisGudackogInstrumenta();
        cout<<"Vrsta violoncela: "<<getViolonceloVrsta()<<endl;
        cout<<"Velicina: "<<getVelicina()<<endl;
    }

    void unosVioloncela()
    {
        int br;
        cout<<"ID: ";
        cin>>violonceloID;
        fflush(stdin);
        unosGudackogInstrumenta();
        cout<<"Vrsta violoncela[1-Akusticno/2-Carbon fiber/3-Elektricno/4-Full size/5-Razna]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrstav = akusticnoVioloncelo;
            break;
        case 2:
            vrstav = carbonFiberVioloncelo;
            break;
        case 3:
            vrstav = elektricnoVioloncelo;
            break;
        case 4:
            vrstav  = fullSizeVioloncelo;
            break;
        case 5:
            vrstav = raznaVioloncela;
            break;
        }
        cout<<"Velicina: ";
        cin>>velicina;
        fflush(stdin);
    }
};

int Violoncelo::getViolonceloID()const
{
    return violonceloID;
}

void dodajUFajlVioloncelo()
{
    Violoncelo v;
    ofstream outFile;
    outFile.open("VIOLONCELO.dat",ios::binary|ios::app);
    v.unosVioloncela();
    outFile.write(reinterpret_cast<char *> (&v), sizeof(Violoncelo));
    outFile.close();
    cout<<"\n\nVioloncelo dodato u fajl!";
    cin.ignore();
    cin.get();
}
void ispisiFajlVioloncelo()
{
    Violoncelo v;
    ifstream inFile;
    inFile.open("VIOLONCELO.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVA VIOLONCELA U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&v), sizeof(Violoncelo)))
    {
        v.ispisVioloncela();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluVioloncelo(int n)
{
    Violoncelo v;
    ifstream inFile;
    inFile.open("VIOLONCELO.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&v), sizeof(Violoncelo)))
    {
        if(v.getViolonceloID()==n)
        {
            v.ispisVioloncela();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nVioloncelo ne postoji!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluVioloncelo(int n)
{
    Violoncelo v;
    ifstream inFile;
    inFile.open("VIOLONCELO.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempVioloncelo.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&v), sizeof(Violoncelo)))
    {
        if(v.getViolonceloID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&v), sizeof(Violoncelo));
        }
    }
    outFile.close();
    inFile.close();
    remove("VIOLONCELO.dat");
    rename("TempVioloncelo.dat","VIOLONCELO.dat");
    cout<<"\n\n\tVioloncelo obrisano!";
    cin.ignore();
    cin.get();
}
//////////////////////////////////////////////////////////////////
class Zanr
{
protected:
    tipMuzike tip;
    zanrovi vrsta;
public:
    Zanr()
    {
        tip = vokalnoInstrumentalna;
        vrsta = hiphop;
    }

    Zanr(tipMuzike TIP, zanrovi VRSTA)
    {
        tip = TIP;
        vrsta = VRSTA;
    }

    Zanr(const Zanr &z)
    {
        tip = z.tip;
        vrsta = z.vrsta;
    }

    string getTip()const
    {
        switch(tip)
        {
        case vokalna:
            return "Vokalna";
            break;
        case instrumentalna:
            return "Instrumentalna";
            break;
        case vokalnoInstrumentalna:
            return "Vokalno instrumentalna";
            break;
        }
    }
    string getVrsta()const
    {
        switch(vrsta)
        {
        case alternative:
            return "Alternative";
            break;
        case bluz:
            return "Bluz";
            break;
        case dens:
            return "Dens";
            break;
        case dzez:
            return "Dzez";
            break;
        case hiphop:
            return "Hip hop";
            break;
        case kantri:
            return "Kantri";
            break;
        case klasicna:
            return "Klasicna";
            break;
        case metal:
            return "Metal";
            break;
        case pop:
            return "Pop";
            break;
        case rege:
            return "Rege";
            break;
        case rok:
            return "Rok";
            break;
        }
    }

    void setTip()
    {
        int br;
        cout<<"Tip muzike [1-Vokalna/2-Instrumentalna/3-Vokalno instrumentalna]: "<<endl;
        cin>>br;

        switch(br)
        {
        case 1:
            tip = vokalna;
            break;
        case 2:
            tip = instrumentalna;
            break;
        case 3:
            tip = vokalnoInstrumentalna;
            break;
        }
    }

    void setVrsta()
    {
        int br;
        cout<<"Zanr [1-Alternative/2-Bluz/3-Dens/4-Dzez/5-Hiphop/6-Kantri/7-Klasicna/8-Metal/9-Pop/10-Rege/11-Rok]: "<<endl;
        cin>>br;

        switch(br)
        {
        case 1:
            vrsta = alternative;
            break;
        case 2:
            vrsta = bluz;
            break;
        case 3:
            vrsta = dens;
            break;
        case 4:
            vrsta = dzez;
            break;
        case 5:
            vrsta = hiphop;
            break;
        case 6:
            vrsta = kantri;
            break;
        case 7:
            vrsta = klasicna;
            break;
        case 8:
            vrsta = metal;
            break;
        case 9:
            vrsta = pop;
            break;
        case 10:
            vrsta = rege;
            break;
        case 11:
            vrsta = rok;
            break;
        }
    }

    void ispisiZanr()
    {
        cout<<"Tip: "<<getTip()<<endl;
        cout<<"Vrsta: "<<getVrsta()<<endl;
    }

    void unesiZanr()
    {
        setTip();
        setVrsta();
    }
};
//////////////////////////////////////////////////////////////////////////////////////
class Zaposlen : public Osoba
{
private:
    float plata;
    int satiRada;

public:
    Zaposlen() : Osoba()
    {
        plata = 50000.00;
        satiRada = 8;
    }

    Zaposlen(float PL, int SR, string I, string P, int G) : Osoba(I,P,G)
    {
        plata = PL;
        satiRada = SR;
    }

    Zaposlen(const Zaposlen &z) : Osoba((Osoba)z)
    {
        plata = z.plata;
        satiRada = z.satiRada;
    }

    float getPlata()const
    {
        return plata;
    }
    int getSatiRada()const
    {
        return satiRada;
    }

    void setPlata(float PLATA)
    {
        plata = PLATA;
    }
    void setSatiRada(int SATIRADA)
    {
        satiRada = SATIRADA;
    }

    void ispisiZaposlenog()
    {
        Osoba::ispisiOsobu();
        cout<<"Plata: "<<getPlata()<<"din"<<endl;
        cout<<"Sati rada: "<<getSatiRada()<<endl;
    }

    void unesiZaposlenog()
    {
        Osoba::unesiOsobu();
        cout<<"Plata: ";
        cin>>plata;
        cout<<"Sati rada: ";
        cin>>satiRada;
    }

};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZvucnaKartica : Proizvod
{
private:
    zvucnaKarticaVrsta vrsta;
public:

    int zvucnaKarticaID;

    ZvucnaKartica() : Proizvod()
    {
        vrsta = usb;
    }
    ZvucnaKartica(zvucnaKarticaVrsta v, float c, float o, proizvodjaci pp) : Proizvod(c,o,pp)
    {
        vrsta = v;
    }

    ZvucnaKartica(const ZvucnaKartica &z) : Proizvod((Proizvod)z)
    {
        vrsta = z.vrsta;
    }

    int getZvucnaKarticaID()const;
    void setVrsta(zvucnaKarticaVrsta VRSTA)
    {
        vrsta = VRSTA;
    }
    string getVrsta()
    {
        switch(vrsta)
        {
        case usb:
            return "USB";
            break;
        case firewire:
            return "Firewire";
            break;
        case thunderbolt:
            return "Thunderbolt";
            break;
        }
    }

    void ispisiZvucnuKarticu()
    {
        cout<<"ID: "<<getZvucnaKarticaID()<<endl;
        ispisProizvoda();
        cout<<"Vrsta: "<<getVrsta()<<endl;
    }

    void unesiZvucnuKarticu()
    {
        int br;
        cout<<"ID: ";
        cin>>zvucnaKarticaID;
        fflush(stdin);
        unosProizvoda();
        cout<<"Vrsta [1-Firewire/2-Thunderbolt/3-USB]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrsta = firewire;
            break;
        case 2:
            vrsta = thunderbolt;
            break;
        case 3:
            vrsta = usb;
        }
    }

};

int ZvucnaKartica::getZvucnaKarticaID()const
{
    return zvucnaKarticaID;
}

void dodajUFajlZvucnaKartica()
{
    ZvucnaKartica z;
    ofstream outFile;
    outFile.open("ZVUCNAKARTICA.dat",ios::binary|ios::app);
    z.unesiZvucnuKarticu();
    outFile.write(reinterpret_cast<char *> (&z), sizeof(ZvucnaKartica));
    outFile.close();
    cout<<"\n\nZvucna kartica dodata u fajl!";
    cin.ignore();
    cin.get();
}

void ispisiFajlZvucnaKartica()
{
    ZvucnaKartica z;
    ifstream inFile;
    inFile.open("ZVUCNAKARTICA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVE ZVUCNE KARTICE U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&z), sizeof(ZvucnaKartica)))
    {
        z.ispisiZvucnuKarticu();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluZvucnaKartica(int n)
{
    ZvucnaKartica z;
    ifstream inFile;
    inFile.open("ZVUCNAKARTICA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&z), sizeof(ZvucnaKartica)))
    {
        if(z.getZvucnaKarticaID()==n)
        {
            z.ispisiZvucnuKarticu();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nZvucna kartica ne postoji!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluZvucnaKartica(int n)
{
    ZvucnaKartica z;
    ifstream inFile;
    inFile.open("ZVUCNAKARTICA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempZvucnaKartica.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&z), sizeof(ZvucnaKartica)))
    {
        if(z.getZvucnaKarticaID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&z), sizeof(ZvucnaKartica));
        }
    }
    outFile.close();
    inFile.close();
    remove("ZVUCNAKARTICA.dat");
    rename("TempZvucnaKartica.dat","ZVUCNAKARTICA.dat");
    cout<<"\n\n\tZvucna kartica obrisana!";
    cin.ignore();
    cin.get();
}
/////////////////////////////////////////////////////////////
class ZvucnaKutija : public Proizvod
{
private:
    zvucnaKutijaVrsta vrsta;
public:

    int zvucnaKutijaID;

    ZvucnaKutija() : Proizvod()
    {
        vrsta = aktivna;
    }

    ZvucnaKutija(zvucnaKutijaVrsta v, float c, float o, proizvodjaci pp) : Proizvod( c,o,pp)
    {
        vrsta = v;
    }

    ZvucnaKutija(const ZvucnaKutija &zk) : Proizvod((Proizvod)zk)
    {
        vrsta = zk.vrsta;
    }

    int getZvucnaKutijaID()const;
    void setVrsta(zvucnaKutijaVrsta VRSTA)
    {
        vrsta = VRSTA;
    }
    string getVrsta()
    {
        switch(vrsta)
        {
        case aktivna:
            return "Aktivna";
            break;
        case pasivna:
            return "Pasivna";
            break;
        case subwoofer:
            return "Subwoofer";
            break;
        }
    }

    void ispisiZvucnuKutiju()
    {
        cout<<"ID: "<<getZvucnaKutijaID()<<endl;
        ispisProizvoda();
        cout<<"Vrsta: "<<getVrsta()<<endl;
    }

    void unesiZvucnuKutiju()
    {
        int br;
        cout<<"ID: ";
        cin>>zvucnaKutijaID;
        fflush(stdin);
        unosProizvoda();
        cout<<"Vrsta [1-Aktivna/2-Pasivna/3-Subwoofer]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrsta = aktivna;
            break;
        case 2:
            vrsta = pasivna;
            break;
        case 3:
            vrsta = subwoofer;
            break;
        }
    }

};

int ZvucnaKutija::getZvucnaKutijaID()const
{
    return zvucnaKutijaID;
}

void dodajUFajlZvucnaKutija()
{
    ZvucnaKutija z;
    ofstream outFile;
    outFile.open("ZVUCNAKUTIJA.dat",ios::binary|ios::app);
    z.unesiZvucnuKutiju();
    outFile.write(reinterpret_cast<char *> (&z), sizeof(ZvucnaKutija));
    outFile.close();
    cout<<"\n\nZvucna kutija dodata u fajl!";
    cin.ignore();
    cin.get();
}

void ispisiFajlZvucnaKutija()
{
    ZvucnaKutija z;
    ifstream inFile;
    inFile.open("ZVUCNAKUTIJA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVE ZVUCNE KUTIJE U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&z), sizeof(ZvucnaKutija)))
    {
        z.ispisiZvucnuKutiju();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluZvucnaKutija(int n)
{
    ZvucnaKutija z;
    ifstream inFile;
    inFile.open("ZVUCNAKUTIJA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&z), sizeof(ZvucnaKutija)))
    {
        if(z.getZvucnaKutijaID()==n)
        {
            z.ispisiZvucnuKutiju();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nZvucna kutija ne postoji!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluZvucnaKutija(int n)
{
    ZvucnaKutija z;
    ifstream inFile;
    inFile.open("ZVUCNAKUTIJA.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempZvucnaKutija.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&z), sizeof(ZvucnaKutija)))
    {
        if(z.getZvucnaKutijaID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&z), sizeof(ZvucnaKutija));
        }
    }
    outFile.close();
    inFile.close();
    remove("ZVUCNAKAUTIJA.dat");
    rename("TempZvucnaKutija.dat","ZVUCNAKUTIJA.dat");
    cout<<"\n\n\tZvucna kutija obrisana!";
    cin.ignore();
    cin.get();
}
//////////////////////////////////////////////////////////////////////
class RazglasniSistemi : public Proizvod
{
private:
    razglasniSistemiVrsta vrsta;
public:

    int razglasniSistemID;

    RazglasniSistemi()
    {
        cena = 0.00;
        ocena = 1;
        proizvodjac = yamaha;
        vrsta = kompaktni;
    }

    RazglasniSistemi(float CENA, float OCENA, proizvodjaci PROIZVODJAC, razglasniSistemiVrsta VRSTA)
    {
        cena = CENA;
        ocena = OCENA;
        proizvodjac = PROIZVODJAC;
        vrsta = VRSTA;
    }

    RazglasniSistemi(const RazglasniSistemi &rs)
    {
        cena = rs.cena;
        ocena = rs.ocena;
        proizvodjac = rs.proizvodjac;
        vrsta = rs.vrsta;
    }

    int getRazglasniSistemID()const;
    string getVrsta()const
    {
        switch(vrsta)
        {
        case profesionalni:
            return "Profesionalni";
            break;
        case kompaktni:
            return "Kompaktni";
            break;
        }
    }

    void setVrsta()
    {
        int br;
        cout<<"Unesite broj [1-Profesionalni/2-Kompaktni]: "<<endl;
        cin>>br;

        switch(br)
        {
        case 1:
            vrsta = profesionalni;
            break;
        case 2:
            vrsta = kompaktni;
            break;
        }
    }

    void ispisiRazglasniSistem()
    {
        cout<<"ID: "<<getRazglasniSistemID()<<endl;
        ispisProizvoda();
        cout<<"Vrsta: "<<getVrsta()<<endl;
    }

    void unesiRazglasniSistem()
    {
        int br;
        cout<<"ID: ";
        cin>>razglasniSistemID;
        fflush(stdin);
        unosProizvoda();
        setVrsta();
    }

};

int RazglasniSistemi::getRazglasniSistemID()const
{
    return razglasniSistemID;
}

void dodajUFajlRazglasniSistemi()
{
    RazglasniSistemi r;
    ofstream outFile;
    outFile.open("RAZGLASNISISTEM.dat",ios::binary|ios::app);
    r.unesiRazglasniSistem();
    outFile.write(reinterpret_cast<char *> (&r), sizeof(RazglasniSistemi));
    outFile.close();
    cout<<"\n\nRazglasni sistem dodat u fajl!";
    cin.ignore();
    cin.get();
}

void ispisiFajlRazglasniSistemi()
{
    RazglasniSistemi r;
    ifstream inFile;
    inFile.open("RAZGLASNISISTEMI.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVI RAZGLASNI SISTEMI U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&r), sizeof(RazglasniSistemi)))
    {
        r.ispisiRazglasniSistem();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluRazglasniSistemi(int n)
{
    RazglasniSistemi r;
    ifstream inFile;
    inFile.open("RAZGLASNISISTEMI.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&r), sizeof(RazglasniSistemi)))
    {
        if(r.getRazglasniSistemID()==n)
        {
            r.ispisiRazglasniSistem();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nRazglasni sistem ne postoji!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluRazglasniSistemi(int n)
{
    RazglasniSistemi r;
    ifstream inFile;
    inFile.open("RAZGLASNISISTEMI.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempRazglasniSistemi.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&r), sizeof(RazglasniSistemi)))
    {
        if(r.getRazglasniSistemID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&r), sizeof(RazglasniSistemi));
        }
    }
    outFile.close();
    inFile.close();
    remove("RAZGLASNISISTEMI.dat");
    rename("TempRazglasniSistemi.dat","RAZGLASNISISTEMI.dat");
    cout<<"\n\n\tRazglasni sistem obrisan!";
    cin.ignore();
    cin.get();
}
//////////////////////////////////////////////////////////////////////

class ZaUcenje : public Proizvod
{
private:
    zaUcenjeVrsta vrsta;
public:

    int zaUcenjeID;

    ZaUcenje()
    {
        cena = 0.00;
        ocena = 1;
        proizvodjac = yamaha;
        vrsta = disk;
    }

    ZaUcenje( float CENA, float OCENA, proizvodjaci PROIZVODJAC, zaUcenjeVrsta VRSTA)
    {
        cena = CENA;
        ocena = OCENA;
        proizvodjac = PROIZVODJAC;
        vrsta = VRSTA;
    }

    ZaUcenje(const ZaUcenje &zu)
    {
        cena = zu.cena;
        ocena = zu.ocena;
        proizvodjac = zu.proizvodjac;
        vrsta = zu.vrsta;
    }

    int getZaUcenjeID()const;
    string getVrsta()const
    {
        switch(vrsta)
        {
        case disk:
            return "Disk";
            break;
        case knjiga:
            return "Knjiga";
            break;
        case notnaSveska:
            return "Notna sveska";
            break;
        }
    }

    void setVrsta()
    {
        int br;
        cout<<"Vrsta [1-Disk/2-Knjiga/3-Notna sveska]: "<<endl;
        cin>>br;

        switch(br)
        {
        case 1:
            vrsta = disk;
            break;
        case 2:
            vrsta = knjiga;
            break;
        case 3:
            vrsta = notnaSveska;
            break;
        }
    }

    void ispisiZaUcenje()
    {
        cout<<"ID: "<<getZaUcenjeID()<<endl;
        ispisProizvoda();
        cout<<"Vrsta: "<<getVrsta()<<endl;
    }

    void unesiZaUcenje()
    {
        int br;
        cout<<"ID: ";
        cin>>zaUcenjeID;
        unosProizvoda();
        setVrsta();
    }
};

int ZaUcenje::getZaUcenjeID()const
{
    return zaUcenjeID;
}

void dodajUFajlZaUcenje()
{
    ZaUcenje z;
    ofstream outFile;
    outFile.open("ZAUCENJE.dat",ios::binary|ios::app);
    z.unesiZaUcenje();
    outFile.write(reinterpret_cast<char *> (&z), sizeof(ZaUcenje));
    outFile.close();
    cout<<"\n\nSredstvo za ucenje dodato u fajl!";
    cin.ignore();
    cin.get();
}

void ispisiFajlZaUcenje()
{
    ZaUcenje z;
    ifstream inFile;
    inFile.open("ZAUCENJE.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tSVA SREDSTVA ZA UCENEJ U FAJLU\n\n";
    while(inFile.read(reinterpret_cast<char *> (&z), sizeof(ZaUcenje)))
    {
        z.ispisiZaUcenje();
        cout<<"\n\n************************************\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void potraziUFajluZaUcenje(int n)
{
    ZaUcenje z;
    ifstream inFile;
    inFile.open("ZAUCENJE.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&z), sizeof(ZaUcenje)))
    {
        if(z.getZaUcenjeID()==n)
        {
            z.ispisiZaUcenje();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nSredstvo za ucenje ne postoji!"<<endl;
    cin.ignore();
    cin.get();
}

void obrisiUFajluZaUcenje(int n)
{
    ZaUcenje z;
    ifstream inFile;
    inFile.open("ZAUCENJE.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Greska! Ne moze se otvoriti fajl!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("TempZaUcenje.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&z), sizeof(ZaUcenje)))
    {
        if(z.getZaUcenjeID()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&z), sizeof(ZaUcenje));
        }
    }
    outFile.close();
    inFile.close();
    remove("ZAUCENJE.dat");
    rename("TempZaUcenje.dat","ZAUCENJE.dat");
    cout<<"\n\n\tSredstvo za ucenje obrisano!";
    cin.ignore();
    cin.get();
}
///////////////////////////////////////////////////////////////////////////////
class Trajanje
{
private:
    int sekunde, minuti, sati;
public:
    Trajanje()
    {
        sekunde = 0;
        minuti = 0;
        sati = 0;
    }

    Trajanje(int s, int m, int h)
    {
        sekunde = s;
        minuti = m;
        sati = h;
    }

    Trajanje(const Trajanje &t)
    {
        sekunde = t.sekunde;
        minuti = t.minuti;
        sati = t.sati;
    }

    int getSekunde()const
    {
        return sekunde;
    }
    int getMinute()const
    {
        return minuti;
    }
    int getSate()const
    {
        return sati;
    }

    void setSekunde(int s)
    {
        sekunde = s;
    }
    void setMinute(int m)
    {
        minuti = m;
    }
    void setSate(int h)
    {
        sati = h;
    }

    void ispisTrajanja()
    {
        cout<<"Sati: "<<getSate()<<endl;
        cout<<"Minuti: "<<getMinute()<<endl;
        cout<<"Sekunde: "<<getSekunde()<<endl;
    }

    void unosTrajanja()
    {
        cout<<"Sati: ";
        cin>>sati;
        cout<<"Minuti: ";
        cin>>minuti;
        cout<<"Sekunde: ";
        cin>>sekunde;
    }
};
/////////////////////////////////////////////////////////////////////////
class Tonalitet
{
private:
    tonalitet key;
    lestvica les;
public:
    Tonalitet()
    {
        key = C;
        les = dur;
    }

    Tonalitet(tonalitet T, lestvica L)
    {
        key = T;
        les = L;
    }

    Tonalitet(const Tonalitet &t)
    {
        key = t.key;
        les = t.les;
    }

    string getKey()const
    {
        switch(key)
        {
        case C:
            return "C";
            break;
        case Csharp:
            return "C#";
            break;
        case D:
            return "D";
            break;
        case Dsharp:
            return "D#";
            break;
        case E:
            return "E";
            break;
        case F:
            return "F";
            break;
        case Fsharp:
            return "F#";
            break;
        case G:
            return "G";
            break;
        case Gsharp:
            return "G#";
            break;
        case A:
            return "A";
            break;
        case Asharp:
            return "A#";
            break;
        case B:
            return "B";
            break;
        }
    }

    string getLestvica()const
    {
        switch(les)
        {
        case dur:
            return "dur";
            break;
        case mol:
            return "mol";
            break;
        }
    }

    void setKey()
    {
        int k;
        cout<<"Key[1-C/2-C#/3-D/4-D#/5-E/6-F/7-F#/8-G/9-G#/10-A/11-A#/12-B]: ";
        cin>>k;
        switch(k)
        {
        case 1:
            key = C;
            break;
        case 2:
            key = Csharp;
            break;
        case 3:
            key = D;
            break;
        case 4:
            key = Dsharp;
            break;
        case 5:
            key = E;
            break;
        case 6:
            key = F;
            break;
        case 7:
            key = Fsharp;
            break;
        case 8:
            key = G;
            break;
        case 9:
            key = Gsharp;
            break;
        case 10:
            key = A;
            break;
        case 11:
            key = Asharp;
            break;
        case 12:
            key = B;
            break;
        }
    }

    void setLestvica()
    {
        int l;
        cout<<"Lestvica[1-dur/2-mol]: ";
        cin>>l;
        switch(l)
        {
        case 1:
            les = dur;
            break;
        case 2:
            les = mol;
            break;
        }
    }

    void unosTonaliteta()
    {
        setKey();
        setLestvica();
    }

    void ispisTonaliteta()
    {
        cout<<"Tonalitet: "<<getKey()<<getLestvica()<<endl;
    }

};
//////////////////////////////////////////////
class Izvodjac
{
private:
    string ime;
    izvodjacVrsta vrsta;
    int godineNaSceni;
public:
    Izvodjac()
    {
        ime = "Nije uneto";
        vrsta = solo;
        godineNaSceni = 0;
    }

    Izvodjac(string IME, izvodjacVrsta VRSTA, int GOD)
    {
        ime = IME;
        vrsta = VRSTA;
        godineNaSceni = GOD;
    }

    Izvodjac(const Izvodjac &i)
    {
        ime = i.ime;
        vrsta = i.vrsta;
        godineNaSceni = i.godineNaSceni;
    }

    void setIme(string IME)
    {
        ime = IME;
    }
    void setVrsta()
    {
        int br;
        cout<<"Vrsta izvodjaca[1-Solo/2-Grupa]: ";
        cin>>br;
        switch(br)
        {
        case 1:
            vrsta = solo;
            break;
        case 2:
            vrsta = grupa;
            break;
        }
    }
    void setGodineNaSceni(int GOD)
    {
        godineNaSceni = GOD;
    }

    string getIme()const
    {
        return ime;
    }
    string getVrsta()const
    {
        switch(vrsta)
        {
        case solo:
            return "Solo";
            break;
        case grupa:
            return "Grupa";
            break;
        }
    }
    int getGodineNaSceni()const
    {
        return godineNaSceni;
    }

    void ispisiIzvodjaca()
    {
        cout<<"Ime: "<<getIme()<<endl;
        cout<<"Vrsta: "<<getVrsta()<<endl;
        cout<<"Godine na sceni: "<<getGodineNaSceni()<<endl;
    }

    void unesiIzvodjaca()
    {
        cout<<"Ime: ";
        cin>>ime;
        setVrsta();
        cout<<"Godine na sceni: ";
        cin>>godineNaSceni;
    }
};
/////////////////////////////////////////////////////////////////////////////
class Pesma
{
private:
    Trajanje trajanje;
    Izvodjac izvodjac;
    string nazivPesme;
    Datum datumIzdavanja;
    Zanr zanr;
    Tonalitet tonalitett;
public:
    Pesma() : trajanje(), izvodjac(), datumIzdavanja(), zanr(), tonalitett()
    {
        nazivPesme = "Nije unet";
    }

    Pesma(string np, int s, int m, int h, string IME, izvodjacVrsta VRSTA, int GOD, int dan, int mesec, int godina,tipMuzike TIP, zanrovi VRST, tonalitet T, lestvica L) : trajanje(s,m,h), izvodjac(IME, VRSTA, GOD), datumIzdavanja(dan,mesec,godina), zanr(TIP, VRST), tonalitett(T,L)
    {
        nazivPesme = np;
    }

    Pesma(const Pesma &p) : trajanje(p.trajanje), izvodjac(p.izvodjac), datumIzdavanja(p.datumIzdavanja), zanr(p.zanr), tonalitett(p.tonalitett)
    {
        nazivPesme = p.nazivPesme;
    }

    void getTrajanje()
    {
        trajanje.Trajanje::ispisTrajanja();
    }
    void getIzvodjac()
    {
        izvodjac.Izvodjac::ispisiIzvodjaca();
    }
    void getDatumIzdavanja()
    {
        datumIzdavanja.Datum::ispisiDatum();
    }
    string getNazivPesme()const
    {
        return nazivPesme;
    }
    void getZanr()
    {
        zanr.Zanr::ispisiZanr();
    }
    void getTonalitet()
    {
        tonalitett.Tonalitet::ispisTonaliteta();
    }


    void setZanr()
    {
        zanr.Zanr::setTip();
        zanr.Zanr::setVrsta();
    }

    void setTonalitet()
    {
        tonalitett.Tonalitet::unosTonaliteta();
    }

    void setTrajanje()
    {
        int n;
        cout<<"Sati: ";
        cin>>n;
        trajanje.Trajanje::setSate(n);
        cout<<"Minuti: ";
        cin>>n;
        trajanje.Trajanje::setMinute(n);
        cout<<"Sekunde: ";
        cin>>n;
        trajanje.Trajanje::setSekunde(n);
    }

    void setIzvodjac()
    {
        int n;
        string s;
        cout<<"Ime: ";
        cin>>s;
        izvodjac.Izvodjac::setIme(s);
        izvodjac.Izvodjac::setVrsta();
        cout<<"Godine na sceni: ";
        cin>>n;
        izvodjac.Izvodjac::setGodineNaSceni(n);
    }

    void setDatumIzdavanja()
    {
        int n;
        cout<<"Dan: ";
        cin>>n;
        datumIzdavanja.Datum::setDan(n);
        cout<<"Mesec: ";
        cin>>n;
        datumIzdavanja.Datum::setMesec(n);
        cout<<"Godine: ";
        cin>>n;
        datumIzdavanja.Datum::setGodina(n);
    }

    void setNazivPesme(string NP)
    {
        nazivPesme = NP;
    }

    void ispisPesme()
    {
        cout<<"Naziv pesme: "<<getNazivPesme()<<endl;
        getTrajanje();
        getIzvodjac();
        getDatumIzdavanja();
    }

    void unosPesme()
    {
        cout<<"Naziv pesme: ";
        cin>>nazivPesme;
        setTrajanje();
        setIzvodjac();
        setDatumIzdavanja();
    }
};
//////////////////////////////////////////////////////////////////////////////////
class PolicaDuvackih
{
private:
    Lista<Tuba> listaTubi;
    Lista<Truba> listaTrubi;
    Lista<Trombon> listaTrombona;
    Lista<Saksofon> listaSaksofona;
    Lista<Oboa> listaOboa;
    Lista<Klarinet> listaKlarineta;
    Lista<Horna> listaHorni;
    Lista<Flauta> listaFlauti;
public:
    void setListaTubi(Lista<Tuba> tb)
    {
        listaTubi = tb;
    }
    void setListaTruba(Lista<Truba> trub)
    {
        listaTrubi = trub;
    }
    void setListaTrombona(Lista<Trombon> trom)
    {
        listaTrombona = trom;
    }
    void setListaSaksofona(Lista<Saksofon> saks)
    {
        listaSaksofona = saks;
    }
    void setListaOboa(Lista<Oboa> ob)
    {
        listaOboa = ob;
    }
    void setListaKlarineta(Lista<Klarinet> klr)
    {
        listaKlarineta = klr;
    }
    void setListaHorni(Lista<Horna> horn)
    {
        listaHorni = horn;
    }
    void setListaFlauta(Lista<Flauta> fla)
    {
        listaFlauti = fla;
    }

    Lista<Tuba> getlistaTubi()const
    {
        return listaTubi;
    }
    Lista<Truba> getlistaTrubi()const
    {
        return listaTrubi;
    }
    Lista<Trombon> getlistaTrombona()const
    {
        return listaTrombona;
    }
    Lista<Saksofon> getlistaSaksofona()const
    {
        return listaSaksofona;
    }
    Lista<Oboa> getlistaOboa()const
    {
        return listaOboa;
    }
    Lista<Klarinet> getlistaKlarineta()const
    {
        return listaKlarineta;
    }
    Lista<Flauta> getlistaFlauti()const
    {
        return listaFlauti;
    }

    PolicaDuvackih& operator+=(Tuba& tub)
    {
        listaTubi.dodajElement(listaTubi.velicina()+1, tub);
        return *this;
    }
    PolicaDuvackih& operator+=(Truba& trub)
    {
        listaTrubi.dodajElement(listaTrubi.velicina()+1, trub);
        return *this;
    }
    PolicaDuvackih& operator+=(Trombon& trom)
    {
        listaTrombona.dodajElement(listaTrombona.velicina()+1, trom);
        return *this;
    }
    PolicaDuvackih& operator+=(Oboa& obo)
    {
        listaOboa.dodajElement(listaOboa.velicina()+1, obo);
        return *this;
    }
    PolicaDuvackih& operator+=(Klarinet& klar)
    {
        listaKlarineta.dodajElement(listaKlarineta.velicina()+1, klar);
        return *this;
    }
    PolicaDuvackih& operator+=(Horna& hor)
    {
        listaHorni.dodajElement(listaHorni.velicina()+1, hor);
        return *this;
    }
    PolicaDuvackih& operator+=(Flauta& flat)
    {
        listaFlauti.dodajElement(listaFlauti.velicina()+1, flat);
        return *this;
    }
    PolicaDuvackih& operator+=(Saksofon& s)
    {
        listaSaksofona.dodajElement(listaSaksofona.velicina()+1, s);
        return *this;
    }

    void ispisTubi()
    {
        if(listaTubi.velicina() == 0)
        {
            cout<<"-->Nema tubi u prodavnici"<<endl;
        }
        else
        {
            Tuba t;
            cout<<"Tube :"<<endl;

            for (int i = 1; i <= listaTubi.velicina(); i++)
            {
                listaTubi.izlistaj(i, t);
                t.ispisTube();
            }
        }
    }
    void ispisTrubaa()
    {
        if(listaTrubi.velicina() == 0)
        {
            cout<<"-->Nema trubi u prodavnici"<<endl;
        }
        else
        {
            Truba r;
            cout<<"Trube :"<<endl;

            for (int i = 1; i <= listaTrubi.velicina(); i++)
            {
                listaTrubi.izlistaj(i, r);
                r.ispisTruba();
            }
        }
    }
    void ispisTrombonaa()
    {
        if(listaTrombona.velicina() == 0)
        {
            cout<<"-->Nema trombona u prodavnici"<<endl;
        }
        else
        {
            Trombon rb;
            cout<<"Tromboni :"<<endl;

            for (int i = 1; i <= listaTrombona.velicina(); i++)
            {
                listaTrombona.izlistaj(i, rb);
                rb.ispisTrombona();
            }
        }
    }
    void ispisSakdofonaa()
    {
        if(listaSaksofona.velicina() == 0)
        {
            cout<<"-->Nema saksofona u prodavnici"<<endl;
        }
        else
        {
            Saksofon s;
            cout<<"Saksofoni :"<<endl;

            for (int i = 1; i <= listaSaksofona.velicina(); i++)
            {
                listaSaksofona.izlistaj(i, s);
                s.ispisSaksofona();
            }
        }
    }
    void ispisOboa()
    {
        if(listaOboa.velicina() == 0)
        {
            cout<<"-->Nema oboa u prodavnici"<<endl;
        }
        else
        {
            Oboa o;
            cout<<"Oboe :"<<endl;

            for (int i = 1; i <= listaOboa.velicina(); i++)
            {
                o.ispisOboe();
            }
        }
    }

    void ispisKlarinetosa()
    {
        if(listaKlarineta.velicina() == 0)
        {
            cout<<"-->Nema klarineta u prodavnici"<<endl;
        }
        else
        {
            Klarinet kk;
            cout<<"Klarineti :"<<endl;

            for (int i = 1; i <= listaKlarineta.velicina(); i++)
            {
                listaKlarineta.izlistaj(i, kk);
                kk.ispisKlarineta();
            }
        }
    }
    void ispisHorni()
    {
        if(listaHorni.velicina() == 0)
        {
            cout<<"-->Nema horni u prodavnici"<<endl;
        }
        else
        {
            Horna h;
            cout<<"Horne :"<<endl;

            for (int i = 1; i <= listaHorni.velicina(); i++)
            {
                listaHorni.izlistaj(i, h);
                h.ispisHorne();
            }
        }
    }
    void ispisFlauta()
    {
        if(listaFlauti.velicina() == 0)
        {
            cout<<"-->Nema flauta u prodavnici"<<endl;
        }
        else
        {
            Flauta f;
            cout<<"Flaute :"<<endl;

            for (int i = 1; i <= listaFlauti.velicina(); i++)
            {
                listaFlauti.izlistaj(i, f);
                f.ispisFlaute();
            }
        }
    }

    void ispisPoliceDuvackihInstrumenata()
    {
        ispisTubi();
        ispisTrubaa();
        ispisTrombonaa();
        ispisSakdofonaa();
        ispisOboa();
        ispisKlarinetosa();
        ispisHorni();
        ispisFlauta();
    }


};
///////////////////////////////////////////////////////////////////////////////////////////////////////
class PolicaGudackih
{
private:
    Lista<Violoncelo> listaVioloncela;
    Lista<Violina> listaViolina;
    Lista<Viola> listaViola;
    Lista<Kontrabas> listaKontrabasa;
public:
    void setListuVioloncela(Lista<Violoncelo> vio)
    {
        listaVioloncela = vio;
    }
    void setListuViolina(Lista<Violina> vil)
    {
        listaViolina = vil;
    }

    void setListuKontrabasa(Lista<Kontrabas> komb)
    {
        listaKontrabasa = komb;
    }

    Lista<Violoncelo> getlistaVioloncela()const
    {
        return listaVioloncela;
    }
    Lista<Violina> getlistaViolina()const
    {
        return listaViolina;
    }
    Lista<Viola> getlistaViola()const
    {
        return listaViola;
    }
    Lista<Kontrabas> getlistaKontrabasa()const
    {
        return listaKontrabasa;
    }

    PolicaGudackih& operator+=(Violoncelo& viol)
    {
        listaVioloncela.dodajElement(listaVioloncela.velicina()+1, viol);
        return *this;
    }
    PolicaGudackih& operator+=(Violina& vi)
    {
        listaViolina.dodajElement(listaViolina.velicina()+1, vi);
        return *this;
    }
    PolicaGudackih& operator+=(Viola& vo)
    {
        listaViola.dodajElement(listaViola.velicina()+1, vo);
        return *this;
    }
    PolicaGudackih& operator+=(Kontrabas& kon)
    {
        listaKontrabasa.dodajElement(listaKontrabasa.velicina()+1, kon);
        return *this;
    }

    void ispisVioloncela()
    {
        if(listaVioloncela.velicina() == 0)
        {
            cout<<"-->Nema violoncela u prodavnici"<<endl;
        }
        else
        {
            Violoncelo vo;
            cout<<"Violoncela :"<<endl;

            for (int i = 1; i <= listaVioloncela.velicina(); i++)
            {
                listaVioloncela.izlistaj(i, vo);
                vo.ispisVioloncela();
            }
        }
    }
    void ispisViolina()
    {
        if(listaViolina.velicina() == 0)
        {
            cout<<"-->Nema violina u prodavnici"<<endl;
        }
        else
        {
            Violina vi;
            cout<<"Violine :"<<endl;

            for (int i = 1; i <= listaViolina.velicina(); i++)
            {
                listaViolina.izlistaj(i, vi);
                vi.ispisVioline();
            }
        }
    }
    void ispisViola()
    {
        if(listaViola.velicina() == 0)
        {
            cout<<"-->Nema viola u prodavnici"<<endl;
        }
        else
        {
            Viola v;
            cout<<"Viole :"<<endl;

            for (int i = 1; i <= listaViola.velicina(); i++)
            {
                listaViola.izlistaj(i, v);
                v.ispisViole();
            }
        }
    }
    void ispisKontrabasova()
    {
        if(listaKontrabasa.velicina() == 0)
        {
            cout<<"-->Nema kontrabasa u prodavnici"<<endl;
        }
        else
        {
            Kontrabas kb;
            cout<<"Kontrabasi :"<<endl;

            for (int i = 1; i <= listaKontrabasa.velicina(); i++)
            {
                listaKontrabasa.izlistaj(i, kb);
                kb.ispisKontrabasa();
            }
        }
    }

    void ispisPoliceGudackihInstrumenataIKlavira()
    {
        ispisVioloncela();
        ispisViolina();
        ispisViola();
        ispisKontrabasova();
    }

};
///////////////////////////////////////////////////////////////////////////////////////////////////////
class PolicaOstalihInstrumenata
{
private:
    Lista<Klavir> listaKlavira;
    Lista<Harmonika> listaHarmonika;
public:
    void setListuKlavira(Lista<Klavir> klav)
    {
        listaKlavira = klav;
    }
    void setListuHarmonika(Lista<Harmonika> har)
    {
        listaHarmonika = har;
    }

    Lista<Klavir> getlistaKlavira()const
    {
        return listaKlavira;
    }
    Lista<Harmonika> getListaHarmonika()const
    {
        return listaHarmonika;
    }

    PolicaOstalihInstrumenata& operator+=(Klavir& k)
    {
        listaKlavira.dodajElement(listaKlavira.velicina()+1, k);
        return *this;
    }
    PolicaOstalihInstrumenata& operator+=(Harmonika& h)
    {
        listaHarmonika.dodajElement(listaHarmonika.velicina()+1, h);
        return *this;
    }

    void ispisKlaviraa()
    {
        if(listaKlavira.velicina() == 0)
        {
            cout<<"-->Nema klavira u prodavnici"<<endl;
        }
        else
        {
            Klavir k;
            cout<<"Klaviri :"<<endl;

            for (int i = 1; i <= listaKlavira.velicina(); i++)
            {
                listaKlavira.izlistaj(i,k);
                k.ispisKlavira();
            }
        }
    }
    void ispisHarmonika()
    {
        if(listaHarmonika.velicina() == 0)
        {
            cout<<"-->Nema harmonika u prodavnici"<<endl;
        }
        else
        {
            Harmonika h;
            cout<<"Harmonike :"<<endl;

            for (int i = 1; i <= listaHarmonika.velicina(); i++)
            {
                listaHarmonika.izlistaj(i,h);
                h.ispisHarmonike();
            }
        }
    }

    void ispisOstalihInstrumenata()
    {
        ispisKlaviraa();
        ispisHarmonika();
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////
class PolicaOpreme
{
private:
    Lista<OpremaZaInstrumente> listaOpremeZaInstrumente;
    Lista<Mikrofon> listaMikrofona;
    Lista<Kontroler> listaKontrolera;
    Lista<DJOprema> listaDjOpreme;
    Lista<Mikser> listaMiksera;
public:
    void setListuOpremeIn(Lista<OpremaZaInstrumente> inst)
    {
        listaOpremeZaInstrumente = inst;
    }
    void setListuMikrofona(Lista<Mikrofon> mikr)
    {
        listaMikrofona = mikr;
    }
    void setListuKontrolera(Lista<Kontroler> kon)
    {
        listaKontrolera = kon;
    }
    void setListuDJOpreme(Lista<DJOprema> dj)
    {
        listaDjOpreme = dj;
    }
    void setListuMiksera(Lista<Mikser> miks)
    {
        listaMiksera = miks;
    }

    Lista<OpremaZaInstrumente> getlistaOpremeIns()const
    {
        return listaOpremeZaInstrumente;
    }
    Lista<Mikrofon> getlistaMikrofona()const
    {
        return listaMikrofona;
    }
    Lista<Kontroler> getlistaKontrolera()const
    {
        return listaKontrolera;
    }
    Lista<DJOprema> getlistaDJOpreme()const
    {
        return listaDjOpreme;
    }
    Lista<Mikser> getlistaMiksera()const
    {
        return listaMiksera;
    }

    PolicaOpreme& operator+=(Mikrofon& m)
    {
        listaMikrofona.dodajElement(listaMikrofona.velicina()+1, m);
        return *this;
    }
    PolicaOpreme& operator+=(OpremaZaInstrumente& opr)
    {
        listaOpremeZaInstrumente.dodajElement(listaOpremeZaInstrumente.velicina()+1, opr);
        return *this;
    }
    PolicaOpreme& operator+=(Kontroler& k)
    {
        listaKontrolera.dodajElement(listaKontrolera.velicina()+1, k);
        return *this;
    }
    PolicaOpreme& operator+=(DJOprema& dj)
    {
        listaDjOpreme.dodajElement(listaDjOpreme.velicina()+1, dj);
        return *this;
    }
    PolicaOpreme& operator+=(Mikser& mik)
    {
        listaMiksera.dodajElement(listaMiksera.velicina()+1, mik);
        return *this;
    }

    void ispisOpremeIn()
    {
        if(listaOpremeZaInstrumente.velicina() == 0)
        {
            cout<<"-->Nema opreme za instrumente u prodavnici"<<endl;
        }
        else
        {
            OpremaZaInstrumente in;
            cout<<"Oprema za instrumente :"<<endl;

            for (int i = 1; i <= listaOpremeZaInstrumente.velicina(); i++)
            {
                listaOpremeZaInstrumente.izlistaj(i, in);
                in.ispisiOpremu();
            }
        }
    }
    void ispisMikrofonaa()
    {
        if(listaMikrofona.velicina() == 0)
        {
            cout<<"-->Nema mikrofona u prodavnici"<<endl;
        }
        else
        {
            Mikrofon mikr;
            cout<<"Mikrofoni :"<<endl;

            for (int i = 1; i <= listaMikrofona.velicina(); i++)
            {
                listaMikrofona.izlistaj(i, mikr);
                mikr.ispisiMikrofon();
            }
        }
    }
    void ispisKontrolerova()
    {
        if(listaKontrolera.velicina() == 0)
        {
            cout<<"-->Nema kontrolera u prodavnici"<<endl;
        }
        else
        {
            Kontroler ko;
            cout<<"Kontroleri :"<<endl;

            for (int i = 1; i <= listaKontrolera.velicina(); i++)
            {
                listaKontrolera.izlistaj(i, ko);
                ko.ispisiKontroler();
            }
        }
    }
    void ispisDjOpreme()
    {
        if(listaDjOpreme.velicina() == 0)
        {
            cout<<"-->Nema DJ opreme u prodavnici"<<endl;
        }
        else
        {
            DJOprema dj;
            cout<<"DJ oprema :"<<endl;

            for (int i = 1; i <= listaDjOpreme.velicina(); i++)
            {
                listaDjOpreme.izlistaj(i, dj);
                dj.ispisiDJOprema();
            }
        }
    }
    void ispisMikserova()
    {
        if(listaMiksera.velicina() == 0)
        {
            cout<<"-->Nema miksera u prodavnici"<<endl;
        }
        else
        {
            Mikser miks;
            cout<<"Mikseri :"<<endl;

            for (int i = 1; i <= listaMiksera.velicina(); i++)
            {
                listaMiksera.izlistaj(i, miks);
                miks.ispisMiksera();
            }
        }
    }

};
///////////////////////////////////////////////////////////////////////////////////////////////////////
class PolicaUdarackih
{
private:
    Lista<Bubanj> listaBubnjeva;
    Lista<Cinele> listaCinela;
    Lista<Daire> listaDaira;
    Lista<Kastanjete> listaKastanjeta;
    Lista<Metalofon> listaMetalofona;
public:
    void setListuBubnjeva(Lista<Bubanj> bb)
    {
        listaBubnjeva = bb;
    }
    void setListuCinela(Lista<Cinele> cc)
    {
        listaCinela = cc;
    }
    void setListuDaira(Lista<Daire> dd)
    {
        listaDaira = dd;
    }
    void setListuKastanjeta(Lista<Kastanjete> kk)
    {
        listaKastanjeta = kk;
    }
    void setListaMetalofona(Lista<Metalofon> mm)
    {
        listaMetalofona = mm;
    }

    Lista<Bubanj> getListuBubnjeva()const
    {
        return listaBubnjeva;
    }
    Lista<Cinele> getListuCinela()const
    {
        return listaCinela;
    }
    Lista<Daire> getListuDaira()const
    {
        return listaDaira;
    }
    Lista<Kastanjete> getListuKastanjeta()const
    {
        return listaKastanjeta;
    }
    Lista<Metalofon> getListuMetalofona()const
    {
        return listaMetalofona;
    }

    PolicaUdarackih& operator+=(Bubanj& bub)
    {
        listaBubnjeva.dodajElement(listaBubnjeva.velicina()+1, bub);
        return *this;
    }
    PolicaUdarackih& operator+=(Cinele& cine)
    {
        listaCinela.dodajElement(listaCinela.velicina()+1, cine);
        return *this;
    }
    PolicaUdarackih& operator+=(Daire& dar)
    {
        listaDaira.dodajElement(listaDaira.velicina()+1, dar);
        return *this;
    }
    PolicaUdarackih& operator+=(Kastanjete& kst)
    {
        listaKastanjeta.dodajElement(listaKastanjeta.velicina()+1, kst);
        return *this;
    }
    PolicaUdarackih& operator+=(Metalofon& met)
    {
        listaMetalofona.dodajElement(listaMetalofona.velicina()+1, met);
        return *this;
    }

    void ispisBubnjeva()
    {
        if(listaBubnjeva.velicina() == 0)
        {
            cout<<"-->Nema bubnjeva u prodavnici"<<endl;
        }
        else
        {
            Bubanj b;
            cout<<"Bubnjevi :"<<endl;

            for (int i = 1; i <= listaBubnjeva.velicina(); i++)
            {
                listaBubnjeva.izlistaj(i, b);
                b.ispisBubnja();
            }
        }
    }
    void ispisCinela()
    {
        if(listaCinela.velicina() == 0)
        {
            cout<<"-->Nema cinela u prodavnici"<<endl;
        }
        else
        {
            Cinele c;
            cout<<"Cinele :"<<endl;

            for (int i = 1; i <= listaCinela.velicina(); i++)
            {
                listaCinela.izlistaj(i, c);
                c.ispisCinela();
            }
        }
    }
    void ispisDaira()
    {
        if(listaDaira.velicina() == 0)
        {
            cout<<"-->Nema daira u prodavnici"<<endl;
        }
        else
        {
            Daire d;
            cout<<"Daire :"<<endl;

            for (int i = 1; i <= listaDaira.velicina(); i++)
            {
                listaDaira.izlistaj(i, d);
                d.ispisDaira();
            }
        }
    }
    void ispisKastanjeta()
    {
        if(listaKastanjeta.velicina() == 0)
        {
            cout<<"-->Nema kastanjeta u prodavnici"<<endl;
        }
        else
        {
            Kastanjete k;
            cout<<"Kastanjete :"<<endl;

            for (int i = 1; i <= listaKastanjeta.velicina(); i++)
            {
                listaKastanjeta.izlistaj(i, k);
                k.ispisKastanjeta();
            }
        }
    }
    void ispisMetalofonaa()
    {
        if(listaMetalofona.velicina() == 0)
        {
            cout<<"-->Nema metalofona u prodavnici"<<endl;
        }
        else
        {
            Metalofon m;
            cout<<"Metalofoni :"<<endl;

            for (int i = 1; i <= listaMetalofona.velicina(); i++)
            {
                listaMetalofona.izlistaj(i, m);
                m.ispisMetalofona();
            }
        }
    }

    void ispisPolicaUdarackihInstrumenata()
    {
        ispisBubnjeva();
        ispisCinela();
        ispisDaira();
        ispisKastanjeta();
        ispisMetalofonaa();
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////
class PolicaZicanih
{
private:
    Lista<Gitara> listaGitara;
    Lista<Harfa> listaHarfi;
    Lista<Ukulele> listaUkulelea;
public:
    void setListuGitara(Lista<Gitara> gg)
    {
        listaGitara = gg;
    }
    void setListuHarfi(Lista<Harfa> hh)
    {
        listaHarfi = hh;
    }
    void setListuUkulelea(Lista<Ukulele> uu)
    {
        listaUkulelea = uu;
    }

    Lista<Gitara> getListuGitara()const
    {
        return listaGitara;
    }
    Lista<Harfa> getListuHarfi()const
    {
        return listaHarfi;
    }
    Lista<Ukulele> getListuUkulelea()const
    {
        return listaUkulelea;
    }

    PolicaZicanih& operator+=(Gitara& git)
    {
        listaGitara.dodajElement(listaGitara.velicina()+1, git);
        return *this;
    }
    PolicaZicanih& operator+=(Harfa& harf)
    {
        listaHarfi.dodajElement(listaHarfi.velicina()+1, harf);
        return *this;
    }
    PolicaZicanih& operator+=(Ukulele& ukul)
    {
        listaUkulelea.dodajElement(listaUkulelea.velicina()+1, ukul);
        return *this;
    }

    void ispisGitara()
    {
        if(listaGitara.velicina() == 0)
        {
            cout<<"-->Nema gitara u prodavnici"<<endl;
        }
        else
        {
            Gitara g;
            cout<<"Gitare :"<<endl;

            for (int i = 1; i <= listaGitara.velicina(); i++)
            {
                listaGitara.izlistaj(i, g);
                g.ispisGitare();
            }
        }
    }
    void ispisHarfi()
    {
        if(listaHarfi.velicina() == 0)
        {
            cout<<"-->Nema harfi u prodavnici"<<endl;
        }
        else
        {
            Harfa h;
            cout<<"Harfe :"<<endl;

            for (int i = 1; i <= listaHarfi.velicina(); i++)
            {
                listaHarfi.izlistaj(i, h);
                h.ispisHarfe();
            }
        }
    }
    void ispisUkulelea()
    {
        if(listaUkulelea.velicina() == 0)
        {
            cout<<"-->Nema ukulelea u prodavnici"<<endl;
        }
        else
        {
            Ukulele u;
            cout<<"Ukulelei :"<<endl;

            for (int i = 1; i <= listaUkulelea.velicina(); i++)
            {
                listaUkulelea.izlistaj(i, u);
                u.ispisUkulelea();
            }
        }
    }

    void ispisPoliceZicanihInstrumenata()
    {
        ispisGitara();
        ispisHarfi();
        ispisUkulelea();
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////
class Tekstopisac : public Osoba
{
private:
    int brojNapisanihPesama;
    int godineIskustva;
public:
    Tekstopisac()
    {
        ime="Aleksandar";
        prezime="Miletic";
        godine=35;
        brojNapisanihPesama=54;
        godineIskustva=11;
    }

    Tekstopisac(string i,string p, int g, int bnp, int gi)
    {
        ime=i;
        prezime=p;
        godine=g;
        brojNapisanihPesama=bnp;
        godineIskustva=gi;
    }

    Tekstopisac(const Tekstopisac &t)
    {
        ime=t.ime;
        prezime=t.prezime;
        godine=t.godine;
        brojNapisanihPesama=t.brojNapisanihPesama;
        godineIskustva=t.godineIskustva;
    }

    void setBrojnapisanihpesama(int bnp)
    {
        brojNapisanihPesama=bnp;
    }
    void setIskustvo(int gi)
    {
        godineIskustva=gi;
    }

    int getBrojnapisanihpesama()
    {
        return brojNapisanihPesama;
    }
    int getIskustvo()
    {
        return godineIskustva;
    }

    void ispisTekstopisca()
    {
        ispisiOsobu();
        cout<<"Broj napisanih pesama :"<<getBrojnapisanihpesama()<<endl;
        cout<<"Broj godina iskustva :"<<getIskustvo()<<endl;

    }

    void unosTekstopisca()
    {
        unesiOsobu();
        cout<<"Unesite broj napisanih pesama :";
        cin>>brojNapisanihPesama;
        fflush(stdin);
        cout<<endl;
        cout<<"Unesite godine iskustva :";
        cin>>godineIskustva;
        fflush(stdin);
        cout<<endl;
    }

};
///////////////////////////////////////////////////////////////////////////////////////////////////////
class Producent : public Osoba
{
private:
    int brojNapravljenihPesama;
    string softver;
public:
    Producent()
    {
        ime="Lazar";
        prezime="Savić";
        godine=45;
        brojNapravljenihPesama=60;
        softver="FL Studio";

    }

    Producent(string i,string p, int g, int bnp, string s)
    {
        ime=i;
        prezime=p;
        godine=g;
        brojNapravljenihPesama=bnp;
        softver=s;
    }

    Producent(const Producent &p)
    {
        ime=p.ime;
        prezime=p.prezime;
        godine=p.godine;
        brojNapravljenihPesama=p.brojNapravljenihPesama;
        softver=p.softver;
    }

    void setBrojnapravljenihpesama(int bnp)
    {
        brojNapravljenihPesama=bnp;
    }
    void setSoftver(string s)
    {
        softver=s;
    }

    int getBrojnapravljenihpesama()
    {
        return brojNapravljenihPesama;
    }
    string getSoftver()
    {
        return softver;
    }

    void ispisProducenta()
    {
        ispisiOsobu();
        cout<<"Broj napravljenih pesama :"<<getBrojnapravljenihpesama()<<endl;
        cout<<"Softver :"<<getSoftver()<<endl;

    }

    void unosProducenta()
    {
        unesiOsobu();
        cout<<"Unesite broj napravljenih pesama :";
        cin>>brojNapravljenihPesama;
        fflush(stdin);
        cout<<endl;
        cout<<"Softver :";
        cin>>softver;
        fflush(stdin);
        cout<<endl;

    }
};


class Album : public Proizvod
{
private:
    char nazivAlbuma[20];
    Lista<Pesma> pesme;
    Lista<Tekstopisac> tekstopisci;
    Lista<Producent> producenti;
    Trajanje trajanje;
    Izvodjac izvodjac;
    Datum datumIzdavanja;
    Zanr zanr;
public:

    int AlbumID;

    void setPesmu(Lista<Pesma> PESMA)
    {
        pesme = PESMA;
    }
    void setTekstopisca(Lista<Tekstopisac> TEKSTOPISAC)
    {
        tekstopisci = TEKSTOPISAC;
    }
    void setProducenta(Lista<Producent> PRODUCENT)
    {
        producenti = PRODUCENT;
    }

    Lista<Pesma> getPesmu()
    {
        return pesme;
    }
    Lista<Tekstopisac> getTekstopisca()
    {
        return tekstopisci;
    }
    Lista<Producent> getProducenta()
    {
        return producenti;
    }

    Album& operator+=(Pesma& p)
    {
        pesme.dodajElement(pesme.velicina()+1, p);
        return *this;
    }
    Album& operator+=(Tekstopisac& t)
    {
        tekstopisci.dodajElement(tekstopisci.velicina()+1, t);
        return *this;
    }
    Album& operator+=(Producent& p)
    {
        producenti.dodajElement(producenti.velicina()+1, p);
        return *this;
    }

    void printPesme()
    {
        if(pesme.velicina() == 0)
        {
            cout<<endl<<"Nema pesama u albumu!"<<endl;
        }
        else
        {
            Pesma p;
            cout<<endl<<"Pesme u albumu :"<<endl;
            for (int i = 1; i <= pesme.velicina(); i++)
            {
                pesme.izlistaj(i, p);
                p.ispisPesme();
            }
        }
    }

    void printTekstopisce()
    {
        if(tekstopisci.velicina() == 0)
        {
            cout<<endl<<"Nema tesktopisaca albuma!"<<endl;
        }
        else
        {
            Tekstopisac t;
            cout<<endl<<"Tekstopisci albuma :"<<endl;
            for (int i = 1; i <= tekstopisci.velicina(); i++)
            {
                tekstopisci.izlistaj(i, t);
                t.ispisTekstopisca();
            }
        }
    }

    void printProducente()
    {
        if(producenti.velicina() == 0)
        {
            cout<<endl<<"Nema producenata albuma!"<<endl;
        }
        else
        {
            Producent p;
            cout<<endl<<"Producenti albuma :"<<endl;
            for (int i = 1; i <= producenti.velicina(); i++)
            {
                producenti.izlistaj(i, p);
                p.ispisProducenta();
            }
        }
    }

    int getAlbumID()const
    {
        return AlbumID;
    }
    const char* getNazivAlbuma()const
    {
        return nazivAlbuma;
    }
    void ispisiAlbum()
    {
        cout<<"ID: "<<getAlbumID()<<endl;
        cout<<"Naziv albuma: "<<getNazivAlbuma()<<endl;
        printPesme();
        printTekstopisce();
        printProducente();
        trajanje.ispisTrajanja();
        izvodjac.ispisiIzvodjaca();
        datumIzdavanja.ispisiDatum();
        zanr.ispisiZanr();
    }

    void unesiAlbum()
    {
        int broj;
        string str;
        cout<<"ID: ";
        cin>>AlbumID;
        fflush(stdin);
        cout<<"Naziv albuma: ";
        cin>>nazivAlbuma;
        fflush(stdin);
        cout<<"Koliko pesama zelite da dodate u album? ";
        cin>>broj;

    }
};
class Kasa
{
private:
    Lista<Proizvod> prodati;
    double trenutnostanje;
    int kp;
public:
    Kasa()
    {
        trenutnostanje=0.00;
        kp=200;
    }
    Kasa(double t,int k)
    {
        trenutnostanje=t;
        kp=k;
    }
    Kasa(const Kasa &k)
    {
        trenutnostanje=k.trenutnostanje;
        kp=k.kp;
    }

    void setKasa(double t)
    {
        trenutnostanje=t;
    }
    double getKasa()
    {
        return trenutnostanje;
    }

    double dodajukasu(Proizvod &p)
    {
        trenutnostanje+=p.getCena();
        return trenutnostanje;
    }

    bool dodajProdato(const Proizvod &p)
    {
        if(prodati.velicina()<kp)
        {
            return prodati.dodajElement(prodati.velicina()+1,p);

        }
        else
            return false;
    }

    void ispisProdatihProizvoda()
    {
        Proizvod p;
        cout<<endl<<"Prodati proizvodi :" << endl;
        cout<<"=============="<<endl;

        for(int i=1; i<=prodati.velicina(); i++)
        {
            cout<<"Proizvod broj "<<i<<":";
            cout<<endl;
            prodati.izlistaj(i,p);
            cout<<"Naziv :"<<p.getNaziv()<<endl;
            cout<<"Cena :"<<p.getCena()<<endl;
            cout<<"Ocena :"<<p.getOcena()<<endl;
            cout<<"Proizvodjac :"<<p.getProizvodjac()<<endl;

        }
        cout<<endl;
    }

    friend ostream& operator<<(ostream& out, const Kasa &k)
    {
        out<<"------KASA------"<<endl<<"Trenutno stanje u kasi :"<<k.trenutnostanje<<endl<<endl;
        return out;
    }

};

class Prodavnica
{
private:
    Lokacija l;
    Lista<Zaposlen> zaposlenii;
    int kz;
public:

    Prodavnica():l(),kz(20) {}
    Prodavnica(string nazivUlice,string grad,string drzava,int brojUlice, int postanskiBroj,int k):l(nazivUlice,grad,drzava,brojUlice,postanskiBroj),kz(k) {}
    Prodavnica(Prodavnica &p):l(p.l),kz(p.kz) {}

    bool dodajZaposlenog(const Zaposlen &z)
    {
        if(zaposlenii.velicina()<kz)
        {
            return zaposlenii.dodajElement(zaposlenii.velicina()+1,z);
        }
        else
            return false;
    }

    void dajOtkaz(const Zaposlen &z,int n)
    {
        zaposlenii.izbrisiElement(n);
    }

    void ispis(Kasa &k)
    {
        Zaposlen z;
        cout<<endl<<"Zaposleni: " << endl;
        cout<<"-------------------"<<endl;

        for(int i=1; i<=zaposlenii.velicina(); i++)
        {
            cout<<"Zaposleni broj "<<i<<":";
            zaposlenii.izlistaj(i,z);
            cout<<"Ime :"<<z.getIme()<<endl<<"Prezime :"<<z.getPrezime()<<endl;
            cout<<"Godine :"<<z.getGodine()<<endl;
            cout<<"Plata :"<<z.getPlata()<<endl;
            cout<<"Sati rada :"<<z.getSatiRada()<<endl;
        }
        cout<<endl;
        cout<<k;
        k.ispisProdatihProizvoda();
    }

};

int meni()
{
    int op;
    cout<<"\t\t\t    Dobrodosli u muzicku prodavnicu! Izaberite opciju."<<endl<<endl;
    cout<<"1. Dodaj informacije o kupcu"<<endl<<endl;
    cout<<"2. Dodaj proizvod u fajl"<<endl<<endl;
    cout<<"3. Pronadji proizvod u fajlu"<<endl<<endl;
    cout<<"4. Obrisi proizvod iz fajla"<<endl<<endl;
    cout<<"5. Ispisi sve proizvode u fajlu"<<endl<<endl;
    cout<<"6. Dopuni policu"<<endl<<endl;
    cout<<"7. Ispisi policu"<<endl<<endl;
    cout<<"8. Izadji iz prodavnice"<<endl<<endl<<">>";
    cin >>op;
    return op;
}

void printProizvodOpcije()
{
    cout<<"ZICANI INSTRUMENTI"<<endl;
    cout<<"1. Gitara"<<endl;
    cout<<"2. Ukulele"<<endl;
    cout<<"3. Harfa"<<endl<<endl;

    cout<<"UDARACKI INSTRUMENTI"<<endl;
    cout<<"4. Metalofon"<<endl;
    cout<<"5. Bubanj"<<endl;
    cout<<"6. Cinele"<<endl;
    cout<<"7. Daire"<<endl;
    cout<<"8. Kastanjete"<<endl<<endl;

    cout<<"DUVACKI INSTRUMENTI"<<endl;
    cout<<"9. Truba"<<endl;
    cout<<"10. Horna"<<endl;
    cout<<"11. Tuba"<<endl;
    cout<<"12. Trombon"<<endl;
    cout<<"13. Klarinet"<<endl;
    cout<<"14. Oboa"<<endl;
    cout<<"15. Saksofon"<<endl;
    cout<<"16. Flauta"<<endl<<endl;

    cout<<"GUDACKI INSTRUMENTI"<<endl;
    cout<<"17. Violina"<<endl;
    cout<<"18. Viola"<<endl;
    cout<<"19. Violoncelo"<<endl;
    cout<<"20. Kontrabas"<<endl<<endl;

    cout<<"OSTALI INSTRUMENTI"<<endl;
    cout<<"21. Klavir"<<endl;
    cout<<"22. Harmonika"<<endl<<endl;

    cout<<"OSTALI PROIZVODI"<<endl;
    cout<<"23. Mikser"<<endl;
    cout<<"24. Zvucna kutija"<<endl;
    cout<<"25. Razglasni sistemi"<<endl;
    cout<<"26. Pojacala"<<endl;
    cout<<"27. Procesori"<<endl;
    cout<<"28. Zvucna kartica"<<endl;
    cout<<"29. Mikseta"<<endl;
    cout<<"30. Slusalice"<<endl;
    cout<<"31. Kontroler"<<endl;
    cout<<"32. Oprema za instrumente"<<endl;
    cout<<"33. Mikrofon"<<endl;
    cout<<"34. DJ oprema"<<endl;
    cout<<"35. Za ucenje"<<endl<<endl;;
}

void printPoliceOpcije()
{
    cout<<"1. Polica duvackih instrumenata"<<endl;
    cout<<"2. Polica udarackih instrumenata"<<endl;
    cout<<"3. Polica zicanih instrumenata"<<endl;
    cout<<"4. Polica gudackih instrumenata"<<endl;
    cout<<"5. Polica ostalih instrumenata"<<endl;
    cout<<"6. Polica muzicke opreme"<<endl;
}

void printDuvackiOpcije()
{
    cout<<"1. Flauta"<<endl;
    cout<<"2. Horna"<<endl;
    cout<<"3. Klarinet"<<endl;
    cout<<"4. Oboa"<<endl;
    cout<<"5. Saksofon"<<endl;
    cout<<"6. Trombon"<<endl;
    cout<<"7. Truba"<<endl;
    cout<<"8. Tuba"<<endl;
}

void printUdarackiOpcije()
{
    cout<<"1. Bubanj"<<endl;
    cout<<"2. Daire"<<endl;
    cout<<"3. Cinele"<<endl;
    cout<<"4. Metalofon"<<endl;
    cout<<"5. Kastanjete"<<endl;
}

void printZicaniOpcije()
{
    cout<<"1. Gitara"<<endl;
    cout<<"2. Ukulele"<<endl;
    cout<<"3. Harfa"<<endl;
}

void printGudackiOpcije()
{
    cout<<"1. Violina"<<endl;
    cout<<"2. Viola"<<endl;
    cout<<"3. Violoncelo"<<endl;
    cout<<"4. Kontrabas"<<endl;
}

void printOstaliOpcije()
{
    cout<<"1. Klavir"<<endl;
    cout<<"2. Harmonika"<<endl;
}

void printOpremaOpcije()
{
    cout<<"1. DJ Oprema"<<endl;
    cout<<"2. Kontroler"<<endl;
    cout<<"3. Mikrofon"<<endl;
    cout<<"4. Mikser"<<endl;
    cout<<"5. Oprema za instrumente"<<endl;
}

int idUnos()
{
    int ID;
    cout<<"Unesite ID proizvoda: ";
    cin>>ID;
    return ID;
}

void loadingScreen()
{
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U Z";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U Z I ";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U Z I C ";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U Z I C K";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U Z I C K A";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U Z I C K A  P";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U Z I C K A  P R";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U Z I C K A  P R O";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U Z I C K A  P R O D";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U Z I C K A  P R O D A";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U Z I C K A  P R O D A V";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U Z I C K A  P R O D A V N";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U Z I C K A  P R O D A V N I";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U Z I C K A  P R O D A V N I C ";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U Z I C K A  P R O D A V N I C A";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(1000);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        Dobrodosli u muzicku prodavnicu! ^_^";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(1000);
    system("cls");
    Sleep(1000);
}

int main()
{
    system("color 57");
    loadingScreen();

    PolicaDuvackih pd;
    PolicaGudackih pg;
    PolicaUdarackih pu;
    PolicaZicanih pz;
    PolicaOstalihInstrumenata poi;
    PolicaOpreme po;

    int op;
    Kupac k;

    do
    {
        Sleep(1000);
        system("cls");
        op=meni();

        switch(op)
        {

        case 1:
        {
            string str;
            unsigned int i;
            float f;
            cout<<endl;
            k.setUnutra(1);
            cout<<"Ime: ";
            cin >> str;
            k.setIme(str);
            cout<<endl<<"Prezime: ";
            cin >> str;
            k.setPrezime(str);
            cout<<endl<<"Godine: ";
            cin >> i;
            k.setGodine(i);
            cout<<endl<<"Da li zelite da Vam ispisemo unete informacije? ";
            cin >> str;
            cout<<endl;
            if(str=="da")
                k.ispisiKupca();
            break;
        }

        case 2:
        {
            cout<<"Koji proizvod zelite da dodate?"<<endl<<endl;
            printProizvodOpcije();
            int opp;
            cout<<">>";
            cin>>opp;

            if(opp==1)
            {
                dodajUFajlGitara();
            }
            else if(opp==2)
            {
                dodajUFajlUkulele();
            }
            else if(opp==3)
            {
                dodajUFajlHarfa();
            }
            else if(opp==4)
            {
                dodajUFajlMetalofon();
            }
            else if(opp==5)
            {
                dodajUFajlBubanj();
            }
            else if(opp==6)
            {
                dodajUFajlCinele();
            }
            else if(opp==7)
            {
                dodajUFajlDaire();
            }
            else if(opp==8)
            {
                dodajUFajlKastanjete();
            }
            else if(opp==9)
            {
                dodajUFajlTruba();
            }
            else if(opp==10)
            {
                dodajUFajlHorna();
            }
            else if(opp==11)
            {
                dodajUFajlTuba();
            }
            else if(opp==12)
            {
                dodajUFajlTrombon();
            }
            else if(opp==13)
            {
                dodajUFajlKlarinet();
            }
            else if(opp==14)
            {
                dodajUFajlOboa();
            }
            else if(opp==15)
            {
                dodajUFajlSaksofon();
            }
            else if(opp==16)
            {
                dodajUFajlFlauta();
            }
            else if(opp==17)
            {
                dodajUFajlViolina();
            }
            else if(opp==18)
            {
                dodajUFajlViola();
            }
            else if(opp==19)
            {
                dodajUFajlVioloncelo();
            }
            else if(opp==20)
            {
                dodajUFajlKontrabas();
            }
            else if(opp==21)
            {
                dodajUFajlKlavir();
            }
            else if(opp==22)
            {
                dodajUFajlHarmonika();
            }
            else if(opp==23)
            {
                dodajUFajlMikser();
            }
            else if(opp==24)
            {
                dodajUFajlZvucnaKutija();
            }
            else if(opp==25)
            {
                dodajUFajlRazglasniSistemi();
            }
            else if(opp==26)
            {
                dodajUFajlPojacalo();
            }
            else if(opp==27)
            {
                dodajUFajlProcesori();
            }
            else if(opp==28)
            {
                dodajUFajlZvucnaKartica();
            }
            else if(opp==29)
            {
                dodajUFajlMikseta();
            }
            else if(opp==30)
            {
                dodajUFajlSlusalice();
            }
            else if(opp==31)
            {
                dodajUFajlKontroler();
            }
            else if(opp==32)
            {
                dodajUFajlOpremaZaInstrumente();
            }
            else if(opp==33)
            {
                dodajUFajlMikrofon();
            }
            else if(opp==34)
            {
                dodajUFajlDJOprema();
            }
            else if(opp==35)
            {
                dodajUFajlZaUcenje();
            }
            break;
        }

        case 3:
        {
            cout<<"Koji proizvod zelite da potrazite?"<<endl<<endl;
            printProizvodOpcije();
            int opp;
            cout<<">>";
            cin>>opp;

            if(opp==1)
            {
                int ID = idUnos();
                potraziUFajluGitara(ID);
            }
            else if(opp==2)
            {
                int ID = idUnos();
                potraziUFajluUkulele(ID);
            }
            else if(opp==3)
            {
                int ID = idUnos();
                potraziUFajluHarfa(ID);
            }
            else if(opp==4)
            {
                int ID = idUnos();
                potraziUFajluMetalofon(ID);
            }
            else if(opp==5)
            {
                int ID = idUnos();
                potraziUFajluBubanj(ID);
            }
            else if(opp==6)
            {
                int ID = idUnos();
                potraziUFajluCinele(ID);
            }
            else if(opp==7)
            {
                int ID = idUnos();
                potraziUFajluDaire(ID);
            }
            else if(opp==8)
            {
                int ID = idUnos();
                potraziUFajluKastanjete(ID);
            }
            else if(opp==9)
            {
                int ID = idUnos();
                potraziUFajluTruba(ID);
            }
            else if(opp==10)
            {
                int ID = idUnos();
                potraziUFajluHorna(ID);
            }
            else if(opp==11)
            {
                int ID = idUnos();
                potraziUFajluTuba(ID);
            }
            else if(opp==12)
            {
                int ID = idUnos();
                potraziUFajluTrombon(ID);
            }
            else if(opp==13)
            {
                int ID = idUnos();
                potraziUFajluKlarinet(ID);
            }
            else if(opp==14)
            {
                int ID = idUnos();
                potraziUFajluOboa(ID);
            }
            else if(opp==15)
            {
                int ID = idUnos();
                potraziUFajluSaksofon(ID);
            }
            else if(opp==16)
            {
                int ID = idUnos();
                potraziUFajluFlauta(ID);
            }
            else if(opp==17)
            {
                int ID = idUnos();
                potraziUFajluViolina(ID);
            }
            else if(opp==18)
            {
                int ID = idUnos();
                potraziUFajluViola(ID);
            }
            else if(opp==19)
            {
                int ID = idUnos();
                potraziUFajluVioloncelo(ID);
            }
            else if(opp==20)
            {
                int ID = idUnos();
                potraziUFajluKontrabas(ID);
            }
            else if(opp==21)
            {
                int ID = idUnos();
                potraziUFajluKlavir(ID);
            }
            else if(opp==22)
            {
                int ID = idUnos();
                potraziUFajluHarmonika(ID);
            }
            else if(opp==23)
            {
                int ID = idUnos();
                potraziUFajluMikser(ID);
            }
            else if(opp==24)
            {
                int ID = idUnos();
                potraziUFajluZvucnaKutija(ID);
            }
            else if(opp==25)
            {
                int ID = idUnos();
                potraziUFajluRazglasniSistemi(ID);
            }
            else if(opp==26)
            {
                int ID = idUnos();
                potraziUFajluPojacalo(ID);
            }
            else if(opp==27)
            {
                int ID = idUnos();
                potraziUFajluProcesor(ID);
            }
            else if(opp==28)
            {
                int ID = idUnos();
                potraziUFajluZvucnaKartica(ID);
            }
            else if(opp==29)
            {
                int ID = idUnos();
                potraziUFajluMikseta(ID);
            }
            else if(opp==30)
            {
                int ID = idUnos();
                potraziUFajluSlusalice(ID);
            }
            else if(opp==31)
            {
                int ID = idUnos();
                potraziUFajluKontroler(ID);
            }
            else if(opp==32)
            {
                int ID = idUnos();
                potraziUFajluOpremaZaInstrumente(ID);
            }
            else if(opp==33)
            {
                int ID = idUnos();
                potraziUFajluMikrofon(ID);
            }
            else if(opp==34)
            {
                int ID = idUnos();
                potraziUFajluDJOprema(ID);
            }
            else if(opp==35)
            {
                int ID = idUnos();
                potraziUFajluZaUcenje(ID);
            }
            break;
        }

        case 4:
        {
            cout<<"Koji proizvod zelite da obrisete?"<<endl<<endl;
            printProizvodOpcije();
            int opp;
            cout<<">>";
            cin>>opp;

            if(opp==1)
            {
                int ID = idUnos();
                obrisiUFajluGitara(ID);
            }
            else if(opp==2)
            {
                int ID = idUnos();
                obrisiUFajluUkulele(ID);
            }
            else if(opp==3)
            {
                int ID = idUnos();
                obrisiUFajluHarfa(ID);
            }
            else if(opp==4)
            {
                int ID = idUnos();
                obrisiUFajluMetalofon(ID);
            }
            else if(opp==5)
            {
                int ID = idUnos();
                obrisiUFajluBubanj(ID);
            }
            else if(opp==6)
            {
                int ID = idUnos();
                obrisiUFajluCinele(ID);
            }
            else if(opp==7)
            {
                int ID = idUnos();
                obrisiUFajluDaire(ID);
            }
            else if(opp==8)
            {
                int ID = idUnos();
                obrisiUFajluKastanjete(ID);
            }
            else if(opp==9)
            {
                int ID = idUnos();
                obrisiUFajluTruba(ID);
            }
            else if(opp==10)
            {
                int ID = idUnos();
                obrisiUFajluHorna(ID);
            }
            else if(opp==11)
            {
                int ID = idUnos();
                obrisiUFajluTuba(ID);
            }
            else if(opp==12)
            {
                int ID = idUnos();
                obrisiUFajluTrombon(ID);
            }
            else if(opp==13)
            {
                int ID = idUnos();
                obrisiUFajluKlarinet(ID);
            }
            else if(opp==14)
            {
                int ID = idUnos();
                obrisiUFajluOboa(ID);
            }
            else if(opp==15)
            {
                int ID = idUnos();
                obrisiUFajluSaksofon(ID);
            }
            else if(opp==16)
            {
                int ID = idUnos();
                obrisiUFajluFlauta(ID);
            }
            else if(opp==17)
            {
                int ID = idUnos();
                obrisiUFajluViolina(ID);
            }
            else if(opp==18)
            {
                int ID = idUnos();
                obrisiUFajluViola(ID);
            }
            else if(opp==19)
            {
                int ID = idUnos();
                obrisiUFajluVioloncelo(ID);
            }
            else if(opp==20)
            {
                int ID = idUnos();
                obrisiUFajluKontrabas(ID);
            }
            else if(opp==21)
            {
                int ID = idUnos();
                obrisiUFajluKlavir(ID);
            }
            else if(opp==22)
            {
                int ID = idUnos();
                obrisiUFajluHarmonika(ID);
            }
            else if(opp==23)
            {
                int ID = idUnos();
                obrisiUFajluMikser(ID);
            }
            else if(opp==24)
            {
                int ID = idUnos();
                obrisiUFajluZvucnaKutija(ID);
            }
            else if(opp==25)
            {
                int ID = idUnos();
                obrisiUFajluRazglasniSistemi(ID);
            }
            else if(opp==26)
            {
                int ID = idUnos();
                obrisiUFajluPojacalo(ID);
            }
            else if(opp==27)
            {
                int ID = idUnos();
                obrisiUFajluProcesor(ID);
            }
            else if(opp==28)
            {
                int ID = idUnos();
                obrisiUFajluZvucnaKartica(ID);
            }
            else if(opp==29)
            {
                int ID = idUnos();
                obrisiUFajluMikseta(ID);
            }
            else if(opp==30)
            {
                int ID = idUnos();
                obrisiUFajluSlusalice(ID);
            }
            else if(opp==31)
            {
                int ID = idUnos();
                obrisiUFajluKontroler(ID);
            }
            else if(opp==32)
            {
                int ID = idUnos();
                obrisiUFajluOpremaZaInstrumente(ID);
            }
            else if(opp==33)
            {
                int ID = idUnos();
                obrisiUFajluMikrofon(ID);
            }
            else if(opp==34)
            {
                int ID = idUnos();
                obrisiUFajluDJOprema(ID);
            }
            else if(opp==35)
            {
                int ID = idUnos();
                obrisiUFajluZaUcenje(ID);
            }
            break;
        }

        case 5:
        {
            cout<<"Koji fajl zelite da ispisete?"<<endl<<endl;
            printProizvodOpcije();
            int opp;
            cout<<">>";
            cin>>opp;

            if(opp==1)
            {
                ispisiFajlGitara();
            }
            else if(opp==2)
            {
                ispisiFajlUkulele();
            }
            else if(opp==3)
            {
                ispisiFajlHarfa();
            }
            else if(opp==4)
            {
                ispisiFajlMetalofon();
            }
            else if(opp==5)
            {
                ispisiFajlBubanj();
            }
            else if(opp==6)
            {
                ispisiFajlCinele();
            }
            else if(opp==7)
            {
                ispisiFajlDaire();
            }
            else if(opp==8)
            {
                ispisiFajlKastanjete();
            }
            else if(opp==9)
            {
                ispisiFajlTruba();
            }
            else if(opp==10)
            {
                ispisiFajlHorna();
            }
            else if(opp==11)
            {
                ispisiFajlTuba();
            }
            else if(opp==12)
            {
                ispisiFajlTrombon();
            }
            else if(opp==13)
            {
                ispisiFajlKlarinet();
            }
            else if(opp==14)
            {
                ispisiFajlOboa();
            }
            else if(opp==15)
            {
                ispisiFajlSaksofon();
            }
            else if(opp==16)
            {
                ispisiFajlFlauta();
            }
            else if(opp==17)
            {
                ispisiFajlViolina();
            }
            else if(opp==18)
            {
                ispisiFajlViola();
            }
            else if(opp==19)
            {
                ispisiFajlVioloncelo();
            }
            else if(opp==20)
            {
                ispisiFajlKontrabas();
            }
            else if(opp==21)
            {
                ispisiFajlKlavir();
            }
            else if(opp==22)
            {
                ispisiFajlHarmonika();
            }
            else if(opp==23)
            {
                ispisiFajlMikser();
            }
            else if(opp==24)
            {
                ispisiFajlZvucnaKutija();
            }
            else if(opp==25)
            {
                ispisiFajlRazglasniSistemi();
            }
            else if(opp==26)
            {
                ispisiFajlPojacalo();
            }
            else if(opp==27)
            {
                ispisiFajlProcesor();
            }
            else if(opp==28)
            {
                ispisiFajlZvucnaKartica();
            }
            else if(opp==29)
            {
                ispisiFajlMikseta();
            }
            else if(opp==30)
            {
                ispisiFajlSlusalice();
            }
            else if(opp==31)
            {
                ispisiFajlKontroler();
            }
            else if(opp==32)
            {
                ispisiFajlOpremaZaInstrumente();
            }
            else if(opp==33)
            {
                ispisiFajlMikrofon();
            }
            else if(opp==34)
            {
                ispisiFajlDJOprema();
            }
            else if(opp==35)
            {
                ispisiFajlZaUcenje();
            }
            break;
        }
        case 6:
        {
            system("cls");
            cout<<"Na koju policu zelite da dodate proizvod?"<<endl<<endl;
            printPoliceOpcije();
            int opp;
            cout<<">>";
            cin>>opp;
            if(opp==1)
            {
                system("cls");
                cout<<"Koji duvacki instrument zelite da dodate na policu?"<<endl<<endl;
                printDuvackiOpcije();
                int opp2;
                cout<<">>";
                cin>>opp2;
                if(opp2==1)
                {
                    Flauta f;
                    f.unosFlaute();
                    pd+=f;
                }
                else if(opp2==2)
                {
                    Horna h;
                    h.unosHorne();
                    pd+=h;
                }
                else if(opp2==3)
                {
                    Klarinet k;
                    k.unosKlarineta();
                    pd+=k;
                }
                else if(opp2==4)
                {
                    Oboa o;
                    o.unosOboe();
                    pd+=o;
                }
                else if(opp2==5)
                {
                    Saksofon s;
                    s.unosSaksofona();
                    pd+=s;
                }
                else if(opp2==6)
                {
                    Trombon t;
                    t.unosTrombona();
                    pd+=t;
                }
                else if(opp2==7)
                {
                    Truba t;
                    t.unosTruba();
                    pd+=t;
                }
                else if(opp2==8)
                {
                    Tuba t;
                    t.unosTube();
                    pd+=t;
                }
            }
            else if(opp==2)
            {
                system("cls");
                cout<<"Koji udaracki instrument zelite da dodate na policu?"<<endl<<endl;
                printUdarackiOpcije();
                int opp2;
                cout<<">>";
                cin>>opp2;
                if(opp2==1)
                {
                    Bubanj b;
                    b.unosBubnja();
                    pu+=b;
                }
                else if(opp2==2)
                {
                    Daire d;
                    d.unosDaira();
                    pu+=d;
                }
                else if(opp2==3)
                {
                    Cinele c;
                    c.unosCinela();
                    pu+=c;
                }
                else if(opp2==4)
                {
                    Metalofon m;
                    m.unosMetalofona();
                    pu+=m;
                }
                else if(opp2==5)
                {
                    Kastanjete k;
                    k.unosKastanjeta();
                    pu+=k;
                }
            }
            else if(opp==3)
            {
                system("cls");
                cout<<"Koji zicani instrument zelite da dodate na policu?"<<endl<<endl;
                printZicaniOpcije();
                int opp2;
                cout<<">>";
                cin>>opp2;
                if(opp2==1)
                {
                    Gitara g;
                    g.unosGitare();
                    pz+=g;
                }
                else if(opp2==2)
                {
                    Ukulele u;
                    u.unosUkulelea();
                    pz+=u;
                }
                else if(opp2==3)
                {
                    Harfa h;
                    h.unosHarfe();
                    pz+=h;
                }
            }
            else if(opp==4)
            {
                system("cls");
                cout<<"Koji gudacki instrument zelite da dodate na policu?"<<endl<<endl;
                printGudackiOpcije();
                int opp2;
                cout<<">>";
                cin>>opp2;
                if(opp2==1)
                {
                    Violina v;
                    v.unosVioline();
                    pg+=v;
                }
                else if(opp2==2)
                {
                    Viola v;
                    v.unosViole();
                    pg+=v;
                }
                else if(opp2==3)
                {
                    Violoncelo v;
                    v.unosVioloncela();
                    pg+=v;
                }
                else if(opp2==4)
                {
                    Kontrabas k;
                    k.unosKontrabasa();
                    pg+=k;
                }
            }
            else if(opp==5)
            {
                system("cls");
                cout<<"Koji instrument zelite da dodate na policu?"<<endl<<endl;
                printOstaliOpcije();
                int opp2;
                cout<<">>";
                cin>>opp2;
                if(opp2==1)
                {
                    Klavir k;
                    k.unosKlavira();
                    poi+=k;
                }
                else if(opp2==2)
                {
                    Harmonika h;
                    h.unosHarmonike();
                    poi+=h;
                }
            }
            else if(opp==6)
            {
                system("cls");
                cout<<"Koju opremu zelite da dodate na policu?"<<endl<<endl;
                printOpremaOpcije();
                int opp2;
                cout<<">>";
                cin>>opp2;
                if(opp2==1)
                {
                    DJOprema d;
                    d.unesiDJOprema();
                    po+=d;
                }
                else if(opp2==2)
                {
                    Kontroler k;
                    k.unesiKontroler();
                    po+=k;
                }
                else if(opp2==3)
                {
                    Mikrofon m;
                    m.unesiMikrofon();
                    po+=m;
                }
                else if(opp2==4)
                {
                    Mikser m;
                    m.unosMiksera();
                    po+=m;
                }
                else if(opp2==5)
                {
                    OpremaZaInstrumente o;
                    o.unesiOpremu();
                    po+=o;
                }
            }
            break;
        }
        case 7:
        {
            system("cls");
            cout<<"Koju policu zelite da ispisete?"<<endl<<endl;
            printPoliceOpcije();
            int opp;
            cout<<">>";
            cin>>opp;
            if(opp==1)
            {
                system("cls");
                pd.ispisPoliceDuvackihInstrumenata();
            }
            else if(opp==2)
            {
                system("cls");
                pu.ispisPolicaUdarackihInstrumenata();
            }
            else if(opp==3)
            {
                system("cls");
                pz.ispisPoliceZicanihInstrumenata();
            }
            else if(opp==4)
            {
                system("cls");
                pg.ispisPoliceGudackihInstrumenataIKlavira();
            }
            else if(opp==5)
            {
                system("cls");
                poi.ispisOstalihInstrumenata();
            }
            else if(opp==6)
            {
                system("cls");
                po.ispisOpremeIn();
            }
            break;
        }
        case 8:
        {
            cout<<endl<<"Dovidjenja!"<<endl;
            exit(0);
        }

        }



    }
    while(op>0 && op<9);



    return 0;
}
