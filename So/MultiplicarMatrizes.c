#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

struct argumentoMatriz{
    int *** matriz;
    int linhaSomar;
    int tam;
};

void * multiplicarLinhaColuna(void * arg) {
    int linhaSomar = ((struct argumentoMatriz *) arg)->linhaSomar;
    int ***matriz = ((struct argumentoMatriz *) arg)->matriz;
    int tam = ((struct argumentoMatriz *) arg)->tam; 
    register int *matrizResultante = (int *) malloc(tam * sizeof(int));
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
    pthread_exit(NULL);
}


// Multiplicar o primeiro pelos coluna do outro e depois retornar ao valor de seu ponto 

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
    pthread_t th[l];
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

    start = clock();

    for (int i = 0; i < l; i++){
        struct argumentoMatriz *t1 = (struct argumentoMatriz *) malloc(sizeof(struct argumentoMatriz));
        t1->matriz = matrizes1;
        t1->linhaSomar = i;
        t1->tam = l;
    
        int err = pthread_create(&th[i], NULL, multiplicarLinhaColuna, (void *)t1);
        if (err < 0){
            perror("Erro não possivel criar thread");
            exit(1);
        }
    }
    for (int i = 0; i < l; i++){
        void * result = NULL;
        pthread_join(th[i], &result);
    }
    //Ultima matriz colocar no
    // pthread_create(&th1, NULL, multiplicarLinhaColuna, &t1);
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