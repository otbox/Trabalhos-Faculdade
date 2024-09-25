#include <stdio.h>
//Otavio Marques Cruz 281443
//Guilherme Bastos Leone 176199 
int main () {
    int tam = 10;
    int matriz[tam][tam];

    for(int x = 0; x < tam; x++){
        for (int y =0; y < tam; y++){
            scanf("%d",&matriz[x][y]);
        }
    }
    int maiorValor = 0;
    for(int x = 0; x < tam; x++){
        for (int y =0; y < tam; y++){
            if (maiorValor < matriz[x][y]){
                maiorValor = matriz[x][y];
            }
        }
    }  
    printf("Maior Valor: %d\n", maiorValor);
    printf("Numeros Diagonal:");
    for(int x = 0; x < tam; x++){
        printf("%d ", matriz[x][x]);
    }

}