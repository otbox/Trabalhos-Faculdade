#include <iostream> 
#include <cmath>
#include <vector>
using namespace std;

const double PI = 3.14159265359;

int main () {
    
    int R1, R2, R3;
    cin >> R1 >> R2 >> R3;

    //Calculo dos trechos das laterais
    vector<int> L = {abs(R2 - R1), abs(R3 - R2)};
    
    //Numero de Divisões e Perguntas
    int nD, nP;
    cin >> nD >> nP;
    vector<double> TR = {2*R1*PI/nD, 2*R2*PI/nD, 2*R3*PI/nD};
    vector<double> TR1 = {2*R1*PI, 2*R2*PI, 2*R3*PI};

    for (int i=0; i < TR.size(); i++){
        cout << TR1[i] << " ";
        cout << TR[i] << " ";
    }
    cout << "Fim leitura";
    for (int i = 0; i < nP; i++)
    {
        int Ir, Il, Fr, Fl;

        cin >> Ir >> Il >> Fr >> Fl;
        
        // Djisktra 
        // DTA Distancia Trecho Absoluta 
        vector<double> DTA(3);
        for (int j = 0; j < TR.size(); j++){
            DTA[j] = TR[j] * abs(Ir - Fr);
            cout << "DTA: " << DTA[j] << " ";
        }
        cout << endl;
        vector<double> DLA(2);
        for (int j = 0; j < L.size(); j++){
            DLA[j] = L[j] * abs(Il - Fl);
            cout << "DLA: " << DLA[j] << " ";
        }
        cout << endl;
        double Distancia = MAXFLOAT;
        for (int k = 0; k < DTA.size(); k++){
            for (int m = 0; m < DLA.size(); m++) {
                double d = DTA[k] + DLA[m];
                cout << "DDD: " << d << " "; 
                if(Distancia > d) {
                    // cout << d << " - " << DTA[m] << " "<< DLA[k];
                    Distancia = d;
                }
            } 
        }
        cout << "D:" << Distancia << endl;
    }
    
    return 0;
}