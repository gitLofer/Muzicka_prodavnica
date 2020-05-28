#ifndef KLARINET_HPP_INCLUDED
#define KLARINET_HPP_INCLUDED

#include "duvackiinstrument.hpp"

class Klarinet: public DuvackiInstrument{
private:
    char klarinetMaterijal[20];
    klarinetVrsta vrstak;
public:

    int klarinetID;

    Klarinet()
    {
    cena=800.00;
    ocena=8.75;
    proizvodjac=yamaha;
    vrsta=drveni;
    vrstak=harmonijskiKlarinet;
    }

    Klarinet(float c, float o,proizvodjaci p, duvackiVrsta v, klarinetVrsta kv){
        cena=c;
        ocena=o;
        proizvodjac=p;
        vrsta=v;
        vrstak=kv;
    }

    Klarinet(const Klarinet &k)
    {
        cena=k.cena;
        ocena=k.ocena;
        proizvodjac=k.proizvodjac;
        vrsta=k.vrsta;
        vrstak=k.vrstak;
    }

    int getKlarinetID()const;
    const char* getMaterijal()const {return klarinetMaterijal; }
    string getKlarinet()
    {
        switch(vrstak)
        {
        case harmonijskiKlarinet:
            return "Harmonijski";
            break;
        case klarinetA:
            return "A";
            break;
        case klarinetBb:
            return "Bb";
            break;
        }
    }


    void setKlarinet(klarinetVrsta kv){vrstak=kv; }

    void ispisKlarineta()
    {
        cout<<"ID: "<<getKlarinetID()<<endl;
        ispisDuvackogInstrumenta();
        cout<<"Vrsta klarineta :"<<getKlarinet()<<endl;
        cout<<"Materijal klarineta :"<<getMaterijal()<<endl;
    }

    void unosKlarineta()
    {
        int br;
        cout<<"ID: ";
        cin>>klarinetID;
        fflush(stdin);
        unosDuvackogInstrumenta();
        cout<<"Vrsta klarineta[1-Harmonijski/2-A/3-Bb]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrstak = harmonijskiKlarinet;
            break;
        case 2:
            vrstak = klarinetA;
            break;
        case 3:
            vrstak = klarinetBb;
            break;
        }
        cout<<"Materijal klarineta: ";
        cin>>klarinetMaterijal;
        fflush(stdin);
    }

};

int Klarinet::getKlarinetID()const {return klarinetID;}

void dodajUFajlKlarinet()
{
	Klarinet k;
	ofstream outFile;
	outFile.open("KLARINET.dat",ios::binary|ios::app);
	k.unosKlarineta();
	outFile.write(reinterpret_cast<char *> (&k), sizeof(Klarinet));
	outFile.close();
    	cout<<"\n\nKlarinet dodat u fajl!";
	cin.ignore();
	cin.get();
}
void ispisiFajlKlarinet()
{
	Klarinet k;
	ifstream inFile;
	inFile.open("KLARINET.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVI KLARINETI U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&k), sizeof(Klarinet)))
	{
	    k.ispisKlarineta();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluKlarinet(int n)
{
	Klarinet k;
	ifstream inFile;
	inFile.open("KLARINET.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&k), sizeof(Klarinet)))
	{
		if(k.getKlarinetID()==n)
		{
	  		k.ispisKlarineta();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nKlarinet ne postoji!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluKlarinet(int n)
{
	Klarinet k;
	ifstream inFile;
	inFile.open("KLARINET.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempKlarinet.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&k), sizeof(Klarinet)))
	{
		if(k.getKlarinetID()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&k), sizeof(Klarinet));
		}
	}
	outFile.close();
	inFile.close();
	remove("KLARINET.dat");
	rename("TempKlarinet.dat","KLARINET.dat");
	cout<<"\n\n\tKlarinet obrisan!";
	cin.ignore();
	cin.get();
}

#endif // KLARINET_HPP_INCLUDED
