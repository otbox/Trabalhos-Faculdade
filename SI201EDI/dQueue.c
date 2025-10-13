// Modificar o codigo do Camolesi, para poder colocar o fim no inicio de forma circular;
// Para poder adicionar infinatamente
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node * next;
} t_node;

typedef struct queue {
    int size;
    t_node * head;
    t_node * tail;
} t_queue;

void init_queue(t_queue * q) {
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
}

void enqueue (t_queue *q, t_node *n) {
    if (q->head == NULL) {
        q->head = n;
        q->tail = n;
        n->next = n;
        return;
    }
    // (*q->head).next = n;
    n->next = q->head;
    q->head = n;
    (*q->head).next = q->head; 
}

void dequeue (t_queue * q) {
    if (q->head == NULL) {
        print("Empty queue");
    }
    t_node * aux = q->head; 
    q->head = aux->next;
    free(aux); 
}

void printQueue (t_queue *q) { 
    if (q->head == NULL) {
        printf("Empty Queue!\n");
        return; 
    }
    t_node * temp = q->head;
    int c = 0; 
    printf("<<:");
    while(temp != q->tail) {
        printf("%p:%d -> %p | \n", temp, temp->value, temp->next);

        temp = temp->next;
    }
    printf("%p:%d -> %p >>\n", q->tail, (*q->tail).value, (*q->tail).next);
} 

int main () {
    t_queue * queue1 = (t_queue *) malloc(sizeof(t_queue));
    t_node teste = {1,NULL};
    t_node teste1 = {2,NULL};
    t_node teste2 = {3,NULL};
    t_node teste3 = {4,NULL};

    enqueue(queue1,&teste);
    printQueue(queue1);
    enqueue(queue1,&teste1);
    enqueue(queue1,&teste2);
    printQueue(queue1);

    return 0; 
}
