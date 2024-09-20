#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct jogador {
    char nome[50];
    int ranking;
};

void separador(){

}



int main () {

    srand(time(NULL));
    int a = rand() % 20;
    struct jogador jogadores1[10] = {
        {"João", 1},
        {"Maria", 2},
        {"Carlos", 3},
        {"Ana", 4},
        {"Pedro", 5},
        {"Lucas", 6},
        {"Fernanda", 7},
        {"Roberto", 8},
        {"Camila", 9},
        {"Rafael", 10}
    };


    int qntTimes;
    int qntJogadores = 10;
    printf("Entre com a Quantidade de Times");
    scanf("%d", &qntTimes);

    float divisoesPorMedia[qntTimes];
    int somaDoRanking = 0;
    int qntGrupos = qntTimes;
    if (qntJogadores % qntTimes != 0){
        qntGrupos = qntTimes++;
    }

    struct jogador[qntGrupos][qntJogadores]
    for (int i = 0; i < 10; i++){
        somaDoRanking += jogadores1[i].ranking;
    }
    printf("SomadoRanking: %d",somaDoRanking );
    for (int i = 0; i < qntTimes; i++){ 
        // divisoesPorMedia[qntTimes - 1] = 
    }
    

    return 0;
}