//---------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
//---------------------------------------------------------------------------

/* -----------------------------------------------------------------------------
Estrutura pilha dinamica
------------------------------------------------------------------------------*/

typedef struct no_pilha {
	int dado;
	struct no_pilha *prox;
}  Tno_pilha;




/* -----------------------------------------------------------------------------
Prototipos das funcoes b�sicas
------------------------------------------------------------------------------*/
int Inicializar_pilha      (Tno_pilha **inicio);
int Inicializar2_pilha     (Tno_pilha **inicio);
int Inserir_topo           (Tno_pilha **inicio, int info);
int Remover_topo           (Tno_pilha **inicio);
int Obter_topo             (Tno_pilha *inicio, int *dado);
int Verifica_vazio         (Tno_pilha *inicio, int *resp);


/* -----------------------------------------------------------------------------
Prototipos das funcoes derivadas e testes
------------------------------------------------------------------------------*/
int Juntar_pilhas      (Tno_pilha **P1, Tno_pilha **P2, Tno_pilha **P3);
int Listar             (Tno_pilha *P1);



/* -----------------------------------------------------------------------------
PRINCIPAL
------------------------------------------------------------------------------*/
int main(void)
{

	int info;
	int erro, resposta; /* valor de erro retornado pelas funcoes */
	Tno_pilha *ini;
	Tno_pilha *P1, *P2, *P3;

	int q;  /* receber a opcao do usuario */
	erro=Inicializar_pilha (&ini);
	do {
	    system("cls");
	    printf("PILHA\n");
		printf("\n\nOpcoes:\n");
		printf("1 -> Inserir \n");
		printf("2 -> Remover\n");
		printf("3 -> Inicializar\n");
		printf("4 -> Consultar Topo \n");
		printf("5 -> Verificar Vazio\n");
		printf("6 -> Listar\n");
		printf("7 -> Sair \n\n:");
		//printf("8 -> Juntar pilhas\n");
		scanf("%d", &q);     /* Ler a opcao do usuario */
		switch(q) {
		    case 8:
		            Inicializar_pilha  (&P1);
		            Inicializar_pilha  (&P2);
		            Inserir_topo    (&P1, 10);
		            Inserir_topo    (&P1, 20);
		            Inserir_topo    (&P1, 30);
		            Inserir_topo    (&P1, 40);
                    Inserir_topo    (&P2, 100);
		            Inserir_topo    (&P2, 200);
		            Inserir_topo    (&P2, 300);
                    Listar (P1);
		            Listar (P2);
		            printf ("--------------\n");
		            //Juntar_pilhas (&P1, &P2, &P3);
		            Listar (P1);
		            Listar (P2);
		            Listar (P3);
		             system("pause");
					break;

			case 1: printf("Dado para insercao na Pilha: ");
                    scanf("%d",&info);
                    erro=Inserir_topo (&ini, info);
                    if (erro == 0) printf("Insercao realizada com sucesso\n");
                    system("pause");
					break;
            case 2: erro = Remover_topo (&ini);
                    if (erro==1)
                    {
                        printf("\nPilha vazia. Impossivel remover.\n");
                    }
                    system("pause");
                    break;
            case 3: erro = Inicializar2_pilha (&ini);
                    printf("\nInicializacao realizada com sucesso !\n");
                    printf("\nPILHA VAZIA !\n");
                    system("pause");
					break;
			case 4: erro= Obter_topo (ini, &info);
                    if (erro==1)
                    {
                        printf("\nPilha vazia. Impossivel consultar topo\n");
                    }
                    else {
                         printf("\nTopo: %d\n",info);
                    }
                    system("pause");
					break;
			case 5: erro= Verifica_vazio (ini, &resposta);
                    if (resposta==1)
                    {
                        printf("\nPilha vazia\n");
                    }
                    else {
                         printf("\nPilha nao vazia\n");
                    }
                    system("pause");
					break;
			case 6: Listar (ini);
			        break;
			case 7: break;
			default: printf("\n\n Opcao nao valida\n");
		}
		getchar();    /* Limpa o buffer de entrada */
	} while ((q != 7) );

}


/* ------------------------------------------------------------------------------------
INICIALIZAR
--------------------------------------------------------------------------------------*/
int Inicializar_pilha (Tno_pilha **inicio)
{
	*inicio= NULL;
	return 0; /* sem erro */
} /* Fim da fun��o de INICIALIZAR */

// =================================================
int Inicializar2_pilha(Tno_pilha **inicio)
{
    Tno_pilha *percorre, *aux;
	if(*inicio != NULL)
	{
       percorre = *inicio;
	   while (percorre != NULL)
	   {
             aux = percorre;
	         percorre = percorre -> prox;
	         free(aux);
	   }
	   *inicio = NULL;
	   return 1; // inicializa apagando tudo da pilha
	}
}

/* -------------------------------------------------------------------------------------
INSER��O
---------------------------------------------------------------------------------------*/
int Inserir_topo (Tno_pilha **inicio, int info) // o mesmo que inserir_inicio
{
    Tno_pilha *no_novo;

    /* Criacao do novo no - Aloca��o de memoria */
    no_novo = (Tno_pilha *) malloc(sizeof(Tno_pilha));
    no_novo -> dado = info;

	if (*inicio==NULL)
	{    // insercao em pilha vazia
	    no_novo -> prox = NULL;
	    *inicio = no_novo;
	}
	else { // insercao em pilha nao vazia
	     no_novo -> prox = *inicio;
	    *inicio = no_novo;
	}
    return 0;
}


/* -------------------------------------------------------------------------
REMOCAO
-------------------------------------------------------------------------*/
int Remover_topo (Tno_pilha **inicio)  // o mesmo que remover_inicio
{
    Tno_pilha *aux;
    if (*inicio == NULL)
    {
         return 1;  /* UNDERFLOW - pilha vazia, impossivel remover topo */
    }
    else {
        aux = *inicio;
        *inicio = (*inicio)->prox;
        free(aux);
        return 0;
    }
}

// =================================================================
int Obter_topo(Tno_pilha *inicio, int *dado)
{
    if (inicio != NULL)
    {
       *dado = inicio -> dado;
       return 0;
    }
    else
       return 1; // Pilha Vazia - erro
}
// ================================================================
int Verifica_vazio (Tno_pilha *inicio, int *resp)
{
    if (inicio != NULL)
       *resp = 0; // Pilha nao Vazia
    else
       *resp = 1; // Pilha Vazia
    return 0;
}


// ================================================================
int Listar (Tno_pilha *P1)
{
    printf ("Pilha: ");
    while (P1 != NULL)
    {
        printf ("%d - ", P1->dado);
        P1 = P1 -> prox;
    }
      printf (" \n ");
      system ("pause");
}


