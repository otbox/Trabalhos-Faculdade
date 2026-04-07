#include <stdlib.h>
#include <stdio.h>

float Procedimento_Media (int *Idades, int nALunos) {
    float soma = 0; 
    for(int i = 0; i < nALunos; i++)
        soma += Idades[i];
    return soma/nALunos;
}

int main () {
    int nAlunos = 0; 
    printf("Informe o numero de Alunos:\n");
    scanf("%d", &nAlunos);

    int *AlunosIdades = (int *) malloc(nAlunos * sizeof(int));
    for(int i = 0; i < nAlunos; i++)
        scanf("%d", &AlunosIdades[i]);
    float resultado = Procedimento_Media(AlunosIdades,nAlunos);
    printf("Media: %f", resultado);
    return 0;
}