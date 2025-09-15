// Modificar o codigo do Camolesi, para poder colocar o fim no inicio de forma circular;
// Para poder adicionar infinatamente

typedef struct node {
    int value;
    struct node * next;
} t_node;

typedef struct queue {
    int size;
    t_node * head;
    t_node * tail;
} t_queue;

void enqueue (t_queue * q, t_node * n) {
    
}
