#ifndef DUVACKIINSTRUMENT_HPP_INCLUDED
#define DUVACKIINSTRUMENT_HPP_INCLUDED

class Duvackiinstrument: public Instrument{
protected:
    duvackiVrsta vrsta;

public:
    Duvackiinstrument(){
        naziv="Flauta";
        cena=1000.00;
        ocena=9.34;
        proizvodjac=yamaha;
        boja="Srebrna";
        timbre="sharp";
        vrsta=drveni;
    }

    Duvackiinstrument(DinString n, float c, float o, proizvodjaci p, DinString b, DinString t, duvackiVrsta v){
        naziv=n;
        cena=c;
        ocena=o;
        proizvodjac=p;
        boja=b;
        timbre=t;
        vrsta=v;
    }

    Duvackiinstrument(const Duvackiinstrument &di){
        naziv=di.naziv;
        cena=di.cena;
        ocena=di.ocena;
        proizvodjac=di.proizvodjac;
        boja=di.boja;
        timbre=di.timbre;
        vrsta=di.vrsta;
    }

    duvackiVrsta getVrsta(){return vrsta; }
    void setVrsta(duvackiVrsta v){vrsta=v; }

    void ispisDuvackogInstrumenta(){
        Instrument :: ispisInstrumenta();
        cout<<"Vrsta :"<<getVrsta()<<endl;
    }
};

#endif // DUVACKIINSTRUMENT_HPP_INCLUDED
