#include <stdio.h>
//Otavio Marques Cruz 281443
//Guilherme Bastos Leone 176199 
int main() {
    char questoesGabarito[10];
    char questoesAluno[10];

    printf("Gabarito\n");
    for (int x = 0; x < 10; x++){
        scanf("%c\n", &questoesGabarito[x]);
    }
    printf("Prova Aluno\n");
    for (int x = 0; x < 10; x++){
        scanf("%c\n", &questoesAluno[x]);
    }
    int nota = 0;
    for (int x = 0; x < 10; x++ ){
        if(questoesGabarito[x] == questoesAluno[x]){
            nota++;
        }
    }
    printf("A nota do aluno foi de %d", nota);
}