#ifndef DJOPREMA_HPP_INCLUDED
#define DJOPREMA_HPP_INCLUDED

#include "proizvod.hpp"

class DJOprema : public Proizvod
{
private:
    djOpremaVrsta vrsta;
public:
    DJOprema()
    {
        naziv = "Nije unet";
        cena = 8000;
        ocena = 9.67;
        proizvodjac = yamaha;
        vrsta = djInterface;
    }

    DJOprema(string NAZIV, float CENA, float OCENA, proizvodjaci PROIZVODJAC, djOpremaVrsta VRSTA)
    {
        naziv = NAZIV;
        cena = CENA;
        ocena = OCENA;
        proizvodjac = PROIZVODJAC;
        vrsta = VRSTA;
    }

    DJOprema(const DJOprema &dj)
    {
        naziv = dj.naziv;
        cena = dj.cena;
        ocena = dj.ocena;
        proizvodjac = dj.proizvodjac;
        vrsta = dj.vrsta;
    }

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
        cout<<"Unesite broj [1-DJ interface/2-DJ kontroler/3-DJ mikseta/4-DJ paket/5-DJ slusalice]: "<<endl;
        cin>>br;

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
};

#endif