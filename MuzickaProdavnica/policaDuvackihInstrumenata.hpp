#ifndef POLICADUVACKIHINSTRUMENATA_HPP_INCLUDED
#define POLICADUVACKIHINSTRUMENATA_HPP_INCLUDED

class PolicaDuvackih
{
private:
    List<Tuba> listaTubi;
    List<Truba> listaTrubi;
    List<Trombon> listaTrombona;
    List<Saksofon> listaSaksofona;
    List<Oboa> listaOboa;
    List<Klarinet> listaKlarineta;
    List<Horna> listaHorni;
    List<Flauta> listaFlauti;
public:
    void setListaTubi(List<Tuba> tb)
    {
        listaTubi = tb;
    }
    void setListaTruba(List<Truba> trub)
    {
        listaTrubi = trub;
    }
    void setListaTrombona(List<Trombon> trom)
    {
        listaTrombona = trom;
    }
    void setListaSaksofona(List<Saksofon> saks)
    {
        listaSaksofona = saks;
    }
    void setListaOboa(Lista<Oboa> ob)
    {
        listaOboa = ob;
    }
    void setListaKlarineta(List<Klarinet> klr)
    {
        listaKlarineta = klr;
    }
    void setListaHorni(List<Horna> horn)
    {
        listaHorni = horn;
    }
    void setListaFlauta(List<Flauta> fla)
    {
        listaFlauti = fla;
    }

    List<Tuba> getlistaTubi()const{return listaTubi;}
    List<Truba> getlistaTrubi()const{return listaTrubi;}
    List<Trombon> getlistaTrombona()const{return listaTrombona;}
    List<Saksofon> getlistaSaksofona()const{return listaSaksofona;}
    List<Oboa> getlistaOboa()const{return listaOboa;}
    List<Klarinet> getlistaKlarineta()const{return listaKlarineta;}
    List<Horna> getlistaHorni()const{return listaHorni;}
    List<Flauta> getlistaFlauti()const{return listaFlauti;}

    PolicaDuvackih& operator+=(Tuba& tub)
    {
        listaTubi.add(listaTubi.size()+1, tub);
        return *this;
    }
    PolicaDuvackih& operator+=(Truba& trub)
    {
        listaTrubi.add(listaTrubi.size()+1, trub);
        return *this;
    }
    PolicaDuvackih& operator+=(Trombon& trom)
    {
        listaTrombona.add(listaTrombona.size()+1, trom);
        return *this;
    }
    PolicaDuvackih& operator+=(Saksofon& sak)
    {
        listaSaksofona.add(listaSaksofona.size()+1, sak);
        return *this;
    }
    PolicaDuvackih& operator+=(Oboa& obo)
    {
        listaOboa.add(listaOboa.size()+1, obo);
        return *this;
    }
    PolicaDuvackih& operator+=(Klarinet& klar)
    {
        listaKlarineta.add(listaKlarineta.size()+1, klar);
        return *this;
    }
    PolicaDuvackih& operator+=(Horna& hor)
    {
        listaHorni.add(listaHorni.size()+1, hor);
        return *this;
    }
    PolicaDuvackih& operator+=(Flauta& flat)
    {
        listaFlauti.add(listaFlauti.size()+1, flat);
        return *this;
    }

    void ispisTubi()
    {
        if(listaTubi.size() == 0)
        {
            cout<<"-->Nema tubi u prodavnici"<<endl;
        }
        else
        {
            Tuba t;
            cout<<"Tube :"<<endl;

            for (int i = 1; i <= listaTubi.size(); i++)
            {
                listaTubi.read(i, t);
                t.ispisTube();
            }
        }
    }
    void ispisTrubaa()
    {
        if(listaTrubi.size() == 0)
        {
            cout<<"-->Nema trubi u prodavnici"<<endl;
        }
        else
        {
            Truba r;
            cout<<"Trube :"<<endl;

            for (int i = 1; i <= listaTrubi.size(); i++)
            {
                listaTrubi.read(i, r);
                r.ispisTruba();
            }
        }
    }
    void ispisTrombonaa()
    {
        if(listaTrombona.size() == 0)
        {
            cout<<"-->Nema trombona u prodavnici"<<endl;
        }
        else
        {
            Trombon rb;
            cout<<"Tromboni :"<<endl;

            for (int i = 1; i <= listaTrombona.size(); i++)
            {
                listaTrombona.read(i, rb);
                rb.ispisTrombona();
            }
        }
    }
    void ispisSakdofonaa()
    {
        if(listaSaksofona.size() == 0)
        {
            cout<<"-->Nema saksofona u prodavnici"<<endl;
        }
        else
        {
            Saksofon s;
            cout<<"Saksofoni :"<<endl;

            for (int i = 1; i <= listaSaksofona.size(); i++)
            {
                listaSaksofona.read(i, s);
                s.ispisSaksofona();
            }
        }
    }
    void ispisOboa()
    {
        if(listaOboa.size() == 0)
        {
            cout<<"-->Nema oboa u prodavnici"<<endl;
        }
        else
        {
            Oboa o;
            cout<<"Oboe :"<<endl;

            for (int i = 1; i <= listaOboa.size(); i++)
            {
                listaOboa.read(i, o);
                o.ispisOboe();
            }
        }
    }
    void ispisKlarinetosa()
    {
        if(listaKlarineta.size() == 0)
        {
            cout<<"-->Nema klarineta u prodavnici"<<endl;
        }
        else
        {
            Klarinet kk;
            cout<<"Klarineti :"<<endl;

            for (int i = 1; i <= listaKlarineta.size(); i++)
            {
                listaKlarineta.read(i, kk);
                kk.ispisKlarineta();
            }
        }
    }
    void ispisHorni()
    {
        if(listaHorni.size() == 0)
        {
            cout<<"-->Nema horni u prodavnici"<<endl;
        }
        else
        {
            Horna h;
            cout<<"Horne :"<<endl;

            for (int i = 1; i <= listaHorni.size(); i++)
            {
                listaHorni.read(i, h);
                h.ispisHorne();
            }
        }
    }
    void ispisFlauta()
    {
        if(listaFlauti.size() == 0)
        {
            cout<<"-->Nema flauta u prodavnici"<<endl;
        }
        else
        {
            Flauta f;
            cout<<"Flaute :"<<endl;

            for (int i = 1; i <= listaFlauti.size(); i++)
            {
                listaFlauti.read(i, f);
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
