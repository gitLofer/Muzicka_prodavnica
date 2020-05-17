#ifndef UDARACKIINSTRUMENT_HPP_INCLUDED
#define UDARACKIINSTRUMENT_HPP_INCLUDED

class UdarackiInstrument : public Instrument
{
protected:
    udarackiVisinaTona ton;
public:
    UdarackiInstrument()
    {
        naziv = "Bubanj";
        cena = 5000.00;
        ocena = 10.0;
        proizvodjac = yamaha;
        boja = "CRVENA";
        timbre = "round";
        ton = neodredjena;
    }
    UdarackiInstrument(DinString naz, float cc, float oo, proizvodjaci pp, DinString bb, DinString tt, udarackiVisinaTona visina)
    {
        naziv = naz;
        cena = cc;
        ocena = oo;
        proizvodjac = pp;
        boja = bb;
        timbre = tt;
        ton = visina;
    }
    UdarackiInstrument(const UdarackiInstrument &u)
    {
        naziv = u.naziv;
        cena = u.cena;
        ocena = u.ocena;
        proizvodjac = u.proizvodjac;
        boja = u.boja;
        timbre = u.timbre;
        ton = u.ton;
    }

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
        Instrument :: ispisInstrumenta();
        cout<<"Visina tona: "<<getVisinaTona()<<endl;
    }

};

#endif // UDARACKIINSTRUMENT_HPP_INCLUDED
