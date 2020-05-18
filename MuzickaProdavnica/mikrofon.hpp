#ifndef MIKROFON_HPP_INCLUDED
#define MIKROFON_HPP_INCLUDED

#include "proizvod.hpp"

class Mikrofon : public Proizvod
{
private:
    mikrofonVrsta vrsta;
public:
    Mikrofon()
    {
        naziv = "Nije unet";
        cena = 7999.99;
        ocena = 9.66;
        proizvodjac = yamaha;
        vrsta = headset;
    }

    Mikrofon(string NAZIV, float CENA, float OCENA, proizvodjaci PROIZVODJAC, mikrofonVrsta VRSTA)
    {
        naziv = NAZIV;
        cena = CENA;
        ocena = OCENA;
        proizvodjac = PROIZVODJAC;
        vrsta = VRSTA;
    }

    Mikrofon(const Mikrofon &m)
    {
        naziv = m.naziv;
        cena = m.cena;
        ocena = m.ocena;
        proizvodjac = m.proizvodjac;
        vrsta = m.vrsta;
    }

    string getVrsta()const
    {
        switch(vrsta)
        {
        case dinamicki:
            return "Dinamicki";
            break;
        case headset:
            return "Headset";
            break;
        case instrumentalni:
            return "Instrumentalni";
            break;
        case kondenzatorski:
            return "Kondenzatorski";
            break;
        case lavalier:
            return "Lavalier";
            break;
        case ribon:
            return "Ribon";
            break;
        case vokalni:
            return "Vokalni";
            break;
        case zaKamere:
            return "Za kamere";
            break;
        }
    }

    void setVrsta()
    {
        int br;
        cout<<"Unesite broj [1-Dinamicki/2-Headset/3-Instrumentalni/4-Kondenzatorski/5-Lavalier/6-Ribon/7-Vokalni/8-Za kamere]: "<<endl;
        cin>>br;

        switch(br)
        {
        case 1:
            vrsta = dinamicki;
            break;
        case 2:
            vrsta = headset;
            break;
        case 3:
            vrsta = instrumentalni;
            break;
        case 4:
            vrsta = kondenzatorski;
            break;
        case 5:
            vrsta = lavalier;
            break;
        case 6:
            vrsta = ribon;
            break;
        case 7:
            vrsta = vokalni;
            break;
        case 8:
            vrsta = zaKamere;
            break;
        }

    }
};

#endif