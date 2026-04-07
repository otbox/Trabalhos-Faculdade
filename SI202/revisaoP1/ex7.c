#include <stdio.h>
#include <string.h>

void imprimirCaracteres(char * palavra) {
    for (int i = 0; i < strlen(palavra); i++){
       printf("%d ",palavra[i]);

       if(palavra[i] < 0)
         printf("acentuada: %c | %d ", palavra[i], palavra[i]);
    }
    printf("\n");
}

void removeAcentos(char *str) {
    char *comAcento = "áàãâäéèêëíìîïóòõôöúùûüçÁÀÃÂÄÉÈÊËÍÌÎÏÓÒÕÔÖÚÙÛÜÇ";
    char *semAcento = "aaaaaeeeeiiiiooooouuuucAAAAAEEEEIIIIOOOOOUUUUC";

    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; comAcento[j] != '\0'; j++) {
            if (str[i] == comAcento[j]) {
                str[i] = semAcento[j];
                for (int k = i + 1; str[k] != '\0'; k++)
                    str[k] = str[k+1];
                break;  
            }
        }
    }
}

void substituir (char * palavra) {
    int len = strlen(palavra);
    char *ultLetra = &palavra[len-1];
    char * sufixo = "";
    if(*ultLetra < 96){
        sufixo = "MENTE";
        if (*ultLetra == 'O') 
            *ultLetra = 'A';
        ;
    }else
        sufixo = "mente";
    if(*ultLetra == 'o')
        *ultLetra = 'a';
    strcat(palavra, sufixo);
}

int main (){
    char *string;  
    printf("gerador de adverbios insira a palavra: \n");  
    scanf("%s",string);
    removeAcentos(string);
    // imprimirCaracteres(string);
    substituir(string);
    printf("%s\n",string);
}