#include <iostream>
using namespace std;

int main () {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++){
        int a,b,c;
        cin >> a >> b >> c;
        if (a == b){
            cout << c << endl; 
            continue;
        }
        if (a == c) {
            cout << b << endl;
            continue;
        }
        cout << a << endl;
    }
    return 0;
}