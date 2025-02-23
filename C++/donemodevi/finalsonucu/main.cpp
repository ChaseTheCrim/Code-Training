#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "filem.h"

void ogrenciMenu(DersKayitSistemi& sistem, int ogrenciNo);

bool isValidSelection(const std::string& input) {
    return input.length() == 1 && std::isdigit(input[0]);
}

void menu() {
    DersKayitSistemi sistem;
    sistem.ogrenciDosyadanOku();
    sistem.dersDosyadanOku();
    int secim;
    std::string input;
    bool cikis = true;

    while (cikis) {
        std::cout << "1. Yeni Ogrenci Ekle" << std::endl;
        std::cout << "2. Yeni Ders Ekle" << std::endl;
        std::cout << "3. Ogrenci Listele" << std::endl;
        std::cout << "4. Ders Listele" << std::endl;
        std::cout << "5. Ogrenci Sec" << std::endl;
        std::cout << "6. Ders Sec" << std::endl;
        std::cout << "7. Cikis" << std::endl;
        std::cout << "Seciminiz: ";
        std::cin >> input;

        if (isValidSelection(input)) {
            secim = std::stoi(input);
            switch (secim) {
                case 1:
                    system("CLS");
                    yeniOgrenciEkle(sistem);
                    sistem.dosyayaYaz();
                    break;
                case 2:
                    system("CLS");
                    yeniDersEkle(sistem);
                    sistem.dosyayaYaz();
                    break;
                case 3:
                    system("CLS");
                    sistem.ogrenciListele();
                    break;
                case 4:
                    system("CLS");
                    sistem.dersListele();
                    break;
                case 5: {
                        system("CLS");
                        int ogrNo;
                        std::cout << "Ogrenci No: ";
                        std::cin >> ogrNo;
                        sistem.ogrenciSec(ogrNo);
                        ogrenciMenu(sistem, ogrNo);
                    break;
                }
                case 6: {
                    system("CLS");
                    std::string dersKodu;
                    std::cout << "Ders Kodu: ";
                    std::cin >> dersKodu;
                    sistem.dersSec(dersKodu);
                    break;
                }
                case 7:
                    std::cout << "Cikis yapiliyor..." << std::endl;
                    cikis = false;
                    break;
                default:
                    system("CLS");
                    std::cout << "Gecersiz secim!" << std::endl;
                    std::cout << "---------------" << std::endl;
            }
        } else {
            system("CLS");
            std::cout << "Gecersiz secim!" << std::endl;
            std::cout << "---------------" << std::endl;
        }
    }
}

void ogrenciMenu(DersKayitSistemi& sistem, int ogrenciNo) {
    int secim;
    std::string input;
    bool geri = true;

    while (geri) {

        std::cout << "1. Ogrenci Dersleri" << std::endl;
        std::cout << "2. Ogrenci Ders Ekle" << std::endl;
        std::cout << "3. Ogrenci Ders Cikar" << std::endl;
        std::cout << "4. Ogrenci isim guncelle" << std::endl;
        std::cout << "5. Ogrenci no guncelle" << std::endl;
        std::cout << "6. Ogrenci sil" << std::endl;
        std::cout << "7. Ogrenci Not Ekle" << std::endl;
        std::cout << "8. Ogrenci Ortalama Hesaplama" << std::endl;
        std::cout << "9. Geri gel" << std::endl;
        std::cout << "Seciminiz: ";
        std::cin >> input;

        if (isValidSelection(input)) {
            secim = std::stoi(input);
            switch (secim) {
                case 1:
                system("CLS");
                sistem.ogrenciSec(ogrenciNo);
                sistem.ogrenciDersleriGoster(ogrenciNo);
                    break;
                case 2: {
                    system("CLS");
                    std::string dersKodu;
                    std::cout << "Ders Kodu: ";
                    std::cin >> dersKodu;
                    sistem.ogrenciDersEkle(ogrenciNo, dersKodu);
                    break;
                }
                case 3: {
                    system("CLS");
                    std::string dersKodu;
                    std::cout << "Ders Kodu: ";
                    std::cin >> dersKodu;
                    sistem.ogrenciDersCikar(ogrenciNo, dersKodu);
                    break;
                }
                case 4: {
                    system("CLS");
                    int ogrNo;
                    std::string yeniIsim;
                    std::cout << "Ogrenci No: ";
                    std::cin >> ogrNo;
                    std::cout << "Yeni Isim: ";
                    std::cin >> yeniIsim;
                    sistem.ogrenciIsimGuncelle(ogrNo, yeniIsim);
                    break;
                }
                case 5: {
                    system("CLS");
                    int eskiOgrNo, yeniOgrNo;
                    std::cout << "Eski Ogrenci No: ";
                    std::cin >> eskiOgrNo;
                    std::cout << "Yeni Ogrenci No: ";
                    std::cin >> yeniOgrNo;
                    sistem.ogrenciNoGuncelle(eskiOgrNo, yeniOgrNo);
                    break;
                }
                case 6: {
                    system("CLS");
                    int ogrNo;
                    std::cout << "Ogrenci No: ";
                    std::cin >> ogrNo;
                    sistem.ogrenciSil(ogrNo);
                    break;
                }
                case 7:
                    int ogrenciNo;
                    std::cout << "Ogrenci No: ";
                    std::cin >> ogrenciNo;
                    sistem.ogrenciStandartSapmaHesapla(ogrenciNo);
                break;
                case 8:{  // Yeni seçenek
                int ogrenciNo;
                std::cout << "Ogrenci No: ";
                std::cin >> ogrenciNo;
                auto it = std::find_if(sistem.getOgrenciler().begin(), sistem.getOgrenciler().end(), [&](const Ogrenci& ogrenci) {
                    return ogrenci.getOgrenciNo() == ogrenciNo;
                });

                if (it != sistem.getOgrenciler().end()) {
                    double ortalama = it->hesaplaOrtalama();
                    std::cout << "Ogrencinin not ortalamasi: " << ortalama << std::endl;
                } else {
                    std::cerr << "Ogrenci bulunamadi!" << std::endl;
                }
                break;
                }
                case 9:
                    system("CLS");
                    geri = false;
                    break;
                default:
                    system("CLS");
                    std::cout << "Gecersiz secim!" << std::endl;
                    std::cout << "---------------" << std::endl;
            }
        } else {
            system("CLS");
            std::cout << "Gecersiz secim!" << std::endl;
            std::cout << "---------------" << std::endl;
        }
    }
}

int main() {
    menu();
    return 0;
}
