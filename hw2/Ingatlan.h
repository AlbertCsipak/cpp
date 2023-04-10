#pragma once
#include <stdio.h>
#include <string>

class Ingatlan{
public:
    virtual double osszKoltseg() const = 0;
    virtual operator std::string() const = 0;//egyszerubb kiiratas vegett
};
