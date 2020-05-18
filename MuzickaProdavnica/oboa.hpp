#ifndef OBOA_HPP_INCLUDED
#define OBOA_HPP_INCLUDED

class Oboa: public Duvackiinstrument{
private:
    oboaVrsta vrstao;

public:
    Oboa(){
    naziv="Oboa";
    cena=800.00;
    ocena=8.75;
    proizvodjac=yamaha;
    boja="zlatna";
    timbre="nije unet";
    vrsta=drveni;
    vrstao=baroknaOboa;
    }

    Oboa(DinString n, float c, float o,proizvodjaci p, DinString b, DinString t, duvackiVrsta v,  oboaVrsta ov){
        naziv=n;
        cena=c;
        ocena=o;
        proizvodjac=p;
        boja=b;
        timbre=t;
        vrsta=v;
        vrstao=ov;
    }

    Oboa(const Oboa &o){
        naziv=o.naziv;
        cena=o.cena;
        ocena=o.ocena;
        proizvodjac=o.proizvodjac;
        boja=o.boja;
        timbre=o.timbre;
        vrsta=o.vrsta;
        vrstao=o.vrstao;
    }

    oboaVrsta getOboa(){return vrstao; }
    void setOboa(oboaVrsta ov){vrstao=ov; }

    void ispisOboe(){
        Duvackiinstrument::ispisDuvackogInstrumenta();
        cout<<"Vrsta oboe :"<<getOboa()<<endl;
    }

};

#endif // OBOA_HPP_INCLUDED
