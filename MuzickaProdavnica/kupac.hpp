#ifndef KUPAC_HPP_INCLUDED
#define KUPAC_HPP_INCLUDED

#include "kupac.hpp"

class Kupac : public Osoba{
private:
    bool unutra;

public:
    Kupac() : Osoba(){
    unutra = false;
    }

    Kupac( bool U, string I, string P, int G) : Osoba(I,P,G){
    unutra = U;
    }

    Kupac(const Kupac &k) : Osoba((Osoba)k){
    unutra = k.unutra;
    }

    bool getUnutra()const {return unutra;}

    void setUnutra(bool U) {unutra = U;}

    void ispisiKupca(){
    ispisiOsobu();
    cout<<"Unutra: ";
    if(unutra==0)
        cout<<"Ne"<<endl;
    else
        cout<<"Da"<<endl;
    }

    void unesiKupca() {
    unesiOsobu();
    cout<<"Unutra: ";
    cin>>unutra;
    }

};

#endif
