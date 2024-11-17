#include <stdio.h>

int main () {
    int n = 5;
    int fat = 1;
    for (int i = n; i > 0; i--){
        fat *= i;
    }
    printf("Resultado:%d\n",fat);
}