#include <stdio.h>

int somar (int n) {
    if (n == 1 || n == 0)
        return n;
    return n + somar(n - 1);
}

int main () {
    int n;
    printf("Somar todos os números de um intervalo:\n");
    scanf("%d", &n);
    printf("resultado: %d",somar(n));
    return 1;
}
