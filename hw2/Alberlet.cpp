#include "Alberlet.h"
#include <sstream>

Alberlet::Alberlet(const int terulet,const int szobaSzam,const int nmAr)
    : Lakas(terulet, szobaSzam, 0, nmAr),
    _honapSzam(0)
{
}


double Alberlet::mennyibeKerul(const int honapDb) const{
    if (lakok() < 1) {
        return 1;
    }
    else{
        return Lakas::osszKoltseg() / lakok();
    }
}
 
bool Alberlet::lefoglaltE() const{
    if (lakok() > 0) {
        return true;
    }
    else{
        return false;
    }
}

bool Alberlet::lefoglal(const int honapDb) {
    if (!lefoglaltE()) {
        _honapSzam = honapDb;
        return true;
    }
    return false;
}

bool Alberlet::bekoltozik(const int lakok){
    
    if (szobaSzam() * 8 >= lakok && Lakas::terulet() / 2 >= lakok) {
        Lakas::SetLakok(lakok);
        return true;
    }
    return false;
}

Alberlet::operator std::string() const{
    std::ostringstream oss;
    oss << "Ennyi honapra van lefoglalva : " << _honapSzam << std::endl;
    oss << Lakas::operator std::string() << std::endl;
    return oss.str();//os stream-ből sima string létrehozása
}
 
 
