#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int criptograph (char letra) {
	char * aphabet = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	for (int i = 0; i < 26; i++){
		if (letra == aphabet[i]){
			return i + 1;
		}
	} 
	return -1;
 }

int * criptographText (char * texto){
	int *retorno = (int *) malloc(strlen(texto) * sizeof(int));
	for (int i = 0; i < strlen(texto); i++)
		retorno[i] = criptograph(texto[i]);
	return  retorno; 
	 
} 

int main () {
	char * texto = "MAMACO";
	for (int i = 0; i < strlen(texto); i++)
		printf("%d",criptographText(texto)[i]);
	return 0;
}
