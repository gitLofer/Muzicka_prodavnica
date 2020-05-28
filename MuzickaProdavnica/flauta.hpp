#ifndef FLAUTA_HPP_INCLUDED
#define FLAUTA_HPP_INCLUDED

#include "duvackiInstrument.hpp"
enum flautaVrsta {standardna, pikolo, harmonijska};

class Flauta: public DuvackiInstrument{
private:
    flautaVrsta vrstaf;
public:

    int flautaID;

    Flauta(){
    cena=800.00;
    ocena=8.75;
    proizvodjac=yamaha;
    vrsta=drveni;
    vrstaf=standardna;
    }

    Flauta(float c, float o,proizvodjaci p, duvackiVrsta v,  flautaVrsta fv){
        cena=c;
        ocena=o;
        proizvodjac=p;
        vrsta=v;
        vrstaf=fv;
    }

    Flauta(const Flauta &f){
        cena=f.cena;
        ocena=f.ocena;
        proizvodjac=f.proizvodjac;
        vrsta=f.vrsta;
        vrstaf=f.vrstaf;
    }

    int getFlautaID()const;
    
    string getFlauta()const{
        switch(vrstaf){
        case harmonijska:
            return "Harmonijska";
            break;
        case pikolo:
            return "Pikolo";
            break;
        case standardna:
            return "Standardna";
            break;
        }
    }
    
    void setFlauta(flautaVrsta fv){vrstaf=fv; }

    void ispisFlaute(){
        
        cout<<"ID: "<<getFlautaID()<<endl;
        ispisDuvackogInstrumenta();
        cout<<"Vrsta flaute :"<<getFlauta()<<endl;
    }

    void unosFlaute(){
        
       int br;
       cout<<"ID: ";
       cin>>flautaID;
       fflush(stdin);
       unosDuvackogInstrumenta();
       cout<<"Vrsta flaute[1-Harmonijska/2-Pikolo/3-Standardna]: ";
       cin>>br;
       fflush(stdin);
       switch(br){
       case 1:
        vrstaf = harmonijska;
        break;
       case 2:
        vrstaf = pikolo;
        break;
       case 3:
        vrstaf = standardna;
        break;
       }
    }
};

int Flauta::getFlautaID()const {return flautaID; }

void dodajUFajlFlauta(){
    
	Flauta f;
	ofstream outFile;
	outFile.open("FLAUTA.dat",ios::binary|ios::app);
	f.unosFlaute();
	outFile.write(reinterpret_cast<char *> (&f), sizeof(Flauta));
	outFile.close();
    	cout<<"\n\nFlauta dodata u fajl!";
	cin.ignore();
	cin.get();
}

void ispisiFajlFlauta(){
    
	Flauta f;
	ifstream inFile;
	inFile.open("FLAUTA.dat",ios::binary);
	if(!inFile){
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVE FLAUTE U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&f), sizeof(Flauta))){
	    f.ispisFlaute();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluFlauta(int n){
    
	Flauta f;
	ifstream inFile;
	inFile.open("FLAUTA.dat",ios::binary);
    
	if(!inFile){
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&f), sizeof(Flauta))){
		if(f.getFlautaID()==n){
	  		 f.ispisFlaute();
			 flag=true;
		}
	}
    
	inFile.close();
	if(flag==false)
		cout<<"\n\nFlauta ne postoji!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluFlauta(int n){
    
	Flauta f;
	ifstream inFile;
	inFile.open("FLAUTA.dat",ios::binary);
	if(!inFile){
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
    }
    
	ofstream outFile;
	outFile.open("TempFlauta.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&f), sizeof(Flauta))){
		if(f.getFlautaID()!=n){
			outFile.write(reinterpret_cast<char *> (&f), sizeof(Flauta));
		}
	}
    
	outFile.close();
	inFile.close();
	remove("FLAUTA.dat");
	rename("TempFlauta.dat","FLAUTA.dat");
	cout<<"\n\n\tFlauta obrisana!";
	cin.ignore();
	cin.get();
}

#endif
