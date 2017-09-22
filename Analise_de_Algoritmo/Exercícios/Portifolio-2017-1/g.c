#include <stdio.h>
#include <stdlib.h>

struct No{
    int val;
    struct No *prox;
};

typedef struct No No;

void exibir(No *FILA){
    printf("\n===================== FILA =======================\n");
    if(!FILA->prox){
        printf("\nFILA vazia\n");
        return;
    }
    No *temp = FILA->prox;
    while(temp){
        printf("%d ", temp->val);
        temp = temp->prox;
    }
    printf("\n");
}

void enqueue(No *novo, No *FILA){
    if(!FILA->prox)
        FILA->prox = novo;
    else{
        No *atual, *ant;
        atual = FILA->prox;
        while(atual != NULL){
            ant = atual;
            atual = atual->prox;
        }
        ant->prox = novo;
    }
    
}

No *dequeue(No *FILA){
    if(!FILA->prox){
        printf("\nNao foi possivel retirar, a fila estah vazia!\n");
        return;
    }
    No *deq;
    deq = FILA->prox;
    FILA->prox = deq->prox;
    deq->prox = NULL;
    return deq;
}

void checaMem(No *novo){
    if(!novo){
        printf("\nNao foi possivel alocar memoria\n");
        exit(1);
    }
}

void limpa(){
    printf("\nPressione qualquer tecla para continuar\n");
    system("read x");
    system("clear");
}

int menu(){
    limpa();
    printf("================ MENU =================\n");
    printf("1 -> Enqueue\n");
    printf("2 -> Dequeue\n");
    printf("3 -> Exibir\n");
    printf("4 -> Sair\n");
    printf("=======================================\n");
    int op;
    printf("\nEscolha uma opcao: ");
    scanf("%d", &op);
    return op;
}

int main(){
    int op = 0, val;
    No *FILA = (No *) malloc(sizeof(No));
    checaMem(FILA);
    FILA->prox = NULL;
    while(op != 4){
        op = menu();
        if(op == 1){
            printf("\nInforme o valor: ");
            scanf("%d", &val);
            No* novo = (No *)malloc(sizeof(No));
            novo->val = val;
            novo->prox = NULL;
            enqueue(novo, FILA);
        } else if(op == 2){
            No *deq;
            deq = dequeue(FILA);
            free(deq);
        } else if(op == 3)
            exibir(FILA);
        else if(op != 4)
            printf("\nOpcao invalida!\n");
    }
    return 0;
}