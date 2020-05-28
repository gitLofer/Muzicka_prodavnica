#ifndef POLICAZICANIHINSTRUMENATA_HPP_INCLUDED
#define POLICAZICANIHINSTRUMENATA_HPP_INCLUDED

#include "lista.hpp"

class PolicaZicanih
{
private:
    Lista<Gitara> listaGitara;
    Lista<Harfa> listaHarfi;
    Lista<Ukulele> listaUkulelea;
public:
    void setListuGitara(Lista<Gitara> gg)
    {
        listaGitara = gg;
    }
    void setListuHarfi(Lista<Harfa> hh)
    {
        listaHarfi = hh;
    }
    void setListuUkulelea(Lista<Ukulele> uu)
    {
        listaUkulelea = uu;
    }

    Lista<Gitara> getListuGitara()const{return listaGitara;}
    Lista<Harfa> getListuHarfi()const{return listaHarfi;}
    Lista<Ukulele> getListuUkulelea()const{return listaUkulelea;}

    PolicaZicanih& operator+=(Gitara& git)
    {
        listaGitara.dodajElement(listaGitara.velicina()+1, git);
        return *this;
    }
    PolicaZicanih& operator+=(Harfa& harf)
    {
        listaHarfi.dodajElement(listaHarfi.velicina()+1, harf);
        return *this;
    }
    PolicaZicanih& operator+=(Ukulele& ukul)
    {
        listaUkulelea.dodajElement(listaUkulelea.velicina()+1, ukul);
        return *this;
    }

    void ispisGitara()
    {
        if(listaGitara.velicina() == 0)
        {
            cout<<"-->Nema gitara u prodavnici"<<endl;
        }
        else
        {
            Gitara g;
            cout<<"Gitare :"<<endl;

            for (int i = 1; i <= listaGitara.velicina(); i++)
            {
                listaGitara.izlistaj(i, g);
                g.ispisGitare();
            }
        }
    }
    void ispisHarfi()
    {
        if(listaHarfi.velicina() == 0)
        {
            cout<<"-->Nema harfi u prodavnici"<<endl;
        }
        else
        {
            Harfa h;
            cout<<"Harfe :"<<endl;

            for (int i = 1; i <= listaHarfi.velicina(); i++)
            {
                listaHarfi.izlistaj(i, h);
                h.ispisHarfe();
            }
        }
    }
    void ispisUkulelea()
    {
        if(listaUkulelea.velicina() == 0)
        {
            cout<<"-->Nema ukulelea u prodavnici"<<endl;
        }
        else
        {
            Ukulele u;
            cout<<"Ukulelei :"<<endl;

            for (int i = 1; i <= listaUkulelea.velicina(); i++)
            {
                listaUkulelea.izlistaj(i, u);
                u.ispisUkulelea();
            }
        }
    }

    void ispisPoliceZicanihInstrumenata()
    {
        ispisGitara();
        ispisHarfi();
        ispisUkulelea();
    }
};


#endif // POLICAZICANIHINSTRUMENATA_HPP_INCLUDED
