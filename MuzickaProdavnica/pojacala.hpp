#ifndef POJACALA_HPP_INCLUDED
#define POJACALA_HPP_INCLUDED

#include "proizvod.hpp"
enum pojacalaVrsta {tube, solidState, modelling, hybrid};


class Pojacala : public Proizvod {
private:
    pojacalaVrsta vrsta;
public:
    int pojacaloID;

    Pojacala() : Proizvod()
    {
    pojacaloID = 0;
    vrsta = hybrid;
    }
    Pojacala( int id, pojacalaVrsta v, float c, float o, proizvodjaci pp) : Proizvod(c,o,pp)
    {
    pojacaloID = id;
    vrsta = v;
    }

    Pojacala(const Pojacala &p)
    {
      pojacaloID = p.pojacaloID;
      cena = p.cena;
      ocena = p.ocena;
      proizvodjac = p.proizvodjac;
      vrsta = p.vrsta;
    }

    void setVrsta(pojacalaVrsta VRSTA) {vrsta = VRSTA;}
    void setPojacaloID(int id) {pojacaloID = id;}

    string getVrsta()
    {
    switch(vrsta)
    {
    case tube:
        return "Tube";
        break;
    case solidState:
        return "Solid state";
        break;
    case modelling:
        return "Modelling";
        break;
    case hybrid:
        return "Hybrid";
        break;
    }
    }
    int getPojacaloID()const;

    void ispisiPojacala()
    {
    cout<<"ID: "<<getPojacaloID()<<endl;
    ispisProizvoda();
    cout<<"Vrsta: "<<getVrsta()<<endl;
    }

    void unesiPojacala()
    {
    int br;
    cout<<"ID: ";
    cin>>pojacaloID;
    unosProizvoda();
    cout<<"Vrsta[1-Tube/2-Solid state/3-Modelling/4-Hybrid]: ";
    cin>>br;
    switch(br)
    {
    case 1:
        vrsta = tube;
        break;
    case 2:
        vrsta = solidState;
        break;
    case 3:
        vrsta = modelling;
        break;
    case 4:
        vrsta = hybrid;
        break;
    }
    }

};

int Pojacala::getPojacaloID()const {return pojacaloID;}

void dodajUFajlPojacalo()
{
	Pojacala p;
	ofstream outFile;
	outFile.open("POJACALO.dat",ios::binary|ios::app);
	p.unesiPojacala();
	outFile.write(reinterpret_cast<char *> (&p), sizeof(Pojacala));
	outFile.close();
    	cout<<"\n\nPojacalo upisano u fajl! ";
	cin.ignore();
	cin.get();
}
void ispisiFajlPojacalo()
{
	Pojacala p;
	ifstream inFile;
	inFile.open("POJACALO.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVA POJACALA U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&p), sizeof(Pojacala)))
	{
		p.ispisiPojacala();
		cout<<"\n\n*************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluPojacalo(int n)
{
	Pojacala p;
	ifstream inFile;
	inFile.open("POJACALO.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&p), sizeof(Pojacala)))
	{
		if(p.getPojacaloID()==n)
		{
	  		 p.ispisiPojacala();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nPojacalo ne postoji!";
	cin.ignore();
	cin.get();
}
void obrisiUFajluPojacalo(int n)
{
	Pojacala p;
	ifstream inFile;
	inFile.open("POJACALO.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempPojacalo.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&p), sizeof(Pojacala)))
	{
		if(p.getPojacaloID()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&p), sizeof(Pojacala));
		}
	}
	outFile.close();
	inFile.close();
	remove("POJACALO.dat");
	rename("TempPojacalo.dat","POJACALO.dat");
	cout<<"\n\n\tPojacalo orbisano!";
	cin.ignore();
	cin.get();
}

#endif
