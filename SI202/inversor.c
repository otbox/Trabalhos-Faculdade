#include <stdio.h>
#include <string.h>

int main() {
  char *texto;

  fgets(texto, 100, stdin);

  for (int i = strlen(texto) - 2; i >= 0; i--) {
    printf("%c", texto[i]);
  }
  printf("\n");
  return 0;
}