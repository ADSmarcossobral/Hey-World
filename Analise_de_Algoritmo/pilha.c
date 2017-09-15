#include <stdio.h>
#include <stdlib.h>

struct No{
        int val;
        struct No *prox;
};

typedef struct No No;

void exibir(No *PILHA){
    printf("\n===================== PILHA =======================\n");
    if(!PILHA->prox){
        printf("\nPILHA vazia\n");
        return;
    }
    No *temp = PILHA->prox;
    while(temp){
        printf("%d ", temp->val);
        temp = temp->prox;
    }
    printf("\n");
}

void push(No *novo, No *PILHA){
    if(!PILHA->prox)
        PILHA->prox = novo;
    else{
        No *atual, *ant;
        atual = PILHA->prox;
        while(atual != NULL){
            ant = atual;
            atual = atual->prox;
        }
        ant->prox = novo;
    }
}

No *pop(No *PILHA){
    if(!PILHA->prox){
        printf("\nNao foi possivel retirar, a fila estah vazia!\n");
        return NULL;
    }
    No *atual, *ant;
    atual = PILHA->prox;
    ant = PILHA;
    while(atual->prox != NULL){
        ant = atual;
        atual = atual->prox;
    }
    ant->prox = NULL;
    atual->prox = NULL;
    return atual;
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
    printf("1 -> PUSH\n");
    printf("2 -> POP\n");
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
    No *PILHA = (No *) malloc(sizeof(No));
    checaMem(PILHA);
    PILHA->prox = NULL;
    while(op != 4){
        op = menu();
        if(op == 1){
            printf("\nInforme o valor: ");
            scanf("%d", &val);
            No* novo = (No *)malloc(sizeof(No));
            novo->val = val;
            novo->prox = NULL;
            push(novo, PILHA);
        } else if(op == 2){
            No *no;
            no = pop(PILHA);
            free(no);
        } else if(op == 3)
            exibir(PILHA);
        else if(op != 4)
            printf("\nOpcao invalida!\n");
    }
    return 0;
}