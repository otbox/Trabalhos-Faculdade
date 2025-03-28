#include <iostream>
using namespace std;
#include <cmath>

class Potencia {
    private:
        double resultado;  
    public: 
        
    double calcula(int base, int expoente) {
        cout << "Método calcula(int, int) chamado.\n";
        resultado = pow(base, expoente);
        return resultado;
    }

    // 2. Base inteira e expoente real
    double calcula(int base, double expoente) {
        cout << "Método calcula(int, double) chamado.\n";
        resultado = pow(base, expoente);
        return resultado;
    }

    // 3. Base e expoente reais
    double calcula(double base, double expoente) {
        cout << "Método calcula(double, double) chamado.\n";
        resultado = pow(base, expoente);
        return resultado;
    }

}; 


int main () { 
    Potencia *teste = new Potencia();
    cout << teste->calcula(2,2.5) << endl;
}