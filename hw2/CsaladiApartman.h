#pragma once
#include <stdio.h>
#include "Lakas.h"
#include <string>

class CsaladiApartman : public Lakas{
public:
    CsaladiApartman(const int terulet,const int szobaSzam,const int nmAr);
    
    bool gyerekSzuletik();
    
    bool bekoltozik(const int lakok) override;
    
    virtual operator std::string() const override;
private:
    int _gyerekekSzama;
};
