#ifndef ALBUM_HPP_INCLUDED
#define ALBUM_HPP_INCLUDED

#include "proizvod.hpp"
#include "lista.hpp"
#include "tekstopisac.hpp"
#include "producent.hpp"
#include "trajanje.hpp"
#include "izvodjac.hpp"
#include "datum.hpp"
#include "zanr.hpp"

class Album : public Proizvod
{
private:
    char nazivAlbuma[20];
    Lista<Pesma> pesme;
    Lista<Tekstopisac> tekstopisci;
    Lista<Producent> producenti;
    Trajanje trajanje;
    Izvodjac izvodjac;
    Datum datumIzdavanja;
    Zanr zanr;
public:

    int AlbumID;

    void setPesmu(Lista<Pesma> PESMA) {pesme = PESMA;}
    void setTekstopisca(Lista<Tekstopisac> TEKSTOPISAC) {tekstopisci = TEKSTOPISAC;}
    void setProducenta(Lista<Producent> PRODUCENT) {producenti = PRODUCENT;}

    Lista<Pesma> getPesmu(){return pesme;}
    Lista<Tekstopisac> getTekstopisca(){return tekstopisci;}
    Lista<Producent> getProducenta(){return producenti;}

    Album& operator+=(Pesma& p) {pesme.dodajElement(pesme.velicina()+1, p); return *this;}
    Album& operator+=(Tekstopisac& t) {tekstopisci.dodajElement(tekstopisci.velicina()+1, t); return *this;}
    Album& operator+=(Producent& p) {producenti.dodajElement(producenti.velicina()+1, p); return *this;}

    void printPesme()
        {
            if(pesme.velicina() == 0) {cout<<endl<<"Nema pesama u albumu!"<<endl;}
            else
            {
                Pesma p;
                cout<<endl<<"Pesme u albumu :"<<endl;
                for (int i = 1; i <= pesme.velicina(); i++) { pesme.izlistaj(i, p); p.ispisPesme(); }
            }
       }

    void printTekstopisce()
        {
            if(tekstopisci.velicina() == 0) {cout<<endl<<"Nema tesktopisaca albuma!"<<endl;}
            else
            {
                Tekstopisac t;
                cout<<endl<<"Tekstopisci albuma :"<<endl;
                for (int i = 1; i <= tekstopisci.velicina(); i++) { tekstopisci.izlistaj(i, t); t.ispisTekstopisca(); }
            }
       }

    void printProducente()
        {
            if(producenti.velicina() == 0) {cout<<endl<<"Nema producenata albuma!"<<endl;}
            else
            {
                Producent p;
                cout<<endl<<"Producenti albuma :"<<endl;
                for (int i = 1; i <= producenti.velicina(); i++) { producenti.izlistaj(i, p); p.ispisProducenta(); }
            }
       }

    int getAlbumID()const {return AlbumID;}
    const char* getNazivAlbuma()const {return nazivAlbuma;}
    void ispisiAlbum()
    {
        cout<<"ID: "<<getAlbumID()<<endl;
        cout<<"Naziv albuma: "<<getNazivAlbuma()<<endl;
        printPesme();
        printTekstopisce();
        printProducente();
        trajanje.ispisTrajanja();
        izvodjac.ispisiIzvodjaca();
        datumIzdavanja.ispisiDatum();
        zanr.ispisiZanr();
    }

    void unesiAlbum()
    {
        int broj;
        string str;
        cout<<"ID: ";
        cin>>AlbumID;
        fflush(stdin);
        cout<<"Naziv albuma: ";
        cin>>nazivAlbuma;
        fflush(stdin);
        cout<<"Koliko pesama zelite da dodate u album? ";
        cin>>broj;

    }
};

#endif
