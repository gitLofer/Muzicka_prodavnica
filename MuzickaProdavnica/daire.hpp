#ifndef DAIRE_HPP_INCLUDED
#define DAIRE_HPP_INCLUDED

#include "udarackiInstrument.hpp"

class Daire : public UdarackiInstrument
{
private:
    char obrucMaterijal[20];
public:

    int daireID;

    Daire()
    {
        cena = 700.00;
        ocena = 10.0;
        proizvodjac = yamaha;
        ton = neodredjena;;
    }
    Daire(float cc, float oo, proizvodjaci pp, udarackiVisinaTona visina)
    {
        cena = cc;
        ocena = oo;
        proizvodjac = pp;
        ton = visina;
    }
    Daire(const Daire &d)
    {
        cena = d.cena;
        ocena = d.ocena;
        proizvodjac = d.proizvodjac;
        ton = d.ton;
    }

    //void setMaterijalObruca(string obruc){obrucMaterijal = obruc;}

    const char* getMaterijalObruca()const{return obrucMaterijal;}
    int getDaireID()const;

    void ispisDaira()
    {
        cout<<"ID: "<<getDaireID()<<endl;
        ispisUdarackogInstrumenta();
        cout<<"Materijal obruca: "<<getMaterijalObruca()<<endl;
    }

    void unosDaira()
    {
        cout<<"ID: ";
        cin>>daireID;
        fflush(stdin);
        unosUdarackogInstrumenta();
        cout<<"Materijal obruca: ";
        cin>>obrucMaterijal;
        fflush(stdin);
    }
};

int Daire::getDaireID()const {return daireID;}

void dodajUFajlDaire()
{
	Daire d;
	ofstream outFile;
	outFile.open("DAIRE.dat",ios::binary|ios::app);
	d.unosDaira();
	outFile.write(reinterpret_cast<char *> (&d), sizeof(Daire));
	outFile.close();
    	cout<<"\n\nDaire dodate u fajl!";
	cin.ignore();
	cin.get();
}
void ispisiFajlDaire()
{
	Daire d;
	ifstream inFile;
	inFile.open("DAIRE.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVE DAIRE U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&d), sizeof(Daire)))
	{
	    d.ispisDaira();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluDaire(int n)
{
	Daire d;
	ifstream inFile;
	inFile.open("DAIRE.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&d), sizeof(Daire)))
	{
		if(d.getDaireID()==n)
		{
	  		 d.ispisDaira();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nDaire ne postoje!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluDaire(int n)
{
	Daire d;
	ifstream inFile;
	inFile.open("DAIRE.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempDaire.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&d), sizeof(Daire)))
	{
		if(d.getDaireID()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&d), sizeof(Daire));
		}
	}
	outFile.close();
	inFile.close();
	remove("DAIRE.dat");
	rename("TempDaire.dat","DAIRE.dat");
	cout<<"\n\n\tDaire obrisane!";
	cin.ignore();
	cin.get();
}

#endif
