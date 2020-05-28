#ifndef PESMA_HPP_INCLUDED
#define PESMA_HPP_INCLUDED

#include "trajanje.hpp"
#include "izvodjac.hpp"
#include "datum.hpp"
#inlcude "zanr.hpp"
#inlcude "tonalitet.hpp"

class Pesma
{
private:
    Trajanje trajanje;
    Izvodjac izvodjac;
    string nazivPesme;
    Datum datumIzdavanja;
    Zanr zanr;
    Tonalitet tonalitett;
public:
    Pesma() : trajanje(), izvodjac(), datumIzdavanja(), zanr(), tonalitett()
    {
        nazivPesme = "Nije unet";
    }

    Pesma(string np, int s, int m, int h, string IME, izvodjacVrsta VRSTA, int GOD, int dan, int mesec, int godina,tipMuzike TIP, zanrovi VRST, tonalitet T, lestvica L) : trajanje(s,m,h), izvodjac(IME, VRSTA, GOD), datumIzdavanja(dan,mesec,godina), zanr(TIP, VRST), tonalitett(T,L)
    {
        nazivPesme = np;
    }

    Pesma(const Pesma &p) : trajanje(p.trajanje), izvodjac(p.izvodjac), datumIzdavanja(p.datumIzdavanja), zanr(p.zanr), tonalitett(p.tonalitett)
    {
        nazivPesme = p.nazivPesme;
    }

    void getTrajanje() {trajanje.Trajanje::ispisTrajanja();}
    void getIzvodjac() {izvodjac.Izvodjac::ispisiIzvodjaca();}
    void getDatumIzdavanja() {datumIzdavanja.Datum::ispisiDatum();}
    string getNazivPesme()const {return nazivPesme;}
    void getZanr() {zanr.Zanr::ispisiZanr();}
    void getTonalitet() {tonalitett.Tonalitet::ispisTonaliteta();}


    void setZanr()
    {
    zanr.Zanr::setTip();
    zanr.Zanr::setVrsta();
    }

    void setTonalitet()
    {
    tonalitett.Tonalitet::unosTonaliteta();
    }

    void setTrajanje()
    {
    int n;
    cout<<"Sati: ";
    cin>>n;
    trajanje.Trajanje::setSate(n);
    cout<<"Minuti: ";
    cin>>n;
    trajanje.Trajanje::setMinute(n);
    cout<<"Sekunde: ";
    cin>>n;
    trajanje.Trajanje::setSekunde(n);
    }

    void setIzvodjac()
    {
    int n;
    string s;
    cout<<"Ime: ";
    cin>>s;
    izvodjac.Izvodjac::setIme(s);
    izvodjac.Izvodjac::setVrsta();
    cout<<"Godine na sceni: ";
    cin>>n;
    izvodjac.Izvodjac::setGodineNaSceni(n);
    }

    void setDatumIzdavanja()
    {
    int n;
    cout<<"Dan: ";
    cin>>n;
    datumIzdavanja.Datum::setDan(n);
    cout<<"Mesec: ";
    cin>>n;
    datumIzdavanja.Datum::setMesec(n);
    cout<<"Godine: ";
    cin>>n;
    datumIzdavanja.Datum::setGodina(n);
    }

    void setNazivPesme(string NP) {nazivPesme = NP;}

    void ispisPesme()
    {
        cout<<"Naziv pesme: "<<getNazivPesme()<<endl;
        getTrajanje();
        getIzvodjac();
        getDatumIzdavanja();
    }

    void unosPesme()
    {
        cout<<"Naziv pesme: ";
        cin>>nazivPesme;
        setTrajanje();
        setIzvodjac();
        setDatumIzdavanja();
    }
};

#endif
