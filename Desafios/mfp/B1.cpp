#include <iostream>
#include <vector>
using namespace std; 
int main () {

    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> vertx(N);
    vector<int> verify(N);

    int sobraRuas = 0;
    int faltaRuas = 0;

    for (int i = 0; i < M; i++) {
        int a,b;
        cin >> a >> b;
        // verify[b - 1]++;
        // verify[a - 1]++;
        // if (verify[b - 1] > 1){
        //     sobraRuas++;
        // }
        vertx[a - 1].push_back(b - 1);
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
    }


    
    return 0;
}