#ifndef OBOA_HPP_INCLUDED
#define OBOA_HPP_INCLUDED

#include "duvackiInstrument.hpp"
enum oboaVrsta {baroknaOboa, klasicnaOboa, beckaOboa, modernaOboa};


class Oboa: public DuvackiInstrument{
private:
    oboaVrsta vrstao;
public:

    int oboaID;

    Oboa(){
    cena=800.00;
    ocena=8.75;
    proizvodjac=yamaha;
    vrsta=drveni;
    vrstao=baroknaOboa;
    }

    Oboa(float c, float o,proizvodjaci p, duvackiVrsta v,  oboaVrsta ov){
        cena=c;
        ocena=o;
        proizvodjac=p;
        vrsta=v;
        vrstao=ov;
    }

    Oboa(const Oboa &o){
        cena=o.cena;
        ocena=o.ocena;
        proizvodjac=o.proizvodjac;
        vrsta=o.vrsta;
        vrstao=o.vrstao;
    }

    int getOboaID()const;
    string getOboa()const{
        switch(vrstao){
        case baroknaOboa:
            return "Barokna";
            break;
        case beckaOboa:
            return "Becka";
            break;
        case klasicnaOboa:
            return "Klasicna";
            break;
        case modernaOboa:
            return "Moderna";
            break;
        }
    }
    void setOboa(oboaVrsta ov){vrstao=ov; }

    void ispisOboe(){
        cout<<"ID: "<<getOboaID()<<endl;
        ispisDuvackogInstrumenta();
        cout<<"Vrsta oboe :"<<getOboa()<<endl;
    }

    void unosOboe(){
        int br;
        cout<<"ID: ";
        cin>>oboaID;
        fflush(stdin);
        unosDuvackogInstrumenta();
        cout<<"Vrsta oboe[1-Barokna/2-Becka/3-Klasicna/4-Moderna]: ";
        cin>>br;
        fflush(stdin);
        switch(br){
        case 1:
            vrstao = baroknaOboa;
            break;
        case 2:
            vrstao = beckaOboa;
            break;
        case 3:
            vrstao = klasicnaOboa;
            break;
        case 4:
            vrstao = modernaOboa;
            break;
        }
    }
};

int Oboa::getOboaID()const {return oboaID;}

void dodajUFajlOboa(){
	Oboa o;
	ofstream outFile;
	outFile.open("OBOA.dat",ios::binary|ios::app);
	o.unosOboe();
	outFile.write(reinterpret_cast<char *> (&o), sizeof(Oboa));
	outFile.close();
    	cout<<"\n\nOboa dodata u fajl!";
	cin.ignore();
	cin.get();
}

void ispisiFajlOboa(){
	Oboa o;
	ifstream inFile;
	inFile.open("OBOA.dat",ios::binary);
	if(!inFile){
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
    
	cout<<"\n\n\n\t\tSVE OBOE U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&o), sizeof(Oboa))){
	    o.ispisOboe();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluOboa(int n){
	Oboa o;
	ifstream inFile;
	inFile.open("OBOA.dat",ios::binary);
	if(!inFile){
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&o), sizeof(Oboa))){
		if(o.getOboaID()==n){
	  		o.ispisOboe();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nOboa ne postoji!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluOboa(int n){
	Oboa o;
	ifstream inFile;
	inFile.open("OBOA.dat",ios::binary);
	if(!inFile){
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempOboa.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&o), sizeof(Oboa))){
		if(o.getOboaID()!=n){
			outFile.write(reinterpret_cast<char *> (&o), sizeof(Oboa));
		}
	}
	outFile.close();
	inFile.close();
	remove("OBOA.dat");
	rename("TempOboa.dat","OBOA.dat");
	cout<<"\n\n\tOboa obrisana!";
	cin.ignore();
	cin.get();
}

#endif
