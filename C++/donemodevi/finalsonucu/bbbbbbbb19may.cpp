#ifndef FILEMANIPULATE_H
#define FILEMANIPULATE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>  // Standart sapma hesaplama için gerekli

class Ders {
private:
    std::string dersAdi;
    std::string dersKodu;
    int dersKredi;

public:
    Ders(const std::string& ad, const std::string& kod, int kredi)
        : dersAdi(ad), dersKodu(kod), dersKredi(kredi) {}

    std::string getDersAdi() const { return dersAdi; }
    std::string getDersKodu() const { return dersKodu; }
    int getDersKredi() const { return dersKredi; }

    void setDersAdi(const std::string& ad) { dersAdi = ad; }
    void setDersKodu(const std::string& kod) { dersKodu = kod; }
    void setDersKredi(int kredi) { dersKredi = kredi; }
};

class Ogrenci {
private:
    std::string ogrenciAdi;
    int ogrenciNo;
    std::vector<int> notlar;  // Öğrencinin notları

public:
    Ogrenci(const std::string& ad, int no) : ogrenciAdi(ad), ogrenciNo(no) {}

    std::string getOgrenciAdi() const { return ogrenciAdi; }
    int getOgrenciNo() const { return ogrenciNo; }

    void setOgrenciAdi(const std::string& ad) { ogrenciAdi = ad; }
    void setOgrenciNo(int no) { ogrenciNo = no; }

    void notEkle(int notDegeri) { notlar.push_back(notDegeri); }
    const std::vector<int>& getNotlar() const { return notlar; }

    // Ortalama hesaplama fonksiyonu
    double hesaplaOrtalama() const {
        if (notlar.empty()) return 0.0;

        double toplam = 0.0;
        for (int notDegeri : notlar) {
            toplam += notDegeri;
        }
        return toplam / notlar.size();
    }

    // Standart sapma hesaplama fonksiyonu
    double hesaplaStandartSapma() const {
        double toplam = 0.0;
        double ortalama, standartSapma = 0.0;

        if (notlar.empty()) return 0.0;  // Notlar boşsa standart sapma 0 olarak kabul edilir

        for (int notDegeri : notlar) {
            toplam += notDegeri;
        }

        ortalama = toplam / notlar.size();

        for (int notDegeri : notlar) {
            standartSapma += pow(notDegeri - ortalama, 2);
        }

        return sqrt(standartSapma / notlar.size());
    }

    // Öğrencinin geçip geçmediğini belirleyen fonksiyon
    bool gectiMi() const {
        double standartSapma = hesaplaStandartSapma();
        return standartSapma <= 30.0;  // Örneğin, standart sapma 30 veya daha küçükse öğrenci geçmiştir.
    }
};

class DersKayitSistemi {
private:
    std::vector<Ogrenci> ogrenciler;
    std::vector<Ders> dersler;

public:
    void ogrenciEkle(const Ogrenci& ogrenci) {
        ogrenciler.push_back(ogrenci);
    }

    void dersEkle(const Ders& ders) {
        dersler.push_back(ders);
    }

    void dosyayaYaz() {
        std::ofstream dosya("kayitlar.txt");
        if (dosya.is_open()) {
            for (const auto& ogrenci : ogrenciler) {
                dosya << "Ogrenci: " << ogrenci.getOgrenciAdi() << "," << ogrenci.getOgrenciNo() << std::endl;
            }
            dosya << "###" << std::endl;
            for (const auto& ders : dersler) {
                dosya << "Ders: " << ders.getDersAdi() << "," << ders.getDersKodu() << "," << ders.getDersKredi() << std::endl;
            }
            dosya.close();
            std::cout << "Kayitlar basariyla dosyaya yazildi." << std::endl;
        } else {
            std::cerr << "Dosya acilirken hata olustu!" << std::endl;
        }
    }

    void ogrenciListele() {
        std::cout << "### Ogrenci Listesi ###" << std::endl;
        for (const auto& ogrenci : ogrenciler) {
            std::cout << "Ogrenci Adi: " << ogrenci.getOgrenciAdi() << ", Ogrenci No: " << ogrenci.getOgrenciNo() << std::endl;
        }
    }

