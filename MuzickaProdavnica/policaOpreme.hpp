#ifndef POLICAOPREME_HPP_INCLUDED
#define POLICAOPREME_HPP_INCLUDED

#include "lista.hpp"
#include "opremaZaInstrumente.hpp"
#include "mikrofon.hpp"
#include "kontroler.hpp"
#include "djOprema.hpp"
#include "mikser.hpp"

class PolicaOpreme
{
private:
    Lista<OpremaZaInstrumente> listaOpremeZaInstrumente;
    Lista<Mikrofon> listaMikrofona;
    Lista<Kontroler> listaKontrolera;
    Lista<DJOprema> listaDjOpreme;
    Lista<Mikser> listaMiksera;
public:
void setListuOpremeIn(Lista<OpremaZaInstrumente> inst)
    {
        listaOpremeZaInstrumente = inst;
    }
    void setListuMikrofona(Lista<Mikrofon> mikr)
    {
        listaMikrofona = mikr;
    }
    void setListuKontrolera(Lista<Kontroler> kon)
    {
        listaKontrolera = kon;
    }
    void setListuDJOpreme(Lista<DJOprema> dj)
    {
        listaDjOpreme = dj;
    }
    void setListuMiksera(Lista<Mikser> miks)
    {
        listaMiksera = miks;
    }

    Lista<OpremaZaInstrumente> getlistaOpremeIns()const{return listaOpremeZaInstrumente;}
    Lista<Mikrofon> getlistaMikrofona()const{return listaMikrofona;}
    Lista<Kontroler> getlistaKontrolera()const{return listaKontrolera;}
    Lista<DJOprema> getlistaDJOpreme()const{return listaDjOpreme;}
    Lista<Mikser> getlistaMiksera()const{return listaMiksera;}

    PolicaOpreme& operator+=(Mikrofon& m)
    {
        listaMikrofona.dodajElement(listaMikrofona.velicina()+1, m);
        return *this;
    }
    PolicaOpreme& operator+=(OpremaZaInstrumente& opr)
    {
        listaOpremeZaInstrumente.dodajElement(listaOpremeZaInstrumente.velicina()+1, opr);
        return *this;
    }
    PolicaOpreme& operator+=(Kontroler& k)
    {
        listaKontrolera.dodajElement(listaKontrolera.velicina()+1, k);
        return *this;
    }
    PolicaOpreme& operator+=(DJOprema& dj)
    {
        listaDjOpreme.dodajElement(listaDjOpreme.velicina()+1, dj);
        return *this;
    }
    PolicaOpreme& operator+=(Mikser& mik)
    {
        listaMiksera.dodajElement(listaMiksera.velicina()+1, mik);
        return *this;
    }

    void ispisOpremeIn()
    {
        if(listaOpremeZaInstrumente.velicina() == 0)
        {
            cout<<"-->Nema opreme za instrumente u prodavnici"<<endl;
        }
        else
        {
            OpremaZaInstrumente in;
            cout<<"Oprema za instrumente :"<<endl;

            for (int i = 1; i <= listaOpremeZaInstrumente.velicina(); i++)
            {
                listaOpremeZaInstrumente.izlistaj(i, in);
                in.ispisiOpremu();
            }
        }
    }
    void ispisMikrofonaa()
    {
        if(listaMikrofona.velicina() == 0)
        {
            cout<<"-->Nema mikrofona u prodavnici"<<endl;
        }
        else
        {
            Mikrofon mikr;
            cout<<"Mikrofoni :"<<endl;

            for (int i = 1; i <= listaMikrofona.velicina(); i++)
            {
                listaMikrofona.izlistaj(i, mikr);
                mikr.ispisiMikrofon();
            }
        }
    }
    void ispisKontrolerova()
    {
        if(listaKontrolera.velicina() == 0)
        {
            cout<<"-->Nema kontrolera u prodavnici"<<endl;
        }
        else
        {
            Kontroler ko;
            cout<<"Kontroleri :"<<endl;

            for (int i = 1; i <= listaKontrolera.velicina(); i++)
            {
                listaKontrolera.izlistaj(i, ko);
                ko.ispisiKontroler();
            }
        }
    }
    void ispisDjOpreme()
    {
        if(listaDjOpreme.velicina() == 0)
        {
            cout<<"-->Nema DJ opreme u prodavnici"<<endl;
        }
        else
        {
            DJOprema dj;
            cout<<"DJ oprema :"<<endl;

            for (int i = 1; i <= listaDjOpreme.velicina(); i++)
            {
                listaDjOpreme.izlistaj(i, dj);
                dj.ispisiDJOprema();
            }
        }
    }
    void ispisMikserova()
    {
        if(listaMiksera.velicina() == 0)
        {
            cout<<"-->Nema miksera u prodavnici"<<endl;
        }
        else
        {
            Mikser miks;
            cout<<"Mikseri :"<<endl;

            for (int i = 1; i <= listaMiksera.velicina(); i++)
            {
                listaMiksera.izlistaj(i, miks);
                miks.ispisMiksera();
            }
        }
    }

};
#endif
