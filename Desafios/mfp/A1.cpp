#include <iostream> 
#include <vector>
using namespace std;

int main () { 

    int N, M;
    cin >> N >> M;
    vector<int> resposta(M + 1, 0); // Use M+1 to handle boundary conditions

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        resposta[0]++; // Increment the start of the range
        if (a < M) {
            resposta[a]--; // Decrement the element after the range
        }
    }

    // Compute the prefix sum to finalize the values
    for (int i = 1; i < M; i++) {
        resposta[i] += resposta[i - 1];
    }

    // Output the result
    for (int i = 0; i < M; i++) {
        cout << resposta[i] << " ";
    }
    cout << endl;

    return 0;
}