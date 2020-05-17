#include <iostream>

#include "proizvod.hpp"
#include "instrument.hpp"
#include "zicaniInstrument.hpp"
#include "udarackiInstrument.hpp"
#include "bubanj.hpp"
#include "cinele.hpp"
#include "daire.hpp"
#include "gitara.hpp"
#include "harfa.hpp"
#include "kastanjete.hpp"
#include "metalofon.hpp"
#include "ukulele.hpp"

using namespace std;

int main()
{
    Proizvod P1;
    P1.ispisProizvoda();
    cout<<endl;
    Instrument I;
    I.ispisInstrumenta();
    cout<<endl;
    ZicaniInstrument Z;
    Z.ispisZicanogInstrumenta();
    cout<<endl;
    UdarackiInstrument U;
    U.ispisUdarackogInstrumenta();
    cout<<endl;
    Bubanj B;
    B.ispisBubnja();
    cout<<endl;
    Cinele C;
    C.ispisCinela();
    cout<<endl;
    Daire D;
    D.ispisDaira();
    cout<<endl;
    Gitara G;
    G.ispisGitare();
    cout<<endl;
    Harfa H;
    H.ispisHarfe();
    cout<<endl;
    Kastanjete K;
    K.ispisKastanjeta();
    cout<<endl;
    Ukulele Uk;
    Uk.ispisUkulelea();
    return 0;
}
