#include <stdio.h>

long double fatorial (int numero) {
    if (numero - 1 == 0){
        return numero;
    }
    return numero * fatorial(numero - 1);
}

int main () {
    int n;
    printf("Calculadora de fatorial com Recursividade\n");
    while (1) {
        printf("Entre com seu numero, 0 para sair\n");
        scanf("%d",&n);
        if (n == 0) {
            printf("Voce escolheu sair.");
            return 0;
        }
        printf("Resultado: %Lf\n",fatorial(n));
    }
}
