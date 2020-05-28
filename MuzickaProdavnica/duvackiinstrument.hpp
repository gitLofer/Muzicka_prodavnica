#ifndef DUVACKIINSTRUMENT_HPP_INCLUDED
#define DUVACKIINSTRUMENT_HPP_INCLUDED

#include "instrument.hpp"
enum duvackiVrsta {limeni, drveni};

class DuvackiInstrument: public Instrument{
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
    void setVrsta(duvackiVrsta v){vrsta=v; }

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

#endif
