#pragma once
#include <stdio.h>
#include "Berelheto.h"
#include "Ingatlan.h"
#include <string>


class Garazs  : public Ingatlan ,public Berelheto{
public:
    Garazs(const int terulet,const int nmAr,const bool futottE);
    double osszKoltseg() const override;
    
    double mennyibeKerul(const int honapDb) const override;
    bool lefoglaltE() const override;
    bool lefoglal(const int honapDb) override;
    
    void autoKiBeAll();
    
    virtual operator std::string() const override;
    
    int terulet() const;
    int nmAr() const;
    bool futottE() const;
    int honapSzam() const;
    bool Auto() const;//auto vedett
private:
    int _terulet;
    int _nmAr;
    bool _futottE;
    int _honapSzam;
    bool _auto;
};
