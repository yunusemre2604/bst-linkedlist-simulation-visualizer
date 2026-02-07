//IkiliAramaAgaci.hpp baslangic

#ifndef IkiliAramaAgaci_HPP
#define IkiliAramaAgaci_HPP
#include "Karakter.hpp"
#include <iostream>
using namespace std;

class IkiliAramaAgaci
{
public:
    Karakter *kok;
    IkiliAramaAgaci *sonraki;
    
   
    void ekle(char veri);
    int toplamDeger();
    int yukseklik();
    void yazdirAgac(Karakter* root);
    void karakterat(int adet,char karakter);
    void yazdirAgacNokta(Karakter* root, int level, int height);
    void yazdirAgacNokta2(Karakter* root, int level, int height);
    void agacSil();
    void aynalama();
    
    ~IkiliAramaAgaci();
    
    
private:
    void aynalama(Karakter* &aktif);
    int dugumSayisi;
    void agacSil(Karakter *kok);
    void ekle(char veri, Karakter* aktifDugum);
    int toplamDeger(Karakter* aktif );
    int yukseklik(Karakter *aktif);
    void yazdirAgacLevel(Karakter* root, int level, int height);
   
    
};

#endif


//IkiliAramaAgaci.hpp bitis


