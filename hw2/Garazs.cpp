#include "Garazs.h"
#include <sstream>

Garazs::Garazs(const int terulet,const int nmAr,const bool futottE)
    : _terulet(terulet),
    _nmAr(nmAr),
    _futottE(futottE),
    _honapSzam(0),
    _auto(0)
{
}

double Garazs::mennyibeKerul(const int honapDb) const{
    if (_futottE) {
        return osszKoltseg() * 1.5;
    }
    else{
        return osszKoltseg();
    }
}

bool Garazs::lefoglaltE() const{
    if (_honapSzam > 0 || _auto) {
        return true;
    }
    else{
        return false;
    }
}


bool Garazs::lefoglal(const int honapDb) {
    if (!lefoglaltE()) {
        _honapSzam = honapDb;
        return true;
    }
    return false;
}

void Garazs::autoKiBeAll(){
    if (_auto) {
        _auto = false;
    }
    else{
        _auto = true;
    }
}

double Garazs::osszKoltseg() const{
    return _nmAr*_terulet;
}

int Garazs::terulet() const{
    return _terulet;
}
int Garazs::nmAr() const{
    return _nmAr;
}
bool Garazs::futottE() const{
    return _futottE;
}
int Garazs::honapSzam() const{
    return _honapSzam;
}
bool Garazs::Auto() const{
    return _auto;
}//auto vedett

Garazs::operator std::string() const{
    std::ostringstream oss;
    oss << "Terulet : " << _terulet << std::endl;
    oss << "Negyzetmeter ara: " << _nmAr << std::endl;
    oss << "Futott-e : " << _futottE << std::endl;
    oss << "Ennyi honapra van lefoglalva: " << _honapSzam << std::endl;
    oss << "Van a garazsban auto : " << std::boolalpha << _auto << std::endl;
    return oss.str();//os stream-ből sima string létrehozása
}