    void dersListele() {
        std::cout << "### Ders Listesi ###" << std::endl;
        for (const auto& ders : dersler) {
            std::cout << "Ders Adi: " << ders.getDersAdi() << ", Ders Kodu: " << ders.getDersKodu() << ", Ders Kredi: " << ders.getDersKredi() << std::endl;
        }
    }

    void ogrenciDosyadanOku() {
        std::ifstream dosya("kayitlar.txt");
        if (dosya.is_open()) {
            std::string satir;
            ogrenciler.clear();
            while (std::getline(dosya, satir) && satir != "###") {
                if (satir.find("Ogrenci: ") == 0) {
                    std::string ad = satir.substr(9, satir.find(",") - 9);
                    int no = std::stoi(satir.substr(satir.find(",") + 1));
                    ogrenciEkle(Ogrenci(ad, no));
                }
            }
            std::cout << "Dosyadan ogrenciler basariyla okundu." << std::endl;
        } else {
            std::cerr << "Dosya acilirken hata olustu!" << std::endl;
        }
    }

    void dersDosyadanOku() {
        std::ifstream dosya("kayitlar.txt");
        if (dosya.is_open()) {
            std::string satir;
            dersler.clear();
            bool dersBilgileriOkunuyor = false;
            while (std::getline(dosya, satir)) {
                if (satir == "###") {
                    dersBilgileriOkunuyor = true;
                    continue;
                }
                if (dersBilgileriOkunuyor && satir.find("Ders: ") == 0) {
                    std::string ad = satir.substr(6, satir.find(",", 6) - 6);
                    std::string kod = satir.substr(satir.find(",") + 1, satir.find(",", satir.find(",") + 1) - satir.find(",") - 1);
                    int kredi = std::stoi(satir.substr(satir.find_last_of(",") + 1));
                    dersEkle(Ders(ad, kod, kredi));
                }
            }
            std::cout << "Dosyadan dersler basariyla okundu." << std::endl;
        } else {
            std::cerr << "Dosya acilirken hata olustu!" << std::endl;
        }
    }

    void ogrenciSec(int ogrenciNo) {
        auto it = std::find_if(ogrenciler.begin(), ogrenciler.end(), [&](const Ogrenci& ogrenci) {
            return ogrenci.getOgrenciNo() == ogrenciNo;
        });

        if (it != ogrenciler.end()) {
            std::cout << "Ogrenci Bilgileri: " << std::endl;
            std::cout << "Ogrenci Adi: " << it->getOgrenciAdi() << ", Ogrenci No: " << it->getOgrenciNo() << std::endl;
            std::cout << "Notlar: ";
            for (int notDegeri : it->getNotlar()) {
                std::cout << notDegeri << " ";
            }
            std::cout << std::endl;
        } else {
            std::cerr << "Ogrenci bulunamadi!" << std::endl;
        }
    }

    void dersSec(const std::string& dersKodu) {
        auto it = std::find_if(dersler.begin(), dersler.end(), [&](const Ders& ders) {
            return ders.getDersKodu() == dersKodu;
        });

        if (it != dersler.end()) {
            std::cout << "Ders Bilgileri: " << std::endl;
            std::cout << "Ders Adi: " << it->getDersAdi() << ", Ders Kodu: " << it->getDersKodu() << ", Ders Kredi: " << it->getDersKredi() << std::endl;
        } else {
            std::cerr << "Ders bulunamadi!" << std::endl;
        }
    }

    void ogrenciyeNotEkle(int ogrenciNo, int notDegeri) {
        auto it = std::find_if(ogrenciler.begin(), ogrenciler.end(), [&](const Ogrenci& ogrenci) {
            return ogrenci.getOgrenciNo() == ogrenciNo;
        });

        if (it != ogrenciler.end()) {
            it->notEkle(notDegeri);
            std::cout << "Not basariyla eklendi." << std::endl;
        } else {
            std::cerr << "Ogrenci bulunamadi!" << std::endl;
        }
    }

