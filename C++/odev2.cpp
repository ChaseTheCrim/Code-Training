#include <iostream>
#include <string>

class tabak{
    public:

     tabak(int c,std::string r,std::string d,std::string m,std::string a)
    :cap(c),renk(r),desen(d),malzeme(m),amac(a){}

    int cap;
    std::string renk;
    std::string desen;

    std::string getMalzeme() {return malzeme;}
    std::string getAmac() {return amac;}

    private:
    std::string malzeme;
    std::string amac;
};

int main(){

//ilk tabak

    tabak guzeltabak(4,"mavi","cicekli","porselen","dekorasyon");

    std::cout << "tabak capiniz: " << guzeltabak.cap << std::endl;
    std::cout << "tabak renginiz: " << guzeltabak.renk << std::endl;
    std::cout << "tabak deseniniz: " << guzeltabak.desen << std::endl;

    std::cout << "tabak malzemesi: " << guzeltabak.getMalzeme() << std::endl;
    std::cout << "tabak amaci: " << guzeltabak.getAmac() << std::endl;

/*ikinci tabak*/ std::cout << std::endl;

    tabak cicitabak(4,"fil disi","cicekli","porselen","sanat eseri");

    std::cout << "tabak capiniz: " << guzeltabak.cap << std::endl;
    std::cout << "tabak renginiz: " << guzeltabak.renk << std::endl;
    std::cout << "tabak deseniniz: " << guzeltabak.desen << std::endl;

    std::cout << "tabak malzemesi: " << guzeltabak.getMalzeme() << std::endl;
    std::cout << "tabak amaci: " << guzeltabak.getAmac() << std::endl;

/*ucuncu tabak*/ std::cout << std::endl;

    tabak iyitabak(12,"beyaz","bombeli","plastik","yemek aleti");

    std::cout << "tabak capiniz: " << iyitabak.cap << std::endl;
    std::cout << "tabak renginiz: " << iyitabak.renk << std::endl;
    std::cout << "tabak deseniniz: " << iyitabak.desen << std::endl;

    std::cout << "tabak malzemesi: " << iyitabak.getMalzeme() << std::endl;
    std::cout << "tabak amaci: " << iyitabak.getAmac() << std::endl;

return 0;
}