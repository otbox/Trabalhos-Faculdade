#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int RA;
  float Nota;
} aluno;

#define ARQUIVO "notas.txt"

int contadorLinhas(FILE *arquivo) {
  char string[25];
  int c = 0;
  float f;

  while (fgets(string, sizeof(string), arquivo) != NULL) {
    // printf("%s", string);
    c++;
  }
  return c;
}

void adicionarAluno(FILE *arquivo) {
  int RA;
  float Nota;
  printf("Aluno RA: ");
  scanf("%d", &RA);
  printf("Aluno Nota: ");
  scanf("%f", &Nota);
  fprintf(arquivo, "\n%d %.2f", RA, Nota);
}

void preencherAlunos(FILE *arquivo, aluno *aluno, int n) {
  rewind(arquivo);
  for (int i = 0; i < n; i++) {
    fscanf(arquivo, "%d %f", &aluno[i].RA, &aluno[i].Nota);
  }
}

void visualizarAlunos(aluno *aluno, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d %.2f\n", aluno[i].RA, aluno[i].Nota);
  }
}

void calcularMedia(aluno *aluno, int n) {
  float notaTotal = 0;
  for (int i = 0; i < n; i++) {
    notaTotal += aluno[i].Nota;
  }
  printf("%.2zip f\n", notaTotal/n);
}

int main() {
  FILE *arquivo1;
  arquivo1 = fopen("notas.txt", "a+");
  if (arquivo1 == NULL) {
    perror("Erro ao abrir o arquivo");
    return -1;
  }
  int nAlunos = contadorLinhas(arquivo1);
  aluno alunos[nAlunos];
  int opcao;
  printf("1 - Adicionar Aluno\n");
  printf("2 - Visualizar Turma\n");
  printf("3 - Calcular Nota\n");
  scanf("%d", &opcao);

  switch (opcao) {
  case 1:
    adicionarAluno(arquivo1);
    break;
  case 2:
    preencherAlunos(arquivo1, alunos, nAlunos);
    visualizarAlunos(alunos, nAlunos);
    break;
  case 3:
    preencherAlunos(arquivo1, alunos, nAlunos);
    calcularMedia(alunos, nAlunos);
    break;
  default:
    printf("Nenhuma alternativa selecionada");
    break;
    return 0;
  }
}