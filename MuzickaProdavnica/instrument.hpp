#ifndef INSTRUMENT_HPP_INCLUDED
#define INSTRUMENT_HPP_INCLUDED

class Instrument : public Proizvod
{
protected:
    DinString boja;
    DinString timbre;
public:
    Instrument()
    {
        naziv = "Gitara";
        cena = 15000.00;
        ocena = 9.7;
        proizvodjac = gibson;
        boja = "CRVENA";
        timbre = "sharp";
    }
    Instrument(DinString na, float c, float o, proizvodjaci pp, DinString b, DinString tim)
    {
        naziv = na;
        cena = c;
        ocena = o;
        proizvodjac = pp;
        boja = b;
        timbre = tim;
    }
    Instrument(const Instrument &i)
    {
        naziv = i.naziv;
        cena = i.cena;
        ocena = i.ocena;
        proizvodjac = i.proizvodjac;
        boja = i.boja;
        timbre = i.timbre;
    }

    void setBoja(DinString boj){boja = boj;}
    void setTimbre(DinString ti){timbre = ti;}

    DinString getBoja()const{return boja;}
    DinString getTimbre()const{return timbre;}

    void ispisInstrumenta()
    {
        Proizvod :: ispisProizvoda();
        cout<<"Boja: "<<getBoja()<<endl;
        cout<<"Timbre: "<<getTimbre()<<endl;
    }
};

#endif // INSTRUMENT_HPP_INCLUDED
