#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    int priority;
    struct node * next;
    struct node * prev;
} t_node;

typedef struct deque {
    t_node * inicio;
    t_node * fim;
} t_deque;


void init_q (t_deque * q) { 
    q->inicio = NULL;
    q->fim = NULL;
}

int isEmpty(t_deque * q) {
    if (q->inicio == NULL) {
        return  1;
    } 
    return 0;
}

int dequeue (t_deque * q, int priority) {
    if (isEmpty(q)) {
        return 1;
    }
    if (isEmpty(q)){
        return 1;
    }

    
    t_node * aux = q->inicio; 
    if (q->inicio == q->fim){
        init_q(q);
    }else{ 
        while (aux->priority != priority){
            aux = aux->next;
        }
        (*aux->prev).next = aux->next;
        (*aux->next).prev = aux->prev;
    }

    free(aux);
    return 0;
}

int dequeue_first (t_deque * q) {
    if (isEmpty(q)) {
        return 1;
    }
    if (isEmpty(q)){
        return 1;
    }

    t_node * aux = q->inicio; 
    if (q->inicio == q->fim){
        init_q(q);
    }else{
        q->inicio = aux->next; 
        (*q->fim).next = aux->next;
        (*q->inicio).prev = q->fim;
    }

    free(aux);
    return 0;
}

int dequeue_last (t_deque * q) {
    if (isEmpty(q)){
        return 1;
    }

    t_node * aux = q->fim; 
    if (q->inicio == q->fim){
        init_q(q);
    }else{
        q->fim = aux->prev; 
        (*q->fim).next = q->inicio;
        (*q->inicio).prev = q->fim;
    }

    free(aux);
    return 0;
}

void enqueue_last (t_deque * q, int value) {
    t_node * n_node = (t_node *) malloc(sizeof(t_node)); 
    n_node->value = value;
    if (isEmpty(q)){
        q->inicio = n_node;
        q->fim = n_node;
        n_node->prev = n_node;
        n_node->next = n_node;
        return;
    }
    (*q->fim).next = n_node;
    (*q->inicio).prev = n_node;
    n_node->prev = q->fim;
    n_node->next = q->inicio;
    q->fim = n_node;
}

void enqueue (t_deque * q, int value, int p) {
    t_node * n_node = (t_node *) malloc(sizeof(t_node)); 
    n_node->value = value;
    n_node->priority = p;
    if (isEmpty(q)){
        q->inicio = n_node;
        q->fim = n_node;
        n_node->prev = n_node;
        n_node->next = n_node;
        return;
    }

    t_node * aux = q->inicio;
    while (aux != q->inicio || (aux == q->inicio && p <= aux->priority)) {
        if (p > aux->priority) {
            break; // posição encontrada
        }
        aux = aux->next;
        if (aux == q->inicio) {
            break; // deu a volta
        }
    }


    n_node->prev = aux->prev;
    n_node->next = aux;
    (*aux->prev).next = n_node;
    aux->prev = n_node;

    if (aux == q->inicio && p > aux->priority) {
        q->inicio = n_node;
    }
    if (aux == q->inicio && p <= q->fim->priority) {
        q->fim = n_node;
    }
}

void printQueue(t_deque *q) {
    if (isEmpty(q)) {
        printf("Fila vazia\n");
        return;
    }

    t_node *aux = q->inicio;
    do {
        printf("%d >", aux->value);
        aux = aux->next;
    } while (aux != q->inicio);

    printf("\n");
}


int main () { 
    t_deque deque1;
    init_q(&deque1);
    enqueue(&deque1, 1, 2);
    printQueue(&deque1);
    enqueue(&deque1, 2, 2);
    printQueue(&deque1);
    enqueue(&deque1, 3, 1);
    dequeue_first(&deque1);
    printQueue(&deque1);
}
