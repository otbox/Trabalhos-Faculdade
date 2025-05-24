#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int numPontos, numRuas;
    int faltaRuas = 0, sobraRuas = 0;
    cin >> numPontos >> numRuas;
    vector<vector<int>> numeros(numPontos);

    for (int i = 0; i < numRuas; i++)
    {
        int a, b;
        cin >> b >> a;
        numeros[a - 1].push_back(b - 1);
    }

    for (int i = 0; i < numeros.size(); i++)
    {
        vector<int> visitados(numPontos);
        int cc = 0;

        if (visitados[i] > 0)
        {
            cout << i << " foi visitado" << endl;
            continue;
        }

        cout << "size " << i << " " << numeros[i].size() << endl;
        visitados[i]++;
        for (int j = 0; j < numeros[i].size(); j++)
        {
            cout << numeros[i][j] << " ";
            int mm = numeros[i][j];
            vector<int> temp(numPontos, 0);
            temp[i] = 1;

            bool c = false;
            while (true)
            {
                if (visitados[mm] == 1 && c)
                {
                    break;
                }
                cout << "visitando: " << mm << endl;
                if (numeros[mm].size() == 0)
                {
                    for (int ll = 0; ll < numPontos; ll++)
                    {
                        if (temp[ll] == 1)
                        {
                            cout << "cc: " << cc << endl;
                            numeros[ll][0] = mm;
                            if (cc == numPontos)
                            {
                                cc++;
                                cout << "raiz encotrada";
                            }
                        }
                    }
                    cout << "temp <";
                    for (int i : temp)
                    {
                        cout << i << " ";
                    }
                    cout << ">" << endl;
                    break;
                }
                temp[mm] = 1;
                mm = numeros[mm][0];
                c = true;
            }
        }
    }

    cout << "tamanho: " << numeros.size() << endl;
    for (int i = 0; i < numeros.size(); i++)
    {
        cout << "node " << i << " size : " << numeros[i].size() << endl;
        for (int j = 0; j < numeros[i].size(); j++)
        {
            cout << numeros[i][j] << " ";
        }
        cout << endl;
        cout << "----" << endl;
    }
}