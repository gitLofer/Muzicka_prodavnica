#ifndef KASTANJETE_HPP_INCLUDED
#define KASTANJETE_HPP_INCLUDED

class Kastanjete : public UdarackiInstrument
{
private:
    drvoVrsta vrsta;
public:
    Kastanjete()
    {
        naziv = "Kastanjete";
        cena = 800.00;
        ocena = 6.0;
        proizvodjac = yamaha;
        boja = "BRAON";
        timbre = "round";
        ton = odredjena;
        vrsta = jasen;
    }
    Kastanjete(DinString naz, float cc, float oo, proizvodjaci pp, DinString bb, DinString tt, udarackiVisinaTona visina, drvoVrsta drv)
    {
        naziv = naz;
        cena = cc;
        ocena = oo;
        proizvodjac = pp;
        boja = bb;
        timbre = tt;
        ton = visina;
        vrsta = drv;
    }
    Kastanjete(const Kastanjete &k)
    {
        naziv = k.naziv;
        cena = k.cena;
        ocena = k.ocena;
        proizvodjac = k.proizvodjac;
        boja = k.boja;
        timbre = k.timbre;
        ton = k.ton;
        vrsta = k.vrsta;
    }

    void setVrsta(drvoVrsta vrs){vrsta = vrs;}

    string getVrstaDrveta()const
    {
        switch(vrsta)
        {
        case jasen:
            return "JASEN";
            break;
        case javor:
            return "JAVOR";
            break;
        case mahagoni:
            return "MAHAGONI";
            break;
        default:
            return "Nema vrste drveta";
            break;
        }
    }

    void ispisKastanjeta()
    {
        UdarackiInstrument :: ispisUdarackogInstrumenta();
        cout<<"Vrsta drveta: "<<getVrstaDrveta()<<endl;
    }
};


#endif // KASTANJETE_HPP_INCLUDED
