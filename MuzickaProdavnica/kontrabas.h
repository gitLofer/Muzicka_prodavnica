#ifndef KONTRABAS_HPP_INCLUDED
#define KONTRABAS_HPP_INCLUDED

#include "gudackiInstrument.hpp"

class Kontrabas : public GudackiInstrument
{
private:
    kontrabasVrsta vrstak;
    char velicina[20];
public:

    int kontrabasID;

    Kontrabas() : GudackiInstrument()
    {
        vrstak = dupliBas;
    }
   Kontrabas(kontrabasVrsta kontrabasType,tipGudala tipG, int brojZ, zicaVrsta typeOfString, bool electric,float c, float o, proizvodjaci pp)
   : GudackiInstrument( tipG, brojZ,electric,c,o,pp)
   {
        vrstak = kontrabasType;
    }
    Kontrabas(const Kontrabas &v) : GudackiInstrument((GudackiInstrument)v)
    {
        vrstak = v.vrstak;
    }

    int getKontrabasID()const {return kontrabasID;}
    const char* getVelicina()const {return velicina;}
    string getKontrabasVrsta() const
    {
        switch(vrstak)
        {
        case dadihu:
            return "Dadihu";
            break;
        case dalaruan:
            return "Dalaruan";
            break;
        case dupliBas:
            return "Dupli bas";
            break;
        case oktobas:
            return "Oktobas";
            break;
        case violona:
            return "Violona";
            break;
        }
    }

void setKontrabasVrsta(kontrabasVrsta k) {vrstak = k;}

void ispisKontrabasa()
    {
        cout<<"ID: "<<getKontrabasID()<<endl;
        ispisGudackogInstrumenta();
        cout<<"Vrsta kontrabasa: "<<getKontrabasVrsta()<<endl;
        cout<<"Velicina: "<<getVelicina()<<endl;
    }

void unosKontrabasa()
    {
        int br;
        cout<<"ID: ";
        cin>>kontrabasID;
        fflush(stdin);
        unosGudackogInstrumenta();
        cout<<"Vrsta kontrabasa[1-Dadihu/2-Dalaruan/3-Dupli bas/4-Oktobas/5-Violona]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrstak = dadihu;
            break;
        case 2:
            vrstak = dalaruan;
            break;
        case 3:
            vrstak = dupliBas;
            break;
        case 4:
            vrstak = oktobas;
            break;
        case 5:
            vrstak = violona;
            break;
        }
        cout<<"Velicina: ";
        cin>>velicina;
    }
};

void dodajUFajlKontrabas()
{
	Kontrabas k;
	ofstream outFile;
	outFile.open("KONTRABAS.dat",ios::binary|ios::app);
	k.unosKontrabasa();
	outFile.write(reinterpret_cast<char *> (&k), sizeof(Kontrabas));
	outFile.close();
    	cout<<"\n\nKontrabas dodat u fajl!";
	cin.ignore();
	cin.get();
}
void ispisiFajlKontrabas()
{
	Kontrabas k;
	ifstream inFile;
	inFile.open("KONTRABAS.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVI KONTRABASI U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&k), sizeof(Kontrabas)))
	{
	    k.ispisKontrabasa();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluKontrabas(int n)
{
	Kontrabas k;
	ifstream inFile;
	inFile.open("KONTRABAS.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&k), sizeof(Kontrabas)))
	{
		if(k.getKontrabasID()==n)
		{
	  		k.ispisKontrabasa();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nKontrabas ne postoji!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluKontrabas(int n)
{
	Kontrabas k;
	ifstream inFile;
	inFile.open("KONTRABAS.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempKontrabas.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&k), sizeof(Kontrabas)))
	{
		if(k.getKontrabasID()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&k), sizeof(Kontrabas));
		}
	}
	outFile.close();
	inFile.close();
	remove("KONTRABAS.dat");
	rename("TempKontrabas.dat","KONTRABAS.dat");
	cout<<"\n\n\tKontrabas obrisan!";
	cin.ignore();
	cin.get();
}

#endif 
