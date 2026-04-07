#include <stdio.h>
#include <getopt.h>

int main (int argc, char *argv[]) {
    int opcao;
    printf("%d", argc);
    while ((opcao = getopt(argc, argv, "o")) != -1)
  {
     switch (opcao)
     {
      case 'o':
            
        break;
     }
  }

    return 0;
}