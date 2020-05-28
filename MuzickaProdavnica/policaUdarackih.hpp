#ifndef POLICAUDARACKIH_HPP_INCLUDED
#define POLICAUDARACKIH_HPP_INCLUDED

#include "lista.hpp"
#include "bubanj.hpp"
#include "cinele.hpp"
#include "daire.hpp"
#include "kastanjete.hpp"
#inlcude "metalofon.hpp"

class PolicaUdarackih
{
private:
    Lista<Bubanj> listaBubnjeva;
    Lista<Cinele> listaCinela;
    Lista<Daire> listaDaira;
    Lista<Kastanjete> listaKastanjeta;
    Lista<Metalofon> listaMetalofona;
public:
    void setListuBubnjeva(Lista<Bubanj> bb)
    {
        listaBubnjeva = bb;
    }
    void setListuCinela(Lista<Cinele> cc)
    {
        listaCinela = cc;
    }
    void setListuDaira(Lista<Daire> dd)
    {
        listaDaira = dd;
    }
    void setListuKastanjeta(Lista<Kastanjete> kk)
    {
        listaKastanjeta = kk;
    }
    void setListaMetalofona(Lista<Metalofon> mm)
    {
        listaMetalofona = mm;
    }

    Lista<Bubanj> getListuBubnjeva()const{return listaBubnjeva;}
    Lista<Cinele> getListuCinela()const{return listaCinela;}
    Lista<Daire> getListuDaira()const{return listaDaira;}
    Lista<Kastanjete> getListuKastanjeta()const{return listaKastanjeta;}
    Lista<Metalofon> getListuMetalofona()const{return listaMetalofona;}

    PolicaUdarackih& operator+=(Bubanj& bub)
    {
        listaBubnjeva.dodajElement(listaBubnjeva.velicina()+1, bub);
        return *this;
    }
    PolicaUdarackih& operator+=(Cinele& cine)
    {
        listaCinela.dodajElement(listaCinela.velicina()+1, cine);
        return *this;
    }
    PolicaUdarackih& operator+=(Daire& dar)
    {
        listaDaira.dodajElement(listaDaira.velicina()+1, dar);
        return *this;
    }
    PolicaUdarackih& operator+=(Kastanjete& kst)
    {
        listaKastanjeta.dodajElement(listaKastanjeta.velicina()+1, kst);
        return *this;
    }
    PolicaUdarackih& operator+=(Metalofon& met)
    {
        listaMetalofona.dodajElement(listaMetalofona.velicina()+1, met);
        return *this;
    }

    void ispisBubnjeva()
    {
        if(listaBubnjeva.velicina() == 0)
        {
            cout<<"-->Nema bubnjeva u prodavnici"<<endl;
        }
        else
        {
            Bubanj b;
            cout<<"Bubnjevi :"<<endl;

            for (int i = 1; i <= listaBubnjeva.velicina(); i++)
            {
                listaBubnjeva.izlistaj(i, b);
                b.ispisBubnja();
            }
        }
    }
    void ispisCinela()
    {
        if(listaCinela.velicina() == 0)
        {
            cout<<"-->Nema cinela u prodavnici"<<endl;
        }
        else
        {
            Cinele c;
            cout<<"Cinele :"<<endl;

            for (int i = 1; i <= listaCinela.velicina(); i++)
            {
                listaCinela.izlistaj(i, c);
                c.ispisCinela();
            }
        }
    }
    void ispisDaira()
    {
        if(listaDaira.velicina() == 0)
        {
            cout<<"-->Nema daira u prodavnici"<<endl;
        }
        else
        {
            Daire d;
            cout<<"Daire :"<<endl;

            for (int i = 1; i <= listaDaira.velicina(); i++)
            {
                listaDaira.izlistaj(i, d);
                d.ispisDaira();
            }
        }
    }
    void ispisKastanjeta()
    {
        if(listaKastanjeta.velicina() == 0)
        {
            cout<<"-->Nema kastanjeta u prodavnici"<<endl;
        }
        else
        {
            Kastanjete k;
            cout<<"Kastanjete :"<<endl;

            for (int i = 1; i <= listaKastanjeta.velicina(); i++)
            {
                listaKastanjeta.izlistaj(i, k);
                k.ispisKastanjeta();
            }
        }
    }
    void ispisMetalofonaa()
    {
        if(listaMetalofona.velicina() == 0)
        {
            cout<<"-->Nema metalofona u prodavnici"<<endl;
        }
        else
        {
            Metalofon m;
            cout<<"Metalofoni :"<<endl;

            for (int i = 1; i <= listaMetalofona.velicina(); i++)
            {
                listaMetalofona.izlistaj(i, m);
                m.ispisMetalofona();
            }
        }
    }

    void ispisPolicaUdarackihInstrumenata()
    {
        ispisBubnjeva();
        ispisCinela();
        ispisDaira();
        ispisKastanjeta();
        ispisMetalofonaa();
    }
};
#endif
