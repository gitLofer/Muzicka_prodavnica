#ifndef KONTRABAS_H_INCLUDED
#define KONTRABAS_H_INCLUDED

#include "gudackiInstrument.h"

class Kontrabas : GudackiInstrument {
private:
    kontrabasVrsta vrsta;
    float velicina;
public:
    Kontrabas() : GudackiInstrument(){
        vrsta = dupliBas;
        velicina = 3/4;
    }
    Kontrabas(float vSize,kontrabasVrsta kontrabasType,tipGudala tipG, int brojZ, zicaVrsta typeOfString, bool electric,DinString na, float c, float o, proizvodjaci pp, DinString b, DinString tim) : GudackiInstrument(tipG, brojZ, typeOfString, electric, na, c, o, pp, b, tim) {
        vrsta = kontrabasType;
        velicina = vSize;
    }
    Kontrabas(const Kontrabas &v) : GudackiInstrument((GudackiInstrument)v) {
        vrsta = v.vrsta;
        velicina = v.velicina;
    }

    kontrabasVrsta getViolonceloVrsta () const {return vrsta;}
    float getVelicina () const {return velicina;}

    void setViolonceloVrsta (kontrabasVrsta k) {vrsta = k;}
    void setVelicina (float f) {velicina = f;}
};


#endif // KONTRABAS_H_INCLUDED
