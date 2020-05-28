#ifndef TONALITET_HPP_INCLUDED
#define TONALITET_HPP_INCLUDED

enum tonalitet {C, Csharp, D, Dsharp, E, F, Fsharp, G, Gsharp, A, Asharp, B};
enum lestvica {mol, dur};

class Tonalitet
{
private:
    tonalitet key;
    lestvica les;
public:
    Tonalitet()
    {
        key = C;
        les = dur;
    }

    Tonalitet(tonalitet T, lestvica L)
    {
        key = T;
        les = L;
    }

    Tonalitet(const Tonalitet &t)
    {
        key = t.key;
        les = t.les;
    }

    string getKey()const
    {
        switch(key)
        {
        case C:
            return "C";
            break;
        case Csharp:
            return "C#";
            break;
        case D:
            return "D";
            break;
        case Dsharp:
            return "D#";
            break;
        case E:
            return "E";
            break;
        case F:
            return "F";
            break;
        case Fsharp:
            return "F#";
            break;
        case G:
            return "G";
            break;
        case Gsharp:
            return "G#";
            break;
        case A:
            return "A";
            break;
        case Asharp:
            return "A#";
            break;
        case B:
            return "B";
            break;
        }
    }

    string getLestvica()const
    {
        switch(les)
        {
        case dur:
            return "dur";
            break;
        case mol:
            return "mol";
            break;
        }
    }

    void setKey()
    {
        int k;
        cout<<"Key[1-C/2-C#/3-D/4-D#/5-E/6-F/7-F#/8-G/9-G#/10-A/11-A#/12-B]: ";
        cin>>k;
        switch(k)
        {
            case 1:
            key = C;
            break;
        case 2:
            key = Csharp;
            break;
        case 3:
            key = D;
            break;
        case 4:
            key = Dsharp;
            break;
        case 5:
            key = E;
            break;
        case 6:
            key = F;
            break;
        case 7:
            key = Fsharp;
            break;
        case 8:
            key = G;
            break;
        case 9:
            key = Gsharp;
            break;
        case 10:
            key = A;
            break;
        case 11:
            key = Asharp;
            break;
        case 12:
            key = B;
            break;
        }
    }

    void setLestvica()
    {
        int l;
        cout<<"Lestvica[1-dur/2-mol]: ";
        cin>>l;
        switch(l)
        {
        case 1:
            les = dur;
            break;
        case 2:
            les = mol;
            break;
        }
    }

    void unosTonaliteta()
    {
        setKey();
        setLestvica();
    }

    void ispisTonaliteta()
    {
        cout<<"Tonalitet: "<<getKey()<<getLestvica()<<endl;
    }

};
#endif
