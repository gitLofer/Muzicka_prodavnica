#ifndef POLICAUDARACKIHINSTRUMENATA_HPP_INCLUDED
#define POLICAUDARACKIHINSTRUMENATA_HPP_INCLUDED
#include "list.hpp"

class PolicaUdarackih
{
private:
    List<Bubanj> listaBubnjeva;
    List<Cinele> listaCinela;
    List<Daire> listaDaira;
    List<Kastanjete> listaKastanjeta;
    List<Metalofon> listaMetalofona;
public:
    void setListuBubnjeva(List<Bubanj> bb)
    {
        listaBubnjeva = bb;
    }
    void setListuCinela(List<Cinele> cc)
    {
        listaCinela = cc;
    }
    void setListuDaira(List<Daire> dd)
    {
        listaDaira = dd;
    }
    void setListuKastanjeta(List<Kastanjete> kk)
    {
        listaKastanjeta = kk;
    }
    void setListaMetalofona(List<Metalofon> mm)
    {
        listaMetalofona = mm;
    }

    List<Bubanj> getListuBubnjeva()const{return listaBubnjeva;}
    List<Cinele> getListuCinela()const{return listaCinela;}
    List<Daire> getListuDaira()const{return listaDaira;}
    List<Kastanjete> getListuKastanjeta()const{return listaKastanjeta;}
    List<Metalofon> getListuMetalofona()const{return listaMetalofona;}

    PolicaUdarackih& operator+=(Bubanj& bub)
    {
        listaBubnjeva.add(listaBubnjeva.size()+1, bub);
        return *this;
    }
    PolicaUdarackih& operator+=(Cinele& cine)
    {
        listaCinela.add(listaCinela.size()+1, cine);
        return *this;
    }
    PolicaUdarackih& operator+=(Daire& dar)
    {
        listaDaira.add(listaDaira.size()+1, dar);
        return *this;
    }
    PolicaUdarackih& operator+=(Kastanjete& kst)
    {
        listaKastanjeta.add(listaKastanjeta.size()+1, kst);
        return *this;
    }
    PolicaUdarackih& operator+=(Metalofon& met)
    {
        listaMetalofona.add(listaMetalofona.size()+1, met);
        return *this;
    }

    void ispisBubnjeva()
    {
        if(listaBubnjeva.size() == 0)
        {
            cout<<"-->Nema bubnjeva u prodavnici"<<endl;
        }
        else
        {
            Bubanj b;
            cout<<"Bubnjevi :"<<endl;

            for (int i = 1; i <= listaBubnjeva.size(); i++)
            {
                listaBubnjeva.read(i, b);
                b.ispisBubnja();
            }
        }
    }
    void ispisCinela()
    {
        if(listaCinela.size() == 0)
        {
            cout<<"-->Nema cinela u prodavnici"<<endl;
        }
        else
        {
            Cinele c;
            cout<<"Cinele :"<<endl;

            for (int i = 1; i <= listaCinela.size(); i++)
            {
                listaCinela.read(i, c);
                c.ispisCinela();
            }
        }
    }
    void ispisDaira()
    {
        if(listaDaira.size() == 0)
        {
            cout<<"-->Nema daira u prodavnici"<<endl;
        }
        else
        {
            Daire d;
            cout<<"Daire :"<<endl;

            for (int i = 1; i <= listaDaira.size(); i++)
            {
                listaDaira.read(i, d);
                d.ispisDaira();
            }
        }
    }
    void ispisKastanjeta()
    {
        if(listaKastanjeta.size() == 0)
        {
            cout<<"-->Nema kastanjeta u prodavnici"<<endl;
        }
        else
        {
            Kastanjete k;
            cout<<"Kastanjete :"<<endl;

            for (int i = 1; i <= listaKastanjeta.size(); i++)
            {
                listaKastanjeta.read(i, k);
                k.ispisKastanjeta();
            }
        }
    }
    void ispisMetalofonaa()
    {
        if(listaMetalofona.size() == 0)
        {
            cout<<"-->Nema metalofona u prodavnici"<<endl;
        }
        else
        {
            Metalofon m;
            cout<<"Metalofoni :"<<endl;

            for (int i = 1; i <= listaMetalofona.size(); i++)
            {
                listaMetalofona.read(i, m);
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

#endif // POLICAUDARACKIHINSTRUMENATA_HPP_INCLUDED
