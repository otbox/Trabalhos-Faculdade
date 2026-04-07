#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    char esporte[40];
    int idade;
    int nMedalhas;
} atleta;

atleta getAtetla (atleta * atletas, int opc,int n){
    atleta atletaSelecionado;
    atletaSelecionado.idade = 0;
    atletaSelecionado.nMedalhas = 0;   

    for(int i = 0; i < n; i++){
      if (opc){
        if(atletaSelecionado.idade < atletas[i].idade)
          atletaSelecionado = atletas[i];
      }
      else if (!opc) {  
        if(atletaSelecionado.nMedalhas < atletas[i].nMedalhas)
          atletaSelecionado = atletas[i];
      }
    }
    return atletaSelecionado;
}
void preencherAlunos(FILE *arquivo, atleta *atleta, int n) {
  rewind(arquivo);
  for (int i = 0; i < n; i++) {
    fgets(atleta[i].nome, 50, arquivo);
    fgets(atleta[i].esporte, 40, arquivo);
    fscanf(arquivo, "%d\n%d\n", &atleta[i].idade, &atleta[i].nMedalhas);
  }
  for (int i = 0; i < n; i++){
    printf("%s%s%d\n%d\n", atleta[i].nome,atleta[i].esporte,atleta[i].idade,atleta[i].nMedalhas);
  }
}
int main (){
    // int nAtletas;
    // printf("Digite o numero de atletas: ");
    // scanf("%d", &nAtletas);
    atleta atletas[5];
    FILE * arquivo = fopen("atletas.txt", "w+");
    for (int i = 0; i < 5; i++){
        printf("Entre com o Nome:");
        fgets(atletas[i].nome, 50, stdin);
        // getchar();
        printf("Entre com o Esporte:");
        fgets(atletas[i].esporte, 40, stdin);
        printf("Entre com o Idade:");
        scanf("%d",&atletas[i].idade);
        printf("Entre com o Numero de medalhas:");
        scanf("%d",&atletas[i].nMedalhas);
        fprintf(arquivo, "%s%s%d\n%d\n", atletas[i].nome,atletas[i].esporte,atletas[i].idade,atletas[i].nMedalhas);
        getchar();
    }
    preencherAlunos(arquivo, atletas, 5);
    atleta OldAtleta = getAtetla(atletas, 1, 5);
    atleta BestAtleta = getAtetla(atletas, 0, 5);
    printf("Atleta mais velho é %s", OldAtleta.nome);
    printf("Atleta com mais medalhas é %s", BestAtleta.nome);
}