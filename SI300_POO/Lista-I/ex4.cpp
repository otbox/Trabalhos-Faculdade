#include <iostream>
using namespace std;

class Pessoa {
    private: 
        int atr1;
    public:
        Pessoa(int atr1) {this->atr1 = atr1;}
        int getAtr1() {return atr1;}
        void setAtr1(int atr1) {this->atr1 = atr1;}
};

int main () {
    Pessoa jorge(12);
    cout << jorge.getAtr1() << endl;
    jorge.setAtr1(2);
    cout << jorge.getAtr1() << endl;

    return 0;
}
