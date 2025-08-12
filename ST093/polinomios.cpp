#include <iostream>
#include <vector>
using namespace std;

// O(n²)

vector<int> teste; 

int potencia (int v, int n) {
    int res = v;
    if (teste.size() == 0) {
        if (n == 0) {
            return 1;
        }
        for (int i = 0; i < n - 1; i++){
            res *= v; 
        }
    } else {

    }

    teste.push_back(res);
    return res;
}

int polinomios(int x, a)

int main() { 
    int Npolinomio = 0;
    int x = 0;
    int res = 0;
    cout << "Qual o tamanho do polinomio?" << endl;
    cin >> Npolinomio;
    cout << "Qual valor do x?" << endl;
    cin >> x;
    res = x;
    for (int i = 2; i <= Npolinomio; i++){
        res += potencia(x, i);
        cout << res << " ";
    } 
    cout << res << endl;
    return 0;
}