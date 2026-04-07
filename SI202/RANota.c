#include <stdio.h>
#include <stdlib.h>

#define NUMUSUARIO 2

int main() {
  float notas[NUMUSUARIO];
  int ra;
  FILE *file;

  file = fopen("notas.txt", "w+");
  
  if (file == NULL) {
    printf("Erro ao criar arquivo");
    return 0;
  }

  for (int i = 0; i < NUMUSUARIO; i++) {
    scanf("%d %f", &ra, &notas[i]);
    fprintf(file, "%d %0.2f\n", ra, notas[i]);
  }

  fclose(file);

  return 0;
}