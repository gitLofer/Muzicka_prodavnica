#ifndef POLICAGUDACKIH_HPP_INCLUDED
#define POLICAGUDACKIH_HPP_INCLUDED

#include "lista.hpp"
#include "violina.hpp"
#include "violoncelo.hpp"
#include "viola.hpp"
#include "kontrabas.hpp"

class PolicaGudackih
{
private:
    Lista<Violoncelo> listaVioloncela;
    Lista<Violina> listaViolina;
    Lista<Viola> listaViola;
    Lista<Kontrabas> listaKontrabasa;
public:
    void setListuVioloncela(Lista<Violoncelo> vio)
    {
        listaVioloncela = vio;
    }
    void setListuViolina(Lista<Violina> vil)
    {
        listaViolina = vil;
    }

    void setListuKontrabasa(Lista<Kontrabas> komb)
    {
        listaKontrabasa = komb;
    }

    Lista<Violoncelo> getlistaVioloncela()const{return listaVioloncela;}
    Lista<Violina> getlistaViolina()const{return listaViolina;}
    Lista<Viola> getlistaViola()const{return listaViola;}
    Lista<Kontrabas> getlistaKontrabasa()const{return listaKontrabasa;}

    PolicaGudackih& operator+=(Violoncelo& viol)
    {
        listaVioloncela.dodajElement(listaVioloncela.velicina()+1, viol);
        return *this;
    }
    PolicaGudackih& operator+=(Violina& vi)
    {
        listaViolina.dodajElement(listaViolina.velicina()+1, vi);
        return *this;
    }
    PolicaGudackih& operator+=(Viola& vo)
    {
        listaViola.dodajElement(listaViola.velicina()+1, vo);
        return *this;
    }
    PolicaGudackih& operator+=(Kontrabas& kon)
    {
        listaKontrabasa.dodajElement(listaKontrabasa.velicina()+1, kon);
        return *this;
    }

    void ispisVioloncela()
    {
        if(listaVioloncela.velicina() == 0)
        {
            cout<<"-->Nema violoncela u prodavnici"<<endl;
        }
        else
        {
            Violoncelo vo;
            cout<<"Violoncela :"<<endl;

            for (int i = 1; i <= listaVioloncela.velicina(); i++)
            {
                listaVioloncela.izlistaj(i, vo);
                vo.ispisVioloncela();
            }
        }
    }
    void ispisViolina()
    {
        if(listaViolina.velicina() == 0)
        {
            cout<<"-->Nema violina u prodavnici"<<endl;
        }
        else
        {
            Violina vi;
            cout<<"Violine :"<<endl;

            for (int i = 1; i <= listaViolina.velicina(); i++)
            {
                listaViolina.izlistaj(i, vi);
                vi.ispisVioline();
            }
        }
    }
    void ispisViola()
    {
        if(listaViola.velicina() == 0)
        {
            cout<<"-->Nema viola u prodavnici"<<endl;
        }
        else
        {
            Viola v;
            cout<<"Viole :"<<endl;

            for (int i = 1; i <= listaViola.velicina(); i++)
            {
                listaViola.izlistaj(i, v);
                v.ispisViole();
            }
        }
    }
    void ispisKontrabasova()
    {
        if(listaKontrabasa.velicina() == 0)
        {
            cout<<"-->Nema kontrabasa u prodavnici"<<endl;
        }
        else
        {
            Kontrabas kb;
            cout<<"Kontrabasi :"<<endl;

            for (int i = 1; i <= listaKontrabasa.velicina(); i++)
            {
                listaKontrabasa.izlistaj(i, kb);
                kb.ispisKontrabasa();
            }
        }
    }

    void ispisPoliceGudackihInstrumenataIKlavira()
    {
        ispisVioloncela();
        ispisViolina();
        ispisViola();
        ispisKontrabasova();
    }

};
#endif
