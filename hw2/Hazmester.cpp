#include "Hazmester.h"
#include "Alberlet.h"

std::string Hazmester::Split(const std::string& sor,const int idx) {
    std::string jelenlegi = "";
    std::vector<std::string> szavak;
    
    for(auto& x : sor){
        if (x == ' ')
        {
            szavak.push_back(jelenlegi);
            jelenlegi = "";
        }
        else
        {
            jelenlegi += x;
        }
    }
    szavak.push_back(jelenlegi);
    return szavak[idx];
}

void Hazmester::Karbantart(std::string utvonal) {
    std::ifstream inputFile(utvonal);
    Tarsashaz ingatlanok(10,5);
    if (inputFile.is_open())
    {
        while (!inputFile.eof())
        {
            std::string sor;
            getline(inputFile, sor);
            if (Split(sor, 0) == "Alberlet")
            {
                ingatlanok.lakasHozzaad(Alberlet(stoi(Split(sor, 1)), stoi(Split(sor, 2)),stoi(Split(sor, 3))));
            }
            else if (Split(sor, 0) == "CsaladiApartman") {
                ingatlanok.lakasHozzaad(CsaladiApartman(stoi(Split(sor, 1)), stoi(Split(sor, 2)),stoi(Split(sor, 3))));
            }
            else if (Split(sor, 0) == "Garazs") {
                ingatlanok.garazsHozzaad(Garazs(stoi(Split(sor, 1)), stoi(Split(sor, 2)), (Split(sor, 3) == "futott" ? true : false)));
            }
        }
    }
    inputFile.close();
    
    //sima ingatlanok elerese soran problema: Type 'Tarsashaz' does not provide a subscript operator
    //ezert referencia atvetele
    std::vector<std::shared_ptr<Ingatlan>> v;
    ingatlanok.GetIngatlanok(v);
    
    //modositasok a vectoron
    std::dynamic_pointer_cast<Garazs>(v[2])->lefoglal(5);
    std::dynamic_pointer_cast<Garazs>(v[2])->autoKiBeAll();
    
    std::dynamic_pointer_cast<Alberlet>(v[0])->lefoglal(10);
    std::dynamic_pointer_cast<Alberlet>(v[0])->bekoltozik(200);//nem fog mukodni, tul magas ...
    std::dynamic_pointer_cast<Alberlet>(v[0])->bekoltozik(1);
    
    std::dynamic_pointer_cast<CsaladiApartman>(v[1])->bekoltozik(3);
    std::dynamic_pointer_cast<CsaladiApartman>(v[1])->gyerekSzuletik();
    
    //egesz kiiratasa
    std::cout << std::string(ingatlanok) << std::endl;
    
    //ertekek
    std::cout << "Osszes lako: " << ingatlanok.osszesLako() << std::endl;
    std::cout << "Osszes ingatlan ertek: " << ingatlanok.ingatlanErtek() << std::endl;
    
}
