#ifndef UDARACKIINSTRUMENT_HPP_INCLUDED
#define UDARACKIINSTRUMENT_HPP_INCLUDED

#include "instrument.hpp"

class UdarackiInstrument : public Instrument
{
protected:
    udarackiVisinaTona ton;
public:
    /// Constructors
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

    /// Functions
    void setVisinaTona(udarackiVisinaTona vis){ton = vis;}

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

#endif // UDARACKIINSTRUMENT_HPP_INCLUDED
