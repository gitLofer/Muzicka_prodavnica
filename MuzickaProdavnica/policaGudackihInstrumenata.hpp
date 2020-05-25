#ifndef POLICAGUDACKIHINSTRUMENATA_HPP_INCLUDED
#define POLICAGUDACKIHINSTRUMENATA_HPP_INCLUDED

class PolicaGudackih
{
private:
    List<Violoncelo> listaVioloncela;
    List<Volina> listaViolina;
    List<Viola> listaViola;
    List<Kontrabas> listaKontrabasa;
public:
    void setListuVioloncela(List<Violoncelo> vio)
    {
        listaVioloncela = vio;
    }
    void setListuViolina(List<Violina> vil)
    {
        listaViolina = vil;
    }
    void setListuViola(List<Viola> vi)
    {
        listaViola = vi;
    }
    void setListuKontrabasova(List<Kontrabas> komb)
    {
        listaKontrabasa = komb;
    }

    List<Violoncelo> getlistaVioloncela()const{return listaVioloncela;}
    List<Volina> getlistaViolina()const{return listaViolina;}
    List<Viola> getlistaViola()const{return listaViola;}
    List<Kontrabas> getlistaKontrabasa()const{return listaKontrabasa;}

    PolicaGudackih& operator+=(Violoncelo& viol)
    {
        listaVioloncela.add(listaVioloncela.size()+1, viol);
        return *this;
    }
    PolicaGudackih& operator+=(Violina& vi)
    {
        listaViolina.add(listaViolina.size()+1, vi);
        return *this;
    }
    PolicaGudackih& operator+=(Viola& vo)
    {
        listaViola.add(listaViola.size()+1, vo);
        return *this;
    }
    PolicaGudackih& operator+=(Kontrabas& kon)
    {
        listaKontrabasa.add(listaKontrabasa.size()+1, kon);
        return *this;
    }

    void ispisVioloncela()
    {
        if(listaVioloncela.size() == 0)
        {
            cout<<"-->Nema violoncela u prodavnici"<<endl;
        }
        else
        {
            Violoncelo vo;
            cout<<"Violoncela :"<<endl;

            for (int i = 1; i <= listaVioloncela.size(); i++)
            {
                listaVioloncela.read(i, vo);
                vo.ispisVioloncela();
            }
        }
    }
    void ispisViolina()
    {
        if(listaViolina.size() == 0)
        {
            cout<<"-->Nema violina u prodavnici"<<endl;
        }
        else
        {
            Violina vi;
            cout<<"Violine :"<<endl;

            for (int i = 1; i <= listaViolina.size(); i++)
            {
                listaViolina.read(i, vi);
                vi.ispisVioline();
            }
        }
    }
    void ispisViola()
    {
        if(listaViola.size() == 0)
        {
            cout<<"-->Nema viola u prodavnici"<<endl;
        }
        else
        {
            Viola v;
            cout<<"Viole :"<<endl;

            for (int i = 1; i <= listaViola.size(); i++)
            {
                listaViola.read(i, v);
                v.ispisViole();
            }
        }
    }
    void ispisKontrabasova()
    {
        if(listaKontrabasa.size() == 0)
        {
            cout<<"-->Nema kontrabasa u prodavnici"<<endl;
        }
        else
        {
            Kontrabas kb;
            cout<<"Kontrabasi :"<<endl;

            for (int i = 1; i <= listaKontrabasa.size(); i++)
            {
                listaKontrabasa.read(i, kb);
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

#endif // POLICAGUDACKIHINSTRUMENATA_HPP_INCLUDED
