#include<iostream>
#include<fstream>
#include<cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include<cctype>
#include<iomanip>
#include <string>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;

#include "proizvod.hpp"
#include "instrument.hpp"
#include "zicaniInstrument.hpp"
#include "udarackiInstrument.hpp"
#include "gudackiInstrument.h"
#include "duvackiinstrument.hpp"
#include "bubanj.hpp"
#include "cinele.hpp"
#include "daire.hpp"
#include "gitara.hpp"
#include "horna.hpp"
#include "harfa.hpp"
#include "kastanjete.hpp"
#include "metalofon.hpp"
#include "ukulele.hpp"
#include "gudackiInstrument.h"
#include "viola.h"
#include "violina.h"
#include "violoncelo.h"
#include "kontrabas.h"
#include "mikser.h"
#include "policaZicanihInstrumenata.hpp"
#include "policaUdarackihInstrumenata.hpp"
#include "policaDuvackihInstrumenata.hpp"
#include "datum.hpp"
#include "trajanje.hpp"
#include "zvucnaKartica.hpp"
#include "zvucnaKutija.hpp"
#include "tuba.hpp"

using namespace std;


int meni()
{
    int op;
    cout<<"\t\t\t    Dobrodosli u muzicku prodavnicu! Izaberite opciju."<<endl<<endl;
    cout<<"1. Dodaj informacije o kupcu"<<endl<<endl;
    cout<<"2. Dodaj proizvod u fajl"<<endl<<endl;
    cout<<"3. Pronadji proizvod u fajlu"<<endl<<endl;
    cout<<"4. Obrisi proizvod iz fajla"<<endl<<endl;
    cout<<"5. Ispisi sve proizvode u fajlu"<<endl<<endl;
    cout<<"6. Dopuni policu"<<endl<<endl;
    cout<<"7. Ispisi policu"<<endl<<endl;
    cout<<"8. Izadji iz prodavnice"<<endl<<endl<<">>";
    cin >>op;
    return op;
}

void printProizvodOpcije()
{
    cout<<"ZICANI INSTRUMENTI"<<endl;
    cout<<"1. Gitara"<<endl;
    cout<<"2. Ukulele"<<endl;
    cout<<"3. Harfa"<<endl<<endl;

    cout<<"UDARACKI INSTRUMENTI"<<endl;
    cout<<"4. Metalofon"<<endl;
    cout<<"5. Bubanj"<<endl;
    cout<<"6. Cinele"<<endl;
    cout<<"7. Daire"<<endl;
    cout<<"8. Kastanjete"<<endl<<endl;

    cout<<"DUVACKI INSTRUMENTI"<<endl;
    cout<<"9. Truba"<<endl;
    cout<<"10. Horna"<<endl;
    cout<<"11. Tuba"<<endl;
    cout<<"12. Trombon"<<endl;
    cout<<"13. Klarinet"<<endl;
    cout<<"14. Oboa"<<endl;
    cout<<"15. Saksofon"<<endl;
    cout<<"16. Flauta"<<endl<<endl;

    cout<<"GUDACKI INSTRUMENTI"<<endl;
    cout<<"17. Violina"<<endl;
    cout<<"18. Viola"<<endl;
    cout<<"19. Violoncelo"<<endl;
    cout<<"20. Kontrabas"<<endl<<endl;

    cout<<"OSTALI INSTRUMENTI"<<endl;
    cout<<"21. Klavir"<<endl;
    cout<<"22. Harmonika"<<endl<<endl;

    cout<<"OSTALI PROIZVODI"<<endl;
    cout<<"23. Mikser"<<endl;
    cout<<"24. Zvucna kutija"<<endl;
    cout<<"25. Razglasni sistemi"<<endl;
    cout<<"26. Pojacala"<<endl;
    cout<<"27. Procesori"<<endl;
    cout<<"28. Zvucna kartica"<<endl;
    cout<<"29. Mikseta"<<endl;
    cout<<"30. Slusalice"<<endl;
    cout<<"31. Kontroler"<<endl;
    cout<<"32. Oprema za instrumente"<<endl;
    cout<<"33. Mikrofon"<<endl;
    cout<<"34. DJ oprema"<<endl;
    cout<<"35. Za ucenje"<<endl<<endl;;
}

