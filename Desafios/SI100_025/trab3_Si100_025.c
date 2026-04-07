#include <stdio.h>
#include <stdlib.h>

int visitar(int *teste, int N, int *visitados, int *visitei)
{
    int tempo = __INT16_MAX__;
    int visitado = 0;
    for (int i = 0; i < N; i++)
    {
        if (tempo > teste[i] && !visitados[i])
        {
            tempo = teste[i];
            visitado = i;
        }
    }
    printf("Visitei %d, tempo: %d\n", visitado,teste[visitado]);
    *visitei = visitado;
    visitados[visitado] = 1;
    return teste[visitado];
}

int main()
{

    int N = 5;
    int teste[6][6] = {0};
    int visitados[7] = {0};
    int visitados1[6] = {0};
    scanf("%d",&N);
    N++;
    for (int n = 0; n < N; n++)
    {
        for (int j = 0; j < N; j++) {
        int a;
        scanf("%d", &a);
        teste[n][j] = a;
        teste[j][n] = a;
        }
    }

    int tempo = visitar(teste[0], N, visitados1, &visitados[1]);
    printf("tempo aqui: %d\n", tempo);
    
    for (int i = 1; i < N + 2; i++)
    {
        tempo += visitar(teste[visitados[i]], N, visitados1, &visitados[i+1]);
        printf("tempo aqui: %d\n", tempo);
    }
    printf("\n");
    printf("\n");
    
    for (int i = 1; i < N + 2; i ++) {
        printf("%d", visitados[i]);
        if (i != N + 1) {
            printf(" -> ");
        }
    }
    printf("\n");
    printf("%d", tempo);
    printf("\n");

    return 0;
}
