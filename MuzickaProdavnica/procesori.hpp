#ifndef PROCESORI_HPP_INCLUDED
#define PROCESORI_HPP_INCLUDED

#include "proizvod.hpp"
enum procesoriVrsta {dinamickiProcesor, ekvilajzer};

class Procesori : public Proizvod 
{
private:
    procesoriVrsta vrsta;
public:

    int procesorID;

    Procesori() : Proizvod()
    {
    vrsta = ekvilajzer;
    }
    Procesori(procesoriVrsta v, float c, float o, proizvodjaci pp) : Proizvod(c,o,pp)
    {
    vrsta = v;
    }

    Procesori(const Procesori &p) : Proizvod((Proizvod)p)
    {
    vrsta = p.vrsta;
    }

    int getProcesorID()const;
    void setVrsta(procesoriVrsta VRSTA) {vrsta = VRSTA;}
    string getVrsta()
    {
    switch(vrsta)
    {
    case dinamickiProcesor:
        return "Dinamicki procesor";
        break;
    case ekvilajzer:
        return "Ekvilajzer";
        break;
    }
    }

    void ispisiProcesor()
    {
    cout<<"ID: "<<getProcesorID()<<endl;
    ispisProizvoda();
    cout<<"Vrsta: "<<getVrsta()<<endl;
    }

    void unesiProcesor()
    {
    int br;
    cout<<"ID: ";
    cin>>procesorID;
    fflush(stdin);
    unosProizvoda();
    cout<<"Vrsta procesora[1-Dinamicki/2-Ekvilajzer]: ";
    cin>>br;
    fflush(stdin);
    switch(br)
    {
    case 1:
    vrsta = dinamickiProcesor;
    break;
    case 2:
    vrsta = ekvilajzer;
    break;
    }
    }
};

int Procesori::getProcesorID()const {return procesorID;}

void dodajUFajlProcesori()
{
	Procesori p;
	ofstream outFile;
	outFile.open("PROCESOR.dat",ios::binary|ios::app);
	p.unesiProcesor();
	outFile.write(reinterpret_cast<char *> (&p), sizeof(Procesori));
	outFile.close();
    	cout<<"\n\nProcesor dodat u fajl!";
	cin.ignore();
	cin.get();
}
void ispisiFajlProcesor()
{
	Procesori p;
	ifstream inFile;
	inFile.open("PROCESOR.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVI PROCESORI U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&p), sizeof(Procesori)))
	{
	    p.ispisiProcesor();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluProcesor(int n)
{
	Procesori p;
	ifstream inFile;
	inFile.open("PROCESOR.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&p), sizeof(Procesori)))
	{
		if(p.getProcesorID()==n)
		{
	  		p.ispisiProcesor();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nProcesor ne postoji!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluProcesor(int n)
{
	Procesori p;
	ifstream inFile;
	inFile.open("PROCESOR.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempProcesor.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&p), sizeof(Procesori)))
	{
		if(p.getProcesorID()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&p), sizeof(Procesori));
		}
	}
	outFile.close();
	inFile.close();
	remove("PROCESOR.dat");
	rename("TempProcesor.dat","PROCESOR.dat");
	cout<<"\n\n\tProcesor obrisan!";
	cin.ignore();
	cin.get();
}
#endif
