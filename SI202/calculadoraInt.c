#include <stdio.h>
#include <math.h>
#include <string.h>
float soma (float n1, float n2) {return n1 + n2;}
float subtrai (float n1, float n2) {return n1 - n2;}
float divide (float n1, float n2) {return n1 / n2;}
float multiplica (float n1, float n2) {return n1 * n2;}
float eleva (float n1, float n2) {return pow(n1, n2);}


int main () {
    char texto[15];
    float n1,n2, resultado;
    scanf("%f %s %f",&n1,texto,&n2);
    if (!strcmp(texto, "soma")){resultado =soma(n1, n2);}
    if (!strcmp(texto, "subtrai")){resultado =subtrai(n1, n2);}
    if (!strcmp(texto, "multiplica")){resultado =multiplica(n1, n2);}
    if (!strcmp(texto, "divide")){resultado =divide(n1, n2);}
    if (!strcmp(texto, "eleva")){resultado =eleva(n1, n2);}
    printf("resultado: %.2f\n",resultado);
}