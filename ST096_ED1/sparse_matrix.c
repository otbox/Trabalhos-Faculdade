#include <stdio.h>
#include <stdlib.h>

typedef struct matriz_node {
    int data;
    int x, y;
    struct matriz_node *l, *r,*t,*d;
}  tmatriz_node;

typedef struct matriz_vector {
    int pos;
    tmatriz_node *node;
} tvector;


#define SIZE 10
tvector tcol[SIZE], trow[SIZE];


void insert(tmatriz_node * nnode) {
    tmatriz_node curr 
    while (curr != NULL) {

    }
}



void initMatriz(tvector * tv) {
    for (int i = 0; i < SIZE; i++) {
        tv[i].node = NULL;
        tv[i].pos = i;
    }
}

void printM() {
    for (int i = 0; i < SIZE; i++) { 
        tmatriz_node * curr;
        
    }
}

int main () {
    return 0;
}