#ifndef MIKSETA_HPP_INCLUDED
#define MIKSETA_HPP_INCLUDED

#include "proizvod.hpp"
enum miksetaVrsta {analogna, digitalna};


class Mikseta : public Proizvod{
private:
    miksetaVrsta vrsta;
public:

    int miksetaID;

    Mikseta() : Proizvod(){
    vrsta = analogna;
    }

    Mikseta(miksetaVrsta v, float c, float o, proizvodjaci pp) : Proizvod(c,o,pp){
    vrsta = v;
    }

    Mikseta(const Mikseta &m) : Proizvod((Proizvod)m){
    vrsta = m.vrsta;
    }

    void setVrsta(miksetaVrsta VRSTA) {vrsta = VRSTA;}
    string getVrsta(){
    switch(vrsta){
    case analogna:
        return "Analogna";
        break;
    case digitalna:
        return "Digitalna";
        break;
    }
    }
    int getMiksetaID()const;

    void ispisiMiksetu(){
    cout<<"ID: "<<getMiksetaID()<<endl;
    ispisProizvoda();
    cout<<"Vrsta: "<<getVrsta()<<endl;
    }

    void unesiMiksetu()
    {
    int br;
    cout<<"ID: ";
    cin>>miksetaID;
    fflush(stdin);
    unosProizvoda();
    cout<<"Vrsta miksete[1-Analogna/2-Digitalna]: ";
    cin>>br;
    fflush(stdin);
    switch(br)
    {
    case 1:
        vrsta = analogna;
        break;
    case 2:
        vrsta = digitalna;
        break;
    }
    }
};

int Mikseta::getMiksetaID()const {return miksetaID;}

void dodajUFajlMikseta(){
	Mikseta m;
	ofstream outFile;
	outFile.open("MIKSETA.dat",ios::binary|ios::app);
	m.unesiMiksetu();
	outFile.write(reinterpret_cast<char *> (&m), sizeof(Mikseta));
	outFile.close();
    	cout<<"\n\nMikseta dodata u fajl!";
	cin.ignore();
	cin.get();
}

void ispisiFajlMikseta(){
	Mikseta m;
	ifstream inFile;
	inFile.open("MIKSETA.dat",ios::binary);
	if(!inFile){
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVE MIKSETE U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&m), sizeof(Mikseta))){
	    m.ispisiMiksetu();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluMikseta(int n){
	Mikseta m;
	ifstream inFile;
	inFile.open("MIKSETA.dat",ios::binary);
	if(!inFile){
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&m), sizeof(Mikseta)))
	{
		if(m.getMiksetaID()==n)
		{
	  		m.ispisiMiksetu();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nMikseta ne postoji!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluMikseta(int n){
	Mikseta m;
	ifstream inFile;
	inFile.open("MIKSETA.dat",ios::binary);
	if(!inFile){
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempMikseta.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&m), sizeof(Mikseta))){
		if(m.getMiksetaID()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&m), sizeof(Mikseta));
		}
	}
	outFile.close();
	inFile.close();
	remove("MIKSETA.dat");
	rename("TempMikseta.dat","MIKSETA.dat");
	cout<<"\n\n\tMikseta obrisana!";
	cin.ignore();
	cin.get();
}
#endif
