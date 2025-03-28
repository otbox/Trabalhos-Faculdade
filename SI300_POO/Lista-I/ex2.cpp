#include <iostream>
#include <string>
using namespace std;

int main() { 
    int inteiro;
    float flutuante;
    string texto;

    cout << "Digite um número inteiro: ";
    cin >> inteiro;
    
    cout << "Digite um número um ponto flutuante: ";
    cin >> flutuante;
    
    cin.ignore(); 
    
    cout << "Digite uma string: ";
    getline(cin, texto);



    cout << inteiro << " , " << flutuante <<" , " << texto << endl;


    return 0;
}
