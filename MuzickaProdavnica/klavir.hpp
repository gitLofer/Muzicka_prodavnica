#ifndef KLAVIR_HPP_INCLUDED
#define KLAVIR_HPP_INCLUDED

#include "instrument.hpp"
enum klavirVrsta {elektricni, pianino, koncertni, polukoncertni};

class Klavir: public Instrument{
private:
    klavirVrsta vrstak;
public:

    int klavirID;

    Klavir(){
        cena=4000.00;
        ocena=9.69;
        proizvodjac=yamaha;
        vrstak=elektricni;
    }

    Klavir( float c, float o, proizvodjaci p, klavirVrsta k){
        cena=c;
        ocena=o;
        proizvodjac=p;
        vrstak=k;
    }

    Klavir(const Klavir &k){
        cena=k.cena;
        ocena=k.ocena;
        proizvodjac=k.proizvodjac;
        vrstak=k.vrstak;
    }

    int getKlavirID()const;
    string getKlavir()const{
        switch(vrstak){
        case elektricni:
            return "Elektricni";
            break;
        case koncertni:
            return "Koncertni";
            break;
        case pianino:
            return "Pianino";
            break;
        case polukoncertni:
            return "Polukoncertni";
            break;
        }
    }
    void setKlavir(klavirVrsta k){vrstak=k; }

    void ispisKlavira(){
        cout<<"ID: "<<getKlavirID()<<endl;
        ispisInstrumenta();
        cout<<"Vrsta klavira:"<<getKlavir()<<endl;
    }

    void unosKlavira(){

        int br;
        cout<<"ID: ";
        cin>>klavirID;
        fflush(stdin);
        unosInstrumenta();
        cout<<"Vrsta klavira[1-Elektricni/2-Koncertni/3-Pianino/4-Polukoncertni]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrstak = elektricni;
            break;
        case 2:
            vrstak = koncertni;
            break;
        case 3:
            vrstak = pianino;
            break;
        case 4:
            vrstak = polukoncertni;
            break;
        }
    }
};

int Klavir::getKlavirID()const {return klavirID;}

void dodajUFajlKlavir(){
	Klavir k;
	ofstream outFile;
	outFile.open("KLAVIR.dat",ios::binary|ios::app);
	k.unosKlavira();
	outFile.write(reinterpret_cast<char *> (&k), sizeof(Klavir));
	outFile.close();
    	cout<<"\n\nKlavir dodat u fajl!";
	cin.ignore();
	cin.get();
}

void ispisiFajlKlavir(){
	Klavir k;
	ifstream inFile;
	inFile.open("KLAVIR.dat",ios::binary);
	if(!inFile) {
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVI KLAVIRI U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&k), sizeof(Klavir))){
	    k.ispisKlavira();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluKlavir(int n){
	Klavir k;
	ifstream inFile;
	inFile.open("KLAVIR.dat",ios::binary);
	if(!inFile){
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&k), sizeof(Klavir))){
		if(k.getKlavirID()==n){
	  		k.ispisKlavira();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nKlavir ne postoji!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluKlavir(int n){
	Klavir k;
	ifstream inFile;
	inFile.open("KLAVIR.dat",ios::binary);
	if(!inFile){
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempKlavir.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&k), sizeof(Klavir))){
		if(k.getKlavirID()!=n){
			outFile.write(reinterpret_cast<char *> (&k), sizeof(Klavir));
		}
	}
	outFile.close();
	inFile.close();
	remove("KLAVIR.dat");
	rename("TempKlavir.dat","KLAVIR.dat");
	cout<<"\n\n\tKlavir obrisan!";
	cin.ignore();
	cin.get();
}

#endif
