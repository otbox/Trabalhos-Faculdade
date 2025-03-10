#include <iostream>
using namespace std;

enum OPERACAO {
    SOMA,
    SUBTRACAO,
    MULTIPLICACAO,
    DIVISAO,
};

class Tabuada2 {
    private:
        int n;
        OPERACAO op;
    public:
        Tabuada2 (int n = 1, OPERACAO op = SOMA) {
        this->n = n;
        this->op = op;
    } 
        int getN () {return n;};
        void setN (int n) {this->n = n;}
        void setOp (OPERACAO op) {this->op = op;}
        OPERACAO getOp () {return op;}
        void Servico();
};

void Tabuada2::Servico () {
    if (op == DIVISAO && n == 0) {
        cout << "Erro impossível dividir por zero" << endl;
        return;
    }
    for (int x = 1; x <= 10; x++)
        switch (op) {
            case SOMA:
                cout << n << " + " << x << " = " << n + x << endl;
                break;
            case SUBTRACAO:
                cout << n << " - " << x << " = " << n - x << endl;
                break;
            case MULTIPLICACAO:
                cout << n << " * " << x << " = " << n * x << endl;
                break;
            case DIVISAO:
                cout << n << " / " << x << " = " << n / x << endl; 
                break;
        }
}

int main () {
    Tabuada2 * tab = new Tabuada2(2, SUBTRACAO);
    tab->Servico();
    tab->setOp(MULTIPLICACAO);
    tab->setN(5);
    cout << tab->getN() << tab->getOp() << endl;
    tab->Servico();

    delete tab;

}

