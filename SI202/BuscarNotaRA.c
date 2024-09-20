#include <stdio.h>
#include <stdlib.h>

int main() {
  int RA, nota;
  printf("Procurar por RA: ");
  scanf("%d", &RA);

  FILE *file;

  file = fopen("notas.txt", "r");

  if (file == NULL) {
    printf("Erro ao criar arquivo");
    return 0;
  }

while (1){
    int RA1;
    float Nota1;
    if(fscanf(file, "%d %f\n", &RA1,&Nota1) == -1){
        printf("Não encontrado\n");
        break;
    }
    if (RA == RA1){
        printf("A nota do %d é %.2f",RA1,Nota1);
        break;
    }
  }
  fclose(file);
  return 0;
}