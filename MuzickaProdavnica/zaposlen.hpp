#ifndef ZAPOSLEN_HPP_INCLUDED
#define ZAPOSLEN_HPP_INCLUDED

#include "oosba.hpp"

class Zaposlen : public Osoba
{
private:
float plata;
int satiRada;

public:
Zaposlen() : Osoba()
{
plata = 50000.00;
satiRada = 8;
}

Zaposlen(float PL, int SR, string I, string P, int G) : Osoba(I,P,G)
{
plata = PL;
satiRada = SR;
}

Zaposlen(const Zaposlen &z) : Osoba((Osoba)z)
{
plata = z.plata;
satiRada = z.satiRada;
}

float getPlata()const {return plata;}
int getSatiRada()const {return satiRada;}

void setPlata(float PLATA) {plata = PLATA;}
void setSatiRada(int SATIRADA) {satiRada = SATIRADA;}

void ispisiZaposlenog()
{
Osoba::ispisiOsobu();
cout<<"Plata: "<<getPlata()<<"din"<<endl;
cout<<"Sati rada: "<<getSatiRada()<<endl;
}

void unesiZaposlenog()
{
Osoba::unesiOsobu();
cout<<"Plata: ";
cin>>plata;
cout<<"Sati rada: ";
cin>>satiRada;
}

};
#endif
