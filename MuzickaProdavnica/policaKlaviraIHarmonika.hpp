#ifndef POLICAKLAVIRAIHARMONIKA_HPP_INCLUDED
#define POLICAKLAVIRAIHARMONIKA_HPP_INCLUDED

class PolicaOstalihInstrumenata
{
private:
    List<Klavir> listaKlavira;
    List<Harmonika> listaHarmonika;
public:
    void setListuKlavira(List<Klavir> klav)
    {
        listaKlavira = klav;
    }
    void setListuHarmonika(List<Harmonika> har)
    {
        listaHarmonika = har;
    }

    List<Klavir> getlistaKlavira()const{return listaKlavira;}
    List<Harmonika> getListaHarmonika()const{return listaHarmonika;}

    void ispisKlaviraa()
    {
        if(listaKlavira.size() == 0)
        {
            cout<<"-->Nema klavira u prodavnici"<<endl;
        }
        else
        {
            Klavir k;
            cout<<"Klaviri :"<<endl;

            for (int i = 1; i <= listaKlavira.size(); i++)
            {
                listaKlavira.read(i,k);
                k.ispisKlavira();
            }
        }
    }
    void ispisHarmonika()
    {
        if(listaHarmonika.size() == 0)
        {
            cout<<"-->Nema harmonika u prodavnici"<<endl;
        }
        else
        {
            Harmonika h;
            cout<<"Harmonike :"<<endl;

            for (int i = 1; i <= listaHarmonika.size(); i++)
            {
                listaHarmonika.read(i,h);
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

#endif // POLICAKLAVIRAIHARMONIKA_HPP_INCLUDED
