#ifndef TUBA_HPP_INCLUDED
#define TUBA_HPP_INCLUDED

class Tuba: public Duvackiinstrument{
private:
    tubaVrsta vrstat;

public:
    Tuba(){
    naziv="Tuba";
    cena=1500.00;
    ocena=8.75;
    proizvodjac=fender;
    boja="zlatna";
    timbre="nije unet";
    vrsta=limeni;
    vrstat=kontrabasTuba;
    }

    Tuba(DinString n, float c, float o,proizvodjaci p, DinString b, DinString t, duvackiVrsta v, tubaVrsta tv){
        naziv=n;
        cena=c;
        ocena=o;
        proizvodjac=p;
        boja=b;
        timbre=t;
        vrsta=v;
        vrstat=tv;
    }

    Tuba(const Tuba &t){
        naziv=t.naziv;
        cena=t.cena;
        ocena=t.ocena;
        proizvodjac=t.proizvodjac;
        boja=t.boja;
        timbre=t.timbre;
        vrsta=t.vrsta;
        vrstat=t.vrstat;
    }

    tubaVrsta getTuba(){return vrstat; }
    void setTuba(tubaVrsta tv){vrstat=tv; }

    void ispisTube(){
        Duvackiinstrument::ispisDuvackogInstrumenta();
        cout<<"Vrsta tube :"<<getTuba()<<endl;
    }

};


#endif // TUBA_HPP_INCLUDED
