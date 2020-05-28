#ifndef ZVUCNAKUTIJA_HPP_INCLUDED
#define ZVUCNAKUTIJA_HPP_INCLUDED

#include "proizvod.hpp"

class ZvucnaKutija : public Proizvod {
private:
    zvucnaKutijaVrsta vrsta;
public:

    int zvucnaKutijaID;

    ZvucnaKutija() : Proizvod()
    {
    vrsta = aktivna;
    }

    ZvucnaKutija(zvucnaKutijaVrsta v, float c, float o, proizvodjaci pp) : Proizvod( c,o,pp)
    {
    vrsta = v;
    }

    ZvucnaKutija(const ZvucnaKutija &zk) : Proizvod((Proizvod)zk)
    {
    vrsta = zk.vrsta;
    }

    int getZvucnaKutijaID()const;
    void setVrsta(zvucnaKutijaVrsta VRSTA) {vrsta = VRSTA;}
    string getVrsta()
    {
    switch(vrsta)
    {
    case aktivna:
        return "Aktivna";
        break;
    case pasivna:
        return "Pasivna";
        break;
    case subwoofer:
        return "Subwoofer";
        break;
    }
    }

    void ispisiZvucnuKutiju()
    {
    cout<<"ID: "<<getZvucnaKutijaID()<<endl;
    ispisProizvoda();
    cout<<"Vrsta: "<<getVrsta()<<endl;
    }

    void unesiZvucnuKutiju()
    {
    int br;
    cout<<"ID: ";
    cin>>zvucnaKutijaID;
    fflush(stdin);
    unosProizvoda();
    cout<<"Vrsta [1-Aktivna/2-Pasivna/3-Subwoofer]: ";
    cin>>br;
    fflush(stdin);
    switch(br)
    {
    case 1:
        vrsta = aktivna;
        break;
    case 2:
        vrsta = pasivna;
        break;
    case 3:
        vrsta = subwoofer;
        break;
    }
    }

};

int ZvucnaKutija::getZvucnaKutijaID()const {return zvucnaKutijaID;}

void dodajUFajlZvucnaKutija()
{
	ZvucnaKutija z;
	ofstream outFile;
	outFile.open("ZVUCNAKUTIJA.dat",ios::binary|ios::app);
	z.unesiZvucnuKutiju();
	outFile.write(reinterpret_cast<char *> (&z), sizeof(ZvucnaKutija));
	outFile.close();
    	cout<<"\n\nZvucna kutija dodata u fajl!";
	cin.ignore();
	cin.get();
}

void ispisiFajlZvucnaKutija()
{
	ZvucnaKutija z;
	ifstream inFile;
	inFile.open("ZVUCNAKUTIJA.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVE ZVUCNE KUTIJE U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&z), sizeof(ZvucnaKutija)))
	{
	    z.ispisiZvucnuKutiju();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluZvucnaKutija(int n)
{
	ZvucnaKutija z;
	ifstream inFile;
	inFile.open("ZVUCNAKUTIJA.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&z), sizeof(ZvucnaKutija)))
	{
		if(z.getZvucnaKutijaID()==n)
		{
	  		z.ispisiZvucnuKutiju();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nZvucna kutija ne postoji!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluZvucnaKutija(int n)
{
	ZvucnaKutija z;
	ifstream inFile;
	inFile.open("ZVUCNAKUTIJA.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempZvucnaKutija.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&z), sizeof(ZvucnaKutija)))
	{
		if(z.getZvucnaKutijaID()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&z), sizeof(ZvucnaKutija));
		}
	}
	outFile.close();
	inFile.close();
	remove("ZVUCNAKAUTIJA.dat");
	rename("TempZvucnaKutija.dat","ZVUCNAKUTIJA.dat");
	cout<<"\n\n\tZvucna kutija obrisana!";
	cin.ignore();
	cin.get();
}

#endif // ZVUCNAKUTIJA_HPP_INCLUDED
