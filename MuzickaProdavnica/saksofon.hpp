#ifndef SAKSOFON_HPP_INCLUDED
#define SAKSOFON_HPP_INCLUDED

class Saksofon: public Duvackiinstrument{
private:
    saksofonVrsta vrstas;

public:
    Saksofon(){
    naziv="Saksofon";
    cena=800.00;
    ocena=8.75;
    proizvodjac=yamaha;
    boja="zlatna";
    timbre="nije unet";
    vrsta=drveni;
    vrstas=sopranSaksofon;
    }

    Saksofon(DinString n, float c, float o,proizvodjaci p, DinString b, DinString t, duvackiVrsta v,  saksofonVrsta sv){
        naziv=n;
        cena=c;
        ocena=o;
        proizvodjac=p;
        boja=b;
        timbre=t;
        vrsta=v;
        vrstas=sv;
    }

    Saksofon(const Saksofon &s){
        naziv=s.naziv;
        cena=s.cena;
        ocena=s.ocena;
        proizvodjac=s.proizvodjac;
        boja=s.boja;
        timbre=s.timbre;
        vrsta=s.vrsta;
        vrstas=s.vrstas;
    }

    saksofonVrsta getSaksofon(){return vrstas; }
    void setSaksofon(saksofonVrsta sv){vrstas=sv; }

    void ispisSaksofona(){
        Duvackiinstrument::ispisDuvackogInstrumenta();
        cout<<"Vrsta saksofona :"<<getSaksofon()<<endl;
    }

};

#endif // SAKSOFON_HPP_INCLUDED
