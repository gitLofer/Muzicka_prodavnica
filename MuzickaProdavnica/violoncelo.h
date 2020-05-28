#ifndef VIOLONCELO_H_INCLUDED
#define VIOLONCELO_H_INCLUDED

#include "gudackiInstrument.h"

class Violoncelo : GudackiInstrument {
private:
    violonceloVrsta vrstav;
    char velicina[20];
public:

    int violonceloID;

    Violoncelo() : GudackiInstrument(){
        vrstav = carbonFiberVioloncelo;
    }
    Violoncelo(violonceloVrsta violonceloType,tipGudala tipG, int brojZ, zicaVrsta typeOfString, bool electric, float c, float o, proizvodjaci pp)
   : GudackiInstrument( tipG, brojZ,electric, c,o,pp)
   {
        vrstav = violonceloType;
    }
    Violoncelo(const Violoncelo &v) : GudackiInstrument((GudackiInstrument)v) {
        vrstav = v.vrstav;
    }

    int getViolonceloID()const;
    string getViolonceloVrsta () const
    {
        switch(vrstav)
        {
        case akusticnoVioloncelo:
            return "Akusticno";
            break;
        case carbonFiberVioloncelo:
            return "Carbon fiber";
            break;
        case elektricnoVioloncelo:
            return "Violoncelo";
            break;
        case fullSizeVioloncelo:
            return "Full size";
            break;
        case raznaVioloncela:
            return "Razno";
            break;
        }
    }
    const char* getVelicina () const {return velicina;}

    void setViolonceloVrsta (violonceloVrsta v) {vrstav = v;}


    void ispisVioloncela()
    {
        cout<<"ID: "<<getViolonceloID()<<endl;
        ispisGudackogInstrumenta();
        cout<<"Vrsta violoncela: "<<getViolonceloVrsta()<<endl;
        cout<<"Velicina: "<<getVelicina()<<endl;
    }

    void unosVioloncela()
    {
        int br;
        cout<<"ID: ";
        cin>>violonceloID;
        fflush(stdin);
        unosGudackogInstrumenta();
        cout<<"Vrsta violoncela[1-Akusticno/2-Carbon fiber/3-Elektricno/4-Full size/5-Razna]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrstav = akusticnoVioloncelo;
            break;
        case 2:
            vrstav = carbonFiberVioloncelo;
            break;
        case 3:
            vrstav = elektricnoVioloncelo;
            break;
        case 4:
            vrstav  = fullSizeVioloncelo;
            break;
        case 5:
            vrstav = raznaVioloncela;
            break;
        }
        cout<<"Velicina: ";
        cin>>velicina;
        fflush(stdin);
    }
};

int Violoncelo::getViolonceloID()const {return violonceloID;}

void dodajUFajlVioloncelo()
{
	Violoncelo v;
	ofstream outFile;
	outFile.open("VIOLONCELO.dat",ios::binary|ios::app);
	v.unosVioloncela();
	outFile.write(reinterpret_cast<char *> (&v), sizeof(Violoncelo));
	outFile.close();
    	cout<<"\n\nVioloncelo dodato u fajl!";
	cin.ignore();
	cin.get();
}
void ispisiFajlVioloncelo()
{
	Violoncelo v;
	ifstream inFile;
	inFile.open("VIOLONCELO.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVA VIOLONCELA U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&v), sizeof(Violoncelo)))
	{
	    v.ispisVioloncela();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluVioloncelo(int n)
{
	Violoncelo v;
	ifstream inFile;
	inFile.open("VIOLONCELO.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&v), sizeof(Violoncelo)))
	{
		if(v.getViolonceloID()==n)
		{
	  		v.ispisVioloncela();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nVioloncelo ne postoji!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluVioloncelo(int n)
{
	Violoncelo v;
	ifstream inFile;
	inFile.open("VIOLONCELO.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempVioloncelo.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&v), sizeof(Violoncelo)))
	{
		if(v.getViolonceloID()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&v), sizeof(Violoncelo));
		}
	}
	outFile.close();
	inFile.close();
	remove("VIOLONCELO.dat");
	rename("TempVioloncelo.dat","VIOLONCELO.dat");
	cout<<"\n\n\tVioloncelo obrisano!";
	cin.ignore();
	cin.get();
}

#endif // VIOLONCELO_H_INCLUDED
