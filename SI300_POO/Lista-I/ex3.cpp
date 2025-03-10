#include <iostream>
using namespace std;

class classe {
    private:
        int atr1;
    public: 
        int getAtr1() {return this->atr1;};
        void setAtr1(int atr1) {this->atr1 = atr1;};
};

int main () {
    classe teste;
    teste.setAtr1(2);
    cout << teste.getAtr1() << endl;

    return 0;
}
