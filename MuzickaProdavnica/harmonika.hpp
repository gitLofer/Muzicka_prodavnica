#ifndef HARMONIKA_HPP_INCLUDED
#define HARMONIKA_HPP_INCLUDED

#include "instrument.hpp"
enum harmonikaVrsta {obicna, usnena};


class Harmonika: public Instrument{
private:
    harmonikaVrsta vrstah;
public:

    int harmonikaID;

    Harmonika(){
        cena=4000.00;
        ocena=9.69;
        proizvodjac=yamaha;
        vrstah=obicna;
    }

    Harmonika(float c, float o, proizvodjaci p, harmonikaVrsta h ){
        cena=c;
        ocena=o;
        proizvodjac=p;
        vrstah=h;
    }

    Harmonika(const Harmonika &h){
        cena=h.cena;
        ocena=h.ocena;
        proizvodjac=h.proizvodjac;
        vrstah=h.vrstah;
    }

    string getHarmonika(){
        switch(vrstah){
        case obicna:
            return "Obicna";
            break;
        case usnena:
            return "Usnena";
            break;
        }
    }
    void setHarmonika(harmonikaVrsta h){vrstah=h; }
    int getHarmonikaID()const;

    void ispisHarmonike(){
        cout<<"ID: "<<getHarmonikaID()<<endl;
        ispisInstrumenta();
        cout<<"Vrsta harmonike:"<<getHarmonika()<<endl;
    }

    void unosHarmonike(){
        int br;
        cout<<"ID: ";
        cin>>harmonikaID;
        unosInstrumenta();
        cout<<"Vrsta harmonike[1-Obicna/2-Usnena]: ";
        cin>>br;
        fflush(stdin);
        switch(br){
        case 1:
            vrstah = obicna;
            break;
        case 2:
            vrstah = usnena;
            break;
        }
    }
};

int Harmonika::getHarmonikaID()const {return harmonikaID;}

void dodajUFajlHarmonika(){
	Harmonika h;
	ofstream outFile;
	outFile.open("HARMONIKA.dat",ios::binary|ios::app);
	h.unosHarmonike();
	outFile.write(reinterpret_cast<char *> (&h), sizeof(Harmonika));
	outFile.close();
    	cout<<"\n\nHarmonika dodata u fajl!";
	cin.ignore();
	cin.get();
}

void ispisiFajlHarmonika(){
	Harmonika h;
	ifstream inFile;
	inFile.open("HARMONIKA.dat",ios::binary);
	if(!inFile){
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVE HARMONIKE U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&h), sizeof(Harmonika))){
	    h.ispisHarmonike();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluHarmonika(int n){
	Harmonika h;
	ifstream inFile;
	inFile.open("HARMONIKA.dat",ios::binary);
	if(!inFile){
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&h), sizeof(Harmonika))){
		if(h.getHarmonikaID()==n){
	  		h.ispisHarmonike();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nHarmonika ne postoji!"<<endl;
	cin.ignore();
	cin.get();
}


void obrisiUFajluHarmonika(int n){
	Harmonika h;
	ifstream inFile;
	inFile.open("HARMONIKA.dat",ios::binary);
	if(!inFile){
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempHarmonika.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&h), sizeof(Harmonika))){
		if(h.getHarmonikaID()!=n){
			outFile.write(reinterpret_cast<char *> (&h), sizeof(Harmonika));
		}
	}
	outFile.close();
	inFile.close();
	remove("HARMONIKA.dat");
	rename("TempHarmonika.dat","HARMONIKA.dat");
	cout<<"\n\n\tHarmonika obrisana!";
	cin.ignore();
	cin.get();
}

#endif
