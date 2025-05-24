
#include <iostream>
#include <numeric> 
using namespace std; 

int main() {
    int X = 1;
    int Y, K;

    cin >> Y >> K;

    for (int i = 0; i < K;) {
        int passo = gcd(X, Y);

        if (passo == 1) {
            X += (K - i);
            break;
        }

        int qnt = 1; 
        X += (passo * qnt);
        i += qnt;
    }

    cout << X << endl;
    return 0;
}