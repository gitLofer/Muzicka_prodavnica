#ifndef OSOBA_HPP_INCLUDED
#define OSOBA_HPP_INCLUDED

class Osoba
{
protected:
string ime, prezime;
int godine;

public:
Osoba()
{
ime = "Nije uneto";
prezime = "Nije uneto";
godine = 0;
}

Osoba(string IME, string PREZIME, int GODINE)
{
ime = IME;
prezime = PREZIME;
godine = GODINE;
}

Osoba(const Osoba &o)
{
ime = o.ime;
prezime = o.prezime;
godine = o.godine;
}

string getIme()const {return ime;}
string getPrezime()const {return prezime;}
int getGodine()const {return godine;}

void setIme(string IME) {ime = IME;}
void setPrezime(string PREZIME) {prezime = PREZIME;}
void setGodine(int GODINE) {godine = GODINE;}


void ispisiOsobu()
{
cout<<"Ime: "<<getIme()<<endl;
cout<<"Prezime: "<<getPrezime()<<endl;
cout<<"Godine: "<<getGodine()<<endl;
}

void unesiOsobu()
{
cout<<"Ime: ";
cin>>ime;
fflush(stdin);
cout<<"Prezime: ";
cin>>prezime;
fflush(stdin);
cout<<"Godine: ";
cin>>godine;
fflush(stdin);
}

};

#endif
