#ifndef ZICANIINSTRUMENT_HPP_INCLUDED
#define ZICANIINSTRUMENT_HPP_INCLUDED

#include "instrument.hpp"

class ZicaniInstrument : public Instrument
{
protected:
    int brojZica;
    float duzinaZice;
    zicaVrsta vrstaZica;
public:
    ZicaniInstrument()
    {
        naziv = "Gitara";
        cena = 7000.00;
        ocena = 6.9;
        proizvodjac = taylor;
        boja = "CRNA";
        timbre = "sharp";
        brojZica = 6;
        duzinaZice = 1.5;
        vrstaZica = nikl;
    }
    ZicaniInstrument(DinString naz, float cc, float oo, proizvodjaci pp, DinString bb, DinString tt, int broj, float duzina, zicaVrsta vrs)
    {
        naziv = naz;
        cena = cc;
        ocena = oo;
        proizvodjac = pp;
        boja = bb;
        timbre = tt;
        brojZica = broj;
        duzinaZice = duzina;
        vrstaZica = vrs;
    }
    ZicaniInstrument(const ZicaniInstrument &z)
    {
        naziv = z.naziv;
        cena = z.cena;
        ocena = z.ocena;
        proizvodjac = z.proizvodjac;
        boja = z.boja;
        timbre = z.timbre;
        brojZica = z.brojZica;
        duzinaZice = z.duzinaZice;
        vrstaZica = z.vrstaZica;
    }

    void setBrojZica(int br){brojZica = br;}
    void setDuzinaZica(float duz){duzinaZice = duz;}
    void setVrztaZica(zicaVrsta vr){vrstaZica = vr;}

    int getBrojZica()const{return brojZica;}
    float getDuzinaZica()const {return duzinaZice;}
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
        Instrument :: ispisInstrumenta();
        cout<<"Broj zica: "<<getBrojZica()<<endl;
        cout<<"Duzina zica: "<<getDuzinaZica()<<" metara"<<endl;
        cout<<"Vrsta zica: "<<getVrstaZica()<<endl;

    }
};


#endif // ZICANIINSTRUMENT_HPP_INCLUDED
