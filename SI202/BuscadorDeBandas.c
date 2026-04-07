#include <stdio.h>
#include <string.h>

struct band {
    char nome[50];
    char generoMusical[50];
    int numeroIntegrante;
    int seguidoresInstagram;
    int ouvintesSpotify;
};

#define NUMBER_BANDS 5

int main () {
    struct band bands[NUMBER_BANDS];
    char generoMusicalPesquisa[50];
    printf("Entre com as informações da bandas:\n");
    for (int i = 0; i < NUMBER_BANDS; i++){
        printf("Entre com o nome:\n");
        fgets(bands[i].nome, 50, stdin);
        printf("Entre com o genero musical:\n");
        fgets(bands[i].generoMusical, 50, stdin);
        printf("Entre com o numero integrante:\n");
        scanf("%d", &bands[i].numeroIntegrante);
        printf("Entre com o numero seguidores:\n");
        scanf("%d", &bands[i].seguidoresInstagram);
        printf("Entre com o numero ouvintes:\n");
        scanf("%d", &bands[i].ouvintesSpotify);
        getchar();
        printf("----------------------------------\n");
    }

    printf("Pesquisar por gênero musical:\n");
    fgets(generoMusicalPesquisa, 50, stdin);
    for (int i = 0; i < NUMBER_BANDS; i++){
        if (!strcmp(bands[i].generoMusical, generoMusicalPesquisa)){
            printf("Bandas Encontradas: %s", bands[i].nome);
        }
    }
    struct band moreListenBand = bands[0];
    for (int i = 0; i < NUMBER_BANDS; i++){
        
        if ((moreListenBand.ouvintesSpotify + moreListenBand.seguidoresInstagram) < (bands[i].ouvintesSpotify + bands[i].ouvintesSpotify)){
            moreListenBand = bands[i];
        }
    }
    printf("Banda Mais Ouvida %s", moreListenBand.nome);
    return 0;
}