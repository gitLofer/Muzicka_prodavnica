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
#include "bubanj.hpp"
#include "cinele.hpp"
#include "daire.hpp"
#include "gitara.hpp"
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

using namespace std;


int meni()
{
int op;
cout<<"Dobrodosli u muzicku prodavnicu! Izaberite opciju."<<endl<<endl;
cout<<"1. Dodaj informacije o kupcu"<<endl;
cout<<"2. Dodaj proizvod"<<endl;
cout<<"3. Pronadji proizvod"<<endl;
cout<<"4. Obrisi proizvod"<<endl;
cout<<"5. Ispisi proizvode klase"<<endl;
cout<<"6. Ispisi sve dodate proizvode"<<endl;
cin >>op;
return op;
}

void ispisiFajlSve()
{
    ispisiFajlBubanj();
    ispisiFajlCinele();
    ispisiFajlDaire();
    ispisiFajlDJOprema();
    ispisiFajlFlauta();
    ispisiFajlGitara();
    ispisiFajlHarfa();
    ispisiFajlHarmonika();
    ispisiFajlHorna();
    ispisiFajlKastanjete();
    ispisiFajlKlarinet();
    ispisiFajlKlavir();
    ispisiFajlKontrabas();
    ispisiFajlKontroler();
    ispisiFajlMetalofon();
    ispisiFajlMikrofon();
    ispisiFajlMikser();
    ispisiFajlMikseta();
    ispisiFajlOboa();
    ispisiFajlOpremaZaInstrumente();
    ispisiFajlSaksofon();
    ispisiFajlProcesor();
    ispisiFajlSlusalice();
    ispisiFajlTrombon();
    ispisiFajlTruba();
    ispisiFajlTuba();
    ispisiFajlUkulele();
    ispisiFajlViola();
    ispisiFajlViolina();
    ispisiFajlVioloncelo();
    ispisiFajlZvucnaKartica();
    ispisiFajlZvucnaKutija();
    ispisiFajlRazglasniSistemi();
    ispisiFajlZaUcenje();
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
    cout<<"35. Album"<<endl;
}

int idUnos()
{
        int ID;
        cout<<"Unesite ID proizvoda: ";
        cin>>ID;
        return ID;
}

int main()
{
    Proizvod P1;
    P1.ispisProizvoda();
    cout<<endl;
    Instrument I;
    I.ispisInstrumenta();
    cout<<endl;
    ZicaniInstrument Z;
    Z.ispisZicanogInstrumenta();
    cout<<endl;
    UdarackiInstrument U;
    U.ispisUdarackogInstrumenta();
    cout<<endl;
    Bubanj B;
    B.ispisBubnja();
    cout<<endl;
    Cinele C;
    C.ispisCinela();
    cout<<endl;
    Daire D;
    D.ispisDaira();
    cout<<endl;
    Gitara G;
    G.ispisGitare();
    cout<<endl;
    Harfa H;
    H.ispisHarfe();
    cout<<endl;
    Kastanjete K;
    K.ispisKastanjeta();
    cout<<endl;
    Ukulele Uk;
    Uk.ispisUkulelea();
    return 0;
}
