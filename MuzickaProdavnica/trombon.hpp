#ifndef TROMBON_HPP_INCLUDED
#define TROMBON_HPP_INCLUDED

class Trombon: public Duvackiinstrument{
private:
    trombonVrsta vrstat;

public:
    Trombon(){
    naziv="Trombon";
    cena=1000.00;
    ocena=7.96;
    proizvodjac=yamaha;
    boja="zlatna";
    timbre="nije unet";
    vrsta=limeni;
    vrstat=altTrombon;
    }

    Trombon(DinString n, float c, float o,proizvodjaci p, DinString b, DinString t, duvackiVrsta v, trombonVrsta tv){
        naziv=n;
        cena=c;
        ocena=o;
        proizvodjac=p;
        boja=b;
        timbre=t;
        vrsta=v;
        vrstat=tv;
    }

    Trombon(const Trombon &t){
        naziv=t.naziv;
        cena=t.cena;
        ocena=t.ocena;
        proizvodjac=t.proizvodjac;
        boja=t.boja;
        timbre=t.timbre;
        vrsta=t.vrsta;
        vrstat=t.vrstat;
    }

    trombonVrsta getTrombon(){return vrstat; }
    void setTrombon(trombonVrsta tv){vrstat=tv; }

    void ispisTrombona(){
        Duvackiinstrument::ispisDuvackogInstrumenta();
        cout<<"Vrsta trombona :"<<getTrombon()<<endl;
    }

};

#endif // TROMBON_HPP_INCLUDED
