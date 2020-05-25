#ifndef POLICAOPREME_HPP_INCLUDED
#define POLICAOPREME_HPP_INCLUDED

class PolicaOpreme
{
private:
    List<OpremaZaInstrumente> listaOpremeZaInstrumente;
    List<Mikrofon> listaMikrofona;
    List<Kontroler> listaKontrolera;
    List<DJOprema> listaDjOpreme;
    List<Mikser> listaMiksera;
public:
void setListuOpremeIn(List<OpremaZaInstrumente> inst)
    {
        listaOpremeZaInstrumente = inst;
    }
    void setListuMikrofona(List<Mikrofon> mikr)
    {
        listaMikrofona = mikr;
    }
    void setListuKontrolera(List<Kontroler> kon)
    {
        listaKontrolera = kon;
    }
    void setListuDJOpreme(List<DJOprema> dj)
    {
        listaDjOpreme = dj;
    }
    void setListuMiksera(List<Mikser> miks)
    {
        listaMiksera = miks;
    }

    List<OpremaZaInstrumente> getlistaOpremeIns()const{return listaVioloncela;}
    List<Mikrofon> getlistaMikrofona()const{return listaVioloncela;}
    List<Kontroler> getlistaKontrolera()const{return listaVioloncela;}
    List<DJOprema> getlistaDJOpreme()const{return listaVioloncela;}
    List<Mikser> getlistaMiksera()const{return listaVioloncela;}

    PolicaOpreme& operator+=(Mikrofon& m)
    {
        listaMikrofona.add(listaMikrofona.size()+1, m);
        return *this;
    }
    PolicaOpreme& operator+=(OpremaZaInstrumente& opr)
    {
        listaOpremeZaInstrumente.add(listaOpremeZaInstrumente.size()+1, opr);
        return *this;
    }
    PolicaOpreme& operator+=(Kontroler& k)
    {
        listaKontrolera.add(listaKontrolera.size()+1, k);
        return *this;
    }
    PolicaOpreme& operator+=(DJOprema& dj)
    {
        listaDjOpreme.add(listaDjOpreme.size()+1, dj);
        return *this;
    }
    PolicaOpreme& operator+=(Mikser& mik)
    {
        listaMiksera.add(listaMiksera.size()+1, mik);
        return *this;
    }

    void ispisOpremeIn()
    {
        if(listaOpremeZaInstrumente.size() == 0)
        {
            cout<<"-->Nema opreme za instrumente u prodavnici"<<endl;
        }
        else
        {
            OpremaZaInstrumente in;
            cout<<"Oprema za instrumente :"<<endl;

            for (int i = 1; i <= listaOpremeZaInstrumente.size(); i++)
            {
                listaOpremeZaInstrumente.read(i, in);
                ///in.ispis(); dodaj kad dodas ispis u opremu
            }
        }
    }
    void ispisMikrofonaa()
    {
        if(listaMikrofona.size() == 0)
        {
            cout<<"-->Nema mikrofona u prodavnici"<<endl;
        }
        else
        {
            Mikrofon mikr;
            cout<<"Mikrofoni :"<<endl;

            for (int i = 1; i <= listaMikrofona.size(); i++)
            {
                listaMikrofona.read(i, mikr);
                ///mikr.ispisVioloncela();sejm
            }
        }
    }
    void ispisKontrolerova()
    {
        if(listaKontrolera.size() == 0)
        {
            cout<<"-->Nema kontrolera u prodavnici"<<endl;
        }
        else
        {
            Kontroler ko;
            cout<<"Kontroleri :"<<endl;

            for (int i = 1; i <= listaKontrolera.size(); i++)
            {
                listaKontrolera.read(i, ko);
                ///ko.ispis();sejm
            }
        }
    }
    void ispisDjOpreme()
    {
        if(listaDjOpreme.size() == 0)
        {
            cout<<"-->Nema DJ opreme u prodavnici"<<endl;
        }
        else
        {
            DJOprema dj;
            cout<<"DJ oprema :"<<endl;

            for (int i = 1; i <= listaDjOpreme.size(); i++)
            {
                listaDjOpreme.read(i, dj);
                dj.ispis();
            }
        }
    }
    void ispisMikserova()
    {
        if(listaMiksera.size() == 0)
        {
            cout<<"-->Nema miksera u prodavnici"<<endl;
        }
        else
        {
            Mikser miks;
            cout<<"Mikseri :"<<endl;

            for (int i = 1; i <= listaMiksera.size(); i++)
            {
                listaMiksera.read(i, miks);
                ///miks.ispis();
            }
        }
    }

};

#endif // POLICAOPREME_HPP_INCLUDED
