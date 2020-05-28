#ifndef PROIZVOD_HPP_INCLUDED
#define PROIZVOD_HPP_INCLUDED

class Proizvod
{
protected:
    char naziv[20];
    float cena;
    float ocena;
    proizvodjaci proizvodjac;
public:
    Proizvod(){ cena = 4500.00; ocena = 10.00; proizvodjac = ibanez;}
    Proizvod( float c, float o,proizvodjaci p){ cena = c; ocena = o; proizvodjac = p;}
    Proizvod(const Proizvod &p){ cena = p.cena; ocena = p.ocena; proizvodjac = p.proizvodjac;}


    void setCena(float ce){cena = ce;}
    void setOcena(float oc){ocena = oc;}
    void setProizvodjac(proizvodjaci pro){proizvodjac = pro;}

    const char* getNaziv()const {return naziv;}
    float getCena()const{return cena;}
    float getOcena()const{return ocena;}
    string getProizvodjac()const
    {
        switch(proizvodjac)
        {
        case fender:
            return "FENDER";
            break;
        case gibson:
            return "GIBSON";
            break;
        case ibanez:
            return "IBANEZ";
            break;
        case taylor:
            return "TAYLOR";
            break;
        case yamaha:
            return "YAMAHA";
            break;
        default:
            return "Nema proizvodjaca";
            break;
        }
    }

    void ispisProizvoda()
    {
        cout<<"Naziv proizvoda: "<<getNaziv()<<endl;
        cout<<"Cena proizvoda: "<<getCena()<<endl;
        cout<<"Ocena proizvoda: "<<getOcena()<<endl;
        cout<<"Proizvodjac: "<<getProizvodjac()<<endl;
    }

    void unosProizvoda()
    {
        int br;
        cout<<"Naziv: ";
        cin>>naziv;
        fflush(stdin);
        cout<<"Cena: ";
        cin>>cena;
        fflush(stdin);
        cout<<"Ocena: ";
        cin>>ocena;
        fflush(stdin);
        cout<<"Proizvodjac[1-Fender/2-Gibson/3-Ibanez/4-Taylor/5-Yamaha]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            proizvodjac = fender;
            break;
        case 2:
            proizvodjac = gibson;
            break;
        case 3:
            proizvodjac = ibanez;
            break;
        case 4:
            proizvodjac = taylor;
            break;
        case 5:
            proizvodjac = yamaha;
            break;
        }
    }
};

#endif
