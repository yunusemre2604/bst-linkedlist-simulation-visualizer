/**
* @file IkiliAramaAgaci.cpp
* @description Bağlı listenin düğümlerini tutuyor , ikili arama ağacının silme, ekrana çizdirme gibi işlemlerini yapan fonksiyonlar burada.
* @course 1. Öğretim C grubu
* @assignment 2. Ödev
* @date 20.12.2024
* @author Yunus Emre Yıldız - yunus.yildiz25@ogr.sakarya.edu.tr
*/
// IkiliAramaAgaci.cpp baslangic
#include "IkiliAramaAgaci.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

IkiliAramaAgaci::~IkiliAramaAgaci()
{
    agacSil(kok);
    
}
void IkiliAramaAgaci::agacSil(Karakter *kok)
{
    if (kok == nullptr)
        return;

    // Sol ve sağ alt ağaçları sil
    agacSil(kok->sol);
    agacSil(kok->sag);

    // Şu anki düğümü sil
    delete kok;
}
void IkiliAramaAgaci::agacSil() {
    agacSil(kok); // Ağacı kökten başlayarak sil
    kok = nullptr; // Kökü sıfırla
}

void IkiliAramaAgaci::ekle(char veri)
{
    if (kok == nullptr)
    {
        kok = new Karakter(veri);
    }
    else
        ekle(veri, kok);
}
void IkiliAramaAgaci::ekle(char veri, Karakter *aktifDugum)
{

    if (aktifDugum->veri > veri)
    {
        if (aktifDugum->sol)
            ekle(veri, aktifDugum->sol);
        else
            aktifDugum->sol = new Karakter(veri);
    }
    else if (aktifDugum->veri < veri)
    {
        if (aktifDugum->sag)
            ekle(veri, aktifDugum->sag);
        else
            aktifDugum->sag = new Karakter(veri);
    }
    else
        return;
}
int IkiliAramaAgaci::toplamDeger()
{
    return toplamDeger(kok) + kok->veri;
}

int IkiliAramaAgaci::toplamDeger(Karakter *aktif)
{
    if (aktif == nullptr)
        return 0; // Eğer geçerli düğüm yoksa 0 döndür.

    // Geçerli düğümün değeri
    int toplam = 0;

    int mevcutDeger = aktif->veri;
    if (aktif->sol)
    {
        toplam += 2 * aktif->sol->veri;
        toplam += toplamDeger(aktif->sol);
    }
    // Sol ve sağ alt ağaçların toplam değerleri
    if (aktif->sag)
    {
        toplam += aktif->sag->veri;
        toplam += toplamDeger(aktif->sag);
    }

    // Toplam değeri döndür
    return toplam;
}
void IkiliAramaAgaci::karakterat(int adet, char karakter)
{
    for (int i = 0; i < adet; i++)
    {
        cout << karakter;
    }
}
int IkiliAramaAgaci::yukseklik()
{
    return yukseklik(kok);
}
int IkiliAramaAgaci::yukseklik(Karakter *aktif)
{
    if (aktif)
    {
        return 1 + max(yukseklik(aktif->sol), yukseklik(aktif->sag));
    }
    return -1;
}
void IkiliAramaAgaci::yazdirAgacLevel(Karakter *root, int level, int height)
{

    if (level == 1)
    {
        if (root)
        {
            // cout  << root->veri << setw(position);
            cout << root->veri;
            karakterat((pow(2, height + 1)) * 2 - 1, ' ');
        }
        else
        {
            // cout  << " " << setw(position);
            cout << ' ';
            karakterat((pow(2, height + 1)) * 2 - 1, ' ');
        }
    }
    else if (level > 1)
    {

        yazdirAgacLevel(root ? root->sol : nullptr, level - 1, height - 1);

        yazdirAgacLevel(root ? root->sag : nullptr, level - 1, height - 1);
    }
}
void IkiliAramaAgaci::yazdirAgacNokta2(Karakter *root, int level, int height)
{

    if (level == 1)
    {
        if (root)
        {
            if (root->sag || root->sol)
            {
                cout << '.';
                karakterat((pow(2, height + 1)) * 2 - 1, ' ');
            }
            else
            {
                // cout  << " " << setw(position);
                cout << ' ';
                karakterat((pow(2, height + 1)) * 2 - 1, ' ');
            }
            // cout  << root->veri << setw(position);
        }
        else
        {
            cout << ' ';
            karakterat((pow(2, height + 1)) * 2 - 1, ' ');
        }
    }
    else if (level > 1)
    {

        yazdirAgacNokta2(root ? root->sol : nullptr, level - 1, height - 1);

        yazdirAgacNokta2(root ? root->sag : nullptr, level - 1, height - 1);
    }
}
void IkiliAramaAgaci::yazdirAgacNokta(Karakter *root, int level, int height)
{

    if (level == 1)
    {
        if (root)
        {
            if (root->sol)
            {
                karakterat(pow(2, height) + 1, '.');

                if (root->sag)
                {
                    karakterat(pow(2, height), '.');
                    karakterat(pow(2, height + 1) - 1, ' ');
                }
                else
                {
                    karakterat(pow(2, height), ' ');
                    karakterat(pow(2, height + 1) - 1, ' ');
                }
            }
            if (!root->sol)
            {
                karakterat(pow(2, height), ' ');

                if (root->sag)
                {
                    karakterat(pow(2, height) + 1, '.');
                    karakterat(pow(2, height + 1) - 1, ' ');
                }
                else
                {
                    karakterat(pow(2, height) + 1, ' ');
                    karakterat(pow(2, height + 1) - 1, ' ');
                }
            }
        }
        else
        {
            // cout  << " " << setw(position);
            karakterat(pow(2, height + 1) * 2, ' ');
        }
    }
    else if (level > 1)
    {

        yazdirAgacNokta(root ? root->sol : nullptr, level - 1, height - 1);
        yazdirAgacNokta(root ? root->sag : nullptr, level - 1, height - 1);
    }
}
void IkiliAramaAgaci::yazdirAgac(Karakter *root)
{

    int height = yukseklik(root);
    int totalWidth = pow(2, height + 1) - 1;
    for (int i = 1; i <= height + 1; i++)
    {
        int position = totalWidth / 2 + 1;

        karakterat(pow(2, height + 1 - i + 1) + 1, ' ');
        yazdirAgacLevel(root, i, height);
        cout << endl;
        karakterat(pow(2, height + 1 - i + 1) + 1, ' ');
        yazdirAgacNokta2(root, i, height);
        cout << endl;
        karakterat(pow(2, height - i + 1) + 1, ' ');
        yazdirAgacNokta(root, i, height);
        cout << endl;
    }
}
void IkiliAramaAgaci::aynalama()
{
    aynalama(kok); // Ağacın kökünden itibaren aynalamayı başlatır
}

void IkiliAramaAgaci::aynalama(Karakter *&aktif)
{
    if (aktif == nullptr)
        return; // Boş düğüm varsa geri dön

    // Sol ve sağ alt ağaçları aynala
    aynalama(aktif->sol);
    aynalama(aktif->sag);

    // Sol ve sağ düğümleri yer değiştir
    Karakter *temp = aktif->sol;
    aktif->sol = aktif->sag;
    aktif->sag = temp;
}
// IkiliAramaAgaci.cpp bitis
