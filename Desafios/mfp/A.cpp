#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Dado um numero de N e um limite M 
// veja que aquele número N é igual ou menor que M  
// Veja se aquele número é maior que M, caso não veja se é menor que a metade dele
// Caso sim coloque +1 em todos os M Posições anteriores de vetor
// Exemplo dado M = 4 e um número 3 então <1,1,1,0>
// Executar até que M = N  

void ContagemBinaria (vector<int> &output,int M, int N) {
    // cout << N << " " << M << " " << endl;
    if (N == M){
        for (int i = 0; i < N; i++){
            output[i]++;
        }
        // cout << "Achei: " << N << "=" << M << endl;
        return;
    }
    //Se media menor que numero media cresce
    if (M < N) {
        return ContagemBinaria(output, (M + N)/2 + 1,N);
    }

    return ContagemBinaria(output, M/2 , N);
}

int main() {
    int QntN, Media; 
    cin >> QntN >> Media; 

    vector<int> Nums(QntN);
    vector<int> Saida(Media);

    for (int x = 0; x < QntN; x++) {
        cin >> Nums[x];
        ContagemBinaria(Saida, Media, Nums[x]);
    }


    sort(Nums.begin(), Nums.end());
    for (size_t i = 0; i < Media; i++)
    {
        // cout << Nums[i];
        cout << Saida[i] << " ";
    }
    cout << endl;

}