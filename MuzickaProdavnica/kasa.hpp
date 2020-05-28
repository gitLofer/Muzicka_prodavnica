#include "lista.hpp"
#include "proizvod.hpp"

class Kasa{
private:
	Lista<Proizvod> prodati;
	double trenutnostanje;
	int kp;
  
public:
	Kasa(){trenutnostanje=0.00; kp=200;}
	Kasa(double t,int k){trenutnostanje=t; kp=k; }
	Kasa(const Kasa &k){trenutnostanje=k.trenutnostanje; kp=k.kp;}

	void setKasa(double t){trenutnostanje=t; }
	double getKasa(){return trenutnostanje; }

	double dodajukasu(Proizvod &p){
       	 	trenutnostanje+=p.getCena();
        	return trenutnostanje;
    	}

	bool dodajProdato(const Proizvod &p){
        	if(prodati.velicina()<kp){
         	  return prodati.dodajElement(prodati.velicina()+1,p);

       	 	}else
       	 	return false;
   	 }

	void ispisProdatihProizvoda(){
        	Proizvod p;
        	cout<<endl<<"Prodati proizvodi :" << endl;
        	cout<<"=============="<<endl;

       		 for(int i=1;i<=prodati.velicina();i++){
           		 cout<<"Proizvod broj "<<i<<":";
            		cout<<endl;
            		prodati.izlistaj(i,p);
            		cout<<"Naziv :"<<p.getNaziv()<<endl;
            		cout<<"Cena :"<<p.getCena()<<endl;
			cout<<"Ocena :"<<p.getOcena()<<endl;
			cout<<"Proizvodjac :"<<p.getProizvodjac()<<endl;

            	}
        	cout<<endl;
	}

	friend ostream& operator<<(ostream& out, const Kasa &k){
        	out<<"------KASA------"<<endl<<"Trenutno stanje u kasi :"<<k.trenutnostanje<<endl<<endl;
        	return out;
    }
};
