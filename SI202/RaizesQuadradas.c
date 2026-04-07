#include <math.h>
#include <stdio.h>

#define TAM_VETOR 10

void procedimento (double *vetor1, double *vetor2) {
    for(int i = 0; i < TAM_VETOR; i++){
        vetor2[i] = sqrt(vetor1[i]);
    }
}

int main () {
    double vetor[TAM_VETOR], vetorResultado[TAM_VETOR];
    for (int i = 0; i < TAM_VETOR; i++) 
        scanf("%lf", &vetor[i]);
    procedimento(vetor, vetorResultado);
    for (int i = 0; i < TAM_VETOR; i++) 
        printf("%.2lf ", vetorResultado[i]);
    printf("\n");
    return 0;
}