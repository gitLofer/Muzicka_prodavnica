#ifndef BUBANJ_HPP_INCLUDED
#define BUBANJ_HPP_INCLUDED

#include "udarackiInstrument.hpp"
enum bubanjVrsta {kongo, bongo, djambe, tabla, timpani, pahu};

class Bubanj : public UdarackiInstrument
{
private:
    bool glasan;
    bool rezonantan;
    int brojSlojeva;
    bubanjVrsta vrsta;
public:

    int bubanjID;

    Bubanj()
    {
        cena = 2500.00;
        ocena = 9.0;
        proizvodjac = yamaha;
        ton = odredjena;
        glasan = true;
        rezonantan = false;
        brojSlojeva = 2;
        vrsta = bongo;
    }
    Bubanj(int idd,float cc, float oo, proizvodjaci pp, udarackiVisinaTona visina,bool glasnoca, bool rez, int brs, bubanjVrsta bub)
    {
        bubanjID = idd;
        cena = cc;
        ocena = oo;
        proizvodjac = pp;
        ton = visina;
        glasan = glasnoca;
        rezonantan = rez;
        brojSlojeva = brs;
        vrsta = bub;
    }
    Bubanj(const Bubanj &b)
    {
        bubanjID = b.bubanjID;
        cena = b.cena;
        ocena = b.ocena;
        proizvodjac = b.proizvodjac;
        ton = b.ton;
        glasan = b.glasan;
        rezonantan = b.rezonantan;
        brojSlojeva = b.brojSlojeva;
        vrsta = b.vrsta;
    }

    void setGlasnoca(bool glas){glasan = glas;}
    void setRezonantan(bool rezon){rezonantan = rezon;}
    void setBrojSlojeva(int br){brojSlojeva = br;}
    void setVrstaBubnjeva(bubanjVrsta vr){vrsta = vr;}

    string getGlasnoca()const
    {
        if(glasan == false)
        {
            return "Nije glasan";
        }else if (glasan == true)
        {
            return "Glasan";
        }else
           return "Nije odredjena glasnoca instrumenta";
    }
    string getRezonantnost()const
    {
        if(rezonantan == false)
        {
            return "Nije rezonantan";
        }else if (rezonantan == true)
        {
            return "Rezonantan";
        }else
           return "Nije odredjena rezonantnost instrumenta";
    }
    int getBrojSlojeva()const{return brojSlojeva;}
    string getVrstaBubnja()const
    {
        switch(vrsta)
        {
        case kongo:
            return "KONGO";
            break;
        case bongo:
            return "BONGO";
            break;
        case djambe:
            return "DJAMBE";
            break;
        case tabla:
            return "TABLA";
            break;
        case timpani:
            return "TIMPANI";
            break;
        case pahu:
            return "PAHU";
            break;
        default:
            return "Nema vrste bubnjeva";
            break;
        }
    }
    int getBubanjID()const;

    void ispisBubnja()
    {
        cout<<"ID: "<<getBubanjID()<<endl;
        ispisUdarackogInstrumenta();
        cout<<"Glasnost bubnja: "<<getGlasnoca()<<endl;
        cout<<"Rezonantnost bubnja: "<<getRezonantnost()<<endl;
        cout<<"Broj slojeva: "<<getBrojSlojeva()<<endl;
        cout<<"Vrsta bubnjeva: "<<getVrstaBubnja()<<endl;
    }

    void unosBubnja()
    {
        int br;
        cout<<"ID: ";
        cin>>bubanjID;
        fflush(stdin);
        unosUdarackogInstrumenta();
        cout<<"Glasnoca bubnja: ";
        cin>>glasan;
        fflush(stdin);
        cout<<"Rezonantnost bubnja: ";
        cin>>rezonantan;
        fflush(stdin);
        cout<<"Broj slojeva: ";
        cin>>brojSlojeva;
        fflush(stdin);
        cout<<"Vrsta bubnja[1-Bongo/2-Djambe/3-Kongo/4-Pahu/5-Tabla/6-Timpani]: ";
        cin>>br;
        fflush(stdin);
        switch(br)
        {
        case 1:
            vrsta = bongo;
            break;
        case 2:
            vrsta = djambe;
            break;
        case 3:
            vrsta = kongo;
            break;
        case 4:
            vrsta = pahu;
            break;
        case 5:
            vrsta = tabla;
            break;
        case 6:
            vrsta = timpani;
            break;
        }
    }

};
int Bubanj::getBubanjID()const {return bubanjID;}

void dodajUFajlBubanj()
{
	Bubanj b;
	ofstream outFile;
	outFile.open("BUBANJ.dat",ios::binary|ios::app);
	b.unosBubnja();
	outFile.write(reinterpret_cast<char *> (&b), sizeof(Bubanj));
	outFile.close();
    	cout<<"\n\nBubanj dodat u fajl!";
	cin.ignore();
	cin.get();
}
void ispisiFajlBubanj()
{
	Bubanj b;
	ifstream inFile;
	inFile.open("BUBANJ.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVI BUBNJEVI U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&b), sizeof(Bubanj)))
	{
		b.ispisBubnja();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluBubanj(int n)
{
	Bubanj b;
	ifstream inFile;
	inFile.open("BUBANJ.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&b), sizeof(Bubanj)))
	{
		if(b.getBubanjID()==n)
		{
	  		 b.ispisBubnja();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nBubanj ne postoji!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluBubanj(int n)
{
	Bubanj b;
	ifstream inFile;
	inFile.open("BUBANJ.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempBubanj.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&b), sizeof(Bubanj)))
	{
		if(b.getBubanjID()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&b), sizeof(Bubanj));
		}
	}
	outFile.close();
	inFile.close();
	remove("BUBANJ.dat");
	rename("TempBubanj.dat","BUBANJ.dat");
	cout<<"\n\n\tBubanj obrisan!";
	cin.ignore();
	cin.get();
}

#endif
