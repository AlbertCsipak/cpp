#pragma once
#include <stdio.h>
#include "Berelheto.h"
#include "Lakas.h"
#include <string>

class Alberlet : public Lakas ,public Berelheto{
public:
    Alberlet(const int terulet,const int szobaSzam,const int nmAr);
    
    double mennyibeKerul(const int honapDb) const override;
    bool lefoglaltE() const override;
    bool lefoglal(const int honapDb) override;
    
    bool bekoltozik(const int lakok) override;
    
    virtual operator std::string() const override;
    
private:
    int _honapSzam;
};
