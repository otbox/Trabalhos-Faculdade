#include <iostream>
#include <string>
#include <vector>
#include <cmath> 
using namespace std;

long long greaterNumber (long long n) {
    // pegar o maior numero divisivel por dois;
    long long teste = 2;
    while (true) {
        long long t = teste  * 2; 
        if (t  > n ){
            return teste;
        }
        teste = t;
    } 
    
    return teste;
}

long long greaterPalimNumber (long long n) {
    long long maior = 0;
    long long teste = greaterNumber(n);
    
    if (teste + 1 == n) {
        return teste + 1;
    }
    teste++;

    int s = 1;
    for (int i = sqrt(teste); i > 0; i--){
        long long J = teste/pow(2,s) + 1;
        if (teste + J < n) {
            teste += J;
        }
        s++;  
    }
    return teste;
}

string toBinary(long long n) {
    if (n == 0) return "0";
    
    string bin = "";
    while (n > 0) {
        bin = char('0' + (n % 2)) + bin;
        n /= 2;
    }
    return bin;
}

bool ehPalim(const string& s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long n;
    cin >> n;
    
    if (ehPalim(toBinary(n))){
        cout << n;
        return 0;
    }
    
    // if (ehPalim(toBinary(greaterPalimNumber(n)))) {
    //     cout << greaterPalimNumber(n);
    // };
    
    cout << greaterPalimNumber(n);
  
    
    
    // // for (long long i = n; i >= 1; i--) {
    // //     string aux = toBinary(i);
    // //     if (ehPalim(aux)) {
    // //         cout << i << '\n';
    // //         return 0;
    // //     }
    // }



    return 0;
}


// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     long long m;
//     cin >> m;

//     long long total_bits = m * 1000000LL * 8;

//     int qubits = ceil(log2(total_bits));

//     cout << qubits << endl;

//     return 0;
// }


// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int c, g;
//     cin >> c >> g;
    
//     if (c==1) {
//         cout << "vivo e morto" << endl;
//         return 0;
//     } else if(c==0 && g==1) {
//         cout << "vivo" << endl;
//         return 0;
//     } else if (g==0) {
//         cout << "morto" << endl;
//     }

//     return 0;
// }

