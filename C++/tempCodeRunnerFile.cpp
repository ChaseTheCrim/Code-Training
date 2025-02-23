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

    tabak guzeltabak(4,"mavi","cicekli","porselen","dekarasyon");

    std::cout << "tabak renginiz: " << guzeltabak.renk << std::endl;
    std::cout << "tabak deseniniz: " << guzeltabak.desen << std::endl;

    std::cout << "tabak malzemesi: " << guzeltabak.getMalzeme() << std::endl;
    std::cout << "tabak amaci: " << guzeltabak.getAmac() << std::endl;


return 0;
}