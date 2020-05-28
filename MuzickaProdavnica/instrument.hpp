#ifndef INSTRUMENT_HPP_INCLUDED
#define INSTRUMENT_HPP_INCLUDED

#include "proizvod.hpp"

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

    const char* getBoja()const {return boja;}
    const char* getTimbre()const {return timbre;}

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

#endif
