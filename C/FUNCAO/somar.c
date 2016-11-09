#include <stdio.h>
int S(int a, int b){
    int soma = a + b;
    return soma;
}
int main(){
    int a , b;
    scanf("%d%d", &a, &b);
    printf("Soma = %d\n", S(a,b));
    return 0;
}
