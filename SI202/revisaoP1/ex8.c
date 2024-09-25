#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char telefone[50];
    char email[50];
} contato;
int main() {
    int nNumeros;
    printf("Armazenador de numeros do ZAP-ZAP\n");
    printf("Insira a quantidade de números desejado: \n");
    scanf("%d", &nNumeros);

    contato contatos[nNumeros];
    for(int i = 0; i < nNumeros; i++){
        printf("Insira nome:\n");
        scanf("%s",contatos[i].nome);
        printf("Insira telefone:\n");
        scanf("%s",contatos[i].telefone);
        printf("Insira Email:\n");
        scanf("%s",contatos[i].email);
    } 

    while (1){
        char DDD[5];
        printf("Digite o DDD ou escreva 'sair' para sair\n");
        scanf("%s",DDD);
        if (!strcmp(DDD, "sair"))
            break;
        int c = 0;
        printf("Encontrado com o DDD-%s os Nomes:", DDD);
        for(int i = 0; i < nNumeros; i++){
            char DDDNumero[3] = {contatos[i].telefone[0], contatos[i].telefone[1]};
            if(!strcmp(DDD, DDDNumero)){
                c++;
                printf("%s\n", contatos[i].nome);
            }
        }
        if(c == 0)
        printf("Não encontrado nenhum contato com esse DDD");

    }
    
    return 0;
}