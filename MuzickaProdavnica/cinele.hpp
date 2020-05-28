#ifndef CINELE_HPP_INCLUDED
#define CINELE_HPP_INCLUDED

#include "udarackiInstrument.hpp"
enum cineleVrsta {orchestral, crash, hiHats, suspended, splash, ancient};

class Cinele : public UdarackiInstrument
{
private:
    int precnik;
    cineleVrsta vrsta;
public:

    int cineleID;

    Cinele()
    {
        cena = 1000.00;
        ocena = 8.0;
        proizvodjac = yamaha;
        precnik = 20;
        vrsta = splash;
    }
    Cinele(float cc, float oo, proizvodjaci pp, udarackiVisinaTona visina, int pre, cineleVrsta vrs)
    {
        cena = cc;
        ocena = oo;
        proizvodjac = pp;
        ton = visina;
        precnik = pre;
        vrsta = vrs;
    }
    Cinele(const Cinele &c)
    {
        cena = c.cena;
        ocena = c.ocena;
        proizvodjac = c.proizvodjac;
        ton = c.ton;
        precnik = c.precnik;
        vrsta = c.vrsta;
    }

    void setPrencnik(int prec){precnik = prec;}
    void setVrstaCinela(cineleVrsta cinela){vrsta = cinela;}

    int getCineleID()const;
    int getPrecnik()const{return precnik;}
    string getVrstaCinela()const
    {
        switch(vrsta)
        {
        case orchestral:
            return "ORCHESTRAL";
            break;
        case crash:
            return "CRASH";
            break;
        case hiHats:
            return "HIHATS";
            break;
        case suspended:
            return "SUSPENDED";
            break;
        case splash:
            return "SPLASH";
            break;
        case ancient:
            return "ANCIENT";
            break;
        default:
            return "Nema vrste cinela";
            break;
        }
    }

    void ispisCinela()
    {
        cout<<"ID: "<<getCineleID()<<endl;
        ispisUdarackogInstrumenta();
        cout<<"Precnik: "<<getPrecnik()<<endl;
        cout<<"Vrsta cinela: "<<getVrstaCinela()<<endl;
    }

    void unosCinela()
    {
        int br;
        cout<<"ID: ";
        cin>>cineleID;
        unosUdarackogInstrumenta();
        cout<<"Precnik: ";
        cin>>precnik;
        fflush(stdin);
        cout<<"Vrsta cinela[1-Ancient/2-Crash/3-Hi hats/4-Orchestral/5-Splash/6-Suspended]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrsta = ancient;
            break;
        case 2:
            vrsta = crash;
            break;
        case 3:
            vrsta = hiHats;
            break;
        case 4:
            vrsta = orchestral;
            break;
        case 5:
            vrsta = splash;
            break;
        case 6:
            vrsta = suspended;
            break;
        }
    }
};

int Cinele::getCineleID()const {return cineleID;}

void dodajUFajlCinele()
{
	Cinele c;
	ofstream outFile;
	outFile.open("CINELE.dat",ios::binary|ios::app);
	c.unosCinela();
	outFile.write(reinterpret_cast<char *> (&c), sizeof(Cinele));
	outFile.close();
    	cout<<"\n\nCinele dodate u fajl!";
	cin.ignore();
	cin.get();
}
void ispisiFajlCinele()
{
	Cinele c;
	ifstream inFile;
	inFile.open("CINELE.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVE CINELE U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&c), sizeof(Cinele)))
	{
		c.ispisCinela();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluCinele(int n)
{
	Cinele c;
	ifstream inFile;
	inFile.open("CINELE.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&c), sizeof(Cinele)))
	{
		if(c.getCineleID()==n)
		{
	  		 c.ispisCinela();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nCinele ne postoje!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluCinele(int n)
{
	Cinele c;
	ifstream inFile;
	inFile.open("CINELE.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempCinele.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&c), sizeof(Cinele)))
	{
		if(c.getCineleID()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&c), sizeof(Cinele));
		}
	}
	outFile.close();
	inFile.close();
	remove("CINELE.dat");
	rename("TempCinele.dat","CINELE.dat");
	cout<<"\n\n\tCinele obrisane!";
	cin.ignore();
	cin.get();
}

#endif
