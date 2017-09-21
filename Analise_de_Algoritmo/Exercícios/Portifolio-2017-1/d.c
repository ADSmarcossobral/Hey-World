#include <stdio.h>
#include <stdlib.h>

int TAM = 1;

int menu(){
    printf("============================= MENU =============================\n");
    printf("1 - PUSH\n");
    printf("2 - POP\n");
    printf("3 - Exibir\n");
    printf("4 - Sair\n");
    printf("\nEscolha uma opcao: ");
    int op;
    scanf("%d", &op);
    return op;
}

void push(int *vetor, int val){
    vetor = (int *) realloc(vetor, TAM * sizeof(int));
    *(vetor+TAM-1) = val;
    TAM++;
}

void pop(int *vetor){
    vetor = (int *) realloc(vetor[1], TAM * sizeof(int));
    TAM--;
}

void selectAll(int *vetor){
    printf("Fila: ");
    for(int x = 0; x < TAM; x++)
        printf("%d ", *(vetor+x));
    printf("\n");
}

int opcao(int *vetor, int op){
    if(op == 1){
        int val;
        printf("\nInforme o valor: ");
        scanf("%d", &val);
        push(vetor, val);
    } else if(op == 2){
        pop(vetor);
    } else if(op == 3)
        selectAll(vetor);
    else if(op == 4)
        return 0;
    else
        printf("\nOpcao invalida!!!\n");
    return 1;
}

int main(){
    int *vetor;
    vetor = (int *) malloc(TAM * sizeof(int));
    while(opcao(vetor, menu()));


}