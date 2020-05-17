#ifndef DAIRE_HPP_INCLUDED
#define DAIRE_HPP_INCLUDED

class Daire : public UdarackiInstrument
{
private:
    DinString obrucMaterijal;
public:
    Daire()
    {
        naziv = "Daire";
        cena = 700.00;
        ocena = 10.0;
        proizvodjac = yamaha;
        boja = "SVETLO BRAON";
        timbre = "sharp";
        ton = neodredjena;
        obrucMaterijal = "DRVENI";
    }
    Daire(DinString naz, float cc, float oo, proizvodjaci pp, DinString bb, DinString tt, udarackiVisinaTona visina, DinString materijal)
    {
        naziv = naz;
        cena = cc;
        ocena = oo;
        proizvodjac = pp;
        boja = bb;
        timbre = tt;
        ton = visina;
        obrucMaterijal = materijal;
    }
    Daire(const Daire &d)
    {
        naziv = d.naziv;
        cena = d.cena;
        ocena = d.ocena;
        proizvodjac = d.proizvodjac;
        boja = d.boja;
        timbre = d.timbre;
        ton = d.ton;
        obrucMaterijal = d.obrucMaterijal;
    }

    void setMaterijalObruca(DinString obruc){obrucMaterijal = obruc;}

    DinString getMaterijalObruca()const{return obrucMaterijal;}

    void ispisDaira()
    {
        UdarackiInstrument :: ispisUdarackogInstrumenta();
        cout<<"Materijal obruca: "<<getMaterijalObruca()<<endl;
    }
};

#endif // DAIRE_HPP_INCLUDED
