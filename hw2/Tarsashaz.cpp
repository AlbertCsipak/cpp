#include "Tarsashaz.h"
#include "Alberlet.h"
#include "CsaladiApartman.h"
#include <sstream>

Tarsashaz::Tarsashaz(const int maxLakas, const int maxGarazs)
    : _maxLakas(maxLakas),
    _maxGarazs(maxLakas),
    _lakasCount(0),
    _garazsCount(0)
{
}

void Tarsashaz::GetIngatlanok(std::vector<std::shared_ptr<Ingatlan>>& v){
    v = ingatlanok;
}

bool Tarsashaz::lakasHozzaad(const Alberlet alberlet){
    if (_lakasCount < _maxLakas) {
        ++_lakasCount;
        ingatlanok.push_back(std::make_unique<Alberlet>(alberlet));
        return true;
    }
    return false;
}

bool Tarsashaz::lakasHozzaad(const CsaladiApartman csaladi){
    if (_lakasCount < _maxGarazs) {
        ++_lakasCount;
        ingatlanok.push_back(std::make_unique<CsaladiApartman>(csaladi));
        return true;
    }
    return false;
}

bool Tarsashaz::garazsHozzaad(const Garazs garazs){
    if (_garazsCount < 10){
        ++_garazsCount;
        ingatlanok.push_back(std::make_unique<Garazs>(garazs));
        return true;
    }
    return false;
}


int Tarsashaz::osszesLako()const{
    int osszesLako = 0;
    for(auto& x : ingatlanok){
        if (std::dynamic_pointer_cast<Lakas>(x) != nullptr) {
            osszesLako += std::dynamic_pointer_cast<Lakas>(x)->lakok();
        }
    }
    return osszesLako;
}

int Tarsashaz::ingatlanErtek(){
    int osszErtek = 0;
    for(auto& x : ingatlanok){
        if (std::dynamic_pointer_cast<Lakas>(x) != nullptr) {
            if (std::dynamic_pointer_cast<Lakas>(x) -> lakok() >= 1) {
                osszErtek += std::dynamic_pointer_cast<Lakas>(x)->osszKoltseg();
            }
        }
        else if (std::dynamic_pointer_cast<Garazs>(x) != nullptr) {
            if (std::dynamic_pointer_cast<Garazs>(x) -> lefoglaltE()) {
                osszErtek += std::dynamic_pointer_cast<Garazs>(x)->osszKoltseg();
                
            }
        }
    }
    return osszErtek;
}
 
Tarsashaz::operator std::string() const{
    std::ostringstream oss;
    for(auto& x : ingatlanok){
        oss << std::string(*x) << std::endl;
    }
    return oss.str();//os stream-ből sima string létrehozása
}
