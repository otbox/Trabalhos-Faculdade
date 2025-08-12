#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 5;
vector<bool> visited(MAXN);
vector<vector<int>> matriz(MAXN); 

void pesquisar () {

    
}

int main( ){ 
    int N, M;
    cin >> N >> M;


    for(int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
        {
            int a;
            cin >> a;
            matriz[i].push_back(a);
        }
    }

}

//Verificar se algum numero se repete,
// Selecionar algum deles
// Verificar se os adjacentes sofreram alteração
// Correção dos adjacentes,
// Verificar os adjacentes se existe algum parecido
// Corrigir adjacentes até a regra ser suprida