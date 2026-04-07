#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

struct argumentoMatriz{
    int *** matriz;
    int linhaSomar;
    int tam;
};

void * multiplicarLinhaColuna(void * arg) {
    struct argumentoMatriz *t = (struct argumentoMatriz *) arg;
    int linhaSomar = t->linhaSomar;
    int ***matriz = t->matriz;
    int tam = t->tam; 
    int *matrizResultante = (int *) malloc(tam * sizeof(int));
    if (matrizResultante == NULL) {
        perror("Falha ao alocar memória");
        pthread_exit(NULL);
    }
    for (int i = 0; i < tam; i++) {
        matrizResultante[i] = 0; // Inicializando a soma

        // Multiplicando a linha da primeira matriz pela coluna da segunda
        for (int j = 0; j < tam; j++) {
            matrizResultante[i] += matriz[0][linhaSomar][j] * matriz[1][j][i];
            // printf("Multiplicando %d * %d\n", matriz[0][linhaSomar][j], matriz[1][j][i]);
        }

        // printf("Resultado parcial da linha %d, coluna %d: %d\n", linhaSomar, i, matrizResultante[i]);
        matriz[2][linhaSomar][i] = matrizResultante[i];
    }
    free(matrizResultante);
    pthread_exit(NULL);
}

int main () {
    int nMatriz;
    clock_t start, end;
    // Apenas Matrizes Quadradas 
    printf("Numero de matrizes:\n");
    scanf("%d",&nMatriz);
    printf("Entre com os Tam Matrizes:\n");
    int l, c;
    nMatriz++;
    printf("Entrada de Tamanho N N:");
    scanf("%d %d", &l, &c);
    int *** matrizes1 = (int ***) malloc(nMatriz * sizeof(int**)); 
    for (int i = 0; i < nMatriz; i++){
        matrizes1[i] = (int **) malloc(l * sizeof(int*));
        for (int j = 0; j < l; j++){
            matrizes1[i][j] = (int *) malloc(c * sizeof(int));
        }
    }
    nMatriz--;
    for (int i = 0; i < nMatriz; i++) {
        printf("Preencha a Matriz %d:\n", i);
        for (int j = 0; j < l; j++) {
            for (int k = 0; k < c; k++) {
                scanf("%d", &matrizes1[i][j][k]);
            }
        }
    }
    for (int v = 0; v < nMatriz; v++){
        for (int a =0; a < l; a++){
            for (int b = 0; b < l; b++){
                printf("%d ", matrizes1[v][a][b]);
            }
            printf("\n");
        }
    }
    printf("Matrizes preenchidas com sucesso!\n");

    int numThreads = 4; // Specify the number of threads
    pthread_t threads[numThreads];

    start = clock();

    for (int i = 0; i < l; i += numThreads) {
        for (int j = 0; j < numThreads; j++) {
            if (i + j < l) {
                struct argumentoMatriz *t = (struct argumentoMatriz *) malloc(sizeof(struct argumentoMatriz));
                t->matriz = matrizes1;
                t->linhaSomar = i + j;
                t->tam = l;
                int err = pthread_create(&threads[j], NULL, multiplicarLinhaColuna, (void *)t);
                if (err < 0){
                    perror("Erro não possivel criar thread");
                    exit(1);
                }
            }
        }
        for (int j = 0; j < numThreads; j++) {
            if (i + j < l) {
                void * result = NULL;
                pthread_join(threads[j], &result);
            }
        }
    }

    end = clock();
    double result_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("tempo resultante: %lf segundos\n", result_time);
    for (int a =0; a < l; a++){
        for (int b = 0; b < l; b++){
            printf("%d ", matrizes1[nMatriz][a][b]);
        }
        printf("\n");
    }

    for (int i = 0; i < nMatriz + 1; i++) {
        for (int j = 0; j < l; j++) {
            free(matrizes1[i][j]);
        }
        free(matrizes1[i]);
    }
    free(matrizes1);
    return 0;
}