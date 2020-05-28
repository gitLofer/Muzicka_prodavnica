#ifndef VIOLINA_HPP_INCLUDED
#define VIOLINA_HPP_INCLUDED

#include "gudackiInstrument.hpp"
enum violinaVrsta {klasicnaViolina, baroknaViolina, strohViolina, elektricnaViolina, poluelektricnaViolina};

class Violina : GudackiInstrument
{
private:
    violinaVrsta vrstav;
    char velicina[20];
public:

    int violinaID;

    Violina() : GudackiInstrument(){
        vrstav = klasicnaViolina;
    }
    Violina(violinaVrsta violinaType,tipGudala tipG, int brojZ, zicaVrsta typeOfString, bool electric, float c, float o, proizvodjaci pp)
   : GudackiInstrument( tipG, brojZ,electric, c,o,pp)
   {
        vrstav = violinaType;
    }
    Violina(const Violina &v) : GudackiInstrument((GudackiInstrument)v) {
        vrstav = v.vrstav;
    }

    int getViolinaID()const;
    string getViolinaVrsta () const
    {
        switch(vrstav)
        {
        case baroknaViolina:
            return "Barokna";
            break;
        case elektricnaViolina:
            return "Elektricna";
            break;
        case klasicnaViolina:
            return "Klasicna";
            break;
        case poluelektricnaViolina:
            return "Polu elektricna";
            break;
        case strohViolina:
            return "Stroh";
            break;
        }
    }
    const char* getVelicina () const {return velicina;}

    void setViolinaVrsta (violinaVrsta v) {vrstav = v;}

    void ispisVioline()
    {
        cout<<"ID: "<<getViolinaID()<<endl;
        ispisGudackogInstrumenta();
        cout<<"Vrsta violine: "<<getViolinaVrsta()<<endl;
        cout<<"Velicina: "<<getVelicina()<<endl;
    }

    void unosVioline()
    {
        int br;
        cout<<"ID: ";
        cin>>violinaID;
        fflush(stdin);
        unosGudackogInstrumenta();
        cout<<"Vrsta violine[1-Barokna/2-Elektricna/3-Klasicna/4-Polu elektricna/5-Stroh]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrstav = baroknaViolina;
            break;
        case 2:
            vrstav = elektricnaViolina;
            break;
        case 3:
            vrstav = klasicnaViolina;
            break;
        case 4:
            vrstav = poluelektricnaViolina;
            break;
        case 5:
            vrstav = strohViolina;
            break;
        }
        cout<<"Velicina: ";
        cin>>velicina;
        fflush(stdin);
    }
};

int Violina::getViolinaID()const {return violinaID;}

void dodajUFajlViolina()
{
	Violina v;
	ofstream outFile;
	outFile.open("VIOLINA.dat",ios::binary|ios::app);
	v.unosVioline();
	outFile.write(reinterpret_cast<char *> (&v), sizeof(Violina));
	outFile.close();
    	cout<<"\n\nViolina dodata u fajl!";
	cin.ignore();
	cin.get();
}
void ispisiFajlViolina()
{
	Violina v;
	ifstream inFile;
	inFile.open("VIOLINA.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVE VIOLINE U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&v), sizeof(Violina)))
	{
	    v.ispisVioline();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluViolina(int n)
{
	Violina v;
	ifstream inFile;
	inFile.open("VIOLINA.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&v), sizeof(Violina)))
	{
		if(v.getViolinaID()==n)
		{
	  		v.ispisVioline();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nViolina ne postoji!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluViolina(int n)
{
	Violina v;
	ifstream inFile;
	inFile.open("VIOLINA.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempViolina.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&v), sizeof(Violina)))
	{
		if(v.getViolinaID()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&v), sizeof(Violina));
		}
	}
	outFile.close();
	inFile.close();
	remove("VIOLINA.dat");
	rename("TempViolina.dat","VIOLINA.dat");
	cout<<"\n\nViolina obrisana!";
	cin.ignore();
	cin.get();
}
#endif
