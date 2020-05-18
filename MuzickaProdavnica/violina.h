#ifndef VIOLINA_H_INCLUDED
#define VIOLINA_H_INCLUDED

#include "gudackiInstrument.h"

 // Velicine - 1/32, 1/16, 1/10, 1/8, 1/4, 1/2, 3/4, 4/4

class Violina : GudackiInstrument{
private:
    violinaVrsta vrsta;
    float velicina;
public:
    Violina() : GudackiInstrument(){
        vrsta = klasicnaViolina;
        velicina = 3/4;
    }
    Violina(float vSize,violinaVrsta violinType,tipGudala tipG, int brojZ, zicaVrsta typeOfString, bool electric,DinString na, float c, float o, proizvodjaci pp, DinString b, DinString tim) : GudackiInstrument(tipG, brojZ, typeOfString, electric, na, c, o, pp, b, tim) {
        vrsta = violinType;
        velicina = vSize;
    }
    Violina(const Violina &v) : GudackiInstrument((GudackiInstrument)&v) {
        vrsta = v.vrsta;
        velicina = v.velicina;
    }

    violinaVrsta getViolinaVrsta () const {return vrsta;}
    float getVelicina () const {return velicina;}

    void setViolinaVrsta (violinaVrsta v) {vrsta = v;}
    void setVelicina (float f) {velicina = f;}
};

#endif // VIOLINA_H_INCLUDED
