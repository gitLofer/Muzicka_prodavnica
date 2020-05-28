#ifndef UKULELE_HPP_INCLUDED
#define UKULELE_HPP_INCLUDED

#inlcude "ukulele.hpp"
enum ukuleleVrsta {standard, koncert, tenor, bariton};


class Ukulele : public ZicaniInstrument
{
private:
    ukuleleVrsta vrstaUkulelea;
public:

    int ukuleleID;

    Ukulele()
    {
        cena = 2000.00;
        ocena = 10.0;
        proizvodjac = taylor;
        brojZica = 4;
        duzinaZice = 0.30;
        vrstaZica = najlon;
        vrstaUkulelea = standard;
    }
    Ukulele(float cc, float oo, proizvodjaci pp, int broj, float duzina, zicaVrsta vrs, ukuleleVrsta uku)
    {
        cena = cc;
        ocena = oo;
        proizvodjac = pp;
        brojZica = broj;
        duzinaZice = duzina;
        vrstaZica = vrs;
        vrstaUkulelea = uku;
    }
    Ukulele(const Ukulele &u)
    {
        cena = u.cena;
        ocena = u.ocena;
        proizvodjac = u.proizvodjac;
        brojZica = u.brojZica;
        duzinaZice = u.duzinaZice;
        vrstaZica = u.vrstaZica;
        vrstaUkulelea = u.vrstaUkulelea;
    }

    void setVrstaUkulelea(ukuleleVrsta vrs){vrstaUkulelea = vrs;}

    int getUkuleleID()const;
    string getVrstaUkulelea()const
    {
        switch(vrstaUkulelea)
        {
        case standard:
            return "STANDARD";
            break;
        case koncert:
            return "KONCERT";
            break;
        case tenor:
            return "TENOR";
            break;
        case bariton:
            return "BARITON";
            break;
        default:
            return "Nema vrste ukulelea";
            break;
        }
    }

    void ispisUkulelea()
    {
        cout<<"ID: "<<getUkuleleID()<<endl;
        ispisZicanogInstrumenta();
        cout<<"Vrsta ukulelea: "<<getVrstaUkulelea()<<endl;
    }

    void unosUkulelea()
    {
        int br;
        cout<<"ID: ";
        cin>>ukuleleID;
        fflush(stdin);
        unosZicanogInstrumenta();
        cout<<"Vrsta ukulelea[1-Bariton/2-Koncert/3-Standard/4-Tenor]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrstaUkulelea = bariton;
            break;
        case 2:
            vrstaUkulelea = koncert;
            break;
        case 3:
            vrstaUkulelea = standard;
            break;
        case 4:
            vrstaUkulelea = tenor;
            break;
        }
    }
};

int Ukulele::getUkuleleID()const {return ukuleleID;}

void dodajUFajlUkulele()
{
	Ukulele u;
	ofstream outFile;
	outFile.open("UKULELE.dat",ios::binary|ios::app);
	u.unosUkulelea();
	outFile.write(reinterpret_cast<char *> (&u), sizeof(Ukulele));
	outFile.close();
    	cout<<"\n\nUkulele dodato u fajl!";
	cin.ignore();
	cin.get();
}
void ispisiFajlUkulele()
{
	Ukulele u;
	ifstream inFile;
	inFile.open("UKULELE.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVI UKULELEI U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&u), sizeof(Ukulele)))
	{
	    u.ispisUkulelea();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluUkulele(int n)
{
	Ukulele u;
	ifstream inFile;
	inFile.open("UKULELE.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&u), sizeof(Ukulele)))
	{
		if(u.getUkuleleID()==n)
		{
	  		u.ispisUkulelea();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nUkulele ne postoji!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluUkulele(int n)
{
	Ukulele u;
	ifstream inFile;
	inFile.open("UKULELE.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempUkulele.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&u), sizeof(Ukulele)))
	{
		if(u.getUkuleleID()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&u), sizeof(Ukulele));
		}
	}
	outFile.close();
	inFile.close();
	remove("UKULELE.dat");
	rename("TempUkulele.dat","UKULELE.dat");
	cout<<"\n\n\tUkelele obrisano!";
	cin.ignore();
	cin.get();
}
#endif
