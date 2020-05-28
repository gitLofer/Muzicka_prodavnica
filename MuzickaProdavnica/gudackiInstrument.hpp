#ifndef GUDACKIINSTRUMENT_HPP_INCLUDED
#define GUDACKIINSTRUMENT_HPP_INCLUDED

#include "instrument.hpp"

enum tipGudala {NEMACKI, FRANCUSKI};

class GudackiInstrument : Instrument
{
protected:
    tipGudala gudaloTip;
    int brojZica;
    zicaVrsta vrstaZica;
    bool isElectric;
public:
    GudackiInstrument() : Instrument() {
        gudaloTip = NEMACKI;
        brojZica = 4;
        isElectric = false;
    }
    GudackiInstrument( tipGudala tipG, int brojZ,bool electric, float c, float o, proizvodjaci pp) : Instrument( c, o, pp) {
        gudaloTip = tipG;
        brojZica = brojZ;
        isElectric = electric;
    }
    GudackiInstrument(const GudackiInstrument &gi) : Instrument((Instrument)gi) {
        gudaloTip = gi.gudaloTip;
        brojZica = gi.brojZica;
    }

    tipGudala getGudalo () const {return gudaloTip;}
    int getZicaBroj () const {return brojZica;}
    bool getElectric () const {return isElectric;}

    void setGudalo (tipGudala g) {gudaloTip = g;}
    void setZicaBroj (int b) {brojZica = b;}
    void setElectric (bool e) {isElectric = e;}

    void ispisGudackogInstrumenta()
    {
        ispisInstrumenta();
        cout<<"Tip gudala: "<<getGudalo()<<endl;
        cout<<"Broj zica: "<<getZicaBroj()<<endl;
        cout<<"Elektricna: "<<getElectric()<<endl;
    }

    void unosGudackogInstrumenta()
    {
        int br;
        unosInstrumenta();
        cout<<"Tip gudala[1-Francuski/2-Nemacki]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            gudaloTip = FRANCUSKI;
            break;
        case 2:
            gudaloTip = NEMACKI;
            break;
        }
        cout<<"Broj zica: ";
        cin>>brojZica;
        fflush(stdin);
        cout<<"Elektricna: ";
        cin>>isElectric;
        fflush(stdin);
     }
};

#endif 
