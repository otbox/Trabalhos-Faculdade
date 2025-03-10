#include <stdio.h>

int isPalindromo (char * string, int inicio, int fim) {
    if (inicio >= fim) {
        return 1;
    } 
    if (string[inicio] != string[fim]) {
        return 0;
    }
    return isPalindromo(string, inicio + 1, fim - 1);
}

int main () {
    char teste[] = "radar"; 
    printf("%s", isPalindromo(teste, 0, sizeof(teste) - 2) ? "True" : "False");
}