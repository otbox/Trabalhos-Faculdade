#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct jogador {
    char nome[50];
    int ranking;
};

void separador(){
    printf("-------------------------------\n");
}

int main () {
    srand(time(NULL));

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
    printf("Entre com a Quantidade de Times: ");
    scanf("%d", &qntTimes);

    // Sort players by ranking in descending order
    for (int i = 0; i < qntJogadores; i++) {
        for (int j = i + 1; j < qntJogadores; j++) {
            if (jogadores1[i].ranking < jogadores1[j].ranking) {
                struct jogador temp = jogadores1[i];
                jogadores1[i] = jogadores1[j];
                jogadores1[j] = temp;
            }
        }
    }

    // Create teams
    struct jogador times[qntTimes][qntJogadores / qntTimes + 1]; // +1 for remaining players
    int idx = 0;
    for (int i = 0; i < qntTimes; i++) {
        int j = 0;
        while (j < qntJogadores / qntTimes) {
            times[i][j] = jogadores1[idx++];
            j++;
        }
        // Add a player from the top, middle, and bottom of the remaining players
        if (idx < qntJogadores) {
            times[i][j++] = jogadores1[idx++];
        }
        if (idx < qntJogadores) {
            times[i][j++] = jogadores1[idx + (qntJogadores - idx) / 2];
            idx += (qntJogadores - idx) / 2;
        }
        if (idx < qntJogadores) {
            times[i][j++] = jogadores1[idx++];
        }
    }

    // Shuffle teams
    for (int i = 0; i < qntTimes; i++) {
        int teamSize = qntJogadores / qntTimes;
        if (i < qntJogadores % qntTimes) {
            teamSize++;
        }
        for (int j = 0; j < teamSize; j++) {
            int idx1 = rand() % teamSize;
            int idx2 = rand() % teamSize;
            struct jogador temp = times[i][idx1];
            times[i][idx1] = times[i][idx2];
            times[i][idx2] = temp;
        }
    }

    // Print teams
    for (int i = 0; i < qntTimes; i++) {
        int teamSize = qntJogadores / qntTimes;
        if (i < qntJogadores % qntTimes) {
            teamSize++;
        }
        printf("Time %d:\n", i + 1);
        for (int j = 0; j < teamSize; j++) {
            printf("%s (Ranking: %d)\n", times[i][j].nome, times[i][j].ranking);
        }
        separador();
    }

    return 0;
}