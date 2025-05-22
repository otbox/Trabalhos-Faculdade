#include <iostream>
#include <vector>
using namespace std;

int main () { 
    
    
    int numPontos, numRuas;
    int faltaRuas = 0, sobraRuas = 0;
    cin >> numPontos >> numRuas;
    vector<vector<int>> numeros(numPontos);
    
    for (int i = 0; i < numRuas; i++){
        int a,b;
        cin >> b >> a;
        numeros[a - 1].push_back(b - 1);
    }   


    for (int i = 0; i < numeros.size(); i++){
        vector<int> visitados(numPontos);

        if (visitados[i] > 0) {
            cout << i << " foi visitado" << endl;
            continue;
        }

        cout << "size " << i << " " << numeros[i].size() << endl;
        visitados[i]++;
        for (int j = 0; j < numeros[i].size(); j++){
            cout << numeros[i][j] << " ";
            int mm = numeros[i][j];
            vector<int> temp(numeros[i].size());
            temp.push_back(i);
            while (true) {
                if (visitados[mm] = 1){
                    break;
                }
                cout << "visitando: " << mm << endl;
                if (numeros[mm].size() == 0){
                    for (int n : temp) {
                        numeros[n][0] = mm;
                    }
                    break;
                }
                temp.push_back(mm);
                mm = numeros[mm][0];
            }
        } 
    
    }   


    cout << "tamanho: "<< numeros.size() << endl; 
    for (int i = 0; i < numeros.size(); i++){
        cout << "size " << i << " " << numeros[i].size() << endl;
        for (int j = 0; j < numeros[i].size(); j++){
            cout << numeros[i][j] << " ";
        } 
        cout << "---" << endl;
    }   

}