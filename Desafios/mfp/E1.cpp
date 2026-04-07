#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> matriz(N, vector<int>(M));
    
    // Lê a matriz atual (após ação da Py)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matriz[i][j];
        }
    }
    
    // Direções: cima, baixo, esquerda, direita
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    bool changed = true;
    
    // Enquanto houver conflitos, resolve incrementando valores
    while (changed) {
        changed = false;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                
                // Verifica se tem conflito com algum adjacente
                bool hasConflict = false;
                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    
                    // Se está dentro dos limites e tem o mesmo valor
                    if (ni >= 0 && ni < N && nj >= 0 && nj < M) {
                        if (matriz[i][j] == matriz[ni][nj]) {
                            hasConflict = true;
                            break;
                        }
                    }
                }
                
                // Se tem conflito, incrementa este valor
                if (hasConflict) {
                    matriz[i][j]++;
                    changed = true;
                }
            }
        }
    }
    
    // Imprime a matriz resultante
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << matriz[i][j];
            if (j < M - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}