#ifndef TRAJANJE_HPP_INCLUDED
#define TRAJANJE_HPP_INCLUDED

class Trajanje
{
private:
    int sekunde, minuti, sati;
public:
    Trajanje()
    {
        sekunde = 0;
        minuti = 0;
        sati = 0;
    }

    Trajanje(int s, int m, int h)
    {
        sekunde = s;
        minuti = m;
        sati = h;
    }

    Trajanje(const Trajanje &t)
    {
        sekunde = t.sekunde;
        minuti = t.minuti;
        sati = t.sati;
    }

    int getSekunde()const {return sekunde;}
    int getMinute()const {return minuti;}
    int getSate()const {return sati;}

    void setSekunde(int s) {sekunde = s;}
    void setMinute(int m) {minuti = m;}
    void setSate(int h) {sati = h;}

    void ispisTrajanja()
    {
        cout<<"Sati: "<<getSate()<<endl;
        cout<<"Minuti: "<<getMinute()<<endl;
        cout<<"Sekunde: "<<getSekunde()<<endl;
    }

    void unosTrajanja()
    {
        cout<<"Sati: ";
        cin>>sati;
        cout<<"Minuti: ";
        cin>>minuti;
        cout<<"Sekunde: ";
        cin>>sekunde;
    }
};

#endif // TRAJANJE_HPP_INCLUDED
