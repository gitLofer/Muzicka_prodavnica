#ifndef VIOLA_H_INCLUDED
#define VIOLA_H_INCLUDED

#include "gudackiInstrument.h"

class Viola : GudackiInstrument {
private:
    violaVrsta vrsta;
    float velicine;
public:
public:
    Viola() : GudackiInstrument(){
        vrsta = akusticnaViola;
        velicina = 3/4;
    }
    Viola(float vSize,violaVrsta violinType,tipGudala tipG, int brojZ, zicaVrsta typeOfString, bool electric,DinString na, float c, float o, proizvodjaci pp, DinString b, DinString tim) : GudackiInstrument(tipG, brojZ, typeOfString, electric, na, c, o, pp, b, tim) {
        vrsta = violinType;
        velicina = vSize;
    }
    Viola(const Viola &v) : GudackiInstrument((GudackiInstrument)&v) {
        vrsta = v.vrsta;
        velicina = v.velicina;
    }

    violaVrsta getViolaVrsta () const {return vrsta;}
    float getVelicina () const {return velicina;}

    void setViolaVrsta (violaVrsta v) {vrsta = v;}
    void setVelicina (float f) {velicina = f;}
};

#endif // VIOLA_H_INCLUDED
