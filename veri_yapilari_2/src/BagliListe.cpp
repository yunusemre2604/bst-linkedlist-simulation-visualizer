/**
* @file BagliListe.cpp
* @description Bağlı listeyi oluşturma, ekrana yazdırma gibi bağlı liste ile ilgili fonksiyonlar burada
* @course 1. Öğretim C grubu
* @assignment 2. Ödev
* @date 20.12.2024
* @author Yunus Emre Yıldız - yunus.yildiz25@ogr.sakarya.edu.tr
*/



//BagliListe.cpp bitis

#include "BagliListe.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

BagliListe::BagliListe(const string &dosyaAdi) : bas(nullptr){
    dosyaOku(dosyaAdi);
}
BagliListe :: ~BagliListe(){
     IkiliAramaAgaci *temp;
    while (bas)
    {
        temp = bas;
        bas = bas->sonraki;
        delete temp;
    }
}

void BagliListe::dosyaOku(const string &dosyaAdi)
{
    
    ifstream dosya(dosyaAdi);
    string satir;
    IkiliAramaAgaci *sonAgac = nullptr;
    while (getline(dosya, satir)) //dosyadan satır satır okuma yapılır.
    {
        
        istringstream ss(satir);
        char karakter; 
        IkiliAramaAgaci *yeniAgac = new IkiliAramaAgaci(); //her satır için yeni bir ağaç oluşturulur
        while (ss >> karakter)
        {
            
            yeniAgac->ekle(karakter); //satırdaki karakterler okunur ve ağaca eklenir.
                                    //Satırdaki her bir karakter true döndüğü sürece yeni oluşturulan ağaca eklenir.
        }
        if (!bas)   //Eğer ki ilk agac yoksa oluşturulan ağacın adresi bas değişkenine atanır.
        {
            
            bas = yeniAgac;
            bas->sonraki=nullptr;
        }   
        else  //Aksi durumda son ağacın sonraki adresi oluşturulan yeni ağacın adresini gösterecek şekilde ayarlama yapılır.
        {
            sonAgac->sonraki = yeniAgac;
            yeniAgac->sonraki=nullptr;
        }
        sonAgac = yeniAgac; //artık son ağac eklenen yeni agactır.
        dugumSayyisi++;
    }
    
    dosya.close();
}





void BagliListe::yazdirListe(int baslangic, int aralik, int mevcut) const{
    IkiliAramaAgaci *gecici = bas;
    IkiliAramaAgaci *gecici2 = gecici;
    for (int i = 0; i < baslangic && gecici; ++i) {
        gecici = gecici->sonraki;
        gecici2 =gecici;
    }
    for (int i = 0; i < aralik ; ++i) {
        
        cout << setw(15) << "............";
        
    }
    cout <<endl;
    for (int i = 0; i < aralik && gecici; ++i) {
        
        cout << setw(4) << "."<< setw(10)  << (int)gecici%10000 <<".";
        gecici = gecici->sonraki;
    }
    cout <<endl;
     for (int i = 0; i < aralik ; ++i) {
        
        cout << setw(15) << "............";
        
    }
    cout <<endl;
    gecici =gecici2;
    for (int i = 0; i < aralik && gecici; ++i) {
        
        cout <<setw(4) << "."<< setw(10) << gecici->toplamDeger() <<".";
        gecici = gecici->sonraki;
    }
    cout <<endl;
     for (int i = 0; i < aralik ; ++i) {
        
        cout << setw(15) << "............";
        
    }
    cout <<endl;
    gecici =gecici2;
    for (int i = 0; i < aralik && gecici; ++i) {
        
        cout <<setw(4) << "."<< setw(10) << (int)gecici->sonraki%10000 << ".";
        gecici = gecici->sonraki;
    }
    cout <<endl;
     for (int i = 0; i < aralik ; ++i) {
        
        cout << setw(15) << "............";
        
    }
    cout <<endl;
    gecici =gecici2;
    for (int i = 0; i < aralik; ++i) {
        if (i + baslangic == mevcut) {
            cout << setw(15) << "^^^^^^^^^^^^";
            
        }
        else {
            cout << setw(15) <<"            ";
            
            
        }
     
    }
    cout <<endl;
    for (int i = 0; i < aralik; ++i) {
        if (i + baslangic == mevcut) {
            cout << setw(15) << "||||||||||||";
            
        }
        else {
            cout << setw(15) <<"            ";
            
            
        }
     
    }
    cout<<endl;
    gecici =bas;
    for(int i=0; i<mevcut&&gecici;i++)
    {
        gecici=gecici->sonraki;
    }
    if(gecici)
        gecici->yazdirAgac(gecici->kok);
    
}
IkiliAramaAgaci* BagliListe :: dugumGetir(int sira){
    
    IkiliAramaAgaci *gecici = bas ;
    int sayac = 0;
    while(sira>=0&&gecici!=0)
    {
        if(sayac==sira){
            return gecici;
        }
        gecici = gecici->sonraki;
        sayac++;
       
        
    }
    return 0;
}
void BagliListe :: mevcutuSil(int silinecekIndex){
    if(silinecekIndex<0 || silinecekIndex >= dugumSayyisi || !bas) return;
    
    
    
    if(silinecekIndex == 0)
    {
        IkiliAramaAgaci *gecici =bas;
        bas = gecici->sonraki;
        gecici->agacSil();
        delete gecici;
            

    }
    else{
        IkiliAramaAgaci *gecici =bas;
        IkiliAramaAgaci *onceki = nullptr;
        for (int i = 0; i < silinecekIndex; ++i) {
            onceki = gecici;
            gecici = gecici->sonraki;
        }
        onceki->sonraki = gecici->sonraki;
        gecici->agacSil();
        delete gecici;
    }
    dugumSayyisi--;
    

}


void BagliListe :: menu(){
    int mevcutIndex =0;
    const int sayfadakiDugumSayisi =10; 
    char secim;
    do{
        system("CLS");
        int baslangic = (mevcutIndex /sayfadakiDugumSayisi) * sayfadakiDugumSayisi;
        int kalanDugumler = dugumSayyisi - baslangic;

        int gosterilecekDugumSayisi;

        if (kalanDugumler < sayfadakiDugumSayisi) {
            gosterilecekDugumSayisi = kalanDugumler;
        } else {
            gosterilecekDugumSayisi = sayfadakiDugumSayisi;
        }
        
        yazdirListe(baslangic,gosterilecekDugumSayisi,mevcutIndex);
        cout <<"secim : "; cin >>secim;
        if (secim == 'd'|| secim == 'D' ) {
            // Sağ düğüme git
            if (mevcutIndex + 1 < dugumSayyisi) {
                mevcutIndex++;
            }
        } else if (secim == 'a'|| secim == 'A' ) {
            // Sol düğüme git
            if (mevcutIndex - 1 >= 0) {
                mevcutIndex--;
            }
        }else if(secim == 's' || secim == 'S'){
            if(dugumSayyisi>0)
            {
                mevcutuSil(mevcutIndex);

            }
            if (mevcutIndex >= dugumSayyisi && mevcutIndex > 0) {
                mevcutIndex--;
            }

        }else if(secim == 'w' || secim == 'W' ){
            IkiliAramaAgaci* mevcutAgac = dugumGetir(mevcutIndex);
            if (mevcutAgac) {
            mevcutAgac->aynalama();
            
            }
        }
    }while(secim!='x' );
}

//BagliListe.cpp bitis