    void ogrenciStandartSapmaHesapla(int ogrenciNo) {
        auto it = std::find_if(ogrenciler.begin(), ogrenciler.end(), [&](const Ogrenci& ogrenci) {
            return ogrenci.getOgrenciNo() == ogrenciNo;
        });

        if (it != ogrenciler.end()) {
            double standartSapma = it->hesaplaStandartSapma();
            std::cout << "Ogrencinin notlarinin standart sapmasi: " << standartSapma << std::endl;
        } else {
            std::cerr << "Ogrenci bulunamadi!" << std::endl;
        }
    }

    const std::vector<Ogrenci>& getOgrenciler() const {
        return ogrenciler;
    }
};

void yeniOgrenciEkle(DersKayitSistemi& sistem) {
    std::string ad;
    int no;
    std::cout << "Ogrenci Adi: ";
    std::cin >> ad;
    std::cout << "Ogrenci No: ";
    std::cin >> no;
    sistem.ogrenciEkle(Ogrenci(ad, no));
}

void yeniDersEkle(DersKayitSistemi& sistem) {
    std::string ad, kod;
    int kredi;
    std::cout << "Ders Adi: ";
    std::cin >> ad;
    std::cout << "Ders Kodu: ";
    std::cin >> kod;
    std::cout << "Ders Kredi: ";
    std::cin >> kredi;
    sistem.dersEkle(Ders(ad, kod, kredi));
}

#endif  // FILEMANIPULATE_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>

void menu() {
    DersKayitSistemi sistem;
    sistem.ogrenciDosyadanOku();
    sistem.dersDosyadanOku();
    int secim;
    bool cikis = true;  // Sonsuz döngüden kaçınmak için bool kullanıyoruz

    while (cikis) {
        std::cout << "1. Yeni Ogrenci Ekle" << std::endl;
        std::cout << "2. Yeni Ders Ekle" << std::endl;
        std::cout << "3. Ogrenci Listele" << std::endl;
        std::cout << "4. Ders Listele" << std::endl;
        std::cout << "5. Ogrenci Sec" << std::endl;
        std::cout << "6. Ders Sec" << std::endl;
        std::cout << "7. Ogrenciye Not Ekle" << std::endl;
        std::cout << "8. Ogrenci Standart Sapma Hesapla" << std::endl;
        std::cout << "9. Ogrenci Ortalama Hesapla" << std::endl;  // Yeni seçenek
        std::cout << "10. Cikis" << std::endl;
        std::cout << "Seciminiz: ";
        std::cin >> secim;

        switch (secim) {
            case 1:
                yeniOgrenciEkle(sistem);
                sistem.dosyayaYaz();
                break;
            case 2:
                yeniDersEkle(sistem);
                sistem.dosyayaYaz();
                break;
            case 3:
                sistem.ogrenciListele();
                break;
            case 4:
                sistem.dersListele();
                break;
            case 5: {
                int ogrNo;
                std::cout << "Ogrenci No: ";
                std::cin >> ogrNo;
                sistem.ogrenciSec(ogrNo);
                break;
            }
            case 6: {
                std::string dersKodu;
                std::cout << "Ders Kodu: ";
                std::cin >> dersKodu;
                sistem.dersSec(dersKodu);
                break;
            }
            case 7: {
                int ogrenciNo, notDegeri;
                std::cout << "Ogrenci No: ";
                std::cin >> ogrenciNo;
                std::cout << "Not Degeri: ";
                std::cin >> notDegeri;
                sistem.ogrenciyeNotEkle(ogrenciNo, notDegeri);
                sistem.dosyayaYaz();
                break;
            }
            case 8: {
                int ogrenciNo;
                std::cout << "Ogrenci No: ";
                std::cin >> ogrenciNo;
                sistem.ogrenciStandartSapmaHesapla(ogrenciNo);
                break;
            }
            case 9: {  // Yeni seçenek
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
            case 10:
                std::cout << "Cikis yapiliyor..." << std::endl;
                cikis = false;
                break;
            default:
                std::cout << "Gecersiz secim!" << std::endl;
                std::cout << "---------------" << std::endl;
        }
    }
}


int main() {
    menu();
    return 0;
}
