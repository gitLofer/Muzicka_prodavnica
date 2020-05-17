#ifndef METALOFON_HPP_INCLUDED
#define METALOFON_HPP_INCLUDED

class Metalofon : public UdarackiInstrument
{
private:
    int brojOktava;
public:
    Metalofon()
    {
        naziv = "Metalofon";
        cena = 1000.00;
        ocena = 10.0;
        proizvodjac = yamaha;
        boja = "BELA";
        timbre = "sharp";
        ton = odredjena;
        brojOktava = 2;
    }
    Metalofon(DinString naz, float cc, float oo, proizvodjaci pp, DinString bb, DinString tt, udarackiVisinaTona visina, int brO)
    {
        naziv = naz;
        cena = cc;
        ocena = oo;
        proizvodjac = pp;
        boja = bb;
        timbre = tt;
        ton = visina;
        brojOktava = brO;
    }
    Metalofon(const Metalofon &m)
    {
        naziv = m.naziv;
        cena = m.cena;
        ocena = m.ocena;
        proizvodjac = m.proizvodjac;
        boja = m.boja;
        timbre = m.timbre;
        ton = m.ton;
    }

    void setBrojOktava(int broj){brojOktava = broj;}

    int getBrojOktava()const{return brojOktava;}

    void ispisMetalofona()
    {
        UdarackiInstrument :: ispisUdarackogInstrumenta();
        cout<<"Broj oktava: "<<getBrojOktava()<<endl;
    }
};

#endif // METALOFON_HPP_INCLUDED
