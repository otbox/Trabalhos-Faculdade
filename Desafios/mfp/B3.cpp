#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
vector<bool> visited(MAXN);

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int components = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }

    if (M == N - 1 && components == 1) {
        cout << "BOM" << endl;
    } else {
        int destruir = M - (N - components); // ciclos = arestas extras
        int construir = components - 1;      // ligações faltando entre componentes
        cout << "RUIM " << destruir << " " << construir << endl;
    }

    return 0;
}
