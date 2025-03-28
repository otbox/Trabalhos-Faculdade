

	#define _GNU_SOURCE // necessário porque getline() é extensão GNU
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct jogador {
   int nivel;
   char nome[30];
} jogadores[50], aux;


int QntJogadores = 0;


void bubble_sort()
{
   for (int i = 0; i < QntJogadores; i++)
   {
       for (int j = 0;j < QntJogadores -1; j++)
       {
           if (jogadores[j].nivel > jogadores[j+1].nivel){
               aux = jogadores[j];
               jogadores[j] = jogadores[j+1];
               jogadores[j+1] = aux;}
       }
   }
}




void carregaJogadores()


{
 FILE *pont_arq;
 size_t len= 100;
 char *linha =malloc(len);
  pont_arq = fopen("arquivo.txt", "r") ;




 char delim[] = ",";


 while (getline(&linha, &len, pont_arq) > 0)  {
   char *ptr = strtok(linha, delim);
   if ((ptr != NULL) && (!strcmp(ptr,"1")) )


   {
       ptr = strtok(NULL, delim);
       jogadores[QntJogadores].nivel = atoi(ptr);
       ptr = strtok(NULL, delim);
       strcpy(jogadores[QntJogadores].nome, ptr);
       QntJogadores++;
   }
 }
 if (linha)
   free(linha);


 bubble_sort();


 for (int i=0; i<QntJogadores; i++)
 {
     printf("%d) %s",jogadores[i].nivel,jogadores[i].nome);
 }


 fclose(pont_arq);
}




void teams(int numerosTimes)
{
   char TimesValidos[numerosTimes][300];
   for (int i = 0; i<numerosTimes; i++)
   {
       strcpy(TimesValidos[i],jogadores[i].nome);
   }


   for (int i = numerosTimes; i < QntJogadores; i++)
   {
              strcat(TimesValidos[(numerosTimes-1)-(i%numerosTimes)], jogadores[i].nome);


   }






   printf("\nTimes Selecionados:\n\n");
   for (int i=0; i<numerosTimes; i++)
   {
       printf("Time %d)\n%s\n",i+1,TimesValidos[i]);
   }
}






int main(void){
   int n;
 carregaJogadores();
 printf("Quantos Times? ");
 scanf("%d",&n);
 teams(n);
 return(0);}