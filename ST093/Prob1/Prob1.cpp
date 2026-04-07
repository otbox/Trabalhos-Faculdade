#include <bits/stdc++.h>
using namespace std;

map<string, vector<string>> pre;
map<string, int> memo;

int semestre(string d)
{
    if (pre[d].empty())
        return 1;
    if (memo.count(d))
        // cout << "Foi contado" << d << memo.count(d) << endl;
        return memo[d];
    int max = 0;
    for (auto &d2 : pre[d])
    {
        int s = semestre(d2);
        if (s > max)
            max = s;
    }
    cout << d << " " << max + 1 << " " << memo.count(d) << endl; 
    return memo[d] = max + 1;
    // return max + 1;
}

int main()
{
    ios::sync_with_stdio();
    cin.tie(0);

    string d, p;
    set<string> disciplinas;
    int N;
    cin >> N;
    clock_t inicio = clock();
    // Adapted for input format: Y:A,E
    // Y is the discipline, A,E are prerequisites (comma separated, possibly empty)
    for (int i = 0; i < N; ++i)
    {
        string line;
        cin >> line;
        size_t pos = line.find(':');
        string disc = line.substr(0, pos);
        disciplinas.insert(disc);
        if (pos != string::npos && pos + 1 < line.size())
        {
            string prereqs = line.substr(pos + 1);
            stringstream ss(prereqs);
            string prereq;
            while (getline(ss, prereq, ','))
            {
                if (!prereq.empty())
                {
                    pre[disc].push_back(prereq);
                    disciplinas.insert(prereq);
                }
            }
        }
    }
    int resposta = 0;
    for (auto &disc : disciplinas)
    {
        resposta = max(resposta, semestre(disc));
    }
    clock_t fim = clock();
    double tempo = double(fim - inicio) / CLOCKS_PER_SEC;
    cout << resposta << " semestres\n";
    cout << "Executado em " << tempo << " segundos\n";
}