#include <iostream> 
#include <vector>
using namespace std;

int main () {
    
    int N, K;
    cin >> N >> K; 
    vector<int> particulas(N);
    
    vector<int> filtros;

    for (int i = 0; i < N; i++)
    {   
        int x;
        cin >> x;
        filtros.push_back(x);
    }

    for (int i = 0; i < N; i++) {
        int particula = filtros[i];
        int pos = i; 
        while (true) {
            if (particula > filtros[pos]){
                break;
            }
            particula += K;
            pos = (pos + 1) % N;
        } 
        particulas[i] = pos + 1;     
    }

    for (int i : particulas) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
} 