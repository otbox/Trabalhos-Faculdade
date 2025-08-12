#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main () {
    // Taxa de deecoerencia =  qntcolaCNPQ / qubits em isolados
    int N;
    cin >> N;

    vector<char> isolados; 

    int qbisuperIsolados = 0;
    int qbitdepois = 0;
    for (int i = 0; i < N; i++) {
        char t;
        cin >> t;
        if (t == '*'){
            qbisuperIsolados++;
        }
        isolados.push_back(t);
    } 
    for (int i = 0; i < N; i++) {
        char t;
        cin >> t;
        if (isolados[i] != t){
            qbitdepois++;
        }
    } 

    double teste1 = double(qbitdepois) / double(qbisuperIsolados);
    cout << fixed << setprecision(2) << teste1 << endl;


}