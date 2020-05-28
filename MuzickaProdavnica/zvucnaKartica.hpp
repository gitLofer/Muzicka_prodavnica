#ifndef ZVUCNAKARTICA_HPP_INCLUDED
#define ZVUCNAKARTICA_HPP_INCLUDED

#include "proizvod.hpp"
enum zvucnaKarticaVrsta {usb, firewire, thunderbolt};

class ZvucnaKartica : public Proizvod {
private:
    zvucnaKarticaVrsta vrsta;
public:

    int zvucnaKarticaID;

    ZvucnaKartica() : Proizvod()
    {
    vrsta = usb;
    }
    ZvucnaKartica(zvucnaKarticaVrsta v, float c, float o, proizvodjaci pp) : Proizvod(c,o,pp)
    {
    vrsta = v;
    }

    ZvucnaKartica(const ZvucnaKartica &z) : Proizvod((Proizvod)z)
    {
    vrsta = z.vrsta;
    }

    int getZvucnaKarticaID()const;
    void setVrsta(zvucnaKarticaVrsta VRSTA) {vrsta = VRSTA;}
    string getVrsta()
    {
    switch(vrsta)
    {
    case usb:
        return "USB";
        break;
    case firewire:
        return "Firewire";
        break;
    case thunderbolt:
        return "Thunderbolt";
        break;
    }
    }

    void ispisiZvucnuKarticu()
    {
    cout<<"ID: "<<getZvucnaKarticaID()<<endl;
    ispisProizvoda();
    cout<<"Vrsta: "<<getVrsta()<<endl;
    }

    void unesiZvucnuKarticu()
    {
    int br;
    cout<<"ID: ";
    cin>>zvucnaKarticaID;
    fflush(stdin);
    unosProizvoda();
    cout<<"Vrsta [1-Firewire/2-Thunderbolt/3-USB]: ";
    cin>>br;
    fflush(stdin);
    switch(br)
    {
    case 1:
        vrsta = firewire;
        break;
    case 2:
        vrsta = thunderbolt;
        break;
    case 3:
        vrsta = usb;
    }
    }

};

int ZvucnaKartica::getZvucnaKarticaID()const {return zvucnaKarticaID;}

void dodajUFajlZvucnaKartica()
{
	ZvucnaKartica z;
	ofstream outFile;
	outFile.open("ZVUCNAKARTICA.dat",ios::binary|ios::app);
	z.unesiZvucnuKarticu();
	outFile.write(reinterpret_cast<char *> (&z), sizeof(ZvucnaKartica));
	outFile.close();
    	cout<<"\n\nZvucna kartica dodata u fajl!";
	cin.ignore();
	cin.get();
}

void ispisiFajlZvucnaKartica()
{
	ZvucnaKartica z;
	ifstream inFile;
	inFile.open("ZVUCNAKARTICA.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVE ZVUCNE KARTICE U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&z), sizeof(ZvucnaKartica)))
	{
	    z.ispisiZvucnuKarticu();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluZvucnaKartica(int n)
{
	ZvucnaKartica z;
	ifstream inFile;
	inFile.open("ZVUCNAKARTICA.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&z), sizeof(ZvucnaKartica)))
	{
		if(z.getZvucnaKarticaID()==n)
		{
	  		z.ispisiZvucnuKarticu();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nZvucna kartica ne postoji!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluZvucnaKartica(int n)
{
	ZvucnaKartica z;
	ifstream inFile;
	inFile.open("ZVUCNAKARTICA.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempZvucnaKartica.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&z), sizeof(ZvucnaKartica)))
	{
		if(z.getZvucnaKarticaID()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&z), sizeof(ZvucnaKartica));
		}
	}
	outFile.close();
	inFile.close();
	remove("ZVUCNAKARTICA.dat");
	rename("TempZvucnaKartica.dat","ZVUCNAKARTICA.dat");
	cout<<"\n\n\tZvucna kartica obrisana!";
	cin.ignore();
	cin.get();
}
#endif
