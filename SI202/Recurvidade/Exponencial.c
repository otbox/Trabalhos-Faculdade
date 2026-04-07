#include <stdio.h>

int exponecia (int x,int n) {
    if (n == 0)
        return 1;
    return x * exponecia(x,n - 1);
}

int main() {
    int x, n;
    printf("Entre com o numero e com exponenciar (x n): ");
    scanf("%d %d", &x, &n);
    printf("%d\n", exponecia(x, n));
}