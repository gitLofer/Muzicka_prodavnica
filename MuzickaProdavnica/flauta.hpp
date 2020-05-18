#ifndef FLAUTA_HPP_INCLUDED
#define FLAUTA_HPP_INCLUDED

class Flauta: public Duvackiinstrument{
private:
    flautaVrsta vrstaf;

public:
    Flauta(){
    naziv="Flauta";
    cena=800.00;
    ocena=8.75;
    proizvodjac=yamaha;
    boja="zlatna";
    timbre="nije unet";
    vrsta=drveni;
    vrstaf=standardna;
    }

    Flauta(DinString n, float c, float o,proizvodjaci p, DinString b, DinString t, duvackiVrsta v,  flautaVrsta fv){
        naziv=n;
        cena=c;
        ocena=o;
        proizvodjac=p;
        boja=b;
        timbre=t;
        vrsta=v;
        vrstaf=fv;
    }

    Flauta(const Flauta &f){
        naziv=f.naziv;
        cena=f.cena;
        ocena=f.ocena;
        proizvodjac=f.proizvodjac;
        boja=f.boja;
        timbre=f.timbre;
        vrsta=f.vrsta;
        vrstaf=f.vrstaf;
    }

    flautaVrsta getFlauta(){return vrstaf; }
    void setFlauta(flautaVrsta fv){vrstaf=fv; }

    void ispisFlaute(){
        Duvackiinstrument::ispisDuvackogInstrumenta();
        cout<<"Vrsta flaute :"<<getFlauta()<<endl;
    }

};


#endif // FLAUTA_HPP_INCLUDED
