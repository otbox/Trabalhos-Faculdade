#include <stdio.h>

void converter (int n) {
    if (n <  1) {
        // printf("1");
        return;
    }
    converter(n/2);
    printf("%d", n%2);
    return;
}

int main () {
    int n;
    printf("Conversor Decimal para Binário - Recursivo\n");
    printf("Entre com o numero decimal:");
    scanf("%d",&n);
    converter(n);
}