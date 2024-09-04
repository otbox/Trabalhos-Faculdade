#include <stdlib.h>
#include <stdio.h>

int main (){
    int nC;
    scanf("%d",&nC);
    float* c = (float *)malloc(nC * sizeof(float));
    for (int x = 0; x < nC; x++){
        scanf("%d",&c[x]);
    }


    float maiorCachoeira = 0, menorCachoeira = __INT_MAX__;
    for (int x = 0; x < nC; x++){
        if(menorCachoeira > c[x]){
            menorCachoeira = c[x];
        }
        if(maiorCachoeira < c[x]){
            maiorCachoeira = c[x];
        }
    }
    free(c);
    printf("Distancia da menor cachoeira: %.2fKm, maior cachoeira: %.2fKm",menorCachoeira, maiorCachoeira);
    return 0;
}