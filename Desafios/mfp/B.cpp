#include <iostream>
#include <vector>
#include <iomanip>
using namespace std; 

void printMatrix (vector<vector<int>> &m) {
    for (int i = 0; i < m.size(); i++){
        for (int j = 0; j < m[0].size(); j++){
            cout << setw(3) << m[i][j] << " ";
        }
        cout << endl;
    }
} 

vector<int> verificação;

int main() {
    int NumPontos, NumRuas;

    cin >> NumPontos >> NumRuas;

    vector<vector<int>> camihos(NumRuas, vector<int>(NumPontos));

    for (int i = 0; i < NumRuas; i++){
        int a = 0, b = 0;
        cin >> a >> b;
        camihos[a - 1][b - 1] = 1; 
    } 

    
    printMatrix(camihos);


    return 0; 
}