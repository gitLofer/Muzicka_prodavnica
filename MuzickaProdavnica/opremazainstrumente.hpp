#ifndef OPREMAZAINSTRUMENTE_HPP_INCLUDED
#define OPREMAZAINSTRUMENTE_HPP_INCLUDED

#include "proizvod.hpp"
enum instrumentOpremaVrsta {stalak, lampa, stolica, metronom, stimer, zvucnaViljuska, kapodaster};


class OpremaZaInstrumente : public Proizvod
{
private:
    instrumentOpremaVrsta vrsta;
public:

    int opremaID;

    OpremaZaInstrumente()
    {
        cena = 500;
        ocena = 8;
        proizvodjac = yamaha;
        vrsta = metronom;
    }

    OpremaZaInstrumente( float CENA, float OCENA, proizvodjaci PROIZVODJAC, instrumentOpremaVrsta VRSTA)
    {
        cena = CENA;
        ocena = OCENA;
        proizvodjac = PROIZVODJAC;
        vrsta = VRSTA;
    }

    OpremaZaInstrumente(const OpremaZaInstrumente &o)
    {
        cena = o.cena;
        ocena = o.ocena;
        proizvodjac = o.proizvodjac;
        vrsta = o.vrsta;
    }

    int getOpremaID()const;
    string getVrsta()const
    {
        switch(vrsta)
        {
        case kapodaster:
            return "Kapodaster";
            break;
        case metronom:
            return "Metronom";
            break;
        case stalak:
            return "Stalak";
            break;
        case stimer:
            return "Stimer";
            break;
        case stolica:
            return "Stolica";
            break;
        case zvucnaViljuska:
            return "Zvucna viljuska";
            break;
        }
    }

    void setVrsta()
    {
        int br;
        cout<<"Unesite broj [1-Kapodaster/2-Metronom/3-Stalak/4-Stimer/5-Stolica/6-Zvucna viljuska]: "<<endl;
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrsta = kapodaster;
            break;
        case 2:
            vrsta = metronom;
            break;
        case 3:
            vrsta = stalak;
            break;
        case 4:
            vrsta = stimer;
            break;
        case 5:
            vrsta = stolica;
            break;
        case 6:
            vrsta = zvucnaViljuska;
            break;
        }
    }

    void ispisiOpremu()
    {
        cout<<"ID: "<<getOpremaID()<<endl;
        ispisProizvoda();
        cout<<"Vrsta: "<<getVrsta()<<endl;
    }

    void unesiOpremu()
    {
        cout<<"ID: ";
        cin>>opremaID;
        fflush(stdin);
        unosProizvoda();
        setVrsta();
    }
};

int OpremaZaInstrumente::getOpremaID()const {return opremaID;}

void dodajUFajlOpremaZaInstrumente()
{
	OpremaZaInstrumente o;
	ofstream outFile;
	outFile.open("OPREMAZAINSTRUMENTE.dat",ios::binary|ios::app);
	o.unesiOpremu();
	outFile.write(reinterpret_cast<char *> (&o), sizeof(OpremaZaInstrumente));
	outFile.close();
    	cout<<"\n\nOprema dodata u fajl!";
	cin.ignore();
	cin.get();
}

void ispisiFajlOpremaZaInstrumente()
{
	OpremaZaInstrumente o;
	ifstream inFile;
	inFile.open("OPREMAZAINSTRUMENTE.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVA OPREMA ZA INSTRUMENTE U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&o), sizeof(OpremaZaInstrumente)))
	{
	    o.ispisiOpremu();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluOpremaZaInstrumente(int n)
{
	OpremaZaInstrumente o;
	ifstream inFile;
	inFile.open("OPREMAZAINSTRUMENTE.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&o), sizeof(OpremaZaInstrumente)))
	{
		if(o.getOpremaID()==n)
		{
	  		o.ispisiOpremu();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nOorema ne postoji!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluOpremaZaInstrumente(int n)
{
	OpremaZaInstrumente o;
	ifstream inFile;
	inFile.open("OPREMAZAINSTRUMENTE.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempOprema.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&o), sizeof(OpremaZaInstrumente)))
	{
		if(o.getOpremaID()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&o), sizeof(OpremaZaInstrumente));
		}
	}
	outFile.close();
	inFile.close();
	remove("OPREMAZAINSTRUMENTE.dat");
	rename("TempOprema.dat","OPREMAZAINSTRUMENTE.dat");
	cout<<"\n\n\tOprema obrisana!";
	cin.ignore();
	cin.get();
}
#endif
