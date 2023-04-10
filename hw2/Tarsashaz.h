#pragma once
#include <stdio.h>
#include <vector>
#include "Lakas.h"
#include "Garazs.h"
#include "CsaladiApartman.h"
#include "Alberlet.h"
#include <string>

class Tarsashaz{
public:
    
    Tarsashaz(const int maxLakas, const int maxGarazs);
    
    bool lakasHozzaad(const Alberlet alberlet);
    bool lakasHozzaad(const CsaladiApartman csaladi);
    bool garazsHozzaad(const Garazs garazs);
    int osszesLako() const;
    int ingatlanErtek();
    
    virtual operator std::string() const;//egesz listat
    
    //Type 'Tarsashaz' does not provide a subscript operator
    void GetIngatlanok(std::vector<std::shared_ptr<Ingatlan>>& v);
    
    
    
private:
    std::vector<std::shared_ptr<Ingatlan>> ingatlanok;
    int _maxLakas;
    int _maxGarazs;
    int _lakasCount;
    int _garazsCount;
};

