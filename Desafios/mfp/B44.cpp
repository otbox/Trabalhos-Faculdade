#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> graph;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    for (int v : graph[u]){
        if (!visited[v]) dfs(v);
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie();

    cin >> N >> M;
    graph.assign(N + 1, {}); //Inicializando com um tamanho 
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    visited.assign(N + 1, false);
    int C =0;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i]) {
            dfs(i);
            C++;
        }
    }
    

    long long D = M - N + C;
    if (D < 0) D = 0;
    long long A = C - 1;
    
    if (D==0 && A==0) {cout << "BOM";}else{
        cout << "RUIM " << D << " " << C;
    }
    cout << endl;
}