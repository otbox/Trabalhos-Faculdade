#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int item[50];
    int inicio, fim;
} t_queue;

void printq(t_queue * q) {


    if(q->fim == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("C= i:%d f:%d ", q->inicio, q->fim);
    for (int i = q->inicio; i <= q->fim; i++) {
        printf("%d >", q->item[i]);
    }
    printf(">\n");
}
void enqueue (t_queue * q, int valor) {
    if (q->fim == -1){
        q->inicio = 0;
    }

    if ((q->fim + 1) > 49){
        perror("Stack Overflow");
        return;
    }

    q->item[++q->fim] = valor;
}

int dequeue (t_queue * q){
    if (q->fim == -1){
        return -1;
    }
    int temp = q->item[q->inicio];
    for(int i = q->inicio; i < q->fim; i++){
        q->item[i] = q->item[i + 1];
    }
    q->fim--;
    return temp;
}

void invert(t_queue ** q){
    t_queue * aux = (t_queue *) malloc(sizeof(t_queue));
    aux->fim = -1;
    aux->inicio = -1;
    if((*q)->fim == -1) {
        printf("Queue is empty\n");
        return;
    }
    int fim = (*q)->fim;
    for (int i = fim; i >= (*q)->inicio; i--){
        enqueue(aux,(*q)->item[i]);
    }
    *q = aux;
}



int main () {
    t_queue * q1 = (t_queue *) malloc(sizeof(t_queue));
    q1->fim = -1;
    q1->inicio = -1;
    
    enqueue(q1, 1);
    enqueue(q1, 2);
    enqueue(q1, 3);
    enqueue(q1, 4);
    enqueue(q1, 5);
    enqueue(q1, 6);
    printq(q1);
    invert(&q1);
    printq(q1);
    return 0;
}