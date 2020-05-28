#ifndef POLICADUVACKIHINSTRUMENATA_HPP_INCLUDED
#define POLICADUVACKIHINSTRUMENATA_HPP_INCLUDED

#include "lista.hpp"

class PolicaDuvackih
{
private:
    Lista<Tuba> listaTubi;
    Lista<Truba> listaTrubi;
    Lista<Trombon> listaTrombona;
    Lista<Saksofon> listaSaksofona;
    Lista<Oboa> listaOboa;
    Lista<Klarinet> listaKlarineta;
    Lista<Horna> listaHorni;
    Lista<Flauta> listaFlauti;
public:
    void setListaTubi(Lista<Tuba> tb)
    {
        listaTubi = tb;
    }
    void setListaTruba(Lista<Truba> trub)
    {
        listaTrubi = trub;
    }
    void setListaTrombona(Lista<Trombon> trom)
    {
        listaTrombona = trom;
    }
    void setListaSaksofona(Lista<Saksofon> saks)
    {
        listaSaksofona = saks;
    }
    void setListaOboa(Lista<Oboa> ob)
    {
        listaOboa = ob;
    }
    void setListaKlarineta(Lista<Klarinet> klr)
    {
        listaKlarineta = klr;
    }
    void setListaHorni(Lista<Horna> horn)
    {
        listaHorni = horn;
    }
    void setListaFlauta(Lista<Flauta> fla)
    {
        listaFlauti = fla;
    }

    Lista<Tuba> getlistaTubi()const{return listaTubi;}
    Lista<Truba> getlistaTrubi()const{return listaTrubi;}
    Lista<Trombon> getlistaTrombona()const{return listaTrombona;}
    Lista<Saksofon> getlistaSaksofona()const{return listaSaksofona;}
    Lista<Oboa> getlistaOboa()const{return listaOboa;}
    Lista<Klarinet> getlistaKlarineta()const{return listaKlarineta;}
    Lista<Flauta> getlistaFlauti()const{return listaFlauti;}

    PolicaDuvackih& operator+=(Tuba& tub)
    {
        listaTubi.dodajElement(listaTubi.velicina()+1, tub);
        return *this;
    }
    PolicaDuvackih& operator+=(Truba& trub)
    {
        listaTrubi.dodajElement(listaTrubi.velicina()+1, trub);
        return *this;
    }
    PolicaDuvackih& operator+=(Trombon& trom)
    {
        listaTrombona.dodajElement(listaTrombona.velicina()+1, trom);
        return *this;
    }
    PolicaDuvackih& operator+=(Oboa& obo)
    {
        listaOboa.dodajElement(listaOboa.velicina()+1, obo);
        return *this;
    }
    PolicaDuvackih& operator+=(Klarinet& klar)
    {
        listaKlarineta.dodajElement(listaKlarineta.velicina()+1, klar);
        return *this;
    }
    PolicaDuvackih& operator+=(Horna& hor)
    {
        listaHorni.dodajElement(listaHorni.velicina()+1, hor);
        return *this;
    }
    PolicaDuvackih& operator+=(Flauta& flat)
    {
        listaFlauti.dodajElement(listaFlauti.velicina()+1, flat);
        return *this;
    }
    
     PolicaDuvackih& operator+=(Saksofon& s)
    {
        listaSaksofona.dodajElement(listaSaksofona.velicina()+1, s);
        return *this;
    }


    void ispisTubi()
    {
        if(listaTubi.velicina() == 0)
        {
            cout<<"-->Nema tubi u prodavnici"<<endl;
        }
        else
        {
            Tuba t;
            cout<<"Tube :"<<endl;

            for (int i = 1; i <= listaTubi.velicina(); i++)
            {
                listaTubi.izlistaj(i, t);
                t.ispisTube();
            }
        }
    }
    void ispisTrubaa()
    {
        if(listaTrubi.velicina() == 0)
        {
            cout<<"-->Nema trubi u prodavnici"<<endl;
        }
        else
        {
            Truba r;
            cout<<"Trube :"<<endl;

            for (int i = 1; i <= listaTrubi.velicina(); i++)
            {
                listaTrubi.izlistaj(i, r);
                r.ispisTruba();
            }
        }
    }
    void ispisTrombonaa()
    {
        if(listaTrombona.velicina() == 0)
        {
            cout<<"-->Nema trombona u prodavnici"<<endl;
        }
        else
        {
            Trombon rb;
            cout<<"Tromboni :"<<endl;

            for (int i = 1; i <= listaTrombona.velicina(); i++)
            {
                listaTrombona.izlistaj(i, rb);
                rb.ispisTrombona();
            }
        }
    }
    void ispisSakdofonaa()
    {
        if(listaSaksofona.velicina() == 0)
        {
            cout<<"-->Nema saksofona u prodavnici"<<endl;
        }
        else
        {
            Saksofon s;
            cout<<"Saksofoni :"<<endl;

            for (int i = 1; i <= listaSaksofona.velicina(); i++)
            {
                listaSaksofona.izlistaj(i, s);
                s.ispisSaksofona();
            }
        }
    }
    void ispisOboa()
    {
       if(listaOboa.velicina() == 0)
        {
            cout<<"-->Nema oboa u prodavnici"<<endl;
        }
        else
        {
            Oboa o;
            cout<<"Oboe :"<<endl;

            for (int i = 1; i <= listaOboa.velicina(); i++)
            {
                o.ispisOboe();
            }
        }
    }

    void ispisKlarinetosa()
    {
        if(listaKlarineta.velicina() == 0)
        {
            cout<<"-->Nema klarineta u prodavnici"<<endl;
        }
        else
        {
            Klarinet kk;
            cout<<"Klarineti :"<<endl;

            for (int i = 1; i <= listaKlarineta.velicina(); i++)
            {
                listaKlarineta.izlistaj(i, kk);
                kk.ispisKlarineta();
            }
        }
    }
    void ispisHorni()
    {
        if(listaHorni.velicina() == 0)
        {
            cout<<"-->Nema horni u prodavnici"<<endl;
        }
        else
        {
            Horna h;
            cout<<"Horne :"<<endl;

            for (int i = 1; i <= listaHorni.velicina(); i++)
            {
                listaHorni.izlistaj(i, h);
                h.ispisHorne();
            }
        }
    }
    void ispisFlauta()
    {
        if(listaFlauti.velicina() == 0)
        {
            cout<<"-->Nema flauta u prodavnici"<<endl;
        }
        else
        {
            Flauta f;
            cout<<"Flaute :"<<endl;

            for (int i = 1; i <= listaFlauti.velicina(); i++)
            {
                listaFlauti.izlistaj(i, f);
                f.ispisFlaute();
            }
        }
    }

    void ispisPoliceDuvackihInstrumenata()
    {
        ispisTubi();
        ispisTrubaa();
        ispisTrombonaa();
        ispisSakdofonaa();
        ispisOboa();
        ispisKlarinetosa();
        ispisHorni();
        ispisFlauta();
    }


};

#endif // POLICADUVACKIHINSTRUMENATA_HPP_INCLUDED
