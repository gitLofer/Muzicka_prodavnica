#ifndef SLUSALICE_HPP_INCLUDED
#define SLUSALICE_HPP_INCLUDED

#include "proizvod.hpp"

class Slusalice : public Proizvod
{
private:
    bool saMikrofonom;
    float duzinaKabla;
    char frekventniOdziv[20], sistem[20];
public:

    int slusaliceID;

    Slusalice()
    {
    cena = 5999.99;
    ocena = 8.89;
    proizvodjac = yamaha;
    saMikrofonom = true;
    duzinaKabla = 2.5;
    }

    Slusalice( float CENA, float OCENA, proizvodjaci PROIZVODJAC, bool MIKROFON, float DUZINA)
    {
        cena = CENA;
        ocena = OCENA;
        proizvodjac = PROIZVODJAC;
        saMikrofonom = MIKROFON;
        duzinaKabla = DUZINA;
    }

    Slusalice(const Slusalice &s)
    {
        cena = s.cena;
        ocena = s.ocena;
        proizvodjac = s.proizvodjac;
        saMikrofonom = s.saMikrofonom;
        duzinaKabla = s.duzinaKabla;
    }

    int getSlusaliceID()const;
    bool getMikrofon()const {return saMikrofonom;}
    float getDuzinaKabla()const {return duzinaKabla;}
    const char* getFrekventniOdziv()const {return frekventniOdziv;}
    const char* getSistem()const {return sistem;}

    void setMikrofon(bool MIKROFON) {saMikrofonom = MIKROFON;}
    void setDuzinaKabla(float DUZINA) {duzinaKabla = DUZINA;}

    void ispisiSlusalice()
    {
        cout<<"ID: "<<getSlusaliceID()<<endl;
        ispisProizvoda();
        cout<<"Ima mikrofon: "<<getMikrofon()<<endl;
        cout<<"Duzina kabla: "<<getDuzinaKabla()<<"m"<<endl;
        cout<<"Frekventni odziv: "<<getFrekventniOdziv()<<endl;
        cout<<"Sistem: "<<getSistem()<<endl;
    }

    void unesiSlusalice()
    {
        cout<<"ID: ";
        cin>>slusaliceID;
        fflush(stdin);
        unosProizvoda();
        cout<<"Ima mikrofon: ";
        cin>>saMikrofonom;
        fflush(stdin);
        cout<<"Duzina kabla: ";
        cin>>duzinaKabla;
        fflush(stdin);
        cout<<"Frekventni odziv: ";
        cin>>frekventniOdziv;
        fflush(stdin);
        cout<<"Sistem: ";
        cin>>sistem;
        fflush(stdin);
    }

};

int Slusalice::getSlusaliceID()const {return slusaliceID;}

void dodajUFajlSlusalice()
{
	Slusalice s;
	ofstream outFile;
	outFile.open("SLUSALICE.dat",ios::binary|ios::app);
	s.unesiSlusalice();
	outFile.write(reinterpret_cast<char *> (&s), sizeof(Slusalice));
	outFile.close();
    	cout<<"\n\nSlusalice dodate u fajl!";
	cin.ignore();
	cin.get();
}
void ispisiFajlSlusalice()
{
	Slusalice s;
	ifstream inFile;
	inFile.open("SLUSALICE.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVE SLUSALICE U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&s), sizeof(Slusalice)))
	{
	    s.ispisiSlusalice();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluSlusalice(int n)
{
	Slusalice s;
	ifstream inFile;
	inFile.open("SLUSALICE.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&s), sizeof(Slusalice)))
	{
		if(s.getSlusaliceID()==n)
		{
	  		s.ispisiSlusalice();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nSlusalice ne postoje!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluSlusalice(int n)
{
	Slusalice s;
	ifstream inFile;
	inFile.open("SLUSALICE.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempSlusalice.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&s), sizeof(Slusalice)))
	{
		if(s.getSlusaliceID()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&s), sizeof(Slusalice));
		}
	}
	outFile.close();
	inFile.close();
	remove("SLUSALICE.dat");
	rename("TempSlusalice.dat","SLUSALICE.dat");
	cout<<"\n\n\tSlusalice obrisane!";
	cin.ignore();
	cin.get();
}

#endif
