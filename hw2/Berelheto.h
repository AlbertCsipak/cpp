#pragma once
#include <stdio.h>

class Berelheto{
    virtual double mennyibeKerul(const int honapDb) const = 0;
    virtual bool lefoglaltE() const = 0;
    virtual bool lefoglal(const int honapDb) = 0;
};
