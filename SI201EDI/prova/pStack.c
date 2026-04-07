#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int valor;
    struct node * next;  
} t_node;

void push (t_node ** top, int valor) {
    t_node * aux = (t_node *) malloc(sizeof(t_node));
    aux->valor = valor;
    aux->next = (*top);
    *top = aux;
}

int pop (t_node ** top) {
    if (*top == NULL) {
        // perror("Stack Underflow");
        return  -1;
    }
    t_node * aux = *top;
    int value = aux->valor;
    *top = (*top)->next;
    free(aux);
    return value;
}   

void print (t_node * top) {
    t_node * current = top;
    while (current != NULL) {
        printf("%p - %d > ", current, current->valor);
        current = current->next;
    }
    printf("\n");
}

int max(t_node ** top) {
    t_node * aux = NULL;
    int current = pop(top);
    int max = current; 
    while (current != -1){
        current = pop(top);
        if (max < current) {
            max = current;
        }
        push(&aux, current);
    }
    while(aux != NULL) {
        push(top, pop(&aux));
        aux = aux->next;
    }
    return max;
}

int somar(t_node ** s, t_node ** s1){
    if (*s == NULL || *s1 == NULL){
        return 1;
    }
    t_node * aux = * s; 
    while (aux->next != NULL){
        aux = aux->next;
    }
    aux->next = *s1;
    return 0;
}


int main () {
    t_node * stack = NULL;
    t_node * stack1 = NULL;

    push(&stack, 5);
    push(&stack, 6);
    push(&stack, 3);
    push(&stack1, 66);
    push(&stack1, 69);
    push(&stack1, 34);
    somar(&stack, &stack1);

    printf("max: %d\n", max(&stack));
    print(stack);
    return 0;
}