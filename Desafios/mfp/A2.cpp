#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio();
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> num(M);
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        if (a > 0) {
            int limite = min(a, M);
            for (int j = 0; j < limite; j++) {
                num[j]++;
            }
        }
    }
    for (int a : num){
        cout << a << " ";
    }
    cout << endl;


    return 0;
}