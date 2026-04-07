#include<stdio.h>
int main(){
int a, b;
a = 8;
b = 5;
int *pont, *outropont;
pont = &a;
outropont =&b;
*pont = *outropont + 3;

printf("%d", *pont - 5);
// printf("%d", )
}

int strlenght(char *string){
    int c = 0;
    while(string[c] != '\0'){
        c++;
    }
    return c;
}

