#include <iostream>
#include <numeric> 
using namespace std; 

int main() {
    int X  = 1;
    int Y, K;

    cin >> Y >> K;

    for (int i = 0; i < K; i++) {
        int passo = gcd(X,Y);
        // int qnt = X / passo;
        cout << "X: " << X << "Y: " << Y << "passo:" << passo << ":" << endl;
        // << qnt << endl; 
        // cout << passo << endl;
        // if (X > passo) {
        //     X += (passo * qnt);
        //     i += qnt;
        //     continue;
        // }

        X += gcd(X, Y);
        cout << X << endl;
    }

    cout << X << gcd(15,140) << endl;
    return 0;
} 