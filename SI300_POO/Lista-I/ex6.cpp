#include <iostream>
using namespace std;

class Tabuada1 {
private:
  int atr;

public:
  Tabuada1(int atr) { this->atr = atr; }
  int getAtr() { return atr; }
  void setAtr(int atr) { this->atr = atr; }
  void soma() {
    for (int x = 1; x <= 10; x++)
      cout << atr << " + " << x << " = " << atr + x << endl;
  }
  void subtracao() {
    for (int x = 1; x <= 10; x++)
      cout << atr << " - " << x << " = " << atr - x << endl;
  }
  void multiplicacao() {
    for (int x = 1; x <= 10; x++)
      cout << atr << " * " << x << " = " << atr * x << endl;
  }
  void divisao() {
    if (atr == 0) {
      cout << "Erro divisão com zero" << endl;
    } else {
      for (int x = 1; x <= 10; x++)
        cout << atr << " / " << x << " = "
             << ((atr / x) > 0 ? to_string(atr / x) : "Erro número não inteiro")
             << endl;
    }
  };
};

int main() {
  Tabuada1 *teste = new Tabuada1(0);
  // teste->setAtr(2);
  teste->soma();
  teste->subtracao();
  teste->multiplicacao();
  teste->divisao();

  delete teste;
  return 0;
}