void printPoliceOpcije()
{
    cout<<"1. Polica duvackih instrumenata"<<endl;
    cout<<"2. Polica udarackih instrumenata"<<endl;
    cout<<"3. Polica zicanih instrumenata"<<endl;
    cout<<"4. Polica gudackih instrumenata"<<endl;
    cout<<"5. Polica ostalih instrumenata"<<endl;
    cout<<"6. Polica muzicke opreme"<<endl;
}

void printDuvackiOpcije()
{
    cout<<"1. Flauta"<<endl;
    cout<<"2. Horna"<<endl;
    cout<<"3. Klarinet"<<endl;
    cout<<"4. Oboa"<<endl;
    cout<<"5. Saksofon"<<endl;
    cout<<"6. Trombon"<<endl;
    cout<<"7. Truba"<<endl;
    cout<<"8. Tuba"<<endl;
}

void printUdarackiOpcije()
{
    cout<<"1. Bubanj"<<endl;
    cout<<"2. Daire"<<endl;
    cout<<"3. Cinele"<<endl;
    cout<<"4. Metalofon"<<endl;
    cout<<"5. Kastanjete"<<endl;
}

void printZicaniOpcije()
{
    cout<<"1. Gitara"<<endl;
    cout<<"2. Ukulele"<<endl;
    cout<<"3. Harfa"<<endl;
}

void printGudackiOpcije()
{
    cout<<"1. Violina"<<endl;
    cout<<"2. Viola"<<endl;
    cout<<"3. Violoncelo"<<endl;
    cout<<"4. Kontrabas"<<endl;
}

void printOstaliOpcije()
{
    cout<<"1. Klavir"<<endl;
    cout<<"2. Harmonika"<<endl;
}

void printOpremaOpcije()
{
    cout<<"1. DJ Oprema"<<endl;
    cout<<"2. Kontroler"<<endl;
    cout<<"3. Mikrofon"<<endl;
    cout<<"4. Mikser"<<endl;
    cout<<"5. Oprema za instrumente"<<endl;
}

int idUnos()
{
    int ID;
    cout<<"Unesite ID proizvoda: ";
    cin>>ID;
    return ID;
}

void loadingScreen()
{
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U Z";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U Z I ";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U Z I C ";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U Z I C K";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U Z I C K A";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U Z I C K A  P";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U Z I C K A  P R";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U Z I C K A  P R O";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U Z I C K A  P R O D";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U Z I C K A  P R O D A";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U Z I C K A  P R O D A V";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U Z I C K A  P R O D A V N";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U Z I C K A  P R O D A V N I";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U Z I C K A  P R O D A V N I C ";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(500);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        M U Z I C K A  P R O D A V N I C A";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(1000);
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                        Dobrodosli u muzicku prodavnicu! ^_^";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                     ******************************************";
    Sleep(1000);
    system("cls");
    Sleep(1000);
}

