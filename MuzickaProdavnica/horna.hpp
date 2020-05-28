#ifndef HORNA_HPP_INCLUDED
#define HORNA_HPP_INCLUDED

#include "duvackiinstrument.hpp"

class Horna: public DuvackiInstrument{
private:
    hornaVrsta vrstah;
public:

    int hornaID;

    Horna()
    {
    cena=2000.00;
    ocena=8.75;
    proizvodjac=yamaha;
    vrsta=limeni;
    vrstah=jednostruka;
    }

    Horna( float c, float o,proizvodjaci p, duvackiVrsta v, hornaVrsta hv)
    {
        cena=c;
        ocena=o;
        proizvodjac=p;
        vrsta=v;
        vrstah=hv;
    }

    Horna(const Horna &h)
    {
        cena=h.cena;
        ocena=h.ocena;
        proizvodjac=h.proizvodjac;
        vrsta=h.vrsta;
    }

    int getHornaID()const;
    string getHorna()const
    {
        switch(vrstah)
        {
        case jednostruka:
            return "Jednostruka";
            break;
        case dvostruka:
            return "Dvostruka";
            break;
        case odvojivoZvono:
            return "Odvojivo zvono";
            break;
        }
    }
    void setHorna(hornaVrsta hv){vrstah=hv; }

    void ispisHorne()
    {
        cout<<"ID: "<<getHornaID()<<endl;
        ispisDuvackogInstrumenta();
        cout<<"Vrsta horne :"<<getHorna()<<endl;
    }

    void unosHorne()
    {
        int br;
        cout<<"ID: ";
        cin>>hornaID;
        fflush(stdin);
        unosDuvackogInstrumenta();
        cout<<"Vrsta horne[1-Dvostruka/2-Jednostruka/3-Sa odvojivim zvonom]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrstah = dvostruka;
            break;
        case 2:
            vrstah = jednostruka;
            break;
        case 3:
            vrstah = odvojivoZvono;
            break;
        }
    }
};

int Horna::getHornaID()const {return hornaID;}

void dodajUFajlHorna()
{
	Horna h;
	ofstream outFile;
	outFile.open("HORNA.dat",ios::binary|ios::app);
	h.unosHorne();
	outFile.write(reinterpret_cast<char *> (&h), sizeof(Horna));
	outFile.close();
    	cout<<"\n\nHorna dodata u fajl!";
	cin.ignore();
	cin.get();
}
void ispisiFajlHorna()
{
	Horna h;
	ifstream inFile;
	inFile.open("HORNA.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVE HORNE U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&h), sizeof(Horna)))
	{
	    h.ispisHorne();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluHorna(int n)
{
	Horna h;
	ifstream inFile;
	inFile.open("HORNA.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&h), sizeof(Horna)))
	{
		if(h.getHornaID()==n)
		{
	  		h.ispisHorne();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nHorna ne postoji!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluHorna(int n)
{
	Horna h;
	ifstream inFile;
	inFile.open("HORNA.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempHorna.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&h), sizeof(Horna)))
	{
		if(h.getHornaID()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&h), sizeof(Horna));
		}
	}
	outFile.close();
	inFile.close();
	remove("HORNA.dat");
	rename("TempHorna.dat","HORNA.dat");
	cout<<"\n\n\tHorna obrisana!";
	cin.ignore();
	cin.get();
}

#endif // HORNA_HPP_INCLUDED
