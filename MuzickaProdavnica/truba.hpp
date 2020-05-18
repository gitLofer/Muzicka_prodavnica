#ifndef TRUBA_HPP_INCLUDED
#define TRUBA_HPP_INCLUDED

class Truba: public Duvackiinstrument{
private:
    trubaVrsta vrstat;

public:
    Truba(){
    naziv="Truba";
    cena=1500.00;
    ocena=8.75;
    proizvodjac=gibson;
    boja="zlatna";
    timbre="nesto";
    vrsta=limeni;
    vrstat=basTruba;
    }

    Truba(DinString n, float c, float o,proizvodjaci p, DinString b, DinString t, duvackiVrsta v, trubaVrsta tv){
        naziv=n;
        cena=c;
        ocena=o;
        proizvodjac=p;
        boja=b;
        timbre=t;
        vrsta=v;
        vrstat=tv;
    }

    Truba(const Truba &t){
        naziv=t.naziv;
        cena=t.cena;
        ocena=t.ocena;
        proizvodjac=t.proizvodjac;
        boja=t.boja;
        timbre=t.timbre;
        vrsta=t.vrsta;
        vrstat=t.vrstat;
    }

    trubaVrsta getTruba(){return vrstat; }
    void setTruba(trubaVrsta tv){vrstat=tv; }

    void ispisTruba(){
        Duvackiinstrument::ispisDuvackogInstrumenta();
        cout<<"Vrsta trube :"<<getTruba()<<endl;
    }

};

#endif // TRUBA_HPP_INCLUDED
