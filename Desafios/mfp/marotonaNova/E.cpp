#include <iostream>
#include <numeric> 
using namespace std; 

int main() {
    int X  = 1;
    int Y, K;

    cin >> Y >> K;

    for (int i = 0; i < K; i++) {
        int passo = gcd(X,Y);
        int qnt = X / passo;
        cout << X << "/" << passo << ":" << qnt << endl; 
        cout << passo << endl;
        if (X > passo) {
            X += (passo * qnt);
            i += qnt;
            continue;
        }

        X += gcd(X, Y);
        cout << X << endl;
    }

    cout << X << endl;
    return 0;
} 