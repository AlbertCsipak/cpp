#pragma once
#include <stdio.h>
#include "Ingatlan.h"
#include <string>

class Lakas : public Ingatlan{
public:
    Lakas(const int terulet, const int szobaSzam, const int lakok, const int nmAr);
    
    virtual bool bekoltozik(const int lakok) = 0;
    
    virtual operator std::string() const override;
    
    int lakokSzama();
    
    double osszKoltseg() const override;
    
    Lakas& SetLakok(const int Ujlakok);
    
    int terulet() const;
    int szobaSzam() const;
    int lakok() const;
    int nmAr() const;
    
private:
    int _terulet;
    int _szobaSzam;
    int _lakok;
    int _nmAr;
    
};
