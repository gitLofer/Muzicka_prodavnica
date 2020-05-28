#ifndef KASTANJETE_HPP_INCLUDED
#define KASTANJETE_HPP_INCLUDED

#include "udarackiInstrument.hpp"

class Kastanjete : public UdarackiInstrument
{
private:
    drvoVrsta vrsta;
public:
    int kastanjeteID;

    /// Constructors
    Kastanjete()
    {
        cena = 800.00;
        ocena = 6.0;
        proizvodjac = yamaha;
        ton = odredjena;
        vrsta = jasen;
    }
    Kastanjete( float cc, float oo, proizvodjaci pp,  udarackiVisinaTona visina, drvoVrsta drv)
    {
        cena = cc;
        ocena = oo;
        proizvodjac = pp;
        ton = visina;
        vrsta = drv;
    }
    Kastanjete(const Kastanjete &k)
    {
        cena = k.cena;
        ocena = k.ocena;
        proizvodjac = k.proizvodjac;
        ton = k.ton;
        vrsta = k.vrsta;
    }

    /// Functions
    void setVrsta(drvoVrsta vrs){vrsta = vrs;}

    int getKastanjeteID()const;
    string getVrstaDrveta()const
    {
        switch(vrsta)
        {
        case jasen:
            return "JASEN";
            break;
        case javor:
            return "JAVOR";
            break;
        case mahagoni:
            return "MAHAGONI";
            break;
        default:
            return "Nema vrste drveta";
            break;
        }
    }

    void ispisKastanjeta()
    {
        cout<<"ID: "<<getKastanjeteID()<<endl;
        ispisUdarackogInstrumenta();
        cout<<"Vrsta drveta: "<<getVrstaDrveta()<<endl;
    }

    void unosKastanjeta()
    {
        int br;
        cout<<"ID: ";
        cin>>kastanjeteID;
        fflush(stdin);
        unosUdarackogInstrumenta();
        cout<<"Vrsta drveta[1-Jasen/2-Javor/3-Mahagoni]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrsta = jasen;
            break;
        case 2:
            vrsta = javor;
            break;
        case 3:
            vrsta = mahagoni;
            break;
        }
    }

};

int Kastanjete::getKastanjeteID()const {return kastanjeteID;}

void dodajUFajlKastanjete()
{
	Kastanjete k;
	ofstream outFile;
	outFile.open("KASTANJETE.dat",ios::binary|ios::app);
	k.unosKastanjeta();
	outFile.write(reinterpret_cast<char *> (&k), sizeof(Kastanjete));
	outFile.close();
    	cout<<"\n\nKastanjete dodate u fajl!";
	cin.ignore();
	cin.get();
}
void ispisiFajlKastanjete()
{
	Kastanjete k;
	ifstream inFile;
	inFile.open("KASTANJETE.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVE KASTANJETE U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&k), sizeof(Kastanjete)))
	{
	    k.ispisKastanjeta();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluKastanjete(int n)
{
	Kastanjete k;
	ifstream inFile;
	inFile.open("KASTANJETE.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&k), sizeof(Kastanjete)))
	{
		if(k.getKastanjeteID()==n)
		{
	  		k.ispisKastanjeta();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nKastanjete ne postoje!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluKastanjete(int n)
{
	Kastanjete k;
	ifstream inFile;
	inFile.open("KASTANJETE.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempKastanjete.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&k), sizeof(Kastanjete)))
	{
		if(k.getKastanjeteID()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&k), sizeof(Kastanjete));
		}
	}
	outFile.close();
	inFile.close();
	remove("KASTANJETE.dat");
	rename("TempKastanjete.dat","KASTANJETE.dat");
	cout<<"\n\n\tKastanjete obrisane!";
	cin.ignore();
	cin.get();
}

#endif // KASTANJETE_HPP_INCLUDED
