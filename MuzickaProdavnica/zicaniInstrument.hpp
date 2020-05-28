#ifndef ZICANIINSTRUMENT_HPP_INCLUDED
#define ZICANIINSTRUMENT_HPP_INCLUDED

#include "instrument.hpp"
enum zicaVrsta {nikl, celik, najlon};

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

#endif
