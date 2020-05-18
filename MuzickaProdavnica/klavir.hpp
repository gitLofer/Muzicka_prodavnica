#ifndef KLAVIR_HPP_INCLUDED
#define KLAVIR_HPP_INCLUDED

class Klavir: public Instrument{
private:
    klavirVrsta vrstak;

public:
    Klavir(){
        naziv="Klavir";
        cena=4000.00;
        ocena=9.69;
        proizvodjac=yamaha;
        boja="crna";
        timbre="sharp";
        vrstak=elektricni;
    }

    Klavir(DinString n, float c, float o, proizvodjaci p, DinString b, DinString t, klavirVrsta k){
        naziv=n;
        cena=c;
        ocena=o;
        proizvodjac=p;
        boja=b;
        timbre=t;
        vrstak=k;
    }

    Klavir(const Klavir &k){
        naziv=k.naziv;
        cena=k.cena;
        ocena=k.ocena;
        proizvodjac=k.proizvodjac;
        boja=k.boja;
        timbre=k.timbre;
        vrstak=k.vrstak;
    }

    klavirVrsta getKlavir(){return vrstak; }
    void setKlavir(klavirVrsta k){vrstak=k; }

    void ispisKlavira(){
        Instrument :: ispisInstrumenta();
        cout<<"Vrsta klavira:"<<getKlavir()<<endl;
    }
};


#endif // KLAVIR_HPP_INCLUDED
