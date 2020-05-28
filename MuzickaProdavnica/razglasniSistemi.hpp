#ifndef RAZGLASNISISTEMI_HPP_INCLUDED
#define RAZGLASNISISTEMI_HPP_INCLUDED

#include "proizvod.hpp"
enum razglasniSistemiVrsta {profesionalni, kompaktni};

class RazglasniSistemi : public Proizvod
{
private:
    razglasniSistemiVrsta vrsta;
public:

    int razglasniSistemID;

    RazglasniSistemi()
    {
        cena = 0.00;
        ocena = 1;
        proizvodjac = yamaha;
        vrsta = kompaktni;
    }

    RazglasniSistemi(float CENA, float OCENA, proizvodjaci PROIZVODJAC, razglasniSistemiVrsta VRSTA)
    {
        cena = CENA;
        ocena = OCENA;
        proizvodjac = PROIZVODJAC;
        vrsta = VRSTA;
    }

    RazglasniSistemi(const RazglasniSistemi &rs)
    {
        cena = rs.cena;
        ocena = rs.ocena;
        proizvodjac = rs.proizvodjac;
        vrsta = rs.vrsta;
    }

    int getRazglasniSistemID()const;
    string getVrsta()const
    {
        switch(vrsta)
        {
    case profesionalni:
        return "Profesionalni";
        break;
    case kompaktni:
        return "Kompaktni";
        break;
        }
    }

    void setVrsta()
    {
        int br;
        cout<<"Unesite broj [1-Profesionalni/2-Kompaktni]: "<<endl;
        cin>>br;

        switch(br)
        {
        case 1:
            vrsta = profesionalni;
            break;
        case 2:
            vrsta = kompaktni;
            break;
        }
    }

    void ispisiRazglasniSistem()
    {
        cout<<"ID: "<<getRazglasniSistemID()<<endl;
        ispisProizvoda();
        cout<<"Vrsta: "<<getVrsta()<<endl;
    }

    void unesiRazglasniSistem()
    {
        int br;
        cout<<"ID: ";
        cin>>razglasniSistemID;
        fflush(stdin);
        unosProizvoda();
        setVrsta();
    }

};

int RazglasniSistemi::getRazglasniSistemID()const {return razglasniSistemID;}

void dodajUFajlRazglasniSistemi()
{
	RazglasniSistemi r;
	ofstream outFile;
	outFile.open("RAZGLASNISISTEM.dat",ios::binary|ios::app);
	r.ispisiRazglasniSistem();
	outFile.write(reinterpret_cast<char *> (&r), sizeof(RazglasniSistemi));
	outFile.close();
    	cout<<"\n\nRazglasni sistem dodat u fajl!";
	cin.ignore();
	cin.get();
}

void ispisiFajlRazglasniSistemi()
{
	RazglasniSistemi r;
	ifstream inFile;
	inFile.open("RAZGLASNISISTEMI.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVI RAZGLASNI SISTEMI U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&r), sizeof(RazglasniSistemi)))
	{
	    r.ispisiRazglasniSistem();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluRazglasniSistemi(int n)
{
	RazglasniSistemi r;
	ifstream inFile;
	inFile.open("RAZGLASNISISTEMI.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&r), sizeof(RazglasniSistemi)))
	{
		if(r.getRazglasniSistemID()==n)
		{
	  		r.ispisiRazglasniSistem();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nRazglasni sistem ne postoji!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluRazglasniSistemi(int n)
{
	RazglasniSistemi r;
	ifstream inFile;
	inFile.open("RAZGLASNISISTEMI.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempRazglasniSistemi.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&r), sizeof(RazglasniSistemi)))
	{
		if(r.getRazglasniSistemID()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&r), sizeof(RazglasniSistemi));
		}
	}
	outFile.close();
	inFile.close();
	remove("RAZGLASNISISTEMI.dat");
	rename("TempRazglasniSistemi.dat","RAZGLASNISISTEMI.dat");
	cout<<"\n\n\tRazglasni sistem obrisan!";
	cin.ignore();
	cin.get();
}
#endif
