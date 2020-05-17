#ifndef CINELE_HPP_INCLUDED
#define CINELE_HPP_INCLUDED

class Cinele : public UdarackiInstrument
{
private:
    int precnik;
    cineleVrsta vrsta;
public:
    Cinele()
    {
        naziv = "Cinele";
        cena = 1000.00;
        ocena = 8.0;
        proizvodjac = yamaha;
        boja = "ZLATNA";
        timbre = "round";
        precnik = 20;
        vrsta = splash;
    }
    Cinele(DinString naz, float cc, float oo, proizvodjaci pp, DinString bb, DinString tt, udarackiVisinaTona visina, int pre, cineleVrsta vrs)
    {
        naziv = naz;
        cena = cc;
        ocena = oo;
        proizvodjac = pp;
        boja = bb;
        timbre = tt;
        ton = visina;
        precnik = pre;
        vrsta = vrs;
    }
    Cinele(const Cinele &c)
    {
        naziv = c.naziv;
        cena = c.cena;
        ocena = c.ocena;
        proizvodjac = c.proizvodjac;
        boja = c.boja;
        timbre = c.timbre;
        ton = c.ton;
        precnik = c.precnik;
        vrsta = c.vrsta;
    }

    void setPrencnik(int prec){precnik = prec;}
    void setVrstaCinela(cineleVrsta cinela){vrsta = cinela;}

    int getPrecnik()const{return precnik;}
    string getVrstaCinela()const
    {
        switch(vrsta)
        {
        case orchestral:
            return "ORCHESTRAL";
            break;
        case crash:
            return "CRASH";
            break;
        case hiHats:
            return "HIHATS";
            break;
        case suspended:
            return "SUSPENDED";
            break;
        case splash:
            return "SPLASH";
            break;
        case ancient:
            return "ANCIENT";
            break;
        default:
            return "Nema vrste cinela";
            break;
        }
    }

    void ispisCinela()
    {
        UdarackiInstrument :: ispisUdarackogInstrumenta();
        cout<<"Precnik: "<<getPrecnik()<<endl;
        cout<<"Vrsta cinela: "<<getVrstaCinela()<<endl;
    }

};

#endif // CINELE_HPP_INCLUDED
