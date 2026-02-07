
//BagliListe.hpp baslangic
#ifndef BagliListe_HPP
#define BagliListe_HPP
#include "IkiliAramaAgaci.hpp"
#include <iostream>
#include <string>
using namespace std;

class BagliListe
{

private:
    IkiliAramaAgaci *bas;
    void dosyaOku(const string& dosyaAdi);
    
public:
    int dugumSayyisi = 0;
    BagliListe(const string& dosyaAdi);
    ~BagliListe();
    
    
    
    
    void menu();
    
    void yazdirListe(int baslangic, int aralik, int mevcut) const;
    IkiliAramaAgaci* dugumGetir(int sira);
    void mevcutuSil(int silinecekIndex);
    
    
};


#endif

//BagliListe.hpp bitis