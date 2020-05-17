#ifndef UKULELE_HPP_INCLUDED
#define UKULELE_HPP_INCLUDED

class Ukulele : public ZicaniInstrument
{
private:
    ukuleleVrsta vrstaUkulelea;
public:
    Ukulele()
    {
        naziv = "Ukulele";
        cena = 2000.00;
        ocena = 10.0;
        proizvodjac = taylor;
        boja = "TAMNO BRAON";
        timbre = "round";
        brojZica = 4;
        duzinaZice = 0.30;
        vrstaZica = najlon;
        vrstaUkulelea = standard;
    }
    Ukulele(DinString naz, float cc, float oo, proizvodjaci pp, DinString bb, DinString tt, int broj, float duzina, zicaVrsta vrs, ukuleleVrsta uku)
    {
        naziv = naz;
        cena = cc;
        ocena = oo;
        proizvodjac = pp;
        boja = bb;
        timbre = tt;
        brojZica = broj;
        duzinaZice = duzina;
        vrstaZica = vrs;
        vrstaUkulelea = uku;
    }
    Ukulele(const Ukulele &u)
    {
        naziv = u.naziv;
        cena = u.cena;
        ocena = u.ocena;
        proizvodjac = u.proizvodjac;
        boja = u.boja;
        timbre = u.timbre;
        brojZica = u.brojZica;
        duzinaZice = u.duzinaZice;
        vrstaZica = u.vrstaZica;
        vrstaUkulelea = u.vrstaUkulelea;
    }

    void setVrstaUkulelea(ukuleleVrsta vrs){vrstaUkulelea = vrs;}

    string getVrstaUkulelea()const
    {
        switch(vrstaUkulelea)
        {
        case standard:
            return "STANDARD";
            break;
        case koncert:
            return "KONCERT";
            break;
        case tenor:
            return "TENOR";
            break;
        case bariton:
            return "BARITON";
            break;
        default:
            return "Nema vrste ukulelea";
            break;
        }
    }

    void ispisUkulelea()
    {
        ZicaniInstrument :: ispisZicanogInstrumenta();
        cout<<"Vrsta ukulelea: "<<getVrstaUkulelea()<<endl;
    }
};

#endif // UKULELE_HPP_INCLUDED
