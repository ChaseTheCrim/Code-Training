#ifndef FILEM_H
#define FILEM_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>

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
    std::vector<std::string> alinanDersler;
    std::vector<int> notlar;

public:
    Ogrenci(const std::string& ad, int no) : ogrenciAdi(ad), ogrenciNo(no) {}

    std::string getOgrenciAdi() const { return ogrenciAdi; }
    int getOgrenciNo() const { return ogrenciNo; }
    const std::vector<std::string>& getAlinanDersler() const { return alinanDersler; }

    void setOgrenciAdi(const std::string& ad) { ogrenciAdi = ad; }
    void setOgrenciNo(int no) { ogrenciNo = no; }

    void notEkle(int notDegeri) { notlar.push_back(notDegeri); }
    const std::vector<int>& getNotlar() const { return notlar; }
    
    void dersEkle(const std::string& dersKodu) {
        alinanDersler.push_back(dersKodu);
    }

    void dersCikar(const std::string& dersKodu) {
        auto it = std::find(alinanDersler.begin(), alinanDersler.end(), dersKodu);
        if (it != alinanDersler.end()) {
            alinanDersler.erase(it);
        }
    }
    void dersleriGoster() const {
    if (alinanDersler.empty()) {
        std::cout << "Ogrenci bu donem ders almamis." << std::endl;
    } else {
        std::cout << "Aldigi Dersler:" << std::endl;
        for (const auto& ders : alinanDersler) {
            std::cout << ders << std::endl;
        }
    }
}
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

    void alinanDersleriDosyayaYaz(int ogrenciNo) {
    std::ofstream dosya("kayitlar.txt", std::ios::app);

    if (dosya.is_open()) {
        auto it = std::find_if(ogrenciler.begin(), ogrenciler.end(), [&](const Ogrenci& ogrenci) {
            return ogrenci.getOgrenciNo() == ogrenciNo;
        });

        if (it != ogrenciler.end()) {
            dosya << "Ogrenci: " << it->getOgrenciAdi() << "," << it->getOgrenciNo() << std::endl;
            dosya << "Aldigi Dersler:" << std::endl;
            for (const auto& ders : it->getAlinanDersler()) {
                dosya << ders << std::endl;
            }
            dosya << "###" << std::endl;
            std::cout << "Ogrencinin alinan dersler basariyla dosyaya yazildi." << std::endl;
        } else {
            std::cerr << "Ogrenci bulunamadi!" << std::endl;
        }
        dosya.close();
    } else {
        std::cerr << "Dosya acilirken hata olustu!" << std::endl;
    }
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
        std::cout << "---------------" << std::endl;
    }

    void dersListele() {
        std::cout << "### Ders Listesi ###" << std::endl;
        for (const auto& ders : dersler) {
            std::cout << "Ders Adi: " << ders.getDersAdi() << ", Ders Kodu: " << ders.getDersKodu() << ", Ders Kredi: " << ders.getDersKredi() << std::endl;
        }
        std::cout << "---------------" << std::endl;
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

    void ogrenciSil(int ogrenciNo) {
        auto it = std::find_if(ogrenciler.begin(), ogrenciler.end(), [&](const Ogrenci& ogrenci) {
            return ogrenci.getOgrenciNo() == ogrenciNo;
        });

        if (it != ogrenciler.end()) {
            ogrenciler.erase(it);
            std::cout << "Ogrenci basariyla silindi." << std::endl;
            dosyayaYaz();
        } else {
            std::cerr << "Ogrenci bulunamadi!" << std::endl;
        }
    }

    void ogrenciIsimGuncelle(int ogrenciNo, const std::string& yeniIsim) {
        auto it = std::find_if(ogrenciler.begin(), ogrenciler.end(), [&](const Ogrenci& ogrenci) {
            return ogrenci.getOgrenciNo() == ogrenciNo;
        });

        if (it != ogrenciler.end()) {
            it->setOgrenciAdi(yeniIsim);
            std::cout << "Ogrenci ismi basariyla guncellendi." << std::endl;
            dosyayaYaz();
        } else {
            std::cerr << "Ogrenci bulunamadi!" << std::endl;
        }
    }

    void ogrenciNoGuncelle(int eskiOgrenciNo, int yeniOgrenciNo) {
        auto it = std::find_if(ogrenciler.begin(), ogrenciler.end(), [&](const Ogrenci& ogrenci) {
            return ogrenci.getOgrenciNo() == eskiOgrenciNo;
        });

        if (it != ogrenciler.end()) {
            it->setOgrenciNo(yeniOgrenciNo);
            std::cout << "Ogrenci numarasi basariyla guncellendi." << std::endl;
            dosyayaYaz();
        } else {
            std::cerr << "Ogrenci bulunamadi!" << std::endl;
        }
    }
    void ogrenciDersEkle(int ogrenciNo, const std::string& dersKodu) {
        auto it = std::find_if(ogrenciler.begin(), ogrenciler.end(), [&](const Ogrenci& ogrenci) {
            return ogrenci.getOgrenciNo() == ogrenciNo;
        });

        if (it != ogrenciler.end()) {
            it->dersEkle(dersKodu);
            system("CLS");
            std::cout << "Ogrenciye ders basariyla eklendi." << std::endl;
            dosyayaYaz();
        } else {
            std::cerr << "Ogrenci bulunamadi!" << std::endl;
        }
    }

    void ogrenciDersCikar(int ogrenciNo, const std::string& dersKodu) {
        auto it = std::find_if(ogrenciler.begin(), ogrenciler.end(), [&](const Ogrenci& ogrenci) {
            return ogrenci.getOgrenciNo() == ogrenciNo;
        });

        if (it != ogrenciler.end()) {
            it->dersCikar(dersKodu);
            std::cout << "Ogrencinin dersi basariyla cikarildi." << std::endl;
            dosyayaYaz();
        } else {
            std::cerr << "Ogrenci bulunamadi!" << std::endl;
        }
    }
    void ogrenciDersleriGoster(int ogrenciNo) const {
        auto it = std::find_if(ogrenciler.begin(), ogrenciler.end(), [&](const Ogrenci& ogrenci) {
            return ogrenci.getOgrenciNo() == ogrenciNo;
        });

        if (it != ogrenciler.end()) {
        it->dersleriGoster();
        } else {
            std::cerr << "Ogrenci bulunamadi!" << std::endl;
        }
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
    std::cout << "Ders Kredisi: ";
    std::cin >> kredi;

    sistem.dersEkle(Ders(ad, kod, kredi));
}
#endif
