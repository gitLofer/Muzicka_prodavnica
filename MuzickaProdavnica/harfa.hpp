#ifndef HARFA_HPP_INCLUDED
#define HARFA_HPP_INCLUDED

#include "zicaniInstrument.hpp"
enum harfaVrsta {pedala, poluga};

class Harfa : public ZicaniInstrument
{
private:
    bool elektricna;
    harfaVrsta vrstaHarfe;
public:

    int harfaID;
    Harfa()
    {
        cena = 20590.00;
        ocena = 7.9;
        proizvodjac = yamaha;
        brojZica = 48;
        duzinaZice = 2;
        vrstaZica = celik;
        elektricna = false;
        vrstaHarfe = poluga;
    }
    Harfa( float cc, float oo, proizvodjaci pp, int broj, float duzina, zicaVrsta vrs, bool elektro, harfaVrsta harf )
    {
        cena = cc;
        ocena = oo;
        proizvodjac = pp;
        brojZica = broj;
        duzinaZice = duzina;
        vrstaZica = vrs;
        elektricna = elektro;
        vrstaHarfe = harf;
    }
    Harfa(const Harfa &h)
    {
       
        cena = h.cena;
        ocena = h.ocena;
        proizvodjac = h.proizvodjac;
        brojZica = h.brojZica;
        duzinaZice = h.duzinaZice;
        vrstaZica = h.vrstaZica;
        elektricna = h.elektricna;
        vrstaHarfe = h.vrstaHarfe;
    }

    void setElektricna(bool elek){elektricna = elek;}
    void setVrstaHarfe(harfaVrsta ha){vrstaHarfe = ha;}

    int getHarfaID()const;
    string getElektricna()const
    {
        if(elektricna == false)
        {
            return "Nije elektricna";
        }else if(elektricna == true)
        {
            return "Jeste elektricna";
        }else
            return "Nema podataka o elektricnosti";
    }
    string getVrstaHarfe()const
    {
        switch(vrstaHarfe)
        {
        case pedala:
            return "PEDALA";
            break;
        case poluga:
            return "POLUGA";
            break;
        default:
            return "Nema vrste harfe";
            break;
        }
    }

    void ispisHarfe()
    {
        cout<<"ID: "<<getHarfaID()<<endl;
        ispisZicanogInstrumenta();
        cout<<"Elektricna: "<<getElektricna()<<endl;
        cout<<"Vrsta harfe: "<<getVrstaHarfe()<<endl;
    }
    
    void unosHarfe()
    {
        int br;
        cout<<"ID: ";
        cin>>harfaID;
        unosZicanogInstrumenta();
        cout<<"Elektricna: ";
        cin>>elektricna;
        fflush(stdin);
        cout<<"Vrsta harfe[1-Pedala/2-Poluga]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrstaHarfe = pedala;
            break;
        case 2:
            vrstaHarfe = poluga;
            break;
        }
    }
};



int Harfa::getHarfaID()const {return harfaID;}

void dodajUFajlHarfa(){
	Harfa h;
	ofstream outFile;
	outFile.open("HARFA.dat",ios::binary|ios::app);
	h.unosHarfe();
	outFile.write(reinterpret_cast<char *> (&h), sizeof(Harfa));
	outFile.close();
    	cout<<"\n\nHarfa dodata u fajl!";
	cin.ignore();
	cin.get();
}

void ispisiFajlHarfa(){
	Harfa h;
	ifstream inFile;
	inFile.open("HARFA.dat",ios::binary);
    
	if(!inFile){
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVE HARFE U FAJLU\n\n";
    
	while(inFile.read(reinterpret_cast<char *> (&h), sizeof(Harfa))){
	    h.ispisHarfe();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluHarfa(int n){
	Harfa h;
	ifstream inFile;
	inFile.open("HARFA.dat",ios::binary);
    
	if(!inFile){
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
    
	while(inFile.read(reinterpret_cast<char *> (&h), sizeof(Harfa))){
		if(h.getHarfaID()==n){
	  		h.ispisHarfe();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nHarfa ne postoji!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluHarfa(int n){
	Harfa h;
	ifstream inFile;
	inFile.open("HARFA.dat",ios::binary);
    
	if(!inFile){
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
    
	ofstream outFile;
	outFile.open("TempHarfa.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&h), sizeof(Harfa))){
		if(h.getHarfaID()!=n){
			outFile.write(reinterpret_cast<char *> (&h), sizeof(Harfa));
		}
	}
    
	outFile.close();
	inFile.close();
	remove("HARFA.dat");
	rename("TempHarfa.dat","HARFA.dat");
	cout<<"\n\n\tHarfa obrisana!";
	cin.ignore();
	cin.get();
}



#endif // HARFA_HPP_INCLUDED
