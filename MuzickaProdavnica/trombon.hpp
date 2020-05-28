#ifndef TROMBON_HPP_INCLUDED
#define TROMBON_HPP_INCLUDED

#include "duvackiinstrument.hpp"

class Trombon : public DuvackiInstrument
{
private:
    trombonVrsta vrstat;
public:

    int trombonID;

    Trombon(){
    cena=1000.00;
    ocena=7.96;
    proizvodjac=yamaha;
    vrsta=limeni;
    vrstat=altTrombon;
    }

    Trombon(float c, float o,proizvodjaci p, duvackiVrsta v, trombonVrsta tv){
        cena=c;
        ocena=o;
        proizvodjac=p;
        vrsta=v;
        vrstat=tv;
    }

    Trombon(const Trombon &t){
        cena=t.cena;
        ocena=t.ocena;
        proizvodjac=t.proizvodjac;
        vrsta=t.vrsta;
        vrstat=t.vrstat;
    }

    int getTrombonID()const;
    string getTrombon()
    {
        switch(vrstat)
        {
        case altTrombon:
            return "Alt";
            break;
        case basTrombon:
            return "Bas";
            break;
        case tenorBasTrombon:
            return "Tenor bas";
            break;
        case tenorTrombon:
            return "Tenor";
            break;
        }
    }
    void setTrombon(trombonVrsta tv){vrstat=tv; }

    void ispisTrombona(){
        cout<<"ID: "<<getTrombonID()<<endl;
        ispisDuvackogInstrumenta();
        cout<<"Vrsta trombona :"<<getTrombon()<<endl;
    }

    void unosTrombona()
    {
       int br;
       cout<<"ID: ";
       cin>>trombonID;
       fflush(stdin);
       unosDuvackogInstrumenta();
       cout<<"Vrsta trombona[1-Alt/2-Bas/3-Tenor bas/4-Tenor]: ";
       cin>>br;
       fflush(stdin);
       switch(br)
       {
       case 1:
           vrstat = altTrombon;
           break;
       case 2:
           vrstat = basTrombon;
           break;
       case 3:
           vrstat = tenorBasTrombon;
           break;
       case 4:
         vrstat = tenorTrombon;
         break;
       }
    }
};

int Trombon::getTrombonID()const {return trombonID;}

void dodajUFajlTrombon()
{
	Trombon t;
	ofstream outFile;
	outFile.open("TROMBON.dat",ios::binary|ios::app);
	t.unosTrombona();
	outFile.write(reinterpret_cast<char *> (&t), sizeof(Trombon));
	outFile.close();
    	cout<<"\n\nTrombon dodat u fajl!";
	cin.ignore();
	cin.get();
}
void ispisiFajlTrombon()
{
	Trombon t;
	ifstream inFile;
	inFile.open("TROMBON.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVEI TROMBONI U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&t), sizeof(Trombon)))
	{
	    t.ispisTrombona();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluTrombon(int n)
{
	Trombon t;
	ifstream inFile;
	inFile.open("TROMBON.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&t), sizeof(Trombon)))
	{
		if(t.getTrombonID()==n)
		{
	  		t.ispisTrombona();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nTrombon ne postoji!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluTrombon(int n)
{
	Trombon t;
	ifstream inFile;
	inFile.open("TROMBON.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempTrombon.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&t), sizeof(Trombon)))
	{
		if(t.getTrombonID()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&t), sizeof(Trombon));
		}
	}
	outFile.close();
	inFile.close();
	remove("TROMBON.dat");
	rename("TempTrombon.dat","TROMBON.dat");
	cout<<"\n\n\tTrombon obrisan!";
	cin.ignore();
	cin.get();
}

#endif // TROMBON_HPP_INCLUDED
