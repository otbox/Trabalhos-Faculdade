#include <stdio.h>

#define SIZE 10

typedef struct {
    int value;
} t_node;

typedef struct {
    int length;
    t_node items[SIZE];
} t_stack;

void initStack(t_stack *s) {
    s->length = 0;
}

void push(t_stack *s, t_node n) {
    if (s->length >= SIZE) {
        perror("Stack Overflow");
        return;
    }
    for (int i = s->length; i > 0; i--) {
        s->items[i] = s->items[i - 1];
    }
    s->items[0] = n;
    s->length++;
}

t_node pop(t_stack *s) {
    
    if (s->length <= 0){
        perror("Stack Underflow");
        t_node empty = {0}; // valor default
        return empty;
    }
    t_node result = s->items[0];
        for (int i = 0; i < s->length; i++) {
        s->items[i] = s->items[i + 1];
    }
    s->length--;
    return result;
}

void printStack(t_stack *s) {
    for (int i = 0; i < s->length; i++) {
        printf("%d-", s->items[i].value);
    }
    printf("\n");
}

int main() {
    t_stack teste;
    initStack(&teste);

    t_node n1 = {1};    
    t_node n2 = {2};
    t_node n3 = {3};
    t_node n4 = {4};
    t_node n5 = {5};

    push(&teste, n1);
    printStack(&teste);
    push(&teste, n2);
    push(&teste,n3);
    push(&teste,n4);
    push(&teste,n5);
    push(&teste,n5);
    push(&teste,n5);
    push(&teste,n5);
    push(&teste,n5);
    push(&teste,n5);
    push(&teste,n5);
    push(&teste,n5);
    push(&teste,n5);
    push(&teste,n5);
    push(&teste,n5);
    push(&teste,n5);
    printStack(&teste);
    pop(&teste);
    printStack(&teste);
    pop(&teste);
    printStack(&teste);
    pop(&teste);
    pop(&teste);
    return 0;
}
