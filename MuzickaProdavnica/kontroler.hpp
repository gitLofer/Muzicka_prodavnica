#ifndef KONTROLER_HPP_INCLUDED
#define KONTROLER_HPP_INCLUDED

#include "proizvod.hpp"

class Kontroler : public Proizvod
{
private:
    kontrolerVrsta vrsta;
public:
    Kontroler()
    {
        naziv = "Nije unet";
        cena = 6799.99;
        ocena = 9;
        proizvodjac = yamaha;
        vrsta = recording;
    }

    Kontroler(string NAZIV, float CENA, float OCENA, proizvodjaci PROIZVODJAC, kontrolerVrsta VRSTA)
    {
        naziv = NAZIV;
        cena = CENA;
        ocena = OCENA;
        proizvodjac = PROIZVODJAC;
        vrsta = VRSTA;
    }

    Kontroler(const Kontroler &k)
    {
        naziv = k.naziv;
        cena = k.cena;
        ocena = k.ocena;
        proizvodjac = k.proizvodjac;
        vrsta = k.vrsta;
    }

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

#endif