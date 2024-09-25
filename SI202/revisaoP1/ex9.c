#include <stdlib.h>
#include <stdio.h>

int* unirVetores (int *v1, int *v2, int n1, int n2) {
   int * v3 = (int *) malloc((n1 + n2)* sizeof(int));
   for(int i = 0; i < n1; i++)
        v3[i] = v1[i];                                                 
   for(int i = 0; i < n2; i++)
        v3[n1 + i] = v2[i];                                          
    return v3;
}

int main() {
    printf("Unir vetores:\n");
    int n1,n2;
    
    printf("Digite a qnt de elementos primeiro vetor:\n");
    scanf("%d",&n1);
    int * v1 = (int *) malloc(n1 * sizeof(int));
    printf("Digite a qnt de elementos segundo vetor:\n");
    scanf("%d",&n2);
    int * v2 = (int *) malloc(n2 * sizeof(int));
    printf("Preencha vetor 1:");
     for(int i = 0; i < n1; i++)
        scanf("%d",&v1[i]);
    printf("Preencha vetor 2:");
     for(int i = 0; i < n2; i++)
        scanf("%d",&v2[i]);

    int *v3 = unirVetores(v1, v2, n1, n2);
    for(int i = 0; i < (n1 + n2); i++)
        printf("%d\n",v3[i]);
    return 0;
}