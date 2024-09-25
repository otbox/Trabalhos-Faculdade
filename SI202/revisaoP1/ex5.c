#include <stdio.h>

float mediaTemp (int temp[3][12]) {
	int soma = temp[0][11] + temp[0][0] + temp[0][1] + temp[0][2];
	return soma/4;
}

int indexMaiorVariacaoTemp (int temp[3][12]){
  int maiorC = 0;
  int index = 0;
    for(int j = 0; j < 12;j++){
      int variacao = temp[0][j] - temp[2][j]; 
      if(maiorC < variacao){
	      maiorC = variacao; 
	      index = j;
      }
   }
   return index;
}

float mediaTempAnual (int temp[3][12]) {
  float soma = 0;
  for (int i = 0; i < 12; i++) {
    soma += temp[1][i];
  }
  return soma/12;
}

int main() {
  int temp[3][12] =  {{29,30,29,28,25,24,25,27,28,29,29,29},{24,24,24,22,19,18,18,19,21,23,23,24},{20,20,19,17,14,12,12,13,15,17,19,20}};
  char meses[13][15] = {"","janeiro","fevereiro","marco","abril","maio","junho","julho","agosto","outubro","novembro","dezembro"};

  int maiorC = 0;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 12;j++){
      if(maiorC < temp[0][j])
	      maiorC = temp[i][j]; 
    }    
  }
  for(int j = 0; j < 12;j++){
      if(temp[0][j] <= 25)
	      printf("Meses mais frescos sao %s\n", meses[j]);    
  }
  printf("Media das maiores temperaturas %.2f \n", mediaTemp(temp));
  //printf("Maior temperatura registrada %d", maiorC);
  printf("Mes com maior variacao de temperatura eh: %s\n", meses[indexMaiorVariacaoTemp(temp)]);
  printf("Media anual de temperatura eh: %.2f\n", mediaTempAnual(temp));

  return 0;
}
