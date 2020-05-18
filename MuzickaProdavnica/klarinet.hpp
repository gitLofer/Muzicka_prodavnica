#ifndef KLARINET_HPP_INCLUDED
#define KLARINET_HPP_INCLUDED

class Klarinet: public Duvackiinstrument{
private:
    DinString klarinetMaterijal;
    klarinetVrsta vrstak;

public:
    Klarinet(){
    naziv="Klarinet";
    cena=800.00;
    ocena=8.75;
    proizvodjac=yamaha;
    boja="zlatna";
    timbre="nije unet";
    vrsta=drveni;
    klarinetMaterijal="Nije unet";
    vrstak=harmonijskiKlarinet;
    }

    Klarinet(DinString n, float c, float o,proizvodjaci p, DinString b, DinString t, duvackiVrsta v,DinString km, klarinetVrsta kv){
        naziv=n;
        cena=c;
        ocena=o;
        proizvodjac=p;
        boja=b;
        timbre=t;
        vrsta=v;
        klarinetMaterijal=km;
        vrstak=kv;
    }

    Klarinet(const Klarinet &k){
        naziv=k.naziv;
        cena=k.cena;
        ocena=k.ocena;
        proizvodjac=k.proizvodjac;
        boja=k.boja;
        timbre=k.timbre;
        vrsta=k.vrsta;
        klarinetMaterijal=k.klarinetMaterijal;
        vrstak=k.vrstak;
    }

    DinString getMaterijal(){return klarinetMaterijal; }
    klarinetVrsta getKlarinet(){return vrstak; }

    void setMaterijal(DinString km){klarinetMaterijal=km; }
    void setKlarinet(klarinetVrsta kv){vrstak=kv; }

    void ispisKlarineta(){
        Duvackiinstrument::ispisDuvackogInstrumenta();
        cout<<"Vrsta klarineta :"<<getKlarinet()<<endl;
        cout<<"Materijal klarineta :"<<getMaterijal()<<endl;
    }

};

#endif // KLARINET_HPP_INCLUDED
