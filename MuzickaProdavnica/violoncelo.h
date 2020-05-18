#ifndef VIOLONCELO_H_INCLUDED
#define VIOLONCELO_H_INCLUDED

#include "gudackiInstrument.h"

class Violoncelo : GudackiInstrument {
private:
    violonceloVrsta vrsta;
    float velicina;
public:
    Violoncelo() : GudackiInstrument(){
        vrsta = carbonFiberVioloncelo;
        velicina = 3/4;
    }
    Violoncelo(float vSize,violonceloVrsta violonceloType,tipGudala tipG, int brojZ, zicaVrsta typeOfString, bool electric,DinString na, float c, float o, proizvodjaci pp, DinString b, DinString tim) : GudackiInstrument(tipG, brojZ, typeOfString, electric, na, c, o, pp, b, tim) {
        vrsta = violonceloType;
        velicina = vSize;
    }
    Violoncelo(const Violoncelo &v) : GudackiInstrument((GudackiInstrument)v) {
        vrsta = v.vrsta;
        velicina = v.velicina;
    }

    violonceloVrsta getViolonceloVrsta () const {return vrsta;}
    float getVelicina () const {return velicina;}

    void setViolonceloVrsta (violonceloVrsta v) {vrsta = v;}
    void setVelicina (float f) {velicina = f;}
};

#endif // VIOLONCELO_H_INCLUDED
