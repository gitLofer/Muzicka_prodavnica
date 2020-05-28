#ifndef DJOPREMA_HPP_INCLUDED
#define DJOPREMA_HPP_INCLUDED

#include "proizvod.hpp"
enum djOpremaVrsta {djKontroler, djMikseta, djSlusalice, djInterface, djPaket};

class DJOprema : public Proizvod
{
private:
    djOpremaVrsta vrsta;
public:

    int DJOpremaID;

    DJOprema()
    {
        cena = 8000;
        ocena = 9.67;
        proizvodjac = yamaha;
        vrsta = djInterface;
    }

    DJOprema(float CENA, float OCENA, proizvodjaci PROIZVODJAC, djOpremaVrsta VRSTA)
    {
        cena = CENA;
        ocena = OCENA;
        proizvodjac = PROIZVODJAC;
        vrsta = VRSTA;
    }

    DJOprema(const DJOprema &dj)
    {
        cena = dj.cena;
        ocena = dj.ocena;
        proizvodjac = dj.proizvodjac;
        vrsta = dj.vrsta;
    }

    int getDJOpremaID()const;

    string getVrsta()const
    {
        switch(vrsta)
        {
        case djInterface:
            return "DJ interface";
            break;
        case djKontroler:
            return "DJ kontroler";
            break;
        case djMikseta:
            return "DJ mikseta";
            break;
        case djPaket:
            return "DJ paket";
            break;
        case djSlusalice:
            return "DJ Slusalice";
            break;
        }
    }

    void setVrsta()
    {
        int br;
        cout<<"Vrsta [1-DJ interface/2-DJ kontroler/3-DJ mikseta/4-DJ paket/5-DJ slusalice]: ";
        cin>>br;
        fflush(stdin);

        switch(br)
        {
        case 1:
            vrsta = djInterface;
            break;
        case 2:
            vrsta = djKontroler;
            break;
        case 3:
            vrsta = djMikseta;
            break;
        case 4:
            vrsta = djPaket;
            break;
        case 5:
            vrsta = djSlusalice;
            break;
        }
    }

    void ispisiDJOprema()
    {
        cout<<"ID: "<<getDJOpremaID()<<endl;
        ispisProizvoda();
        cout<<"Vrsta: "<<getVrsta()<<endl;
    }

    void unesiDJOprema()
    {
        cout<<"ID: ";
        cin>>DJOpremaID;
        fflush(stdin);
        unosProizvoda();
        setVrsta();
    }
};

int DJOprema::getDJOpremaID()const {return DJOpremaID;}

void dodajUFajlDJOprema()
{
	DJOprema dj;
	ofstream outFile;
	outFile.open("DJOPREMA.dat",ios::binary|ios::app);
	dj.unesiDJOprema();
	outFile.write(reinterpret_cast<char *> (&dj), sizeof(DJOprema));
	outFile.close();
    	cout<<"\n\nDJ oprema dodata u fajl!";
	cin.ignore();
	cin.get();
}
void ispisiFajlDJOprema()
{
	DJOprema dj;
	ifstream inFile;
	inFile.open("DJOPREMA.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVA DJ OPREMA U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&dj), sizeof(DJOprema)))
	{
	    dj.ispisiDJOprema();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluDJOprema(int n)
{
	DJOprema dj;
	ifstream inFile;
	inFile.open("DJOPREMA.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&dj), sizeof(DJOprema)))
	{
		if(dj.getDJOpremaID()==n)
		{
	  		 dj.ispisiDJOprema();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nDJ oprema ne postoji!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluDJOprema(int n)
{
	DJOprema dj;
	ifstream inFile;
	inFile.open("DJOPREMA.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempDJoprema.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&dj), sizeof(DJOprema)))
	{
		if(dj.getDJOpremaID()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&dj), sizeof(DJOprema));
		}
	}
	outFile.close();
	inFile.close();
	remove("DJOPREMA.dat");
	rename("TempDJoprema.dat","DJOPREMA.dat");
	cout<<"\n\n\tDJ oprema obrisana!";
	cin.ignore();
	cin.get();
}

#endif
