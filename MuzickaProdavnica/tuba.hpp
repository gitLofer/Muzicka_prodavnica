#ifndef TUBA_HPP_INCLUDED
#define TUBA_HPP_INCLUDED

#include "duvackiinstrument.hpp"

class Tuba: public DuvackiInstrument{
private:
    tubaVrsta vrstat;
public:

    int tubaID;

    Tuba(){
    cena=1500.00;
    ocena=8.75;
    proizvodjac=fender;
    vrsta=limeni;
    vrstat=kontrabasTuba;
    }

    Tuba(float c, float o,proizvodjaci p, duvackiVrsta v, tubaVrsta tv){
        cena=c;
        ocena=o;
        proizvodjac=p;
        vrsta=v;
        vrstat=tv;
    }

    Tuba(const Tuba &t){
        cena=t.cena;
        ocena=t.ocena;
        proizvodjac=t.proizvodjac;
        vrsta=t.vrsta;
        vrstat=t.vrstat;
    }

    int getTubaID()const;
    string getTuba()const
    {
        switch(vrstat)
        {
        case basTuba:
            return "Bas";
            break;
        case kontrabasTuba:
            return "Kontrabas";
            break;
        case subKontrabasTuba:
            return "Sub kontrabas";
            break;
        case tenorTuba:
            return "Tenor";
            break;
        }
    }
    void setTuba(tubaVrsta tv){vrstat=tv; }

    void ispisTube()
    {
        cout<<"ID: "<<getTubaID()<<endl;
        ispisDuvackogInstrumenta();
        cout<<"Vrsta tube :"<<getTuba()<<endl;
    }

    void unosTube()
    {
        int br;
        cout<<"ID: ";
        cin>>tubaID;
        fflush(stdin);
        unosDuvackogInstrumenta();
        cout<<"Vrsta tube[1-Bas/2-Kontrabas/3-Sub kontrabas/4-Tenor]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrstat = basTuba;
            break;
        case 2:
            vrstat = kontrabasTuba;
            break;
        case 3:
            vrstat = subKontrabasTuba;
            break;
        case 4:
            vrstat = tenorTuba;
            break;
        }
    }
};

int Tuba::getTubaID()const {return tubaID;}

void dodajUFajlTuba()
{
	Tuba t;
	ofstream outFile;
	outFile.open("TUBA.dat",ios::binary|ios::app);
	t.unosTube();
	outFile.write(reinterpret_cast<char *> (&t), sizeof(Tuba));
	outFile.close();
    	cout<<"\n\nTuba dodata u fajl!";
	cin.ignore();
	cin.get();
}
void ispisiFajlTuba()
{
	Tuba t;
	ifstream inFile;
	inFile.open("TUBA.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVE TUBE U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&t), sizeof(Tuba)))
	{
	    t.ispisTube();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluTuba(int n)
{
	Tuba t;
	ifstream inFile;
	inFile.open("TUBA.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&t), sizeof(Tuba)))
	{
		if(t.getTubaID()==n)
		{
	  		t.ispisTube();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nTuba ne postoji!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluTuba(int n)
{
	Tuba t;
	ifstream inFile;
	inFile.open("TUBA.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempTuba.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&t), sizeof(Tuba)))
	{
		if(t.getTubaID()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&t), sizeof(Tuba));
		}
	}
	outFile.close();
	inFile.close();
	remove("TUBA.dat");
	rename("TempTuba.dat","TUBA.dat");
	cout<<"\n\n\tTuba obrisana!";
	cin.ignore();
	cin.get();
}


#endif // TUBA_HPP_INCLUDED
