#ifndef ZAUCENJE_HPP_INCLUDED
#define ZAUCENJE_HPP_INCLUDED

#include "proizvod.hpp"
enum zaUcenjeVrsta {knjiga, disk, notnaSveska};


class ZaUcenje : public Proizvod{
private:
    zaUcenjeVrsta vrsta;
public:

    int zaUcenjeID;

    ZaUcenje(){
        cena = 0.00;
        ocena = 1;
        proizvodjac = yamaha;
        vrsta = disk;
    }

    ZaUcenje( float CENA, float OCENA, proizvodjaci PROIZVODJAC, zaUcenjeVrsta VRSTA){
        cena = CENA;
        ocena = OCENA;
        proizvodjac = PROIZVODJAC;
        vrsta = VRSTA;
    }

    ZaUcenje(const ZaUcenje &zu){
        cena = zu.cena;
        ocena = zu.ocena;
        proizvodjac = zu.proizvodjac;
        vrsta = zu.vrsta;
    }

    int getZaUcenjeID()const;
    string getVrsta()const
    {
        switch(vrsta){
          case disk:
              return "Disk";
              break;
          case knjiga:
              return "Knjiga";
              break;
          case notnaSveska:
              return "Notna sveska";
              break;
                  }
              }

    void setVrsta(){
        int br;
        cout<<"Vrsta [1-Disk/2-Knjiga/3-Notna sveska]: "<<endl;
        cin>>br;

        switch(br){
          case 1:
              vrsta = disk;
              break;
          case 2:
              vrsta = knjiga;
              break;
          case 3:
              vrsta = notnaSveska;
              break;
              }
          }

          void ispisiZaUcenje()
          {
              cout<<"ID: "<<getZaUcenjeID()<<endl;
              ispisProizvoda();
              cout<<"Vrsta: "<<getVrsta()<<endl;
          }

    void unesiZaUcenje(){
        int br;
        cout<<"ID: ";
        cin>>zaUcenjeID;
        unosProizvoda();
        setVrsta();
    }
};

int ZaUcenje::getZaUcenjeID()const {return zaUcenjeID;}

void dodajUFajlZaUcenje(){
	ZaUcenje z;
	ofstream outFile;
	outFile.open("ZAUCENJE.dat",ios::binary|ios::app);
	z.unesiZaUcenje();
	outFile.write(reinterpret_cast<char *> (&z), sizeof(ZaUcenje));
	outFile.close();
    	cout<<"\n\nSredstvo za ucenje dodato u fajl!";
	cin.ignore();
	cin.get();
}

void ispisiFajlZaUcenje(){
	ZaUcenje z;
	ifstream inFile;
	inFile.open("ZAUCENJE.dat",ios::binary);
	if(!inFile){
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVA SREDSTVA ZA UCENEJ U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&z), sizeof(ZaUcenje))){
	    z.ispisiZaUcenje();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluZaUcenje(int n){
	ZaUcenje z;
	ifstream inFile;
	inFile.open("ZAUCENJE.dat",ios::binary);
	if(!inFile){
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&z), sizeof(ZaUcenje))){
		if(z.getZaUcenjeID()==n){
	  		z.ispisiZaUcenje();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nSredstvo za ucenje ne postoji!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluZaUcenje(int n){
	ZaUcenje z;
	ifstream inFile;
	inFile.open("ZAUCENJE.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempZaUcenje.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&z), sizeof(ZaUcenje))){
		if(z.getZaUcenjeID()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&z), sizeof(ZaUcenje));
		}
	}
	outFile.close();
	inFile.close();
	remove("ZAUCENJE.dat");
	rename("TempZaUcenje.dat","ZAUCENJE.dat");
	cout<<"\n\n\tSredstvo za ucenje obrisano!";
	cin.ignore();
	cin.get();
}

#endif
