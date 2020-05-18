#ifndef GUDACKIINSTRUMENT_H_INCLUDED
#define GUDACKIINSTRUMENT_H_INCLUDED

#include "instrument.hpp"

enum tipGudala {NEMACKI, FRANCUSKI};

class GudackiInstrument : Instrument {
protected:
    tipGudala gudaloTip;
    int brojZica;
    zicaVrsta vrstaZica;
    bool isElectric;
public:
    GudackiInstrument() : Instrument() {
        gudaloTip = NEMACKI;
        brojZica = 4;
        vrstaZica = najlon;
        isElectric = false;
    }
    GudackiInstrument(tipGudala tipG, int brojZ, zicaVrsta typeOfString, bool electric,DinString na, float c, float o, proizvodjaci pp, DinString b, DinString tim) : Instrument(na, c, o, pp, b, tim) {
        gudaloTip = tipG;
        brojZica = brojZ;
        vrstaZica = typeOfString;
        isElectric = electric;
    }
    GudackiInstrument(const GudackiInstrument &gi) : Proizvod((Proizvod)&gi) {
        gudaloTip = gi.gudaloTip;
        brojZica = gi.brojZica;
    }

    tipGudala getGudalo () const {return gudaloTip;}
    int getZicaBroj () const {return brojZica;}
    zicaVrsta getZicaVrsta () const {return vrstaZica;}
    bool getElectric () const {return isElectric;}

    void setGudalo (tipGudala g) {gudaloTip = g;}
    void setZicaBroj (int b) {brojZica = b;}
    void setZicaVrsta (zicaVrsta zv) {vrstaZica = zv;}
    void setElectric (bool e) {isElectric = e;}
};

#endif // GUDACKIINSTRUMENT_H_INCLUDED
