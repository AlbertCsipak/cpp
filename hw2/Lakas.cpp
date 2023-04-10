#include "Lakas.h"
#include <sstream>

Lakas::Lakas(const int terulet, const int szobaSzam, const int lakok, const int nmAr)
    : _terulet(terulet),
    _szobaSzam(szobaSzam),
    _lakok(lakok),
    _nmAr(nmAr)
{
}

int Lakas::szobaSzam() const{
    return _szobaSzam;
}
int Lakas::terulet() const{
    return _terulet;
}
int Lakas::lakok() const{
    return _lakok;
}
int Lakas::nmAr() const{
    return _nmAr;
}

double Lakas::osszKoltseg() const{
    return _nmAr*_terulet;
}

Lakas& Lakas::SetLakok(const int Ujlakok){
    _lakok = Ujlakok;
    return *this;
}

Lakas::operator std::string() const{
    std::ostringstream oss;
    oss << "Terulet : " << _terulet << std::endl;
    oss << "Szobak szama: " << _szobaSzam << std::endl;
    oss << "Lakok szama: " << _lakok << std::endl;
    oss << "Negyzetmeter ara: " << _nmAr << std::endl;
    return oss.str();//os stream-ből sima string létrehozása
}
