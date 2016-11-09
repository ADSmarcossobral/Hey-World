#include <stdlib.h>
#include <stdio.h>
void menu();
int escolha();
int main(){
    menu();
    printf("Voce escolheu a opcao %d\n", escolha());
    return 0;
}
void menu(){
    puts("Digite: 0 --> Sair | 1 --> Imprimir | 2 --> Listar");
}
int escolha(){
    int op;
    scanf("%d", &op);
    return op;
}
