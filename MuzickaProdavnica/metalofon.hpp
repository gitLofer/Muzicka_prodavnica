#ifndef METALOFON_HPP_INCLUDED
#define METALOFON_HPP_INCLUDED

#include "udarackiInstrument.hpp"

class Metalofon : public UdarackiInstrument
{
private:
    int brojOktava;
public:

    int metalofonID;

    Metalofon()
    {
        cena = 1000.00;
        ocena = 10.0;
        proizvodjac = yamaha;
        ton = odredjena;
        brojOktava = 2;
    }
    Metalofon(float cc, float oo, proizvodjaci pp, udarackiVisinaTona visina, int brO)
    {
        cena = cc;
        ocena = oo;
        proizvodjac = pp;
        ton = visina;
        brojOktava = brO;
    }
    Metalofon(const Metalofon &m)
    {
        cena = m.cena;
        ocena = m.ocena;
        proizvodjac = m.proizvodjac;
        ton = m.ton;
    }

    int getMetalofonID()const;
    void setBrojOktava(int broj){brojOktava = broj;}

    int getBrojOktava()const{return brojOktava;}

    void ispisMetalofona()
    {
        cout<<"ID: "<<getMetalofonID()<<endl;
        ispisUdarackogInstrumenta();
        cout<<"Broj oktava: "<<getBrojOktava()<<endl;
    }

    void unosMetalofona()
    {
        cout<<"ID: ";
        cin>>metalofonID;
        fflush(stdin);
        unosUdarackogInstrumenta();
        cout<<"Broj oktava: ";
        cin>>brojOktava;
        fflush(stdin);
    }
};

int Metalofon::getMetalofonID()const {return metalofonID;}

void dodajUFajlMetalofon()
{
	Metalofon m;
	ofstream outFile;
	outFile.open("METALOFON.dat",ios::binary|ios::app);
	m.unosMetalofona();
	outFile.write(reinterpret_cast<char *> (&m), sizeof(Metalofon));
	outFile.close();
    	cout<<"\n\nMetalofon dodat u fajl!";
	cin.ignore();
	cin.get();
}
void ispisiFajlMetalofon()
{
	Metalofon m;
	ifstream inFile;
	inFile.open("METALOFON.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVI METALOFONI U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&m), sizeof(Metalofon)))
	{
	    m.ispisMetalofona();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluMetalofon(int n)
{
	Metalofon m;
	ifstream inFile;
	inFile.open("METALOFON.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&m), sizeof(Metalofon)))
	{
		if(m.getMetalofonID()==n)
		{
	  		m.ispisMetalofona();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nMetalofon ne postoji!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluMetalofon(int n)
{
	Metalofon m;
	ifstream inFile;
	inFile.open("METALOFON.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempMetalofon.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&m), sizeof(Metalofon)))
	{
		if(m.getMetalofonID()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&m), sizeof(Metalofon));
		}
	}
	outFile.close();
	inFile.close();
	remove("METALOFON.dat");
	rename("TempMetalofon.dat","METALOFON.dat");
	cout<<"\n\n\tMetalofon obrisan!";
	cin.ignore();
	cin.get();
}

#endif // METALOFON_HPP_INCLUDED
