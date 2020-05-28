#ifndef POLICAOSTALIHINSTRUMENATA_HPP_INCLUDED
#define POLICAOSTALIHINSTRUMENATA_HPP_INCLUDED

#include "lista.hpp"
#include "klavir.hpp"
#include "harmonika.hpp"

class PolicaOstalihInstrumenata
{
private:
    Lista<Klavir> listaKlavira;
    Lista<Harmonika> listaHarmonika;
public:
    void setListuKlavira(Lista<Klavir> klav)
    {
        listaKlavira = klav;
    }
    void setListuHarmonika(Lista<Harmonika> har)
    {
        listaHarmonika = har;
    }

    Lista<Klavir> getlistaKlavira()const{return listaKlavira;}
    Lista<Harmonika> getListaHarmonika()const{return listaHarmonika;}

    void ispisKlaviraa()
    {
        if(listaKlavira.velicina() == 0)
        {
            cout<<"-->Nema klavira u prodavnici"<<endl;
        }
        else
        {
            Klavir k;
            cout<<"Klaviri :"<<endl;

            for (int i = 1; i <= listaKlavira.velicina(); i++)
            {
                listaKlavira.izlistaj(i,k);
                k.ispisKlavira();
            }
        }
    }
    void ispisHarmonika()
    {
        if(listaHarmonika.velicina() == 0)
        {
            cout<<"-->Nema harmonika u prodavnici"<<endl;
        }
        else
        {
            Harmonika h;
            cout<<"Harmonike :"<<endl;

            for (int i = 1; i <= listaHarmonika.velicina(); i++)
            {
                listaHarmonika.izlistaj(i,h);
                h.ispisHarmonike();
            }
        }
    }

    void ispisOstalihInstrumenata()
    {
        ispisKlaviraa();
        ispisHarmonika();
    }
};
#endif
