#include <stdio.h>

int fibonnacci (int n) {
    if (n == 1 || n == 0)
        return n;
    return fibonnacci(n - 1) + fibonnacci(n - 2);
}

int main () {
    int n = 6;
    for (int i = 0; i < n; i++) {
        printf("%d",fibonnacci(i));
    }
}

