#ifndef MIKSER_H_INCLUDED
#define MIKSER_H_INCLUDED

#include "proizvod.hpp"

/// Note:
// Nemam blage veze kako da uradim - mikser, zvucna kutija, razglasni sistemi, pojacala, procesori, zvucna kartica, mikseta
// Glavni razlog je to sto bi bukv copy paste ovo jos jedno 5-6 puta
// - Petar

class Mikser : Proizvod {
private:
    mikserVrsta vrsta;
public:
    Mikser() : Proizvod(){
        vrsta = digitalni;
    }
    Mikser(mikserVrsta mikserType,DinString na, float c, float o, proizvodjaci pp, DinString b, DinString tim) : Proizvod(na, c, o, pp, b, tim) {
        vrsta = mikserType;
    }
    Mikser(const Mikser &m) : Proizvod((Proizvod)&v) {
        vrsta = m.vrsta;
    }

    mikserVrsta getMikserVrsta () const {return vrsta;}
    void setMikserVrsta (mikserVrsta m) {vrsta = m;}
};

#endif // MIKSER_H_INCLUDED
