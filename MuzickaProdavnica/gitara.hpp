#ifndef GITARA_HPP_INCLUDED
#define GITARA_HPP_INCLUDED

class Gitara : public ZicaniInstrument
{
private:
    gitaraVrsta vrstaGitare;
public:
    Gitara()
    {
        naziv = "Gitara";
        cena = 9500.00;
        ocena = 9.9;
        proizvodjac = yamaha;
        boja = "BELA";
        timbre = "sharp";
        brojZica = 6;
        duzinaZice = 1.33;
        vrstaZica = nikl;
        vrstaGitare = elektricnaGitara;
    }
    Gitara(DinString naz, float cc, float oo, proizvodjaci pp, DinString bb, DinString tt, int broj, float duzina, zicaVrsta vrs, gitaraVrsta git)
    {
        naziv = naz;
        cena = cc;
        ocena = oo;
        proizvodjac = pp;
        boja = bb;
        timbre = tt;
        brojZica = broj;
        duzinaZice = duzina;
        vrstaZica = vrs;
        vrstaGitare = git;
    }
    Gitara(const Gitara &g)
    {
        naziv = g.naziv;
        cena = g.cena;
        ocena = g.ocena;
        proizvodjac = g.proizvodjac;
        boja = g.boja;
        timbre = g.timbre;
        brojZica = g.brojZica;
        duzinaZice = g.duzinaZice;
        vrstaZica = g.vrstaZica;
        vrstaGitare = g.vrstaGitare;
    }

    void setVrstaGitare(gitaraVrsta vrs){vrstaGitare = vrs;}

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

    void ispisGitare()
    {
        ZicaniInstrument :: ispisZicanogInstrumenta();
        cout<<"Vrsta gitare: "<<getVrstaGitare()<<endl;
    }

};


#endif // GITARA_HPP_INCLUDED
