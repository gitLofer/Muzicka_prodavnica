#ifndef ZANR_HPP_INCLUDED
#define ZANR_HPP_INCLUDED

enum tipMuzike {vokalna, instrumentalna, vokalnoInstrumentalna};
enum zanrovi {alternative, bluz, rege, pop, rok, hiphop, dzez, dens, klasicna, kantri, metal};

class Zanr
{
protected:
    tipMuzike tip;
    zanrovi vrsta;
public:
    Zanr()
    {
        tip = vokalnoInstrumentalna;
        vrsta = hiphop;
    }

    Zanr(tipMuzike TIP, zanrovi VRSTA)
    {
        tip = TIP;
        vrsta = VRSTA;
    }

    Zanr(const Zanr &z)
    {
        tip = z.tip;
        vrsta = z.vrsta;
    }

    string getTip()const
    {
        switch(tip)
        {
        case vokalna:
            return "Vokalna";
            break;
        case instrumentalna:
            return "Instrumentalna";
            break;
        case vokalnoInstrumentalna:
            return "Vokalno instrumentalna";
            break;
        }
    }
    string getVrsta()const
    {
        switch(vrsta)
        {
        case alternative:
            return "Alternative";
            break;
        case bluz:
            return "Bluz";
            break;
        case dens:
            return "Dens";
            break;
        case dzez:
            return "Dzez";
            break;
        case hiphop:
            return "Hip hop";
            break;
        case kantri:
            return "Kantri";
            break;
        case klasicna:
            return "Klasicna";
            break;
        case metal:
            return "Metal";
            break;
        case pop:
            return "Pop";
            break;
        case rege:
            return "Rege";
            break;
        case rok:
            return "Rok";
            break;
        }
    }

    void setTip()
    {
        int br;
        cout<<"Tip muzike [1-Vokalna/2-Instrumentalna/3-Vokalno instrumentalna]: "<<endl;
        cin>>br;

        switch(br)
        {
        case 1:
            tip = vokalna;
            break;
        case 2:
            tip = instrumentalna;
            break;
        case 3:
            tip = vokalnoInstrumentalna;
            break;
        }
    }

    void setVrsta()
    {
        int br;
        cout<<"Zanr [1-Alternative/2-Bluz/3-Dens/4-Dzez/5-Hiphop/6-Kantri/7-Klasicna/8-Metal/9-Pop/10-Rege/11-Rok]: "<<endl;
        cin>>br;

        switch(br)
        {
        case 1:
            vrsta = alternative;
            break;
        case 2:
            vrsta = bluz;
            break;
        case 3:
            vrsta = dens;
            break;
        case 4:
            vrsta = dzez;
            break;
        case 5:
            vrsta = hiphop;
            break;
        case 6:
            vrsta = kantri;
            break;
        case 7:
            vrsta = klasicna;
            break;
        case 8:
            vrsta = metal;
            break;
        case 9:
            vrsta = pop;
            break;
        case 10:
            vrsta = rege;
            break;
        case 11:
            vrsta = rok;
            break;
        }
    }

    void ispisiZanr()
    {
    cout<<"Tip: "<<getTip()<<endl;
    cout<<"Vrsta: "<<getVrsta()<<endl;
    }

    void unesiZanr()
    {
    setTip();
    setVrsta();
    }
};
#endif
