#ifndef MIKSER_H_INCLUDED
#define MIKSER_H_INCLUDED

#include "proizvod.hpp"

class Mikser : Proizvod {
private:
    mikserVrsta vrsta;
public:
    Mikser() : Proizvod(){
        vrsta = digitalni;
    }
    Mikser(mikserVrsta mikserType,DinString na, float c, float o, proizvodjaci pp) : Proizvod(na, c, o, pp) {
        vrsta = mikserType;
    }
    Mikser(const Mikser &m) : Proizvod((Proizvod)m) {
        vrsta = m.vrsta;
    }

    mikserVrsta getMikserVrsta () const {return vrsta;}
    void setMikserVrsta (mikserVrsta m) {vrsta = m;}
};

#endif // MIKSER_H_INCLUDED
