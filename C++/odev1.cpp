#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct tabak {
    float cap;
    string desen;
    string renk;
};

int main() {

    vector<tabak> kalitelitabaklar;

    for (int i = 0; i < 3; ++i) {
        tabak yeniTabak;

        cout << "tabagin capini girin: ";
        cin >> yeniTabak.cap;

        cout << "tabagin desenini girin: ";
        cin >> yeniTabak.desen;

        cout << "tabagin rengini girin: ";
        cin >> yeniTabak.renk;

        kalitelitabaklar.push_back(yeniTabak);
    }
//internette vektör boyutunu size_t kapsamak konusunda iş görür diye okudum çünkü bir nevi
//dinamik veri türü gibi bir işe yarıyormuş.
    for (size_t i = 0; i < kalitelitabaklar.size(); ++i) {
        cout << endl << i + 1 << ". tabak ozellikleri: " << endl;
        cout << "cap: " << kalitelitabaklar[i].cap << endl;
        cout << "desen: " << kalitelitabaklar[i].desen << endl;
        cout << "renk: " << kalitelitabaklar[i].renk << endl;
    }

    return 0;
}

//kodu ilk başta yazarken hatalı giriş engelini en son eklerim diyodum ama yazdığım kodun
//iskeletinin %70'i internetten stackoverflow gibi mekanlardan bakarak yaptığım için kodun
//bozulması korkusuyla ekleyemedim.
//Ömer Faruk Ünal 230212056