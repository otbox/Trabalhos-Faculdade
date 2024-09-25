#include<stdio.h>
int main(){
int i;
for(i = 1; i < 9; i++){
int aux = 0;
aux += i*i;
}
printf("%d\n", aux);
return 0;
}