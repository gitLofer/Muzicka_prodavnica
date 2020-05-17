#ifndef BUBANJ_HPP_INCLUDED
#define BUBANJ_HPP_INCLUDED

class Bubanj : public UdarackiInstrument
{
private:
    bool glasan;
    bool rezonantan;
    int brojSlojeva;
    bubanjVrsta vrsta;
public:
    Bubanj()
    {
        naziv = "Bubanj";
        cena = 2500.00;
        ocena = 9.0;
        proizvodjac = yamaha;
        boja = "BRAON";
        timbre = "round";
        ton = odredjena;
        glasan = true;
        rezonantan = false;
        brojSlojeva = 2;
        vrsta = bongo;
    }
    Bubanj(DinString naz, float cc, float oo, proizvodjaci pp, DinString bb, DinString tt, udarackiVisinaTona visina,bool glasnoca, bool rez, int brs, bubanjVrsta bub)
    {
        naziv = naz;
        cena = cc;
        ocena = oo;
        proizvodjac = pp;
        boja = bb;
        timbre = tt;
        ton = visina;
        glasan = glasnoca;
        rezonantan = rez;
        brojSlojeva = brs;
        vrsta = bub;
    }
    Bubanj(const Bubanj &b)
    {
        naziv = b.naziv;
        cena = b.cena;
        ocena = b.ocena;
        proizvodjac = b.proizvodjac;
        boja = b.boja;
        timbre = b.timbre;
        ton = b.ton;
        glasan = b.glasan;
        rezonantan = b.rezonantan;
        brojSlojeva = b.brojSlojeva;
        vrsta = b.vrsta;
    }

    void setGlasnoca(bool glas){glasan = glas;}
    void setRezonantan(bool rezon){rezonantan = rezon;}
    void setBrojSlojeva(int br){brojSlojeva = br;}
    void setVrstaBubnjeva(bubanjVrsta vr){vrsta = vr;}

    string getGlasnoca()const
    {
        if(glasan == false)
        {
            return "Nije glasan";
        }else if (glasan == true)
        {
            return "Glasan";
        }else
           return "Nije odredjena glasnoca instrumenta";
    }
    string getRezonantnost()const
    {
        if(rezonantan == false)
        {
            return "Nije rezonantan";
        }else if (rezonantan == true)
        {
            return "Rezonantan";
        }else
           return "Nije odredjena rezonantnost instrumenta";
    }
    int getBrojSlojeva()const{return brojSlojeva;}
    string getVrstaBubnja()const
    {
        switch(vrsta)
        {
        case kongo:
            return "KONGO";
            break;
        case bongo:
            return "BONGO";
            break;
        case djambe:
            return "DJAMBE";
            break;
        case tabla:
            return "TABLA";
            break;
        case timpani:
            return "TIMPANI";
            break;
        case pahu:
            return "PAHU";
            break;
        default:
            return "Nema vrste bubnjeva";
            break;
        }
    }

    void ispisBubnja()
    {
        UdarackiInstrument :: ispisUdarackogInstrumenta();
        cout<<"Glasnost bubnja: "<<getGlasnoca()<<endl;
        cout<<"Rezonantnost bubnja: "<<getRezonantnost()<<endl;
        cout<<"Broj slojeva: "<<getBrojSlojeva()<<endl;
        cout<<"Vrsta bubnjeva: "<<getVrstaBubnja()<<endl;
    }
};

#endif // BUBANJ_HPP_INCLUDED
