#include <stdio.h>

void inversor (char * string, int inicio, int fim) {
    if (inicio >= fim) 
        return; 
    char in = string[inicio];
    string[inicio] = string[fim];
    string[fim] = in;
    inversor(string, inicio + 1, fim - 1); 
    // return;
}

int main () {
    char teste[] = "saci";
    inversor(teste, 0, sizeof(teste) - 2);
    printf("%s", teste);
}
