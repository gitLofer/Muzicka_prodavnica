#ifndef HARFA_HPP_INCLUDED
#define HARFA_HPP_INCLUDED

class Harfa : public ZicaniInstrument
{
private:
    bool elektricna;
    harfaVrsta vrstaHarfe;
public:
    Harfa()
    {
        naziv = "Harfa";
        cena = 20590.00;
        ocena = 7.9;
        proizvodjac = yamaha;
        boja = "ZLATNA";
        timbre = "round";
        brojZica = 48;
        duzinaZice = 2;
        vrstaZica = celik;
        elektricna = false;
        vrstaHarfe = poluga;
    }
    Harfa(DinString naz, float cc, float oo, proizvodjaci pp, DinString bb, DinString tt, int broj, float duzina, zicaVrsta vrs, bool elektro, harfaVrsta harf )
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
        elektricna = elektro;
        vrstaHarfe = harf;
    }
    Harfa(const Harfa &h)
    {
        naziv = h.naziv;
        cena = h.cena;
        ocena = h.ocena;
        proizvodjac = h.proizvodjac;
        boja = h.boja;
        timbre = h.timbre;
        brojZica = h.brojZica;
        duzinaZice = h.duzinaZice;
        vrstaZica = h.vrstaZica;
        elektricna = h.elektricna;
        vrstaHarfe = h.vrstaHarfe;
    }

    void setElektricna(bool elek){elektricna = elek;}
    void setVrstaHarfe(harfaVrsta ha){vrstaHarfe = ha;}

    string getElektricna()const
    {
        if(elektricna == false)
        {
            return "Nije elektricna";
        }else if(elektricna == true)
        {
            return "Jeste elektricna";
        }else
            return "Nema podataka o elektricnosti";
    }
    string getVrstaHarfe()const
    {
        switch(vrstaHarfe)
        {
        case pedala:
            return "PEDALA";
            break;
        case poluga:
            return "POLUGA";
            break;
        default:
            return "Nema vrste harfe";
            break;
        }
    }

    void ispisHarfe()
    {
        ZicaniInstrument :: ispisZicanogInstrumenta();
        cout<<"Elektricna: "<<getElektricna()<<endl;
        cout<<"Vrsta harfe: "<<getVrstaHarfe()<<endl;
    }
};
#endif // HARFA_HPP_INCLUDED
