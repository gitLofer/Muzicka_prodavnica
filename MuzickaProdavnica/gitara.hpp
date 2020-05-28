#ifndef GITARA_HPP_INCLUDED
#define GITARA_HPP_INCLUDED

#include "zicaniInstrument.hpp"
class Gitara : public ZicaniInstrument
{
private:
    gitaraVrsta vrstaGitare;
public:

    int gitaraID;

    Gitara()
    {

        cena = 9500.00;
        ocena = 9.9;
        proizvodjac = yamaha;
        brojZica = 6;
        duzinaZice = 1.33;
        vrstaZica = nikl;
        vrstaGitare = elektricnaGitara;
    }
    Gitara( float cc, float oo, proizvodjaci pp, int broj, float duzina, zicaVrsta vrs, gitaraVrsta git)
    {

        cena = cc;
        ocena = oo;
        proizvodjac = pp;
        brojZica = broj;
        duzinaZice = duzina;
        vrstaZica = vrs;
        vrstaGitare = git;
    }
    Gitara(const Gitara &g)
    {
        cena = g.cena;
        ocena = g.ocena;
        proizvodjac = g.proizvodjac;
        brojZica = g.brojZica;
        duzinaZice = g.duzinaZice;
        vrstaZica = g.vrstaZica;
        vrstaGitare = g.vrstaGitare;
    }

    void setVrstaGitare(gitaraVrsta vrs){vrstaGitare = vrs; }

    int getGitaraID()const;
    string getVrstaGitare()const
    {
        switch(vrstaGitare)
        {
        case klasicnaGitara:
            return "KLASICNA GITARA";
            break;
        case akusticnaGitara:
            return "AKUSTICNA GITARA";
            break;
        case elektroAkusticnaGitara:
            return "ELEKTROAKUSTICNA GITARA";
            break;
        case elektricnaGitara:
            return "ELEKTRICNA GITARA";
            break;
        case basGitara:
            return "BAS GITARA";
            break;
        default:
            return "Nema vrste gitare";
            break;
        }
    }

    void ispisGitare(){
        cout<<"ID: "<<getGitaraID()<<endl;
        ispisZicanogInstrumenta();
        cout<<"Vrsta gitare: "<<getVrstaGitare()<<endl;
    }

    void unosGitare(){
        int br;
        cout<<"ID: ";
        cin>>gitaraID;
        unosZicanogInstrumenta();
        cout<<"Vrsta gitare[1-Akusticna/2-Bas/3-Elektricna/4-Elektro akusticna/5-Klasicna]: ";
        cin>>br;
        switch(br)
        {
        case 1:
            vrstaGitare = akusticnaGitara;
            break;
        case 2:
            vrstaGitare = basGitara;
            break;
        case 3:
            vrstaGitare = elektricnaGitara;
            break;
        case 4:
            vrstaGitare = elektroAkusticnaGitara;
            break;
        case 5:
            vrstaGitare = klasicnaGitara;
            break;

        }
    }

};

int Gitara::getGitaraID()const {return gitaraID;}

void dodajUFajlGitara()
{
	Gitara g;
	ofstream outFile;
	outFile.open("GITARA.dat",ios::binary|ios::app);
	g.unosGitare();
	outFile.write(reinterpret_cast<char *> (&g), sizeof(Gitara));
	outFile.close();
    	cout<<"\n\nGitara dodata u fajl!";
	cin.ignore();
	cin.get();
}
void ispisiFajlGitara()
{
	Gitara g;
	ifstream inFile;
	inFile.open("GITARA.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tSVE GITARE U FAJLU\n\n";
	while(inFile.read(reinterpret_cast<char *> (&g), sizeof(Gitara)))
	{
	    g.ispisGitare();
		cout<<"\n\n************************************\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void potraziUFajluGitara(int n)
{
	Gitara g;
	ifstream inFile;
	inFile.open("GITARA.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&g), sizeof(Gitara)))
	{
		if(g.getGitaraID()==n)
		{
	  		g.ispisGitare();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nGitara ne postoji!"<<endl;
	cin.ignore();
	cin.get();
}

void obrisiUFajluGitara(int n)
{
	Gitara g;
	ifstream inFile;
	inFile.open("GITARA.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Greska! Ne moze se otvoriti fajl!";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("TempGitara.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&g), sizeof(Gitara)))
	{
		if(g.getGitaraID()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&g), sizeof(Gitara));
		}
	}
	outFile.close();
	inFile.close();
	remove("GITARA.dat");
	rename("TempGitara.dat","GITARA.dat");
	cout<<"\n\n\tGitara obrisana!";
	cin.ignore();
	cin.get();
}


#endif // GITARA_HPP_INCLUDED
