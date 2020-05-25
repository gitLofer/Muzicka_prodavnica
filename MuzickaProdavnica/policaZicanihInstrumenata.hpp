#ifndef POLICAZICANIHINSTRUMENATA_HPP_INCLUDED
#define POLICAZICANIHINSTRUMENATA_HPP_INCLUDED

#include "list.hpp"
class PolicaZicanih
{
private:
    List<Gitara> listaGitara;
    List<Harfa> listaHarfi;
    List<Ukulele> listaUkulelea;
public:
    void setListuGitara(List<Gitara> gg)
    {
        listaGitara = gg;
    }
    void setListuHarfi(List<Harfa> hh)
    {
        listaHarfi = hh;
    }
    void setListuUkulelea(List<Ukulele> uu)
    {
        listaUkulelea = uu;
    }

    List<Gitara> getListuGitara()const{return listaGitara;}
    List<Harfa> getListuHarfi()const{return listaHarfi;}
    List<Ukulele> getListuUkulelea()const{return listaUkulelea;}

    PolicaZicanih& operator+=(Gitara& git)
    {
        listaGitara.add(listaGitara.size()+1, git);
        return *this;
    }
    PolicaZicanih& operator+=(Harfa& harf)
    {
        listaHarfi.add(listaHarfi.size()+1, harf);
        return *this;
    }
    PolicaZicanih& operator+=(Ukulele& ukul)
    {
        listaUkulelea.add(listaUkulelea.size()+1, ukul);
        return *this;
    }

    void ispisGitara()
    {
        if(listaGitara.size() == 0)
        {
            cout<<"-->Nema gitara u prodavnici"<<endl;
        }
        else
        {
            Gitara g;
            cout<<"Gitare :"<<endl;

            for (int i = 1; i <= listaGitara.size(); i++)
            {
                listaGitara.read(i, g);
                g.ispisGitare();
            }
        }
    }
    void ispisHarfi()
    {
        if(listaHarfi.size() == 0)
        {
            cout<<"-->Nema harfi u prodavnici"<<endl;
        }
        else
        {
            Harfa h;
            cout<<"Harfe :"<<endl;

            for (int i = 1; i <= listaHarfi.size(); i++)
            {
                listaHarfi.read(i, h);
                h.ispisHarfe();
            }
        }
    }
    void ispisUkulelea()
    {
        if(listaUkulelea.size() == 0)
        {
            cout<<"-->Nema ukulelea u prodavnici"<<endl;
        }
        else
        {
            Ukulele u;
            cout<<"Ukulelei :"<<endl;

            for (int i = 1; i <= listaUkulelea.size(); i++)
            {
                listaUkulelea.read(i, u);
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
