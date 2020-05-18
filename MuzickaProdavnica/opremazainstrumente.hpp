#ifndef OPREMAZAINSTRUMENTE_HPP_INCLUDED
#define OPREMAZAINSTRUMENTE_HPP_INCLUDED

#include "proizvod.hpp"

class OpremaZaInstrumente : public Proizvod
{
private:
    instrumentOpremaVrsta vrsta;
public:
    OpremaZaInstrumente()
    {
        naziv = "Nije unet";
        cena = 500;
        ocena = 8;
        proizvodjac = yamaha;
        vrsta = metronom;
    }

    OpremaZaInstrumente(string NAZIV, float CENA, float OCENA, proizvodjaci PROIZVODJAC, instrumentOpremaVrsta VRSTA)
    {
        naziv = NAZIV;
        cena = CENA;
        ocena = OCENA;
        proizvodjac = PROIZVODJAC;
        vrsta = VRSTA;
    }

    OpremaZaInstrumente(const OpremaZaInstrumente &o)
    {
        naziv = o.naziv;
        cena = o.cena;
        ocena = o.ocena;
        proizvodjac = o.proizvodjac;
        vrsta = o.vrsta;
    }

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

};

#endif