#ifndef LOKACIJA_HPP_INCLUDED
#define LOKACIJA_HPP_INCLUDED

class Lokacija
{
protected:
    string nazivUlice, grad, drzava;
    int brojUlice, postanskiBroj;

public:
    Lokacija()
    {
    nazivUlice = "Nije unet";
    grad = "Nije unet";
    drzava = "Nije uneta";
    brojUlice = 0;
    postanskiBroj = 0;
    }

    Lokacija(string ULICA, string GRAD, string DRZAVA, int BRU, int BRP)
    {
    nazivUlice = ULICA;
    grad = GRAD;
    drzava = DRZAVA;
    brojUlice = BRU;
    postanskiBroj = BRP;
    }

    Lokacija(const Lokacija &l)
    {
    nazivUlice = l.nazivUlice;
    grad = l.grad;
    drzava = l.drzava;
    brojUlice = l.brojUlice;
    postanskiBroj = l.postanskiBroj;
    }

    string getNazivUlice()const {return nazivUlice;}
    string getGrad()const {return grad;}
    string getDrzava()const {return drzava;}
    int getBrojUlice()const {return brojUlice;}
    int getPostanskiBroj()const {return postanskiBroj;}

    void setNazivUlice(string NAZIV) {nazivUlice = NAZIV;}
    void setGrad(string GRAD) {grad = GRAD;}
    void setDrzava(string DRZAVA) {drzava = DRZAVA;}
    void setBrojUlice(int BRU) {brojUlice = BRU;}
    void setPostanskiBroj(int BRP) {postanskiBroj = BRP;}

    void ispisiLokaciju()
    {
        cout<<"Naziv ulice: "<<getNazivUlice()<<endl;
        cout<<"Broj ulice: "<<getBrojUlice()<<endl;
        cout<<"Grad: "<<getGrad()<<endl;
        cout<<"Postanski broj: "<<getPostanskiBroj()<<endl;
        cout<<"Drzava: "<<getDrzava()<<endl;
    }

    void unesiLokaciju()
    {
        cout<<"Naziv ulice: ";
        cin>>nazivUlice;
        cout<<"Broj ulice: ";
        cin>>brojUlice;
        cout<<"Grad: ";
        cin>>grad;
        cout<<"Postanski broj: ";
        cin>>postanskiBroj;
        cout<<"Drzava: ";
        cin>>drzava;
    }

};

#endif // LOKACIJA_HPP_INCLUDED
