#include <cstdint>
#include <iomanip>
#include <iostream> 
#include <vector>
using namespace std;

void printMatrix (vector<vector<int>> &m) {
    for (int i = 0; i < m.size(); i++){
        for (int j = 0; j < m[0].size(); j++){
            cout << setw(3) << m[i][j] << " ";
        }
        cout << endl;
    }
} 

// int procurarMenorTempo() {

// }


vector<vector<int>> analisarRio(vector<vector<int>> &m, int a, int b) {
    vector<vector<int>> caminhosTempos(m.size(), vector<int>(2, 0));
    vector<int> caminhosMenorTempos;
    int MenorTempo = INT16_MAX;
    cout << "Cidade " << a << endl;
    for (int  i = 0; i < m.size(); i++){
        if (m[a][i] > -1) {
            if (m[a][i] <= MenorTempo){
                MenorTempo = m[a][i];
                cout << "MMMM :" << MenorTempo << endl;
                m[a][i] = -1;
                m[i][a] = -1;
                caminhosTempos[i][0] = i;
                caminhosTempos[i][1] = MenorTempo;
                caminhosMenorTempos.push_back(i);
                
            }
            cout << "d: " << i <<" t: " << m[a][i] << endl;
        }else{
            continue;
        }
    }
    printMatrix(caminhosTempos);
    printMatrix(m);
    return caminhosTempos;

    // return (analisarRio(m, caminhosMenorTempos.back(), b, ));
}

int andarPeloRio (vector<vector<int>> &m, int a, int nFestas) {
    vector<vector<int>> copia = m;
    vector<int> CidadesVisitadas;
    int tempo = 0;
    int Visitada = 0;
    int ProximaCidade = 0;
    while (CidadesVisitadas.size() < nFestas){
        CidadesVisitadas.push_back(Visitada);
        vector<vector<int>> analisada = analisarRio(copia, Visitada, a);
        for (vector<int> aN : analisada){
            // cout << "teste:" << aN[0];
            bool flag = true;
            for (int vI : CidadesVisitadas){
                if (ProximaCidade == vI){
                    cout << "Repetida " << vI;
                    flag = false;
                    break;
                }
            }
            if (flag) {
                break;
            }
            ProximaCidade = aN[0];
            if (aN[1] > tempo)
                tempo = aN[1];
        }
        cout << "proxima cidade: " <<ProximaCidade << endl;
        // for (int j = 0; j < b; j++){
            // cout << m[i][j] << " ";
            // }
            Visitada = ProximaCidade;
        cout << endl;
    }
    return tempo;
}

int main () {
    int nCidades,nCaminhos,D;
    cin >> nCidades >> nCaminhos >> D;

    vector<vector<int>> camihos(nCidades, vector<int>(nCidades, -1)); 
    // vector<vector<int>> horas(M, vector<int>(N)); 

    for (int i = 0; i < nCaminhos; i++){
        int a, b, c = -2;
        cin >> a >> b >> c;
        camihos[a - 1][b - 1] = c;
        camihos[b - 1][a - 1] = c;
    }
    printMatrix(camihos);    
    cout << andarPeloRio(camihos, nCidades, D) << endl;

}