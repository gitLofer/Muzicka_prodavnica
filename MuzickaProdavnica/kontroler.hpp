#ifndef KONTROLER_HPP_INCLUDED
#define KONTROLER_HPP_INCLUDED

#include "proizvod.hpp"
enum kontrolerVrsta {recording, keyboard, pad, monitor};

class Kontroler : public Proizvod
{
private:
    kontrolerVrsta vrsta;
public:

    int kontrolerID;

    Kontroler()
    {
        cena = 6799.99;
        ocena = 9;
        proizvodjac = yamaha;
        vrsta = recording;
    }

    Kontroler(float CENA, float OCENA, proizvodjaci PROIZVODJAC, kontrolerVrsta VRSTA)
    {
        cena = CENA;
        ocena = OCENA;
        proizvodjac = PROIZVODJAC;
        vrsta = VRSTA;
    }

    Kontroler(const Kontroler &k)
    {
        cena = k.cena;
        ocena = k.ocena;
        proizvodjac = k.proizvodjac;
        vrsta = k.vrsta;
    }

    int getKontrolerID()const;
    string getVrsta()const
    {
        switch(vrsta)
        {
        case keyboard:
            return "Keyboard";
            break;
        case monitor:
            return "Monitor";
            break;
        case pad:
            return "Pad";
            break;
        case recording:
            return "Recording";
            break;
        }
    }

    void setVrsta()
    {
        int br;
        cout<<"Unesite broj [1-Keyboard/2-Monitor/3-Pad/4-Recording]: "<<endl;
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrsta = keyboard;
            break;
        case 2:
            vrsta = monitor;
            break;
        case 3:
            vrsta = pad;
            break;
        case 4:
            vrsta = recording;
            break;
        }
    }

    void ispisiKontroler()
    {
        cout<<"ID: "<<getKontrolerID()<<endl;
        ispisProizvoda();
        cout<<"Vrsta: "<<getVrsta()<<endl;
    }

    void unesiKontroler()
    {
        int br;
        cout<<"ID: ";
        cin>>kontrolerID;
        fflush(stdin);
        unosProizvoda();
        cout<<"Vrsta[1-Keyboard/2-Monitor/3-Pad/4-Recording]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrsta = keyboard;
            break;
        case 2:
            vrsta = monitor;
            break;
        case 3:
            vrsta = pad;
            break;
        case 4:
            vrsta = recording;
                break;
        }
    }
};

int Kontroler::getKontrolerID()const {return kontrolerID;}

void dodajUFajlKontroler()
{
	Kontroler k;
	ofstream outFile;
	outFile.open("KONTROLER.dat",ios::binary|ios::app);
	k.unesiKontroler();
	outFile.write(reinterpret_cast<char *> (&k), sizeof(Kontroler));
	outFile.close();
    	cout<<"\n\nKontroler dodat u fajl!";
	cin.ignore();
	cin.get();
}
void ispisiFajlKontroler()
{
	Kontroler k;
	ifstream inFile;
	inFile.open("KONTROLER.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVI KONTROLERI U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&k), sizeof(Kontroler)))
	{
	    k.ispisiKontroler();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluKontroler(int n)
{
	Kontroler k;
	ifstream inFile;
	inFile.open("KONTROLER.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&k), sizeof(Kontroler)))
	{
		if(k.getKontrolerID()==n)
		{
	  		k.ispisiKontroler();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nKontroler ne postoji!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluKontroler(int n)
{
	Kontroler k;
	ifstream inFile;
	inFile.open("KONTROLER.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempKontroler.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&k), sizeof(Kontroler)))
	{
		if(k.getKontrolerID()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&k), sizeof(Kontroler));
		}
	}
	outFile.close();
	inFile.close();
	remove("KONTROLER.dat");
	rename("TempKontroler.dat","KONTROLER.dat");
	cout<<"\n\n\tKontroler obrisan!";
	cin.ignore();
	cin.get();
}
#endif
