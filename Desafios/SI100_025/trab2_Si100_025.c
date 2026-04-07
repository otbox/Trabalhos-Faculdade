#include <stdio.h>
#include <stdlib.h>
int fatorial (int a) {
    if (a ==  1) {
        return a;
    }
    return fatorial(a - 1) * a; 
}

int IntLenght (int a) {
    if (a/10 < 10) {
        return 2;
    }
    return IntLenght(a/10) + 1; 
} 

int main () {

    char * n = "719";
    
    int c = 0;
    int result = 0;
    for (int i = IntLenght(atoi(n)); i > 0; i--) {
        result += ((int)n[c++] - '0') * fatorial(i);
    }

    printf("%d \n", result);

    return 0;   
}
