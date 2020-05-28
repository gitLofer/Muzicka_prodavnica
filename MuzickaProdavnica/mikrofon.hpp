#ifndef MIKROFON_HPP_INCLUDED
#define MIKROFON_HPP_INCLUDED

#inlcude "proizvod.hpp"
enum mikrofonVrsta {zicani, bezicni, studijski};

class Mikrofon : public Proizvod
{
private:
    mikrofonVrsta vrsta;
public:

    int mikrofonID;

    Mikrofon()
    {
        cena = 7999.99;
        ocena = 9.66;
        proizvodjac = yamaha;
        vrsta = studijski;
    }

    Mikrofon( float CENA, float OCENA, proizvodjaci PROIZVODJAC, mikrofonVrsta VRSTA)
    {
        cena = CENA;
        ocena = OCENA;
        proizvodjac = PROIZVODJAC;
        vrsta = VRSTA;
    }

    Mikrofon(const Mikrofon &m)
    {
        cena = m.cena;
        ocena = m.ocena;
        proizvodjac = m.proizvodjac;
        vrsta = m.vrsta;
    }

    int getMikrofonID()const;
    string getVrsta()const
    {
        switch(vrsta)
        {
    case bezicni:
        return "Bezicni";
        break;
    case studijski:
        return "Studijski";
        break;
    case zicani:
        return "Zicani";
        break;
        }
    }

    void setVrsta()
    {
        int br;
        cout<<"Vrsta mikrofona[1-Bezicni/2-Studijski/3-Zicani]: "<<endl;
        cin>>br;

        switch(br)
        {
    case 1:
        vrsta = bezicni;
        break;
    case 2:
        vrsta = studijski;
        break;
    case 3:
        vrsta = zicani;
        break;
        }

    }

   void ispisiMikrofon()
   {
       cout<<"ID: "<<getMikrofonID()<<endl;
        ispisProizvoda();
        cout<<"Vrsta: "<<getVrsta()<<endl;
   }

   void unesiMikrofon()
   {
       cout<<"ID: ";
       cin>>mikrofonID;
       fflush(stdin);
       unosProizvoda();
       setVrsta();
   }

};

int Mikrofon::getMikrofonID()const {return mikrofonID;}

void dodajUFajlMikrofon()
{
	Mikrofon m;
	ofstream outFile;
	outFile.open("MIKROFON.dat",ios::binary|ios::app);
	m.unesiMikrofon();
	outFile.write(reinterpret_cast<char *> (&m), sizeof(Mikrofon));
	outFile.close();
    	cout<<"\n\nMikrofon dodat u fajl!";
	cin.ignore();
	cin.get();
}
void ispisiFajlMikrofon()
{
	Mikrofon m;
	ifstream inFile;
	inFile.open("MIKROFON.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVI MIKROFONI U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&m), sizeof(Mikrofon)))
	{
	    m.ispisiMikrofon();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluMikrofon(int n)
{
	Mikrofon m;
	ifstream inFile;
	inFile.open("MIKROFON.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&m), sizeof(Mikrofon)))
	{
		if(m.getMikrofonID()==n)
		{
	  		m.ispisiMikrofon();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nMikrofon ne postoji!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluMikrofon(int n)
{
	Mikrofon m;
	ifstream inFile;
	inFile.open("MIKROFON.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempMikrofon.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&m), sizeof(Mikrofon)))
	{
		if(m.getMikrofonID()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&m), sizeof(Mikrofon));
		}
	}
	outFile.close();
	inFile.close();
	remove("MIKROFON.dat");
	rename("TempMikrofon.dat","MIKROFON.dat");
	cout<<"\n\n\tMikrofon obrisan!";
	cin.ignore();
	cin.get();
}

#endif
