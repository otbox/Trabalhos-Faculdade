#include <stdio.h>
#include <string.h>

int main () {
    char texTO[100];
    int k = 0;
    scanf("%d\n", &k);
    fgets(texTO, 100, stdin);

    for (int i =0; i <= strlen(texTO) - 2; i++){
        if (texTO[i] > 96 && texTO[i] < 123){
            if (texTO[i] + k > 122){
                int sobra = texTO[i] + k - 123;
                printf("%c", 65 + sobra);
                continue;
            }
            printf("%c",texTO[i] + k - 32);
            
        }else if (texTO[i] > 64){
            if (texTO[i] + k > 90){
                int sobra = texTO[i] + k - 91;
                printf("%c", 65 + sobra);
                continue;
            }
            printf("%c",texTO[i] + k);
        }else{
            printf("%c", texTO[i]);
        }
    }
    printf("\n");
}