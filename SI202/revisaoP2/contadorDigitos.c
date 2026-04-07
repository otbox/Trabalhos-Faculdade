#include <stdio.h>


// 2345 = 2.345 * 10 ^ 3 extrair o expoente e somar + 1
int contar (int n) {
    if (n/10 < 1) 
        return 1;
    return 1 + contar(n/10);
}

int main () {
    printf("%d", contar(12345));
}