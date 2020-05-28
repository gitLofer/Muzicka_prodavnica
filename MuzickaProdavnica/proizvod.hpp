#ifndef PROIZVOD_HPP_INCLUDED
#define PROIZVOD_HPP_INCLUDED

#include <string>
using namespace std;

enum proizvodjaci {fender, gibson, ibanez, taylor, yamaha};
enum zicaVrsta {nikl, celik, najlon};
enum gitaraVrsta {klasicnaGitara, akusticnaGitara, elektroAkusticnaGitara, elektricnaGitara, basGitara};
enum ukuleleVrsta {standard, koncert, tenor, bariton};
enum harfaVrsta {pedala, poluga};
enum bubanjVrsta {kongo, bongo, djambe, tabla, timpani, pahu};
enum cineleVrsta {orchestral, crash, hiHats, suspended, splash, ancient};
enum drvoVrsta {jasen, javor, mahagoni};
enum trubaVrsta {visokaTruba, altTruba, basTruba};
enum duvackiVrsta {limeni, drveni};
enum trombonVrsta {altTrombon, tenorTrombon, basTrombon, tenorBasTrombon};
enum hornaVrsta {jednostruka, dvostruka, odvojivoZvono};
enum tubaVrsta {kontrabasTuba, basTuba, tenorTuba, subKontrabasTuba};
enum klarinetVrsta {klarinetA, klarinetBb, harmonijskiKlarinet};
enum oboaVrsta {baroknaOboa, klasicnaOboa, beckaOboa, modernaOboa};
enum saksofonVrsta {sopranSaksofon, altSaksofon, tenorSaksofon, baritonSaksofon};
enum flautaVrsta {standardna, pikolo, harmonijska};
enum klavirVrsta {elektricni, pianino, koncertni, polukoncertni};
enum violinaVrsta {klasicnaViolina, baroknaViolina, strohViolina, elektricnaViolina, poluelektricnaViolina};
enum violaVrsta {akusticnaViola, elektricnaViola, elektricnoAkusticnaViola};
enum violonceloVrsta {carbonFiberVioloncelo, fullSizeVioloncelo, akusticnoVioloncelo, raznaVioloncela, elektricnoVioloncelo};
enum kontrabasVrsta {dupliBas, violona, oktobas, dalaruan, dadihu};
enum mikserVrsta {saEfektima, bezEfekata, power, digitalni};
enum zvucnaKutijaVrsta {aktivna, pasivna, subwoofer};
enum pojacalaVrsta {tube, solidState, modelling, hybrid};
enum procesoriVrsta {dinamickiProcesor, ekvilajzer};
enum mikrofonVrsta {zicani, bezicni, studijski};
enum zvucnaKarticaVrsta {usb, firewire, thunderbolt};
enum razglasniSistemiVrsta {profesionalni, kompaktni};
enum miksetaVrsta {analogna, digitalna};
enum kontrolerVrsta {recording, keyboard, pad, monitor};
enum harmonikaVrsta {obicna, usnena};
enum instrumentOpremaVrsta {stalak, lampa, stolica, metronom, stimer, zvucnaViljuska, kapodaster};
enum udarackiVisinaTona {odredjena, neodredjena};
enum djOpremaVrsta {djKontroler, djMikseta, djSlusalice, djInterface, djPaket};
enum zaUcenjeVrsta {knjiga, disk, notnaSveska};
enum izvodjacVrsta {solo, grupa};
enum tipMuzike {vokalna, instrumentalna, vokalnoInstrumentalna};
enum zanrovi {alternative, bluz, rege, pop, rok, hiphop, dzez, dens, klasicna, kantri, metal};
enum tipGudala {NEMACKI, FRANCUSKI};
enum tonalitet {C, Csharp, D, Dsharp, E, F, Fsharp, G, Gsharp, A, Asharp, B};
enum lestvica {mol, dur};

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
