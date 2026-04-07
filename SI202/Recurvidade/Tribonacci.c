#include <stdio.h>

int tribonacci (int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1)
        return n;
    return tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1);
}

int main () {
    int n;
    printf("Calculador de Tribonacci: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        printf("%d ", tribonacci(i));
    printf("\n");
    printf("%d\n", tribonacci(n - 1));
    return 1;
}