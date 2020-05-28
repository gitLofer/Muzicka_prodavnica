#ifndef MIKSER_HPP_INCLUDED
#define MIKSER_HPP_INCLUDED

#include "proizvod.hpp"

class Mikser : Proizvod {
private:
    mikserVrsta vrsta;
public:

    int mikserID;

    Mikser() : Proizvod(){
        vrsta = digitalni;
    }
    Mikser(mikserVrsta mikserType,float c, float o, proizvodjaci pp) : Proizvod( c, o, pp) {
        vrsta = mikserType;
    }
    Mikser(const Mikser &m) : Proizvod((Proizvod)m) {
        vrsta = m.vrsta;
    }

    int getMikserID()const;
    string getMikserVrsta()const
    {
        switch(vrsta)
        {
        case bezEfekata:
            return "Bez efekata";
            break;
        case digitalni:
            return "Digitalni";
            break;
        case power:
            return "Power";
            break;
        case saEfektima:
            return "Sa efektima";
            break;
        }
    }
    void setMikserVrsta (mikserVrsta m) {vrsta = m;}

    void ispisMiksera()
    {
        cout<<"ID: "<<getMikserID()<<endl;
        ispisProizvoda();
        cout<<"Vrsta miksera: "<<getMikserVrsta()<<endl;
    }

    void unosMiksera()
    {
        int br;
        cout<<"ID: ";
        cin>>mikserID;
        fflush(stdin);
        unosProizvoda();
        cout<<"Vrsta miksera[1-Bez efekta/2-Digitalni/3-Power/4-Sa efektima]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrsta = bezEfekata;
            break;
        case 2:
            vrsta = digitalni;
            break;
        case 3:
            vrsta = power;
            break;
        case 4:
            vrsta = saEfektima;
            break;
        }
    }
};

int Mikser::getMikserID()const {return mikserID;}

void dodajUFajlMikser()
{
	Mikser m;
	ofstream outFile;
	outFile.open("MIKSER.dat",ios::binary|ios::app);
	m.unosMiksera();
	outFile.write(reinterpret_cast<char *> (&m), sizeof(Mikser));
	outFile.close();
    	cout<<"\n\nMikser dodat u fajl!";
	cin.ignore();
	cin.get();
}
void ispisiFajlMikser()
{
	Mikser m;
	ifstream inFile;
	inFile.open("MIKSER.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVI MIKSERI U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&m), sizeof(Mikser)))
	{
	    m.ispisMiksera();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluMikser(int n)
{
	Mikser m;
	ifstream inFile;
	inFile.open("MIKSER.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&m), sizeof(Mikser)))
	{
		if(m.getMikserID()==n)
		{
	  		m.ispisMiksera();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nMikser ne postoji!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluMikser(int n)
{
	Mikser m;
	ifstream inFile;
	inFile.open("MIKSER.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempMikser.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&m), sizeof(Mikser)))
	{
		if(m.getMikserID()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&m), sizeof(Mikser));
		}
	}
	outFile.close();
	inFile.close();
	remove("MIKSER.dat");
	rename("TempMikser.dat","MIKSER.dat");
	cout<<"\n\n\tMikser obrisan!";
	cin.ignore();
	cin.get();
}
#endif 