int main()
{
    system("color 57");
    //loadingScreen();

    PolicaDuvackih pd;
    PolicaGudackih pg;
    PolicaUdarackih pu;
    PolicaZicanih pz;
    PolicaOstalihInstrumenata poi;
    PolicaOpreme po;

    int op;
    Kupac k;

    do
    {
        Sleep(1000);
        system("cls");
        op=meni();

        switch(op)
        {

        case 1:
        {
            string str;
            unsigned int i;
            float f;
            cout<<endl;
            k.setUnutra(1);
            cout<<"Ime: ";
            cin >> str;
            k.setIme(str);
            cout<<endl<<"Prezime: ";
            cin >> str;
            k.setPrezime(str);
            cout<<endl<<"Godine: ";
            cin >> i;
            k.setGodine(i);
            cout<<endl<<"Da li zelite da Vam ispisemo unete informacije? ";
            cin >> str;
            cout<<endl;
            if(str=="da")
                k.ispisiKupca();
            break;
        }

        case 2:
        {
            cout<<"Koji proizvod zelite da dodate?"<<endl<<endl;
            printProizvodOpcije();
            int opp;
            cout<<">>";
            cin>>opp;

            if(opp==1)
            {
                dodajUFajlGitara();
            }
            else if(opp==2)
            {
                dodajUFajlUkulele();
            }
            else if(opp==3)
            {
                dodajUFajlHarfa();
            }
            else if(opp==4)
            {
                dodajUFajlMetalofon();
            }
            else if(opp==5)
            {
                dodajUFajlBubanj();
            }
            else if(opp==6)
            {
                dodajUFajlCinele();
            }
            else if(opp==7)
            {
                dodajUFajlDaire();
            }
            else if(opp==8)
            {
                dodajUFajlKastanjete();
            }
            else if(opp==9)
            {
                dodajUFajlTruba();
            }
            else if(opp==10)
            {
                dodajUFajlHorna();
            }
            else if(opp==11)
            {
                dodajUFajlTuba();
            }
            else if(opp==12)
            {
                dodajUFajlTrombon();
            }
            else if(opp==13)
            {
                dodajUFajlKlarinet();
            }
            else if(opp==14)
            {
                dodajUFajlOboa();
            }
            else if(opp==15)
            {
                dodajUFajlSaksofon();
            }
            else if(opp==16)
            {
                dodajUFajlFlauta();
            }
            else if(opp==17)
            {
                dodajUFajlViolina();
            }
            else if(opp==18)
            {
                dodajUFajlViola();
            }
            else if(opp==19)
            {
                dodajUFajlVioloncelo();
            }
            else if(opp==20)
            {
                dodajUFajlKontrabas();
            }
            else if(opp==21)
            {
                dodajUFajlKlavir();
            }
            else if(opp==22)
            {
                dodajUFajlHarmonika();
            }
            else if(opp==23)
            {
                dodajUFajlMikser();
            }
            else if(opp==24)
            {
                dodajUFajlZvucnaKutija();
            }
            else if(opp==25)
            {
                dodajUFajlRazglasniSistemi();
            }
            else if(opp==26)
            {
                dodajUFajlPojacalo();
            }
            else if(opp==27)
            {
                dodajUFajlProcesori();
            }
            else if(opp==28)
            {
                dodajUFajlZvucnaKartica();
            }
            else if(opp==29)
            {
                dodajUFajlMikseta();
            }
            else if(opp==30)
            {
                dodajUFajlSlusalice();
            }
            else if(opp==31)
            {
                dodajUFajlKontroler();
            }
            else if(opp==32)
            {
                dodajUFajlOpremaZaInstrumente();
            }
            else if(opp==33)
            {
                dodajUFajlMikrofon();
            }
            else if(opp==34)
            {
                dodajUFajlDJOprema();
            }
            else if(opp==35)
            {
                dodajUFajlZaUcenje();
            }
            break;
        }

        case 3:
        {
            cout<<"Koji proizvod zelite da potrazite?"<<endl<<endl;
            printProizvodOpcije();
            int opp;
            cout<<">>";
            cin>>opp;

            if(opp==1)
            {
                int ID = idUnos();
                potraziUFajluGitara(ID);
            }
            else if(opp==2)
            {
                int ID = idUnos();
                potraziUFajluUkulele(ID);
            }
            else if(opp==3)
            {
                int ID = idUnos();
                potraziUFajluHarfa(ID);
            }
            else if(opp==4)
            {
                int ID = idUnos();
                potraziUFajluMetalofon(ID);
            }
            else if(opp==5)
            {
                int ID = idUnos();
                potraziUFajluBubanj(ID);
            }
            else if(opp==6)
            {
                int ID = idUnos();
                potraziUFajluCinele(ID);
            }
            else if(opp==7)
            {
                int ID = idUnos();
                potraziUFajluDaire(ID);
            }
            else if(opp==8)
            {
                int ID = idUnos();
                potraziUFajluKastanjete(ID);
            }
            else if(opp==9)
            {
                int ID = idUnos();
                potraziUFajluTruba(ID);
            }
            else if(opp==10)
            {
                int ID = idUnos();
                potraziUFajluHorna(ID);
            }
            else if(opp==11)
            {
                int ID = idUnos();
                potraziUFajluTuba(ID);
            }
            else if(opp==12)
            {
                int ID = idUnos();
                potraziUFajluTrombon(ID);
            }
            else if(opp==13)
            {
                int ID = idUnos();
                potraziUFajluKlarinet(ID);
            }
            else if(opp==14)
            {
                int ID = idUnos();
                potraziUFajluOboa(ID);
            }
            else if(opp==15)
            {
                int ID = idUnos();
                potraziUFajluSaksofon(ID);
            }
            else if(opp==16)
            {
                int ID = idUnos();
                potraziUFajluFlauta(ID);
            }
            else if(opp==17)
            {
                int ID = idUnos();
                potraziUFajluViolina(ID);
            }
            else if(opp==18)
            {
                int ID = idUnos();
                potraziUFajluViola(ID);
            }
            else if(opp==19)
            {
                int ID = idUnos();
                potraziUFajluVioloncelo(ID);
            }
            else if(opp==20)
            {
                int ID = idUnos();
                potraziUFajluKontrabas(ID);
            }
            else if(opp==21)
            {
                int ID = idUnos();
                potraziUFajluKlavir(ID);
            }
            else if(opp==22)
            {
                int ID = idUnos();
                potraziUFajluHarmonika(ID);
            }
            else if(opp==23)
            {
                int ID = idUnos();
                potraziUFajluMikser(ID);
            }
            else if(opp==24)
            {
                int ID = idUnos();
                potraziUFajluZvucnaKutija(ID);
            }
            else if(opp==25)
            {
                int ID = idUnos();
                potraziUFajluRazglasniSistemi(ID);
            }
            else if(opp==26)
            {
                int ID = idUnos();
                potraziUFajluPojacalo(ID);
            }
            else if(opp==27)
            {
                int ID = idUnos();
                potraziUFajluProcesor(ID);
            }
            else if(opp==28)
            {
                int ID = idUnos();
                potraziUFajluZvucnaKartica(ID);
            }
            else if(opp==29)
            {
                int ID = idUnos();
                potraziUFajluMikseta(ID);
            }
            else if(opp==30)
            {
                int ID = idUnos();
                potraziUFajluSlusalice(ID);
            }
            else if(opp==31)
            {
                int ID = idUnos();
                potraziUFajluKontroler(ID);
            }
            else if(opp==32)
            {
                int ID = idUnos();
                potraziUFajluOpremaZaInstrumente(ID);
            }
            else if(opp==33)
            {
                int ID = idUnos();
                potraziUFajluMikrofon(ID);
            }
            else if(opp==34)
            {
                int ID = idUnos();
                potraziUFajluDJOprema(ID);
            }
            else if(opp==35)
            {
                int ID = idUnos();
                potraziUFajluZaUcenje(ID);
            }
            break;
        }

        case 4:
        {
            cout<<"Koji proizvod zelite da obrisete?"<<endl<<endl;
            printProizvodOpcije();
            int opp;
            cout<<">>";
            cin>>opp;

            if(opp==1)
            {
                int ID = idUnos();
                obrisiUFajluGitara(ID);
            }
            else if(opp==2)
            {
                int ID = idUnos();
                obrisiUFajluUkulele(ID);
            }
            else if(opp==3)
            {
                int ID = idUnos();
                obrisiUFajluHarfa(ID);
            }
            else if(opp==4)
            {
                int ID = idUnos();
                obrisiUFajluMetalofon(ID);
            }
            else if(opp==5)
            {
                int ID = idUnos();
                obrisiUFajluBubanj(ID);
            }
            else if(opp==6)
            {
                int ID = idUnos();
                obrisiUFajluCinele(ID);
            }
            else if(opp==7)
            {
                int ID = idUnos();
                obrisiUFajluDaire(ID);
            }
            else if(opp==8)
            {
                int ID = idUnos();
                obrisiUFajluKastanjete(ID);
            }
            else if(opp==9)
            {
                int ID = idUnos();
                obrisiUFajluTruba(ID);
            }
            else if(opp==10)
            {
                int ID = idUnos();
                obrisiUFajluHorna(ID);
            }
            else if(opp==11)
            {
                int ID = idUnos();
                obrisiUFajluTuba(ID);
            }
            else if(opp==12)
            {
                int ID = idUnos();
                obrisiUFajluTrombon(ID);
            }
            else if(opp==13)
            {
                int ID = idUnos();
                obrisiUFajluKlarinet(ID);
            }
            else if(opp==14)
            {
                int ID = idUnos();
                obrisiUFajluOboa(ID);
            }
            else if(opp==15)
            {
                int ID = idUnos();
                obrisiUFajluSaksofon(ID);
            }
            else if(opp==16)
            {
                int ID = idUnos();
                obrisiUFajluFlauta(ID);
            }
            else if(opp==17)
            {
                int ID = idUnos();
                obrisiUFajluViolina(ID);
            }
            else if(opp==18)
            {
                int ID = idUnos();
                obrisiUFajluViola(ID);
            }
            else if(opp==19)
            {
                int ID = idUnos();
                obrisiUFajluVioloncelo(ID);
            }
            else if(opp==20)
            {
                int ID = idUnos();
                obrisiUFajluKontrabas(ID);
            }
            else if(opp==21)
            {
                int ID = idUnos();
                obrisiUFajluKlavir(ID);
            }
            else if(opp==22)
            {
                int ID = idUnos();
                obrisiUFajluHarmonika(ID);
            }
            else if(opp==23)
            {
                int ID = idUnos();
                obrisiUFajluMikser(ID);
            }
            else if(opp==24)
            {
                int ID = idUnos();
                obrisiUFajluZvucnaKutija(ID);
            }
            else if(opp==25)
            {
                int ID = idUnos();
                obrisiUFajluRazglasniSistemi(ID);
            }
            else if(opp==26)
            {
                int ID = idUnos();
                obrisiUFajluPojacalo(ID);
            }
            else if(opp==27)
            {
                int ID = idUnos();
                obrisiUFajluProcesor(ID);
            }
            else if(opp==28)
            {
                int ID = idUnos();
                obrisiUFajluZvucnaKartica(ID);
            }
            else if(opp==29)
            {
                int ID = idUnos();
                obrisiUFajluMikseta(ID);
            }
            else if(opp==30)
            {
                int ID = idUnos();
                obrisiUFajluSlusalice(ID);
            }
            else if(opp==31)
            {
                int ID = idUnos();
                obrisiUFajluKontroler(ID);
            }
            else if(opp==32)
            {
                int ID = idUnos();
                obrisiUFajluOpremaZaInstrumente(ID);
            }
            else if(opp==33)
            {
                int ID = idUnos();
                obrisiUFajluMikrofon(ID);
            }
            else if(opp==34)
            {
                int ID = idUnos();
                obrisiUFajluDJOprema(ID);
            }
            else if(opp==35)
            {
                int ID = idUnos();
                obrisiUFajluZaUcenje(ID);
            }
            break;
        }

        case 5:
        {
            cout<<"Koji fajl zelite da ispisete?"<<endl<<endl;
            printProizvodOpcije();
            int opp;
            cout<<">>";
            cin>>opp;

            if(opp==1)
            {
                ispisiFajlGitara();
            }
            else if(opp==2)
            {
                ispisiFajlUkulele();
            }
            else if(opp==3)
            {
                ispisiFajlHarfa();
            }
            else if(opp==4)
            {
                ispisiFajlMetalofon();
            }
            else if(opp==5)
            {
                ispisiFajlBubanj();
            }
            else if(opp==6)
            {
                ispisiFajlCinele();
            }
            else if(opp==7)
            {
                ispisiFajlDaire();
            }
            else if(opp==8)
            {
                ispisiFajlKastanjete();
            }
            else if(opp==9)
            {
                ispisiFajlTruba();
            }
            else if(opp==10)
            {
                ispisiFajlHorna();
            }
            else if(opp==11)
            {
                ispisiFajlTuba();
            }
            else if(opp==12)
            {
                ispisiFajlTrombon();
            }
            else if(opp==13)
            {
                ispisiFajlKlarinet();
            }
            else if(opp==14)
            {
                ispisiFajlOboa();
            }
            else if(opp==15)
            {
                ispisiFajlSaksofon();
            }
            else if(opp==16)
            {
                ispisiFajlFlauta();
            }
            else if(opp==17)
            {
                ispisiFajlViolina();
            }
            else if(opp==18)
            {
                ispisiFajlViola();
            }
            else if(opp==19)
            {
                ispisiFajlVioloncelo();
            }
            else if(opp==20)
            {
                ispisiFajlKontrabas();
            }
            else if(opp==21)
            {
                ispisiFajlKlavir();
            }
            else if(opp==22)
            {
                ispisiFajlHarmonika();
            }
            else if(opp==23)
            {
                ispisiFajlMikser();
            }
            else if(opp==24)
            {
                ispisiFajlZvucnaKutija();
            }
            else if(opp==25)
            {
                ispisiFajlRazglasniSistemi();
            }
            else if(opp==26)
            {
                ispisiFajlPojacalo();
            }
            else if(opp==27)
            {
                ispisiFajlProcesor();
            }
            else if(opp==28)
            {
                ispisiFajlZvucnaKartica();
            }
            else if(opp==29)
            {
                ispisiFajlMikseta();
            }
            else if(opp==30)
            {
                ispisiFajlSlusalice();
            }
            else if(opp==31)
            {
                ispisiFajlKontroler();
            }
            else if(opp==32)
            {
                ispisiFajlOpremaZaInstrumente();
            }
            else if(opp==33)
            {
                ispisiFajlMikrofon();
            }
            else if(opp==34)
            {
                ispisiFajlDJOprema();
            }
            else if(opp==35)
            {
                ispisiFajlZaUcenje();
            }
            break;
        }
        case 6:
        {
            system("cls");
            cout<<"Na koju policu zelite da dodate proizvod?"<<endl<<endl;
            printPoliceOpcije();
            int opp;
            cout<<">>";
            cin>>opp;
            if(opp==1)
            {
                system("cls");
                cout<<"Koji duvacki instrument zelite da dodate na policu?"<<endl<<endl;
                printDuvackiOpcije();
                int opp2;
                cout<<">>";
                cin>>opp2;
                if(opp2==1)
                {
                    Flauta f;
                    f.unosFlaute();
                    pd+=f;
                }
                else if(opp2==2)
                {
                    Horna h;
                    h.unosHorne();
                    pd+=h;
                }
                else if(opp2==3)
                {
                    Klarinet k;
                    k.unosKlarineta();
                    pd+=k;
                }
                else if(opp2==4)
                {
                    Oboa o;
                    o.unosOboe();
                    pd+=o;
                }
                else if(opp2==5)
                {
                    Saksofon s;
                    s.unosSaksofona();
                    pd+=s;
                }
                else if(opp2==6)
                {
                    Trombon t;
                    t.unosTrombona();
                    pd+=t;
                }
                else if(opp2==7)
                {
                    Truba t;
                    t.unosTruba();
                    pd+=t;
                }
                else if(opp2==8)
                {
                    Tuba t;
                    t.unosTube();
                    pd+=t;
                }
            }
            else if(opp==2)
            {
                system("cls");
                cout<<"Koji udaracki instrument zelite da dodate na policu?"<<endl<<endl;
                printUdarackiOpcije();
                int opp2;
                cout<<">>";
                cin>>opp2;
                if(opp2==1)
                {
                    Bubanj b;
                    b.unosBubnja();
                    pu+=b;
                }
                else if(opp2==2)
                {
                    Daire d;
                    d.unosDaira();
                    pu+=d;
                }
                else if(opp2==3)
                {
                    Cinele c;
                    c.unosCinela();
                    pu+=c;
                }
                else if(opp2==4)
                {
                    Metalofon m;
                    m.unosMetalofona();
                    pu+=m;
                }
                else if(opp2==5)
                {
                    Kastanjete k;
                    k.unosKastanjeta();
                    pu+=k;
                }
            }
            else if(opp==3)
            {
                system("cls");
                cout<<"Koji zicani instrument zelite da dodate na policu?"<<endl<<endl;
                printZicaniOpcije();
                int opp2;
                cout<<">>";
                cin>>opp2;
                if(opp2==1)
                {
                    Gitara g;
                    g.unosGitare();
                    pz+=g;
                }
                else if(opp2==2)
                {
                    Ukulele u;
                    u.unosUkulelea();
                    pz+=u;
                }
                else if(opp2==3)
                {
                    Harfa h;
                    h.unosHarfe();
                    pz+=h;
                }
            }
            else if(opp==4)
            {
                system("cls");
                cout<<"Koji gudacki instrument zelite da dodate na policu?"<<endl<<endl;
                printGudackiOpcije();
                int opp2;
                cout<<">>";
                cin>>opp2;
                if(opp2==1)
                {
                    Violina v;
                    v.unosVioline();
                    pg+=v;
                }
                else if(opp2==2)
                {
                    Viola v;
                    v.unosViole();
                    pg+=v;
                }
                else if(opp2==3)
                {
                    Violoncelo v;
                    v.unosVioloncela();
                    pg+=v;
                }
                else if(opp2==4)
                {
                    Kontrabas k;
                    k.unosKontrabasa();
                    pg+=k;
                }
            }
            else if(opp==5)
            {
                system("cls");
                cout<<"Koji instrument zelite da dodate na policu?"<<endl<<endl;
                printOstaliOpcije();
                int opp2;
                cout<<">>";
                cin>>opp2;
                if(opp2==1)
                {
                    Klavir k;
                    k.unosKlavira();
                    poi+=k;
                }
                else if(opp2==2)
                {
                    Harmonika h;
                    h.unosHarmonike();
                    poi+=h;
                }
            }
            else if(opp==6)
            {
                system("cls");
                cout<<"Koju opremu zelite da dodate na policu?"<<endl<<endl;
                printOpremaOpcije();
                int opp2;
                cout<<">>";
                cin>>opp2;
                if(opp2==1)
                {
                    DJOprema d;
                    d.unesiDJOprema();
                    po+=d;
                }
                else if(opp2==2)
                {
                    Kontroler k;
                    k.unesiKontroler();
                    po+=k;
                }
                else if(opp2==3)
                {
                    Mikrofon m;
                    m.unesiMikrofon();
                    po+=m;
                }
                else if(opp2==4)
                {
                    Mikser m;
                    m.unosMiksera();
                    po+=m;
                }
                else if(opp2==5)
                {
                    OpremaZaInstrumente o;
                    o.unesiOpremu();
                    po+=o;
                }
            }
            break;
        }
        case 7:
        {
            system("cls");
            cout<<"Koju policu zelite da ispisete?"<<endl<<endl;
            printPoliceOpcije();
            int opp;
            cout<<">>";
            cin>>opp;
            if(opp==1)
            {
                system("cls");
                pd.ispisPoliceDuvackihInstrumenata();
            }
            else if(opp==2)
            {
                system("cls");
                pu.ispisPolicaUdarackihInstrumenata();
            }
            else if(opp==3)
            {
                system("cls");
                pz.ispisPoliceZicanihInstrumenata();
            }
            else if(opp==4)
            {
                system("cls");
                pg.ispisPoliceGudackihInstrumenataIKlavira();
            }
            else if(opp==5)
            {
                system("cls");
                poi.ispisOstalihInstrumenata();
            }
            else if(opp==6)
            {
                system("cls");
                po.ispisOpremeIn();
            }
            break;
        }
        case 8:
        {
            cout<<endl<<"Dovidjenja!"<<endl;
            exit(0);
        }

        }



    }
    while(op>0 && op<9);

    return 0;
}
