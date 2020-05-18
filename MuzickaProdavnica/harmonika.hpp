#ifndef HARMONIKA_HPP_INCLUDED
#define HARMONIKA_HPP_INCLUDED

class Harmonika: public Instrument{
private:
    harmonikaVrsta vrstah;

public:
    Harmonika(){
        naziv="Harmonika";
        cena=4000.00;
        ocena=9.69;
        proizvodjac=yamaha;
        boja="crna";
        timbre="sharp";
        vrstah=obicna;
    }

    Harmonika(DinString n, float c, float o, proizvodjaci p, DinString b, DinString t, harmonikaVrsta h ){
        naziv=n;
        cena=c;
        ocena=o;
        proizvodjac=p;
        boja=b;
        timbre=t;
        vrstah=h;
    }

    Harmonika(const Harmonika &h){
        naziv=h.naziv;
        cena=h.cena;
        ocena=h.ocena;
        proizvodjac=h.proizvodjac;
        boja=h.boja;
        timbre=h.timbre;
        vrstah=h.vrstah;
    }

    harmonikaVrsta getHarmonika(){return vrstah; }
    void setHarmonika(harmonikaVrsta h){vrstah=h; }

    void ispisHarmonike(){
        Instrument :: ispisInstrumenta();
        cout<<"Vrsta harmonike:"<<getHarmonika()<<endl;
    }
};

#endif // HARMONIKA_HPP_INCLUDED
