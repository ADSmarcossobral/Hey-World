#include <stdio.h>
#include <stdlib.h>

int TAM = 1;

void pauseClear(){
    printf("\nPressione enter para continuar...\n");
    system("read x");
    system("clear");
}

int menu(){
    pauseClear();
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

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}  

void push(int *vetor, int val){
    vetor = (int *) realloc(vetor, TAM * sizeof(int));
    *(vetor+TAM-1) = val; // Mesmo que vetor[TAM-1] (Menos 1 porque o tamanho parte de 1)
    TAM++;
}

void pop(int *vetor){
    if(TAM == 1){
        printf("\nPilha Vazia!\n");
        return;
    }
    vetor = (int *) realloc(vetor, TAM - 2 * sizeof(int));
    TAM--;
}

void selectAll(int *vetor){
    if(TAM == 1){
        printf("\nPilha Vazia!\n");
        return;
    }
    printf("Pilha: ");
    for(int x = 0; x < TAM - 1; x++)
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
    free(vetor);
}