#ifndef VIOLA_HPP_INCLUDED
#define VIOLA_HPP_INCLUDED

#include "gudackiInstrument.hpp"
enum violaVrsta {akusticnaViola, elektricnaViola, elektricnoAkusticnaViola};

class Viola : GudackiInstrument {
private:
    violaVrsta vrsta;
    char velicina[20];
public:

    int violaID;

    Viola() : GudackiInstrument(){
        vrsta = akusticnaViola;
    }
    Viola(violaVrsta violaType,tipGudala tipG, int brojZ, zicaVrsta typeOfString, bool electric,float c, float o, proizvodjaci pp)
   : GudackiInstrument(tipG, brojZ,electric, c,o,pp)
   {
        vrsta = violaType;
    }
    Viola(const Viola &v) : GudackiInstrument((GudackiInstrument)v) {
        vrsta = v.vrsta;
    }

    int getViolaID()const;
    string getViolaVrsta () const
    {
        switch(vrsta)
        {
        case akusticnaViola:
            return "Akusticna";
            break;
        case elektricnaViola:
            return "Elektricna";
            break;
        case elektricnoAkusticnaViola:
            return "Elektricno akusticna";
            break;
        }
    }
    const char* getVelicina () const {return velicina;}

    void setViolaVrsta (violaVrsta v) {vrsta = v;}

    void ispisViole()
    {
        cout<<"ID: "<<getViolaID()<<endl;
        ispisGudackogInstrumenta();
        cout<<"Vrsta viole: "<<getViolaVrsta()<<endl;
        cout<<"Velicina: "<<getVelicina()<<endl;
    }

    void unosViole()
    {
        int br;
        cout<<"ID: ";
        cin>>violaID;
        fflush(stdin);
        unosGudackogInstrumenta();
        cout<<"Vrsta viole[1-Akusticna/2-Elektricna/3-Elektricno akusticna]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrsta = akusticnaViola;
            break;
        case 2:
            vrsta = elektricnaViola;
            break;
        case 3:
            vrsta = elektricnoAkusticnaViola;
            break;
        }
        cout<<"Velicina: ";
        cin>>velicina;
        fflush(stdin);
    }
};
int Viola::getViolaID()const {return violaID;}

void dodajUFajlViola()
{
	Viola v;
	ofstream outFile;
	outFile.open("VIOLA.dat",ios::binary|ios::app);
	v.unosViole();
	outFile.write(reinterpret_cast<char *> (&v), sizeof(Viola));
	outFile.close();
    	cout<<"\n\nViola dodata u fajl!";
	cin.ignore();
	cin.get();
}
void ispisiFajlViola()
{
	Viola v;
	ifstream inFile;
	inFile.open("VIOLA.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVE VIOLE U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&v), sizeof(Viola)))
	{
	    v.ispisViole();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluViola(int n)
{
	Viola v;
	ifstream inFile;
	inFile.open("VIOLA.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&v), sizeof(Viola)))
	{
		if(v.getViolaID()==n)
		{
	  		v.ispisViole();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nViola ne postoji!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluViola(int n)
{
	Viola v;
	ifstream inFile;
	inFile.open("VIOLA.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempViola.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&v), sizeof(Viola)))
	{
		if(v.getViolaID()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&v), sizeof(Viola));
		}
	}
	outFile.close();
	inFile.close();
	remove("VIOLA.dat");
	rename("TempViola.dat","VIOLA.dat");
	cout<<"\n\n\tViola obrisana!";
	cin.ignore();
	cin.get();
}
#endif
