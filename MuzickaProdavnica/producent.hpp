#ifndef PRODUCENT_HPP_INCLUDED
#define PRODUCENT_HPP_INCLUDED

#include "osoba.hpp"

class Producent : public Osoba{
private:
	int brojNapravljenihPesama;
	string softver;
  
public:
	Producent(){
		ime="Lazar";
		prezime="Savic";
		godine=45;
		brojNapravljenihPesama=60;
		softver="FL Studio";
	}

	Producent(string i,string p, int g, int bnp, string s){
		ime=i;
		prezime=p;
		godine=g;
		brojNapravljenihPesama=bnp;
		softver=s;
	}

	Producent(const Producent &p){
		ime=p.ime;
		prezime=p.prezime;
		godine=p.godine;
		brojNapravljenihPesama=p.brojNapravljenihPesama;
		softver=p.softver;
	}

	void setBrojnapravljenihpesama(int bnp){brojNapravljenihPesama=bnp; }
	void setSoftver(string s){softver=s; }

	int getBrojnapravljenihpesama(){return brojNapravljenihPesama; }
	string getSoftver(){return softver; }

	void ispisProducenta(){
		ispisiOsobu();
		cout<<"Broj napravljenih pesama :"<<getBrojnapravljenihpesama()<<endl;
		cout<<"Softver :"<<getSoftver()<<endl;

	}

	void unosProducenta(){
		unesiOsobu();
		cout<<"Unesite broj napravljenih pesama :";
		cin>>brojNapravljenihPesama;
		fflush(stdin);
		cout<<endl;
		cout<<"Softver :";
		cin>>softver;
		fflush(stdin);
		cout<<endl;

	}
};

#endif
