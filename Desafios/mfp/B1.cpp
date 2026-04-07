#include <iostream>
#include <vector>
using namespace std; 

// int atualizarValor()


int main () {

    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> vertx(N + 1);
    vector<int> verify(N + 1);

    int sobraRuas = 0;
    int faltaRuas = 0;
    int raiz = 1;
    for (int i = 0; i < M; i++) {
        int a,b;
        cin >> b >> a;
        vertx[a].push_back(b);
    }

    // RuasConstruidas precisa ser = a quantidade de vertices caso nao falha
    int ruasContruidas = 0;
    int c1 = 0;
    for (int i = 0;  i < vertx.size(); i++) {
        while(true) {
            if (vertx[i][0] == i) {
                cout << raiz;
            }  

        }
    }

    for (vector<int> i : vertx) {
        if (i.size() > 1)  
            sobraRuas++;
    }



    for (int i = 0; i < N; i++){
        if (verify[i] == 0) {
            faltaRuas++;
        }
    }

    for (int i : verify){
        cout << i << " ";
    }
    cout << endl;
    int a1 = 0;
    for (vector<int> i : vertx){
        for (int j : i) {
            cout << "node "<< a1 << ": " << j;
        }
        cout << endl; 
        a1++;
    }
    cout << endl;
    if (sobraRuas != 0 || faltaRuas != 0){
        cout << "RUIM " << sobraRuas << " " << faltaRuas << endl; 
    }else {
        cout << "BOM"; 
    }


    
    return 0;
}