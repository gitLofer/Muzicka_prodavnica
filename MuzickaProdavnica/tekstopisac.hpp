#ifndef TEKSTOPISAC_HPP_INCLUDED
#define TEKSTOPISAC_HPP_INCLUDED

#include "osoba.hpp"

class Tekstopisac : public Osoba{
private:
	int brojNapisanihPesama;
	int godineIskustva;
  
public:
	Tekstopisac(){
		ime="Aleksandar";
		prezime="Miletic";
		godine=35;
		brojNapisanihPesama=54;
		godineIskustva=11;
	}

	Tekstopisac(string i,string p, int g, int bnp, int gi){
		ime=i;
		prezime=p;
		godine=g;
		brojNapisanihPesama=bnp;
		godineIskustva=gi;
	}

	Tekstopisac(const Tekstopisac &t){
		ime=t.ime;
		prezime=t.prezime;
		godine=t.godine;
		brojNapisanihPesama=t.brojNapisanihPesama;
		godineIskustva=t.godineIskustva;
	}

	void setBrojnapisanihpesama(int bnp){brojNapisanihPesama=bnp; }
	void setIskustvo(int gi){godineIskustva=gi; }

	int getBrojnapisanihpesama(){return brojNapisanihPesama; }
	int getIskustvo(){return godineIskustva; }

	void ispisTekstopisca(){
		ispisiOsobu();
		cout<<"Broj napisanih pesama :"<<getBrojnapisanihpesama()<<endl;
		cout<<"Broj godina iskustva :"<<getIskustvo()<<endl;
	}

	void unosTekstopisca(){
		unesiOsobu();
		cout<<"Unesite broj napisanih pesama :";
		cin>>brojNapisanihPesama;
		fflush(stdin);
		cout<<endl;
		cout<<"Unesite godine iskustva :";
		cin>>godineIskustva;
		fflush(stdin);
		cout<<endl;
	}

};

#endif
