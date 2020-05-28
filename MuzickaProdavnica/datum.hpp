#ifndef DATUM_HPP_INCLUDED
#define DATUM_HPP_INCLUDED

class Datum
{
protected:
    int dan, mesec, godina;

public:

    Datum(int DAN, int MESEC, int GODINA)
    {
    dan = DAN;
    mesec = MESEC;
    godina = GODINA;
    }

    Datum()
    {
    dan = 20;
    mesec = 1;
    godina = 2004;
    }

    Datum(const Datum &d)
    {
    dan = d.dan;
    mesec = d.mesec;
    godina = d.godina;
    }

    int getDan()const {return dan;}
    int getMesec()const {return mesec;}
    int getGodina()const {return godina;}

    void setDan(int DAN)
    {
    if(DAN<1 || DAN>31)
    cout<<"Dan van opsega! Probajte ponovo."<<endl;
    else
    dan = DAN;
    }
    void setMesec(int MESEC)
    {
    if(MESEC<1 || MESEC>12)
    cout<<"Mesec van opsega! Probajte ponovo."<<endl;
    else
    mesec = MESEC;
    }
    void setGodina(int GODINA)
    {
    if(GODINA<1900|| GODINA>2020)
    cout<<"Godina van opsega! Probajte ponovo."<<endl;
    else
    godina = GODINA;
    }

    void ispisiDatum()
    {
    cout<<"Datum: "<<getDan()<<"-"<<getMesec()<<"-"<<getGodina()<<endl;
    }

    void unesiDatum()
    {
    cout<<"Dan: ";
    cin>>dan;
    fflush(stdin);
    cout<<"Mesec: ";
    cin>>mesec;
    fflush(stdin);
    cout<<"Godina: ";
    cin>>godina;
    fflush(stdin);
    }
};

#endif // DATUM_HPP_INCLUDED
