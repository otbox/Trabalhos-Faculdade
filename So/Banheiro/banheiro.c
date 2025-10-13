#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

#define N_PESSOAS 10

sem_t mutex_num_mulheres;
sem_t mutex_num_homem;
sem_t mutex_banheiro;
int num_mulher = 0;
int num_homem = 0;

void homem_entrou(int id){
    printf("Homem %d está dentro do banheiro",id);
    return;
}
void mulher_entrou(int id){
    printf("Mulher %d está dentro do banheiro",id);
    return;
}
void mulher_sai(int id){
    printf("Mulher %d está saindo do banheiro",id);
    return;
}
void homem_sai(int id){
    printf("Homem %d está saindo do banheiro",id);
    return;
}

void *mulher_quer_entrar(void * idM) {
    int id = *((int *) idM);

    sem_wait(&mutex_num_mulheres);
    if (num_mulher == 0){
        sem_wait(&mutex_banheiro);
    }


    return NULL;
}

void *homem_quer_entrar(void *idH){
    int id = *((int *) idH);

    printf("Homem %d querendo entrar", id);
    sem_wait(&mutex_num_homem);
    num_homem++;
    if (num_homem == 1){
        sem_wait(&mutex_banheiro);
    }
    
    sem_post(&mutex_banheiro);
    printf("Homem %d entrou", id);
    return NULL;
}



int main () {
    pthread_t idH[N_PESSOAS/2],idM[N_PESSOAS/2];

    sem_init(&mutex_num_mulheres,0,1);
    sem_init(&mutex_num_homem, 0, 1);
    sem_init(&mutex_banheiro, 0, 1);

    for (int i = 0; i < N_PESSOAS; i++){
        if (i % 2){
            pthread_create(&idH[i], NULL, homem_entrou, void *restrict arg)
        }else {
            pthread_create(&idM[i], NULL, mulher_entrou, void *restrict arg)
        }
    }




    return 0;
}