#include <stdio.h>
//Otavio Marques Cruz 281443
//Guilherme Bastos Leone 176199 
int main () {
    float montanteInicial = 0.0;
    scanf("%f", &montanteInicial);
    int anos = 11;
    float rentablidade = 0.1187;
    float montanteFinal = montanteInicial;

    for(int i =0; i < anos; i++){
        montanteFinal *= (1+ rentablidade);
    }
    printf("Seu montante final: %.2f\n", montanteFinal);

    return 0;

}