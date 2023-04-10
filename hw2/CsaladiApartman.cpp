#include "CsaladiApartman.h"
#include <sstream>

CsaladiApartman::CsaladiApartman(const int terulet,const int szobaSzam,const int nmAr)
    : Lakas(terulet, szobaSzam, 0, nmAr),
    _gyerekekSzama(0)
{
}

bool CsaladiApartman::gyerekSzuletik(){
    if (lakok() >= 2) {
        ++_gyerekekSzama;
        int a = lakok();
        SetLakok(++a);
        return true;
    }
    return false;
}

bool CsaladiApartman::bekoltozik(const int lakok){
    double mLakok = lakok - _gyerekekSzama*0.5;
    if (szobaSzam() * 2 >= lakok && Lakas::terulet() / 10 >= mLakok) {
        Lakas::SetLakok(lakok);
        return true;
    }
    return false;
}

CsaladiApartman::operator std::string() const{
    std::ostringstream oss;
    oss << "Gyerekek szama : " << _gyerekekSzama << std::endl;
    oss << Lakas::operator std::string() << std::endl;
    return oss.str();//os stream-ből sima string létrehozása
}
