#ifndef TRUBA_HPP_INCLUDED
#define TRUBA_HPP_INCLUDED

#include "duvackiInstrument.hpp"
enum trubaVrsta {visokaTruba, altTruba, basTruba};

class Truba: public DuvackiInstrument{
private:
    trubaVrsta vrstat;
public:

    int trubaID;

    Truba(){
    cena=1500.00;
    ocena=8.75;
    proizvodjac=gibson;
    vrsta=limeni;
    vrstat=basTruba;
    }

    Truba( float c, float o,proizvodjaci p, duvackiVrsta v, trubaVrsta tv){
        cena=c;
        ocena=o;
        proizvodjac=p;
        vrsta=v;
        vrstat=tv;
    }

    Truba(const Truba &t){
        cena=t.cena;
        ocena=t.ocena;
        proizvodjac=t.proizvodjac;
        vrsta=t.vrsta;
        vrstat=t.vrstat;
    }

    int getTrubaID()const;
    string getTruba()const{
        switch(vrstat){
        case altTruba:
            return "Alt";
            break;
        case basTruba:
            return "Bas";
            break;
        case visokaTruba:
            return "Visoka";
            break;
        }
    }
    
    void setTruba(trubaVrsta tv){vrstat=tv; }

    void ispisTruba(){
        cout<<"ID: "<<getTrubaID()<<endl;
        ispisDuvackogInstrumenta();
        cout<<"Vrsta trube :"<<getTruba()<<endl;
    }

    void unosTruba(){
        int br;
        cout<<"ID: ";
        cin>>trubaID;
        fflush(stdin);
        unosDuvackogInstrumenta();
        cout<<"Vrsta trube[1-Alt/2-Bas/3-Visoka]: ";
        cin>>br;
        fflush(stdin);
        switch(br){
        case 1:
            vrstat = altTruba;
            break;
        case 2:
            vrstat = basTruba;
            break;
        case 3:
            vrstat = visokaTruba;
            break;
        }
    }
};

int Truba::getTrubaID()const {return trubaID;}

void dodajUFajlTruba(){
	Truba t;
	ofstream outFile;
	outFile.open("TRUBA.dat",ios::binary|ios::app);
	t.unosTruba();
	outFile.write(reinterpret_cast<char *> (&t), sizeof(Truba));
	outFile.close();
    	cout<<"\n\nTruba dodata u fajl!";
	cin.ignore();
	cin.get();
}

void ispisiFajlTruba(){
	Truba t;
	ifstream inFile;
	inFile.open("TRUBA.dat",ios::binary);
	if(!inFile){
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVE TRUBE U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&t), sizeof(Truba))){
	    t.ispisTruba();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluTruba(int n){
	Truba t;
	ifstream inFile;
	inFile.open("TRUBA.dat",ios::binary);
	if(!inFile){
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&t), sizeof(Truba))){
		if(t.getTrubaID()==n){
	  		t.ispisTruba();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nTruba ne postoji!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluTruba(int n){
	Truba t;
	ifstream inFile;
	inFile.open("TRUBA.dat",ios::binary);
	if(!inFile){
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempTruba.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&t), sizeof(Truba))){
		if(t.getTrubaID()!=n){
			outFile.write(reinterpret_cast<char *> (&t), sizeof(Truba));
		}
	}
	outFile.close();
	inFile.close();
	remove("TRUBA.dat");
	rename("TempTruba.dat","TRUBA.dat");
	cout<<"\n\n\tTruba obrisana!";
	cin.ignore();
	cin.get();
}

#endif
