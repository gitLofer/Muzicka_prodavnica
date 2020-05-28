#ifndef PRODAVNICA_HPP_INCLUDED
#define PRODAVNICA_HPP_INCLUDED

#include "lista.hpp"
#include "zaposlen.hpp"
#include "lokacija.hpp"
#include "kasa.hpp"

class Prodavnica{
private:
	Lokacija l;
	Lista<Zaposlen> zaposlenii;
	int kz;
public:
	
	Prodavnica():l(),kz(20){}
	Prodavnica(string nazivUlice,string grad,string drzava,int brojUlice, int postanskiBroj,int k):l(nazivUlice,grad,drzava,brojUlice,postanskiBroj),kz(k){}
	Prodavnica(Prodavnica &p):l(p.l),kz(p.kz){}

	bool dodajZaposlenog(const Zaposlen &z){
        	if(zaposlenii.velicina()<kz){
          	 	return zaposlenii.dodajElement(zaposlenii.velicina()+1,z);
        	}else
       		 return false;
   	 }

    	 void dajOtkaz(const Zaposlen &z,int n){
        	zaposlenii.izbrisiElement(n);
    	}
	
	void ispis(Kasa &k){
		Zaposlen z;
		cout<<endl<<"Zaposleni: " << endl;
        	cout<<"-------------------"<<endl;
		
		 for(int i=1;i<=zaposlenii.velicina();i++){
            		cout<<"Zaposleni broj "<<i<<":";
            		zaposlenii.izlistaj(i,z);
			cout<<"Ime :"<<z.getIme()<<endl<<"Prezime :"<<z.getPrezime()<<endl;
			cout<<"Godine :"<<z.getGodine()<<endl;
			cout<<"Plata :"<<z.getPlata()<<endl;
			cout<<"Sati rada :"<<z.getSatiRada()<<endl;
		}
		cout<<endl;
		cout<<k;
		k.ispisProdatihProizvoda();
	}
		
		
};

#endif //PRODAVNICA_HPP_INCLUDED
