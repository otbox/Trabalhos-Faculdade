#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>


struct valores {
    int inital;
    int final;
    int *vetor;
};
void * somar (void *arg){ 
    int inicio,final;
    int *vetor;
    inicio = ((struct valores *) arg)->inital;
    final = ((struct valores *) arg)->final;
    vetor = ((struct valores *) arg)->vetor;  
    int *soma = (int*) malloc(sizeof(int));
    *soma =0;
    printf("inicio:%d",inicio);
    printf(" final:%d",final);    
    for (;inicio <= final; inicio++){
        *soma += vetor[inicio];
    }
    printf(" soma:%d ",*soma);
    pthread_exit((void *) soma);
} 

int main () {
    pthread_t t1, t2;

    int vetor1[10] = {2,3,4,1,5,6,7,8,1,10};
    struct valores v1,v2;
    v1.vetor = vetor1;
    v1.inital = 0;
    v1.final = 4;
    v2.vetor = vetor1;
    v2.inital = 5;
    v2.final = 9;
    pthread_create(&t1, NULL, somar, &v1);
    pthread_create(&t2, NULL, somar, &v2);

    void * somaParcial = NULL;
    void * somaParcial2 = NULL;
    pthread_join(t1, &somaParcial);
    pthread_join(t2, &somaParcial2);
    int soma = 0;
    soma = *((int *) somaParcial);
    soma += *((int *) somaParcial2);
    printf("%d",soma);
    return 0;

}