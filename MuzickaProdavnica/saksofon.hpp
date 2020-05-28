#ifndef SAKSOFON_HPP_INCLUDED
#define SAKSOFON_HPP_INCLUDED

#include "duvackiInstrument.hpp"

class Saksofon: public DuvackiInstrument{
private:
    saksofonVrsta vrstas;
public:
    int saksofonID;

    Saksofon()
    {
    cena=800.00;
    ocena=8.75;
    proizvodjac=yamaha;
    vrsta=drveni;
    vrstas=sopranSaksofon;
    }

    Saksofon(float c, float o,proizvodjaci p, duvackiVrsta v,  saksofonVrsta sv)
    {
        cena=c;
        ocena=o;
        proizvodjac=p;
        vrsta=v;
        vrstas=sv;
    }

    Saksofon(const Saksofon &s)
    {
        cena=s.cena;
        ocena=s.ocena;
        proizvodjac=s.proizvodjac;
        vrsta=s.vrsta;
        vrstas=s.vrstas;
    }

    int getSaksofonID()const;
    string getSaksofon()
    {
        switch(vrstas)
        {
        case altSaksofon:
            return "Alt";
            break;
        case baritonSaksofon:
            return "Bariton";
            break;
        case sopranSaksofon:
            return "Sopran";
            break;
        case tenorSaksofon:
            return "Tenor";
            break;
        }
    }
    void setSaksofon(saksofonVrsta sv){vrstas=sv; }

    void ispisSaksofona()
    {
        cout<<"ID: "<<getSaksofonID()<<endl;
        ispisDuvackogInstrumenta();
        cout<<"Vrsta saksofona :"<<getSaksofon()<<endl;
    }

    void unosSaksofona()
    {
        int br;
        cout<<"ID: ";
        cin>>saksofonID;
        fflush(stdin);
        unosDuvackogInstrumenta();
        cout<<"Vrsta saksofona[1-Alt/2-Bariton/3-Sopran/4-Tenor]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrstas = altSaksofon;
            break;
        case 2:
            vrstas = baritonSaksofon;
            break;
        case 3:
            vrstas = sopranSaksofon;
            break;
        case 4:
            vrstas = tenorSaksofon;
            break;
        }
    }
};

int Saksofon::getSaksofonID()const {return saksofonID;}

void dodajUFajlSaksofon()
{
	Saksofon s;
	ofstream outFile;
	outFile.open("SAKSOFON.dat",ios::binary|ios::app);
	s.unosSaksofona();
	outFile.write(reinterpret_cast<char *> (&s), sizeof(Saksofon));
	outFile.close();
    	cout<<"\n\nSaksofon dodat u fajl!";
	cin.ignore();
	cin.get();
}
void ispisiFajlSaksofon()
{
	Saksofon s;
	ifstream inFile;
	inFile.open("SAKSOFON.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVI SAKSOFONI U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&s), sizeof(Saksofon)))
	{
	    s.ispisSaksofona();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluSaksofon(int n)
{
	Saksofon s;
	ifstream inFile;
	inFile.open("SAKSOFON.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&s), sizeof(Saksofon)))
	{
		if(s.getSaksofonID()==n)
		{
	  		s.ispisSaksofona();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nSaksofon ne postoji!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluSaksofon(int n)
{
	Saksofon s;
	ifstream inFile;
	inFile.open("SAKSOFON.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempSaksofon.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&s), sizeof(Saksofon)))
	{
		if(s.getSaksofonID()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&s), sizeof(Saksofon));
		}
	}
	outFile.close();
	inFile.close();
	remove("SAKSOFON.dat");
	rename("TempSaksofon.dat","SAKSOFON.dat");
	cout<<"\n\n\tSaksofon obrisan!";
	cin.ignore();
	cin.get();
}

#endif // SAKSOFON_HPP_INCLUDED
