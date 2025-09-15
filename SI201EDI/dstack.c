#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node * next;
} t_node;

typedef struct stack {
    int size;
    t_node * top; 
} t_stack;

t_node stackpop(t_stack * stack1){
    return * stack1->top;
}

int size (t_stack * stack1) {
    return stack1->size;
}

void push (t_stack * stack1, t_node * var) {
    t_node * actualTop = stack1->top;  
    var->next = actualTop;
    stack1->top = var;
    stack1->size++;
}

void pop (t_stack * stack1) {
    t_node * actualTop = stack1->top; 
    stack1->top = actualTop->next;
    stack1->size--;
    free(actualTop);
}

int main () {
    t_stack * teste_Stack = (t_stack *) malloc(sizeof(t_stack));
    teste_Stack->top = NULL;
    t_node * teste = (t_node *) malloc(sizeof(t_node));
    t_node * teste1 = (t_node *) malloc(sizeof(t_node));
    teste->value = 15;
    teste1->value = 18;
    push(teste_Stack, teste);
    printf("%p \n",teste_Stack->top);
    printf("%d \n",teste_Stack->top->value);
    push(teste_Stack, teste1);
    printf("%p \n",teste_Stack->top);
    printf("%d \n",teste_Stack->top->value);
    pop(teste_Stack);
    printf("%p \n",teste_Stack->top);
    printf("%d \n",teste_Stack->top->value);
    return 0;
}