#ifndef HORNA_HPP_INCLUDED
#define HORNA_HPP_INCLUDED


class Horna: public Duvackiinstrument{
private:
    hornaVrsta vrstah;

public:
    Horna(){
    naziv="Horna";
    cena=2000.00;
    ocena=8.75;
    proizvodjac=yamaha;
    boja="zlatna";
    timbre="nije unet";
    vrsta=limeni;
    vrstah=jednostruka;
    }

    Horna(DinString n, float c, float o,proizvodjaci p, DinString b, DinString t, duvackiVrsta v, hornaVrsta hv){
        naziv=n;
        cena=c;
        ocena=o;
        proizvodjac=p;
        boja=b;
        timbre=t;
        vrsta=v;
        vrstah=hv;
    }

    Horna(const Horna &h){
        naziv=h.naziv;
        cena=h.cena;
        ocena=h.ocena;
        proizvodjac=h.proizvodjac;
        boja=h.boja;
        timbre=h.timbre;
        vrsta=h.vrsta;
    }

    hornaVrsta getHorna(){return vrstah; }
    void setHorna(hornaVrsta hv){vrstah=hv; }

    void ispisHorne(){
        Duvackiinstrument::ispisDuvackogInstrumenta();
        cout<<"Vrsta horne :"<<getHorna()<<endl;
    }

};



#endif // HORNA_HPP_INCLUDED
