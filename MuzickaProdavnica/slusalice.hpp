#ifndef SLUSALICE_HPP_INCLUDED
#define SLUSALICE_HPP_INCLUDED

#include "proizvod.hpp"

class Slusalice : public Proizvod
{
private:
    bool saMikrofonom;
    float duzinaKabla;
    string frekventniOdziv, sistem;
public:
    Slusalice()
    {
    naziv = "Nije unet";
    cena = 5999.99;
    ocena = 8.89;
    proizvodjac = yamaha;
    saMikrofonom = true;
    duzinaKabla = 2.5;
    frekventniOdziv = "16Hz - 20kHz";
    sistem = "stereo";
    }

    Slusalice(string NAZIV, float CENA, float OCENA, proizvodjaci PROIZVODJAC, bool MIKROFON, float DUZINA, string FO, string SISTEM)
    {
        naziv = NAZIV;
        cena = CENA;
        ocena = OCENA;
        proizvodjac = PROIZVODJAC;
        saMikrofonom = MIKROFON;
        duzinaKabla = DUZINA;
        frekventniOdziv = FO;
        sistem = SISTEM;
    }

    Slusalice(const Slusalice &s)
    {
        naziv = s.naziv;
        cena = s.cena;
        ocena = s.ocena;
        proizvodjac = s.proizvodjac;
        saMikrofonom = s.saMikrofonom;
        duzinaKabla = s.duzinaKabla;
        frekventniOdziv = s.frekventniOdziv;
        sistem = s.sistem;
    }

    bool getMikrofon()const {return saMikrofonom;}
    float getDuzinaKabla()const {return duzinaKabla;}
    string getFrekventniOdziv()const {return frekventniOdziv;}
    string getSistem()const {return sistem;}

    void setMikrofon(bool MIKROFON) {saMikrofonom = MIKROFON;}
    void setDuzinaKabla(float DUZINA) {duzinaKabla = DUZINA;}
    void setFrekventniOdziv(string FO) {frekventniOdziv = FO;}
    void setSistem(string SISTEM) {sistem = SISTEM;}

};

#endif