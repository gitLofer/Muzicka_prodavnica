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
        godineNaSceni = 5;
    }

    Izvodjac(string IME, izvodjacVrsta VRSTA, int GODINE)
    {
        ime = IME;
        vrsta = VRSTA;
        godineNaSceni = GODINE;
    }

    Izvodjac(const Izvodjac &i)
    {
        ime = i.ime;
        vrsta = i.vrsta;
        godineNaSceni = i.godineNaSceni;
    }

    string getIme()const {return ime;}
    string getVrsta()const
    {
        switch(vrsta)
        {
        case grupa:
            return "Grupa";
            break;
        case solo:
            return "Solo";
            break;
        }
    }
    int getGodineNaSceni()const {return godineNaSceni;}

    void setIme(string IME) {ime = IME;}
    void setGodineNaSceni(int GODINE) {godineNaSceni = GODINE;}
    void setVrsta()
    {
        int br;
        cout<<"Unesite broj [1-Grupa/2-Solo]: "<<endl;
        cin>>br;

        switch(br)
        {
        case 1:
            vrsta = grupa;
            break;
        case 2:
            vrsta = solo;
            break;
        }
    }
};

#endif