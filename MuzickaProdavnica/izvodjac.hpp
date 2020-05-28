#ifndef IZVODJAC_HPP_INCLUDED
#define IZVODJAC_HPP_INCLUDED

enum izvodjacVrsta {solo, grupa};

class Izvodjac
{
private:
    string ime;
    izvodjacVrsta vrsta;
    int godineNaSceni;
public:
    Izvodjac()
    {
        ime = "Nije uneto";
        vrsta = solo;
        godineNaSceni = 0;
    }

    Izvodjac(string IME, izvodjacVrsta VRSTA, int GOD)
    {
        ime = IME;
        vrsta = VRSTA;
        godineNaSceni = GOD;
    }

    Izvodjac(const Izvodjac &i)
    {
        ime = i.ime;
        vrsta = i.vrsta;
        godineNaSceni = i.godineNaSceni;
    }

    void setIme(string IME) {ime = IME;}
    void setVrsta()
    {
        int br;
        cout<<"Vrsta izvodjaca[1-Solo/2-Grupa]: ";
        cin>>br;
        switch(br)
        {
        case 1:
            vrsta = solo;
            break;
        case 2:
            vrsta = grupa;
            break;
        }
    }
    void setGodineNaSceni(int GOD) {godineNaSceni = GOD;}

    string getIme()const {return ime;}
    string getVrsta()const
    {
        switch(vrsta)
        {
        case solo:
            return "Solo";
            break;
        case grupa:
            return "Grupa";
            break;
        }
    }
    int getGodineNaSceni()const {return godineNaSceni;}

    void ispisiIzvodjaca()
    {
        cout<<"Ime: "<<getIme()<<endl;
        cout<<"Vrsta: "<<getVrsta()<<endl;
        cout<<"Godine na sceni: "<<getGodineNaSceni()<<endl;
    }

    void unesiIzvodjaca()
    {
        cout<<"Ime: ";
        cin>>ime;
        setVrsta();
        cout<<"Godine na sceni: ";
        cin>>godineNaSceni;
    }
};

#endif
